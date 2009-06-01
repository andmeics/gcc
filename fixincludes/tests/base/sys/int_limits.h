/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/sys/int_limits.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( SOLARIS_INT_LIMITS_1_CHECK )
#pragma ident	"@(#)int_limits.h	1.9	04/09/28 SMI"
#define	UINT8_MAX	(255)
#define	UINT16_MAX	(65535)
#endif  /* SOLARIS_INT_LIMITS_1_CHECK */


#if defined( SOLARIS_INT_LIMITS_2_CHECK )
#pragma ident	"@(#)int_limits.h	1.9	04/09/28 SMI"
#define	INT_FAST16_MAX INT32_MAX
#define	UINT_FAST16_MAX UINT32_MAX
#define	INT_FAST16_MIN INT32_MIN
#endif  /* SOLARIS_INT_LIMITS_2_CHECK */
