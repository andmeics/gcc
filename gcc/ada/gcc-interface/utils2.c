/****************************************************************************
 *                                                                          *
 *                         GNAT COMPILER COMPONENTS                         *
 *                                                                          *
 *                               U T I L S 2                                *
 *                                                                          *
 *                          C Implementation File                           *
 *                                                                          *
 *          Copyright (C) 1992-2010, Free Software Foundation, Inc.         *
 *                                                                          *
 * GNAT is free software;  you can  redistribute it  and/or modify it under *
 * terms of the  GNU General Public License as published  by the Free Soft- *
 * ware  Foundation;  either version 3,  or (at your option) any later ver- *
 * sion.  GNAT is distributed in the hope that it will be useful, but WITH- *
 * OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License *
 * for  more details.  You should have received a copy of the GNU General   *
 * Public License along with GCC; see the file COPYING3.  If not see        *
 * <http://www.gnu.org/licenses/>.                                          *
 *                                                                          *
 * GNAT was originally developed  by the GNAT team at  New York University. *
 * Extensive contributions were provided by Ada Core Technologies Inc.      *
 *                                                                          *
 ****************************************************************************/

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "ggc.h"
#include "output.h"
#include "tree-inline.h"

#include "ada.h"
#include "types.h"
#include "atree.h"
#include "elists.h"
#include "namet.h"
#include "nlists.h"
#include "snames.h"
#include "stringt.h"
#include "uintp.h"
#include "fe.h"
#include "sinfo.h"
#include "einfo.h"
#include "ada-tree.h"
#include "gigi.h"

static tree find_common_type (tree, tree);
static tree compare_arrays (tree, tree, tree);
static tree nonbinary_modular_operation (enum tree_code, tree, tree, tree);
static tree build_simple_component_ref (tree, tree, tree, bool);

/* Return the base type of TYPE.  */

tree
get_base_type (tree type)
{
  if (TREE_CODE (type) == RECORD_TYPE
      && TYPE_JUSTIFIED_MODULAR_P (type))
    type = TREE_TYPE (TYPE_FIELDS (type));

  while (TREE_TYPE (type)
	 && (TREE_CODE (type) == INTEGER_TYPE
	     || TREE_CODE (type) == REAL_TYPE))
    type = TREE_TYPE (type);

  return type;
}

/* EXP is a GCC tree representing an address.  See if we can find how
   strictly the object at that address is aligned.   Return that alignment
   in bits.  If we don't know anything about the alignment, return 0.  */

unsigned int
known_alignment (tree exp)
{
  unsigned int this_alignment;
  unsigned int lhs, rhs;

  switch (TREE_CODE (exp))
    {
    CASE_CONVERT:
    case VIEW_CONVERT_EXPR:
    case NON_LVALUE_EXPR:
      /* Conversions between pointers and integers don't change the alignment
	 of the underlying object.  */
      this_alignment = known_alignment (TREE_OPERAND (exp, 0));
      break;

    case COMPOUND_EXPR:
      /* The value of a COMPOUND_EXPR is that of it's second operand.  */
      this_alignment = known_alignment (TREE_OPERAND (exp, 1));
      break;

    case PLUS_EXPR:
    case MINUS_EXPR:
      /* If two address are added, the alignment of the result is the
	 minimum of the two alignments.  */
      lhs = known_alignment (TREE_OPERAND (exp, 0));
      rhs = known_alignment (TREE_OPERAND (exp, 1));
      this_alignment = MIN (lhs, rhs);
      break;

    case POINTER_PLUS_EXPR:
      lhs = known_alignment (TREE_OPERAND (exp, 0));
      rhs = known_alignment (TREE_OPERAND (exp, 1));
      /* If we don't know the alignment of the offset, we assume that
	 of the base.  */
      if (rhs == 0)
	this_alignment = lhs;
      else
	this_alignment = MIN (lhs, rhs);
      break;

    case COND_EXPR:
      /* If there is a choice between two values, use the smallest one.  */
      lhs = known_alignment (TREE_OPERAND (exp, 1));
      rhs = known_alignment (TREE_OPERAND (exp, 2));
      this_alignment = MIN (lhs, rhs);
      break;

    case INTEGER_CST:
      {
	unsigned HOST_WIDE_INT c = TREE_INT_CST_LOW (exp);
	/* The first part of this represents the lowest bit in the constant,
	   but it is originally in bytes, not bits.  */
	this_alignment = MIN (BITS_PER_UNIT * (c & -c), BIGGEST_ALIGNMENT);
      }
      break;

    case MULT_EXPR:
      /* If we know the alignment of just one side, use it.  Otherwise,
	 use the product of the alignments.  */
      lhs = known_alignment (TREE_OPERAND (exp, 0));
      rhs = known_alignment (TREE_OPERAND (exp, 1));

      if (lhs == 0)
	this_alignment = rhs;
      else if (rhs == 0)
	this_alignment = lhs;
      else
	this_alignment = MIN (lhs * rhs, BIGGEST_ALIGNMENT);
      break;

    case BIT_AND_EXPR:
      /* A bit-and expression is as aligned as the maximum alignment of the
	 operands.  We typically get here for a complex lhs and a constant
	 negative power of two on the rhs to force an explicit alignment, so
	 don't bother looking at the lhs.  */
      this_alignment = known_alignment (TREE_OPERAND (exp, 1));
      break;

    case ADDR_EXPR:
      this_alignment = expr_align (TREE_OPERAND (exp, 0));
      break;

    case CALL_EXPR:
      {
	tree t = maybe_inline_call_in_expr (exp);
	if (t)
	  return known_alignment (t);
      }

      /* Fall through... */

    default:
      /* For other pointer expressions, we assume that the pointed-to object
	 is at least as aligned as the pointed-to type.  Beware that we can
	 have a dummy type here (e.g. a Taft Amendment type), for which the
	 alignment is meaningless and should be ignored.  */
      if (POINTER_TYPE_P (TREE_TYPE (exp))
	  && !TYPE_IS_DUMMY_P (TREE_TYPE (TREE_TYPE (exp))))
	this_alignment = TYPE_ALIGN (TREE_TYPE (TREE_TYPE (exp)));
      else
	this_alignment = 0;
      break;
    }

  return this_alignment;
}

/* We have a comparison or assignment operation on two types, T1 and T2, which
   are either both array types or both record types.  T1 is assumed to be for
   the left hand side operand, and T2 for the right hand side.  Return the
   type that both operands should be converted to for the operation, if any.
   Otherwise return zero.  */

static tree
find_common_type (tree t1, tree t2)
{
  /* ??? As of today, various constructs lead here with types of different
     sizes even when both constants (e.g. tagged types, packable vs regular
     component types, padded vs unpadded types, ...).  While some of these
     would better be handled upstream (types should be made consistent before
     calling into build_binary_op), some others are really expected and we
     have to be careful.  */

  /* We must prevent writing more than what the target may hold if this is for
     an assignment and the case of tagged types is handled in build_binary_op
     so use the lhs type if it is known to be smaller, or of constant size and
     the rhs type is not, whatever the modes.  We also force t1 in case of
     constant size equality to minimize occurrences of view conversions on the
     lhs of assignments.  */
  if (TREE_CONSTANT (TYPE_SIZE (t1))
      && (!TREE_CONSTANT (TYPE_SIZE (t2))
          || !tree_int_cst_lt (TYPE_SIZE (t2), TYPE_SIZE (t1))))
    return t1;

  /* Otherwise, if the lhs type is non-BLKmode, use it.  Note that we know
     that we will not have any alignment problems since, if we did, the
     non-BLKmode type could not have been used.  */
  if (TYPE_MODE (t1) != BLKmode)
    return t1;

  /* If the rhs type is of constant size, use it whatever the modes.  At
     this point it is known to be smaller, or of constant size and the
     lhs type is not.  */
  if (TREE_CONSTANT (TYPE_SIZE (t2)))
    return t2;

  /* Otherwise, if the rhs type is non-BLKmode, use it.  */
  if (TYPE_MODE (t2) != BLKmode)
    return t2;

  /* In this case, both types have variable size and BLKmode.  It's
     probably best to leave the "type mismatch" because changing it
     could cause a bad self-referential reference.  */
  return NULL_TREE;
}

/* Return an expression tree representing an equality comparison of A1 and A2,
   two objects of type ARRAY_TYPE.  The result should be of type RESULT_TYPE.

   Two arrays are equal in one of two ways: (1) if both have zero length in
   some dimension (not necessarily the same dimension) or (2) if the lengths
   in each dimension are equal and the data is equal.  We perform the length
   tests in as efficient a manner as possible.  */

