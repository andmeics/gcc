/* Processing rules for constraints.
   Copyright (C) 2013-2014 Free Software Foundation, Inc.
   Contributed by Andrew Sutton (andrew.n.sutton@gmail.com)

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
#include "hash-set.h"
#include "machmode.h"
#include "vec.h"
#include "double-int.h"
#include "input.h"
#include "alias.h"
#include "symtab.h"
#include "wide-int.h"
#include "inchash.h"
#include "tree.h"
#include "print-tree.h"
#include "stringpool.h"
#include "attribs.h"
#include "intl.h"
#include "flags.h"
#include "cp-tree.h"
#include "c-family/c-common.h"
#include "c-family/c-objc.h"
#include "cp-objcp-common.h"
#include "tree-inline.h"
#include "decl.h"
#include "toplev.h"
#include "type-utils.h"

/*---------------------------------------------------------------------------
                       Operations on constraints
---------------------------------------------------------------------------*/

/* Returns true if C is a constraint tree code. */
static inline bool
constraint_p (tree_code c)
{
  return PRED_CONSTR <= c && c <= DISJ_CONSTR;
}

/* Returns true if T is a constraint. */
bool
constraint_p (tree t)
{
  return constraint_p (TREE_CODE (t));
}

/* Make a predicate constraint from the given expression. */
tree
make_predicate_constraint (tree expr)
{
  return build_nt (PRED_CONSTR, expr);
}

/* Returns the conjunction of two constraints A and B. Note that 
   conjoining a non-null constraint with NULL_TREE is an identity 
   operation. That is, for non-null A,

      conjoin_constraints(a, NULL_TREE) == a

   and

      conjoin_constraints (NULL_TREE, a) == a

   If both A and B are NULL_TREE, the result is also NULL_TREE. */
tree
conjoin_constraints (tree a, tree b)
{
  gcc_assert (a ? constraint_p (a) : true);
  gcc_assert (b ? constraint_p (b) : true);
  if (a)
    return b ? build_nt (CONJ_CONSTR, a, b) : a;
  else if (b)
    return b;
  else
    return NULL_TREE;
}

/* Transform the vector of expressions in the T into a conjunction
   of requirements. T must be a TREE_VEC. */
tree
conjoin_constraints (tree t)
{
  gcc_assert (TREE_CODE (t) == TREE_VEC);
  tree r = NULL_TREE;
  for (int i = 0; i < TREE_VEC_LENGTH (t); ++i)
    r = conjoin_constraints (r, TREE_VEC_ELT (t, i));
  return r;
}

/*---------------------------------------------------------------------------
                    Resolution of qualified concept names
---------------------------------------------------------------------------*/

/* This facility is used to resolve constraint checks from 
   requirement expressions. A constraint check is a call to 
   a function template declared with the keyword 'concept'.

   The result of resolution is a pair (a TREE_LIST) whose value 
   is the matched declaration, and whose purpose contains the 
   coerced template arguments that can be substituted into the 
   call.  */

// Given an overload set OVL, try to find a unique definition that can be
// instantiated by the template arguments ARGS.
//
// This function is not called for arbitrary call expressions. In particular,
// the call expression must be written with explicit template arguments
// and no function arguments. For example:
//
//      f<T, U>()
//
// If a single match is found, this returns a TREE_LIST whose VALUE
// is the constraint function (not the template), and its PURPOSE is
// the complete set of arguments substituted into the parameter list.
static tree
resolve_constraint_check (tree ovl, tree args)
{
  tree cands = NULL_TREE;
  for (tree p = ovl; p != NULL_TREE; p = OVL_NEXT (p))
    {
      // Get the next template overload.
      tree tmpl = OVL_CURRENT (p);
      if (TREE_CODE (tmpl) != TEMPLATE_DECL)
        continue;

      // Don't try to deduce checks for non-concept-like. We often
      // end up trying to resolve constraints in functional casts
      // as part of a post-fix expression. We can save time and
      // headaches by not instantiating those declarations.
      //
      // NOTE: This masks a potential error, caused by instantiating
      // non-deduced contexts using placeholder arguments.
      tree fn = DECL_TEMPLATE_RESULT (tmpl);
      if (DECL_ARGUMENTS (fn))
        continue;
      if (!DECL_DECLARED_CONCEPT_P (fn))
        continue;

      // Remember the candidate if we can deduce a substitution.
      ++processing_template_decl;
      tree parms = TREE_VALUE (DECL_TEMPLATE_PARMS (tmpl));
      if (tree subst = coerce_template_parms (parms, args, tmpl))
        if (subst != error_mark_node)
          cands = tree_cons (subst, fn, cands);
      --processing_template_decl;
    }

  // If we didn't find a unique candidate, then this is
  // not a constraint check.
  if (!cands || TREE_CHAIN (cands))
    return NULL_TREE;

  // Constraints must be declared concepts.
  tree decl = TREE_VALUE (cands);
  if (!DECL_DECLARED_CONCEPT_P (decl))
    return NULL_TREE;

  return cands;
}

// Determine if the the call expression CALL is a constraint check, and
// return the concept declaration and arguments being checked. If CALL
// does not denote a constraint check, return NULL.
tree
resolve_constraint_check (tree call)
{
  gcc_assert (TREE_CODE (call) == CALL_EXPR);

  // A constraint check must be only a template-id expression. If
  // it's a call to a base-link, its function(s) should be a
  // template-id expression. If this is not a template-id, then it
  // cannot be a concept-check.
  tree target = CALL_EXPR_FN (call);
  if (BASELINK_P (target))
    target = BASELINK_FUNCTIONS (target);
  if (TREE_CODE (target) != TEMPLATE_ID_EXPR)
    return NULL_TREE;

  // Get the overload set and template arguments and try to
  // resolve the target.
  tree ovl = TREE_OPERAND (target, 0);
  
  /* This is a function call of a variable concept... ill-formed. */
  if (TREE_CODE (ovl) == TEMPLATE_DECL)
    {
      error ("function call of variable concept %qE", call);
      return error_mark_node;
    }

  tree args = TREE_OPERAND (target, 1);
  return resolve_constraint_check (ovl, args);
}

// Given a call expression or template-id expression to a concept, EXPR,
// possibly including a placeholder argument, deduce the concept being checked
// and the prototype parameter.  Returns true if the constraint and prototype
// can be deduced and false otherwise. Note that the CHECK and PROTO arguments
// are set to NULL_TREE if this returns false.
bool
deduce_constrained_parameter (tree expr, tree& check, tree& proto)
{
  if (TREE_CODE (expr) == TEMPLATE_ID_EXPR)
    {
      // Get the check and prototype parameter from the variable template.
      tree decl = TREE_OPERAND (expr, 0);
      tree parms = DECL_TEMPLATE_PARMS (decl);

      check = DECL_TEMPLATE_RESULT (decl);
      proto = TREE_VALUE (TREE_VEC_ELT (TREE_VALUE (parms), 0));
      return true;
    }
  else if (TREE_CODE (expr) == CALL_EXPR)
    {
      // Resolve the constraint check to deduce the prototype parameter.
      tree info = resolve_constraint_check (expr);
      if (info && info != error_mark_node)
        {
          // Get function and argument from the resolved check expression and
          // the prototype parameter. Note that if the first argument was a
          // pack, we need to extract the first element ot get the prototype.
          check = TREE_VALUE (info);
          tree arg = TREE_VEC_ELT (TREE_PURPOSE (info), 0);
          if (ARGUMENT_PACK_P (arg))
            arg = TREE_VEC_ELT (ARGUMENT_PACK_ARGS (arg), 0);
          proto = TREE_TYPE (arg);
          return true;
        }
      check = proto = NULL_TREE;
      return false;
    }
  else
    gcc_unreachable ();
}

// Given a call expression or template-id expression to a concept, EXPR,
// deduce the concept being checked and return the template arguments.
// Returns NULL_TREE if deduction fails.
static tree
deduce_concept_introduction (tree expr)
{
  if (TREE_CODE (expr) == TEMPLATE_ID_EXPR)
    {
      // Get the parameters from the template expression.
      tree decl = TREE_OPERAND (expr, 0);
      tree args = TREE_OPERAND (expr, 1);
      tree var = DECL_TEMPLATE_RESULT (decl);
      tree parms = TREE_VALUE (DECL_TEMPLATE_PARMS (decl));

      parms = coerce_template_parms (parms, args, var);      
      // Check that we are returned a proper set of arguments.
      if (parms == error_mark_node)
        return NULL_TREE;
      return parms;
    }
  else if (TREE_CODE (expr) == CALL_EXPR)
    {
      // Resolve the constraint check and return arguments.
      tree info = resolve_constraint_check (expr);
      if (info && info != error_mark_node)
        return TREE_PURPOSE (info);
      return NULL_TREE;
    }
  else
    gcc_unreachable ();
}

