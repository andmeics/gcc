/* Convert a program in SSA form into Normal form.
   Copyright (C) 2004, 2005, 2006, 2007 Free Software Foundation, Inc.
   Contributed by Andrew Macleod <amacleod@redhat.com>

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
#include "ggc.h"
#include "basic-block.h"
#include "diagnostic.h"
#include "bitmap.h"
#include "tree-flow.h"
#include "timevar.h"
#include "tree-dump.h"
#include "tree-ssa-live.h"
#include "tree-pass.h"
#include "toplev.h"
#include "langhooks.h"


/* Used to hold all the components required to do SSA PHI elimination.
   The node and pred/succ list is a simple linear list of nodes and
   edges represented as pairs of nodes.

   The predecessor and successor list:  Nodes are entered in pairs, where
   [0] ->PRED, [1]->SUCC.  All the even indexes in the array represent 
   predecessors, all the odd elements are successors. 
   
   Rationale:
   When implemented as bitmaps, very large programs SSA->Normal times were 
   being dominated by clearing the interference graph.

   Typically this list of edges is extremely small since it only includes 
   PHI results and uses from a single edge which have not coalesced with 
   each other.  This means that no virtual PHI nodes are included, and
   empirical evidence suggests that the number of edges rarely exceed
   3, and in a bootstrap of GCC, the maximum size encountered was 7.
   This also limits the number of possible nodes that are involved to
   rarely more than 6, and in the bootstrap of gcc, the maximum number
   of nodes encountered was 12.  */
 
typedef struct _elim_graph {
  /* Size of the elimination vectors.  */
  int size;

  /* List of nodes in the elimination graph.  */
  VEC(tree,heap) *nodes;

  /*  The predecessor and successor edge list.  */
  VEC(int,heap) *edge_list;

  /* Visited vector.  */
  sbitmap visited;

  /* Stack for visited nodes.  */
  VEC(int,heap) *stack;
  
  /* The variable partition map.  */
  var_map map;

  /* Edge being eliminated by this graph.  */
  edge e;

  /* List of constant copies to emit.  These are pushed on in pairs.  */
  VEC(tree,heap) *const_copies;
} *elim_graph;


/* Create a temporary variable based on the type of variable T.  Use T's name
   as the prefix.  */

static tree
create_temp (tree t)
{
  tree tmp;
  const char *name = NULL;
  tree type;

  if (TREE_CODE (t) == SSA_NAME)
    t = SSA_NAME_VAR (t);

  gcc_assert (TREE_CODE (t) == VAR_DECL || TREE_CODE (t) == PARM_DECL);

  type = TREE_TYPE (t);
  tmp = DECL_NAME (t);
  if (tmp)
    name = IDENTIFIER_POINTER (tmp);

  if (name == NULL)
    name = "temp";
  tmp = create_tmp_var (type, name);

  if (DECL_DEBUG_EXPR_IS_FROM (t) && DECL_DEBUG_EXPR (t))
    {
      SET_DECL_DEBUG_EXPR (tmp, DECL_DEBUG_EXPR (t));  
      DECL_DEBUG_EXPR_IS_FROM (tmp) = 1;
    }
  else if (!DECL_IGNORED_P (t))
    {
      SET_DECL_DEBUG_EXPR (tmp, t);
      DECL_DEBUG_EXPR_IS_FROM (tmp) = 1;
    }
  DECL_ARTIFICIAL (tmp) = DECL_ARTIFICIAL (t);
  DECL_IGNORED_P (tmp) = DECL_IGNORED_P (t);
  add_referenced_var (tmp);

  /* add_referenced_var will create the annotation and set up some
     of the flags in the annotation.  However, some flags we need to
     inherit from our original variable.  */
  set_symbol_mem_tag (tmp, symbol_mem_tag (t));
  if (is_call_clobbered (t))
    mark_call_clobbered (tmp, var_ann (t)->escape_mask);

  return tmp;
}


/* This helper function fill insert a copy from a constant or variable SRC to 
   variable DEST on edge E.  */

static void
insert_copy_on_edge (edge e, tree dest, tree src)
{
  tree copy;

  copy = build_gimple_modify_stmt (dest, src);
  set_is_used (dest);

  if (TREE_CODE (src) == ADDR_EXPR)
    src = TREE_OPERAND (src, 0);
  if (TREE_CODE (src) == VAR_DECL || TREE_CODE (src) == PARM_DECL)
    set_is_used (src);

  if (dump_file && (dump_flags & TDF_DETAILS))
    {
      fprintf (dump_file,
	       "Inserting a copy on edge BB%d->BB%d :",
	       e->src->index,
	       e->dest->index);
      print_generic_expr (dump_file, copy, dump_flags);
      fprintf (dump_file, "\n");
    }

  bsi_insert_on_edge (e, copy);
}


/* Create an elimination graph with SIZE nodes and associated data
   structures.  */

static elim_graph
new_elim_graph (int size)
{
  elim_graph g = (elim_graph) xmalloc (sizeof (struct _elim_graph));

  g->nodes = VEC_alloc (tree, heap, 30);
  g->const_copies = VEC_alloc (tree, heap, 20);
  g->edge_list = VEC_alloc (int, heap, 20);
  g->stack = VEC_alloc (int, heap, 30);
  
  g->visited = sbitmap_alloc (size);

  return g;
}


