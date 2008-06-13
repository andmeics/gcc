/*  DO NOT EDIT THIS FILE.

    It has been auto-edited by fixincludes from:

	"fixinc/tests/inc/stdlib.h"

    This had to be done to correct non-standard usages in the
    original, manufacturer supplied header file.  */



#if defined( HPUX11_ABS_CHECK )
#if !defined(_MATH_INCLUDED) || defined(__GNUG__)
#endif  /* HPUX11_ABS_CHECK */


#if defined( HPUX_LONG_DOUBLE_CHECK )
extern long double strtold(const char *, char **);

#endif  /* HPUX_LONG_DOUBLE_CHECK */


#if defined( INT_ABORT_FREE_AND_EXIT_CHECK )
extern void	abort(int);
extern void	free(void*);
extern void	exit(void*);
#endif  /* INT_ABORT_FREE_AND_EXIT_CHECK */


#if defined( LYNXOS_MISSING_PUTENV_CHECK )
extern char *getenv	_AP((const char *));
extern int putenv				_AP((char *));
#endif  /* LYNXOS_MISSING_PUTENV_CHECK */


#if defined( SVR4_GETCWD_CHECK )
extern char* getcwd(char *, size_t);
#endif  /* SVR4_GETCWD_CHECK */


#if defined( SVR4_PROFIL_CHECK )
profil(unsigned short *, size_t, int, unsigned int);
#endif  /* SVR4_PROFIL_CHECK */


#if defined( SYSZ_STDLIB_FOR_SUN_CHECK )
extern void *	calloc(size_t);
extern void *	malloc(size_t);
extern void *	realloc(void*,size_t);
extern void *	bsearch(void*,size_t,size_t);

#endif  /* SYSZ_STDLIB_FOR_SUN_CHECK */