static tree
compare_arrays (tree result_type, tree a1, tree a2)
{
  tree result = convert (result_type, boolean_true_node);
  tree a1_is_null = convert (result_type, boolean_false_node);
  tree a2_is_null = convert (result_type, boolean_false_node);
  tree t1 = TREE_TYPE (a1);
  tree t2 = TREE_TYPE (a2);
  bool a1_side_effects_p = TREE_SIDE_EFFECTS (a1);
  bool a2_side_effects_p = TREE_SIDE_EFFECTS (a2);
  bool length_zero_p = false;

  /* If either operand has side-effects, they have to be evaluated only once
     in spite of the multiple references to the operand in the comparison.  */
  if (a1_side_effects_p)
    a1 = gnat_protect_expr (a1);

  if (a2_side_effects_p)
    a2 = gnat_protect_expr (a2);

  /* Process each dimension separately and compare the lengths.  If any
     dimension has a length known to be zero, set LENGTH_ZERO_P to true
     in order to suppress the comparison of the data at the end.  */
  while (TREE_CODE (t1) == ARRAY_TYPE && TREE_CODE (t2) == ARRAY_TYPE)
    {
      tree lb1 = TYPE_MIN_VALUE (TYPE_DOMAIN (t1));
      tree ub1 = TYPE_MAX_VALUE (TYPE_DOMAIN (t1));
      tree lb2 = TYPE_MIN_VALUE (TYPE_DOMAIN (t2));
      tree ub2 = TYPE_MAX_VALUE (TYPE_DOMAIN (t2));
      tree length1 = size_binop (PLUS_EXPR, size_binop (MINUS_EXPR, ub1, lb1),
				 size_one_node);
      tree length2 = size_binop (PLUS_EXPR, size_binop (MINUS_EXPR, ub2, lb2),
				 size_one_node);
      tree comparison, this_a1_is_null, this_a2_is_null;

      /* If the length of the first array is a constant, swap our operands
	 unless the length of the second array is the constant zero.  */
      if (TREE_CODE (length1) == INTEGER_CST && !integer_zerop (length2))
	{
	  tree tem;
	  bool btem;

	  tem = a1, a1 = a2, a2 = tem;
	  tem = t1, t1 = t2, t2 = tem;
	  tem = lb1, lb1 = lb2, lb2 = tem;
	  tem = ub1, ub1 = ub2, ub2 = tem;
	  tem = length1, length1 = length2, length2 = tem;
	  tem = a1_is_null, a1_is_null = a2_is_null, a2_is_null = tem;
	  btem = a1_side_effects_p, a1_side_effects_p = a2_side_effects_p,
	  a2_side_effects_p = btem;
	}

      /* If the length of the second array is the constant zero, we can just
	 use the original stored bounds for the first array and see whether
	 last < first holds.  */
      if (integer_zerop (length2))
	{
	  length_zero_p = true;

	  ub1 = TYPE_MAX_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t1)));
	  lb1 = TYPE_MIN_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t1)));

	  comparison = build_binary_op (LT_EXPR, result_type, ub1, lb1);
	  comparison = SUBSTITUTE_PLACEHOLDER_IN_EXPR (comparison, a1);
	  if (EXPR_P (comparison))
	    SET_EXPR_LOCATION (comparison, input_location);

	  this_a1_is_null = comparison;
	  this_a2_is_null = convert (result_type, boolean_true_node);
	}

      /* Otherwise, if the length is some other constant value, we know that
	 this dimension in the second array cannot be superflat, so we can
	 just use its length computed from the actual stored bounds.  */
      else if (TREE_CODE (length2) == INTEGER_CST)
	{
	  tree bt;

	  ub1 = TYPE_MAX_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t1)));
	  lb1 = TYPE_MIN_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t1)));
	  /* Note that we know that UB2 and LB2 are constant and hence
	     cannot contain a PLACEHOLDER_EXPR.  */
	  ub2 = TYPE_MAX_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t2)));
	  lb2 = TYPE_MIN_VALUE (TYPE_INDEX_TYPE (TYPE_DOMAIN (t2)));
	  bt = get_base_type (TREE_TYPE (ub1));

	  comparison
	    = build_binary_op (EQ_EXPR, result_type,
			       build_binary_op (MINUS_EXPR, bt, ub1, lb1),
			       build_binary_op (MINUS_EXPR, bt, ub2, lb2));
	  comparison = SUBSTITUTE_PLACEHOLDER_IN_EXPR (comparison, a1);
	  if (EXPR_P (comparison))
	    SET_EXPR_LOCATION (comparison, input_location);

	  this_a1_is_null = build_binary_op (LT_EXPR, result_type, ub1, lb1);
	  if (EXPR_P (this_a1_is_null))
	    SET_EXPR_LOCATION (this_a1_is_null, input_location);

	  this_a2_is_null = convert (result_type, boolean_false_node);
	}

      /* Otherwise, compare the computed lengths.  */
      else
	{
	  length1 = SUBSTITUTE_PLACEHOLDER_IN_EXPR (length1, a1);
	  length2 = SUBSTITUTE_PLACEHOLDER_IN_EXPR (length2, a2);

	  comparison
	    = build_binary_op (EQ_EXPR, result_type, length1, length2);
	  if (EXPR_P (comparison))
	    SET_EXPR_LOCATION (comparison, input_location);

	  /* If the length expression is of the form (cond ? val : 0), assume
	     that cond is equivalent to (length != 0).  That's guaranteed by
	     construction of the array types in gnat_to_gnu_entity.  */
	  if (TREE_CODE (length1) == COND_EXPR
	      && integer_zerop (TREE_OPERAND (length1, 2)))
	    this_a1_is_null = invert_truthvalue (TREE_OPERAND (length1, 0));
	  else
	    this_a1_is_null = build_binary_op (EQ_EXPR, result_type, length1,
					       size_zero_node);
          if (EXPR_P (this_a1_is_null))
	    SET_EXPR_LOCATION (this_a1_is_null, input_location);

	  /* Likewise for the second array.  */
	  if (TREE_CODE (length2) == COND_EXPR
	      && integer_zerop (TREE_OPERAND (length2, 2)))
	    this_a2_is_null = invert_truthvalue (TREE_OPERAND (length2, 0));
	  else
	    this_a2_is_null = build_binary_op (EQ_EXPR, result_type, length2,
					       size_zero_node);
          if (EXPR_P (this_a2_is_null))
	    SET_EXPR_LOCATION (this_a2_is_null, input_location);
	}

      /* Append expressions for this dimension to the final expressions.  */
      result = build_binary_op (TRUTH_ANDIF_EXPR, result_type,
				result, comparison);

      a1_is_null = build_binary_op (TRUTH_ORIF_EXPR, result_type,
				    this_a1_is_null, a1_is_null);

      a2_is_null = build_binary_op (TRUTH_ORIF_EXPR, result_type,
				    this_a2_is_null, a2_is_null);

      t1 = TREE_TYPE (t1);
      t2 = TREE_TYPE (t2);
    }

  /* Unless the length of some dimension is known to be zero, compare the
     data in the array.  */
  if (!length_zero_p)
    {
      tree type = find_common_type (TREE_TYPE (a1), TREE_TYPE (a2));
      tree comparison;

      if (type)
	{
	  a1 = convert (type, a1),
	  a2 = convert (type, a2);
	}

      comparison = fold_build2 (EQ_EXPR, result_type, a1, a2);
      if (EXPR_P (comparison))
	SET_EXPR_LOCATION (comparison, input_location);

      result
	= build_binary_op (TRUTH_ANDIF_EXPR, result_type, result, comparison);
    }

  /* The result is also true if both sizes are zero.  */
  result = build_binary_op (TRUTH_ORIF_EXPR, result_type,
			    build_binary_op (TRUTH_ANDIF_EXPR, result_type,
					     a1_is_null, a2_is_null),
			    result);

  /* If either operand has side-effects, they have to be evaluated before
     starting the comparison above since the place they would be otherwise
     evaluated could be wrong.  */
  if (a1_side_effects_p)
    result = build2 (COMPOUND_EXPR, result_type, a1, result);

  if (a2_side_effects_p)
    result = build2 (COMPOUND_EXPR, result_type, a2, result);

  return result;
}

/* Compute the result of applying OP_CODE to LHS and RHS, where both are of
   type TYPE.  We know that TYPE is a modular type with a nonbinary
   modulus.  */

static tree
nonbinary_modular_operation (enum tree_code op_code, tree type, tree lhs,
                             tree rhs)
{
  tree modulus = TYPE_MODULUS (type);
  unsigned int needed_precision = tree_floor_log2 (modulus) + 1;
  unsigned int precision;
  bool unsignedp = true;
  tree op_type = type;
  tree result;

  /* If this is an addition of a constant, convert it to a subtraction
     of a constant since we can do that faster.  */
  if (op_code == PLUS_EXPR && TREE_CODE (rhs) == INTEGER_CST)
    {
      rhs = fold_build2 (MINUS_EXPR, type, modulus, rhs);
      op_code = MINUS_EXPR;
    }

  /* For the logical operations, we only need PRECISION bits.  For
     addition and subtraction, we need one more and for multiplication we
     need twice as many.  But we never want to make a size smaller than
     our size. */
  if (op_code == PLUS_EXPR || op_code == MINUS_EXPR)
    needed_precision += 1;
  else if (op_code == MULT_EXPR)
    needed_precision *= 2;

  precision = MAX (needed_precision, TYPE_PRECISION (op_type));

  /* Unsigned will do for everything but subtraction.  */
  if (op_code == MINUS_EXPR)
    unsignedp = false;

  /* If our type is the wrong signedness or isn't wide enough, make a new
     type and convert both our operands to it.  */
  if (TYPE_PRECISION (op_type) < precision
      || TYPE_UNSIGNED (op_type) != unsignedp)
    {
      /* Copy the node so we ensure it can be modified to make it modular.  */
      op_type = copy_node (gnat_type_for_size (precision, unsignedp));
      modulus = convert (op_type, modulus);
      SET_TYPE_MODULUS (op_type, modulus);
      TYPE_MODULAR_P (op_type) = 1;
      lhs = convert (op_type, lhs);
      rhs = convert (op_type, rhs);
    }

  /* Do the operation, then we'll fix it up.  */
  result = fold_build2 (op_code, op_type, lhs, rhs);

  /* For multiplication, we have no choice but to do a full modulus
     operation.  However, we want to do this in the narrowest
     possible size.  */
  if (op_code == MULT_EXPR)
    {
      tree div_type = copy_node (gnat_type_for_size (needed_precision, 1));
      modulus = convert (div_type, modulus);
      SET_TYPE_MODULUS (div_type, modulus);
      TYPE_MODULAR_P (div_type) = 1;
      result = convert (op_type,
			fold_build2 (TRUNC_MOD_EXPR, div_type,
				     convert (div_type, result), modulus));
    }

  /* For subtraction, add the modulus back if we are negative.  */
  else if (op_code == MINUS_EXPR)
    {
      result = gnat_protect_expr (result);
      result = fold_build3 (COND_EXPR, op_type,
			    fold_build2 (LT_EXPR, boolean_type_node, result,
					 convert (op_type, integer_zero_node)),
			    fold_build2 (PLUS_EXPR, op_type, result, modulus),
			    result);
    }

  /* For the other operations, subtract the modulus if we are >= it.  */
  else
    {
      result = gnat_protect_expr (result);
      result = fold_build3 (COND_EXPR, op_type,
			    fold_build2 (GE_EXPR, boolean_type_node,
					 result, modulus),
			    fold_build2 (MINUS_EXPR, op_type,
					 result, modulus),
			    result);
    }

  return convert (type, result);
}

/* Make a binary operation of kind OP_CODE.  RESULT_TYPE is the type
   desired for the result.  Usually the operation is to be performed
   in that type.  For MODIFY_EXPR and ARRAY_REF, RESULT_TYPE may be 0
   in which case the type to be used will be derived from the operands.

   This function is very much unlike the ones for C and C++ since we
   have already done any type conversion and matching required.  All we
   have to do here is validate the work done by SEM and handle subtypes.  */

