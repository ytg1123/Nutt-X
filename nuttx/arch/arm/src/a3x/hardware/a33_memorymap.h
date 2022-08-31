/************************************************************************************
 * arch/arm/src/a33/hardware/a33_memorymap.h
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

#ifndef __ARCH_ARM_SRC_A3X_HARDWARE_A3X_MEMORYMAP_H
#define __ARCH_ARM_SRC_A3X_HARDWARE_A3X_MEMORYMAP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include <arch/a3x/chip.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* Decimal configuration values may exceed 2Gb and, hence, overflow to negative
 * values unless we force them to unsigned long:
 */

#define __CONCAT(a,b) a ## b
#define MKULONG(a) __CONCAT(a,ul)

/* A33 physical section base addresses (aligned to 1MB boundaries) */

#define A3X_INTMEM_PSECTION  0x00000000 /* Internal memory 0x0000:0000-0x0000:7fff 32k*/
#define A3X_PERIPH_PSECTION  0x01c00000 /* Peripherals     0x01c0:0000-0x01c4:ffff */
#define A3X_SRAMVE_PSECTION  0x00004000 /* VE SRAM         0x0000:4000-0x0000:ffff 48k */
#define A3X_SRAMA2_PSECTION  0x00044000 /* A2 SRAM         0x0004:4000-0x0005:3fff 64k */
#define A3X_DEFE_PSECTION    0x01e00000 /* DEFE,DEB,       0x01e0:0000-0x010b:ffff  */
#define A3X_DEBE_PSECTION    0x01e60000 /* DEFE,DEB,       0x01e6:0000-0x01e6:ffff  */
#define A3X_R_PSECTION       0x01f00000 /* R_              0x01f0:0800-0x01f0:3bff  */
#define A3X_DDR_PSECTION     0x40000000 /* DDR-II/DDR-III  0x4000:0000-0xbfff:ffff 2G */
#define A3X_BROM_PSECTION    0xfff00000 /* BROM            0xffff:0000—0xffff:7fff 32K */
#define A3X_SCUREG_PSECTION  0x01c80000 /* SCUREG          0x01c8:0000-0x01c8:0000 8K */


/* A33 Offsets from the internal memory section base address */

#define A3X_SRAMA1_OFFSET    0x00000000 /* SRAM A1         0x0000:0000-0x0000:7fff 32K */
#define A3X_SRAMA2_OFFSET    0x00044000 /* SRAM A2         0x0004:4000-0x0005:3fff 64K */
#define A3X_SRAMVE_OFFSET    0x00004000 /* SRAM VE         0x0000:4000-0x0000:ffff 48K */

/* A33 offsets from the peripheral section base address */

