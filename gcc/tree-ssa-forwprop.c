/* Forward propagation of expressions for single use variables.
   Copyright (C) 2004, 2005, 2007, 2008 Free Software Foundation, Inc.

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
#include "ggc.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "basic-block.h"
#include "timevar.h"
#include "diagnostic.h"
#include "tree-flow.h"
#include "tree-pass.h"
#include "tree-dump.h"
#include "langhooks.h"
#include "flags.h"

/* This pass propagates the RHS of assignment statements into use
   sites of the LHS of the assignment.  It's basically a specialized
   form of tree combination.   It is hoped all of this can disappear
   when we have a generalized tree combiner.

   Note carefully that after propagation the resulting statement
   must still be a proper gimple statement.  Right now we simply
   only perform propagations we know will result in valid gimple
   code.  One day we'll want to generalize this code.

   One class of common cases we handle is forward propagating a single use
   variable into a COND_EXPR.  

     bb0:
       x = a COND b;
       if (x) goto ... else goto ...

   Will be transformed into:

     bb0:
       if (a COND b) goto ... else goto ...
 
   Similarly for the tests (x == 0), (x != 0), (x == 1) and (x != 1).

   Or (assuming c1 and c2 are constants):

     bb0:
       x = a + c1;  
       if (x EQ/NEQ c2) goto ... else goto ...

   Will be transformed into:

     bb0:
        if (a EQ/NEQ (c2 - c1)) goto ... else goto ...

   Similarly for x = a - c1.
    
   Or

     bb0:
       x = !a
       if (x) goto ... else goto ...

   Will be transformed into:

     bb0:
        if (a == 0) goto ... else goto ...

   Similarly for the tests (x == 0), (x != 0), (x == 1) and (x != 1).
   For these cases, we propagate A into all, possibly more than one,
   COND_EXPRs that use X.

   Or

     bb0:
       x = (typecast) a
       if (x) goto ... else goto ...

   Will be transformed into:

     bb0:
        if (a != 0) goto ... else goto ...

   (Assuming a is an integral type and x is a boolean or x is an
    integral and a is a boolean.)

   Similarly for the tests (x == 0), (x != 0), (x == 1) and (x != 1).
   For these cases, we propagate A into all, possibly more than one,
   COND_EXPRs that use X.

   In addition to eliminating the variable and the statement which assigns
   a value to the variable, we may be able to later thread the jump without
   adding insane complexity in the dominator optimizer.

   Also note these transformations can cascade.  We handle this by having
   a worklist of COND_EXPR statements to examine.  As we make a change to
   a statement, we put it back on the worklist to examine on the next
   iteration of the main loop.

   A second class of propagation opportunities arises for ADDR_EXPR
   nodes.

     ptr = &x->y->z;
     res = *ptr;

   Will get turned into

     res = x->y->z;

   Or
     ptr = (type1*)&type2var;
     res = *ptr

   Will get turned into (if type1 and type2 are the same size
   and neither have volatile on them):
     res = VIEW_CONVERT_EXPR<type1>(type2var)

   Or

     ptr = &x[0];
     ptr2 = ptr + <constant>;

   Will get turned into

     ptr2 = &x[constant/elementsize];

  Or

     ptr = &x[0];
     offset = index * element_size;
     offset_p = (pointer) offset;
     ptr2 = ptr + offset_p

  Will get turned into:

     ptr2 = &x[index];

  We also propagate casts into SWITCH_EXPR and COND_EXPR conditions to
  allow us to remove the cast and {NOT_EXPR,NEG_EXPR} into a subsequent
  {NOT_EXPR,NEG_EXPR}.

   This will (of course) be extended as other needs arise.  */

static bool forward_propagate_addr_expr (tree name, tree rhs);

/* Set to true if we delete EH edges during the optimization.  */
static bool cfg_changed;


/* Get the next statement we can propagate NAME's value into skipping
   trivial copies.  Returns the statement that is suitable as a
   propagation destination or NULL_TREE if there is no such one.
   This only returns destinations in a single-use chain.  FINAL_NAME_P
   if non-NULL is written to the ssa name that represents the use.  */

static tree
get_prop_dest_stmt (tree name, tree *final_name_p)
{
  use_operand_p use;
  tree use_stmt;

  do {
    /* If name has multiple uses, bail out.  */
    if (!single_imm_use (name, &use, &use_stmt))
      return NULL_TREE;

    /* If this is not a trivial copy, we found it.  */
    if (TREE_CODE (use_stmt) != GIMPLE_MODIFY_STMT
	|| TREE_CODE (GIMPLE_STMT_OPERAND (use_stmt, 0)) != SSA_NAME
	|| GIMPLE_STMT_OPERAND (use_stmt, 1) != name)
      break;

    /* Continue searching uses of the copy destination.  */
    name = GIMPLE_STMT_OPERAND (use_stmt, 0);
  } while (1);

  if (final_name_p)
    *final_name_p = name;

  return use_stmt;
}

