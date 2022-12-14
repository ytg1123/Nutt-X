/****************************************************************************
 * arch/arm/src/a1x/a1x_boot.c
 *
 *   Copyright (C) 2013, 2017 Gregory Nutt. All rights reserved.
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
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <assert.h>

#ifdef CONFIG_PAGING
#  include <nuttx/page.h>
#endif

#include "chip.h"
#include "arm.h"
#include "mmu.h"
#include "fpu.h"
#include "up_internal.h"
#include "up_arch.h"

#include "a33_lowputc.h"
#include "a33_boot.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
/* The vectors are, by default, positioned at the beginning of the text
 * section.  They will always have to be copied to the correct location.
 *
 * If we are using high vectors (CONFIG_ARCH_LOWVECTORS=n).  In this case,
 * the vectors will lie at virtual address 0xffff:000 and we will need
 * to a) copy the vectors to another location, and b) map the vectors
 * to that address, and
 *
 * For the case of CONFIG_ARCH_LOWVECTORS=y, defined.  Vectors will be
 * copied to SRAM A1 at address 0x0000:0000
 */

#if !defined(CONFIG_ARCH_LOWVECTORS) && defined(CONFIG_ARCH_ROMPGTABLE)
#  error High vector remap cannot be performed if we are using a ROM page table
#endif

/****************************************************************************
 * Public Data
 ****************************************************************************/

extern uint32_t _vector_start; /* Beginning of vector block */
extern uint32_t _vector_end;   /* End+1 of vector block */

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* This table describes how to map a set of 1Mb pages to space the physical
 * address space of the A3X.
 */

#ifndef CONFIG_ARCH_ROMPGTABLE
static const struct section_mapping_s section_mapping[] =
{
  { A33_INTMEM_PSECTION,  A33_INTMEM_VSECTION,  /* Includes vectors and page table */
    A33_INTMEM_MMUFLAGS,  A33_INTMEM_NSECTIONS
  },
  { A33_PERIPH_PSECTION,  A33_PERIPH_VSECTION,
    A33_PERIPH_MMUFLAGS,  A33_PERIPH_NSECTIONS
  },
  { A33_SRAMC_PSECTION,   A33_SRAMC_VSECTION,
    A33_SRAMC_MMUFLAGS,   A33_SRAMC_NSECTIONS
  },
  { A33_DE_PSECTION,      A33_DE_VSECTION,
    A33_DE_MMUFLAGS,      A33_DE_NSECTIONS
  },
  { A33_DDR_MAPPADDR,     A33_DDR_MAPVADDR,
    A33_DDR_MMUFLAGS,     A33_DDR_NSECTIONS
  }
  { A33_BROM_PSECTION,    A33_BROM_VSECTION,
    A33_BROM_MMUFLAGS,    A33_BROM_NSECTIONS
  }
};

#define NMAPPINGS \
  (sizeof(section_mapping) / sizeof(struct section_mapping_s))
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: a3x_setupmappings
 *
 * Description:
 *   Map all of the initial memory regions defined in section_mapping[]
 *
 ****************************************************************************/

#ifndef CONFIG_ARCH_ROMPGTABLE
static inline void a3x_setupmappings(void)
{
  mmu_l1_map_regions(section_mapping, NMAPPINGS);
}
#endif

/****************************************************************************
 * Name: a3x_vectorpermissions
 *
 * Description:
 *   Set permissions on the vector mapping.
 *
 ****************************************************************************/

#if !defined(CONFIG_ARCH_ROMPGTABLE) && defined(CONFIG_ARCH_LOWVECTORS) && \
     defined(CONFIG_PAGING)
static void a3x_vectorpermissions(uint32_t mmuflags)
{
  /* The PTE for the beginning of ISRAM is at the base of the L2 page table */

  uint32_t pte = mmu_l2_getentry(PG_L2_VECT_VADDR, 0);

  /* Mask out the old MMU flags from the page table entry.
   *
   * The pte might be zero the first time this function is called.
   */

  if (pte == 0)
    {
      pte = PG_VECT_PBASE;
    }
  else
    {
      pte &= PG_L1_PADDRMASK;
    }

  /* Update the page table entry with the MMU flags and save */

  mmu_l2_setentry(PG_L2_VECT_VADDR, pte, 0, mmuflags);
}
#endif

/****************************************************************************
 * Name: a3x_vectormapping
 *
 * Description:
 *   Setup a special mapping for the interrupt vectors when (1) the
 *   interrupt vectors are not positioned in ROM, and when (2) the interrupt
 *   vectors are located at the high address, 0xffff0000.  When the
 *   interrupt vectors are located in ROM, we just have to assume that they
 *   were set up correctly;  When vectors  are located in low memory,
 *   0x00000000, the mapping for the ROM memory region will be suppressed.
 *
 ****************************************************************************/

