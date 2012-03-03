/* Folding of trees in SSA form.
   Copyright (C) 2004, 2005, 2007, 2008, 2009, 2010, 2011
   Free Software Foundation, Inc.

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
#include "tm.h"
#include "tree.h"
#include "tm_p.h"
#include "basic-block.h"
#include "timevar.h"
#include "gimple-pretty-print.h"
#include "tree-flow.h"
#include "tree-pass.h"
#include "tree-dump.h"
#include "langhooks.h"
#include "flags.h"
#include "gimple.h"
#include "expr.h"
#include "tree-ssa-propagate.h"


static inline void defcodefor_name_3 (tree name, enum tree_code *code,
				      tree *arg1, tree *arg2, tree *arg3);
#define defcodefor_name(n,c,a1,a2)  defcodefor_name_3(n,c,a1,a2,NULL)

/* Generate a mask for the TYPE.  */
static double_int
mask_for_type (tree type)
{
  int width;
  if (type == NULL_TREE)
    return double_int_minus_one;
  width = TYPE_PRECISION (type);

  if (TREE_CODE (type) == VECTOR_TYPE)
    width = TYPE_VECTOR_SUBPARTS (type) * TYPE_PRECISION (TREE_TYPE (type));
  else if (TREE_CODE (type) == COMPLEX_TYPE)
    width = TYPE_PRECISION (TREE_TYPE (type)) * 2;
  
  return double_int_mask (width);
}

/* Implement a simple nonzero function. Most of the work is done
   in nonzerobits_1. */
static double_int
gimple_default_nonzero_bits (tree val)
{
  tree type;
  if (val == NULL_TREE)
    return double_int_minus_one;
  type = TREE_TYPE (val);
  return mask_for_type (type);
}

/* Get the statement we can propagate from into NAME skipping
   trivial copies.  Returns the statement which defines the
   propagation source or NULL_TREE if there is no such one.
   If SINGLE_USE_ONLY is set considers only sources which have
   a single use chain up to NAME.  If SINGLE_USE_P is non-null,
   it is set to whether the chain to NAME is a single use chain
   or not.  SINGLE_USE_P is not written to if SINGLE_USE_ONLY is set.  */

static gimple
get_prop_source_stmt (tree name, bool single_use_only, bool *single_use_p)
{
  bool single_use = true;

  do {
    gimple def_stmt = SSA_NAME_DEF_STMT (name);

    if (!has_single_use (name))
      {
	single_use = false;
	if (single_use_only)
	  return NULL;
      }

    /* If name is defined by a PHI node or is the default def, bail out.  */
    if (!is_gimple_assign (def_stmt))
      return NULL;

    /* If def_stmt is not a simple copy, we possibly found it.  */
    if (!gimple_assign_ssa_name_copy_p (def_stmt))
      {
	tree rhs;

	if (!single_use_only && single_use_p)
	  *single_use_p = single_use;

	/* We can look through pointer conversions in the search
	   for a useful stmt for the comparison folding.  */
	rhs = gimple_assign_rhs1 (def_stmt);
	if (CONVERT_EXPR_CODE_P (gimple_assign_rhs_code (def_stmt))
	    && TREE_CODE (rhs) == SSA_NAME
	    && POINTER_TYPE_P (TREE_TYPE (gimple_assign_lhs (def_stmt)))
	    && POINTER_TYPE_P (TREE_TYPE (rhs)))
	  name = rhs;
	else
	  return def_stmt;
      }
    else
      {
	/* Continue searching the def of the copy source name.  */
	name = gimple_assign_rhs1 (def_stmt);
      }
  } while (1);
}

/* Checks if the destination ssa name in DEF_STMT can be used as
   propagation source.  Returns true if so, otherwise false.  */

static bool
can_propagate_from (gimple def_stmt)
{
  gcc_assert (is_gimple_assign (def_stmt));

  /* If the rhs has side-effects we cannot propagate from it.  */
  if (gimple_has_volatile_ops (def_stmt))
    return false;

  /* If the rhs is a load we cannot propagate from it.  */
  if (TREE_CODE_CLASS (gimple_assign_rhs_code (def_stmt)) == tcc_reference
      || TREE_CODE_CLASS (gimple_assign_rhs_code (def_stmt)) == tcc_declaration)
    return false;

  /* Constants can be always propagated.  */
  if (gimple_assign_single_p (def_stmt)
      && is_gimple_min_invariant (gimple_assign_rhs1 (def_stmt)))
    return true;

  /* We cannot propagate ssa names that occur in abnormal phi nodes.  */
  if (stmt_references_abnormal_ssa_name (def_stmt))
    return false;

  /* If the definition is a conversion of a pointer to a function type,
     then we can not apply optimizations as some targets require
     function pointers to be canonicalized and in this case this
     optimization could eliminate a necessary canonicalization.  */
  if (CONVERT_EXPR_CODE_P (gimple_assign_rhs_code (def_stmt)))
    {
      tree rhs = gimple_assign_rhs1 (def_stmt);
      if (POINTER_TYPE_P (TREE_TYPE (rhs))
          && TREE_CODE (TREE_TYPE (TREE_TYPE (rhs))) == FUNCTION_TYPE)
        return false;
    }

  return true;
}

static nonzerobits_t nonzerobitsf = gimple_default_nonzero_bits;
static valueizer_t valueizerv = NULL;

static tree
valueizerf (tree val)
{
  tree name;
  gimple def_stmt;

  if (valueizerv)
    val = valueizerv (val);

  if (TREE_CODE (val) != SSA_NAME)
    return val;

  name = val;

  do {
    def_stmt = SSA_NAME_DEF_STMT (name);

    /* If name is defined by a PHI node or is the default def, bail out.  */
    if (!is_gimple_assign (def_stmt))
      {
	if (!SSA_NAME_OCCURS_IN_ABNORMAL_PHI (name))
	  return name;
	return val;
      }

    /* If def_stmt is not a simple copy, we possibly found it.  */
    if (!gimple_assign_ssa_name_copy_p (def_stmt))
      break;
    else
      /* Continue searching the def of the copy source name.  */
      name = gimple_assign_rhs1 (def_stmt);
  } while (1);
  
  /* If we got a constant, return that constant. */
  if (gimple_assign_single_p (def_stmt)
      && is_gimple_min_invariant (gimple_assign_rhs1 (def_stmt)))
    return gimple_assign_rhs1 (def_stmt);

  /* If got a name that occurs in an abnormal phi, ignore it. */
  if (SSA_NAME_OCCURS_IN_ABNORMAL_PHI (name))
    return val;

  return name;
}
/* Set the nonzerbits hook to NONZEROBITSP. */
void
gimple_combine_set_nonzerobits (nonzerobits_t nonzerobitsp)
{
  /* NULL means set it to the default one. */
  if (nonzerobitsp == NULL)
    nonzerobitsp = gimple_default_nonzero_bits;
  nonzerobitsf = nonzerobitsp;
}

void
gimple_combine_set_valueizer (valueizer_t valueizerp)
{
  valueizerv = valueizerp;
}

static tree
gimple_combine_build2 (location_t loc, enum tree_code code,
		       tree type, tree arg1, tree arg2)
{
  tree tem;
  if (commutative_tree_code (code)
      && tree_swap_operands_p (arg1, arg2, true))
    {
      tree t = arg1;
      arg1 = arg2;
      arg2 = t;
    }

  tem = gimple_combine_binary (loc, code, type, arg1, arg2);
  if (tem)
    return tem;
  return build2_loc (loc, code, type, arg1, arg2);
}

static tree
gimple_combine_build3 (location_t loc, enum tree_code code,
		       tree type, tree arg1, tree arg2, tree arg3)
{
  tree tem;

  tem = gimple_combine_ternary (loc, code, type, arg1, arg2, arg3);
  if (tem)
    return tem;
  return build3_loc (loc, code, type, arg1, arg2, arg3);
}

static tree
gimple_combine_build1 (location_t loc, enum tree_code code,
		       tree type, tree arg1)
{
  tree tem;

  /* Convert (bool)a CMP b into just a CMP b.  Only do this while
     building the tree as it useless otherwise.  */
  if (CONVERT_EXPR_CODE_P (code)
      && TREE_CODE (type) == BOOLEAN_TYPE
      && COMPARISON_CLASS_P (arg1))
    return gimple_combine_build2 (loc, TREE_CODE (arg1), type,
				  TREE_OPERAND (arg1, 0),
				  TREE_OPERAND (arg1, 1));

  tem = gimple_combine_unary (loc, code, type, arg1);
  if (tem)
    return tem;
  return build1_loc (loc, code, type, arg1);
}

/* Report that what we got for VAL's nonzerobits (a) if it is
   not just the type's nonzerobits.  */
static double_int
nonzerobits_report (double_int a, tree val)
{
  tree type;
  double_int nonzero;
  if (!dump_file || !(dump_flags & TDF_DETAILS))
    return a;

  type = TREE_TYPE (val);

  nonzero = mask_for_type (type);
  if (double_int_equal_p (nonzero, a))
    return a;

  fprintf (dump_file, "Found nonzerobits for '");
  print_generic_expr (dump_file, val, 0);
  fprintf (dump_file, "' as "HOST_WIDE_INT_PRINT_DOUBLE_HEX "\n",
	   a.high, a.low);

  return a;
}

