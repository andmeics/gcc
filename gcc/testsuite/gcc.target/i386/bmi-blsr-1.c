/* { dg-do run { target { bmi && { ! ia32 } } } } */
/* { dg-options "-O2 -mbmi -fno-inline" } */

#include <x86intrin.h>

#include "bmi-check.h"

long long calc_blsr_u64 (long long src1, long long src2)
{
  return (src1-1) & (src2);
}

static void
bmi_test()
{
  unsigned i;
  long long src = 0xfacec0ffeefacec0;
  long long res, res_ref;

  for (i=0; i<5; ++i) {
    src = i + src << i;

    res_ref = calc_blsr_u64 (src, src);
    res = __blsr_u64 (src);

    if (res != res_ref)
      abort();
  }
}
