/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-require-effective-target powerpc_popcntb_ok } */
/* { dg-options "-mdejagnu-cpu=power5" } */

void abort ();

unsigned int
do_compare (unsigned int a, unsigned int b)
{
  return __builtin_cmpb (a, b);  /* { dg-warning "implicit declaration of function '__builtin_cmpb'" } */
}

void
expect (unsigned int pattern, unsigned int value)
{
  if (pattern != value)
    abort ();
}

int
main (int argc, char *argv[])
{
  expect (0xff000000, do_compare (0x12345678, 0x12000000));
  expect (0x00ffffff, do_compare (0x12345678, 0x00345678));
  expect (0x000000ff, do_compare (0x00000078, 0x12345678));
}
