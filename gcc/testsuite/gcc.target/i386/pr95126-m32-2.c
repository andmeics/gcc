/* { dg-do compile { target { ia32 } } } */
/* { dg-options "-O2" } */

struct small{ short a,b; signed char c; };
static const struct small s = { 1,2,0 };
extern int func(struct small X);

void call_func(void)
{
  func(s);
}

/* { dg-final { scan-assembler "movl\[ \\t]*\\\$" } } */
/* { dg-final { scan-assembler "movb\[ \\t]*\\\$0, " } } */
/* { dg-final { scan-assembler-not "movzwl" } } */

