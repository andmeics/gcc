/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** mad_f64_m_tied1:
**	fmad	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_m_tied1, svfloat64_t,
		z0 = svmad_f64_m (p0, z0, z1, z2),
		z0 = svmad_m (p0, z0, z1, z2))

/*
** mad_f64_m_tied2:
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, \1, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_m_tied2, svfloat64_t,
		z0 = svmad_f64_m (p0, z1, z0, z2),
		z0 = svmad_m (p0, z1, z0, z2))

/*
** mad_f64_m_tied3:
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mad_f64_m_tied3, svfloat64_t,
		z0 = svmad_f64_m (p0, z1, z2, z0),
		z0 = svmad_m (p0, z1, z2, z0))

/*
** mad_f64_m_untied:
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, z2\.d, z3\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_m_untied, svfloat64_t,
		z0 = svmad_f64_m (p0, z1, z2, z3),
		z0 = svmad_m (p0, z1, z2, z3))

/*
** mad_x0_f64_m_tied1:
**	mov	(z[0-9]+\.d), x0
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_m_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z0, z1, x0),
		 z0 = svmad_m (p0, z0, z1, x0))

/*
** mad_x0_f64_m_tied2:
**	mov	(z[0-9]+\.d), x0
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, \2, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_m_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z1, z0, x0),
		 z0 = svmad_m (p0, z1, z0, x0))

/*
** mad_x0_f64_m_untied:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_m_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z1, z2, x0),
		 z0 = svmad_m (p0, z1, z2, x0))

/*
** mad_d4_f64_m_tied1:
**	mov	(z[0-9]+\.d), d4
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_m_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z0, z1, d4),
		 z0 = svmad_m (p0, z0, z1, d4))

/*
** mad_d4_f64_m_tied2:
**	mov	(z[0-9]+\.d), d4
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, \2, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_m_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z1, z0, d4),
		 z0 = svmad_m (p0, z1, z0, d4))

/*
** mad_d4_f64_m_untied:
**	mov	(z[0-9]+\.d), d4
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_m_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_m (p0, z1, z2, d4),
		 z0 = svmad_m (p0, z1, z2, d4))

/*
** mad_2_f64_m_tied1:
**	fmov	(z[0-9]+\.d), #2\.0(?:e\+0)?
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_m_tied1, svfloat64_t,
		z0 = svmad_n_f64_m (p0, z0, z1, 2),
		z0 = svmad_m (p0, z0, z1, 2))

/*
** mad_2_f64_m_tied2:
**	fmov	(z[0-9]+\.d), #2\.0(?:e\+0)?
**	mov	(z[0-9]+\.d), z0\.d
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, \2, \1
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_m_tied2, svfloat64_t,
		z0 = svmad_n_f64_m (p0, z1, z0, 2),
		z0 = svmad_m (p0, z1, z0, 2))

/*
** mad_2_f64_m_untied:
**	fmov	(z[0-9]+\.d), #2\.0(?:e\+0)?
**	movprfx	z0, z1
**	fmad	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_m_untied, svfloat64_t,
		z0 = svmad_n_f64_m (p0, z1, z2, 2),
		z0 = svmad_m (p0, z1, z2, 2))

/*
** mad_f64_z_tied1:
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_z_tied1, svfloat64_t,
		z0 = svmad_f64_z (p0, z0, z1, z2),
		z0 = svmad_z (p0, z0, z1, z2))

/*
** mad_f64_z_tied2:
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_z_tied2, svfloat64_t,
		z0 = svmad_f64_z (p0, z1, z0, z2),
		z0 = svmad_z (p0, z1, z0, z2))

/*
** mad_f64_z_tied3:
**	movprfx	z0\.d, p0/z, z0\.d
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_z_tied3, svfloat64_t,
		z0 = svmad_f64_z (p0, z1, z2, z0),
		z0 = svmad_z (p0, z1, z2, z0))

/*
** mad_f64_z_untied:
**	movprfx	z0\.d, p0/z, z3\.d
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_z_untied, svfloat64_t,
		z0 = svmad_f64_z (p0, z1, z2, z3),
		z0 = svmad_z (p0, z1, z2, z3))

/*
** mad_x0_f64_z_tied1:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_z_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z0, z1, x0),
		 z0 = svmad_z (p0, z0, z1, x0))

/*
** mad_x0_f64_z_tied2:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_z_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z1, z0, x0),
		 z0 = svmad_z (p0, z1, z0, x0))

/*
** mad_x0_f64_z_untied:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, \1
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_z_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z1, z2, x0),
		 z0 = svmad_z (p0, z1, z2, x0))

/*
** mad_d4_f64_z_tied1:
**	mov	(z[0-9]+\.d), d4
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_z_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z0, z1, d4),
		 z0 = svmad_z (p0, z0, z1, d4))

/*
** mad_d4_f64_z_tied2:
**	mov	(z[0-9]+\.d), d4
**	movprfx	z0\.d, p0/z, z0\.d
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_z_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z1, z0, d4),
		 z0 = svmad_z (p0, z1, z0, d4))

/*
** mad_d4_f64_z_untied:
**	mov	(z[0-9]+\.d), d4
**	movprfx	z0\.d, p0/z, \1
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_z_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_z (p0, z1, z2, d4),
		 z0 = svmad_z (p0, z1, z2, d4))

/*
** mad_f64_x_tied1:
**	fmad	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_x_tied1, svfloat64_t,
		z0 = svmad_f64_x (p0, z0, z1, z2),
		z0 = svmad_x (p0, z0, z1, z2))

/*
** mad_f64_x_tied2:
**	fmad	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_x_tied2, svfloat64_t,
		z0 = svmad_f64_x (p0, z1, z0, z2),
		z0 = svmad_x (p0, z1, z0, z2))

/*
** mad_f64_x_tied3:
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_x_tied3, svfloat64_t,
		z0 = svmad_f64_x (p0, z1, z2, z0),
		z0 = svmad_x (p0, z1, z2, z0))

/*
** mad_f64_x_untied:
**	movprfx	z0, z3
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_f64_x_untied, svfloat64_t,
		z0 = svmad_f64_x (p0, z1, z2, z3),
		z0 = svmad_x (p0, z1, z2, z3))

/*
** mad_x0_f64_x_tied1:
**	mov	(z[0-9]+\.d), x0
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_x_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z0, z1, x0),
		 z0 = svmad_x (p0, z0, z1, x0))

/*
** mad_x0_f64_x_tied2:
**	mov	(z[0-9]+\.d), x0
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_x_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z1, z0, x0),
		 z0 = svmad_x (p0, z1, z0, x0))

/*
** mad_x0_f64_x_untied:
**	mov	z0\.d, x0
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_ZS (mad_x0_f64_x_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z1, z2, x0),
		 z0 = svmad_x (p0, z1, z2, x0))

/*
** mad_d4_f64_x_tied1:
**	mov	(z[0-9]+\.d), d4
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_x_tied1, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z0, z1, d4),
		 z0 = svmad_x (p0, z0, z1, d4))

/*
** mad_d4_f64_x_tied2:
**	mov	(z[0-9]+\.d), d4
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_x_tied2, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z1, z0, d4),
		 z0 = svmad_x (p0, z1, z0, d4))

/*
** mad_d4_f64_x_untied:
**	mov	z0\.d, d4
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_ZS (mad_d4_f64_x_untied, svfloat64_t, double,
		 z0 = svmad_n_f64_x (p0, z1, z2, d4),
		 z0 = svmad_x (p0, z1, z2, d4))

/*
** mad_2_f64_x_tied1:
**	fmov	(z[0-9]+\.d), #2\.0(?:e\+0)?
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_x_tied1, svfloat64_t,
		z0 = svmad_n_f64_x (p0, z0, z1, 2),
		z0 = svmad_x (p0, z0, z1, 2))

/*
** mad_2_f64_x_tied2:
**	fmov	(z[0-9]+\.d), #2\.0(?:e\+0)?
**	fmad	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_x_tied2, svfloat64_t,
		z0 = svmad_n_f64_x (p0, z1, z0, 2),
		z0 = svmad_x (p0, z1, z0, 2))

/*
** mad_2_f64_x_untied:
**	fmov	z0\.d, #2\.0(?:e\+0)?
**	fmla	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mad_2_f64_x_untied, svfloat64_t,
		z0 = svmad_n_f64_x (p0, z1, z2, 2),
		z0 = svmad_x (p0, z1, z2, 2))
