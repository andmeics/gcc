/* { dg-do run { target { powerpc*-*-* && p8vector_hw } } } */
/* { dg-options "-mdejagnu-cpu=power8 -O2" } */

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <altivec.h>

#ifdef DEBUG
#include <stdio.h>
#endif

void abort (void);

int main() {
  int i;
  vector bool char ubc_arg1, ubc_arg2, ubc_arg3;
  vector unsigned char uc_arg1, uc_arg2, uc_arg3;
  vector signed char sc_arg1, sc_arg2, sc_arg3;

  vector bool char vec_ubc_expected1, vec_ubc_result1;
  vector unsigned char vec_uc_expected1, vec_uc_result1;
  vector signed char vec_sc_expected1, vec_sc_result1;

  /* vec_permxor: bool char args, result */
  ubc_arg1 = (vector bool char){0xA, 0x2, 0xB0, 0x4,
				0x5, 0x6, 0x7, 0x8,
				0x9, 0x10, 0x11, 0x12,
				0x13, 0x15, 0x15, 0x16};
  ubc_arg2 = (vector bool char){0x5, 0x20, 0xC, 0x40,
				0x55, 0x66, 0x77, 0x88,
				0x9, 0xFF, 0x0, 0xED,
				0x4, 0x5, 0x6, 0x7};
  ubc_arg3 = (vector bool char){0x08, 0x19, 0x2A, 0x3B,
				0x4D, 0x5C, 0x6D, 0x7E,
				0x8F, 0x90, 0xA1, 0xB2,
				0xC3, 0xD4, 0xE5, 0xF6};
  vec_ubc_expected1 = (vector bool char){0x3, 0xFD, 0xB0, 0xE9,
					 0x0, 0x2, 0x2, 0xE,
					 0xE, 0x15, 0x31, 0x1E,
					 0x53, 0x40, 0x73, 0x61};
  vec_ubc_result1 = vec_permxor (ubc_arg1, ubc_arg2, ubc_arg3);

  for (i = 0; i < 16; i++) {
    if (vec_ubc_expected1[i] != vec_ubc_result1[i])
#ifdef DEBUG
      printf("ERROR vec_permxor (ubc, ubc, ubc) result[%d]=0x%x != expected[%d]=0x%x\n",
	     i, vec_ubc_result1[i],  i, vec_ubc_expected1[i]);
#else
      abort();
#endif
  }

  /* vec_permxor: signed char args, result */
  sc_arg1 = (vector signed char){0x1, 0x2, 0x3, 0x4,
				 0x5, 0x6, 0x7, 0x8,
				 0x9, 0x10, 0xA, 0xB,
				 0xC, 0xD, 0xE, 0xF};
  sc_arg2 = (vector signed char){0x5, 0x5, 0x7, 0x8,
				 0x9, 0xA, 0xB, 0xC,
				 0xD, 0xE, 0xF, 0x0,
				 0x1, 0x2, 0x3, 0x4};
  sc_arg3 = (vector signed char){0x08, 0x19, 0x2A, 0x3B,
				0x4D, 0x5C, 0x6D, 0x7E,
				0x8F, 0x90, 0xA1, 0xB2,
				0xC3, 0xD4, 0xE5, 0xF6};
  vec_sc_expected1 = (vector signed char){0xC, 0xC, 0xC, 0x4,
					  0x7, 0x7, 0x5, 0xB,
					  0xD, 0x15, 0xF, 0xC,
					  0x4, 0x4, 0x4, 0x4};
  vec_sc_result1 = vec_permxor (sc_arg1, sc_arg2, sc_arg3);

  for (i = 0; i < 16; i++) {
    if (vec_sc_expected1[i] != vec_sc_result1[i])
#ifdef DEBUG
      printf("ERROR vec_permxor (sc, sc, sc) result[%d]=0x%x != expected[%d]=0x%x\n",
	     i, vec_sc_result1[i],  i, vec_sc_expected1[i]);
#else
      abort();
#endif
  }

  /* vec_permxor: unsigned char args, result */
  uc_arg1 = (vector unsigned char){0xA, 0xB, 0xC, 0xD,
				   0xE, 0xF, 0x0, 0x1,
				   0x2, 0x3, 0x4, 0x5,
				   0x6, 0x7, 0x8, 0x9};
  uc_arg2 = (vector unsigned char){0x5, 0x6, 0x7, 0x8,
				   0x9, 0xA, 0xB, 0xC,
				   0xD, 0xE, 0xF, 0x0,
				   0x1, 0x2, 0x3, 0x4};
  uc_arg3 = (vector unsigned char){0x08, 0x19, 0x2A, 0x3B,
				   0x4D, 0x5C, 0x6D, 0x7E,
				   0x8F, 0x90, 0xA1, 0xB2,
				   0xC3, 0xD4, 0xE5, 0xF6};
  vec_uc_expected1 = (vector unsigned char){0x7, 0x5, 0x3, 0xD,
					    0xC, 0xE, 0x2, 0x2,
					    0x6, 0x6, 0x2, 0x2,
					    0xE, 0xE, 0x2, 0x2};
  vec_uc_result1 = vec_permxor (uc_arg1, uc_arg2, uc_arg3);

  for (i = 0; i < 16; i++) {
    if (vec_uc_expected1[i] != vec_uc_result1[i])
#ifdef DEBUG
      printf("ERROR vec_permxor (uc, uc, uc) result[%d]=0x%x != expected[%d]=0x%x\n",
	     i, vec_uc_result1[i],  i, vec_uc_expected1[i]);
#else
      abort();
#endif
  }
}
