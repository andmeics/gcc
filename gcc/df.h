/* Form lists of pseudo register references for autoinc optimization
   for GNU compiler.  This is part of flow optimization.
   Copyright (C) 1999, 2000, 2001, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   Originally contributed by Michael P. Hayes 
             (m.hayes@elec.canterbury.ac.nz, mhayes@redhat.com)
   Major rewrite contributed by Danny Berlin (dberlin@dberlin.org)
             and Kenneth Zadeck (zadeck@naturalbridge.com).

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

#ifndef GCC_DF_H
#define GCC_DF_H

#include "bitmap.h"
#include "basic-block.h"
#include "alloc-pool.h"

struct dataflow;
struct df;
struct df_problem;
struct df_link;

/* Data flow problems.  All problems must have a unique id here.  */ 
/* Scanning is not really a dataflow problem, but it is useful to have
   the basic block functions in the vector so that things get done in
   a uniform manner.  The first four problems are always defined.  The
   last 5 are optional and can be added or deleted at any time.  */
#define DF_SCAN  0 
#define DF_LR    1      /* Live Registers backward. */
#define DF_UR    2      /* Uninitialized Registers forwards. */
#define DF_LIVE  3      /* Live Registers & Uninitialized Registers */

#define DF_RU    4      /* Reaching Uses. */
#define DF_RD    5      /* Reaching Defs. */
#define DF_UREC  6      /* Uninitialized Registers with Early Clobber. */
#define DF_CHAIN 7      /* Def-Use and/or Use-Def Chains. */
#define DF_RI    8      /* Register Info. */

#define DF_LAST_PROBLEM_PLUS1 (DF_RI + 1)
#define DF_FIRST_OPTIONAL_PROBLEM DF_RU

/* Dataflow direction.  */
enum df_flow_dir
  {
    DF_NONE,
    DF_FORWARD,
    DF_BACKWARD
  };


/* The first of these is a set of a register.  The remaining three are
   all uses of a register (the mem_load and mem_store relate to how
   the register as an addressing operand).  */
enum df_ref_type {DF_REF_REG_DEF, DF_REF_REG_USE, DF_REF_REG_MEM_LOAD,
		  DF_REF_REG_MEM_STORE};

#define DF_REF_TYPE_NAMES {"def", "use", "mem load", "mem store"}

enum df_ref_flags
  {
    /* Read-modify-write refs generate both a use and a def and
       these are marked with this flag to show that they are not
       independent.  */
    DF_REF_READ_WRITE = 1 << 0,

    /* If this flag is set for an artificial use or def, that ref
       logically happens at the top of the block.  If it is not set
       for an artificial use or def, that ref logically happens at the
       bottom of the block.  This is never set for regular refs.  */
    DF_REF_AT_TOP = 1 << 1,

    /* This flag is set if the use is inside a REG_EQUAL or REG_EQUIV
       note.  */
    DF_REF_IN_NOTE = 1 << 2,

    /* This flag is set if this ref, generally a def, may clobber the
       referenced register.  This is generally only set for hard
       registers that cross a call site.  With better information
       about calls, some of these could be changed in the future to
       DF_REF_MUST_CLOBBER.  */
    DF_REF_MAY_CLOBBER = 1 << 3,



    /* This flag is set if this ref, generally a def, is a real
       clobber. This is not currently set for registers live across a
       call because that clobbering may or may not happen.  

       Most of the uses of this are with sets that have a
       GET_CODE(..)==CLOBBER.  Note that this is set even if the
       clobber is to a subreg.  So in order to tell if the clobber
       wipes out the entire register, it is necessary to also check
       the DF_REF_PARTIAL flag.  */
    DF_REF_MUST_CLOBBER = 1 << 4,

    /* This bit is true if this ref is part of a multiword hardreg.  */
    DF_REF_MW_HARDREG = 1 << 5,

    /* This flag is set if this ref is a partial use or def of the
       associated register.  */
    DF_REF_PARTIAL = 1 << 6,
    
    /* This flag is set if this ref occurs inside of a conditional
       execution instruction.  */
    DF_REF_CONDITIONAL = 1 << 7,



    /* This flag is set if this ref is inside a pre/post modify.  */
    DF_REF_PRE_POST_MODIFY = 1 << 8,

    /* This flag is set if this ref is a usage of the stack pointer by
       a function call.  */
    DF_REF_CALL_STACK_USAGE = 1 << 9,

    /* This flag is used internally to group
       the hardregs. */
    DF_REF_MW_HARDREG_GROUP = 1 << 10,

    /* This bit is true if this ref can make regs_ever_live true for
       this regno.  */
    DF_REGS_EVER_LIVE = 1 << 11,


    /* These two flags are markers for general purpose use.
       Used for verification of existing refs. */
    DF_REF_REF_MARKER = 1 << 12,
    DF_REF_REG_MARKER = 1 << 13
  };


/* Function prototypes added to df_problem instance.  */

/* Allocate the problem specific data.  */
typedef void (*df_alloc_function) (bitmap);

/* This function is called if the problem has global data that needs
   to be cleared when ever the set of blocks changes.  The bitmap
   contains the set of blocks that may require special attention.
   This call is only made if some of the blocks are going to change.
   If everything is to be deleted, the wholesale deletion mechanisms
   apply. */