/* Get the statement we can propagate from into NAME skipping
   trivial copies.  Returns the statement which defines the
   propagation source or NULL_TREE if there is no such one.
   If SINGLE_USE_ONLY is set considers only sources which have
   a single use chain up to NAME.  If SINGLE_USE_P is non-null,
   it is set to whether the chain to NAME is a single use chain
   or not.  SINGLE_USE_P is not written to if SINGLE_USE_ONLY is set.  */

static tree
get_prop_source_stmt (tree name, bool single_use_only, bool *single_use_p)
{
  bool single_use = true;

  do {
    tree def_stmt = SSA_NAME_DEF_STMT (name);

    if (!has_single_use (name))
      {
	single_use = false;
	if (single_use_only)
	  return NULL_TREE;
      }

    /* If name is defined by a PHI node or is the default def, bail out.  */
    if (TREE_CODE (def_stmt) != GIMPLE_MODIFY_STMT)
      return NULL_TREE;

    /* If name is not a simple copy destination, we found it.  */
    if (TREE_CODE (GIMPLE_STMT_OPERAND (def_stmt, 1)) != SSA_NAME)
      {
	tree rhs;

	if (!single_use_only && single_use_p)
	  *single_use_p = single_use;

	/* We can look through pointer conversions in the search
	   for a useful stmt for the comparison folding.  */
	rhs = GIMPLE_STMT_OPERAND (def_stmt, 1);
	if (CONVERT_EXPR_P (rhs)
	    && TREE_CODE (TREE_OPERAND (rhs, 0)) == SSA_NAME
	    && POINTER_TYPE_P (TREE_TYPE (rhs))
	    && POINTER_TYPE_P (TREE_TYPE (TREE_OPERAND (rhs, 0))))
	  name = TREE_OPERAND (rhs, 0);
	else
	  return def_stmt;
      }
    else
      {
	/* Continue searching the def of the copy source name.  */
	name = GIMPLE_STMT_OPERAND (def_stmt, 1);
      }
  } while (1);
}

/* Checks if the destination ssa name in DEF_STMT can be used as
   propagation source.  Returns true if so, otherwise false.  */

static bool
can_propagate_from (tree def_stmt)
{
  tree rhs = GIMPLE_STMT_OPERAND (def_stmt, 1);
  use_operand_p use_p;
  ssa_op_iter iter;

  /* If the rhs has side-effects we cannot propagate from it.  */
  if (TREE_SIDE_EFFECTS (rhs))
    return false;

  /* If the rhs is a load we cannot propagate from it.  */
  if (REFERENCE_CLASS_P (rhs)
      || DECL_P (rhs))
    return false;

  /* Constants can be always propagated.  */
  if (is_gimple_min_invariant (rhs))
    return true;

  /* If any of the SSA operands occurs in abnormal PHIs we cannot
     propagate from this stmt.  */
  FOR_EACH_SSA_USE_OPERAND (use_p, def_stmt, iter, SSA_OP_USE)
    if (SSA_NAME_OCCURS_IN_ABNORMAL_PHI (USE_FROM_PTR (use_p)))
      return false;

  /* If the definition is a conversion of a pointer to a function type,
     then we can not apply optimizations as some targets require function
     pointers to be canonicalized and in this case this optimization could
     eliminate a necessary canonicalization.  */
  if (CONVERT_EXPR_P (rhs)
      && POINTER_TYPE_P (TREE_TYPE (TREE_OPERAND (rhs, 0)))
      && TREE_CODE (TREE_TYPE (TREE_TYPE
			        (TREE_OPERAND (rhs, 0)))) == FUNCTION_TYPE)
    return false;

  return true;
}

/* Remove a copy chain ending in NAME along the defs but not
   further or including UP_TO_STMT.  If NAME was replaced in
   its only use then this function can be used to clean up
   dead stmts.  Returns true if UP_TO_STMT can be removed
   as well, otherwise false.  */

static bool
remove_prop_source_from_use (tree name, tree up_to_stmt)
{
  block_stmt_iterator bsi;
  tree stmt;

  do {
    if (!has_zero_uses (name))
      return false;

    stmt = SSA_NAME_DEF_STMT (name);
    if (stmt == up_to_stmt)
      return true;

    bsi = bsi_for_stmt (stmt);
    release_defs (stmt);
    bsi_remove (&bsi, true);

    name = GIMPLE_STMT_OPERAND (stmt, 1);
  } while (TREE_CODE (name) == SSA_NAME);

  return false;
}

/* Combine OP0 CODE OP1 in the context of a COND_EXPR.  Returns
   the folded result in a form suitable for COND_EXPR_COND or
   NULL_TREE, if there is no suitable simplified form.  If
   INVARIANT_ONLY is true only gimple_min_invariant results are
   considered simplified.  */

static tree
combine_cond_expr_cond (enum tree_code code, tree type,
			tree op0, tree op1, bool invariant_only)
{
  tree t;

  gcc_assert (TREE_CODE_CLASS (code) == tcc_comparison);

  t = fold_binary (code, type, op0, op1);
  if (!t)
    return NULL_TREE;

  /* Require that we got a boolean type out if we put one in.  */
  gcc_assert (TREE_CODE (TREE_TYPE (t)) == TREE_CODE (type));

  /* Canonicalize the combined condition for use in a COND_EXPR.  */
  t = canonicalize_cond_expr_cond (t);

  /* Bail out if we required an invariant but didn't get one.  */
  if (!t
      || (invariant_only
	  && !is_gimple_min_invariant (t)))
    return NULL_TREE;

  return t;
}