#define A3X_SRAMC_OFFSET     0x00000000 /* SRAM Controller 0x01c0:0000-0x01c0:0fff 4K */
#define A3X_DRAMC_OFFSET     0x00001000 /* DRAM Controller 0x01c0:1000-0x01c0:1fff 4K */
#define A3X_DMA_OFFSET       0x00002000 /* DMA             0x01c0:2000-0x01c0:2fff 4K */
#define A3X_NDFC_OFFSET      0x00003000 /* NDFC            0x01c0:3000-0x01c0:3fff 4K */
#define A3X_LCD_OFFSET       0x0000c000 /* LCD             0x01c0:c000-0x01c0:cfff 4K */
#define A3X_VE_OFFSET        0x0000e000 /* VE              0x01c0:e000-0x01c0:efff 4K */
#define A3X_SDMMC0_OFFSET    0x0000f000 /* SD/MMC 0        0x01c0:f000-0x01c0:ffff 4K */
#define A3X_SDMMC1_OFFSET    0x00010000 /* SD/MMC 1        0x01c1:0000-0x01c1:0fff 4K */
#define A3X_SDMMC2_OFFSET    0x00011000 /* SD/MMC 2        0x01c1:1000-0x01c1:1fff 4K */
#define A3X_SS_OFFSET        0x00015000 /* SS              0x01c1:5000-0x01c1:5fff 4K */
#define A3X_USBDRD_OFFSET    0x00019000 /* USB DRD         0x01c1:9000-0x01c1:9fff 4K */
#define A3X_USB_OFFSET       0x0001a000 /* USB EHCI/OHCI   0x01c1:a000-0x01c1:afff 4K */
#define A3X_CCU_OFFSET       0x00020000 /* CCU             0x01c2:0000-0x01c2:03ff 4K */
#define A3X_PIO_OFFSET       0x00020800 /* PIO             0x01c2:0800-0x01c2:0bff 1K */
#define A3X_TIMER_OFFSET     0x00020c00 /* Timer           0x01c2:0C00-0x01c2:0fff 1K */
#define A3X_PWM_OFFSET       0x00021400 /* PWM             0x01c2:1400-0x01c2:17ff 1K */
#define A3X_DAUDIO0_OFFSET   0x00022000 /* DAUDIO 0        0x01c2:2200-0x01c2:23ff 1K */
#define A3X_DAUDIO1_OFFSET   0x00022400 /* DAUDIO 1        0x01c2:2400-0x01c2:27ff 1K */
#define A3X_KADC_OFFSET      0x00022400 /* KEYADC          0x01c2:2800-0x01c2:b7ff 1K */
#define A3X_AUDIO_OFFSET     0x00022c00 /* AUDIO           0x01c2:2800-0x01c2:33ff 1K */
#define A3X_SID_OFFSET       0x00023800 /* SID             0x01c2:3800-0x01c2:3bff 1K */
#define A3X_THERMAL_OFFSET   0x00025000 /* THERMAL SENSOR  0x01c2:5000-0x01c2:53ff 1K */
#define A3X_UART_OFFSET(n)   (0x00028000 + ((uint32_t)(n) << 10))
#define A3X_UART0_OFFSET     0x00028000 /* UART 0          0x01c2:8000-0x01c2:83ff 1K */
#define A3X_UART1_OFFSET     0x00028400 /* UART 1          0x01c2:8400-0x01c2:87ff 1K */
#define A3X_UART2_OFFSET     0x00028800 /* UART 2          0x01c2:8800-0x01c2:8bff 1K */
#define A3X_UART3_OFFSET     0x00028c00 /* UART 3          0x01c2:8C00-0x01c2:8fff 1K */
#define A3X_UART4_OFFSET     0x00029000 /* UART 4          0x01c2:9000-0x01c2:93ff 1K */
#define A3X_TWI0_OFFSET      0x0002ac00 /* TWI 0           0x01c2:ac00-0x01c2:afff 1K */
#define A3X_TWI1_OFFSET      0x0002b000 /* TWI 1           0x01c2:b000-0x01c2:B3ff 1K */
#define A3X_TWI2_OFFSET      0x0002b400 /* TWI 2           0x01c2:b400-0x01c2:b7ff 1K */
#define A3X_GPU_OFFSET       0x00040000 /* GPU             0x01c4:0000-0x01c4:ffff 64K */
#define A3X_HSTMR_OFFSET     0x00060000 /* HSTMR           0x01c6:0000-0x01c6:0fff  4K */
#define A3X_DRAMCOM_OFFSET   0x00062000 /* DRAMCOM         0x01c6:2000-0x01c6:2fff  4K */
#define A3X_DRAMCTL_OFFSET   0x00063000 /* DRAMCTL         0x01c6:3000-0x01c6:3fff  4K */
#define A3X_DRAMPHY_OFFSET   0x00065000 /* DRAMPHY         0x01c6:5000-0x01c6:5fff  4K */
#define A3X_SPI0_OFFSET      0x00068000 /* SPI 0           0x01c6:8000-0x01c6:8fff 4K */
#define A3X_SPI1_OFFSET      0x00069000 /* SPI 1           0x01c6:9000-0x01c6:9fff 4K */
#define A3X_MIPIDSI0_OFFSET  0x000a0000 /* MIPIDSI0        0x01ca:0000-0x01ca:0fff 4K */
#define A3X_MIPID_PHY_OFFSET 0x000a1000 /* MIPIDSI0 PHY    0x01ca:1000-0x01ca:1fff 4K */
#define A3X_CSI_OFFSET       0x000b0000 /* CSI             0x01b0:0c00-0x01b0:0fff 1K */
#define A3X_R_TIMER_OFFSET   0x00000800 /* R_TIMER */
#define A3X_R_INTC_OFFSET    0x00000c00 /* R_  */
#define A3X_R_WDOG_OFFSET    0x00001000 /* R_  */
#define A3X_R_PRCM_OFFSET    0x00001400 /* R_  */
#define A3X_R_CPUCFG_OFFSET  0x00001c00 /* R_  */
#define A3X_R_TWI_OFFSET     0x00002400 /* R_  */
#define A3X_R_UART_OFFSET    0x00002800 /* R_  */
#define A3X_R_PIO_OFFSET     0x00002c00 /* R_  */
#define A3X_R_RSB_OFFSET     0x00003400 /* R_  */
#define A3X_R_PWM_OFFSET     0x00003800 /* R_  */

/* A33 ARM MP PSECTION Offsets */
#define A3X_SCUREG_OFFSET    0x00000000  /* SCUREG          0x01c8:0000-0x01c8:0000 8K */
#define A3X_MPSCU_OFFSET     0x00000000  /* 00000000-000000fc  0.25 KB SCU registers */
#define A3X_MPICC_OFFSET     0x00000100  /* 00000100-000001ff  0.25 KB Interrupt controller interfaces */
#define A3X_MPGTM_OFFSET     0x00000200  /* 00000200-000002ff  0.25 KB Global timer */
                                         /* 00000300-000005ff        Reserved */
#define A3X_MPPTM_OFFSET     0x00000600  /* 00000600-000006ff  0.25 KB Private timers and watchdogs */
                                         /* 00000700-00000fff        Reserved */
#define A3X_MPICD_OFFSET     0x00001000  /* 00001000-00001fff   4 KB Interrupt distributor */
#define A3X_PL310_OFFSET     0x00002000  /* 00002000-00002fff   4 KB PL310 (L2 Cache controller) */

/* A33 offsets from the DE section base address */
#define A3X_DEFE_OFFSET      0x00000000 /* DEFE            0x01e0:0000-0x01e1:ffff 128K */
#define A3X_DEBE_OFFSET      0x00060000 /* DEBE            0x01e6:0000-0x01e7:ffff 128K */

