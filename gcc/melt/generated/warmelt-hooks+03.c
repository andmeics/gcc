/* GCC MELT GENERATED FILE warmelt-hooks+03.c - DO NOT EDIT */
/* secondary MELT generated C file of rank #3 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f3[] =
  MELT_RUN_HASHMD5 /* from melt-run.h */ ;


/**** warmelt-hooks+03.c declarations ****/
/**** MELT GENERATED DECLARATIONS for warmelt-hooks ** DO NOT EDIT ; see gcc-melt.org ****/

/****++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
***
    Copyright 2012 - 2013 Free Software Foundation, Inc.
    Contributed by Basile Starynkevitch <basile@starynkevitch.net>

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
    <http://www.gnu.org/licenses/>.
***
----------------------------------------------------------------****/


/** ordinary MELT module meltbuild-sources/warmelt-hooks**/
#define MELT_HAS_INITIAL_ENVIRONMENT 1	/*usualmodule */


/*** 3 MELT module variables declarations ****/
MELT_EXTERN void melt_forwarding_module_data (void);
MELT_EXTERN void melt_marking_module_data (void);

MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY
  melt_WARMELTmiHOOKS_module_var_ptr_tab[16];
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melt_WARMELTmiHOOKS_module_var_flags[1];

static inline melt_ptr_t
melt_module_var_fetch (int ix)
{
  return (ix > 0
	  && ix <= 3) ? melt_WARMELTmiHOOKS_module_var_ptr_tab[ix] : NULL;
}

static inline void
melt_module_var_put (int ix, melt_ptr_t val)
{
  if (ix > 0 && ix <= 3)
    {
      melt_WARMELTmiHOOKS_module_var_ptr_tab[ix] = val;
      melt_WARMELTmiHOOKS_module_var_flags[ix / 16] = true;
    }
}

/* MELT module variables indexes */
enum
{
  meltmodatix_none,
  meltmodvarix_MELT_INPCHANBUCK_symb = 1,
  meltmodvarix_MELT_ALARMBUCKET_symb = 2,
  meltmodvarix_MELT_CHILDBUCK_symb = 3,
  meltmodatix_last
};				/* end MELT module variables indexes */

/*** 3 MELT called hook declarations ***/

/*declare MELT called hook #0 HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER **/
MELT_EXTERN melt_ptr_t
melthook_HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER (melt_ptr_t melthookdata,
						 melt_ptr_t meltinp0_PREVENV,
						 const char
						 *meltinp1_MODULNAME);

/*declare MELT called hook #1 HOOK_SYMBOL_IMPORTER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_SYMBOL_IMPORTER (melt_ptr_t melthookdata,
						      const char
						      *meltinp0_SYMNAMESTR,
						      const char
						      *meltinp1_MODULENAMESTR,
						      melt_ptr_t
						      meltinp2_PARENV);

/*declare MELT called hook #2 HOOK_VALUE_EXPORTER **/
MELT_EXTERN void melthook_HOOK_VALUE_EXPORTER (melt_ptr_t melthookdata,
					       melt_ptr_t meltinp0_SYM,
					       melt_ptr_t meltinp1_VAL,
					       melt_ptr_t meltinp2_CONTENV);

/*** end of 3 MELT called hook declarations ***/

/*** 27 extra MELT c-headers ***/


/** MELT extra c-header 1 : **/


static void
melt_override_gate_callback (void *gccdata, void *userdata ATTRIBUTE_UNUSED)
{
  bool *pgatestatus = (bool *) gccdata;
  bool gatsta = false;
  long oldgatstalng = 0, newgatstalng = 0;
  gcc_assert (pgatestatus != NULL);
  gatsta = *pgatestatus;
  oldgatstalng = newgatstalng = (long) gatsta;
  melthookproc_HOOK_OVERRIDE_GATE (oldgatstalng, &newgatstalng);
  gatsta = (newgatstalng != 0L);
  *pgatestatus = gatsta;
}				/* end of  melt_override_gate_callback */

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 2 : **/

/* flag for PLUGIN_OVERRIDE_GATE */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_override_gate_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 3 : **/

/* flag for PLUGIN_START_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_start_unit_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 4 : **/


