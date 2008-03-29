/* { dg-do run } */
/* { dg-require-effective-target sse4 } */
/* { dg-options "-O2 -msse4.2" } */

#include "sse4_2-check.h"
#include "sse4_2-pcmpstr.h"

#define NUM 1024

#define IMM_VAL0 \
  (_SIDD_SBYTE_OPS | _SIDD_CMP_RANGES | _SIDD_MASKED_POSITIVE_POLARITY)
#define IMM_VAL1 \
  (_SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY \
   | _SIDD_BIT_MASK)
#define IMM_VAL2 \
  (_SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_MASKED_NEGATIVE_POLARITY)
#define IMM_VAL3 \
  (_SIDD_SWORD_OPS | _SIDD_CMP_EQUAL_ORDERED \
   | _SIDD_MASKED_NEGATIVE_POLARITY | _SIDD_UNIT_MASK)


static void
sse4_2_test (void)
{
  union
    {
      __m128i x[NUM];
      char c[NUM *16];
    } src1, src2;
  __m128i res, correct;
  int i;

  for (i = 0; i < NUM *16; i++)
    {
      src1.c[i] = rand ();
      src2.c[i] = rand ();
    }

  for (i = 0; i < NUM; i++)
    {
      switch((rand() % 4))
	{
	case 0:
	  res  = _mm_cmpistrm (src1.x[i], src2.x[i], IMM_VAL0);
	  correct = cmp_im (&src1.x[i], &src2.x[i], IMM_VAL0, NULL);
	  break;

	case 1:
	  res  = _mm_cmpistrm (src1.x[i], src2.x[i], IMM_VAL1);
	  correct = cmp_im (&src1.x[i], &src2.x[i], IMM_VAL1, NULL);
	  break;

	case 2:
	  res  = _mm_cmpistrm (src1.x[i], src2.x[i], IMM_VAL2);
	  correct = cmp_im (&src1.x[i], &src2.x[i], IMM_VAL2, NULL);
	  break;

	default:
	  res  = _mm_cmpistrm (src1.x[i], src2.x[i], IMM_VAL3);
	  correct = cmp_im (&src1.x[i], &src2.x[i], IMM_VAL3, NULL);
	  break;
        }

      if (memcmp (&correct, &res, sizeof (res)))
	abort ();
    }
}