static double_int
nonzerobits (tree val)
{
  double_int nonzero, lhs, rhs;
  tree op0, op1, op2;
  enum tree_code code;
  tree type;

  if (val == NULL_TREE)
    return double_int_minus_one;

  type = TREE_TYPE (val);

  nonzero = mask_for_type (type);

  if (!INTEGRAL_TYPE_P (type))
    return nonzero;

  if (TREE_CODE (val) == INTEGER_CST)
    return double_int_and (tree_to_double_int (val), nonzero);

  /* If we have a SSA_NAME, ask the hook first. */
  if (TREE_CODE (val) == SSA_NAME)
    {
      double_int t = nonzerobitsf (val);
      t = double_int_and (t, nonzero);
      if (!double_int_equal_p (t, nonzero))
        return nonzerobits_report (t, val);
    }

  defcodefor_name_3 (val, &code, &op0, &op1, &op2);

  /* Truth value based codes are always have just one bit set. */
  if (truth_value_p (code))
    return double_int_one;

  switch (code)
    {
      case MEM_REF:
	return nonzero;
      case BIT_IOR_EXPR:
      case BIT_XOR_EXPR:
      case MAX_EXPR:
      case MIN_EXPR:
	lhs = nonzerobits (op0);
	if (double_int_equal_p (lhs, nonzero))
          return lhs;
	rhs = nonzerobits (op1);
	return nonzerobits_report (double_int_ior (lhs, rhs), val);
      case COND_EXPR:
	lhs = nonzerobits (op1);
	if (double_int_equal_p (lhs, nonzero))
	  return lhs;
	 rhs = nonzerobits (op2);
	return nonzerobits_report (double_int_ior (lhs, rhs), val);
      case BIT_AND_EXPR:
	lhs = nonzerobits (op0);
	rhs = nonzerobits (op1);
	return nonzerobits_report (double_int_and (lhs, rhs), val);
#if 0
      /* Handle BIT_FIELD_REF with the width. */
      case BIT_FIELD_REF:
#endif
      CASE_CONVERT:
	  {
	    tree rtype = TREE_TYPE (op0);
	    bool uns;
	    double_int mask;
	    double_int rmask = nonzerobits (op0);
	    /* First extend mask and value according to the original type.  */
	    uns = (TREE_CODE (rtype) == INTEGER_TYPE
	           && TYPE_IS_SIZETYPE (rtype) ? 0 : TYPE_UNSIGNED (rtype));
	    mask = double_int_ext (rmask, TYPE_PRECISION (rtype), uns);

	    /* Then extend mask and value according to the target type.  */
	    uns = (TREE_CODE (type) == INTEGER_TYPE && TYPE_IS_SIZETYPE (type)
	           ? 0 : TYPE_UNSIGNED (type));
	    mask = double_int_ext (mask, TYPE_PRECISION (type), uns);
	    return nonzerobits_report (double_int_and (mask, nonzero), val);
	  }
      default:
	return nonzero;
    }
}

/* Given a ssa_name in NAME see if it was defined by an assignment and
   set CODE to be the code and ARG1 to the first operand on the rhs and ARG2
   to the second operand on the rhs. */
static inline void
defcodefor_name_3 (tree name, enum tree_code *code, tree *arg1, tree *arg2,
		   tree *arg3)
{
  gimple def;
  enum tree_code code1;
  tree arg11;
  tree arg21;
  tree arg31;
  enum gimple_rhs_class grhs_class;

  name = valueizerf (name);

  code1 = TREE_CODE (name);
  arg11 = name;
  arg21 = NULL_TREE;
  arg31 = NULL_TREE;
  grhs_class = get_gimple_rhs_class (code1);

  if (code1 == SSA_NAME)
    {
      def = SSA_NAME_DEF_STMT (name);
      
      if (def && is_gimple_assign (def)
	  && can_propagate_from (def))
	{
	  code1 = gimple_assign_rhs_code (def);
	  arg11 = gimple_assign_rhs1 (def);
          arg21 = gimple_assign_rhs2 (def);
          arg31 = gimple_assign_rhs3 (def);
	}
    }
  else if (grhs_class == GIMPLE_TERNARY_RHS
	   || GIMPLE_BINARY_RHS
	   || GIMPLE_UNARY_RHS
	   || GIMPLE_SINGLE_RHS)
    extract_ops_from_tree_1 (name, &code1, &arg11, &arg21, &arg31);

  if (arg11)
    arg11 = valueizerf (arg11);
  
  if (arg21)
    arg21 = valueizerf (arg21);

  if (arg31)
    arg31 = valueizerf (arg31);

  *code = code1;
  *arg1 = arg11;
  if (arg2)
    *arg2 = arg21;
  if (arg3)
    *arg3 = arg31;
}

/* Return the rhs of a gimple_assign STMT in a form of a single tree,
   converted to type TYPE.

   This should disappear, but is needed so we can combine expressions and use
   the fold() interfaces. Long term, we need to develop folding and combine
   routines that deal with gimple exclusively . */

static tree
rhs_to_tree (tree type, gimple stmt)
{
  location_t loc = gimple_location (stmt);
  enum tree_code code = gimple_assign_rhs_code (stmt);
  if (get_gimple_rhs_class (code) == GIMPLE_TERNARY_RHS)
    return fold_build3_loc (loc, code, type, gimple_assign_rhs1 (stmt),
			    gimple_assign_rhs2 (stmt),
			    gimple_assign_rhs3 (stmt));
  else if (get_gimple_rhs_class (code) == GIMPLE_BINARY_RHS)
    return fold_build2_loc (loc, code, type, gimple_assign_rhs1 (stmt),
			gimple_assign_rhs2 (stmt));
  else if (get_gimple_rhs_class (code) == GIMPLE_UNARY_RHS)
    return build1 (code, type, gimple_assign_rhs1 (stmt));
  else if (get_gimple_rhs_class (code) == GIMPLE_SINGLE_RHS)
    return gimple_assign_rhs1 (stmt);
  else
    gcc_unreachable ();
}

/* Combine OP0 CODE OP1 in the context of a COND_EXPR.  Returns
   the folded result in a form suitable for COND_EXPR_COND or
   NULL_TREE, if there is no suitable simplified form.  If
   INVARIANT_ONLY is true only gimple_min_invariant results are
   considered simplified.  */

static tree
combine_cond_expr_cond (location_t loc, enum tree_code code, tree type,
			tree op0, tree op1, bool invariant_only,
			bool nowarnings)
{
  tree t;

  gcc_assert (TREE_CODE_CLASS (code) == tcc_comparison);

  fold_defer_overflow_warnings ();

  /* Swap the operands so that fold_binary will return NULL if we
     really did not do any folding. */
  if (tree_swap_operands_p (op0, op1, true))
    {
      t = op0;
      op0 = op1;
      op1 = t;
      code = swap_tree_comparison (code);
    }

  t = fold_binary_loc (loc, code, type, op0, op1);
  if (!t)
    {
      fold_undefer_overflow_warnings (false, NULL, 0);
      return NULL_TREE;
    }

  /* Require that we got a boolean type out if we put one in.  */
  gcc_assert (TREE_CODE (TREE_TYPE (t)) == TREE_CODE (type));

  /* Even if we get a bool type, strip the boolean types conversions off. */
  while (CONVERT_EXPR_P (t)
	 && TREE_CODE (TREE_TYPE (TREE_OPERAND (t, 0))) == BOOLEAN_TYPE)
    t = TREE_OPERAND (t, 0);

  /* If we had a != 0 and we just reduced it down to a, then
     return NULL as this is already the canonicalize form. */
  if (code == NE_EXPR && integer_zerop (op1)
      && t == op0
      && !COMPARISON_CLASS_P (op0)
      && TREE_CODE (op0) != SSA_NAME)
    t = NULL_TREE;

  /* Bail out if we required an invariant but didn't get one.  */
  if (!t || (invariant_only && !is_gimple_min_invariant (t)))
    {
      fold_undefer_overflow_warnings (false, NULL, 0);
      return NULL_TREE;
    }

  fold_undefer_overflow_warnings_loc (!nowarnings, loc, 0);

  return t;
}

/* Checks if expression has type of one-bit precision, or is a known
   truth-valued expression.  */
static bool
truth_valued_ssa_name (tree name)
{
  double_int nz;
  tree type = TREE_TYPE (name);

  if (!INTEGRAL_TYPE_P (type))
    return false;
  /* Don't check here for BOOLEAN_TYPE as the precision isn't
     necessarily one and so ~X is not equal to !X.  */
  if (TYPE_PRECISION (type) == 1)
    return true;
  /* If the only bits which are maybe nonzero is the first or no bits,
     then this is a truth valued name. */
  nz = nonzerobits (name);
  return double_int_one_p (nz) || double_int_zero_p (nz);
}

/* Combine the comparison OP0 CODE OP1 at LOC with the defining statements
   of its operand.  Return a new comparison tree or NULL_TREE if there
   were no simplifying combines.  */

