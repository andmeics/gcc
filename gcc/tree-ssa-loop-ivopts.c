/* Induction variable optimizations.
   Copyright (C) 2003 Free Software Foundation, Inc.
   
This file is part of GCC.
   
GCC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.
   
GCC is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.
   
You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

/* This pass tries to find the optimal set of induction variables for the loop.
   It optimizes just the basic linear induction variables (although adding
   support for other types should not be too hard).  It includes the
   optimizations commonly known as strength reduction, induction variable
   coalescing and induction variable elimination.  It does it in the
   following steps:

   1) The interesting uses of induction variables are found.  This includes

      -- uses of induction variables in non-linear expressions
      -- adresses of arrays
      -- comparisons of induction variables

   2) Candidates for the induction variables are found.  This includes

      -- old induction variables
      -- the variables defined by expressions derived from the "interesting
	 uses" above

   3) The optimal (w.r. to a cost function) set of variables is chosen.  The
      cost function assigns a cost to sets of induction variables and consists
      of three parts:

      -- The use costs.  Each of the interesting uses choses the best induction
	 variable in the set and adds its cost to the sum.  The cost reflects
	 the time spent on modifying the induction variables value to be usable
	 for the given purpose (adding base and offset for arrays, etc.).
      -- The variable costs.  Each of the variables has a cost assigned that
	 reflects the costs assoctiated with incrementing the value of the
	 variable.  The original variables are somewhat preferred.
      -- The set cost.  Depending on the size of the set, extra cost may be
	 added to reflect register pressure.

      All the costs are defined in a machine-specific way, using the target
      hooks and machine descriptions to determine them.

   4) The trees are transformed to use the new variables, the dead code is
      removed.
   
   All of this is done loop by loop.  Doing it globally is theoretically
   possible, it might give a better performance and it might enable us
   to decide costs more precisely, but getting all the interactions right
   would be complicated.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "hard-reg-set.h"
#include "basic-block.h"
#include "output.h"
#include "diagnostic.h"
#include "tree-flow.h"
#include "tree-dump.h"
#include "timevar.h"
#include "cfgloop.h"
#include "varray.h"
#include "expr.h"
#include "tree-pass.h"
#include "ggc.h"

/* The infinite cost.  */
#define INFTY 100000

/* Just to shorten the ugly names.  */
#define EXEC_BINARY nondestructive_fold_binary_to_constant
#define EXEC_UNARY nondestructive_fold_unary_to_constant

/* Representation of the induction variable.  */
struct iv
{
  tree base;		/* Initial value of the iv.  */
  tree step;		/* Step of the iv (constant only).  */
  tree ssa_name;	/* The ssa name with the value.  */
  bool biv_p;		/* Is it a biv?  */
  bool have_use_for;	/* Do we already have a use for it?  */
};

/* The currently optimized loop.  ??? Perhaps it would be better to pass it
   everywhere in argument, so that the functions are easier to generalize
   if needed?  */
static struct loop *current_loop;

/* The highest ssa name before optimizations.  */
static unsigned old_highest_ssa_version;

/* The outermost loop in that the variable is used.  */
static struct loop **outermost_usage;

/* The array of induction variable descriptions, indexed by the ssa name
   version.  */
static struct iv **ivs;

/* Information attached to loop.  */
struct loop_data
{
  unsigned n_exits;	/* Number of exit edges.  */
  edge single_exit;	/* The exit edge in case there is exactly one and
			   its source dominates the loops latch.  */
  tree assumptions;	/* Assumptions for the number of iterations be valid.  */
  tree may_be_zero;	/* Condition under that the loop exits in the first
			   iteration.  */
  tree niter;		/* Number of iterations.  */

  unsigned regs_used;	/* Number of registers used.  */
};

#define LOOP_DATA(LOOP) ((struct loop_data *) (LOOP)->aux)

/* Types of uses.  */
enum use_type
{
  USE_NONLINEAR_EXPR,	/* Use in a nonlinear expression.  */
  USE_ADDRESS,		/* Use in an address.  */
  USE_COMPARE		/* Use is a compare.  */
};

/* The candidate - cost pair.  */
struct cost_pair
{
  struct iv_cand *cand;	/* The candidate.  */
  unsigned cost;	/* The cost.  */
};

/* Use.  */
struct iv_use
{
  unsigned id;		/* The id of the use.  */
  enum use_type type;	/* Type of the use.  */
  struct iv *iv;	/* The induction variable it is based on.  */
  tree stmt;		/* Statement in that it occurs.  */
  tree *op_p;		/* The place where it occurs.  */
  bitmap related_cands;	/* The set of "related" iv candidates.  */

  unsigned best_cost;	/* The best of the candidate costs.  */
  unsigned n_map_members; /* Number of candidates in the cost_map list.  */
  struct cost_pair *cost_map;
			/* The costs wrto the iv candidates.  */
};

/* The uses of induction variables.  */
static varray_type iv_uses;

/* The position where the iv is computed.  */
enum iv_position
{
  IP_START,		/* At the very beginning of the loop body.  */
  IP_NORMAL,		/* At the end, just before the exit condition.  */
  IP_END		/* At the end of the latch block.  */
};

/* The induction variable candidate.  */
struct iv_cand
{
  unsigned id;		/* The number of the candidate.  */
  bool important;	/* Whether this is an "important" candidate, i.e. such
			   that it should be considered by all uses.  */
  enum iv_position pos;	/* Where it is computed.  */
  tree var_before;	/* The variable used for it before incrementation.  */
  tree var_after;	/* The variable used for it after incrementation.  */
  struct iv *iv;	/* The value of the candidate.  */
  unsigned cost;	/* Cost of the candidate.  */
};

/* The candidates.  */
static varray_type iv_candidates;

/* Whether to consider just related and important candidates when replacing an
   use.  */
static bool consider_all_candidates;

/* Bound on number of candidates below that all candidates are considered.  */

#define CONSIDER_ALL_CANDIDATES_BOUND 50

/* The properties of the target.  */

unsigned avail_regs;	/* Number of available registers.  */
unsigned res_regs;	/* Number of reserved registers.  */
unsigned small_cost;	/* The cost for register when there is a free one.  */
unsigned pres_cost;	/* The cost for register when there are not too many
			   free ones.  */
unsigned spill_cost;	/* The cost for register when we need to spill.  */

/* The list of trees for that the decl_rtl field must be reset is stored
   here.  */

static varray_type decl_rtl_to_reset;

#define SWAP(X, Y) do { void *tmp = (X); (X) = (Y); (Y) = tmp; } while (0)

static tree force_gimple_operand (tree, tree *, tree, bool);

/* Dumps information about the induction variable IV to FILE.  */

extern void dump_iv (FILE *, struct iv *);
void
dump_iv (FILE *file, struct iv *iv)
{
  fprintf (file, "ssa name ");
  print_generic_expr (file, iv->ssa_name, TDF_SLIM);
  fprintf (file, "\n");

  if (iv->step)
    {
      fprintf (file, "  base ");
      print_generic_expr (file, iv->base, TDF_SLIM);
      fprintf (file, "\n");

      fprintf (file, "  step ");
      print_generic_expr (file, iv->step, TDF_SLIM);
      fprintf (file, "\n");
    }
  else
    {
      fprintf (file, "  invariant ");
      print_generic_expr (file, iv->base, TDF_SLIM);
      fprintf (file, "\n");
    }

  if (iv->biv_p)
    fprintf (file, "  is a biv\n");
}

/* Dumps information about the USE to FILE.  */

extern void dump_use (FILE *, struct iv_use *);
void
dump_use (FILE *file, struct iv_use *use)
{
  struct iv *iv = use->iv;

  fprintf (file, "use %d\n", use->id);

  switch (use->type)
    {
    case USE_NONLINEAR_EXPR:
      fprintf (file, "  generic\n");
      break;

    case USE_ADDRESS:
      fprintf (file, "  address\n");
      break;

    case USE_COMPARE:
      fprintf (file, "  compare\n");
      break;
    }

   fprintf (file, "  in statement ");
   print_generic_expr (file, use->stmt, TDF_SLIM);
   fprintf (file, "\n");

   fprintf (file, "  at position ");
   print_generic_expr (file, *use->op_p, TDF_SLIM);
   fprintf (file, "\n");

   if (iv->step)
     {
       fprintf (file, "  base ");
       print_generic_expr (file, iv->base, TDF_SLIM);
       fprintf (file, "\n");

       fprintf (file, "  step ");
       print_generic_expr (file, iv->step, TDF_SLIM);
       fprintf (file, "\n");
     }
   else
     {
       fprintf (file, "  invariant ");
       print_generic_expr (file, iv->base, TDF_SLIM);
       fprintf (file, "\n");
     }

   fprintf (file, "  related candidates ");
   dump_bitmap (file, use->related_cands);
   fprintf (file, "\n");
}

/* Dumps information about induction variable candidate CAND to FILE.  */

extern void dump_cand (FILE *, struct iv_cand *);
void
dump_cand (FILE *file, struct iv_cand *cand)
{
  struct iv *iv = cand->iv;

  fprintf (file, "candidate %d%s\n",
	   cand->id, cand->important ? " (important)" : "");

  switch (cand->pos)
    {
    case IP_START:
      fprintf (file, "  incremented at start\n");
      break;

    case IP_NORMAL:
      fprintf (file, "  incremented before exit test\n");
      break;

    case IP_END:
      fprintf (file, "  incremented at end\n");
      break;
    }

   if (iv->step)
     {
       fprintf (file, "  base ");
       print_generic_expr (file, iv->base, TDF_SLIM);
       fprintf (file, "\n");

       fprintf (file, "  step ");
       print_generic_expr (file, iv->step, TDF_SLIM);
       fprintf (file, "\n");
     }
   else
     {
       fprintf (file, "  invariant ");
       print_generic_expr (file, iv->base, TDF_SLIM);
       fprintf (file, "\n");
     }
}

/* Checks whether ARG is either NULL_TREE or constant zero.  */

static bool
zero_p (tree arg)
{
  if (!arg)
    return true;

  return integer_zerop (arg);
}

/* Calls CBCK for each index in ADDR_P.  It passes the pointer to the index,
   the base if it is an array and DATA to the callback.  If the callback returns
   false, the whole search stops and false is returned.  */

static bool
for_each_index (tree *addr_p, bool (*cbck) (tree, tree *, void *), void *data)
{
  tree *nxt;

  for (; ; addr_p = nxt)
    {
      switch (TREE_CODE (*addr_p))
	{
	case SSA_NAME:
	  return cbck (NULL, addr_p, data);

	case INDIRECT_REF:
	  nxt = &TREE_OPERAND (*addr_p, 0);
	  return cbck (NULL, nxt, data);

	case BIT_FIELD_REF:
	case COMPONENT_REF:
	  nxt = &TREE_OPERAND (*addr_p, 0);
	  break;

	case ARRAY_REF:
	  nxt = &TREE_OPERAND (*addr_p, 0);
	  if (!cbck (*nxt, &TREE_OPERAND (*addr_p, 1), data))
	    return false;
	  break;

	case VAR_DECL:
	case PARM_DECL:
	case STRING_CST:
	  return true;

	default:
    	  abort ();
	}
    }
}

/* Forces IDX to be either constant or ssa name.  Callback for
   for_each_index.  */

