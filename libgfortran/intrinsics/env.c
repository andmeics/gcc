/* Implementation of the GETENV g77, and
   GET_ENVIRONMENT_VARIABLE F2003, intrinsics. 
   Copyright (C) 2004 Free Software Foundation, Inc.
   Contributed by Janne Blomqvist.

This file is part of the GNU Fortran 95 runtime library (libgfortran).

Libgfortran is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

Libgfortran is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with libgfor; see the file COPYING.LIB.  If not,
write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "config.h"
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "libgfortran.h"


/* GETENV (NAME, VALUE), g77 intrinsic for retrieving the value of
 an environment variable. The name of the variable is specified in
 NAME, and the result is stored into VALUE.  */

void 
prefix(getenv) (char * name, 
		char * value, 
		gfc_strlen_type name_len, 
		gfc_strlen_type value_len)
{

  /* Make a null-terminated copy of the name string so that c library
     functions work correctly.  This is a C99 VLA, which ought to be
     faster than malloc and free.  */

  char name_nt[name_len+1];

  char *res = NULL;
  int res_len;

  if (name == NULL || value == NULL)
    runtime_error ("Both arguments to getenv are mandatory.");

  if (value_len < 1 || name_len < 1)
    runtime_error ("Zero length string(s) passed to getenv.");
  else
    memset (value, ' ', value_len); /* Blank the string.  */

  memcpy (name_nt, name, name_len);
  memset (&name_nt[name_len], '\0', 1); 

  res = getenv(name_nt);

  /* If res is NULL, it means that the environment variable didn't 
     exist, so just return.  */
  if (res == NULL)
    return;

  res_len = strlen(res);
  if (value_len < res_len)
    memcpy (value, res, value_len);
  else
    memcpy (value, res, res_len);
}


/* GET_ENVIRONMENT_VARIABLE (name, [value, length, status, trim_name])
   is a F2003 intrinsic for getting an environment variable.  Note that as
   Un*x doesn't consider trailing blanks in environment variables to be
   significant, the trim_name argument has no meaning.  */

/* Status codes specifyed by the standard. */
#define GFC_SUCCESS 0
#define GFC_VALUE_TOO_SHORT -1
#define GFC_NAME_DOES_NOT_EXIST 1

/* This is also specified by the standard and means that the
   processor doesn't support environment variables.  At the moment,
   gfortran doesn't use it.  */
#define GFC_NOT_SUPPORTED 2

/* Processor-specific failure code.  */
#define GFC_FAILURE 42

void
prefix(get_environment_variable_i4) 
  (
   char *name,
   char *value,
   GFC_INTEGER_4 *length,
   GFC_INTEGER_4 *status,
   GFC_LOGICAL_4 *trim_name,
   gfc_strlen_type name_len,
   gfc_strlen_type value_len)
{
  int stat = GFC_SUCCESS, res_len = 0;
  char name_nt[name_len+1], *res;

  if (name == NULL)
    runtime_error ("Name is required for get_environment_variable.");

  if (value == NULL && length == NULL && status == NULL && trim_name == NULL)
    return;

  if (name_len < 1)
    runtime_error ("Zero-length string passed as name to "
		   "get_environment_variable.");

  if (value != NULL)
    { 
      if (value_len < 1)
	runtime_error ("Zero-length string passed as value to "
		       "get_environment_variable.");
      else
	memset (value, ' ', value_len); /* Blank the string.  */
    }

  memcpy (name_nt, name, name_len);
  memset (&name_nt[name_len], '\0', 1); 
  
  res = getenv(name_nt);

  if (res == NULL)
    stat = GFC_NAME_DOES_NOT_EXIST;
  else
    {
      res_len = strlen(res);
      if (value != NULL)
	{
	  if (value_len < res_len)
	    {
	      memcpy (value, res, value_len);
	      stat = GFC_VALUE_TOO_SHORT;
	    }
	  else
	    memcpy (value, res, res_len);
	}
    }

  if (status != NULL)
    *status = stat;

  if (length != NULL)
    *length = res_len;
}


/* INTEGER*8 wrapper for get_environment_variable.  */

void
prefix(get_environment_variable_i8)
  (
   char *name,
   char *value,
   GFC_INTEGER_8 *length,
   GFC_INTEGER_8 *status,
   GFC_LOGICAL_8 *trim_name,
   gfc_strlen_type name_len,
   gfc_strlen_type value_len)
{
  GFC_INTEGER_4 length4, status4;
  GFC_LOGICAL_4 trim_name4;

  prefix (get_environment_variable_i4) (name, value, &length4, &status4, 
					&trim_name4, name_len, value_len);

  if (length)
    *length = length4;

  if (status)
    *status = status4;
}
