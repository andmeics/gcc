/* Definitions for ELF systems with .init_array/.fini_array section
   support.
   Copyright (C) 2011-2014 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifdef HAVE_INITFINI_ARRAY_SUPPORT

#define USE_INITFINI_ARRAY

#undef INIT_SECTION_ASM_OP
#undef FINI_SECTION_ASM_OP

#undef INIT_ARRAY_SECTION_ASM_OP
#define INIT_ARRAY_SECTION_ASM_OP

#undef FINI_ARRAY_SECTION_ASM_OP
#define FINI_ARRAY_SECTION_ASM_OP

/* Use .init_array/.fini_array section for constructors and destructors. */
#undef TARGET_ASM_CONSTRUCTOR
#define TARGET_ASM_CONSTRUCTOR default_elf_init_array_asm_out_constructor
#undef TARGET_ASM_DESTRUCTOR
#define TARGET_ASM_DESTRUCTOR default_elf_fini_array_asm_out_destructor

#endif
