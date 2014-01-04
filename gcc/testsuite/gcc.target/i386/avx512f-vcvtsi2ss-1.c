/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vcvtsi2ss\[ \\t\]+\[^\n\]*\{rn-sae\}\[^\n\]*%xmm\[0-9\]" 1 } } */

#include <immintrin.h>

volatile __m128 x;
volatile int n;

void extern
avx512f_test (void)
{
  x = _mm_cvt_roundi32_ss (x, n, _MM_FROUND_TO_NEAREST_INT);
}
