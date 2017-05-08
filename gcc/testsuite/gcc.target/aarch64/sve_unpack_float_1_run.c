/* { dg-do run { target aarch64_sve_hw } } */
/* { dg-options "-O2 -ftree-vectorize -fno-inline -march=armv8-a+sve" } */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "sve_unpack_float_1.c"

#define ARRAY_SIZE 199

#define VAL1 ((float) ((i * 645.56665) - (645.56665)))

int __attribute__ ((optimize (1)))
main (void)
{
  double array_dest[ARRAY_SIZE];
  float array_source[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++)
    array_source[i] = VAL1;

  unpack_float_plus_7point9 (array_dest, array_source, ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++)
    if (array_dest[i] != (double) (VAL1 + 7.9))
      {
	fprintf (stderr,"%d: %f != %f\n", i, array_dest[i],
		 (double) (VAL1 + 7.9));
	exit (1);
      }

  return 0;
}
