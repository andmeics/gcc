/* Header file for routines that straddle the border between GIMPLE and
   SSA in gimple.
   Copyright (C) 2009-2013 Free Software Foundation, Inc.

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

#ifndef GCC_GIMPLE_SSA_H
#define GCC_GIMPLE_SSA_H

#include "tree-ssa-operands.h"

/* This structure is used to map a gimple statement to a label,
   or list of labels to represent transaction restart.  */

struct GTY(()) tm_restart_node {
  gimple stmt;
  tree label_or_list;
};

/* Gimple dataflow datastructure. All publicly available fields shall have
   gimple_ accessor defined, all publicly modifiable fields should have
   gimple_set accessor.  */
struct GTY(()) gimple_df {
  /* A vector of all the noreturn calls passed to modify_stmt.
     cleanup_control_flow uses it to detect cases where a mid-block
     indirect call has been turned into a noreturn call.  When this
     happens, all the instructions after the call are no longer
     reachable and must be deleted as dead.  */
  vec<gimple, va_gc> *modified_noreturn_calls;

  /* Array of all SSA_NAMEs used in the function.  */
  vec<tree, va_gc> *ssa_names;

  /* Artificial variable used for the virtual operand FUD chain.  */
  tree vop;

  /* The PTA solution for the ESCAPED artificial variable.  */
  struct pt_solution escaped;

  /* A map of decls to artificial ssa-names that point to the partition
     of the decl.  */
  struct pointer_map_t * GTY((skip(""))) decls_to_pointers;

  /* Free list of SSA_NAMEs.  */
  vec<tree, va_gc> *free_ssanames;

  /* Hashtable holding definition for symbol.  If this field is not NULL, it
     means that the first reference to this variable in the function is a
     USE or a VUSE.  In those cases, the SSA renamer creates an SSA name
     for this variable with an empty defining statement.  */
  htab_t GTY((param_is (union tree_node))) default_defs;

  /* True if there are any symbols that need to be renamed.  */
  unsigned int ssa_renaming_needed : 1;

  /* True if all virtual operands need to be renamed.  */
  unsigned int rename_vops : 1;

  /* True if the code is in ssa form.  */
  unsigned int in_ssa_p : 1;

  /* True if IPA points-to information was computed for this function.  */
  unsigned int ipa_pta : 1;

  struct ssa_operands ssa_operands;

  /* Map gimple stmt to tree label (or list of labels) for transaction
     restart and abort.  */
  htab_t GTY ((param_is (struct tm_restart_node))) tm_restart;
};


/* Return true when gimple SSA form was built.
   gimple_in_ssa_p is queried by gimplifier in various early stages before SSA
   infrastructure is initialized.  Check for presence of the datastructures
   at first place.  */
static inline bool
gimple_in_ssa_p (const struct function *fun)
{
  return fun && fun->gimple_df && fun->gimple_df->in_ssa_p;
}

/* Artificial variable used for the virtual operand FUD chain.  */
static inline tree
gimple_vop (const struct function *fun)
{
  gcc_checking_assert (fun && fun->gimple_df);
  return fun->gimple_df->vop;
}

/* Return the set of VUSE operand for statement G.  */

static inline use_operand_p
gimple_vuse_op (const_gimple g)
{
  struct use_optype_d *ops;
  if (!gimple_has_mem_ops (g))
    return NULL_USE_OPERAND_P;
  ops = g->gsops.opbase.use_ops;
  if (ops
      && USE_OP_PTR (ops)->use == &g->gsmembase.vuse)
    return USE_OP_PTR (ops);
  return NULL_USE_OPERAND_P;
}

/* Return the set of VDEF operand for statement G.  */

static inline def_operand_p
gimple_vdef_op (gimple g)
{
  if (!gimple_has_mem_ops (g))
    return NULL_DEF_OPERAND_P;
  if (g->gsmembase.vdef)
    return &g->gsmembase.vdef;
  return NULL_DEF_OPERAND_P;
}

/* Mark statement S as modified, and update it.  */

static inline void
update_stmt (gimple s)
{
  if (gimple_has_ops (s))
    {
      gimple_set_modified (s, true);
      update_stmt_operands (s);
    }
}

/* Update statement S if it has been optimized.  */

static inline void
update_stmt_if_modified (gimple s)
{
  if (gimple_modified_p (s))
    update_stmt_operands (s);
}


#endif /* GCC_GIMPLE_SSA_H */