static tree
forward_propagate_into_comparison_1 (location_t loc,
				     enum tree_code code, tree type,
				     tree op0, tree op1, bool nowarnings)
{
  tree tmp = NULL_TREE;
  tree rhs0 = NULL_TREE, rhs1 = NULL_TREE;
  tree rhs01 = NULL_TREE, rhs11 = NULL_TREE;
  bool single_use0_p = false, single_use1_p = false;
  bool single_use01_p = false, single_use11_p = false;
  enum tree_code code0;

  tree arg1, arg2, arg3;

  defcodefor_name_3 (op0, &code0, &arg1, &arg2, &arg3);

  /* Try to simplify (a|b)!=0 to a!=0|b!=0 but only do this
     if one of (a!=0) or (b!=0) simplifies.  */
  if (code == NE_EXPR
      && integer_zerop (op1)
      && code0 == BIT_IOR_EXPR)
    {
      tree arg11, arg21;
      arg11 = gimple_combine_binary (loc, NE_EXPR, type, arg1, op1);
      arg21 = gimple_combine_binary (loc, NE_EXPR, type, arg2, op1);
      if (arg11 || arg21)
	{
	  if (arg11 == NULL)
	    arg11 = build2_loc (loc, NE_EXPR, type, arg1, op1);
	  if (arg21 == NULL)
	    arg21 = build2_loc (loc, NE_EXPR, type, arg2, op1);
	  return gimple_combine_build2 (loc, BIT_IOR_EXPR, type, arg11, arg21);
	}
    }

  /* Try to simplify (a|b)==0 to a==0&b==0 but only do this
     if one of (a==0) or (b==0) simplifies.  */
  if (code == EQ_EXPR
      && integer_zerop (op1)
      && code0 == BIT_IOR_EXPR)
    {
      tree arg11, arg21;
      arg11 = gimple_combine_binary (loc, EQ_EXPR, type, arg1, op1);
      arg21 = gimple_combine_binary (loc, EQ_EXPR, type, arg2, op1);
      /* If we have a BIT_NOT_EXPR then this did not simplify after all. */
      if (arg11 && (TREE_CODE (arg11) == BIT_NOT_EXPR
		    || TREE_CODE (arg11) == TRUTH_NOT_EXPR))
	arg11 = NULL_TREE;
      if (arg21 && (TREE_CODE (arg21) == BIT_NOT_EXPR
		    || TREE_CODE (arg21) == TRUTH_NOT_EXPR))
	arg21 = NULL_TREE;
      if (arg11 || arg21)
	{
	  if (arg11 == NULL)
	    arg11 = build2_loc (loc, EQ_EXPR, type, arg1, op1);
	  if (arg21 == NULL)
	    arg21 = build2_loc (loc, EQ_EXPR, type, arg2, op1);
	  return gimple_combine_build2 (loc, BIT_AND_EXPR, type, arg11, arg21);
	}
    }

  /* If we have (a ? b : c) CMP op1 and either b CMP op1 or c CMP op1
     simplifies to a constant, then produce a ? (b CMP op1) : (c CMP op1)
     which will simplify to something containing a | or a &.  */
  if (code0 == COND_EXPR)
    {
      tree arg11, arg21;
      arg11 = gimple_combine_binary (loc, code, type, arg2, op1);
      arg21 = gimple_combine_binary (loc, code, type, arg3, op1);
      if ((arg11 && TREE_CODE (arg11) == INTEGER_CST)
          || (arg21 && TREE_CODE (arg21) == INTEGER_CST))
	{
	  if (arg11 == NULL)
	    arg11 = build2_loc (loc, code, type, arg2, op1);
	  if (arg21 == NULL)
	    arg21 = build2_loc (loc, code, type, arg3, op1);
	  return gimple_combine_build3 (loc, COND_EXPR, type, arg1, arg11, arg21);
	}
    }

  /* FIXME: this really should not be using combine_cond_expr_cond (fold_binary)
     but matching the patterns directly.  */

  /* For comparisons use the first operand, that is likely to
     simplify comparisons against constants.  */
  if (TREE_CODE (op0) == SSA_NAME)
    {
      gimple def_stmt = get_prop_source_stmt (op0, false, &single_use0_p);
      if (def_stmt && can_propagate_from (def_stmt))
	{
	  rhs0 = rhs_to_tree (TREE_TYPE (op1), def_stmt);
	  tmp = combine_cond_expr_cond (loc, code, type, rhs0, op1,
					!single_use0_p, nowarnings);
	  if (tmp)
	    return tmp;
	  /* If we have a conversion, try to combine with what we have before.  */
	  if (CONVERT_EXPR_P (rhs0)
	      && TREE_CODE (TREE_OPERAND (rhs0, 0)) == SSA_NAME)
	    {
	      gimple def_stmt1 = get_prop_source_stmt (TREE_OPERAND (rhs0, 0),
						       false, &single_use01_p);
	      if (def_stmt1 && can_propagate_from (def_stmt1))
		{
		  rhs01 = rhs_to_tree (TREE_TYPE (TREE_OPERAND (rhs0, 0)),
					  def_stmt1);
		  rhs01 = fold_convert (TREE_TYPE (op0), rhs01);
		  single_use01_p &= single_use0_p;
		  tmp = combine_cond_expr_cond (loc, code, type, rhs01, op1,
						!single_use01_p, nowarnings);
		  if (tmp)
		    return tmp;
		}
	    }
	}
    }

  /* If that wasn't successful, try the second operand.  */
  if (TREE_CODE (op1) == SSA_NAME)
    {
      gimple def_stmt = get_prop_source_stmt (op1, false, &single_use1_p);
      if (def_stmt && can_propagate_from (def_stmt))
	{
	  rhs1 = rhs_to_tree (TREE_TYPE (op0), def_stmt);
	  tmp = combine_cond_expr_cond (loc, code, type,
					op0, rhs1, !single_use1_p,
					nowarnings);
	  if (tmp)
	    return tmp;
	  /* If we have a conversion, try to combine with what we have before.  */
	  if (CONVERT_EXPR_P (rhs1)
	      && TREE_CODE (TREE_OPERAND (rhs1, 0)) == SSA_NAME)
	    {
	      gimple def_stmt1 = get_prop_source_stmt (TREE_OPERAND (rhs1, 0),
						       false, &single_use11_p);
	      if (def_stmt1 && can_propagate_from (def_stmt1))
		{
		  rhs11 = rhs_to_tree (TREE_TYPE (TREE_OPERAND (rhs1, 0)),
					  def_stmt1);
		  rhs11 = fold_convert (TREE_TYPE (op0), rhs11);
		  single_use11_p &= single_use1_p;
		  tmp = combine_cond_expr_cond (loc, code, type,
						op0, rhs11, !single_use01_p,
						nowarnings);
		  if (tmp)
		    return tmp;
		}
	    }
	}
    }

  /* If that wasn't successful either, try both operands.  */
  if (rhs0 != NULL_TREE
      && rhs1 != NULL_TREE)
    {
      tmp = combine_cond_expr_cond (loc, code, type,
				    rhs0, rhs1,
				    !(single_use0_p && single_use1_p),
				    nowarnings);
      if (tmp)
	return tmp;
    }
  if (rhs01 != NULL_TREE
      && rhs1 != NULL_TREE)
    {
      tmp = combine_cond_expr_cond (loc, code, type,
				    rhs01, rhs1,
				    !(single_use01_p && single_use1_p),
				    nowarnings);
      if (tmp)
	return tmp;
    }
  if (rhs0 != NULL_TREE
      && rhs11 != NULL_TREE)
    {
      tmp = combine_cond_expr_cond (loc, code, type,
				    rhs0, rhs11,
				    !(single_use0_p && single_use11_p),
				    nowarnings);
      if (tmp)
	return tmp;
    }
  if (rhs01 != NULL_TREE
      && rhs11 != NULL_TREE)
    {
      tmp = combine_cond_expr_cond (loc, code, type,
				    rhs01, rhs11,
				    !(single_use01_p && single_use11_p),
				    nowarnings);
      if (tmp)
	return tmp;
    }


  return tmp;
}

/* Propagate from the ssa name definition statements of the assignment
   from a comparison at *GSI into the conditional if that simplifies it.
   Returns true if the stmt was modified therwise returns false.  */

static tree 
forward_propagate_into_comparison (location_t loc,
				   enum tree_code code,
				   tree type, tree rhs1,
				   tree rhs2)
{
  tree tmp;
  tree tmp1 = NULL_TREE;
  bool reversed_edges = false;
  gcc_assert (TREE_CODE_CLASS (code) == tcc_comparison);

  /* Combine the comparison with defining statements.  */
  do {
    tree canonicalized;
    tmp = forward_propagate_into_comparison_1 (loc, code,
					       type, rhs1, rhs2,
					       false);
    if (!tmp)
      break;
    if (TREE_CODE (tmp) == TRUTH_NOT_EXPR
	|| TREE_CODE (tmp) == BIT_NOT_EXPR)
    {
      reversed_edges ^= true;
      tmp = TREE_OPERAND (tmp, 0);
    }
    canonicalized = canonicalize_cond_expr_cond (tmp);
    if (!canonicalized)
      {
	tmp1 = tmp;
	break;
      }
    tmp1 = canonicalized;
    gimple_cond_get_ops_from_tree (canonicalized, &code, &rhs1, &rhs2);
  } while (tmp);


  if (tmp1)
    {
      if (reversed_edges)
	tmp1 = build1 (BIT_NOT_EXPR, TREE_TYPE (tmp1), tmp1);
      if (!useless_type_conversion_p (type, TREE_TYPE (tmp1)))
	tmp1 = build1 (NOP_EXPR, type, tmp1);
      return tmp1;
    }

  return NULL_TREE;
}

/* Propagate from the ssa name definition statements of COND_EXPR
   in GIMPLE_COND statement STMT into the conditional if that simplifies it.
   Returns zero if no statement was changed, one if there were
   changes and two if cfg_cleanup needs to run.  */

static tree
forward_propagate_into_gimple_cond (gimple stmt)
{
  tree tmp;
  enum tree_code code = gimple_cond_code (stmt);
  tree rhs1 = gimple_cond_lhs (stmt);
  tree rhs2 = gimple_cond_rhs (stmt);
  location_t loc = gimple_location (stmt);
  bool reversed_edges = false;
  bool proping = false;

  if (code == NE_EXPR
      && TREE_CODE (TREE_TYPE (rhs1)) == BOOLEAN_TYPE
      && integer_zerop (rhs2))
    {
      defcodefor_name (rhs1, &code, &rhs1, &rhs2);
      proping = true;
    }

  /* If we had a = ~b; if(a!=0) then do it as b==0 */
  if (code == BIT_NOT_EXPR || code == TRUTH_NOT_EXPR)
    {
      code = EQ_EXPR;
      rhs2 = build_zero_cst (TREE_TYPE (rhs1));
    }

  /* We can do tree combining on SSA_NAME and comparison expressions.  */
  if (TREE_CODE_CLASS (code) != tcc_comparison)
    return NULL_TREE;

  tmp = gimple_combine_binary (loc, code, boolean_type_node, rhs1, rhs2);
  if (!tmp)
    {
      /* Canonicalize _Bool == 0 and _Bool != 1 to _Bool != 0 by
	 swapping edges.  */
      if ((TREE_CODE (TREE_TYPE (rhs1)) == BOOLEAN_TYPE
	   || (INTEGRAL_TYPE_P (TREE_TYPE (rhs1))
	       && TYPE_PRECISION (TREE_TYPE (rhs1)) == 1))
          && ((code == EQ_EXPR
	       && integer_zerop (rhs2))
	      || (code == NE_EXPR
		  && integer_onep (rhs2))))
	{
	  reversed_edges = true;
	  tmp = build2 (NE_EXPR, boolean_type_node, rhs1,
			build_zero_cst (TREE_TYPE (rhs1)));
        }
      /* If we had propragating a comparison into a != 0 case
	 then just do that propragation. */
      else if (proping)
	  tmp = build2 (code, boolean_type_node, rhs1, rhs2);
      else
	return NULL_TREE;
    }

  /* Strip off the conversion from a boolean type to a boolean
     type, they are worthless for GIMPLE_COND.
     Note this is done as we use boolean_type_node here. */
  while (CONVERT_EXPR_P (tmp)
	 && TREE_CODE (TREE_TYPE (TREE_OPERAND (tmp, 0))) == BOOLEAN_TYPE)
    tmp = TREE_OPERAND (tmp, 0);

  if (TREE_CODE (tmp) == TRUTH_NOT_EXPR
      || TREE_CODE (tmp) == BIT_NOT_EXPR)
    {
      reversed_edges = true;
      tmp = TREE_OPERAND (tmp, 0);
    }
  if (CONVERT_EXPR_P (tmp))
    {
      tree t = TREE_OPERAND (tmp, 0);
      /* If we just changed a != 0 to be the same as (bool)a
         then don't do anything as we will produce the same
         result and cause an infinite loop.  */
      if (code == NE_EXPR && integer_zerop (rhs2)
	  && operand_equal_for_phi_arg_p (t, rhs1))
	return NULL_TREE;
      tmp = build2_loc (loc, NE_EXPR, boolean_type_node, t,
			build_zero_cst (TREE_TYPE (t)));
    }

  /* If we just changed a != 0 to be the same as a
      then don't do anything as we will produce the same
      result and cause an infinite loop.  */
  if (code == NE_EXPR && integer_zerop (rhs2)
      && operand_equal_for_phi_arg_p (tmp, rhs1)
      && !proping)
    return NULL_TREE;

  if (reversed_edges)
    tmp = build1 (BIT_NOT_EXPR, TREE_TYPE (tmp), tmp);


  return tmp;
}

