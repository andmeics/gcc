/* Test the `vsra_ns64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vsra_ns64 (void)
{
  int64x1_t out_int64x1_t;
  int64x1_t arg0_int64x1_t;
  int64x1_t arg1_int64x1_t;

  out_int64x1_t = vsra_n_s64 (arg0_int64x1_t, arg1_int64x1_t, 1);
}

/* { dg-final { scan-assembler "vsra\.s64\[ 	\]+\[dD\]\[0-9\]+, \[dD\]\[0-9\]+, #\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