/* Propagate from the ssa name definition statements of COND_EXPR
   in statement STMT into the conditional if that simplifies it.
   Returns zero if no statement was changed, one if there were
   changes and two if cfg_cleanup needs to run.  */

static int
forward_propagate_into_cond (tree cond_expr, tree stmt)
{
  int did_something = 0;

  do {
    tree tmp = NULL_TREE;
    tree cond = COND_EXPR_COND (cond_expr);
    tree name, def_stmt, rhs0 = NULL_TREE, rhs1 = NULL_TREE;
    bool single_use0_p = false, single_use1_p = false;

    /* We can do tree combining on SSA_NAME and comparison expressions.  */
    if (COMPARISON_CLASS_P (cond)
	&& TREE_CODE (TREE_OPERAND (cond, 0)) == SSA_NAME)
      {
	/* For comparisons use the first operand, that is likely to
	   simplify comparisons against constants.  */
	name = TREE_OPERAND (cond, 0);
	def_stmt = get_prop_source_stmt (name, false, &single_use0_p);
	if (def_stmt != NULL_TREE
	    && can_propagate_from (def_stmt))
	  {
	    tree op1 = TREE_OPERAND (cond, 1);
	    rhs0 = GIMPLE_STMT_OPERAND (def_stmt, 1);
	    tmp = combine_cond_expr_cond (TREE_CODE (cond), boolean_type_node,
				          fold_convert (TREE_TYPE (op1), rhs0),
				          op1, !single_use0_p);
	  }
	/* If that wasn't successful, try the second operand.  */
	if (tmp == NULL_TREE
	    && TREE_CODE (TREE_OPERAND (cond, 1)) == SSA_NAME)
	  {
	    tree op0 = TREE_OPERAND (cond, 0);
	    name = TREE_OPERAND (cond, 1);
	    def_stmt = get_prop_source_stmt (name, false, &single_use1_p);
	    if (def_stmt == NULL_TREE
	        || !can_propagate_from (def_stmt))
	      return did_something;

	    rhs1 = GIMPLE_STMT_OPERAND (def_stmt, 1);
	    tmp = combine_cond_expr_cond (TREE_CODE (cond), boolean_type_node,
					  op0,
				          fold_convert (TREE_TYPE (op0), rhs1),
					  !single_use1_p);
	  }
	/* If that wasn't successful either, try both operands.  */
	if (tmp == NULL_TREE
	    && rhs0 != NULL_TREE
	    && rhs1 != NULL_TREE)
	  tmp = combine_cond_expr_cond (TREE_CODE (cond), boolean_type_node,
					rhs0,
				        fold_convert (TREE_TYPE (rhs0), rhs1),
					!(single_use0_p && single_use1_p));
      }
    else if (TREE_CODE (cond) == SSA_NAME)
      {
	name = cond;
	def_stmt = get_prop_source_stmt (name, true, NULL);
	if (def_stmt == NULL_TREE
	    || !can_propagate_from (def_stmt))
	  return did_something;

	rhs0 = GIMPLE_STMT_OPERAND (def_stmt, 1);
	tmp = combine_cond_expr_cond (NE_EXPR, boolean_type_node, rhs0,
				      build_int_cst (TREE_TYPE (rhs0), 0),
				      false);
      }

    if (tmp)
      {
	if (dump_file && tmp)
	  {
	    fprintf (dump_file, "  Replaced '");
	    print_generic_expr (dump_file, cond, 0);
	    fprintf (dump_file, "' with '");
	    print_generic_expr (dump_file, tmp, 0);
	    fprintf (dump_file, "'\n");
	  }

	COND_EXPR_COND (cond_expr) = unshare_expr (tmp);
	update_stmt (stmt);

	/* Remove defining statements.  */
	remove_prop_source_from_use (name, NULL);

	if (is_gimple_min_invariant (tmp))
	  did_something = 2;
	else if (did_something == 0)
	  did_something = 1;

	/* Continue combining.  */
	continue;
      }

    break;
  } while (1);

  return did_something;
}

/* We've just substituted an ADDR_EXPR into stmt.  Update all the 
   relevant data structures to match.  */

static void
tidy_after_forward_propagate_addr (tree stmt)
{
  /* We may have turned a trapping insn into a non-trapping insn.  */
  if (maybe_clean_or_replace_eh_stmt (stmt, stmt)
      && tree_purge_dead_eh_edges (bb_for_stmt (stmt)))
    cfg_changed = true;

  if (TREE_CODE (GIMPLE_STMT_OPERAND (stmt, 1)) == ADDR_EXPR)
     recompute_tree_invariant_for_addr_expr (GIMPLE_STMT_OPERAND (stmt, 1));

  mark_symbols_for_renaming (stmt);
}

