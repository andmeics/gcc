/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** cvt_s64_f16_m_tied1:
**	fcvtzs	z0\.d, p0/m, z4\.h
**	ret
*/
TEST_DUAL_Z (cvt_s64_f16_m_tied1, svint64_t, svfloat16_t,
	     z0 = svcvt_s64_f16_m (z0, p0, z4),
	     z0 = svcvt_s64_m (z0, p0, z4))

/*
** cvt_s64_f16_m_tied2:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0, z4
**	fcvtzs	z0\.d, p0/m, \1\.h
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f16_m_tied2, svint64_t, svfloat16_t,
		 z0_res = svcvt_s64_f16_m (z4, p0, z0),
		 z0_res = svcvt_s64_m (z4, p0, z0))

/*
** cvt_s64_f16_m_untied:
**	movprfx	z0, z1
**	fcvtzs	z0\.d, p0/m, z4\.h
**	ret
*/
TEST_DUAL_Z (cvt_s64_f16_m_untied, svint64_t, svfloat16_t,
	     z0 = svcvt_s64_f16_m (z1, p0, z4),
	     z0 = svcvt_s64_m (z1, p0, z4))

/*
** cvt_s64_f32_m_tied1:
**	fcvtzs	z0\.d, p0/m, z4\.s
**	ret
*/
TEST_DUAL_Z (cvt_s64_f32_m_tied1, svint64_t, svfloat32_t,
	     z0 = svcvt_s64_f32_m (z0, p0, z4),
	     z0 = svcvt_s64_m (z0, p0, z4))

/*
** cvt_s64_f32_m_tied2:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0, z4
**	fcvtzs	z0\.d, p0/m, \1\.s
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f32_m_tied2, svint64_t, svfloat32_t,
		 z0_res = svcvt_s64_f32_m (z4, p0, z0),
		 z0_res = svcvt_s64_m (z4, p0, z0))

/*
** cvt_s64_f32_m_untied:
**	movprfx	z0, z1
**	fcvtzs	z0\.d, p0/m, z4\.s
**	ret
*/
TEST_DUAL_Z (cvt_s64_f32_m_untied, svint64_t, svfloat32_t,
	     z0 = svcvt_s64_f32_m (z1, p0, z4),
	     z0 = svcvt_s64_m (z1, p0, z4))

/*
** cvt_s64_f64_m_tied1:
**	fcvtzs	z0\.d, p0/m, z4\.d
**	ret
*/
TEST_DUAL_Z (cvt_s64_f64_m_tied1, svint64_t, svfloat64_t,
	     z0 = svcvt_s64_f64_m (z0, p0, z4),
	     z0 = svcvt_s64_m (z0, p0, z4))

/*
** cvt_s64_f64_m_tied2:
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z4
**	fcvtzs	z0\.d, p0/m, \1
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f64_m_tied2, svint64_t, svfloat64_t,
		 z0_res = svcvt_s64_f64_m (z4, p0, z0),
		 z0_res = svcvt_s64_m (z4, p0, z0))

/*
** cvt_s64_f64_m_untied:
**	movprfx	z0, z1
**	fcvtzs	z0\.d, p0/m, z4\.d
**	ret
*/
TEST_DUAL_Z (cvt_s64_f64_m_untied, svint64_t, svfloat64_t,
	     z0 = svcvt_s64_f64_m (z1, p0, z4),
	     z0 = svcvt_s64_m (z1, p0, z4))

/*
** cvt_s64_f16_z_tied1:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0\.d, p0/z, \1\.d
**	fcvtzs	z0\.d, p0/m, \1\.h
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f16_z_tied1, svint64_t, svfloat16_t,
		 z0_res = svcvt_s64_f16_z (p0, z0),
		 z0_res = svcvt_s64_z (p0, z0))

/*
** cvt_s64_f16_z_untied:
**	movprfx	z0\.d, p0/z, z4\.d
**	fcvtzs	z0\.d, p0/m, z4\.h
**	ret
*/
TEST_DUAL_Z (cvt_s64_f16_z_untied, svint64_t, svfloat16_t,
	     z0 = svcvt_s64_f16_z (p0, z4),
	     z0 = svcvt_s64_z (p0, z4))

