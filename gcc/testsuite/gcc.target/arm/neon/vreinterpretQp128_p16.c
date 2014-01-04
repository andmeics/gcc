/* Test the `vreinterpretQp128_p16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_crypto_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_crypto } */

#include "arm_neon.h"

void test_vreinterpretQp128_p16 (void)
{
  poly128_t out_poly128_t;
  poly16x8_t arg0_poly16x8_t;

  out_poly128_t = vreinterpretq_p128_p16 (arg0_poly16x8_t);
}

/* { dg-final { cleanup-saved-temps } } */