tree
build_binary_op (enum tree_code op_code, tree result_type,
                 tree left_operand, tree right_operand)
{
  tree left_type  = TREE_TYPE (left_operand);
  tree right_type = TREE_TYPE (right_operand);
  tree left_base_type = get_base_type (left_type);
  tree right_base_type = get_base_type (right_type);
  tree operation_type = result_type;
  tree best_type = NULL_TREE;
  tree modulus, result;
  bool has_side_effects = false;

  if (operation_type
      && TREE_CODE (operation_type) == RECORD_TYPE
      && TYPE_JUSTIFIED_MODULAR_P (operation_type))
    operation_type = TREE_TYPE (TYPE_FIELDS (operation_type));

  if (operation_type
      && !AGGREGATE_TYPE_P (operation_type)
      && TYPE_EXTRA_SUBTYPE_P (operation_type))
    operation_type = get_base_type (operation_type);

  modulus = (operation_type
	     && TREE_CODE (operation_type) == INTEGER_TYPE
	     && TYPE_MODULAR_P (operation_type)
	     ? TYPE_MODULUS (operation_type) : NULL_TREE);

  switch (op_code)
    {
    case INIT_EXPR:
    case MODIFY_EXPR:
      /* If there were integral or pointer conversions on the LHS, remove
	 them; we'll be putting them back below if needed.  Likewise for
	 conversions between array and record types, except for justified
	 modular types.  But don't do this if the right operand is not
	 BLKmode (for packed arrays) unless we are not changing the mode.  */
      while ((CONVERT_EXPR_P (left_operand)
	      || TREE_CODE (left_operand) == VIEW_CONVERT_EXPR)
	     && (((INTEGRAL_TYPE_P (left_type)
		   || POINTER_TYPE_P (left_type))
		  && (INTEGRAL_TYPE_P (TREE_TYPE
				       (TREE_OPERAND (left_operand, 0)))
		      || POINTER_TYPE_P (TREE_TYPE
					 (TREE_OPERAND (left_operand, 0)))))
		 || (((TREE_CODE (left_type) == RECORD_TYPE
		       && !TYPE_JUSTIFIED_MODULAR_P (left_type))
		      || TREE_CODE (left_type) == ARRAY_TYPE)
		     && ((TREE_CODE (TREE_TYPE
				     (TREE_OPERAND (left_operand, 0)))
			  == RECORD_TYPE)
			 || (TREE_CODE (TREE_TYPE
					(TREE_OPERAND (left_operand, 0)))
			     == ARRAY_TYPE))
		     && (TYPE_MODE (right_type) == BLKmode
			 || (TYPE_MODE (left_type)
			     == TYPE_MODE (TREE_TYPE
					   (TREE_OPERAND
					    (left_operand, 0))))))))
	{
	  left_operand = TREE_OPERAND (left_operand, 0);
	  left_type = TREE_TYPE (left_operand);
	}

      /* If a class-wide type may be involved, force use of the RHS type.  */
      if ((TREE_CODE (right_type) == RECORD_TYPE
	   || TREE_CODE (right_type) == UNION_TYPE)
	  && TYPE_ALIGN_OK (right_type))
	operation_type = right_type;

      /* If we are copying between padded objects with compatible types, use
	 the padded view of the objects, this is very likely more efficient.
	 Likewise for a padded object that is assigned a constructor, if we
	 can convert the constructor to the inner type, to avoid putting a
	 VIEW_CONVERT_EXPR on the LHS.  But don't do so if we wouldn't have
	 actually copied anything.  */
      else if (TYPE_IS_PADDING_P (left_type)
	       && TREE_CONSTANT (TYPE_SIZE (left_type))
	       && ((TREE_CODE (right_operand) == COMPONENT_REF
		    && TYPE_IS_PADDING_P
		       (TREE_TYPE (TREE_OPERAND (right_operand, 0)))
		    && gnat_types_compatible_p
		       (left_type,
			TREE_TYPE (TREE_OPERAND (right_operand, 0))))
		   || (TREE_CODE (right_operand) == CONSTRUCTOR
		       && !CONTAINS_PLACEHOLDER_P
			   (DECL_SIZE (TYPE_FIELDS (left_type)))))
	       && !integer_zerop (TYPE_SIZE (right_type)))
	operation_type = left_type;

      /* Find the best type to use for copying between aggregate types.  */
      else if (((TREE_CODE (left_type) == ARRAY_TYPE
		 && TREE_CODE (right_type) == ARRAY_TYPE)
		|| (TREE_CODE (left_type) == RECORD_TYPE
		    && TREE_CODE (right_type) == RECORD_TYPE))
	       && (best_type = find_common_type (left_type, right_type)))
	operation_type = best_type;

      /* Otherwise use the LHS type.  */
      else if (!operation_type)
	operation_type = left_type;

      /* Ensure everything on the LHS is valid.  If we have a field reference,
	 strip anything that get_inner_reference can handle.  Then remove any
	 conversions between types having the same code and mode.  And mark
	 VIEW_CONVERT_EXPRs with TREE_ADDRESSABLE.  When done, we must have
	 either an INDIRECT_REF, a NULL_EXPR or a DECL node.  */
      result = left_operand;
      while (true)
	{
	  tree restype = TREE_TYPE (result);

	  if (TREE_CODE (result) == COMPONENT_REF
	      || TREE_CODE (result) == ARRAY_REF
	      || TREE_CODE (result) == ARRAY_RANGE_REF)
	    while (handled_component_p (result))
	      result = TREE_OPERAND (result, 0);
	  else if (TREE_CODE (result) == REALPART_EXPR
		   || TREE_CODE (result) == IMAGPART_EXPR
		   || (CONVERT_EXPR_P (result)
		       && (((TREE_CODE (restype)
			     == TREE_CODE (TREE_TYPE
					   (TREE_OPERAND (result, 0))))
			     && (TYPE_MODE (TREE_TYPE
					    (TREE_OPERAND (result, 0)))
				 == TYPE_MODE (restype)))
			   || TYPE_ALIGN_OK (restype))))
	    result = TREE_OPERAND (result, 0);
	  else if (TREE_CODE (result) == VIEW_CONVERT_EXPR)
	    {
	      TREE_ADDRESSABLE (result) = 1;
	      result = TREE_OPERAND (result, 0);
	    }
	  else
	    break;
	}

      gcc_assert (TREE_CODE (result) == INDIRECT_REF
		  || TREE_CODE (result) == NULL_EXPR
		  || DECL_P (result));

      /* Convert the right operand to the operation type unless it is
	 either already of the correct type or if the type involves a
	 placeholder, since the RHS may not have the same record type.  */
      if (operation_type != right_type
	  && !CONTAINS_PLACEHOLDER_P (TYPE_SIZE (operation_type)))
	{
	  right_operand = convert (operation_type, right_operand);
	  right_type = operation_type;
	}

      /* If the left operand is not of the same type as the operation
	 type, wrap it up in a VIEW_CONVERT_EXPR.  */
      if (left_type != operation_type)
	left_operand = unchecked_convert (operation_type, left_operand, false);

      has_side_effects = true;
      modulus = NULL_TREE;
      break;

    case ARRAY_REF:
      if (!operation_type)
	operation_type = TREE_TYPE (left_type);

      /* ... fall through ... */

    case ARRAY_RANGE_REF:
      /* First look through conversion between type variants.  Note that
	 this changes neither the operation type nor the type domain.  */
      if (TREE_CODE (left_operand) == VIEW_CONVERT_EXPR
	  && TYPE_MAIN_VARIANT (TREE_TYPE (TREE_OPERAND (left_operand, 0)))
	     == TYPE_MAIN_VARIANT (left_type))
	{
	  left_operand = TREE_OPERAND (left_operand, 0);
	  left_type = TREE_TYPE (left_operand);
	}

      /* For a range, make sure the element type is consistent.  */
      if (op_code == ARRAY_RANGE_REF
	  && TREE_TYPE (operation_type) != TREE_TYPE (left_type))
	operation_type = build_array_type (TREE_TYPE (left_type),
					   TYPE_DOMAIN (operation_type));

      /* Then convert the right operand to its base type.  This will prevent
	 unneeded sign conversions when sizetype is wider than integer.  */
      right_operand = convert (right_base_type, right_operand);
      right_operand = convert (sizetype, right_operand);

      if (!TREE_CONSTANT (right_operand)
	  || !TREE_CONSTANT (TYPE_MIN_VALUE (right_type)))
	gnat_mark_addressable (left_operand);

      modulus = NULL_TREE;
      break;

    case TRUTH_ANDIF_EXPR:
    case TRUTH_ORIF_EXPR:
    case TRUTH_AND_EXPR:
    case TRUTH_OR_EXPR:
    case TRUTH_XOR_EXPR:
#ifdef ENABLE_CHECKING
      gcc_assert (TREE_CODE (get_base_type (result_type)) == BOOLEAN_TYPE);
#endif
      operation_type = left_base_type;
      left_operand = convert (operation_type, left_operand);
      right_operand = convert (operation_type, right_operand);
      break;

    case GE_EXPR:
    case LE_EXPR:
    case GT_EXPR:
    case LT_EXPR:
    case EQ_EXPR:
    case NE_EXPR:
#ifdef ENABLE_CHECKING
      gcc_assert (TREE_CODE (get_base_type (result_type)) == BOOLEAN_TYPE);
#endif
      /* If either operand is a NULL_EXPR, just return a new one.  */
      if (TREE_CODE (left_operand) == NULL_EXPR)
	return build2 (op_code, result_type,
		       build1 (NULL_EXPR, integer_type_node,
			       TREE_OPERAND (left_operand, 0)),
		       integer_zero_node);

      else if (TREE_CODE (right_operand) == NULL_EXPR)
	return build2 (op_code, result_type,
		       build1 (NULL_EXPR, integer_type_node,
			       TREE_OPERAND (right_operand, 0)),
		       integer_zero_node);

      /* If either object is a justified modular types, get the
	 fields from within.  */
      if (TREE_CODE (left_type) == RECORD_TYPE
	  && TYPE_JUSTIFIED_MODULAR_P (left_type))
	{
	  left_operand = convert (TREE_TYPE (TYPE_FIELDS (left_type)),
				  left_operand);
	  left_type = TREE_TYPE (left_operand);
	  left_base_type = get_base_type (left_type);
	}

      if (TREE_CODE (right_type) == RECORD_TYPE
	  && TYPE_JUSTIFIED_MODULAR_P (right_type))
	{
	  right_operand = convert (TREE_TYPE (TYPE_FIELDS (right_type)),
				  right_operand);
	  right_type = TREE_TYPE (right_operand);
	  right_base_type = get_base_type (right_type);
	}

      /* If both objects are arrays, compare them specially.  */
      if ((TREE_CODE (left_type) == ARRAY_TYPE
	   || (TREE_CODE (left_type) == INTEGER_TYPE
	       && TYPE_HAS_ACTUAL_BOUNDS_P (left_type)))
	  && (TREE_CODE (right_type) == ARRAY_TYPE
	      || (TREE_CODE (right_type) == INTEGER_TYPE
		  && TYPE_HAS_ACTUAL_BOUNDS_P (right_type))))
	{
	  result = compare_arrays (result_type, left_operand, right_operand);

	  if (op_code == NE_EXPR)
	    result = invert_truthvalue (result);
	  else
	    gcc_assert (op_code == EQ_EXPR);

	  return result;
	}

      /* Otherwise, the base types must be the same, unless they are both fat
	 pointer types or record types.  In the latter case, use the best type
	 and convert both operands to that type.  */
      if (left_base_type != right_base_type)
	{
	  if (TYPE_IS_FAT_POINTER_P (left_base_type)
	      && TYPE_IS_FAT_POINTER_P (right_base_type))
	    {
	      gcc_assert (TYPE_MAIN_VARIANT (left_base_type)
			  == TYPE_MAIN_VARIANT (right_base_type));
	      best_type = left_base_type;
	    }

	  else if (TREE_CODE (left_base_type) == RECORD_TYPE
		   && TREE_CODE (right_base_type) == RECORD_TYPE)
	    {
	      /* The only way this is permitted is if both types have the same
		 name.  In that case, one of them must not be self-referential.
		 Use it as the best type.  Even better with a fixed size.  */
	      gcc_assert (TYPE_NAME (left_base_type)
			  && TYPE_NAME (left_base_type)
			     == TYPE_NAME (right_base_type));

	      if (TREE_CONSTANT (TYPE_SIZE (left_base_type)))
		best_type = left_base_type;
	      else if (TREE_CONSTANT (TYPE_SIZE (right_base_type)))
		best_type = right_base_type;
	      else if (!CONTAINS_PLACEHOLDER_P (TYPE_SIZE (left_base_type)))
		best_type = left_base_type;
	      else if (!CONTAINS_PLACEHOLDER_P (TYPE_SIZE (right_base_type)))
		best_type = right_base_type;
	      else
		gcc_unreachable ();
	    }

	  else
	    gcc_unreachable ();

	  left_operand = convert (best_type, left_operand);
	  right_operand = convert (best_type, right_operand);
	}
      else
	{
	  left_operand = convert (left_base_type, left_operand);
	  right_operand = convert (right_base_type, right_operand);
	}

      /* If we are comparing a fat pointer against zero, we just need to
	 compare the data pointer.  */
      if (TYPE_IS_FAT_POINTER_P (left_base_type)
	  && TREE_CODE (right_operand) == CONSTRUCTOR
	  && integer_zerop (VEC_index (constructor_elt,
				       CONSTRUCTOR_ELTS (right_operand),
				       0)->value))
	{
	  left_operand
	    = build_component_ref (left_operand, NULL_TREE,
				   TYPE_FIELDS (left_base_type), false);
	  right_operand
	    = convert (TREE_TYPE (left_operand), integer_zero_node);
	}

      modulus = NULL_TREE;
      break;

    case LSHIFT_EXPR:
    case RSHIFT_EXPR:
    case LROTATE_EXPR:
    case RROTATE_EXPR:
       /* The RHS of a shift can be any type.  Also, ignore any modulus
	 (we used to abort, but this is needed for unchecked conversion
	 to modular types).  Otherwise, processing is the same as normal.  */
      gcc_assert (operation_type == left_base_type);
      modulus = NULL_TREE;
      left_operand = convert (operation_type, left_operand);
      break;

    case BIT_AND_EXPR:
    case BIT_IOR_EXPR:
    case BIT_XOR_EXPR:
      /* For binary modulus, if the inputs are in range, so are the
	 outputs.  */
      if (modulus && integer_pow2p (modulus))
	modulus = NULL_TREE;
      goto common;

    case COMPLEX_EXPR:
      gcc_assert (TREE_TYPE (result_type) == left_base_type
		  && TREE_TYPE (result_type) == right_base_type);
      left_operand = convert (left_base_type, left_operand);
      right_operand = convert (right_base_type, right_operand);
      break;

    case TRUNC_DIV_EXPR:   case TRUNC_MOD_EXPR:
    case CEIL_DIV_EXPR:    case CEIL_MOD_EXPR:
    case FLOOR_DIV_EXPR:   case FLOOR_MOD_EXPR:
    case ROUND_DIV_EXPR:   case ROUND_MOD_EXPR:
      /* These always produce results lower than either operand.  */
      modulus = NULL_TREE;
      goto common;

    case POINTER_PLUS_EXPR:
      gcc_assert (operation_type == left_base_type
		  && sizetype == right_base_type);
      left_operand = convert (operation_type, left_operand);
      right_operand = convert (sizetype, right_operand);
      break;

    case PLUS_NOMOD_EXPR:
    case MINUS_NOMOD_EXPR:
      if (op_code == PLUS_NOMOD_EXPR)
	op_code = PLUS_EXPR;
      else
	op_code = MINUS_EXPR;
      modulus = NULL_TREE;

      /* ... fall through ... */

    case PLUS_EXPR:
    case MINUS_EXPR:
      /* Avoid doing arithmetics in ENUMERAL_TYPE or BOOLEAN_TYPE like the
	 other compilers.  Contrary to C, Ada doesn't allow arithmetics in
	 these types but can generate addition/subtraction for Succ/Pred.  */
      if (operation_type
	  && (TREE_CODE (operation_type) == ENUMERAL_TYPE
	      || TREE_CODE (operation_type) == BOOLEAN_TYPE))
	operation_type = left_base_type = right_base_type
	  = gnat_type_for_mode (TYPE_MODE (operation_type),
				TYPE_UNSIGNED (operation_type));

      /* ... fall through ... */

    default:
    common:
      /* The result type should be the same as the base types of the
	 both operands (and they should be the same).  Convert
	 everything to the result type.  */

      gcc_assert (operation_type == left_base_type
		  && left_base_type == right_base_type);
      left_operand = convert (operation_type, left_operand);
      right_operand = convert (operation_type, right_operand);
    }

  if (modulus && !integer_pow2p (modulus))
    {
      result = nonbinary_modular_operation (op_code, operation_type,
					    left_operand, right_operand);
      modulus = NULL_TREE;
    }
  /* If either operand is a NULL_EXPR, just return a new one.  */
  else if (TREE_CODE (left_operand) == NULL_EXPR)
    return build1 (NULL_EXPR, operation_type, TREE_OPERAND (left_operand, 0));
  else if (TREE_CODE (right_operand) == NULL_EXPR)
    return build1 (NULL_EXPR, operation_type, TREE_OPERAND (right_operand, 0));
  else if (op_code == ARRAY_REF || op_code == ARRAY_RANGE_REF)
    result = fold (build4 (op_code, operation_type, left_operand,
			   right_operand, NULL_TREE, NULL_TREE));
  else
    result
      = fold_build2 (op_code, operation_type, left_operand, right_operand);

  TREE_SIDE_EFFECTS (result) |= has_side_effects;
  TREE_CONSTANT (result)
    |= (TREE_CONSTANT (left_operand) & TREE_CONSTANT (right_operand)
	&& op_code != ARRAY_REF && op_code != ARRAY_RANGE_REF);

  if ((op_code == ARRAY_REF || op_code == ARRAY_RANGE_REF)
      && TYPE_VOLATILE (operation_type))
    TREE_THIS_VOLATILE (result) = 1;

  /* If we are working with modular types, perform the MOD operation
     if something above hasn't eliminated the need for it.  */
  if (modulus)
    result = fold_build2 (FLOOR_MOD_EXPR, operation_type, result,
			  convert (operation_type, modulus));

  if (result_type && result_type != operation_type)
    result = convert (result_type, result);

  return result;
}

