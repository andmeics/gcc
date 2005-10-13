/* Temporary library support for decimal floating point.
   Copyright (C) 2005 Free Software Foundation, Inc.

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

/* FIXME: this file should not be merged to mainline.  */

#include "decContext.h"
#include "decimal128.h"
#include "decimal64.h"
#include "decimal32.h"

extern int isinfd32 (_Decimal32);
extern int isinfd64 (_Decimal64);
extern int isinfd128 (_Decimal128);
extern void __dfp_enable_traps (void);
extern void __dfp_raise (int exception __attribute__ ((unused)));

int
isinfd32 (_Decimal32 arg)
{
  decNumber dn;
  decimal32ToNumber ((decimal32 *) &arg, &dn);
  return (decNumberIsInfinite (&dn));
}

int
isinfd64 (_Decimal64 arg)
{
  decNumber dn;
  decimal64ToNumber ((decimal64 *) &arg, &dn);
  return (decNumberIsInfinite (&dn));
}

int
isinfd128 (_Decimal128 arg)
{
  decNumber dn;
  decimal128ToNumber ((decimal128 *) &arg, &dn);
  return (decNumberIsInfinite (&dn));
}

int __dfp_traps;

void
__dfp_enable_traps (void)
{
  __dfp_traps = 1;
}

void
__dfp_raise (int exception __attribute__ ((unused)))
{
  raise (SIGFPE);
}