namespace {

/*---------------------------------------------------------------------------
                       Lifting of concept definitions
---------------------------------------------------------------------------*/

tree lift_expression (tree);

/* If the tree T has operands, then lift any concepts out of them.  */
tree
lift_operands (tree t)
{
  if (int n = tree_operand_length (t))
    {
      t = copy_node (t);
      for (int i = 0; i < n; ++i)
        TREE_OPERAND (t, i) = lift_expression (TREE_OPERAND (t, i));
    }
  return t;
}

/* Recursively lift all operands of the function call. Also, check
   that the call target is not accidentally a variable concept
   since that's ill-formed.  */
tree
lift_function_call (tree t)
{
  gcc_assert (TREE_CODE (t) == CALL_EXPR);
  tree target = CALL_EXPR_FN (t);
  if (VAR_P (target)) {
    error ("%qE cannot be used as a function", target);
    return error_mark_node;
  }
  return lift_operands (t);
}

/* Inline a function (concept) definition by substituting
   ARGS into its body. */
tree
lift_function_definition (tree fn, tree args)
{
  /* Extract the body of the function minus the return expression.  */
  tree body = DECL_SAVED_TREE (fn);
  if (!body)
    return error_mark_node;
  if (TREE_CODE (body) == BIND_EXPR)
    body = BIND_EXPR_BODY (body);
  
  /* FIXME: Why isn't this being checked at the point of definition? */
  if (TREE_CODE (body) != RETURN_EXPR)
    {
      error_at (DECL_SOURCE_LOCATION (fn),
                "concept definition %qD has multiple statements", fn);
      return error_mark_node;
    }

  gcc_assert (TREE_CODE (body) == RETURN_EXPR);
  body = TREE_OPERAND (body, 0);

  /* Substitute template arguments to produce our inline expression.  */
  tree result = tsubst_expr (body, args, tf_none, NULL_TREE, false);
  if (result == error_mark_node)
    return error_mark_node;

  return lift_expression (result);
}

/* Inline a reference to a function concept.  */
tree
lift_call_expression (tree t)
{
  /* Try to resolve this function call as a concept.  If not, then 
     it can be returned as-is.  */
  tree check = resolve_constraint_check (t);
  if (!check)
    return lift_function_call (t);
  if (check == error_mark_node)
    return error_mark_node;

  tree fn = TREE_VALUE (check);
  tree args = TREE_PURPOSE (check);
  return lift_function_definition (fn, args);
}

tree
lift_variable_initializer (tree var, tree args)
{
  /* Extract the body from the variable initializer.  */
  tree init = DECL_INITIAL (var);
  if (!init)
    return error_mark_node;

  /* Substitute the arguments to form our new inline expression.  */
  tree result = tsubst_expr (init, args, tf_none, NULL_TREE, false);
  if (result == error_mark_node)
    return error_mark_node;

  return lift_expression (result);
}

/* Inline a reference to a variable concept.  */
tree
lift_variable_concept (tree t)
{
  tree tmpl = TREE_OPERAND (t, 0);
  tree args = TREE_OPERAND (t, 1);
  tree decl = DECL_TEMPLATE_RESULT (tmpl);
  gcc_assert (DECL_DECLARED_CONCEPT_P (decl));
  return lift_variable_initializer (decl, args);
}

/* Determine if a template-id is a variable concept and inline.  

   TODO: I don't think that we get template-ids for variable 
   templates any more. They tend to be transformed into var-decl
   specializations when an id-expression is parsed.
*/
tree
lift_template_id (tree t)
{
  if (variable_concept_p (TREE_OPERAND (t, 0)))
    return lift_variable_concept (t);

  /* Check that we didn't refer to a function concept like
      a variable.

     TODO: Add a note on how to fix this.  */
  tree tmpl = TREE_OPERAND (t, 0);
  if (TREE_CODE (tmpl) == OVERLOAD)
    {
      tree fn = OVL_FUNCTION (tmpl);
      if (TREE_CODE (fn) == TEMPLATE_DECL 
          && DECL_DECLARED_CONCEPT_P (DECL_TEMPLATE_RESULT (fn)))
        {
          error ("invalid reference to function concept %qD", fn);
          return error_mark_node;
        }
    }

  return t;
}

/* If the variable declaration is a specialization of a concept
   declaration, then inline it's initializer. */
tree
lift_variable (tree t)
{
  if (tree ti = DECL_TEMPLATE_INFO (t)) 
    {
      tree tmpl = TI_TEMPLATE (ti);
      tree args = TI_ARGS (ti);
      tree decl = DECL_TEMPLATE_RESULT (tmpl);
      if (DECL_DECLARED_CONCEPT_P (decl))
        return lift_variable_initializer (decl, args);
    }
  return t;
}

/* Lift any constraints appearing in a nested requirement of
   a requires-expression. */
tree
lift_requires_expression (tree t)
{
  tree parms = TREE_OPERAND (t, 0);
  tree reqs = TREE_OPERAND (t, 1);
  tree result = NULL_TREE;
  for (; reqs != NULL_TREE; reqs = TREE_CHAIN (reqs))
    {
      tree req = TREE_VALUE (reqs);
      if (TREE_CODE (req) == NESTED_REQ)
        {
          tree expr = lift_expression (TREE_OPERAND (req, 0));
          req = finish_nested_requirement (expr);
        }
      result = tree_cons (NULL_TREE, req, result);
    }
  return finish_requires_expr (parms, result);
}

/* Transform the pack expansion by lifting its pattern. */
tree
lift_pack_expansion (tree t)
{
  TREE_OPERAND (t, 0) = lift_expression (TREE_OPERAND (t, 0));
  return t;
}

/* Inline references to specializations of concepts.  */
tree 
lift_expression (tree t)
{
  if (t == NULL_TREE)
    return NULL_TREE;
  
  if (t == error_mark_node)
    return error_mark_node;

  /* Concepts can be referred to by call or variable. All other
     nodes are preserved.  */
  switch (TREE_CODE (t))
    {
    case CALL_EXPR:
      return lift_call_expression (t);
    
    case TEMPLATE_ID_EXPR:
      return lift_template_id (t);

    case VAR_DECL:
      return lift_variable (t);
    
    case REQUIRES_EXPR:
      return lift_requires_expression (t);

    case EXPR_PACK_EXPANSION:
      return lift_pack_expansion (t);

    case TREE_LIST:
      {
        t = copy_node (t);
        TREE_VALUE (t) = lift_expression (TREE_VALUE (t));
        TREE_CHAIN (t) = lift_expression (TREE_CHAIN (t));
        return t;
      }

    default:
      return lift_operands (t);
    }
}

/*---------------------------------------------------------------------------
                        Constraint normalization
---------------------------------------------------------------------------*/

tree transform_expression (tree);

/* Check that the logical-or or logical-and expression does
   not result in a call to a user-defined user-defined operator 
   (temp.constr.op). Returns true if the logical operator is 
   admissible and false otherwise. */
bool
check_logical_expr (tree t) 
{
  /* We can't do much for type dependent expressions. */
  if (type_dependent_expression_p (t))
    return true;

  /* Resolve the logical operator. Note that template processing is
     disabled so we get the actual call or target expression back.
     not_processing_template_sentinel sentinel. */
  tree arg1 = TREE_OPERAND (t, 0);
  tree arg2 = TREE_OPERAND (t, 1);
  tree ovl = NULL_TREE;
  tree expr = build_new_op (input_location, TREE_CODE (t), LOOKUP_NORMAL, 
                            arg1, arg2, /*arg3*/NULL_TREE, 
                            &ovl, tf_none);
  if (TREE_CODE (expr) != TREE_CODE (t))
    {
      error ("user-defined operator %qs in constraint %qE",
             operator_name_info[TREE_CODE (t)].name, t);
      return false;
    }
  return true;
}

/* Transform a logical-or or logical-and expression into either
   a conjunction or disjunction. */
tree
xform_logical (tree t, tree_code c)
{
  if (!check_logical_expr (t))
    return error_mark_node;
  tree t0 = transform_expression (TREE_OPERAND (t, 0));
  tree t1 = transform_expression (TREE_OPERAND (t, 1));
  return build_nt (c, t0, t1);
}

/* A simple requirement T introduces an expression constraint
   for its expression. */
inline tree
xform_simple_requirement (tree t)
{
  return build_nt (EXPR_CONSTR, TREE_OPERAND (t, 0));
}

/* A type requirement T introduce a type constraint for its
   type. */
inline tree
xform_type_requirement (tree t)
{
  return build_nt (TYPE_CONSTR, TREE_OPERAND (t, 0));
}

/* A compound requirement T introduces a conjunction of constraints
   depending on its form. The conjunction always includes
   an expression constraint for the expression of the requirement.
   If a trailing return type was specified, the conjunction includes
   either an implicit conversion constraint or an argument
   deduction constraint. If the noexcept specifier is present, the
   conjunction includes an exception constraint. */
tree
xform_compound_requirement (tree t)
{
  tree expr = TREE_OPERAND (t, 0);
  tree constr = build_nt (EXPR_CONSTR, TREE_OPERAND (t, 0));

  /* If a type is given, append an implicit conversion or
     argument deduction constraint. 

     FIXME: Handle argument deduction constraints. */
  if (tree type = TREE_OPERAND (t, 1)) 
    {
      tree iconv = build_nt (ICONV_CONSTR, expr, type);
      constr = conjoin_constraints (constr, iconv);
    }

  /* If noexcept is present, append an exception constraint. */
  if (COMPOUND_REQ_NOEXCEPT_P (t))
    {
      tree except = build_nt (EXCEPT_CONSTR, expr);
      constr = conjoin_constraints (constr, except);
    }

  return constr;
}

/* A nested requirement T introduces a conjunction of constraints
   corresponding to its constraint-expression. */
inline tree
xform_nested_requirement (tree t)
{
  return transform_expression (TREE_OPERAND (t, 0));
}

/* Transform a requirement T into one or more constraints. */
tree 
xform_requirement (tree t)
{
  switch (TREE_CODE (t))
  {
  case SIMPLE_REQ:
    return xform_simple_requirement (t);
  
  case TYPE_REQ:
    return xform_type_requirement (t);
  
  case COMPOUND_REQ:
    return xform_compound_requirement (t);
  
  case NESTED_REQ:
    return xform_nested_requirement (t);

  default:
    gcc_unreachable ();
  }
  return error_mark_node;
}

/* Transform a sequence of requirements into a conjunction of
   constraints. */
tree
xform_requirements (tree t)
{
  tree result = NULL_TREE;
  for (; t; t = TREE_CHAIN (t)) {
    tree constr = xform_requirement (TREE_VALUE (t));
    result = conjoin_constraints (result, constr);
  }
  return result;
}

/* Transform a requires-expression into a parameterized constraint. */
tree
xform_requires_expr (tree t)
{
  tree operand = xform_requirements (TREE_OPERAND (t, 1));
  if (tree parms = TREE_OPERAND (t, 0))
    return build_nt (PARM_CONSTR, parms, operand);
  else
    return operand;
}

/* Transform an expression into an atomic predicate constraint. 
    After substitution, the expression of a predicate constraint shall 
    have type bool (temp.constr.pred). For non-type- dependent 
    expressions, we can check that now. */
tree
xform_atomic (tree t) 
{
  if (!type_dependent_expression_p (t)) 
  {
    tree type = cv_unqualified (TREE_TYPE (t));
    if (!same_type_p (type, boolean_type_node))
      {
        error ("predicate constraint %qE does not have type %<bool%>", t);
        return error_mark_node;
      }
  }
  return build_nt (PRED_CONSTR, t);
}

/* Transform an expression into a constraint. */
tree
xform_expr (tree t)
{
  switch (TREE_CODE (t))
    {
    case TRUTH_ANDIF_EXPR:
      return xform_logical (t, CONJ_CONSTR);
    
    case TRUTH_ORIF_EXPR:
      return xform_logical (t, DISJ_CONSTR);
    
    case REQUIRES_EXPR:
      return xform_requires_expr (t);
    
    case BIND_EXPR:        
      return transform_expression (BIND_EXPR_BODY (t));
    
    default:
      /* All other constraints are atomic. */ 
      return xform_atomic (t);
    }
}

/* Transform a statement into an expression. */
tree
xform_stmt (tree t)
{
  switch (TREE_CODE (t))
    {
    case RETURN_EXPR:
      return transform_expression (TREE_OPERAND (t, 0));
    default:
      gcc_unreachable ();
    }
  return error_mark_node;
}

// Reduction rules for the declaration T.
tree
xform_decl (tree t)
{
  switch (TREE_CODE (t))
    {
    case VAR_DECL:
      return xform_atomic (t);
    default:
      gcc_unreachable ();
    }
  return error_mark_node;
}

/* Transform an exceptional node into a constraint. */
tree
xform_misc (tree t)
{
  switch (TREE_CODE (t))
    {
    case TRAIT_EXPR:
      return xform_atomic (t);
    case CONSTRUCTOR:
      return xform_atomic (t);
    default:
      gcc_unreachable ();
    }
  return error_mark_node;
}


/* Transform a lifted expression into a constraint. This either
   returns a constraint, or it returns error_mark_node when
   a constraint cannot be formed. */
tree
transform_expression (tree t)
{
  if (!t) 
    return NULL_TREE;
 
  if (t == error_mark_node)
    return error_mark_node;

  switch (TREE_CODE_CLASS (TREE_CODE (t))) 
    {
    case tcc_unary:
    case tcc_binary:
    case tcc_expression:
    case tcc_vl_exp:
      return xform_expr (t);
    
    case tcc_statement:   
      return xform_stmt (t);
    
    case tcc_declaration: 
      return xform_decl (t);
    
    case tcc_exceptional: 
      return xform_misc (t);
    
    case tcc_constant:
    case tcc_reference:
    case tcc_comparison:
      /* These are atomic predicate constraints. */
      return xform_atomic (t);

    default:
      /* Unhandled node kind. */
      gcc_unreachable ();
    }
  return error_mark_node;
}

/*---------------------------------------------------------------------------
                        Constraint normalization
---------------------------------------------------------------------------*/

tree normalize_constraint (tree);

/* The normal form of the disjunction T0 /\ T1 is the conjunction
   of the normal form of T0 and the normal form of T1 */
inline tree
normalize_conjunction (tree t)
{
  tree t0 = normalize_constraint (TREE_OPERAND (t, 0));
  tree t1 = normalize_constraint (TREE_OPERAND (t, 1));
  return build_nt (CONJ_CONSTR, t0, t1);
}

/* The normal form of the disjunction T0 \/ T1 is the disjunction 
   of the normal form of T0 and the normal form of T1 */
inline tree
normalize_disjunction (tree t)
{
  tree t0 = normalize_constraint (TREE_OPERAND (t, 0));
  tree t1 = normalize_constraint (TREE_OPERAND (t, 1));
  return build_nt (DISJ_CONSTR, t0, t1);
}

/* A predicate constraint is normalized in two stages. First all
   references specializations of concepts are replaced by their
   substituted definitions. Then, the resulting expression is
   transformed into a constraint by transforming && expressions
   into conjunctions and || into disjunctions. */
tree 
normalize_predicate_constraint (tree t)
{
  tree expr = PRED_CONSTR_EXPR (t);
  tree lifted = lift_expression (expr);
  tree constr = transform_expression (lifted);
  return constr;
}

/* The normal form of a parameterized constraint is the normal
   form of its operand. */
tree
normalize_parameterized_constraint (tree t)
{
  tree parms = PARM_CONSTR_PARMS (t);
  tree operand = normalize_constraint (PARM_CONSTR_OPERAND (t));
  return build_nt (PARM_CONSTR, parms, operand);
}

/* Normalize the constraint T by reducing it so that it is
   comprised of only conjunctions and disjunctions of atomic
   constraints. */
tree
normalize_constraint (tree t)
{
  if (!t)
    return NULL_TREE;
  
  switch (TREE_CODE (t))
    {
      case CONJ_CONSTR:
        return normalize_conjunction (t);
      
      case DISJ_CONSTR:
        return normalize_disjunction (t);
      
      case PRED_CONSTR:
        return normalize_predicate_constraint (t);
      
      case PARM_CONSTR:
        return normalize_parameterized_constraint (t);
      
      case EXPR_CONSTR:
      case TYPE_CONSTR:
      case ICONV_CONSTR:
      case DEDUCT_CONSTR:
      case EXCEPT_CONSTR:
        /* These constraints are defined to be atomic. */
        return t;
      
      default:
        /* CONSTR was not a constraint. */
        gcc_unreachable();
    }
  return error_mark_node;
}

} /* namespace */


