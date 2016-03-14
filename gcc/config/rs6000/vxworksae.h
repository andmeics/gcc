/* Definitions of target machine for GNU compiler.  PowerPC VxworksAE version.
   Copyright (C) 2005-2016 Free Software Foundation, Inc.
   Contributed by CodeSourcery, LLC.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* VxWorksAE for E500V2 expects a specific CPU value to designate 8548.  */
#undef VXCPU_FOR_8548
#define VXCPU_FOR_8548 "PPCE500V2"

/* This platform supports the probing method of stack checking and
   requires 4K of space for executing a possible last chance handler.  */
#undef STACK_CHECK_PROTECT
#define STACK_CHECK_PROTECT 4096
