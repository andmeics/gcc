/* Test the `vreinterprets32_s64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vreinterprets32_s64 (void)
{
  int32x2_t out_int32x2_t;
  int64x1_t arg0_int64x1_t;

  out_int32x2_t = vreinterpret_s32_s64 (arg0_int64x1_t);
}

/* { dg-final { cleanup-saved-temps } } */