typedef void (*df_reset_function) (bitmap);

/* Free the basic block info.  Called from the block reordering code
   to get rid of the blocks that have been squished down.   */
typedef void (*df_free_bb_function) (basic_block, void *);

/* Local compute function.  */
typedef void (*df_local_compute_function) (bitmap);

/* Init the solution specific data.  */
typedef void (*df_init_function) (bitmap);

/* Iterative dataflow function.  */
typedef void (*df_dataflow_function) (struct dataflow *, bitmap, int *, int);

/* Confluence operator for blocks with 0 out (or in) edges.  */
typedef void (*df_confluence_function_0) (basic_block);

/* Confluence operator for blocks with 1 or more out (or in) edges.  */
typedef void (*df_confluence_function_n) (edge);

/* Transfer function for blocks.  */
typedef bool (*df_transfer_function) (int);

/* Function to massage the information after the problem solving.  */
typedef void (*df_finalizer_function) (bitmap);

/* Function to free all of the problem specific datastructures.  */
typedef void (*df_free_function) (void);

/* Function to remove this problem from the stack of dataflow problems
   without effecting the other problems in the stack except for those
   that depend on this problem.  */
typedef void (*df_remove_problem_function) (void);

/* Function to dump basic block independent results to FILE.  */
typedef void (*df_dump_problem_function) (FILE *);

/* Function to dump top or bottom of basic block results to FILE.  */
typedef void (*df_dump_bb_problem_function) (basic_block, FILE *);

/* Function to dump top or bottom of basic block results to FILE.  */
typedef void (*df_verify_solution_start) (void);

/* Function to dump top or bottom of basic block results to FILE.  */
typedef void (*df_verify_solution_end) (void);

/* The static description of a dataflow problem to solve.  See above
   typedefs for doc for the function fields.  */

struct df_problem {
  /* The unique id of the problem.  This is used it index into
     df->defined_problems to make accessing the problem data easy.  */
  unsigned int id;                        
  enum df_flow_dir dir;			/* Dataflow direction.  */
  df_alloc_function alloc_fun;
  df_reset_function reset_fun;
  df_free_bb_function free_bb_fun;
  df_local_compute_function local_compute_fun;
  df_init_function init_fun;
  df_dataflow_function dataflow_fun;
  df_confluence_function_0 con_fun_0;
  df_confluence_function_n con_fun_n;
  df_transfer_function trans_fun;
  df_finalizer_function finalize_fun;
  df_free_function free_fun;
  df_remove_problem_function remove_problem_fun;
  df_dump_problem_function dump_start_fun;
  df_dump_bb_problem_function dump_top_fun;
  df_dump_bb_problem_function dump_bottom_fun;
  df_verify_solution_start verify_start_fun;
  df_verify_solution_end verify_end_fun;
  struct df_problem *dependent_problem;
};


/* The specific instance of the problem to solve.  */
struct dataflow
{
  struct df_problem *problem;           /* The problem to be solved.  */

  /* Communication between iterative_dataflow and hybrid_search. */
  sbitmap visited, pending, considered; 

  /* Array indexed by bb->index, that contains basic block problem and
     solution specific information.  */
  void **block_info;
  unsigned int block_info_size;

  /* The pool to allocate the block_info from. */
  alloc_pool block_pool;                

  /* The lr and ur problems have their transfer functions recomputed
     only if necessary.  This is possible for them because, the
     problems are kept active for the entire backend and their
     transfer functions are indexed by the REGNO.  These are not
     defined for any other problem.  */
  bitmap out_of_date_transfer_functions;

  /* Other problem specific data that is not on a per basic block
     basis.  The structure is generally defined privately for the
     problem.  The exception being the scanning problem where it is
     fully public.  */
  void *problem_data;

  /* Local flags for some of the problems. */
  unsigned int local_flags;
  
  /* True if this problem of this instance has been initialized.  This
     is used by the dumpers to keep garbage out of the dumps if, for
     debugging a dump is produced before the first call to
     df_analyze after a new problem is added.  */
  bool computed;

  /* True if the something has changed which invalidates the dataflow
     solutions.  Note that this bit is always true for all problems except 
     lr, ur, and live.  */
  bool solutions_dirty;


};


/* The set of multiword hardregs used as operands to this
   instruction. These are factored into individual uses and defs but
   the aggregate is still needed to service the REG_DEAD and
   REG_UNUSED notes.  */
struct df_mw_hardreg
{
  rtx mw_reg;                   /* The multiword hardreg.  */ 
  enum df_ref_type type;        /* Used to see if the ref is read or write.  */
  enum df_ref_flags flags;	/* Various flags.  */
  struct df_link *regs;         /* The individual regs that make up
				   this hardreg.  */
  struct df_mw_hardreg *next;   /* The next mw_hardreg in this insn.  */
};
 

/* One of these structures is allocated for every insn.  */
struct df_insn_info
{
  rtx insn;                     /* The insn this info comes from.  */
  struct df_ref *defs;	        /* Head of insn-def chain.  */
  struct df_ref *uses;	        /* Head of insn-use chain.  */
  struct df_mw_hardreg *mw_hardregs;   
  /* Head of insn-use chain for uses in REG_EQUAL/EQUIV notes.  */
  struct df_ref *eq_uses;       
  /* ???? The following luid field should be considered private so that
     we can change it on the fly to accommodate new insns?  */
  int luid;			/* Logical UID.  */
};