/* DEF_RHS contains the address of the 0th element in an array. 
   USE_STMT uses type of DEF_RHS to compute the address of an
   arbitrary element within the array.  The (variable) byte offset
   of the element is contained in OFFSET.

   We walk back through the use-def chains of OFFSET to verify that
   it is indeed computing the offset of an element within the array
   and extract the index corresponding to the given byte offset.

   We then try to fold the entire address expression into a form
   &array[index].

   If we are successful, we replace the right hand side of USE_STMT
   with the new address computation.  */

static bool
forward_propagate_addr_into_variable_array_index (tree offset,
						  tree def_rhs, tree use_stmt)
{
  tree index;

  /* Try to find an expression for a proper index.  This is either
     a multiplication expression by the element size or just the
     ssa name we came along in case the element size is one.  */
  if (integer_onep (TYPE_SIZE_UNIT (TREE_TYPE (TREE_TYPE (def_rhs)))))
    index = offset;
  else
    {
      /* Get the offset's defining statement.  */
      offset = SSA_NAME_DEF_STMT (offset);

      /* The statement which defines OFFSET before type conversion
         must be a simple GIMPLE_MODIFY_STMT.  */
      if (TREE_CODE (offset) != GIMPLE_MODIFY_STMT)
	return false;

      /* The RHS of the statement which defines OFFSET must be a
	 multiplication of an object by the size of the array elements. 
	 This implicitly verifies that the size of the array elements
	 is constant.  */
     offset = GIMPLE_STMT_OPERAND (offset, 1);
      if (TREE_CODE (offset) != MULT_EXPR
	  || TREE_CODE (TREE_OPERAND (offset, 1)) != INTEGER_CST
	  || !simple_cst_equal (TREE_OPERAND (offset, 1),
				TYPE_SIZE_UNIT (TREE_TYPE (TREE_TYPE (def_rhs)))))
	return false;

      /* The first operand to the MULT_EXPR is the desired index.  */
      index = TREE_OPERAND (offset, 0);
    }

  /* Replace the pointer addition with array indexing.  */
  GIMPLE_STMT_OPERAND (use_stmt, 1) = unshare_expr (def_rhs);
  TREE_OPERAND (TREE_OPERAND (GIMPLE_STMT_OPERAND (use_stmt, 1), 0), 1)
    = index;

  /* That should have created gimple, so there is no need to
     record information to undo the propagation.  */
  fold_stmt_inplace (use_stmt);
  tidy_after_forward_propagate_addr (use_stmt);
  return true;
}

/* NAME is a SSA_NAME representing DEF_RHS which is of the form
   ADDR_EXPR <whatever>.

   Try to forward propagate the ADDR_EXPR into the use USE_STMT.
   Often this will allow for removal of an ADDR_EXPR and INDIRECT_REF
   node or for recovery of array indexing from pointer arithmetic.
   
   Return true if the propagation was successful (the propagation can
   be not totally successful, yet things may have been changed).  */