struct idx_fs_data
{
  tree stmts;
  tree var;
};

static bool
idx_force_simple (tree base ATTRIBUTE_UNUSED, tree *idx, void *data)
{
  struct idx_fs_data *d = data;
  tree stmts;

  *idx = force_gimple_operand (*idx, &stmts, d->var, true);

  if (stmts)
    {
      tree_stmt_iterator tsi = tsi_start (d->stmts);
      tsi_link_before (&tsi, stmts, TSI_SAME_STMT);
    }

  return true;
}

/* Updates TREE_ADDRESSABLE flag for the base variable of EXPR.  */

static void
update_addressable_flag (tree expr)
{
  if (TREE_CODE (expr) != ADDR_EXPR)
    abort ();

  expr = TREE_OPERAND (expr, 0);
  while (TREE_CODE (expr) == ARRAY_REF
	 || TREE_CODE (expr) == COMPONENT_REF
	 || TREE_CODE (expr) == REALPART_EXPR
	 || TREE_CODE (expr) == IMAGPART_EXPR)
    expr = TREE_OPERAND (expr, 0);
  if (TREE_CODE (expr) != VAR_DECL
      && TREE_CODE (expr) != PARM_DECL)
    return;

  TREE_ADDRESSABLE (expr) = 1;
}

/* Expands EXPR to list of gimple statements STMTS, forcing it to become
   a gimple operand that is returned.  Temporary variables (if needed)
   are based on VAR.  If SIMPLE is true, force the operand to be either
   ssa_name or integer constant.  */

static tree
force_gimple_operand (tree expr, tree *stmts, tree var, bool simple)
{
  enum tree_code code = TREE_CODE (expr);
  char class = TREE_CODE_CLASS (code);
  tree op0, op1, stmts0, stmts1, stmt, rhs, name;
  tree_stmt_iterator tsi;
  struct idx_fs_data d;

  if (is_gimple_val (expr)
      && (!simple
	  || TREE_CODE (expr) == SSA_NAME
	  || TREE_CODE (expr) == INTEGER_CST))
    {
      if (code == ADDR_EXPR)
	update_addressable_flag (expr);

      *stmts = NULL_TREE;
      return expr;
    }

  if (code == ADDR_EXPR)
    {
      op0 = TREE_OPERAND (expr, 0);
      if (TREE_CODE (op0) == INDIRECT_REF)
	return force_gimple_operand (TREE_OPERAND (op0, 0), stmts, var,
				     simple);
    }

  if (!var)
    {
      var = create_tmp_var (TREE_TYPE (expr), "fgotmp");
      add_referenced_tmp_var (var);
    }

  switch (class)
    {
    case '1':
    case '2':
      op0 = force_gimple_operand (TREE_OPERAND (expr, 0), &stmts0, var, false);
      if (class == '2')
	{
	  op1 = force_gimple_operand (TREE_OPERAND (expr, 1), &stmts1, var, false);
	  rhs = build (code, TREE_TYPE (expr), op0, op1);
	}
      else
	{
	  rhs = build1 (code, TREE_TYPE (expr), op0);
	  stmts1 = NULL_TREE;
	}

      stmt = build (MODIFY_EXPR, void_type_node, var, rhs);
      name = make_ssa_name (var, stmt);
      TREE_OPERAND (stmt, 0) = name;

      if (stmts0)
	{
	  *stmts = stmts0;
	  if (stmts1)
	    {
	      tsi = tsi_last (*stmts);
	      tsi_link_after (&tsi, stmts1, TSI_CONTINUE_LINKING);
	    }
	}
      else if (stmts1)
	*stmts = stmts1;
      else
	*stmts = alloc_stmt_list ();

      tsi = tsi_last (*stmts);
      tsi_link_after (&tsi, stmt, TSI_CONTINUE_LINKING);
      return name;

    default:
      break;
    }

  if (TREE_CODE (expr) == ADDR_EXPR)
    {
      stmt = build (MODIFY_EXPR, void_type_node, var, expr);
      name = make_ssa_name (var, stmt);
      TREE_OPERAND (stmt, 0) = name;

      *stmts = alloc_stmt_list ();
      tsi = tsi_last (*stmts);
      tsi_link_after (&tsi, stmt, TSI_CONTINUE_LINKING);

      d.stmts = *stmts;
      d.var = var;
      for_each_index (&TREE_OPERAND (expr, 0), idx_force_simple, &d);

      update_addressable_flag (TREE_OPERAND (stmt, 1));

      return name;
    }

  abort ();
}

/* If TYPE is an array type, corresponding pointer type is returned,
   otherwise the TYPE is returned unchanged.  */

static tree
array2ptr (tree type)
{
  if (TREE_CODE (type) != ARRAY_TYPE)
    return type;

  return build_pointer_type (TREE_TYPE (type));
}

/* Sets single_exit field for loops.  */

static void
find_exit_edges (void)
{
  basic_block bb;
  edge e;
  struct loop *src, *dest;;

  FOR_EACH_BB (bb)
    {
      for (e = bb->succ; e; e = e->succ_next)
	{
	  src = e->src->loop_father;
	  dest = find_common_loop (src, e->dest->loop_father);

	  for (; src != dest; src = src->outer)
	    {
	      LOOP_DATA (src)->n_exits++;
	      if (LOOP_DATA (src)->n_exits > 1)
		{
		  LOOP_DATA (src)->single_exit = NULL;
		  continue;
		}

	      if (!dominated_by_p (CDI_DOMINATORS, src->latch, e->src))
		continue;

	      LOOP_DATA (src)->single_exit = e;
	    }
	}
    }
}

/* Finds the outermost loop in that each ssa name is used.  */

static void
find_outermost_usage (void)
{
  basic_block bb;
  block_stmt_iterator bsi;
  unsigned i, ver;
  use_optype uses;
  tree use, stmt;
  struct loop *loop;

  FOR_EACH_BB (bb)
    {
      loop = bb->loop_father;

      for (bsi = bsi_start (bb); !bsi_end_p (bsi); bsi_next (&bsi))
	{
	  stmt = bsi_stmt (bsi);
	  get_stmt_operands (stmt);

	  uses = STMT_USE_OPS (stmt);
	  for (i = 0; i < NUM_USES (uses); i++)
	    {
	      use = USE_OP (uses, i);
	      ver = SSA_NAME_VERSION (use);

	      if (!outermost_usage[ver])
		outermost_usage[ver] = loop;
	      else
		outermost_usage[ver] = find_common_loop (loop,
							 outermost_usage[ver]);
	    }
	}
    }
}

/* Returns the basic block in that statements should be emitted for IP_END
   position.  */

static basic_block
ip_end_pos (void)
{
  tree last;
  basic_block bb;

  bb = current_loop->latch;
  last = last_stmt (bb);
  /* If the latch is empty, preserve this (inserting the latch block might need
     extra jumps, which might spoil the code).  */
  if (!last || TREE_CODE (last) == LABEL_EXPR)
    return NULL;

  return bb;
}

/* Returns the basic block in that statements should be emitted for IP_NORMAL
   position.  */

static basic_block
ip_normal_pos (void)
{
  tree last;
  basic_block bb;

  if (current_loop->latch->pred->pred_next)
    return NULL;

  bb = current_loop->latch->pred->src;
  last = last_stmt (bb);
  if (TREE_CODE (last) != COND_EXPR)
    return NULL;

  return bb;
}

/* Returs true if STMT is after the place where the IP_NORMAL ivs will be
   emitted.  */

static bool
stmt_after_ip_normal_pos (tree stmt)
{
  basic_block bb = ip_normal_pos (), sbb = bb_for_stmt (stmt);

  if (!bb)
    abort ();

  if (sbb == current_loop->latch)
    return true;

  if (sbb != bb)
    return false;

  return stmt == last_stmt (bb);
}

/* Initializes data structures used by the iv optimization pass.  LOOPS is the
   loop tree.  */

static void
tree_ssa_iv_optimize_init (struct loops *loops)
{
  unsigned i;

  old_highest_ssa_version = highest_ssa_version;
  ivs = xcalloc (highest_ssa_version, sizeof (struct iv *));
  outermost_usage = xcalloc (highest_ssa_version, sizeof (struct loop *));

  for (i = 1; i < loops->num; i++)
    if (loops->parray[i])
      loops->parray[i]->aux = xcalloc (1, sizeof (struct loop_data));

  find_exit_edges ();
  find_outermost_usage ();

  VARRAY_GENERIC_PTR_NOGC_INIT (iv_uses, 20, "iv_uses");
  VARRAY_GENERIC_PTR_NOGC_INIT (iv_candidates, 20, "iv_candidates");
  VARRAY_GENERIC_PTR_NOGC_INIT (decl_rtl_to_reset, 20, "decl_rtl_to_reset");
}

/* Allocates an induction variable with given initial value BASE and step STEP
   for loop LOOP.  */

static struct iv *
alloc_iv (tree base, tree step)
{
  struct iv *iv = xcalloc (1, sizeof (struct iv));

  if (step && integer_zerop (step))
    step = NULL_TREE;

  iv->base = base;
  iv->step = step;
  iv->biv_p = false;
  iv->have_use_for = false;
  iv->ssa_name = NULL_TREE;

  return iv;
}

/* Sets STEP and BASE for induction variable IV.  */

static void
set_iv (tree iv, tree base, tree step)
{
  unsigned ver = SSA_NAME_VERSION (iv);

  if (ivs[ver])
    abort ();

  ivs[ver] = alloc_iv (base, step);
  ivs[ver]->ssa_name = iv;
}

/* Finds induction variable declaration for VAR.  */

static struct iv *
get_iv (tree var)
{
  unsigned ver = SSA_NAME_VERSION (var);
  basic_block bb;
  
  if (!ivs[ver])
    {
      bb = bb_for_stmt (SSA_NAME_DEF_STMT (var));

      if (!bb
	  || !flow_bb_inside_loop_p (current_loop, bb))
	set_iv (var, var, NULL_TREE);
    }

  return ivs[ver];
}

/* Determines the step of a biv defined in PHI.  */

static tree
determine_biv_step (tree phi)
{
  tree var = phi_element_for_edge (phi, loop_latch_edge (current_loop))->def;
  tree type = TREE_TYPE (var);
  tree step, stmt, lhs, rhs, op0, op1;
  enum tree_code code;

  if (TREE_CODE (var) != SSA_NAME
      || !is_gimple_reg (var))
    return NULL_TREE;

  /* Just work for integers and pointers.  */
  if (TREE_CODE (type) != INTEGER_TYPE
      && TREE_CODE (type) != POINTER_TYPE)
    return NULL_TREE;

  step = convert (type, integer_zero_node);

  while (1)
    {
      stmt = SSA_NAME_DEF_STMT (var);
      if (stmt == phi)
	return step;

      if (TREE_CODE (stmt) != MODIFY_EXPR)
	return NULL_TREE;

      lhs = TREE_OPERAND (stmt, 0);
      rhs = TREE_OPERAND (stmt, 1);

      if (lhs != var)
	return NULL_TREE;

      code = TREE_CODE (rhs);
      switch (code)
	{
	case SSA_NAME:
	  var = rhs;
	  break;

	case PLUS_EXPR:
	case MINUS_EXPR:
	  op0 = TREE_OPERAND (rhs, 0);
	  op1 = TREE_OPERAND (rhs, 1);

	  if (TREE_CODE (op1) != INTEGER_CST)
	    {
	      if (code == MINUS_EXPR
		  || TREE_CODE (op0) != INTEGER_CST)
		return NULL_TREE;

	      SWAP (op0, op1);
	    }

	  if (TREE_CODE (op0) != SSA_NAME)
	    return NULL_TREE;

	  step = EXEC_BINARY (code, type, step, op1);
	  var = op0;
	  break;
	  
	default:
	  return NULL_TREE;
	}
    }
}

