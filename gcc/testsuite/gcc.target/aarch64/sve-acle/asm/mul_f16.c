/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** mul_f16_m_tied1:
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_m_tied1, svfloat16_t,
		z0 = svmul_f16_m (p0, z0, z1),
		z0 = svmul_m (p0, z0, z1))

/* Bad RA choice: no preferred output sequence.  */
TEST_UNIFORM_Z (mul_f16_m_tied2, svfloat16_t,
		z0 = svmul_f16_m (p0, z1, z0),
		z0 = svmul_m (p0, z1, z0))

/*
** mul_f16_m_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, z2\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_m_untied, svfloat16_t,
		z0 = svmul_f16_m (p0, z1, z2),
		z0 = svmul_m (p0, z1, z2))

/*
** mul_w0_f16_m_tied1:
**	mov	(z[0-9]+\.h), w0
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_m_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_m (p0, z0, x0),
		 z0 = svmul_m (p0, z0, x0))

/*
** mul_w0_f16_m_untied:
**	mov	(z[0-9]+\.h), w0
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_m_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_m (p0, z1, x0),
		 z0 = svmul_m (p0, z1, x0))

/*
** mul_h4_f16_m_tied1:
**	mov	(z[0-9]+\.h), h4
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_m_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_m (p0, z0, d4),
		 z0 = svmul_m (p0, z0, d4))

/*
** mul_h4_f16_m_untied:
**	mov	(z[0-9]+\.h), h4
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_m_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_m (p0, z1, d4),
		 z0 = svmul_m (p0, z1, d4))

/*
** mul_1_f16_m_tied1:
**	fmov	(z[0-9]+\.h), #1\.0(?:e\+0)?
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (mul_1_f16_m_tied1, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z0, 1),
		z0 = svmul_m (p0, z0, 1))

/*
** mul_1_f16_m_untied:
**	fmov	(z[0-9]+\.h), #1\.0(?:e\+0)?
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (mul_1_f16_m_untied, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z1, 1),
		z0 = svmul_m (p0, z1, 1))

/*
** mul_0p5_f16_m_tied1:
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_m_tied1, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z0, 0.5),
		z0 = svmul_m (p0, z0, 0.5))

/*
** mul_0p5_f16_m_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_m_untied, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z1, 0.5),
		z0 = svmul_m (p0, z1, 0.5))

/*
** mul_2_f16_m_tied1:
**	fmul	z0\.h, p0/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (mul_2_f16_m_tied1, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z0, 2.0),
		z0 = svmul_m (p0, z0, 2.0))

/*
** mul_2_f16_m_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (mul_2_f16_m_untied, svfloat16_t,
		z0 = svmul_n_f16_m (p0, z1, 2.0),
		z0 = svmul_m (p0, z1, 2.0))

/*
** mul_f16_z_tied1:
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_z_tied1, svfloat16_t,
		z0 = svmul_f16_z (p0, z0, z1),
		z0 = svmul_z (p0, z0, z1))

/*
** mul_f16_z_tied2:
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_z_tied2, svfloat16_t,
		z0 = svmul_f16_z (p0, z1, z0),
		z0 = svmul_z (p0, z1, z0))

/*
** mul_f16_z_untied:
**	movprfx	z0\.h, p0/z, z1\.h
**	fmul	z0\.h, p0/m, z0\.h, z2\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_z_untied, svfloat16_t,
		z0 = svmul_f16_z (p0, z1, z2),
		z0 = svmul_z (p0, z1, z2))

/*
** mul_w0_f16_z_tied1:
**	mov	(z[0-9]+\.h), w0
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_z_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_z (p0, z0, x0),
		 z0 = svmul_z (p0, z0, x0))

/*
** mul_w0_f16_z_untied:
**	mov	(z[0-9]+\.h), w0
**	movprfx	z0\.h, p0/z, \1
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_z_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_z (p0, z1, x0),
		 z0 = svmul_z (p0, z1, x0))

/*
** mul_h4_f16_z_tied1:
**	mov	(z[0-9]+\.h), h4
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_z_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_z (p0, z0, d4),
		 z0 = svmul_z (p0, z0, d4))

/*
** mul_h4_f16_z_untied:
**	mov	(z[0-9]+\.h), h4
**	movprfx	z0\.h, p0/z, \1
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_z_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_z (p0, z1, d4),
		 z0 = svmul_z (p0, z1, d4))

/*
** mul_1_f16_z_tied1:
**	fmov	(z[0-9]+\.h), #1\.0(?:e\+0)?
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (mul_1_f16_z_tied1, svfloat16_t,
		z0 = svmul_n_f16_z (p0, z0, 1),
		z0 = svmul_z (p0, z0, 1))

/*
** mul_0p5_f16_z_tied1:
**	movprfx	z0\.h, p0/z, z0\.h
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_z_tied1, svfloat16_t,
		z0 = svmul_n_f16_z (p0, z0, 0.5),
		z0 = svmul_z (p0, z0, 0.5))

/*
** mul_0p5_f16_z_untied:
**	movprfx	z0\.h, p0/z, z1\.h
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_z_untied, svfloat16_t,
		z0 = svmul_n_f16_z (p0, z1, 0.5),
		z0 = svmul_z (p0, z1, 0.5))

/*
** mul_2_f16_z_untied:
**	movprfx	z0\.h, p0/z, z1\.h
**	fmul	z0\.h, p0/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (mul_2_f16_z_untied, svfloat16_t,
		z0 = svmul_n_f16_z (p0, z1, 2),
		z0 = svmul_z (p0, z1, 2))

/*
** mul_f16_x_tied1:
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_x_tied1, svfloat16_t,
		z0 = svmul_f16_x (p0, z0, z1),
		z0 = svmul_x (p0, z0, z1))

/*
** mul_f16_x_tied2:
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_x_tied2, svfloat16_t,
		z0 = svmul_f16_x (p0, z1, z0),
		z0 = svmul_x (p0, z1, z0))

/*
** mul_f16_x_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, z2\.h
**	ret
*/
TEST_UNIFORM_Z (mul_f16_x_untied, svfloat16_t,
		z0 = svmul_f16_x (p0, z1, z2),
		z0 = svmul_x (p0, z1, z2))