static bool
forward_propagate_addr_expr_1 (tree name, tree def_rhs, tree use_stmt,
			       bool single_use_p)
{
  tree lhs, rhs, array_ref;
  tree *rhsp, *lhsp;

  gcc_assert (TREE_CODE (def_rhs) == ADDR_EXPR);

  lhs = GIMPLE_STMT_OPERAND (use_stmt, 0);
  rhs = GIMPLE_STMT_OPERAND (use_stmt, 1);

  /* Trivial cases.  The use statement could be a trivial copy or a
     useless conversion.  Recurse to the uses of the lhs as copyprop does
     not copy through different variant pointers and FRE does not catch
     all useless conversions.  Treat the case of a single-use name and
     a conversion to def_rhs type separate, though.  */
  if (TREE_CODE (lhs) == SSA_NAME
      && (rhs == name
	  || CONVERT_EXPR_P (rhs))
      && useless_type_conversion_p (TREE_TYPE (rhs), TREE_TYPE (def_rhs)))
    {
      /* Only recurse if we don't deal with a single use.  */
      if (!single_use_p)
	return forward_propagate_addr_expr (lhs, def_rhs);

      GIMPLE_STMT_OPERAND (use_stmt, 1) = unshare_expr (def_rhs);
      return true;
    }

  /* Now strip away any outer COMPONENT_REF/ARRAY_REF nodes from the LHS. 
     ADDR_EXPR will not appear on the LHS.  */
  lhsp = &GIMPLE_STMT_OPERAND (use_stmt, 0);
  while (handled_component_p (*lhsp))
    lhsp = &TREE_OPERAND (*lhsp, 0);
  lhs = *lhsp;

  /* Now see if the LHS node is an INDIRECT_REF using NAME.  If so, 
     propagate the ADDR_EXPR into the use of NAME and fold the result.  */
  if (TREE_CODE (lhs) == INDIRECT_REF
      && TREE_OPERAND (lhs, 0) == name
      && useless_type_conversion_p (TREE_TYPE (TREE_OPERAND (lhs, 0)),
				    TREE_TYPE (def_rhs))
      /* ???  This looks redundant, but is required for bogus types
	 that can sometimes occur.  */
      && useless_type_conversion_p (TREE_TYPE (lhs),
				    TREE_TYPE (TREE_OPERAND (def_rhs, 0))))
    {
      *lhsp = unshare_expr (TREE_OPERAND (def_rhs, 0));
      fold_stmt_inplace (use_stmt);
      tidy_after_forward_propagate_addr (use_stmt);

      /* Continue propagating into the RHS if this was not the only use.  */
      if (single_use_p)
	return true;
    }

  /* Strip away any outer COMPONENT_REF, ARRAY_REF or ADDR_EXPR
     nodes from the RHS.  */
  rhsp = &GIMPLE_STMT_OPERAND (use_stmt, 1);
  while (handled_component_p (*rhsp)
	 || TREE_CODE (*rhsp) == ADDR_EXPR)
    rhsp = &TREE_OPERAND (*rhsp, 0);
  rhs = *rhsp;

  /* Now see if the RHS node is an INDIRECT_REF using NAME.  If so, 
     propagate the ADDR_EXPR into the use of NAME and fold the result.  */
  if (TREE_CODE (rhs) == INDIRECT_REF
      && TREE_OPERAND (rhs, 0) == name
      && useless_type_conversion_p (TREE_TYPE (TREE_OPERAND (rhs, 0)),
				    TREE_TYPE (def_rhs))
      /* ???  This looks redundant, but is required for bogus types
	 that can sometimes occur.  */
      && useless_type_conversion_p (TREE_TYPE (rhs),
				    TREE_TYPE (TREE_OPERAND (def_rhs, 0))))
    {
      *rhsp = unshare_expr (TREE_OPERAND (def_rhs, 0));
      fold_stmt_inplace (use_stmt);
      tidy_after_forward_propagate_addr (use_stmt);
      return true;
    }

  /* Now see if the RHS node is an INDIRECT_REF using NAME.  If so, 
     propagate the ADDR_EXPR into the use of NAME and try to
     create a VCE and fold the result.  */
  if (TREE_CODE (rhs) == INDIRECT_REF
      && TREE_OPERAND (rhs, 0) == name
      && TYPE_SIZE (TREE_TYPE (rhs))
      && TYPE_SIZE (TREE_TYPE (TREE_OPERAND (def_rhs, 0)))
      /* Function decls should not be used for VCE either as it could be
         a function descriptor that we want and not the actual function code.  */
      && TREE_CODE (TREE_OPERAND (def_rhs, 0)) != FUNCTION_DECL
      /* We should not convert volatile loads to non volatile loads. */
      && !TYPE_VOLATILE (TREE_TYPE (rhs))
      && !TYPE_VOLATILE (TREE_TYPE (TREE_OPERAND (def_rhs, 0)))
      && operand_equal_p (TYPE_SIZE (TREE_TYPE (rhs)),
			  TYPE_SIZE (TREE_TYPE (TREE_OPERAND (def_rhs, 0))), 0)) 
   {
      bool res = true;
      tree new_rhs = unshare_expr (TREE_OPERAND (def_rhs, 0));
      new_rhs = fold_build1 (VIEW_CONVERT_EXPR, TREE_TYPE (rhs), new_rhs);
      /* If we have folded the VCE, then we have to create a new statement.  */
      if (TREE_CODE (new_rhs) != VIEW_CONVERT_EXPR)
	{
	  block_stmt_iterator bsi = bsi_for_stmt (use_stmt);
	  new_rhs = force_gimple_operand_bsi (&bsi, new_rhs, true, NULL, true, BSI_SAME_STMT);
	  /* As we change the deference to a SSA_NAME, we need to return false to make sure that
	     the statement does not get removed.  */
	  res = false;
	}
      *rhsp = new_rhs;
      fold_stmt_inplace (use_stmt);
      tidy_after_forward_propagate_addr (use_stmt);
      return res;
   }

  /* If the use of the ADDR_EXPR is not a POINTER_PLUS_EXPR, there
     is nothing to do. */
  if (TREE_CODE (rhs) != POINTER_PLUS_EXPR
      || TREE_OPERAND (rhs, 0) != name)
    return false;

  /* The remaining cases are all for turning pointer arithmetic into
     array indexing.  They only apply when we have the address of
     element zero in an array.  If that is not the case then there
     is nothing to do.  */
  array_ref = TREE_OPERAND (def_rhs, 0);
  if (TREE_CODE (array_ref) != ARRAY_REF
      || TREE_CODE (TREE_TYPE (TREE_OPERAND (array_ref, 0))) != ARRAY_TYPE
      || !integer_zerop (TREE_OPERAND (array_ref, 1)))
    return false;

  /* Try to optimize &x[0] p+ C where C is a multiple of the size
     of the elements in X into &x[C/element size].  */
  if (TREE_CODE (TREE_OPERAND (rhs, 1)) == INTEGER_CST)
    {
      tree orig = unshare_expr (rhs);
      TREE_OPERAND (rhs, 0) = unshare_expr (def_rhs);

      /* If folding succeeds, then we have just exposed new variables
	 in USE_STMT which will need to be renamed.  If folding fails,
	 then we need to put everything back the way it was.  */
      if (fold_stmt_inplace (use_stmt))
	{
	  tidy_after_forward_propagate_addr (use_stmt);
	  return true;
	}
      else
	{
	  GIMPLE_STMT_OPERAND (use_stmt, 1) = orig;
	  update_stmt (use_stmt);
	  return false;
	}
    }

  /* Try to optimize &x[0] p+ OFFSET where OFFSET is defined by
     converting a multiplication of an index by the size of the
     array elements, then the result is converted into the proper
     type for the arithmetic.  */
  if (TREE_CODE (TREE_OPERAND (rhs, 1)) == SSA_NAME
      /* Avoid problems with IVopts creating PLUS_EXPRs with a
	 different type than their operands.  */
      && useless_type_conversion_p (TREE_TYPE (rhs), TREE_TYPE (name)))
    {
      bool res;
      
      res = forward_propagate_addr_into_variable_array_index (TREE_OPERAND (rhs, 1),
							      def_rhs, use_stmt);
      return res;
    }
  return false;
}

