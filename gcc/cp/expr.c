/* Convert language-specific tree expression to rtl instructions,
   for GNU compiler.
   Copyright (C) 1988-2017 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */


#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "cp-tree.h"

/* Expand C++-specific constants.  Currently, this means PTRMEM_CST.  */

tree
cplus_expand_constant (tree cst)
{
  switch (TREE_CODE (cst))
    {
    case PTRMEM_CST:
      {
	tree type = TREE_TYPE (cst);
	tree member;

	/* Find the member.  */
	member = PTRMEM_CST_MEMBER (cst);

	/* We can't lower this until the class is complete.  */
	if (!COMPLETE_TYPE_P (DECL_CONTEXT (member)))
	  return cst;

	if (TREE_CODE (member) == FIELD_DECL)
	  {
	    /* Find the offset for the field.  */
	    cst = byte_position (member);
	    while (!same_type_p (DECL_CONTEXT (member),
				 TYPE_PTRMEM_CLASS_TYPE (type)))
	      {
		/* The MEMBER must have been nestled within an
		   anonymous aggregate contained in TYPE.  Find the
		   anonymous aggregate.  */
		member = lookup_anon_field (TYPE_PTRMEM_CLASS_TYPE (type),
					    DECL_CONTEXT (member));
		cst = size_binop (PLUS_EXPR, cst, byte_position (member));
	      }
	    cst = fold (build_nop (type, cst));
	  }
	else
	  {
	    tree delta;
	    tree pfn;

	    expand_ptrmemfunc_cst (cst, &delta, &pfn);
	    cst = build_ptrmemfunc1 (type, delta, pfn);
	  }
      }
      break;

    case CONSTRUCTOR:
      {
	constructor_elt *elt;
	unsigned HOST_WIDE_INT idx;
	FOR_EACH_VEC_SAFE_ELT (CONSTRUCTOR_ELTS (cst), idx, elt)
	  elt->value = cplus_expand_constant (elt->value);
      }

    default:
      /* There's nothing to do.  */
      break;
    }

  return cst;
}

/* Called whenever the expression EXPR is used in an rvalue context.
   When REJECT_BUILTIN is true the expression is checked to make sure
   it doesn't make it possible to obtain the address of a GCC built-in
   function with no library fallback (or any of its bits, such as in
   a conversion to bool).  */
tree
mark_rvalue_use (tree expr,
		 location_t loc /* = UNKNOWN_LOCATION */,
		 bool reject_builtin /* = true */)
{
  if (reject_builtin && reject_gcc_builtin (expr, loc))
    return error_mark_node;

  mark_exp_read (expr);
  return expr;
}

/* Called whenever an expression is used in an lvalue context.  */

tree
mark_lvalue_use (tree expr)
{
  mark_exp_read (expr);
  return expr;
}

/* Called whenever an expression is used in a type use context.  */

tree
mark_type_use (tree expr)
{
  mark_exp_read (expr);
  return expr;
}

/* Mark EXP as read, not just set, for set but not used -Wunused
   warning purposes.  */

void
mark_exp_read (tree exp)
{
  if (exp == NULL)
    return;

  switch (TREE_CODE (exp))
    {
    case VAR_DECL:
    case PARM_DECL:
      DECL_READ_P (exp) = 1;
      break;
    case ARRAY_REF:
    case COMPONENT_REF:
    case MODIFY_EXPR:
    case REALPART_EXPR:
    case IMAGPART_EXPR:
    CASE_CONVERT:
    case ADDR_EXPR:
    case INDIRECT_REF:
    case FLOAT_EXPR:
    case NON_DEPENDENT_EXPR:
    case VIEW_CONVERT_EXPR:
      mark_exp_read (TREE_OPERAND (exp, 0));
      break;
    case COMPOUND_EXPR:
      mark_exp_read (TREE_OPERAND (exp, 1));
      break;
    case COND_EXPR:
      if (TREE_OPERAND (exp, 1))
	mark_exp_read (TREE_OPERAND (exp, 1));
      if (TREE_OPERAND (exp, 2))
	mark_exp_read (TREE_OPERAND (exp, 2));
      break;
    default:
      break;
    }
}

