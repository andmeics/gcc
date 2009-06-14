/* PowerPC asm definitions for GNU C.

Copyright (C) 2002, 2003, 2008, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* Under winnt, 1) gas supports the following as names and 2) in particular
   defining "toc" breaks the FUNC_START macro as ".toc" becomes ".2" */

#define r0	0
#define sp	1
#define toc	2
#define r3	3
#define r4	4
#define r5	5
#define r6	6
#define r7	7
#define r8	8
#define r9	9
#define r10	10
#define r11	11
#define r12	12
#define r13	13
#define r14	14
#define r15	15
#define r16	16
#define r17	17
#define r18	18
#define r19     19
#define r20	20
#define r21	21
#define r22	22
#define r23	23
#define r24	24
#define r25	25
#define r26	26
#define r27	27
#define r28	28
#define r29	29
#define r30	30
#define r31	31

#define cr0	0
#define cr1	1
#define cr2	2
#define cr3	3
#define cr4	4
#define cr5	5
#define cr6	6
#define cr7	7

#define f0	0
#define f1	1
#define f2	2
#define f3	3
#define f4	4
#define f5	5
#define f6	6
#define f7	7
#define f8	8
#define f9	9
#define f10	10
#define f11	11
#define f12	12
#define f13	13
#define f14	14
#define f15	15
#define f16	16
#define f17	17
#define f18	18
#define f19     19
#define f20	20
#define f21	21
#define f22	22
#define f23	23
#define f24	24
#define f25	25
#define f26	26
#define f27	27
#define f28	28
#define f29	29
#define f30	30
#define f31	31

/*
 * Macros to glue together two tokens.
 */

#ifdef __STDC__
#define XGLUE(a,b) a##b
#else
#define XGLUE(a,b) a/**/b
#endif

#define GLUE(a,b) XGLUE(a,b)

/*
 * Macros to begin and end a function written in assembler.  If -mcall-aixdesc
 * or -mcall-nt, create a function descriptor with the given name, and create
 * the real function with one or two leading periods respectively.
 */

#if defined (__powerpc64__)
#define FUNC_NAME(name) GLUE(.,name)
#define JUMP_TARGET(name) FUNC_NAME(name)
#define FUNC_START(name) \
	.section ".opd","aw"; \
name: \
	.quad GLUE(.,name); \
	.quad .TOC.@tocbase; \
	.quad 0; \
	.previous; \
	.type GLUE(.,name),@function; \
	.globl name; \
	.globl GLUE(.,name); \
GLUE(.,name):

#define HIDDEN_FUNC(name) \
  FUNC_START(name) \
  .hidden name;	\
  .hidden GLUE(.,name);

#define FUNC_END(name) \
GLUE(.L,name): \
	.size GLUE(.,name),GLUE(.L,name)-GLUE(.,name)

#elif defined(_CALL_AIXDESC)

#ifdef _RELOCATABLE
#define DESC_SECTION ".got2"
#else
#define DESC_SECTION ".got1"
#endif

#define FUNC_NAME(name) GLUE(.,name)
#define JUMP_TARGET(name) FUNC_NAME(name)
#define FUNC_START(name) \
	.section DESC_SECTION,"aw"; \
name: \
	.long GLUE(.,name); \
	.long _GLOBAL_OFFSET_TABLE_; \
	.long 0; \
	.previous; \
	.type GLUE(.,name),@function; \
	.globl name; \
	.globl GLUE(.,name); \
GLUE(.,name):

#define HIDDEN_FUNC(name) \
  FUNC_START(name) \
  .hidden name; \
  .hidden GLUE(.,name);

#define FUNC_END(name) \
GLUE(.L,name): \
	.size GLUE(.,name),GLUE(.L,name)-GLUE(.,name)

#else

#define FUNC_NAME(name) GLUE(__USER_LABEL_PREFIX__,name)
#if defined __PIC__ || defined __pic__
#define JUMP_TARGET(name) FUNC_NAME(name@plt)
#else
#define JUMP_TARGET(name) FUNC_NAME(name)
#endif
#define FUNC_START(name) \
	.type FUNC_NAME(name),@function; \
	.globl FUNC_NAME(name); \
FUNC_NAME(name):

#define HIDDEN_FUNC(name) \
  FUNC_START(name) \
  .hidden FUNC_NAME(name);

#define FUNC_END(name) \
GLUE(.L,name): \
	.size FUNC_NAME(name),GLUE(.L,name)-FUNC_NAME(name)
#endif

#ifdef IN_GCC
/* For HAVE_GAS_CFI_DIRECTIVE.  */
#include "auto-host.h"

#ifdef HAVE_GAS_CFI_DIRECTIVE
# define CFI_STARTPROC			.cfi_startproc
# define CFI_ENDPROC			.cfi_endproc
# define CFI_OFFSET(reg, off)		.cfi_offset reg, off
# define CFI_DEF_CFA_REGISTER(reg)	.cfi_def_cfa_register reg
# define CFI_RESTORE(reg)		.cfi_restore reg
#else
# define CFI_STARTPROC
# define CFI_ENDPROC
# define CFI_OFFSET(reg, off)
# define CFI_DEF_CFA_REGISTER(reg)
# define CFI_RESTORE(reg)
#endif
#endif

#if defined __linux__ && !defined __powerpc64__
	.section .note.GNU-stack
	.previous
#endif