/* STMT is a statement of the form SSA_NAME = ADDR_EXPR <whatever>.

   Try to forward propagate the ADDR_EXPR into all uses of the SSA_NAME.
   Often this will allow for removal of an ADDR_EXPR and INDIRECT_REF
   node or for recovery of array indexing from pointer arithmetic.
   Returns true, if all uses have been propagated into.  */

static bool
forward_propagate_addr_expr (tree name, tree rhs)
{
  int stmt_loop_depth = bb_for_stmt (SSA_NAME_DEF_STMT (name))->loop_depth;
  imm_use_iterator iter;
  tree use_stmt;
  bool all = true;
  bool single_use_p = has_single_use (name);

  FOR_EACH_IMM_USE_STMT (use_stmt, iter, name)
    {
      bool result;
      tree use_rhs;

      /* If the use is not in a simple assignment statement, then
	 there is nothing we can do.  */
      if (TREE_CODE (use_stmt) != GIMPLE_MODIFY_STMT)
	{
	  all = false;
	  continue;
	}

      /* If the use is in a deeper loop nest, then we do not want
	to propagate the ADDR_EXPR into the loop as that is likely
	adding expression evaluations into the loop.  */
      if (bb_for_stmt (use_stmt)->loop_depth > stmt_loop_depth)
	{
	  all = false;
	  continue;
	}

      push_stmt_changes (&use_stmt);

      result = forward_propagate_addr_expr_1 (name, rhs, use_stmt,
					      single_use_p);
      all &= result;

      pop_stmt_changes (&use_stmt);

      /* Remove intermediate now unused copy and conversion chains.  */
      use_rhs = GIMPLE_STMT_OPERAND (use_stmt, 1);
      if (result
	  && TREE_CODE (GIMPLE_STMT_OPERAND (use_stmt, 0)) == SSA_NAME
	  && (TREE_CODE (use_rhs) == SSA_NAME
	      || (CONVERT_EXPR_P (use_rhs)
		  && TREE_CODE (TREE_OPERAND (use_rhs, 0)) == SSA_NAME)))
	{
	  block_stmt_iterator bsi = bsi_for_stmt (use_stmt);
	  release_defs (use_stmt);
	  bsi_remove (&bsi, true);
	}
    }

  return all;
}

/* Forward propagate the comparison COND defined in STMT like
   cond_1 = x CMP y to uses of the form
     a_1 = (T')cond_1
     a_1 = !cond_1
     a_1 = cond_1 != 0
   Returns true if stmt is now unused.  */

