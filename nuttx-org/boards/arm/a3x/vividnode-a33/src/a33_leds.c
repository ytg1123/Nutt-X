/****************************************************************************
 * boards/arm/a33/vividnode-a33/src/a33_leds.c
 *
 *   Copyright (C) 2013, 2015 Gregory Nutt. All rights reserved.
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
#include <stdbool.h>
#include <debug.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "chip.h"
#include "up_arch.h"
#include "up_internal.h"

#include "vividnode-a33.h"

/* The pcDuino v1 has four green LEDs; three can be controlled from software.
 * Two are tied to ground and, hence, illuminated by driving the output pins
 * to a high value:
 *
 *  1. LED1 SPI0_CLK  SPI0_CLK/UART5_RX/EINT23/PI11
 *  2. LED5 IPSOUT    From the PMU (not controllable by software)
 *
 * And two are pull high and, hence, illuminated by grounding the output:
 *
 *   3. LED3 RX_LED    LCD1_D16/ATAD12/KP_IN6/SMC_DET/EINT16/CSI1_D16/PH16
 *   4. LED4 TX_LED    LCD1_D15/ATAD11/KP_IN5/SMC_VPPPP/EINT15/CSI1_D15/PH15

 * These LEDs are not used by the board port unless CONFIG_ARCH_LEDS is
 * defined.  In that case, the usage by the board port is defined in
 * include/board.h and src/stm32_leds.c.
 * The LEDs are used to encode OS-related events as follows:
 *
 *   SYMBOL            Meaning                      LED state
 *                                              LED1 LED3 LED4
 *   ----------------- -----------------------  ---- ---- ---- ------------
 *   LED_STARTED       NuttX has been started   ON   OFF  OFF
 *   LED_HEAPALLOCATE  Heap has been allocated  OFF  ON   OFF
 *   LED_IRQSENABLED   Interrupts enabled       ON   ON   OFF
 *   LED_STACKCREATED  Idle stack created       ON   ON   OFF
 *   LED_INIRQ         In an interrupt          N/C  N/C  Soft glow
 *   LED_SIGNAL        In a signal handler      N/C  N/C  Soft glow
 *   LED_ASSERTION     An assertion failed      N/C  N/C  Soft glow
 *   LED_PANIC         The system has crashed   N/C  N/C  2Hz Flashing
 *   LED_IDLE          MCU is is sleep mode         Not used
 *
 * After booting, LED1 and 3 are not longer used by the system and can be used
 * for other purposes by the application (Of course, all LEDs are available to
 * the application if CONFIG_ARCH_LEDS is not defined.
 */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: a33_led_initialize
 *
 * Description:
 *   Configure LEDs.  LEDs are left in the OFF state.
 *
 ****************************************************************************/

void a33_led_initialize(void)
{
  a33_pio_config(PIO_LED1);
  a33_pio_config(PIO_LED3);
  a33_pio_config(PIO_LED4);
}

/****************************************************************************
 * Name: board_autoled_on
 *
 * Description:
 *   Select the "logical" ON state:
 *
 *   SYMBOL            Value Meaning                    LED state
 *                                                    LED1 LED3 LED4
 *   ----------------- ----- -----------------------  ---- ---- ------------
 *   LED_STARTED         0   NuttX has been started   ON   OFF  OFF
 *   LED_HEAPALLOCATE    1   Heap has been allocated  OFF  ON   OFF
 *   LED_IRQSENABLED     2   Interrupts enabled       ON   ON   OFF
 *   LED_STACKCREATED    2   Idle stack created       ON   ON   OFF
 *   LED_INIRQ           3   In an interrupt          N/C  N/C  Soft glow
 *   LED_SIGNAL          3   In a signal handler      N/C  N/C  Soft glow
 *   LED_ASSERTION       3   An assertion failed      N/C  N/C  Soft glow
 *   LED_PANIC           3   The system has crashed   N/C  N/C  2Hz Flashing
 *   LED_IDLE           ---  MCU is is sleep mode         Not used
 *
 *   LED1 is illuminated by driving the output pins to a high value
 *   LED3 and LED 4 are illuminated by taking the output to ground.
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_on(int led)
{
  switch (led)
    {
    case 0:
      a33_pio_write(PIO_LED1, true);
      a33_pio_write(PIO_LED3, true);
      a33_pio_write(PIO_LED4, true);
      break;

    case 1:
      a33_pio_write(PIO_LED1, false);
      a33_pio_write(PIO_LED3, false);
      a33_pio_write(PIO_LED4, true);
      break;

    case 2:
      a33_pio_write(PIO_LED1, false);
      a33_pio_write(PIO_LED3, true);
      a33_pio_write(PIO_LED4, true);
      break;

    case 3:
      a33_pio_write(PIO_LED4, false);
      break;
    }
}
#endif

/****************************************************************************
 * Name: board_autoled_off
 *
 * Description:
 *   Select the "logical" OFF state:
 *
 *   SYMBOL            Value Meaning                    LED state
 *                                                    LED1 LED3 LED4
 *   ----------------- ----- -----------------------  ---- ---- ------------
 *   LED_STARTED         0   NuttX has been started   ON   OFF  OFF
 *   LED_HEAPALLOCATE    1   Heap has been allocated  OFF  ON   OFF
 *   LED_IRQSENABLED     2   Interrupts enabled       ON   ON   OFF
 *   LED_STACKCREATED    2   Idle stack created       ON   ON   OFF
 *   LED_INIRQ           3   In an interrupt          N/C  N/C  Soft glow
 *   LED_SIGNAL          3   In a signal handler      N/C  N/C  Soft glow
 *   LED_ASSERTION       3   An assertion failed      N/C  N/C  Soft glow
 *   LED_PANIC           3   The system has crashed   N/C  N/C  2Hz Flashing
 *   LED_IDLE           ---  MCU is is sleep mode         Not used
 *
 *   LED1 is illuminated by driving the output pins to a high value
 *   LED3 and LED 4 are illuminated by taking the output to ground.
 *
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_off(int led)
{
  switch (led)
    {
    case 0:
    case 1:
    case 2:
      break;

    case 3:
      a33_pio_write(PIO_LED4, true);
      break;
    }
}
#endif

/****************************************************************************
 * Name:  board_userled_initialize, board_userled, and board_userled_all
 *
 * Description:
 *   These interfaces allow user control of the board LEDs.
 *
 *   If CONFIG_ARCH_LEDS is defined, then NuttX will control both on-board
 *   LEDs up until the completion of boot.
 *   The it will continue to control LED2; LED1 is available for application
 *   use.
 *
 *   If CONFIG_ARCH_LEDS is not defined, then both LEDs are available for
 *   application use.
 *
 ****************************************************************************/

void board_userled_initialize(void)
{
  /* Initialization already performed in a33_led_initialize */
}

void board_userled(int led, bool ledon)
{
  switch (led)
    {
    case BOARD_LED1:
      a33_pio_write(PIO_LED1, ledon);
      break;

    case BOARD_LED3:
      a33_pio_write(PIO_LED3, !ledon);
      break;

#ifndef CONFIG_ARCH_LEDS
    case BOARD_LED4:
      a33_pio_write(PIO_LED4, !ledon);
      break;
#endif
    }
}

void board_userled_all(uint8_t ledset)
{
  board_userled(BOARD_LED1, (ledset & BOARD_LED1) != 0);
  board_userled(BOARD_LED3, (ledset & BOARD_LED3) != 0);
#ifndef CONFIG_ARCH_LEDS
  board_userled(BOARD_LED4, (ledset & BOARD_LED4) != 0);
#endif
}
