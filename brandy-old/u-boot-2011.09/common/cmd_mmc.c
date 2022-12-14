/*
 * (C) Copyright 2003
 * Kyle Harris, kharris@nexus-tech.net
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <mmc.h>
#include <part.h>

#ifndef CONFIG_GENERIC_MMC
int do_mmc (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int dev;

	if (argc < 2)
		return cmd_usage(cmdtp);

	if (strcmp(argv[1], "init") == 0) {
		if (argc == 2) {
			if (curr_device < 0)
				dev = 1;
			else
				dev = curr_device;
		} else if (argc == 3) {
			dev = (int)simple_strtoul(argv[2], NULL, 10);
		} else {
			return cmd_usage(cmdtp);
		}

		if (mmc_legacy_init(dev) != 0) {
			puts("No MMC card found\n");
			return 1;
		}

		curr_device = dev;
		printf("mmc%d is available\n", curr_device);
	} else if (strcmp(argv[1], "device") == 0) {
		if (argc == 2) {
			if (curr_device < 0) {
				puts("No MMC device available\n");
				return 1;
			}
		} else if (argc == 3) {
			dev = (int)simple_strtoul(argv[2], NULL, 10);

#ifdef CONFIG_SYS_MMC_SET_DEV
			if (mmc_set_dev(dev) != 0)
				return 1;
#endif
			curr_device = dev;
		} else {
			return cmd_usage(cmdtp);
		}

		printf("mmc%d is current device\n", curr_device);
	} else {
		return cmd_usage(cmdtp);
	}

	return 0;
}

U_BOOT_CMD(
	mmc, 3, 1, do_mmc,
	"MMC sub-system",
	"init [dev] - init MMC sub system\n"
	"mmc device [dev] - show or set current device"
);
#else /* !CONFIG_GENERIC_MMC */

enum mmc_state {
	MMC_INVALID,
	MMC_READ,
	MMC_WRITE,
	MMC_ERASE,
};
static void print_mmcinfo(struct mmc *mmc)
{
	printf("Device: %s\n", mmc->name);
	printf("Manufacturer ID: %x\n", mmc->cid[0] >> 24);
	printf("OEM: %x\n", (mmc->cid[0] >> 8) & 0xffff);
	printf("Name: %c%c%c%c%c \n", mmc->cid[0] & 0xff,
			(mmc->cid[1] >> 24), (mmc->cid[1] >> 16) & 0xff,
			(mmc->cid[1] >> 8) & 0xff, mmc->cid[1] & 0xff);

	printf("Tran Speed: %d\n", mmc->tran_speed);
	printf("Rd Block Len: %d\n", mmc->read_bl_len);

	printf("%s version %d.%d\n", IS_SD(mmc) ? "SD" : "MMC",
			(mmc->version >> 4) & 0xf, mmc->version & 0xf);

	printf("High Capacity: %s\n", mmc->high_capacity ? "Yes" : "No");
	puts("Capacity: ");
	print_size(mmc->capacity, "\n");

	printf("Bus Width: %d-bit\n", mmc->bus_width);
}

int do_mmcinfo (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	struct mmc *mmc;
	int    card_no;
/*
	if (curr_device < 0) {
		if (get_mmc_num() > 0)
			curr_device = mmc_card_no;
		else {
			puts("No MMC device available\n");
			return 1;
		}
	}
*/
    card_no = get_mmc_num();
    if((card_no != 0) && (card_no != 2))
    {
        puts("No MMC device available\n");
	    return 1;
    }
	mmc = find_mmc_device(card_no);

	if (mmc) {
		mmc_init(mmc);

		print_mmcinfo(mmc);
		return 0;
	} else {
		printf("no mmc device at slot %x\n", card_no);
		return 1;
	}
}

U_BOOT_CMD(
	mmcinfo, 1, 0, do_mmcinfo,
	"display MMC info",
	"    - device number of the device to dislay info of\n"
	""
);


int do_card0_probe(cmd_tbl_t *cmdtp, int flag,
			 int argc, char * const argv[])
{
	extern int get_boot_storage_type(void);
	int boot_type = get_boot_storage_type() ;
	struct mmc *mmc_boot = NULL;
	static int card0_init = 0;

	if(boot_type == STORAGE_SD || card0_init)
	{
		printf("card0 has inited\n");
		return 0;
	}

	board_mmc_pre_init(0);
	mmc_boot = find_mmc_device(0);
	if(!mmc_boot){
		printf("fail to find card0\n");
		return -1;
	}
	if (mmc_init(mmc_boot)) {
		puts("card0 init failed\n");
		return  -1;
	}
	card0_init = 1;
	return 0;
}

U_BOOT_CMD(
	sunxi_card0_probe, 1, 0, do_card0_probe,
	"probe sunxi card0 device",
	"sunxi_card0_probe"
);