/* Empty elimination graph G.  */

static inline void
clear_elim_graph (elim_graph g)
{
  VEC_truncate (tree, g->nodes, 0);
  VEC_truncate (int, g->edge_list, 0);
}


/* Delete elimination graph G.  */

static inline void
delete_elim_graph (elim_graph g)
{
  sbitmap_free (g->visited);
  VEC_free (int, heap, g->stack);
  VEC_free (int, heap, g->edge_list);
  VEC_free (tree, heap, g->const_copies);
  VEC_free (tree, heap, g->nodes);
  free (g);
}


/* Return the number of nodes in graph G.  */

static inline int
elim_graph_size (elim_graph g)
{
  return VEC_length (tree, g->nodes);
}


/* Add NODE to graph G, if it doesn't exist already.  */

static inline void 
elim_graph_add_node (elim_graph g, tree node)
{
  int x;
  tree t;

  for (x = 0; VEC_iterate (tree, g->nodes, x, t); x++)
    if (t == node)
      return;
  VEC_safe_push (tree, heap, g->nodes, node);
}


/* Add the edge PRED->SUCC to graph G.  */

static inline void
elim_graph_add_edge (elim_graph g, int pred, int succ)
{
  VEC_safe_push (int, heap, g->edge_list, pred);
  VEC_safe_push (int, heap, g->edge_list, succ);
}


/* Remove an edge from graph G for which NODE is the predecessor, and
   return the successor node.  -1 is returned if there is no such edge.  */

static inline int
elim_graph_remove_succ_edge (elim_graph g, int node)
{
  int y;
  unsigned x;
  for (x = 0; x < VEC_length (int, g->edge_list); x += 2)
    if (VEC_index (int, g->edge_list, x) == node)
      {
        VEC_replace (int, g->edge_list, x, -1);
	y = VEC_index (int, g->edge_list, x + 1);
	VEC_replace (int, g->edge_list, x + 1, -1);
	return y;
      }
  return -1;
}


/* Find all the nodes in GRAPH which are successors to NODE in the
   edge list.  VAR will hold the partition number found.  CODE is the
   code fragment executed for every node found.  */

#define FOR_EACH_ELIM_GRAPH_SUCC(GRAPH, NODE, VAR, CODE)		\
do {									\
  unsigned x_;								\
  int y_;								\
  for (x_ = 0; x_ < VEC_length (int, (GRAPH)->edge_list); x_ += 2)	\
    {									\
      y_ = VEC_index (int, (GRAPH)->edge_list, x_);			\
      if (y_ != (NODE))							\
        continue;							\
      (VAR) = VEC_index (int, (GRAPH)->edge_list, x_ + 1);		\
      CODE;								\
    }									\
} while (0)


/* Find all the nodes which are predecessors of NODE in the edge list for
   GRAPH.  VAR will hold the partition number found.  CODE is the
   code fragment executed for every node found.  */

#define FOR_EACH_ELIM_GRAPH_PRED(GRAPH, NODE, VAR, CODE)		\
do {									\
  unsigned x_;								\
  int y_;								\
  for (x_ = 0; x_ < VEC_length (int, (GRAPH)->edge_list); x_ += 2)	\
    {									\
      y_ = VEC_index (int, (GRAPH)->edge_list, x_ + 1);			\
      if (y_ != (NODE))							\
        continue;							\
      (VAR) = VEC_index (int, (GRAPH)->edge_list, x_);			\
      CODE;								\
    }									\
} while (0)


/* Add T to elimination graph G.  */

static inline void
eliminate_name (elim_graph g, tree T)
{
  elim_graph_add_node (g, T);
}


/* Build elimination graph G for basic block BB on incoming PHI edge
   G->e.  */

static void
eliminate_build (elim_graph g, basic_block B)
{
  tree phi;
  tree T0, Ti;
  int p0, pi;

  clear_elim_graph (g);
  
  for (phi = phi_nodes (B); phi; phi = PHI_CHAIN (phi))
    {
      T0 = var_to_partition_to_var (g->map, PHI_RESULT (phi));
      
      /* Ignore results which are not in partitions.  */
      if (T0 == NULL_TREE)
	continue;

      Ti = PHI_ARG_DEF (phi, g->e->dest_idx);

      /* If this argument is a constant, or a SSA_NAME which is being
	 left in SSA form, just queue a copy to be emitted on this
	 edge.  */
      if (!phi_ssa_name_p (Ti)
	  || (TREE_CODE (Ti) == SSA_NAME
	      && var_to_partition (g->map, Ti) == NO_PARTITION))
        {
	  /* Save constant copies until all other copies have been emitted
	     on this edge.  */
	  VEC_safe_push (tree, heap, g->const_copies, T0);
	  VEC_safe_push (tree, heap, g->const_copies, Ti);
	}
      else
        {
	  Ti = var_to_partition_to_var (g->map, Ti);
	  if (T0 != Ti)
	    {
	      eliminate_name (g, T0);
	      eliminate_name (g, Ti);
	      p0 = var_to_partition (g->map, T0);
	      pi = var_to_partition (g->map, Ti);
	      elim_graph_add_edge (g, p0, pi);
	    }
	}
    }
}


