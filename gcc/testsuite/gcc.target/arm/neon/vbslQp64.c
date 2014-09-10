/* Test the `vbslQp64' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_crypto_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_crypto } */

#include "arm_neon.h"

void test_vbslQp64 (void)
{
  poly64x2_t out_poly64x2_t;
  uint64x2_t arg0_uint64x2_t;
  poly64x2_t arg1_poly64x2_t;
  poly64x2_t arg2_poly64x2_t;

  out_poly64x2_t = vbslq_p64 (arg0_uint64x2_t, arg1_poly64x2_t, arg2_poly64x2_t);
}

/* { dg-final { scan-assembler "((vbsl)|(vbit)|(vbif))\[ 	\]+\[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
