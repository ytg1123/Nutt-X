/*
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, d.mueller@elsoft.ch
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

/* This code should work for both the S3C2400 and the S3C2410
 * as they seem to have the same I2C controller inside.
 * The different address mapping is handled by the s3c24xx.h files below.
 */

#include <common.h>
#include <asm/arch/base_pmu.h>
#include <power/sunxi/axp81X_reg.h>

int pmu_type;

#define dbg(format,arg...)	printf(format,##arg)
#define CHIPID_BASE  0x01c14200

static int axp81X_set_dcdc6(int set_vol);


int pwrok_restart_enable(void)
{
	u8 reg_val = 0;
	if (axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_HOTOVER_CTL, &reg_val)) {
		return -1;
	}
	/* PWROK drive low restart function enable  */
	/* for watchdog reset */
	reg_val |= 1;
	if (axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_HOTOVER_CTL, reg_val)) {
		return -1;
	}
	return 0;
}

static int axp_probe(void)
{
	u8  pmu_type;
	u32 efuse_cfg = 0;

	if(axp_i2c_read(AXP81X_ADDR, 0x3, &pmu_type))
	{
		printf("axp read error\n");

		return -1;
	}
	pmu_type &= 0xCF;
	if(pmu_type == 0x41)
	{
		/* pmu type AXP81x */
		printf("PMU: AXP81X\n");
		/*SID REG0: bit17:10
		 *if val>0 && val < 40, vdd-sys 1.14v,
		 *else 1.1v
		 */
		efuse_cfg = readl(CHIPID_BASE);
		efuse_cfg >>= 10;
		efuse_cfg &= 0xff;
		if ((efuse_cfg > 0) && (efuse_cfg < 40))
			axp81X_set_dcdc6(1140);
		else
			axp81X_set_dcdc6(1100);

		pwrok_restart_enable();
		return AXP81X_ADDR;
	}
	else
	{
		printf("unknow PMU\n");
		return -1;
	}

}

/* dcdc 6 for vdd_sys */
static int axp81X_set_dcdc6(int set_vol)
{
	u8   reg_value;

	if (set_vol < 0)
		return 0;
	if(set_vol < 600)
		set_vol = 600;
	else if(set_vol > 1520)
		set_vol = 1520;

	if (axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_DC6OUT_VOL, &reg_value)) {
		debug("%d\n", __LINE__);
		return -1;
	}
	reg_value &= (~0x7f);

	/*dcdc6:0.6v-1.1v  10mv/step   1.12v-1.52v  20mv/step */
        if(set_vol > 1100)
             reg_value |= (50+(set_vol - 1100)/20);
        else
            reg_value |= (set_vol - 600)/10;

	if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_DC6OUT_VOL, reg_value)) {
		printf("pmu : unable to set dcdc6\n");
		return -1;
	}
	printf("set vdd sys to %dmv\n", set_vol);
	return 0;
}

static int axp81X_set_dcdc5(int set_vol)
{
    u8   reg_value;

	if(set_vol < 800)
	{
		set_vol = 800;
	}
	else if(set_vol > 1840)
	{
		set_vol = 1840;
	}
	if(axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_DC5OUT_VOL, &reg_value))
    {
    	debug("%d\n", __LINE__);

        return -1;
    }
    reg_value &= (~0x7f);
	//dcdc5?? 0.8v-1.12v  10mv/step   1.12v-1.84v  20mv/step
    if(set_vol > 1120)
    {
         reg_value |= (32+(set_vol - 1120)/20);
    }
    else
    {
        reg_value |= (set_vol - 800)/10;
    }
	if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_DC5OUT_VOL, reg_value))
	{
		printf("sunxi pmu error : unable to set dcdc5\n");

		return -1;
	}

	if(axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_OUTPUT_CTL1, &reg_value))
    {
		return -1;
    }
	reg_value |=  (1 << 4);

    if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_OUTPUT_CTL1, reg_value))
	{
		printf("sunxi pmu error : unable to onoff dcdc5\n");

		return -1;
	}

	return 0;
}

static int axp81X_set_dcdc2(int set_vol)
{
    u8   reg_value;

	if(set_vol < 500)
	{
		set_vol = 500;
	}
	else if(set_vol > 1300)
	{
		set_vol = 1300;
	}
	if(axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_DC2OUT_VOL, &reg_value))
    {
        return -1;
    }
    reg_value &= ~0x7f;
    //dcdc2?? 0.5v-1.2v  10mv/step   1.22v-1.3v  20mv/step
    if(set_vol > 1200)
    {
         reg_value |= (70+(set_vol - 1200)/20);
    }
    else
    {
        reg_value |= (set_vol - 500)/10;
    }

    if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_DC2OUT_VOL, reg_value))
    {
    	printf("sunxi pmu error : unable to set dcdc2\n");
        return -1;
    }

	if(axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_OUTPUT_CTL1, &reg_value))
    {
		return -1;
    }

	reg_value |=  (1 << 1);
	if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_OUTPUT_CTL1, reg_value))
	{
		printf("sunxi pmu error : unable to onoff dcdc2\n");

		return -1;
	}

    return 0;
}

int probe_power_key(void)
{
	u8  reg_value;

	if(axp_i2c_read(AXP81X_ADDR, BOOT_POWER81X_INTSTS5, &reg_value))
    {
        return -1;
    }
    reg_value &= (0x03<<3);
	if(reg_value)
	{
		if(axp_i2c_write(AXP81X_ADDR, BOOT_POWER81X_INTSTS5, reg_value))
	    {
	        return -1;
	    }
	}

	return (reg_value>>3)&3;
}

int set_ddr_voltage(int set_vol)
{
	if(pmu_type == AXP81X_ADDR)
	{
		return axp81X_set_dcdc5(set_vol);
	}

	return -1;
}

int set_pll_voltage(int set_vol)
{
	if(pmu_type == AXP81X_ADDR)
	{
		return axp81X_set_dcdc2(set_vol);
	}

	return -1;
}

int pmu_init(u8 power_mode)
{
	if(sunxi_rsb_init(0))
		return -1;

	if(sunxi_rsb_config(AXP81X_ADDR, 0x3a3))
		return -1;

	pmu_type = axp_probe();

	return pmu_type;
}

