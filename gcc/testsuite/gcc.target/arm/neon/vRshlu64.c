/* Test the `vRshlu64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vRshlu64 (void)
{
  uint64x1_t out_uint64x1_t;
  uint64x1_t arg0_uint64x1_t;
  int64x1_t arg1_int64x1_t;

  out_uint64x1_t = vrshl_u64 (arg0_uint64x1_t, arg1_int64x1_t);
}

/* { dg-final { scan-assembler "vrshl\.u64\[ 	\]+\[dD\]\[0-9\]+, \[dD\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
