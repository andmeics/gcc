/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "kunpckbw\[ \\t\]+\[^\{\n\]*%k\[0-7\](?:\n|\[ \\t\]+#)" 1 } } */

#include <immintrin.h>

void
avx512f_test () {
  __mmask8 k1, k2;
  __mmask16 k3;
  volatile __m512 x = _mm512_setzero_ps();

  __asm__( "kmovb %1, %0" : "=k" (k1) : "r" (1) );
  __asm__( "kmovb %1, %0" : "=k" (k2) : "r" (2) );

  k3 = _kunpackb_mask16 (k1, k2);
  x = _mm512_mask_add_ps (x, k3, x, x);
}
