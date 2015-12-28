/* { dg-do run } */
/* { dg-options "-O1 -lm" } */

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

void conversion()
{
  float sNaN = __builtin_nansf ("");
  double x = (double) sNaN;
  if (issignaling(x))
  {
    __builtin_abort();
  }
}

enum op {Add, Mult, Div, Abs};

void operation(enum op t)
{
  float x, y;
  float sNaN = __builtin_nansf ("");
  switch (t)
  {
    case Abs:
      x = fabs(sNaN);
      break;
    case Add:
      x = sNaN + 2.0;
      break;
    case Mult:
      x = sNaN * 2.0;
      break;
    case Div:
    default:
      x = sNaN / 2.0;
      break;
  }
  if (t == Abs)
  {
    if (!issignaling(x))
    {
      __builtin_abort();
    }
  }
  else if (issignaling(x))
  {
    __builtin_abort();
  }
}

int main (void)
{
  conversion();
  operation(Add);
  operation(Mult);
  operation(Div);
  operation(Abs);
  return 0;
}
