/* Definitions for AMD x86-64 running kFreeBSD-based GNU systems with ELF format
   Copyright (C) 2011-2018 Free Software Foundation, Inc.
   Contributed by Robert Millan.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define GNU_USER_LINK_EMULATION32 "elf_i386_fbsd"
#define GNU_USER_LINK_EMULATION64 "elf_x86_64_fbsd"
#define GNU_USER_LINK_EMULATIONX32 "elf32_x86_64_fbsd"

#define GLIBC_DYNAMIC_LINKER32 "/lib/ld.so.1"
#define GLIBC_DYNAMIC_LINKER64 "/lib/ld-kfreebsd-x86-64.so.1"
#define GLIBC_DYNAMIC_LINKERX32 "/lib/ld-kfreebsd-x32.so.1"