/* Similar, but for unary operations.  */

tree
build_unary_op (enum tree_code op_code, tree result_type, tree operand)
{
  tree type = TREE_TYPE (operand);
  tree base_type = get_base_type (type);
  tree operation_type = result_type;
  tree result;
  bool side_effects = false;

  if (operation_type
      && TREE_CODE (operation_type) == RECORD_TYPE
      && TYPE_JUSTIFIED_MODULAR_P (operation_type))
    operation_type = TREE_TYPE (TYPE_FIELDS (operation_type));

  if (operation_type
      && !AGGREGATE_TYPE_P (operation_type)
      && TYPE_EXTRA_SUBTYPE_P (operation_type))
    operation_type = get_base_type (operation_type);

  switch (op_code)
    {
    case REALPART_EXPR:
    case IMAGPART_EXPR:
      if (!operation_type)
	result_type = operation_type = TREE_TYPE (type);
      else
	gcc_assert (result_type == TREE_TYPE (type));

      result = fold_build1 (op_code, operation_type, operand);
      break;

    case TRUTH_NOT_EXPR:
#ifdef ENABLE_CHECKING
      gcc_assert (TREE_CODE (get_base_type (result_type)) == BOOLEAN_TYPE);
#endif
      result = invert_truthvalue (operand);
      break;

    case ATTR_ADDR_EXPR:
    case ADDR_EXPR:
      switch (TREE_CODE (operand))
	{
	case INDIRECT_REF:
	case UNCONSTRAINED_ARRAY_REF:
	  result = TREE_OPERAND (operand, 0);

	  /* Make sure the type here is a pointer, not a reference.
	     GCC wants pointer types for function addresses.  */
	  if (!result_type)
	    result_type = build_pointer_type (type);

	  /* If the underlying object can alias everything, propagate the
	     property since we are effectively retrieving the object.  */
	  if (POINTER_TYPE_P (TREE_TYPE (result))
	      && TYPE_REF_CAN_ALIAS_ALL (TREE_TYPE (result)))
	    {
	      if (TREE_CODE (result_type) == POINTER_TYPE
		  && !TYPE_REF_CAN_ALIAS_ALL (result_type))
		result_type
		  = build_pointer_type_for_mode (TREE_TYPE (result_type),
						 TYPE_MODE (result_type),
						 true);
	      else if (TREE_CODE (result_type) == REFERENCE_TYPE
		       && !TYPE_REF_CAN_ALIAS_ALL (result_type))
	        result_type
		  = build_reference_type_for_mode (TREE_TYPE (result_type),
						   TYPE_MODE (result_type),
						   true);
	    }
	  break;

	case NULL_EXPR:
	  result = operand;
	  TREE_TYPE (result) = type = build_pointer_type (type);
	  break;

	case COMPOUND_EXPR:
	  /* Fold a compound expression if it has unconstrained array type
	     since the middle-end cannot handle it.  But we don't it in the
	     general case because it may introduce aliasing issues if the
	     first operand is an indirect assignment and the second operand
	     the corresponding address, e.g. for an allocator.  */
	  if (TREE_CODE (type) == UNCONSTRAINED_ARRAY_TYPE)
	    {
	      result = build_unary_op (ADDR_EXPR, result_type,
				       TREE_OPERAND (operand, 1));
	      result = build2 (COMPOUND_EXPR, TREE_TYPE (result),
			       TREE_OPERAND (operand, 0), result);
	      break;
	    }
	  goto common;

	case ARRAY_REF:
	case ARRAY_RANGE_REF:
	case COMPONENT_REF:
	case BIT_FIELD_REF:
	    /* If this is for 'Address, find the address of the prefix and add
	       the offset to the field.  Otherwise, do this the normal way.  */
	  if (op_code == ATTR_ADDR_EXPR)
	    {
	      HOST_WIDE_INT bitsize;
	      HOST_WIDE_INT bitpos;
	      tree offset, inner;
	      enum machine_mode mode;
	      int unsignedp, volatilep;

	      inner = get_inner_reference (operand, &bitsize, &bitpos, &offset,
					   &mode, &unsignedp, &volatilep,
					   false);

	      /* If INNER is a padding type whose field has a self-referential
		 size, convert to that inner type.  We know the offset is zero
		 and we need to have that type visible.  */
	      if (TYPE_IS_PADDING_P (TREE_TYPE (inner))
		  && CONTAINS_PLACEHOLDER_P
		     (TYPE_SIZE (TREE_TYPE (TYPE_FIELDS
					    (TREE_TYPE (inner))))))
		inner = convert (TREE_TYPE (TYPE_FIELDS (TREE_TYPE (inner))),
				 inner);

	      /* Compute the offset as a byte offset from INNER.  */
	      if (!offset)
		offset = size_zero_node;

	      offset = size_binop (PLUS_EXPR, offset,
				   size_int (bitpos / BITS_PER_UNIT));

	      /* Take the address of INNER, convert the offset to void *, and
		 add then.  It will later be converted to the desired result
		 type, if any.  */
	      inner = build_unary_op (ADDR_EXPR, NULL_TREE, inner);
	      inner = convert (ptr_void_type_node, inner);
	      result = build_binary_op (POINTER_PLUS_EXPR, ptr_void_type_node,
					inner, offset);
	      result = convert (build_pointer_type (TREE_TYPE (operand)),
				result);
	      break;
	    }
	  goto common;

	case CONSTRUCTOR:
	  /* If this is just a constructor for a padded record, we can
	     just take the address of the single field and convert it to
	     a pointer to our type.  */
	  if (TYPE_IS_PADDING_P (type))
	    {
	      result = VEC_index (constructor_elt,
				  CONSTRUCTOR_ELTS (operand),
				  0)->value;
	      result = convert (build_pointer_type (TREE_TYPE (operand)),
				build_unary_op (ADDR_EXPR, NULL_TREE, result));
	      break;
	    }

	  goto common;

	case NOP_EXPR:
	  if (AGGREGATE_TYPE_P (type)
	      && AGGREGATE_TYPE_P (TREE_TYPE (TREE_OPERAND (operand, 0))))
	    return build_unary_op (ADDR_EXPR, result_type,
				   TREE_OPERAND (operand, 0));

	  /* ... fallthru ... */

	case VIEW_CONVERT_EXPR:
	  /* If this just a variant conversion or if the conversion doesn't
	     change the mode, get the result type from this type and go down.
	     This is needed for conversions of CONST_DECLs, to eventually get
	     to the address of their CORRESPONDING_VARs.  */
	  if ((TYPE_MAIN_VARIANT (type)
	       == TYPE_MAIN_VARIANT (TREE_TYPE (TREE_OPERAND (operand, 0))))
	      || (TYPE_MODE (type) != BLKmode
		  && (TYPE_MODE (type)
		      == TYPE_MODE (TREE_TYPE (TREE_OPERAND (operand, 0))))))
	    return build_unary_op (ADDR_EXPR,
				   (result_type ? result_type
				    : build_pointer_type (type)),
				   TREE_OPERAND (operand, 0));
	  goto common;

	case CONST_DECL:
	  operand = DECL_CONST_CORRESPONDING_VAR (operand);

	  /* ... fall through ... */

	default:
	common:

	  /* If we are taking the address of a padded record whose field is
	     contains a template, take the address of the template.  */
	  if (TYPE_IS_PADDING_P (type)
	      && TREE_CODE (TREE_TYPE (TYPE_FIELDS (type))) == RECORD_TYPE
	      && TYPE_CONTAINS_TEMPLATE_P (TREE_TYPE (TYPE_FIELDS (type))))
	    {
	      type = TREE_TYPE (TYPE_FIELDS (type));
	      operand = convert (type, operand);
	    }

	  gnat_mark_addressable (operand);
	  result = build_fold_addr_expr (operand);
	}

      TREE_CONSTANT (result) = staticp (operand) || TREE_CONSTANT (operand);
      break;

    case INDIRECT_REF:
      /* If we want to refer to an unconstrained array, use the appropriate
	 expression to do so.  This will never survive down to the back-end.
	 But if TYPE is a thin pointer, first convert to a fat pointer.  */
      if (TYPE_IS_THIN_POINTER_P (type)
	  && TYPE_UNCONSTRAINED_ARRAY (TREE_TYPE (type)))
	{
	  operand
	    = convert (TREE_TYPE (TYPE_UNCONSTRAINED_ARRAY (TREE_TYPE (type))),
		       operand);
	  type = TREE_TYPE (operand);
	}

      if (TYPE_IS_FAT_POINTER_P (type))
	{
	  result = build1 (UNCONSTRAINED_ARRAY_REF,
			   TYPE_UNCONSTRAINED_ARRAY (type), operand);
	  TREE_READONLY (result)
	    = TYPE_READONLY (TYPE_UNCONSTRAINED_ARRAY (type));
	}

      /* If we are dereferencing an ADDR_EXPR, return its operand.  */
      else if (TREE_CODE (operand) == ADDR_EXPR)
	result = TREE_OPERAND (operand, 0);

      /* Otherwise, build and fold the indirect reference.  */
      else
	{
	  result = build_fold_indirect_ref (operand);
	  TREE_READONLY (result) = TYPE_READONLY (TREE_TYPE (type));
	}

      side_effects
	= (!TYPE_IS_FAT_POINTER_P (type) && TYPE_VOLATILE (TREE_TYPE (type)));
      break;

    case NEGATE_EXPR:
    case BIT_NOT_EXPR:
      {
	tree modulus = ((operation_type
			 && TREE_CODE (operation_type) == INTEGER_TYPE
			 && TYPE_MODULAR_P (operation_type))
			? TYPE_MODULUS (operation_type) : NULL_TREE);
	int mod_pow2 = modulus && integer_pow2p (modulus);

	/* If this is a modular type, there are various possibilities
	   depending on the operation and whether the modulus is a
	   power of two or not.  */

	if (modulus)
	  {
	    gcc_assert (operation_type == base_type);
	    operand = convert (operation_type, operand);

	    /* The fastest in the negate case for binary modulus is
	       the straightforward code; the TRUNC_MOD_EXPR below
	       is an AND operation.  */
	    if (op_code == NEGATE_EXPR && mod_pow2)
	      result = fold_build2 (TRUNC_MOD_EXPR, operation_type,
				    fold_build1 (NEGATE_EXPR, operation_type,
						 operand),
				    modulus);

	    /* For nonbinary negate case, return zero for zero operand,
	       else return the modulus minus the operand.  If the modulus
	       is a power of two minus one, we can do the subtraction
	       as an XOR since it is equivalent and faster on most machines. */
	    else if (op_code == NEGATE_EXPR && !mod_pow2)
	      {
		if (integer_pow2p (fold_build2 (PLUS_EXPR, operation_type,
						modulus,
						convert (operation_type,
							 integer_one_node))))
		  result = fold_build2 (BIT_XOR_EXPR, operation_type,
					operand, modulus);
		else
		  result = fold_build2 (MINUS_EXPR, operation_type,
					modulus, operand);

		result = fold_build3 (COND_EXPR, operation_type,
				      fold_build2 (NE_EXPR,
						   boolean_type_node,
						   operand,
						   convert
						     (operation_type,
						      integer_zero_node)),
				      result, operand);
	      }
	    else
	      {
		/* For the NOT cases, we need a constant equal to
		   the modulus minus one.  For a binary modulus, we
		   XOR against the constant and subtract the operand from
		   that constant for nonbinary modulus.  */

		tree cnst = fold_build2 (MINUS_EXPR, operation_type, modulus,
					 convert (operation_type,
						  integer_one_node));

		if (mod_pow2)
		  result = fold_build2 (BIT_XOR_EXPR, operation_type,
					operand, cnst);
		else
		  result = fold_build2 (MINUS_EXPR, operation_type,
					cnst, operand);
	      }

	    break;
	  }
      }

      /* ... fall through ... */

    default:
      gcc_assert (operation_type == base_type);
      result = fold_build1 (op_code, operation_type,
			    convert (operation_type, operand));
    }

  if (side_effects)
    {
      TREE_SIDE_EFFECTS (result) = 1;
      if (TREE_CODE (result) == INDIRECT_REF)
	TREE_THIS_VOLATILE (result) = TYPE_VOLATILE (TREE_TYPE (result));
    }

  if (result_type && TREE_TYPE (result) != result_type)
    result = convert (result_type, result);

  return result;
}

