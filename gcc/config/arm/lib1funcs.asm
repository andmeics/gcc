@ libgcc routines for ARM cpu.
@ Division routines, written by Richard Earnshaw, (rearnsha@armltd.co.uk)

/* Copyright 1995, 1996, 1998, 1999, 2000 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */
/* ------------------------------------------------------------------------ */

/* We need to know what prefix to add to function names.  */

#ifndef __USER_LABEL_PREFIX__
#error  __USER_LABEL_PREFIX__ not defined
#endif

/* ANSI concatenation macros.  */

#define CONCAT1(a, b) CONCAT2(a, b)
#define CONCAT2(a, b) a ## b

/* Use the right prefix for global labels.  */

#define SYM(x) CONCAT1 (__USER_LABEL_PREFIX__, x)

#ifdef __ELF__
#ifdef __thumb__
#define __PLT__  /* Not supported in Thumb assembler (for now).  */
#else
#define __PLT__ (PLT)
#endif
#define TYPE(x) .type SYM(x),function
#define SIZE(x) .size SYM(x), . - SYM(x)
#define LSYM(x) .x
#else
#define __PLT__
#define TYPE(x)
#define SIZE(x)
#define LSYM(x) x
#endif

/* Function end macros.  Variants for 26 bit APCS and interworking.  */

@ This selects the minimum architecture level required.
#define __ARM_ARCH__ 3

#if defined(__ARM_ARCH_3M__) || defined(__ARM_ARCH_4__) \
	|| defined(__ARM_ARCH_4T__)
/* We use __ARM_ARCH__ set to 4 here, but in reality it's any processor with
   long multiply instructions.  That includes v3M.  */
# undef __ARM_ARCH__
# define __ARM_ARCH__ 4
#endif
	
#if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5T__) \
	|| defined(__ARM_ARCH_5TE__)
# undef __ARM_ARCH__
# define __ARM_ARCH__ 5
#endif

/* How to return from a function call depends on the architecture variant.  */

#ifdef __APCS_26__

# define RET		movs	pc, lr
# define RETc(x)	mov##x##s	pc, lr

#elif (__ARM_ARCH__ > 4) || defined(__ARM_ARCH_4T__)

# define RET		bx	lr
# define RETc(x)	bx##x	lr

# if (__ARM_ARCH__ == 4) \
	&& (defined(__thumb__) || defined(__THUMB_INTERWORK__))
#  define __INTERWORKING__
# endif

#else

# define RET		mov	pc, lr
# define RETc(x)	mov##x	pc, lr

#endif

/* Don't pass dirn, it's there just to get token pasting right.  */

.macro	RETLDM	regs=, cond=, dirn=ia
#ifdef __APCS_26__
	.ifc "\regs",""
	ldm\cond\dirn	sp!, {pc}^
	.else
	ldm\cond\dirn	sp!, {\regs, pc}^
	.endif
#elif defined (__INTERWORKING__)
	.ifc "\regs",""
	ldr\cond	lr, [sp], #4
	.else
	ldm\cond\dirn	sp!, {\regs, lr}
	.endif
	bx\cond	lr
#else
	.ifc "\regs",""
	ldr\cond	pc, [sp], #4
	.else
	ldm\cond\dirn	sp!, {\regs, pc}
	.endif
#endif
.endm


