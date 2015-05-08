/* { dg-do run } */

#include <stdlib.h>
#include <openacc.h>

int
main (int argc, char **argv)
{
  const int N = 256;
  unsigned char *h;
  void *d;

  h = (unsigned char *) malloc (N);

  d = acc_malloc (N);

  acc_map_data (h, 0, N);

  acc_unmap_data (h);

  acc_free (d);

  free (h);

  return 0;
}

/* { dg-output "\\\[\[0-9a-fA-FxX\]+,\\\+256\]->\\\[\[^\n\r]*,\\\+256\\\] is a bad map" { target openacc_nvidia_accel_selected } } */
/* { dg-output "cannot map data on shared-memory system" { target openacc_host_selected } } */
/* { dg-shouldfail "" } */
