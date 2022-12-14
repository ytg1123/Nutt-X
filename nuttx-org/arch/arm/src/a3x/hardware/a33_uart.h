/************************************************************************************
 * arch/arm/src/a33/hardware/a33_uart.h
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

#ifndef __ARCH_ARM_SRC_A33_HARDWARE_A3X_UART_H
#define __ARCH_ARM_SRC_A33_HARDWARE_A3X_UART_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include "hardware/a3x_memorymap.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Register offsets *****************************************************************/

#define A33_UART_RBR_OFFSET       0x0000 /* UART Receive Buffer Register */
#define A33_UART_THR_OFFSET       0x0000 /* UART Transmit Holding Register */
#define A33_UART_DLL_OFFSET       0x0000 /* UART Divisor Latch Low Register */
#define A33_UART_DLH_OFFSET       0x0004 /* UART Divisor Latch High Register */
#define A33_UART_IER_OFFSET       0x0004 /* UART Interrupt Enable Register */
#define A33_UART_IIR_OFFSET       0x0008 /* UART Interrupt Identity Register */
#define A33_UART_FCR_OFFSET       0x0008 /* UART FIFO Control Register */
#define A33_UART_LCR_OFFSET       0x000c /* UART Line Control Register */
#define A33_UART_MCR_OFFSET       0x0010 /* UART Modem Control Register */
#define A33_UART_LSR_OFFSET       0x0014 /* UART Line Status Register */
#define A33_UART_MSR_OFFSET       0x0018 /* UART Modem Status Register */
#define A33_UART_SCH_OFFSET       0x001c /* UART Scratch Register */
#define A33_UART_USR_OFFSET       0x007c /* UART Status Register */
#define A33_UART_TFL_OFFSET       0x0080 /* UART Transmit FIFO Level */
#define A33_UART_RFL_OFFSET       0x0084 /* UART Receive FIFO Level */
#define A33_UART_HALT_OFFSET      0x00a4 /* UART Halt TX Register */

/* Register virtual addresses *******************************************************/

#define A33_UART_RBR(n)           (A33_UART_VADDR(n)+A33UART_RBR_OFFSET)
#define A33_UART_THR(n)           (A33_UART_VADDR(n)+A33UART_THR_OFFSET)
#define A33_UART_DLL(n)           (A33_UART_VADDR(n)+A33UART_DLL_OFFSET)
#define A33_UART_DLH(n)           (A33_UART_VADDR(n)+A33UART_DLH_OFFSET)
#define A33_UART_IER(n)           (A33_UART_VADDR(n)+A33UART_IER_OFFSET)
#define A33_UART_IIR(n)           (A33_UART_VADDR(n)+A33UART_IIR_OFFSET)
#define A33_UART_FCR(n)           (A33_UART_VADDR(n)+A33UART_FCR_OFFSET)
#define A33_UART_LCR(n)           (A33_UART_VADDR(n)+A33UART_LCR_OFFSET)
#define A33_UART_MCR(n)           (A33_UART_VADDR(n)+A33UART_MCR_OFFSET)
#define A33_UART_LSR(n)           (A33_UART_VADDR(n)+A33UART_LSR_OFFSET)
#define A33_UART_MSR(n)           (A33_UART_VADDR(n)+A33UART_MSR_OFFSET)
#define A33_UART_SCH(n)           (A33_UART_VADDR(n)+A33UART_SCH_OFFSET)
#define A33_UART_USR(n)           (A33_UART_VADDR(n)+A33UART_USR_OFFSET)
#define A33_UART_TFL(n)           (A33_UART_VADDR(n)+A33UART_TFL_OFFSET)
#define A33_UART_RFL(n)           (A33_UART_VADDR(n)+A33UART_RFL_OFFSET)
#define A33_UART_HALT(n)          (A33_UART_VADDR(n)+A33UART_HALT_OFFSET)