/* Push successors of T onto the elimination stack for G.  */

static void 
elim_forward (elim_graph g, int T)
{
  int S;
  SET_BIT (g->visited, T);
  FOR_EACH_ELIM_GRAPH_SUCC (g, T, S,
    {
      if (!TEST_BIT (g->visited, S))
        elim_forward (g, S);
    });
  VEC_safe_push (int, heap, g->stack, T);
}


/* Return 1 if there unvisited predecessors of T in graph G.  */

static int
elim_unvisited_predecessor (elim_graph g, int T)
{
  int P;
  FOR_EACH_ELIM_GRAPH_PRED (g, T, P, 
    {
      if (!TEST_BIT (g->visited, P))
        return 1;
    });
  return 0;
}

/* Process predecessors first, and insert a copy.  */

static void
elim_backward (elim_graph g, int T)
{
  int P;
  SET_BIT (g->visited, T);
  FOR_EACH_ELIM_GRAPH_PRED (g, T, P, 
    {
      if (!TEST_BIT (g->visited, P))
        {
	  elim_backward (g, P);
	  insert_copy_on_edge (g->e, 
			       partition_to_var (g->map, P), 
			       partition_to_var (g->map, T));
	}
    });
}

/* Insert required copies for T in graph G.  Check for a strongly connected 
   region, and create a temporary to break the cycle if one is found.  */

static void 
elim_create (elim_graph g, int T)
{
  tree U;
  int P, S;

  if (elim_unvisited_predecessor (g, T))
    {
      U = create_temp (partition_to_var (g->map, T));
      insert_copy_on_edge (g->e, U, partition_to_var (g->map, T));
      FOR_EACH_ELIM_GRAPH_PRED (g, T, P, 
	{
	  if (!TEST_BIT (g->visited, P))
	    {
	      elim_backward (g, P);
	      insert_copy_on_edge (g->e, partition_to_var (g->map, P), U);
	    }
	});
    }
  else
    {
      S = elim_graph_remove_succ_edge (g, T);
      if (S != -1)
	{
	  SET_BIT (g->visited, T);
	  insert_copy_on_edge (g->e, 
			       partition_to_var (g->map, T), 
			       partition_to_var (g->map, S));
	}
    }
  
}


/* Eliminate all the phi nodes on edge E in graph G.  */

static void
eliminate_phi (edge e, elim_graph g)
{
  int x;
  basic_block B = e->dest;

  gcc_assert (VEC_length (tree, g->const_copies) == 0);

  /* Abnormal edges already have everything coalesced.  */
  if (e->flags & EDGE_ABNORMAL)
    return;

  g->e = e;

  eliminate_build (g, B);

  if (elim_graph_size (g) != 0)
    {
      tree var;

      sbitmap_zero (g->visited);
      VEC_truncate (int, g->stack, 0);

      for (x = 0; VEC_iterate (tree, g->nodes, x, var); x++)
        {
	  int p = var_to_partition (g->map, var);
	  if (!TEST_BIT (g->visited, p))
	    elim_forward (g, p);
	}
       
      sbitmap_zero (g->visited);
      while (VEC_length (int, g->stack) > 0)
	{
	  x = VEC_pop (int, g->stack);
	  if (!TEST_BIT (g->visited, x))
	    elim_create (g, x);
	}
    }

  /* If there are any pending constant copies, issue them now.  */
  while (VEC_length (tree, g->const_copies) > 0)
    {
      tree src, dest;
      src = VEC_pop (tree, g->const_copies);
      dest = VEC_pop (tree, g->const_copies);
      insert_copy_on_edge (e, dest, src);
    }
}


/* Take the ssa-name var_map MAP, and assign real variables to each 
   partition.  */

static void
assign_vars (var_map map)
{
  int x, num;
  tree var, root;
  var_ann_t ann;

  num = num_var_partitions (map);
  for (x = 0; x < num; x++)
    {
      var = partition_to_var (map, x);
      if (TREE_CODE (var) != SSA_NAME)
	{
	  ann = var_ann (var);
	  /* It must already be coalesced.  */
	  gcc_assert (ann->out_of_ssa_tag == 1);
	  if (dump_file && (dump_flags & TDF_DETAILS))
	    {
	      fprintf (dump_file, "partition %d already has variable ", x);
	      print_generic_expr (dump_file, var, TDF_SLIM);
	      fprintf (dump_file, " assigned to it.\n");
	    }
	}
      else
        {
	  root = SSA_NAME_VAR (var);
	  ann = var_ann (root);
	  /* If ROOT is already associated, create a new one.  */
	  if (ann->out_of_ssa_tag)
	    {
	      root = create_temp (root);
	      ann = var_ann (root);
	    }
	  /* ROOT has not been coalesced yet, so use it.  */
	  if (dump_file && (dump_flags & TDF_DETAILS))
	    {
	      fprintf (dump_file, "Partition %d is assigned to var ", x);
	      print_generic_stmt (dump_file, root, TDF_SLIM);
	    }
	  change_partition_var (map, root, x);
	}
    }
}


