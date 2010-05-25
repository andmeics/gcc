/* Test the `vld1Q_lanes64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vld1Q_lanes64 (void)
{
  int64x2_t out_int64x2_t;
  int64x2_t arg1_int64x2_t;

  out_int64x2_t = vld1q_lane_s64 (0, arg1_int64x2_t, 1);
}

/* { dg-final { scan-assembler "vld1\.64\[ 	\]+((\\\{\[dD\]\[0-9\]+\\\})|(\[dD\]\[0-9\]+)), \\\[\[rR\]\[0-9\]+\\\]!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