static bool
forward_propagate_comparison (tree cond, tree stmt)
{
  tree name = GIMPLE_STMT_OPERAND (stmt, 0);
  tree use_stmt, tmp = NULL_TREE;

  /* Don't propagate ssa names that occur in abnormal phis.  */
  if ((TREE_CODE (TREE_OPERAND (cond, 0)) == SSA_NAME
       && SSA_NAME_OCCURS_IN_ABNORMAL_PHI (TREE_OPERAND (cond, 0)))
      || (TREE_CODE (TREE_OPERAND (cond, 1)) == SSA_NAME
	  && SSA_NAME_OCCURS_IN_ABNORMAL_PHI (TREE_OPERAND (cond, 1))))
    return false;

  /* Do not un-cse comparisons.  But propagate through copies.  */
  use_stmt = get_prop_dest_stmt (name, &name);
  if (use_stmt == NULL_TREE)
    return false;

  /* Conversion of the condition result to another integral type.  */
  if (TREE_CODE (use_stmt) == GIMPLE_MODIFY_STMT
      && (CONVERT_EXPR_P (GIMPLE_STMT_OPERAND (use_stmt, 1))
          || COMPARISON_CLASS_P (GIMPLE_STMT_OPERAND (use_stmt, 1))
          || TREE_CODE (GIMPLE_STMT_OPERAND (use_stmt, 1)) == TRUTH_NOT_EXPR)
      && INTEGRAL_TYPE_P (TREE_TYPE (GIMPLE_STMT_OPERAND (use_stmt, 0))))
    {
      tree lhs = GIMPLE_STMT_OPERAND (use_stmt, 0);
      tree rhs = GIMPLE_STMT_OPERAND (use_stmt, 1);

      /* We can propagate the condition into a conversion.  */
      if (CONVERT_EXPR_P (rhs))
	{
	  /* Avoid using fold here as that may create a COND_EXPR with
	     non-boolean condition as canonical form.  */
	  tmp = build2 (TREE_CODE (cond), TREE_TYPE (lhs),
			TREE_OPERAND (cond, 0), TREE_OPERAND (cond, 1));
	}
      /* We can propagate the condition into X op CST where op
	 is EQ_EXPR or NE_EXPR and CST is either one or zero.  */
      else if (COMPARISON_CLASS_P (rhs)
	       && TREE_CODE (TREE_OPERAND (rhs, 0)) == SSA_NAME
	       && TREE_CODE (TREE_OPERAND (rhs, 1)) == INTEGER_CST)
	{
	  enum tree_code code = TREE_CODE (rhs);
	  tree cst = TREE_OPERAND (rhs, 1);

	  tmp = combine_cond_expr_cond (code, TREE_TYPE (lhs),
					fold_convert (TREE_TYPE (cst), cond),
					cst, false);
	  if (tmp == NULL_TREE)
	    return false;
	}
      /* We can propagate the condition into a statement that
	 computes the logical negation of the comparison result.  */
      else if (TREE_CODE (rhs) == TRUTH_NOT_EXPR)
	{
	  tree type = TREE_TYPE (TREE_OPERAND (cond, 0));
	  bool nans = HONOR_NANS (TYPE_MODE (type));
	  enum tree_code code;
	  code = invert_tree_comparison (TREE_CODE (cond), nans);
	  if (code == ERROR_MARK)
	    return false;

	  tmp = build2 (code, TREE_TYPE (lhs), TREE_OPERAND (cond, 0),
			TREE_OPERAND (cond, 1));
	}
      else
	return false;

      GIMPLE_STMT_OPERAND (use_stmt, 1) = unshare_expr (tmp);
      update_stmt (use_stmt);

      /* Remove defining statements.  */
      remove_prop_source_from_use (name, stmt);

      if (dump_file && (dump_flags & TDF_DETAILS))
	{
	  fprintf (dump_file, "  Replaced '");
	  print_generic_expr (dump_file, rhs, dump_flags);
	  fprintf (dump_file, "' with '");
	  print_generic_expr (dump_file, tmp, dump_flags);
	  fprintf (dump_file, "'\n");
	}

      return true;
    }

  return false;
}

/* If we have lhs = ~x (STMT), look and see if earlier we had x = ~y.
   If so, we can change STMT into lhs = y which can later be copy
   propagated.  Similarly for negation. 

   This could trivially be formulated as a forward propagation 
   to immediate uses.  However, we already had an implementation
   from DOM which used backward propagation via the use-def links.

   It turns out that backward propagation is actually faster as
   there's less work to do for each NOT/NEG expression we find.
   Backwards propagation needs to look at the statement in a single
   backlink.  Forward propagation needs to look at potentially more
   than one forward link.  */

static void
simplify_not_neg_expr (tree stmt)
{
  tree rhs = GIMPLE_STMT_OPERAND (stmt, 1);
  tree rhs_def_stmt = SSA_NAME_DEF_STMT (TREE_OPERAND (rhs, 0));

  /* See if the RHS_DEF_STMT has the same form as our statement.  */
  if (TREE_CODE (rhs_def_stmt) == GIMPLE_MODIFY_STMT
      && TREE_CODE (GIMPLE_STMT_OPERAND (rhs_def_stmt, 1)) == TREE_CODE (rhs))
    {
      tree rhs_def_operand =
	TREE_OPERAND (GIMPLE_STMT_OPERAND (rhs_def_stmt, 1), 0);

      /* Verify that RHS_DEF_OPERAND is a suitable SSA_NAME.  */
      if (TREE_CODE (rhs_def_operand) == SSA_NAME
	  && ! SSA_NAME_OCCURS_IN_ABNORMAL_PHI (rhs_def_operand))
	{
	  GIMPLE_STMT_OPERAND (stmt, 1) = rhs_def_operand;
	  update_stmt (stmt);
	}
    }
}

/* STMT is a SWITCH_EXPR for which we attempt to find equivalent forms of
   the condition which we may be able to optimize better.  */

static void
simplify_switch_expr (tree stmt)
{
  tree cond = SWITCH_COND (stmt);
  tree def, to, ti;

  /* The optimization that we really care about is removing unnecessary
     casts.  That will let us do much better in propagating the inferred
     constant at the switch target.  */
  if (TREE_CODE (cond) == SSA_NAME)
    {
      def = SSA_NAME_DEF_STMT (cond);
      if (TREE_CODE (def) == GIMPLE_MODIFY_STMT)
	{
	  def = GIMPLE_STMT_OPERAND (def, 1);
	  if (TREE_CODE (def) == NOP_EXPR)
	    {
	      int need_precision;
	      bool fail;

	      def = TREE_OPERAND (def, 0);

#ifdef ENABLE_CHECKING
	      /* ??? Why was Jeff testing this?  We are gimple...  */
	      gcc_assert (is_gimple_val (def));
#endif

	      to = TREE_TYPE (cond);
	      ti = TREE_TYPE (def);

	      /* If we have an extension that preserves value, then we
		 can copy the source value into the switch.  */

	      need_precision = TYPE_PRECISION (ti);
	      fail = false;
	      if (! INTEGRAL_TYPE_P (ti))
		fail = true;
	      else if (TYPE_UNSIGNED (to) && !TYPE_UNSIGNED (ti))
		fail = true;
	      else if (!TYPE_UNSIGNED (to) && TYPE_UNSIGNED (ti))
		need_precision += 1;
	      if (TYPE_PRECISION (to) < need_precision)
		fail = true;

	      if (!fail)
		{
		  SWITCH_COND (stmt) = def;
		  update_stmt (stmt);
		}
	    }
	}
    }
}

