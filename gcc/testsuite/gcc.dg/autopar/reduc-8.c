/* { dg-do compile } */
/* { dg-options "-O2 -ftree-parallelize-loops=4 -fdump-tree-parloops2-details -fdump-tree-optimized" } */

#include <stdlib.h>

#define N 3200

extern void abort (void);
typedef signed char T;

__attribute__ ((noinline)) void
testmax (const T *c, T init, T result)
{
  T lc[N], accum = init;
  int i;

  __builtin_memcpy (lc, c, sizeof(lc));

  for (i = 0; i < N; i++) {
    accum = accum < lc[i] ? lc[i] : accum;
  }

  if (accum != result)
    abort ();
}

__attribute__ ((noinline)) void
testmin (const T *c, T init, T result)
{
  T lc[N], accum = init;
  int i;

  __builtin_memcpy (lc, c, sizeof(lc));

  for (i = 0; i < N; i++) {
    accum = accum > lc[i] ? lc[i] : accum;
  }

  if (accum != result)
    abort ();
}

int __attribute__((optimize ("-ftree-parallelize-loops=0")))
main (void)
{
  static signed char A[N] = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f
  };

  static signed char B[N] = {
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f
  };

  static signed char C[N] = {
    0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8,
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
  };

  int i;

  for (i=32; i<N; i++)
    {
      A[i]= 0x01;
      B[i]= 0x70;
      C[i]= 0xff;
    }

  testmin (A, 0, 0);
  testmin (B, 0, 0x80);
  testmin (C, 0, 0x80);

  testmax (A, 0, 0x7f);
  testmax (B, 0, 0x7f);
  testmax (C, 0, 0x77);

  return 0;
}


/* { dg-final { scan-tree-dump-times "Detected reduction" 2 "parloops2" } } */
/* { dg-final { scan-tree-dump-times "SUCCESS: may be parallelized" 2 "parloops2" } } */
