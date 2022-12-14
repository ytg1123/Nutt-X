/*
 *  * Copyright 2000-2009
 *   * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *    *
 *     * SPDX-License-Identifier:	GPL-2.0+
 *     */

#ifndef _SUNXI_GPIO_H
#define _SUNXI_GPIO_H

#define GPIO_REG_READ(reg)              readl((reg))
#define GPIO_REG_WRITE(reg, value)      writel((value), (reg))


#define PIOC_REG_o_CFG0                 0x00
#define PIOC_REG_o_CFG1                 0x04
#define PIOC_REG_o_CFG2                 0x08
#define PIOC_REG_o_CFG3                 0x0C
#define PIOC_REG_o_DATA                 0x10
#define PIOC_REG_o_DRV0                 0x14
#define PIOC_REG_o_DRV1                 0x18
#define PIOC_REG_o_PUL0                 0x1C
#define PIOC_REG_o_PUL1                 0x20



/**#############################################################################################################
 *
 *                           GPIO(PIN) Operations
 *
-##############################################################################################################*/
#define PIO_REG_CFG(n, i)               ((volatile unsigned int *)(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x00))
#define PIO_REG_DLEVEL(n, i)            ((volatile unsigned int *)(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x14))
#define PIO_REG_PULL(n, i)              ((volatile unsigned int *)(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x1C))
#define PIO_REG_DATA(n)                   ((volatile unsigned int *)(SUNXI_PIO_BASE + ((n)-1)*0x24 + 0x10))

#define PIO_REG_CFG_VALUE(n, i)          readl(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x00)
#define PIO_REG_DLEVEL_VALUE(n, i)       readl(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x14)
#define PIO_REG_PULL_VALUE(n, i)         readl(SUNXI_PIO_BASE + ((n)-1)*0x24 + ((i)<<2) + 0x1C)
#define PIO_REG_DATA_VALUE(n)            readl(SUNXI_PIO_BASE + ((n)-1)*0x24 + 0x10)
#define PIO_REG_BASE(n)                    ((volatile unsigned int *)(SUNXI_PIO_BASE + ((n)-1)*24))

#ifdef SUNXI_R_PIO_BASE
#define R_PIO_REG_CFG(n, i)               ((volatile unsigned int *)(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x00))
#define R_PIO_REG_DLEVEL(n, i)            ((volatile unsigned int *)(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x14))
#define R_PIO_REG_PULL(n, i)              ((volatile unsigned int *)(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x1C))
#define R_PIO_REG_DATA(n)                 ((volatile unsigned int *)(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + 0x10))

#define R_PIO_REG_CFG_VALUE(n, i)          readl(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x00)
#define R_PIO_REG_DLEVEL_VALUE(n, i)       readl(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x14)
#define R_PIO_REG_PULL_VALUE(n, i)         readl(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + ((i)<<2) + 0x1C)
#define R_PIO_REG_DATA_VALUE(n)            readl(SUNXI_R_PIO_BASE + ((n)-12)*0x24 + 0x10)
#define R_PIO_REG_BASE(n)                    ((volatile unsigned int *)(SUNXI_R_PIO_BASE + ((n)-12)*24))
#endif


/* struct for gpio */
typedef struct {
    unsigned char      port;                       /* ????????? */
    unsigned char      port_num;                   /* ??????????????? */
    char               mul_sel;                    /* ???????????? */
    char               pull;                       /* ???????????? */
    char               drv_level;                  /* ?????????????????? */
    char               data;                       /* ???????????? */
    unsigned char      reserved[2];                /* ???????????????????????? */
}
normal_gpio_set_t;

int boot_set_gpio(void  *user_gpio_list, __u32 group_count_max, __s32 set_gpio);

#endif /* _SUNXI_GPIO_H */