#define A33_UART0_RBR             (A33_UART0_VADDR+A33UART_RBR_OFFSET)
#define A33_UART0_THR             (A33_UART0_VADDR+A33UART_THR_OFFSET)
#define A33_UART0_DLL             (A33_UART0_VADDR+A33UART_DLL_OFFSET)
#define A33_UART0_DLH             (A33_UART0_VADDR+A33UART_DLH_OFFSET)
#define A33_UART0_IER             (A33_UART0_VADDR+A33UART_IER_OFFSET)
#define A33_UART0_IIR             (A33_UART0_VADDR+A33UART_IIR_OFFSET)
#define A33_UART0_FCR             (A33_UART0_VADDR+A33UART_FCR_OFFSET)
#define A33_UART0_LCR             (A33_UART0_VADDR+A33UART_LCR_OFFSET)
#define A33_UART0_MCR             (A33_UART0_VADDR+A33UART_MCR_OFFSET)
#define A33_UART0_LSR             (A33_UART0_VADDR+A33UART_LSR_OFFSET)
#define A33_UART0_MSR             (A33_UART0_VADDR+A33UART_MSR_OFFSET)
#define A33_UART0_SCH             (A33_UART0_VADDR+A33UART_SCH_OFFSET)
#define A33_UART0_USR             (A33_UART0_VADDR+A33UART_USR_OFFSET)
#define A33_UART0_TFL             (A33_UART0_VADDR+A33UART_TFL_OFFSET)
#define A33_UART0_RFL             (A33_UART0_VADDR+A33UART_RFL_OFFSET)
#define A33_UART0_HALT            (A33_UART0_VADDR+A33UART_HALT_OFFSET)

#define A33_UART1_RBR             (A33_UART1_VADDR+A33UART_RBR_OFFSET)
#define A33_UART1_THR             (A33_UART1_VADDR+A33UART_THR_OFFSET)
#define A33_UART1_DLL             (A33_UART1_VADDR+A33UART_DLL_OFFSET)
#define A33_UART1_DLH             (A33_UART1_VADDR+A33UART_DLH_OFFSET)
#define A33_UART1_IER             (A33_UART1_VADDR+A33UART_IER_OFFSET)
#define A33_UART1_IIR             (A33_UART1_VADDR+A33UART_IIR_OFFSET)
#define A33_UART1_FCR             (A33_UART1_VADDR+A33UART_FCR_OFFSET)
#define A33_UART1_LCR             (A33_UART1_VADDR+A33UART_LCR_OFFSET)
#define A33_UART1_MCR             (A33_UART1_VADDR+A33UART_MCR_OFFSET)
#define A33_UART1_LSR             (A33_UART1_VADDR+A33UART_LSR_OFFSET)
#define A33_UART1_MSR             (A33_UART1_VADDR+A33UART_MSR_OFFSET)
#define A33_UART1_SCH             (A33_UART1_VADDR+A33UART_SCH_OFFSET)
#define A33_UART1_USR             (A33_UART1_VADDR+A33UART_USR_OFFSET)
#define A33_UART1_TFL             (A33_UART1_VADDR+A33UART_TFL_OFFSET)
#define A33_UART1_RFL             (A33_UART1_VADDR+A33UART_RFL_OFFSET)
#define A33_UART1_HALT            (A33_UART1_VADDR+A33UART_HALT_OFFSET)

