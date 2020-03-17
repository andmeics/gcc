/* PR target/93047 */
/* Originator: Andrew Church <gcczilla@achurch.org> */
/* { dg-do run } */
/* { dg-additional-options "-O3 -frename-registers" } */
/* { dg-require-effective-target untyped_assembly } */

#ifdef __MMIX__
/* No parameters on stack for bar.  */
#define STACK_ARGUMENTS_SIZE 0
#else
#define STACK_ARGUMENTS_SIZE 64
#endif

extern void abort(void);

int foo(int n)
{
  return n+1;
}

int bar(int n)
{
  __builtin_return(__builtin_apply((void (*)(void))foo, __builtin_apply_args(),
				   STACK_ARGUMENTS_SIZE));
}

int main(void)
{
  /* Allocate 64 bytes on the stack to make sure that __builtin_apply
     can read at least 64 bytes above the return address.  */
  char dummy[64];

  __asm__ ("" : : "" (dummy));

  if (bar(1) != 2)
    abort();

  return 0;
}