/* A33 offsets from the R_INTC section base address */
#define A3X_INTC_OFFSET      0x00000c00 /* DEFE            0x01f0:0c00-0x01f0:0fff   4K */

/* A33 offsets from the BRROM section base address */

#define A3X_BROM_OFFSET      0x000f0000 /* BROM            0xffff:0000—0xffff:7fff 32K */

/* A33 internal memory physical base addresses */

#define A3X_SRAMA1_PADDR     (A3X_INTMEM_PSECTION+A3X_SRAMA1_OFFSET)
#define A3X_SRAMA2_PADDR     (A3X_INTMEM_PSECTION+A3X_SRAMA2_OFFSET)
#define A3X_SRAMVE_PADDR     (A3X_INTMEM_PSECTION+A3X_SRAMVE_OFFSET)

#define A3X_INTC_PADDR       (A3X_R_PSECTION+A3X_INTC_OFFSET)

/* Peripheral physical base addresses */

#define A3X_SRAMC_PADDR      (A3X_PERIPH_PSECTION+A3X_SRAMC_OFFSET)
#define A3X_DRAMC_PADDR      (A3X_PERIPH_PSECTION+A3X_DRAMC_OFFSET)
#define A3X_DMA_PADDR        (A3X_PERIPH_PSECTION+A3X_DMA_OFFSET)
#define A3X_NDFC_PADDR       (A3X_PERIPH_PSECTION+A3X_NDFC_OFFSET)
#define A3X_LCD_PADDR        (A3X_PERIPH_PSECTION+A3X_LCD_OFFSET)
#define A3X_VE_PADDR         (A3X_PERIPH_PSECTION+A3X_VE_OFFSET)
#define A3X_SDMMC0_PADDR     (A3X_PERIPH_PSECTION+A3X_SDMMC0_OFFSET)
#define A3X_SDMMC1_PADDR     (A3X_PERIPH_PSECTION+A3X_SDMMC1_OFFSET)
#define A3X_SDMMC2_PADDR     (A3X_PERIPH_PSECTION+A3X_SDMMC2_OFFSET)
#define A3X_SS_PADDR         (A3X_PERIPH_PSECTION+A3X_SS_OFFSET)
#define A3X_USBDRD_PADDR     (A3X_PERIPH_PSECTION+A3X_USBDRD_OFFSET)
#define A3X_USB_PADDR        (A3X_PERIPH_PSECTION+A3X_USB_OFFSET)
#define A3X_CCU_PADDR        (A3X_PERIPH_PSECTION+A3X_CCU_OFFSET)
#define A3X_PIO_PADDR        (A3X_PERIPH_PSECTION+A3X_PIO_OFFSET)
#define A3X_TIMER_PADDR      (A3X_PERIPH_PSECTION+A3X_TIMER_OFFSET)
#define A3X_PWM_PADDR        (A3X_PERIPH_PSECTION+A3X_PWM_OFFSET)
#define A3X_DAUDIO0_PADDR    (A3X_PERIPH_PSECTION+A3X_DAUDIO0_OFFSET)
#define A3X_DAUDIO1_PADDR    (A3X_PERIPH_PSECTION+A3X_DAUDIO1_OFFSET)
#define A3X_KADC_PADDR       (A3X_PERIPH_PSECTION+A3X_KADC_OFFSET)
#define A3X_AUDIO_PADDR      (A3X_PERIPH_PSECTION+A3X_AUDIO_OFFSET)
#define A3X_SID_PADDR        (A3X_PERIPH_PSECTION+A3X_SID_OFFSET)
#define A3X_THERMAL_PADDR    (A3X_PERIPH_PSECTION+A3X_THERMAL_OFFSET)
#define A3X_UART_PADDR(n)    (A3X_PERIPH_PSECTION+A3X_UART_OFFSET(n))
#define A3X_UART0_PADDR      (A3X_PERIPH_PSECTION+A3X_UART0_OFFSET)
#define A3X_UART1_PADDR      (A3X_PERIPH_PSECTION+A3X_UART1_OFFSET)
#define A3X_UART2_PADDR      (A3X_PERIPH_PSECTION+A3X_UART2_OFFSET)
#define A3X_UART3_PADDR      (A3X_PERIPH_PSECTION+A3X_UART3_OFFSET)
#define A3X_UART4_PADDR      (A3X_PERIPH_PSECTION+A3X_UART4_OFFSET)
#define A3X_TWI0_PADDR       (A3X_PERIPH_PSECTION+A3X_TWI0_OFFSET)
#define A3X_TWI1_PADDR       (A3X_PERIPH_PSECTION+A3X_TWI1_OFFSET)
#define A3X_TWI2_PADDR       (A3X_PERIPH_PSECTION+A3X_TWI2_OFFSET)
#define A3X_GPU_PADDR        (A3X_PERIPH_PSECTION+A3X_GPU_OFFSET)
#define A3X_HSTMR_PADDR      (A3X_PERIPH_PSECTION+A3X_HSTMR_OFFSET)
#define A3X_DRAMCOM_PADDR    (A3X_PERIPH_PSECTION+A3X_DRAMCOM_OFFSET)
#define A3X_DRAMCTL_PADDR    (A3X_PERIPH_PSECTION+A3X_DRAMCTL_OFFSET)
#define A3X_DRAMPHY_PADDR    (A3X_PERIPH_PSECTION+A3X_DRAMPHY_OFFSET)
#define A3X_SPI0_PADDR       (A3X_PERIPH_PSECTION+A3X_SPI0_OFFSET)
#define A3X_SPI1_PADDR       (A3X_PERIPH_PSECTION+A3X_SPI1_OFFSET)
#define A3X_MIPIDSI0_PADDR   (A3X_PERIPH_PSECTION+A3X_MIPIDSI0_OFFSET)
#define A3X_MIPID_PHY_PADDR  (A3X_PERIPH_PSECTION+A3X_MIPID_PHY_OFFSET)
#define A3X_CSI_PADDR        (A3X_PERIPH_PSECTION+A3X_CSI_OFFSET)
#define A3X_R_TIMER_PARRD    (A3X_R_PSECTION+A3X_R_TIMER_OFFSET) 
#define A3X_R_INTC_PARRD     (A3X_R_PSECTION+A3X_R_INTC_OFFSET) 
#define A3X_R_WDOG_PARRD     (A3X_R_PSECTION+A3X_R_WDOG_OFFSET) 
#define A3X_R_PRCM_PARRD     (A3X_R_PSECTION+A3X_R_PRCM_OFFSET) 
#define A3X_R_CPUCFG_PARRD   (A3X_R_PSECTION+A3X_R_CPUCFG_OFFSET) 
#define A3X_R_TWI_PARRD      (A3X_R_PSECTION+A3X_R_TWI_OFFSET) 
#define A3X_R_UART_PARRD     (A3X_R_PSECTION+A3X_R_UART_OFFSET) 
#define A3X_R_PIO_PARRD      (A3X_R_PSECTION+A3X_R_PIO_OFFSET) 
#define A3X_R_RSB_PARRD      (A3X_R_PSECTION+A3X_R_RSB_OFFSET) 
#define A3X_R_PWM_PARRD      (A3X_R_PSECTION+A3X_R_PWM_OFFSET) 

