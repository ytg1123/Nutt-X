/****************************************************************************************
 * arch/arm/include/a3x/a33_irq.h
 *
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************/

/* This file should never be included directed but, rather, only indirectly through
 * nuttx/irq.h
 */

#ifndef __ARCH_ARM_INCLUDE_A3X_A33_IRQ_H
#define __ARCH_ARM_INCLUDE_A3X_A33_IRQ_H

/****************************************************************************************
 * Included Files
 ****************************************************************************************/

/****************************************************************************************
 * Pre-processor Definitions
 ****************************************************************************************/

/****************************************************************************************
 * sun8iw5 irq defination header file
 * Copyright(c) 2013-2015 Allwinnertech Co., Ltd.
 *      http://www.allwinnertech.com
 * Author: liugang <liugang@allwinnertech.com>
 ****************************************************************************************/

/* External interrupts numbers */

#define SUNXI_GIC_START       0
#define A3X_IRQ_SGI0          (SUNXI_GIC_START + 0)  /* 0 */
#define A3X_IRQ_SGI1          (SUNXI_GIC_START + 1)  /* 1 */
#define A3X_IRQ_SGI2          (SUNXI_GIC_START + 2)  /* 2 */
#define A3X_IRQ_SGI3          (SUNXI_GIC_START + 3)  /* 3 */
#define A3X_IRQ_SGI4          (SUNXI_GIC_START + 4)  /* 4 */
#define A3X_IRQ_SGI5          (SUNXI_GIC_START + 5)  /* 5 */
#define A3X_IRQ_SGI6          (SUNXI_GIC_START + 6)  /* 6 */
#define A3X_IRQ_SGI7          (SUNXI_GIC_START + 7)  /* 7 */
#define A3X_IRQ_SGI8          (SUNXI_GIC_START + 8)  /* 8 */
#define A3X_IRQ_SGI8          (SUNXI_GIC_START + 9)  /* 9 */
#define A3X_IRQ_SGI10          (SUNXI_GIC_START + 10)  /* 10 */
#define A3X_IRQ_SGI11          (SUNXI_GIC_START + 11)  /* 11 */
#define A3X_IRQ_SGI12          (SUNXI_GIC_START + 12)  /* 12 */
#define A3X_IRQ_SGI13          (SUNXI_GIC_START + 13)  /* 13 */
#define A3X_IRQ_SGI14          (SUNXI_GIC_START + 14)  /* 14 */
#define A3X_IRQ_SGI15          (SUNXI_GIC_START + 15)  /* 15 */
#define A3X_IRQ_PPI0          (SUNXI_GIC_START + 16)  /* 16 */
#define A3X_IRQ_PPI1          (SUNXI_GIC_START + 17)  /* 17 */
#define A3X_IRQ_PPI2          (SUNXI_GIC_START + 18)  /* 18 */
#define A3X_IRQ_PPI3          (SUNXI_GIC_START + 19)  /* 19 */
#define A3X_IRQ_PPI4          (SUNXI_GIC_START + 20)  /* 20 */
#define A3X_IRQ_PPI5          (SUNXI_GIC_START + 21)  /* 21 */
#define A3X_IRQ_PPI6          (SUNXI_GIC_START + 22)  /* 22 */
#define A3X_IRQ_PPI7          (SUNXI_GIC_START + 23)  /* 23 */
#define A3X_IRQ_PPI8          (SUNXI_GIC_START + 24)  /* 24 */
#define A3X_IRQ_PPI8          (SUNXI_GIC_START + 25)  /* 25 */
#define A3X_IRQ_PPI10          (SUNXI_GIC_START + 26)  /* 26 */
#define A3X_IRQ_PPI11          (SUNXI_GIC_START + 27)  /* 27 */
#define A3X_IRQ_PPI12          (SUNXI_GIC_START + 28)  /* 28 */
#define A3X_IRQ_PPI13          (SUNXI_GIC_START + 29)  /* 29 */
#define A3X_IRQ_PPI14          (SUNXI_GIC_START + 30)  /* 30 */
#define A3X_IRQ_PPI15          (SUNXI_GIC_START + 31)  /* 31 */