.macro ARM_LDIV0
LSYM(Ldiv0):
	str	lr, [sp, #-4]!
	bl	SYM (__div0) __PLT__
	mov	r0, #0			@ About as wrong as it could be.
	RETLDM
.endm


.macro THUMB_LDIV0
LSYM(Ldiv0):
	push	{ lr }
	bl	SYM (__div0)
	mov	r0, #0			@ About as wrong as it could be.
#if defined (__INTERWORKING__)
	pop	{ r1 }
	bx	r1
#else
	pop	{ pc }
#endif
.endm

.macro FUNC_END name
	SIZE (__\name)
.endm

.macro DIV_FUNC_END name
LSYM(Ldiv0):
#ifdef __thumb__
	THUMB_LDIV0
#else
	ARM_LDIV0
#endif
	FUNC_END \name
.endm

.macro THUMB_FUNC_START name
	.globl	SYM (\name)
	TYPE	(\name)
	.thumb_func
SYM (\name):
.endm

/* Function start macros.  Variants for ARM and Thumb.  */

#ifdef __thumb__
#define THUMB_FUNC .thumb_func
#define THUMB_CODE .force_thumb
#else
#define THUMB_FUNC
#define THUMB_CODE
#endif
	
.macro FUNC_START name
	.text
	.globl SYM (__\name)
	TYPE (__\name)
	.align 0
	THUMB_CODE
	THUMB_FUNC
SYM (__\name):
.endm

/* Special function that will always be coded in ARM assembly, even if
   in Thumb-only compilation.  */

#if defined(__thumb__) && !defined(__THUMB_INTERWORK__)
.macro	ARM_FUNC_START name
	FUNC_START \name
	bx	pc
	nop
	.arm
_L__\name:		/* A hook to tell gdb that we've switched to ARM */
.endm
#else
.macro	ARM_FUNC_START name
	FUNC_START \name
.endm
#endif

/* Register aliases.  */

work		.req	r4	@ XXXX is this safe ?
dividend	.req	r0
divisor		.req	r1
overdone	.req	r2
result		.req	r2
curbit		.req	r3
#if 0
ip		.req	r12
sp		.req	r13
lr		.req	r14
pc		.req	r15
#endif
/* ------------------------------------------------------------------------ */
/*		Bodies of the division and modulo routines.		    */
/* ------------------------------------------------------------------------ */	
.macro ARM_DIV_MOD_BODY modulo
LSYM(Loop1):
	@ Unless the divisor is very big, shift it up in multiples of
	@ four bits, since this is the amount of unwinding in the main
	@ division loop.  Continue shifting until the divisor is 
	@ larger than the dividend.
	cmp	divisor, #0x10000000
	cmplo	divisor, dividend
	movlo	divisor, divisor, lsl #4
	movlo	curbit,  curbit,  lsl #4
	blo	LSYM(Loop1)

LSYM(Lbignum):
	@ For very big divisors, we must shift it a bit at a time, or
	@ we will be in danger of overflowing.
	cmp	divisor, #0x80000000
	cmplo	divisor, dividend
	movlo	divisor, divisor, lsl #1
	movlo	curbit,  curbit,  lsl #1
	blo	LSYM(Lbignum)

LSYM(Loop3):
	@ Test for possible subtractions.  On the final pass, this may 
	@ subtract too much from the dividend ...
	
  .if \modulo
	@ ... so keep track of which subtractions are done in OVERDONE.
	@ We can fix them up afterwards.
	mov	overdone, #0
	cmp	dividend, divisor
	subhs	dividend, dividend, divisor
	cmp	dividend, divisor,  lsr #1
	subhs	dividend, dividend, divisor, lsr #1
	orrhs	overdone, overdone, curbit,  ror #1
	cmp	dividend, divisor,  lsr #2
	subhs	dividend, dividend, divisor, lsr #2
	orrhs	overdone, overdone, curbit,  ror #2
	cmp	dividend, divisor,  lsr #3
	subhs	dividend, dividend, divisor, lsr #3
	orrhs	overdone, overdone, curbit,  ror #3
	mov	ip,       curbit
  .else
	@ ... so keep track of which subtractions are done in RESULT.
	@ The result will be ok, since the "bit" will have been 
	@ shifted out at the bottom.
	cmp	dividend, divisor
	subhs	dividend, dividend, divisor
	orrhs	result,   result,   curbit
	cmp	dividend, divisor,  lsr #1
	subhs	dividend, dividend, divisor, lsr #1
	orrhs	result,   result,   curbit,  lsr #1
	cmp	dividend, divisor,  lsr #2
	subhs	dividend, dividend, divisor, lsr #2
	orrhs	result,   result,   curbit,  lsr #2
	cmp	dividend, divisor,  lsr #3
	subhs	dividend, dividend, divisor, lsr #3
	orrhs	result,   result,   curbit,  lsr #3
  .endif

	cmp	dividend, #0			@ Early termination?
	movnes	curbit,   curbit,  lsr #4	@ No, any more bits to do?
	movne	divisor,  divisor, lsr #4
	bne	LSYM(Loop3)

  .if \modulo
LSYM(Lfixup_dividend):	
	@ Any subtractions that we should not have done will be recorded in
	@ the top three bits of OVERDONE.  Exactly which were not needed
	@ are governed by the position of the bit, stored in IP.
	ands	overdone, overdone, #0xe0000000
	@ If we terminated early, because dividend became zero, then the 
	@ bit in ip will not be in the bottom nibble, and we should not
	@ perform the additions below.  We must test for this though
	@ (rather relying upon the TSTs to prevent the additions) since
	@ the bit in ip could be in the top two bits which might then match
	@ with one of the smaller RORs.
	tstne	ip, #0x7
	beq	LSYM(Lgot_result)
	tst	overdone, ip, ror #3
	addne	dividend, dividend, divisor, lsr #3
	tst	overdone, ip, ror #2
	addne	dividend, dividend, divisor, lsr #2
	tst	overdone, ip, ror #1
	addne	dividend, dividend, divisor, lsr #1
  .endif

LSYM(Lgot_result):
.endm
/* ------------------------------------------------------------------------ */
.macro THUMB_DIV_MOD_BODY modulo
	@ Load the constant 0x10000000 into our work register.
	mov	work, #1
	lsl	work, #28
LSYM(Loop1):
	@ Unless the divisor is very big, shift it up in multiples of
	@ four bits, since this is the amount of unwinding in the main
	@ division loop.  Continue shifting until the divisor is 
	@ larger than the dividend.
	cmp	divisor, work
	bhs	LSYM(Lbignum)
	cmp	divisor, dividend
	bhs	LSYM(Lbignum)
	lsl	divisor, #4
	lsl	curbit,  #4
	b	LSYM(Loop1)
LSYM(Lbignum):
	@ Set work to 0x80000000
	lsl	work, #3
LSYM(Loop2):
	@ For very big divisors, we must shift it a bit at a time, or
	@ we will be in danger of overflowing.
	cmp	divisor, work
	bhs	LSYM(Loop3)
	cmp	divisor, dividend
	bhs	LSYM(Loop3)
	lsl	divisor, #1
	lsl	curbit,  #1
	b	LSYM(Loop2)
LSYM(Loop3):
	@ Test for possible subtractions ...
  .if \modulo
	@ ... On the final pass, this may subtract too much from the dividend, 
	@ so keep track of which subtractions are done, we can fix them up 
	@ afterwards.
	mov	overdone, #0
	cmp	dividend, divisor
	blo	LSYM(Lover1)
	sub	dividend, dividend, divisor
LSYM(Lover1):
	lsr	work, divisor, #1
	cmp	dividend, work
	blo	LSYM(Lover2)
	sub	dividend, dividend, work
	mov	ip, curbit
	mov	work, #1
	ror	curbit, work
	orr	overdone, curbit
	mov	curbit, ip
LSYM(Lover2):
	lsr	work, divisor, #2
	cmp	dividend, work
	blo	LSYM(Lover3)
	sub	dividend, dividend, work
	mov	ip, curbit
	mov	work, #2
	ror	curbit, work
	orr	overdone, curbit
	mov	curbit, ip
LSYM(Lover3):
	lsr	work, divisor, #3
	cmp	dividend, work
	blo	LSYM(Lover4)
	sub	dividend, dividend, work
	mov	ip, curbit
	mov	work, #3
	ror	curbit, work
	orr	overdone, curbit
	mov	curbit, ip
LSYM(Lover4):
	mov	ip, curbit
  .else
	@ ... and note which bits are done in the result.  On the final pass,
	@ this may subtract too much from the dividend, but the result will be ok,
	@ since the "bit" will have been shifted out at the bottom.
	cmp	dividend, divisor
	blo	LSYM(Lover1)
	sub	dividend, dividend, divisor
	orr	result, result, curbit
LSYM(Lover1):
	lsr	work, divisor, #1
	cmp	dividend, work
	blo	LSYM(Lover2)
	sub	dividend, dividend, work
	lsr	work, curbit, #1
	orr	result, work
LSYM(Lover2):
	lsr	work, divisor, #2
	cmp	dividend, work
	blo	LSYM(Lover3)
	sub	dividend, dividend, work
	lsr	work, curbit, #2
	orr	result, work
LSYM(Lover3):
	lsr	work, divisor, #3
	cmp	dividend, work
	blo	LSYM(Lover4)
	sub	dividend, dividend, work
	lsr	work, curbit, #3
	orr	result, work
LSYM(Lover4):
  .endif
	
	cmp	dividend, #0			@ Early termination?
	beq	LSYM(Lover5)
	lsr	curbit,  #4			@ No, any more bits to do?
	beq	LSYM(Lover5)
	lsr	divisor, #4
	b	LSYM(Loop3)
LSYM(Lover5):
  .if \modulo
	@ Any subtractions that we should not have done will be recorded in
	@ the top three bits of "overdone".  Exactly which were not needed
	@ are governed by the position of the bit, stored in ip.
	mov	work, #0xe
	lsl	work, #28
	and	overdone, work
	beq	LSYM(Lgot_result)
	
	@ If we terminated early, because dividend became zero, then the 
	@ bit in ip will not be in the bottom nibble, and we should not
	@ perform the additions below.  We must test for this though
	@ (rather relying upon the TSTs to prevent the additions) since
	@ the bit in ip could be in the top two bits which might then match
	@ with one of the smaller RORs.
	mov	curbit, ip
	mov	work, #0x7
	tst	curbit, work
	beq	LSYM(Lgot_result)
	
	mov	curbit, ip
	mov	work, #3
	ror	curbit, work
	tst	overdone, curbit
	beq	LSYM(Lover6)
	lsr	work, divisor, #3
	add	dividend, work
LSYM(Lover6):
	mov	curbit, ip
	mov	work, #2
	ror	curbit, work
	tst	overdone, curbit
	beq	LSYM(Lover7)
	lsr	work, divisor, #2
	add	dividend, work
LSYM(Lover7):
	mov	curbit, ip
	mov	work, #1
	ror	curbit, work
	tst	overdone, curbit
	beq	LSYM(Lgot_result)
	lsr	work, divisor, #1
	add	dividend, work
  .endif
LSYM(Lgot_result):
.endm	
/* ------------------------------------------------------------------------ */
/*		Start of the Real Functions				    */
/* ------------------------------------------------------------------------ */
#ifdef L_udivsi3

	FUNC_START udivsi3

#ifdef __thumb__

	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	mov	curbit, #1
	mov	result, #0
	
	push	{ work }
	cmp	dividend, divisor
	blo	LSYM(Lgot_result)

	THUMB_DIV_MOD_BODY 0
	
	mov	r0, result
	pop	{ work }
	RET

#else /* ARM version.  */
	
	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	mov	curbit, #1
	mov	result, #0
	cmp	dividend, divisor
	blo	LSYM(Lgot_result)
	
	ARM_DIV_MOD_BODY 0
	
	mov	r0, result
	RET	

#endif /* ARM version */

	DIV_FUNC_END udivsi3

#endif /* L_udivsi3 */
/* ------------------------------------------------------------------------ */
#ifdef L_umodsi3

	FUNC_START umodsi3

#ifdef __thumb__

	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	mov	curbit, #1
	cmp	dividend, divisor
	bhs	LSYM(Lover10)
	RET	

LSYM(Lover10):
	push	{ work }

	THUMB_DIV_MOD_BODY 1
	
	pop	{ work }
	RET
	
#else  /* ARM version.  */
	
	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	cmp     divisor, #1
	cmpne	dividend, divisor
	moveq   dividend, #0
	RETc(lo)
	mov	curbit, #1

	ARM_DIV_MOD_BODY 1
	
	RET	

#endif /* ARM version.  */
	
	DIV_FUNC_END umodsi3

#endif /* L_umodsi3 */
/* ------------------------------------------------------------------------ */
#ifdef L_divsi3

	FUNC_START divsi3	

#ifdef __thumb__
	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	
	push	{ work }
	mov	work, dividend
	eor	work, divisor		@ Save the sign of the result.
	mov	ip, work
	mov	curbit, #1
	mov	result, #0
	cmp	divisor, #0
	bpl	LSYM(Lover10)
	neg	divisor, divisor	@ Loops below use unsigned.
LSYM(Lover10):
	cmp	dividend, #0
	bpl	LSYM(Lover11)
	neg	dividend, dividend
LSYM(Lover11):
	cmp	dividend, divisor
	blo	LSYM(Lgot_result)

	THUMB_DIV_MOD_BODY 0
	
	mov	r0, result
	mov	work, ip
	cmp	work, #0
	bpl	LSYM(Lover12)
	neg	r0, r0
LSYM(Lover12):
	pop	{ work }
	RET

#else /* ARM version.  */
	
	eor	ip, dividend, divisor		@ Save the sign of the result.
	mov	curbit, #1
	mov	result, #0
	cmp	divisor, #0
	rsbmi	divisor, divisor, #0		@ Loops below use unsigned.
	beq	LSYM(Ldiv0)
	cmp	dividend, #0
	rsbmi	dividend, dividend, #0
	cmp	dividend, divisor
	blo	LSYM(Lgot_result)

	ARM_DIV_MOD_BODY 0
	
	mov	r0, result
	cmp	ip, #0
	rsbmi	r0, r0, #0
	RET	

#endif /* ARM version */
	
	DIV_FUNC_END divsi3

#endif /* L_divsi3 */
/* ------------------------------------------------------------------------ */
#ifdef L_modsi3

	FUNC_START modsi3

#ifdef __thumb__

	mov	curbit, #1
	cmp	divisor, #0
	beq	LSYM(Ldiv0)
	bpl	LSYM(Lover10)
	neg	divisor, divisor		@ Loops below use unsigned.
LSYM(Lover10):
	push	{ work }
	@ Need to save the sign of the dividend, unfortunately, we need
	@ work later on.  Must do this after saving the original value of
	@ the work register, because we will pop this value off first.
	push	{ dividend }
	cmp	dividend, #0
	bpl	LSYM(Lover11)
	neg	dividend, dividend
LSYM(Lover11):
	cmp	dividend, divisor
	blo	LSYM(Lgot_result)

	THUMB_DIV_MOD_BODY 1
		
	pop	{ work }
	cmp	work, #0
	bpl	LSYM(Lover12)
	neg	dividend, dividend
LSYM(Lover12):
	pop	{ work }
	RET	

#else /* ARM version.  */
	
	cmp	divisor, #0
	rsbmi	divisor, divisor, #0		@ Loops below use unsigned.
	beq	LSYM(Ldiv0)
	@ Need to save the sign of the dividend, unfortunately, we need
	@ ip later on; this is faster than pushing lr and using that.
	str	dividend, [sp, #-4]!
	cmp	dividend, #0			@ Test dividend against zero
	rsbmi	dividend, dividend, #0		@ If negative make positive
	cmp	dividend, divisor		@ else if zero return zero
	blo	LSYM(Lgot_result)		@ if smaller return dividend
	mov	curbit, #1

	ARM_DIV_MOD_BODY 1

	ldr	ip, [sp], #4
	cmp	ip, #0
	rsbmi	dividend, dividend, #0
	RET	

#endif /* ARM version */
	
	DIV_FUNC_END modsi3

#endif /* L_modsi3 */
/* ------------------------------------------------------------------------ */
#ifdef L_dvmd_tls

	FUNC_START div0

	RET

	FUNC_END div0
	
#endif /* L_divmodsi_tools */
/* ------------------------------------------------------------------------ */
#ifdef L_dvmd_lnx
@ GNU/Linux division-by zero handler.  Used in place of L_dvmd_tls

/* Constants taken from <asm/unistd.h> and <asm/signal.h> */
#define SIGFPE	8
#define __NR_SYSCALL_BASE	0x900000
#define __NR_getpid			(__NR_SYSCALL_BASE+ 20)
#define __NR_kill			(__NR_SYSCALL_BASE+ 37)

	.code	32
	FUNC_START div0

	stmfd	sp!, {r1, lr}
	swi	__NR_getpid
	cmn	r0, #1000
	RETLDM	r1 hs
	mov	r1, #SIGFPE
	swi	__NR_kill
	RETLDM	r1

	FUNC_END div0
	
#endif /* L_dvmd_lnx */
/* ------------------------------------------------------------------------ */
/* These next two sections are here despite the fact that they contain Thumb 
   assembler because their presence allows interworked code to be linked even
   when the GCC library is this one.  */
		
/* Do not build the interworking functions when the target architecture does 
   not support Thumb instructions.  (This can be a multilib option).  */
#if defined L_call_via_rX && (defined __ARM_ARCH_4T__ || defined __ARM_ARCH_5T__ || defined __ARM_ARCH_5TE__)

/* These labels & instructions are used by the Arm/Thumb interworking code. 
   The address of function to be called is loaded into a register and then 
   one of these labels is called via a BL instruction.  This puts the 
   return address into the link register with the bottom bit set, and the 
   code here switches to the correct mode before executing the function.  */
	
	.text
	.align 0
        .force_thumb

.macro call_via register
	THUMB_FUNC_START _call_via_\register

	bx	\register
	nop

	SIZE	(_call_via_\register)
.endm

	call_via r0
	call_via r1
	call_via r2
	call_via r3
	call_via r4
	call_via r5
	call_via r6
	call_via r7
	call_via r8
	call_via r9
	call_via sl
	call_via fp
	call_via ip
	call_via sp
	call_via lr

#endif /* L_call_via_rX */
/* ------------------------------------------------------------------------ */
/* Do not build the interworking functions when the target architecture does 
   not support Thumb instructions.  (This can be a multilib option).  */
#if defined L_interwork_call_via_rX && (defined __ARM_ARCH_4T__ || defined __ARM_ARCH_5T__ || defined __ARM_ARCH_5TE__)

/* These labels & instructions are used by the Arm/Thumb interworking code,
   when the target address is in an unknown instruction set.  The address 
   of function to be called is loaded into a register and then one of these
   labels is called via a BL instruction.  This puts the return address 
   into the link register with the bottom bit set, and the code here 
   switches to the correct mode before executing the function.  Unfortunately
   the target code cannot be relied upon to return via a BX instruction, so
   instead we have to store the resturn address on the stack and allow the
   called function to return here instead.  Upon return we recover the real
   return address and use a BX to get back to Thumb mode.  */
	
	.text
	.align 0

	.code   32
	.globl _arm_return
_arm_return:
	RETLDM
	.code   16

.macro interwork register
	.code	16

	THUMB_FUNC_START _interwork_call_via_\register

	bx	pc
	nop

	.code	32
	.globl LSYM(Lchange_\register)
LSYM(Lchange_\register):
	tst	\register, #1
	streq	lr, [sp, #-4]!
	adreq	lr, _arm_return
	bx	\register

	SIZE	(_interwork_call_via_\register)
.endm
	
	interwork r0
	interwork r1
	interwork r2
	interwork r3
	interwork r4
	interwork r5
	interwork r6
	interwork r7
	interwork r8
	interwork r9
	interwork sl
	interwork fp
	interwork ip
	interwork sp
	
	/* The LR case has to be handled a little differently...  */
	.code 16

	THUMB_FUNC_START _interwork_call_via_lr

	bx 	pc
	nop
	
	.code 32
	.globl .Lchange_lr
.Lchange_lr:
	tst	lr, #1
	stmeqdb	r13!, {lr}
	mov	ip, lr
	adreq	lr, _arm_return
	bx	ip
	
	SIZE	(_interwork_call_via_lr)
	
#endif /* L_interwork_call_via_rX */

#include "ieee754-df.S"
#include "ieee754-sf.S"

