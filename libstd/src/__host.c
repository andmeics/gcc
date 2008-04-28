/*

   Copyright (C) 2007-2008 Free Software Foundation, Inc.
   Contributed by STMicroelectronics

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#if !defined OPT_MSCORLIB_WRAPPER

   /* If we are compiling this, we are sure this is to build C-runtime*/
#  define __LIBSTD_CRT_BUILD

#  include "include/__cdefs.h"

#  if defined(__GNU_CIL__)
#    error "__host.c : Sorry : Platform not supported"
#  endif

#endif


/* include __host before any target include to avoid errors
   generated by defines in them */
#include "include/__host.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>



static int my_errno = 0;

#define UPDATE_ERRNO() do { if (errno!=0) update_errno(); } while (0)

static void update_errno(void)
{
    switch (errno) {
    case 0:
        break;
#if defined ENOENT
    case ENOENT: my_errno = __LIBSTD_ENOENT; break;
#endif
#if defined EIO
    case EIO: my_errno = __LIBSTD_EIO; break;
#endif
#if defined EBADF
    case EBADF: my_errno = __LIBSTD_EBADF; break;
#endif
#if defined EAGAIN
    case EAGAIN:  my_errno = __LIBSTD_EAGAIN; break;
#endif
#if defined ENOMEM
    case ENOMEM:  my_errno = __LIBSTD_ENOMEM; break;
#endif
#if defined EACCES
    case EACCES: my_errno = __LIBSTD_EACCES; break;
#endif
#if defined EFAULT
    case EFAULT: my_errno = __LIBSTD_EFAULT; break;
#endif
#if defined EEXIST
    case EEXIST: my_errno = __LIBSTD_EEXIST; break;
#endif
#if defined ENOTDIR
    case ENOTDIR: my_errno = __LIBSTD_ENOTDIR; break;
#endif
#if defined EINVAL
    case EINVAL: my_errno = __LIBSTD_EINVAL; break;
#endif
#if defined EMFILE
    case EMFILE: my_errno = __LIBSTD_EMFILE; break;
#endif
#if defined ESPIPE
    case ESPIPE: my_errno = __LIBSTD_ESPIPE; break;
#endif
#if defined EDOM
    case EDOM: my_errno = __LIBSTD_EDOM; break;
#endif
#if defined ERANGE
    case ERANGE: my_errno = __LIBSTD_ERANGE; break;
#endif
#if defined ENAMETOOLONG
    case ENAMETOOLONG: my_errno = __LIBSTD_ENAMETOOLONG; break;
#endif
#if defined EILSEQ
    case EILSEQ: my_errno = __LIBSTD_EILSEQ; break;
#endif
#if defined ENOSYS
    case ENOSYS:
#endif
    default:
        my_errno = __LIBSTD_ENOSYS;
        break;
    }
}

