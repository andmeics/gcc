/* Routines for liveness in SSA trees.
   Copyright (C) 2003 Free Software Foundation, Inc.
   Contributed by Andrew MacLeod  <amacleod@redhat.com>

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */


#ifndef _TREE_SSA_LIVE_H__
#define _TREE_SSA_LIVE_H 1

/* Used to create the variable mapping when we go out of SSA form.  */
typedef struct _var_map
{
  /* The partition of all variables.  */
  partition var_partition;

  /* Vector for compacting partitions.  */
  int *partition_to_compact;
  int *compact_to_partition;

  /* Mapping of partition numbers to vars.  */
  tree *partition_to_var;

  /* Current number of partitions.  */
  unsigned int num_partitions;

  /* Original partition size.  */
  unsigned int partition_size;
} *var_map;

#define VAR_ANN_PARTITION(ann) (ann->partition)
#define VAR_ANN_ROOT_INDEX(ann) (ann->root_index)

#define NO_PARTITION		-1

/* Flags to pass to compact_var_map  */

#define VARMAP_NORMAL		0
#define VARMAP_NO_SINGLE_DEFS	1

extern var_map init_var_map (int);
extern void delete_var_map (var_map);
extern void dump_var_map (FILE *, var_map);
extern int var_union (var_map, tree, tree);
extern void change_partition_var (var_map, tree, int);
extern var_map create_ssa_var_map (void);
extern void compact_var_map (var_map, int);

static inline int num_var_partitions (var_map);
static inline tree var_to_partition_to_var (var_map, tree);
static inline tree partition_to_var (var_map, int);
static inline int var_to_partition (var_map, tree);

/* Number of partitions.  */

static inline int 
num_var_partitions (var_map map)
{
  return map->num_partitions;
}

 
/* Given a partition number, return the variable which represents that 
   partition.  */
 
static inline tree
partition_to_var (var_map map, int i)
{
  if (map->compact_to_partition)
    i = map->compact_to_partition[i];
  i = partition_find (map->var_partition, i);
  return map->partition_to_var[i];
}

/* Given a variable, return the partition number which contains it.  
   NO_PARTITION is returned if its not in any partition.  */

static inline int
var_to_partition (var_map map, tree var)
{
  var_ann_t ann;
  int part;

  if (TREE_CODE (var) == SSA_NAME)
    {
      part = partition_find (map->var_partition, SSA_NAME_VERSION (var));
      if (map->partition_to_compact)
	part = map->partition_to_compact[part];
    }
  else
    {
      ann = var_ann (var);
      if (ann->out_of_ssa_tag)
	part = VAR_ANN_PARTITION (ann);
      else
        part = NO_PARTITION;
    }
  return part;
}

/* Given a variable, return the variable which represents the entire partition
   the specified one is a member of.  */

static inline tree
var_to_partition_to_var (var_map map, tree var)
{
  int part;

  part = var_to_partition (map, var);
  if (part == NO_PARTITION)
    return NULL_TREE;
  return partition_to_var (map, part);
}

/*  ---------------- live on entry/exit info ------------------------------  

    This structure is used to represent live range information on SSA based
    trees. A partition map must be provided, and based on the active partitions,
    live-on-entry information and live-on-exit information can be calculated.
    As well, partitions are marked as to whether they are global (live 
    outside the basic block they are defined in).

    The live-on-entry information is per variable. It provide a bitmap for 
    each variable which has a bit set for each basic block that the variable
    is live on entry to that block.

    The live-on-exit information is per block. It provides a bitmap for each
    block indicating which partitions are live on exit from the block.

    For the purposes of this implementation, we treat the elements of a PHI 
    as follows:

       Uses in a PHI are considered LIVE-ON-EXIT to the block from which they
       originate. They are *NOT* considered live on entry to the block
       containing the PHI node.

       The Def of a PHI node is *not* considered live on entry to the block.
       It is considered to be "define early" in the block. Picture it as each
       block having a stmt (or block-preheader) before the first real stmt in 
       the block which defines all the variables that are defined by PHIs.
   
    -----------------------------------------------------------------------  */