/* Similar, but for COND_EXPR.  */

tree
build_cond_expr (tree result_type, tree condition_operand,
                 tree true_operand, tree false_operand)
{
  bool addr_p = false;
  tree result;

  /* The front-end verified that result, true and false operands have
     same base type.  Convert everything to the result type.  */
  true_operand = convert (result_type, true_operand);
  false_operand = convert (result_type, false_operand);

  /* If the result type is unconstrained, take the address of the operands and
     then dereference the result.  Likewise if the result type is passed by
     reference, but this is natively handled in the gimplifier.  */
  if (TREE_CODE (result_type) == UNCONSTRAINED_ARRAY_TYPE
      || CONTAINS_PLACEHOLDER_P (TYPE_SIZE (result_type)))
    {
      result_type = build_pointer_type (result_type);
      true_operand = build_unary_op (ADDR_EXPR, result_type, true_operand);
      false_operand = build_unary_op (ADDR_EXPR, result_type, false_operand);
      addr_p = true;
    }

  result = fold_build3 (COND_EXPR, result_type, condition_operand,
			true_operand, false_operand);

  /* If we have a common SAVE_EXPR (possibly surrounded by arithmetics)
     in both arms, make sure it gets evaluated by moving it ahead of the
     conditional expression.  This is necessary because it is evaluated
     in only one place at run time and would otherwise be uninitialized
     in one of the arms.  */
  true_operand = skip_simple_arithmetic (true_operand);
  false_operand = skip_simple_arithmetic (false_operand);

  if (true_operand == false_operand && TREE_CODE (true_operand) == SAVE_EXPR)
    result = build2 (COMPOUND_EXPR, result_type, true_operand, result);

  if (addr_p)
    result = build_unary_op (INDIRECT_REF, NULL_TREE, result);

  return result;
}

/* Similar, but for RETURN_EXPR.  If RET_VAL is non-null, build a RETURN_EXPR
   around the assignment of RET_VAL to RET_OBJ.  Otherwise just build a bare
   RETURN_EXPR around RESULT_OBJ, which may be null in this case.  */

tree
build_return_expr (tree ret_obj, tree ret_val)
{
  tree result_expr;

  if (ret_val)
    {
      /* The gimplifier explicitly enforces the following invariant:

	      RETURN_EXPR
		  |
	      MODIFY_EXPR
	      /        \
	     /          \
	 RET_OBJ        ...

	 As a consequence, type consistency dictates that we use the type
	 of the RET_OBJ as the operation type.  */
      tree operation_type = TREE_TYPE (ret_obj);

      /* Convert the right operand to the operation type.  Note that it's the
	 same transformation as in the MODIFY_EXPR case of build_binary_op,
	 with the assumption that the type cannot involve a placeholder.  */
      if (operation_type != TREE_TYPE (ret_val))
	ret_val = convert (operation_type, ret_val);

      result_expr = build2 (MODIFY_EXPR, operation_type, ret_obj, ret_val);
    }
  else
    result_expr = ret_obj;

  return build1 (RETURN_EXPR, void_type_node, result_expr);
}

/* Build a CALL_EXPR to call FUNDECL with one argument, ARG.  Return
   the CALL_EXPR.  */

tree
build_call_1_expr (tree fundecl, tree arg)
{
  tree call = build_call_nary (TREE_TYPE (TREE_TYPE (fundecl)),
			       build_unary_op (ADDR_EXPR, NULL_TREE, fundecl),
			       1, arg);
  TREE_SIDE_EFFECTS (call) = 1;
  return call;
}

/* Build a CALL_EXPR to call FUNDECL with two arguments, ARG1 & ARG2.  Return
   the CALL_EXPR.  */

tree
build_call_2_expr (tree fundecl, tree arg1, tree arg2)
{
  tree call = build_call_nary (TREE_TYPE (TREE_TYPE (fundecl)),
			       build_unary_op (ADDR_EXPR, NULL_TREE, fundecl),
			       2, arg1, arg2);
  TREE_SIDE_EFFECTS (call) = 1;
  return call;
}

/* Likewise to call FUNDECL with no arguments.  */

tree
build_call_0_expr (tree fundecl)
{
  /* We rely on build_call_nary to compute TREE_SIDE_EFFECTS.  This makes
     it possible to propagate DECL_IS_PURE on parameterless functions.  */
  tree call = build_call_nary (TREE_TYPE (TREE_TYPE (fundecl)),
			       build_unary_op (ADDR_EXPR, NULL_TREE, fundecl),
			       0);
  return call;
}

/* Call a function that raises an exception and pass the line number and file
   name, if requested.  MSG says which exception function to call.

   GNAT_NODE is the gnat node conveying the source location for which the
   error should be signaled, or Empty in which case the error is signaled on
   the current ref_file_name/input_line.

   KIND says which kind of exception this is for
   (N_Raise_{Constraint,Storage,Program}_Error).  */

tree
build_call_raise (int msg, Node_Id gnat_node, char kind)
{
  tree fndecl = gnat_raise_decls[msg];
  tree label = get_exception_label (kind);
  tree filename;
  int line_number;
  const char *str;
  int len;

  /* If this is to be done as a goto, handle that case.  */
  if (label)
    {
      Entity_Id local_raise = Get_Local_Raise_Call_Entity ();
      tree gnu_result = build1 (GOTO_EXPR, void_type_node, label);

      /* If Local_Raise is present, generate
	 Local_Raise (exception'Identity);  */
      if (Present (local_raise))
	{
	  tree gnu_local_raise
	    = gnat_to_gnu_entity (local_raise, NULL_TREE, 0);
	  tree gnu_exception_entity
	    = gnat_to_gnu_entity (Get_RT_Exception_Entity (msg), NULL_TREE, 0);
	  tree gnu_call
	    = build_call_1_expr (gnu_local_raise,
				 build_unary_op (ADDR_EXPR, NULL_TREE,
						 gnu_exception_entity));

	  gnu_result = build2 (COMPOUND_EXPR, void_type_node,
			       gnu_call, gnu_result);}

      return gnu_result;
    }

  str
    = (Debug_Flag_NN || Exception_Locations_Suppressed)
      ? ""
      : (gnat_node != Empty && Sloc (gnat_node) != No_Location)
        ? IDENTIFIER_POINTER
          (get_identifier (Get_Name_String
			   (Debug_Source_Name
			    (Get_Source_File_Index (Sloc (gnat_node))))))
        : ref_filename;

  len = strlen (str);
  filename = build_string (len, str);
  line_number
    = (gnat_node != Empty && Sloc (gnat_node) != No_Location)
      ? Get_Logical_Line_Number (Sloc(gnat_node)) : input_line;

  TREE_TYPE (filename) = build_array_type (unsigned_char_type_node,
					   build_index_type (size_int (len)));

  return
    build_call_2_expr (fndecl,
		       build1 (ADDR_EXPR,
			       build_pointer_type (unsigned_char_type_node),
			       filename),
		       build_int_cst (NULL_TREE, line_number));
}

/* qsort comparer for the bit positions of two constructor elements
   for record components.  */

static int
compare_elmt_bitpos (const PTR rt1, const PTR rt2)
{
  const constructor_elt * const elmt1 = (const constructor_elt const *) rt1;
  const constructor_elt * const elmt2 = (const constructor_elt const *) rt2;
  const_tree const field1 = elmt1->index;
  const_tree const field2 = elmt2->index;
  const int ret
    = tree_int_cst_compare (bit_position (field1), bit_position (field2));

  return ret ? ret : (int) (DECL_UID (field1) - DECL_UID (field2));
}

/* Return a CONSTRUCTOR of TYPE whose elements are V.  */

