
/* Install modified versions of certain ANSI-incompatible system header
   files which are fixed to work correctly with ANSI C and placed in a
   directory that GNU C will search.

   Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef FIXINCLUDES_FIXLIB_H
#define FIXINCLUDES_FIXLIB_H

#include "auto-host.h"
#include "gansidecl.h"
#include "system.h"

#include "regex.h"
#include "machname.h"

#ifndef STDIN_FILENO
# define STDIN_FILENO   0
#endif
#ifndef STDOUT_FILENO
# define STDOUT_FILENO  1
#endif

typedef int t_success;

#define FAILURE         (-1)
#define SUCCESS           0
#define PROBLEM           1

#define SUCCEEDED(p)    ((p) == SUCCESS)
#define SUCCESSFUL(p)   SUCCEEDED (p)
#define FAILED(p)       ((p) < SUCCESS)
#define HADGLITCH(p)    ((p) > SUCCESS)


#define tSCC static const char
#define tCC  const char
#define tSC  static char

/* If this particular system's header files define the macro `MAXPATHLEN',
   we happily take advantage of it; otherwise we use a value which ought
   to be large enough.  */
#ifndef MAXPATHLEN
# define MAXPATHLEN     4096
#endif

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

#define NUL             '\0'

#ifndef NOPROCESS
#define NOPROCESS	((pid_t) -1)
#define NULLPROCESS	((pid_t)0)

#define EXIT_PANIC	99

#ifndef HAVE_T_BOOL_ENUM
#define HAVE_T_BOOL_ENUM
typedef enum
{
  BOOL_FALSE, BOOL_TRUE
} t_bool;
#endif

typedef int apply_fix_p_t;  /* Apply Fix Predicate Type */

#define APPLY_FIX 0
#define SKIP_FIX  1

#define _P_(p)	()
#endif

/*  Test Descriptor

    Each fix may have associated tests that determine
    whether the fix needs to be applied or not.
    Each test has a type (from the te_test_type enumeration);
    associated test text; and, if the test is TT_EGREP or
    the negated form TT_NEGREP, a pointer to the compiled
    version of the text string.

    */
typedef enum
{
  TT_TEST, TT_EGREP, TT_NEGREP, TT_FUNCTION
} te_test_type;

typedef struct test_desc tTestDesc;

struct test_desc
{
  te_test_type type;
  const char *pz_test_text;
  regex_t *p_test_regex;
};

typedef struct patch_desc tPatchDesc;

/*  Fix Descriptor

    Everything you ever wanted to know about how to apply
    a particular fix (which files, how to qualify them,
    how to actually make the fix, etc...)

    NB:  the FD_ defines are BIT FLAGS

    */
#define FD_MACH_ONLY      0x0000
#define FD_MACH_IFNOT     0x0001
#define FD_SHELL_SCRIPT   0x0002
#define FD_SUBROUTINE     0x0004
#define FD_REPLACEMENT    0x0008
#define FD_SKIP_TEST      0x8000

typedef struct fix_desc tFixDesc;
struct fix_desc
{
  tCC*        fix_name;       /* Name of the fix */
  tCC*        file_list;      /* List of files it applies to */
  tCC**       papz_machs;     /* List of machine/os-es it applies to */
  int         test_ct;
  int         fd_flags;
  tTestDesc*  p_test_desc;
  tCC**       patch_args;
  long        unused;
};

/*
 *  Exported procedures
 */
char * load_file_data _P_(( FILE* fp ));
t_bool is_cxx_header  _P_(( tCC* filename, tCC* filetext ));
void   compile_re     _P_(( tCC* pat, regex_t* re, int match,
			    tCC *e1, tCC *e2 ));
void*  must_malloc    _P_(( size_t ));

void apply_fix _P_(( tFixDesc* p_fixd, tCC* filname ));
apply_fix_p_t run_test _P_((tCC* t_name, tCC* f_name, tCC* text ));

#ifdef MN_NAME_PAT
void   mn_get_regexps _P_(( regex_t** label_re, regex_t** name_re,
			    tCC *who ));
#endif
#endif /* FIXINCLUDES_FIXLIB_H */
