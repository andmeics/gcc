/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** div_f32_m_tied1:
**	fdiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_m_tied1, svfloat32_t,
		z0 = svdiv_f32_m (p0, z0, z1),
		z0 = svdiv_m (p0, z0, z1))

/* Bad RA choice: no preferred output sequence.  */
TEST_UNIFORM_Z (div_f32_m_tied2, svfloat32_t,
		z0 = svdiv_f32_m (p0, z1, z0),
		z0 = svdiv_m (p0, z1, z0))

/*
** div_f32_m_untied:
**	movprfx	z0, z1
**	fdiv	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_m_untied, svfloat32_t,
		z0 = svdiv_f32_m (p0, z1, z2),
		z0 = svdiv_m (p0, z1, z2))

/*
** div_w0_f32_m_tied1:
**	mov	(z[0-9]+\.s), w0
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_m_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_m (p0, z0, x0),
		 z0 = svdiv_m (p0, z0, x0))

/*
** div_w0_f32_m_untied:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0, z1
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_m_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_m (p0, z1, x0),
		 z0 = svdiv_m (p0, z1, x0))

/*
** div_s4_f32_m_tied1:
**	mov	(z[0-9]+\.s), s4
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_m_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_m (p0, z0, d4),
		 z0 = svdiv_m (p0, z0, d4))

/*
** div_s4_f32_m_untied:
**	mov	(z[0-9]+\.s), s4
**	movprfx	z0, z1
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_m_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_m (p0, z1, d4),
		 z0 = svdiv_m (p0, z1, d4))

/*
** div_1_f32_m_tied1:
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_m_tied1, svfloat32_t,
		z0 = svdiv_n_f32_m (p0, z0, 1),
		z0 = svdiv_m (p0, z0, 1))

/*
** div_1_f32_m_untied:
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	movprfx	z0, z1
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_m_untied, svfloat32_t,
		z0 = svdiv_n_f32_m (p0, z1, 1),
		z0 = svdiv_m (p0, z1, 1))

/*
** div_f32_z_tied1:
**	movprfx	z0\.s, p0/z, z0\.s
**	fdiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_z_tied1, svfloat32_t,
		z0 = svdiv_f32_z (p0, z0, z1),
		z0 = svdiv_z (p0, z0, z1))

/*
** div_f32_z_tied2:
**	movprfx	z0\.s, p0/z, z0\.s
**	fdivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_z_tied2, svfloat32_t,
		z0 = svdiv_f32_z (p0, z1, z0),
		z0 = svdiv_z (p0, z1, z0))

/*
** div_f32_z_untied:
**	movprfx	z0\.s, p0/z, z1\.s
**	fdiv	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_z_untied, svfloat32_t,
		z0 = svdiv_f32_z (p0, z1, z2),
		z0 = svdiv_z (p0, z1, z2))

/*
** div_w0_f32_z_tied1:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z0\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_z_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_z (p0, z0, x0),
		 z0 = svdiv_z (p0, z0, x0))

/*
** div_w0_f32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z1\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_z_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_z (p0, z1, x0),
		 z0 = svdiv_z (p0, z1, x0))

/*
** div_s4_f32_z_tied1:
**	mov	(z[0-9]+\.s), s4
**	movprfx	z0\.s, p0/z, z0\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_z_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_z (p0, z0, d4),
		 z0 = svdiv_z (p0, z0, d4))

/*
** div_s4_f32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), s4
**	movprfx	z0\.s, p0/z, z1\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_z_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_z (p0, z1, d4),
		 z0 = svdiv_z (p0, z1, d4))

/*
** div_1_f32_z_tied1:
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	movprfx	z0\.s, p0/z, z0\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_z_tied1, svfloat32_t,
		z0 = svdiv_n_f32_z (p0, z0, 1),
		z0 = svdiv_z (p0, z0, 1))

/*
** div_1_f32_z_untied: { xfail *-*-* }
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	movprfx	z0\.s, p0/z, z1\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_z_untied, svfloat32_t,
		z0 = svdiv_n_f32_z (p0, z1, 1),
		z0 = svdiv_z (p0, z1, 1))

/*
** div_0p5_f32_z_untied: { xfail *-*-* }
**	fmov	(z[0-9]+\.s), #(?:0\.5|5\.0e-1)
**	movprfx	z0\.s, p0/z, z1\.s
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_0p5_f32_z_untied, svfloat32_t,
		z0 = svdiv_n_f32_z (p0, z1, 0.5),
		z0 = svdiv_z (p0, z1, 0.5))

/*
** div_f32_x_tied1:
**	fdiv	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_x_tied1, svfloat32_t,
		z0 = svdiv_f32_x (p0, z0, z1),
		z0 = svdiv_x (p0, z0, z1))

/*
** div_f32_x_tied2:
**	fdivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_x_tied2, svfloat32_t,
		z0 = svdiv_f32_x (p0, z1, z0),
		z0 = svdiv_x (p0, z1, z0))

/*
** div_f32_x_untied:
**	movprfx	z0, z1
**	fdiv	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (div_f32_x_untied, svfloat32_t,
		z0 = svdiv_f32_x (p0, z1, z2),
		z0 = svdiv_x (p0, z1, z2))

/*
** div_w0_f32_x_tied1:
**	mov	(z[0-9]+\.s), w0
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_x_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (p0, z0, x0),
		 z0 = svdiv_x (p0, z0, x0))

/*
** div_w0_f32_x_untied:
**	mov	z0\.s, w0
**	fdivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_ZS (div_w0_f32_x_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (p0, z1, x0),
		 z0 = svdiv_x (p0, z1, x0))

/*
** div_s4_f32_x_tied1:
**	mov	(z[0-9]+\.s), s4
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_x_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (p0, z0, d4),
		 z0 = svdiv_x (p0, z0, d4))

/*
** div_s4_f32_x_untied:
**	mov	z0\.s, s4
**	fdivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_ZS (div_s4_f32_x_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (p0, z1, d4),
		 z0 = svdiv_x (p0, z1, d4))

/*
** div_1_f32_x_tied1:
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	fdiv	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_x_tied1, svfloat32_t,
		z0 = svdiv_n_f32_x (p0, z0, 1),
		z0 = svdiv_x (p0, z0, 1))

/*
** div_1_f32_x_untied:
**	fmov	z0\.s, #1\.0(?:e\+0)?
**	fdivr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (div_1_f32_x_untied, svfloat32_t,
		z0 = svdiv_n_f32_x (p0, z1, 1),
		z0 = svdiv_x (p0, z1, 1))

/*
** ptrue_div_f32_x_tied1:
**	ptrue	(p[0-7])\.s[^\n]*
**	fdiv	z0\.s, \1/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (ptrue_div_f32_x_tied1, svfloat32_t,
		z0 = svdiv_f32_x (svptrue_b32 (), z0, z1),
		z0 = svdiv_x (svptrue_b32 (), z0, z1))

/*
** ptrue_div_f32_x_tied2:
**	ptrue	(p[0-7])\.s[^\n]*
**	fdivr	z0\.s, \1/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (ptrue_div_f32_x_tied2, svfloat32_t,
		z0 = svdiv_f32_x (svptrue_b32 (), z1, z0),
		z0 = svdiv_x (svptrue_b32 (), z1, z0))

/*
** ptrue_div_f32_x_untied:
**	ptrue	(p[0-7])\.s[^\n]*
**	movprfx	z0, z1
**	fdiv	z0\.s, \1/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (ptrue_div_f32_x_untied, svfloat32_t,
		z0 = svdiv_f32_x (svptrue_b32 (), z1, z2),
		z0 = svdiv_x (svptrue_b32 (), z1, z2))

/*
** ptrue_div_w0_f32_x_tied1:
**	ptrue	(p[0-7])\.s[^\n]*
**	mov	(z[0-9]+\.s), w0
**	fdiv	z0\.s, \1/m, z0\.s, \2
**	ret
*/
TEST_UNIFORM_ZS (ptrue_div_w0_f32_x_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (svptrue_b32 (), z0, x0),
		 z0 = svdiv_x (svptrue_b32 (), z0, x0))

