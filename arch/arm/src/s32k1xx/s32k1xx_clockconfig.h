/****************************************************************************
 * arch/arm/src/s32k1xx/s32k1xx_clockconfig.h
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
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

#ifndef __ARCH_ARM_SRC_S32K1XX_S32K1XX_CLKCONFIG_H
#define __ARCH_ARM_SRC_S32K1XX_S32K1XX_CLKCONFIG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* PLL setup structure.
 *
 * This structure can be used to define a PLL configuration.  If powering
 * up or waiting for PLL lock, the PLL input clock source should be
 * configured prior to PLL setup.
 */

struct pll_setup_s
{
  uint32_t pllclksel;       /* PLL clock source register SYSPLLCLKSEL */
  uint32_t pllctrl;         /* PLL control register SYSPLLCTRL */
  uint32_t pllndec;         /* PLL NDEC register SYSPLLNDEC */
  uint32_t pllpdec;         /* PLL PDEC register SYSPLLPDEC */
  uint32_t pllmdec;         /* PLL MDEC registers SYSPLLPDEC */
  uint32_t pllfout;         /* Actual PLL output frequency */
  uint32_t pllfrac;         /* Only aduio PLL has this function*/
  uint32_t pllflags;        /* PLL setup flags */
  uint32_t ahbdiv;          /* AHB divider */
};

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Data
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: s32k1xx_clockconfig
 *
 * Description:
 *   Called to initialize the S32K1XX.  This does whatever setup is needed
 *   to put the MCU in a usable state.  This includes the initialization of
 *   clocking using the settings in board.h.  This function also performs
 *   other low-level chip as necessary.
 *
 *****************************************************************************/

void s32k1xx_clockconfig(FAR const struct pll_setup_s *pllsetup);

/****************************************************************************
 * Name: s32k1xx_get_coreclk
 *
 * Description:
 *   Return the current selection of the CORE clock.
 *
 *****************************************************************************/

uint32_t s32k1xx_get_coreclk(void);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_S32K1XX_S32K1XX_CLKCONFIG_H */