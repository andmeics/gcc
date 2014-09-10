/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vprorq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\[^\{\]" 3 } } */
/* { dg-final { scan-assembler-times "vprorq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vprorq\[ \\t\]+\[^\n\]*%zmm\[0-9\]\{%k\[1-7\]\}\{z\}" 1 } } */

#include <immintrin.h>

volatile __m512i x;
volatile __mmask8 m;

void extern
avx512f_test (void)
{
  x = _mm512_ror_epi64 (x, 12);
  x = _mm512_mask_ror_epi64 (x, m, x, 12);
  x = _mm512_maskz_ror_epi64 (m, x, 12);
}