// -------------------------------------------------------------------------- //
// Constraint Semantic Processing
//
// The following functions are called by the parser and substitution rules
// to create and evaluate constraint-related nodes.


// If the recently parsed TYPE declares or defines a template or template
// specialization, get its corresponding constraints from the current
// template parameters and bind them to TYPE's declaration.
tree
associate_classtype_constraints (tree type)
{
  if (!type || type == error_mark_node || TREE_CODE (type) != RECORD_TYPE)
    return type;

  // An explicit class template specialization has no template
  // parameters.
  if (!current_template_parms)
    return type;

  if (CLASSTYPE_IS_TEMPLATE (type) || CLASSTYPE_TEMPLATE_SPECIALIZATION (type))
    {
      tree decl = TYPE_STUB_DECL (type);
      tree reqs = TEMPLATE_PARMS_CONSTRAINTS (current_template_parms);
      tree ci = build_constraints (reqs, NULL_TREE);

      // An implicitly instantiated member template declaration already
      // has associated constraints. If it is defined outside of its
      // class, then we need match these constraints against those of
      // original declaration.
      if (tree orig_ci = get_constraints (decl))
        {
          if (!equivalent_constraints (ci, orig_ci))
            {
              // FIXME: Improve diagnostics.
              error ("%qT does not match any declaration", type);
              return error_mark_node;
            }
          return type;
        }
      set_constraints (decl, ci);
    }
  return type;
}

namespace {

// Create an empty constraint info block.
inline tree_constraint_info*
build_constraint_info ()
{
  return (tree_constraint_info *)make_node (CONSTRAINT_INFO);
}

} // namespace

/* Build a constraint-info object that contains the 
   associated condstraints of a declaration. This also 
   includes the declaration's template requirements (TREQS)
   and any trailing requirements for a function declarator
   (DREQS). Note that both TREQS and DREQS must be constraints.

   If the declaration has neither template nor declaration 
   requirements this returns NULL_TREE, indicating an 
   unconstrained declaration. */
tree
build_constraints (tree tmpl_reqs, tree decl_reqs)
{
  gcc_assert (tmpl_reqs ? constraint_p (tmpl_reqs) : true);
  gcc_assert (decl_reqs ? constraint_p (decl_reqs) : true);

  if (!tmpl_reqs && !decl_reqs)
    return NULL_TREE;

  tree_constraint_info* ci = build_constraint_info ();
  ci->template_reqs = tmpl_reqs;
  ci->declarator_reqs = decl_reqs;
  ci->associated_constr = conjoin_constraints (tmpl_reqs, decl_reqs);

  ++processing_template_decl;
  ci->normalized_constr = normalize_constraint (ci->associated_constr);
  --processing_template_decl;
  
  ci->assumptions = decompose_assumptions (ci->normalized_constr);
  return (tree)ci;
}