void MELT_MODULE_VISIBILITY
melt_startunithook_callback (void *gcc_data ATTRIBUTE_UNUSED,
			     void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 5 : **/

/* flag for PLUGIN_FINISH_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_finish_unit_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 6 : **/


void MELT_MODULE_VISIBILITY
melt_finishunithook_callback (void *gcc_data ATTRIBUTE_UNUSED,
			      void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 7 : **/

/* flag for PLUGIN_ALL_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melthk_all_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 8 : **/


void MELT_MODULE_VISIBILITY
melt_all_passes_start_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				     void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 9 : **/

/* flag for PLUGIN_ALL_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_all_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 10 : **/


void MELT_MODULE_VISIBILITY
melt_all_passes_end_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				   void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 11 : **/

/* flag for PLUGIN_ALL_IPA_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melthk_all_ipa_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 12 : **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_start_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
					 void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 13 : **/

/* flag for PLUGIN_ALL_IPA_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melthk_all_ipa_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 14 : **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_end_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				       void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 15 : **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melthk_early_gimple_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 16 : **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_start_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
					      void *user_data
					      ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 17 : **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY
  melthk_early_gimple_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 18 : **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_end_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
					    void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 19 : **/

/* flag for PLUGIN_PRE_GENERICIZE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_pre_genericize_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 20 : **/


void MELT_MODULE_VISIBILITY
melt_pre_genericize_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				   void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 21 : **/

/* flag for PLUGIN_FINISH_TYPE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_finish_type_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 22 : **/


void MELT_MODULE_VISIBILITY
melt_finish_type_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 23 : **/

/* flag for PLUGIN_FINISH_DECL declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_finish_decl_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 24 : **/


void MELT_MODULE_VISIBILITY
melt_finish_decl_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 25 : **/

/* flag for PLUGIN_PASS_EXECUTION declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY melthk_pass_execution_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 26 : **/


void MELT_MODULE_VISIBILITY
melt_pass_execution_hook_callback (void *gcc_data ATTRIBUTE_UNUSED,
				   void *user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 27 : **/

 /* header from warmelt-hooks.melt for poll etc... */
#include <poll.h>

#define MELT_BUFSIZE 8192
#define MELT_POLL_DELAY_MILLISEC 500

/*** end of 27 extra MELT c-headers ***/

/** declaration of hook melthook_HOOK_LOW_DEBUG_VALUE_AT */
MELT_EXTERN
  void melthook_HOOK_LOW_DEBUG_VALUE_AT (melt_ptr_t melthookdata,
					 melt_ptr_t meltinp0_VAL,
					 const char *meltinp1_FILENAME,
					 long meltinp2_LINENO,
					 const char *meltinp3_MSG,
					 long meltinp4_COUNT);


/* declare hook frame marking routine for melthook_HOOK_LOW_DEBUG_VALUE_AT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_LOW_DEBUG_VALUE_AT_rout (struct
								       melt_callframe_st
								       *,
								       int);




/** declaration of hook melthook_HOOK_OVERRIDE_GATE */
MELT_EXTERN
  void melthook_HOOK_OVERRIDE_GATE (melt_ptr_t melthookdata,
				    long meltinp0_BEFOREGATE,
				    long *meltoutp0_AFTERGATE);


/* declare hook frame marking routine for melthook_HOOK_OVERRIDE_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_OVERRIDE_GATE_rout (struct
								  melt_callframe_st
								  *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_3_WARMELTmiHOOKS_ENABLE_OVERRIDE_GATE (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_4_WARMELTmiHOOKS_MAYBE_DISABLE_OVERRIDE_GATE (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_5_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_FIRST (meltclosure_ptr_t
							meltclosp_,
							melt_ptr_t
							meltfirstargp_,
							const
							melt_argdescr_cell_t
							meltxargdescr_[],
							union meltparam_un
							*meltxargtab_,
							const
							melt_argdescr_cell_t
							meltxresdescr_[],
							union meltparam_un
							*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_6_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_LAST (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_7_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_FIRST (meltclosure_ptr_t
							  meltclosp_,
							  melt_ptr_t
							  meltfirstargp_,
							  const
							  melt_argdescr_cell_t
							  meltxargdescr_[],
							  union meltparam_un
							  *meltxargtab_,
							  const
							  melt_argdescr_cell_t
							  meltxresdescr_[],
							  union meltparam_un
							  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_8_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_LAST (meltclosure_ptr_t
							 meltclosp_,
							 melt_ptr_t
							 meltfirstargp_,
							 const
							 melt_argdescr_cell_t
							 meltxargdescr_[],
							 union meltparam_un
							 *meltxargtab_,
							 const
							 melt_argdescr_cell_t
							 meltxresdescr_[],
							 union meltparam_un
							 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_9_WARMELTmiHOOKS_LAMBDA_cl1 (meltclosure_ptr_t meltclosp_,
				      melt_ptr_t meltfirstargp_,
				      const melt_argdescr_cell_t
				      meltxargdescr_[],
				      union meltparam_un *meltxargtab_,
				      const melt_argdescr_cell_t
				      meltxresdescr_[],
				      union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_10_WARMELTmiHOOKS_LAMBDA_cl2 (meltclosure_ptr_t meltclosp_,
				       melt_ptr_t meltfirstargp_,
				       const melt_argdescr_cell_t
				       meltxargdescr_[],
				       union meltparam_un *meltxargtab_,
				       const melt_argdescr_cell_t
				       meltxresdescr_[],
				       union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_11_WARMELTmiHOOKS_LAMBDA_cl3 (meltclosure_ptr_t meltclosp_,
				       melt_ptr_t meltfirstargp_,
				       const melt_argdescr_cell_t
				       meltxargdescr_[],
				       union meltparam_un *meltxargtab_,
				       const melt_argdescr_cell_t
				       meltxresdescr_[],
				       union meltparam_un *meltxrestab_);

/** declaration of hook melthook_HOOK_START_UNIT */
MELT_EXTERN void melthook_HOOK_START_UNIT (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_START_UNIT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_START_UNIT_rout (struct
							       melt_callframe_st
							       *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_13_WARMELTmiHOOKS_ENABLE_START_UNIT (meltclosure_ptr_t meltclosp_,
					      melt_ptr_t meltfirstargp_,
					      const melt_argdescr_cell_t
					      meltxargdescr_[],
					      union meltparam_un
					      *meltxargtab_,
					      const melt_argdescr_cell_t
					      meltxresdescr_[],
					      union meltparam_un
					      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_14_WARMELTmiHOOKS_AT_START_UNIT_FIRST (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_LAST (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_16_WARMELTmiHOOKS_LAMBDA_cl4 (meltclosure_ptr_t meltclosp_,
				       melt_ptr_t meltfirstargp_,
				       const melt_argdescr_cell_t
				       meltxargdescr_[],
				       union meltparam_un *meltxargtab_,
				       const melt_argdescr_cell_t
				       meltxresdescr_[],
				       union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_17_WARMELTmiHOOKS_LAMBDA_cl5 (meltclosure_ptr_t meltclosp_,
				       melt_ptr_t meltfirstargp_,
				       const melt_argdescr_cell_t
				       meltxargdescr_[],
				       union meltparam_un *meltxargtab_,
				       const melt_argdescr_cell_t
				       meltxresdescr_[],
				       union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_18_WARMELTmiHOOKS_LAMBDA_cl6 (meltclosure_ptr_t meltclosp_,
				       melt_ptr_t meltfirstargp_,
				       const melt_argdescr_cell_t
				       meltxargdescr_[],
				       union meltparam_un *meltxargtab_,
				       const melt_argdescr_cell_t
				       meltxresdescr_[],
				       union meltparam_un *meltxrestab_);

/** declaration of hook melthook_HOOK_FINISH_UNIT */
MELT_EXTERN void melthook_HOOK_FINISH_UNIT (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_FINISH_UNIT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_UNIT_rout (struct
								melt_callframe_st
								*, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_20_WARMELTmiHOOKS_ENABLE_FINISH_UNIT (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_21_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST (meltclosure_ptr_t meltclosp_,
						melt_ptr_t meltfirstargp_,
						const melt_argdescr_cell_t
						meltxargdescr_[],
						union meltparam_un
						*meltxargtab_,
						const melt_argdescr_cell_t
						meltxresdescr_[],
						union meltparam_un
						*meltxrestab_);

/** declaration of hook melthook_HOOK_ALL_PASSES_START */
MELT_EXTERN void melthook_HOOK_ALL_PASSES_START (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_ALL_PASSES_START hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_PASSES_START_rout (struct
								     melt_callframe_st
								     *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_24_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_25_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST (meltclosure_ptr_t
							    meltclosp_,
							    melt_ptr_t
							    meltfirstargp_,
							    const
							    melt_argdescr_cell_t
							    meltxargdescr_[],
							    union meltparam_un
							    *meltxargtab_,
							    const
							    melt_argdescr_cell_t
							    meltxresdescr_[],
							    union meltparam_un
							    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   *meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   *meltxrestab_);

/** declaration of hook melthook_HOOK_ALL_PASSES_END */
MELT_EXTERN void melthook_HOOK_ALL_PASSES_END (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_ALL_PASSES_END hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_PASSES_END_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_28_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_29_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST (meltclosure_ptr_t
							  meltclosp_,
							  melt_ptr_t
							  meltfirstargp_,
							  const
							  melt_argdescr_cell_t
							  meltxargdescr_[],
							  union meltparam_un
							  *meltxargtab_,
							  const
							  melt_argdescr_cell_t
							  meltxresdescr_[],
							  union meltparam_un
							  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST (meltclosure_ptr_t
							 meltclosp_,
							 melt_ptr_t
							 meltfirstargp_,
							 const
							 melt_argdescr_cell_t
							 meltxargdescr_[],
							 union meltparam_un
							 *meltxargtab_,
							 const
							 melt_argdescr_cell_t
							 meltxresdescr_[],
							 union meltparam_un
							 *meltxrestab_);

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_START */
MELT_EXTERN void melthook_HOOK_ALL_IPA_PASSES_START (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_ALL_IPA_PASSES_START hook */
void MELT_MODULE_VISIBILITY
melthookmark_HOOK_ALL_IPA_PASSES_START_rout (struct melt_callframe_st *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_32_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START (meltclosure_ptr_t
							meltclosp_,
							melt_ptr_t
							meltfirstargp_,
							const
							melt_argdescr_cell_t
							meltxargdescr_[],
							union meltparam_un
							*meltxargtab_,
							const
							melt_argdescr_cell_t
							meltxresdescr_[],
							union meltparam_un
							*meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_33_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_END */
MELT_EXTERN void melthook_HOOK_ALL_IPA_PASSES_END (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_ALL_IPA_PASSES_END hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_IPA_PASSES_END_rout (struct
								       melt_callframe_st
								       *,
								       int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_36_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_37_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST (meltclosure_ptr_t
							     meltclosp_,
							     melt_ptr_t
							     meltfirstargp_,
							     const
							     melt_argdescr_cell_t
							     meltxargdescr_[],
							     union
							     meltparam_un
							     *meltxargtab_,
							     const
							     melt_argdescr_cell_t
							     meltxresdescr_[],
							     union
							     meltparam_un
							     *meltxrestab_);

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_START */
MELT_EXTERN
  void melthook_HOOK_EARLY_GIMPLE_PASSES_START (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_EARLY_GIMPLE_PASSES_START hook */
void MELT_MODULE_VISIBILITY
melthookmark_HOOK_EARLY_GIMPLE_PASSES_START_rout (struct melt_callframe_st *,
						  int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_40_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START (meltclosure_ptr_t
							     meltclosp_,
							     melt_ptr_t
							     meltfirstargp_,
							     const
							     melt_argdescr_cell_t
							     meltxargdescr_[],
							     union
							     meltparam_un
							     *meltxargtab_,
							     const
							     melt_argdescr_cell_t
							     meltxresdescr_[],
							     union
							     meltparam_un
							     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_41_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_END */
MELT_EXTERN
  void melthook_HOOK_EARLY_GIMPLE_PASSES_END (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_EARLY_GIMPLE_PASSES_END hook */
void MELT_MODULE_VISIBILITY
melthookmark_HOOK_EARLY_GIMPLE_PASSES_END_rout (struct melt_callframe_st *,
						int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_44_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_END (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   *meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_45_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_FIRST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_46_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_LAST
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_47_WARMELTmiHOOKS_ENABLE_PRE_GENERICIZE (meltclosure_ptr_t
						  meltclosp_,
						  melt_ptr_t meltfirstargp_,
						  const melt_argdescr_cell_t
						  meltxargdescr_[],
						  union meltparam_un
						  *meltxargtab_,
						  const melt_argdescr_cell_t
						  meltxresdescr_[],
						  union meltparam_un
						  *meltxrestab_);

/** declaration of hook melthook_HOOK_PRE_GENERICIZE */
MELT_EXTERN
  void melthook_HOOK_PRE_GENERICIZE (melt_ptr_t melthookdata,
				     tree meltinp0_TFNDECL);


/* declare hook frame marking routine for melthook_HOOK_PRE_GENERICIZE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_PRE_GENERICIZE_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_49_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_FIRST (meltclosure_ptr_t
							  meltclosp_,
							  melt_ptr_t
							  meltfirstargp_,
							  const
							  melt_argdescr_cell_t
							  meltxargdescr_[],
							  union meltparam_un
							  *meltxargtab_,
							  const
							  melt_argdescr_cell_t
							  meltxresdescr_[],
							  union meltparam_un
							  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_50_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_LAST (meltclosure_ptr_t
							 meltclosp_,
							 melt_ptr_t
							 meltfirstargp_,
							 const
							 melt_argdescr_cell_t
							 meltxargdescr_[],
							 union meltparam_un
							 *meltxargtab_,
							 const
							 melt_argdescr_cell_t
							 meltxresdescr_[],
							 union meltparam_un
							 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_51_WARMELTmiHOOKS_ENABLE_FINISH_TYPE (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);

/** declaration of hook melthook_HOOK_FINISH_TYPE */
MELT_EXTERN
  void melthook_HOOK_FINISH_TYPE (melt_ptr_t melthookdata,
				  tree meltinp0_TFNDECL);


/* declare hook frame marking routine for melthook_HOOK_FINISH_TYPE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_TYPE_rout (struct
								melt_callframe_st
								*, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_53_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_FIRST (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_54_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_LAST (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_55_WARMELTmiHOOKS_RUN_ENDMELTPASS_FUNCTIONS (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_56_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_FIRST (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   *meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_57_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_LAST (meltclosure_ptr_t
							  meltclosp_,
							  melt_ptr_t
							  meltfirstargp_,
							  const
							  melt_argdescr_cell_t
							  meltxargdescr_[],
							  union meltparam_un
							  *meltxargtab_,
							  const
							  melt_argdescr_cell_t
							  meltxresdescr_[],
							  union meltparam_un
							  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_58_WARMELTmiHOOKS_ENABLE_FINISH_DECL (meltclosure_ptr_t meltclosp_,
					       melt_ptr_t meltfirstargp_,
					       const melt_argdescr_cell_t
					       meltxargdescr_[],
					       union meltparam_un
					       *meltxargtab_,
					       const melt_argdescr_cell_t
					       meltxresdescr_[],
					       union meltparam_un
					       *meltxrestab_);

/** declaration of hook melthook_HOOK_FINISH_DECL */
MELT_EXTERN
  void melthook_HOOK_FINISH_DECL (melt_ptr_t melthookdata,
				  tree meltinp0_TFNDECL);


/* declare hook frame marking routine for melthook_HOOK_FINISH_DECL hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_DECL_rout (struct
								melt_callframe_st
								*, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_60_WARMELTmiHOOKS_REGISTER_FINISH_DECL_FIRST (meltclosure_ptr_t
						       meltclosp_,
						       melt_ptr_t
						       meltfirstargp_,
						       const
						       melt_argdescr_cell_t
						       meltxargdescr_[],
						       union meltparam_un
						       *meltxargtab_,
						       const
						       melt_argdescr_cell_t
						       meltxresdescr_[],
						       union meltparam_un
						       *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_61_WARMELTmiHOOKS_REGISTER_FINISH_DECL_LAST (meltclosure_ptr_t
						      meltclosp_,
						      melt_ptr_t
						      meltfirstargp_,
						      const
						      melt_argdescr_cell_t
						      meltxargdescr_[],
						      union meltparam_un
						      *meltxargtab_,
						      const
						      melt_argdescr_cell_t
						      meltxresdescr_[],
						      union meltparam_un
						      *meltxrestab_);

/** declaration of hook melthook_HOOK_PASS_EXECUTION */
MELT_EXTERN
  void melthook_HOOK_PASS_EXECUTION (melt_ptr_t melthookdata,
				     const char *meltinp0_PASSNAME,
				     long meltinp1_PASSNUM);


/* declare hook frame marking routine for melthook_HOOK_PASS_EXECUTION hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_PASS_EXECUTION_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_63_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_FIRST (meltclosure_ptr_t
							  meltclosp_,
							  melt_ptr_t
							  meltfirstargp_,
							  const
							  melt_argdescr_cell_t
							  meltxargdescr_[],
							  union meltparam_un
							  *meltxargtab_,
							  const
							  melt_argdescr_cell_t
							  meltxresdescr_[],
							  union meltparam_un
							  *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_64_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_LAST (meltclosure_ptr_t
							 meltclosp_,
							 melt_ptr_t
							 meltfirstargp_,
							 const
							 melt_argdescr_cell_t
							 meltxargdescr_[],
							 union meltparam_un
							 *meltxargtab_,
							 const
							 melt_argdescr_cell_t
							 meltxresdescr_[],
							 union meltparam_un
							 *meltxrestab_);

/** declaration of hook melthook_HOOK_GIMPLE_GATE */
MELT_EXTERN long melthook_HOOK_GIMPLE_GATE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_GIMPLE_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_GIMPLE_GATE_rout (struct
								melt_callframe_st
								*, int);




/** declaration of hook melthook_HOOK_GIMPLE_EXECUTE */
MELT_EXTERN long melthook_HOOK_GIMPLE_EXECUTE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_GIMPLE_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_GIMPLE_EXECUTE_rout (struct
								   melt_callframe_st
								   *, int);




/** declaration of hook melthook_HOOK_RTL_GATE */
MELT_EXTERN long melthook_HOOK_RTL_GATE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_RTL_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_RTL_GATE_rout (struct
							     melt_callframe_st
							     *, int);




/** declaration of hook melthook_HOOK_RTL_EXECUTE */
MELT_EXTERN long melthook_HOOK_RTL_EXECUTE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_RTL_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_RTL_EXECUTE_rout (struct
								melt_callframe_st
								*, int);




/** declaration of hook melthook_HOOK_SIMPLE_IPA_GATE */
MELT_EXTERN long melthook_HOOK_SIMPLE_IPA_GATE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_SIMPLE_IPA_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_SIMPLE_IPA_GATE_rout (struct
								    melt_callframe_st
								    *, int);




/** declaration of hook melthook_HOOK_SIMPLE_IPA_EXECUTE */
MELT_EXTERN long melthook_HOOK_SIMPLE_IPA_EXECUTE (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_SIMPLE_IPA_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_SIMPLE_IPA_EXECUTE_rout (struct
								       melt_callframe_st
								       *,
								       int);




/** declaration of hook melthook_HOOK_MELT_ATTRIBUTE_DEFINER */
MELT_EXTERN
  void melthook_HOOK_MELT_ATTRIBUTE_DEFINER (melt_ptr_t melthookdata,
					     tree meltinp0_DECL,
					     tree meltinp1_NAME,
					     melt_ptr_t meltinp2_ATTRSEQ,
					     const char *meltinp3_FILELOC,
					     long meltinp4_LINENO);


/* declare hook frame marking routine for melthook_HOOK_MELT_ATTRIBUTE_DEFINER hook */
void MELT_MODULE_VISIBILITY
melthookmark_HOOK_MELT_ATTRIBUTE_DEFINER_rout (struct melt_callframe_st *,
					       int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_72_WARMELTmiHOOKS_AT_MELT_ATTRIBUTE_FIRST (meltclosure_ptr_t
						    meltclosp_,
						    melt_ptr_t meltfirstargp_,
						    const melt_argdescr_cell_t
						    meltxargdescr_[],
						    union meltparam_un
						    *meltxargtab_,
						    const melt_argdescr_cell_t
						    meltxresdescr_[],
						    union meltparam_un
						    *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_73_WARMELTmiHOOKS_AT_MELT_ATTRIBUTE_LAST (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);

/** declaration of hook melthook_HOOK_EXIT_FINALIZER */
MELT_EXTERN void melthook_HOOK_EXIT_FINALIZER (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_EXIT_FINALIZER hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_EXIT_FINALIZER_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_75_WARMELTmiHOOKS_AT_EXIT_FIRST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS (meltclosure_ptr_t
							meltclosp_,
							melt_ptr_t
							meltfirstargp_,
							const
							melt_argdescr_cell_t
							meltxargdescr_[],
							union meltparam_un
							*meltxargtab_,
							const
							melt_argdescr_cell_t
							meltxresdescr_[],
							union meltparam_un
							*meltxrestab_);

/** declaration of hook melthook_HOOK_POLL_INPUTS */
MELT_EXTERN
  void melthook_HOOK_POLL_INPUTS (melt_ptr_t melthookdata,
				  long meltinp0_DELAYMS);


/* declare hook frame marking routine for melthook_HOOK_POLL_INPUTS hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_POLL_INPUTS_rout (struct
								melt_callframe_st
								*, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   *meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   *meltxrestab_);

/** declaration of hook melthook_HOOK_HANDLE_SIGIO */
MELT_EXTERN void melthook_HOOK_HANDLE_SIGIO (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGIO hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGIO_rout (struct
								 melt_callframe_st
								 *, int);




/** declaration of hook melthook_HOOK_HANDLE_SIGALRM */
MELT_EXTERN void melthook_HOOK_HANDLE_SIGALRM (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGALRM hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGALRM_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un
						 *meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un
						 *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un
						   *meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un
						   *meltxrestab_);

/** declaration of hook melthook_HOOK_HANDLE_SIGCHLD */
MELT_EXTERN void melthook_HOOK_HANDLE_SIGCHLD (melt_ptr_t melthookdata);


/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGCHLD hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGCHLD_rout (struct
								   melt_callframe_st
								   *, int);







melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   *meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER (meltclosure_ptr_t
							     meltclosp_,
							     melt_ptr_t
							     meltfirstargp_,
							     const
							     melt_argdescr_cell_t
							     meltxargdescr_[],
							     union
							     meltparam_un
							     *meltxargtab_,
							     const
							     melt_argdescr_cell_t
							     meltxresdescr_[],
							     union
							     meltparam_un
							     *meltxrestab_);



MELT_EXTERN void *melt_start_this_module (void *);
struct melt_initial_frame_st;

/*declare opaque initial frame: */
typedef struct melt_initial_frame_st meltinitial_frame_t;


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG */
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG */



void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_0 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_1 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_2 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_3 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_4 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_5 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_6 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_7 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_8 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_9 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__initialmeltchunk_10 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiHOOKS__forward_or_mark_module_start_frame (struct
							     melt_callframe_st
							     *fp,
							     int marking);



/**** warmelt-hooks+03.c implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_)
{
  long current_blocklevel_signals_meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 3
    melt_ptr_t mcfr_varptr[3];
#define MELTFRAM_NBVARNUM 1
    long mcfr_varnum[1];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST_st *)
	meltfirstargp_;
      /* use arguments meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 3; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST nbval 3*/
  meltfram__.mcfr_nbvar = 3 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("AT_EXIT_LAST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2241:/ getarg");
 /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {

    MELT_LOCATION ("warmelt-hooks.melt:2244:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj =
	(melt_ptr_t) (( /*!FINAL_EXIT_DELAYED_QUEUE */ meltfrout->
		       tabval[0])) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "DELQU_LAST");
  /*_.LASTLIST__V3*/ meltfptr[2] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_CLOSURE__L1*/ meltfnum[0] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.FUN__V2*/ meltfptr[1])) ==
       MELTOBMAG_CLOSURE);;
    MELT_LOCATION ("warmelt-hooks.melt:2246:/ cond");
    /*cond */ if ( /*_#IS_CLOSURE__L1*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  {
	    /*^locexp */
	    meltgc_append_list ((melt_ptr_t)
				( /*_.LASTLIST__V3*/ meltfptr[2]),
				(melt_ptr_t) ( /*_.FUN__V2*/ meltfptr[1]));
	  }
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;

    MELT_LOCATION ("warmelt-hooks.melt:2244:/ clear");
	   /*clear *//*_.LASTLIST__V3*/ meltfptr[2] = 0;
    /*^clear */
	   /*clear *//*_#IS_CLOSURE__L1*/ meltfnum[0] = 0;
    /*epilog */
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("AT_EXIT_LAST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_76_WARMELTmiHOOKS_AT_EXIT_LAST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS (meltclosure_ptr_t
							meltclosp_,
							melt_ptr_t
							meltfirstargp_,
							const
							melt_argdescr_cell_t
							meltxargdescr_[],
							union meltparam_un *
							meltxargtab_,
							const
							melt_argdescr_cell_t
							meltxresdescr_[],
							union meltparam_un *
							meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 42
    melt_ptr_t mcfr_varptr[42];
#define MELTFRAM_NBVARNUM 23
    long mcfr_varnum[23];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS_st
	 *) meltfirstargp_;
      /* use arguments meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 42; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS nbval 42*/
  meltfram__.mcfr_nbvar = 42 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("MELT_INVOKE_INPUT_CALLBACKS", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2315:/ getarg");
 /*_.TUPINCH__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.TUPSTATE__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.TUPSTATE__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#NBINS__L1*/ meltfnum[0] = meltxargtab_[1].meltbp_long;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2316:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L2*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2316:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L3*/ meltfnum[2] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2316:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2316;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"melt_invoke_input_callbacks tupinch=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPINCH__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n.. tupstate=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPSTATE__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = "\n.. nbins=";
	      /*^apply.arg */
	      argtab[8].meltbp_long = /*_#NBINS__L1*/ meltfnum[0];
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V4*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2316:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V4*/ meltfptr[3] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2316:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock BLOCK_SIGNALS */
    {
      /* block_signals meltcit1__BLKSIGNAL start */
      long meltcit1__BLKSIGNAL_lev = melt_blocklevel_signals;
      melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev + 1;



      MELT_LOCATION ("warmelt-hooks.melt:2321:/ quasiblock");


  /*_.REMOVELIST__V6*/ meltfptr[4] =
	(meltgc_new_list
	 ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[1]))));;
      /*^compute */
  /*_.BUCK__V7*/ meltfptr[3] =
	(melt_module_var_fetch (meltmodvarix_MELT_INPCHANBUCK_symb));;
      /*^compute */
  /*_#miI__L4*/ meltfnum[2] =
	(( /*_#NBINS__L1*/ meltfnum[0]) - (1));;
      /*citerblock FOREACH_LONG_UPTO */
      {
	/* foreach_long_upto start meltcit2__EACHLONG */
	long meltcit2__EACHLONG_min = 0;
	long meltcit2__EACHLONG_max = /*_#miI__L4*/ meltfnum[2];
	long meltcit2__EACHLONG_cur = 0;
	for (meltcit2__EACHLONG_cur = meltcit2__EACHLONG_min;
	     meltcit2__EACHLONG_cur <= meltcit2__EACHLONG_max;
	     meltcit2__EACHLONG_cur++)
	  {
	    /*_#IX__L5*/ meltfnum[1] = meltcit2__EACHLONG_cur;



	    MELT_LOCATION ("warmelt-hooks.melt:2327:/ quasiblock");


   /*_.CURINCH__V9*/ meltfptr[8] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.TUPINCH__V2*/ meltfptr[1]),
		( /*_#IX__L5*/ meltfnum[1])));;
	    /*^compute */
   /*_.CURSTATE__V10*/ meltfptr[9] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.TUPSTATE__V3*/ meltfptr[2]),
		( /*_#IX__L5*/ meltfnum[1])));;
	    /*^compute */
   /*_#CURFD__L6*/ meltfnum[5] =
	      (melt_get_int ((melt_ptr_t) ( /*_.CURINCH__V9*/ meltfptr[8])));;
	    /*^compute */
   /*_#READCNT__L7*/ meltfnum[6] = -2;;
	    MELT_LOCATION ("warmelt-hooks.melt:2331:/ cond");
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.CURINCH__V9*/
						 meltfptr[8]),
						(melt_ptr_t) (( /*!CLASS_INPUT_CHANNEL_HANDLER */ meltfrout->tabval[2])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^getslot */
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.CURINCH__V9*/ meltfptr[8]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 1, "INCH_SBUF");
     /*_.SBUF__V11*/ meltfptr[10] = slot;
		};
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.SBUF__V11*/ meltfptr[10] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2332:/ cond");
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.CURINCH__V9*/
						 meltfptr[8]),
						(melt_ptr_t) (( /*!CLASS_INPUT_CHANNEL_HANDLER */ meltfrout->tabval[2])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^getslot */
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.CURINCH__V9*/ meltfptr[8]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 2, "INCH_CLOS");
     /*_.CLOS__V12*/ meltfptr[11] = slot;
		};
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.CLOS__V12*/ meltfptr[11] = NULL;;
	      }
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-hooks.melt:2334:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      {
		/*^locexp */
		/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		melt_dbgcounter++;
#endif
		;
	      }
	      ;

	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#MELT_NEED_DBG__L8*/ meltfnum[7] =
		/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		;;
	      MELT_LOCATION ("warmelt-hooks.melt:2334:/ cond");
	      /*cond */ if ( /*_#MELT_NEED_DBG__L8*/ meltfnum[7])	/*then */
		{
		  /*^cond.then */
		  /*^block */
		  /*anyblock */
		  {

       /*_#MELT_CALLCOUNT__L9*/ meltfnum[8] =
		      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		      meltcallcount	/* melt_callcount debugging */
#else
		      0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		      ;;

		    MELT_CHECK_SIGNAL ();
		    ;
		    MELT_LOCATION ("warmelt-hooks.melt:2334:/ apply");
		    /*apply */
		    {
		      union meltparam_un argtab[11];
		      memset (&argtab, 0, sizeof (argtab));
		      /*^apply.arg */
		      argtab[0].meltbp_long =
			/*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
		      /*^apply.arg */
		      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
		      /*^apply.arg */
		      argtab[2].meltbp_long = 2334;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring =
			"melt_invoke_input_callbacks ix#";
		      /*^apply.arg */
		      argtab[4].meltbp_long = /*_#IX__L5*/ meltfnum[1];
		      /*^apply.arg */
		      argtab[5].meltbp_cstring = " curfd#";
		      /*^apply.arg */
		      argtab[6].meltbp_long = /*_#CURFD__L6*/ meltfnum[5];
		      /*^apply.arg */
		      argtab[7].meltbp_cstring = " curinch=";
		      /*^apply.arg */
		      argtab[8].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURINCH__V9*/ meltfptr[8];
		      /*^apply.arg */
		      argtab[9].meltbp_cstring = "\n.. curstate=";
		      /*^apply.arg */
		      argtab[10].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURSTATE__V10*/ meltfptr[9];
		      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] =
			melt_apply ((meltclosure_ptr_t)
				    (( /*!MELT_DEBUG_FUN */ meltfrout->
				      tabval[0])),
				    (melt_ptr_t) (( /*nil */ NULL)),
				    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR ""), argtab, "",
				    (union meltparam_un *) 0);
		    }
		    ;
		    /*_._IF___V13*/ meltfptr[12] =
		      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-hooks.melt:2334:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[8] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V13*/ meltfptr[12] = NULL;;
		}
	      ;

	      {
		MELT_LOCATION ("warmelt-hooks.melt:2334:/ locexp");
		/*void */ (void) 0;
	      }
	      ;
	      /*^quasiblock */


	      /*epilog */

	      /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[7] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V13*/ meltfptr[12] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*^block */
	    /*anyblock */
	    {


	      {
		/*^locexp */
		/*void */ (void) 0;
	      }
	      ;
	      /*epilog */
	    }

#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-hooks.melt:2336:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L10*/ meltfnum[8] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.CURINCH__V9*/ meltfptr[8]),
				     (melt_ptr_t) (( /*!CLASS_INPUT_CHANNEL_HANDLER */ meltfrout->tabval[2])));;
	      MELT_LOCATION ("warmelt-hooks.melt:2336:/ cond");
	      /*cond */ if ( /*_#IS_A__L10*/ meltfnum[8])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V16*/ meltfptr[12] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-hooks.melt:2336:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curinch"),
					  ("warmelt-hooks.melt")
					  ? ("warmelt-hooks.melt") : __FILE__,
					  (2336) ? (2336) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V16*/ meltfptr[12] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V15*/ meltfptr[13] =
		/*_._IFELSE___V16*/ meltfptr[12];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-hooks.melt:2336:/ clear");
	       /*clear *//*_#IS_A__L10*/ meltfnum[8] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V16*/ meltfptr[12] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V15*/ meltfptr[13] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-hooks.melt:2337:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#gtI__L11*/ meltfnum[7] =
		(( /*_#CURFD__L6*/ meltfnum[5]) > (0));;
	      MELT_LOCATION ("warmelt-hooks.melt:2337:/ cond");
	      /*cond */ if ( /*_#gtI__L11*/ meltfnum[7])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V18*/ meltfptr[17] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-hooks.melt:2337:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curfd"),
					  ("warmelt-hooks.melt")
					  ? ("warmelt-hooks.melt") : __FILE__,
					  (2337) ? (2337) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V18*/ meltfptr[17] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V17*/ meltfptr[12] =
		/*_._IFELSE___V18*/ meltfptr[17];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-hooks.melt:2337:/ clear");
	       /*clear *//*_#gtI__L11*/ meltfnum[7] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V18*/ meltfptr[17] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V17*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2338:/ cond");
	    /*cond */ if ( /*_.CURSTATE__V10*/ meltfptr[9])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{


		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2340:/ locexp");
		    /* melt_invoke_input_callbacks READ_CHK__1 */
		    static char rdbuf[MELT_BUFSIZE];
		    memset (&rdbuf, 0, sizeof (rdbuf));
		    /*_#READCNT__L7*/ meltfnum[6] =
		      read ( /*_#CURFD__L6*/ meltfnum[5], rdbuf,
			    sizeof (rdbuf));
		    if ( /*_#READCNT__L7*/ meltfnum[6] > 0)
		      meltgc_add_out_raw_len ((melt_ptr_t) /*_.SBUF__V11*/
					      meltfptr[10], rdbuf,
					      /*_#READCNT__L7*/ meltfnum[6]);
		    ;
		  }
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
     /*_#eqeqI__L12*/ meltfnum[8] =
		    (( /*_#READCNT__L7*/ meltfnum[6]) == (0));;
		  MELT_LOCATION ("warmelt-hooks.melt:2349:/ cond");
		  /*cond */ if ( /*_#eqeqI__L12*/ meltfnum[8])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {


			{
			  MELT_LOCATION ("warmelt-hooks.melt:2350:/ locexp");
			  meltgc_append_list ((melt_ptr_t)
					      ( /*_.REMOVELIST__V6*/
					       meltfptr[4]),
					      (melt_ptr_t) ( /*_.CURINCH__V9*/
							    meltfptr[8]));
			}
			;
			MELT_LOCATION ("warmelt-hooks.melt:2351:/ compute");
			/*_.CURSTATE__V10*/ meltfptr[9] =
			  /*_.SETQ___V20*/ meltfptr[19] = ( /*nil */ NULL);;
			MELT_LOCATION
			  ("warmelt-hooks.melt:2349:/ quasiblock");


			/*_.PROGN___V21*/ meltfptr[20] =
			  /*_.SETQ___V20*/ meltfptr[19];;
			/*^compute */
			/*_._IF___V19*/ meltfptr[17] =
			  /*_.PROGN___V21*/ meltfptr[20];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2349:/ clear");
		 /*clear *//*_.SETQ___V20*/ meltfptr[19] = 0;
			/*^clear */
		 /*clear *//*_.PROGN___V21*/ meltfptr[20] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

      /*_._IF___V19*/ meltfptr[17] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2352:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2339:/ quasiblock");


		  /*epilog */

		  MELT_LOCATION ("warmelt-hooks.melt:2338:/ clear");
	       /*clear *//*_#eqeqI__L12*/ meltfnum[8] = 0;
		  /*^clear */
	       /*clear *//*_._IF___V19*/ meltfptr[17] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

		/*^block */
		/*anyblock */
		{


		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2355:/ locexp");
		    meltgc_append_list ((melt_ptr_t)
					( /*_.REMOVELIST__V6*/ meltfptr[4]),
					(melt_ptr_t) ( /*_.CURINCH__V9*/
						      meltfptr[8]));
		  }
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2354:/ quasiblock");


		  /*epilog */
		}
		;
	      }
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2358:/ loop");
	    /*loop */
	    {
	    meltlabloop_SCANLOOP_1:;
				/*^loopbody */

	      /*^block */
	      /*anyblock */
	      {


		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2360:/ quasiblock");


     /*_#STOP__L13*/ meltfnum[7] = 0;;
		/*^compute */
		/*_.SEQV__V24*/ meltfptr[17] = ( /*nil */ NULL);;

		{
		  MELT_LOCATION ("warmelt-hooks.melt:2363:/ locexp");
		  /* melt_invoke_input_callbacks EAT_CHK__1 */
		  const char *bufdata =
		    melt_strbuf_str ((melt_ptr_t) /*_.SBUF__V11*/
				     meltfptr[10]);
		  char *buf2nl =
		    bufdata ? CONST_CAST (char *,
					  strstr (bufdata, "\n\n")) : NULL;
		  if (buf2nl)
		    {
		      int paralen = buf2nl - bufdata + 2;
		      ((char *) buf2nl)[1] = '\0';
		/*_.SEQV__V24*/ meltfptr[17] =
			meltgc_read_from_rawstring (bufdata, NULL,
						    UNKNOWN_LOCATION);
		      melt_strbuf_consume ((melt_ptr_t) /*_.SBUF__V11*/
					   meltfptr[10], paralen);
		    }
		  else
		    {
		/*_#STOP__L13*/ meltfnum[7] = 1;
		      if (! /*_.CURSTATE__V10*/ meltfptr[9] && bufdata)
			{
			  int buflen = strlen (bufdata);
		  /*_.SEQV__V24*/ meltfptr[17] =
			    meltgc_read_from_rawstring (bufdata, NULL,
							UNKNOWN_LOCATION);
			  melt_strbuf_consume ((melt_ptr_t) /*_.SBUF__V11*/
					       meltfptr[10], buflen);
			}
		    }
		  ;
		}
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2389:/ cond");
		/*cond */ if ( /*_.SEQV__V24*/ meltfptr[17])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {


#if MELT_HAVE_DEBUG
		      MELT_LOCATION ("warmelt-hooks.melt:2390:/ cppif.then");
		      /*^block */
		      /*anyblock */
		      {


			{
			  /*^locexp */
			  /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
			  melt_dbgcounter++;
#endif
			  ;
			}
			;

			MELT_CHECK_SIGNAL ();
			;
	 /*_#MELT_NEED_DBG__L14*/ meltfnum[8] =
			  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
			  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
			  0	/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
			  ;;
			MELT_LOCATION ("warmelt-hooks.melt:2390:/ cond");
			/*cond */ if ( /*_#MELT_NEED_DBG__L14*/ meltfnum[8])	/*then */
			  {
			    /*^cond.then */
			    /*^block */
			    /*anyblock */
			    {

	   /*_#MELT_CALLCOUNT__L15*/ meltfnum[14] =
				/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
				meltcallcount	/* melt_callcount debugging */
#else
				0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
				;;

			      MELT_CHECK_SIGNAL ();
			      ;
			      MELT_LOCATION
				("warmelt-hooks.melt:2390:/ apply");
			      /*apply */
			      {
				union meltparam_un argtab[7];
				memset (&argtab, 0, sizeof (argtab));
				/*^apply.arg */
				argtab[0].meltbp_long =
				  /*_#MELT_CALLCOUNT__L15*/ meltfnum[14];
				/*^apply.arg */
				argtab[1].meltbp_cstring =
				  "warmelt-hooks.melt";
				/*^apply.arg */
				argtab[2].meltbp_long = 2390;
				/*^apply.arg */
				argtab[3].meltbp_cstring =
				  "melt_invoke_input_callbacks seqv=";
				/*^apply.arg */
				argtab[4].meltbp_aptr =
				  (melt_ptr_t *) & /*_.SEQV__V24*/
				  meltfptr[17];
				/*^apply.arg */
				argtab[5].meltbp_cstring = "\n curinch=";
				/*^apply.arg */
				argtab[6].meltbp_aptr =
				  (melt_ptr_t *) & /*_.CURINCH__V9*/
				  meltfptr[8];
				/*_.MELT_DEBUG_FUN__V27*/ meltfptr[26] =
				  melt_apply ((meltclosure_ptr_t)
					      (( /*!MELT_DEBUG_FUN */
						meltfrout->tabval[0])),
					      (melt_ptr_t) (( /*nil */ NULL)),
					      (MELTBPARSTR_LONG
					       MELTBPARSTR_CSTRING
					       MELTBPARSTR_LONG
					       MELTBPARSTR_CSTRING
					       MELTBPARSTR_PTR
					       MELTBPARSTR_CSTRING
					       MELTBPARSTR_PTR ""), argtab,
					      "", (union meltparam_un *) 0);
			      }
			      ;
			      /*_._IF___V26*/ meltfptr[25] =
				/*_.MELT_DEBUG_FUN__V27*/ meltfptr[26];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-hooks.melt:2390:/ clear");
		     /*clear *//*_#MELT_CALLCOUNT__L15*/ meltfnum[14]
				= 0;
			      /*^clear */
		     /*clear *//*_.MELT_DEBUG_FUN__V27*/ meltfptr[26]
				= 0;
			    }
			    ;
			  }
			else
			  {	/*^cond.else */

	  /*_._IF___V26*/ meltfptr[25] = NULL;;
			  }
			;

			{
			  MELT_LOCATION ("warmelt-hooks.melt:2390:/ locexp");
			  /*void */ (void) 0;
			}
			;
			/*^quasiblock */


			/*epilog */

			/*^clear */
		   /*clear *//*_#MELT_NEED_DBG__L14*/ meltfnum[8] = 0;
			/*^clear */
		   /*clear *//*_._IF___V26*/ meltfptr[25] = 0;
		      }

#else /*MELT_HAVE_DEBUG */
		      /*^cppif.else */
		      /*^block */
		      /*anyblock */
		      {


			{
			  /*^locexp */
			  /*void */ (void) 0;
			}
			;
			/*epilog */
		      }

#endif /*MELT_HAVE_DEBUG */
		      ;

		      MELT_CHECK_SIGNAL ();
		      ;
		      MELT_LOCATION ("warmelt-hooks.melt:2391:/ apply");
		      /*apply */
		      {
			union meltparam_un argtab[1];
			memset (&argtab, 0, sizeof (argtab));
			/*^apply.arg */
			argtab[0].meltbp_aptr =
			  (melt_ptr_t *) & /*_.SEQV__V24*/ meltfptr[17];
			/*_.CLOS__V28*/ meltfptr[26] =
			  melt_apply ((meltclosure_ptr_t)
				      ( /*_.CLOS__V12*/ meltfptr[11]),
				      (melt_ptr_t) ( /*_.CURINCH__V9*/
						    meltfptr[8]),
				      (MELTBPARSTR_PTR ""), argtab, "",
				      (union meltparam_un *) 0);
		      }
		      ;
		      MELT_LOCATION ("warmelt-hooks.melt:2389:/ quasiblock");


		      /*_.PROGN___V29*/ meltfptr[25] =
			/*_.CLOS__V28*/ meltfptr[26];;
		      /*^compute */
		      /*_._IF___V25*/ meltfptr[24] =
			/*_.PROGN___V29*/ meltfptr[25];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-hooks.melt:2389:/ clear");
		 /*clear *//*_.CLOS__V28*/ meltfptr[26] = 0;
		      /*^clear */
		 /*clear *//*_.PROGN___V29*/ meltfptr[25] = 0;
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_._IF___V25*/ meltfptr[24] = NULL;;
		  }
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2392:/ cond");
		/*cond */ if ( /*_#STOP__L13*/ meltfnum[7])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^quasiblock */


		      /*^compute */
       /*_.SCANLOOP__V23*/ meltfptr[20] = NULL;;

		      /*^exit */
		      /*exit */
		      {
			goto meltlabexit_SCANLOOP_1;
		      }
		      ;
		      /*epilog */
		    }
		    ;
		  }		/*noelse */
		;

		MELT_LOCATION ("warmelt-hooks.melt:2360:/ clear");
	       /*clear *//*_#STOP__L13*/ meltfnum[7] = 0;
		/*^clear */
	       /*clear *//*_.SEQV__V24*/ meltfptr[17] = 0;
		/*^clear */
	       /*clear *//*_._IF___V25*/ meltfptr[24] = 0;
		/*epilog */
	      }
	      ;
	      ;
	      goto meltlabloop_SCANLOOP_1;
	    meltlabexit_SCANLOOP_1:;
	      MELT_LOCATION ("warmelt-hooks.melt:2358:/ loopepilog");
	      /*loopepilog */
	      /*_.FOREVER___V22*/ meltfptr[19] =
		/*_.SCANLOOP__V23*/ meltfptr[20];;
	    }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    /*^compute */
   /*_#NULL__L16*/ meltfnum[14] =
	      (( /*_.CURSTATE__V10*/ meltfptr[9]) == NULL);;
	    MELT_LOCATION ("warmelt-hooks.melt:2395:/ cond");
	    /*cond */ if ( /*_#NULL__L16*/ meltfnum[14])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{


#if MELT_HAVE_DEBUG
		  MELT_LOCATION ("warmelt-hooks.melt:2396:/ cppif.then");
		  /*^block */
		  /*anyblock */
		  {


		    {
		      /*^locexp */
		      /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		      melt_dbgcounter++;
#endif
		      ;
		    }
		    ;

		    MELT_CHECK_SIGNAL ();
		    ;
       /*_#MELT_NEED_DBG__L17*/ meltfnum[8] =
		      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		      0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		      ;;
		    MELT_LOCATION ("warmelt-hooks.melt:2396:/ cond");
		    /*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[8])	/*then */
		      {
			/*^cond.then */
			/*^block */
			/*anyblock */
			{

	 /*_#MELT_CALLCOUNT__L18*/ meltfnum[7] =
			    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			    meltcallcount	/* melt_callcount debugging */
#else
			    0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			    ;;

			  MELT_CHECK_SIGNAL ();
			  ;
			  MELT_LOCATION ("warmelt-hooks.melt:2396:/ apply");
			  /*apply */
			  {
			    union meltparam_un argtab[5];
			    memset (&argtab, 0, sizeof (argtab));
			    /*^apply.arg */
			    argtab[0].meltbp_long =
			      /*_#MELT_CALLCOUNT__L18*/ meltfnum[7];
			    /*^apply.arg */
			    argtab[1].meltbp_cstring = "warmelt-hooks.melt";
			    /*^apply.arg */
			    argtab[2].meltbp_long = 2396;
			    /*^apply.arg */
			    argtab[3].meltbp_cstring =
			      "melt_invoke_input_callbacks eof curinch=";
			    /*^apply.arg */
			    argtab[4].meltbp_aptr =
			      (melt_ptr_t *) & /*_.CURINCH__V9*/ meltfptr[8];
			    /*_.MELT_DEBUG_FUN__V32*/ meltfptr[17] =
			      melt_apply ((meltclosure_ptr_t)
					  (( /*!MELT_DEBUG_FUN */ meltfrout->
					    tabval[0])),
					  (melt_ptr_t) (( /*nil */ NULL)),
					  (MELTBPARSTR_LONG
					   MELTBPARSTR_CSTRING
					   MELTBPARSTR_LONG
					   MELTBPARSTR_CSTRING MELTBPARSTR_PTR
					   ""), argtab, "",
					  (union meltparam_un *) 0);
			  }
			  ;
			  /*_._IF___V31*/ meltfptr[25] =
			    /*_.MELT_DEBUG_FUN__V32*/ meltfptr[17];;
			  /*epilog */

			  MELT_LOCATION ("warmelt-hooks.melt:2396:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[7] = 0;
			  /*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V32*/ meltfptr[17] =
			    0;
			}
			;
		      }
		    else
		      {		/*^cond.else */

	/*_._IF___V31*/ meltfptr[25] = NULL;;
		      }
		    ;

		    {
		      MELT_LOCATION ("warmelt-hooks.melt:2396:/ locexp");
		      /*void */ (void) 0;
		    }
		    ;
		    /*^quasiblock */


		    /*epilog */

		    /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[8] = 0;
		    /*^clear */
		 /*clear *//*_._IF___V31*/ meltfptr[25] = 0;
		  }

#else /*MELT_HAVE_DEBUG */
		  /*^cppif.else */
		  /*^block */
		  /*anyblock */
		  {


		    {
		      /*^locexp */
		      /*void */ (void) 0;
		    }
		    ;
		    /*epilog */
		  }

#endif /*MELT_HAVE_DEBUG */
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2397:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[1];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_aptr = /*nil */ (melt_ptr_t *) NULL;
		    /*_.CLOS__V33*/ meltfptr[24] =
		      melt_apply ((meltclosure_ptr_t)
				  ( /*_.CLOS__V12*/ meltfptr[11]),
				  (melt_ptr_t) ( /*_.CURINCH__V9*/
						meltfptr[8]),
				  (MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2395:/ quasiblock");


		  /*_.PROGN___V34*/ meltfptr[17] =
		    /*_.CLOS__V33*/ meltfptr[24];;
		  /*^compute */
		  /*_._IF___V30*/ meltfptr[26] =
		    /*_.PROGN___V34*/ meltfptr[17];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-hooks.melt:2395:/ clear");
	       /*clear *//*_.CLOS__V33*/ meltfptr[24] = 0;
		  /*^clear */
	       /*clear *//*_.PROGN___V34*/ meltfptr[17] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

    /*_._IF___V30*/ meltfptr[26] = NULL;;
	      }
	    ;
	    /*^compute */
	    /*_.LET___V8*/ meltfptr[7] = /*_._IF___V30*/ meltfptr[26];;

	    MELT_LOCATION ("warmelt-hooks.melt:2327:/ clear");
	     /*clear *//*_.CURINCH__V9*/ meltfptr[8] = 0;
	    /*^clear */
	     /*clear *//*_.CURSTATE__V10*/ meltfptr[9] = 0;
	    /*^clear */
	     /*clear *//*_#CURFD__L6*/ meltfnum[5] = 0;
	    /*^clear */
	     /*clear *//*_#READCNT__L7*/ meltfnum[6] = 0;
	    /*^clear */
	     /*clear *//*_.SBUF__V11*/ meltfptr[10] = 0;
	    /*^clear */
	     /*clear *//*_.CLOS__V12*/ meltfptr[11] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V15*/ meltfptr[13] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V17*/ meltfptr[12] = 0;
	    /*^clear */
	     /*clear *//*_.FOREVER___V22*/ meltfptr[19] = 0;
	    /*^clear */
	     /*clear *//*_#NULL__L16*/ meltfnum[14] = 0;
	    /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[26] = 0;
	  }			/*end foreach_long_upto meltcit2__EACHLONG */

	/*citerepilog */

	MELT_LOCATION ("warmelt-hooks.melt:2324:/ clear");
	     /*clear *//*_#IX__L5*/ meltfnum[1] = 0;
	/*^clear */
	     /*clear *//*_.LET___V8*/ meltfptr[7] = 0;
      }				/*endciterblock FOREACH_LONG_UPTO */
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-hooks.melt:2401:/ cppif.then");
      /*^block */
      /*anyblock */
      {


	{
	  /*^locexp */
	  /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	  melt_dbgcounter++;
#endif
	  ;
	}
	;

	MELT_CHECK_SIGNAL ();
	;
    /*_#MELT_NEED_DBG__L19*/ meltfnum[7] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-hooks.melt:2401:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L19*/ meltfnum[7])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L20*/ meltfnum[8] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-hooks.melt:2401:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[5];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L20*/ meltfnum[8];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-hooks.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 2401;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "melt_invoke_input_callbacks removelist=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.REMOVELIST__V6*/ meltfptr[4];
		/*_.MELT_DEBUG_FUN__V36*/ meltfptr[24] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V35*/ meltfptr[25] =
		/*_.MELT_DEBUG_FUN__V36*/ meltfptr[24];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-hooks.melt:2401:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[8] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V36*/ meltfptr[24] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V35*/ meltfptr[25] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-hooks.melt:2401:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[7] = 0;
	/*^clear */
	      /*clear *//*_._IF___V35*/ meltfptr[25] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*^block */
      /*anyblock */
      {


	{
	  /*^locexp */
	  /*void */ (void) 0;
	}
	;
	/*epilog */
      }

#endif /*MELT_HAVE_DEBUG */
      ;
      /*citerblock FOREACH_IN_LIST */
      {
	/* start foreach_in_list meltcit3__EACHLIST */
	for ( /*_.CURPAIR__V37*/ meltfptr[17] =
	     melt_list_first ((melt_ptr_t) /*_.REMOVELIST__V6*/ meltfptr[4]);
	     melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V37*/ meltfptr[17])
	     == MELTOBMAG_PAIR;
	     /*_.CURPAIR__V37*/ meltfptr[17] =
	     melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V37*/ meltfptr[17]))
	  {
	    /*_.CUREMOVE__V38*/ meltfptr[8] =
	      melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V37*/ meltfptr[17]);



#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-hooks.melt:2405:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      {
		/*^locexp */
		/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		melt_dbgcounter++;
#endif
		;
	      }
	      ;

	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#MELT_NEED_DBG__L21*/ meltfnum[5] =
		/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		;;
	      MELT_LOCATION ("warmelt-hooks.melt:2405:/ cond");
	      /*cond */ if ( /*_#MELT_NEED_DBG__L21*/ meltfnum[5])	/*then */
		{
		  /*^cond.then */
		  /*^block */
		  /*anyblock */
		  {

       /*_#MELT_CALLCOUNT__L22*/ meltfnum[6] =
		      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		      meltcallcount	/* melt_callcount debugging */
#else
		      0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		      ;;

		    MELT_CHECK_SIGNAL ();
		    ;
		    MELT_LOCATION ("warmelt-hooks.melt:2405:/ apply");
		    /*apply */
		    {
		      union meltparam_un argtab[5];
		      memset (&argtab, 0, sizeof (argtab));
		      /*^apply.arg */
		      argtab[0].meltbp_long =
			/*_#MELT_CALLCOUNT__L22*/ meltfnum[6];
		      /*^apply.arg */
		      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
		      /*^apply.arg */
		      argtab[2].meltbp_long = 2405;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring =
			"melt_invoke_input_callbacks curemove=";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CUREMOVE__V38*/ meltfptr[8];
		      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[10] =
			melt_apply ((meltclosure_ptr_t)
				    (( /*!MELT_DEBUG_FUN */ meltfrout->
				      tabval[0])),
				    (melt_ptr_t) (( /*nil */ NULL)),
				    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR ""), argtab, "",
				    (union meltparam_un *) 0);
		    }
		    ;
		    /*_._IF___V39*/ meltfptr[9] =
		      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[10];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-hooks.melt:2405:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L22*/ meltfnum[6] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V40*/ meltfptr[10] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V39*/ meltfptr[9] = NULL;;
		}
	      ;

	      {
		MELT_LOCATION ("warmelt-hooks.melt:2405:/ locexp");
		/*void */ (void) 0;
	      }
	      ;
	      /*^quasiblock */


	      /*epilog */

	      /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L21*/ meltfnum[5] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V39*/ meltfptr[9] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*^block */
	    /*anyblock */
	    {


	      {
		/*^locexp */
		/*void */ (void) 0;
	      }
	      ;
	      /*epilog */
	    }

#endif /*MELT_HAVE_DEBUG */
	    ;
   /*_#GET_INT__L23*/ meltfnum[14] =
	      (melt_get_int
	       ((melt_ptr_t) ( /*_.CUREMOVE__V38*/ meltfptr[8])));;
	    /*^compute */
   /*_.BUCKETLONG_REMOVE__V41*/ meltfptr[11] =
	      meltgc_longsbucket_remove ((melt_ptr_t) /*_.BUCK__V7*/
					 meltfptr[3],
					 ( /*_#GET_INT__L23*/ meltfnum[14]));;
	    MELT_LOCATION ("warmelt-hooks.melt:2406:/ compute");
	    /*_.BUCK__V7*/ meltfptr[3] = /*_.SETQ___V42*/ meltfptr[13] =
	      /*_.BUCKETLONG_REMOVE__V41*/ meltfptr[11];;
	  }			/* end foreach_in_list meltcit3__EACHLIST */
     /*_.CURPAIR__V37*/ meltfptr[17] = NULL;
     /*_.CUREMOVE__V38*/ meltfptr[8] = NULL;


	/*citerepilog */

	MELT_LOCATION ("warmelt-hooks.melt:2402:/ clear");
	     /*clear *//*_.CURPAIR__V37*/ meltfptr[17] = 0;
	/*^clear */
	     /*clear *//*_.CUREMOVE__V38*/ meltfptr[8] = 0;
	/*^clear */
	     /*clear *//*_#GET_INT__L23*/ meltfnum[14] = 0;
	/*^clear */
	     /*clear *//*_.BUCKETLONG_REMOVE__V41*/ meltfptr[11] = 0;
	/*^clear */
	     /*clear *//*_.SETQ___V42*/ meltfptr[13] = 0;
      }				/*endciterblock FOREACH_IN_LIST */
      ;
      MELT_LOCATION ("warmelt-hooks.melt:2408:/ putmodvar");
      melt_module_var_put (meltmodvarix_MELT_INPCHANBUCK_symb,
			   (melt_ptr_t) ( /*_.BUCK__V7*/ meltfptr[3]));
      ;

      MELT_LOCATION ("warmelt-hooks.melt:2321:/ clear");
	    /*clear *//*_.REMOVELIST__V6*/ meltfptr[4] = 0;
      /*^clear */
	    /*clear *//*_.BUCK__V7*/ meltfptr[3] = 0;
      /*^clear */
	    /*clear *//*_#miI__L4*/ meltfnum[2] = 0;
      /* block_signals meltcit1__BLKSIGNAL end */
      melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev;
      MELT_CHECK_SIGNAL ();


      /*citerepilog */
    }				/*endciterblock BLOCK_SIGNALS */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("MELT_INVOKE_INPUT_CALLBACKS", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_77_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   * meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 17
    melt_ptr_t mcfr_varptr[17];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER_st
	 *) meltfirstargp_;
      /* use arguments meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 17; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER nbval 17*/
  meltfram__.mcfr_nbvar = 17 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("REGISTER_INPUT_CHANNEL_HANDLER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2517:/ getarg");
 /*_.CLOS__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.DATA__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.DATA__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#INCHFD__L1*/ meltfnum[0] = meltxargtab_[1].meltbp_long;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2528:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L2*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2528:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L3*/ meltfnum[2] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2528:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2528;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"register_input_channel_handler clos=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOS__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " data=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.DATA__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " inchfd=";
	      /*^apply.arg */
	      argtab[8].meltbp_long = /*_#INCHFD__L1*/ meltfnum[0];
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V4*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2528:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V4*/ meltfptr[3] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2528:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2530:/ quasiblock");


 /*_#GOODINCHFD__L4*/ meltfnum[2] = 0;;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_CLOSURE__L5*/ meltfnum[1] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.CLOS__V2*/ meltfptr[1])) ==
       MELTOBMAG_CLOSURE);;
    MELT_LOCATION ("warmelt-hooks.melt:2531:/ cond");
    /*cond */ if ( /*_#IS_CLOSURE__L5*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

   /*_#gteqI__L7*/ meltfnum[6] =
	    (( /*_#INCHFD__L1*/ meltfnum[0]) >= (0));;
	  /*^compute */
	  /*_#_IF___L6*/ meltfnum[5] = /*_#gteqI__L7*/ meltfnum[6];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2531:/ clear");
	     /*clear *//*_#gteqI__L7*/ meltfnum[6] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_#_IF___L6*/ meltfnum[5] = 0;;
      }
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2531:/ cond");
    /*cond */ if ( /*_#_IF___L6*/ meltfnum[5])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  {
	    MELT_LOCATION ("warmelt-hooks.melt:2533:/ locexp");
	    /*register_input_channel_handler STATINCHFDCHK__1 */
	    {
	      struct stat STATINCHFDCHK__1_stat;
	      memset (&STATINCHFDCHK__1_stat, 0, sizeof (struct stat));
	      if (fstat
		  ( /*_#INCHFD__L1*/ meltfnum[0], &STATINCHFDCHK__1_stat))
		warning (0, "MELT bad registered input channel fd#%d - %s",
			 (int) /*_#INCHFD__L1*/ meltfnum[0],
			 xstrerror (errno));
	      else
	 /*_#GOODINCHFD__L4*/ meltfnum[2] = 1;
	    } /* end STATINCHFDCHK__1 */ ;
	  }
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#NOT__L8*/ meltfnum[6] =
      (!( /*_#GOODINCHFD__L4*/ meltfnum[2]));;
    MELT_LOCATION ("warmelt-hooks.melt:2545:/ cond");
    /*cond */ if ( /*_#NOT__L8*/ meltfnum[6])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^quasiblock */


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-hooks.melt:2545:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  /*_._IF___V7*/ meltfptr[3] = /*_.RETURN___V8*/ meltfptr[7];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2545:/ clear");
	     /*clear *//*_.RETURN___V8*/ meltfptr[7] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V7*/ meltfptr[3] = NULL;;
      }
    ;
    /*^compute */
    /*_.LET___V6*/ meltfptr[4] = /*_._IF___V7*/ meltfptr[3];;

    MELT_LOCATION ("warmelt-hooks.melt:2530:/ clear");
	   /*clear *//*_#GOODINCHFD__L4*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_#IS_CLOSURE__L5*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_#_IF___L6*/ meltfnum[5] = 0;
    /*^clear */
	   /*clear *//*_#NOT__L8*/ meltfnum[6] = 0;
    /*^clear */
	   /*clear *//*_._IF___V7*/ meltfptr[3] = 0;
    MELT_LOCATION ("warmelt-hooks.melt:2546:/ quasiblock");


 /*_.INSBUF__V9*/ meltfptr[7] =
      (melt_ptr_t)
      meltgc_new_strbuf ((meltobject_ptr_t)
			 (( /*!DISCR_STRBUF */ meltfrout->tabval[1])),
			 (const char *) 0);;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2547:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_INPUT_CHANNEL_HANDLER */ meltfrout->tabval[2])), (4), "CLASS_INPUT_CHANNEL_HANDLER");
  /*_.INST__V11*/ meltfptr[10] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @INCH_SBUF",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (1),
			  ( /*_.INSBUF__V9*/ meltfptr[7]), "INCH_SBUF");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @INCH_CLOS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (2),
			  ( /*_.CLOS__V2*/ meltfptr[1]), "INCH_CLOS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @INCH_DATA",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (3),
			  ( /*_.DATA__V3*/ meltfptr[2]), "INCH_DATA");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V11*/ meltfptr[10],
				  "newly made instance");
    ;
    /*_.INCHDLR__V10*/ meltfptr[3] = /*_.INST__V11*/ meltfptr[10];;
    /*^compute */
 /*_.INBUCK__V12*/ meltfptr[11] =
      (melt_module_var_fetch (meltmodvarix_MELT_INPCHANBUCK_symb));;

    {
      MELT_LOCATION ("warmelt-hooks.melt:2553:/ locexp");
      melt_put_int ((melt_ptr_t) ( /*_.INCHDLR__V10*/ meltfptr[3]),
		    ( /*_#INCHFD__L1*/ meltfnum[0]));
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_BUCKETLONG__L9*/ meltfnum[2] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.INBUCK__V12*/ meltfptr[11])) ==
       MELTOBMAG_BUCKETLONGS);;
    /*^compute */
 /*_#NOT__L10*/ meltfnum[1] =
      (!( /*_#IS_BUCKETLONG__L9*/ meltfnum[2]));;
    MELT_LOCATION ("warmelt-hooks.melt:2554:/ cond");
    /*cond */ if ( /*_#NOT__L10*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-hooks.melt:2555:/ quasiblock");


   /*_.NEWINBUCK__V15*/ meltfptr[14] =
	    (meltgc_new_longsbucket
	     ((meltobject_ptr_t)
	      ( /*!DISCR_BUCKET_LONGS */ meltfrout->tabval[3]), (50)));;
	  MELT_LOCATION ("warmelt-hooks.melt:2557:/ compute");
	  /*_.INBUCK__V12*/ meltfptr[11] = /*_.SETQ___V16*/ meltfptr[15] =
	    /*_.NEWINBUCK__V15*/ meltfptr[14];;
	  /*_.LET___V14*/ meltfptr[13] = /*_.SETQ___V16*/ meltfptr[15];;

	  MELT_LOCATION ("warmelt-hooks.melt:2555:/ clear");
	     /*clear *//*_.NEWINBUCK__V15*/ meltfptr[14] = 0;
	  /*^clear */
	     /*clear *//*_.SETQ___V16*/ meltfptr[15] = 0;
	  /*_._IF___V13*/ meltfptr[12] = /*_.LET___V14*/ meltfptr[13];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2554:/ clear");
	     /*clear *//*_.LET___V14*/ meltfptr[13] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V13*/ meltfptr[12] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2558:/ quasiblock");


 /*_.UPDATEDINBUCK__V17*/ meltfptr[14] =
      meltgc_longsbucket_put ((melt_ptr_t) /*_.INBUCK__V12*/ meltfptr[11],
			      ( /*_#INCHFD__L1*/ meltfnum[0]),
			      (melt_ptr_t) /*_.INCHDLR__V10*/ meltfptr[3]);;
    MELT_LOCATION ("warmelt-hooks.melt:2560:/ putmodvar");
    melt_module_var_put (meltmodvarix_MELT_INPCHANBUCK_symb,
			 (melt_ptr_t) ( /*_.UPDATEDINBUCK__V17*/
				       meltfptr[14]));
    ;

    {
      MELT_LOCATION ("warmelt-hooks.melt:2561:/ locexp");
      /* FCNTLINCHFDCHK__1 start */
      if (fcntl ( /*_#INCHFD__L1*/ meltfnum[0], F_SETOWN, getpid ()))
	melt_fatal_error
	  ("MELT failed to set ownership (F_SETOWN) fd #%d - %s",
	   (int) /*_#INCHFD__L1*/ meltfnum[0], xstrerror (errno));
      /* end  FCNTLINCHFDCHK__1 */
      ;
    }
    ;

    MELT_LOCATION ("warmelt-hooks.melt:2558:/ clear");
	   /*clear *//*_.UPDATEDINBUCK__V17*/ meltfptr[14] = 0;

    MELT_LOCATION ("warmelt-hooks.melt:2546:/ clear");
	   /*clear *//*_.INSBUF__V9*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.INCHDLR__V10*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_.INBUCK__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_#IS_BUCKETLONG__L9*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_#NOT__L10*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IF___V13*/ meltfptr[12] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-hooks.melt:2517:/ clear");
	   /*clear *//*_.LET___V6*/ meltfptr[4] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("REGISTER_INPUT_CHANNEL_HANDLER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_79_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER (meltclosure_ptr_t meltclosp_,
						 melt_ptr_t meltfirstargp_,
						 const melt_argdescr_cell_t
						 meltxargdescr_[],
						 union meltparam_un *
						 meltxargtab_,
						 const melt_argdescr_cell_t
						 meltxresdescr_[],
						 union meltparam_un *
						 meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 18
    melt_ptr_t mcfr_varptr[18];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER_st
	 *) meltfirstargp_;
      /* use arguments meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 18; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER nbval 18*/
  meltfram__.mcfr_nbvar = 18 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("REGISTER_ALARM_TIMER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2649:/ getarg");
 /*_.CLOS__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#PERIODMS__L1*/ meltfnum[0] = meltxargtab_[0].meltbp_long;

  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.DATA__V3*/ meltfptr[2] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.DATA__V3*/ meltfptr[2])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2655:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L2*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2655:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L3*/ meltfnum[2] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2655:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2655;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "register_alarm_timer clos=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOS__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " periodms=";
	      /*^apply.arg */
	      argtab[6].meltbp_long = /*_#PERIODMS__L1*/ meltfnum[0];
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V4*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2655:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V4*/ meltfptr[3] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2655:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_CLOSURE__L4*/ meltfnum[2] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.CLOS__V2*/ meltfptr[1])) ==
       MELTOBMAG_CLOSURE);;
    MELT_LOCATION ("warmelt-hooks.melt:2656:/ cond");
    /*cond */ if ( /*_#IS_CLOSURE__L4*/ meltfnum[2])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#gteqI__L5*/ meltfnum[1] =
	    (( /*_#PERIODMS__L1*/ meltfnum[0]) >= (50));;
	  MELT_LOCATION ("warmelt-hooks.melt:2657:/ cond");
	  /*cond */ if ( /*_#gteqI__L5*/ meltfnum[1])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-hooks.melt:2658:/ quasiblock");


		/*_.RES__V9*/ meltfptr[8] = ( /*nil */ NULL);;
		/*citerblock BLOCK_SIGNALS */
		{
		  /* block_signals meltcit1__BLKSIGNAL start */
		  long meltcit1__BLKSIGNAL_lev = melt_blocklevel_signals;
		  melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev + 1;



		  MELT_LOCATION ("warmelt-hooks.melt:2662:/ quasiblock");


      /*_.PERIODBOX__V11*/ meltfptr[10] =
		    (meltgc_new_int
		     ((meltobject_ptr_t)
		      (( /*!DISCR_CONSTANT_INTEGER */ meltfrout->tabval[1])),
		      ( /*_#PERIODMS__L1*/ meltfnum[0])));;
		  MELT_LOCATION ("warmelt-hooks.melt:2663:/ cond");
												/*cond */ if ((melt_module_var_fetch (meltmodvarix_MELT_ALARMBUCKET_symb)))
												/*then */
		    {
		      /*^cond.then */
      /*_.OLDBUCK__V12*/ meltfptr[11] =
			(melt_module_var_fetch
					 (meltmodvarix_MELT_ALARMBUCKET_symb));;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-hooks.melt:2663:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {

	/*_.MAKE_BUCKETLONG__V13*/ meltfptr[12] =
			  (meltgc_new_longsbucket
			   ((meltobject_ptr_t)
			    ( /*!DISCR_BUCKET_LONGS */ meltfrout->tabval[2]),
			    (31)));;
			/*^compute */
			/*_.OLDBUCK__V12*/ meltfptr[11] =
			  /*_.MAKE_BUCKETLONG__V13*/ meltfptr[12];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2663:/ clear");
		  /*clear *//*_.MAKE_BUCKETLONG__V13*/ meltfptr[12] = 0;
		      }
		      ;
		    }
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2664:/ quasiblock");


		  /*^rawallocobj */
		  /*rawallocobj */
		  {
		    melt_ptr_t newobj = 0;
		    melt_raw_object_create (newobj,
					    (melt_ptr_t) (( /*!CLASS_ALARM_HANDLER */ meltfrout->tabval[3])), (4), "CLASS_ALARM_HANDLER");
       /*_.INST__V15*/ meltfptr[14] =
		      newobj;
		  };
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @ALARMH_PERIOD",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V15*/
						     meltfptr[14])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (1),
					( /*_.PERIODBOX__V11*/ meltfptr[10]),
					"ALARMH_PERIOD");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @ALARMH_CLOS",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V15*/
						     meltfptr[14])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (2),
					( /*_.CLOS__V2*/ meltfptr[1]),
					"ALARMH_CLOS");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @ALARMH_DATA",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V15*/
						     meltfptr[14])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (3),
					( /*_.DATA__V3*/ meltfptr[2]),
					"ALARMH_DATA");
		  ;
		  /*^touchobj */

		  melt_dbgtrace_written_object ( /*_.INST__V15*/ meltfptr[14],
						"newly made instance");
		  ;
		  /*_.ALHD__V14*/ meltfptr[12] =
		    /*_.INST__V15*/ meltfptr[14];;
		  /*^compute */
      /*_#CURELTIM__L6*/ meltfnum[5] =
		    melt_relative_time_millisec ();;
		  /*^compute */
      /*_#NEXTIM__L7*/ meltfnum[6] =
		    (( /*_#CURELTIM__L6*/ meltfnum[5]) +
		     ( /*_#PERIODMS__L1*/ meltfnum[0]));;
		  /*^compute */
      /*_.NEWBUCK__V16*/ meltfptr[15] =
		    meltgc_longsbucket_put ((melt_ptr_t) /*_.OLDBUCK__V12*/
					    meltfptr[11],
					    ( /*_#NEXTIM__L7*/ meltfnum[6]),
					    (melt_ptr_t) /*_.ALHD__V14*/
					    meltfptr[12]);;
		  /*^compute */
      /*_#FIRSTKEY__L8*/ meltfnum[7] =
		    melt_longsbucket_nth_key ((melt_ptr_t) /*_.NEWBUCK__V16*/
					      meltfptr[15], (int) 0);;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2672:/ cond");
		  /*cond */ if ( /*_#FIRSTKEY__L8*/ meltfnum[7])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	/*_#miI__L10*/ meltfnum[9] =
			  (( /*_#FIRSTKEY__L8*/ meltfnum[7]) -
			   ( /*_#CURELTIM__L6*/ meltfnum[5]));;
			/*^compute */
			/*_#FIRSTDELAY__L9*/ meltfnum[8] =
			  /*_#miI__L10*/ meltfnum[9];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2672:/ clear");
		  /*clear *//*_#miI__L10*/ meltfnum[9] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_#FIRSTDELAY__L9*/ meltfnum[8] = 0;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2674:/ putmodvar");
		  melt_module_var_put (meltmodvarix_MELT_ALARMBUCKET_symb,
				       (melt_ptr_t) ( /*_.NEWBUCK__V16*/
						     meltfptr[15]));
		  ;

		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2675:/ locexp");
		    melt_set_real_timer_millisec ( /*_#FIRSTDELAY__L9*/
						  meltfnum[8]);
		  }
		  ;
		  MELT_LOCATION ("warmelt-hooks.melt:2676:/ compute");
		  /*_.RES__V9*/ meltfptr[8] = /*_.SETQ___V17*/ meltfptr[16] =
		    /*_.ALHD__V14*/ meltfptr[12];;
		  /*_.LET___V10*/ meltfptr[9] =
		    /*_.SETQ___V17*/ meltfptr[16];;

		  MELT_LOCATION ("warmelt-hooks.melt:2662:/ clear");
		/*clear *//*_.PERIODBOX__V11*/ meltfptr[10] = 0;
		  /*^clear */
		/*clear *//*_.OLDBUCK__V12*/ meltfptr[11] = 0;
		  /*^clear */
		/*clear *//*_.ALHD__V14*/ meltfptr[12] = 0;
		  /*^clear */
		/*clear *//*_#CURELTIM__L6*/ meltfnum[5] = 0;
		  /*^clear */
		/*clear *//*_#NEXTIM__L7*/ meltfnum[6] = 0;
		  /*^clear */
		/*clear *//*_.NEWBUCK__V16*/ meltfptr[15] = 0;
		  /*^clear */
		/*clear *//*_#FIRSTKEY__L8*/ meltfnum[7] = 0;
		  /*^clear */
		/*clear *//*_#FIRSTDELAY__L9*/ meltfnum[8] = 0;
		  /*^clear */
		/*clear *//*_.SETQ___V17*/ meltfptr[16] = 0;
		  /* block_signals meltcit1__BLKSIGNAL end */
		  melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev;
		  MELT_CHECK_SIGNAL ();


		  /*citerepilog */

		  MELT_LOCATION ("warmelt-hooks.melt:2660:/ clear");
		/*clear *//*_.LET___V10*/ meltfptr[9] = 0;
		}		/*endciterblock BLOCK_SIGNALS */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2677:/ quasiblock");


		/*_._RETVAL___V1*/ meltfptr[0] = /*_.RES__V9*/ meltfptr[8];;

		{
		  MELT_LOCATION ("warmelt-hooks.melt:2677:/ locexp");
		  /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
		  if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
		    melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
		  ;
		}
		;
		/*^finalreturn */
		;
		/*finalret */ goto meltlabend_rout;
		/*_.LET___V8*/ meltfptr[7] = /*_.RETURN___V18*/ meltfptr[10];;

		MELT_LOCATION ("warmelt-hooks.melt:2658:/ clear");
	       /*clear *//*_.RES__V9*/ meltfptr[8] = 0;
		/*^clear */
	       /*clear *//*_.RETURN___V18*/ meltfptr[10] = 0;
		/*_._IF___V7*/ meltfptr[3] = /*_.LET___V8*/ meltfptr[7];;
		/*epilog */

		MELT_LOCATION ("warmelt-hooks.melt:2657:/ clear");
	       /*clear *//*_.LET___V8*/ meltfptr[7] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_._IF___V7*/ meltfptr[3] = NULL;;
	    }
	  ;
	  /*^compute */
	  /*_._IF___V6*/ meltfptr[4] = /*_._IF___V7*/ meltfptr[3];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2656:/ clear");
	     /*clear *//*_#gteqI__L5*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[3] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V6*/ meltfptr[4] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2649:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_._IF___V6*/ meltfptr[4];;

    {
      MELT_LOCATION ("warmelt-hooks.melt:2649:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_#IS_CLOSURE__L4*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_._IF___V6*/ meltfptr[4] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("REGISTER_ALARM_TIMER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_82_WARMELTmiHOOKS_REGISTER_ALARM_TIMER */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER (meltclosure_ptr_t
						   meltclosp_,
						   melt_ptr_t meltfirstargp_,
						   const melt_argdescr_cell_t
						   meltxargdescr_[],
						   union meltparam_un *
						   meltxargtab_,
						   const melt_argdescr_cell_t
						   meltxresdescr_[],
						   union meltparam_un *
						   meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 24
    melt_ptr_t mcfr_varptr[24];
#define MELTFRAM_NBVARNUM 8
    long mcfr_varnum[8];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER_st
	 *) meltfirstargp_;
      /* use arguments meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 24; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER nbval 24*/
  meltfram__.mcfr_nbvar = 24 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("UNREGISTER_ALARM_TIMER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2681:/ getarg");
 /*_.TIM__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2683:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2683:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2683:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2683;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "unregister_alarm_timer tim=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.TIM__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V4*/ meltfptr[3] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V3*/ meltfptr[2] =
	      /*_.MELT_DEBUG_FUN__V4*/ meltfptr[3];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2683:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V4*/ meltfptr[3] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V3*/ meltfptr[2] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2683:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V3*/ meltfptr[2] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2684:/ cond");
    /*cond */ if ( /*_.TIM__V2*/ meltfptr[1])	/*then */
      {
	/*^cond.then */
	/*_._IFELSE___V5*/ meltfptr[3] = ( /*nil */ NULL);;
      }
    else
      {
	MELT_LOCATION ("warmelt-hooks.melt:2684:/ cond.else");

	/*^block */
	/*anyblock */
	{

	  /*^quasiblock */


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-hooks.melt:2684:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  /*^quasiblock */


	  /*_.PROGN___V7*/ meltfptr[6] = /*_.RETURN___V6*/ meltfptr[2];;
	  /*^compute */
	  /*_._IFELSE___V5*/ meltfptr[3] = /*_.PROGN___V7*/ meltfptr[6];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2684:/ clear");
	     /*clear *//*_.RETURN___V6*/ meltfptr[2] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V7*/ meltfptr[6] = 0;
	}
	;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_NOT_A__L3*/ meltfnum[1] =
      !melt_is_instance_of ((melt_ptr_t) ( /*_.TIM__V2*/ meltfptr[1]),
			    (melt_ptr_t) (( /*!CLASS_ALARM_HANDLER */
					   meltfrout->tabval[1])));;
    MELT_LOCATION ("warmelt-hooks.melt:2685:/ cond");
    /*cond */ if ( /*_#IS_NOT_A__L3*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*_._IFELSE___V8*/ meltfptr[2] = ( /*nil */ NULL);;
      }
    else
      {
	MELT_LOCATION ("warmelt-hooks.melt:2685:/ cond.else");

	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-hooks.melt:2686:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
     /*_#IS_A__L4*/ meltfnum[0] =
	      melt_is_instance_of ((melt_ptr_t) ( /*_.TIM__V2*/ meltfptr[1]),
				   (melt_ptr_t) (( /*!CLASS_ALARM_HANDLER */
						  meltfrout->tabval[1])));;
	    MELT_LOCATION ("warmelt-hooks.melt:2686:/ cond");
	    /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V10*/ meltfptr[9] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-hooks.melt:2686:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check tim"),
					("warmelt-hooks.melt")
					? ("warmelt-hooks.melt") : __FILE__,
					(2686) ? (2686) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		 /*clear *//*_._IFELSE___V10*/ meltfptr[9] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V9*/ meltfptr[6] = /*_._IFELSE___V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2686:/ clear");
	       /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_._IFELSE___V10*/ meltfptr[9] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V9*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-hooks.melt:2687:/ quasiblock");


   /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	  {
	    MELT_LOCATION ("warmelt-hooks.melt:2687:/ locexp");
	    /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	    if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	      melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	    ;
	  }
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  MELT_LOCATION ("warmelt-hooks.melt:2685:/ quasiblock");


	  /*_.PROGN___V12*/ meltfptr[11] = /*_.RETURN___V11*/ meltfptr[9];;
	  /*^compute */
	  /*_._IFELSE___V8*/ meltfptr[2] = /*_.PROGN___V12*/ meltfptr[11];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2685:/ clear");
	     /*clear *//*_.IFCPP___V9*/ meltfptr[6] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V11*/ meltfptr[9] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V12*/ meltfptr[11] = 0;
	}
	;
      }
    ;
    /*citerblock BLOCK_SIGNALS */
    {
      /* block_signals meltcit1__BLKSIGNAL start */
      long meltcit1__BLKSIGNAL_lev = melt_blocklevel_signals;
      melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev + 1;



      MELT_LOCATION ("warmelt-hooks.melt:2690:/ quasiblock");


  /*_.OLDBUCK__V13*/ meltfptr[6] =
	(melt_module_var_fetch (meltmodvarix_MELT_ALARMBUCKET_symb));;
      /*^compute */
  /*_#OLDBUCKLEN__L5*/ meltfnum[0] =
	melt_longsbucket_count ((melt_ptr_t) /*_.OLDBUCK__V13*/ meltfptr[6]);;
      /*^compute */
  /*_.NEWBUCK__V14*/ meltfptr[9] =
	(meltgc_new_longsbucket
	 ((meltobject_ptr_t) ( /*!DISCR_BUCKET_LONGS */ meltfrout->tabval[2]),
	  ( /*_#OLDBUCKLEN__L5*/ meltfnum[0])));;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-hooks.melt:2694:/ cond");
      /*cond */ if ( /*_#OLDBUCKLEN__L5*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[11] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-hooks.melt:2694:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-hooks.melt:2696:/ putmodvar");
	    melt_module_var_put (meltmodvarix_MELT_ALARMBUCKET_symb,
				 (melt_ptr_t) (( /*nil */ NULL)));
	    ;

	    {
	      MELT_LOCATION ("warmelt-hooks.melt:2697:/ locexp");
	      melt_set_real_timer_millisec (0);
	    }
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2698:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

	    {
	      MELT_LOCATION ("warmelt-hooks.melt:2698:/ locexp");
	      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
	      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
		melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
	      ;
	    }
	    ;
	    /*^finalreturn */
	    ;
	    /*finalret */ goto meltlabend_rout;
	    MELT_LOCATION ("warmelt-hooks.melt:2694:/ quasiblock");


	    /*_.PROGN___V17*/ meltfptr[16] = /*_.RETURN___V16*/ meltfptr[15];;
	    /*^compute */
	    /*_._IFELSE___V15*/ meltfptr[11] =
	      /*_.PROGN___V17*/ meltfptr[16];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2694:/ clear");
	      /*clear *//*_.RETURN___V16*/ meltfptr[15] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V17*/ meltfptr[16] = 0;
	  }
	  ;
	}
      ;
      /*citerblock FOREACH_IN_BUCKETLONG */
      {
	/*foreach_in_bucketlong meltcit2__EACHBUCKLONG */ unsigned
	  meltcit2__EACHBUCKLONG_ix = 0, meltcit2__EACHBUCKLONG_cnt = 0;
  /*_#OLDKEY__L6*/ meltfnum[5] = 0L;
  /*_.OLDALA__V18*/ meltfptr[15] = NULL;
	for (meltcit2__EACHBUCKLONG_ix = 0;
	     /* retrieve in meltcit2__EACHBUCKLONG iteration the count, it might change! */
	     (meltcit2__EACHBUCKLONG_cnt =
	      melt_longsbucket_count ((melt_ptr_t) /*_.OLDBUCK__V13*/
				      meltfptr[6])) > 0
	     && meltcit2__EACHBUCKLONG_ix < meltcit2__EACHBUCKLONG_cnt;
	     meltcit2__EACHBUCKLONG_ix++)
	  {
     /*_#OLDKEY__L6*/ meltfnum[5] = 0L;
     /*_.OLDALA__V18*/ meltfptr[15] = NULL;
	    {
	      struct melt_bucketlongentry_st *meltcit2__EACHBUCKLONG_buent
		=
		((struct meltbucketlongs_st *) /*_.OLDBUCK__V13*/
		 meltfptr[6])->buckl_entab + meltcit2__EACHBUCKLONG_ix;
	      if (!meltcit2__EACHBUCKLONG_buent->ebl_va)
		continue;
       /*_#OLDKEY__L6*/ meltfnum[5] =
		meltcit2__EACHBUCKLONG_buent->ebl_at;
       /*_.OLDALA__V18*/ meltfptr[15] =
		meltcit2__EACHBUCKLONG_buent->ebl_va;
	      meltcit2__EACHBUCKLONG_buent = NULL;
	    }
	    /*foreach_in_bucketlong meltcit2__EACHBUCKLONG body: */




#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-hooks.melt:2702:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L7*/ meltfnum[6] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.OLDALA__V18*/ meltfptr[15]),
				     (melt_ptr_t) (( /*!CLASS_ALARM_HANDLER */
						    meltfrout->tabval[1])));;
	      MELT_LOCATION ("warmelt-hooks.melt:2702:/ cond");
	      /*cond */ if ( /*_#IS_A__L7*/ meltfnum[6])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V20*/ meltfptr[19] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-hooks.melt:2702:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check oldala"),
					  ("warmelt-hooks.melt")
					  ? ("warmelt-hooks.melt") : __FILE__,
					  (2702) ? (2702) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V20*/ meltfptr[19] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V19*/ meltfptr[16] =
		/*_._IFELSE___V20*/ meltfptr[19];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-hooks.melt:2702:/ clear");
	       /*clear *//*_#IS_A__L7*/ meltfnum[6] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V20*/ meltfptr[19] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V19*/ meltfptr[16] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    /*^compute */
   /*_#eqeq__L8*/ meltfnum[6] =
	      (( /*_.OLDALA__V18*/ meltfptr[15]) ==
	       ( /*_.TIM__V2*/ meltfptr[1]));;
	    MELT_LOCATION ("warmelt-hooks.melt:2703:/ cond");
	    /*cond */ if ( /*_#eqeq__L8*/ meltfnum[6])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V21*/ meltfptr[19] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-hooks.melt:2703:/ cond.else");

		/*^block */
		/*anyblock */
		{

     /*_.BUCKETLONG_PUT__V22*/ meltfptr[21] =
		    meltgc_longsbucket_put ((melt_ptr_t) /*_.NEWBUCK__V14*/
					    meltfptr[9],
					    ( /*_#OLDKEY__L6*/ meltfnum[5]),
					    (melt_ptr_t) /*_.OLDALA__V18*/
					    meltfptr[15]);;
		  MELT_LOCATION ("warmelt-hooks.melt:2704:/ compute");
		  /*_.NEWBUCK__V14*/ meltfptr[9] =
		    /*_.SETQ___V23*/ meltfptr[22] =
		    /*_.BUCKETLONG_PUT__V22*/ meltfptr[21];;
		  MELT_LOCATION ("warmelt-hooks.melt:2703:/ quasiblock");


		  /*_.PROGN___V24*/ meltfptr[23] =
		    /*_.SETQ___V23*/ meltfptr[22];;
		  /*^compute */
		  /*_._IFELSE___V21*/ meltfptr[19] =
		    /*_.PROGN___V24*/ meltfptr[23];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-hooks.melt:2703:/ clear");
	       /*clear *//*_.BUCKETLONG_PUT__V22*/ meltfptr[21] = 0;
		  /*^clear */
	       /*clear *//*_.SETQ___V23*/ meltfptr[22] = 0;
		  /*^clear */
	       /*clear *//*_.PROGN___V24*/ meltfptr[23] = 0;
		}
		;
	      }
	    ;
	    /* ending foreach_in_bucketlong meltcit2__EACHBUCKLONG */
     /*_#OLDKEY__L6*/ meltfnum[5] = 0L;
     /*_.OLDALA__V18*/ meltfptr[15] = NULL;
	  }			/* end foreach_in_bucketlong meltcit2__EACHBUCKLONG_ix */


	/*citerepilog */

	MELT_LOCATION ("warmelt-hooks.melt:2699:/ clear");
	     /*clear *//*_#OLDKEY__L6*/ meltfnum[5] = 0;
	/*^clear */
	     /*clear *//*_.OLDALA__V18*/ meltfptr[15] = 0;
	/*^clear */
	     /*clear *//*_.IFCPP___V19*/ meltfptr[16] = 0;
	/*^clear */
	     /*clear *//*_#eqeq__L8*/ meltfnum[6] = 0;
	/*^clear */
	     /*clear *//*_._IFELSE___V21*/ meltfptr[19] = 0;
      }				/*endciterblock FOREACH_IN_BUCKETLONG */
      ;
      MELT_LOCATION ("warmelt-hooks.melt:2706:/ putmodvar");
      melt_module_var_put (meltmodvarix_MELT_ALARMBUCKET_symb,
			   (melt_ptr_t) ( /*_.NEWBUCK__V14*/ meltfptr[9]));
      ;

      MELT_LOCATION ("warmelt-hooks.melt:2690:/ clear");
	    /*clear *//*_.OLDBUCK__V13*/ meltfptr[6] = 0;
      /*^clear */
	    /*clear *//*_#OLDBUCKLEN__L5*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_.NEWBUCK__V14*/ meltfptr[9] = 0;
      /*^clear */
	    /*clear *//*_._IFELSE___V15*/ meltfptr[11] = 0;
      /* block_signals meltcit1__BLKSIGNAL end */
      melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev;
      MELT_CHECK_SIGNAL ();


      /*citerepilog */
    }				/*endciterblock BLOCK_SIGNALS */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-hooks.melt:2681:/ clear");
	   /*clear *//*_._IFELSE___V5*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_#IS_NOT_A__L3*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V8*/ meltfptr[2] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("UNREGISTER_ALARM_TIMER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_83_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER (meltclosure_ptr_t
							   meltclosp_,
							   melt_ptr_t
							   meltfirstargp_,
							   const
							   melt_argdescr_cell_t
							   meltxargdescr_[],
							   union meltparam_un
							   * meltxargtab_,
							   const
							   melt_argdescr_cell_t
							   meltxresdescr_[],
							   union meltparam_un
							   * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 25
    melt_ptr_t mcfr_varptr[25];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER_st
	 *) meltfirstargp_;
      /* use arguments meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 25; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER nbval 25*/
  meltfram__.mcfr_nbvar = 25 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("REGISTER_CHILD_PROCESS_HANDLER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2829:/ getarg");
 /*_.CLOS__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#PID__L1*/ meltfnum[0] = meltxargtab_[0].meltbp_long;

  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.DATA__V3*/ meltfptr[2] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.DATA__V3*/ meltfptr[2])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2833:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L2*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2833:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L3*/ meltfnum[2] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2833:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2833;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"register_child_process_handler clos=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOS__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " pid=";
	      /*^apply.arg */
	      argtab[6].meltbp_long = /*_#PID__L1*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " data=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.DATA__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V4*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2833:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V4*/ meltfptr[3] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2833:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_CLOSURE__L4*/ meltfnum[2] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.CLOS__V2*/ meltfptr[1])) ==
       MELTOBMAG_CLOSURE);;
    MELT_LOCATION ("warmelt-hooks.melt:2834:/ cond");
    /*cond */ if ( /*_#IS_CLOSURE__L4*/ meltfnum[2])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#gtI__L5*/ meltfnum[1] =
	    (( /*_#PID__L1*/ meltfnum[0]) > (0));;
	  MELT_LOCATION ("warmelt-hooks.melt:2835:/ cond");
	  /*cond */ if ( /*_#gtI__L5*/ meltfnum[1])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-hooks.melt:2836:/ quasiblock");


     /*_#PIDISBAD__L6*/ meltfnum[5] = 0;;

		{
		  MELT_LOCATION ("warmelt-hooks.melt:2838:/ locexp");
		  /* register_child_process_handler TRYKILLCHK__1 */
		  if (kill ((pid_t) /*_#PID__L1*/ meltfnum[0], 0))
	     /*_#PIDISBAD__L6*/ meltfnum[5] = -1L;
		  ;
		}
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-hooks.melt:2844:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		    melt_dbgcounter++;
#endif
		    ;
		  }
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
       /*_#MELT_NEED_DBG__L7*/ meltfnum[6] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-hooks.melt:2844:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L7*/ meltfnum[6])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	 /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-hooks.melt:2844:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-hooks.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 2844;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "register_child_process_handler pidisbad=";
			  /*^apply.arg */
			  argtab[4].meltbp_long =
			    /*_#PIDISBAD__L6*/ meltfnum[5];
			  /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[0])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V9*/ meltfptr[8] =
			  /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2844:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V9*/ meltfptr[8] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2844:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[6] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*void */ (void) 0;
		  }
		  ;
		  /*epilog */
		}