/* Finds basic ivs.  */

static bool
find_bivs (void)
{
  tree phi, step;
  bool found = false;

  for (phi = phi_nodes (current_loop->header); phi; phi = TREE_CHAIN (phi))
    {
      step = determine_biv_step (phi);
      if (!step)
	continue;

      set_iv (PHI_RESULT (phi),
	      phi_element_for_edge (phi, loop_preheader_edge (current_loop))->def,
	      step);
      found |= (integer_nonzerop (step) != 0);
    }

  return found;
}

/* Marks basic ivs.  */

static void
mark_bivs (void)
{
  tree phi, stmt, var, rhs, op0, op1;
  struct iv *iv;

  for (phi = phi_nodes (current_loop->header); phi; phi = TREE_CHAIN (phi))
    {
      iv = get_iv (PHI_RESULT (phi));
      if (!iv)
	continue;

      iv->biv_p = true;
      var = phi_element_for_edge (phi, loop_latch_edge (current_loop))->def;
      stmt = SSA_NAME_DEF_STMT (var);

      while (TREE_CODE (stmt) != PHI_NODE)
	{
	  var = TREE_OPERAND (stmt, 0);
	  iv = get_iv (var);
	  iv->biv_p = true;

	  rhs = TREE_OPERAND (stmt, 1);
	  switch (TREE_CODE (rhs))
	    {
	    case SSA_NAME:
	      var = rhs;
	      break;

	    case PLUS_EXPR:
	    case MINUS_EXPR:
	      op0 = TREE_OPERAND (rhs, 0);
	      op1 = TREE_OPERAND (rhs, 1);
	      var = TREE_CODE (op1) != INTEGER_CST ? op1 : op0;
	      break;

	    default:
	      abort ();
	    }

	  stmt = SSA_NAME_DEF_STMT (var);
	}
    }
}

/* Finds definition of VAR and fills in BASE and STEP accordingly.  */

static bool
get_var_def (tree var, tree *base, tree *step)
{
  struct iv *iv;
  
  if (is_gimple_min_invariant (var))
    {
      *base = var;
      *step = NULL_TREE;
      return true;
    }

  iv = get_iv (var);
  if (!iv)
    return false;

  *base = iv->base;
  *step = iv->step;

  return true;
}

/* Finds general ivs in statement STMT.  */

static void
find_givs_in_stmt (tree stmt)
{
  tree lhs, rhs, op0, op1, mul = NULL_TREE;
  bool negate = false;
  tree base = NULL_TREE, step = NULL_TREE, type;
  tree base0 = NULL_TREE, step0 = NULL_TREE;
  enum tree_code code;
  char class;

  if (TREE_CODE (stmt) != MODIFY_EXPR)
    return;

  lhs = TREE_OPERAND (stmt, 0);
  rhs = TREE_OPERAND (stmt, 1);
  if (TREE_CODE (lhs) != SSA_NAME)
    return;

  type = TREE_TYPE (lhs);
  if (TREE_CODE (type) != INTEGER_TYPE
      && TREE_CODE (type) != POINTER_TYPE)
    return;

  code = TREE_CODE (rhs);
  class = TREE_CODE_CLASS (code);
  if (class == '1' || class == '2')
    {
      op0 = TREE_OPERAND (rhs, 0);
      if (!get_var_def (op0, &base0, &step0))
	return;
    }

  if (class == '2')
    {
      op1 = TREE_OPERAND (rhs, 1);
      if (!get_var_def (op1, &base, &step))
	return;
    }

  switch (code)
    {
    case SSA_NAME:
      if (!get_var_def (rhs, &base, &step))
	return;
      break;

    case PLUS_EXPR:
      break;

    case MINUS_EXPR:
      negate = true;
      break;

    case MULT_EXPR:
      if (step0)
	{
	  if (step)
	    return;

	  if (TREE_CODE (base) != INTEGER_CST)
	    return;

	  mul = base;
	  base = base0;
	  step = step0;
	  base0 = NULL_TREE;
	  step0 = NULL_TREE;
	}
      else if (step)
	{
	  if (TREE_CODE (base0) != INTEGER_CST)
	    return;

	  mul = base0;
	  base0 = NULL_TREE;
	}
      else
	return;

      break;
	  
    case NEGATE_EXPR:
      negate = true;
      base = base0;
      step = step0;
      base0 = NULL_TREE;
      step0 = NULL_TREE;
      break;

    default:
      return;
    }

  if (negate)
    {
      base = fold (build1 (NEGATE_EXPR, type, base));
      if (step)
	step = EXEC_UNARY (NEGATE_EXPR, type, step);
    }

  if (mul)
    {
      base = fold (build (MULT_EXPR, type, mul, base));
      if (step)
	step = EXEC_BINARY (MULT_EXPR, type, mul, step);
    }

  if (base0)
    base = fold (build (PLUS_EXPR, type, base, base0));
    
  if (step0)
    {
      if (step)
	step = EXEC_BINARY (PLUS_EXPR, type, step, step0);
      else
	step = step0;
    }
  
  set_iv (lhs, base, step);
}

/* Finds general ivs in basic block BB.  */

static void
find_givs_in_bb (basic_block bb)
{
  block_stmt_iterator bsi;

  for (bsi = bsi_start (bb); !bsi_end_p (bsi); bsi_next (&bsi))
    find_givs_in_stmt (bsi_stmt (bsi));
}

/* Finds general ivs.  */

static void
find_givs (void)
{
  basic_block *body = get_loop_body_in_dom_order (current_loop);
  unsigned i;

  for (i = 0; i < current_loop->num_nodes; i++)
    find_givs_in_bb (body[i]);
  free (body);
}

/* Computes inverse of X modulo 2^s, where MASK = 2^s-1.  */

static tree
inverse (tree x, tree mask)
{
  tree type = TREE_TYPE (x);
  tree ctr = EXEC_BINARY (RSHIFT_EXPR, type, mask, integer_one_node);
  tree rslt = convert (type, integer_one_node);

  while (integer_nonzerop (ctr))
    {
      rslt = EXEC_BINARY (MULT_EXPR, type, rslt, x);
      rslt = EXEC_BINARY (BIT_AND_EXPR, type, rslt, mask);
      x = EXEC_BINARY (MULT_EXPR, type, x, x);
      x = EXEC_BINARY (BIT_AND_EXPR, type, x, mask);
      ctr = EXEC_BINARY (RSHIFT_EXPR, type, ctr, integer_one_node);
    }

  return rslt;
}

/* Determine the number of iterations.  */