#define A33_UART2_RBR             (A33_UART2_VADDR+A33UART_RBR_OFFSET)
#define A33_UART2_THR             (A33_UART2_VADDR+A33UART_THR_OFFSET)
#define A33_UART2_DLL             (A33_UART2_VADDR+A33UART_DLL_OFFSET)
#define A33_UART2_DLH             (A33_UART2_VADDR+A33UART_DLH_OFFSET)
#define A33_UART2_IER             (A33_UART2_VADDR+A33UART_IER_OFFSET)
#define A33_UART2_IIR             (A33_UART2_VADDR+A33UART_IIR_OFFSET)
#define A33_UART2_FCR             (A33_UART2_VADDR+A33UART_FCR_OFFSET)
#define A33_UART2_LCR             (A33_UART2_VADDR+A33UART_LCR_OFFSET)
#define A33_UART2_MCR             (A33_UART2_VADDR+A33UART_MCR_OFFSET)
#define A33_UART2_LSR             (A33_UART2_VADDR+A33UART_LSR_OFFSET)
#define A33_UART2_MSR             (A33_UART2_VADDR+A33UART_MSR_OFFSET)
#define A33_UART2_SCH             (A33_UART2_VADDR+A33UART_SCH_OFFSET)
#define A33_UART2_USR             (A33_UART2_VADDR+A33UART_USR_OFFSET)
#define A33_UART2_TFL             (A33_UART2_VADDR+A33UART_TFL_OFFSET)
#define A33_UART2_RFL             (A33_UART2_VADDR+A33UART_RFL_OFFSET)
#define A33_UART2_HALT            (A33_UART2_VADDR+A33UART_HALT_OFFSET)

#define A33_UART3_RBR             (A33_UART3_VADDR+A33UART_RBR_OFFSET)
#define A33_UART3_THR             (A33_UART3_VADDR+A33UART_THR_OFFSET)
#define A33_UART3_DLL             (A33_UART3_VADDR+A33UART_DLL_OFFSET)
#define A33_UART3_DLH             (A33_UART3_VADDR+A33UART_DLH_OFFSET)
#define A33_UART3_IER             (A33_UART3_VADDR+A33UART_IER_OFFSET)
#define A33_UART3_IIR             (A33_UART3_VADDR+A33UART_IIR_OFFSET)
#define A33_UART3_FCR             (A33_UART3_VADDR+A33UART_FCR_OFFSET)
#define A33_UART3_LCR             (A33_UART3_VADDR+A33UART_LCR_OFFSET)
#define A33_UART3_MCR             (A33_UART3_VADDR+A33UART_MCR_OFFSET)
#define A33_UART3_LSR             (A33_UART3_VADDR+A33UART_LSR_OFFSET)
#define A33_UART3_MSR             (A33_UART3_VADDR+A33UART_MSR_OFFSET)
#define A33_UART3_SCH             (A33_UART3_VADDR+A33UART_SCH_OFFSET)
#define A33_UART3_USR             (A33_UART3_VADDR+A33UART_USR_OFFSET)
#define A33_UART3_TFL             (A33_UART3_VADDR+A33UART_TFL_OFFSET)
#define A33_UART3_RFL             (A33_UART3_VADDR+A33UART_RFL_OFFSET)
#define A33_UART3_HALT            (A33_UART3_VADDR+A33UART_HALT_OFFSET)

#define A33_UART4_RBR             (A33_UART4_VADDR+A33UART_RBR_OFFSET)
#define A33_UART4_THR             (A33_UART4_VADDR+A33UART_THR_OFFSET)
#define A33_UART4_DLL             (A33_UART4_VADDR+A33UART_DLL_OFFSET)
#define A33_UART4_DLH             (A33_UART4_VADDR+A33UART_DLH_OFFSET)
#define A33_UART4_IER             (A33_UART4_VADDR+A33UART_IER_OFFSET)
#define A33_UART4_IIR             (A33_UART4_VADDR+A33UART_IIR_OFFSET)
#define A33_UART4_FCR             (A33_UART4_VADDR+A33UART_FCR_OFFSET)
#define A33_UART4_LCR             (A33_UART4_VADDR+A33UART_LCR_OFFSET)
#define A33_UART4_MCR             (A33_UART4_VADDR+A33UART_MCR_OFFSET)
#define A33_UART4_LSR             (A33_UART4_VADDR+A33UART_LSR_OFFSET)
#define A33_UART4_MSR             (A33_UART4_VADDR+A33UART_MSR_OFFSET)
#define A33_UART4_SCH             (A33_UART4_VADDR+A33UART_SCH_OFFSET)
#define A33_UART4_USR             (A33_UART4_VADDR+A33UART_USR_OFFSET)
#define A33_UART4_TFL             (A33_UART4_VADDR+A33UART_TFL_OFFSET)
#define A33_UART4_RFL             (A33_UART4_VADDR+A33UART_RFL_OFFSET)
#define A33_UART4_HALT            (A33_UART4_VADDR+A33UART_HALT_OFFSET)

