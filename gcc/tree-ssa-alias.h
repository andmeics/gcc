/* Tree based alias analysis and alias oracle.
   Copyright (C) 2008 Free Software Foundation, Inc.
   Contributed by Richard Guenther  <rguenther@suse.de>

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef TREE_SSA_ALIAS_H
#define TREE_SSA_ALIAS_H

#include "coretypes.h"


/* The reasons a variable may escape a function.  */
enum escape_type 
{
  NO_ESCAPE = 0,			/* Doesn't escape.  */
  ESCAPE_STORED_IN_GLOBAL = 1 << 0,
  ESCAPE_TO_ASM = 1 << 1,		/* Passed by address to an assembly
					   statement.  */
  ESCAPE_TO_CALL = 1 << 2,		/* Escapes to a function call.  */
  ESCAPE_BAD_CAST = 1 << 3,		/* Cast from pointer to integer */
  ESCAPE_TO_RETURN = 1 << 4,		/* Returned from function.  */
  ESCAPE_TO_PURE_CONST = 1 << 5,	/* Escapes to a pure or constant
					   function call.  */
  ESCAPE_IS_GLOBAL = 1 << 6,		/* Is a global variable.  */
  ESCAPE_IS_PARM = 1 << 7,		/* Is an incoming function argument.  */
  ESCAPE_UNKNOWN = 1 << 8		/* We believe it escapes for
					   some reason not enumerated
					   above.  */
};


/* The points-to solution.

   The points-to solution is a union of pt_vars and the abstract
   sets specified by the flags.  */
struct GTY(()) pt_solution
{
  /* Nonzero if points-to analysis couldn't determine where this pointer
     is pointing to.  */
  unsigned int anything : 1;

  /* Nonzero if the points-to set includes any global memory.  Note that
     even if this is zero pt_vars can still include global variables.  */
  unsigned int nonlocal : 1;

  /* Nonzero if the points-to set includes any escaped local variable.  */
  unsigned int escaped : 1;

  /* Nonzero if the points-to set includes 'nothing', the points-to set
     includes memory at address NULL.  */
  unsigned int null : 1;


  /* Nonzero if the pt_vars bitmap includes a global variable.  */
  unsigned int vars_contains_global : 1;

  /* Set of variables that this pointer may point to.  */
  bitmap vars;
};


/* Simplified and cached information about a memory reference tree.
   Used by the alias-oracle internally and externally in alternate
   interfaces.  */
typedef struct ao_ref_s
{
  /* The original full memory reference tree or NULL_TREE if that is
     not available.  */
  tree ref;

  /* The following fields are the decomposed reference as returned
     by get_ref_base_and_extent.  */
  /* The base object of the memory reference or NULL_TREE if all of
     the following fields are not yet computed.  */
  tree base;
  /* The offset relative to the base.  */
  HOST_WIDE_INT offset;
  /* The size of the access.  */
  HOST_WIDE_INT size;
  /* The maximum possible extent of the access or -1 if unconstrained.  */
  HOST_WIDE_INT max_size;

  /* The alias set of the access or -1 if not yet computed.  */
  alias_set_type ref_alias_set;

  /* The alias set of the base object or -1 if not yet computed.  */
  alias_set_type base_alias_set;
} ao_ref;


/* In tree-ssa-alias.c  */
extern void ao_ref_init (ao_ref *, tree);
extern tree ao_ref_base (ao_ref *);
extern alias_set_type ao_ref_alias_set (ao_ref *);
extern enum escape_type is_escape_site (gimple);
extern bool ptr_deref_may_alias_global_p (tree);
extern bool refs_may_alias_p (tree, tree);
extern bool refs_anti_dependent_p (tree, tree);
extern bool refs_output_dependent_p (tree, tree);
extern bool ref_maybe_used_by_stmt_p (gimple, tree);
extern bool stmt_may_clobber_ref_p (gimple, tree);
extern bool stmt_may_clobber_ref_p_1 (gimple, ao_ref *);
extern void *walk_non_aliased_vuses (ao_ref *, tree,
				     void *(*)(ao_ref *, tree, void *),
				     void *(*)(ao_ref *, tree, void *), void *);
extern unsigned int walk_aliased_vdefs (tree, tree,
					bool (*)(tree, tree, void *), void *,
					bitmap *);
extern struct ptr_info_def *get_ptr_info (tree);
extern void dump_alias_info (FILE *);
extern void debug_alias_info (void);
extern void dump_points_to_solution (FILE *, struct pt_solution *);
extern void dump_points_to_info_for (FILE *, tree);
extern void debug_points_to_info_for (tree);
extern void dump_alias_stats (FILE *);


/* In tree-ssa-structalias.c  */
extern unsigned int compute_may_aliases (void);
extern void delete_alias_heapvars (void);
extern bool pt_solution_includes_global (struct pt_solution *);
extern bool pt_solution_includes (struct pt_solution *, const_tree);
extern bool pt_solutions_intersect (struct pt_solution *, struct pt_solution *);
extern void pt_solution_reset (struct pt_solution *);
extern void dump_pta_stats (FILE *);


#endif /* TREE_SSA_ALIAS_H  */