/* Replace use operand P with whatever variable it has been rewritten to based 
   on the partitions in MAP.  EXPR is an optional expression vector over SSA 
   versions which is used to replace P with an expression instead of a variable.
   If the stmt is changed, return true.  */ 

static inline bool
replace_use_variable (var_map map, use_operand_p p, tree *expr)
{
  tree new_var;
  tree var = USE_FROM_PTR (p);

  /* Check if we are replacing this variable with an expression.  */
  if (expr)
    {
      int version = SSA_NAME_VERSION (var);
      if (expr[version])
        {
	  tree new_expr = GIMPLE_STMT_OPERAND (expr[version], 1);
	  SET_USE (p, new_expr);

	  /* Clear the stmt's RHS, or GC might bite us.  */
	  GIMPLE_STMT_OPERAND (expr[version], 1) = NULL_TREE;
	  return true;
	}
    }

  new_var = var_to_partition_to_var (map, var);
  if (new_var)
    {
      SET_USE (p, new_var);
      set_is_used (new_var);
      return true;
    }
  return false;
}


/* Replace def operand DEF_P with whatever variable it has been rewritten to 
   based on the partitions in MAP.  EXPR is an optional expression vector over
   SSA versions which is used to replace DEF_P with an expression instead of a 
   variable.  If the stmt is changed, return true.  */ 

static inline bool
replace_def_variable (var_map map, def_operand_p def_p, tree *expr)
{
  tree new_var;
  tree var = DEF_FROM_PTR (def_p);

  /* Do nothing if we are replacing this variable with an expression.  */
  if (expr && expr[SSA_NAME_VERSION (var)])
    return true;

  new_var = var_to_partition_to_var (map, var);
  if (new_var)
    {
      SET_DEF (def_p, new_var);
      set_is_used (new_var);
      return true;
    }
  return false;
}


/* Remove any PHI node which is a virtual PHI.  */

static void
eliminate_virtual_phis (void)
{
  basic_block bb;
  tree phi, next;

  FOR_EACH_BB (bb)
    {
      for (phi = phi_nodes (bb); phi; phi = next)
        {
	  next = PHI_CHAIN (phi);
	  if (!is_gimple_reg (SSA_NAME_VAR (PHI_RESULT (phi))))
	    {
#ifdef ENABLE_CHECKING
	      int i;
	      /* There should be no arguments of this PHI which are in
		 the partition list, or we get incorrect results.  */
	      for (i = 0; i < PHI_NUM_ARGS (phi); i++)
	        {
		  tree arg = PHI_ARG_DEF (phi, i);
		  if (TREE_CODE (arg) == SSA_NAME 
		      && is_gimple_reg (SSA_NAME_VAR (arg)))
		    {
		      fprintf (stderr, "Argument of PHI is not virtual (");
		      print_generic_expr (stderr, arg, TDF_SLIM);
		      fprintf (stderr, "), but the result is :");
		      print_generic_stmt (stderr, phi, TDF_SLIM);
		      internal_error ("SSA corruption");
		    }
		}
#endif
	      remove_phi_node (phi, NULL_TREE, true);
	    }
	}
    }
}


/* This function will rewrite the current program using the variable mapping
   found in MAP.  If the replacement vector VALUES is provided, any 
   occurrences of partitions with non-null entries in the vector will be 
   replaced with the expression in the vector instead of its mapped 
   variable.  */