#define A33_UART5_RBR             (A33_UART5_VADDR+A33UART_RBR_OFFSET)
#define A33_UART5_THR             (A33_UART5_VADDR+A33UART_THR_OFFSET)
#define A33_UART5_DLL             (A33_UART5_VADDR+A33UART_DLL_OFFSET)
#define A33_UART5_DLH             (A33_UART5_VADDR+A33UART_DLH_OFFSET)
#define A33_UART5_IER             (A33_UART5_VADDR+A33UART_IER_OFFSET)
#define A33_UART5_IIR             (A33_UART5_VADDR+A33UART_IIR_OFFSET)
#define A33_UART5_FCR             (A33_UART5_VADDR+A33UART_FCR_OFFSET)
#define A33_UART5_LCR             (A33_UART5_VADDR+A33UART_LCR_OFFSET)
#define A33_UART5_MCR             (A33_UART5_VADDR+A33UART_MCR_OFFSET)
#define A33_UART5_LSR             (A33_UART5_VADDR+A33UART_LSR_OFFSET)
#define A33_UART5_MSR             (A33_UART5_VADDR+A33UART_MSR_OFFSET)
#define A33_UART5_SCH             (A33_UART5_VADDR+A33UART_SCH_OFFSET)
#define A33_UART5_USR             (A33_UART5_VADDR+A33UART_USR_OFFSET)
#define A33_UART5_TFL             (A33_UART5_VADDR+A33UART_TFL_OFFSET)
#define A33_UART5_RFL             (A33_UART5_VADDR+A33UART_RFL_OFFSET)
#define A33_UART5_HALT            (A33_UART5_VADDR+A33UART_HALT_OFFSET)

#define A33_UART6_RBR             (A33_UART6_VADDR+A33UART_RBR_OFFSET)
#define A33_UART6_THR             (A33_UART6_VADDR+A33UART_THR_OFFSET)
#define A33_UART6_DLL             (A33_UART6_VADDR+A33UART_DLL_OFFSET)
#define A33_UART6_DLH             (A33_UART6_VADDR+A33UART_DLH_OFFSET)
#define A33_UART6_IER             (A33_UART6_VADDR+A33UART_IER_OFFSET)
#define A33_UART6_IIR             (A33_UART6_VADDR+A33UART_IIR_OFFSET)
#define A33_UART6_FCR             (A33_UART6_VADDR+A33UART_FCR_OFFSET)
#define A33_UART6_LCR             (A33_UART6_VADDR+A33UART_LCR_OFFSET)
#define A33_UART6_MCR             (A33_UART6_VADDR+A33UART_MCR_OFFSET)
#define A33_UART6_LSR             (A33_UART6_VADDR+A33UART_LSR_OFFSET)
#define A33_UART6_MSR             (A33_UART6_VADDR+A33UART_MSR_OFFSET)
#define A33_UART6_SCH             (A33_UART6_VADDR+A33UART_SCH_OFFSET)
#define A33_UART6_USR             (A33_UART6_VADDR+A33UART_USR_OFFSET)
#define A33_UART6_TFL             (A33_UART6_VADDR+A33UART_TFL_OFFSET)
#define A33_UART6_RFL             (A33_UART6_VADDR+A33UART_RFL_OFFSET)
#define A33_UART6_HALT            (A33_UART6_VADDR+A33UART_HALT_OFFSET)

