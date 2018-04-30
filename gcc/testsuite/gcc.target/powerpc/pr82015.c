/* { dg-do compile { target { powerpc*-*-* && lp64 } } } */
/* { dg-skip-if "" { powerpc*-*-darwin* } } */
/* { dg-require-effective-target powerpc_vsx_ok } */
/* { dg-options "-O2 -mvsx" } */

unsigned long foo_11(__vector __int128_t *p)
{
  return __builtin_unpack_vector_int128(*p, 11); /* { dg-error "argument 2 must be a 1-bit unsigned literal" } */
}

unsigned long foo_n(__vector __int128_t *p, unsigned long n)
{
  return __builtin_unpack_vector_int128(*p, n);	/* { dg-error "argument 2 must be a 1-bit unsigned literal" } */
}