static void
determine_number_of_iterations (void)
{
  tree stmt, cond, type, op0, op1;
  enum tree_code code;
  tree base0, step0, base1, step1, step, delta, mmin, mmax;
  tree may_xform, bound, s, d, tmp;
  bool was_sharp = false;
  tree assumption;
  tree assumptions = boolean_true_node;
  tree noloop_assumptions = boolean_false_node;
  tree unsigned_step_type;

  /* The meaning of these assumptions is this:
     if !assumptions
       then the rest of information does not have to be valid
     if noloop_assumptions then the loop does not have to roll
       (but it is only conservative approximation, i.e. it only says that
       if !noloop_assumptions, then the loop does not end before the computed
       number of iterations)  */

  if (!LOOP_DATA (current_loop)->single_exit)
    return;

  stmt = last_stmt (LOOP_DATA (current_loop)->single_exit->src);
  if (!stmt || TREE_CODE (stmt) != COND_EXPR)
    return;

  /* We want the condition for staying inside loop.  */
  cond = COND_EXPR_COND (stmt);
  if (LOOP_DATA (current_loop)->single_exit->flags & EDGE_TRUE_VALUE)
    cond = invert_truthvalue (cond);

  code = TREE_CODE (cond);
  switch (code)
    {
    case GT_EXPR:
    case GE_EXPR:
    case NE_EXPR:
    case LT_EXPR:
    case LE_EXPR:
      break;

    default:
      return;
    }
  
  op0 = TREE_OPERAND (cond, 0);
  op1 = TREE_OPERAND (cond, 1);
  type = TREE_TYPE (op0);

  if (TREE_CODE (type) != INTEGER_TYPE
    && TREE_CODE (type) != POINTER_TYPE)
    return;
      
  if (!get_var_def (op0, &base0, &step0))
    return;
  if (!get_var_def (op1, &base1, &step1))
    return;

  /* Make < comparison from > ones.  */
  if (code == GE_EXPR
      || code == GT_EXPR)
    {
      SWAP (base0, base1);
      SWAP (step0, step1);
      code = swap_tree_comparison (code);
    }

  /* We can take care of the case of two induction variables chasing each other
     if the test is NE. I have never seen a loop using it, but still it is
     cool.  */
  if (!zero_p (step0) && !zero_p (step1))
    {
      if (code != NE_EXPR)
	return;

      step0 = EXEC_BINARY (MINUS_EXPR, type, step0, step1);
      step1 = NULL_TREE;
    }

  /* If the result is a constant,  the loop is weird.  More precise handling
     would be possible, but the situation is not common enough to waste time
     on it.  */
  if (zero_p (step0) && zero_p (step1))
    return;

  /* Ignore loops of while (i-- < 10) type.  */
  if (code != NE_EXPR)
    {
      if (step0 && !tree_expr_nonnegative_p (step0))
	return;

      if (!zero_p (step1) && tree_expr_nonnegative_p (step1))
	return;
    }

  /* For pointers these are NULL.  We assume pointer arithmetics never
     overflows.  */
  mmin = TYPE_MIN_VALUE (type);
  mmax = TYPE_MAX_VALUE (type);

  /* Some more condition normalization.  We must record some assumptions
     due to overflows.  */

  if (code == LT_EXPR)
    {
      /* We want to take care only of <=; this is easy,
	 as in cases the overflow would make the transformation unsafe the loop
	 does not roll.  Seemingly it would make more sense to want to take
	 care of <, as NE is more simmilar to it, but the problem is that here
	 the transformation would be more difficult due to possibly infinite
	 loops.  */
      if (zero_p (step0))
	{
	  if (mmax)
	    assumption = fold (build (EQ_EXPR, boolean_type_node, base0, mmax));
	  else
	    assumption = boolean_true_node;
	  if (integer_nonzerop (assumption))
	    {
	      /* We exit immediatelly.  */
	      LOOP_DATA (current_loop)->assumptions = boolean_true_node;
	      LOOP_DATA (current_loop)->may_be_zero = boolean_true_node;
	      LOOP_DATA (current_loop)->niter = convert (type, integer_zero_node);
	      return;
	    }
	  base0 = fold (build (PLUS_EXPR, type, base0, integer_one_node));
	}
      else
	{
	  if (mmin)
	    assumption = fold (build (EQ_EXPR, boolean_type_node, base1, mmin));
	  else
	    assumption = boolean_true_node;
	  if (integer_nonzerop (assumption))
	    {
	      LOOP_DATA (current_loop)->assumptions = boolean_true_node;
	      LOOP_DATA (current_loop)->may_be_zero = boolean_true_node;
	      LOOP_DATA (current_loop)->niter = convert (type, integer_zero_node);
	      return;
	    }
	  base1 = fold (build (MINUS_EXPR, type, base1, integer_one_node));
	}
      noloop_assumptions = assumption;
      code = LE_EXPR;

      /* It will be useful to be able to tell the difference once more in
	 <= -> != reduction.  */
      was_sharp = true;
    }

  /* Take care of trivially infinite loops.  */
  if (code != NE_EXPR)
    {
      if (zero_p (step0)
	  && mmin
	  && operand_equal_p (base0, mmin, 0))
	return;
      if (zero_p (step1)
	  && mmax
	  && operand_equal_p (base1, mmax, 0))
	return;
    }

  /* If we can we want to take care of NE conditions instead of size
     comparisons, as they are much more friendly (most importantly
     this takes care of special handling of loops with step 1).  We can
     do it if we first check that upper bound is greater or equal to
     lower bound, their difference is constant c modulo step and that
     there is not an overflow.  */
  if (code != NE_EXPR)
    {
      if (zero_p (step0))
	step = EXEC_UNARY (NEGATE_EXPR, type, step1);
      else
	step = step0;
      delta = build (MINUS_EXPR, type, base1, base0);
      delta = fold (build (FLOOR_MOD_EXPR, type, delta, step));
      may_xform = boolean_false_node;

      if (TREE_CODE (delta) == INTEGER_CST)
	{
	  tmp = EXEC_BINARY (MINUS_EXPR, type, step, integer_zero_node);
	  if (was_sharp
	      && operand_equal_p (delta, tmp, 0))
	    {
	      /* A special case.  We have transformed condition of type
		 for (i = 0; i < 4; i += 4)
		 into
		 for (i = 0; i <= 3; i += 4)
		 obviously if the test for overflow during that transformation
		 passed, we cannot overflow here.  Most importantly any
		 loop with sharp end condition and step 1 falls into this
		 cathegory, so handling this case specially is definitely
		 worth the troubles.  */
	      may_xform = boolean_true_node;
	    }
	  else if (zero_p (step0))
	    {
	      if (!mmin)
		may_xform = boolean_true_node;
	      else
		{
		  bound = EXEC_BINARY (PLUS_EXPR, type, mmin, step);
		  bound = EXEC_BINARY (MINUS_EXPR, type, bound, delta);
		  may_xform = fold (build (LE_EXPR, boolean_type_node,
					   bound, base0));
		}
	    }
	  else
	    {
	      if (!mmax)
		may_xform = boolean_true_node;
	      else
		{
		  bound = EXEC_BINARY (MINUS_EXPR, type, mmax, step);
		  bound = EXEC_BINARY (PLUS_EXPR, type, bound, delta);
		  may_xform = fold (build (LE_EXPR, boolean_type_node,
					   base1, bound));
		}
	    }
	}

      if (!integer_zerop (may_xform))
	{
	  /* We perform the transformation always provided that it is not
	     completely senseless.  This is OK, as we would need this assumption
	     to determine the number of iterations anyway.  */
	  if (!integer_nonzerop (may_xform))
	    assumptions = may_xform;

	  if (zero_p (step0))
	    {
	      base0 = build (PLUS_EXPR, type, base0, delta);
	      base0 = fold (build (MINUS_EXPR, type, base0, step));
	    }
	  else
	    {
	      base1 = build (MINUS_EXPR, type, base1, delta);
	      base1 = fold (build (PLUS_EXPR, type, base1, step));
	    }

	  assumption = fold (build (GT_EXPR, boolean_type_node, base0, base1));
	  noloop_assumptions = fold (build (TRUTH_OR_EXPR, boolean_type_node,
					    noloop_assumptions, assumption));
	  code = NE_EXPR;
	}
    }

  /* Count the number of iterations.  */
  if (code == NE_EXPR)
    {
      /* Everything we do here is just arithmetics modulo size of mode.  This
	 makes us able to do more involved computations of number of iterations
	 than in other cases.  First transform the condition into shape
	 s * i <> c, with s positive.  */
      base1 = fold (build (MINUS_EXPR, type, base1, base0));
      base0 = NULL_TREE;
      if (!zero_p (step1))
  	step0 = EXEC_UNARY (NEGATE_EXPR, type, step1);
      step1 = NULL_TREE;
      if (!tree_expr_nonnegative_p (step0))
	{
	  step0 = EXEC_UNARY (NEGATE_EXPR, type, step0);
	  base1 = fold (build1 (NEGATE_EXPR, type, base1));
	}

      /* Let nsd (s, size of mode) = d.  If d does not divide c, the loop
	 is infinite.  Otherwise, the number of iterations is
	 (inverse(s/d) * (c/d)) mod (size of mode/d).  */
      s = step0;
      d = integer_one_node;
      unsigned_step_type = make_unsigned_type (TYPE_PRECISION (type));
      bound = convert (unsigned_step_type, build_int_2 (~0, ~0));
      while (1)
	{
	  tmp = EXEC_BINARY (BIT_AND_EXPR, type, s, integer_one_node);
	  if (integer_nonzerop (tmp))
	    break;
	  
	  s = EXEC_BINARY (RSHIFT_EXPR, type, s, integer_one_node);
	  d = EXEC_BINARY (LSHIFT_EXPR, type, d, integer_one_node);
	  bound = EXEC_BINARY (RSHIFT_EXPR, type, d, integer_one_node);
	}

      tmp = fold (build (EXACT_DIV_EXPR, type, base1, d));
      tmp = fold (build (MULT_EXPR, type, tmp, inverse (s, bound)));
      LOOP_DATA (current_loop)->niter = fold (build (BIT_AND_EXPR, type,
						     tmp, bound));
    }
  else
    {
      if (zero_p (step1))
	/* Condition in shape a + s * i <= b
	   We must know that b + s does not overflow and a <= b + s and then we
	   can compute number of iterations as (b + s - a) / s.  (It might
	   seem that we in fact could be more clever about testing the b + s
	   overflow condition using some information about b - a mod s,
	   but it was already taken into account during LE -> NE transform).  */
	{
	  if (mmax)
	    {
	      bound = EXEC_BINARY (MINUS_EXPR, type, mmax, step0);
	      assumption = fold (build (LE_EXPR, boolean_type_node,
					base1, bound));
	      assumptions = fold (build (TRUTH_AND_EXPR, boolean_type_node,
					 assumptions, assumption));
	    }
	  step = step0;
	  tmp = fold (build (PLUS_EXPR, type, base1, step0));
	  assumption = fold (build (GT_EXPR, boolean_type_node, base0, tmp));
	  delta = fold (build (PLUS_EXPR, type, base1, step));
	  delta = fold (build (MINUS_EXPR, type, delta, base0));
	}
      else
	{
	  /* Condition in shape a <= b - s * i
	     We must know that a - s does not overflow and a - s <= b and then
	     we can again compute number of iterations as (b - (a - s)) / s.  */
	  if (mmin)
	    {
	      bound = EXEC_BINARY (MINUS_EXPR, type, mmin, step1);
	      assumption = fold (build (LE_EXPR, boolean_type_node,
					bound, base0));
	      assumptions = fold (build (TRUTH_AND_EXPR, boolean_type_node,
					 assumptions, assumption));
	    }
	  step = fold (build1 (NEGATE_EXPR, type, step1));
	  tmp = fold (build (PLUS_EXPR, type, base0, step1));
	  assumption = fold (build (GT_EXPR, boolean_type_node, tmp, base1));
	  delta = fold (build (MINUS_EXPR, type, base0, step));
	  delta = fold (build (MINUS_EXPR, type, base1, delta));
	}
      noloop_assumptions = fold (build (TRUTH_OR_EXPR, boolean_type_node,
					noloop_assumptions, assumption));
      delta = fold (build (FLOOR_DIV_EXPR, type, delta, step));
      LOOP_DATA (current_loop)->niter = delta;
    }

  LOOP_DATA (current_loop)->assumptions = assumptions;
  LOOP_DATA (current_loop)->may_be_zero = noloop_assumptions;
}

/* For each ssa name defined in LOOP determines whether it is an induction
   variable and if so, its initial value and step.  */

static bool
find_induction_variables (void)
{
  unsigned i;

  /* TODO (FIXME?) Use scev for this.  ??? Perhaps the code could still be useful at lower
     optimization levels, since it might be faster.  */

  if (!find_bivs ())
    return false;
  find_givs ();
  mark_bivs ();
  determine_number_of_iterations ();

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      if (LOOP_DATA (current_loop)->niter)
	{
	  fprintf (tree_dump_file, "  number of iterations ");
	  print_generic_expr (tree_dump_file, LOOP_DATA (current_loop)->niter,
			      TDF_SLIM);
	  fprintf (tree_dump_file, "\n");

    	  fprintf (tree_dump_file, "  may be zero if ");
    	  print_generic_expr (tree_dump_file, LOOP_DATA (current_loop)->may_be_zero,
    			      TDF_SLIM);
    	  fprintf (tree_dump_file, "\n");

    	  fprintf (tree_dump_file, "  bogus unless ");
    	  print_generic_expr (tree_dump_file, LOOP_DATA (current_loop)->assumptions,
    			      TDF_SLIM);
    	  fprintf (tree_dump_file, "\n");
    	  fprintf (tree_dump_file, "\n");
    	};
 
      fprintf (tree_dump_file, "Induction variables:\n\n");

      for (i = 0; i < highest_ssa_version; i++)
	if (ivs[i])
	  dump_iv (tree_dump_file, ivs[i]);
    }


  return true;
}

/* Records a use of type USE_TYPE at *USE_P in STMT whose value is IV.  */

static void
record_use (tree *use_p, struct iv *iv, tree stmt, enum use_type use_type)
{
  struct iv_use *use = xcalloc (1, sizeof (struct iv_use));

  use->id = VARRAY_ACTIVE_SIZE (iv_uses);
  use->type = use_type;
  use->iv = iv;
  use->stmt = stmt;
  use->op_p = use_p;
  use->related_cands = BITMAP_XMALLOC ();
  use->best_cost = INFTY;

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    dump_use (tree_dump_file, use);

  VARRAY_PUSH_GENERIC_PTR_NOGC (iv_uses, use);
}

/* Checks whether the use *OP_P is interesting and if so, records it.  */

static void
find_interesting_uses_op (tree *op_p)
{
  struct iv *iv;
  struct iv *civ;

  if (TREE_CODE (*op_p) != SSA_NAME)
    return;

  iv = get_iv (*op_p);
  if (!iv || !iv->step || iv->have_use_for)
    return;
  iv->have_use_for = true;

  civ = xmalloc (sizeof (struct iv));
  *civ = *iv;

  record_use (op_p, civ, SSA_NAME_DEF_STMT (*op_p), USE_NONLINEAR_EXPR);
}

/* Checks whether the condition *COND_P in STMT is interesting
   and if so, records it.  */