/* Define a register reference structure.  One of these is allocated
   for every register reference (use or def).  Note some register
   references (e.g., post_inc, subreg) generate both a def and a use.  */
struct df_ref
{
  rtx reg;			/* The register referenced.  */
  unsigned int regno;           /* The register number referenced.  */
  basic_block bb;               /* Basic block containing the instruction. */

  /* Insn containing ref. This will be null if this is an artificial
     reference.  */
  rtx insn;
  rtx *loc;			/* The location of the reg.  */
  struct df_link *chain;	/* Head of def-use, use-def.  */
  int id;	          	/* Location in table.  */
  enum df_ref_type type;	/* Type of ref.  */
  enum df_ref_flags flags;	/* Various flags.  */

  /* For each regno, there are three chains of refs, one for the uses,
     the eq_uses and the defs.  These chains go thru the refs
     themselves rather than using an external structure.  */
  struct df_ref *next_reg;     /* Next ref with same regno and type.  */
  struct df_ref *prev_reg;     /* Prev ref with same regno and type.  */

  /* Each insn has three lists, one for the uses, the eq_uses and the
     defs. This is the next field in either of these chains. */
  struct df_ref *next_ref; 
};

/* These links are used for two purposes:
   1) def-use or use-def chains. 
   2) Multiword hard registers that underly a single hardware register.  */
struct df_link
{
  struct df_ref *ref;
  struct df_link *next;
};


enum df_chain_flags
{
  /* Flags that control the building of chains.  */
  DF_DU_CHAIN      =  1, /* Build DU chains.  */  
  DF_UD_CHAIN      =  2  /* Build UD chains.  */
};

enum df_ri_flags
{
  /* Flag to control the building of register info.  */
  DF_RI_LIFE       =  1, /* Build register info.  */
  DF_RI_SETJMP     =  2  /* Build pseudos that cross setjmp info.  */
};

enum df_changeable_flags 
{
  /* Scanning flags.  */
  /* Flag to control the running of dce as a side effect of building LR.  */
  DF_LR_RUN_DCE           =  1, /* Run DCE.  */
  DF_NO_HARD_REGS         =  2, /* Skip hard registers in RD and CHAIN Building.  */
  DF_EQ_NOTES             =  4, /* Build chains with uses present in EQUIV/EQUAL notes. */
  DF_RI_NO_UPDATE         =  8, /* Do not update the register info when df_analyze is run.  */
  DF_NO_REGS_EVER_LIVE    = 16, /* Do not compute the regs_ever_live.  */

  /* Cause df_insn_rescan df_notes_rescan and df_insn_delete, to
  return immediately.  This is used by passes that know how to update
  the scanning them selves.  */
  DF_NO_INSN_RESCAN       = 32,

  /* Cause df_insn_rescan df_notes_rescan and df_insn_delete, to
  return after marking the insn for later processing.  This allows all
  rescans to be batched.  */
  DF_DEFER_INSN_RESCAN    = 64
};

/* Two of these structures are inline in df, one for the uses and one
   for the defs.  This structure is only contains the refs within the
   boundary of the df_set_blocks if that has been defined.  */
struct df_ref_info
{
  struct df_ref **refs;         /* Ref table, indexed by id.  */
  unsigned int *begin;          /* First ref_index for this pseudo.  */
  unsigned int *count;          /* Count of refs for this pseudo.  */
  unsigned int refs_size;       /* Size of currently allocated refs table.  */

  /* Table_size is the number of elements in the refs table.  This
     will also be the width of the bitvectors in the rd and ru
     problems.  Total_size is the number of refs.  These will be the
     same if the focus has not been reduced by df_set_blocks.  If the
     focus has been reduced, table_size will be smaller since it only
     contains the refs in the set blocks.  */
  unsigned int table_size;
  unsigned int total_size;

  /* True if refs table is organized so that every reference for a
     particular pseudo is contiguous.  This allows the use of an
     efficient bitmap operator to clear ranges of bits.  */
  bool refs_organized_alone;
  /* This is true if the organization of uses should include the
     eq_uses also.  */
  bool refs_organized_with_eq_uses;
  /* True if the next refs should be added immediately or false to
     defer to later to reorganize the table.  */
  bool add_refs_inline; 
};

/* Three of these structures are allocated for every pseudo reg. One
   for the uses, one for the eq_uses and one for the defs.  */
struct df_reg_info
{
  /* Head of chain for refs of that type and regno.  */
  struct df_ref *reg_chain;
  /* Number of refs in the chain.  */
  unsigned int n_refs;
};


/*----------------------------------------------------------------------------
   Problem data for the scanning dataflow problem.  Unlike the other
   dataflow problems, the problem data for scanning is fully exposed and
   used by owners of the problem.
----------------------------------------------------------------------------*/

struct df
{

