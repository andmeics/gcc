/*  Special support for trampolines
 *
 *   Copyright (C) 1996, 1997, 2000, 2004 Free Software Foundation, Inc.
 *   Written By Michael Meissner
 * 
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 * 
 * In addition to the permissions in the GNU General Public License, the
 * Free Software Foundation gives you unlimited permission to link the
 * compiled version of this file with other programs, and to distribute
 * those programs without any restriction coming from the use of this
 * file.  (The General Public License restrictions do apply in other
 * respects; for example, they cover modification of the file, and
 * distribution when not linked into another program.)
 * 
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 * 
 *  As a special exception, if you link this library with files
 *  compiled with GCC to produce an executable, this does not cause the
 *  resulting executable to be covered by the GNU General Public License.
 *  This exception does not however invalidate any other reasons why the
 *  executable file might be covered by the GNU General Public License.
 */ 

/* APPLE LOCAL mainline throughout this file */
/* Some 32/64 macros, donated from /usr/include/architecture/ppc . */

#if defined(__ppc64__)
#define MODE_CHOICE(x, y) y
#else
#define MODE_CHOICE(x, y) x
#endif

#define cmpg    MODE_CHOICE(cmpw, cmpd)
#define lg      MODE_CHOICE(lwz, ld)
#define stg     MODE_CHOICE(stw, std)
#define lgx     MODE_CHOICE(lwzx, ldx)
#define stgx    MODE_CHOICE(stwx, stdx)
#define lgu     MODE_CHOICE(lwzu, ldu)
#define stgu    MODE_CHOICE(stwu, stdu)
#define lgux    MODE_CHOICE(lwzux, ldux)
#define stgux   MODE_CHOICE(stwux, stdux)
#define lgwa    MODE_CHOICE(lwz, lwa)

#define g_long  MODE_CHOICE(long, quad)         /* usage is ".g_long" */

#define GPR_BYTES       MODE_CHOICE(4,8)        /* size of a GPR in bytes */
#define LOG2_GPR_BYTES  MODE_CHOICE(2,3)        /* log2(GPR_BYTES) */

/* Set up trampolines.  */

.text
	.align	LOG2_GPR_BYTES
Ltrampoline_initial:
	mflr	r0
	bl	1f
Lfunc = .-Ltrampoline_initial
	.g_long	0		/* will be replaced with function address */
Lchain = .-Ltrampoline_initial
	.g_long	0		/* will be replaced with static chain */
1:	mflr	r11
	lg	r12,0(r11)	/* function address */
	mtlr	r0
	mtctr	r12
	lg	r11,GPR_BYTES(r11)	/* static chain */
	bctr

trampoline_size = .-Ltrampoline_initial

/* R3 = stack address to store trampoline */
/* R4 = length of trampoline area */
/* R5 = function address */
/* R6 = static chain */

	.globl ___trampoline_setup
___trampoline_setup:
	mflr	r0		/* save return address */
        bcl 20,31,LCF0		/* load up __trampoline_initial into r7 */
LCF0:
        mflr	r11
        addis	r7,r11,ha16(LTRAMP-LCF0)
	lg	r7,lo16(LTRAMP-LCF0)(r7)
	subi	r7,r7,GPR_BYTES
	li	r8,trampoline_size	/* verify trampoline big enough */
	cmpg	cr1,r8,r4
	srwi	r4,r4,2			/* # words to move (insns always 4-byte) */
	addi	r9,r3,-GPR_BYTES	/* adjust pointer for lgu */
	mtctr	r4
	blt	cr1,Labort

	mtlr	r0

	/* Copy the instructions to the stack */
Lmove:
	lgu	r10,GPR_BYTES(r7)
	stgu	r10,GPR_BYTES(r9)
	bdnz	Lmove

	/* Store correct function and static chain */
	stg	r5,Lfunc(r3)
	stg	r6,Lchain(r3)

	/* Now flush both caches */
	mtctr	r4
Lcache:
	icbi	0,r3
	dcbf	0,r3
	addi	r3,r3,4
	bdnz	Lcache

	/* Finally synchronize things & return */
	sync
	isync
	blr

Labort:
#ifdef __DYNAMIC__
	bl	L_abort$stub
.data
.section __TEXT,__picsymbolstub1,symbol_stubs,pure_instructions,32
	.align 2
L_abort$stub:
        .indirect_symbol _abort
        mflr r0
        bcl 20,31,L0$_abort
L0$_abort:
        mflr r11
        addis r11,r11,ha16(L_abort$lazy_ptr-L0$_abort)
        mtlr r0
	lgu r12,lo16(L_abort$lazy_ptr-L0$_abort)(r11)
        mtctr r12
        bctr
.data
.lazy_symbol_pointer
L_abort$lazy_ptr:
        .indirect_symbol _abort
	.g_long	dyld_stub_binding_helper
#else
	bl	_abort
#endif
.data
	.align LOG2_GPR_BYTES
LTRAMP:
	.g_long Ltrampoline_initial

