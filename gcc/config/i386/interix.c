/* Subroutines for insn-output.c for Windows NT.
   Copyright (C) 1998, 1999, 2002 Free Software Foundation, Inc.

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
#include "system.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "output.h"
#include "tree.h"
#include "flags.h"

/* Return string which is the former assembler name modified with a 
   suffix consisting of an atsign (@) followed by the number of bytes of 
   arguments */

const char *
gen_stdcall_suffix (decl)
     tree decl;
{
  int total = 0;
  /* ??? This probably should use XSTR (XEXP (DECL_RTL (decl), 0), 0) instead
     of DECL_ASSEMBLER_NAME.  */
  const char *const asmname = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl));
  char *newsym;

  if (TYPE_ARG_TYPES (TREE_TYPE (decl)))
    if (TREE_VALUE (tree_last (TYPE_ARG_TYPES (TREE_TYPE (decl)))) 
        == void_type_node)
      {
	tree formal_type = TYPE_ARG_TYPES (TREE_TYPE (decl));

	while (TREE_VALUE (formal_type) != void_type_node)
	  {
	    int parm_size
	      = TREE_INT_CST_LOW (TYPE_SIZE (TREE_VALUE (formal_type)));
	    /* Must round up to include padding.  This is done the same
	       way as in store_one_arg.  */
	    parm_size = ((parm_size + PARM_BOUNDARY - 1)
			 / PARM_BOUNDARY * PARM_BOUNDARY);
	    total += parm_size;
	    formal_type = TREE_CHAIN (formal_type);
	  }
      }

  newsym = xmalloc (strlen (asmname) + 10);
  sprintf (newsym, "%s@%d", asmname, total/BITS_PER_UNIT);
  return IDENTIFIER_POINTER (get_identifier (newsym));
}

void
i386_interix_encode_section_info (decl, first)
     tree decl;
     int first;
{
  if (flag_pic)
    {
      rtx rtl = (TREE_CODE_CLASS (TREE_CODE (decl)) != 'd'
		 ? TREE_CST_RTL (decl) : DECL_RTL (decl));
      SYMBOL_REF_FLAG (XEXP (rtl, 0))
	= (TREE_CODE_CLASS (TREE_CODE (decl)) != 'd'
	   || ! TREE_PUBLIC (decl));
    }
  if (first && TREE_CODE (decl) == FUNCTION_DECL)
    if (lookup_attribute ("stdcall",
			  TYPE_ATTRIBUTES (TREE_TYPE (decl))))
      XEXP (DECL_RTL (decl), 0) =
	gen_rtx (SYMBOL_REF, Pmode, gen_stdcall_suffix (decl));
}

#if 0	
/* Turn this back on when the linker is updated to handle grouped
   .data$ sections correctly. See corresponding note in i386/interix.h. 
   MK.  */

/* Cover function for UNIQUE_SECTION.  */

void
i386_pe_unique_section (decl, reloc)
     tree decl;
     int reloc;
{
  int len;
  const char *name;
  char *string,*prefix;

  name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl));
  name = (* targetm.strip_name_encoding) (name);

  /* The object is put in, for example, section .text$foo.
     The linker will then ultimately place them in .text
     (everything from the $ on is stripped). Don't put
     read-only data in .rdata section to avoid a PE linker 
     bug when .rdata$* grouped sections are used in code
     without a .rdata section.  */
  if (TREE_CODE (decl) == FUNCTION_DECL)
    prefix = ".text$";
  else if (DECL_READONLY_SECTION (decl, reloc))
    prefix = ".rdata$";
  else
    prefix = ".data$";
  len = strlen (name) + strlen (prefix);
  string = alloca (len + 1);
  sprintf (string, "%s%s", prefix, name);

  DECL_SECTION_NAME (decl) = build_string (len, string);
}

#endif /* 0 */
