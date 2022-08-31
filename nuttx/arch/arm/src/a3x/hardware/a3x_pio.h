/************************************************************************************
 * arch/arm/src/a33/hardware/a3x_pio.h
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_A3X_HARDWARE_A3X_PIO_H
#define __ARCH_ARM_SRC_A3X_HARDWARE_A3X_PIO_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include "hardware/a3x_memorymap.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

#define PIO_REG_PORTA         0 
#define PIO_REG_PORTB         1
#define PIO_REG_PORTC         2
#define PIO_REG_PORTD         3
#define PIO_REG_PORTE         4
#define PIO_REG_PORTF         5
#define PIO_REG_PORTG         6
#define PIO_REG_PORTH         7

#define PIO_REG_CFG_INPUT     0
#define PIO_REG_CFG_OUTPUT    1

#define PIO_REG_DRV_LEVEL0    0
#define PIO_REG_DRV_LEVEL1    1
#define PIO_REG_DRV_LEVEL2    2
#define PIO_REG_DRV_LEVEL3    3

#define PIO_REG_PULL_NONE     0
#define PIO_REG_PULL_UP       1
#define PIO_REG_PULL_DOWN     2

#define PIO_REG_INT_POSEDGE   0
#define PIO_REG_INT_NEGEDGE   1
#define PIO_REG_INT_HILEVEL   2
#define PIO_REG_INT_LOWLEVEL  3
#define PIO_REG_INT_BOTHEDGES 4

/* Register offsets *****************************************************************/

#define A3X_PIO_CFG0_OFFSET(n)    (0x0000 + (n)*0x24) /* Port Configure Register 0, n=1-7 */
#define A3X_PIO_CFG1_OFFSET(n)    (0x0004 + (n)*0x24) /* Port Configure Register 1, n=1-7 */
#define A3X_PIO_CFG2_OFFSET(n)    (0x0008 + (n)*0x24) /* Port Configure Register 2, n=1-7 */
#define A3X_PIO_CFG3_OFFSET(n)    (0x000c + (n)*0x24) /* Port Configure Register 3, n=1-7 */
#define A3X_PIO_DAT_OFFSET(n)     (0x0010 + (n)*0x24) /* Port Data Register, n=1-7 */
#define A3X_PIO_DRV0_OFFSET(n)    (0x0014 + (n)*0x24) /* Port Multi-Driving Register 0, n=1-7 */
#define A3X_PIO_DRV1_OFFSET(n)    (0x0018 + (n)*0x24) /* Port Multi-Driving Register 1, n=1-7 */
#define A3X_PIO_PUL0_OFFSET(n)    (0x001c + (n)*0x24) /* Port Pull Register 0, n=1-7 */
#define A3X_PIO_PUL1_OFFSET(n)    (0x0020 + (n)*0x24) /* Port Pull Register 1, n=1-7 */
#define A3X_PIO_INT_CFG0_OFFSET(n) (0x0200 + (n)*0x20 + 0x00) /* PIO Interrupt Configure Register 0 */
#define A3X_PIO_INT_CFG1_OFFSET(n) (0x0200 + (n)*0x20 + 0x04) /* PIO Interrupt Configure Register 1 */
#define A3X_PIO_INT_CFG2_OFFSET(n) (0x0200 + (n)*0x20 + 0x08) /* PIO Interrupt Configure Register 2 */
#define A3X_PIO_INT_CFG3_OFFSET(n) (0x0200 + (n)*0x20 + 0x0c) /* PIO Interrupt Configure Register 3 */
#define A3X_PIO_INT_CTL_OFFSET(n)  (0x0200 + (n)*0x20 + 0x10) /* PIO Interrupt Control Register */
#define A3X_PIO_INT_STA_OFFSET(n)  (0x0200 + (n)*0x20 + 0x14) /* PIO Interrupt Status Register */
#define A3X_PIO_INT_DEB_OFFSET(n)  (0x0200 + (n)*0x20 + 0x18) /* PIO Interrupt Debounce Register */

#define PIO_REG_CFG(n, i)               ((volatile unsigned int *)( A3X_PIO_PADDR + ((n)-1)*0x24 + ((i)<<2) + 0x00))
#define PIO_REG_DLEVEL(n, i)            ((volatile unsigned int *)( A3X_PIO_PADDR + ((n)-1)*0x24 + ((i)<<2) + 0x14))
#define PIO_REG_PULL(n, i)              ((volatile unsigned int *)( A3X_PIO_PADDR + ((n)-1)*0x24 + ((i)<<2) + 0x1C))
#define PIO_REG_DATA(n)                 ((volatile unsigned int *)( A3X_PIO_PADDR + ((n)-1)*0x24 + 0x10))

