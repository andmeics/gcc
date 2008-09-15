/* { dg-do run } */
/* { dg-options "-O2 -msse2" } */

#ifndef CHECK_H
#define CHECK_H "sse2-check.h"
#endif

#ifndef TEST
#define TEST sse2_test
#endif

#include CHECK_H

#include <emmintrin.h>

static __m128i
__attribute__((noinline, unused))
test (__m128i s1, __m128i count)
{
  return _mm_sra_epi32 (s1, count); 
}

static void
TEST (void)
{
  union128i_d u, s;
  union128i_q c;
  int e[4] = {0};
  int i;
 
  s.x = _mm_set_epi32 (1, -2, 3, 4);
  c.x = _mm_set_epi64x (16, 29);

  u.x = test (s.x, c.x);

  if (c.a[0] < 32)
    for (i = 0; i < 4; i++)
      e[i] = s.a[i] >> c.a[0]; 

  if (check_union128i_d (u, e))
    abort (); 
}
