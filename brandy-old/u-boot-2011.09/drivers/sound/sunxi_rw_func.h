/*
 * (C) Copyright 2014-2019
 * allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * caiyongheng <caiyongheng@allwinnertech.com>
 *
 * some simple description for this code
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#ifndef __SUNXI_RW_FUNC__
#define __SUNXI_RW_FUNC__
#include <asm/io.h>
#include <linux/compiler.h>

#if defined(CONFIG_ARCH_SUN50IW3) || defined(CONFIG_ARCH_SUN8IW12) || \
defined(CONFIG_ARCH_SUN8IW15) || defined(CONFIG_ARCH_SUN8IW16) || \
defined(CONFIG_ARCH_SUN8IW18) || defined(CONFIG_ARCH_SUN50IW8)
#define ADDR_WIDTH 0x3f
#else
#define ADDR_WIDTH 0x1f

#endif

extern u32 read_prcm_wvalue(u32 addr, void __iomem *ADDA_PR_CFG_REG);

extern void write_prcm_wvalue(u32 addr, u32 val, void __iomem *ADDA_PR_CFG_REG);

extern u32 codec_wrreg_prcm_bits(void __iomem *ADDA_PR_CFG_REG,
				 u32 reg, u32 mask, u32 value);

extern u32 codec_wrreg_bits(void __iomem *address, u32	mask, u32 value);


extern u32 codec_wr_control(void __iomem *reg, u32 mask, u32 shift, u32 val);
extern void codec_wrreg(void __iomem *address, u32 val);
extern u32 codec_rdreg(void __iomem *address);

extern u32 audiodebug_reg_read(u32 reg);

#endif
