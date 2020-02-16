/* { dg-require-effective-target aarch64_asm_f64mm_ok } */
/* { dg-additional-options "-march=armv8.2-a+f64mm" } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** zip1q_s8_tied1:
**	zip1	z0\.q, z0\.q, z1\.q
**	ret
*/
TEST_UNIFORM_Z (zip1q_s8_tied1, svint8_t,
		z0 = svzip1q_s8 (z0, z1),
		z0 = svzip1q (z0, z1))

/*
** zip1q_s8_tied2:
**	zip1	z0\.q, z1\.q, z0\.q
**	ret
*/
TEST_UNIFORM_Z (zip1q_s8_tied2, svint8_t,
		z0 = svzip1q_s8 (z1, z0),
		z0 = svzip1q (z1, z0))

/*
** zip1q_s8_untied:
**	zip1	z0\.q, z1\.q, z2\.q
**	ret
*/
TEST_UNIFORM_Z (zip1q_s8_untied, svint8_t,
		z0 = svzip1q_s8 (z1, z2),
		z0 = svzip1q (z1, z2))
