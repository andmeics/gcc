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

#define __LIBSTD_CRT_BUILD

#include <string.h>

LIBSTD_LPROTO_IMPL(int, memcmp, const void *s1, const void *s2, size_t n)
{
    if (n) {
        const unsigned char *ps1_ = (const unsigned char *) s1;
        const unsigned char *ps2_ = (const unsigned char *) s2;

        while (--n && *ps1_==*ps2_) {
            ++ps1_;
            ++ps2_;
        }
        return (*ps1_ - *ps2_);
    }

    return 0;
}
