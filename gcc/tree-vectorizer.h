/* Loop Vectorization
   Copyright (C) 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
   Contributed by Dorit Naishlos <dorit@il.ibm.com>

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
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#ifndef GCC_TREE_VECTORIZER_H
#define GCC_TREE_VECTORIZER_H

#ifdef USE_MAPPED_LOCATION
  typedef source_location LOC;
  #define UNKNOWN_LOC UNKNOWN_LOCATION
  #define EXPR_LOC(e) EXPR_LOCATION(e)
  #define LOC_FILE(l) LOCATION_FILE (l)
  #define LOC_LINE(l) LOCATION_LINE (l)
#else
  typedef source_locus LOC;
  #define UNKNOWN_LOC NULL
  #define EXPR_LOC(e) EXPR_LOCUS(e)
  #define LOC_FILE(l) (l)->file
  #define LOC_LINE(l) (l)->line
#endif

/* Used for naming of new temporaries.  */
enum vect_var_kind {
  vect_simple_var,
  vect_pointer_var,
  vect_scalar_var
};

/* Defines type of operation.  */
enum operation_type {
  unary_op = 1,
  binary_op,
  ternary_op
};

/* Define type of available alignment support.  */
enum dr_alignment_support {
  dr_unaligned_unsupported,
  dr_unaligned_supported,
  dr_explicit_realign,
  dr_explicit_realign_optimized,
  dr_aligned
};

/* Define type of def-use cross-iteration cycle.  */
enum vect_def_type {
  vect_constant_def = 1,
  vect_invariant_def,
  vect_loop_def,
  vect_induction_def,
  vect_reduction_def,
  vect_unknown_def_type
};

/* Define verbosity levels.  */
enum verbosity_levels {
  REPORT_NONE,
  REPORT_VECTORIZED_LOOPS,
  REPORT_UNVECTORIZED_LOOPS,
  REPORT_ALIGNMENT,
  REPORT_DR_DETAILS,
  REPORT_BAD_FORM_LOOPS,
  REPORT_OUTER_LOOPS,
  REPORT_DETAILS,
  /* New verbosity levels should be added before this one.  */
  MAX_VERBOSITY_LEVEL
};

/************************************************************************
  SLP 
 ************************************************************************/

/* A computation tree of an SLP instance. Each node corresponds to a group of
   stmts to be packed in a SIMD stmt.  */
typedef struct _slp_tree {
  /* Only binary and unary operations are supported. LEFT child corresponds to 
     the first operand and RIGHT child to the second if the operation is
     binary.  */
  struct _slp_tree *left;
  struct _slp_tree *right;
  /* A group of scalar stmts to be vectorized together.  */
  VEC (tree, heap) *stmts;
  /* Vectorized stmt/s.  */
  VEC (tree, heap) *vec_stmts;
  /* Number of vectorized stmts.  */
  unsigned int vec_stmts_size;
} *slp_tree;


/* SLP instance is a sequence of stmts in a loop that can be packed into 
   SIMD stmts.  */
typedef struct _slp_instance {
  /* The root of SLP tree.  */
  slp_tree root;

  /* Size of groups of scalar stmts that will be replaced by SIMD stmt/s.  */
  unsigned int group_size;  

  /* The unrolling factor required to vectorized this SLP instance.  */
  unsigned int unrolling_factor;  
} *slp_instance;

DEF_VEC_P(slp_instance);
DEF_VEC_ALLOC_P(slp_instance, heap);

/* Access Functions.  */
#define SLP_INSTANCE_TREE(S)                             (S)->root
#define SLP_INSTANCE_GROUP_SIZE(S)                       (S)->group_size
#define SLP_INSTANCE_UNROLLING_FACTOR(S)                 (S)->unrolling_factor

#define SLP_TREE_LEFT(S)                         (S)->left
#define SLP_TREE_RIGHT(S)                        (S)->right
#define SLP_TREE_SCALAR_STMTS(S)                 (S)->stmts
#define SLP_TREE_VEC_STMTS(S)                    (S)->vec_stmts
#define SLP_TREE_NUMBER_OF_VEC_STMTS(S)          (S)->vec_stmts_size

