/* { dg-do assemble } */
/* { dg-options "-std=c99 -O3 -march=armv8-a+sve --save-temps" } */

#define DO_REGREG_OPS(TYPE, OP, NAME)				\
void varith_##TYPE##_##NAME (TYPE* dst, TYPE* src, int count)	\
{								\
  for (int i = 0; i < count; ++i)				\
    dst[i] = dst[i] OP src[i];					\
}

#define DO_IMMEDIATE_OPS(VALUE, TYPE, OP, NAME)		\
void varithimm_##NAME##_##TYPE (TYPE* dst, int count)	\
{							\
  for (int i = 0; i < count; ++i)			\
    dst[i] = dst[i] OP VALUE;				\
}

#define DO_ARITH_OPS(TYPE, OP, NAME)			\
DO_REGREG_OPS (TYPE, OP, NAME);				\
DO_IMMEDIATE_OPS (0, TYPE, OP, NAME ## 0);		\
DO_IMMEDIATE_OPS (0.5, TYPE, OP, NAME ## 0point5);	\
DO_IMMEDIATE_OPS (1, TYPE, OP, NAME ## 1);		\
DO_IMMEDIATE_OPS (2, TYPE, OP, NAME ## 2);		\
DO_IMMEDIATE_OPS (5, TYPE, OP, NAME ## 5);		\
DO_IMMEDIATE_OPS (-1, TYPE, OP, NAME ## minus1);

DO_ARITH_OPS (float, *, mul)
DO_ARITH_OPS (double, *, mul)

/* { dg-final { scan-assembler-times {\tfmul\tz[0-9]+\.s, z[0-9]+\.s, z[0-9]+\.s\n} 4 } } */
/* { dg-final { scan-assembler-times {\tfmul\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #0.5\n} 1 } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #1} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #2} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #5} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s, #-} } } */

/* { dg-final { scan-assembler-times {\tfmul\tz[0-9]+\.d, z[0-9]+\.d, z[0-9]+\.d\n} 4 } } */
/* { dg-final { scan-assembler-times {\tfmul\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d, #0.5\n} 1 } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d, #1} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d, #2} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d, #5} } } */
/* { dg-final { scan-assembler-not   {\tfmul\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d, #-} } } */
