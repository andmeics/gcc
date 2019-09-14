/* { dg-require-effective-target vect_float } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 40
#define M 128
float in[N+M];
float coeff[M];
float out[N];
float fir_out[N];

/* Should be vectorized. Fixed misaligment in the inner-loop.  */
__attribute__ ((noinline))
void foo (){
 int i,j,k;
 float diff;

 for (i = 0; i < N; i++) {
  out[i] = 0;
 }

 for (k = 0; k < 4; k++) {
  for (i = 0; i < N; i++) {
    diff = 0;
    for (j = k; j < M; j+=4) {
      diff += in[j+i]*coeff[j];
    }
    out[i] += diff;
  }
 }

}

/* Vectorized. Changing misalignment in the inner-loop.  */
__attribute__ ((noinline))
void fir (){
  int i,j,k;
  float diff;

  for (i = 0; i < N; i++) {
    diff = 0;
    for (j = 0; j < M; j++) {
      diff += in[j+i]*coeff[j];
    }
    fir_out[i] = diff;
  }
}


int main (void)
{
  check_vect ();
  int i, j;
  float diff;

  for (i = 0; i < M; i++)
    coeff[i] = i;
  for (i = 0; i < N+M; i++)
    in[i] = i;

  foo ();
  fir ();

  for (i = 0; i < N; i++) {
    if (out[i] != fir_out[i])
      abort ();
  }

  return 0;
}

/* { dg-final { scan-tree-dump-times "OUTER LOOP VECTORIZED" 2 "vect" { xfail { vect_no_align && { ! vect_hw_misalign } } } } } */
