/* Tree lowering pass.  Lowers GIMPLE into unstructured form.

   Copyright (C) 2003 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "errors.h"
#include "varray.h"
#include "tree-simple.h"
#include "tree-inline.h"
#include "diagnostic.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "tree-flow.h"
#include "timevar.h"
#include "except.h"
#include "hashtab.h"
#include "flags.h"
#include "function.h"
#include "expr.h"
#include "toplev.h"

struct lower_data
{
  /* Block the current statement belongs to.  */
  tree block;
};

static void lower_stmt_body (tree *, struct lower_data *);
static void lower_stmt (tree_stmt_iterator *, struct lower_data *);
static void lower_bind_expr (tree_stmt_iterator *, struct lower_data *);
static void lower_cond_expr (tree_stmt_iterator *, struct lower_data *);

/* Lowers the BODY.  */
void
lower_function_body (tree *body)
{
  struct lower_data data;
  tree root;

  if (TREE_CODE (*body) != BIND_EXPR)
    abort ();

  data.block = DECL_INITIAL (current_function_decl);
  BLOCK_SUBBLOCKS (data.block) = NULL_TREE;
  BLOCK_CHAIN (data.block) = NULL_TREE;

  record_vars (BIND_EXPR_VARS (*body));
  root = BIND_EXPR_BODY (*body);
  lower_stmt_body (&root, &data);

  if (data.block != DECL_INITIAL (current_function_decl))
    abort ();
  BLOCK_SUBBLOCKS (data.block) =
	  blocks_nreverse (BLOCK_SUBBLOCKS (data.block));

  *body = root;
}

/* Lowers the EXPR.  Unlike gimplification the statements are not relowered
   when they are changed -- if this has to be done, the lowering routine must
   do it explicitly.  DATA is passed through the recursion.  */

static void
lower_stmt_body (tree *expr, struct lower_data *data)
{
  tree_stmt_iterator tsi;

  for (tsi = tsi_start (expr); !tsi_end_p (tsi); )
    lower_stmt (&tsi, data);
}

/* Lowers statement TSI.  DATA is passed through the recursion.  */
static void
lower_stmt (tree_stmt_iterator *tsi, struct lower_data *data)
{
  tree stmt = tsi_stmt (*tsi);

  if (EXPR_LOCUS (stmt))
    TREE_BLOCK (stmt) = data->block;

  switch (TREE_CODE (stmt))
    {
    case BIND_EXPR:
      lower_bind_expr (tsi, data);
      /* Avoid moving the tsi -- it has already been moved by delinking the
	 statement.  */
      return;

    case COMPOUND_EXPR:
      abort ();

    case NOP_EXPR:
    case ASM_EXPR:
    case RETURN_EXPR:
    case MODIFY_EXPR:
    case CALL_EXPR:
    case GOTO_EXPR:
    case LABEL_EXPR:
    case VA_ARG_EXPR:
    case RESX_EXPR:
    case SWITCH_EXPR:
      break;

    case COND_EXPR:
      lower_cond_expr (tsi, data);
      break;

    default:
      print_node_brief (stderr, "", tsi_stmt (*tsi), 0);
      abort ();
    }

  tsi_next (tsi);
}

/* Record the variables in VARS.  */

void
record_vars (tree vars)
{
  for (; vars; vars = TREE_CHAIN (vars))
    {
      tree var = vars;

      /* Nothing to do in this case.  */
      if (DECL_EXTERNAL (var))
	continue;

      /* Record the variable.  */
      cfun->unexpanded_var_list = tree_cons (NULL_TREE, var,
					     cfun->unexpanded_var_list);
    }
}

/* Lowers a bind_expr TSI.  DATA is passed through the recursion.  */

