#include <stdarg.h>

#ifdef DBG
#include <stdio.h>
#define DEBUG_FPUTS(x) fputs (x, stdout)
#define DEBUG_DOT putc ('.', stdout)
#define DEBUG_NL putc ('\n', stdout)
#else
#define DEBUG_FPUTS(x)
#define DEBUG_DOT
#define DEBUG_NL
#endif

/* Turn off checking for variable arguments with -DSKIPVA.  */
#ifdef SKIPVA
const int test_va = 0;
#else
const int test_va = 1;
#endif

#include "fp-struct-defs.h"
#include "fp-struct-init.h"
#include "fp-struct-test-by-value-y.h"

DEFS(d, double)
INITS(d, double)

TEST(Sd1, double)
TEST(Sd2, double)
TEST(Sd3, double)
TEST(Sd4, double)
TEST(Sd5, double)
TEST(Sd6, double)
TEST(Sd7, double)
TEST(Sd8, double)
TEST(Sd9, double)
TEST(Sd10, double)
TEST(Sd11, double)
TEST(Sd12, double)
TEST(Sd13, double)
TEST(Sd14, double)
TEST(Sd15, double)
TEST(Sd16, double)