/* Main entry point for the forward propagation optimizer.  */

static unsigned int
tree_ssa_forward_propagate_single_use_vars (void)
{
  basic_block bb;
  unsigned int todoflags = 0;

  cfg_changed = false;

  FOR_EACH_BB (bb)
    {
      block_stmt_iterator bsi;

      /* Note we update BSI within the loop as necessary.  */
      for (bsi = bsi_start (bb); !bsi_end_p (bsi); )
	{
	  tree stmt = bsi_stmt (bsi);

	  /* If this statement sets an SSA_NAME to an address,
	     try to propagate the address into the uses of the SSA_NAME.  */
	  if (TREE_CODE (stmt) == GIMPLE_MODIFY_STMT)
	    {
	      tree lhs = GIMPLE_STMT_OPERAND (stmt, 0);
	      tree rhs = GIMPLE_STMT_OPERAND (stmt, 1);


	      if (TREE_CODE (lhs) != SSA_NAME)
		{
		  bsi_next (&bsi);
		  continue;
		}

	      if (TREE_CODE (rhs) == ADDR_EXPR
		  /* Handle pointer conversions on invariant addresses
		     as well, as this is valid gimple.  */
		  || (CONVERT_EXPR_P (rhs)
		      && TREE_CODE (TREE_OPERAND (rhs, 0)) == ADDR_EXPR
		      && POINTER_TYPE_P (TREE_TYPE (rhs))))
		{
		  STRIP_NOPS (rhs);
		  if (!stmt_references_abnormal_ssa_name (stmt)
		      && forward_propagate_addr_expr (lhs, rhs))
		    {
		      release_defs (stmt);
		      todoflags |= TODO_remove_unused_locals;
		      bsi_remove (&bsi, true);
		    }
		  else
		    bsi_next (&bsi);
		}
	      else if ((TREE_CODE (rhs) == BIT_NOT_EXPR
		        || TREE_CODE (rhs) == NEGATE_EXPR)
		       && TREE_CODE (TREE_OPERAND (rhs, 0)) == SSA_NAME)
		{
		  simplify_not_neg_expr (stmt);
		  bsi_next (&bsi);
		}
              else if (TREE_CODE (rhs) == COND_EXPR)
                {
		  int did_something;
		  fold_defer_overflow_warnings ();
                  did_something = forward_propagate_into_cond (rhs, stmt);
		  if (did_something == 2)
		    cfg_changed = true;
		  fold_undefer_overflow_warnings (!TREE_NO_WARNING (rhs)
		    && did_something, stmt, WARN_STRICT_OVERFLOW_CONDITIONAL);
		  bsi_next (&bsi);
                }
	      else if (COMPARISON_CLASS_P (rhs))
		{
		  if (forward_propagate_comparison (rhs, stmt))
		    {
		      release_defs (stmt);
		      todoflags |= TODO_remove_unused_locals;
		      bsi_remove (&bsi, true);
		    }
		  else
		    bsi_next (&bsi);
		}
	      else
		bsi_next (&bsi);
	    }
	  else if (TREE_CODE (stmt) == SWITCH_EXPR)
	    {
	      simplify_switch_expr (stmt);
	      bsi_next (&bsi);
	    }
	  else if (TREE_CODE (stmt) == COND_EXPR)
	    {
	      int did_something;
	      fold_defer_overflow_warnings ();
	      did_something = forward_propagate_into_cond (stmt, stmt);
	      if (did_something == 2)
		cfg_changed = true;
	      fold_undefer_overflow_warnings (did_something, stmt,
					      WARN_STRICT_OVERFLOW_CONDITIONAL);
	      bsi_next (&bsi);
	    }
	  else
	    bsi_next (&bsi);
	}
    }

  if (cfg_changed)
    todoflags |= TODO_cleanup_cfg;
  return todoflags;
}


static bool
gate_forwprop (void)
{
  return 1;
}

struct gimple_opt_pass pass_forwprop = 
{
 {
  GIMPLE_PASS,
  "forwprop",			/* name */
  gate_forwprop,		/* gate */
  tree_ssa_forward_propagate_single_use_vars,	/* execute */
  NULL,				/* sub */
  NULL,				/* next */
  0,				/* static_pass_number */
  TV_TREE_FORWPROP,		/* tv_id */
  PROP_cfg | PROP_ssa,		/* properties_required */
  0,				/* properties_provided */
  0,				/* properties_destroyed */
  0,				/* todo_flags_start */
  TODO_dump_func
  | TODO_ggc_collect
  | TODO_update_ssa
  | TODO_verify_ssa		/* todo_flags_finish */
 }
};