#define A33_UART7_RBR             (A33_UART7_VADDR+A33UART_RBR_OFFSET)
#define A33_UART7_THR             (A33_UART7_VADDR+A33UART_THR_OFFSET)
#define A33_UART7_DLL             (A33_UART7_VADDR+A33UART_DLL_OFFSET)
#define A33_UART7_DLH             (A33_UART7_VADDR+A33UART_DLH_OFFSET)
#define A33_UART7_IER             (A33_UART7_VADDR+A33UART_IER_OFFSET)
#define A33_UART7_IIR             (A33_UART7_VADDR+A33UART_IIR_OFFSET)
#define A33_UART7_FCR             (A33_UART7_VADDR+A33UART_FCR_OFFSET)
#define A33_UART7_LCR             (A33_UART7_VADDR+A33UART_LCR_OFFSET)
#define A33_UART7_MCR             (A33_UART7_VADDR+A33UART_MCR_OFFSET)
#define A33_UART7_LSR             (A33_UART7_VADDR+A33UART_LSR_OFFSET)
#define A33_UART7_MSR             (A33_UART7_VADDR+A33UART_MSR_OFFSET)
#define A33_UART7_SCH             (A33_UART7_VADDR+A33UART_SCH_OFFSET)
#define A33_UART7_USR             (A33_UART7_VADDR+A33UART_USR_OFFSET)
#define A33_UART7_TFL             (A33_UART7_VADDR+A33UART_TFL_OFFSET)
#define A33_UART7_RFL             (A33_UART7_VADDR+A33UART_RFL_OFFSET)
#define A33_UART7_HALT            (A33_UART7_VADDR+A33UART_HALT_OFFSET)

/* Register bit field definitions ***************************************************/

/* UART Receive Buffer Register */

#define UART_RBR_MASK             0x000000ff

/* UART Transmit Holding Register */

#define UART_THR_MASK             0x000000ff

/* UART Divisor Latch Low Register */

#define UART_DLL_MASK             0x000000ff

/* UART Divisor Latch High Register */

#define UART_DLH_MASK             0x000000ff

/* UART Interrupt Enable Register */

#define UART_IER_ERBFI            (1 << 0) /* Bit 0:  Enable Received Data Available Interrupt */
#define UART_IER_ETBEI            (1 << 1) /* Bit 1:  Enable Transmit Holding Register Empty Interrupt */
#define UART_IER_ELSI             (1 << 2) /* Bit 2:  Enable Receiver Line Status Interrupt */
#define UART_IER_EDSSI            (1 << 3) /* Bit 3:  Enable Modem Status Interrupt */
#define UART_IER_PTIME            (1 << 7) /* Bit 7:  Programmable THRE Interrupt Mode Enable */
#define UART_IER_ALLIE            0x0000008f

/* UART Interrupt Identity Register */

#define UART_IIR_IID_SHIFT        (0) /* Bits: 0-3: Interrupt ID */
#define UART_IIR_IID_MASK         (15 << UART_IIR_IID_SHIFT)
#  define UART_IIR_IID_MODEM      (0 << UART_IIR_IID_SHIFT)  /* Modem status */
#  define UART_IIR_IID_NONE       (1 << UART_IIR_IID_SHIFT)  /* No interrupt pending */
#  define UART_IIR_IID_TXEMPTY    (2 << UART_IIR_IID_SHIFT)  /* THR empty */
#  define UART_IIR_IID_RECV       (4 << UART_IIR_IID_SHIFT)  /* Received data available */
#  define UART_IIR_IID_LINESTATUS (6 << UART_IIR_IID_SHIFT)  /* Receiver line status */
#  define UART_IIR_IID_BUSY       (7 << UART_IIR_IID_SHIFT)  /* Busy detect */
#  define UART_IIR_IID_TIMEOUT    (12 << UART_IIR_IID_SHIFT) /* Character timeout */
#define UART_IIR_FEFLAG_SHIFT     (6) /* Bits 6-7: FIFOs Enable Flag */
#define UART_IIR_FEFLAG_MASK      (3 << UART_IIR_FEFLAG_SHIFT)
#  define UART_IIR_FEFLAG_DISABLE (0 << UART_IIR_FEFLAG_SHIFT)
#  define UART_IIR_FEFLAG_ENABLE  (3 << UART_IIR_FEFLAG_SHIFT)

