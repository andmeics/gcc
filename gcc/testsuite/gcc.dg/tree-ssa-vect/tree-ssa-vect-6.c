/* { dg-do run { target powerpc*-*-* } } */
/* { dg-do compile { target i?86-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -maltivec" { target powerpc*-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -msse2" { target i?86-*-* } } */

#include <stdarg.h>
#include <signal.h>

#define N 16

float results1[N] = {192.00,240.00,288.00,336.00,384.00,432.00,480.00,528.00,0.00};
float results2[N] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,54.00,120.00,198.00,288.00,390.00,504.00,630.00};

int main1 ()
{
  int i;
  float a[N] = {0};
  float e[N] = {0};
  float b[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  float c[N] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  for (i = 0; i < N/2; i++)
    { 
      a[i] = b[i+N/2] * c[i+N/2] - b[i] * c[i];
      e[i+N/2] = b[i] * c[i+N/2] + b[i+N/2] * c[i];
    }

  /* check results:  */
  for (i=0; i<N; i++)
    {
      if (a[i] != results1[i] || e[i] != results2[i])
	abort(); 
    }


  for (i = 1; i <=N-4; i++)
    {
      a[i+3] = b[i-1];
    }

  /* check results:  */
  for (i = 1; i <=N-4; i++)
    {
      if (a[i+3] != b[i-1])
        abort ();
    }

  return 0;
}

void
sig_ill_handler (int sig)
{
    exit(0);
}

int main (void)
{
  /* Exit on systems without altivec.  */
  signal (SIGILL, sig_ill_handler);
  /* Altivec instruction, 'vor %v0,%v0,%v0'.  */
  asm volatile (".long 0x10000484");
  signal (SIGILL, SIG_DFL);

  return main1 ();
}


/* { dg-final { scan-tree-dump-times "vectorized 2 loops" 1 "vect" } } */