/* A33 ARM MP Physical Base Addresses */
#define A3X_SCUREG_PADDR     (A3X_SCUREG_PSECTION+A3X_SCUREG_OFFSET)
#define A3X_MPSCU_PBASE      (A3X_SCUREG_PSECTION+A3X_MPSCU_OFFSET)
#define A3X_MPICC_PBASE      (A3X_SCUREG_PSECTION+A3X_MPICC_OFFSET)
#define A3X_MPGTM_PBASE      (A3X_SCUREG_PSECTION+A3X_MPGTM_OFFSET)
#define A3X_MPPTM_PBASE      (A3X_SCUREG_PSECTION+A3X_MPPTM_OFFSET)
#define A3X_MPICD_PBASE      (A3X_SCUREG_PSECTION+A3X_MPICD_OFFSET)
#define A3X_PL310_PBASE      (A3X_SCUREG_PSECTION+A3X_PL310_OFFSET)

/* A33 DE section physical base addresses */

#define A3X_DEFE_PADDR       (A3X_DEFE_PSECTION+A3X_DEFE_OFFSET)
#define A3X_DEBE_PADDR       (A3X_DEBE_PSECTION+A3X_DEBE_OFFSET)

/* A33 BRROM section physical base address */

#define A3X_BROM_PADDR       (A3X_BROM_PSECTION+A3X_BROM_OFFSET)

/* Sizes of memory regions in bytes.
 *
 * These sizes exclude the undefined addresses at the end of the memory
 * region.  The implemented sizes of the external memory regions are
 * not known apriori and must be specified with configuration settings.
 */

#define A3X_INTMEM_SIZE      0x00008000 /* Internal memory 0x0000:0000-0x00007ffff 32k */
#define A3X_PERIPH_SIZE      0x00300400 /* Peripherals     0x01c0:0000-0x01f0:03ff */
#define A3X_SRAMA2_SIZE      0x00010000 /* SRAM VE         0x0004:4000-0x0005:3fff 64k */
#define A3X_SRAMVE_SIZE      0x0000c000 /* SRAM VE         0x0000:4000-0x0000:ffff 48k */
#define A3X_DEFE_SIZE        0x00020000 /* DE              0x01e0:0000-0x01e1:ffff 128k */
#define A3X_DEBE_SIZE        0x00010000 /* BE              0x01e6:0000-0x01e6:ffff 64k  */
#define A3X_R_SIZE           0x00003400 /*                 0x01f0:0800-0x01f0:3bff  */
#define A3X_BROM_SIZE        0x000f8000 /* BROM            0xfff0:0000—0xffff:7fff 32K */

/* Force configured sizes that might exceed 2GB to be unsigned long */

#define A3X_DDR_MAPOFFSET    MKULONG(CONFIG_A3X_DDR_MAPOFFSET)
#define A3X_DDR_MAPSIZE      MKULONG(CONFIG_A3X_DDR_MAPSIZE)
#define A3X_DDR_HEAP_OFFSET  MKULONG(CONFIG_A3X_DDR_HEAP_OFFSET)
#define A3X_DDR_HEAP_SIZE    MKULONG(CONFIG_A3X_DDR_HEAP_SIZE)

/* Convert size in bytes to number of sections (in Mb). */

#define _NSECTIONS(b)        (((b)+0x000fffff) >> 20)

