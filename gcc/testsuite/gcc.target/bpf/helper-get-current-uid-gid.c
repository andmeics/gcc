/* { dg-do compile } */

#include <stdint.h>

void
foo ()
{
  uint64_t ret;

  ret = __builtin_bpf_helper_get_current_uid_gid ();
}

/* { dg-final { scan-assembler "call\t15" } } */