/*-----------------------------------------------------------------*/
/* Info on vectorized loops.                                       */
/*-----------------------------------------------------------------*/
typedef struct _loop_vec_info {

  /* The loop to which this info struct refers to.  */
  struct loop *loop;

  /* The loop basic blocks.  */
  basic_block *bbs;

  /* Number of iterations.  */
  tree num_iters;

  /* Is the loop vectorizable? */
  bool vectorizable;

  /* Unrolling factor  */
  int vectorization_factor;

  /* Unknown DRs according to which loop was peeled.  */
  struct data_reference *unaligned_dr;

  /* peeling_for_alignment indicates whether peeling for alignment will take
     place, and what the peeling factor should be:
     peeling_for_alignment = X means:
        If X=0: Peeling for alignment will not be applied.
        If X>0: Peel first X iterations.
        If X=-1: Generate a runtime test to calculate the number of iterations
                 to be peeled, using the dataref recorded in the field
                 unaligned_dr.  */
  int peeling_for_alignment;

  /* The mask used to check the alignment of pointers or arrays.  */
  int ptr_mask;

  /* All data references in the loop.  */
  VEC (data_reference_p, heap) *datarefs;

  /* All data dependences in the loop.  */
  VEC (ddr_p, heap) *ddrs;

  /* Statements in the loop that have data references that are candidates for a
     runtime (loop versioning) misalignment check.  */
  VEC(tree,heap) *may_misalign_stmts;

  /* The loop location in the source.  */
  LOC loop_line_number;

  /* All interleaving chains of stores in the loop, represented by the first 
     stmt in the chain.  */
  VEC(tree, heap) *strided_stores;

  /* All SLP groups in the loop.  */
  VEC(slp_instance, heap) *slp_instances;

  /* The unrolling factor needed to SLP the loop.  */
  unsigned slp_unrolling_factor;
} *loop_vec_info;

/* Access Functions.  */
#define LOOP_VINFO_LOOP(L)            (L)->loop
#define LOOP_VINFO_BBS(L)             (L)->bbs
#define LOOP_VINFO_NITERS(L)          (L)->num_iters
#define LOOP_VINFO_VECTORIZABLE_P(L)  (L)->vectorizable
#define LOOP_VINFO_VECT_FACTOR(L)     (L)->vectorization_factor
#define LOOP_VINFO_PTR_MASK(L)        (L)->ptr_mask
#define LOOP_VINFO_DATAREFS(L)        (L)->datarefs
#define LOOP_VINFO_DDRS(L)            (L)->ddrs
#define LOOP_VINFO_INT_NITERS(L)      (TREE_INT_CST_LOW ((L)->num_iters))
#define LOOP_PEELING_FOR_ALIGNMENT(L) (L)->peeling_for_alignment
#define LOOP_VINFO_UNALIGNED_DR(L)    (L)->unaligned_dr
#define LOOP_VINFO_MAY_MISALIGN_STMTS(L) (L)->may_misalign_stmts
#define LOOP_VINFO_LOC(L)             (L)->loop_line_number
#define LOOP_VINFO_STRIDED_STORES(L)  (L)->strided_stores
#define LOOP_VINFO_SLP_INSTANCES(L)   (L)->slp_instances
#define LOOP_VINFO_SLP_UNROLLING_FACTOR(L) (L)->slp_unrolling_factor

#define NITERS_KNOWN_P(n)                     \
(host_integerp ((n),0)                        \
&& TREE_INT_CST_LOW ((n)) > 0)

#define LOOP_VINFO_NITERS_KNOWN_P(L)                     \
NITERS_KNOWN_P((L)->num_iters)

static inline loop_vec_info
loop_vec_info_for_loop (struct loop *loop)
{
  return (loop_vec_info) loop->aux;
}

static inline bool
nested_in_vect_loop_p (struct loop *loop, tree stmt)
{
  return (loop->inner 
          && (loop->inner == (bb_for_stmt (stmt))->loop_father));
}

/*-----------------------------------------------------------------*/
/* Info on vectorized defs.                                        */
/*-----------------------------------------------------------------*/
enum stmt_vec_info_type {
  undef_vec_info_type = 0,
  load_vec_info_type,
  store_vec_info_type,
  op_vec_info_type,
  call_vec_info_type,
  assignment_vec_info_type,
  condition_vec_info_type,
  reduc_vec_info_type,
  induc_vec_info_type,
  type_promotion_vec_info_type,
  type_demotion_vec_info_type,
  type_conversion_vec_info_type,
  loop_exit_ctrl_vec_info_type
};