/* Sizes of memory regions in sections.
 *
 * The boot logic in A3X_boot.c, will select 1Mb level 1 MMU mappings to
 * span the entire physical address space.  The definitions below specify
 * the number of 1Mb entries that are required to span a particular address
 * region.
 *
 * NOTE: the size of the mapped SDRAM region depends on the configured size
 * of DRAM, not on the size of the address space assigned to DRAM.
 */

#define A3X_INTMEM_NSECTIONS _NSECTIONS(A3X_INTMEM_SIZE)
#define A3X_PERIPH_NSECTIONS _NSECTIONS(A3X_PERIPH_SIZE)
#define A3X_SRAMA2_NSECTIONS _NSECTIONS(A3X_SRAMA2_SIZE)
#define A3X_SRAMVE_NSECTIONS _NSECTIONS(A3X_SRAMVE_SIZE)
#define A3X_DEFE_NSECTIONS   _NSECTIONS(A3X_DEFE_SIZE)
#define A3X_DEBE_NSECTIONS   _NSECTIONS(A3X_DEBE_SIZE)
#define A3X_R_NSECTIONS      _NSECTIONS(A3X_R_SIZE)
#define A3X_DDR_NSECTIONS    _NSECTIONS(A3X_DDR_MAPSIZE)
#define A3X_BROM_NSECTIONS   _NSECTIONS(A3X_BROM_SIZE)

/* Section MMU Flags */

#define A3X_INTMEM_MMUFLAGS  MMU_MEMFLAGS
#define A3X_PERIPH_MMUFLAGS  MMU_IOFLAGS
#define A3X_SRAMA2_MMUFLAGS  MMU_MEMFLAGS
#define A3X_SRAMVE_MMUFLAGS  MMU_MEMFLAGS
#define A3X_DEFE_MMUFLAGS    MMU_MEMFLAGS
#define A3X_DEBE_MMUFLAGS    MMU_MEMFLAGS
#define A3X_R_MMUFLAGS       MMU_MEMFLAGS
#define A3X_DDR_MMUFLAGS     MMU_MEMFLAGS
#define A3X_BROM_MMUFLAGS    MMU_ROMFLAGS

/* A33 Virtual (mapped) Memory Map
 *
 * board_memorymap.h contains special mappings that are needed when a ROM
 * memory map is used.  It is included in this odd location becaue it depends
 * on some the virtual address definitions provided above.
 */

#include <arch/board/board_memorymap.h>

/* A33 Virtual (mapped) Memory Map.  These are the mappings that will
 * be created if the page table lies in RAM.  If the platform has another,
 * read-only, pre-initialized page table (perhaps in ROM), then the board.h
 * file must provide these definitions.
 */

#ifndef CONFIG_ARCH_ROMPGTABLE

/* Notice that these mappings are a simple 1-to-1 mappings */

#define A3X_INTMEM_VSECTION  0x00000000 /* Internal memory 0x0000:0000-0x00007ffff */
#define A3X_PERIPH_VSECTION  0x01c00000 /* Peripherals     0x01c0:0000-0x01c4:ffff */
#define A3X_SRAMA2_VSECTION  0x00044000 /* Internel mem    0x0004:4000-0x0005:3fff internal mem */
#define A3X_SRAMVE_VSECTION  0x00004000 /* VE SRAM         0x0000:4000-0x0000f3fff VE sram */
#define A3X_DDR_VSECTION     0x40000000 /* DDR-II/DDR-III  0x4000:0000-0xbfff:ffff 2G */
#define A3X_BROM_VSECTION    0xfff00000 /* BROM            0xffff:0000—0xffff:7fff 32K */
#define A3X_DEFE_VSECTION    0x01e00000 /* DEFE            0x01e0:0000-0x01e1:ffff 128K */
#define A3X_DEBE_VSECTION    0x01e60000 /* DEBE            0x01e6:0000-0x01f6:ffff 64K */
#define A3X_R_VSECTION       0x01f00000 /* R_              0x01f0:0800-0x01f0:3bff 1K */
#define A3X_SCUREG_VSECTION  0x01c80000 /* SCUREG          0x01c8:0000-0x01c8:0000 8K */


#endif

/* A33 internal memory virtual base addresses */

#define A3X_SRAMA1_VADDR     (A3X_INTMEM_VSECTION+A3X_SRAMA1_OFFSET)
#define A3X_SRAMA2_VADDR     (A3X_INTMEM_VSECTION+A3X_SRAMA2_OFFSET)
#define A3X_SRAMNAND_VADDR
#define A3X_SRAMVE_VADDR      (A3X_INTMEM_VSECTION+A3X_SRAMVE_OFFSET)

/* Peripheral virtual base addresses */

