/* Hooks for cfg representation specific functions.
   Copyright (C) 2003, 2004 Free Software Foundation, Inc.
   Contributed by Sebastian Pop <s.pop@laposte.net>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef GCC_CFGHOOKS_H
#define GCC_CFGHOOKS_H

struct cfg_hooks
{
  /* Name of the corresponding ir.  */
  const char *name;

  /* Debugging.  */
  int (*verify_flow_info) (void);
  void (*dump_bb) (basic_block, FILE *, int);

  /* Basic CFG manipulation.  */

  /* Return new basic block.  */
  basic_block (*create_basic_block) (void *head, void *end, basic_block after);

  /* Redirect edge E to the given basic block B and update underlying program
     representation.  Returns false when edge is not easily redirectable for
     whatever reason.  */
  bool (*redirect_edge_and_branch) (edge e, basic_block b);

  /* Same as the above but allows redirecting of fallthru edges.  In that case
     newly created forwarder basic block is returned.  It aborts when called
     on abnormal edge.  */
  basic_block (*redirect_edge_and_branch_force) (edge, basic_block);

  /* Remove statements corresponding to a given basic block.  */
  void (*delete_basic_block) (basic_block);

  /* Creates a new basic block just after basic block B by splitting
     everything after specified instruction I.  */
  basic_block (*split_block) (basic_block b, void * i);

  /* Move block B immediately after block A.  */
  bool (*move_block_after) (basic_block b, basic_block a);

  /* Return true when blocks A and B can be merged into single basic block.  */
  bool (*can_merge_blocks_p) (basic_block a, basic_block b);

  /* Merge blocks A and B.  */
  void (*merge_blocks) (basic_block a, basic_block b);

  /* Higher level functions representable by primitive operations above if
     we didn't have some oddities in RTL and Tree representations.  */
  basic_block (*split_edge) (edge);
  void (*make_forwarder_block) (edge);

  /* Tries to make the edge fallthru.  */
  void (*tidy_fallthru_edge) (edge);
};

extern void verify_flow_info (void);
extern void dump_bb (basic_block, FILE *, int);
extern bool redirect_edge_and_branch (edge, basic_block);
extern basic_block redirect_edge_and_branch_force (edge, basic_block);
extern edge split_block (basic_block, void *);
extern edge split_block_after_labels (basic_block);
extern bool move_block_after (basic_block, basic_block);
extern void delete_basic_block (basic_block);
extern basic_block split_edge (edge);
extern basic_block create_basic_block (void *, void *, basic_block);
extern basic_block create_empty_bb (basic_block);
extern bool can_merge_blocks_p (basic_block, basic_block);
extern void merge_blocks (basic_block, basic_block);
extern edge make_forwarder_block (basic_block, bool (*)(edge),
				  void (*) (basic_block));
extern void tidy_fallthru_edge (edge);
extern void tidy_fallthru_edges (void);

/* Hooks containers.  */
extern struct cfg_hooks rtl_cfg_hooks;
extern struct cfg_hooks cfg_layout_rtl_cfg_hooks;

/* Declarations.  */
extern void rtl_register_cfg_hooks (void);
extern void cfg_layout_rtl_register_cfg_hooks (void);

#endif  /* GCC_CFGHOOKS_H */
