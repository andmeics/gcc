/* { dg-do compile } */ 
/* { dg-options "-O2 -fdump-tree-dce1" } */
void
cleanup (int a, int b)
{
  if (a)
    if (b)
      a = 1;
    else
      b = 1;
  else if (a)
    a = 1;
  else
    b = 1;
  return;
}
/* Dce should get rid of the initializers and cfgcleanup should elliminate ifs  */
/* { dg-final { scan-tree-dump-times "if " 0 "dce1"} } */
/* { dg-final { scan-tree-dump-times "goto " 0 "dce1"} } */