#define A3X_SRAMC_VADDR      (A3X_PERIPH_VSECTION+A3X_SRAMC_OFFSET)
#define A3X_DRAMC_VADDR      (A3X_PERIPH_VSECTION+A3X_DRAMC_OFFSET)
#define A3X_DMA_VADDR        (A3X_PERIPH_VSECTION+A3X_DMA_OFFSET)
#define A3X_NDFC_VADDR       (A3X_PERIPH_VSECTION+A3X_NDFC_OFFSET)
#define A3X_LCD_VADDR        (A3X_PERIPH_VSECTION+A3X_LCD_OFFSET)
#define A3X_VE_VADDR         (A3X_PERIPH_VSECTION+A3X_VE_OFFSET)
#define A3X_SDMMC0_VADDR     (A3X_PERIPH_VSECTION+A3X_SDMMC0_OFFSET)
#define A3X_SDMMC1_VADDR     (A3X_PERIPH_VSECTION+A3X_SDMMC1_OFFSET)
#define A3X_SDMMC2_VADDR     (A3X_PERIPH_VSECTION+A3X_SDMMC2_OFFSET)
#define A3X_SS_VADDR         (A3X_PERIPH_VSECTION+A3X_SS_OFFSET)
#define A3X_USBDRD_VADDR     (A3X_PERIPH_VSECTION+A3X_USBDRD_OFFSET)
#define A3X_USB_VADDR        (A3X_PERIPH_VSECTION+A3X_USB1_OFFSET)
#define A3X_CCU_VADDR        (A3X_PERIPH_VSECTION+A3X_CCU_OFFSET)
#define A3X_PIO_VADDR        (A3X_PERIPH_VSECTION+A3X_PIO_OFFSET)
#define A3X_TIMER_VADDR      (A3X_PERIPH_VSECTION+A3X_TIMER_OFFSET)
#define A3X_PMU_VADDR        (A3X_PERIPH_VSECTION+A3X_PMU_OFFSET)
#define A3X_DAUDIO0_VADDR    (A3X_PERIPH_VSECTION+A3X_DAUDIO0_OFFSET)
#define A3X_DAUDIO1_VADDR    (A3X_PERIPH_VSECTION+A3X_DAUDIO1_OFFSET)
#define A3X_KADC_VADDR       (A3X_PERIPH_VSECTION+A3X_KADC_OFFSET)
#define A3X_SID_VADDR        (A3X_PERIPH_VSECTION+A3X_SID_OFFSET)
#define A3X_THERMAL_VADDR    (A3X_PERIPH_VSECTION+A3X_THERMAL_OFFSET)
#define A3X_UART_VADDR(n)    (A3X_PERIPH_VSECTION+A3X_UART_OFFSET(n))
#define A3X_UART0_VADDR      (A3X_PERIPH_VSECTION+A3X_UART0_OFFSET)
#define A3X_UART1_VADDR      (A3X_PERIPH_VSECTION+A3X_UART1_OFFSET)
#define A3X_UART2_VADDR      (A3X_PERIPH_VSECTION+A3X_UART2_OFFSET)
#define A3X_UART3_VADDR      (A3X_PERIPH_VSECTION+A3X_UART3_OFFSET)
#define A3X_UART4_VADDR      (A3X_PERIPH_VSECTION+A3X_UART4_OFFSET)
#define A3X_TWI0_VADDR       (A3X_PERIPH_VSECTION+A3X_TWI0_OFFSET)
#define A3X_TWI1_VADDR       (A3X_PERIPH_VSECTION+A3X_TWI1_OFFSET)
#define A3X_TWI2_VADDR       (A3X_PERIPH_VSECTION+A3X_TWI2_OFFSET)
#define A3X_GPU_VADDR        (A3X_PERIPH_VSECTION+A3X_GPU_OFFSET)
#define A3X_HSTMR_VADDR      (A3X_PERIPH_VSECTION+A3X_HSTMR_OFFSET)
#define A3X_DRAMCOM_VADDR    (A3X_PERIPH_VSECTION+A3X_DRAMCOM_OFFSET)
#define A3X_DRAMCTL_VADDR    (A3X_PERIPH_VSECTION+A3X_DRAMCTL_OFFSET)
#define A3X_DRAMPHY_VADDR    (A3X_PERIPH_VSECTION+A3X_DRAMPHY_OFFSET)
#define A3X_SPI0_VADDR       (A3X_PERIPH_VSECTION+A3X_SPI0_OFFSET)
#define A3X_SPI1_VADDR       (A3X_PERIPH_VSECTION+A3X_SPI1_OFFSET)
#define A3X_MIPIDSI0_VADDR   (A3X_PERIPH_VSECTION+A3X_MIPIDSI0_OFFSET)
#define A3X_MIPID_PHY_VADDR  (A3X_PERIPH_VSECTION+A3X_MIPID_PHY_OFFSET)
#define A3X_CSI_VADDR        (A3X_PERIPH_VSECTION+A3X_CSI_OFFSET)
#define A3X_SCUREG_VADDR     (A3X_SCUREG_VSECTION+A3X_SCUREG_OFFSET)
#define A3X_R_TIMER_VARRD    (A3X_R_VSECTION+A3X_R_TIMER_OFFSET) 
#define A3X_R_INTC_VARRD     (A3X_R_VSECTION+A3X_R_INTC_OFFSET) 
#define A3X_R_WDOG_VARRD     (A3X_R_VSECTION+A3X_R_WDOG_OFFSET) 
#define A3X_R_PRCM_VARRD     (A3X_R_VSECTION+A3X_R_PRCM_OFFSET) 
#define A3X_R_CPUCFG_VARRD   (A3X_R_VSECTION+A3X_R_CPUCFG_OFFSET) 
#define A3X_R_TWI_VARRD      (A3X_R_VSECTION+A3X_R_TWI_OFFSET) 
#define A3X_R_UART_VARRD     (A3X_R_VSECTION+A3X_R_UART_OFFSET) 
#define A3X_R_PIO_VARRD      (A3X_R_VSECTION+A3X_R_PIO_OFFSET) 
#define A3X_R_RSB_VARRD      (A3X_R_VSECTION+A3X_R_RSB_OFFSET) 
#define A3X_R_PWM_VARRD      (A3X_R_VSECTION+A3X_R_PWM_OFFSET) 
/* A33 DE section virtual base addresses */