/* UART FIFO Control Register */

#define UART_FCR_FIFOE            (1 << 0)  /* Bit 0:  Enable FIFOs */
#define UART_FCR_RFIFOR           (1 << 1)  /* Bit 1:  RCVR FIFO Reset */
#define UART_FCR_XFIFOR           (1 << 2)  /* Bit 2:  XMIT FIFO reset */
#define UART_FCR_DMAM             (1 << 3)  /* Bit 3:  DMA mode */
#define UART_FCR_TFT_SHIFT        (4)       /* Bits 4-5: TX Empty Trigger */
#define UART_FCR_TFT_MASK         (3 << UART_FCR_TFT_SHIFT)
#  define UART_FCR_TFT_EMPTY      (0 << UART_FCR_TFT_SHIFT) /* FIFO empty */
#  define UART_FCR_TFT_TWO        (1 << UART_FCR_TFT_SHIFT) /* 2 characters in the FIFO */
#  define UART_FCR_TFT_QUARTER    (2 << UART_FCR_TFT_SHIFT) /* FIFO 1/4 full */
#  define UART_FCR_TFT_HALF       (3 << UART_FCR_TFT_SHIFT) /* FIFO 1/2 full */
#define UART_FCR_RT_SHIFT         (6)       /* Bits 6-7: RCVR Trigger */
#define UART_FCR_RT_MASK          (3 << UART_FCR_RT_SHIFT)
#  define UART_FCR_RT_ONE         (0 << UART_FCR_RT_SHIFT) /* 1 character in the FIFO */
#  define UART_FCR_RT_QUARTER     (1 << UART_FCR_RT_SHIFT) /* FIFO 1/4 full */
#  define UART_FCR_RT_HALF        (2 << UART_FCR_RT_SHIFT) /* FIFO 1/2 full */
#  define UART_FCR_RT_MINUS2      (3 << UART_FCR_RT_SHIFT) /* FIFO-2 less than full */

/* UART Line Control Register */

#define UART_LCR_DLS_SHIFT        (0)       /* Bits 0-1: Data Length Select */
#define UART_LCR_DLS_MASK         (3 << UART_LCR_DLS_SHIFT)
#  define UART_LCR_DLS_5BITS      (0 << UART_LCR_DLS_SHIFT) /* 5 bits */
#  define UART_LCR_DLS_6BITS      (1 << UART_LCR_DLS_SHIFT) /* 6 bits */
#  define UART_LCR_DLS_7BITS      (2 << UART_LCR_DLS_SHIFT) /* 7 bits */
#  define UART_LCR_DLS_8BITS      (3 << UART_LCR_DLS_SHIFT) /* 8 bits */
#define UART_LCR_STOP             (1 << 2)  /* Bit 2:  Number of stop bits */
#define UART_LCR_PEN              (1 << 3)  /* Bit 3:  Parity Enable */
#define UART_LCR_EPS              (1 << 4)  /* Bit 4:  Even Parity Select */
#define UART_LCR_BC               (1 << 6)  /* Bit 6:  Break Control Bit */
#define UART_LCR_DLAB             (1 << 7)  /* Bit 7:  Divisor Latch Access Bit */

/* UART Modem Control Register */

