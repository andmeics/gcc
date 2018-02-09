/* { dg-do compile { target { lp64 } } } */
/* { dg-options "-O2 -mfunction-return=keep -mindirect-branch=keep -mcmodel=large" } */
/* { dg-additional-options "-fPIC" { target fpic } } */

__attribute__ ((function_return("thunk-extern")))
void
bar (void)
{ /* { dg-error "'-mfunction-return=thunk-extern' and '-mcmodel=large' are not compatible" } */
}
