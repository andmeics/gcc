/* Test the `vmovQ_nf32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vmovQ_nf32 (void)
{
  float32x4_t out_float32x4_t;
  float32_t arg0_float32_t;

  out_float32x4_t = vmovq_n_f32 (arg0_float32_t);
}

/* { dg-final { scan-assembler "vdup\.32\[ 	\]+\[qQ\]\[0-9\]+, (\[rR\]\[0-9\]+|\[dD\]\[0-9\]+\\\[\[0-9\]+\\\])!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
