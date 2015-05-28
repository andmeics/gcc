/* { dg-do compile } */
/* { dg-require-effective-target mpx } */
/* { dg-options "-fcheck-pointer-bounds -mmpx -O2 -fdump-tree-strlen" } */
/* { dg-final { scan-tree-dump-times "strlen" 1 "strlen" } } */
/* { dg-final { cleanup-tree-dump "strlen" } } */

#include "string.h"

size_t test (char *str1, char *str2)
{
  size_t len = strlen (str2);
  memcpy (str1, str2, len + 1);
  return len + strlen (str1);
}
