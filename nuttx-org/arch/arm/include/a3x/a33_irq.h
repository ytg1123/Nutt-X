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
#define SUNXI_GIC_START          32
#define A3X_IRQ_UART0          (SUNXI_GIC_START + 0)  /* 32 */
#define A3X_IRQ_UART1          (SUNXI_GIC_START + 1)  /* 33 */
#define A3X_IRQ_UART2          (SUNXI_GIC_START + 2)  /* 34 */
#define A3X_IRQ_UART3          (SUNXI_GIC_START + 3)  /* 35 */
#define A3X_IRQ_UART4          (SUNXI_GIC_START + 4)  /* 36 */
#define A3X_IRQ_UART5          (SUNXI_GIC_START + 5)  /* 37 */
#define A3X_IRQ_TWI0           (SUNXI_GIC_START + 6)  /* 38 */
#define A3X_IRQ_TWI1           (SUNXI_GIC_START + 7)  /* 39 */
#define A3X_IRQ_TWI2           (SUNXI_GIC_START + 8)  /* 40 */
#define A3X_IRQ_EINTA          (SUNXI_GIC_START + 11)  /* 43 */
#define A3X_IRQ_IIS0           (SUNXI_GIC_START + 13)  /* 45 */
#define A3X_IRQ_IIS1           (SUNXI_GIC_START + 14)  /* 46 */
#define A3X_IRQ_EINTB          (SUNXI_GIC_START + 15)  /* 47 */
#define A3X_IRQ_EINTG          (SUNXI_GIC_START + 17)  /* 49 */
#define A3X_IRQ_TIMER0         (SUNXI_GIC_START + 18)  /* 50 */
#define A3X_IRQ_TIMER1         (SUNXI_GIC_START + 19)  /* 51 */
#define A3X_IRQ_WATCHDOG       (SUNXI_GIC_START + 25)  /* 57 */
#define A3X_IRQ_CODEC          (SUNXI_GIC_START + 29)  /* 61*/
#define A3X_IRQ_LRADC          (SUNXI_GIC_START + 30)  /* 62*/
#define A3X_IRQ_THERMAL        (SUNXI_GIC_START + 31)  /* 63*/
#define A3X_IRQ_NMI            (SUNXI_GIC_START + 32)  /* 64 */
#define A3X_IRQ_RTIMER0        (SUNXI_GIC_START + 33)  /* 65 */
#define A3X_IRQ_RTIMER1        (SUNXI_GIC_START + 34)  /* 66 */
#define A3X_IRQ_RWATCHDOG      (SUNXI_GIC_START + 36)  /* 68 */
#define A3X_IRQ_RUART          (SUNXI_GIC_START + 38)  /* 70 */
#define A3X_IRQ_RSB            (SUNXI_GIC_START + 39)  /* 71 */
#define A3X_IRQ_RALARM0        (SUNXI_GIC_START + 40)  /* 72 */
#define A3X_IRQ_RALARM1        (SUNXI_GIC_START + 41)  /* 73 */
#define A3X_IRQ_RTWI           (SUNXI_GIC_START + 44)  /* 76 */
#define A3X_IRQ_EINTL          (SUNXI_GIC_START + 45)  /* 77 */
#define A3X_IRQ_HMIC           (SUNXI_GIC_START + 46)  /* 78 */
#define A3X_IRQ_MBOX           (SUNXI_GIC_START + 49)  /* 81 */
#define A3X_IRQ_DMA            (SUNXI_GIC_START + 50)  /* 82 */
#define A3X_IRQ_HSTMR          (SUNXI_GIC_START + 51)  /* 83 */
#define A3X_IRQ_VE             (SUNXI_GIC_START + 58)  /* 90 */
#define A3X_IRQ_MMC0           (SUNXI_GIC_START + 60)  /* 92 */
#define A3X_IRQ_MMC1           (SUNXI_GIC_START + 61)  /* 93 */
#define A3X_IRQ_MMC2           (SUNXI_GIC_START + 62)  /* 94 */
#define A3X_IRQ_SPI0           (SUNXI_GIC_START + 65)  /* 97 */
#define A3X_IRQ_SPI1           (SUNXI_GIC_START + 66)  /* 98 */
#define A3X_IRQ_NAND           (SUNXI_GIC_START + 70)  /* 102 */
#define A3X_IRQ_USBOTG         (SUNXI_GIC_START + 71)  /* 103 */
#define A3X_IRQ_USBEHCI0       (SUNXI_GIC_START + 72)  /* 104 */
#define A3X_IRQ_USBOHCI0       (SUNXI_GIC_START + 73)  /* 105 */
#define A3X_IRQ_SS             (SUNXI_GIC_START + 80)  /* 112 */
#define A3X_IRQ_CSI            (SUNXI_GIC_START + 84)  /* 116 */
#define A3X_IRQ_CSI_CCI        (SUNXI_GIC_START + 85)  /* 117 */
#define A3X_IRQ_LCD0           (SUNXI_GIC_START + 86)  /* 118 */
#define A3X_IRQ_MIPIDSI        (SUNXI_GIC_START + 89)  /* 121 */
#define A3X_IRQ_DRC            (SUNXI_GIC_START + 91)  /* 123 */
#define A3X_IRQ_DEFE0          (SUNXI_GIC_START + 93)  /* 125 */
#define A3X_IRQ_DEBE0          (SUNXI_GIC_START + 95)  /* 127 */
#define A3X_IRQ_GPUGP          (SUNXI_GIC_START + 97)  /* 129 */
#define A3X_IRQ_GPUGPMMU       (SUNXI_GIC_START + 98)  /* 130 */
#define A3X_IRQ_GPUPP0         (SUNXI_GIC_START + 99)  /* 131 */
#define A3X_IRQ_GPUPPMMU0      (SUNXI_GIC_START + 100) /* 132 */
#define A3X_IRQ_GPUPMU         (SUNXI_GIC_START + 101) /* 133 */
#define A3X_IRQ_GPUPP1         (SUNXI_GIC_START + 102) /* 134 */
#define A3X_IRQ_GPUPPMMU1      (SUNXI_GIC_START + 103) /* 135 */