static void
rewrite_trees (var_map map, tree *values)
{
  elim_graph g;
  basic_block bb;
  block_stmt_iterator si;
  edge e;
  tree phi;
  bool changed;
 
#ifdef ENABLE_CHECKING
  /* Search for PHIs where the destination has no partition, but one
     or more arguments has a partition.  This should not happen and can
     create incorrect code.  */
  FOR_EACH_BB (bb)
    {
      tree phi;
      for (phi = phi_nodes (bb); phi; phi = PHI_CHAIN (phi))
	{
	  tree T0 = var_to_partition_to_var (map, PHI_RESULT (phi));
	  if (T0 == NULL_TREE)
	    {
	      int i;
	      for (i = 0; i < PHI_NUM_ARGS (phi); i++)
		{
		  tree arg = PHI_ARG_DEF (phi, i);

		  if (TREE_CODE (arg) == SSA_NAME
		      && var_to_partition (map, arg) != NO_PARTITION)
		    {
		      fprintf (stderr, "Argument of PHI is in a partition :(");
		      print_generic_expr (stderr, arg, TDF_SLIM);
		      fprintf (stderr, "), but the result is not :");
		      print_generic_stmt (stderr, phi, TDF_SLIM);
		      internal_error ("SSA corruption");
		    }
		}
	    }
	}
    }
#endif

  /* Replace PHI nodes with any required copies.  */
  g = new_elim_graph (map->num_partitions);
  g->map = map;
  FOR_EACH_BB (bb)
    {
      for (si = bsi_start (bb); !bsi_end_p (si); )
	{
	  tree stmt = bsi_stmt (si);
	  use_operand_p use_p, copy_use_p;
	  def_operand_p def_p;
	  bool remove = false, is_copy = false;
	  int num_uses = 0;
	  stmt_ann_t ann;
	  ssa_op_iter iter;

	  ann = stmt_ann (stmt);
	  changed = false;

	  if (TREE_CODE (stmt) == GIMPLE_MODIFY_STMT 
	      && (TREE_CODE (GIMPLE_STMT_OPERAND (stmt, 1)) == SSA_NAME))
	    is_copy = true;

	  copy_use_p = NULL_USE_OPERAND_P;
	  FOR_EACH_SSA_USE_OPERAND (use_p, stmt, iter, SSA_OP_USE)
	    {
	      if (replace_use_variable (map, use_p, values))
		changed = true;
	      copy_use_p = use_p;
	      num_uses++;
	    }

	  if (num_uses != 1)
	    is_copy = false;

	  def_p = SINGLE_SSA_DEF_OPERAND (stmt, SSA_OP_DEF);

	  if (def_p != NULL)
	    {
	      /* Mark this stmt for removal if it is the list of replaceable 
		 expressions.  */
	      if (values && values[SSA_NAME_VERSION (DEF_FROM_PTR (def_p))])
		remove = true;
	      else
		{
		  if (replace_def_variable (map, def_p, NULL))
		    changed = true;
		  /* If both SSA_NAMEs coalesce to the same variable,
		     mark the now redundant copy for removal.  */
		  if (is_copy)
		    {
		      gcc_assert (copy_use_p != NULL_USE_OPERAND_P);
		      if (DEF_FROM_PTR (def_p) == USE_FROM_PTR (copy_use_p))
			remove = true;
		    }
		}
	    }
	  else
	    FOR_EACH_SSA_DEF_OPERAND (def_p, stmt, iter, SSA_OP_DEF)
	      if (replace_def_variable (map, def_p, NULL))
		changed = true;

	  /* Remove any stmts marked for removal.  */
	  if (remove)
	    bsi_remove (&si, true);
	  else
	    bsi_next (&si);
	}

      phi = phi_nodes (bb);
      if (phi)
        {
	  edge_iterator ei;
	  FOR_EACH_EDGE (e, ei, bb->preds)
	    eliminate_phi (e, g);
	}
    }

  delete_elim_graph (g);
}

/* These are the local work structures used to determine the best place to 
   insert the copies that were placed on edges by the SSA->normal pass..  */
static VEC(edge,heap) *edge_leader;
static VEC(tree,heap) *stmt_list;
static bitmap leader_has_match = NULL;
static edge leader_match = NULL;


/* Pass this function to make_forwarder_block so that all the edges with
   matching PENDING_STMT lists to 'curr_stmt_list' get redirected.  E is the
   edge to test for a match.  */

static inline bool 
same_stmt_list_p (edge e)
{
  return (e->aux == (PTR) leader_match) ? true : false;
}


/* Return TRUE if S1 and S2 are equivalent copies.  */

static inline bool
identical_copies_p (const_tree s1, const_tree s2)
{
#ifdef ENABLE_CHECKING
  gcc_assert (TREE_CODE (s1) == GIMPLE_MODIFY_STMT);
  gcc_assert (TREE_CODE (s2) == GIMPLE_MODIFY_STMT);
  gcc_assert (DECL_P (GIMPLE_STMT_OPERAND (s1, 0)));
  gcc_assert (DECL_P (GIMPLE_STMT_OPERAND (s2, 0)));
#endif

  if (GIMPLE_STMT_OPERAND (s1, 0) != GIMPLE_STMT_OPERAND (s2, 0))
    return false;

  s1 = GIMPLE_STMT_OPERAND (s1, 1);
  s2 = GIMPLE_STMT_OPERAND (s2, 1);

  if (s1 != s2)
    return false;

  return true;
}


/* Compare the PENDING_STMT list for edges E1 and E2. Return true if the lists
   contain the same sequence of copies.  */

static inline bool 
identical_stmt_lists_p (const_edge e1, const_edge e2)
{
  tree t1 = PENDING_STMT (e1);
  tree t2 = PENDING_STMT (e2);
  tree_stmt_iterator tsi1, tsi2;

  gcc_assert (TREE_CODE (t1) == STATEMENT_LIST);
  gcc_assert (TREE_CODE (t2) == STATEMENT_LIST);

  for (tsi1 = tsi_start (t1), tsi2 = tsi_start (t2);
       !tsi_end_p (tsi1) && !tsi_end_p (tsi2); 
       tsi_next (&tsi1), tsi_next (&tsi2))
    {
      if (!identical_copies_p (tsi_stmt (tsi1), tsi_stmt (tsi2)))
        break;
    }

  if (!tsi_end_p (tsi1) || ! tsi_end_p (tsi2))
    return false;

  return true;
}


/* Allocate data structures used in analyze_edges_for_bb.   */

static void
init_analyze_edges_for_bb (void)
{
  edge_leader = VEC_alloc (edge, heap, 25);
  stmt_list = VEC_alloc (tree, heap, 25);
  leader_has_match = BITMAP_ALLOC (NULL);
}