tree
gnat_build_constructor (tree type, VEC(constructor_elt,gc) *v)
{
  bool allconstant = (TREE_CODE (TYPE_SIZE (type)) == INTEGER_CST);
  bool side_effects = false;
  tree result, obj, val;
  unsigned int n_elmts;

  /* Scan the elements to see if they are all constant or if any has side
     effects, to let us set global flags on the resulting constructor.  Count
     the elements along the way for possible sorting purposes below.  */
  FOR_EACH_CONSTRUCTOR_ELT (v, n_elmts, obj, val)
    {
      /* The predicate must be in keeping with output_constructor.  */
      if (!TREE_CONSTANT (val)
	  || (TREE_CODE (type) == RECORD_TYPE
	      && CONSTRUCTOR_BITFIELD_P (obj)
	      && !initializer_constant_valid_for_bitfield_p (val))
	  || !initializer_constant_valid_p (val, TREE_TYPE (val)))
	allconstant = false;

      if (TREE_SIDE_EFFECTS (val))
	side_effects = true;
    }

  /* For record types with constant components only, sort field list
     by increasing bit position.  This is necessary to ensure the
     constructor can be output as static data.  */
  if (allconstant && TREE_CODE (type) == RECORD_TYPE && n_elmts > 1)
    qsort (VEC_address (constructor_elt, v), n_elmts,
           sizeof (constructor_elt), compare_elmt_bitpos);

  result = build_constructor (type, v);
  TREE_CONSTANT (result) = TREE_STATIC (result) = allconstant;
  TREE_SIDE_EFFECTS (result) = side_effects;
  TREE_READONLY (result) = TYPE_READONLY (type) || allconstant;
  return result;
}

/* Return a COMPONENT_REF to access a field that is given by COMPONENT,
   an IDENTIFIER_NODE giving the name of the field, or FIELD, a FIELD_DECL,
   for the field.  Don't fold the result if NO_FOLD_P is true.

   We also handle the fact that we might have been passed a pointer to the
   actual record and know how to look for fields in variant parts.  */

static tree
build_simple_component_ref (tree record_variable, tree component,
                            tree field, bool no_fold_p)
{
  tree record_type = TYPE_MAIN_VARIANT (TREE_TYPE (record_variable));
  tree ref, inner_variable;

  gcc_assert ((TREE_CODE (record_type) == RECORD_TYPE
	       || TREE_CODE (record_type) == UNION_TYPE
	       || TREE_CODE (record_type) == QUAL_UNION_TYPE)
	      && TYPE_SIZE (record_type)
	      && (component != 0) != (field != 0));

  /* If no field was specified, look for a field with the specified name
     in the current record only.  */
  if (!field)
    for (field = TYPE_FIELDS (record_type); field;
	 field = TREE_CHAIN (field))
      if (DECL_NAME (field) == component)
	break;

  if (!field)
    return NULL_TREE;

  /* If this field is not in the specified record, see if we can find
     something in the record whose original field is the same as this one. */
  if (DECL_CONTEXT (field) != record_type)
    /* Check if there is a field with name COMPONENT in the record.  */
    {
      tree new_field;

      /* First loop thru normal components.  */
      for (new_field = TYPE_FIELDS (record_type); new_field;
	   new_field = TREE_CHAIN (new_field))
	if (SAME_FIELD_P (field, new_field))
	  break;

      /* Next, loop thru DECL_INTERNAL_P components if we haven't found
         the component in the first search. Doing this search in 2 steps
         is required to avoiding hidden homonymous fields in the
         _Parent field.  */
      if (!new_field)
	for (new_field = TYPE_FIELDS (record_type); new_field;
	     new_field = TREE_CHAIN (new_field))
	  if (DECL_INTERNAL_P (new_field))
	    {
	      tree field_ref
		= build_simple_component_ref (record_variable,
					      NULL_TREE, new_field, no_fold_p);
	      ref = build_simple_component_ref (field_ref, NULL_TREE, field,
						no_fold_p);

	      if (ref)
		return ref;
	    }

      field = new_field;
    }

  if (!field)
    return NULL_TREE;

  /* If the field's offset has overflowed, do not attempt to access it
     as doing so may trigger sanity checks deeper in the back-end.
     Note that we don't need to warn since this will be done on trying
     to declare the object.  */
  if (TREE_CODE (DECL_FIELD_OFFSET (field)) == INTEGER_CST
      && TREE_OVERFLOW (DECL_FIELD_OFFSET (field)))
    return NULL_TREE;

  /* Look through conversion between type variants.  Note that this
     is transparent as far as the field is concerned.  */
  if (TREE_CODE (record_variable) == VIEW_CONVERT_EXPR
      && TYPE_MAIN_VARIANT (TREE_TYPE (TREE_OPERAND (record_variable, 0)))
	 == record_type)
    inner_variable = TREE_OPERAND (record_variable, 0);
  else
    inner_variable = record_variable;

  ref = build3 (COMPONENT_REF, TREE_TYPE (field), inner_variable, field,
		NULL_TREE);

  if (TREE_READONLY (record_variable) || TREE_READONLY (field))
    TREE_READONLY (ref) = 1;
  if (TREE_THIS_VOLATILE (record_variable) || TREE_THIS_VOLATILE (field)
      || TYPE_VOLATILE (record_type))
    TREE_THIS_VOLATILE (ref) = 1;

  if (no_fold_p)
    return ref;

  /* The generic folder may punt in this case because the inner array type
     can be self-referential, but folding is in fact not problematic.  */
  else if (TREE_CODE (record_variable) == CONSTRUCTOR
	   && TYPE_CONTAINS_TEMPLATE_P (TREE_TYPE (record_variable)))
    {
      VEC(constructor_elt,gc) *elts = CONSTRUCTOR_ELTS (record_variable);
      unsigned HOST_WIDE_INT idx;
      tree index, value;
      FOR_EACH_CONSTRUCTOR_ELT (elts, idx, index, value)
	if (index == field)
	  return value;
      return ref;
    }

  else
    return fold (ref);
}

/* Like build_simple_component_ref, except that we give an error if the
   reference could not be found.  */

tree
build_component_ref (tree record_variable, tree component,
                     tree field, bool no_fold_p)
{
  tree ref = build_simple_component_ref (record_variable, component, field,
					 no_fold_p);

  if (ref)
    return ref;

  /* If FIELD was specified, assume this is an invalid user field so raise
     Constraint_Error.  Otherwise, we have no type to return so abort.  */
  gcc_assert (field);
  return build1 (NULL_EXPR, TREE_TYPE (field),
		 build_call_raise (CE_Discriminant_Check_Failed, Empty,
				   N_Raise_Constraint_Error));
}

/* Helper for build_call_alloc_dealloc, with arguments to be interpreted
   identically.  Process the case where a GNAT_PROC to call is provided.  */

static inline tree
build_call_alloc_dealloc_proc (tree gnu_obj, tree gnu_size, tree gnu_type,
			       Entity_Id gnat_proc, Entity_Id gnat_pool)
{
  tree gnu_proc = gnat_to_gnu (gnat_proc);
  tree gnu_proc_addr = build_unary_op (ADDR_EXPR, NULL_TREE, gnu_proc);
  tree gnu_call;

  /* The storage pools are obviously always tagged types, but the
     secondary stack uses the same mechanism and is not tagged.  */
  if (Is_Tagged_Type (Etype (gnat_pool)))
    {
      /* The size is the third parameter; the alignment is the
	 same type.  */
      Entity_Id gnat_size_type
	= Etype (Next_Formal (Next_Formal (First_Formal (gnat_proc))));
      tree gnu_size_type = gnat_to_gnu_type (gnat_size_type);

      tree gnu_pool = gnat_to_gnu (gnat_pool);
      tree gnu_pool_addr = build_unary_op (ADDR_EXPR, NULL_TREE, gnu_pool);
      tree gnu_align = size_int (TYPE_ALIGN (gnu_type) / BITS_PER_UNIT);

      gnu_size = convert (gnu_size_type, gnu_size);
      gnu_align = convert (gnu_size_type, gnu_align);

      /* The first arg is always the address of the storage pool; next
	 comes the address of the object, for a deallocator, then the
	 size and alignment.  */
      if (gnu_obj)
	gnu_call = build_call_nary (TREE_TYPE (TREE_TYPE (gnu_proc)),
				    gnu_proc_addr, 4, gnu_pool_addr,
				    gnu_obj, gnu_size, gnu_align);
      else
	gnu_call = build_call_nary (TREE_TYPE (TREE_TYPE (gnu_proc)),
				    gnu_proc_addr, 3, gnu_pool_addr,
				    gnu_size, gnu_align);
    }

  /* Secondary stack case.  */
  else
    {
      /* The size is the second parameter.  */
      Entity_Id gnat_size_type
	= Etype (Next_Formal (First_Formal (gnat_proc)));
      tree gnu_size_type = gnat_to_gnu_type (gnat_size_type);

      gnu_size = convert (gnu_size_type, gnu_size);

      /* The first arg is the address of the object, for a deallocator,
	 then the size.  */
      if (gnu_obj)
	gnu_call = build_call_nary (TREE_TYPE (TREE_TYPE (gnu_proc)),
				    gnu_proc_addr, 2, gnu_obj, gnu_size);
      else
	gnu_call = build_call_nary (TREE_TYPE (TREE_TYPE (gnu_proc)),
				    gnu_proc_addr, 1, gnu_size);
    }

  TREE_SIDE_EFFECTS (gnu_call) = 1;
  return gnu_call;
}

/* Helper for build_call_alloc_dealloc, to build and return an allocator for
   DATA_SIZE bytes aimed at containing a DATA_TYPE object, using the default
   __gnat_malloc allocator.  Honor DATA_TYPE alignments greater than what the
   latter offers.  */

static inline tree
maybe_wrap_malloc (tree data_size, tree data_type, Node_Id gnat_node)
{
  /* When the DATA_TYPE alignment is stricter than what malloc offers
     (super-aligned case), we allocate an "aligning" wrapper type and return
     the address of its single data field with the malloc's return value
     stored just in front.  */

  unsigned int data_align = TYPE_ALIGN (data_type);
  unsigned int default_allocator_alignment
      = get_target_default_allocator_alignment () * BITS_PER_UNIT;

  tree aligning_type
    = ((data_align > default_allocator_alignment)
       ? make_aligning_type (data_type, data_align, data_size,
			     default_allocator_alignment,
			     POINTER_SIZE / BITS_PER_UNIT)
       : NULL_TREE);

  tree size_to_malloc
    = aligning_type ? TYPE_SIZE_UNIT (aligning_type) : data_size;

  tree malloc_ptr;

  /* On VMS, if pointers are 64-bit and the allocator size is 32-bit or
     Convention C, allocate 32-bit memory.  */
  if (TARGET_ABI_OPEN_VMS
      && (POINTER_SIZE == 64
	     && (UI_To_Int (Esize (Etype (gnat_node))) == 32
		 || Convention (Etype (gnat_node)) == Convention_C)))
    malloc_ptr = build_call_1_expr (malloc32_decl, size_to_malloc);
  else
    malloc_ptr = build_call_1_expr (malloc_decl, size_to_malloc);

  if (aligning_type)
    {
      /* Latch malloc's return value and get a pointer to the aligning field
	 first.  */
      tree storage_ptr = gnat_protect_expr (malloc_ptr);

      tree aligning_record_addr
	= convert (build_pointer_type (aligning_type), storage_ptr);

      tree aligning_record
	= build_unary_op (INDIRECT_REF, NULL_TREE, aligning_record_addr);

      tree aligning_field
	= build_component_ref (aligning_record, NULL_TREE,
			       TYPE_FIELDS (aligning_type), false);

      tree aligning_field_addr
        = build_unary_op (ADDR_EXPR, NULL_TREE, aligning_field);

      /* Then arrange to store the allocator's return value ahead
	 and return.  */
      tree storage_ptr_slot_addr
	= build_binary_op (POINTER_PLUS_EXPR, ptr_void_type_node,
			   convert (ptr_void_type_node, aligning_field_addr),
			   size_int (-(HOST_WIDE_INT) POINTER_SIZE
				     / BITS_PER_UNIT));

      tree storage_ptr_slot
	= build_unary_op (INDIRECT_REF, NULL_TREE,
			  convert (build_pointer_type (ptr_void_type_node),
				   storage_ptr_slot_addr));

      return
	build2 (COMPOUND_EXPR, TREE_TYPE (aligning_field_addr),
		build_binary_op (MODIFY_EXPR, NULL_TREE,
				 storage_ptr_slot, storage_ptr),
		aligning_field_addr);
    }
  else
    return malloc_ptr;
}