#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2845:/ cond");
		/*cond */ if ( /*_#PIDISBAD__L6*/ meltfnum[5])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^quasiblock */


       /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

		      {
			MELT_LOCATION ("warmelt-hooks.melt:2845:/ locexp");
			/*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
			if (meltxresdescr_ && meltxresdescr_[0]
			    && meltxrestab_)
			  melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
			;
		      }
		      ;
		      /*^finalreturn */
		      ;
		      /*finalret */ goto meltlabend_rout;
		      /*_._IF___V11*/ meltfptr[9] =
			/*_.RETURN___V12*/ meltfptr[8];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-hooks.melt:2845:/ clear");
		 /*clear *//*_.RETURN___V12*/ meltfptr[8] = 0;
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_._IF___V11*/ meltfptr[9] = NULL;;
		  }
		;
		MELT_LOCATION ("warmelt-hooks.melt:2846:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;
     /*_.MAKE_INTEGERBOX__V14*/ meltfptr[13] =
		  (meltgc_new_int
		   ((meltobject_ptr_t)
		    (( /*!DISCR_CONSTANT_INTEGER */ meltfrout->tabval[2])),
		    ( /*_#PID__L1*/ meltfnum[0])));;
		MELT_LOCATION ("warmelt-hooks.melt:2846:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_CHILD_PROCESS_HANDLER */ meltfrout->tabval[1])), (4), "CLASS_CHILD_PROCESS_HANDLER");
      /*_.INST__V16*/ meltfptr[15] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @CHILPROH_PID",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V16*/
						   meltfptr[15])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V16*/ meltfptr[15]), (1),
				      ( /*_.MAKE_INTEGERBOX__V14*/
				       meltfptr[13]), "CHILPROH_PID");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @CHILPROH_CLOS",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V16*/
						   meltfptr[15])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V16*/ meltfptr[15]), (2),
				      ( /*_.CLOS__V2*/ meltfptr[1]),
				      "CHILPROH_CLOS");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @CHILPROH_DATA",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V16*/
						   meltfptr[15])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V16*/ meltfptr[15]), (3),
				      ( /*_.DATA__V3*/ meltfptr[2]),
				      "CHILPROH_DATA");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V16*/ meltfptr[15],
					      "newly made instance");
		;
		/*_.CHPH__V15*/ meltfptr[14] = /*_.INST__V16*/ meltfptr[15];;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-hooks.melt:2852:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
		    melt_dbgcounter++;
