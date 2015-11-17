/* { dg-do compile { target { powerpc*-*-* && ilp32 } } } */
/* { dg-require-effective-target powerpc_p9modulo_ok } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power9" } } */
/* { dg-options "-mcpu=power9 -O2" } */

int i_trailing_zero (int a) { return __builtin_ctz (a); }

/* { dg-final { scan-assembler     "cnttzw " } } */
/* { dg-final { scan-assembler-not "cntlzw " } } */
