/* { dg-require-effective-target vect_float } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 256

typedef float afloat __attribute__ ((__aligned__(16)));

void bar (afloat *pa, afloat *pb, afloat *pc)
{
  int i;

  /* check results:  */
  for (i = 0; i < N; i++)
    {
      if (pa[i] != (pb[i] * pc[i]))
	abort();
    }

  return;
}


int
main1 (int n , afloat * __restrict__ pa, afloat * __restrict__ pb, afloat * __restrict__ pc)
{
  int i;

  for (i = 0; i < n; i++)
    {
      pa[i] = pb[i] * pc[i];
    }

  return 0;
}

int main (void)
{
  int i;
  int n=N;
  afloat a[N];
  afloat b[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57};
  afloat c[N] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

  check_vect ();

  main1 (n,a,b,c);
  bar (a,b,c);
  return 0;
}

/* This fails to vectorize for 64-bit powerpc but there's no way to
   specify that in an xfail list.  */
/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" } } */