/*
** ptrue_div_w0_f32_x_untied:
**	ptrue	(p[0-7])\.s[^\n]*
**	mov	z0\.s, w0
**	fdivr	z0\.s, \1/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_ZS (ptrue_div_w0_f32_x_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (svptrue_b32 (), z1, x0),
		 z0 = svdiv_x (svptrue_b32 (), z1, x0))

/*
** ptrue_div_s4_f32_x_tied1:
**	ptrue	(p[0-7])\.s[^\n]*
**	mov	(z[0-9]+\.s), s4
**	fdiv	z0\.s, \1/m, z0\.s, \2
**	ret
*/
TEST_UNIFORM_ZS (ptrue_div_s4_f32_x_tied1, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (svptrue_b32 (), z0, d4),
		 z0 = svdiv_x (svptrue_b32 (), z0, d4))

/*
** ptrue_div_s4_f32_x_untied:
**	ptrue	(p[0-7])\.s[^\n]*
**	mov	z0\.s, s4
**	fdivr	z0\.s, \1/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_ZS (ptrue_div_s4_f32_x_untied, svfloat32_t, float,
		 z0 = svdiv_n_f32_x (svptrue_b32 (), z1, d4),
		 z0 = svdiv_x (svptrue_b32 (), z1, d4))

/*
** ptrue_div_1_f32_x_untied:
**	ptrue	(p[0-7])\.s[^\n]*
**	fmov	z0\.s, #1\.0(?:e\+0)?
**	fdivr	z0\.s, \1/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (ptrue_div_1_f32_x_untied, svfloat32_t,
		z0 = svdiv_n_f32_x (svptrue_b32 (), z1, 1),
		z0 = svdiv_x (svptrue_b32 (), z1, 1))

/*
** ptrue_div_1_f32_x_tied1:
**	ptrue	(p[0-7])\.s[^\n]*
**	fmov	(z[0-9]+\.s), #1\.0(?:e\+0)?
**	fdiv	z0\.s, \1/m, z0\.s, \2
**	ret
*/
TEST_UNIFORM_Z (ptrue_div_1_f32_x_tied1, svfloat32_t,
		z0 = svdiv_n_f32_x (svptrue_b32 (), z0, 1),
		z0 = svdiv_x (svptrue_b32 (), z0, 1))
