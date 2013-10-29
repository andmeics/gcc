/* callee cannot be inlined into caller because it has a higher
   target ISA.  */
/* { dg-do compile } */

__attribute__((always_inline,target("sse4.2")))
__inline int callee () /* { dg-error "inlining failed in call to always_inline" }  */
{
  return 0;
}

__attribute__((target("sse")))
__inline int caller ()
{
  return callee(); /* { dg-error "called from here" }  */
}

int main ()
{
  return caller();
}
/* callee cannot be inlined into caller because it has a higher
   target ISA.  */
