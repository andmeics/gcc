/* { dg-do run } */
/* { dg-options "-O2 -fno-strict-aliasing -msse2" } */
/* { dg-additional-options "-mno-mmx" { target { ! ia32 } } } */

#include "sse2-check.h"
#include "mmx-vals.h"

__attribute__((noinline, noclone))
static void
test_psllwi  (long long *ll1, unsigned int imm, long long *r)
{
  __m64 t1 = *(__m64 *) ll1;
  switch (imm)
    {
    case 0:
      *(__m64 *) r = _m_psrlqi (t1, 0);
      break;
    case 1:
      *(__m64 *) r = _m_psrlqi (t1, 1);
      break;
    case 2:
      *(__m64 *) r = _m_psrlqi (t1, 2);
      break;
    case 3:
      *(__m64 *) r = _m_psrlqi (t1, 3);
      break;
    case 4:
      *(__m64 *) r = _m_psrlqi (t1, 4);
      break;
    case 5:
      *(__m64 *) r = _m_psrlqi (t1, 5);
      break;
    case 6:
      *(__m64 *) r = _m_psrlqi (t1, 6);
      break;
    case 7:
      *(__m64 *) r = _m_psrlqi (t1, 7);
      break;
    case 8:
      *(__m64 *) r = _m_psrlqi (t1, 8);
      break;
    case 9:
      *(__m64 *) r = _m_psrlqi (t1, 9);
      break;
    case 10:
      *(__m64 *) r = _m_psrlqi (t1, 10);
      break;
    case 11:
      *(__m64 *) r = _m_psrlqi (t1, 11);
      break;
    case 12:
      *(__m64 *) r = _m_psrlqi (t1, 12);
      break;
    case 13:
      *(__m64 *) r = _m_psrlqi (t1, 13);
      break;
    case 14:
      *(__m64 *) r = _m_psrlqi (t1, 14);
      break;
    case 15:
      *(__m64 *) r = _m_psrlqi (t1, 15);
      break;
    case 16:
      *(__m64 *) r = _m_psrlqi (t1, 16);
      break;
    case 17:
      *(__m64 *) r = _m_psrlqi (t1, 17);
      break;
    case 18:
      *(__m64 *) r = _m_psrlqi (t1, 18);
      break;
    case 19:
      *(__m64 *) r = _m_psrlqi (t1, 19);
      break;
    case 20:
      *(__m64 *) r = _m_psrlqi (t1, 20);
      break;
    case 21:
      *(__m64 *) r = _m_psrlqi (t1, 21);
      break;
    case 22:
      *(__m64 *) r = _m_psrlqi (t1, 22);
      break;
    case 23:
      *(__m64 *) r = _m_psrlqi (t1, 23);
      break;
    case 24:
      *(__m64 *) r = _m_psrlqi (t1, 24);
      break;
    case 25:
      *(__m64 *) r = _m_psrlqi (t1, 25);
      break;
    case 26:
      *(__m64 *) r = _m_psrlqi (t1, 26);
      break;
    case 27:
      *(__m64 *) r = _m_psrlqi (t1, 27);
      break;
    case 28:
      *(__m64 *) r = _m_psrlqi (t1, 28);
      break;
    case 29:
      *(__m64 *) r = _m_psrlqi (t1, 29);
      break;
    case 30:
      *(__m64 *) r = _m_psrlqi (t1, 30);
      break;
    case 31:
      *(__m64 *) r = _m_psrlqi (t1, 31);
      break;
    case 32:
      *(__m64 *) r = _m_psrlqi (t1, 32);
      break;
    case 33:
      *(__m64 *) r = _m_psrlqi (t1, 33);
      break;
    case 34:
      *(__m64 *) r = _m_psrlqi (t1, 34);
      break;
    case 35:
      *(__m64 *) r = _m_psrlqi (t1, 35);
      break;
    case 36:
      *(__m64 *) r = _m_psrlqi (t1, 36);
      break;
    case 37:
      *(__m64 *) r = _m_psrlqi (t1, 37);
      break;
    case 38:
      *(__m64 *) r = _m_psrlqi (t1, 38);
      break;
    case 39:
      *(__m64 *) r = _m_psrlqi (t1, 39);
      break;
    case 40:
      *(__m64 *) r = _m_psrlqi (t1, 40);
      break;
    case 41:
      *(__m64 *) r = _m_psrlqi (t1, 41);
      break;
    case 42:
      *(__m64 *) r = _m_psrlqi (t1, 42);
      break;
    case 43:
      *(__m64 *) r = _m_psrlqi (t1, 43);
      break;
    case 44:
      *(__m64 *) r = _m_psrlqi (t1, 44);
      break;
    case 45:
      *(__m64 *) r = _m_psrlqi (t1, 45);
      break;
    case 46:
      *(__m64 *) r = _m_psrlqi (t1, 46);
      break;
    case 47:
      *(__m64 *) r = _m_psrlqi (t1, 47);
      break;
    case 48:
      *(__m64 *) r = _m_psrlqi (t1, 48);
      break;
    case 49:
      *(__m64 *) r = _m_psrlqi (t1, 49);
      break;
    case 50:
      *(__m64 *) r = _m_psrlqi (t1, 50);
      break;
    case 51:
      *(__m64 *) r = _m_psrlqi (t1, 51);
      break;
    case 52:
      *(__m64 *) r = _m_psrlqi (t1, 52);
      break;
    case 53:
      *(__m64 *) r = _m_psrlqi (t1, 53);
      break;
    case 54:
      *(__m64 *) r = _m_psrlqi (t1, 54);
      break;
    case 55:
      *(__m64 *) r = _m_psrlqi (t1, 55);
      break;
    case 56:
      *(__m64 *) r = _m_psrlqi (t1, 56);
      break;
    case 57:
      *(__m64 *) r = _m_psrlqi (t1, 57);
      break;
    case 58:
      *(__m64 *) r = _m_psrlqi (t1, 58);
      break;
    case 59:
      *(__m64 *) r = _m_psrlqi (t1, 59);
      break;
    case 60:
      *(__m64 *) r = _m_psrlqi (t1, 60);
      break;
    case 61:
      *(__m64 *) r = _m_psrlqi (t1, 61);
      break;
    case 62:
      *(__m64 *) r = _m_psrlqi (t1, 62);
      break;
    case 63:
      *(__m64 *) r = _m_psrlqi (t1, 63);
      break;
    default:
      *(__m64 *) r = _m_psrlqi (t1, 64);
      break;
    }
}

/* Routine to manually compute the results */
static void
compute_correct_result (unsigned long long *src, unsigned int imm,
			unsigned long long *res)
{
  int i;
  if (imm > 63)
    res[0] = 0;
  else
    res[0] = src[0] >> imm;
}

static void
sse2_test (void)
{
  int i;
  unsigned int count;
  long long r, ck;
  int fail = 0;

  /* Run the MMX tests */
  for (i = 0; i < MMX_num_ops; i++)
    {
      count = MMXops[i];
      test_psllwi (&MMXops[i], count, &r);
      compute_correct_result (&MMXops[i], count, &ck);
      if (ck != r)
	  fail++;
      }

  if (fail != 0)
    abort ();
}
