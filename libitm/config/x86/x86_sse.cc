/* Copyright (C) 2009, 2011 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU Transactional Memory Library (libitm).

   Libitm is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   Libitm is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include "libitm_i.h"
#include "dispatch.h"

// ??? Use memcpy for now, until we have figured out how to best instantiate
// these loads/stores.
CREATE_DISPATCH_FUNCTIONS_T_MEMCPY(M64, GTM::abi_disp()->, )
CREATE_DISPATCH_FUNCTIONS_T_MEMCPY(M128, GTM::abi_disp()->, )

void ITM_REGPARM
_ITM_LM64 (const _ITM_TYPE_M64 *ptr)
{
  GTM::GTM_LB (ptr, sizeof (*ptr));
}

void ITM_REGPARM
_ITM_LM128 (const _ITM_TYPE_M128 *ptr)
{
  GTM::GTM_LB (ptr, sizeof (*ptr));
}

// Helpers for re-aligning two 128-bit values.
#ifdef __SSSE3__
# define INSN0		"movdqa	%xmm1, %xmm0"
# define INSN(N)	"palignr $" #N ", %xmm1, %xmm0"
# define TABLE_ENT_0	INSN0 "\n\tret\n\t"
# define TABLE_ENT(N)	".balign 8\n\t" INSN(N) "\n\tret\n\t"

asm(".pushsection .text\n\
	.balign 16\n\
	.globl	GTM_palignr_table\n\
	.hidden	GTM_palignr_table\n\
	.type	GTM_palignr_table, @function\n\
GTM_palignr_table:\n\t"
	TABLE_ENT_0
	TABLE_ENT(1)
	TABLE_ENT(2)
	TABLE_ENT(3)
	TABLE_ENT(4)
	TABLE_ENT(5)
	TABLE_ENT(6)
	TABLE_ENT(7)
	TABLE_ENT(8)
	TABLE_ENT(9)
	TABLE_ENT(10)
	TABLE_ENT(11)
	TABLE_ENT(12)
	TABLE_ENT(13)
	TABLE_ENT(14)
	TABLE_ENT(15)
	".balign 8\n\
	.size	GTM_palignr_table, .-GTM_palignr_table\n\
	.popsection");

# undef INSN0
# undef INSN
# undef TABLE_ENT_0
# undef TABLE_ENT
#elif defined(__SSE2__)
# define INSNS_8	"punpcklqdq %xmm1, %xmm0"
# define INSNS(N)	"psrldq $"#N", %xmm0\n\t" \
			"pslldq $(16-"#N"), %xmm1\n\t" \
			"por %xmm1, %xmm0"
# define TABLE_ENT_0	"ret\n\t"
# define TABLE_ENT_8	".balign 16\n\t" INSNS_8 "\n\tret\n\t"
# define TABLE_ENT(N)	".balign 16\n\t" INSNS(N) "\n\tret\n\t"

asm(".pushsection .text\n\
	.balign 16\n\
	.globl	GTM_pshift_table\n\
	.hidden	GTM_pshift_table\n\
	.type	GTM_pshift_table, @function\n\
GTM_pshift_table:\n\t"
	TABLE_ENT_0
	TABLE_ENT(1)
	TABLE_ENT(2)
	TABLE_ENT(3)
	TABLE_ENT(4)
	TABLE_ENT(5)
	TABLE_ENT(6)
	TABLE_ENT(7)
	TABLE_ENT_8
	TABLE_ENT(9)
	TABLE_ENT(10)
	TABLE_ENT(11)
	TABLE_ENT(12)
	TABLE_ENT(13)
	TABLE_ENT(14)
	TABLE_ENT(15)
	".balign 8\n\
	.size	GTM_pshift_table, .-GTM_pshift_table\n\
	.popsection");

# undef INSNS_8
# undef INSNS
# undef TABLE_ENT_0
# undef TABLE_ENT_8
# undef TABLE_ENT
#endif
