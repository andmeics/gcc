/* { dg-do run } */
/* { dg-options "-O2 -mavx512f" } */
/* { dg-require-effective-target avx512f } */

#define AVX512F

#include "avx512f-helper.h"

#define SIZE (AVX512F_LEN / 32)
#include "avx512f-mask-type.h"

void static
CALC (float *s1, float *s2, float *r)
{
  int i;

  for (i = 0; i < SIZE / 4; i++)
    {
      r[4 * i] = s1[4 * i + 2];
      r[4 * i + 1] = s2[4 * i + 2];
      r[4 * i + 2] = s1[4 * i + 3];
      r[4 * i + 3] = s2[4 * i + 3];
    }
}

void static
TEST (void)
{
  UNION_TYPE (AVX512F_LEN, ) s1, s2, res1, res2, res3;
  MASK_TYPE mask = MASK_VALUE;
  float res_ref[SIZE];
  int i;

  for (i = 0; i < SIZE; i++)
    {
      s1.a[i] = i * 123.2 + 32.6;
      s2.a[i] = i + 2.5;
      res2.a[i] = DEFAULT_VALUE;
    }

  res1.x = INTRINSIC (_unpackhi_ps) (s1.x, s2.x);
  res2.x = INTRINSIC (_mask_unpackhi_ps) (res2.x, mask, s1.x, s2.x);
  res3.x = INTRINSIC (_maskz_unpackhi_ps) (mask, s1.x, s2.x);

  CALC (s1.a, s2.a, res_ref);

  if (UNION_CHECK (AVX512F_LEN, ) (res1, res_ref))
    abort ();

  MASK_MERGE () (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, ) (res2, res_ref))
    abort ();

  MASK_ZERO () (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, ) (res3, res_ref))
    abort ();
}