/* Propagate from the ssa name definition statements of COND_EXPR
   in the rhs of statement STMT into the conditional if that simplifies it.
   Returns true zero if the stmt was changed.  */

static tree
forward_propagate_into_cond (location_t loc, enum tree_code code1,
			     tree type, tree cond, tree op1, tree op2)
{
  tree tmp = NULL_TREE;
  bool swap = false;
  enum tree_code code;
  tree rhs1;
  tree rhs2;

  gcc_assert (code1 == COND_EXPR);

  /* bool == 0 ? b : a -> bool ? b : a */
  /* bool != 1 ? b : a -> bool ? b : a */
  /* This is done first so we only the other simplifiers
     don't have bool == 0 or bool != 1 and only bool. */
  if (((TREE_CODE (cond) == EQ_EXPR
	 && integer_zerop (TREE_OPERAND (cond, 1)))
	|| (TREE_CODE (cond) == NE_EXPR
	    && integer_onep (TREE_OPERAND (cond, 1))))
      && (TREE_CODE (TREE_TYPE (TREE_OPERAND (cond, 0))) == BOOLEAN_TYPE
	  || (INTEGRAL_TYPE_P (TREE_TYPE (TREE_OPERAND (cond, 0)))
	      && TYPE_PRECISION (TREE_TYPE (TREE_OPERAND (cond, 0))) == 1)))
    return gimple_combine_build3 (loc, COND_EXPR, type,
				  TREE_OPERAND (cond, 0), op2, op1);

  /* A ? 1 : 0  -> (type) A. */
  if (integer_onep (op1)
      && integer_zerop (op2)
      && INTEGRAL_TYPE_P (type))
    return gimple_combine_build1 (loc, NOP_EXPR, type, cond);

  /* A ? 0 : 1 -> (type) !A */
  if (integer_onep (op1)
      && integer_zerop (op2)
      && INTEGRAL_TYPE_P (type))
    {
      tree tmp = gimple_combine_build1 (loc, BIT_NOT_EXPR,
					TREE_TYPE (cond), cond);
      return gimple_combine_build1 (loc, NOP_EXPR, type, tmp);
    }

  /* A ? B : 0 -> A & B  if B is a bool expr. */
  if (integer_zerop (op2)
      && truth_valued_ssa_name (op1))
    {
      cond = gimple_combine_build1 (loc, NOP_EXPR, type, cond);
      return gimple_combine_build2 (loc, BIT_AND_EXPR, type, cond, op1);
    }

  /* A ? 0 : B -> !A & B if B is a bool expr. */
  if (integer_zerop (op1)
      && truth_valued_ssa_name (op2))
    {
      cond = gimple_combine_build2 (loc, BIT_XOR_EXPR, TREE_TYPE (cond), cond,
				 build_int_cst_type (TREE_TYPE (cond), 1));
      cond = gimple_combine_build1 (loc, NOP_EXPR, type, cond);
      return gimple_combine_build2 (loc, BIT_AND_EXPR, type, cond, op2);
    }

  /* A ? B : 1 -> !A | B  if B is a bool expr. */
  if (integer_onep (op2)
      && truth_valued_ssa_name (op1))
    {
      cond = gimple_combine_build2 (loc, BIT_XOR_EXPR, TREE_TYPE (cond), cond,
				 build_int_cst_type (TREE_TYPE (cond), 1));
      cond = gimple_combine_build1 (loc, NOP_EXPR, type, cond);
      return gimple_combine_build2 (loc, BIT_IOR_EXPR, type, cond, op1);
    }

  /* A ? 1 : B -> A | B if B is a bool expr. */
  if (integer_onep (op1)
      && truth_valued_ssa_name (op2))
    {
      cond = gimple_combine_build1 (loc, NOP_EXPR, type, cond);
      return gimple_combine_build2 (loc, BIT_IOR_EXPR, type, cond, op2);
    }

  /* 1 ? A : B -> A. */
  if (integer_onep (cond))
    return op1;

  /* 0 ? A : B -> A. */
  if (integer_zerop (cond))
    return op2;

  /* If all else, try to simplify the condition. */
  defcodefor_name (cond, &code, &rhs1, &rhs2);

  /* If we have a = ~b;  a?c:d then convert it to b==0?c:d */
  if (code == BIT_NOT_EXPR || code == TRUTH_NOT_EXPR)
    {
      code = EQ_EXPR;
      rhs2 = build_zero_cst (TREE_TYPE (rhs1));
    }

  /* We can do tree combining on comparison expressions.  */
  if (TREE_CODE_CLASS (code) != tcc_comparison)
    return NULL_TREE;

  tmp = gimple_combine_binary (loc, code, TREE_TYPE (cond), rhs1, rhs2);

  /* If we had a SSA name before and we did not simplify the comparison,
     then just propragate the comparison.  */
  if (!tmp && TREE_CODE (cond) == SSA_NAME)
    tmp = build2_loc (loc, code, TREE_TYPE (cond), rhs1, rhs2);

  if (!tmp)
    return NULL_TREE;

  /* Strip off the conversion from a boolean type to a boolean
     type, they are worthless for GIMPLE_COND.
     Note this is done as we use boolean_type_node here. */
  while (CONVERT_EXPR_P (tmp)
	 && TREE_CODE (TREE_TYPE (TREE_OPERAND (tmp, 0))) == BOOLEAN_TYPE)
    tmp = TREE_OPERAND (tmp, 0);

  if (TREE_CODE (tmp) == TRUTH_NOT_EXPR
      || TREE_CODE (tmp) == BIT_NOT_EXPR)
    {
      swap = true;
      tmp = TREE_OPERAND (tmp, 0);
    }

  if (CONVERT_EXPR_P (tmp))
    {
      tree t = TREE_OPERAND (tmp, 0);
      /* If we just changed a != 0 to be the same as (bool)a
         then don't do anything as we will produce the same
         result and cause an infinite loop.  */
      if (code == NE_EXPR && integer_zerop (rhs2) &&
	  operand_equal_for_phi_arg_p (t, rhs1))
	return NULL_TREE;
      tmp = build2_loc (loc, NE_EXPR, boolean_type_node, t,
			build_zero_cst (TREE_TYPE (t)));
    }

  if (dump_file && tmp)
    {
      fprintf (dump_file, "  Replaced '");
      print_generic_expr (dump_file, cond, 0);
      fprintf (dump_file, "' with '");
      print_generic_expr (dump_file, tmp, 0);
      fprintf (dump_file, "'\n");
    }

  if ((!swap && integer_onep (tmp))
      || (swap && integer_zerop (tmp)))
    return op1;
  else if ((swap && integer_onep (tmp))
     	   || (!swap && integer_zerop (tmp)))
    return op2;

  if (swap)
    {
      tree t = op1;
      op1 = op2;
      op2 = t;
    }

  return gimple_combine_build3 (loc, COND_EXPR, type, tmp, op1, op2);
}

/* Simplify not, negative, and absolute expressions.  */

static tree 
simplify_not_neg_abs_expr (location_t loc, enum tree_code code,
		           tree type, tree rhs)
{
  tree arg1, arg2;
  enum tree_code code0;

  if (code != BIT_NOT_EXPR && code != NEGATE_EXPR && code != ABS_EXPR)
    return NULL_TREE;
  
  defcodefor_name (rhs, &code0, &arg1, &arg2);

  /* ABS (ABS (a)) -> ABS (a). */
  if (code == ABS_EXPR && code0 == code)
    return rhs;

  /* ABS (-a) -> ABS (a) */
  if (code == ABS_EXPR && code0 == NEGATE_EXPR)
    return gimple_combine_build1 (loc, code, type, arg1);

  /* ~(~ (a)) -> a and -(-a) -> a */
  if (code0 == code)
    return arg1;

  /* ~ (-a) -> a - 1 */
  if (code == BIT_NOT_EXPR
      && code0 == NEGATE_EXPR)
    return gimple_combine_build2 (loc, MINUS_EXPR, type, arg1,
				  build_int_cst_type (type, 1));
  /* - (~a) -> a + 1 */
  if (code == NEGATE_EXPR
      && code0 == BIT_NOT_EXPR)
    return gimple_combine_build2 (loc, PLUS_EXPR, type, arg1,
				  build_int_cst_type (type, 1));

  /* ~ (X ^ C) for C constant is X ^ D where D = ~C.  */
  if (code == BIT_NOT_EXPR
      && code0 == BIT_XOR_EXPR
      && TREE_CODE (arg2) == INTEGER_CST)
    {
      tree cst = fold_build1 (code, type, arg2);
      return gimple_combine_build2 (loc, code0, type, arg1, cst);
    }

  /* fold ~ (a CMP b) to a PMC b if there is a PMC.  */
  if (code == BIT_NOT_EXPR
      && TREE_CODE_CLASS (code0) == tcc_comparison)
    {
      tree op_type = TREE_TYPE (arg1);
      if (!(FLOAT_TYPE_P (op_type)
            && flag_trapping_math
            && code0 != ORDERED_EXPR && code0 != UNORDERED_EXPR
            && code0 != NE_EXPR && code0 != EQ_EXPR))
	{
	  code0 = invert_tree_comparison (code0,
					  HONOR_NANS (TYPE_MODE (op_type)));
	  if (code0 != ERROR_MARK)
	    return gimple_combine_build2 (loc, code0, type, arg1, arg2);
	}
    }


  return NULL_TREE;
}