static void
find_interesting_uses_cond (tree stmt, tree *cond_p)
{
  tree *op0_p;
  tree *op1_p;
  struct iv *iv0 = NULL, *iv1 = NULL, *civ;
  struct iv const_iv;
  tree zero = integer_zero_node;

  const_iv.step = NULL_TREE;

  if (TREE_CODE (*cond_p) == SSA_NAME)
    {
      op0_p = cond_p;
      op1_p = &zero;
    }
  else
    {
      op0_p = &TREE_OPERAND (*cond_p, 0);
      op1_p = &TREE_OPERAND (*cond_p, 1);
    }

  if (TREE_CODE (*op0_p) == SSA_NAME)
    iv0 = get_iv (*op0_p);
  else
    iv0 = &const_iv;

  if (TREE_CODE (*op1_p) == SSA_NAME)
    iv1 = get_iv (*op1_p);
  else
    iv1 = &const_iv;

  if (/* When comparing with non-invariant value, we may not do any senseful
	 induction variable elimination.  */
      (!iv0 || !iv1)
      /* Eliminating condition based on two ivs would be nontrivial.
	 ??? TODO -- it is not really important to handle this case.  */
      || (!zero_p (iv0->step) && !zero_p (iv1->step)))
    {
      find_interesting_uses_op (op0_p);
      find_interesting_uses_op (op1_p);
      return;
    }

  if (zero_p (iv0->step) && zero_p (iv1->step))
    {
      /* If both are invariants, this is a work for unswitching.  */
      return;
    }

  civ = xmalloc (sizeof (struct iv));
  *civ = zero_p (iv0->step) ? *iv1: *iv0;
  record_use (cond_p, civ, stmt, USE_COMPARE);
}

/* Cumulates the steps of indices into DATA and replaces their values with the
   initial ones.  Returns false when the value of the index cannot be determined.
   Callback for for_each_index.  */

static bool
idx_find_step (tree base, tree *idx, void *data)
{
  tree *step_p = data;
  struct iv *iv;
  tree step, type;
  
  if (TREE_CODE (*idx) != SSA_NAME)
    return true;

  iv = get_iv (*idx);
  if (!iv)
    return false;

  *idx = iv->base;

  if (!iv->step)
    return true;

  if (base)
    {
      step = TYPE_SIZE_UNIT (TREE_TYPE (TREE_TYPE (base)));
      type = array2ptr (TREE_TYPE (base));
    }
  else
    {
      /* The step for pointer arithmetics already is 1 byte.  */
      step = integer_one_node;
      type = TREE_TYPE (*idx);
    }

  step = EXEC_BINARY (MULT_EXPR, type, step, iv->step);

  if (!*step_p)
    *step_p = step;
  else
    *step_p = EXEC_BINARY (PLUS_EXPR, type, *step_p, step);

  return true;
}

/* Records use in index IDX.  Callback for for_each_index.  */

static bool
idx_record_use (tree base ATTRIBUTE_UNUSED, tree *idx,
		void *data ATTRIBUTE_UNUSED)
{
  find_interesting_uses_op (idx);
  return true;
}

/* Finds addresses in *OP_P inside STMT.  */

static void
find_interesting_uses_address (tree stmt, tree *op_p)
{
  tree base = unshare_expr (*op_p), step = NULL;
  struct iv *civ;

  /* Ignore bitfields for now.  Not really something terribly complicated
     to handle.  TODO.  */
  if (TREE_CODE (base) == COMPONENT_REF
      && DECL_NONADDRESSABLE_P (TREE_OPERAND (base, 1)))
    goto fail;

  if (!for_each_index (&base, idx_find_step, &step)
      || zero_p (step))
    goto fail;

  if (TREE_CODE (base) == INDIRECT_REF)
    base = TREE_OPERAND (base, 0);
  else
    base = build1 (ADDR_EXPR,
		   build_pointer_type (TREE_TYPE (base)),
		   base);

  civ = alloc_iv (base, step);
  record_use (op_p, civ, stmt, USE_ADDRESS);
  return;

fail:
  for_each_index (op_p, idx_record_use, NULL);
}

/* Finds interesting uses of induction variables in the statement STMT.  */

static void
find_interesting_uses_stmt (tree stmt)
{
  struct iv *iv;
  tree *op_p, lhs, rhs;
  use_optype uses = NULL;
  unsigned i, n;
  struct loop *loop;

  if (TREE_CODE (stmt) == COND_EXPR)
    {
      find_interesting_uses_cond (stmt, &COND_EXPR_COND (stmt));
      return;
    }

  if (TREE_CODE (stmt) == MODIFY_EXPR)
    {
      lhs = TREE_OPERAND (stmt, 0);
      rhs = TREE_OPERAND (stmt, 1);

      if (TREE_CODE (lhs) == SSA_NAME)
	{
	  /* If the statement defines an induction variable, uses of the induction
	     variables of the loop are not interesting.  */

	  iv = get_iv (lhs);

	  if (iv)
	    {
	      /* If the variable is used outside of the loop, we must preserve it.

		 TODO -- add posibility to replace it by the known final value,
		 or to express the final value using the other ivs.  */
	      loop = outermost_usage[SSA_NAME_VERSION (lhs)];
	      if (loop
		  && loop != current_loop
		  && !flow_loop_nested_p (current_loop, loop))
		find_interesting_uses_op (&lhs);

	      return;
	    }
	}

      switch (TREE_CODE_CLASS (TREE_CODE (rhs)))
	{
	case '<':
	  find_interesting_uses_cond (stmt, &TREE_OPERAND (stmt, 1));
	  return;

	case 'r':
	  find_interesting_uses_address (stmt, &TREE_OPERAND (stmt, 1));
	  return;

	default: ;
	}

      if (TREE_CODE_CLASS (TREE_CODE (lhs)) == 'r')
	{
	  find_interesting_uses_address (stmt, &TREE_OPERAND (stmt, 0));
	  find_interesting_uses_op (&TREE_OPERAND (stmt, 1));
	  return;
	}
    }

  if (TREE_CODE (stmt) == PHI_NODE
      && bb_for_stmt (stmt) == current_loop->header)
    {
      lhs = PHI_RESULT (stmt);
      iv = get_iv (lhs);

      if (iv)
	{
	  /* If the variable is used outside of the loop, we must preserve it.
	     FIXME -- we do not handle this case correctly, since we just try
	     to replace the rhs of the phi.  */
	      
	  loop = outermost_usage[SSA_NAME_VERSION (lhs)];
	  if (loop
	      && loop != current_loop
	      && !flow_loop_nested_p (current_loop, loop))
	    find_interesting_uses_op (&lhs);

	  return;
	}
    }

  if (TREE_CODE (stmt) == PHI_NODE)
    n = PHI_NUM_ARGS (stmt);
  else
    {
      get_stmt_operands (stmt);
      uses = STMT_USE_OPS (stmt);
      n = NUM_USES (uses);
    }

  for (i = 0; i < n; i++)
    {
      if (TREE_CODE (stmt) == PHI_NODE)
	op_p = &PHI_ARG_DEF (stmt, i);
      else
	op_p = USE_OP_PTR (uses, i);

      if (TREE_CODE (*op_p) != SSA_NAME)
	continue;

      iv = get_iv (*op_p);
      if (!iv)
	continue;

      find_interesting_uses_op (op_p);
    }
}

/* Finds uses of the induction variables that are interesting.  */

static void
find_interesting_uses (void)
{
  basic_block bb;
  block_stmt_iterator bsi;
  tree phi;

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    fprintf (tree_dump_file, "Uses:\n\n");

  FOR_EACH_BB (bb)
    {
      for (phi = phi_nodes (bb); phi; phi = TREE_CHAIN (phi))
	find_interesting_uses_stmt (phi);
      for (bsi = bsi_start (bb); !bsi_end_p (bsi); bsi_next (&bsi))
	find_interesting_uses_stmt (bsi_stmt (bsi));
    }

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    fprintf (tree_dump_file, "\n");
}

/* Adds a candidate BASE + STEP * i.  Important field is set to IMPORTANT and
   position to POS.  If USE is not NULL, the candidate is set as related to
   it.  */

static void
add_candidate_1 (tree base, tree step, bool important, enum iv_position pos,
		 struct iv_use *use)
{
  unsigned i;
  struct iv_cand *cand = NULL;

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_candidates); i++)
    {
      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);

      if (cand->pos != pos)
	continue;

      if (!operand_equal_p (base, cand->iv->base, 0))
	continue;

      if (zero_p (cand->iv->step))
	{
	  if (zero_p (step))
	    break;
	}
      else
	{
	  if (step && operand_equal_p (step, cand->iv->step, 0))
	    break;
	}
    }

  if (i == VARRAY_ACTIVE_SIZE (iv_candidates))
    {
      cand = xcalloc (1, sizeof (struct iv_cand));
      cand->id = i;
      cand->iv = alloc_iv (base, step);
      cand->pos = pos;
      cand->var_before = create_tmp_var_raw (TREE_TYPE (base), "ivtmp");
      cand->var_after = cand->var_before;
      cand->important = important;
      VARRAY_PUSH_GENERIC_PTR_NOGC (iv_candidates, cand);

      if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
	dump_cand (tree_dump_file, cand);
    }

  if (important && !cand->important)
    {
      cand->important = true;
      if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
	fprintf (tree_dump_file, "Candidate %d is important\n", cand->id);
    }

  if (use)
    {
      bitmap_set_bit (use->related_cands, i);
      if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
	fprintf (tree_dump_file, "Candidate %d is related to use %d\n",
		 cand->id, use->id);
    }
}

/* Adds a candidate BASE + STEP * i.  Important field is set to IMPORTANT and
   position to POS.  If USE is not NULL, the candidate is set as related to
   it.  The candidate computation is scheduled on all available positions.  */

static void
add_candidate (tree base, tree step, bool important, struct iv_use *use)
{
  add_candidate_1 (base, step, important, IP_START, use);
  if (ip_normal_pos ())
    add_candidate_1 (base, step, important, IP_NORMAL, use);
  if (ip_end_pos ())
    add_candidate_1 (base, step, important, IP_END, use);
}

/* Adds standard iv candidates.  */

static void
add_standard_iv_candidates (void)
{
  /* Add 0 + 1 * iteration candidate.  */
  add_candidate (convert (integer_type_node, integer_zero_node),
      		 convert (integer_type_node, integer_one_node),
		 true, NULL);

  /* The same for a long type.  */
  add_candidate (convert (long_integer_type_node, integer_zero_node),
		 convert (long_integer_type_node, integer_one_node),
		 true, NULL);
}


/* Adds candidates bases on the old induction variable IV.  */

static void
add_old_iv_candidates (struct iv *iv)
{ 
  add_candidate (iv->base, iv->step, true, NULL);

  /* The same, but with initial value zero.  */
  add_candidate (convert (TREE_TYPE (iv->base), integer_zero_node),
		 iv->step, true, NULL);
}

/* Adds candidates based on the old induction variables.  */

static void
add_old_ivs_candidates (void)
{
  unsigned i;
  struct iv *iv;

  for (i = 0; i < highest_ssa_version; i++)
    {
      iv = ivs[i];
      if (!iv || !iv->biv_p)
	continue;

      add_old_iv_candidates (iv);
    }
}

/* Adds candidates based on the value of the induction variable IV and USE.  */