/* Free data structures used in analyze_edges_for_bb.   */

static void
fini_analyze_edges_for_bb (void)
{
  VEC_free (edge, heap, edge_leader);
  VEC_free (tree, heap, stmt_list);
  BITMAP_FREE (leader_has_match);
}


/* Look at all the incoming edges to block BB, and decide where the best place
   to insert the stmts on each edge are, and perform those insertions.  */

static void
analyze_edges_for_bb (basic_block bb)
{
  edge e;
  edge_iterator ei;
  int count;
  unsigned int x;
  bool have_opportunity;
  block_stmt_iterator bsi;
  tree stmt;
  edge single_edge = NULL;
  bool is_label;
  edge leader;

  count = 0;

  /* Blocks which contain at least one abnormal edge cannot use 
     make_forwarder_block.  Look for these blocks, and commit any PENDING_STMTs
     found on edges in these block.  */
  have_opportunity = true;
  FOR_EACH_EDGE (e, ei, bb->preds)
    if (e->flags & EDGE_ABNORMAL)
      {
        have_opportunity = false;
	break;
      }

  if (!have_opportunity)
    {
      FOR_EACH_EDGE (e, ei, bb->preds)
	if (PENDING_STMT (e))
	  bsi_commit_one_edge_insert (e, NULL);
      return;
    }

  /* Find out how many edges there are with interesting pending stmts on them.  
     Commit the stmts on edges we are not interested in.  */
  FOR_EACH_EDGE (e, ei, bb->preds)
    {
      if (PENDING_STMT (e))
        {
	  gcc_assert (!(e->flags & EDGE_ABNORMAL));
	  if (e->flags & EDGE_FALLTHRU)
	    {
	      bsi = bsi_start (e->src);
	      if (!bsi_end_p (bsi))
	        {
		  stmt = bsi_stmt (bsi);
		  bsi_next (&bsi);
		  gcc_assert (stmt != NULL_TREE);
		  is_label = (TREE_CODE (stmt) == LABEL_EXPR);
		  /* Punt if it has non-label stmts, or isn't local.  */
		  if (!is_label || DECL_NONLOCAL (TREE_OPERAND (stmt, 0)) 
		      || !bsi_end_p (bsi))
		    {
		      bsi_commit_one_edge_insert (e, NULL);
		      continue;
		    }
		}
	    }
	  single_edge = e;
	  count++;
	}
    }

  /* If there aren't at least 2 edges, no sharing will happen.  */
  if (count < 2)
    {
      if (single_edge)
        bsi_commit_one_edge_insert (single_edge, NULL);
      return;
    }

  /* Ensure that we have empty worklists.  */
#ifdef ENABLE_CHECKING
  gcc_assert (VEC_length (edge, edge_leader) == 0);
  gcc_assert (VEC_length (tree, stmt_list) == 0);
  gcc_assert (bitmap_empty_p (leader_has_match));
#endif

  /* Find the "leader" block for each set of unique stmt lists.  Preference is
     given to FALLTHRU blocks since they would need a GOTO to arrive at another
     block.  The leader edge destination is the block which all the other edges
     with the same stmt list will be redirected to.  */
  have_opportunity = false;
  FOR_EACH_EDGE (e, ei, bb->preds)
    {
      if (PENDING_STMT (e))
	{
	  bool found = false;

	  /* Look for the same stmt list in edge leaders list.  */
	  for (x = 0; VEC_iterate (edge, edge_leader, x, leader); x++)
	    {
	      if (identical_stmt_lists_p (leader, e))
		{
		  /* Give this edge the same stmt list pointer.  */
		  PENDING_STMT (e) = NULL;
		  e->aux = leader;
		  bitmap_set_bit (leader_has_match, x);
		  have_opportunity = found = true;
		  break;
		}
	    }

	  /* If no similar stmt list, add this edge to the leader list.  */
	  if (!found)
	    {
	      VEC_safe_push (edge, heap, edge_leader, e);
	      VEC_safe_push (tree, heap, stmt_list, PENDING_STMT (e));
	    }
	}
     }

  /* If there are no similar lists, just issue the stmts.  */
  if (!have_opportunity)
    {
      for (x = 0; VEC_iterate (edge, edge_leader, x, leader); x++)
	bsi_commit_one_edge_insert (leader, NULL);
      VEC_truncate (edge, edge_leader, 0);
      VEC_truncate (tree, stmt_list, 0);
      bitmap_clear (leader_has_match);
      return;
    }

  if (dump_file)
    fprintf (dump_file, "\nOpportunities in BB %d for stmt/block reduction:\n",
	     bb->index);
  
  /* For each common list, create a forwarding block and issue the stmt's
     in that block.  */
  for (x = 0; VEC_iterate (edge, edge_leader, x, leader); x++)
    if (bitmap_bit_p (leader_has_match, x))
      {
	edge new_edge;
	block_stmt_iterator bsi;
	tree curr_stmt_list;

	leader_match = leader;

	/* The tree_* cfg manipulation routines use the PENDING_EDGE field
	   for various PHI manipulations, so it gets cleared when calls are 
	   made to make_forwarder_block(). So make sure the edge is clear, 
	   and use the saved stmt list.  */
	PENDING_STMT (leader) = NULL;
	leader->aux = leader;
	curr_stmt_list = VEC_index (tree, stmt_list, x);

        new_edge = make_forwarder_block (leader->dest, same_stmt_list_p, 
					 NULL);
	bb = new_edge->dest;
	if (dump_file)
	  {
	    fprintf (dump_file, "Splitting BB %d for Common stmt list.  ", 
		     leader->dest->index);
	    fprintf (dump_file, "Original block is now BB%d.\n", bb->index);
	    print_generic_stmt (dump_file, curr_stmt_list, TDF_VOPS);
	  }

	FOR_EACH_EDGE (e, ei, new_edge->src->preds)
	  {
	    e->aux = NULL;
	    if (dump_file)
	      fprintf (dump_file, "  Edge (%d->%d) lands here.\n", 
		       e->src->index, e->dest->index);
	  }

	bsi = bsi_last (leader->dest);
	bsi_insert_after (&bsi, curr_stmt_list, BSI_NEW_STMT);

	leader_match = NULL;
	/* We should never get a new block now.  */
      }
    else
      {
	PENDING_STMT (leader) = VEC_index (tree, stmt_list, x);
	bsi_commit_one_edge_insert (leader, NULL);
      }

   
  /* Clear the working data structures.  */
  VEC_truncate (edge, edge_leader, 0);
  VEC_truncate (tree, stmt_list, 0);
  bitmap_clear (leader_has_match);
}


