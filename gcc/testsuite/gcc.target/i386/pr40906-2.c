/* { dg-do run } */
/* { dg-require-effective-target ilp32 } */
/* { dg-options "-O2 -fomit-frame-pointer -mpush-args -mno-accumulate-outgoing-args -m128bit-long-double" } */

void abort (void);

void __attribute__((noinline))
f (long double a)
{
  if (a != 1.23L)
    abort ();
}

int __attribute__((noinline))
g (long double b)
{
  f (b);
  return 0;
}

int
main (void)
{
  g (1.23L);
  return 0;
}