#define A3X_DEFE_VADDR       (A3X_DE_VSECTION+A3X_DEFE_OFFSET)
#define A3X_DEBE_VADDR       (A3X_DE_VSECTION+A3X_DEBE_OFFSET)

/* A33 BRROM section virtual base address */

#define A3X_BROM_VADDR       (A3X_BROM_VSECTION+A3X_BROM_OFFSET)

/* R_INT */
#define A3X_INTC_VADDR       (A3X_R_VSECTION+A3X_INTC_OFFSET)

/* Offset SDRAM address */

#define A3X_DDR_MAPPADDR     (A3X_DDR_PSECTION+A3X_DDR_MAPOFFSET)
#define A3X_DDR_MAPVADDR     (A3X_DDR_VSECTION+A3X_DDR_MAPOFFSET)

/* NuttX virtual base address
 *
 * The boot logic will create a temporarily mapping based on where NuttX is
 * executing in memory.  In this case, NuttX will be running from either
 * internal SRAM or external SDRAM.
 *
 * Setup the RAM region as the NUTTX .txt, .bss, and .data region.
 */

#define NUTTX_TEXT_VADDR     (CONFIG_RAM_VSTART & 0xfff00000)
#define NUTTX_TEXT_PADDR     (CONFIG_RAM_START & 0xfff00000)
#define NUTTX_TEXT_PEND      ((CONFIG_RAM_END + 0x000fffff) & 0xfff00000)
#define NUTTX_TEXT_SIZE      (NUTTX_TEXT_PEND - NUTTX_TEXT_PADDR)

/* MMU Page Table
 *
 * Determine the address of the MMU page table.  Regardless of the memory
 * configuration, we will keep the page table in the A33's internal SRAM.
 */

#if defined(PGTABLE_BASE_PADDR) || defined(PGTABLE_BASE_VADDR)

  /* Sanity check.. if one is undefined, both should be undefined */

#  if !defined(PGTABLE_BASE_PADDR) || !defined(PGTABLE_BASE_VADDR)
#    error "Only one of PGTABLE_BASE_PADDR or PGTABLE_BASE_VADDR is defined"
#  endif

  /* A sanity check, if the configuration says that the page table is read-only
   * and pre-initialized (maybe ROM), then it should have also defined both of
   * the page table base addresses.
   */

#  ifdef CONFIG_ARCH_ROMPGTABLE
#    error "CONFIG_ARCH_ROMPGTABLE defined; PGTABLE_BASE_P/VADDR not defined"
#  endif

#else /* PGTABLE_BASE_PADDR || PGTABLE_BASE_VADDR */

  /* If CONFIG_PAGING is selected, then parts of the 1-to-1 virtual memory
   * map probably do not apply because paging logic will probably partition
   * the SRAM section differently.  In particular, if the page table is located
   * at the end of SRAM, then the virtual page table address defined below
   * will probably be in error.  In that case PGTABLE_BASE_VADDR is defined
   * in the file mmu.h
   *
   * We must declare the page table at the bottom or at the top of internal
   * SRAM.  We pick the bottom of internal SRAM *unless* there are vectors
   * in the way at that position.
   */

#  if defined(CONFIG_ARCH_LOWVECTORS)
  /* In this case, table must lie in SRAM A2 after the vectors in SRAM A1 */

#    define PGTABLE_BASE_PADDR  A3X_SRAMA2_PADDR
#    define PGTABLE_BASE_VADDR  A3X_SRAMA2_VADDR

#  else /* CONFIG_ARCH_LOWVECTORS */

  /* Otherwise, the vectors lie at another location.  The page table will
   * then be positioned at the beginning of SRAM A1.
   */

#    define PGTABLE_BASE_PADDR  A3X_SRAMA1_PADDR
#    define PGTABLE_BASE_VADDR  A3X_SRAMA1_VADDR

#  endif /* CONFIG_ARCH_LOWVECTORS */

  /* Note that the page table does not lie in the same address space as does the
   * mapped RAM in either case.  So we will need to create a special mapping for
   * the page table at boot time.
   */

#  define ARMV7A_PGTABLE_MAPPING 1

#endif /* PGTABLE_BASE_PADDR || PGTABLE_BASE_VADDR */