static void
add_iv_value_candidates (struct iv *iv, struct iv_use *use)
{
  add_candidate (iv->base, iv->step, false, use);

  /* The same, but with initial value zero.  */
  add_candidate (convert (array2ptr (TREE_TYPE (iv->base)), integer_zero_node),
		 iv->step, false, use);
}

/* Adds candidates based on the address IV and USE.  */

static void
add_address_candidates (struct iv *iv, struct iv_use *use)
{
  tree base, type;

  /* First, the trivial choices.  */
  add_iv_value_candidates (iv, use);

  /* Second, try removing the COMPONENT_REFs.  */
  if (TREE_CODE (iv->base) == ADDR_EXPR)
    {
      base = TREE_OPERAND (iv->base, 0);
      type = TREE_TYPE (iv->base);
      while (TREE_CODE (base) == COMPONENT_REF
	     || (TREE_CODE (base) == ARRAY_REF
		 && TREE_CODE (TREE_OPERAND (base, 1)) == INTEGER_CST))
	base = TREE_OPERAND (base, 0);

      if (base != TREE_OPERAND (iv->base, 0))
	{ 
	  if (TREE_CODE (base) == INDIRECT_REF)
	    base = TREE_OPERAND (base, 0);
	  else
	    base = build1 (ADDR_EXPR, type, base);
	  add_candidate (base, iv->step, false, use);
	}
    }
}

/* Adds candidates based on the uses.  */

static void
add_derived_ivs_candidates (void)
{
  unsigned i;

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      struct iv_use *use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);

      if (!use)
	continue;

      switch (use->type)
	{
	case USE_NONLINEAR_EXPR:
	case USE_COMPARE:
	  /* Just add the ivs based on the value of the iv used here.  */
	  add_iv_value_candidates (use->iv, use);
	  break;

	case USE_ADDRESS:
	  add_address_candidates (use->iv, use);
	  break;
	}
    }
}

/* Finds the candidates for the induction variables.  */

static void
find_iv_candidates (void)
{
  /* Add commonly used ivs.  */
  add_standard_iv_candidates ();

  /* Add old induction variables.  */
  add_old_ivs_candidates ();

  /* Add induction variables derived from uses.  */
  add_derived_ivs_candidates ();
}

/* Allocates the data structure mapping the (use, candidate) pairs to costs.
   If consider_all_candidates is true, we use a two-dimensional array, otherwise
   we allocate a simple list to every use.  */

static void
alloc_use_cost_map (void)
{
  unsigned i, n_imp = 0, size, j;

  if (!consider_all_candidates)
    {
      for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_candidates); i++)
	{
	  struct iv_cand *cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);
	  if (cand->important)
	    n_imp++;
	}
    }

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      struct iv_use *use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);

      if (consider_all_candidates)
	{
	  size = VARRAY_ACTIVE_SIZE (iv_candidates);
	  use->n_map_members = size;
	}
      else
	{
	  size = n_imp;
	  EXECUTE_IF_SET_IN_BITMAP (use->related_cands, 0, j, size++);
	  use->n_map_members = 0;
	}

      use->cost_map = xcalloc (size, sizeof (struct cost_pair));
    }
}

/* Sets cost of (USE, CANDIDATE) pair to COST.  */

static void
set_use_iv_cost (struct iv_use *use, struct iv_cand *cand, unsigned cost)
{
  if (cost < use->best_cost)
    use->best_cost = cost;

  if (consider_all_candidates)
    {
      use->cost_map[cand->id].cand = cand;
      use->cost_map[cand->id].cost = cost;
      return;
    }

  if (cost == INFTY)
    return;

  use->cost_map[use->n_map_members].cand = cand;
  use->cost_map[use->n_map_members].cost = cost;
  use->n_map_members++;
}

/* Gets cost of (USE, CANDIDATE) pair.  */

static int
get_use_iv_cost (struct iv_use *use, struct iv_cand *cand)
{
  unsigned i;

  if (!cand)
    return INFTY;

  if (consider_all_candidates)
    return use->cost_map[cand->id].cost;

  for (i = 0; i < use->n_map_members; i++)
    if (use->cost_map[i].cand != cand)
      break;

  if (i == use->n_map_members)
    return INFTY;

  return use->cost_map[i].cost;
}

/* Returns estimate on cost of computing SEQ.  */

static unsigned
seq_cost (rtx seq)
{
  unsigned cost = 0;
  rtx set;

  for (; seq; seq = NEXT_INSN (seq))
    {
      set = single_set (seq);
      if (set)
	cost += rtx_cost (set, SET);
      else
	cost++;
    }

  return cost;
}

/* Prepares decl_rtl for variables referred in *EXPR_P.  Callback for
   walk_tree.  DATA contains the actual fake register number.  */

static tree
prepare_decl_rtl (tree *expr_p, int *ws, void *data)
{
  tree obj = NULL_TREE;
  rtx x = NULL_RTX;
  int *regno = data;

  switch (TREE_CODE (*expr_p))
    {
    case SSA_NAME:
      *ws = 0;
      obj = SSA_NAME_VAR (*expr_p);
      if (!DECL_RTL_SET_P (obj))
	x = gen_raw_REG (DECL_MODE (obj), (*regno)++);
      break;

    case VAR_DECL:
    case PARM_DECL:
      *ws = 0;
      obj = *expr_p;

      if (DECL_RTL_SET_P (obj))
	break;

      if (DECL_MODE (obj) == BLKmode)
	{
	  if (TREE_STATIC (obj)
	      || DECL_EXTERNAL (obj))
	    {
	      const char *name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (obj));
	      x = gen_rtx_SYMBOL_REF (Pmode, name);
	    }
	  else
	    x = gen_raw_REG (Pmode, (*regno)++);

	  x = gen_rtx_MEM (DECL_MODE (obj), x);
	}
      else
	x = gen_raw_REG (DECL_MODE (obj), (*regno)++);

      break;

    default:
      break;
    }

  if (x)
    {
      VARRAY_PUSH_GENERIC_PTR_NOGC (decl_rtl_to_reset, obj);
      SET_DECL_RTL (obj, x);
    }

  return NULL_TREE;
}

/* Determines cost of the computation of EXPR.  FIXME -- we waste lots of memory
   on temporary expressions here.  We should cache the results somehow.  Also
   the hacks we need to do around to make expand_expr work are disgusting.  */

static unsigned
computation_cost (tree expr)
{
  rtx seq, rslt;
  tree type = TREE_TYPE (expr);
  unsigned cost;
  int regno = 0;

  walk_tree (&expr, prepare_decl_rtl, &regno, NULL);
  start_sequence ();
  rslt = expand_expr (expr, NULL_RTX, TYPE_MODE (type), EXPAND_NORMAL);
  seq = get_insns ();
  end_sequence ();

  cost = seq_cost (seq);
  if (GET_CODE (rslt) == MEM)
    cost += address_cost (XEXP (rslt, 0), TYPE_MODE (type));

  return cost;
}

/* Determines the expression by that USE is expressed from induction variable
   CAND.  */

static tree
get_computation (struct iv_use *use, struct iv_cand *cand)
{
  tree ubase = use->iv->base, ustep = use->iv->step;
  tree cbase = cand->iv->base, cstep = cand->iv->step;
  tree utype = TREE_TYPE (ubase), ctype = TREE_TYPE (cbase);
  tree expr;
  tree ustype = TREE_TYPE (ustep);
  tree ratio;

  switch (cand->pos)
    {
    case IP_START:
      expr = cand->var_after;
      break;

    case IP_NORMAL:
      if (stmt_after_ip_normal_pos (use->stmt))
	expr = cand->var_after;
      else
	expr = cand->var_before;
      break;

    case IP_END:
      expr = cand->var_before;
      break;

    default:
      abort ();
    }

  if (TYPE_PRECISION (utype) > TYPE_PRECISION (ctype))
    {
      /* We do not have a precision to express the values of use.  */
      return NULL_TREE;
    }

  if (utype != ctype)
    {
      expr = convert (utype, expr);
      cbase = convert (utype, cbase);
      cstep = convert (ustype, cstep);
    }

  if (!integer_zerop (EXEC_BINARY (TRUNC_MOD_EXPR, ustype, ustep, cstep)))
    {
      /* TODO maybe consider case when ustep divides cstep and the ratio is
	 a power of 2 (so that the division is fast to execute)?  */
      return NULL_TREE;
    }
  ratio = EXEC_BINARY (EXACT_DIV_EXPR, ustype, ustep, cstep);

  /* If we are after the "normal" position, the value of the candidate is
     higher by one iteration.  */
  if (cand->pos == IP_NORMAL
      && stmt_after_ip_normal_pos (use->stmt))
    cbase = fold (build (PLUS_EXPR, utype, cbase, cstep));

  /* use = ubase + ratio * (var - cbase)  */
  expr = fold (build (PLUS_EXPR, utype,
		      ubase,
		      fold (build (MULT_EXPR, ustype,
				   ratio,
				   fold (build (MINUS_EXPR, utype,
						expr, cbase))))));

  return expr;
}

/* Determines cost of basing replacement of USE on CAND in a generic
   expression.  */

static void
determine_use_iv_cost_generic (struct iv_use *use, struct iv_cand *cand)
{
  tree expr = get_computation (use, cand);

  if (!expr)
    {
      set_use_iv_cost (use, cand, INFTY);
      return;
    }

  set_use_iv_cost (use, cand, computation_cost (expr));
}

/* Determines cost of basing replacement of USE on CAND in an address.  */

static void
determine_use_iv_cost_address (struct iv_use *use, struct iv_cand *cand)
{
  tree expr = get_computation (use, cand);

  if (!expr)
    {
      set_use_iv_cost (use, cand, INFTY);
      return;
    }

  expr = build1 (INDIRECT_REF, TREE_TYPE (TREE_TYPE (expr)), expr);
  set_use_iv_cost (use, cand, computation_cost (expr));
}

/* Determines cost of basing replacement of USE on CAND in a condition.  */

static void
determine_use_iv_cost_condition (struct iv_use *use, struct iv_cand *cand)
{
  /* TODO implement induction variable elimination.  */
  determine_use_iv_cost_generic (use, cand);
}

/* Determines cost of basing replacement of USE on CAND.  */

static void
determine_use_iv_cost (struct iv_use *use, struct iv_cand *cand)
{
  switch (use->type)
    {
    case USE_NONLINEAR_EXPR:
      determine_use_iv_cost_generic (use, cand);
      break;

    case USE_ADDRESS:
      determine_use_iv_cost_address (use, cand);
      break;

    case USE_COMPARE:
      determine_use_iv_cost_condition (use, cand);
      break;
    }
}

/* Determines costs of basing the use of the iv on an iv candidate.  */