/* Indicates whether/how a variable is used in the loop.  */
enum vect_relevant {
  vect_unused_in_loop = 0,
  vect_used_in_outer_by_reduction,
  vect_used_in_outer,

  /* defs that feed computations that end up (only) in a reduction. These
     defs may be used by non-reduction stmts, but eventually, any 
     computations/values that are affected by these defs are used to compute 
     a reduction (i.e. don't get stored to memory, for example). We use this 
     to identify computations that we can change the order in which they are 
     computed.  */
  vect_used_by_reduction,

  vect_used_in_loop  
};

enum slp_vect_type {
  loop_vect = 0,
  pure_slp,
  hybrid
};

typedef struct data_reference *dr_p;
DEF_VEC_P(dr_p);
DEF_VEC_ALLOC_P(dr_p,heap);

typedef struct _stmt_vec_info {

  enum stmt_vec_info_type type;

  /* The stmt to which this info struct refers to.  */
  tree stmt;

  /* The loop_vec_info with respect to which STMT is vectorized.  */
  loop_vec_info loop_vinfo;

  /* Not all stmts in the loop need to be vectorized. e.g, the increment
     of the loop induction variable and computation of array indexes. relevant
     indicates whether the stmt needs to be vectorized.  */
  enum vect_relevant relevant;

  /* Indicates whether this stmts is part of a computation whose result is
     used outside the loop.  */
  bool live;

  /* The vector type to be used.  */
  tree vectype;

  /* The vectorized version of the stmt.  */
  tree vectorized_stmt;


  /** The following is relevant only for stmts that contain a non-scalar
     data-ref (array/pointer/struct access). A GIMPLE stmt is expected to have 
     at most one such data-ref.  **/

  /* Information about the data-ref (access function, etc),
     relative to the inner-most containing loop.  */
  struct data_reference *data_ref_info;

  /* Information about the data-ref relative to this loop
     nest (the loop that is being considered for vectorization).  */
  tree dr_base_address;
  tree dr_init;
  tree dr_offset;
  tree dr_step;
  tree dr_aligned_to;

  /* Stmt is part of some pattern (computation idiom)  */
  bool in_pattern_p;

  /* Used for various bookkeeping purposes, generally holding a pointer to 
     some other stmt S that is in some way "related" to this stmt. 
     Current use of this field is:
        If this stmt is part of a pattern (i.e. the field 'in_pattern_p' is 
        true): S is the "pattern stmt" that represents (and replaces) the 
        sequence of stmts that constitutes the pattern.  Similarly, the 
        related_stmt of the "pattern stmt" points back to this stmt (which is 
        the last stmt in the original sequence of stmts that constitutes the 
        pattern).  */
  tree related_stmt;

  /* List of datarefs that are known to have the same alignment as the dataref
     of this stmt.  */
  VEC(dr_p,heap) *same_align_refs;

  /* Classify the def of this stmt.  */
  enum vect_def_type def_type;

  /* If this stmt is a part of pure or hybrid SLP.  */
  enum slp_vect_type slp_type;

  /* Interleaving info.  */
  /* First data-ref in the interleaving group.  */
  tree first_dr;
  /* Pointer to the next data-ref in the group.  */
  tree next_dr;
  /* The size of the interleaving group.  */
  unsigned int size;
  /* For stores, number of stores from this group seen. We vectorize the last
     one.  */
  unsigned int store_count;
  /* For loads only, the gap from the previous load. For consecutive loads, GAP
     is 1.  */
  unsigned int gap;
  /* In case that two or more stmts share data-ref, this is the pointer to the
     previously detected stmt with the same dr.  */
  tree same_dr_stmt;
  /* For loads only, if there is a store with the same location, this field is
     TRUE.  */
  bool read_write_dep;
} *stmt_vec_info;

/* Access Functions.  */
#define STMT_VINFO_TYPE(S)                 (S)->type
#define STMT_VINFO_STMT(S)                 (S)->stmt
#define STMT_VINFO_LOOP_VINFO(S)           (S)->loop_vinfo
#define STMT_VINFO_RELEVANT(S)             (S)->relevant
#define STMT_VINFO_LIVE_P(S)               (S)->live
#define STMT_VINFO_VECTYPE(S)              (S)->vectype
#define STMT_VINFO_VEC_STMT(S)             (S)->vectorized_stmt
#define STMT_VINFO_DATA_REF(S)             (S)->data_ref_info

