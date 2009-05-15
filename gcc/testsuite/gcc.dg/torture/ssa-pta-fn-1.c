/* { dg-do run } */
/* { dg-options "-fdump-tree-alias" } */
/* { dg-skip-if "" { *-*-* } { "-O0" } { "" } } */

extern void abort (void);
int *glob;

int * __attribute__((noinline,const))
foo_const(int *p) { return p; }

int * __attribute__((noinline,pure))
foo_pure(int *p) { return glob; }

int * __attribute__((noinline))
foo_normal(int *p) { glob = p; return p; }

void test_const(void)
{
  int i;
  int *p = &i;
  int *q_const = foo_const(p);
  *p = 1;
  *q_const = 2;
  if (*p != 2)
    abort ();
}

void test(void)
{
  int i;
  int *p = &i;
  int *q_normal = foo_normal(p);
  *p = 1;
  *q_normal = 2;
  if (*p != 2)
    abort ();
}

void test_pure(void)
{
  int i;
  int *p = &i;
  int *q_pure = foo_pure(p);
  *p = 1;
  *q_pure = 2;
  if (*p != 2)
    abort ();
}

int main()
{
  test_const();
  test();
  test_pure();
  return 0;
}

/* { dg-final { scan-tree-dump "q_const_., points-to non-local, points-to vars: { i }" "alias" } } */
/* { dg-final { scan-tree-dump "q_pure_., points-to non-local, points-to escaped, points-to vars: { i }" "alias" } } */
/* { dg-final { scan-tree-dump "q_normal_., points-to non-local, points-to escaped, points-to vars: { }" "alias" } } */
/* { dg-final { cleanup-tree-dump "alias" } } */