#define A3X_IRQ_UART0          (SUNXI_GIC_START + 32)  /* 32 */
#define A3X_IRQ_UART1          (SUNXI_GIC_START + 33)  /* 33 */
#define A3X_IRQ_UART2          (SUNXI_GIC_START + 34)  /* 34 */
#define A3X_IRQ_UART3          (SUNXI_GIC_START + 35)  /* 35 */
#define A3X_IRQ_UART4          (SUNXI_GIC_START + 36)  /* 36 */
#define A3X_IRQ_TWI0           (SUNXI_GIC_START + 38)  /* 38 */
#define A3X_IRQ_TWI1           (SUNXI_GIC_START + 39)  /* 39 */
#define A3X_IRQ_TWI2           (SUNXI_GIC_START + 40)  /* 40 */
#define A3X_IRQ_EINTA          (SUNXI_GIC_START + 43)  /* 43 */
#define A3X_IRQ_DAUDIO0        (SUNXI_GIC_START + 45)  /* 45 */
#define A3X_IRQ_DAUDIO1        (SUNXI_GIC_START + 46)  /* 46 */
#define A3X_IRQ_EINTB          (SUNXI_GIC_START + 47)  /* 47 */
#define A3X_IRQ_EINTG          (SUNXI_GIC_START + 49)  /* 49 */
#define A3X_IRQ_TIMER0         (SUNXI_GIC_START + 50)  /* 50 */
#define A3X_IRQ_TIMER1         (SUNXI_GIC_START + 51)  /* 51 */
#define A3X_IRQ_WATCHDOG       (SUNXI_GIC_START + 57)  /* 57 */
#define A3X_IRQ_CODEC          (SUNXI_GIC_START + 61)  /* 61*/
#define A3X_IRQ_KEYADC         (SUNXI_GIC_START + 62)  /* 62*/
#define A3X_IRQ_THERMAL        (SUNXI_GIC_START + 63)  /* 63*/
#define A3X_IRQ_NMI            (SUNXI_GIC_START + 64)  /* 64 */
#define A3X_IRQ_RTIMER0        (SUNXI_GIC_START + 65)  /* 65 */
#define A3X_IRQ_RTIMER1        (SUNXI_GIC_START + 66)  /* 66 */
#define A3X_IRQ_RWATCHDOG      (SUNXI_GIC_START + 68)  /* 68 */
#define A3X_IRQ_RUART          (SUNXI_GIC_START + 70)  /* 70 */
#define A3X_IRQ_RSB            (SUNXI_GIC_START + 71)  /* 71 */
#define A3X_IRQ_RALARM0        (SUNXI_GIC_START + 72)  /* 72 */
#define A3X_IRQ_RALARM1        (SUNXI_GIC_START + 73)  /* 73 */
#define A3X_IRQ_RTWI           (SUNXI_GIC_START + 76)  /* 76 */
#define A3X_IRQ_EINTL          (SUNXI_GIC_START + 77)  /* 77 */
#define A3X_IRQ_HMIC           (SUNXI_GIC_START + 78)  /* 78 */
#define A3X_IRQ_MBOX           (SUNXI_GIC_START + 81)  /* 81 */
#define A3X_IRQ_DMA            (SUNXI_GIC_START + 82)  /* 82 */
#define A3X_IRQ_HSTMR          (SUNXI_GIC_START + 83)  /* 83 */
#define A3X_IRQ_VE             (SUNXI_GIC_START + 90)  /* 90 */
#define A3X_IRQ_MMC0           (SUNXI_GIC_START + 92)  /* 92 */
#define A3X_IRQ_MMC1           (SUNXI_GIC_START + 93)  /* 93 */
#define A3X_IRQ_MMC2           (SUNXI_GIC_START + 94)  /* 94 */
#define A3X_IRQ_SPI0           (SUNXI_GIC_START + 97)  /* 97 */
#define A3X_IRQ_SPI1           (SUNXI_GIC_START + 98)  /* 98 */
#define A3X_IRQ_NAND           (SUNXI_GIC_START + 102)  /* 102 */
#define A3X_IRQ_USBOTG         (SUNXI_GIC_START + 103)  /* 103 */
#define A3X_IRQ_USBEHCI0       (SUNXI_GIC_START + 104)  /* 104 */
#define A3X_IRQ_USBOHCI0       (SUNXI_GIC_START + 105)  /* 105 */
#define A3X_IRQ_SS             (SUNXI_GIC_START + 112)  /* 112 */
#define A3X_IRQ_CSI            (SUNXI_GIC_START + 116)  /* 116 */
#define A3X_IRQ_CSI_CCI        (SUNXI_GIC_START + 117)  /* 117 */
#define A3X_IRQ_LCD0           (SUNXI_GIC_START + 118)  /* 118 */
#define A3X_IRQ_MIPIDSI        (SUNXI_GIC_START + 121)  /* 121 */
#define A3X_IRQ_DRC            (SUNXI_GIC_START + 123)  /* 123 */
#define A3X_IRQ_DEFE0          (SUNXI_GIC_START + 125)  /* 125 */
#define A3X_IRQ_DEBE0          (SUNXI_GIC_START + 127)  /* 127 */

