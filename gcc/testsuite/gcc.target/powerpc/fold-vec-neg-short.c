/* Verify that overloaded built-ins for vec_neg with short
   inputs produce the right code.  */

/* { dg-do compile } */
/* { dg-require-effective-target powerpc_p8vector_ok } */
/* { dg-options "-mvsx -O2 -mcpu=power8" } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */


#include <altivec.h>

vector signed short
test3 (vector signed short x)
{
  return vec_neg (x);
}

/* { dg-final { scan-assembler-times "xxspltib|vspltisw|vxor" 1 } } */
/* { dg-final { scan-assembler-times "vsubuhm" 1 } } */
/* { dg-final { scan-assembler-times "vmaxsh" 0 } } */
