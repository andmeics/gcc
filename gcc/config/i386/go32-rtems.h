/* Configuration for an i386 running RTEMS on top of MS-DOS with
   djgpp/go32 v1.x.

   Copyright (C) 1996 Free Software Foundation, Inc.
   Contributed by Joel Sherrill (joel@OARcorp.com).
 
This file is part of GNU CC.
 
GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.
 
GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "i386/go32.h"

/* Specify predefined symbols in preprocessor.  */

#ifdef CPP_PREDEFINES
#undef CPP_PREDEFINES
#endif
#define CPP_PREDEFINES "-Dunix -Di386 -DGO32 -DMSDOS -Drtems -D__rtems__ \
  -Asystem(unix) -Asystem(msdos) -Acpu(i386) -Amachine(i386) -Asystem(rtems)"

/* end of i386/go32-rtems.h */

