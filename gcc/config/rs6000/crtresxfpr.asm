/*
 * Special support for eabi and SVR4
 *
 *   Copyright (C) 1995, 1996, 1998, 2000, 2001, 2008, 2009
 *   Free Software Foundation, Inc.
 *   Written By Michael Meissner
 *   64-bit support written by David Edelsohn
 * 
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3, or (at your option) any
 * later version.
 * 
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * Under Section 7 of GPL version 3, you are granted additional
 * permissions described in the GCC Runtime Library Exception, version
 * 3.1, as published by the Free Software Foundation.
 *
 * You should have received a copy of the GNU General Public License and
 * a copy of the GCC Runtime Library Exception along with this program;
 * see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
 * <http://www.gnu.org/licenses/>.
 */ 

/* Do any initializations needed for the eabi environment */

	.section ".text"
	#include "ppc-asm.h"

/* On PowerPC64 Linux, these functions are provided by the linker.  */
#ifndef __powerpc64__

/* Routines for restoring floating point registers, called by the compiler.  */
/* Called with r11 pointing to the stack header word of the caller of the */
/* function, just beyond the end of the floating point save area.  */
/* In addition to restoring the fp registers, it will return to the caller's */
/* caller */

HIDDEN_FUNC(_restfpr_14_x)	lfd	14,-144(11)	/* restore fp registers */
HIDDEN_FUNC(_restfpr_15_x)	lfd	15,-136(11)
HIDDEN_FUNC(_restfpr_16_x)	lfd	16,-128(11)
HIDDEN_FUNC(_restfpr_17_x)	lfd	17,-120(11)
HIDDEN_FUNC(_restfpr_18_x)	lfd	18,-112(11)
HIDDEN_FUNC(_restfpr_19_x)	lfd	19,-104(11)
HIDDEN_FUNC(_restfpr_20_x)	lfd	20,-96(11)
HIDDEN_FUNC(_restfpr_21_x)	lfd	21,-88(11)
HIDDEN_FUNC(_restfpr_22_x)	lfd	22,-80(11)
HIDDEN_FUNC(_restfpr_23_x)	lfd	23,-72(11)
HIDDEN_FUNC(_restfpr_24_x)	lfd	24,-64(11)
HIDDEN_FUNC(_restfpr_25_x)	lfd	25,-56(11)
HIDDEN_FUNC(_restfpr_26_x)	lfd	26,-48(11)
HIDDEN_FUNC(_restfpr_27_x)	lfd	27,-40(11)
HIDDEN_FUNC(_restfpr_28_x)	lfd	28,-32(11)
HIDDEN_FUNC(_restfpr_29_x)	lfd	29,-24(11)
HIDDEN_FUNC(_restfpr_30_x)	lfd	30,-16(11)
HIDDEN_FUNC(_restfpr_31_x)	lwz	0,4(11)
				lfd	31,-8(11)
				mtlr	0
				mr	1,11
				blr
FUNC_END(_restfpr_31_x)
FUNC_END(_restfpr_30_x)
FUNC_END(_restfpr_29_x)
FUNC_END(_restfpr_28_x)
FUNC_END(_restfpr_27_x)
FUNC_END(_restfpr_26_x)
FUNC_END(_restfpr_25_x)
FUNC_END(_restfpr_24_x)
FUNC_END(_restfpr_23_x)
FUNC_END(_restfpr_22_x)
FUNC_END(_restfpr_21_x)
FUNC_END(_restfpr_20_x)
FUNC_END(_restfpr_19_x)
FUNC_END(_restfpr_18_x)
FUNC_END(_restfpr_17_x)
FUNC_END(_restfpr_16_x)
FUNC_END(_restfpr_15_x)
FUNC_END(_restfpr_14_x)

#endif
