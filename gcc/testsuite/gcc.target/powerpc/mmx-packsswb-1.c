/* { dg-do run } */
/* { dg-options "-O3 -mpower8-vector" } */
/* { dg-require-effective-target p8vector_hw } */

#define NO_WARN_X86_INTRINSICS 1
#ifndef CHECK_H
#define CHECK_H "mmx-check.h"
#endif

#ifndef TEST
#define TEST mmx_test
#endif

#include CHECK_H

#include <mmintrin.h>
#include <xmmintrin.h>

static __m64
__attribute__((noinline, unused))
test (__m64 s1, __m64 s2)
{
  return _mm_packs_pi16 (s1, s2);
}

static signed char
saturate (signed short val)
{
  if (val > 127)
    return 127;
  else if (val < -128)
    return -128;
  else
    return val;
}

static void
TEST (void)
{
  __m64_union s1, s2;
  __m64_union u;
  __m64_union e;
  int i;

  s1.as_m64 = _mm_set_pi16 (2134, -128, 1234, 6354);
  s2.as_m64 = _mm_set_pi16 (41124, 234, 2344, 2354);
  u.as_m64 = test (s1.as_m64, s2.as_m64);

#ifdef __LITTLE_ENDIAN__
  e.as_m64 = _mm_set_pi8 (saturate (_mm_extract_pi16 (s2.as_m64, 3)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 2)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 1)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 0)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 3)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 2)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 1)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 0)));
#else
  e.as_m64 = _mm_set_pi8 (saturate (_mm_extract_pi16 (s1.as_m64, 3)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 2)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 1)),
                          saturate (_mm_extract_pi16 (s1.as_m64, 0)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 3)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 2)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 1)),
                          saturate (_mm_extract_pi16 (s2.as_m64, 0)));
#endif

  if (u.as_m64 != e.as_m64)
    abort ();
}
