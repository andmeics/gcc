/* Specific flags and argument handling of the Fortran front-end.
   Copyright (C) 1997 Free Software Foundation, Inc.

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

#include "config.h"

#include <sys/types.h>
#include <stdio.h>

#include "gansidecl.h"

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

/* This bit is set if we saw a `-xfoo' language specification.  */
#define LANGSPEC	(1<<1)
/* This bit is set if they did `-lm' or `-lmath'.  */
#define MATHLIB		(1<<2)
/* This bit is set if they did `-lc'.  */
#define WITHLIBC	(1<<3)

#ifndef MATH_LIBRARY
#define MATH_LIBRARY "-lm"
#endif

#ifndef FORTRAN_LIBRARY
#define FORTRAN_LIBRARY "-lf2c"
#endif

extern char *xmalloc PROTO((size_t));

void
lang_specific_driver (fn, in_argc, in_argv)
     void (*fn)();
     int *in_argc;
     char ***in_argv;
{
  int i, j;

  /* If non-zero, the user gave us the `-v' flag.  */ 
  int saw_verbose_flag = 0;

  /* This will be 0 if we encounter a situation where we should not
     link in libstdf77.  */
  int library = 1;

  /* The number of arguments being added to what's in argv, other than
     libraries.  We use this to track the number of times we've inserted
     -xf77/-xnone.  */
  int added = 2;

  /* Used to track options that take arguments, so we don't go wrapping
     those with -xf77/-xnone.  */
  char *quote = NULL;

  /* The new argument list will be contained in this.  */
  char **arglist;

  /* Non-zero if we saw a `-xfoo' language specification on the
     command line.  Used to avoid adding our own -xf77 if the user
     already gave a language for the file.  */
  int saw_speclang = 0;

  /* "-lm" or "-lmath" if it appears on the command line.  */
  char *saw_math = 0;

  /* "-lc" if it appears on the command line.  */
  char *saw_libc = 0;

  /* An array used to flag each argument that needs a bit set for
     LANGSPEC, MATHLIB, or WITHLIBC.  */
  int *args;

  /* By default, we throw on the math library.  */
  int need_math = 1;

  /* The total number of arguments with the new stuff.  */
  int argc;

  /* The argument list.  */
  char **argv;

  /* The total number of arguments with the new stuff.  */
  int num_args = 1;

  argc = *in_argc;
  argv = *in_argv;

  args = (int *) xmalloc (argc * sizeof (int));
  bzero ((char *) args, argc * sizeof (int));

  for (i = 1; i < argc; i++)
    {
      /* If the previous option took an argument, we swallow it here.  */
      if (quote)
	{
	  quote = NULL;
	  continue;
	}

      /* We don't do this anymore, since we don't get them with minus
	 signs on them.  */
      if (argv[i][0] == '\0' || argv[i][1] == '\0')
	continue;

      if (argv[i][0] == '-')
	{
	  if (library != 0 && (strcmp (argv[i], "-nostdlib") == 0
			       || strcmp (argv[i], "-nodefaultlibs") == 0))
	    {
	      library = 0;
	    }
	  else if (strcmp (argv[i], "-lm") == 0
		   || strcmp (argv[i], "-lmath") == 0
#ifdef ALT_LIBM
		   || strcmp (argv[i], ALT_LIBM) == 0
#endif
		  )
	    {
	      args[i] |= MATHLIB;
	      need_math = 0;
	    }
	  else if (strcmp (argv[i], "-lc") == 0)
	    args[i] |= WITHLIBC;
	  else if (strcmp (argv[i], "-v") == 0)
	    {
	      saw_verbose_flag = 1;
	      if (argc == 2)
		{
		  /* If they only gave us `-v', don't try to link in libf2c. */ 
		  library = 0;
		}
	    }
	  else if (strncmp (argv[i], "-x", 2) == 0)
	    saw_speclang = 1;
	  else if (((argv[i][2] == '\0'
		     && (char *)strchr ("bBVDUoeTuIYmLiA", argv[i][1]) != NULL)
		    || strcmp (argv[i], "-Tdata") == 0))
	    quote = argv[i];
	  else if (library != 0 && ((argv[i][2] == '\0'
		     && (char *) strchr ("cSEM", argv[i][1]) != NULL)
		    || strcmp (argv[i], "-MM") == 0))
	    {
	      /* Don't specify libraries if we won't link, since that would
		 cause a warning.  */
	      library = 0;
	      added -= 2;
	    }
	  else
	    /* Pass other options through.  */
	    continue;
	}
      else
	{
	  int len; 

	  if (saw_speclang)
	    {
	      saw_speclang = 0;
	      continue;
	    }

	  /* If the filename ends in .c or .i, put options around it.
	     But not if a specified -x option is currently active.  */
	  len = strlen (argv[i]);
	  if (len > 2
	      && (argv[i][len - 1] == 'c' || argv[i][len - 1] == 'i')
	      && argv[i][len - 2] == '.')
	    {
	      args[i] |= LANGSPEC;
	      added += 2;
	    }
	}
    }

  if (quote)
    (*fn) ("argument to `%s' missing\n", quote);

  /* If we know we don't have to do anything, bail now.  */
  if (! added && ! library)
    {
      free (args);
      return;
    }

  num_args = argc + added + need_math;
  arglist = (char **) xmalloc (num_args * sizeof (char *));

  /* NOTE: We start at 1 now, not 0.  */
  for (i = 0, j = 0; i < argc; i++, j++)
    {
      arglist[j] = argv[i];

      /* Make sure -lf2c is before the math library, since libf2c
	 itself uses those math routines.  */
      if (!saw_math && (args[i] & MATHLIB) && library)
	{
	  --j;
	  saw_math = argv[i];
	}

      if (!saw_libc && (args[i] & WITHLIBC) && library)
	{
	  --j;
	  saw_libc = argv[i];
	}

      /* Wrap foo.c and foo.i files in a language specification to
	 force the gcc compiler driver to run cc1plus on them.  */
      if (args[i] & LANGSPEC)
	{
	  int len = strlen (argv[i]);
	  switch (argv[i][len - 1])
	    {
	    case 'F':
	      arglist[j++] = "-xf77-cpp-input";
	      break;
	    case 'r':
	      /* Don't do ratfor for ".for".  */
	      if (argv[i][len - 2] == '.')
		{
		  arglist[j++] = "-xratfor";
		  break;
		}
	    default:
	      arglist[j++] = "-xf77";
	      break;
	    }
	  arglist[j++] = argv[i];
	  arglist[j] = "-xnone";
	}
  }

  /* Add `-lf2c' if we haven't already done so.  */
  if (library)
    arglist[j++] = FORTRAN_LIBRARY;
  if (saw_math)
    arglist[j++] = saw_math;
  else if (library)
    arglist[j++] = MATH_LIBRARY;
  if (saw_libc)
    arglist[j++] = saw_libc;

  arglist[j] = NULL;

  *in_argc = j;
  *in_argv = arglist;
}