  /* The set of problems to be solved is stored in two arrays.  In
     PROBLEMS_IN_ORDER, the problems are stored in the order that they
     are solved.  This is an internally dense array that may have
     nulls at the end of it.  In PROBLEMS_BY_INDEX, the problem is
     stored by the value in df_problem.id.  These are used to access
     the problem local data without having to search the first
     array.  */

  struct dataflow *problems_in_order [DF_LAST_PROBLEM_PLUS1]; 
  struct dataflow *problems_by_index [DF_LAST_PROBLEM_PLUS1]; 
  int num_problems_defined;

  /* If not NULL, the subset of blocks of the program to be considered
     for analysis.  */ 
  bitmap blocks_to_analyze;

  /* True if someone added or deleted something from regs_ever_live so
     that the entry and exit blocks need be reprocessed.  */
  bool redo_entry_and_exit;

  /* The following information is really the problem data for the
     scanning instance but it is used too often by the other problems
     to keep getting it from there.  */
  struct df_ref_info def_info;   /* Def info.  */
  struct df_ref_info use_info;   /* Use info.  */

  /* The following three arrays are allocated in parallel.   They contain
     the sets of refs of each type for each reg.  */
  struct df_reg_info **def_regs;       /* Def reg info.  */
  struct df_reg_info **use_regs;       /* Eq_use reg info.  */
  struct df_reg_info **eq_use_regs;    /* Eq_use info.  */
  unsigned int regs_size;       /* Size of currently allocated regs table.  */
  unsigned int regs_inited;     /* Number of regs with reg_infos allocated.  */


  struct df_insn_info **insns;   /* Insn table, indexed by insn UID.  */
  unsigned int insns_size;       /* Size of insn table.  */
  bitmap hardware_regs_used;     /* The set of hardware registers used.  */
  /* The set of hard regs that are in the artificial uses at the end
     of a regular basic block.  */
  bitmap regular_block_artificial_uses;
  /* The set of hard regs that are in the artificial uses at the end
     of a basic block that has an EH pred.  */
  bitmap eh_block_artificial_uses;
  /* The set of hardware registers live on entry to the function.  */
  bitmap entry_block_defs;
  bitmap exit_block_uses;        /* The set of hardware registers used in exit block.  */

  /* Insns to delete, rescan or reprocess the notes at next
     df_rescan_all or df_process_deferred_rescans. */
  bitmap insns_to_delete;
  bitmap insns_to_rescan;
  bitmap insns_to_notes_rescan;
  int *postorder;                /* The current set of basic blocks in postorder.  */
  int n_blocks;                  /* The number of blocks in postorder.  */

  /* An array [FIRST_PSEUDO_REGISTER], indexed by regno, of the number of
     refs that qualify as being in regs_ever_live.  */
  unsigned int *hard_regs_live_count;

  /* Problem specific control infomation.  */
  enum df_changeable_flags changeable_flags;
};

#define DF_SCAN_BB_INFO(BB) (df_scan_get_bb_info((BB)->index))
#define DF_RU_BB_INFO(BB) (df_ru_get_bb_info((BB)->index))
#define DF_RD_BB_INFO(BB) (df_rd_get_bb_info((BB)->index))
#define DF_LR_BB_INFO(BB) (df_lr_get_bb_info((BB)->index))
#define DF_UR_BB_INFO(BB) (df_ur_get_bb_info((BB)->index))
#define DF_UREC_BB_INFO(BB) (df_urec_get_bb_info((BB)->index))
#define DF_LIVE_BB_INFO(BB) (df_live_get_bb_info((BB)->index))

/* Most transformations that wish to use live register analysis will
   use these macros.  This info is the and of the lr and ur sets.  */
#define DF_LIVE_IN(BB) (DF_LIVE_BB_INFO(BB)->in) 
#define DF_LIVE_OUT(BB) (DF_LIVE_BB_INFO(BB)->out) 


/* Live in for register allocation also takes into account several other factors.  */
#define DF_RA_LIVE_IN(BB) (DF_UREC_BB_INFO(BB)->in) 
#define DF_RA_LIVE_TOP(BB) (DF_UREC_BB_INFO(BB)->top) 
#define DF_RA_LIVE_OUT(BB) (DF_UREC_BB_INFO(BB)->out) 

/* These macros are currently used by only reg-stack since it is not
   tolerant of uninitialized variables.  This intolerance should be
   fixed because it causes other problems.  */ 
#define DF_LR_IN(BB) (DF_LR_BB_INFO(BB)->in) 
#define DF_LR_TOP(BB) (DF_LR_BB_INFO(BB)->top) 
#define DF_LR_OUT(BB) (DF_LR_BB_INFO(BB)->out) 

/* These macros are currently used by only combine which needs to know
   what is really uninitialized.  */ 
#define DF_UR_IN(BB) (DF_UR_BB_INFO(BB)->in) 
#define DF_UR_OUT(BB) (DF_UR_BB_INFO(BB)->out) 


/* Macros to access the elements within the ref structure.  */


#define DF_REF_REAL_REG(REF) (GET_CODE ((REF)->reg) == SUBREG \
				? SUBREG_REG ((REF)->reg) : ((REF)->reg))
#define DF_REF_REGNO(REF) ((REF)->regno)
#define DF_REF_REAL_LOC(REF) (GET_CODE (*((REF)->loc)) == SUBREG \
                               ? &SUBREG_REG (*((REF)->loc)) : ((REF)->loc))
