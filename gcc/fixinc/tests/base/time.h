#ifndef FIXINC_M88K_MULTI_INCL_CHECK
#define FIXINC_M88K_MULTI_INCL_CHECK 1



#if defined( M88K_MULTI_INCL_CHECK )

#endif  /* M88K_MULTI_INCL_CHECK */


#if defined( VXWORKS_NEEDS_VXTYPES_CHECK )
unsigned int	_clocks_per_sec;
#endif  /* VXWORKS_NEEDS_VXTYPES_CHECK */


#if defined( VXWORKS_TIME_CHECK )
#ifndef __gcc_VOIDFUNCPTR_defined
#ifdef __cplusplus
typedef void (*__gcc_VOIDFUNCPTR) (...);
#else
typedef void (*__gcc_VOIDFUNCPTR) ();
#endif
#define __gcc_VOIDFUNCPTR_defined
#endif
#define VOIDFUNCPTR __gcc_VOIDFUNCPTR
#endif  /* VXWORKS_TIME_CHECK */

#endif  /* FIXINC_M88K_MULTI_INCL_CHECK */
