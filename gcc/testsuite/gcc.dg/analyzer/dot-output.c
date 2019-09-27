/* Verify that the various .dot output files from the analyzer are readable
   by .dot.  */

/* { dg-require-dot "" } */
/* { dg-additional-options "-fdump-analyzer-callgraph -fdump-analyzer-exploded-graph -fdump-analyzer-state-purge -fdump-analyzer-supergraph" } */

#include <stdlib.h>

int some_call (int i, char ch)
{
  return i * i;
}

int *test (int *buf, int n, int *out)
{
  int i;
  int *result = malloc (sizeof (int) * n);
  
  /* A loop, to ensure we have phi nodes.  */
  for (i = 0; i < n; i++)
    result[i] = buf[i] + i; /* { dg-warning "possibly-NULL" "" { xfail *-*-* } } */
  /* TODO(xfail): why isn't the warning appearing? */

  /* Example of a "'" (to test quoting).  */
  *out = some_call (i, 'a');
  
  return result;
}

/* { dg-final { dg-check-dot "dot-output.c.callgraph.dot" } } */
/* { dg-final { dg-check-dot "dot-output.c.eg.dot" } } */
/* { dg-final { dg-check-dot "dot-output.c.state-purge.dot" } } */
/* { dg-final { dg-check-dot "dot-output.c.supergraph.dot" } } */
