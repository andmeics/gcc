/* { dg-do run } */
/* { dg-options "-O1 -fwrapv" } */

#include <stdint.h>
#include <limits.h>
#include <stdio.h>

#ifndef N
#define N 65
#endif

#ifndef TYPE
#define TYPE int32_t
#endif

#ifndef DEBUG
#define DEBUG 1
#endif

#define BASE ((TYPE) -1 < 0 ? -126 : 4)

__attribute__ ((noinline, noipa))
void fun1(TYPE *x, int n)
{
    for (int i = 0; i < n; i++)
      x[i] = (-x[i]) >> 31;
}

__attribute__ ((noinline, noipa, optimize("O0")))
void fun2(TYPE *x, int n)
{
    for (int i = 0; i < n; i++)
      x[i] = (-x[i]) >> 31;
}

int main ()
{
  TYPE a[N];
  TYPE b[N];

  a[0] = INT_MIN;
  b[0] = INT_MIN;

  for (int i = 1; i < N; ++i)
    {
      a[i] = BASE + i * 13;
      b[i] = BASE + i * 13;
      if (DEBUG)
        printf ("%d: 0x%x\n", i, a[i]);
    }

  fun1 (a, N);
  fun2 (b, N);

  for (int i = 0; i < N; ++i)
    {
      if (DEBUG)
        printf ("%d = 0x%x == 0x%x\n", i, a[i], b[i]);

      if (a[i] != b[i])
        __builtin_abort ();
    }
  return 0;
}