namespace {
// Build a new call expression, but don't actually generate a new
// function call. We just want the tree, not the semantics.
inline tree
build_call_check (tree id)
{
  ++processing_template_decl;
  vec<tree, va_gc> *fargs = make_tree_vector();
  tree call = finish_call_expr (id, &fargs, false, false, tf_none);
  --processing_template_decl;
  return call;
}
} // namespace

// Construct a concept check for the given TARGET. The target may be
// an overload set or a baselink referring to an overload set. Template
// arguments to the target are given by ARG and REST. If the target is
// a function (overload set or baselink referring to an overload set),
// then this builds the call expression  TARGET<ARG, REST>(). If REST is
// NULL_TREE, then the resulting check is just TARGET<ARG>(). If ARG is
// NULL_TREE, then the resulting check is TARGET<REST>().
tree
build_concept_check (tree target, tree arg, tree rest)
{
  gcc_assert (rest ? TREE_CODE (rest) == TREE_VEC : true);

  // Build a template-id that acts as the call target using TARGET as
  // the template and ARG as the only explicit argument.
  int n = rest ? TREE_VEC_LENGTH (rest) : 0;
  tree targs;
  if (arg)
    {
      targs = make_tree_vec (n + 1);
      TREE_VEC_ELT (targs, 0) = arg;
      if (rest)
        for (int i = 0; i < n; ++i)
          TREE_VEC_ELT (targs, i + 1) = TREE_VEC_ELT (rest, i);
      SET_NON_DEFAULT_TEMPLATE_ARGS_COUNT (targs, n + 1);
    }
  else
    {
      gcc_assert (rest != NULL_TREE);
      targs = rest;
    }

  if (variable_template_p (target))
    return lookup_template_variable (target, targs);
  else
    return build_call_check (lookup_template_function (target, targs));
}

// Returns a TYPE_DECL that contains sufficient information to build
// a template parameter of the same kind as PROTO and constrained
// by the concept declaration FN. PROTO is saved as the initializer of
// the new type decl, and the constraining function is saved in
// DECL_SIZE_UNIT.
//
// If specified, ARGS provides additional arguments to the constraint
// check. These are stored in the DECL_SIZE field.
tree
build_constrained_parameter (tree fn, tree proto, tree args)
{
  tree name = DECL_NAME (fn);
  tree type = TREE_TYPE (proto);
  tree decl = build_decl (input_location, TYPE_DECL, name, type);
  DECL_INITIAL (decl) = proto;  // Describing parameter
  DECL_SIZE_UNIT (decl) = fn;   // Constraining function declaration
  DECL_SIZE (decl) = args;      // Extra template arguments.
  return decl;
}

/* Create a constraint expression for the given DECL that 
   evaluates the requirements specified by CONSTR, a TYPE_DECL 
   that contains all the information necessary to build the 
   requirements (see finish_concept_name for the layout of 
   that TYPE_DECL).

   Note that the constraints are neither reduced nor decomposed. 
   That is done only after the requires clause has been parsed 
   (or not). */
tree
finish_shorthand_constraint (tree decl, tree constr)
{
  // No requirements means no constraints.
  if (!constr)
    return NULL_TREE;

  tree proto = DECL_INITIAL (constr); // The prototype declaration
  tree con = DECL_SIZE_UNIT (constr); // The concept declaration
  tree args = DECL_SIZE (constr);     // Extra template arguments

  // If the parameter declaration is variadic, but the concept is not
  // then we need to apply the concept to every element in the pack.
  bool is_proto_pack = template_parameter_pack_p (proto);
  bool is_decl_pack = template_parameter_pack_p (decl);
  bool apply_to_all_p = is_decl_pack && !is_proto_pack;

  // Get the argument and overload used for the requirement. Adjust
  // if we're going to expand later.
  tree arg = template_parm_to_arg (build_tree_list (NULL_TREE, decl));
  if (apply_to_all_p)
    arg = PACK_EXPANSION_PATTERN (TREE_VEC_ELT (ARGUMENT_PACK_ARGS (arg), 0));

  // Build the concept check. If it the constraint needs to be applied
  // to all elements of the parameter pack, then make the constraint
  // an expansion.
  tree check;
  if (TREE_CODE (con) == VAR_DECL)
    {
      check = build_concept_check (DECL_TI_TEMPLATE (con), arg, args);
    }
  else
    {
      tree ovl = build_overload (DECL_TI_TEMPLATE (con), NULL_TREE);
      check = build_concept_check (ovl, arg, args);
    }
  if (apply_to_all_p)
    {
      check = make_pack_expansion (check);

      // Set the type to indicate that this expansion will get special
      // treatment during instantiation.
      //
      // TODO: Maybe this should be a different kind of node... one that
      // has all the same properties as a pack expansion, but has a definite
      // expansion when instantiated as part of an expression.
      //
      // As of now, this is a hack.
      TREE_TYPE (check) = boolean_type_node;
    }

  return make_predicate_constraint (check);
}

/* Returns a conjunction of shorthand requirements for the template
   parameter list PARMS. Note that the requirements are stored in
   the TYPE of each tree node. */
tree
get_shorthand_constraints (tree parms)
{
  tree result = NULL_TREE;
  parms = INNERMOST_TEMPLATE_PARMS (parms);
  for (int i = 0; i < TREE_VEC_LENGTH (parms); ++i)
    {
      tree parm = TREE_VEC_ELT (parms, i);
      tree constr = TEMPLATE_PARM_CONSTRAINTS (parm);
      result = conjoin_constraints (result, constr);
    }
  return result;
}

// Returns and chains a new parameter for PARAMETER_LIST which will conform
// to the prototype given by SRC_PARM.  The new parameter will have its
// identifier and location set according to IDENT and PARM_LOC respectively.
static tree
process_introduction_parm (tree parameter_list, tree src_parm)
{
  // If we have a pack, we should have a single pack argument which is the
  // placeholder we want to look at.
  bool is_parameter_pack = ARGUMENT_PACK_P (src_parm);
  if (is_parameter_pack)
    src_parm = TREE_VEC_ELT (ARGUMENT_PACK_ARGS (src_parm), 0);

  // At this point we should have a INTRODUCED_PARM_DECL, but we want to grab
  // the associated decl from it.  Also grab the stored identifier and location
  // that should be chained to it in a PARM_DECL.
  gcc_assert (TREE_CODE (src_parm) == INTRODUCED_PARM_DECL);

  tree ident = DECL_NAME (src_parm);
  location_t parm_loc = DECL_SOURCE_LOCATION (src_parm);

  // If we expect a pack and the deduced template is not a pack, or if the
  // template is using a pack and we didn't declare a pack, throw an error.
  if (is_parameter_pack != INTRODUCED_PACK_P (src_parm))
    {
      error_at (parm_loc, "cannot match pack for introduced parameter");
      tree err_parm = build_tree_list (error_mark_node, error_mark_node);
      return chainon (parameter_list, err_parm);
    }

  src_parm = TREE_TYPE (src_parm);

  tree parm;
  bool is_non_type;
  if (TREE_CODE (src_parm) == TYPE_DECL)
    {
      is_non_type = false;
      parm = finish_template_type_parm (class_type_node, ident);
    }
  else if (TREE_CODE (src_parm) == TEMPLATE_DECL)
    {
      is_non_type = false;
      current_template_parms = DECL_TEMPLATE_PARMS (src_parm);
      parm = finish_template_template_parm (class_type_node, ident);
    }
  else
    {
      is_non_type = true;

      // Since we don't have a declarator, so we can copy the source
      // parameter and change the name and eventually the location.
      parm = copy_decl (src_parm);
      DECL_NAME (parm) = ident;
    }

  // Wrap in a TREE_LIST for process_template_parm.  Introductions do not
  // retain the defaults from the source template.
  parm = build_tree_list (NULL_TREE, parm);

  return process_template_parm (parameter_list, parm_loc, parm,
                                is_non_type, is_parameter_pack);
}

/* Associates a constraint check to the current template based 
   on the introduction parameters.  INTRO_LIST should be a TREE_VEC 
   of INTRODUCED_PARM_DECLs containing a chained PARM_DECL which 
   contains the identifier as well as the source location.  
   TMPL_DECL is the decl for the concept being used.  If we take 
   some concept, C, this will form a check in the form of 
   C<INTRO_LIST> filling in any extra arguments needed by the
   defaults deduced.

   Returns NULL_TREE if no concept could be matched and 
   error_mark_node if an error occurred when matching.
*/
tree
finish_template_introduction (tree tmpl_decl, tree intro_list)
{
  /* Deduce the concept check.  */
  tree expr = build_concept_check (tmpl_decl, NULL_TREE, intro_list);
  if (expr == error_mark_node)
    return NULL_TREE;

  tree parms = deduce_concept_introduction (expr);
  if (!parms)
    return NULL_TREE;

  /* Build template parameter scope for introduction.  */
  tree parm_list = NULL_TREE;
  begin_template_parm_list ();
  int nargs = MIN (TREE_VEC_LENGTH (parms), TREE_VEC_LENGTH (intro_list));
  for (int n = 0; n < nargs; ++n)
    parm_list = process_introduction_parm (parm_list, TREE_VEC_ELT (parms, n));
  parm_list = end_template_parm_list (parm_list);
  for (int i = 0; i < TREE_VEC_LENGTH (parm_list); ++i)
    if (TREE_VALUE (TREE_VEC_ELT (parm_list, i)) == error_mark_node)
      {
        end_template_decl ();
        return error_mark_node;
      }

  /* Build a concept check for our constraint.  */
  tree check_args = make_tree_vec (TREE_VEC_LENGTH (parms));
  int n = 0;
  for (; n < TREE_VEC_LENGTH (parm_list); ++n)
    {
      tree parm = TREE_VEC_ELT (parm_list, n);
      TREE_VEC_ELT (check_args, n) = template_parm_to_arg (parm);
    }

  /* If the template expects more parameters we should be able 
     to use the defaults from our deduced concept.  */
  for (; n < TREE_VEC_LENGTH (parms); ++n)
    TREE_VEC_ELT (check_args, n) = TREE_VEC_ELT (parms, n);

  /* Associate the constraint. */
  tree check = build_concept_check (tmpl_decl, NULL_TREE, check_args);
  tree constr = make_predicate_constraint (check);
  TEMPLATE_PARMS_CONSTRAINTS (current_template_parms) = constr;

  return parm_list;
}