/* This function will analyze the insertions which were performed on edges,
   and decide whether they should be left on that edge, or whether it is more
   efficient to emit some subset of them in a single block.  All stmts are
   inserted somewhere.  */

static void
perform_edge_inserts (void)
{
  basic_block bb;

  if (dump_file)
    fprintf(dump_file, "Analyzing Edge Insertions.\n");

  /* analyze_edges_for_bb calls make_forwarder_block, which tries to
     incrementally update the dominator information.  Since we don't
     need dominator information after this pass, go ahead and free the
     dominator information.  */
  free_dominance_info (CDI_DOMINATORS);
  free_dominance_info (CDI_POST_DOMINATORS);

  /* Allocate data structures used in analyze_edges_for_bb.   */
  init_analyze_edges_for_bb ();

  FOR_EACH_BB (bb)
    analyze_edges_for_bb (bb);

  analyze_edges_for_bb (EXIT_BLOCK_PTR);

  /* Free data structures used in analyze_edges_for_bb.   */
  fini_analyze_edges_for_bb ();

#ifdef ENABLE_CHECKING
  {
    edge_iterator ei;
    edge e;
    FOR_EACH_BB (bb)
      {
	FOR_EACH_EDGE (e, ei, bb->preds)
	  {
	    if (PENDING_STMT (e))
	      error (" Pending stmts not issued on PRED edge (%d, %d)\n", 
		     e->src->index, e->dest->index);
	  }
	FOR_EACH_EDGE (e, ei, bb->succs)
	  {
	    if (PENDING_STMT (e))
	      error (" Pending stmts not issued on SUCC edge (%d, %d)\n", 
		     e->src->index, e->dest->index);
	  }
      }
    FOR_EACH_EDGE (e, ei, ENTRY_BLOCK_PTR->succs)
      {
	if (PENDING_STMT (e))
	  error (" Pending stmts not issued on ENTRY edge (%d, %d)\n", 
		 e->src->index, e->dest->index);
      }
    FOR_EACH_EDGE (e, ei, EXIT_BLOCK_PTR->preds)
      {
	if (PENDING_STMT (e))
	  error (" Pending stmts not issued on EXIT edge (%d, %d)\n", 
		 e->src->index, e->dest->index);
      }
  }
#endif
}


/* Remove the ssa-names in the current function and translate them into normal
   compiler variables.  PERFORM_TER is true if Temporary Expression Replacement
   should also be used.  */

static void
remove_ssa_form (bool perform_ter)
{
  basic_block bb;
  tree phi, next;
  tree *values = NULL;
  var_map map;

  map = coalesce_ssa_name ();

  /* Return to viewing the variable list as just all reference variables after
     coalescing has been performed.  */
  partition_view_normal (map, false);

  if (dump_file && (dump_flags & TDF_DETAILS))
    {
      fprintf (dump_file, "After Coalescing:\n");
      dump_var_map (dump_file, map);
    }

  if (perform_ter)
    {
      values = find_replaceable_exprs (map);
      if (values && dump_file && (dump_flags & TDF_DETAILS))
	dump_replaceable_exprs (dump_file, values);
    }

  /* Assign real variables to the partitions now.  */
  assign_vars (map);

  if (dump_file && (dump_flags & TDF_DETAILS))
    {
      fprintf (dump_file, "After Base variable replacement:\n");
      dump_var_map (dump_file, map);
    }

  rewrite_trees (map, values);

  if (values)
    free (values);

  /* Remove PHI nodes which have been translated back to real variables.  */
  FOR_EACH_BB (bb)
    {
      for (phi = phi_nodes (bb); phi; phi = next)
	{
	  next = PHI_CHAIN (phi);
	  remove_phi_node (phi, NULL_TREE, true);
	}
    }

  /* If any copies were inserted on edges, analyze and insert them now.  */
  perform_edge_inserts ();

  delete_var_map (map);
}