#define PIO_REG_CFG_VALUE(n, i)          readl(A3X_PIO_PADDR  + ((n)-1)*0x24 + ((i)<<2) + 0x00)
#define PIO_REG_DLEVEL_VALUE(n, i)       readl(A3X_PIO_PADDR  + ((n)-1)*0x24 + ((i)<<2) + 0x14)
#define PIO_REG_PULL_VALUE(n, i)         readl(A3X_PIO_PADDR  + ((n)-1)*0x24 + ((i)<<2) + 0x1C)
#define PIO_REG_DATA_VALUE(n)            readl(A3X_PIO_PADDR  + ((n)-1)*0x24 + 0x10)
#define PIO_REG_BASE(n)                  ((volatile unsigned int *)(A3X_PIO_PADDR +((n)-1)*24))

#ifdef A3X_R_PIO_PARRD
#define R_PIO_REG_CFG(n, i)               ((volatile unsigned int *)( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x00))
#define R_PIO_REG_DLEVEL(n, i)            ((volatile unsigned int *)( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x14))
#define R_PIO_REG_PULL(n, i)              ((volatile unsigned int *)( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x1C))
#define R_PIO_REG_DATA(n)                 ((volatile unsigned int *)( A3X_R_PIO_PADDR + ((n)-12)*0x24 + 0x10))

#define R_PIO_REG_CFG_VALUE(n, i)         readl( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x00)
#define R_PIO_REG_DLEVEL_VALUE(n, i)      readl( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x14)
#define R_PIO_REG_PULL_VALUE(n, i)        readl( A3X_R_PIO_PADDR + ((n)-12)*0x24 + ((i)<<2) + 0x1C)
#define R_PIO_REG_DATA_VALUE(n)           readl( A3X_R_PIO_PADDR + ((n)-12)*0x24 + 0x10)
#define R_PIO_REG_BASE(n)                 ((volatile unsigned int *)( A3X_R_PIO_PADDR +((n)-12)*24))
#endif

/* Register virtual addresses *******************************************************/

#define A3X_PIO_CFG0(n)           (A3X_PIO_VADDR+A3X_PIO_CFG0_OFFSET(n))
#define A3X_PIO_CFG1(n)           (A3X_PIO_VADDR+A3X_PIO_CFG1_OFFSET(n))
#define A3X_PIO_CFG2(n)           (A3X_PIO_VADDR+A3X_PIO_CFG2_OFFSET(n))
#define A3X_PIO_CFG3(n)           (A3X_PIO_VADDR+A3X_PIO_CFG3_OFFSET(n))
#define A3X_PIO_DAT(n)            (A3X_PIO_VADDR+A3X_PIO_DAT_OFFSET(n))
#define A3X_PIO_DRV0(n)           (A3X_PIO_VADDR+A3X_PIO_DRV0_OFFSET(n))
#define A3X_PIO_DRV1(n)           (A3X_PIO_VADDR+A3X_PIO_DRV1_OFFSET(n))
#define A3X_PIO_PUL0(n)           (A3X_PIO_VADDR+A3X_PIO_PUL0_OFFSET(n))
#define A3X_PIO_PUL1(n)           (A3X_PIO_VADDR+A3X_PIO_PUL1_OFFSET(n))
#define A3X_PIO_INT_CFG0(n)       (A3X_PIO_VADDR+A3X_PIO_INT_CFG0_OFFSET(n))
#define A3X_PIO_INT_CFG1(n)       (A3X_PIO_VADDR+A3X_PIO_INT_CFG1_OFFSET(n))
#define A3X_PIO_INT_CFG2(n)       (A3X_PIO_VADDR+A3X_PIO_INT_CFG2_OFFSET(n))
#define A3X_PIO_INT_CFG3(n)       (A3X_PIO_VADDR+A3X_PIO_INT_CFG3_OFFSET(n))
#define A3X_PIO_INT_CTL(n)        (A3X_PIO_VADDR+A3X_PIO_INT_CTL_OFFSET(n))
#define A3X_PIO_INT_STA(n)        (A3X_PIO_VADDR+A3X_PIO_INT_STA_OFFSET(n))
#define A3X_PIO_INT_DEB(n)        (A3X_PIO_VADDR+A3X_PIO_INT_DEB_OFFSET(n))

/* Register bit field definitions ***************************************************/

/* Port Configure Register 0, n=0-7 */

#define PIO_CFG0_SHIFT(n)         ((n) << 2)
#define PIO_CFG0_MASK(n)          (7 << PIO_CFG0_SHIFT(n))
#  define PIO_CFG0(m,v)           ((uint32_t)(v) << PIO_CFG0_SHIFT(n))

/* Port Configure Register 1, n=8-15 */

#define PIO_CFG1_SHIFT(n)         (((n) - 8) << 2)
#define PIO_CFG1_MASK(n)          (7 << PIO_CFG1_SHIFT(n))
#  define PIO_CFG1(m,v)           ((uint32_t)(v) << PIO_CFG1_SHIFT(n))

/* Port Configure Register 2, n=16-23 */