typedef struct tree_live_info_d
{
  /* Var map this relates to.  */
  var_map map;

  /* Bitmap indicating which partitions are global.  */
  bitmap global;

  /* Bitmap of live on entry blocks for partition elements.  */
  bitmap *livein;

  /* Number of basic blocks when live on exit calculated.  */
  int num_blocks;

  /* Bitmap of what variables are live on exit for a basic blocks.  */
  bitmap *liveout;
} *tree_live_info_p;


extern tree_live_info_p calculate_live_on_entry (var_map);
extern void calculate_live_on_exit (tree_live_info_p);
extern void delete_tree_live_info (tree_live_info_p);

#define LIVEDUMP_ENTRY	0x01
#define LIVEDUMP_EXIT	0x02
#define LIVEDUMP_ALL	(LIVEDUMP_ENTRY | LIVEDUMP_EXIT)
extern void dump_live_info (FILE *, tree_live_info_p, int);

static inline int partition_is_global (tree_live_info_p, int);
static inline bitmap live_entry_blocks (tree_live_info_p, int);
static inline bitmap live_on_exit (tree_live_info_p, basic_block);
static inline var_map live_var_map (tree_live_info_p);
static inline void live_merge_and_clear (tree_live_info_p, int, int);
static inline void make_live_on_entry (tree_live_info_p, basic_block, int);

static inline int
partition_is_global (tree_live_info_p live, int p)
{
  if (!live->global)
    abort ();

  return bitmap_bit_p (live->global, p);
}

static inline bitmap
live_entry_blocks (tree_live_info_p live, int p)
{
  if (!live->livein)
    abort ();

  return live->livein[p];
}

static inline bitmap
live_on_exit (tree_live_info_p live, basic_block bb)
{
  if (!live->liveout)
    abort();

  if (bb == ENTRY_BLOCK_PTR || bb == EXIT_BLOCK_PTR)
    abort ();
  
  return live->liveout[bb->index];
}

static inline var_map 
live_var_map (tree_live_info_p live)
{
  return live->map;
}

/* Merge the live on entry information for partitions p1 and p2, and put the
   result into p1.  Clear p2. */
static inline void 
live_merge_and_clear (tree_live_info_p live, int p1, int p2)
{
  bitmap_a_or_b (live->livein[p1], live->livein[p1], live->livein[p2]);
  bitmap_zero (live->livein[p2]);
}

static inline void 
make_live_on_entry (tree_live_info_p live, basic_block bb , int p)
{
  bitmap_set_bit (live->livein[p], bb->index);
  bitmap_set_bit (live->global, p);
}

/* A tree_partition_associator object is a base structure which allows
   partitions to be associated with a tree object.

   A varray of tree elements represent each distinct tree item.
   A parallel int array represents the first partition number associated with 
   the tree.
   This partition number is then used as in index into the next_partition
   array, which returns the index of the next partition which is associated
   with the tree. TPA_NONE indicates the end of the list.  
   A varray paralleling the partition list 'partition_to_tree_map' is used
   to indicate which tree index the partition is in.  */

typedef struct tree_partition_associator_d
{
  varray_type trees;
  varray_type first_partition;
  int *next_partition;
  int *partition_to_tree_map;
  int num_trees;
  int uncompressed_num;
  var_map map;
} *tpa_p;

/* Value returned when there are no more partitions associated with a tree.  */
#define TPA_NONE		-1


static inline tree tpa_tree (tpa_p, int);
static inline int tpa_first_partition (tpa_p, int);
static inline int tpa_next_partition (tpa_p, int);
static inline int tpa_num_trees (tpa_p);
static inline int tpa_find_tree (tpa_p, int);
static inline void tpa_decompact (tpa_p);
extern tpa_p tpa_init (var_map);
extern void tpa_delete (tpa_p);
extern void tpa_dump (FILE *, tpa_p);
extern void tpa_remove_partition (tpa_p, int, int);
extern int tpa_compact (tpa_p);


/* Number of distinct tree nodes.  */
static inline int
tpa_num_trees (tpa_p tpa)
{
  return tpa->num_trees;
}

