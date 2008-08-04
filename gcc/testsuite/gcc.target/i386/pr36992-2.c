/* { dg-do compile }
/* { dg-options "-O0 -msse2" } */

#include <emmintrin.h>

__m128i
test (__m128i b)
{
  return _mm_move_epi64 (b);
}

/* { dg-final { scan-assembler-not "%mm" } } */