/* Search every PHI node for arguments associated with backedges which
   we can trivially determine will need a copy (the argument is either
   not an SSA_NAME or the argument has a different underlying variable
   than the PHI result).

   Insert a copy from the PHI argument to a new destination at the
   end of the block with the backedge to the top of the loop.  Update
   the PHI argument to reference this new destination.  */

static void
insert_backedge_copies (void)
{
  basic_block bb;

  FOR_EACH_BB (bb)
    {
      tree phi;

      for (phi = phi_nodes (bb); phi; phi = PHI_CHAIN (phi))
	{
	  tree result = PHI_RESULT (phi);
	  tree result_var;
	  int i;

	  if (!is_gimple_reg (result))
	    continue;

	  result_var = SSA_NAME_VAR (result);
	  for (i = 0; i < PHI_NUM_ARGS (phi); i++)
	    {
	      tree arg = PHI_ARG_DEF (phi, i);
	      edge e = PHI_ARG_EDGE (phi, i);

	      /* If the argument is not an SSA_NAME, then we will need a 
		 constant initialization.  If the argument is an SSA_NAME with
		 a different underlying variable then a copy statement will be 
		 needed.  */
	      if ((e->flags & EDGE_DFS_BACK)
		  && (TREE_CODE (arg) != SSA_NAME
		      || SSA_NAME_VAR (arg) != result_var))
		{
		  tree stmt, name, last = NULL;
		  block_stmt_iterator bsi;

		  bsi = bsi_last (PHI_ARG_EDGE (phi, i)->src);
		  if (!bsi_end_p (bsi))
		    last = bsi_stmt (bsi);

		  /* In theory the only way we ought to get back to the
		     start of a loop should be with a COND_EXPR or GOTO_EXPR.
		     However, better safe than sorry. 
		     If the block ends with a control statement or
		     something that might throw, then we have to
		     insert this assignment before the last
		     statement.  Else insert it after the last statement.  */
		  if (last && stmt_ends_bb_p (last))
		    {
		      /* If the last statement in the block is the definition
			 site of the PHI argument, then we can't insert
			 anything after it.  */
		      if (TREE_CODE (arg) == SSA_NAME
			  && SSA_NAME_DEF_STMT (arg) == last)
			continue;
		    }

		  /* Create a new instance of the underlying variable of the 
		     PHI result.  */
		  stmt = build_gimple_modify_stmt (NULL_TREE,
						   PHI_ARG_DEF (phi, i));
		  name = make_ssa_name (result_var, stmt);
		  GIMPLE_STMT_OPERAND (stmt, 0) = name;

		  /* Insert the new statement into the block and update
		     the PHI node.  */
		  if (last && stmt_ends_bb_p (last))
		    bsi_insert_before (&bsi, stmt, BSI_NEW_STMT);
		  else
		    bsi_insert_after (&bsi, stmt, BSI_NEW_STMT);
		  SET_PHI_ARG_DEF (phi, i, name);
		}
	    }
	}
    }
}

/* Take the current function out of SSA form, translating PHIs as described in
   R. Morgan, ``Building an Optimizing Compiler'',
   Butterworth-Heinemann, Boston, MA, 1998. pp 176-186.  */

static unsigned int
rewrite_out_of_ssa (void)
{
  /* If elimination of a PHI requires inserting a copy on a backedge,
     then we will have to split the backedge which has numerous
     undesirable performance effects.

     A significant number of such cases can be handled here by inserting
     copies into the loop itself.  */
  insert_backedge_copies ();

  eliminate_virtual_phis ();

  if (dump_file && (dump_flags & TDF_DETAILS))
    dump_tree_cfg (dump_file, dump_flags & ~TDF_DETAILS);

  remove_ssa_form (flag_tree_ter && !flag_mudflap);

  if (dump_file && (dump_flags & TDF_DETAILS))
    dump_tree_cfg (dump_file, dump_flags & ~TDF_DETAILS);

  cfun->gimple_df->in_ssa_p = false;
  return 0;
}


/* Define the parameters of the out of SSA pass.  */

struct tree_opt_pass pass_del_ssa = 
{
  "optimized",				/* name */
  NULL,					/* gate */
  rewrite_out_of_ssa,			/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_TREE_SSA_TO_NORMAL,		/* tv_id */
  PROP_cfg | PROP_ssa | PROP_alias,	/* properties_required */
  0,					/* properties_provided */
  /* ??? If TER is enabled, we also kill gimple.  */
  PROP_ssa,				/* properties_destroyed */
  TODO_verify_ssa | TODO_verify_flow
    | TODO_verify_stmts,		/* todo_flags_start */
  TODO_dump_func
  | TODO_ggc_collect
  | TODO_remove_unused_locals,		/* todo_flags_finish */
  0					/* letter */
};
