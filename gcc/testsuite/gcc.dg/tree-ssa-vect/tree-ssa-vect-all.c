/* { dg-do run { target powerpc*-*-* i?86-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -maltivec" { target powerpc*-*-* } } */
/* { dg-options "-O2 -ftree-vectorize -fdump-tree-vect-stats -msse" { target i?86-*-* } } */

#include <stdarg.h>
#include <signal.h>

#define N 16

int iadd_results[N] = {0,6,12,18,24,30,36,42,48,54,60,66,72,78,84,90};
float fadd_results[N] = {0.0,6.0,12.0,18.0,24.0,30.0,36.0,42.0,48.0,54.0,60.0,66.0,72.0,78.0,84.0,90.0};
float fmul_results[N] = {0.0,3.0,12.0,27.0,48.0,75.0,108.0,147.0,192.0,243.0,300.0,363.0,432.0,507.0,588.0,675.0};
float fresults1[N] = {192.00,240.00,288.00,336.00,384.00,432.00,480.00,528.00,48.00,54.00,60.00,66.00,72.00,78.00,84.00,90.00};
float fresults2[N] = {0.00,6.00,12.00,18.00,24.00,30.00,36.00,42.00,0.00,54.00,120.00,198.00,288.00,390.00,504.00,630.00};

/****************************************************/
void icheck_results (int *a, int *results)
{
  int i;
  for (i = 0; i < N; i++)
    {
      if (a[i] != results[i])
	abort ();
    }
}

void fcheck_results (float *a, float *results)
{
  int i;
  for (i = 0; i < N; i++)
    {
      if (a[i] != results[i])
	abort ();
    }
}   

void 
fbar_mul (float *a)
{
  fcheck_results (a, fmul_results);
} 

void 
fbar_add (float *a)
{
  fcheck_results (a, fadd_results);
} 

void 
ibar_add (int *a)
{
  icheck_results (a, iadd_results);
} 

void 
fbar1 (float *a)
{
  fcheck_results (a, fresults1);
} 

void 
fbar2 (float *a)
{
  fcheck_results (a, fresults2);
} 


/* All of the loops below are currently vectorizable.  */

int
main1 ()
{
  int i,j;
  float a[N];
  float e[N];
  float b[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  float c[N] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float d[N] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
  int ic[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  int ib[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  int ia[N];
  char cb[N] = {0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};
  char ca[N];


  /* Test 1: copy chars.  */
  for (i = 0; i < N; i++)
    {
      ca[i] = cb[i];
    }
  /* check results:  */
  for (i = 0; i < N; i++)
    {
      if (ca[i] != cb[i])
	abort ();
    }


  /* Test 2: fp mult.  */
  for (i = 0; i < N; i++)
    {
      a[i] = b[i] * c[i];
    }
  fbar_mul (a);


  /* Test 3: mixed types (int, fp), same nunits in vector.  */
  for (i = 0; i < N; i++)
    {
      a[i] = b[i] + c[i] + d[i];
      e[i] = b[i] + c[i] + d[i];
      ia[i] = ib[i] + ic[i];
    }
  ibar_add (ia);
  fbar_add (a);
  fbar_add (e);


  /* Test 4: access with offset.  */
  for (i = 0; i < N/2; i++)
    {
      a[i] = b[i+N/2] * c[i+N/2] - b[i] * c[i];
      e[i+N/2] = b[i] * c[i+N/2] + b[i+N/2] * c[i];
    }
  fbar1 (a);
  fbar2 (e);


  /* Test 5: access with offset */
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


  /* Test 6 - loop induction with stride != 1.  */
  i = 0;
  j = 0;
  while (i < 5*N)
    {
      a[j] = c[j];
      i += 5;
      j++;
    }
  /* check results:  */
  for (i = 0; i <N; i++)
    {
      if (a[i] != c[i])
        abort ();
    }


  /* Test 7 - reverse access.  */
  for (i = N; i > 0; i--)
    {
      a[N-i] = d[N-i];
    }
  /* check results:  */
  for (i = 0; i <N; i++)
    {
      if (a[i] != d[i])
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


/* { dg-final { scan-tree-dump-times "vectorized 7 loops" 1 "vect"} } */
