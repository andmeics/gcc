/* Definitions for rtems targeting a AVR using ELF.
   Copyright (C) 2004, 2007 Free Software Foundation, Inc.
   Contributed by Ralf Corsepius (ralf.corsepius@rtems.org).

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

/* Specify predefined symbols in preprocessor.  */

#define TARGET_OS_CPP_BUILTINS()	\
do {					\
  builtin_define ("__rtems__");		\
  builtin_define ("__USE_INIT_FINI__");	\
  builtin_assert ("system=rtems");	\
} while (0)
