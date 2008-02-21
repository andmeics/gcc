/* Test the `vdup_lanes64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vdup_lanes64 (void)
{
  int64x1_t out_int64x1_t;
  int64x1_t arg0_int64x1_t;

  out_int64x1_t = vdup_lane_s64 (arg0_int64x1_t, 0);
}

/* { dg-final { cleanup-saved-temps } } */