static void
determine_use_iv_costs (void)
{
  unsigned i, j;
  struct iv_use *use;
  struct iv_cand *cand;

  consider_all_candidates = (VARRAY_ACTIVE_SIZE (iv_candidates)
			     <= CONSIDER_ALL_CANDIDATES_BOUND);

  alloc_use_cost_map ();

  if (!consider_all_candidates)
    {
      /* Add the important candidate entries.  */
      for (j = 0; j < VARRAY_ACTIVE_SIZE (iv_candidates); j++)
	{
	  cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, j);
	  if (!cand->important)
	    continue;
	  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
	    {
	      use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);
	      determine_use_iv_cost (use, cand);
	    }
	}
    }

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);

      if (consider_all_candidates)
	{
	  for (j = 0; j < VARRAY_ACTIVE_SIZE (iv_candidates); j++)
	    {
	      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, j);
	      determine_use_iv_cost (use, cand);
	    }
	}
      else
	{
	  EXECUTE_IF_SET_IN_BITMAP (use->related_cands, 0, j,
	    {
	      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, j);
	      if (!cand->important)
	        determine_use_iv_cost (use, cand);
	    });
	}
    }

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "Use-candidate costs:\n");

      for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
	{
	  use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);

	  fprintf (tree_dump_file, "Use %d:\n", i);
	  fprintf (tree_dump_file, "  cand\tcost\n");
	  for (j = 0; j < use->n_map_members; j++)
	    {
	      if (use->cost_map[j].cand
		  && use->cost_map[j].cost != INFTY)
		fprintf (tree_dump_file, "  %d\t%d\n",
			 use->cost_map[j].cand->id,
			 use->cost_map[j].cost);
	    }
	  fprintf (tree_dump_file, "\n");
	}
      fprintf (tree_dump_file, "\n");
    }
}

/* Determines cost of the candidate CAND.  */

static void
determine_iv_cost (struct iv_cand *cand)
{
  unsigned cost_base, cost_step;
  tree base = cand->iv->base;
  tree type = TREE_TYPE (base);
  tree ass;

  /* There are two costs associated with the candidate -- its incrementation
     and its initialization.  The second is almost negligible for any loop
     that rolls enough, so we take it just very little into account.  */

  if (cand->pos == IP_START)
    {
      /* We must decrease the base, because it will get increased just at the
	 start of the loop body.  */
      base = fold (build (MINUS_EXPR, type, base, cand->iv->step));
    }

  cost_base = computation_cost (cand->iv->base);
  ass = build (MODIFY_EXPR, void_type_node,
	       cand->var_after,
	       build (PLUS_EXPR, type,
		      cand->var_before, cand->iv->step));
  cost_step = computation_cost (ass);

  /* TODO use profile to determine the ratio here.  */
  cand->cost = cost_step + cost_base / 5;
}

/* Determines costs of computation of the candidates.  */

static void
determine_iv_costs (void)
{
  unsigned i;

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "Candidate costs:\n");
      fprintf (tree_dump_file, "  cand\tcost\n");
    }

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_candidates); i++)
    {
      struct iv_cand *cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);

      determine_iv_cost (cand);

      if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
	fprintf (tree_dump_file, "  %d\t%d\n", i, cand->cost);
    }
  
if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
      fprintf (tree_dump_file, "\n");
}

/* Calculates cost for having SIZE induction variables.  */

static unsigned
global_cost_for_size (unsigned size)
{
  unsigned regs_needed = LOOP_DATA (current_loop)->regs_used + size;
  unsigned cost = 0, n_uses;

  if (regs_needed + res_regs <= avail_regs)
    cost += small_cost * size;
  else if (regs_needed <= avail_regs)
    cost += pres_cost * size;
  else
    {
      cost += pres_cost * size;
      n_uses = VARRAY_ACTIVE_SIZE (iv_uses);
      cost += spill_cost * n_uses * (regs_needed - avail_regs) / regs_needed;
    }

  return cost;
}

/* For each size of the induction variable set determine the penalty.  */

static void
determine_set_costs (void)
{
  unsigned i, j, n;
  tree phi, stmt, op;
  use_optype uses;
  basic_block *body, bb;
  block_stmt_iterator bsi;

  /* We use the following model (definitely improvable, especially the
     cost function -- TODO):

     We estimate the number of registers available (using MD data), name it A.

     We estimate the number of registers used by the loop, name it U.  This
     number is obtained as the number of loop phi nodes (not counting virtual
     registers and bivs) + the number of variables from outside of the loop.

     We set a reserve R (free regs that are used for temporary computations,
     etc.).  For now the reserve a constant 3.

     Let I be the number of induction variables.
     
     -- if U + I + R <= A, the cost is I * SMALL_COST (just not to encourage
	make a lot of ivs without a reason).
     -- if A - R < U + I <= A, the cost is I * PRES_COST
     -- if U + I > A, the cost is I * PRES_COST and
        number of uses * SPILL_COST * (U + I - A) / (U + I) is added.  */

  static bool fst = true;

  if (fst)
    {
      tree var1 = create_tmp_var_raw (integer_type_node, "ivtmp");
      tree var2 = create_tmp_var_raw (integer_type_node, "ivtmp");
      tree var3 = create_tmp_var_raw (integer_ptr_type_node, "ivtmp");

      for (i = 0; i < FIRST_PSEUDO_REGISTER; i++)
	if (GENERAL_REGNO_P (i)
	    && !fixed_regs[i])
	  avail_regs++;

      res_regs = 3;

      /* These are really just heuristic values.  */
      small_cost = computation_cost (build (MODIFY_EXPR, void_type_node,
					    var1, var2));
      pres_cost = 2 * small_cost;
      spill_cost = computation_cost (build (MODIFY_EXPR, void_type_node,
					    build1 (INDIRECT_REF,
						    integer_type_node, var3),
					    var1));
      spill_cost += computation_cost (build (MODIFY_EXPR, void_type_node,
					     var1,
					     build1 (INDIRECT_REF,
						     integer_type_node, var3)));

      fst = false;
    }

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "Global costs:\n");
      fprintf (tree_dump_file, "  avail_regs %d\n", avail_regs);
      fprintf (tree_dump_file, "  small_cost %d\n", small_cost);
      fprintf (tree_dump_file, "  pres_cost %d\n", pres_cost);
      fprintf (tree_dump_file, "  spill_cost %d\n", spill_cost);
    }

  n = 0;
  for (phi = phi_nodes (current_loop->header); phi; phi = TREE_CHAIN (phi))
    {
      op = PHI_RESULT (phi);

      if (!is_gimple_reg (op))
	continue;

      if (get_iv (op))
	continue;

      n++;
    }

  body = get_loop_body (current_loop);
  for (j = 0; j < current_loop->num_nodes; j++)
    for (bsi = bsi_start (body[j]); !bsi_end_p (bsi); bsi_next (&bsi))
      {
	stmt = bsi_stmt (bsi);
	get_stmt_operands (stmt);
	uses = STMT_USE_OPS (stmt);

	for (i = 0; i < NUM_USES (uses); i++)
	  {
	    op = USE_OP (uses, i);

	    bb = bb_for_stmt (SSA_NAME_DEF_STMT (op));
	    if (bb && flow_bb_inside_loop_p (current_loop, bb))
	      continue;

	    n++;
	  }
      }

  LOOP_DATA (current_loop)->regs_used = n;
  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    fprintf (tree_dump_file, "  regs_used %d\n", n);
  free (body);

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "  cost for size:\n");
      fprintf (tree_dump_file, "  ivs\tcost\n");
      for (j = 0; j <= 2 * avail_regs; j++)
	fprintf (tree_dump_file, "  %d\t%d\n", j, global_cost_for_size (j));
      fprintf (tree_dump_file, "\n");
    }
}

/* Finds a best candidate from SET to base the USE on.  */

static struct iv_cand *
find_best_candidate (struct iv_use *use, bitmap set)
{
  unsigned j;
  unsigned bcost = INFTY, acost;
  struct iv_cand *best = NULL, *cand;

  EXECUTE_IF_SET_IN_BITMAP (set, 0, j,
    {
      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, j);
      acost = get_use_iv_cost (use, cand);

      if (acost < bcost)
	{
	  bcost = acost;
	  best = cand;
	}
    });

  return best;
}

/* Computes cost of using the candidates in the SET and stores it into COST.
   It also estimates the maximum possible gain of adding other ivs and stores
   it into DELTA.  The bitmap of used candidates is stored into USED.  */

static void
compute_iv_set_cost (bitmap set, bitmap used, unsigned *cost, unsigned *delta)
{
  unsigned i, acost;
  struct iv_use *use;
  struct iv_cand *cand;
  unsigned size = 0;

  *cost = 0;
  *delta = 0;

  /* First count the costs of uses.  */
  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);
      cand = find_best_candidate (use, set);
      acost = get_use_iv_cost (use, cand);

      if (acost == INFTY)
	{
	  *cost = *delta = INFTY;
	  return;
	}

      bitmap_set_bit (used, cand->id);

      *cost += acost;
      *delta += acost - use->best_cost;
    }

  /* Now add the candidate costs.  */
  EXECUTE_IF_SET_IN_BITMAP (used, 0, i,
    {
      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);
      *cost += cand->cost;
      size++;
    });

  /* And set costs.  */
  *cost += global_cost_for_size (size);
}

/* Find the optimal extension of ACTUAL set of ivs (with cost ACTUAL_COST)
   starting at candidate IV_NUM.  If it is better than *BEST_COST, store it
   into BEST.  */

static void
find_optimal_iv_set_1 (unsigned iv_num, bitmap actual, unsigned actual_cost,
		       bitmap best, unsigned *best_cost)
{
  unsigned cost_with, delta;
  bitmap used_cands;

  if (iv_num == VARRAY_ACTIVE_SIZE (iv_candidates))
    {
      if (actual_cost < *best_cost)
	{
	  bitmap_copy (best, actual);
	  *best_cost = actual_cost;
	}

      return;
    }

  bitmap_set_bit (actual, iv_num);
  used_cands = BITMAP_XMALLOC ();
  compute_iv_set_cost (actual, used_cands, &cost_with, &delta);

  if (cost_with < *best_cost + delta)
    {
      if (cost_with == INFTY)
	find_optimal_iv_set_1 (iv_num + 1, actual, cost_with, best, best_cost);
      else
	{
	  if (cost_with < actual_cost
	      /* If not all candidates are used, there is no point in trying
		 the possibility here.  */
	      && bitmap_equal_p (used_cands, actual))
	    find_optimal_iv_set_1 (iv_num + 1, actual, cost_with,
				   best, best_cost);
	}
    }

  bitmap_clear_bit (actual, iv_num);
  find_optimal_iv_set_1 (iv_num + 1, actual, actual_cost, best, best_cost);
}

/* Attempts to find the optimal set of induction variables.  We do backtracking
   here, trying to add new ivs to the set.  We use the following optimizations
   to make it faster:
   
   1) If adding a variable would make the cost grow, it is not worthwhile
      (this is not true under some weird circumstances, but for any
      practical example it is).
   2) When computing the costs of uses we also compute the minimum cost
      of uses we could reach by choosing the optimal iv as a base for them.
      We use this information to cut the imperspective branches.  */

static bitmap
find_optimal_iv_set (void)
{
  unsigned cost = INFTY;
  bitmap set = BITMAP_XMALLOC ();
  bitmap best = BITMAP_XMALLOC ();

  find_optimal_iv_set_1 (0, set, INFTY, best, &cost);
  BITMAP_XFREE (set);

  if (cost == INFTY)
    {
      if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
	fprintf (tree_dump_file, "Unable to substitute for ivs, failed.\n");
      BITMAP_XFREE (best);
      return NULL;
    }

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "Best set of candidates (cost %d): ", cost);
      dump_bitmap (tree_dump_file, best);
      fprintf (tree_dump_file, "\n");
    }

  return best;
}

/* Creates a new induction variable corresponding to CAND.  */

