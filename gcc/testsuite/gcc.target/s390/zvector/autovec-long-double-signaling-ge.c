/* { dg-do compile { target int128 } } */
/* { dg-options "-O3 -march=z14 -mzvector -mzarch" } */

#include "autovec.h"

AUTOVEC_LONG_DOUBLE (SIGNALING_GE);

/* { dg-final { scan-assembler {\n\twfkhexb\t} } } */
