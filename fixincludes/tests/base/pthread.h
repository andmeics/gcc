/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/pthread.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( AIX_PTHREAD_CHECK )
#define PTHREAD_MUTEX_INITIALIZER \
{...init stuff...}
#endif  /* AIX_PTHREAD_CHECK */


#if defined( ALPHA_PTHREAD_CHECK )
#  if defined (_PTHREAD_ENV_DECC) || defined (_PTHREAD_ENV_EPCC) || defined (__PRAGMA_EXTERN_PREFIX)
#   define _PTHREAD_USE_PTDNAM_
#  endif
#  if defined (_PTHREAD_ENV_DECC) || defined (__PRAGMA_EXTERN_PREFIX)
#   define _PTHREAD_USE_PTDNAM_
#  endif
#endif  /* ALPHA_PTHREAD_CHECK */


#if defined( ALPHA_PTHREAD_GCC_CHECK )
# define _PTHREAD_ENV_INTELC
#elif defined (__GNUC__)
# define _PTHREAD_ENV_GCC
#else
# error <pthread.h>: unrecognized compiler.
#endif
#endif  /* ALPHA_PTHREAD_GCC_CHECK */


#if defined( ALPHA_PTHREAD_INIT_CHECK )
/*
 * @(#)_RCSfile: pthread.h,v $ _Revision: 1.1.33.21 $ (DEC) _Date: 2000/08/15 15:30:13 $
 */
#ifndef _PTHREAD_NOMETER_STATIC
# define PTHREAD_MUTEX_INITIALIZER     {_PTHREAD_MSTATE_CONFIG, _PTHREAD_MVALID | _PTHREAD_MVF_STA, 0, 0, 0, 0, 0, 0 }
# define PTHREAD_COND_INITIALIZER     {_PTHREAD_CSTATE_SLOW, _PTHREAD_CVALID | _PTHREAD_CVF_STA, 0, 0, 0, 0 }
# define PTHREAD_MUTEX_INITWITHNAME_NP(_n_,_a_)     {_PTHREAD_MSTATE_CONFIG, _PTHREAD_MVALID | _PTHREAD_MVF_STA, _n_, _a_, 0, 0, 0, 0 }
# define PTHREAD_COND_INITWITHNAME_NP(_n_,_a_)     {_PTHREAD_CSTATE_SLOW, _PTHREAD_CVALID | _PTHREAD_CVF_STA, _n_, _a_, 0, 0 }
#else
# define PTHREAD_MUTEX_INITIALIZER {0, _PTHREAD_MVALID | _PTHREAD_MVF_STA, 0, 0, 0, 0, 0, 0 }
# define PTHREAD_MUTEX_INITWITHNAME_NP(_n_,_a_)     {0, _PTHREAD_MVALID | _PTHREAD_MVF_STA, _n_, _a_, 0, 0, 0, 0 }
# define PTHREAD_COND_INITWITHNAME_NP(_n_,_a_)     {{{0},0}, _PTHREAD_CVALID | _PTHREAD_CVF_STA, _n_, _a_, 0, 0 }
#endif

#define PTHREAD_RWLOCK_INITIALIZER {_PTHREAD_RWVALID | _PTHREAD_RWVF_STA, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define PTHREAD_RWLOCK_INITWITHNAME_NP(_n_,_a_)         {_PTHREAD_RWVALID | _PTHREAD_RWVF_STA, _n_, _a_, 0, 0, 0, 0, 0, 0, 0 }

#endif  /* ALPHA_PTHREAD_INIT_CHECK */


#if defined( GLIBC_MUTEX_INIT_CHECK )
#define PTHREAD_MUTEX_INITIALIZER \
  { { 0, 0, 0, 0, 0, 0 } }
#ifdef __USE_GNU
# if __WORDSIZE == 64
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, 0 } }
#  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0 } }
#  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, 0 } }
# else
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, 0, 0 } }
#  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0, 0 } }
#  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, 0, 0 } }
# endif
#endif
# if __WORDSIZE == 64
#  define PTHREAD_RWLOCK_INITIALIZER \
  { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }
# else
#  define PTHREAD_RWLOCK_INITIALIZER \
  { { 0, 0, 0, 0, 0, 0, 0, 0 } }
# endif
# ifdef __USE_GNU
#  if __WORDSIZE == 64
#   define PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,					      \
      PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP } }
#  else
#   define PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  { { 0, 0, 0, 0, 0, 0, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP, 0 } }
#  endif
# endif
#define PTHREAD_COND_INITIALIZER { { 0, 0, 0, 0, 0, (void *) 0, 0, 0 } }
#endif  /* GLIBC_MUTEX_INIT_CHECK */