/*---------------------------------------------------------------------------
                        Constraint substitution
---------------------------------------------------------------------------*/

tree tsubst_constraint (tree, tree, tsubst_flags_t, tree);

/* The following functions implement substitution rules for constraints. 
   Substitution without checking constraints happens only in the 
   instantiation of class templates. For example:

      template<C1 T> struct S {
        void f(T) requires C2<T>;
        void g(T) requires T::value;
      };

      S<int> s; // error instantiating S<int>::g(T)
   
   When we instantiate S, we substitute into its member declarations,
   including their constraints. However, those constraints are not
   checked. Substituting int into C2<T> yields C2<int>, and substituting
   into T::value yields a substitution failure, making the program
   ill-formed. 

   Note that we only ever substitute into the associated constraints
   of a declaration. That is, substitute is defined only for predicate 
   constraints and conjunctions. */

/* Substitute into the predicate constraints. Returns error_mark_node 
   if the substitution into the expression fails. */
tree
tsubst_predicate_constraint (tree t, tree args, 
                             tsubst_flags_t complain, tree in_decl)
{
  tree expr = PRED_CONSTR_EXPR (t);
  ++processing_template_decl;
  tree result = tsubst_expr (expr, args, complain, in_decl, false);
  --processing_template_decl;
  return build_nt (PRED_CONSTR, result);
}

/* Substitute into the conjunction of constraints. Returns 
   error_mark_node if substitution into either operand fails. */
tree
tsubst_conjunction (tree t, tree args, 
                    tsubst_flags_t complain, tree in_decl)
{
  tree t0 = TREE_OPERAND (t, 0);
  tree r0 = tsubst_constraint (t0, args, complain, in_decl);
  tree t1 = TREE_OPERAND (t, 1);
  tree r1 = tsubst_constraint (t1, args, complain, in_decl);
  return build_nt (CONJ_CONSTR, r0, r1);
}

/* Substitute ARGS into the constraint T. */
tree
tsubst_constraint (tree t, tree args, tsubst_flags_t complain, tree in_decl)
{
  if (TREE_CODE (t) == CONJ_CONSTR)
    return tsubst_conjunction (t, args, complain, in_decl);
  else if (TREE_CODE (t) == PRED_CONSTR)
    return tsubst_predicate_constraint (t, args, complain, in_decl);
  else
    gcc_unreachable ();
  return error_mark_node;
}

namespace {

/* A subroutine of tsubst_constraint_variables. In an unevaluated 
   context, the substitution of PARM_DECLs are not properly chained 
   during substitution. Do that here. */
tree
fixup_constraint_vars (tree parms)
{
  if (!parms)
    return parms;

  tree p = TREE_CHAIN (parms);
  tree q = parms;
  while (p && TREE_VALUE (p) != void_type_node)
    {
      DECL_CHAIN (TREE_VALUE (q)) = TREE_VALUE (p);
      q = p;
      p = TREE_CHAIN (p);
    }
  return parms;
}

/* A subroutine of tsubst_constraint_variables. Register local 
   specializations for each of parameter in PARMS and its 
   corresponding substituted constraint variable in VARS. 
   Returns VARS. */
tree
declare_constraint_vars (tree parms, tree vars)
{
  tree s = TREE_VALUE (vars);
  for (tree p = parms; p && !VOID_TYPE_P (TREE_VALUE (p)); p = TREE_CHAIN (p))
    {
      tree t = TREE_VALUE (p);
      if (DECL_PACK_P (t))
        {
          tree pack = extract_fnparm_pack (t, &s);
          register_local_specialization (pack, t);
        }
      else
        {
          register_local_specialization (s, t);
          s = TREE_CHAIN (s);
        }
    }
  return vars;
}

/* A subroutine of tsubst_parameterized_constraint. Substitute ARGS 
   into the parameter list T, producing a sequence of constraint 
   variables, declared in the current scope. 

   Note that the caller must establish a local specialization stack
   prior to calling this function since this substitution will 
   declare the substituted parameters. */
tree
tsubst_constraint_variables (tree t, tree args,
                             tsubst_flags_t complain, tree in_decl)
{
  tree vars = tsubst (t, args, complain, in_decl);
  if (vars == error_mark_node)
    return error_mark_node;
  return declare_constraint_vars (t, fixup_constraint_vars (vars));
}

/* Substitute ARGS into the simple requirement T. Note that
   substitution may result in an ill-formed expression without
   causing the program to be ill-formed. In such cases, the
   requirement wraps an error_mark_node. */
inline tree
tsubst_simple_requirement (tree t, tree args, 
                           tsubst_flags_t complain, tree in_decl)
{
  tree expr = tsubst_expr (TREE_OPERAND (t, 0), args, complain, in_decl, false);
  return finish_simple_requirement (expr);
}

/* Substitute ARGS into the type requirement T. Note that
   substitution may result in an ill-formed type without
   causing the program to be ill-formed. In such cases, the
   requirement wraps an error_mark_node. */
inline tree
tsubst_type_requirement (tree t, tree args, 
                         tsubst_flags_t complain, tree in_decl)
{
  tree type = tsubst (TREE_OPERAND (t, 0), args, complain, in_decl);
  return finish_type_requirement (type);
}

/* Substitute args into the compound requirement T. If substituting
   into either the expression or the type fails, the corresponding
   operands in the resulting node will be error_mark_node. This
   preserves a requirement for the purpose of partial ordering, but
   it will never be satisfied. */
tree
tsubst_compound_requirement (tree t, tree args,
                             tsubst_flags_t complain, tree in_decl)
{
  tree expr = tsubst_expr (TREE_OPERAND (t, 0), args, complain, in_decl, false);
  tree type = tsubst (TREE_OPERAND (t, 1), args, complain, in_decl);
  bool noexcept_p = COMPOUND_REQ_NOEXCEPT_P (t);
  return finish_compound_requirement (expr, type, noexcept_p);
}

/* Substitute ARGS into the nested requirement T. */
tree
tsubst_nested_requirement (tree t, tree args, 
                           tsubst_flags_t complain, tree in_decl)
{
  tree expr = tsubst_expr (TREE_OPERAND (t, 0), args, complain, in_decl, false);
  return finish_nested_requirement (expr);
}

inline tree
tsubst_requirement (tree t, tree args, tsubst_flags_t complain, tree in_decl)
{
  switch (TREE_CODE (t))
    {
    case SIMPLE_REQ:
      return tsubst_simple_requirement (t, args, complain, in_decl);
    case TYPE_REQ:
      return tsubst_type_requirement (t, args, complain, in_decl);
    case COMPOUND_REQ:
      return tsubst_compound_requirement (t, args, complain, in_decl);
    case NESTED_REQ:
      return tsubst_nested_requirement (t, args, complain, in_decl);
    default:
      gcc_unreachable ();
    }
  return error_mark_node;
}

/* Substitute ARGS into the list of requirements T. Note that
   substitution failures here result in ill-formed programs. */
tree
tsubst_requirement_body (tree t, tree args, 
                         tsubst_flags_t complain, tree in_decl)
{
  tree r = NULL_TREE;
  while (t)
    {
      tree e = tsubst_requirement (TREE_VALUE (t), args, complain, in_decl);
      if (e == error_mark_node)
        return error_mark_node;
      r = tree_cons (NULL_TREE, e, r);
      t = TREE_CHAIN (t);
    }
  return r;
}

} /* namespace */

/* Substitute ARGS into the requires expression T. Note that this
   results in the re-declaration of local parameters when
   substituting through the parameter list. If either substitution
   fails, the program is ill-formed. */
tree
tsubst_requires_expr (tree t, tree args, 
                      tsubst_flags_t complain, tree in_decl)
{
  local_specialization_stack stack;

  tree parms = TREE_OPERAND (t, 0);
  if (parms)
    {
      parms = tsubst_constraint_variables (parms, args, complain, in_decl);
      if (parms == error_mark_node)
        return error_mark_node;
    }
  
  tree reqs = TREE_OPERAND (t, 1);
  reqs = tsubst_requirement_body (reqs, args, complain, in_decl);
  if (reqs == error_mark_node)
    return error_mark_node;

  return finish_requires_expr (parms, reqs);
}

