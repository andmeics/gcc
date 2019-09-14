/* Verify that overloaded built-ins for vec_abs with int
   inputs produce the right results when -mcpu=power8 is specified.  */

/* { dg-do compile } */
/* { dg-require-effective-target powerpc_altivec_ok } */
/* { dg-options "-maltivec -O2 -mdejagnu-cpu=power8 -fwrapv" } */

#include <altivec.h>

vector signed int
test1 (vector signed int x)
{
  return vec_abs (x);
}

/* { dg-final { scan-assembler-times "vspltisw|vxor" 1 } } */
/* { dg-final { scan-assembler-times "vsubuwm" 1 } } */
/* { dg-final { scan-assembler-times "vmaxsw" 1 } } */