#define DF_REF_REG(REF) ((REF)->reg)
#define DF_REF_LOC(REF) ((REF)->loc)
#define DF_REF_BB(REF) ((REF)->bb)
#define DF_REF_BBNO(REF) (DF_REF_BB (REF)->index)
#define DF_REF_INSN(REF) ((REF)->insn)
#define DF_REF_INSN_UID(REF) (INSN_UID ((REF)->insn))
#define DF_REF_TYPE(REF) ((REF)->type)
#define DF_REF_CHAIN(REF) ((REF)->chain)
#define DF_REF_ID(REF) ((REF)->id)
#define DF_REF_FLAGS(REF) ((REF)->flags)
#define DF_REF_FLAGS_IS_SET(REF, v) ((DF_REF_FLAGS (REF) & (v)) != 0)
#define DF_REF_FLAGS_SET(REF, v) (DF_REF_FLAGS (REF) |= (v))
#define DF_REF_FLAGS_CLEAR(REF, v) (DF_REF_FLAGS (REF) &= ~(v))
/* If DF_REF_IS_ARTIFICIAL () is true, this is not a real definition/use, 
   but an artificial one created to model 
   always live registers, eh uses, etc.  
   ARTIFICIAL refs has NULL insn.  */
#define DF_REF_IS_ARTIFICIAL(REF) ((REF)->insn == NULL)
#define DF_REF_REF_MARK(REF) (DF_REF_FLAGS_SET ((REF),DF_REF_REF_MARKER))
#define DF_REF_REG_MARK(REF) (DF_REF_FLAGS_SET ((REF),DF_REF_REG_MARKER))
#define DF_REF_REF_UNMARK(REF) (DF_REF_FLAGS_CLEAR ((REF),DF_REF_REF_MARKER))
#define DF_REF_REG_UNMARK(REF) (DF_REF_FLAGS_CLEAR ((REF),DF_REF_REG_MARKER))
#define DF_REF_IS_REF_MARKED(REF) (DF_REF_FLAGS_IS_SET ((REF),DF_REF_REF_MARKER))
#define DF_REF_IS_REG_MARKED(REF) (DF_REF_FLAGS_IS_SET ((REF),DF_REF_REG_MARKER))
#define DF_REF_NEXT_REG(REF) ((REF)->next_reg)
#define DF_REF_PREV_REG(REF) ((REF)->prev_reg)
#define DF_REF_NEXT_REF(REF) ((REF)->next_ref)

/* Macros to determine the reference type.  */

#define DF_REF_REG_DEF_P(REF) (DF_REF_TYPE (REF) == DF_REF_REG_DEF)
#define DF_REF_REG_USE_P(REF) ((REF) && !DF_REF_REG_DEF_P (REF))
#define DF_REF_REG_MEM_STORE_P(REF) (DF_REF_TYPE (REF) == DF_REF_REG_MEM_STORE)
#define DF_REF_REG_MEM_LOAD_P(REF) (DF_REF_TYPE (REF) == DF_REF_REG_MEM_LOAD)
#define DF_REF_REG_MEM_P(REF) (DF_REF_REG_MEM_STORE_P (REF) \
                               || DF_REF_REG_MEM_LOAD_P (REF))

/* Macros to get the refs out of def_info or use_info refs table.  If
   the focus of the dataflow has been set to some subset of blocks
   with df_set_blocks, these macros will only find the uses and defs
   in that subset of blocks.  

   These macros should be used with care.  The def macros are only
   usable after a call to df_maybe_reorganize_def_refs and the use
   macros are only usable after a call to
   df_maybe_reorganize_use_refs.  HOWEVER, BUILDING AND USING THESE
   ARRAYS ARE A CACHE LOCALITY KILLER.  */

#define DF_DEFS_TABLE_SIZE() (df->def_info.table_size)
#define DF_DEFS_TOTAL_SIZE() (df->def_info.total_size)
#define DF_DEFS_GET(ID) (df->def_info.refs[(ID)])
#define DF_DEFS_SET(ID,VAL) (df->def_info.refs[(ID)]=(VAL))
#define DF_DEFS_COUNT(ID) (df->def_info.count[(ID)])
#define DF_DEFS_BEGIN(ID) (df->def_info.begin[(ID)])
#define DF_USES_TABLE_SIZE() (df->use_info.table_size)
#define DF_USES_TOTAL_SIZE() (df->use_info.total_size)
#define DF_USES_GET(ID) (df->use_info.refs[(ID)])
#define DF_USES_SET(ID,VAL) (df->use_info.refs[(ID)]=(VAL))
#define DF_USES_COUNT(ID) (df->use_info.count[(ID)])
#define DF_USES_BEGIN(ID) (df->use_info.begin[(ID)])

/* Macros to access the register information from scan dataflow record.  */