#define PIO_CFG2_SHIFT(n)         (((n) - 16) << 2)
#define PIO_CFG2_MASK(n)          (7 << PIO_CFG2_SHIFT(n))
#  define PIO_CFG2(m,v)           ((uint32_t)(v) << PIO_CFG2_SHIFT(n))

/* Port Configure Register 3, n=24-31 */

#define PIO_CFG3_SHIFT(n)         (((n) - 24) << 2)
#define PIO_CFG3_MASK(n)          (7 << PIO_CFG3_SHIFT(n))
#  define PIO_CFG3(m,v)           ((uint32_t)(v) << PIO_CFG3_SHIFT(n))

/* Port n Data Register, n=0-9 */

#define PIO_DAT(n)                 (1 << (n)) /* PA data, n=0-31 */

/* Port n Multi-Driving Register 0, n=0-9 */

#define PIO_DRV0_SHIFT(n)          ((n) << 1) /* PA DRV0, n=0-15 */
#define PIO_DRV0_MASK(n)           (3 << PIO_DRV0_SHIFT(n))
#  define PIO_DRV0(n,v)            ((uint32_t)(v) << PIO_DRV0_SHIFT(n))

/* Port n Multi-Driving Register 1, n=0-9 */

#define PIO_DRV1_SHIFT(n)          (((n) - 16) << 1) /* PA DRV1, n=16-31 */
#define PIO_DRV1_MASK(n)           (3 << PIO_DRV1_SHIFT(n))
#  define PIO_DRV1(n,v)            ((uint32_t)(v) << PIO_DRV1_SHIFT(n))

/* Port n Pull Register 0, n=0-9 */

#define PIO_PUL0_SHIFT(n)          ((n) << 1) /* PA PUL0, n=0-15 */
#define PIO_PUL0_MASK(n)           (3 << PIO_PUL0_SHIFT(n))
#  define PIO_PUL0(n,v)            ((uint32_t)(v) << PIO_PUL0_SHIFT(n))

/* Port n Pull Register 1, n=0-9 */

#define PIO_PUL1_SHIFT(n)          (((n) - 16) << 1) /* PA PUL1, n=16-31 */
#define PIO_PUL1_MASK(n)           (3 << PIO_PUL1_SHIFT(n))
#  define PIO_PUL1(n,v)            ((uint32_t)(v) << PIO_PUL1_SHIFT(n))

/* PIO Interrupt Configure Register 0 */

#define PIO_INT_CFG0_SHIFT(n)      ((n) << 2)
#define PIO_INT_CFG0_MASK(n)       (15 << PIO_INT_CFG0_SHIFT(n))
#  define PIO_INT_CFG0(m,v)        ((uint32_t)(v) << PIO_INT_CFG0_SHIFT(n))

/* PIO Interrupt Configure Register 1 */

#define PIO_INT_CFG1_SHIFT(n)      (((n) - 8) << 2)
#define PIO_INT_CFG1_MASK(n)       (15 << PIO_INT_CFG1_SHIFT(n))
#  define PIO_INT_CFG1(m,v)        ((uint32_t)(v) << PIO_INT_CFG1_SHIFT(n))

/* PIO Interrupt Configure Register 2 */

#define PIO_INT_CFG2_SHIFT(n)      (((n) - 16) << 2)
#define PIO_INT_CFG2_MASK(n)       (15 << PIO_INT_CFG2_SHIFT(n))
#  define PIO_INT_CFG2(m,v)        ((uint32_t)(v) << PIO_INT_CFG2_SHIFT(n))

/* PIO Interrupt Configure Register 3 */

#define PIO_INT_CFG3_SHIFT(n)      (((n) - 24) << 2)
#define PIO_INT_CFG3_MASK(n)       (15 << PIO_INT_CFG3_SHIFT(n))
#  define PIO_INT_CFG3(m,v)        ((uint32_t)(v) << PIO_INT_CFG3_SHIFT(n))

/* PIO Interrupt Control Register */

#define PIO_INT_CTL(n)             (1 << (n))

/* PIO Interrupt Status Register */

#define PIO_INT_STA(n)             (1 << (n))

/* PIO Interrupt Debounce Register */

#define PIO_INT_DEB_CLKSEL         (1 << 0)  /* Bit 0: PIO Interrupt Clock Select */
#define PIO_INT_DEB_CLKPRESC_SHIFT (4)       /* Bit 4-6: Debounce Clock Pre-scale */
#define PIO_INT_DEB_CLKPRESC_MASK  (7 << PIO_INT_DEB_CLKPRESC_SHIFT)
#  define PIO_INT_DEB_CLKPRESC(n)  ((uint32_t)(n) << PIO_INT_DEB_CLKPRESC_SHIFT)

/* SDRAM Pad Multi-Driving Register */
/* REVISIT: Missing register bit definitions */

/* SDRAM Pad Pull Register */
/* REVISIT: Missing register bit definitions */

#endif /* __ARCH_ARM_SRC_A3X_HARDWARE_A3X_PIO_H */