#define A3X_IRQ_GPUGP          (SUNXI_GIC_START + 129)  /* 129 */
#define A3X_IRQ_GPUGPMMU       (SUNXI_GIC_START + 130)  /* 130 */
#define A3X_IRQ_GPUPP0         (SUNXI_GIC_START + 131)  /* 131 */
#define A3X_IRQ_GPUPPMMU0      (SUNXI_GIC_START + 132) /* 132 */
#define A3X_IRQ_GPUPMU         (SUNXI_GIC_START + 133) /* 133 */
#define A3X_IRQ_GPUPP1         (SUNXI_GIC_START + 134) /* 134 */
#define A3X_IRQ_GPUPPMMU1      (SUNXI_GIC_START + 135) /* 135 */
#define A3X_IRQ_CTI0           (SUNXI_GIC_START + 140) /*      CTI0            */
#define A3X_IRQ_CTI1           (SUNXI_GIC_START + 141) /*      CTI1            */
#define A3X_IRQ_CTI2           (SUNXI_GIC_START + 142) /*      CTI2            */
#define A3X_IRQ_CTI3           (SUNXI_GIC_START + 143) /*      CTI3            */
#define A3X_IRQ_COMMTX0        (SUNXI_GIC_START + 144) /*      COMMTX0         */
#define A3X_IRQ_COMMTX1        (SUNXI_GIC_START + 145) /*      COMMTX1         */
#define A3X_IRQ_COMMTX2        (SUNXI_GIC_START + 146) /*      COMMTX2         */
#define A3X_IRQ_COMMTX3        (SUNXI_GIC_START + 147) /*      COMMTX3         */
#define A3X_IRQ_COMMRX0        (SUNXI_GIC_START + 148) /*      COMMRX0         */
#define A3X_IRQ_COMMRX1        (SUNXI_GIC_START + 149) /*      COMMRX1         */
#define A3X_IRQ_COMMRX2        (SUNXI_GIC_START + 150) /*      COMMRX2         */
#define A3X_IRQ_COMMRX3        (SUNXI_GIC_START + 151) /*      COMMRX3         */
#define A3X_IRQ_PMU0           (SUNXI_GIC_START + 152) /*      PMU0            */
#define A3X_IRQ_PMU1           (SUNXI_GIC_START + 153) /*      PMU1            */
#define A3X_IRQ_PMU2           (SUNXI_GIC_START + 154) /*      PMU2            */
#define A3X_IRQ_PMU3           (SUNXI_GIC_START + 155) /*      PMU3            */
#define A3X_IRQ_AXI_ERROR      (SUNXI_GIC_START + 156) /*      AXI_ERROR       */

/* Total number of interrupts */
#define A3X_IRQ_MAX            (A3X_IRQ_AXI_ERROR + 1)
#define A3X_IRQ_UART_DEBUG     (A3X_IRQ_UART0)

#define A3X_IRQ_NINT       A3X_IRQ_MAX
#define A3X_PIO_NINT       0

/* Total number of IRQ numbers */

#define NR_IRQS            (A3X_IRQ_NINT + A3X_PIO_NINT)


/****************************************************************************************
 * Public Types
 ****************************************************************************************/

/****************************************************************************************
 * Inline functions
 ****************************************************************************************/

/****************************************************************************************
 * Public Data
 ****************************************************************************************/

/****************************************************************************************
 * Public Function Prototypes
 ****************************************************************************************/

#ifndef __ASSEMBLY__
#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#undef EXTERN
#ifdef __cplusplus
}
#endif
#endif

#endif /* __ARCH_ARM_INCLUDE_A3X_A33_IRQ_H */

