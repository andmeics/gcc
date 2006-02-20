/* { dg-do compile { target powerpc*-*-* } } */
/* { dg-xfail-if "" { "powerpc-*-eabispe*" "powerpc-ibm-aix*" } { "*" } { "" } } */
/* { dg-options "-maltivec -ansi" } */

/* PR 16155
 * Compilation of a simple altivec test program fails if the -ansi flag is
 * given to gcc, when compiling with -maltivec.
 */

#include <altivec.h>

void foo(void)
{
  vector unsigned short a, b;
  a = vec_splat(b, 0);
}

/* { dg-bogus "parse error before \"typeof\"" "-maltivec -mansi" { target powerpc*-*-* } 0 } */