/* Retrieve the tree node for a specified index.  */
static inline tree
tpa_tree (tpa_p tpa, int i)
{
  return VARRAY_TREE (tpa->trees, i);
}

/* Get the first partition associated with a tree.  */
static inline int
tpa_first_partition (tpa_p tpa, int i)
{
  return VARRAY_INT (tpa->first_partition, i);
}

/* Get the next partition in a list.  */
static inline int
tpa_next_partition (tpa_p tpa, int i)
{
  return tpa->next_partition[i];
}

/* Get the tree whose list a partition is a member of.  TPA_NONE is returned
   if the partition is not associated with any list.  */
static inline int 
tpa_find_tree (tpa_p tpa, int i)
{
  return tpa->partition_to_tree_map[i];
}

/* Compacting removes lists with single elements. This routine puts them
   back in again.  */
static inline void 
tpa_decompact(tpa_p tpa)
{
#ifdef ENABLE_CHECKING
  if (tpa->uncompressed_num == -1)
    abort ();
#endif
  tpa->num_trees = tpa->uncompressed_num;
}

/* Once a var_map has been created and compressed, a complimentary root_var
   object can be built.  This creates a list of all the root variables from
   which ssa version names are derived.  Each root variable has a list of 
   which partitions are versions of that root.  

   This is implemented using the tree_partition_associator.

   The tree vector is used to represent the root variable.
   The list of partitions represent SSA versions of the root variable.  */

typedef tpa_p root_var_p;

static inline tree root_var (root_var_p, int);
static inline int root_var_first_partition (root_var_p, int);
static inline int root_var_next_partition (root_var_p, int);
static inline int root_var_num (root_var_p);
static inline void root_var_dump (FILE *, root_var_p);
static inline void root_var_remove_partition (root_var_p, int, int);
static inline void root_var_delete (root_var_p);
static inline int root_var_find (root_var_p, int);
static inline int root_var_compact (root_var_p);
static inline void root_var_decompact (tpa_p);

extern root_var_p root_var_init (var_map);

/* Value returned when there are no more partitions associated with a root
   variable.  */
#define ROOT_VAR_NONE		TPA_NONE

/* Number of distinct root variables.  */
static inline int 
root_var_num (root_var_p rv)
{
  return tpa_num_trees (rv);
}

/* A specific root variable.  */
static inline tree
root_var (root_var_p rv, int i)
{
  return tpa_tree (rv, i);
}

/* First partition belonging to a root variable list.  */
static inline int
root_var_first_partition (root_var_p rv, int i)
{
  return tpa_first_partition (rv, i);
}

/* Next partition belonging to a root variable partition list.  */
static inline int
root_var_next_partition (root_var_p rv, int i)
{
  return tpa_next_partition (rv, i);
}

/* Show debug info for a root_var list.  */
static inline void
root_var_dump (FILE *f, root_var_p rv)
{
  fprintf (f, "\nRoot Var dump\n");
  tpa_dump (f, rv);
  fprintf (f, "\n");
}

/* destroy a root_var object.  */
static inline void
root_var_delete (root_var_p rv)
{
  tpa_delete (rv);
}

/* Remove a partition from a root_var list.  */
static inline void
root_var_remove_partition (root_var_p rv, int root_index, int partition_index)
{
  tpa_remove_partition (rv, root_index, partition_index);
}

/* Find the root_var list index for a specific partition.  */
static inline int
root_var_find (root_var_p rv, int i)
{
  return tpa_find_tree (rv, i);
}

/* Hide single element lists in the object.  */
static inline int 
root_var_compact (root_var_p rv)
{
  return tpa_compact (rv);
}

/* Expose the single element lists in the object.  */
static inline void
root_var_decompact (root_var_p rv)
{
  tpa_decompact (rv);
}

/* This is similar to a root_var structure, except this associates partitions
   with their type rather than their root variable. This is used to 
   coalesce memory locations based on type.   */

typedef tpa_p type_var_p;

