/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vptestmq\[ \\t\]+\[^\n\]*%zmm\[0-7\]\[^\n^k\]*k\[1-7\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vptestmq\[ \\t\]+\[^\n\]*%zmm\[0-7\]\[^\n^k\]*k\[1-7\]\{" 1 } } */

#include <immintrin.h>

volatile __m512i x;
volatile __mmask8 m8;

void extern
avx512f_test (void)
{
  m8 = _mm512_test_epi64_mask (x, x);
  m8 = _mm512_mask_test_epi64_mask (3, x, x);
}