#define DF_REG_SIZE(DF) (df->regs_inited)
#define DF_REG_DEF_GET(REG) (df->def_regs[(REG)])
#define DF_REG_DEF_CHAIN(REG) (df->def_regs[(REG)]->reg_chain)
#define DF_REG_DEF_COUNT(REG) (df->def_regs[(REG)]->n_refs)
#define DF_REG_USE_GET(REG) (df->use_regs[(REG)])
#define DF_REG_USE_CHAIN(REG) (df->use_regs[(REG)]->reg_chain)
#define DF_REG_USE_COUNT(REG) (df->use_regs[(REG)]->n_refs)
#define DF_REG_EQ_USE_GET(REG) (df->eq_use_regs[(REG)])
#define DF_REG_EQ_USE_CHAIN(REG) (df->eq_use_regs[(REG)]->reg_chain)
#define DF_REG_EQ_USE_COUNT(REG) (df->eq_use_regs[(REG)]->n_refs)
#define DF_REG_EVER_LIVE_P(REG) (df->hard_regs_live_count[REG] != 0)

/* Macros to access the elements within the reg_info structure table.  */

#define DF_REGNO_FIRST_DEF(REGNUM) \
(DF_REG_DEF_GET(REGNUM) ? DF_REG_DEF_GET(REGNUM) : 0)
#define DF_REGNO_LAST_USE(REGNUM) \
(DF_REG_USE_GET(REGNUM) ? DF_REG_USE_GET(REGNUM) : 0)

/* Macros to access the elements within the insn_info structure table.  */

#define DF_INSN_SIZE() ((df)->insns_size)
#define DF_INSN_GET(INSN) (df->insns[(INSN_UID(INSN))])
#define DF_INSN_SET(INSN,VAL) (df->insns[(INSN_UID (INSN))]=(VAL))
#define DF_INSN_LUID(INSN) (DF_INSN_GET(INSN)->luid)
#define DF_INSN_DEFS(INSN) (DF_INSN_GET(INSN)->defs)
#define DF_INSN_USES(INSN) (DF_INSN_GET(INSN)->uses)
#define DF_INSN_EQ_USES(INSN) (DF_INSN_GET(INSN)->eq_uses)

#define DF_INSN_UID_GET(UID) (df->insns[(UID)])
#define DF_INSN_UID_SET(UID,VAL) (df->insns[(UID)]=(VAL))
#define DF_INSN_UID_SAFE_GET(UID) (((unsigned)(UID) < DF_INSN_SIZE())	\
                                     ? DF_INSN_UID_GET (UID) \
                                     : NULL)
#define DF_INSN_UID_LUID(INSN) (DF_INSN_UID_GET(INSN)->luid)
#define DF_INSN_UID_DEFS(INSN) (DF_INSN_UID_GET(INSN)->defs)
#define DF_INSN_UID_USES(INSN) (DF_INSN_UID_GET(INSN)->uses)
#define DF_INSN_UID_EQ_USES(INSN) (DF_INSN_UID_GET(INSN)->eq_uses)
#define DF_INSN_UID_MWS(INSN) (DF_INSN_UID_GET(INSN)->mw_hardregs)

/* This is a bitmap copy of regs_invalidated_by_call so that we can
   easily add it into bitmaps, etc. */ 

extern bitmap df_invalidated_by_call;


/* One of these structures is allocated for every basic block.  */
struct df_scan_bb_info
{
  /* Defs at the start of a basic block that is the target of an
     exception edge.  */
  struct df_ref *artificial_defs;

  /* Uses of hard registers that are live at every block.  */
  struct df_ref *artificial_uses;
};


/* Reaching uses.  All bitmaps are indexed by the id field of the ref
   except sparse_kill (see below).  */
struct df_ru_bb_info 
{
  /* Local sets to describe the basic blocks.  */
  /* The kill set is the set of uses that are killed in this block.
     However, if the number of uses for this register is greater than
     DF_SPARSE_THRESHOLD, the sparse_kill is used instead. In
     sparse_kill, each register gets a slot and a 1 in this bitvector
     means that all of the uses of that register are killed.  This is
     a very useful efficiency hack in that it keeps from having push
     around big groups of 1s.  This is implemented by the
     bitmap_clear_range call.  */

  bitmap kill;
  bitmap sparse_kill;
  bitmap gen;   /* The set of uses generated in this block.  */

  /* The results of the dataflow problem.  */
  bitmap in;    /* At the top of the block.  */
  bitmap out;   /* At the bottom of the block.  */
};


/* Reaching definitions.  All bitmaps are indexed by the id field of
   the ref except sparse_kill (see above).  */
struct df_rd_bb_info 
{
  /* Local sets to describe the basic blocks.  See the note in the RU
     datastructures for kill and sparse_kill.  */
  bitmap kill;  
  bitmap sparse_kill;
  bitmap gen;   /* The set of defs generated in this block.  */

  /* The results of the dataflow problem.  */
  bitmap in;    /* At the top of the block.  */
  bitmap out;   /* At the bottom of the block.  */
};


/* Live registers.  All bitmaps are referenced by the register number.  

   df_lr_bb_info:IN is the "in" set of the traditional dataflow sense
   which is the confluence of out sets of all predecessor blocks.
   The difference between IN and TOP is 
   due to the artificial defs and uses at the top (DF_REF_TOP)
   (e.g. exception handling dispatch block, which can have
   a few registers defined by the runtime) - which is NOT included
   in the "in" set before this function but is included after.  
   For the initial live set of forward scanning, TOP should be used
   instead of IN - otherwise, artificial defs won't be in IN set
   causing the bad transformation. TOP set can not simply be
   the union of IN set and artificial defs at the top, 
   because artificial defs might not be used at all,
   in which case those defs are not live at any point
   (except as a dangling def) - hence TOP has to be calculated
   during the LR problem computation and stored in df_lr_bb_info.  */