static void
lower_bind_expr (tree_stmt_iterator *tsi, struct lower_data *data)
{
  tree old_block = data->block;
  tree stmt = tsi_stmt (*tsi);

  if (BIND_EXPR_BLOCK (stmt))
    {
      data->block = BIND_EXPR_BLOCK (stmt);

      /* Block tree may get clobbered by inlining.  Normally this would be
	 fixed in rest_of_decl_compilation using block notes, but since we
	 are not going to emit them, it is up to us.  */
      BLOCK_CHAIN (data->block) = BLOCK_SUBBLOCKS (old_block);
      BLOCK_SUBBLOCKS (old_block) = data->block;
      BLOCK_SUBBLOCKS (data->block) = NULL_TREE;
      BLOCK_SUPERCONTEXT (data->block) = old_block;
    }

  record_vars (BIND_EXPR_VARS (stmt));
  lower_stmt_body (&BIND_EXPR_BODY (stmt), data);

  if (BIND_EXPR_BLOCK (stmt))
    {
      if (data->block != BIND_EXPR_BLOCK (stmt))
	abort ();

      BLOCK_SUBBLOCKS (data->block) =
	      blocks_nreverse (BLOCK_SUBBLOCKS (data->block));
      data->block = old_block;
    }

  /* The BIND_EXPR no longer carries any useful information, so get rid
     of it.  */
  tsi_link_chain_before (tsi, BIND_EXPR_BODY (stmt), TSI_SAME_STMT);
  tsi_delink (tsi);
}

/* Lowers a cond_expr TSI.  DATA is passed through the recursion.  */

static void
lower_cond_expr (tree_stmt_iterator *tsi, struct lower_data *data)
{
  tree stmt = tsi_stmt (*tsi);
  bool then_is_goto, else_is_goto;
  tree then_branch, else_branch, then_label, else_label, end_label;
  
  lower_stmt_body (&COND_EXPR_THEN (stmt), data);
  lower_stmt_body (&COND_EXPR_ELSE (stmt), data);

  /* Find out whether the branches are ordinary local gotos.  */
  then_branch = COND_EXPR_THEN (stmt);
  else_branch = COND_EXPR_ELSE (stmt);

  then_is_goto = simple_goto_p (then_branch);
  else_is_goto = simple_goto_p (else_branch);

  if (then_is_goto && else_is_goto)
    return;
 
  /* Replace the cond_expr with explicit gotos.  */
  if (!then_is_goto)
    {
      then_label = build1 (LABEL_EXPR, void_type_node, NULL_TREE);
      COND_EXPR_THEN (stmt) = build_and_jump (&LABEL_EXPR_LABEL (then_label));
    }
  else
    then_label = NULL_TREE;

  if (!else_is_goto)
    {
      else_label = build1 (LABEL_EXPR, void_type_node, NULL_TREE);
      COND_EXPR_ELSE (stmt) = build_and_jump (&LABEL_EXPR_LABEL (else_label));
    }
  else
    else_label = NULL_TREE;

  end_label = NULL_TREE;
  if (then_label)
    {
      tsi_link_after (tsi, then_label, TSI_CONTINUE_LINKING);
      tsi_link_chain_after (tsi, then_branch, TSI_CONTINUE_LINKING);
  
      if (else_label)
	{
	  end_label = build1 (LABEL_EXPR, void_type_node, NULL_TREE);
	  tsi_link_after (tsi, build_and_jump (&LABEL_EXPR_LABEL (end_label)),
			  TSI_CONTINUE_LINKING);
	}
    }
  
  if (else_label)
    {
      tsi_link_after (tsi, else_label, TSI_CONTINUE_LINKING);
      tsi_link_chain_after (tsi, else_branch, TSI_CONTINUE_LINKING);
    }

  if (end_label)
    tsi_link_after (tsi, end_label, TSI_CONTINUE_LINKING);
}

/* Expand those variables in the unexpanded_var_list that are used.  */

void
expand_used_vars (void)
{
  tree var, cell;

  cfun->unexpanded_var_list = nreverse (cfun->unexpanded_var_list);

  for (cell = cfun->unexpanded_var_list; cell; cell = TREE_CHAIN (cell))
    {
      var = TREE_VALUE (cell);

      if (TREE_CODE (var) == VAR_DECL)
	{
	  struct var_ann_d *ann = var_ann (var);

	  /* Remove all unused, unaliased temporaries.  Also remove
	     unused, unaliased local variables during highly
	     optimizing compilations.  */
	  ann = var_ann (var);
	  if (ann
	      && ! ann->may_aliases
	      && ! ann->used
	      && ! ann->has_hidden_use
	      && ! TREE_ADDRESSABLE (var)
	      && (DECL_ARTIFICIAL (var) || optimize >= 2))
	    continue;
	}

      expand_var (var);
    }

  cfun->unexpanded_var_list = NULL_TREE;
}