/* STMT is a SWITCH_EXPR for which we attempt to find equivalent forms of
   the condition which we may be able to optimize better.  */

static tree
simplify_gimple_switch (gimple stmt)
{
  tree cond = gimple_switch_index (stmt);
  tree def, to, ti;
  enum tree_code code;
  tree defto = NULL;

  defcodefor_name (cond, &code, &def, NULL);

  if (code == INTEGER_CST && cond != def)
    return def;

  /* The optimization that we really care about is removing unnecessary
     casts.  That will let us do much better in propagating the inferred
     constant at the switch target.  */
  while (CONVERT_EXPR_CODE_P (code))
    {
      int need_precision;

      to = TREE_TYPE (cond);
      ti = TREE_TYPE (def);

      /* If we have an extension that preserves value, then we
	 can copy the source value into the switch.  */

      need_precision = TYPE_PRECISION (ti);
      if (! INTEGRAL_TYPE_P (ti))
	break;
      else if (TYPE_UNSIGNED (to) && !TYPE_UNSIGNED (ti))
	break;
      else if (!TYPE_UNSIGNED (to) && TYPE_UNSIGNED (ti))
	need_precision += 1;
      if (TYPE_PRECISION (to) < need_precision)
	break;

      defto = def;

      defcodefor_name (def, &code, &def, NULL);
    }

  return defto;
}

/* Helper routine for simplify_bitwise_binary_1 function.
   Return for the SSA name NAME the expression X if it mets condition
   NAME = !X. Otherwise return NULL_TREE.
   Detected patterns for NAME = !X are:
     !X and X == 0 for X with integral type.
     X ^ 1, X != 1,or ~X for X with integral type with precision of one.  */
static tree
lookup_logical_inverted_value (tree name)
{
  tree op1, op2;
  enum tree_code code;

  /* If name has none-intergal type then return.  */
  if (!INTEGRAL_TYPE_P (TREE_TYPE (name)))
    return NULL_TREE;

  defcodefor_name (name, &code, &op1, &op2);

  /* If CODE isn't an EQ_EXPR, BIT_XOR_EXPR, or BIT_NOT_EXPR, then return.  */

  switch (code)
    {
    case BIT_NOT_EXPR:
      if (truth_valued_ssa_name (name))
	return op1;
      break;
    case EQ_EXPR:
      /* Check if we have X == 0 and X has an integral type.  */
      if (!INTEGRAL_TYPE_P (TREE_TYPE (op1)))
	break;
      if (integer_zerop (op2))
	return op1;
      break;
    case NE_EXPR:
      /* Check if we have X != 1 and X is a truth-valued.  */
      if (!INTEGRAL_TYPE_P (TREE_TYPE (op1)))
	break;
      if (integer_onep (op2) && truth_valued_ssa_name (op1))
	return op1;
      break;
    case BIT_XOR_EXPR:
      /* Check if we have X ^ 1 and X is truth valued.  */
      if (integer_onep (op2) && truth_valued_ssa_name (op1))
	return op1;
      break;
    default:
      break;
    }

  return NULL_TREE;
}

/* Optimize ARG1 CODE ARG2 to a constant for bitwise binary
   operations CODE, if one operand has the logically inverted
   value of the other.  */
static tree
simplify_bitwise_binary_1 (enum tree_code code, tree type,
			   tree arg1, tree arg2)
{
  tree anot;

  /* If CODE isn't a bitwise binary operation, return NULL_TREE.  */
  if (code != BIT_AND_EXPR && code != BIT_IOR_EXPR
      && code != BIT_XOR_EXPR)
    return NULL_TREE;

  /* First check if operands ARG1 and ARG2 are equal.  */
  if (arg1 == arg2
      && (code == BIT_AND_EXPR || code == BIT_IOR_EXPR))
    return arg1;
  if (arg1 == arg2 && code == BIT_XOR_EXPR)
    return fold_convert (type, integer_zero_node);

  /* See if we have in arguments logical-not patterns.  */
  if (((anot = lookup_logical_inverted_value (arg1)) == NULL_TREE
       || anot != arg2)
      && ((anot = lookup_logical_inverted_value (arg2)) == NULL_TREE
	  || anot != arg1))
    return NULL_TREE;

  /* X & !X -> 0.  */
  if (code == BIT_AND_EXPR)
    return fold_convert (type, integer_zero_node);
  /* X | !X -> 1 and X ^ !X -> 1, if X is truth-valued.  */
  if (truth_valued_ssa_name (anot))
    return fold_convert (type, integer_one_node);

  /* ??? Otherwise result is (X != 0 ? X : 1).  not handled.  */
  return NULL_TREE;
}

/* Simplify bitwise binary operations.
   Return the tree of what the code was transformed into.  */