/* Helper for build_call_alloc_dealloc, to release a DATA_TYPE object
   designated by DATA_PTR using the __gnat_free entry point.  */

static inline tree
maybe_wrap_free (tree data_ptr, tree data_type)
{
  /* In the regular alignment case, we pass the data pointer straight to free.
     In the superaligned case, we need to retrieve the initial allocator
     return value, stored in front of the data block at allocation time.  */

  unsigned int data_align = TYPE_ALIGN (data_type);
  unsigned int default_allocator_alignment
      = get_target_default_allocator_alignment () * BITS_PER_UNIT;

  tree free_ptr;

  if (data_align > default_allocator_alignment)
    {
      /* DATA_FRONT_PTR (void *)
	 = (void *)DATA_PTR - (void *)sizeof (void *))  */
      tree data_front_ptr
	= build_binary_op
	  (POINTER_PLUS_EXPR, ptr_void_type_node,
	   convert (ptr_void_type_node, data_ptr),
	   size_int (-(HOST_WIDE_INT) POINTER_SIZE / BITS_PER_UNIT));

      /* FREE_PTR (void *) = *(void **)DATA_FRONT_PTR  */
      free_ptr
	= build_unary_op
	  (INDIRECT_REF, NULL_TREE,
	   convert (build_pointer_type (ptr_void_type_node), data_front_ptr));
    }
  else
    free_ptr = data_ptr;

  return build_call_1_expr (free_decl, free_ptr);
}

/* Build a GCC tree to call an allocation or deallocation function.
   If GNU_OBJ is nonzero, it is an object to deallocate.  Otherwise,
   generate an allocator.

   GNU_SIZE is the number of bytes to allocate and GNU_TYPE is the contained
   object type, used to determine the to-be-honored address alignment.
   GNAT_PROC, if present, is a procedure to call and GNAT_POOL is the storage
   pool to use.  If not present, malloc and free are used.  GNAT_NODE is used
   to provide an error location for restriction violation messages.  */

tree
build_call_alloc_dealloc (tree gnu_obj, tree gnu_size, tree gnu_type,
                          Entity_Id gnat_proc, Entity_Id gnat_pool,
                          Node_Id gnat_node)
{
  gnu_size = SUBSTITUTE_PLACEHOLDER_IN_EXPR (gnu_size, gnu_obj);

  /* Explicit proc to call ?  This one is assumed to deal with the type
     alignment constraints.  */
  if (Present (gnat_proc))
    return build_call_alloc_dealloc_proc (gnu_obj, gnu_size, gnu_type,
					  gnat_proc, gnat_pool);

  /* Otherwise, object to "free" or "malloc" with possible special processing
     for alignments stricter than what the default allocator honors.  */
  else if (gnu_obj)
    return maybe_wrap_free (gnu_obj, gnu_type);
  else
    {
      /* Assert that we no longer can be called with this special pool.  */
      gcc_assert (gnat_pool != -1);

      /* Check that we aren't violating the associated restriction.  */
      if (!(Nkind (gnat_node) == N_Allocator && Comes_From_Source (gnat_node)))
	Check_No_Implicit_Heap_Alloc (gnat_node);

      return maybe_wrap_malloc (gnu_size, gnu_type, gnat_node);
    }
}

/* Build a GCC tree to correspond to allocating an object of TYPE whose
   initial value is INIT, if INIT is nonzero.  Convert the expression to
   RESULT_TYPE, which must be some type of pointer.  Return the tree.

   GNAT_PROC and GNAT_POOL optionally give the procedure to call and
   the storage pool to use.  GNAT_NODE is used to provide an error
   location for restriction violation messages.  If IGNORE_INIT_TYPE is
   true, ignore the type of INIT for the purpose of determining the size;
   this will cause the maximum size to be allocated if TYPE is of
   self-referential size.  */

tree
build_allocator (tree type, tree init, tree result_type, Entity_Id gnat_proc,
                 Entity_Id gnat_pool, Node_Id gnat_node, bool ignore_init_type)
{
  tree size = TYPE_SIZE_UNIT (type);
  tree result;

  /* If the initializer, if present, is a NULL_EXPR, just return a new one.  */
  if (init && TREE_CODE (init) == NULL_EXPR)
    return build1 (NULL_EXPR, result_type, TREE_OPERAND (init, 0));

  /* If RESULT_TYPE is a fat or thin pointer, set SIZE to be the sum of the
     sizes of the object and its template.  Allocate the whole thing and
     fill in the parts that are known.  */
  else if (TYPE_IS_FAT_OR_THIN_POINTER_P (result_type))
    {
      tree storage_type
	= build_unc_object_type_from_ptr (result_type, type,
					  get_identifier ("ALLOC"), false);
      tree template_type = TREE_TYPE (TYPE_FIELDS (storage_type));
      tree storage_ptr_type = build_pointer_type (storage_type);
      tree storage;

      size = SUBSTITUTE_PLACEHOLDER_IN_EXPR (TYPE_SIZE_UNIT (storage_type),
					     init);

      /* If the size overflows, pass -1 so the allocator will raise
	 storage error.  */
      if (TREE_CODE (size) == INTEGER_CST && TREE_OVERFLOW (size))
	size = ssize_int (-1);

      storage = build_call_alloc_dealloc (NULL_TREE, size, storage_type,
					  gnat_proc, gnat_pool, gnat_node);
      storage = convert (storage_ptr_type, gnat_protect_expr (storage));

      if (TYPE_IS_PADDING_P (type))
	{
	  type = TREE_TYPE (TYPE_FIELDS (type));
	  if (init)
	    init = convert (type, init);
	}

      /* If there is an initializing expression, make a constructor for
	 the entire object including the bounds and copy it into the
	 object.  If there is no initializing expression, just set the
	 bounds.  */
      if (init)
	{
	  VEC(constructor_elt,gc) *v = VEC_alloc (constructor_elt, gc, 2);

	  CONSTRUCTOR_APPEND_ELT (v, TYPE_FIELDS (storage_type),
				  build_template (template_type, type, init));
	  CONSTRUCTOR_APPEND_ELT (v, TREE_CHAIN (TYPE_FIELDS (storage_type)),
				  init);

	  return convert
	    (result_type,
	     build2 (COMPOUND_EXPR, storage_ptr_type,
		     build_binary_op
		     (MODIFY_EXPR, storage_type,
		      build_unary_op (INDIRECT_REF, NULL_TREE,
				      convert (storage_ptr_type, storage)),
		      gnat_build_constructor (storage_type, v)),
		     convert (storage_ptr_type, storage)));
	}
      else
	return build2
	  (COMPOUND_EXPR, result_type,
	   build_binary_op
	   (MODIFY_EXPR, template_type,
	    build_component_ref
	    (build_unary_op (INDIRECT_REF, NULL_TREE,
			     convert (storage_ptr_type, storage)),
	     NULL_TREE, TYPE_FIELDS (storage_type), false),
	    build_template (template_type, type, NULL_TREE)),
	   convert (result_type, convert (storage_ptr_type, storage)));
    }

  /* If we have an initializing expression, see if its size is simpler
     than the size from the type.  */
  if (!ignore_init_type && init && TYPE_SIZE_UNIT (TREE_TYPE (init))
      && (TREE_CODE (TYPE_SIZE_UNIT (TREE_TYPE (init))) == INTEGER_CST
	  || CONTAINS_PLACEHOLDER_P (size)))
    size = TYPE_SIZE_UNIT (TREE_TYPE (init));

  /* If the size is still self-referential, reference the initializing
     expression, if it is present.  If not, this must have been a
     call to allocate a library-level object, in which case we use
     the maximum size.  */
  if (CONTAINS_PLACEHOLDER_P (size))
    {
      if (!ignore_init_type && init)
	size = substitute_placeholder_in_expr (size, init);
      else
	size = max_size (size, true);
    }

  /* If the size overflows, pass -1 so the allocator will raise
     storage error.  */
  if (TREE_CODE (size) == INTEGER_CST && TREE_OVERFLOW (size))
    size = ssize_int (-1);

  result = convert (result_type,
		    build_call_alloc_dealloc (NULL_TREE, size, type,
					      gnat_proc, gnat_pool,
					      gnat_node));

  /* If we have an initial value, protect the new address, assign the value
     and return the address with a COMPOUND_EXPR.  */
  if (init)
    {
      result = gnat_protect_expr (result);
      result
	= build2 (COMPOUND_EXPR, TREE_TYPE (result),
		  build_binary_op
		  (MODIFY_EXPR, NULL_TREE,
		   build_unary_op (INDIRECT_REF,
				   TREE_TYPE (TREE_TYPE (result)), result),
		   init),
		  result);
    }

  return convert (result_type, result);
}

/* Fill in a VMS descriptor for EXPR and return a constructor for it.
   GNAT_FORMAL is how we find the descriptor record.  GNAT_ACTUAL is
   how we derive the source location to raise C_E on an out of range
   pointer. */

tree
fill_vms_descriptor (tree expr, Entity_Id gnat_formal, Node_Id gnat_actual)
{
  tree parm_decl = get_gnu_tree (gnat_formal);
  tree record_type = TREE_TYPE (TREE_TYPE (parm_decl));
  tree field;
  const bool do_range_check
    = strcmp ("MBO",
	      IDENTIFIER_POINTER (DECL_NAME (TYPE_FIELDS (record_type))));
  VEC(constructor_elt,gc) *v = NULL;

  expr = maybe_unconstrained_array (expr);
  gnat_mark_addressable (expr);

  for (field = TYPE_FIELDS (record_type); field; field = TREE_CHAIN (field))
    {
      tree conexpr = convert (TREE_TYPE (field),
			      SUBSTITUTE_PLACEHOLDER_IN_EXPR
			      (DECL_INITIAL (field), expr));

      /* Check to ensure that only 32-bit pointers are passed in
	 32-bit descriptors */
      if (do_range_check
          && strcmp (IDENTIFIER_POINTER (DECL_NAME (field)), "POINTER") == 0)
        {
	  tree pointer64type
	    = build_pointer_type_for_mode (void_type_node, DImode, false);
	  tree addr64expr = build_unary_op (ADDR_EXPR, pointer64type, expr);
	  tree malloc64low
	    = build_int_cstu (long_integer_type_node, 0x80000000);

	  add_stmt (build3 (COND_EXPR, void_type_node,
			    build_binary_op (GE_EXPR, boolean_type_node,
					     convert (long_integer_type_node,
						      addr64expr),
					     malloc64low),
			    build_call_raise (CE_Range_Check_Failed,
					      gnat_actual,
					      N_Raise_Constraint_Error),
			    NULL_TREE));
        }
      CONSTRUCTOR_APPEND_ELT (v, field, conexpr);
    }

  return gnat_build_constructor (record_type, v);
}

/* Indicate that we need to take the address of T and that it therefore
   should not be allocated in a register.  Returns true if successful.  */