#endif
		    ;
		  }
		  ;

		  MELT_CHECK_SIGNAL ();
		  ;
       /*_#MELT_NEED_DBG__L9*/ meltfnum[7] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-hooks.melt:2852:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[7])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	 /*_#MELT_CALLCOUNT__L10*/ meltfnum[6] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-hooks.melt:2852:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L10*/ meltfnum[6];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-hooks.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 2852;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "register_child_process_handler chph=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CHPH__V15*/ meltfptr[14];
			  /*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[0])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V17*/ meltfptr[16] =
			  /*_.MELT_DEBUG_FUN__V18*/ meltfptr[17];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2852:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[6] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V17*/ meltfptr[16] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-hooks.melt:2852:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V17*/ meltfptr[16] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*^block */
		/*anyblock */
		{


		  {
		    /*^locexp */
		    /*void */ (void) 0;
		  }
		  ;
		  /*epilog */
		}

#endif /*MELT_HAVE_DEBUG */
		;
		/*citerblock BLOCK_SIGNALS */
		{
		  /* block_signals meltcit1__BLKSIGNAL start */
		  long meltcit1__BLKSIGNAL_lev = melt_blocklevel_signals;
		  melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev + 1;



		  MELT_LOCATION ("warmelt-hooks.melt:2855:/ quasiblock");


		  /*^cond */
												/*cond */ if ((melt_module_var_fetch (meltmodvarix_MELT_CHILDBUCK_symb)))
												/*then */
		    {
		      /*^cond.then */
      /*_.BUCK__V19*/ meltfptr[17] =
			(melt_module_var_fetch
					 (meltmodvarix_MELT_CHILDBUCK_symb));;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-hooks.melt:2855:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {

	/*_.MAKE_BUCKETLONG__V20*/ meltfptr[16] =
			  (meltgc_new_longsbucket
			   ((meltobject_ptr_t)
			    ( /*!DISCR_BUCKET_LONGS */ meltfrout->tabval[3]),
			    (13)));;
			/*^compute */
			/*_.BUCK__V19*/ meltfptr[17] =
			  /*_.MAKE_BUCKETLONG__V20*/ meltfptr[16];;
			/*epilog */

			MELT_LOCATION ("warmelt-hooks.melt:2855:/ clear");
		  /*clear *//*_.MAKE_BUCKETLONG__V20*/ meltfptr[16] = 0;
		      }
		      ;
		    }
		  ;

#if MELT_HAVE_DEBUG
		  MELT_LOCATION ("warmelt-hooks.melt:2858:/ cppif.then");
		  /*^block */
		  /*anyblock */
		  {


		    MELT_CHECK_SIGNAL ();
		    ;
	/*_#IS_BUCKETLONG__L11*/ meltfnum[6] =
		      (melt_magic_discr
		       ((melt_ptr_t) ( /*_.BUCK__V19*/ meltfptr[17])) ==
		       MELTOBMAG_BUCKETLONGS);;
		    MELT_LOCATION ("warmelt-hooks.melt:2858:/ cond");
		    /*cond */ if ( /*_#IS_BUCKETLONG__L11*/ meltfnum[6])	/*then */
		      {
			/*^cond.then */
			/*_._IFELSE___V22*/ meltfptr[21] = ( /*nil */ NULL);;
		      }
		    else
		      {
			MELT_LOCATION ("warmelt-hooks.melt:2858:/ cond.else");

			/*^block */
			/*anyblock */
			{




			  {
			    /*^locexp */
			    melt_assert_failed (("check buck"),
						("warmelt-hooks.melt")
						? ("warmelt-hooks.melt") :
						__FILE__,
						(2858) ? (2858) : __LINE__,
						__FUNCTION__);
			    ;
			  }
			  ;
		    /*clear *//*_._IFELSE___V22*/ meltfptr[21] = 0;
			  /*epilog */
			}
			;
		      }
		    ;
		    /*^compute */
		    /*_.IFCPP___V21*/ meltfptr[16] =
		      /*_._IFELSE___V22*/ meltfptr[21];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-hooks.melt:2858:/ clear");
		  /*clear *//*_#IS_BUCKETLONG__L11*/ meltfnum[6] = 0;
		    /*^clear */
		  /*clear *//*_._IFELSE___V22*/ meltfptr[21] = 0;
		  }

#else /*MELT_HAVE_DEBUG */
		  /*^cppif.else */
		  /*_.IFCPP___V21*/ meltfptr[16] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		  ;
		  /*^compute */
      /*_.BUCKETLONG_PUT__V23*/ meltfptr[21] =
		    meltgc_longsbucket_put ((melt_ptr_t) /*_.BUCK__V19*/
					    meltfptr[17],
					    ( /*_#PID__L1*/ meltfnum[0]),
					    (melt_ptr_t) /*_.CHPH__V15*/
					    meltfptr[14]);;
		  MELT_LOCATION ("warmelt-hooks.melt:2859:/ compute");
		  /*_.BUCK__V19*/ meltfptr[17] =
		    /*_.SETQ___V24*/ meltfptr[23] =
		    /*_.BUCKETLONG_PUT__V23*/ meltfptr[21];;
		  MELT_LOCATION ("warmelt-hooks.melt:2860:/ putmodvar");
		  melt_module_var_put (meltmodvarix_MELT_CHILDBUCK_symb,
				       (melt_ptr_t) ( /*_.BUCK__V19*/
						     meltfptr[17]));
		  ;

		  MELT_LOCATION ("warmelt-hooks.melt:2855:/ clear");
		/*clear *//*_.BUCK__V19*/ meltfptr[17] = 0;
		  /*^clear */
		/*clear *//*_.IFCPP___V21*/ meltfptr[16] = 0;
		  /*^clear */
		/*clear *//*_.BUCKETLONG_PUT__V23*/ meltfptr[21] = 0;
		  /*^clear */
		/*clear *//*_.SETQ___V24*/ meltfptr[23] = 0;
		  /* block_signals meltcit1__BLKSIGNAL end */
		  melt_blocklevel_signals = meltcit1__BLKSIGNAL_lev;
		  MELT_CHECK_SIGNAL ();


		  /*citerepilog */
		}		/*endciterblock BLOCK_SIGNALS */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-hooks.melt:2863:/ quasiblock");


		/*_._RETVAL___V1*/ meltfptr[0] =
		  /*_.CHPH__V15*/ meltfptr[14];;

		{
		  MELT_LOCATION ("warmelt-hooks.melt:2863:/ locexp");
		  /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
		  if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
		    melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
		  ;
		}
		;
		/*^finalreturn */
		;
		/*finalret */ goto meltlabend_rout;
		/*_.LET___V13*/ meltfptr[8] =
		  /*_.RETURN___V25*/ meltfptr[17];;

		MELT_LOCATION ("warmelt-hooks.melt:2846:/ clear");
	       /*clear *//*_.MAKE_INTEGERBOX__V14*/ meltfptr[13] = 0;
		/*^clear */
	       /*clear *//*_.CHPH__V15*/ meltfptr[14] = 0;
		/*^clear */
	       /*clear *//*_.RETURN___V25*/ meltfptr[17] = 0;
		/*_.LET___V8*/ meltfptr[7] = /*_.LET___V13*/ meltfptr[8];;

		MELT_LOCATION ("warmelt-hooks.melt:2836:/ clear");
	       /*clear *//*_#PIDISBAD__L6*/ meltfnum[5] = 0;
		/*^clear */
	       /*clear *//*_._IF___V11*/ meltfptr[9] = 0;
		/*^clear */
	       /*clear *//*_.LET___V13*/ meltfptr[8] = 0;
		/*_._IF___V7*/ meltfptr[3] = /*_.LET___V8*/ meltfptr[7];;
		/*epilog */

		MELT_LOCATION ("warmelt-hooks.melt:2835:/ clear");
	       /*clear *//*_.LET___V8*/ meltfptr[7] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_._IF___V7*/ meltfptr[3] = NULL;;
	    }
	  ;
	  /*^compute */
	  /*_._IF___V6*/ meltfptr[4] = /*_._IF___V7*/ meltfptr[3];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-hooks.melt:2834:/ clear");
	     /*clear *//*_#gtI__L5*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[3] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V6*/ meltfptr[4] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2829:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_._IF___V6*/ meltfptr[4];;

    {
      MELT_LOCATION ("warmelt-hooks.melt:2829:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_#IS_CLOSURE__L4*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_._IF___V6*/ meltfptr[4] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("REGISTER_CHILD_PROCESS_HANDLER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_85_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER (meltclosure_ptr_t
							     meltclosp_,
							     melt_ptr_t
							     meltfirstargp_,
							     const
							     melt_argdescr_cell_t
							     meltxargdescr_[],
							     union
							     meltparam_un *
							     meltxargtab_,
							     const
							     melt_argdescr_cell_t
							     meltxresdescr_[],
							     union
							     meltparam_un *
							     meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER_melt
    = melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER_st
  {
    int mcfr_nbvar;
#if MELT_HAVE_DEBUG
    const char *mcfr_flocs;
#else				/*!MELT_HAVE_DEBUG */
    const char *mcfr_unusedflocs;
#endif				/*MELT_HAVE_DEBUG */
    struct meltclosure_st *mcfr_clos;
    struct excepth_melt_st *mcfr_exh;
    struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
#define MELTFRAM_NBVARPTR 6
    melt_ptr_t mcfr_varptr[6];
#define MELTFRAM_NBVARNUM 2
    long mcfr_varnum[2];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER_st
	 *) meltfirstargp_;
      /* use arguments meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 6; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER nbval 6*/
  meltfram__.mcfr_nbvar = 6 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("UNREGISTER_CHILD_PROCESS_HANDLER", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-hooks.melt:2868:/ getarg");
 /*_.CHD__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2870:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*melt_increment_dbgcounter */
#if MELT_HAVE_DEBUG
	melt_dbgcounter++;
#endif
	;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-hooks.melt:2870:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-hooks.melt:2870:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-hooks.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 2870;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"unregister_child_process_handler chd=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CHD__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V4*/ meltfptr[3] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V3*/ meltfptr[2] =
	      /*_.MELT_DEBUG_FUN__V4*/ meltfptr[3];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-hooks.melt:2870:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V4*/ meltfptr[3] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V3*/ meltfptr[2] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-hooks.melt:2870:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V3*/ meltfptr[2] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*^block */
    /*anyblock */
    {


      {
	/*^locexp */
	/*void */ (void) 0;
      }
      ;
      /*epilog */
    }

#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-hooks.melt:2871:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
      /*^cond */
      /*cond */ if (( /*nil */ NULL))	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V6*/ meltfptr[2] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-hooks.melt:2871:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("@$@unimplemented unregister_child_process_handler"), ("warmelt-hooks.melt") ? ("warmelt-hooks.melt") : __FILE__, (2871) ? (2871) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V6*/ meltfptr[2] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[3] = /*_._IFELSE___V6*/ meltfptr[2];;
      /*epilog */

      MELT_LOCATION ("warmelt-hooks.melt:2871:/ clear");
	     /*clear *//*_._IFELSE___V6*/ meltfptr[2] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-hooks.melt:2868:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.IFCPP___V5*/ meltfptr[3];;

    {
      MELT_LOCATION ("warmelt-hooks.melt:2868:/ locexp");
      /*ochecknores compilobj_nrep_return */
#if MELT_HAVE_DEBUG
      if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
	melt_warn_for_no_expected_secondary_results ();
/* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG */
      ;
    }
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*epilog */

    /*^clear */
	   /*clear *//*_.IFCPP___V5*/ meltfptr[3] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("UNREGISTER_CHILD_PROCESS_HANDLER", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_86_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER */



/**** end of warmelt-hooks+03.c ****/