#define A3X_IRQ_PMU0           (SUNXI_GIC_START + 120) /* 152 */
#define A3X_IRQ_PMU1           (SUNXI_GIC_START + 121) /* 153 */
#define A3X_IRQ_PMU2           (SUNXI_GIC_START + 122) /* 154 */
#define A3X_IRQ_PMU3           (SUNXI_GIC_START + 123) /* 155 */

/* Total number of interrupts */
#define A3X_IRQ_MAX            (SUNXI_GIC_START + 128)
#define A3X_IRQ_UART_DEBUG     (A3X_IRQ_UART0)

#define A3X_IRQ_NINT       128

#ifdef CONFIG_A3X_PIO_IRQ
#  define A3X_PIO_EINT0    (A3X_IRQ_NINT+0)
#  define A3X_PIO_EINT1    (A3X_IRQ_NINT+1)
#  define A3X_PIO_EINT2    (A3X_IRQ_NINT+2)
#  define A3X_PIO_EINT3    (A3X_IRQ_NINT+3)
#  define A3X_PIO_EINT4    (A3X_IRQ_NINT+4)
#  define A3X_PIO_EINT5    (A3X_IRQ_NINT+5)
#  define A3X_PIO_EINT6    (A3X_IRQ_NINT+6)
#  define A3X_PIO_EINT7    (A3X_IRQ_NINT+7)
#  define A3X_PIO_EINT8    (A3X_IRQ_NINT+8)
#  define A3X_PIO_EINT9    (A3X_IRQ_NINT+9)
#  define A3X_PIO_EINT10   (A3X_IRQ_NINT+10)
#  define A3X_PIO_EINT11   (A3X_IRQ_NINT+11)
#  define A3X_PIO_EINT12   (A3X_IRQ_NINT+12)
#  define A3X_PIO_EINT13   (A3X_IRQ_NINT+13)
#  define A3X_PIO_EINT14   (A3X_IRQ_NINT+14)
#  define A3X_PIO_EINT15   (A3X_IRQ_NINT+15)
#  define A3X_PIO_EINT16   (A3X_IRQ_NINT+16)
#  define A3X_PIO_EINT17   (A3X_IRQ_NINT+17)
#  define A3X_PIO_EINT18   (A3X_IRQ_NINT+18)
#  define A3X_PIO_EINT19   (A3X_IRQ_NINT+19)
#  define A3X_PIO_EINT20   (A3X_IRQ_NINT+20)
#  define A3X_PIO_EINT21   (A3X_IRQ_NINT+21)
#  define A3X_PIO_EINT22   (A3X_IRQ_NINT+22)
#  define A3X_PIO_EINT23   (A3X_IRQ_NINT+23)
#  define A3X_PIO_EINT24   (A3X_IRQ_NINT+24)
#  define A3X_PIO_EINT25   (A3X_IRQ_NINT+25)
#  define A3X_PIO_EINT26   (A3X_IRQ_NINT+26)
#  define A3X_PIO_EINT27   (A3X_IRQ_NINT+27)
#  define A3X_PIO_EINT28   (A3X_IRQ_NINT+28)
#  define A3X_PIO_EINT29   (A3X_IRQ_NINT+29)
#  define A3X_PIO_EINT30   (A3X_IRQ_NINT+30)
#  define A3X_PIO_EINT31   (A3X_IRQ_NINT+31)
#  define A3X_PIO_NINT     32
#else
#  define A3X_PIO_NINT     0
#endif

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