/*
** cvt_s64_f32_z_tied1:
**	mov	(z[0-9]+)\.d, z0\.d
**	movprfx	z0\.d, p0/z, \1\.d
**	fcvtzs	z0\.d, p0/m, \1\.s
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f32_z_tied1, svint64_t, svfloat32_t,
		 z0_res = svcvt_s64_f32_z (p0, z0),
		 z0_res = svcvt_s64_z (p0, z0))

/*
** cvt_s64_f32_z_untied:
**	movprfx	z0\.d, p0/z, z4\.d
**	fcvtzs	z0\.d, p0/m, z4\.s
**	ret
*/
TEST_DUAL_Z (cvt_s64_f32_z_untied, svint64_t, svfloat32_t,
	     z0 = svcvt_s64_f32_z (p0, z4),
	     z0 = svcvt_s64_z (p0, z4))

/*
** cvt_s64_f64_z_tied1:
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0\.d, p0/z, \1
**	fcvtzs	z0\.d, p0/m, \1
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f64_z_tied1, svint64_t, svfloat64_t,
		 z0_res = svcvt_s64_f64_z (p0, z0),
		 z0_res = svcvt_s64_z (p0, z0))

/*
** cvt_s64_f64_z_untied:
**	movprfx	z0\.d, p0/z, z4\.d
**	fcvtzs	z0\.d, p0/m, z4\.d
**	ret
*/
TEST_DUAL_Z (cvt_s64_f64_z_untied, svint64_t, svfloat64_t,
	     z0 = svcvt_s64_f64_z (p0, z4),
	     z0 = svcvt_s64_z (p0, z4))

/*
** cvt_s64_f16_x_tied1:
**	fcvtzs	z0\.d, p0/m, z0\.h
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f16_x_tied1, svint64_t, svfloat16_t,
		 z0_res = svcvt_s64_f16_x (p0, z0),
		 z0_res = svcvt_s64_x (p0, z0))

/*
** cvt_s64_f16_x_untied:
**	fcvtzs	z0\.d, p0/m, z4\.h
**	ret
*/
TEST_DUAL_Z (cvt_s64_f16_x_untied, svint64_t, svfloat16_t,
	     z0 = svcvt_s64_f16_x (p0, z4),
	     z0 = svcvt_s64_x (p0, z4))

/*
** cvt_s64_f32_x_tied1:
**	fcvtzs	z0\.d, p0/m, z0\.s
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f32_x_tied1, svint64_t, svfloat32_t,
		 z0_res = svcvt_s64_f32_x (p0, z0),
		 z0_res = svcvt_s64_x (p0, z0))

/*
** cvt_s64_f32_x_untied:
**	fcvtzs	z0\.d, p0/m, z4\.s
**	ret
*/
TEST_DUAL_Z (cvt_s64_f32_x_untied, svint64_t, svfloat32_t,
	     z0 = svcvt_s64_f32_x (p0, z4),
	     z0 = svcvt_s64_x (p0, z4))

/*
** cvt_s64_f64_x_tied1:
**	fcvtzs	z0\.d, p0/m, z0\.d
**	ret
*/
TEST_DUAL_Z_REV (cvt_s64_f64_x_tied1, svint64_t, svfloat64_t,
		 z0_res = svcvt_s64_f64_x (p0, z0),
		 z0_res = svcvt_s64_x (p0, z0))

/*
** cvt_s64_f64_x_untied:
**	fcvtzs	z0\.d, p0/m, z4\.d
**	ret
*/
TEST_DUAL_Z (cvt_s64_f64_x_untied, svint64_t, svfloat64_t,
	     z0 = svcvt_s64_f64_x (p0, z4),
	     z0 = svcvt_s64_x (p0, z4))
