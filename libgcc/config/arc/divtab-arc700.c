/* Copyright (C) 2004-2020 Free Software Foundation, Inc.
   Contributor: Joern Rennecke <joern.rennecke@embecosm.com>
		on behalf of Synopsys Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* Calculate division table for ARC700 integer division
   Contributed by Joern Rennecke
   joern.rennecke@arc.com  */

#include <stdio.h>
#include <math.h>

int
main ()
{
  int i, j;
  unsigned x;
  double q, r, err, max_err = -1;

  puts("/* This table has been generated by divtab-arc700.c.  */");
  puts("\
/* 1/512 .. 1/256, normalized.  There is a leading 1 in bit 31.\n\
   For powers of two, we list unnormalized numbers instead.  The values\n\
   for powers of 2 are loaded, but not used.  The value for 1 is actually\n\
   the first instruction after .Lmuldiv.  */\n\
	.balign 4");
  puts (".Ldivtab:\n");
  for (i = 256; i >= 2; --i)
    {
      j = i < 0 ? -i : i;
      if (j & (j-1))
	while (j < 128)
	  j += j;
      else
	/* Power of two. */
	j *= 128;
      q = 4.*(1<<30)*128/j;
      r = ceil (q);
      printf ("\t.long\t0x%X\n", (unsigned) r);
      err = r - q;
      if (err > max_err)
	max_err = err;
    }
#if 0
  printf ("\t/* maximum error: %f */\n", max_err);
#endif
  exit (0);
}
