/* Copyright (C) 1993, 1995, 1996, 1997 Free Software Foundation, Inc.
   This file is part of the GNU IO Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

#include "libioP.h"
#include <errno.h>
/* ANSI explicitly requires setting errno to a positive value on failure. */

int
_IO_fgetpos (fp, posp)
     _IO_FILE* fp;
     _IO_fpos_t *posp;
{
  _IO_fpos_t pos;
  CHECK_FILE (fp, EOF);
  _IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile, fp);
  _IO_flockfile (fp);
  pos = _IO_seekoff (fp, 0, _IO_seek_cur, 0);
  _IO_cleanup_region_end (1);
  if (pos == _IO_pos_BAD)
    {
#ifdef EIO
      if (errno == 0)
	__set_errno (EIO);
#endif
      return EOF;
    }
  *posp = pos;
  return 0;
}

#ifdef weak_alias
weak_alias (_IO_fgetpos, fgetpos)
#endif