bool
gnat_mark_addressable (tree t)
{
  while (true)
    switch (TREE_CODE (t))
      {
      case ADDR_EXPR:
      case COMPONENT_REF:
      case ARRAY_REF:
      case ARRAY_RANGE_REF:
      case REALPART_EXPR:
      case IMAGPART_EXPR:
      case VIEW_CONVERT_EXPR:
      case NON_LVALUE_EXPR:
      CASE_CONVERT:
	t = TREE_OPERAND (t, 0);
	break;

      case COMPOUND_EXPR:
	t = TREE_OPERAND (t, 1);
	break;

      case CONSTRUCTOR:
	TREE_ADDRESSABLE (t) = 1;
	return true;

      case VAR_DECL:
      case PARM_DECL:
      case RESULT_DECL:
	TREE_ADDRESSABLE (t) = 1;
	return true;

      case FUNCTION_DECL:
	TREE_ADDRESSABLE (t) = 1;
	return true;

      case CONST_DECL:
	return DECL_CONST_CORRESPONDING_VAR (t)
	       && gnat_mark_addressable (DECL_CONST_CORRESPONDING_VAR (t));

      default:
	return true;
    }
}

/* Save EXP for later use or reuse.  This is equivalent to save_expr in tree.c
   but we know how to handle our own nodes.  */

tree
gnat_save_expr (tree exp)
{
  tree type = TREE_TYPE (exp);
  enum tree_code code = TREE_CODE (exp);

  if (TREE_CONSTANT (exp) || code == SAVE_EXPR || code == NULL_EXPR)
    return exp;

  if (code == UNCONSTRAINED_ARRAY_REF)
    {
      tree t = build1 (code, type, gnat_save_expr (TREE_OPERAND (exp, 0)));
      TREE_READONLY (t) = TYPE_READONLY (type);
      return t;
    }

  /* If this is a COMPONENT_REF of a fat pointer, save the entire fat pointer.
     This may be more efficient, but will also allow us to more easily find
     the match for the PLACEHOLDER_EXPR.  */
  if (code == COMPONENT_REF
      && TYPE_IS_FAT_POINTER_P (TREE_TYPE (TREE_OPERAND (exp, 0))))
    return build3 (code, type, gnat_save_expr (TREE_OPERAND (exp, 0)),
		   TREE_OPERAND (exp, 1), TREE_OPERAND (exp, 2));

  return save_expr (exp);
}

/* Protect EXP for immediate reuse.  This is a variant of gnat_save_expr that
   is optimized under the assumption that EXP's value doesn't change before
   its subsequent reuse(s) except through its potential reevaluation.  */

tree
gnat_protect_expr (tree exp)
{
  tree type = TREE_TYPE (exp);
  enum tree_code code = TREE_CODE (exp);

  if (TREE_CONSTANT (exp) || code == SAVE_EXPR || code == NULL_EXPR)
    return exp;

  /* If EXP has no side effects, we theoritically don't need to do anything.
     However, we may be recursively passed more and more complex expressions
     involving checks which will be reused multiple times and eventually be
     unshared for gimplification; in order to avoid a complexity explosion
     at that point, we protect any expressions more complex than a simple
     arithmetic expression.  */
  if (!TREE_SIDE_EFFECTS (exp))
    {
      tree inner = skip_simple_arithmetic (exp);
      if (!EXPR_P (inner) || REFERENCE_CLASS_P (inner))
	return exp;
    }

  /* If this is a conversion, protect what's inside the conversion.  */
  if (code == NON_LVALUE_EXPR
      || CONVERT_EXPR_CODE_P (code)
      || code == VIEW_CONVERT_EXPR)
  return build1 (code, type, gnat_protect_expr (TREE_OPERAND (exp, 0)));

  /* If we're indirectly referencing something, we only need to protect the
     address since the data itself can't change in these situations.  */
  if (code == INDIRECT_REF || code == UNCONSTRAINED_ARRAY_REF)
    {
      tree t = build1 (code, type, gnat_protect_expr (TREE_OPERAND (exp, 0)));
      TREE_READONLY (t) = TYPE_READONLY (type);
      return t;
    }

  /* If this is a COMPONENT_REF of a fat pointer, save the entire fat pointer.
     This may be more efficient, but will also allow us to more easily find
     the match for the PLACEHOLDER_EXPR.  */
  if (code == COMPONENT_REF
      && TYPE_IS_FAT_POINTER_P (TREE_TYPE (TREE_OPERAND (exp, 0))))
    return build3 (code, type, gnat_protect_expr (TREE_OPERAND (exp, 0)),
		   TREE_OPERAND (exp, 1), TREE_OPERAND (exp, 2));

  /* If this is a fat pointer or something that can be placed in a register,
     just make a SAVE_EXPR.  Likewise for a CALL_EXPR as large objects are
     returned via invisible reference in most ABIs so the temporary will
     directly be filled by the callee.  */
  if (TYPE_IS_FAT_POINTER_P (type)
      || TYPE_MODE (type) != BLKmode
      || code == CALL_EXPR)
    return save_expr (exp);

  /* Otherwise reference, protect the address and dereference.  */
  return
    build_unary_op (INDIRECT_REF, type,
		    save_expr (build_unary_op (ADDR_EXPR,
					       build_reference_type (type),
					       exp)));
}

/* This is equivalent to stabilize_reference_1 in tree.c but we take an extra
   argument to force evaluation of everything.  */

static tree
gnat_stabilize_reference_1 (tree e, bool force)
{
  enum tree_code code = TREE_CODE (e);
  tree type = TREE_TYPE (e);
  tree result;

  /* We cannot ignore const expressions because it might be a reference
     to a const array but whose index contains side-effects.  But we can
     ignore things that are actual constant or that already have been
     handled by this function.  */
  if (TREE_CONSTANT (e) || code == SAVE_EXPR)
    return e;

  switch (TREE_CODE_CLASS (code))
    {
    case tcc_exceptional:
    case tcc_declaration:
    case tcc_comparison:
    case tcc_expression:
    case tcc_reference:
    case tcc_vl_exp:
      /* If this is a COMPONENT_REF of a fat pointer, save the entire
	 fat pointer.  This may be more efficient, but will also allow
	 us to more easily find the match for the PLACEHOLDER_EXPR.  */
      if (code == COMPONENT_REF
	  && TYPE_IS_FAT_POINTER_P (TREE_TYPE (TREE_OPERAND (e, 0))))
	result
	  = build3 (code, type,
		    gnat_stabilize_reference_1 (TREE_OPERAND (e, 0), force),
		    TREE_OPERAND (e, 1), TREE_OPERAND (e, 2));
      /* If the expression has side-effects, then encase it in a SAVE_EXPR
	 so that it will only be evaluated once.  */
      /* The tcc_reference and tcc_comparison classes could be handled as
	 below, but it is generally faster to only evaluate them once.  */
      else if (TREE_SIDE_EFFECTS (e) || force)
	return save_expr (e);
      else
	return e;
      break;

    case tcc_binary:
      /* Recursively stabilize each operand.  */
      result
	= build2 (code, type,
		  gnat_stabilize_reference_1 (TREE_OPERAND (e, 0), force),
		  gnat_stabilize_reference_1 (TREE_OPERAND (e, 1), force));
      break;

    case tcc_unary:
      /* Recursively stabilize each operand.  */
      result
	= build1 (code, type,
		  gnat_stabilize_reference_1 (TREE_OPERAND (e, 0), force));
      break;

    default:
      gcc_unreachable ();
    }

  /* See similar handling in gnat_stabilize_reference.  */
  TREE_READONLY (result) = TREE_READONLY (e);
  TREE_SIDE_EFFECTS (result) |= TREE_SIDE_EFFECTS (e);
  TREE_THIS_VOLATILE (result) = TREE_THIS_VOLATILE (e);

  return result;
}

/* This is equivalent to stabilize_reference in tree.c but we know how to
   handle our own nodes and we take extra arguments.  FORCE says whether to
   force evaluation of everything.  We set SUCCESS to true unless we walk
   through something we don't know how to stabilize.  */

tree
gnat_stabilize_reference (tree ref, bool force, bool *success)
{
  tree type = TREE_TYPE (ref);
  enum tree_code code = TREE_CODE (ref);
  tree result;

  /* Assume we'll success unless proven otherwise.  */
  if (success)
    *success = true;

  switch (code)
    {
    case CONST_DECL:
    case VAR_DECL:
    case PARM_DECL:
    case RESULT_DECL:
      /* No action is needed in this case.  */
      return ref;

    case ADDR_EXPR:
    CASE_CONVERT:
    case FLOAT_EXPR:
    case FIX_TRUNC_EXPR:
    case VIEW_CONVERT_EXPR:
      result
	= build1 (code, type,
		  gnat_stabilize_reference (TREE_OPERAND (ref, 0), force,
					    success));
      break;

    case INDIRECT_REF:
    case UNCONSTRAINED_ARRAY_REF:
      result = build1 (code, type,
		       gnat_stabilize_reference_1 (TREE_OPERAND (ref, 0),
						   force));
      break;

    case COMPONENT_REF:
     result = build3 (COMPONENT_REF, type,
		      gnat_stabilize_reference (TREE_OPERAND (ref, 0), force,
						success),
		      TREE_OPERAND (ref, 1), NULL_TREE);
      break;

    case BIT_FIELD_REF:
      result = build3 (BIT_FIELD_REF, type,
		       gnat_stabilize_reference (TREE_OPERAND (ref, 0), force,
						 success),
		       gnat_stabilize_reference_1 (TREE_OPERAND (ref, 1),
						   force),
		       gnat_stabilize_reference_1 (TREE_OPERAND (ref, 2),
						   force));
      break;

    case ARRAY_REF:
    case ARRAY_RANGE_REF:
      result = build4 (code, type,
		       gnat_stabilize_reference (TREE_OPERAND (ref, 0), force,
						 success),
		       gnat_stabilize_reference_1 (TREE_OPERAND (ref, 1),
						   force),
		       NULL_TREE, NULL_TREE);
      break;

    case CALL_EXPR:
      result = gnat_stabilize_reference_1 (ref, force);
      break;

    case COMPOUND_EXPR:
      result = build2 (COMPOUND_EXPR, type,
		       gnat_stabilize_reference (TREE_OPERAND (ref, 0), force,
						 success),
		       gnat_stabilize_reference_1 (TREE_OPERAND (ref, 1),
						   force));
      break;

    case CONSTRUCTOR:
      /* Constructors with 1 element are used extensively to formally
	 convert objects to special wrapping types.  */
      if (TREE_CODE (type) == RECORD_TYPE
	  && VEC_length (constructor_elt, CONSTRUCTOR_ELTS (ref)) == 1)
	{
	  tree index
	    = VEC_index (constructor_elt, CONSTRUCTOR_ELTS (ref), 0)->index;
	  tree value
	    = VEC_index (constructor_elt, CONSTRUCTOR_ELTS (ref), 0)->value;
	  result
	    = build_constructor_single (type, index,
					gnat_stabilize_reference_1 (value,
								    force));
	}
      else
	{
	  if (success)
	    *success = false;
	  return ref;
	}
      break;

    case ERROR_MARK:
      ref = error_mark_node;

      /* ...  fall through to failure ... */

      /* If arg isn't a kind of lvalue we recognize, make no change.
	 Caller should recognize the error for an invalid lvalue.  */
    default:
      if (success)
	*success = false;
      return ref;
    }

  /* TREE_THIS_VOLATILE and TREE_SIDE_EFFECTS set on the initial expression
     may not be sustained across some paths, such as the way via build1 for
     INDIRECT_REF.  We reset those flags here in the general case, which is
     consistent with the GCC version of this routine.

     Special care should be taken regarding TREE_SIDE_EFFECTS, because some
     paths introduce side-effects where there was none initially (e.g. if a
     SAVE_EXPR is built) and we also want to keep track of that.  */
  TREE_READONLY (result) = TREE_READONLY (ref);
  TREE_SIDE_EFFECTS (result) |= TREE_SIDE_EFFECTS (ref);
  TREE_THIS_VOLATILE (result) = TREE_THIS_VOLATILE (ref);

  return result;
}