static inline tree type_var (type_var_p, int);
static inline int type_var_first_partition (type_var_p, int);
static inline int type_var_next_partition (type_var_p, int);
static inline int type_var_num (type_var_p);
static inline void type_var_dump (FILE *, type_var_p);
static inline void type_var_remove_partition (type_var_p, int, int);
static inline void type_var_delete (type_var_p);
static inline int type_var_find (type_var_p, int);
static inline int type_var_compact (type_var_p);
static inline void type_var_decompact (type_var_p);

extern type_var_p type_var_init (var_map);


/* Value returned when there is no partitions associated with a list.  */
#define TYPE_VAR_NONE		TPA_NONE

/* Number of distinct type lists.  */
static inline int 
type_var_num (type_var_p tv)
{
  return tpa_num_trees (tv);
}

/* The type of a specific list.  */
static inline tree
type_var (type_var_p tv, int i)
{
  return tpa_tree (tv, i);
}

/* First partition belonging to a type list.  */
static inline int
type_var_first_partition (type_var_p tv, int i)
{
  return tpa_first_partition (tv, i);
}

/* Next partition belonging to a type list.  */
static inline int
type_var_next_partition (type_var_p tv, int i)
{
  return tpa_next_partition (tv, i);
}

/* Show debug info for a type_var object.  */
static inline void
type_var_dump (FILE *f, type_var_p tv)
{
  fprintf (f, "\nType Var dump\n");
  tpa_dump (f, tv);
  fprintf (f, "\n");
}

/* Delete a type_var object.  */
static inline void
type_var_delete (type_var_p tv)
{
  tpa_delete (tv);
}

/* Remove a partition from a specific list.  */
static inline void
type_var_remove_partition (type_var_p tv, int type_index, int partition_index)
{
  tpa_remove_partition (tv, type_index, partition_index);
}

/* Find the type index for the list a partition is in.  */
static inline int
type_var_find (type_var_p tv, int i)
{
  return tpa_find_tree (tv, i);
}

/* Hide single element lists.  */
static inline int 
type_var_compact (type_var_p tv)
{
  return tpa_compact (tv);
}

/* Expose single element lists.  */
static inline void
type_var_decompact (type_var_p tv)
{
  tpa_decompact (tv);
}

/* This set of routines implements a coalesce_list. This is an object which
   is used to track pairs of partitions which are desirable to coalesce
   together at some point.  Costs are associated with each pair, and when 
   all desired information has been collected, the object can be used to 
   order the pairs for processing.  */

/* This structure defines a pair for coalescing.  */

typedef struct partition_pair_d
{
  int first_partition;
  int second_partition;
  int cost;
  struct partition_pair_d *next;
} *partition_pair_p;

/* This structure maintains the list of coalesce pairs.  
   When add_mode is true, list is a triangular shaped list of coalesce pairs.
   The smaller partition number is used to index the list, and the larger is
   index is located in a partition_pair_p object. Each of these lists are sorted
   from smallest to largest second_partition.  New coalesce pairs are allowed
   to be added in this mode.
   When add_mode is false, the lists have all been merged into list[0]. The
   rest of the lists are not used. list[0] is ordered from most desirable
   coalesce to least desirable. pop_best_coalesce() retrieves the pairs
   one at a time.  */

typedef struct coalesce_list_d 
{
  var_map map;
  partition_pair_p *list;
  bool add_mode;
} *coalesce_list_p;

extern coalesce_list_p create_coalesce_list (var_map);
extern void add_coalesce (coalesce_list_p, int, int, int);
extern void sort_coalesce_list (coalesce_list_p);
extern void dump_coalesce_list (FILE *, coalesce_list_p);
extern void delete_coalesce_list (coalesce_list_p);

#define NO_BEST_COALESCE	-1
extern int pop_best_coalesce (coalesce_list_p, int *, int *);

extern conflict_graph build_tree_conflict_graph (tree_live_info_p, tpa_p,
						 coalesce_list_p);
extern void coalesce_tpa_members (tpa_p tpa, conflict_graph graph, var_map map,
				  coalesce_list_p cl, FILE *);


#endif /* _TREE_SSA_LIVE_H  */