#if !defined(CONFIG_ARCH_ROMPGTABLE) && !defined(CONFIG_ARCH_LOWVECTORS)
static void a3x_vectormapping(void)
{
  uint32_t vector_paddr = A3X_VECTOR_PADDR & PTE_SMALL_PADDR_MASK;
  uint32_t vector_vaddr = A3X_VECTOR_VADDR & PTE_SMALL_PADDR_MASK;
  uint32_t vector_size  = (uint32_t)&_vector_end - (uint32_t)&_vector_start;
  uint32_t end_paddr    = A3X_VECTOR_PADDR + vector_size;

  /* REVISIT:  Cannot really assert in this context */

  DEBUGASSERT (vector_size <= VECTOR_TABLE_SIZE);

  /* We want to keep our interrupt vectors and interrupt-related logic in
   * zero-wait state internal SRAM (ISRAM).  The A1X has 128Kb of ISRAM
   * positioned at physical address 0x0300:0000; we need to map this to
   * 0xffff:0000.
   */

  while (vector_paddr < end_paddr)
    {
      mmu_l2_setentry(VECTOR_L2_VBASE,  vector_paddr, vector_vaddr,
                      MMU_L2_VECTORFLAGS);
      vector_paddr += 4096;
      vector_vaddr += 4096;
    }

  /* Now set the level 1 descriptor to refer to the level 2 page table. */

  mmu_l1_setentry(VECTOR_L2_PBASE & PMD_PTE_PADDR_MASK,
                  A3X_VECTOR_VADDR & PMD_PTE_PADDR_MASK,
                  MMU_L1_VECTORFLAGS);
}
#else
  /* No vector remap */

#  define a3x_vectormapping()
#endif

/****************************************************************************
 * Name: a3x_copyvectorblock
 *
 * Description:
 *   Copy the interrupt block to its final destination.  Vectors are already
 *   positioned at the beginning of the text region and only need to be
 *   copied in the case where we are using high vectors.
 *
 ****************************************************************************/

static void a3x_copyvectorblock(void)
{
  uint32_t *src;
  uint32_t *end;
  uint32_t *dest;

  /* If we are using re-mapped vectors in an area that has been marked
   * read only, then temparily mark the mapping write-able (non-buffered).
   */

#ifdef CONFIG_PAGING
  a3x_vectorpermissions(MMU_L2_VECTRWFLAGS);
#endif

  /* Copy the vectors into ISRAM at the address that will be mapped to the vector
   * address:
   *
   *   A3X_VECTOR_PADDR - Unmapped, physical address of vector table in SRAM
   *   A3X_VECTOR_VSRAM - Virtual address of vector table in SRAM
   *   A3X_VECTOR_VADDR - Virtual address of vector table (0x00000000 or
   *                      0xffff0000)
   */

  src  = (uint32_t *)&_vector_start;
  end  = (uint32_t *)&_vector_end;
  dest = (uint32_t *)(A3X_VECTOR_VSRAM + VECTOR_TABLE_OFFSET);

  while (src < end)
    {
      *dest++ = *src++;
    }

  /* Make the vectors read-only, cacheable again */

#if !defined(CONFIG_ARCH_LOWVECTORS) && defined(CONFIG_PAGING)
  a3x_vectorpermissions(MMU_L2_VECTORFLAGS);
#endif
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: arm_boot
 *
 * Description:
 *   Complete boot operations started in arm_head.S
 *
 *   This logic will be executing in SDRAM.  This boot logic was started by
 *   the A10 boot logic.  At this point in time, clocking and SDRAM have
 *   already be initialized (they must be because we are executing out of
 *   SDRAM).  So all that must be done here is to:
 *
 *     1) Refine the memory mapping,
 *     2) Configure the serial console, and
 *     3) Perform board-specific initializations.
 *
 ****************************************************************************/

void arm_boot(void)
{
#ifndef CONFIG_ARCH_ROMPGTABLE
  /* __start provided the basic MMU mappings for SRAM.  Now provide mappings
   * for all IO regions (Including the vector region).
   */

  a3x_setupmappings();

  /* Provide a special mapping for the IRAM interrupt vector positioned in
   * high memory.
   */

  a3x_vectormapping();

#endif /* CONFIG_ARCH_ROMPGTABLE */

  /* Setup up vector block.  _vector_start and _vector_end are exported from
   * arm_vector.S
   */

  a3x_copyvectorblock();

#ifdef CONFIG_ARCH_FPU
  /* Initialize the FPU */

  arm_fpuconfig();
#endif

#ifdef CONFIG_BOOT_SDRAM_DATA
  /* This setting is inappropriate for the A1x because the code is *always*
   * executing from SDRAM.  If CONFIG_BOOT_SDRAM_DATA happens to be set,
   * let's try to do the right thing and initialize the .data and .bss
   * sections.
   */

  arm_data_initialize();
#endif

  /* Perform common, low-level chip initialization (might do nothing) */

  a3x_lowsetup();

#ifdef USE_EARLYSERIALINIT
  /* Perform early serial initialization if we are going to use the serial
   * driver.
   */

  up_earlyserialinit();
#endif

  /* Perform board-specific initialization,  This must include:
   *
   * - Initialization of board-specific memory resources (e.g., SDRAM)
   * - Configuration of board specific resources (PIOs, LEDs, etc).
   */

  a3x_boardinitialize();
}
