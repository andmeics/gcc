/* { dg-do run { xfail *-*-* } } */
/* { dg-options "-g -O2" } */

#include "guality.h"

int a;

int foo()
{
  int tmp = a;
  int tmp2 = a;
  int tmp3;
  int res;
  GUALCHKVAL (a);
  GUALCHKVAL (tmp);
  GUALCHKVAL (tmp2);
  a = 0;
  tmp3 = tmp2;
  GUALCHKVAL (a);
  GUALCHKVAL (tmp);
  GUALCHKVAL (tmp2);
  GUALCHKVAL (tmp3);
  res = tmp - tmp2 + 1;
  return res;
}