/*
** mul_w0_f16_x_tied1:
**	mov	(z[0-9]+\.h), w0
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_x_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (p0, z0, x0),
		 z0 = svmul_x (p0, z0, x0))

/*
** mul_w0_f16_x_untied:
**	mov	z0\.h, w0
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZS (mul_w0_f16_x_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (p0, z1, x0),
		 z0 = svmul_x (p0, z1, x0))

/*
** mul_h4_f16_x_tied1:
**	mov	(z[0-9]+\.h), h4
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_x_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (p0, z0, d4),
		 z0 = svmul_x (p0, z0, d4))

/*
** mul_h4_f16_x_untied:
**	mov	z0\.h, h4
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_ZS (mul_h4_f16_x_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (p0, z1, d4),
		 z0 = svmul_x (p0, z1, d4))

/*
** mul_1_f16_x_tied1:
**	fmov	(z[0-9]+\.h), #1\.0(?:e\+0)?
**	fmul	z0\.h, p0/m, z0\.h, \1
**	ret
*/
TEST_UNIFORM_Z (mul_1_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z0, 1),
		z0 = svmul_x (p0, z0, 1))

/*
** mul_1_f16_x_untied:
**	fmov	z0\.h, #1\.0(?:e\+0)?
**	fmul	z0\.h, p0/m, z0\.h, z1\.h
**	ret
*/
TEST_UNIFORM_Z (mul_1_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z1, 1),
		z0 = svmul_x (p0, z1, 1))

/*
** mul_0p5_f16_x_tied1:
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z0, 0.5),
		z0 = svmul_x (p0, z0, 0.5))

/*
** mul_0p5_f16_x_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (mul_0p5_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z1, 0.5),
		z0 = svmul_x (p0, z1, 0.5))

/*
** mul_2_f16_x_tied1:
**	fmul	z0\.h, p0/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (mul_2_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z0, 2),
		z0 = svmul_x (p0, z0, 2))

/*
** mul_2_f16_x_untied:
**	movprfx	z0, z1
**	fmul	z0\.h, p0/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (mul_2_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (p0, z1, 2),
		z0 = svmul_x (p0, z1, 2))

/*
** ptrue_mul_f16_x_tied1:
**	fmul	(z0\.h, z1\.h, z0\.h|z0\.h, z0\.h, z1\.h)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_f16_x_tied1, svfloat16_t,
		z0 = svmul_f16_x (svptrue_b16 (), z0, z1),
		z0 = svmul_x (svptrue_b16 (), z0, z1))

/*
** ptrue_mul_f16_x_tied2:
**	fmul	(z0\.h, z0\.h, z1\.h|z0\.h, z1\.h, z0\.h)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_f16_x_tied2, svfloat16_t,
		z0 = svmul_f16_x (svptrue_b16 (), z1, z0),
		z0 = svmul_x (svptrue_b16 (), z1, z0))

/*
** ptrue_mul_f16_x_untied:
**	fmul	(z0\.h, z2\.h, z1\.h|z0\.h, z1\.h, z2\.h)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_f16_x_untied, svfloat16_t,
		z0 = svmul_f16_x (svptrue_b16 (), z1, z2),
		z0 = svmul_x (svptrue_b16 (), z1, z2))

/*
** ptrue_mul_w0_f16_x_tied1:
**	mov	(z[0-9]+\.h), w0
**	fmul	(z0\.h, \1, z0\.h|z0\.h, z0\.h, \1)
**	ret
*/
TEST_UNIFORM_ZS (ptrue_mul_w0_f16_x_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (svptrue_b16 (), z0, x0),
		 z0 = svmul_x (svptrue_b16 (), z0, x0))