static tree
simplify_bitwise_binary (location_t loc, enum tree_code code, tree type,
			 tree arg1, tree arg2)
{
  tree res;
  tree def1_arg1, def1_arg2 = NULL_TREE, def2_arg1, def2_arg2 = NULL_TREE;
  enum tree_code def1_code, def2_code;

  gcc_assert (code == BIT_AND_EXPR
	      || code == BIT_XOR_EXPR
	      || code == BIT_IOR_EXPR);

  defcodefor_name (arg1, &def1_code, &def1_arg1, &def1_arg2);
  defcodefor_name (arg2, &def2_code, &def2_arg1, &def2_arg2);

  /* Try to optimize away the AND based on the nonzero bits info. */
  if (code == BIT_AND_EXPR)
    {
      double_int nzop1 = nonzerobits (arg1);
      double_int nzop2;
      if (TREE_CODE (arg2) == INTEGER_CST)
	{
	  double_int val2 = tree_to_double_int (arg2);
	  if (double_int_zero_p (double_int_and_not (nzop1, val2)))
	    return arg1;
        }
        nzop2 = nonzerobits (arg2);
        /* If we are clearing all the nonzero bits, the result is zero.  */
        if (double_int_zero_p (double_int_and (nzop1, nzop2)))
	  return build_zero_cst (TREE_TYPE (arg1));
    }

  /* A | C is C if all bits of A that might be nonzero are on in C.  */
  if (code == BIT_IOR_EXPR
      && TREE_CODE (arg2) == INTEGER_CST
      && double_int_zero_p (double_int_and_not (nonzerobits (arg1),
						tree_to_double_int (arg2))))
						
    return arg2;

  /* A | B -> A if B is known to be zero */
  /* A ^ B -> A if B is known to be zero */
  if ((code == BIT_IOR_EXPR
       || code == BIT_XOR_EXPR)
      && double_int_zero_p (nonzerobits (arg2)))
    return arg1;

  /* A | B -> B if A is known to be zero */
  /* A ^ B -> B if A is known to be zero */
  if ((code == BIT_IOR_EXPR
       || code == BIT_XOR_EXPR)
      && double_int_zero_p (nonzerobits (arg1)))
    return arg2;

  /* A & B -> 0 if A or B are known to be zero */
  if (code == BIT_AND_EXPR
      && (double_int_zero_p (nonzerobits (arg1))
	  || double_int_zero_p (nonzerobits (arg2))))
    return build_zero_cst (type);

  /* If we are XORing two things that have no bits in common,
     convert them into an IOR.  This helps to detect rotation encoded
     using those methods and possibly other simplifications.  */
  if (code == BIT_XOR_EXPR
      && double_int_zero_p (double_int_and (nonzerobits (arg1),
					    nonzerobits (arg2))))
    return gimple_combine_build2 (loc, BIT_IOR_EXPR, type, arg1, arg2);

  /* Fold a!=0|b!=0 if a and b are the same type to (a|b)!=0 . */
  if (code == BIT_IOR_EXPR
      && def1_code == NE_EXPR
      && integer_zerop (def1_arg2)
      && def2_code == NE_EXPR
      && integer_zerop (def2_arg2)
      && types_compatible_p (TREE_TYPE (def1_arg1), TREE_TYPE (def2_arg1))
      && INTEGRAL_TYPE_P (TREE_TYPE (def1_arg1)))
   {
     tree tmp = gimple_combine_build2 (loc, code, TREE_TYPE (def1_arg1),
				       def1_arg1, def2_arg1);
     return gimple_combine_build2 (loc, NE_EXPR, type, tmp,
				   build_zero_cst (TREE_TYPE (def1_arg1)));
   }

  /* Fold a==0&b==0 if a and b are the same type to (a|b)==0 . */
  if (code == BIT_AND_EXPR
      && def1_code == EQ_EXPR
      && integer_zerop (def1_arg2)
      && def2_code == EQ_EXPR
      && integer_zerop (def2_arg2)
      && types_compatible_p (TREE_TYPE (def1_arg1), TREE_TYPE (def2_arg1))
      && INTEGRAL_TYPE_P (TREE_TYPE (def1_arg1)))
   {
     tree tmp = gimple_combine_build2 (loc, BIT_IOR_EXPR, TREE_TYPE (def1_arg1),
				       def1_arg1, def2_arg1);
     return gimple_combine_build2 (loc, EQ_EXPR, type, tmp,
				   build_zero_cst (TREE_TYPE (def1_arg1)));
   }

  /* Try to fold (type) X op CST -> (type) (X op ((type-x) CST)).  */
  if (TREE_CODE (arg2) == INTEGER_CST
      && CONVERT_EXPR_CODE_P (def1_code)
      && INTEGRAL_TYPE_P (TREE_TYPE (def1_arg1))
      && int_fits_type_p (arg2, TREE_TYPE (def1_arg1)))
    {
      tree tmp, cst;
      cst = fold_convert_loc (loc, TREE_TYPE (def1_arg1), arg2);
      tmp = gimple_combine_build2 (loc, code, TREE_TYPE (cst), def1_arg1,
				   cst);
      /* Don't use fold here since it undos this conversion.  */
      return build1_loc (loc, NOP_EXPR, TREE_TYPE (arg1), tmp);
    }

  /* For bitwise binary operations apply operand conversions to the
     binary operation result instead of to the operands.  This allows
     to combine successive conversions and bitwise binary operations.  */
  if (CONVERT_EXPR_CODE_P (def1_code)
      && CONVERT_EXPR_CODE_P (def2_code)
      && types_compatible_p (TREE_TYPE (def1_arg1), TREE_TYPE (def2_arg1))
      /* Make sure that the conversion widens the operands, or has same
	 precision,  or that it changes the operation to a bitfield
	 precision.  */
      && ((TYPE_PRECISION (TREE_TYPE (def1_arg1))
	   <= TYPE_PRECISION (TREE_TYPE (arg1)))
	  || (GET_MODE_CLASS (TYPE_MODE (TREE_TYPE (arg1)))
	      != MODE_INT)
	  || (TYPE_PRECISION (TREE_TYPE (arg1))
	      != GET_MODE_PRECISION (TYPE_MODE (TREE_TYPE (arg1))))))
    {
      tree tmp;
      tmp = gimple_combine_build2 (loc, code, TREE_TYPE (def1_arg1), def1_arg1,
				   def2_arg1);
      return build1_loc (loc, NOP_EXPR, type, tmp);
    }

  /* Canonicalize (a & C1) | C2.  */
  if (code == BIT_IOR_EXPR
      && def1_code == BIT_AND_EXPR
      && TREE_CODE (arg2) == INTEGER_CST
      && TREE_CODE (def1_arg2) == INTEGER_CST)
    {
      double_int c1, c2, msk;
      int width = TYPE_PRECISION (type);
      c1 = tree_to_double_int (def1_arg2);
      c2 = tree_to_double_int (arg2);

      /* If (C1&C2) == C1, then (a&C1)|C2 becomes C2.  */
      if (double_int_equal_p (double_int_and (c1, c2), c1))
	return arg2;

      msk = double_int_mask (width);

      /* If (C1|C2) == ~0 then (X&C1)|C2 becomes X|C2.  */
      if (double_int_zero_p (double_int_and_not (msk,
						 double_int_ior (c1, c2))))
	return gimple_combine_build2 (loc, code, type, def1_arg1, arg2);
    }

  /* (a | CST1) & CST2  ->  (a & CST2) | (CST1 & CST2).  */
  if (code == BIT_AND_EXPR
      && def1_code == BIT_IOR_EXPR
      && TREE_CODE (arg2) == INTEGER_CST
      && TREE_CODE (def1_arg2) == INTEGER_CST)
    {
      tree cst = fold_build2 (BIT_AND_EXPR, type,
			      arg2, def1_arg2);
      tree tem;
      tem = gimple_combine_build2 (loc, code, type, def1_arg1,
				   arg2);
      if (integer_zerop (cst))
	return tem;
      return gimple_combine_build2 (loc, def1_code, type, tem, cst);
    }

  /* Combine successive equal operations with constants.  */
  if (def1_code == code 
      && TREE_CODE (arg2) == INTEGER_CST
      && TREE_CODE (def1_arg2) == INTEGER_CST)
    {
      tree cst = fold_build2 (code, type, arg2, def1_arg2);
      return gimple_combine_build2 (loc, code, type, def1_arg1, cst);
    }

   /* Fold (A OP1 B) OP0 (C OP1 B) to (A OP0 C) OP1 B. */
   if (def1_code == def2_code
       && (def1_code == BIT_AND_EXPR
	   || def1_code == BIT_XOR_EXPR
	   || def1_code == BIT_IOR_EXPR)
       && operand_equal_for_phi_arg_p (def1_arg2,
				       def2_arg2))
    {
      tree inner = gimple_combine_build2 (loc, code, type, def1_arg1, def2_arg1);
      if (integer_zerop (inner))
	{
	  if (def1_code == BIT_AND_EXPR)
	    return inner;
	  else
	    return def1_arg2;
	}
      else
      	return gimple_combine_build2 (loc, def1_code, type, inner, def1_arg2);
    }

  /* Canonicalize X ^ ~0 to ~X.  */
  if (code == BIT_XOR_EXPR
      && TREE_CODE (arg2) == INTEGER_CST
      && integer_all_onesp (arg2))
    return gimple_combine_build1 (loc, BIT_NOT_EXPR, type, arg1);

  /* Fold (X ^ Y) & Y as ~X & Y.  */
  if (code == BIT_AND_EXPR
      && def1_code == BIT_XOR_EXPR
      && operand_equal_for_phi_arg_p (def1_arg2, arg2))
    {
      tree tem;
      tem = gimple_combine_build1 (loc, BIT_NOT_EXPR, type, def1_arg1);
      return gimple_combine_build2 (loc, code, type, tem, arg2);
    }

  /* Fold (X ^ Y) & X as ~Y & X.  */
  if (code == BIT_AND_EXPR
      && def1_code == BIT_XOR_EXPR
      && operand_equal_for_phi_arg_p (def1_arg1, arg2))
    {
      tree tem;
      tem = gimple_combine_build1 (loc, BIT_NOT_EXPR, type, def2_arg1);
      return gimple_combine_build2 (loc, code, type, tem, arg2);
    }

  /* Fold Y & (X ^ Y) as Y & ~X.  */
  if (code == BIT_AND_EXPR
      && def2_code == BIT_XOR_EXPR
      && operand_equal_for_phi_arg_p (def2_arg2, arg1))
    {
      tree tem;
      tem = gimple_combine_build1 (loc, BIT_NOT_EXPR, type, def2_arg1);
      return gimple_combine_build2 (loc, code, type, tem, arg1);
    }
    

  /* Fold X & (X ^ Y) as X & ~Y.  */
  if (code == BIT_AND_EXPR
      && def2_code == BIT_XOR_EXPR
      && operand_equal_for_phi_arg_p (def2_arg1, arg1))
    {
      tree tem;
      tem = gimple_combine_build1 (loc, BIT_NOT_EXPR, type, def2_arg2);
      return gimple_combine_build2 (loc, code, type, tem, arg1);
    }

  /* Fold ~X & N into X ^ N if X's nonzerobits is equal to N. */
  if (code == BIT_AND_EXPR
      && def1_code == BIT_NOT_EXPR
      && TREE_CODE (arg2) == INTEGER_CST
      && double_int_equal_p (tree_to_double_int (arg2),
			     nonzerobits (def1_arg1)))
      return gimple_combine_build2 (loc, BIT_XOR_EXPR, type, def1_arg1, arg2);

  /* Try simple folding for X op !X, and X op X.  */
  res = simplify_bitwise_binary_1 (code, TREE_TYPE (arg1), arg1, arg2);
  if (res != NULL_TREE)
    return res;

  if (code == BIT_AND_EXPR || code == BIT_IOR_EXPR)
    {
      enum tree_code ocode = code == BIT_AND_EXPR ? BIT_IOR_EXPR : BIT_AND_EXPR;
      if (def1_code == ocode)
	{
	  tree x = arg2;
	  enum tree_code coden;
	  tree a1, a2;
	  /* ( X | Y) & X -> X */
	  /* ( X & Y) | X -> X */
	  if (x == def1_arg1
	      || x == def1_arg2)
	    return x;
          /* (~X | Y) & X -> X & Y */
           /* (~X & Y) | X -> X | Y */

	  if (coden == BIT_NOT_EXPR && a1 == x)
	    return gimple_combine_build2 (loc, code, type, def1_arg2, x);

	  defcodefor_name (def1_arg2, &coden, &a1, &a2);
	  /* (Y | ~X) & X -> X & Y */
	  /* (Y & ~X) | X -> X | Y */
	  if (coden == BIT_NOT_EXPR && a1 == x)
	    return gimple_combine_build2 (loc, code, type, x, def1_arg1);
	}
      if (def2_code == ocode)
	{
	  tree x = arg1;
	  enum tree_code coden;
	  tree a1;
	  /* X & ( X | Y) -> X */
	  /* X | ( X & Y) -> X */
	  if (x == def2_arg1
	      || x == def2_arg2)
	    return x;
	  defcodefor_name (def2_arg1, &coden, &a1, NULL);
	  /* (~X | Y) & X -> X & Y */
	  /* (~X & Y) | X -> X | Y */
	  if (coden == BIT_NOT_EXPR && a1 == x)
	    return gimple_combine_build2 (loc, code, type, def2_arg2, x);

	  defcodefor_name (def2_arg2, &coden, &a1, NULL);
	  /* (Y | ~X) & X -> X & Y */
	  /* (Y & ~X) | X -> X | Y */
	  if (coden == BIT_NOT_EXPR && a1 == x)
	    return gimple_combine_build2 (loc, code, type, x, def2_arg1);
	}
    }

  return NULL;
}

/* Perform re-associations of the plus or minus statement STMT that are
   always permitted.  Returns true if the CFG was changed.  */

