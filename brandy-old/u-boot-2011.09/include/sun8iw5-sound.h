/*
 * Copyright (C) 2016 Allwinner Electronics
 * Version  :  V1.00
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __SUN8IW5_SOUND_H__
#define __SUN8IW5_SOUND_H__

#define _ADDA_CCU_BASE		(0X01C20000)


#define _ADDA_PHY_BASE		(0X01c22c00)
#define _ADDA_MEM_SZ		(1024)

#define _ADDA_R_OFST(n)		(0X00 + (n)*4U)

#if 1//offset of regs
#define ADDA_PLL_CPU_CTRL		_ADDA_R_OFST(0)
#define ADDA_PLL_AUDIO_CTRL		_ADDA_R_OFST(2)

#endif


#define ADDA_I2S_APC			_ADDA_R_OFST(0)   // 0x00
#define ADDA_I2S_AP_FORMAT0		_ADDA_R_OFST(1)   // 0x04
#define ADDA_I2S_AP_FORMAT1		_ADDA_R_OFST(2)   // 0x08
#define ADDA_I2S_AP_TXDATA		_ADDA_R_OFST(3)   // 0x0c
#define ADDA_I2S_AP_FIFOC		_ADDA_R_OFST(5)   // 0x14
#define ADDA_I2S_AP_INT			_ADDA_R_OFST(7)   // 0x1c
#define ADDA_I2S_AP_CLKD		_ADDA_R_OFST(9)   // 0x24
#define ADDA_I2S_AP_CNT			_ADDA_R_OFST(10)  // 0x28
#define ADDA_I2S_AP_TXCHSEL		_ADDA_R_OFST(12)  // 0x30

#define ADDA_SYSCLK_CTL			_ADDA_R_OFST(131) // 0x20c
#define ADDA_MOD_CLK_ENA		_ADDA_R_OFST(132) // 0x210
#define ADDA_MOD_RST_CTL		_ADDA_R_OFST(133) // 0x214
#define ADDA_SYS_SR_CTRL		_ADDA_R_OFST(134) // 0x218

#define ADDA_AIF1CLK_CTRL		_ADDA_R_OFST(144) // 0x240
#define ADDA_AIF1_ADCDAT_CTRL		_ADDA_R_OFST(145) // 0x244
#define ADDA_AIF1_DACDAT_CTRL		_ADDA_R_OFST(146) // 0x248
#define ADDA_AIF1_MXR_SRC		_ADDA_R_OFST(147) // 0x24c
#define ADDA_AIF1_VOL_CTRL1		_ADDA_R_OFST(148) // 0x250
#define ADDA_AIF1_VOL_CTRL2		_ADDA_R_OFST(149) // 0x254
#define ADDA_AIF1_VOL_CTRL3		_ADDA_R_OFST(150) // 0x258
#define ADDA_AIF1_VOL_CTRL4		_ADDA_R_OFST(151) // 0x25c
#define ADDA_DAC_DIG_CTRL		_ADDA_R_OFST(200) // 0x320
#define ADDA_DAC_MXR_SRC		_ADDA_R_OFST(204) // 0x330


//Anolog Register R/W Register
#define ADDA_PR_CFG_REG			(0X01f01400 + 0x1c0)

//Anolog Register
#define	HP_PA_VOL			(0x00)
#define LOMIXSC				(0x01)
#define ROMIXSC				(0x02)
#define DAC_PA_SCR			(0x03)
#define LINEIN_GCTR			(0x05)
#define MIC_GCTR			(0x06)
#define PAEN_CTR			(0x07)
#define SPKL_CTR			(0x08)
#define SPKR_CTR			(0x09)
#define MIC2G_LINEOUT_CTR		(0x0A)
#define MIC1G_MICBAIS_CTR		(0x0B)
#define LADCMIXSC			(0x0C)
#define RADCMIXSC			(0x0D)
#define RES_REG				(0x0E)
#define ADC_AP_EN			(0x0F)
#define ADDA_APT0			(0x10)
#define ADDA_APT1			(0x11)
#define ADDA_APT2			(0x12)
#define BIAS_DA16_CTR0			(0x13)
#define BIAS_DA16_CTR1			(0x34)
#define DA16CAL				(0x15)
#define DA16VERIFY			(0x16)
#define BIASCALI			(0x17)
#define BIASVERIFY			(0x18)



#define get_bvalue(addr)	(*((volatile unsigned char  *)(addr)))
#define put_bvalue(addr, v)	(*((volatile unsigned char  *)(addr)) = (unsigned char)(v))
#define get_hvalue(addr)	(*((volatile unsigned short *)(addr)))
#define put_hvalue(addr, v)	(*((volatile unsigned short *)(addr)) = (unsigned short)(v))
#define get_wvalue(addr)	(*((volatile unsigned long  *)(addr)))
#define put_wvalue(addr, v)	(*((volatile unsigned long  *)(addr)) = (unsigned long)(v))

int codec_play_audio_prepare_step1(void);
int codec_play_audio_prepare_step2(void);
int codec_play_audio_prepare_step3(void);
int codec_play_audio(void);
int play_factory_tone(void);
int play_boot_tone(void);

#endif /*__SUN8IW5_SOUND_H__*/

