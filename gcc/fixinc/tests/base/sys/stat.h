

#if defined( M88K_BAD_S_IF_CHECK )
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG) /* is regular? */
#endif  /* M88K_BAD_S_IF_CHECK */


#if defined( RS6000_FCHMOD_CHECK )
extern int fchmod(int, mode_t);
#endif  /* RS6000_FCHMOD_CHECK */


#if defined( SCO_STATIC_FUNC_CHECK )
#ifdef __STDC__
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
static int	stat(const char *__f, struct stat *__p) {
	return __stat32(__f, __p);
}
#if __cplusplus
 }
#endif /* __cplusplus */

#  else /* !__STDC__ */
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
static int	stat(__f, __p)
	char *__f;
	struct stat *__p;
{
	return __stat32(__f, __p);
}
#if __cplusplus
 }
#endif /* __cplusplus */
#endif
#endif  /* SCO_STATIC_FUNC_CHECK */


#if defined( ULTRIX_STAT_CHECK )
@(#)stat.h      6.1     (ULTRIX)
#define S_IFPORT S_IFIFO

/* macro to test for symbolic link */
#define S_ISLNK(mode) (((mode) & S_IFMT) == S_IFLNK)

	fstat(),
	lstat(),

#endif  /* ULTRIX_STAT_CHECK */


#if defined( VXWORKS_NEEDS_VXWORKS_CHECK )
#include </dev/null> /* ULONG */
# define	__INCstath <sys/stat.h>
#include <types/vxTypesOld.h>
#endif  /* VXWORKS_NEEDS_VXWORKS_CHECK */