static tree
associate_plusminus (location_t loc, enum tree_code code, tree type,
		     tree rhs1, tree rhs2)
{
  tree def1_arg1, def1_arg2 = NULL_TREE, def2_arg1, def2_arg2 = NULL_TREE;
  enum tree_code def1_code, def2_code;

  gcc_assert (code == PLUS_EXPR || code == MINUS_EXPR);

  if (!FLOAT_TYPE_P (type))
    {
      if (integer_zerop (rhs2))
	return rhs1;
      if (integer_zerop (rhs1))
	{
	  if (code == PLUS_EXPR)
	    return rhs2;
	  return gimple_combine_build1 (loc, NEGATE_EXPR, type, rhs2);
	}
    }
  else
    {
      if (fold_real_zero_addition_p (type, rhs2, code == MINUS_EXPR))
	return rhs1;

      if (fold_real_zero_addition_p (type, rhs1, 0))
	{
	  if (code == PLUS_EXPR)
	    return rhs2;
	  return gimple_combine_build1 (loc, NEGATE_EXPR, type, rhs2);
	}
    }

   if (code == MINUS_EXPR
       && (!FLOAT_TYPE_P (type) || !HONOR_NANS (TYPE_MODE (type)))
           && operand_equal_p (rhs1, rhs2, 0))
      return build_zero_cst (type);

  /* We can't reassociate at all for saturating types.  */
  if (TYPE_SATURATING (type))
    return NULL_TREE;

  defcodefor_name (rhs1, &def1_code, &def1_arg1, &def1_arg2);
  defcodefor_name (rhs2, &def2_code, &def2_arg1, &def2_arg2);

  if (code == MINUS_EXPR)
    /* Try folding difference of addresses.  */
    {
      HOST_WIDE_INT diff;

      if ((def1_code == ADDR_EXPR
           && def2_code == ADDR_EXPR)
          && ptr_difference_const (def1_arg1, def2_arg1, &diff))
        return build_int_cst_type (type, diff);
    }

  /* First contract negates.  */

  /* A +- (-B) -> A -+ B.  */
  if (def2_code == NEGATE_EXPR)
    {
      code = (code == MINUS_EXPR) ? PLUS_EXPR : MINUS_EXPR;
      return gimple_combine_build2 (loc, code, type, rhs1, 
					def2_arg1);
    }

  /* (-A) + B -> B - A.  */
  if (code == PLUS_EXPR && def1_code == NEGATE_EXPR)
    return gimple_combine_build2 (loc, MINUS_EXPR, type, rhs2, 
				      def1_arg1);

  /* We can't reassociate floating-point or fixed-point plus or minus
     because of saturation to +-Inf.  */
  if (FLOAT_TYPE_P (type)
      || FIXED_POINT_TYPE_P (type))
    return NULL_TREE;

  /* Second match patterns that allow contracting a plus-minus pair
     irrespective of overflow issues.

	(A +- B) - A       ->  +- B
	(A +- B) -+ B      ->  A
	(CST +- A) +- CST  ->  CST +- A
	(A + CST) +- CST   ->  A + CST
	~A + A             ->  -1
	~A + 1             ->  -A 
	A - (A +- B)       ->  -+ B
	A +- (B +- A)      ->  +- B
	CST +- (CST +- A)  ->  CST +- A
	CST +- (A +- CST)  ->  CST +- A
	A + ~A             ->  -1

     via commutating the addition and contracting operations to zero
     by reassociation.  */

  if (def1_code == PLUS_EXPR
      || def1_code == MINUS_EXPR)
    {
      if (operand_equal_p (def1_arg1, rhs2, 0)
	  && code == MINUS_EXPR)
	{
	  /* (A +- B) - A -> +- B.  */
	  if (def1_code == PLUS_EXPR)
	    return def1_arg2;
	  else
	    return gimple_combine_build1 (loc, NEGATE_EXPR, type,
					  def1_arg2);
	}
      else if (operand_equal_p (def1_arg2, rhs2, 0)
	       && code != def1_code)
        /* (A +- B) -+ B -> A.  */
	return def1_arg1;
      else if (TREE_CODE (rhs2) == INTEGER_CST
	       && TREE_CODE (def1_arg1) == INTEGER_CST)
	{
	  /* (CST +- A) +- CST -> CST +- A.  */
	  tree cst = fold_binary (code, type,
				  def1_arg1, rhs2);
	  if (cst && !TREE_OVERFLOW (cst))
	    return gimple_combine_build2 (loc, def1_code, type, cst, def1_arg2);
	}
      else if (TREE_CODE (rhs2) == INTEGER_CST
	       && TREE_CODE (def1_arg2) == INTEGER_CST
	       && def1_code == PLUS_EXPR)
	{
	  /* (A + CST) +- CST -> A + CST.  */
	  tree cst = fold_binary (code, type,
				  def1_arg2, rhs2);
	  if (cst && !TREE_OVERFLOW (cst))
	    return gimple_combine_build2 (loc, PLUS_EXPR, type, def1_arg1, cst);
	}
    }
  else if (def1_code == BIT_NOT_EXPR
	   && INTEGRAL_TYPE_P (type))
    {
      if (code == PLUS_EXPR
	  && operand_equal_p (def1_arg1, rhs2, 0))
	/* ~A + A -> -1.  */
	return build_int_cst_type (type, -1);
      else if (code == PLUS_EXPR
	       && integer_onep (rhs1))
	/* ~A + 1 -> -A.  */
	return gimple_combine_build1 (loc, NEGATE_EXPR, type,
				      def1_arg1);
    }

  if (def2_code == PLUS_EXPR
      || def2_code == MINUS_EXPR)
    {
      if (operand_equal_p (def2_arg1, rhs1, 0)
	  && code == MINUS_EXPR)
	{
	  /* A - (A +- B) -> -+ B.  */
	  if (def2_code == MINUS_EXPR)
	    return def2_arg2;
	  else
	    return gimple_combine_build1 (loc, NEGATE_EXPR, type,
					  def2_arg2);
	}
      else if (operand_equal_p (def2_arg2, rhs1, 0)
	       && code != def2_code)
	{
	  /* A +- (B +- A) -> +- B.  */
	  if (code == PLUS_EXPR)
	    return def2_arg1;
	  else
	    return gimple_combine_build1 (loc, NEGATE_EXPR, type,
					  def2_arg1);
	}
      else if (TREE_CODE (rhs1) == INTEGER_CST
	       && TREE_CODE (def2_arg1) == INTEGER_CST)
	{
	  /* CST +- (CST +- A) -> CST +- A.  */
	  tree cst = fold_binary (code, type,
				  rhs1, def2_arg1);
	  if (cst && !TREE_OVERFLOW (cst))
	    {
	      code = (code == def2_code ? PLUS_EXPR : MINUS_EXPR);
	      return gimple_combine_build2 (loc, code, type, cst,
					    def2_arg2);
	    }
	}
      else if (TREE_CODE (rhs1) == INTEGER_CST
	       && TREE_CODE (def2_arg2) == INTEGER_CST)
	{
	  /* CST +- (A +- CST) -> CST +- A.  */
	  tree cst = fold_binary (def2_code == code
				  ? PLUS_EXPR : MINUS_EXPR,
				  type,
				  rhs1, def2_arg2);
	  if (cst && !TREE_OVERFLOW (cst))
	    return gimple_combine_build2 (loc, code, type, cst,
					  def2_arg1);
	}
    }
  else if (def2_code == BIT_NOT_EXPR
	   && INTEGRAL_TYPE_P (type))
    {
      if (code == PLUS_EXPR
	  && operand_equal_p (def2_arg1, rhs1, 0))
	/* A + ~A -> -1.  */
	return build_int_cst_type (type, -1);
    }

  return NULL_TREE;
}

/* Combine two conversions in a row for the second conversion at *GSI.
   Returns true if there were any changes made.  Else it returns 0.  */
 
