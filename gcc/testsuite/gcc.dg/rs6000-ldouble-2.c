/* APPLE LOCAL file put in 4.1 */
/* { dg-do run { target powerpc*-*-darwin* powerpc*-*-aix* powerpc64-*-linux rs6000-*-* } } */
/* { dg-options "-mlong-double-128" } */

/* Check that LDBL_EPSILON is right for 'long double'.  */

#include <float.h>

extern void abort (void);

int main(void)
{
  volatile long double ee = 1.0;
  long double eps = ee;
  while (ee + 1.0 != 1.0)
    {
      eps = ee;
      ee = eps / 2;
    }
  if (eps != LDBL_EPSILON)
    abort ();
  return 0;
}
