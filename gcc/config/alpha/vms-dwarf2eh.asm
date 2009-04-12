/* VMS dwarf2 exception handling section sequentializer.
   Copyright (C) 2002, 2009 Free Software Foundation, Inc.
   Contributed by Douglas B. Rupp (rupp@gnat.com).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* Linking with this file forces the Dwarf2 EH section to be
   individually loaded by the VMS linker an the unwinder to read it.  */

.section	.eh_frame,NOWRT
		.align 0
		.global __EH_FRAME_BEGIN__
__EH_FRAME_BEGIN__:
