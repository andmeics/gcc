/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** tbl2_bf16_tied1:
**	tbl	z0\.h, {z0\.h(?:, | - )z1\.h}, z4\.h
**	ret
*/
TEST_TBL2 (tbl2_bf16_tied1, svbfloat16x2_t, svbfloat16_t, svuint16_t,
	   z0_res = svtbl2_bf16 (z0, z4),
	   z0_res = svtbl2 (z0, z4))

/*
** tbl2_bf16_tied2:
**	tbl	z0\.h, {z1\.h(?:, | - )z2\.h}, z0\.h
**	ret
*/
TEST_TBL2_REV (tbl2_bf16_tied2, svbfloat16x2_t, svbfloat16_t, svuint16_t,
	       z0_res = svtbl2_bf16 (z1, z0),
	       z0_res = svtbl2 (z1, z0))

/*
** tbl2_bf16_untied:
**	tbl	z0\.h, {z2\.h(?:, | - )z3\.h}, z4\.h
**	ret
*/
TEST_TBL2 (tbl2_bf16_untied, svbfloat16x2_t, svbfloat16_t, svuint16_t,
	   z0_res = svtbl2_bf16 (z2, z4),
	   z0_res = svtbl2 (z2, z4))