#define STMT_VINFO_DR_BASE_ADDRESS(S)      (S)->dr_base_address
#define STMT_VINFO_DR_INIT(S)              (S)->dr_init
#define STMT_VINFO_DR_OFFSET(S)            (S)->dr_offset
#define STMT_VINFO_DR_STEP(S)              (S)->dr_step
#define STMT_VINFO_DR_ALIGNED_TO(S)        (S)->dr_aligned_to

#define STMT_VINFO_IN_PATTERN_P(S)         (S)->in_pattern_p
#define STMT_VINFO_RELATED_STMT(S)         (S)->related_stmt
#define STMT_VINFO_SAME_ALIGN_REFS(S)      (S)->same_align_refs
#define STMT_VINFO_DEF_TYPE(S)             (S)->def_type
#define STMT_VINFO_DR_GROUP_FIRST_DR(S)    (S)->first_dr
#define STMT_VINFO_DR_GROUP_NEXT_DR(S)     (S)->next_dr
#define STMT_VINFO_DR_GROUP_SIZE(S)        (S)->size
#define STMT_VINFO_DR_GROUP_STORE_COUNT(S) (S)->store_count
#define STMT_VINFO_DR_GROUP_GAP(S)         (S)->gap
#define STMT_VINFO_DR_GROUP_SAME_DR_STMT(S)(S)->same_dr_stmt
#define STMT_VINFO_DR_GROUP_READ_WRITE_DEPENDENCE(S)  (S)->read_write_dep

#define DR_GROUP_FIRST_DR(S)               (S)->first_dr
#define DR_GROUP_NEXT_DR(S)                (S)->next_dr
#define DR_GROUP_SIZE(S)                   (S)->size
#define DR_GROUP_STORE_COUNT(S)            (S)->store_count
#define DR_GROUP_GAP(S)                    (S)->gap
#define DR_GROUP_SAME_DR_STMT(S)           (S)->same_dr_stmt
#define DR_GROUP_READ_WRITE_DEPENDENCE(S)  (S)->read_write_dep

#define STMT_VINFO_STRIDED_ACCESS(S)      ((S)->first_dr != NULL)
#define STMT_VINFO_RELEVANT_P(S)          ((S)->relevant != vect_unused_in_loop)

#define STMT_VINFO_HYBRID_SLP(S)           ((S)->slp_type == hybrid)
#define STMT_VINFO_PURE_SLP(S)             ((S)->slp_type == pure_slp)
#define STMT_VINFO_SLP_TYPE(S)              (S)->slp_type

static inline void set_stmt_info (stmt_ann_t ann, stmt_vec_info stmt_info);
static inline stmt_vec_info vinfo_for_stmt (tree stmt);

static inline void
set_stmt_info (stmt_ann_t ann, stmt_vec_info stmt_info)
{
  if (ann)
    ann->common.aux = (char *) stmt_info;
}

static inline stmt_vec_info
vinfo_for_stmt (tree stmt)
{
  stmt_ann_t ann = stmt_ann (stmt);
  return ann ? (stmt_vec_info) ann->common.aux : NULL;
}

static inline bool
is_pattern_stmt_p (stmt_vec_info stmt_info)
{
  tree related_stmt;
  stmt_vec_info related_stmt_info;

  related_stmt = STMT_VINFO_RELATED_STMT (stmt_info);
  if (related_stmt
      && (related_stmt_info = vinfo_for_stmt (related_stmt))
      && STMT_VINFO_IN_PATTERN_P (related_stmt_info))
    return true;

  return false;
}

static inline bool
is_loop_header_bb_p (basic_block bb)
{
  if (bb == (bb->loop_father)->header)
    return true;
  gcc_assert (EDGE_COUNT (bb->preds) == 1);
  return false;
}

/*-----------------------------------------------------------------*/
/* Info on data references alignment.                              */
/*-----------------------------------------------------------------*/

/* Reflects actual alignment of first access in the vectorized loop,
   taking into account peeling/versioning if applied.  */
#define DR_MISALIGNMENT(DR)   (DR)->aux

static inline bool
aligned_access_p (struct data_reference *data_ref_info)
{
  return (DR_MISALIGNMENT (data_ref_info) == 0);
}

