/*
 * (C) Copyright 2007-2013
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Jerry Wang <wangflord@allwinnertech.com>
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __SUNXI_BAT_H__
#define __SUNXI_BAT_H__


typedef struct
{
	int x;
	int y;
	int bit;
	void *buffer;
}sunxi_bmp_store_t;

extern int sunxi_bmp_decode(unsigned long addr, sunxi_bmp_store_t *bmp_info);
extern int sunxi_bmp_dipslay_screen(sunxi_bmp_store_t bmp_info);
extern int sunxi_bmp_display_mem(unsigned char *source, sunxi_bmp_store_t *bmp_info);
extern int show_bmp_on_fb(char *bmp_head_addr, unsigned int fb_id);
extern int sunxi_partition_get_partno_byname(const char *part_name);

#if defined(CONFIG_SUN8IW12P1_NOR) || defined(CONFIG_SUN8IW16P1_NOR) || defined(CONFIG_SUN8IW16P1_AXP2101_NOR)
extern int read_bmp_to_kernel(char *partition_name);
#endif

#define IDLE_STATUS 0
#define DISPLAY_DRIVER_INIT_OK  1
#define DISPLAY_LOGO_LOAD_OK 2
#define DISPLAY_LOGO_LOAD_FAIL 3

#endif  /* __SUNXI_BAT_H__ */