/* Substitute ARGS into the constraint information CI, producing a new 
   constraint record. */
tree
tsubst_constraint_info (tree t, tree args, 
                        tsubst_flags_t complain, tree in_decl)
{
  if (!t || t == error_mark_node || !check_constraint_info (t))
    return NULL_TREE;

  tree tmpl_constr = NULL_TREE;
  if (tree r = CI_TEMPLATE_REQS (t))
    tmpl_constr = tsubst_constraint (r, args, complain, in_decl);

  tree decl_constr = NULL_TREE;
  if (tree r = CI_DECLARATOR_REQS (t))
    decl_constr = tsubst_constraint (r, args, complain, in_decl);

  return build_constraints (tmpl_constr, decl_constr);
}


/*---------------------------------------------------------------------------
                        Constraint satisfaction 
---------------------------------------------------------------------------*/

/* The following functions determine if a constraint, when
   substituting template arguments, is satisfied. For convenience,
   satisfaction reduces a constraint to either true or false (and
   nothing else). */

namespace {

tree check_constraint (tree, tree, tsubst_flags_t, tree);

/* Check the pack expansion by first transforming it into a
   conjunction of constraints. */
tree
check_pack_expansion (tree t, tree args,
                      tsubst_flags_t complain, tree in_decl)
{
  /* Check that somebody isn't arbitrarily expanding packs
     as part of a predicate. Note that packs are normally
     untyped, however, we use the type field as a hack to
     indicate folded boolean expressions generated from a
     shorthand constraint.  This check should disappear with
     fold expressions.  */
  if (!same_type_p (TREE_TYPE (t), boolean_type_node)) 
    {
      error ("invalid pack expansion in constraint %qE", t);
      return boolean_false_node;
    }

  /* Get the vector of expanded arguments. */
  tree exprs = tsubst_pack_expansion (t, args, complain, in_decl);
  if (exprs == error_mark_node)
    return boolean_false_node;

  /* Build a conjunction of constraints from the resulting
     expansions and then check that. */
  tree result = NULL_TREE;
  for (int i = 0; i < TREE_VEC_LENGTH (exprs); ++i)
    {
      tree expr = TREE_VEC_ELT (exprs, i);
      tree constr = transform_expression (expr);
      result = conjoin_constraints (result, constr);
    }
  return check_constraint (result, args, complain, in_decl);
}

/* A predicate constraint is satisfied if its expression evaluates
   to true. If substitution into that node fails, the constraint
   is not satisfied ([temp.constr.pred]).

   Note that a predicate constraint is a constraint expression
   of type bool. If neither of those are true, the program is
   ill-formed; they are not SFINAE'able errors. */
tree
check_predicate_constraint (tree t, tree args, 
                            tsubst_flags_t complain, tree in_decl)
{
  tree original = TREE_OPERAND (t, 0);

  /* Pack expansions are not transformed during normalization,
     which means we might have requires-expressions.

     FIXME: We should never have a naked pack expansion in a
     predicate constraint. When the fold-expression branch is
     integrated, this same logical will apply to that fold. */
  if (TREE_CODE (original) == EXPR_PACK_EXPANSION)
    return check_pack_expansion (original, args, complain, in_decl);

  tree expr = tsubst_expr (original, args, complain, in_decl, false);
  if (expr == error_mark_node)
    return boolean_false_node;

  tree result = fold_non_dependent_expr (expr);
  if (result == error_mark_node)
    return boolean_false_node;

  /* A predicate constraint shall have type bool. In some
     cases, substitution gives us const-qualified bool, which
     is also acceptable.  */
  tree type = cv_unqualified (TREE_TYPE (result));
  if (!same_type_p (type, boolean_type_node))
    {
      error_at (EXPR_LOC_OR_LOC (t, input_location),
                "constraint %qE does not have type %qT", 
                result, boolean_type_node);
      return boolean_false_node;
    }

  return cxx_constant_value (result);
}

/* Check an expression constraint. The constraint is satisfied if
   substitution succeeds ([temp.constr.expr]). 

   Note that the expression is unevaluated. */
tree
check_expression_constraint (tree t, tree args, 
                             tsubst_flags_t complain, tree in_decl)
{
  cp_unevaluated guard;
  tree expr = EXPR_CONSTR_EXPR (t);
  tree check = tsubst_expr (expr, args, complain, in_decl, false);
  if (check == error_mark_node)
    return boolean_false_node;
  return boolean_true_node;
}

/* Check a type constraint. The constraint is satisfied if
   substitution succeeds. */
inline tree
check_type_constraint (tree t, tree args, 
                       tsubst_flags_t complain, tree in_decl)
{
  tree type = TYPE_CONSTR_TYPE (t);
  tree check = tsubst (type, args, complain, in_decl);
  if (check == error_mark_node)
    return boolean_false_node;
  return boolean_true_node;
}

/* Check an implicit conversion constraint. */
tree
check_implicit_conversion_constraint (tree t, tree args, 
                                      tsubst_flags_t complain, tree in_decl)
{
  tree expr = ICONV_CONSTR_EXPR (t);

  /* Don't tsubst as if we're processing a template. If we try 
     to we can end up generating template-like expressions
     (e.g., modop-exprs) that aren't properly typed. */
  int saved_template_decl = processing_template_decl;
  processing_template_decl = 0;
  tree arg = tsubst_expr (expr, args, complain, in_decl, false);
  processing_template_decl = saved_template_decl;

  if (arg == error_mark_node)
    return boolean_false_node;
  tree from = TREE_TYPE (arg);

  tree type = ICONV_CONSTR_TYPE (t);
  tree to = tsubst (type, args, complain, in_decl);
  if (to == error_mark_node)
    return boolean_false_node;

  if (can_convert_arg (to, from, arg, LOOKUP_IMPLICIT, complain))
    return boolean_true_node;
  else
    return boolean_false_node;
}

/* Check an argument deduction constraint.

   TODO: Implement me. We need generalized auto for this to work. */
tree
check_argument_deduction_constraint (tree /*t*/, tree /*args*/, 
                                     tsubst_flags_t /*complain*/, 
                                     tree /*in_decl*/)
{
  gcc_unreachable ();
  return boolean_false_node;
}

/* Check an exception constraint. An exception constraint for an
   expression e is satisfied when noexcept(e) is true. */
tree
check_exception_constraint (tree t, tree args, 
                             tsubst_flags_t complain, tree in_decl)
{
  tree expr = EXCEPT_CONSTR_EXPR (t);
  tree check = tsubst_expr (expr, args, complain, in_decl, false);
  if (check == error_mark_node)
    return boolean_false_node;

  if (expr_noexcept_p (check, complain))
    return boolean_true_node;
  else
    return boolean_false_node;
}

/* Check a parameterized constraint. */
tree
check_parameterized_constraint (tree t, tree args, 
                                tsubst_flags_t complain, tree in_decl)
{
  local_specialization_stack stack;
  tree parms = PARM_CONSTR_PARMS (t);
  tree vars = tsubst_constraint_variables (parms, args, complain, in_decl);
  if (vars == error_mark_node)
    return boolean_false_node;
  tree constr = PARM_CONSTR_OPERAND (t);
  return check_constraint (constr, args, complain, in_decl);
}

/* Check that the conjunction of constraints is satisfied. Note
   that if left operand is not satisfied, the right operand
   is not checked. 

   FIXME: Check that this wouldn't result in a user-defined
   operator. Note that this error is partially diagnosed in
   check_predicate_constriant. It would be nice to diagnose
   the overload, but I don't think it's strictly necessary.  */
tree
check_conjunction (tree t, tree args, tsubst_flags_t complain, tree in_decl)
{
  tree t0 = check_constraint (TREE_OPERAND (t, 0), args, complain, in_decl);
  if (t0 == boolean_false_node)
    return t0;
  tree t1 = check_constraint (TREE_OPERAND (t, 1), args, complain, in_decl);
  if (t1 == boolean_false_node)
    return t1;
  return boolean_true_node;
}

/* Check that the disjunction of constraints is satisfied. Note
   that if the left operand is satisfied, the right operand is not
   checked.  */
tree
check_disjunction (tree t, tree args, tsubst_flags_t complain, tree in_decl)
{
  tree t0 = check_constraint (TREE_OPERAND (t, 0), args, complain, in_decl);
  if (t0 == boolean_true_node)
    return t0;
  tree t1 = check_constraint (TREE_OPERAND (t, 1), args, complain, in_decl);
  if (t1 == boolean_true_node)
    return t0;
  return boolean_false_node;
}

/* Check that the constraint is satisfied, according to the rules 
   for that constraint. Note that each check_* function returns
   true or false, depending on whether it is satisfied or not.  */
tree 
check_constraint (tree t, tree args, tsubst_flags_t complain, tree in_decl)
{
  if (!t)
    return boolean_false_node;

  if (t == error_mark_node)
    return boolean_false_node;

  switch (TREE_CODE (t))
  {
  case PRED_CONSTR:
    return check_predicate_constraint (t, args, complain, in_decl);
  
  case EXPR_CONSTR:
    return check_expression_constraint (t, args, complain, in_decl);
  
  case TYPE_CONSTR:
    return check_type_constraint (t, args, complain, in_decl);
  
  case ICONV_CONSTR:
    return check_implicit_conversion_constraint (t, args, complain, in_decl);
  
  case DEDUCT_CONSTR:
    return check_argument_deduction_constraint (t, args, complain, in_decl);
  
  case EXCEPT_CONSTR:
    return check_exception_constraint (t, args, complain, in_decl);
  
  case PARM_CONSTR:
    return check_parameterized_constraint (t, args, complain, in_decl);
  
  case CONJ_CONSTR:
    return check_conjunction (t, args, complain, in_decl);
  
  case DISJ_CONSTR:
    return check_disjunction (t, args, complain, in_decl);
  
  default:
    gcc_unreachable ();
  }
  return boolean_false_node;
}

} /* namespace */

