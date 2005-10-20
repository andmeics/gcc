// { dg-do compile }
// { dg-options "-fopenmp -fdump-tree-omplower" }

void bar(void);
void foo(void)
{
  #pragma omp critical (xyzzy)
    bar();
}

// { dg-final { scan-tree-dump-times "\\&\\.gomp_critical_user_xyzzy" 2 "omplower" } }