#define UART_MCR_DTR              (1 << 0)  /* Bit 0:  Data Terminal Ready */
#define UART_MCR_RTS              (1 << 1)  /* Bit 1:  Request to Send */
#define UART_MCR_LOOP             (1 << 4)  /* Bit 4:  Loop Back Mode */
#define UART_MCR_AFCE             (1 << 5)  /* Bit 5:  Auto Flow Control Enable */
#define UART_MCR_SIRE             (1 << 6)  /* Bit 6:  SIR Mode Enable */

/* UART Line Status Register */

#define UART_LSR_DR               (1 << 0) /* Bit 0:  Data Ready */
#define UART_LSR_OE               (1 << 1) /* Bit 1:  Overrun Error */
#define UART_LSR_PE               (1 << 2) /* Bit 2:  Parity Error */
#define UART_LSR_FE               (1 << 3) /* Bit 3:  Framing Error */
#define UART_LSR_BI               (1 << 4) /* Bit 4:  Break Interrupt */
#define UART_LSR_THRE             (1 << 5) /* Bit 5:  TX Holding Register Empty */
#define UART_LSR_TEMT             (1 << 6) /* Bit 6:  Transmitter Empty */
#define UART_LSR_FIFOERR          (1 << 7) /* Bit 7:  RX Data Error in FIFO */

/* UART Modem Status Register */

#define UART_MSR_DCTS             (1 << 0)  /* Bit 0:  Delta Clear to Send */
#define UART_MSR_DDSR             (1 << 1)  /* Bit 1:  Delta Data Set Ready */
#define UART_MSR_TERI             (1 << 2)  /* Bit 2:  Trailing Edge Ring Indicator */
#define UART_MSR_DDCD             (1 << 3)  /* Bit 3:  Delta Data Carrier Detect */
#define UART_MSR_CTS              (1 << 4)  /* Bit 4:  Line State of Clear To Send */
#define UART_MSR_DSR              (1 << 5)  /* Bit 5:  Line State of Data Set Ready */
#define UART_MSR_RI               (1 << 6)  /* Bit 6:  Line State of Ring Indicator */
#define UART_MSR_DCD              (1 << 7)  /* Bit 7:  Line State of Data Carrier Detect */

/* UART Scratch Register */

#define UART_SCH_MASK             0x000000ff

/* UART Status Register */

#define UART_USR_BUSY             (1 << 0)  /* Bit 0: UART Busy Bit */
#define UART_USR_TFNF             (1 << 1)  /* Bit 1: Transmit FIFO Not Full */
#define UART_USR_TFE              (1 << 2)  /* Bit 2: Transmit FIFO Empty */
#define UART_USR_RFNE             (1 << 3)  /* Bit 3: Receive FIFO Not Empty */
#define UART_USR_RFF              (1 << 4)  /* Bit 4:  Receive FIFO Full */

/* UART Transmit FIFO Level */

#define UART_TFL_SHIFT            (0)       /* Bits 0-6: Transmit FIFO Level */
#define UART_TFL_MASK             (0x7f << UART_TFL_SHIFT)
#  define UART_TFL(n)             ((uint32_t)(n) << UART_TFL_SHIFT)

/* UART Receive FIFO Level */

#define UART_RFL_SHIFT            (0) /* Bits 0-6: Receive FIFO Level */
#define UART_RFL_MASK             (0x7f << UART_RFL_SHIFT)
#  define UART_RFL(n)             ((uint32_t)(n) << UART_RFL_SHIFT)

/* UART Halt TX Register */

#define UART_HALT_HALT_TX         (1 << 0)  /* Bit 0:  Halt TX */
#define UART_HALT_SIR_TX_INVERT   (1 << 4)  /* Bit 4:  SIR Transmit Pulse Polarity Invert */
#define UART_HALT_SIR_RX_INVERT   (1 << 5)  /* Bit 5:  SIR Receiver Pulse Polarity Invert */

#endif /* __ARCH_ARM_SRC_A33_HARDWARE_A33_UART_H */
