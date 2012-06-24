/* Test the `vgetQ_lanes64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vgetQ_lanes64 (void)
{
  register int64_t out_int64_t asm ("r0");
  int64x2_t arg0_int64x2_t;

  out_int64_t = vgetq_lane_s64 (arg0_int64x2_t, 0);
}

/* { dg-final { scan-assembler "((vmov)|(fmrrd))\[ 	\]+\[rR\]\[0-9\]+, \[rR\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