int do_mmcops(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	enum mmc_state state;
	int    card_no;

	if (argc < 2)
		return cmd_usage(cmdtp);
/*
	if (curr_device < 0) {
		if (get_mmc_num() > 0)
			curr_device = mmc_card_no;
		else {
			puts("No MMC device available\n");
			return 1;
		}
	}
*/
	card_no = get_mmc_num();
	if((card_no != 0) && (card_no != 2))
	{
		puts("No MMC device available\n");
		return 1;
	}

	if (strcmp(argv[1], "rescan") == 0) {
		struct mmc *mmc = find_mmc_device(card_no);

		if (!mmc) {
			printf("no mmc device at slot %x\n", card_no);
			return 1;
		}

		mmc->has_init = 0;

		if (mmc_init(mmc))
			return 1;
		else
			return 0;
	} else if (strncmp(argv[1], "part", 4) == 0) {
		block_dev_desc_t *mmc_dev;
		struct mmc *mmc = find_mmc_device(card_no);

		if (!mmc) {
			printf("no mmc device at slot %x\n", card_no);
			return 1;
		}
		mmc_init(mmc);
		mmc_dev = mmc_get_dev(card_no);
		if (mmc_dev != NULL &&
				mmc_dev->type != DEV_TYPE_UNKNOWN) {
			print_part(mmc_dev);
			return 0;
		}

		puts("get mmc type error!\n");
		return 1;
	} else if (strcmp(argv[1], "list") == 0) {
		print_mmc_devices('\n');
		return 0;
	} else if (strcmp(argv[1], "dev") == 0) {
		int dev, part = -1;
		struct mmc *mmc;

		if (argc == 2)
			dev = card_no;
		else if (argc == 3)
			dev = simple_strtoul(argv[2], NULL, 10);
		else if (argc == 4) {
			dev = (int)simple_strtoul(argv[2], NULL, 10);
			part = (int)simple_strtoul(argv[3], NULL, 10);
			if (part > PART_ACCESS_MASK) {
				printf("#part_num shouldn't be larger"
					" than %d\n", PART_ACCESS_MASK);
				return 1;
			}
		} else
			return cmd_usage(cmdtp);

		mmc = find_mmc_device(dev);
		if (!mmc) {
			printf("no mmc device at slot %x\n", dev);
			return 1;
		}

		mmc_init(mmc);
		if (part != -1) {
			int ret;
			if (mmc->part_config == MMCPART_NOAVAILABLE) {
				printf("Card doesn't support part_switch\n");
				return 1;
			}

			if (part != mmc->part_num) {
				ret = mmc_switch_part(dev, part);
				if (!ret)
					mmc->part_num = part;

				printf("switch to partions #%d, %s\n",
						part, (!ret) ? "OK" : "ERROR");
			}
		}
		board_mmc_set_num(dev);
		if (mmc->part_config == MMCPART_NOAVAILABLE)
			printf("mmc%d is current device\n", dev);
		else
			printf("mmc%d(part %d) is current device\n",
				dev, mmc->part_num);

		return 0;
	}

	if (strcmp(argv[1], "read") == 0)
		state = MMC_READ;
	else if (strcmp(argv[1], "write") == 0)
		state = MMC_WRITE;
	else if (strcmp(argv[1], "erase") == 0)
		state = MMC_ERASE;
	else
		state = MMC_INVALID;

	if (state != MMC_INVALID) {
		struct mmc *mmc = find_mmc_device(card_no);
		int idx = 2;
		u32 blk, cnt, n;
		void *addr;

		if (state != MMC_ERASE) {
			addr = (void *)simple_strtoul(argv[idx], NULL, 16);
			++idx;
		} else
			addr = 0;
		blk = simple_strtoul(argv[idx], NULL, 16);
		cnt = simple_strtoul(argv[idx + 1], NULL, 16);

		if (!mmc) {
			printf("no mmc device at slot %x\n", card_no);
			return 1;
		}

		printf("\nMMC %s: dev # %d, block # %d, count %d ... ",
				argv[1], card_no, blk, cnt);

		mmc_init(mmc);

		switch (state) {
		case MMC_READ:
			n = mmc->block_dev.block_read(card_no, blk,
						      cnt, addr);
			/* flush cache after read */
			flush_cache((ulong)addr, cnt * 512); /* FIXME */
			break;
		case MMC_WRITE:
			n = mmc->block_dev.block_write(card_no, blk,
						      cnt, addr);
			break;
		case MMC_ERASE:
			n = mmc->block_dev.block_erase(card_no, blk, cnt);
			break;
		default:
			BUG();
		}

		printf("%d blocks %s: %s\n",
				n, argv[1], (n == cnt) ? "OK" : "ERROR");
		return (n == cnt) ? 0 : 1;
	}

	return cmd_usage(cmdtp);
}

U_BOOT_CMD(
	mmc, 6, 1, do_mmcops,
	"MMC sub system",
	"read addr blk# cnt\n"
	"mmc write addr blk# cnt\n"
	"mmc erase blk# cnt\n"
	"mmc rescan\n"
	"mmc part - lists available partition on current mmc device\n"
	"mmc dev [dev] [part] - show or set current mmc device [partition]\n"
	"mmc list - lists available devices");
#endif