/* Check the constraints in CI against the given ARGS, returning
   true when the constraints are satisfied and false otherwise. 

   Note that this is the only place that we instantiate the
   constraints. */
bool
check_constraints (tree ci, tree args)
{
  /* If there are no constraints then this is trivially satisfied. */
  if (!ci)
    return true;

  /* If any arguments depend on template parameters, we can't
     check constraints. */
  if (args && uses_template_parms (args))
    return true;
  
  /* Invalid requirements cannot be satisfied. */
  if (!valid_constraints_p (ci))
    return false;

  tree constr = CI_NORMALIZED_CONSTRAINTS (ci);
  tree result = check_constraint (constr, args, tf_none, NULL_TREE);
  return result == boolean_true_node;
}

/* Returns true if the declaration's constraints are satisfied. 
   This is used in cases where a declaration is formed but
   before it is used (e.g., overload resolution). */
bool
constraints_satisfied_p (tree decl)
{
  /* Get the constraints to check for satisfaction. This depends
     on whether we're looking at a template specialization or not. */
  tree ci = NULL_TREE;
  tree args = NULL_TREE;
  if (tree ti = DECL_TEMPLATE_INFO (decl))
    {
      ci = get_constraints (TI_TEMPLATE (ti));
      args = INNERMOST_TEMPLATE_ARGS (TI_ARGS (ti));
    }
  else
    {
      ci = get_constraints (decl);
    }

  return check_constraints (ci, args);
}

/* Returns true if the template's constrains are satisfied
   by the given arguments. This is used in cases where a
   declaration cannot be formed unless the constraints are
   checked (e.g., the use of a template-id that names a
   class). */
bool
constraints_satisfied_p (tree tmpl, tree args)
{
  return check_constraints (get_constraints (tmpl), args);
}

/* Evaluate the function concept FN by substituting ARGS into its
   definition and evaluating that as the result. Returns
   boolean_true_node if the constraints are satisfied and
   boolean_false_node otherwise.  */
tree
evaluate_function_concept (tree fn, tree args)
{
  ++processing_template_decl;
  tree constr = transform_expression (lift_function_definition (fn, args));
  --processing_template_decl;
  return check_constraint (constr, args, tf_none, NULL_TREE);
}

/* Evaluate the variable concept VAR by substituting ARGS into
   its initializer and checking the resulting constraint. Returns
   boolean_true_node if the constraints are satisfied and
   boolean_false_node otherwise.  */
tree
evaluate_variable_concept (tree decl, tree args)
{
  ++processing_template_decl;
  tree constr = transform_expression (lift_variable_initializer (decl, args));
  --processing_template_decl;
  return check_constraint (constr, args, tf_none, NULL_TREE);
}

/* Evaluate the given expression as if it were a predicate
   constraint. Returns boolean_true_node if the constraint
   is satisfied and boolean_false_node otherwise. */
tree
evaluate_constraint_expression (tree expr, tree args)
{
  ++processing_template_decl;
  tree constr = transform_expression (lift_expression (expr));
  --processing_template_decl;
  return check_constraint (constr, args, tf_none, NULL_TREE);
}

/* Normalize EXPR and determine if the resulting constraint is
   satisfied by ARGS. Returns true if and only if the constraint
   is satisfied. */
bool
check_constraint_expression (tree expr, tree args)
{
  return evaluate_constraint_expression (expr, args) == boolean_true_node;
}

/*---------------------------------------------------------------------------
                Semantic analysis of requires-expressions
---------------------------------------------------------------------------*/

/* Finish a requires expression for the given PARMS (possibly
   null) and the non-empty sequence of requirements. */
tree
finish_requires_expr (tree parms, tree reqs)
{
  /* Modify the declared parameters by removing their context 
     so they don't refer to the enclosing scope. */
  for (tree p = parms; p && !VOID_TYPE_P (TREE_VALUE (p)); p = TREE_CHAIN (p))
    DECL_CONTEXT (TREE_VALUE (p)) = NULL_TREE;

  /* Build the node. */
  tree r = build_min (REQUIRES_EXPR, boolean_type_node, parms, reqs);
  TREE_SIDE_EFFECTS (r) = false;
  TREE_CONSTANT (r) = true;
  return r;
}

/* Construct a requirement for the validity of EXPR. */
tree
finish_simple_requirement (tree expr)
{
  return build_nt (SIMPLE_REQ, expr);
}

/* Construct a requirement for the validity of TYPE. */
tree
finish_type_requirement (tree type)
{
  return build_nt (TYPE_REQ, type);
}

/* Construct a requirement for the validity of EXPR, along with
   its properties. if TYPE is non-null, then it specifies either 
   an implicit conversion or argument deduction constraint, 
   depending on whether any placeholders occur in the type name. 
   NOEXCEPT_P is true iff the noexcept keyword was specified. */
tree
finish_compound_requirement (tree expr, tree type, bool noexcept_p)
{
  tree req = build_nt (COMPOUND_REQ, expr, type);
  COMPOUND_REQ_NOEXCEPT_P (req) = noexcept_p;
  return req;
}

/* Finish a nested requirement. */
tree
finish_nested_requirement (tree expr)
{
  return build_nt (NESTED_REQ, expr);
}

// Check that FN satisfies the structural requirements of a
// function concept definition.
tree
check_function_concept (tree fn)
{
  location_t loc = DECL_SOURCE_LOCATION (fn);

  // Check that the function is comprised of only a single
  // return statement.
  tree body = DECL_SAVED_TREE (fn);
  if (TREE_CODE (body) == BIND_EXPR)
    body = BIND_EXPR_BODY (body);

  // Sometimes a function call results in the creation of clean up
  // points. Allow these to be preserved in the body of the
  // constraint, as we might actually need them for some constexpr
  // evaluations.
  if (TREE_CODE (body) == CLEANUP_POINT_EXPR)
    body = TREE_OPERAND (body, 0);

  if (TREE_CODE (body) != RETURN_EXPR)
    error_at (loc, "function concept definition %qD has multiple statements",
              fn);

  return NULL_TREE;
}


// Check that a constrained friend declaration function declaration,
// FN, is admissible. This is the case only when the declaration depends
// on template parameters and does not declare a specialization.
void
check_constrained_friend (tree fn, tree reqs)
{
  if (fn == error_mark_node)
    return;
  gcc_assert (TREE_CODE (fn) == FUNCTION_DECL);

  // If there are not constraints, this cannot be an error.
  if (!reqs)
    return;

  // Constrained friend functions that don't depend on template
  // arguments are effectively meaningless.
  tree parms = DECL_ARGUMENTS (fn);
  tree result = TREE_TYPE (TREE_TYPE (fn));
  if (!(parms && uses_template_parms (parms)) && !uses_template_parms (result))
    {
      error ("constrained friend does not depend on template parameters");
      return;
    }
}

/*---------------------------------------------------------------------------
                        Equivalence of constraints
---------------------------------------------------------------------------*/

/* Returns true when A and B are equivalent constraints.  */
bool
equivalent_constraints (tree a, tree b)
{
  gcc_assert (!a || TREE_CODE (a) == CONSTRAINT_INFO);
  gcc_assert (!b || TREE_CODE (b) == CONSTRAINT_INFO);
  return cp_tree_equal (a, b);
}

/* Returns true if the template declarations A and B have equivalent
   constraints. This is the case when A's constraints subsume B's and
   when B's also constrain A's.  */
bool
equivalently_constrained (tree d1, tree d2)
{
  gcc_assert (TREE_CODE (d1) == TREE_CODE (d2));
  return equivalent_constraints (get_constraints (d1), get_constraints (d2));
}

/*---------------------------------------------------------------------------
                     Partial ordering of constraints
---------------------------------------------------------------------------*/

/* Returns true when the the constraints in A subsume those in B.  */
bool
subsumes_constraints (tree a, tree b)
{
  gcc_assert (!a || TREE_CODE (a) == CONSTRAINT_INFO);
  gcc_assert (!b || TREE_CODE (b) == CONSTRAINT_INFO);
  return subsumes (a, b);
}

/* Determines which of the declarations, A or B, is more constrained.
   That is, which declaration's constraints subsume but are not subsumed
   by the other's?

   Returns 1 if A is more constrained than B, -1 if B is more constrained
   than A, and 0 otherwise. */
int
more_constrained (tree d1, tree d2)
{
  tree c1 = get_constraints (d1);
  tree c2 = get_constraints (d2);
  int winner = 0;
  if (subsumes_constraints (c1, c2))
    ++winner;
  if (subsumes_constraints (c2, c1))
    --winner;
  return winner;
}

/* Returns true if D1 is at least as constrained as D2. That is, the
   associated constraints of D1 subsume those of D2, or both declarations
   are unconstrained. */
bool
at_least_as_constrained (tree d1, tree d2)
{
  tree c1 = get_constraints (d1);
  tree c2 = get_constraints (d2);
  return subsumes_constraints (c1, c2);
}


