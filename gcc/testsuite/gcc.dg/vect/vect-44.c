/* { dg-do run { target powerpc*-*-* } } */
/* { dg-do run { target i?86-*-* x86_64-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -maltivec" { target powerpc*-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -msse2" { target i?86-*-* x86_64-*-* } } */
  
#include <stdarg.h>
#include "tree-vect.h"

#define N 256

typedef float afloat __attribute__ ((__aligned__(16)));

void bar (float *pa, float *pb, float *pc) 
{
  int i;

  /* check results:  */
  for (i = 0; i < N; i++)
    {
      if (pa[i] != (pb[i] * pc[i]))
	abort ();
    }

  return;
}


int
main1 (float * __restrict__ pa, float * __restrict__ pb, float * __restrict__ pc)
{
  int i;

  for (i = 0; i < N; i++)
    {
      pa[i] = pb[i] * pc[i];
    }

  bar (pa,pb,pc);

  return 0;
}

int main (void)
{
  int i;
  afloat a[N+4];
  afloat b[N+4] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69};
  afloat c[N+4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

  check_vect ();

  main1 (a,b,c);
  main1 (&a[1],b,c);
  main1 (a,&b[1],c);
  main1 (&a[1],&b[1],&c[1]);

  return 0;
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" } } */