static inline bool
known_alignment_for_access_p (struct data_reference *data_ref_info)
{
  return (DR_MISALIGNMENT (data_ref_info) != -1);
}

/* vect_dump will be set to stderr or dump_file if exist.  */
extern FILE *vect_dump;
extern enum verbosity_levels vect_verbosity_level;

/* Bitmap of virtual variables to be renamed.  */
extern bitmap vect_memsyms_to_rename;

/*-----------------------------------------------------------------*/
/* Function prototypes.                                            */
/*-----------------------------------------------------------------*/

/*************************************************************************
  Simple Loop Peeling Utilities - in tree-vectorizer.c
 *************************************************************************/
/* Entry point for peeling of simple loops.
   Peel the first/last iterations of a loop.
   It can be used outside of the vectorizer for loops that are simple enough
   (see function documentation).  In the vectorizer it is used to peel the
   last few iterations when the loop bound is unknown or does not evenly
   divide by the vectorization factor, and to peel the first few iterations
   to force the alignment of data references in the loop.  */
extern struct loop *slpeel_tree_peel_loop_to_edge 
  (struct loop *, edge, tree, tree, bool, unsigned int);
extern void slpeel_make_loop_iterate_ntimes (struct loop *, tree);
extern bool slpeel_can_duplicate_loop_p (struct loop *, edge);
#ifdef ENABLE_CHECKING
extern void slpeel_verify_cfg_after_peeling (struct loop *, struct loop *);
#endif


/*************************************************************************
  General Vectorization Utilities
 *************************************************************************/
/** In tree-vectorizer.c **/
extern tree get_vectype_for_scalar_type (tree);
extern bool vect_is_simple_use (tree, loop_vec_info, tree *, tree *,
				enum vect_def_type *);
extern bool vect_is_simple_iv_evolution (unsigned, tree, tree *, tree *);
extern tree vect_is_simple_reduction (loop_vec_info, tree);
extern bool vect_can_force_dr_alignment_p (tree, unsigned int);
extern enum dr_alignment_support vect_supportable_dr_alignment
  (struct data_reference *);
extern bool reduction_code_for_scalar_code (enum tree_code, enum tree_code *);
extern bool supportable_widening_operation (enum tree_code, tree, tree,
  tree *, tree *, enum tree_code *, enum tree_code *);
/* Creation and deletion of loop and stmt info structs.  */
extern loop_vec_info new_loop_vec_info (struct loop *loop);
extern void destroy_loop_vec_info (loop_vec_info, bool);
extern stmt_vec_info new_stmt_vec_info (tree stmt, loop_vec_info);


/** In tree-vect-analyze.c  **/
/* Driver for analysis stage.  */
extern loop_vec_info vect_analyze_loop (struct loop *);


/** In tree-vect-patterns.c  **/
/* Pattern recognition functions.
   Additional pattern recognition functions can (and will) be added
   in the future.  */
typedef tree (* vect_recog_func_ptr) (tree, tree *, tree *);
#define NUM_PATTERNS 4
void vect_pattern_recog (loop_vec_info);


/** In tree-vect-transform.c  **/
extern bool vectorizable_load (tree, block_stmt_iterator *, tree *, slp_tree);
extern bool vectorizable_store (tree, block_stmt_iterator *, tree *, slp_tree);
extern bool vectorizable_operation (tree, block_stmt_iterator *, tree *, slp_tree);
extern bool vectorizable_type_promotion (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_type_demotion (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_conversion (tree, block_stmt_iterator *, 
				     tree *, slp_tree);
extern bool vectorizable_assignment (tree, block_stmt_iterator *, tree *, slp_tree);
extern tree vectorizable_function (tree, tree, tree);
extern bool vectorizable_call (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_condition (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_live_operation (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_reduction (tree, block_stmt_iterator *, tree *);
extern bool vectorizable_induction (tree, block_stmt_iterator *, tree *);
extern void vect_free_slp_tree (slp_tree);
/* Driver for transformation stage.  */
extern void vect_transform_loop (loop_vec_info);

/*************************************************************************
  Vectorization Debug Information - in tree-vectorizer.c
 *************************************************************************/
extern bool vect_print_dump_info (enum verbosity_levels);
extern void vect_set_verbosity_level (const char *);
extern LOC find_loop_location (struct loop *);

#endif  /* GCC_TREE_VECTORIZER_H  */
