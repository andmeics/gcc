/* PR 14204 */
/* { dg-do compile } */
/* { dg-options "-O -Wall -Werror" } */

#if defined __alpha__
# define ASM __asm__("$30")
#elif defined __i386__
# define ASM __asm__("esp")
#elif defined __powerpc__
# define ASM __asm__("r1")
#else
# define ASM
#endif

void *load_PCB (void)
{
  register void *sp ASM;
  return sp;			/* { dg-bogus "uninitialized" } */
}