/* Level 2 Page table start addresses.
 *
 * 16Kb of memory is reserved hold the page table for the virtual mappings.  A
 * portion of this table is not accessible in the virtual address space (for
 * normal operation).   There are several large holes in the physical address
 * space for which there will never be level 1 mappings:
 *
 *                                    LI PAGE TABLE
 *   ADDRESS RANGE           SIZE     ENTRIES       SECTIONS
 *   ----------------------- ------- -------------- ---------
 *   0x0003:0000-0x01eb:ffff 275MB   0x0004-0x006c 26
 *                                  *(none usable) 0
 *   0x01ec:0000-0x3fff:ffff 993MB   0x0078-0x0ffc 993
 *                                  *0x0400-0x0ffc 767
 *
 * And the largest is probably from the end of SDRAM through 0xfff0:0000.
 * But the size of that region varies with the size of the installed SDRAM.
 * It is at least:
 *
 *                                    LI PAGE TABLE
 *   ADDRESS RANGE           SIZE     ENTRIES       SECTIONS
 *   ----------------------- ------- -------------- ---------
 *   0xc000:0000-0xffef:ffff 1022MB  *0x3000-0x3ff8 1022
 *
 * And probably much larger.
 *
 *   * NOTE that the L2 page table entries must be aligned 1KB address
 *     boundaries.
 *
 * These two larger regions is where L2 page tables will positioned.  Up to
 * two L2 page tables may be used:
 *
 * 1) One mapping the vector table (only when CONFIG_ARCH_LOWVECTORS is not
 *    defined).
 * 2) If on-demand paging is supported (CONFIG_PAGING=y), than an additional
 *    L2 page table is needed.
 */

#ifndef CONFIG_ARCH_LOWVECTORS
/* Vector L2 page table offset/size */

#  define VECTOR_L2_OFFSET        0x000000400
#  define VECTOR_L2_SIZE          0x000000bfc

/* Vector L2 page table base addresses */

#  define VECTOR_L2_PBASE         (PGTABLE_BASE_PADDR+VECTOR_L2_OFFSET)
#  define VECTOR_L2_VBASE         (PGTABLE_BASE_VADDR+VECTOR_L2_OFFSET)

/* Vector L2 page table end addresses */

#  define VECTOR_L2_END_PADDR     (VECTOR_L2_PBASE+VECTOR_L2_SIZE)
#  define VECTOR_L2_END_VADDR     (VECTOR_L2_VBASE+VECTOR_L2_SIZE)

#endif /* !CONFIG_ARCH_LOWVECTORS */

/* Paging L2 page table offset/size */

#define PGTABLE_L2_START_PADDR    (A3X_DDR_PSECTION+A3X_DDR_MAPOFFSET+A3X_DDR_MAPSIZE)
#define PGTABLE_BROM_OFFSET       0x3ffc

#define PGTABLE_L2_OFFSET         ((PGTABLE_L2_START_PADDR >> 18) & ~3)
#define PGTABLE_L2_SIZE           (PGTABLE_BROM_OFFSET - PGTABLE_L2_OFFSET)

/* Paging L2 page table base addresses
 *
 * NOTE: If CONFIG_PAGING is defined, mmu.h will re-assign the virtual
 * address of the page table.
 */

#define PGTABLE_L2_PBASE          (PGTABLE_BASE_PADDR+PGTABLE_L2_OFFSET)
#define PGTABLE_L2_VBASE          (PGTABLE_BASE_VADDR+PGTABLE_L2_OFFSET)

/* Paging L2 page table end addresses */

#define PGTABLE_L2_END_PADDR      (PGTABLE_L2_PBASE+PGTABLE_L2_SIZE)
#define PGTABLE_L2_END_VADDR      (PGTABLE_L2_VBASE+PGTABLE_L2_SIZE)

/* Base address of the interrupt vector table.
 *
 *   A3X_VECTOR_PADDR - Unmapped, physical address of vector table in SRAM
 *   A3X_VECTOR_VSRAM - Virtual address of vector table in SRAM
 *   A3X_VECTOR_VADDR - Virtual address of vector table (0x00000000 or 0xffff0000)
 *
 * NOTE: When using LOWVECTORS, the actual base of the vectors appears to be
 * offset to address 0x0000:0040
 */

#define VECTOR_TABLE_SIZE         0x00010000
#define VECTOR_TABLE_OFFSET       0x00000040

#ifdef CONFIG_ARCH_LOWVECTORS  /* Vectors located at 0x0000:0000  */

#  define A3X_VECTOR_PADDR        A3X_SRAMA1_PADDR
#  define A3X_VECTOR_VSRAM        A3X_SRAMA1_VADDR
#  define A3X_VECTOR_VADDR        0x00000000

#else  /* Vectors located at 0xffff:0000 -- this probably does not work */

#  ifdef A3X_ISRAM1_SIZE >= VECTOR_TABLE_SIZE
#    define A3X_VECTOR_PADDR      (A3X_SRAMA1_PADDR+A3X_ISRAM1_SIZE-VECTOR_TABLE_SIZE)
#    define A3X_VECTOR_VSRAM      (A3X_SRAMA1_VADDR+A3X_ISRAM1_SIZE-VECTOR_TABLE_SIZE)
#  else
#    define A3X_VECTOR_PADDR      (A3X_SRAMA1_PADDR+A3X_ISRAM0_SIZE-VECTOR_TABLE_SIZE)
#    define A3X_VECTOR_VSRAM      (A3X_SRAMA1_VADDR+A3X_ISRAM0_SIZE-VECTOR_TABLE_SIZE)
#  endif
#  define A3X_VECTOR_VADDR        0xffff0000

#endif

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

/************************************************************************************
 * Public Functions
 ************************************************************************************/

#endif /* __ARCH_ARM_SRC_A3X_HARDWARE_A10_MEMORYMAP_H */
