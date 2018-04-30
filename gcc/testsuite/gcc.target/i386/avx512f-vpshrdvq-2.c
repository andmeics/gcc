/* { dg-do run } */
/* { dg-options "-O2 -mavx512f -mavx512bw -mavx512vbmi2" } */
/* { dg-require-effective-target avx512f } */
/* { dg-require-effective-target avx512vbmi2 } */

#define AVX512F

#define AVX512VBMI2
#include "avx512f-helper.h"

#define SIZE (AVX512F_LEN / 64)

#include "avx512f-mask-type.h"

static void
CALC (long long *r, long long *dst, long long *s1, long long *s2)
{
  int i;
  for (i = 0; i < SIZE; i++)
    {
      r[i] = (dst[i] >> (s2[i] & 63)) | (s1[i] << (64 - (s2[i] & 63)));
    }
}

void
TEST (void)
{
  int i;
  UNION_TYPE (AVX512F_LEN, i_q) res1, res2, res3, src1, src2;
  MASK_TYPE mask = MASK_VALUE;
  long long res_ref[SIZE];

  for (i = 0; i < SIZE; i++)
    {
      src1.a[i] = 1 + i;
      src2.a[i] = 2 + 2*i;
    }

  for (i = 0; i < SIZE; i++)
    {
      res1.a[i] = DEFAULT_VALUE;
      res2.a[i] = DEFAULT_VALUE;
      res3.a[i] = DEFAULT_VALUE;
    }

  CALC (res_ref, res1.a, src1.a, src2.a);

  res1.x = INTRINSIC (_shrdv_epi64) (res1.x, src1.x, src2.x);
  res2.x = INTRINSIC (_mask_shrdv_epi64) (res2.x, mask, src1.x, src2.x);
  res3.x = INTRINSIC (_maskz_shrdv_epi64) (mask, res3.x, src1.x, src2.x);

  if (UNION_CHECK (AVX512F_LEN, i_q) (res1, res_ref))
    abort ();

  MASK_MERGE (i_q) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_q) (res2, res_ref))
    abort ();

  MASK_ZERO (i_q) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_q) (res3, res_ref))
    abort ();
}