/*---------------------------------------------------------------------------
                        Constraint diagnostics
---------------------------------------------------------------------------*/

/* The diagnosis of constraints performs a combination of
   normalization and satisfaction testing. We recursively
   walk through the conjunction (or disjunctions) of associated 
   constraints, testing each sub-expression in turn.

   We currently restrict diagnostics to just the top-level
   conjunctions within the associated constraints. A fully
   recursive walk is possible, but it can generate a lot
   of errors. */


namespace {

void diagnose_expression (location_t, tree, tree);
void diagnose_constraint (location_t, tree, tree);

/* Diagnose a conjunction of constraints. */
void
diagnose_logical_operation (location_t loc, tree t, tree args)
{
  diagnose_expression (loc, TREE_OPERAND (t, 0), args);
  diagnose_expression (loc, TREE_OPERAND (t, 0), args);
}

/* Determine if the trait expression T is satisfied by ARGS.
   Emit a precise diagnostic if it is not. */
void
diagnose_trait_expression (location_t loc, tree t, tree args)
{
  if (check_constraint_expression (t, args))
    return;

  /* Rebuild the trait expression so we can diagnose the
     specific failure. */
  ++processing_template_decl;
  tree expr = tsubst_expr (t, args, tf_none, NULL_TREE, false);
  --processing_template_decl;

  tree t1 = TRAIT_EXPR_TYPE1 (expr);
  tree t2 = TRAIT_EXPR_TYPE2 (expr);
  switch (TRAIT_EXPR_KIND (t))
    {
    case CPTK_HAS_NOTHROW_ASSIGN:
      inform (loc, "  %qT is not nothrow copy assignable", t1);
      break;
    case CPTK_HAS_NOTHROW_CONSTRUCTOR:
      inform (loc, "  %qT is not nothrow default constructible", t1);
      break;
    case CPTK_HAS_NOTHROW_COPY:
      inform (loc, "  %qT is not nothrow copy constructible", t1);
      break;
    case CPTK_HAS_TRIVIAL_ASSIGN:
      inform (loc, "  %qT is not trivially copy assignable", t1);
      break;
    case CPTK_HAS_TRIVIAL_CONSTRUCTOR:
      inform (loc, "  %qT is not trivially default constructible", t1);
      break;
    case CPTK_HAS_TRIVIAL_COPY:
      inform (loc, "  %qT is not trivially copy constructible", t1);
      break;
    case CPTK_HAS_TRIVIAL_DESTRUCTOR:
      inform (loc, "  %qT is not trivially destructible", t1);
      break;
    case CPTK_HAS_VIRTUAL_DESTRUCTOR:
      inform (loc, "  %qT does not have a virtual destructor", t1);
      break;
    case CPTK_IS_ABSTRACT:
      inform (loc, "  %qT is not an abstract class", t1);
      break;
    case CPTK_IS_BASE_OF:
      inform (loc, "  %qT is not a base of %qT", t1, t2);
      break;
    case CPTK_IS_CLASS:
      inform (loc, "  %qT is not a class", t1);
      break;
    case CPTK_IS_CONVERTIBLE_TO:
      inform (loc, "  %qT is not convertible to %qT", t1, t2);
      break;
    case CPTK_IS_EMPTY:
      inform (loc, "  %qT is not an empty class", t1);
      break;
    case CPTK_IS_ENUM:
      inform (loc, "  %qT is not an enum", t1);
      break;
    case CPTK_IS_FINAL:
      inform (loc, "  %qT is not a final class", t1);
      break;
    case CPTK_IS_LITERAL_TYPE:
      inform (loc, "  %qT is not a literal type", t1);
      break;
    case CPTK_IS_POD:
      inform (loc, "  %qT is not a POD type", t1);
      break;
    case CPTK_IS_POLYMORPHIC:
      inform (loc, "  %qT is not a polymorphic type", t1);
      break;
    case CPTK_IS_SAME_AS:
      inform (loc, "  %qT is not the same as %qT", t1, t2);
      break;
    case CPTK_IS_STD_LAYOUT:
      inform (loc, "  %qT is not an standard layout type", t1);
      break;
    case CPTK_IS_TRIVIAL:
      inform (loc, "  %qT is not a trivial type", t1);
      break;
    case CPTK_IS_UNION:
      inform (loc, "  %qT is not a union", t1);
      break;
    default:
      gcc_unreachable ();
    }
}

/* Determine if the call expression T, when normalized as a constraint,
   is satisfied by ARGS. 

   TODO: If T is refers to a concept, We could recursively analyze 
   its definition to identify the exact failure, but that could 
   emit a *lot* of error messages (defeating the purpose of 
   improved diagnostics). Consider adding a flag to control the 
   depth of diagnostics. */
void
diagnose_call_expression (location_t loc, tree t, tree args)
{
  if (check_constraint_expression (t, args))
    return;

  /* Rebuild the expression for the purpose of diagnostics. */
  ++processing_template_decl;
  tree expr = tsubst_expr (t, args, tf_none, NULL_TREE, false);
  --processing_template_decl;

  /* If the function call is known to be a concept check, then
     diagnose it differently (i.e., we may recurse). */
  if (resolve_constraint_check (t))
    inform (loc, "  concept %qE was not satisfied", expr);
  else
    inform (loc, "  %qE evaluated to false", expr);
}

/* Determine if the template-id T, when normalized as a constraint
   is satisfied by ARGS. */
void
diagnose_template_id (location_t loc, tree t, tree args)
{
  /* Check for invalid template-ids. */
  if (!variable_template_p (TREE_OPERAND (t, 0)))
    {
      inform (loc, "  invalid constraint %qE", t);
      return;
    }

  if (check_constraint_expression (t, args))
    return;

  /* Rebuild the expression for the purpose of diagnostics. */
  ++processing_template_decl;
  tree expr = tsubst_expr (t, args, tf_none, NULL_TREE, false);
  --processing_template_decl;

  tree var = DECL_TEMPLATE_RESULT (TREE_OPERAND (t, 0));
  if (DECL_DECLARED_CONCEPT_P (var))
    inform (loc, "  concept %qE was not satisfied", expr);
  else
    inform (loc, "  %qE evaluated to false", expr);
}

/* Determine if the requires-expression, when normalized as a
   constraint is satisfied by ARGS. 

   TODO: Build sets of expressions, types, and constraints
   based on the requirements in T and emit specific diagnostics
   for those. */
void
diagnose_requires_expression (location_t loc, tree t, tree args)
{
  if (check_constraint_expression (t, args))
    return;
  inform (loc, "requirements not satisfied");
}

/* Diagnose an expression that would be characterized as
   a predicate constraint. */
void
diagnose_other_expression (location_t loc, tree t, tree args)
{
  if (check_constraint_expression (t, args))
    return;
  inform (loc, "  %qE evaluated to false", t);
}

void
diagnose_expression (location_t loc, tree t, tree args)
{
  switch (TREE_CODE (t))
    {
    case TRUTH_ANDIF_EXPR:
      diagnose_logical_operation (loc, t, args);
      break;

    case TRUTH_ORIF_EXPR:
      diagnose_logical_operation (loc, t, args);
      break;

    case CALL_EXPR:
      diagnose_call_expression (loc, t, args);
      break;

    case TEMPLATE_ID_EXPR:
      diagnose_template_id (loc, t, args);
      break;

    case REQUIRES_EXPR:
      diagnose_requires_expression (loc, t, args);
      break;

    case TRAIT_EXPR:
      diagnose_trait_expression (loc, t, args);
      break;

    default:
      diagnose_other_expression (loc, t, args);
      break;
    }
}

inline void
diagnose_predicate_constraint (location_t loc, tree t, tree args)
{
  diagnose_expression (loc, PRED_CONSTR_EXPR (t), args);
}

inline void
diagnose_conjunction (location_t loc, tree t, tree args)
{
  diagnose_constraint (loc, TREE_OPERAND (t, 0), args);
  diagnose_constraint (loc, TREE_OPERAND (t, 1), args);
}

/* Diagnose the constraint T for the given ARGS. This is only
   ever invoked on the associated constraints, so we can
   only have conjunctions of predicate constraints. */
void
diagnose_constraint (location_t loc, tree t, tree args)
{
  switch (TREE_CODE (t))
    {
    case CONJ_CONSTR:
      diagnose_conjunction (loc, t, args);
      break;

    case PRED_CONSTR:
      diagnose_predicate_constraint (loc, t, args);
      break;

    default:
      gcc_unreachable ();
      break;
    }
}

} // namespace

/* Emit diagnostics detailing the failure ARGS to satisfy the constraints
   of the template declaration, DECL.  */
void
diagnose_constraints (location_t loc, tree decl, tree args)
{
  inform (loc, "  constraints not satisfied");

  /* Constraints are attached to the template.  */
  if (tree ti = DECL_TEMPLATE_INFO (decl)) {
    decl = TI_TEMPLATE (ti);
    args = TI_ARGS (ti);
  }
  
  /* Check that the constraints are actually valid.  */
  tree ci = get_constraints (decl);
  if (!valid_constraints_p (ci))
    {
      inform (loc, "    invalid constraints");
      return;
    }

  /* Recursively diagnose the associated constraints.  */
  tree assoc = CI_ASSOCIATED_CONSTRAINTS (ci);
  diagnose_constraint (loc, assoc, args);
}