static tree
combine_conversions (location_t loc, enum tree_code code, tree ltype,
		     tree op0)
{
  enum tree_code defopcode;
  tree defop0;

  gcc_checking_assert (CONVERT_EXPR_CODE_P (code)
		       || code == FLOAT_EXPR
		       || code == FIX_TRUNC_EXPR);



  if (useless_type_conversion_p (ltype, TREE_TYPE (op0)))
    return op0;

  defcodefor_name (op0, &defopcode, &defop0, NULL);

  if (CONVERT_EXPR_CODE_P (defopcode))
    {
      tree type = ltype;
      tree inside_type = TREE_TYPE (defop0);
      tree inter_type = TREE_TYPE (op0);
      int inside_int = INTEGRAL_TYPE_P (inside_type);
      int inside_ptr = POINTER_TYPE_P (inside_type);
      int inside_float = FLOAT_TYPE_P (inside_type);
      int inside_vec = TREE_CODE (inside_type) == VECTOR_TYPE;
      unsigned int inside_prec = TYPE_PRECISION (inside_type);
      int inside_unsignedp = TYPE_UNSIGNED (inside_type);
      int inter_int = INTEGRAL_TYPE_P (inter_type);
      int inter_ptr = POINTER_TYPE_P (inter_type);
      int inter_float = FLOAT_TYPE_P (inter_type);
      int inter_vec = TREE_CODE (inter_type) == VECTOR_TYPE;
      unsigned int inter_prec = TYPE_PRECISION (inter_type);
      int inter_unsignedp = TYPE_UNSIGNED (inter_type);
      int final_int = INTEGRAL_TYPE_P (type);
      int final_ptr = POINTER_TYPE_P (type);
      int final_float = FLOAT_TYPE_P (type);
      int final_vec = TREE_CODE (type) == VECTOR_TYPE;
      unsigned int final_prec = TYPE_PRECISION (type);
      int final_unsignedp = TYPE_UNSIGNED (type);

      /* In addition to the cases of two conversions in a row
	 handled below, if we are converting something to its own
	 type via an object of identical or wider precision, neither
	 conversion is needed.  */
      if (useless_type_conversion_p (type, inside_type)
	  && (((inter_int || inter_ptr) && final_int)
	      || (inter_float && final_float))
	  && inter_prec >= final_prec)
	return unshare_expr (defop0);

      /* Likewise, if the intermediate and initial types are either both
	 float or both integer, we don't need the middle conversion if the
	 former is wider than the latter and doesn't change the signedness
	 (for integers).  Avoid this if the final type is a pointer since
	 then we sometimes need the middle conversion.  Likewise if the
	 final type has a precision not equal to the size of its mode.  */
      if (((inter_int && inside_int)
	   || (inter_float && inside_float)
	   || (inter_vec && inside_vec))
	  && inter_prec >= inside_prec
	  && (inter_float || inter_vec
	      || inter_unsignedp == inside_unsignedp)
	  && ! (final_prec != GET_MODE_BITSIZE (TYPE_MODE (type))
		&& TYPE_MODE (type) == TYPE_MODE (inter_type))
	  && ! final_ptr
	  && (! final_vec || inter_prec == inside_prec))
	return gimple_combine_build1 (loc, code, ltype, defop0);

      /* If we have a sign-extension of a zero-extended value, we can
	 replace that by a single zero-extension.  */
      if (inside_int && inter_int && final_int
	  && inside_prec < inter_prec && inter_prec < final_prec
	  && inside_unsignedp && !inter_unsignedp)
	return gimple_combine_build1 (loc, code, ltype, defop0);

      /* Two conversions in a row are not needed unless:
	 - some conversion is floating-point (overstrict for now), or
	 - some conversion is a vector (overstrict for now), or
	 - the intermediate type is narrower than both initial and
	 final, or
	 - the intermediate type and innermost type differ in signedness,
	 and the outermost type is wider than the intermediate, or
	 - the initial type is a pointer type and the precisions of the
	 intermediate and final types differ, or
	 - the final type is a pointer type and the precisions of the
	 initial and intermediate types differ.  */
      if (! inside_float && ! inter_float && ! final_float
	  && ! inside_vec && ! inter_vec && ! final_vec
	  && (inter_prec >= inside_prec || inter_prec >= final_prec)
	  && ! (inside_int && inter_int
		&& inter_unsignedp != inside_unsignedp
		&& inter_prec < final_prec)
	  && ((inter_unsignedp && inter_prec > inside_prec)
	      == (final_unsignedp && final_prec > inter_prec))
	  && ! (inside_ptr && inter_prec != final_prec)
	  && ! (final_ptr && inside_prec != inter_prec)
	  && ! (final_prec != GET_MODE_BITSIZE (TYPE_MODE (type))
		&& TYPE_MODE (type) == TYPE_MODE (inter_type)))
	return gimple_combine_build1 (loc, code, ltype, defop0);

      /* A truncation to an unsigned type should be canonicalized as
	 bitwise and of a mask.  */
      if (final_int && inter_int && inside_int
	  && final_prec == inside_prec
	  && final_prec > inter_prec
	  && inter_unsignedp)
	{
	  tree tem;
	  tem = double_int_to_tree (inside_type, double_int_mask (inter_prec));

	  tem = gimple_combine_build2 (loc, BIT_AND_EXPR, TREE_TYPE (tem),
				       defop0, tem);
	  return gimple_combine_build1 (loc, code, ltype, tem);
	}
    }

  return NULL_TREE;
}

tree
gimple_combine_ternary (location_t loc, enum tree_code code,
			tree type, tree arg1, tree arg2, tree arg3)
{
  gcc_assert (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (code))
	      && TREE_CODE_LENGTH (code) == 3);

  arg1 = valueizerf (arg1);
  arg2 = valueizerf (arg2);
  arg3 = valueizerf (arg3);

  /* Call fold if we have three constants. */
  if (is_gimple_min_invariant (arg1) && is_gimple_min_invariant (arg2)
       && is_gimple_min_invariant (arg3))
    return fold_ternary_loc (loc, code, type, arg1, arg2, arg3);

  if (code == COND_EXPR)
    return forward_propagate_into_cond (loc, code, type, arg1, arg2, arg3);
  return NULL_TREE;
}

tree
gimple_combine_binary (location_t loc, enum tree_code code,
		       tree type, tree arg1, tree arg2)
{
  if (code == ASSERT_EXPR)
    return NULL_TREE;

  gcc_assert (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (code))
              && TREE_CODE_LENGTH (code) == 2
              && arg1 != NULL_TREE
              && arg2 != NULL_TREE);

  arg1 = valueizerf (arg1);
  arg2 = valueizerf (arg2);

  /* Call fold if we have two constants. */
  if (is_gimple_min_invariant (arg1) && is_gimple_min_invariant (arg2))
    return fold_binary_loc (loc, code, type, arg1, arg2);

  if (commutative_tree_code (code)
      && tree_swap_operands_p (arg1, arg2, true))
    {
      tree t = arg1;
      arg1 = arg2;
      arg2 = t;
    }

  if (TREE_CODE_CLASS (code) == tcc_comparison)
    return forward_propagate_into_comparison (loc, code, type, arg1, arg2);

  switch (code)
    {
      case BIT_AND_EXPR:
      case BIT_XOR_EXPR:
      case BIT_IOR_EXPR:
	return simplify_bitwise_binary (loc, code, type, arg1, arg2);
      case PLUS_EXPR:
      case MINUS_EXPR:
	return associate_plusminus (loc, code, type, arg1, arg2);
      default:
	return NULL_TREE;
    }
}

tree
gimple_combine_unary (location_t loc, enum tree_code code,
		      tree type, tree arg1)
{
  gcc_assert (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (code))
              && TREE_CODE_LENGTH (code) == 1
              && arg1 != NULL_TREE);

  arg1 = valueizerf (arg1);

  /* Call fold if we have a constant. */
  if (is_gimple_min_invariant (arg1))
    return fold_unary_loc (loc, code, type, arg1);

  switch (code)
    {
      CASE_CONVERT:
      case FLOAT_EXPR:
      case FIX_TRUNC_EXPR:
	return combine_conversions (loc, code, type, arg1);
      case BIT_NOT_EXPR:
      case NEGATE_EXPR:
      case ABS_EXPR:
	return simplify_not_neg_abs_expr (loc, code, type, arg1);
      default:
	return NULL_TREE;
    }
}

/* Main entry point for the forward propagation and statement combine
   optimizer.  */

tree
ssa_combine (gimple stmt)
{
  switch (gimple_code (stmt))
    {
    case GIMPLE_ASSIGN:
      {
	tree rhs1 = gimple_assign_rhs1 (stmt);
	tree rhs2 = gimple_assign_rhs2 (stmt);
	tree rhs3 = gimple_assign_rhs3 (stmt);
	tree ltype = TREE_TYPE (gimple_assign_lhs (stmt));
	location_t loc = gimple_location (stmt);
	enum tree_code code = gimple_assign_rhs_code (stmt);
	if (code == SSA_NAME)
	  {
	    tree newrhs = valueizerf (rhs1);
	    return newrhs == rhs1 ? NULL : newrhs;
	   }

	switch (get_gimple_rhs_class (code))
	  {
	    /* We don't handle these yet except SSA_NAME
	       which is done above. */
	    case GIMPLE_SINGLE_RHS:
	      return NULL_TREE;
	    case GIMPLE_BINARY_RHS:
	       return gimple_combine_binary (loc, code, ltype, rhs1, rhs2);
	    case GIMPLE_TERNARY_RHS:
	       return gimple_combine_ternary (loc, code, ltype, rhs1, rhs2,
					      rhs3);
	    case GIMPLE_UNARY_RHS:
	      return gimple_combine_unary (loc, code, ltype, rhs1);
	    default:
              gcc_unreachable ();
	  }
	break;
      }

    case GIMPLE_SWITCH:
      return simplify_gimple_switch (stmt);
      break;

    case GIMPLE_COND:
      return forward_propagate_into_gimple_cond (stmt);
      break;

    case GIMPLE_CALL:
    default:;
    }

  return NULL_TREE;
}

bool
replace_rhs_after_ssa_combine (gimple_stmt_iterator *gsi, tree newexpr)
{
  gimple stmt;

  if (newexpr == NULL_TREE)
    return false;

  stmt = gsi_stmt (*gsi);
  switch (gimple_code (stmt))
    {
    case GIMPLE_ASSIGN:
      {
	newexpr = force_gimple_operand_gsi (gsi, newexpr, false, NULL, true,
					    GSI_SAME_STMT);
	gimple_assign_set_rhs_from_tree (gsi, newexpr);
	update_stmt (gsi_stmt (*gsi));
	return true;
      }

    case GIMPLE_SWITCH:
      {
	newexpr = force_gimple_operand_gsi (gsi, newexpr, true, NULL, true,
					    GSI_SAME_STMT);
	gimple_switch_set_index (gsi_stmt (*gsi), newexpr);
	update_stmt (gsi_stmt (*gsi));
	return true;
      }
      break;

    case GIMPLE_COND:
      {
	bool reversed_edges = false;
	if (TREE_CODE (newexpr) == TRUTH_NOT_EXPR
	    || TREE_CODE (newexpr) == BIT_NOT_EXPR)
	  {
	    reversed_edges = true;
	    newexpr = TREE_OPERAND (newexpr, 0);
	  }

	/* Since we might not get a comparison out of the folding. */
	if (!COMPARISON_CLASS_P (newexpr))
	  newexpr = build2 (NE_EXPR, boolean_type_node, newexpr,
			    build_zero_cst (TREE_TYPE (newexpr)));

	newexpr = force_gimple_operand_gsi (gsi, newexpr, false, NULL, true,
					    GSI_SAME_STMT);
	newexpr = canonicalize_cond_expr_cond (newexpr);
	if (newexpr == NULL_TREE)
	  return false;
	gimple_cond_set_condition_from_tree (stmt, unshare_expr (newexpr));
	if (reversed_edges)
	  {
	    basic_block bb = gimple_bb (stmt);
	    EDGE_SUCC (bb, 0)->flags ^= (EDGE_TRUE_VALUE|EDGE_FALSE_VALUE);
	    EDGE_SUCC (bb, 1)->flags ^= (EDGE_TRUE_VALUE|EDGE_FALSE_VALUE);
	  }
	update_stmt (gsi_stmt (*gsi));
	return true;
      }
      break;

    case GIMPLE_CALL:
      /* Handle replacing calls with simple expressions like constants. */
      return false;

    default:;
    }
  return false;
}