LIBSTD_HPROTO_IMPL(void *, malloc, unsigned int size)
{
    void *result = malloc((size_t)size);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(void *, realloc, void *ptr, unsigned int size)
{
    void *result = realloc(ptr, (size_t)size);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(void, free, void *ptr)
{
    free(ptr);
}

LIBSTD_HPROTO_IMPL(char *, getenv, char *name)
{
    return getenv(name);
}

/* Close a file descriptor. */
LIBSTD_HPROTO_IMPL(int, close, int fildes)
{
    int result;
    result = close(fildes);
    UPDATE_ERRNO();
    return result;
}

/* Return file size. */
LIBSTD_HPROTO_IMPL(int, filesize, char* path)
{
    int result;
    struct stat s;
    if (stat(path, &s) == 0)
        result = s.st_size;
    else {
        UPDATE_ERRNO();
        result = -1;
    }
    return result;
}

/* Called when process exit, to signal IOs _cleanup to host. */
LIBSTD_HPROTO_IMPL(void, exit, int status)
{
    exit(status);
}

/* Control over an open file descriptor.*/
LIBSTD_HPROTO_IMPL(int, fcntl, int fildes, int cmd, int arg)
{
    long result;
    result = fcntl(fildes, cmd, arg);
    UPDATE_ERRNO();
    return result;
}

/* Manages file pointers.  */
LIBSTD_HPROTO_IMPL(long, lseek, int fildes, long offset, int whence)
{
    long result;
    result = lseek(fildes, offset, whence);
    UPDATE_ERRNO();
    return result;
}

/* Create a directory entry.  */
LIBSTD_HPROTO_IMPL(int, link, char *existing, char *anew)
{
    int result;
    result = link(existing, anew);
    UPDATE_ERRNO();
    return result;
}


/* Opens a file descriptor on a file.
   oflags is oneof : O_RDONLY (0), O_WRONLY (1), O_RDWR (2)*/
LIBSTD_HPROTO_IMPL(int, open, char *path, int oflag)
{
    int result;
    int host_flags = 0;

    if ((oflag & __LIBSTD_O_WRONLY) != 0) {
        host_flags |= O_WRONLY;
    }
    if ((oflag & __LIBSTD_O_RDWR) != 0) {
        host_flags |= O_RDWR;
    }
    if ((oflag & __LIBSTD_O_RDONLY) != 0) {
        host_flags |= O_RDONLY;
    }
    if ((oflag & __LIBSTD_O_CREAT) != 0) {
        host_flags |= O_CREAT;
/*         host_flag = host_flag | 0x0040; */
    }
    if ((oflag & __LIBSTD_O_TRUNC) != 0) {
        host_flags |= O_TRUNC;
    }
    if ((oflag & __LIBSTD_O_APPEND) != 0) {
        host_flags |= O_APPEND;
/*         host_flag = host_flag | 0x0400; */
    }
    if ((oflag & __LIBSTD_O_BINARY) != 0) {
#if defined O_BINARY
        host_flags |= O_BINARY;
#endif
    }

    result = open(path, host_flags, 0666);
    UPDATE_ERRNO();
    return result;
}

/* Attempts to read bytes from stream.  */
LIBSTD_HPROTO_IMPL(int, read, int fildes, void *buf, int nbytes)
{
    int result;
    result = read(fildes, buf, nbytes);
    UPDATE_ERRNO();
    return result;
}

/* Renames a file. */
LIBSTD_HPROTO_IMPL(int, rename, char *oldname, char *newname)
{
    int result;
    result = rename(oldname, newname);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(int, remove, char *filename)
{
    int result;
    result = remove(filename);
    UPDATE_ERRNO();
    return result;
}

/* Removes a directory entry.  */
LIBSTD_HPROTO_IMPL(int, unlink, char *path)
{
    int result;
    result = unlink(path);
    UPDATE_ERRNO();
    return result;
}

/* Attempts to write bytes into stream.    */
LIBSTD_HPROTO_IMPL(int, write, int fildes, void *buf, int nbytes)
{
    int result;
    result = write(fildes, buf, nbytes);
    UPDATE_ERRNO();
    return result;
}

/* Getting host montime */
LIBSTD_HPROTO_IMPL(int, clock, void)
{
    int __host__clock_ = -1 ;
#if defined(__ST40)
    struct tms temp;
    times(&temp);
    __host__clock_ = temp.tms_utime + temp.tms_stime;
#else
    __host__clock_ = clock();
#endif
    return __host__clock_ ;
}

LIBSTD_HPROTO_IMPL(unsigned long, time, void *tptr)
{
    unsigned long *l_tptr = (unsigned long *)tptr;
    return time(l_tptr);
}

LIBSTD_HPROTO_IMPL(void, gmtime, void *timer,
                         int *tm_sec,  int *tm_min,  int *tm_hour,
                         int *tm_mday, int *tm_mon,  int *tm_year,
                         int *tm_wday, int *tm_yday, int *tm_isdst)
{
    const unsigned long *l_timer = (const unsigned long *)timer;
    struct tm * _tm = gmtime(l_timer);
    *tm_sec   = _tm->tm_sec;
    *tm_min   = _tm->tm_min;
    *tm_hour  = _tm->tm_hour;
    *tm_mday  = _tm->tm_mday;
    *tm_mon   = _tm->tm_mon;
    *tm_year  = _tm->tm_year;
    *tm_wday  = _tm->tm_wday;
    *tm_yday  = _tm->tm_yday;
    *tm_isdst = _tm->tm_isdst;
}

LIBSTD_HPROTO_IMPL(int, fpclassify, double p0)
{
    return fpclassify(p0);
}

LIBSTD_HPROTO_IMPL(double, dbl_epsilon, void)
{
    return DBL_EPSILON;
}

LIBSTD_HPROTO_IMPL(double, dbl_minval, void)
{
    return DBL_MIN;
}

LIBSTD_HPROTO_IMPL(double, dbl_maxval, void)
{
    return DBL_MAX;
}

LIBSTD_HPROTO_IMPL(double, dbl_hugeval, void)
{
    return HUGE_VAL;
}

LIBSTD_HPROTO_IMPL(float, flt_epsilon, void)
{
    return FLT_EPSILON;
}

LIBSTD_HPROTO_IMPL(float, flt_minval, void)
{
    return FLT_MIN;
}

LIBSTD_HPROTO_IMPL(float, flt_maxval, void)
{
    return FLT_MAX;
}

LIBSTD_HPROTO_IMPL(float, flt_hugeval, void)
{
    return HUGE_VALF;
}

LIBSTD_HPROTO_IMPL(float, flt_nan, void)
{
    return NAN;
}

LIBSTD_HPROTO_IMPL(float, flt_infinity, void)
{
    return INFINITY;
}

/*************************************************************************************************/
/*************** MATH FUNCTIONS ******************************************************************/
/*************************************************************************************************/
LIBSTD_HPROTO_IMPL(double, acos, double p0)
{
    return acos(p0);
}

LIBSTD_HPROTO_IMPL(float, acosf, float p0)
{
    return acosf(p0);
}

LIBSTD_HPROTO_IMPL(double, asin, double p0)
{
    return asin(p0);
}

LIBSTD_HPROTO_IMPL(float, asinf, float p0)
{
    return asinf(p0);
}

LIBSTD_HPROTO_IMPL(double, atan, double p0)
{
    return atan(p0);
}

LIBSTD_HPROTO_IMPL(float, atanf, float p0)
{
    return atanf(p0);
}

LIBSTD_HPROTO_IMPL(double, atan2, double p0, double p1)
{
    return atan2(p0, p1);
}

LIBSTD_HPROTO_IMPL(float, atan2f, float p0, float p1)
{
    return atan2f(p0, p1);
}

LIBSTD_HPROTO_IMPL(double, cos, double p0)
{
    return cos(p0);
}

LIBSTD_HPROTO_IMPL(float, cosf, float p0)
{
    return cosf(p0);
}

LIBSTD_HPROTO_IMPL(double, sin, double p0)
{
    return sin(p0);
}

LIBSTD_HPROTO_IMPL(float, sinf, float p0)
{
    return sinf(p0);
}

LIBSTD_HPROTO_IMPL(double, tan, double p0)
{
    return tan(p0);
}

LIBSTD_HPROTO_IMPL(float, tanf, float p0)
{
    return tanf(p0);
}

LIBSTD_HPROTO_IMPL(double, cosh, double p0)
{
    return cosh(p0);
}

LIBSTD_HPROTO_IMPL(float, coshf, float p0)
{
    return coshf(p0);
}

LIBSTD_HPROTO_IMPL(double, sinh, double p0)
{
    return sinh(p0);
}

LIBSTD_HPROTO_IMPL(float, sinhf, float p0)
{
    return sinhf(p0);
}

LIBSTD_HPROTO_IMPL(double, tanh, double p0)
{
    return tanh(p0);
}

LIBSTD_HPROTO_IMPL(float, tanhf, float p0)
{
    return tanhf(p0);
}

LIBSTD_HPROTO_IMPL(double, exp, double p0)
{
    return exp(p0);
}

LIBSTD_HPROTO_IMPL(float, expf, float p0)
{
    return expf(p0);
}

LIBSTD_HPROTO_IMPL(double, exp2, double p0)
{
    return exp2(p0);
}

LIBSTD_HPROTO_IMPL(float, exp2f, float p0)
{
    return exp2f(p0);
}

LIBSTD_HPROTO_IMPL(double, expm1, double p0)
{
    return expm1(p0);
}

LIBSTD_HPROTO_IMPL(float, expm1f, float p0)
{
    return expm1f(p0);
}

LIBSTD_HPROTO_IMPL(double, log, double p0)
{
    return log(p0);
}

LIBSTD_HPROTO_IMPL(float, logf, float p0)
{
    return logf(p0);
}

LIBSTD_HPROTO_IMPL(double, log10, double p0)
{
    return log10(p0);
}

LIBSTD_HPROTO_IMPL(float, log10f, float p0)
{
    return log10f(p0);
}

LIBSTD_HPROTO_IMPL(double, log1p, double p0)
{
    return log1p(p0);
}

LIBSTD_HPROTO_IMPL(float, log1pf, float p0)
{
    return log1pf(p0);
}

LIBSTD_HPROTO_IMPL(double, log2, double p0)
{
    return log2(p0);
}

LIBSTD_HPROTO_IMPL(float, log2f, float p0)
{
    return log2f(p0);
}


LIBSTD_HPROTO_IMPL(double, cbrt, double p0)
{
    return cbrt(p0);
}

LIBSTD_HPROTO_IMPL(float, cbrtf, float p0)
{
    return cbrtf(p0);
}

LIBSTD_HPROTO_IMPL(double, fabs, double p0)
{
    return fabs(p0);
}

LIBSTD_HPROTO_IMPL(float, fabsf, float p0)
{
    return fabsf(p0);
}

LIBSTD_HPROTO_IMPL(double, pow, double p0, double p1)
{
    return pow(p0,p1);
}

LIBSTD_HPROTO_IMPL(float, powf, float p0, float p1)
{
    return powf(p0,p1);
}

LIBSTD_HPROTO_IMPL(double, sqrt, double p0)
{
    return sqrt(p0);
}

LIBSTD_HPROTO_IMPL(float, sqrtf, float p0)
{
    return sqrtf(p0);
}

LIBSTD_HPROTO_IMPL(double, ceil, double p0)
{
    return ceil(p0);
}

LIBSTD_HPROTO_IMPL(float, ceilf, float p0)
{
    return ceilf(p0);
}

LIBSTD_HPROTO_IMPL(double, floor, double p0)
{
    return floor(p0);
}

LIBSTD_HPROTO_IMPL(float, floorf, float p0)
{
    return floorf(p0);
}

LIBSTD_HPROTO_IMPL(long, lround, double p0)
{
    return lround(p0);
}

LIBSTD_HPROTO_IMPL(long, lroundf, float p0)
{
    return lroundf(p0);
}

LIBSTD_HPROTO_IMPL(double, ldexp, double p0, int p1)
{
    double result = ldexp(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(float, ldexpf, float p0, int p1)
{
    float result = ldexpf(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(double, hypot, double p0, double p1)
{
    double result = hypot(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(float, hypotf, float p0, float p1)
{
    float result = hypotf(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(double, scalbn, double p0, int p1)
{
    double result = scalbn(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(float, scalbnf, float p0, int p1)
{
    float result = scalbnf(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(double, scalbln, double p0, long p1)
{
    double result = scalbln(p0,p1);
    UPDATE_ERRNO();
    return result;
}

LIBSTD_HPROTO_IMPL(float, scalblnf, float p0, long p1)
{
    float result = scalblnf(p0,p1);
    UPDATE_ERRNO();
    return result;
}

/* ensure the prototype is defined correctly */
#if defined(errno)
#undef errno
#endif
LIBSTD_HPROTO_IMPL(int *, errno, void)
{
    return &my_errno;
}