/*
** ptrue_mul_w0_f16_x_untied:
**	mov	(z[0-9]+\.h), w0
**	fmul	(z0\.h, \1, z1\.h|z0\.h, z1\.h, \1)
**	ret
*/
TEST_UNIFORM_ZS (ptrue_mul_w0_f16_x_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (svptrue_b16 (), z1, x0),
		 z0 = svmul_x (svptrue_b16 (), z1, x0))

/*
** ptrue_mul_h4_f16_x_tied1:
**	mov	(z[0-9]+\.h), h4
**	fmul	(z0\.h, \1, z0\.h|z0\.h, z0\.h, \1)
**	ret
*/
TEST_UNIFORM_ZS (ptrue_mul_h4_f16_x_tied1, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (svptrue_b16 (), z0, d4),
		 z0 = svmul_x (svptrue_b16 (), z0, d4))

/*
** ptrue_mul_h4_f16_x_untied:
**	mov	(z[0-9]+\.h), h4
**	fmul	(z0\.h, \1, z1\.h|z0\.h, z1\.h, \1)
**	ret
*/
TEST_UNIFORM_ZS (ptrue_mul_h4_f16_x_untied, svfloat16_t, __fp16,
		 z0 = svmul_n_f16_x (svptrue_b16 (), z1, d4),
		 z0 = svmul_x (svptrue_b16 (), z1, d4))

/*
** ptrue_mul_1_f16_x_untied:
**	fmov	(z[0-9]+\.h), #1\.0(?:e\+0)?
**	fmul	(z0\.h, \1, z1\.h|z0\.h, z1\.h, \1)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_1_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z1, 1),
		z0 = svmul_x (svptrue_b16 (), z1, 1))

/*
** ptrue_mul_0p5_f16_x_tied1:
**	ptrue	(p[0-7])\.h[^\n]*
**	fmul	z0\.h, \1/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_0p5_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z0, 0.5),
		z0 = svmul_x (svptrue_b16 (), z0, 0.5))

/*
** ptrue_mul_0p5_f16_x_untied:
**	ptrue	(p[0-7])\.h[^\n]*
**	movprfx	z0, z1
**	fmul	z0\.h, \1/m, z0\.h, #0\.5
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_0p5_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z1, 0.5),
		z0 = svmul_x (svptrue_b16 (), z1, 0.5))

/*
** ptrue_mul_m1_f16_x_tied1:
**	fmov	(z[0-9]+\.h), #-1\.0(?:e\+0)?
**	fmul	(z0\.h, \1, z0\.h|z0\.h, z0\.h, \1)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_m1_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z0, -1),
		z0 = svmul_x (svptrue_b16 (), z0, -1))

/*
** ptrue_mul_m1_f16_x_untied:
**	fmov	(z[0-9]+\.h), #-1\.0(?:e\+0)?
**	fmul	(z0\.h, \1, z1\.h|z0\.h, z1\.h, \1)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_m1_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z1, -1),
		z0 = svmul_x (svptrue_b16 (), z1, -1))

/*
** ptrue_mul_m0p5_f16_x_tied1:
**	fmov	(z[0-9]+\.h), #-(?:0\.5|5\.0e-1)
**	fmul	(z0\.h, \1, z0\.h|z0\.h, z0\.h, \1)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_m0p5_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z0, -0.5),
		z0 = svmul_x (svptrue_b16 (), z0, -0.5))

/*
** ptrue_mul_m0p5_f16_x_untied:
**	fmov	(z[0-9]+\.h), #-(?:0\.5|5\.0e-1)
**	fmul	(z0\.h, \1, z1\.h|z0\.h, z1\.h, \1)
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_m0p5_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z1, -0.5),
		z0 = svmul_x (svptrue_b16 (), z1, -0.5))

/*
** ptrue_mul_2_f16_x_tied1:
**	ptrue	(p[0-7])\.h[^\n]*
**	fmul	z0\.h, \1/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_2_f16_x_tied1, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z0, 2),
		z0 = svmul_x (svptrue_b16 (), z0, 2))

/*
** ptrue_mul_2_f16_x_untied:
**	ptrue	(p[0-7])\.h[^\n]*
**	movprfx	z0, z1
**	fmul	z0\.h, \1/m, z0\.h, #2\.0
**	ret
*/
TEST_UNIFORM_Z (ptrue_mul_2_f16_x_untied, svfloat16_t,
		z0 = svmul_n_f16_x (svptrue_b16 (), z1, 2),
		z0 = svmul_x (svptrue_b16 (), z1, 2))