#if defined( PTHREAD_PAGE_SIZE_CHECK )
extern int __page_size;
#endif  /* PTHREAD_PAGE_SIZE_CHECK */


#if defined( PTHREAD_INCOMPLETE_STRUCT_ARGUMENT_CHECK )
extern int __sigsetjmp (struct __jmp_buf_tag *__env, int __savemask);
#endif  /* PTHREAD_INCOMPLETE_STRUCT_ARGUMENT_CHECK */


#if defined( SOLARIS_MUTEX_INIT_1_CHECK )
#ident "@(#)pthread.h  1.16    97/05/05 SMI"
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_MUTEX_INITIALIZER	{{{0}, 0}, {{{0}}}, 0}
#else
#define PTHREAD_MUTEX_INITIALIZER	{{{0}, 0}, {{{0}}}, {0}}
#endif
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_COND_INITIALIZER	{{{0},0}, 0} /* */
#else
#define PTHREAD_COND_INITIALIZER	{{{0},0}, {0}} /* */
#endif

#endif  /* SOLARIS_MUTEX_INIT_1_CHECK */


#if defined( SOLARIS_MUTEX_INIT_2_CHECK )
#ident "@(#)pthread.h  1.26  98/04/12 SMI"
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_MUTEX_INITIALIZER	{{{0},0}, {{{0}}}, 0}
#else
#define PTHREAD_MUTEX_INITIALIZER	{{{0},0}, {{{0}}}, {0}}
#endif
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_COND_INITIALIZER	{{{0}, 0}, 0}	/* DEFAULTCV */
#else
#define PTHREAD_COND_INITIALIZER	{{{0}, 0}, {0}}	/* DEFAULTCV */
#endif
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define	PTHREAD_MUTEX_INITIALIZER		/* = DEFAULTMUTEX */	\
	{{0, 0, 0, DEFAULT_TYPE, _MUTEX_MAGIC}, {{{0}}}, 0}
#else
#define	PTHREAD_MUTEX_INITIALIZER		/* = DEFAULTMUTEX */	\
	{{0, 0, 0, DEFAULT_TYPE, _MUTEX_MAGIC}, {{{0}}}, {0}}
#endif
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define	PTHREAD_COND_INITIALIZER		/* = DEFAULTCV */	\
	{{{0, 0, 0, 0}, DEFAULT_TYPE, _COND_MAGIC}, 0}
#else
#define	PTHREAD_COND_INITIALIZER		/* = DEFAULTCV */	\
	{{{0, 0, 0, 0}, DEFAULT_TYPE, _COND_MAGIC}, {0}}
#endif
#endif  /* SOLARIS_MUTEX_INIT_2_CHECK */


#if defined( SOLARIS_RWLOCK_INIT_1_CHECK )
#ident "@(#)pthread.h  1.26  98/04/12 SMI"
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_RWLOCK_INITIALIZER	{0, 0, 0, {0, 0, 0}, {0, 0}, {0, 0}}
#else
#define PTHREAD_RWLOCK_INITIALIZER	{0, 0, 0, {{0}, {0}, {0}}, {{0}, {0}}, {{0}, {0}}}
#endif
#endif  /* SOLARIS_RWLOCK_INIT_1_CHECK */


#if defined( SOLARIS_ONCE_INIT_1_CHECK )
#pragma ident	"@(#)pthread.h	1.37	04/09/28 SMI"
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_ONCE_INIT	{{0, 0, 0, PTHREAD_ONCE_NOTDONE}}
#else
#define PTHREAD_ONCE_INIT	{{{0}, {0}, {0}, {PTHREAD_ONCE_NOTDONE}}}
#endif
#endif  /* SOLARIS_ONCE_INIT_1_CHECK */


#if defined( SOLARIS_ONCE_INIT_2_CHECK )
#ident "@(#)pthread.h  1.26  98/04/12 SMI"
#if __STDC__ - 0 == 0 && !defined(_NO_LONGLONG)
#define PTHREAD_ONCE_INIT	{{0, 0, 0, PTHREAD_ONCE_NOTDONE}}
#else
#define PTHREAD_ONCE_INIT	{{{0}, {0}, {0}, {PTHREAD_ONCE_NOTDONE}}}
#endif

#endif  /* SOLARIS_ONCE_INIT_2_CHECK */


#if defined( THREAD_KEYWORD_CHECK )
extern int pthread_create (pthread_t *__restrict __thr,
extern int pthread_kill (pthread_t __thr, int __signo);
extern int pthread_cancel (pthread_t __thr);
#endif  /* THREAD_KEYWORD_CHECK */
