/* { dg-require-effective-target vect_float } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 16

int
main1 (void)
{
  int i;
  float a[N];
  float b[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  float c[N] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float d[N] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};

  /* Strided access pattern.  */
  for (i = 0; i < N/2; i++)
    {
      a[i] = b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i];
      d[i] = b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i];
    }

  /* Check results.  */
  for (i = 0; i < N/2; i++)
    {
      if (a[i] != b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i]
	  || d[i] != b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i])
	abort();
    }

  return 0;
}

int main (void)
{
  check_vect ();
  return main1 ();
}

/* Needs interleaving support.  */
/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" { target powerpc*-*-* } } } */
/* { dg-final { scan-tree-dump-times "vectorized 0 loops" 1 "vect" { xfail powerpc*-*-* } } } */
/* { dg-final { cleanup-tree-dump "vect" } } */
