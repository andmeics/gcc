/*

   Copyright (C) 2007-2008 Free Software Foundation, Inc.
   Contributed by STMicroelectronics

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#define __BEGIN_EXTERN_C
#define __END_EXTERN_C
#define LIBSTD_HPROTO(rettype, fname, ...) \
       rettype __host__##fname(__VA_ARGS__)

#define PINVOKE_RENAME_HOST_ATTR(rettype, fname, ...) \
       rettype fname(__VA_ARGS__) __attribute__((pinvoke("MSCorelibWrapper_support.so","__host__"#fname)))

#define LIBSTD_HPROTO_IMPL(rettype, fname, ...) \
       rettype __host__##fname(__VA_ARGS__)