static void
create_new_iv (struct iv_cand *cand)
{
  block_stmt_iterator incr_pos;
  tree initial, stmt, base, stmts;
  bool after = false;

  switch (cand->pos)
    {
    case IP_START:
      incr_pos = bsi_start (current_loop->header);
      while (!bsi_end_p (incr_pos)
	     && TREE_CODE (bsi_stmt (incr_pos)) == LABEL_EXPR)
	bsi_next (&incr_pos);
      if (bsi_end_p (incr_pos))
	{
	  incr_pos = bsi_last (current_loop->header);
	  after = true;
	}
      break;

    case IP_NORMAL:
      incr_pos = bsi_last (ip_normal_pos ());
      break;

    case IP_END:
      incr_pos = bsi_last (ip_end_pos ());
      after = true;
      break;
    }
 
  gimple_add_tmp_var (cand->var_before);
  add_referenced_tmp_var (cand->var_before);
  cand->var_before = make_ssa_name (cand->var_before, NULL_TREE);
  cand->var_after = make_ssa_name (cand->var_after, NULL_TREE);

  stmt = build (MODIFY_EXPR, void_type_node,
		cand->var_after,
		build (PLUS_EXPR, TREE_TYPE (cand->var_after),
		       cand->var_before,
		       cand->iv->step));
  SSA_NAME_DEF_STMT (cand->var_after) = stmt;
  if (after)
    bsi_insert_after (&incr_pos, stmt, BSI_NEW_STMT);
  else
    bsi_insert_before (&incr_pos, stmt, BSI_NEW_STMT);

  base = unshare_expr (cand->iv->base);
  if (cand->pos == IP_START)
    {
      /* We must decrease the base, because it will get increased just at the
	 start of the loop body.  */
      base = fold (build (MINUS_EXPR, TREE_TYPE (base), base, cand->iv->step));
    }

  initial = force_gimple_operand (base, &stmts,
				  SSA_NAME_VAR (cand->var_before), false);
  if (stmts)
    bsi_insert_on_edge_immediate (loop_preheader_edge (current_loop), stmts);

  stmt = create_phi_node (cand->var_before, current_loop->header);
  SSA_NAME_DEF_STMT (cand->var_before) = stmt;
  add_phi_arg (&stmt, initial, loop_preheader_edge (current_loop));
  add_phi_arg (&stmt, cand->var_after, loop_latch_edge (current_loop));
}

/* Creates new induction variables described in SET.  */

static void
create_new_ivs (bitmap set)
{
  unsigned i;
  struct iv_cand *cand;

  EXECUTE_IF_SET_IN_BITMAP (set, 0, i,
    {
      cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);
      create_new_iv (cand);
    });
}

/* Rewrites USE (definition of iv used in a nonlinear expression)
   using candidate CAND.  */

static void
rewrite_use_nonlinear_expr (struct iv_use *use, struct iv_cand *cand)
{
  tree comp = get_computation (use, cand);
  tree op, stmts;
  block_stmt_iterator bsi;
 
  if (TREE_CODE (use->stmt) == PHI_NODE)
    {
      /* TODO -- handle rewriting of the phi node.  This may only occur when
	 the result of the phi node is used outside of the loop.  */
      return;
    }

  bsi = stmt_bsi (use->stmt);
  op = force_gimple_operand (comp, &stmts,
			     SSA_NAME_VAR (TREE_OPERAND (use->stmt, 0)),
			     false);
  if (stmts)
    bsi_insert_before (&bsi, stmts, BSI_SAME_STMT);
  TREE_OPERAND (use->stmt, 1) = op;
}

/* Rewrites USE (address that is an iv) using candidate CAND.  */

static void
rewrite_use_address (struct iv_use *use, struct iv_cand *cand)
{
  tree comp = get_computation (use, cand);
  block_stmt_iterator bsi = stmt_bsi (use->stmt);
  tree stmts;
  tree op = force_gimple_operand (comp, &stmts, NULL_TREE, false);
  tree var;

  if (stmts)
    bsi_insert_before (&bsi, stmts, BSI_SAME_STMT);

  if (TREE_CODE (op) == SSA_NAME)
    {
      var = get_base_symbol (*use->op_p);

      if (var_ann (var)->mem_tag)
	var = var_ann (var)->mem_tag;

      var_ann (SSA_NAME_VAR (op))->mem_tag = var;
    }

  *use->op_p = build1 (INDIRECT_REF, TREE_TYPE (*use->op_p), op);
}

/* Rewrites USE (the condition such that one of the arguments is an iv) using
   candidate CAND.  */

static void
rewrite_use_compare (struct iv_use *use, struct iv_cand *cand)
{
  tree comp = get_computation (use, cand);
  tree *op_p, cond, op, stmts;
  block_stmt_iterator bsi = stmt_bsi (use->stmt);

  /* TODO -- induction variable elimination.  */

  cond = *use->op_p;
  op_p = &TREE_OPERAND (cond, 0);
  if (TREE_CODE (*op_p) != SSA_NAME
      || zero_p (get_iv (*op_p)->step))
    op_p = &TREE_OPERAND (cond, 1);

  op = force_gimple_operand (comp, &stmts, SSA_NAME_VAR (*op_p), false);
  if (stmts)
    bsi_insert_before (&bsi, stmts, BSI_SAME_STMT);

  *op_p = op;
}

/* Rewrites USE using candidate CAND.  */

static void
rewrite_use (struct iv_use *use, struct iv_cand *cand)
{
  switch (use->type)
    {
      case USE_NONLINEAR_EXPR:
	rewrite_use_nonlinear_expr (use, cand);
	break;

      case USE_ADDRESS:
	rewrite_use_address (use, cand);
	break;

      case USE_COMPARE:
	rewrite_use_compare (use, cand);
	break;
    }
  modify_stmt (use->stmt);
}

/* Rewrite the uses using the induction variables in SET.  */

static void
rewrite_uses (bitmap set)
{
  unsigned i;
  struct iv_cand *cand;
  struct iv_use *use;

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);
      cand = find_best_candidate (use, set);

      rewrite_use (use, cand);
    }
}

/* Frees data allocated by the optimization of a single loop.  */

static void
free_loop_data (void)
{
  unsigned i;

  for (i = 0; i < old_highest_ssa_version; i++)
    if (ivs[i])
      {
	free (ivs[i]);
	ivs[i] = NULL;
      }

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_uses); i++)
    {
      struct iv_use *use = VARRAY_GENERIC_PTR_NOGC (iv_uses, i);

      free (use->iv);
      BITMAP_XFREE (use->related_cands);
      free (use->cost_map);
      free (use);
    }
  VARRAY_POP_ALL (iv_uses);

  for (i = 0; i < VARRAY_ACTIVE_SIZE (iv_candidates); i++)
    {
      struct iv_cand *cand = VARRAY_GENERIC_PTR_NOGC (iv_candidates, i);

      free (cand->iv);
      free (cand);
    }
  VARRAY_POP_ALL (iv_candidates);

  if (old_highest_ssa_version != highest_ssa_version)
    {
      ivs = xrealloc (ivs, sizeof (struct iv *) * highest_ssa_version);
      memset (ivs + old_highest_ssa_version, 0,
	      sizeof (struct iv *)
	      * (highest_ssa_version - old_highest_ssa_version));

      outermost_usage = xrealloc (outermost_usage,
				  sizeof (struct loop *) * highest_ssa_version);
      memset (outermost_usage + old_highest_ssa_version, 0,
	      sizeof (struct loop *)
	      * (highest_ssa_version - old_highest_ssa_version));
    }

  old_highest_ssa_version = highest_ssa_version;
}

/* Finalizes data structures used by the iv optimization pass.  LOOPS is the
   loop tree.  */

static void
tree_ssa_iv_optimize_finalize (struct loops *loops)
{
  unsigned i;
  tree obj;

  for (i = 1; i < loops->num; i++)
    if (loops->parray[i])
      {
	free (loops->parray[i]->aux);
	loops->parray[i]->aux = NULL;
      }

  free_loop_data ();
  free (ivs);
  free (outermost_usage);

  for (i = 0; i < VARRAY_ACTIVE_SIZE (decl_rtl_to_reset); i++)
    {
      obj = VARRAY_GENERIC_PTR_NOGC (decl_rtl_to_reset, i);

      SET_DECL_RTL (obj, NULL_RTX);
    }
  
  VARRAY_FREE (decl_rtl_to_reset);
  VARRAY_FREE (iv_uses);
  VARRAY_FREE (iv_candidates);
}

/* Optimizes the LOOP.  Returns true if anything changed.  */

static bool
tree_ssa_iv_optimize_loop (struct loop *loop)
{
  bool changed = false, pushed_context = false;
  bitmap iv_set;

  current_loop = loop;

  if (tree_dump_file && (tree_dump_flags & TDF_DETAILS))
    {
      fprintf (tree_dump_file, "Processing loop %d\n", loop->num);
      fprintf (tree_dump_file, "  %d exits\n", LOOP_DATA (loop)->n_exits);
      if (LOOP_DATA (loop)->single_exit)
	{
	  edge ex = LOOP_DATA (loop)->single_exit;

	  fprintf (tree_dump_file, "  single exit %d -> %d, exit condition ",
		   ex->src->index, ex->dest->index);
	  print_generic_expr (tree_dump_file, last_stmt (ex->src), TDF_SLIM);
	  fprintf (tree_dump_file, "\n");
	}
      fprintf (tree_dump_file, "\n");
    }

  /* For each ssa name determines whether it behaves as an induction variable
     in some loop.  */
  if (!find_induction_variables ())
    goto finish;

  ggc_push_context ();
  pushed_context = true;

  /* Finds interesting uses (item 1).  */
  find_interesting_uses ();

  /* Finds candidates for the induction variables (item 2).  */
  find_iv_candidates ();

  /* Calculates the costs (item 3, part 1).  */
  determine_use_iv_costs ();
  determine_iv_costs ();
  determine_set_costs ();

  /* Find the optimal set of induction variables (item 3, part 2).  */
  iv_set = find_optimal_iv_set ();
  if (!iv_set)
    goto finish;
  changed = true;

  /* Create the new induction variables (item 4, part 1).  */
  create_new_ivs (iv_set);
  
  /* Rewrite the uses (item 4, part 2).  */
  rewrite_uses (iv_set);

  BITMAP_XFREE (iv_set);
finish:
  free_loop_data ();

  if (pushed_context)
    {
      ggc_collect ();
      ggc_pop_context ();
    }
  return changed;
}

/* Main entry point.  Optimizes induction variables in LOOPS.  */

void
tree_ssa_iv_optimize (struct loops *loops)
{
  bool run_dce = false;
  struct loop *loop;

  tree_ssa_iv_optimize_init (loops);

  /* Optimize the loops starting with the innermost ones.  */
  loop = loops->tree_root;
  while (loop->inner)
    loop = loop->inner;

  /* Scan the loops, inner ones first.  */
  while (loop != loops->tree_root)
    {
      run_dce |= tree_ssa_iv_optimize_loop (loop);

      if (loop->next)
	{
	  loop = loop->next;
	  while (loop->inner)
	    loop = loop->inner;
	}
      else
	loop = loop->outer;
    }

  tree_ssa_iv_optimize_finalize (loops);

  /* Cleanup the now unused variables.  */
  if (run_dce)
    tree_ssa_dce_no_cfg_changes ();
}