struct df_lr_bb_info 
{
  /* Local sets to describe the basic blocks.  */
  bitmap def;   /* The set of registers set in this block 
                   - except artificial defs at the top.  */
  bitmap use;   /* The set of registers used in this block.  */
  bitmap adef;  /* The artificial defs at top. */
  bitmap ause;  /* The artificial uses at top. */

  /* The results of the dataflow problem.  */
  bitmap in;    /* Just before the block itself. */
  bitmap top;   /* Just before the first insn in the block. */
  bitmap out;   /* At the bottom of the block.  */
};



/* Uninitialized registers.  All bitmaps are referenced by the register number.  */
struct df_ur_bb_info 
{
  /* Local sets to describe the basic blocks.  */
  bitmap kill;  /* The set of registers unset in this block.  Calls,
		   for instance, unset registers.  */
  bitmap gen;   /* The set of registers set in this block.  */

  /* The results of the dataflow problem.  */
  bitmap in;    /* At the top of the block.  */
  bitmap out;   /* At the bottom of the block.  */
};

/* Anded results of LR and UR.  */
struct df_live_bb_info 
{
  /* The results of the dataflow problem.  */
  bitmap in;    /* At the top of the block.  */
  bitmap out;   /* At the bottom of the block.  */
};


/* Uninitialized registers.  All bitmaps are referenced by the register number.  */
struct df_urec_bb_info 
{
  /* Local sets to describe the basic blocks.  */
  bitmap earlyclobber;  /* The set of registers that are referenced
			   with an an early clobber mode.  */
  /* Kill and gen are defined as in the UR problem.  */
  bitmap kill;
  bitmap gen;

  /* The results of the dataflow problem.  */
  bitmap in;    /* Just before the block.  */
  bitmap top;   /* Just before the first insn in the block. */
  bitmap out;   /* At the bottom of the block.  */
};


/* This is used for debugging and for the dumpers to find the latest
   instance so that the df info can be added to the dumps.  This
   should not be used by regular code.  */ 
extern struct df *df;
#define df_scan  (df->problems_by_index[DF_SCAN])
#define df_ru    (df->problems_by_index[DF_RU])
#define df_rd    (df->problems_by_index[DF_RD])
#define df_lr    (df->problems_by_index[DF_LR])
#define df_ur    (df->problems_by_index[DF_UR])
#define df_live  (df->problems_by_index[DF_LIVE])
#define df_urec  (df->problems_by_index[DF_UREC])
#define df_chain (df->problems_by_index[DF_CHAIN])
#define df_ri    (df->problems_by_index[DF_RI])

/* This symbol turns on checking that each modfication of the cfg has
  been identified to the appropriate df routines.  It is not part of
  verification per se because the check that the final solution has
  not changed covers this.  However, if the solution is not being
  properly recomputed because the cfg is being modified, adding in
  calls to df_check_cfg_clean can be used to find the source of that
  kind of problem.  */
#if 0
#define DF_DEBUG_CFG
#endif

/* Functions defined in df-core.c.  */

extern void df_add_problem (struct df_problem *);
extern enum df_changeable_flags df_set_flags (enum df_changeable_flags);
extern enum df_changeable_flags df_clear_flags (enum df_changeable_flags);
extern void df_set_blocks (bitmap);
extern void df_remove_problem (struct dataflow *);
extern void df_finish_pass (void);
extern void df_analyze_problem (struct dataflow *, bitmap, int *, int);
extern void df_analyze (void);
extern int df_get_n_blocks (void);
extern int *df_get_postorder (void);
extern void df_simple_iterative_dataflow (enum df_flow_dir, df_init_function,
					  df_confluence_function_0, df_confluence_function_n,
					  df_transfer_function, bitmap, int *, int);
extern void df_mark_solutions_dirty (void);
extern bool df_get_bb_dirty (basic_block);
extern void df_set_bb_dirty (basic_block);
extern void df_compact_blocks (void);
extern void df_bb_replace (int, basic_block);
extern void df_bb_delete (int);
extern void df_verify (void);
#ifdef DF_DEBUG_CFG
extern void df_check_cfg_clean (void);
#endif
extern struct df_ref *df_bb_regno_last_use_find (basic_block, unsigned int);
extern struct df_ref *df_bb_regno_first_def_find (basic_block, unsigned int);
extern struct df_ref *df_bb_regno_last_def_find (basic_block, unsigned int);
extern bool df_insn_regno_def_p (rtx, unsigned int);
extern struct df_ref *df_find_def (rtx, rtx);
extern bool df_reg_defined (rtx, rtx);
extern struct df_ref *df_find_use (rtx, rtx);
extern bool df_reg_used (rtx, rtx);
extern void df_iterative_dataflow (struct dataflow *,bitmap, int *, int);
extern void df_print_regset (FILE *file, bitmap r);
extern void df_dump (FILE *);
extern void df_dump_start (FILE *);
extern void df_dump_top (basic_block, FILE *);
extern void df_dump_bottom (basic_block, FILE *);
extern void df_refs_chain_dump (struct df_ref *, bool, FILE *);
extern void df_regs_chain_dump (struct df_ref *,  FILE *);
extern void df_insn_debug (rtx, bool, FILE *);
extern void df_insn_debug_regno (rtx, FILE *);
extern void df_regno_debug (unsigned int, FILE *);
extern void df_ref_debug (struct df_ref *, FILE *);
extern void debug_df_insn (rtx);
extern void debug_df_regno (unsigned int);
extern void debug_df_reg (rtx);
extern void debug_df_defno (unsigned int);
extern void debug_df_useno (unsigned int);
extern void debug_df_ref (struct df_ref *);
extern void debug_df_chain (struct df_link *);

/* Functions defined in df-problems.c. */

extern struct df_link *df_chain_create (struct df_ref *, struct df_ref *);
extern void df_chain_unlink (struct df_ref *);
extern void df_chain_copy (struct df_ref *, struct df_link *);
extern bitmap df_get_live_in (basic_block);
extern bitmap df_get_live_top (basic_block);
extern void df_grow_bb_info (struct dataflow *);
extern void df_chain_dump (struct df_link *, FILE *);
extern void df_print_bb_index (basic_block bb, FILE *file);
extern void df_ru_add_problem (void);
extern struct df_ru_bb_info *df_ru_get_bb_info (unsigned int);
extern void df_rd_add_problem (void);
extern struct df_rd_bb_info *df_rd_get_bb_info (unsigned int);
extern struct df_lr_bb_info *df_lr_get_bb_info (unsigned int);
extern void df_lr_simulate_artificial_refs_at_end (basic_block, bitmap);
extern void df_lr_simulate_one_insn (basic_block, rtx, bitmap);
extern void df_lr_add_problem (void);
extern void df_lr_verify_transfer_functions (void);
extern void df_ur_add_problem (void);
extern void df_ur_verify_transfer_functions (void);
extern struct df_ur_bb_info *df_ur_get_bb_info (unsigned int);
extern void df_live_add_problem (void);
extern struct df_live_bb_info *df_live_get_bb_info (unsigned int);
extern void df_urec_add_problem (void);
extern struct df_urec_bb_info *df_urec_get_bb_info (unsigned int);
extern void df_chain_add_problem (enum df_chain_flags);
extern void df_ri_add_problem (enum df_ri_flags);
extern bitmap df_ri_get_setjmp_crosses (void);

/* Functions defined in df-scan.c.  */

extern void df_scan_alloc (bitmap);
extern struct df_scan_bb_info *df_scan_get_bb_info (unsigned int);
extern void df_scan_add_problem (void);
extern void df_grow_reg_info (void);
extern void df_scan_blocks (void);
extern struct df_ref *df_ref_create (rtx, rtx *, rtx,basic_block, 
				     enum df_ref_type, enum df_ref_flags);
extern struct df_ref *df_get_artificial_defs (unsigned int);
extern struct df_ref *df_get_artificial_uses (unsigned int);
extern void df_reg_chain_create (struct df_reg_info *, struct df_ref *);
extern struct df_ref *df_reg_chain_unlink (struct df_ref *);
extern void df_ref_remove (struct df_ref *);
extern struct df_insn_info * df_insn_create_insn_record (rtx);
extern void df_insn_delete (basic_block, unsigned int);
extern void df_bb_refs_record (int, bool);
extern bool df_insn_rescan (rtx);
extern void df_insn_rescan_all (void);
extern void df_process_deferred_rescans (void);
extern void df_insn_refs_record (rtx, struct df_ref *);
extern bool df_has_eh_preds (basic_block);
extern void df_recompute_luids (basic_block);
extern void df_insn_change_bb (rtx);
extern void df_maybe_reorganize_use_refs (void);
extern void df_maybe_reorganize_def_refs (void);
extern void df_drop_organized_tables (void);
extern void df_ref_change_reg_with_loc (int, int, rtx);
extern void df_notes_rescan (rtx);
extern void df_hard_reg_init (void);
extern void df_update_entry_block_defs (void);
extern void df_update_exit_block_uses (void);
extern void df_update_entry_exit_and_calls (void);
extern bool df_hard_reg_used_p (unsigned int);
extern bool df_regs_ever_live_p (unsigned int);
extern void df_set_regs_ever_live (unsigned int, bool);
extern void df_compute_regs_ever_live (bool);
extern bool df_read_modify_subreg_p (rtx);
extern void df_scan_verify (void);

/* web */

/* This entry is allocated for each reference in the insn stream.  */
struct web_entry
{
  /* Pointer to the parent in the union/find tree.  */
  struct web_entry *pred;
  /* Newly assigned register to the entry.  Set only for roots.  */
  rtx reg;
  void* extra_info;
};

extern struct web_entry *unionfind_root (struct web_entry *);
extern bool unionfind_union (struct web_entry *, struct web_entry *);
extern void union_defs (struct df_ref *,
                        struct web_entry *, struct web_entry *,
			bool (*fun) (struct web_entry *, struct web_entry *));


#endif /* GCC_DF_H */
