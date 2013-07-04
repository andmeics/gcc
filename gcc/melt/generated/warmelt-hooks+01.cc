/* GCC MELT GENERATED C++ FILE warmelt-hooks+01.cc - DO NOT EDIT - see http://gcc-melt.org/ */
/* secondary MELT generated C++ file of rank #1 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f1[] = MELT_RUN_HASHMD5 /* from melt-run.h */;


/**** warmelt-hooks+01.cc declarations ****/
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
#define MELT_HAS_INITIAL_ENVIRONMENT 1 /*usualmodule*/


/*** 3 MELT module variables declarations ****/
MELT_EXTERN void melt_forwarding_module_data (void);
MELT_EXTERN void melt_marking_module_data (void);

MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY melt_WARMELTmiHOOKS_module_var_ptr_tab[16];
MELT_EXTERN bool MELT_MODULE_VISIBILITY melt_WARMELTmiHOOKS_module_var_flags[1];

static inline melt_ptr_t
melt_module_var_fetch (int ix)
{
    return (ix > 0  &&  ix <= 3)?melt_WARMELTmiHOOKS_module_var_ptr_tab[ix]:NULL;
}

static inline void
melt_module_var_put (int ix, melt_ptr_t val)
{
    if (ix > 0  &&  ix <= 3)
        {
            melt_WARMELTmiHOOKS_module_var_ptr_tab[ix]= val;
            melt_WARMELTmiHOOKS_module_var_flags[ix/16] = true;
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
}; /* end MELT module variables indexes */

/*** 3 MELT called hook declarations ***/

/*declare MELT called hook #0 HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_PREVENV, const char* meltinp1_MODULNAME);

/*declare MELT called hook #1 HOOK_SYMBOL_IMPORTER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_SYMBOL_IMPORTER (melt_ptr_t melthookdatap, const char* meltinp0_SYMNAMESTR, const char* meltinp1_MODULENAMESTR, melt_ptr_t meltinp2_PARENV);

/*declare MELT called hook #2 HOOK_VALUE_EXPORTER **/
MELT_EXTERN void melthook_HOOK_VALUE_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_VAL, melt_ptr_t meltinp2_CONTENV);

/*** end of 3 MELT called hook declarations ***/

/*** 27 extra MELT c-headers ***/


/** MELT extra c-header 1 : **/


static void
melt_override_gate_callback (void* gccdata,
                             void* userdata ATTRIBUTE_UNUSED)
{
    bool *pgatestatus = (bool*) gccdata;
    bool gatsta = false;
    long oldgatstalng = 0, newgatstalng = 0;
    gcc_assert (pgatestatus != NULL);
    gatsta = *pgatestatus;
    oldgatstalng = newgatstalng = (long)gatsta;
    melthookproc_HOOK_OVERRIDE_GATE (oldgatstalng, &newgatstalng);
    gatsta = (newgatstalng != 0L);
    *pgatestatus = gatsta;
} /* end of  melt_override_gate_callback */

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 2 : **/

/* flag for PLUGIN_OVERRIDE_GATE */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_override_gate_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 3 : **/

/* flag for PLUGIN_START_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_start_unit_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 4 : **/


void MELT_MODULE_VISIBILITY
melt_startunithook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                             void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 5 : **/

/* flag for PLUGIN_FINISH_UNIT */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_unit_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 6 : **/


void MELT_MODULE_VISIBILITY
melt_finishunithook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                              void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 7 : **/

/* flag for PLUGIN_ALL_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 8 : **/


void MELT_MODULE_VISIBILITY
melt_all_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                     void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 9 : **/

/* flag for PLUGIN_ALL_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 10 : **/


void MELT_MODULE_VISIBILITY
melt_all_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 11 : **/

/* flag for PLUGIN_ALL_IPA_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_ipa_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 12 : **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 13 : **/

/* flag for PLUGIN_ALL_IPA_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_all_ipa_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 14 : **/


void MELT_MODULE_VISIBILITY
melt_all_ipa_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                       void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 15 : **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_START declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_early_gimple_passes_start_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 16 : **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_start_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 17 : **/

/* flag for PLUGIN_EARLY_GIMPLE_PASSES_END declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_early_gimple_passes_end_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 18 : **/


void MELT_MODULE_VISIBILITY
melt_early_gimple_passes_end_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
        void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 19 : **/

/* flag for PLUGIN_PRE_GENERICIZE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_pre_genericize_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 20 : **/


void MELT_MODULE_VISIBILITY
melt_pre_genericize_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 21 : **/

/* flag for PLUGIN_FINISH_TYPE declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_type_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 22 : **/


void MELT_MODULE_VISIBILITY
melt_finish_type_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 23 : **/

/* flag for PLUGIN_FINISH_DECL declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_finish_decl_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 24 : **/


void MELT_MODULE_VISIBILITY
melt_finish_decl_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 25 : **/

/* flag for PLUGIN_PASS_EXECUTION declare */
MELT_EXTERN bool MELT_MODULE_VISIBILITY  melthk_pass_execution_registered_flag;

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 26 : **/


void MELT_MODULE_VISIBILITY
melt_pass_execution_hook_callback (void* gcc_data ATTRIBUTE_UNUSED,
                                   void* user_data ATTRIBUTE_UNUSED);

/*** end of 27 extra MELT c-headers ***/


/** MELT extra c-header 27 : **/

/* header from warmelt-hooks.melt for poll etc... */
#include <poll.h>

#define MELT_BUFSIZE 8192
#define MELT_POLL_DELAY_MILLISEC 500

/*** end of 27 extra MELT c-headers ***/

/** start of declaration for hook melthook_HOOK_LOW_DEBUG_VALUE_AT**/

/** declaration of hook melthook_HOOK_LOW_DEBUG_VALUE_AT */
MELT_EXTERN
void melthook_HOOK_LOW_DEBUG_VALUE_AT(melt_ptr_t melthookdatap,
                                      melt_ptr_t meltinp0_VAL,
                                      const char* meltinp1_FILENAME,
                                      long meltinp2_LINENO,
                                      const char* meltinp3_MSG,
                                      long meltinp4_COUNT)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_LOW_DEBUG_VALUE_AT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_LOW_DEBUG_VALUE_AT_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_LOW_DEBUG_VALUE_AT**/



/** start of declaration for hook melthook_HOOK_LOW_STDERR_VALUE_AT**/

/** declaration of hook melthook_HOOK_LOW_STDERR_VALUE_AT */
MELT_EXTERN
void melthook_HOOK_LOW_STDERR_VALUE_AT(melt_ptr_t melthookdatap,
                                       melt_ptr_t meltinp0_VAL,
                                       const char* meltinp1_FILENAME,
                                       long meltinp2_LINENO,
                                       const char* meltinp3_MSG,
                                       long meltinp4_COUNT)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_LOW_STDERR_VALUE_AT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_LOW_STDERR_VALUE_AT_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_LOW_STDERR_VALUE_AT**/



/** start of declaration for hook melthook_HOOK_OVERRIDE_GATE**/

/** declaration of hook melthook_HOOK_OVERRIDE_GATE */
MELT_EXTERN
void melthook_HOOK_OVERRIDE_GATE(melt_ptr_t melthookdatap,
                                 long meltinp0_BEFOREGATE,
                                 long* meltoutp0_AFTERGATE)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_OVERRIDE_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_OVERRIDE_GATE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_OVERRIDE_GATE**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_4_WARMELTmiHOOKS_ENABLE_OVERRIDE_GATE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_5_WARMELTmiHOOKS_MAYBE_DISABLE_OVERRIDE_GATE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_6_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_7_WARMELTmiHOOKS_REGISTER_OVERRIDE_GATE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_8_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_9_WARMELTmiHOOKS_UNREGISTER_OVERRIDE_GATE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_10_WARMELTmiHOOKS_LAMBDA_cl1(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_11_WARMELTmiHOOKS_LAMBDA_cl2(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_12_WARMELTmiHOOKS_LAMBDA_cl3(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_START_UNIT**/

/** declaration of hook melthook_HOOK_START_UNIT */
MELT_EXTERN
void melthook_HOOK_START_UNIT(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_START_UNIT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_START_UNIT_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_START_UNIT**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_14_WARMELTmiHOOKS_ENABLE_START_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_UNIT**/

/** declaration of hook melthook_HOOK_FINISH_UNIT */
MELT_EXTERN
void melthook_HOOK_FINISH_UNIT(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_FINISH_UNIT hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_UNIT_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_FINISH_UNIT**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_PASSES_START**/

/** declaration of hook melthook_HOOK_ALL_PASSES_START */
MELT_EXTERN
void melthook_HOOK_ALL_PASSES_START(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_ALL_PASSES_START hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_PASSES_START_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_ALL_PASSES_START**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_PASSES_END**/

/** declaration of hook melthook_HOOK_ALL_PASSES_END */
MELT_EXTERN
void melthook_HOOK_ALL_PASSES_END(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_ALL_PASSES_END hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_PASSES_END_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_ALL_PASSES_END**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_IPA_PASSES_START**/

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_START */
MELT_EXTERN
void melthook_HOOK_ALL_IPA_PASSES_START(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_ALL_IPA_PASSES_START hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_IPA_PASSES_START_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_ALL_IPA_PASSES_START**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_ALL_IPA_PASSES_END**/

/** declaration of hook melthook_HOOK_ALL_IPA_PASSES_END */
MELT_EXTERN
void melthook_HOOK_ALL_IPA_PASSES_END(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_ALL_IPA_PASSES_END hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_ALL_IPA_PASSES_END_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_ALL_IPA_PASSES_END**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_START**/

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_START */
MELT_EXTERN
void melthook_HOOK_EARLY_GIMPLE_PASSES_START(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_EARLY_GIMPLE_PASSES_START hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_EARLY_GIMPLE_PASSES_START_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_START**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_END**/

/** declaration of hook melthook_HOOK_EARLY_GIMPLE_PASSES_END */
MELT_EXTERN
void melthook_HOOK_EARLY_GIMPLE_PASSES_END(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_EARLY_GIMPLE_PASSES_END hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_EARLY_GIMPLE_PASSES_END_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_EARLY_GIMPLE_PASSES_END**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_45_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_46_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_47_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_48_WARMELTmiHOOKS_ENABLE_PRE_GENERICIZE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_PRE_GENERICIZE**/

/** declaration of hook melthook_HOOK_PRE_GENERICIZE */
MELT_EXTERN
void melthook_HOOK_PRE_GENERICIZE(melt_ptr_t melthookdatap,
                                  tree meltinp0_TFNDECL)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_PRE_GENERICIZE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_PRE_GENERICIZE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_PRE_GENERICIZE**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_50_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_51_WARMELTmiHOOKS_REGISTER_PRE_GENERICIZE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_52_WARMELTmiHOOKS_ENABLE_FINISH_TYPE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_TYPE**/

/** declaration of hook melthook_HOOK_FINISH_TYPE */
MELT_EXTERN
void melthook_HOOK_FINISH_TYPE(melt_ptr_t melthookdatap,
                               tree meltinp0_TFNDECL)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_FINISH_TYPE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_TYPE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_FINISH_TYPE**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_54_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_55_WARMELTmiHOOKS_REGISTER_FINISH_TYPE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_56_WARMELTmiHOOKS_RUN_ENDMELTPASS_FUNCTIONS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_57_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_58_WARMELTmiHOOKS_AT_END_OF_THIS_MELT_PASS_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_59_WARMELTmiHOOKS_ENABLE_FINISH_DECL(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_FINISH_DECL**/

/** declaration of hook melthook_HOOK_FINISH_DECL */
MELT_EXTERN
void melthook_HOOK_FINISH_DECL(melt_ptr_t melthookdatap,
                               tree meltinp0_TFNDECL)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_FINISH_DECL hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_FINISH_DECL_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_FINISH_DECL**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_61_WARMELTmiHOOKS_REGISTER_FINISH_DECL_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_62_WARMELTmiHOOKS_REGISTER_FINISH_DECL_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_PASS_EXECUTION**/

/** declaration of hook melthook_HOOK_PASS_EXECUTION */
MELT_EXTERN
void melthook_HOOK_PASS_EXECUTION(melt_ptr_t melthookdatap,
                                  const char* meltinp0_PASSNAME,
                                  long meltinp1_PASSNUM)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_PASS_EXECUTION hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_PASS_EXECUTION_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_PASS_EXECUTION**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_64_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_65_WARMELTmiHOOKS_REGISTER_PASS_EXECUTION_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_GIMPLE_GATE**/

/** declaration of hook melthook_HOOK_GIMPLE_GATE */
MELT_EXTERN
long melthook_HOOK_GIMPLE_GATE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_GIMPLE_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_GIMPLE_GATE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_GIMPLE_GATE**/



/** start of declaration for hook melthook_HOOK_GIMPLE_EXECUTE**/

/** declaration of hook melthook_HOOK_GIMPLE_EXECUTE */
MELT_EXTERN
long melthook_HOOK_GIMPLE_EXECUTE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_GIMPLE_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_GIMPLE_EXECUTE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_GIMPLE_EXECUTE**/



/** start of declaration for hook melthook_HOOK_RTL_GATE**/

/** declaration of hook melthook_HOOK_RTL_GATE */
MELT_EXTERN
long melthook_HOOK_RTL_GATE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_RTL_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_RTL_GATE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_RTL_GATE**/



/** start of declaration for hook melthook_HOOK_RTL_EXECUTE**/

/** declaration of hook melthook_HOOK_RTL_EXECUTE */
MELT_EXTERN
long melthook_HOOK_RTL_EXECUTE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_RTL_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_RTL_EXECUTE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_RTL_EXECUTE**/



/** start of declaration for hook melthook_HOOK_SIMPLE_IPA_GATE**/

/** declaration of hook melthook_HOOK_SIMPLE_IPA_GATE */
MELT_EXTERN
long melthook_HOOK_SIMPLE_IPA_GATE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_SIMPLE_IPA_GATE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_SIMPLE_IPA_GATE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_SIMPLE_IPA_GATE**/



/** start of declaration for hook melthook_HOOK_SIMPLE_IPA_EXECUTE**/

/** declaration of hook melthook_HOOK_SIMPLE_IPA_EXECUTE */
MELT_EXTERN
long melthook_HOOK_SIMPLE_IPA_EXECUTE(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_SIMPLE_IPA_EXECUTE hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_SIMPLE_IPA_EXECUTE_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_SIMPLE_IPA_EXECUTE**/



/** start of declaration for hook melthook_HOOK_MELT_ATTRIBUTE_DEFINER**/

/** declaration of hook melthook_HOOK_MELT_ATTRIBUTE_DEFINER */
MELT_EXTERN
void melthook_HOOK_MELT_ATTRIBUTE_DEFINER(melt_ptr_t melthookdatap,
        tree meltinp0_DECL,
        tree meltinp1_NAME,
        melt_ptr_t meltinp2_ATTRSEQ,
        const char* meltinp3_FILELOC,
        long meltinp4_LINENO)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_MELT_ATTRIBUTE_DEFINER hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_MELT_ATTRIBUTE_DEFINER_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_MELT_ATTRIBUTE_DEFINER**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_73_WARMELTmiHOOKS_AT_MELT_ATTRIBUTE_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_74_WARMELTmiHOOKS_AT_MELT_ATTRIBUTE_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_EXIT_FINALIZER**/

/** declaration of hook melthook_HOOK_EXIT_FINALIZER */
MELT_EXTERN
void melthook_HOOK_EXIT_FINALIZER(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_EXIT_FINALIZER hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_EXIT_FINALIZER_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_EXIT_FINALIZER**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_76_WARMELTmiHOOKS_AT_EXIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_77_WARMELTmiHOOKS_AT_EXIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_78_WARMELTmiHOOKS_MELT_INVOKE_INPUT_CALLBACKS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_POLL_INPUTS**/

/** declaration of hook melthook_HOOK_POLL_INPUTS */
MELT_EXTERN
void melthook_HOOK_POLL_INPUTS(melt_ptr_t melthookdatap,
                               long meltinp0_DELAYMS)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_POLL_INPUTS hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_POLL_INPUTS_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_POLL_INPUTS**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_80_WARMELTmiHOOKS_IS_POLLING_INPUTS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_81_WARMELTmiHOOKS_EVERY_POLLING_INPUT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_82_WARMELTmiHOOKS_GET_POLLING_INPUT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_83_WARMELTmiHOOKS_REGISTER_INPUT_CHANNEL_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_HANDLE_SIGIO**/

/** declaration of hook melthook_HOOK_HANDLE_SIGIO */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGIO(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGIO hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGIO_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_HANDLE_SIGIO**/



/** start of declaration for hook melthook_HOOK_HANDLE_SIGALRM**/

/** declaration of hook melthook_HOOK_HANDLE_SIGALRM */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGALRM(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGALRM hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGALRM_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_HANDLE_SIGALRM**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_86_WARMELTmiHOOKS_REGISTER_ALARM_TIMER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_87_WARMELTmiHOOKS_UNREGISTER_ALARM_TIMER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_HANDLE_SIGCHLD**/

/** declaration of hook melthook_HOOK_HANDLE_SIGCHLD */
MELT_EXTERN
void melthook_HOOK_HANDLE_SIGCHLD(melt_ptr_t melthookdatap)
;


#if !MELT_HAVE_CLASSY_FRAME /*fromline 2821*/
/* declare hook frame marking routine for melthook_HOOK_HANDLE_SIGCHLD hook */
void MELT_MODULE_VISIBILITY melthookmark_HOOK_HANDLE_SIGCHLD_rout (struct melt_callframe_st*, int);

#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2827*/


/** end of declaration for hook melthook_HOOK_HANDLE_SIGCHLD**/






melt_ptr_t MELT_MODULE_VISIBILITY meltrout_89_WARMELTmiHOOKS_REGISTER_CHILD_PROCESS_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY meltrout_90_WARMELTmiHOOKS_UNREGISTER_CHILD_PROCESS_HANDLER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);


MELT_EXTERN void* melt_start_this_module (void*); /*mandatory start of module*/

#if !MELT_HAVE_CLASSY_FRAME /*fromline 2333*/
struct melt_initial_frame_st; /*forward declaration of initial frame*/
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2337*/
/*declare opaque initial frame: */
#if MELT_HAVE_CLASSY_FRAME /*fromline 2342*/
typedef class Melt_InitialFrame /*opaqueinitialclassy*/ meltinitial_frame_t;
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2346*/
typedef struct melt_initial_frame_st meltinitial_frame_t;
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 2350*/


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG*/
MELT_EXTERN const char meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiHOOKS__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG*/



void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_0 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_1 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_2 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_3 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_4 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_5 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_6 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_7 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_8 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_9 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__initialmeltchunk_10 (meltinitial_frame_t*, char*);


void MELT_MODULE_VISIBILITY meltmod__WARMELTmiHOOKS__forward_or_mark_module_start_frame (struct melt_callframe_st* fp, int marking);



/**** warmelt-hooks+01.cc implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST */

    /** start of frame for meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST), clos) {};
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST)) {};
        MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 1
        long mcfr_varnum[1];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST**/

    /* end of frame for routine meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST */ MeltFrame_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST */ struct meltframe_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("AT_START_UNIT_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:376:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:378:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!START_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
            /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:380:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:381:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_START_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:382:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:380:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:378:/ clear");
        /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_START_UNIT_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_15_WARMELTmiHOOKS_AT_START_UNIT_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST */

    /** start of frame for meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST), clos) {};
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST)) {};
        MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 1
        long mcfr_varnum[1];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST**/

    /* end of frame for routine meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST */ MeltFrame_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST */ struct meltframe_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("AT_START_UNIT_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:385:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:387:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!START_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 3, "DELQU_LAST");
            /*_.LASTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:389:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:390:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_START_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:391:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:389:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_START_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:387:/ clear");
        /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_START_UNIT_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_16_WARMELTmiHOOKS_AT_START_UNIT_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 */

    /** start of frame for meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4), clos) {};
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4)) {};
        MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4**/

    /* end of frame for routine meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 */ MeltFrame_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 */ struct meltframe_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_st*) meltfirstargp_;
            /* use arguments meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4 nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("LAMBDA_cl4", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:425:/ getarg");
    /*_.FIRSTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:426:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 0, "REFERENCED_VALUE");
            /*_.PREVRES__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:427:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0]);
            /*_.NEXTRES__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)(/*_.FIRSTPROC__V2*/ meltfptr[1]), (melt_ptr_t)(/*_.PREVRES__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:429:/ quasiblock");


        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @REFERENCED_VALUE", melt_magic_discr((melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0]))) == MELTOBMAG_OBJECT);
        melt_putfield_object(((/*~RESCONT*/ meltfclos->tabval[0])), (0), (/*_.NEXTRES__V4*/ meltfptr[3]), "REFERENCED_VALUE");
        ;
        /*^touch*/
        meltgc_touch((/*~RESCONT*/ meltfclos->tabval[0]));
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object ((/*~RESCONT*/ meltfclos->tabval[0]), "put-fields");
        ;


        MELT_LOCATION("warmelt-hooks.melt:426:/ clear");
        /*clear*/ /*_.PREVRES__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_.NEXTRES__V4*/ meltfptr[3] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl4", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_17_WARMELTmiHOOKS_LAMBDA_cl4*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 */

    /** start of frame for meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5// fromline 1519
        : public Melt_CallFrameWithValues<2>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<2> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5), clos) {};
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5() //the constructor fromline 1594
            : Melt_CallFrameWithValues<2> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5)) {};
        MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 2
        melt_ptr_t mcfr_varptr[2];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 1
        long mcfr_varnum[1];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5**/

    /* end of frame for routine meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 */ MeltFrame_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 */ struct meltframe_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_st*) meltfirstargp_;
            /* use arguments meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<2; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5 nbval 2*/
    meltfram__.mcfr_nbvar = 2/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("LAMBDA_cl5", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:434:/ getarg");
    /*_.LASTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:435:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        meltgc_prepend_list((melt_ptr_t)((/*~REVLASTLIST*/ meltfclos->tabval[0])), (melt_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1]));
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:434:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl5", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_18_WARMELTmiHOOKS_LAMBDA_cl5*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                      const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 */

    /** start of frame for meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6), clos) {};
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6)) {};
        MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6**/

    /* end of frame for routine meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 */ MeltFrame_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 */ struct meltframe_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_st*) meltfirstargp_;
            /* use arguments meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6 nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("LAMBDA_cl6", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:439:/ getarg");
    /*_.LASTPROC__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:440:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 0, "REFERENCED_VALUE");
            /*_.PREVRES__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:441:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0]);
            /*_.NEXTRES__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)(/*_.LASTPROC__V2*/ meltfptr[1]), (melt_ptr_t)(/*_.PREVRES__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-hooks.melt:443:/ quasiblock");


        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @REFERENCED_VALUE", melt_magic_discr((melt_ptr_t)((/*~RESCONT*/ meltfclos->tabval[0]))) == MELTOBMAG_OBJECT);
        melt_putfield_object(((/*~RESCONT*/ meltfclos->tabval[0])), (0), (/*_.NEXTRES__V4*/ meltfptr[3]), "REFERENCED_VALUE");
        ;
        /*^touch*/
        meltgc_touch((/*~RESCONT*/ meltfclos->tabval[0]));
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object ((/*~RESCONT*/ meltfclos->tabval[0]), "put-fields");
        ;


        MELT_LOCATION("warmelt-hooks.melt:440:/ clear");
        /*clear*/ /*_.PREVRES__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_.NEXTRES__V4*/ meltfptr[3] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl6", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_19_WARMELTmiHOOKS_LAMBDA_cl6*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT */

    /** start of frame for meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT), clos) {};
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT)) {};
        MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT**/

    /* end of frame for routine meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT */ MeltFrame_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT */ struct meltframe_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_st*) meltfirstargp_;
            /* use arguments meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_FINISH_UNIT", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:467:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:468:/ locexp");
            /* enable_finish_unit ENFINISHUNIT_CHK__1 */
            if (!melthk_finish_unit_registered_flag)
                {
                    melthk_finish_unit_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_FINISH_UNIT,
                                       melt_finishunithook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_FINISH_UNIT", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_21_WARMELTmiHOOKS_ENABLE_FINISH_UNIT*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST */

    /** start of frame for meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST), clos) {};
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST)) {};
        MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 1
        long mcfr_varnum[1];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST**/

    /* end of frame for routine meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST */ MeltFrame_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST */ struct meltframe_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("AT_FINISH_UNIT_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:481:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:484:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
            /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:486:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:487:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_FINISH_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:488:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:486:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:484:/ clear");
        /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_FINISH_UNIT_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_22_WARMELTmiHOOKS_AT_FINISH_UNIT_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST */

    /** start of frame for meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST// fromline 1519
        : public Melt_CallFrameWithValues<4>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[1];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST), clos) {};
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<4> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST)) {};
        MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<4> (fil,lin, sizeof(MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 4
        melt_ptr_t mcfr_varptr[4];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 1
        long mcfr_varnum[1];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST**/

    /* end of frame for routine meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST */ MeltFrame_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST */ struct meltframe_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<4; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST nbval 4*/
    meltfram__.mcfr_nbvar = 4/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("AT_FINISH_UNIT_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:491:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {

        MELT_LOCATION("warmelt-hooks.melt:494:/ quasiblock");


        /*^getslot*/
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)((/*!FINISH_UNIT_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
            melt_object_get_field(slot,obj, 3, "DELQU_LAST");
            /*_.LASTLIST__V3*/ meltfptr[2] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:496:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:497:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_FINISH_UNIT*/ meltfrout->tabval[1])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:498:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:496:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.ENABLE_FINISH_UNIT__V4*/ meltfptr[3] = 0 ;
                }
                ;
            } /*noelse*/
        ;

        MELT_LOCATION("warmelt-hooks.melt:494:/ clear");
        /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("AT_FINISH_UNIT_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_23_WARMELTmiHOOKS_AT_FINISH_UNIT_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START */

    /** start of frame for meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START), clos) {};
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START)) {};
        MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START**/

    /* end of frame for routine meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START */ MeltFrame_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START */ struct meltframe_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_st*) meltfirstargp_;
            /* use arguments meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_ALL_PASSES_START", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:567:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:568:/ locexp");
            /* enable_all_passes_start ENALLPASSESSTART_CHK__1 */
            if (!melthk_all_passes_start_registered_flag)
                {
                    melthk_all_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_PASSES_START,
                                       melt_all_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_25_WARMELTmiHOOKS_ENABLE_ALL_PASSES_START*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST */

    /** start of frame for meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST**/

    /* end of frame for routine meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST */ MeltFrame_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST */ struct meltframe_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_PASSES_START_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:580:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:584:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:585:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:587:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:588:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:590:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:591:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:589:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:588:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:596:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:585:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:584:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:599:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_start_hook_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:580:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_26_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST */

    /** start of frame for meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST)) {};
        MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST**/

    /* end of frame for routine meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST */ MeltFrame_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST */ struct meltframe_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_PASSES_START_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:603:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:607:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:608:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:610:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:611:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:613:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:614:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:612:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:611:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:619:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:608:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:607:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:622:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:603:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_27_WARMELTmiHOOKS_REGISTER_ALL_PASSES_START_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END */

    /** start of frame for meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END), clos) {};
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END)) {};
        MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END**/

    /* end of frame for routine meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END */ MeltFrame_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END */ struct meltframe_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_st*) meltfirstargp_;
            /* use arguments meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_ALL_PASSES_END", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:690:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:691:/ locexp");
            /* enable_all_passes_end ENALLPASSESEND_CHK__1 */
            if (!melthk_all_passes_end_registered_flag)
                {
                    melthk_all_passes_end_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_PASSES_END,
                                       melt_all_passes_end_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_PASSES_END", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_29_WARMELTmiHOOKS_ENABLE_ALL_PASSES_END*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST */

    /** start of frame for meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST), clos) {};
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST)) {};
        MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST**/

    /* end of frame for routine meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST */ MeltFrame_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST */ struct meltframe_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_PASSES_END_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:703:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:707:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:708:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:710:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:711:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:713:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:714:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:712:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:711:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:719:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:708:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:707:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:722:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_end_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:703:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_END_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_30_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST */

    /** start of frame for meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST), clos) {};
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST)) {};
        MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST**/

    /* end of frame for routine meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST */ MeltFrame_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST */ struct meltframe_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_PASSES_END_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:726:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:730:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:731:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:733:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:734:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:736:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:737:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:735:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:734:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:742:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:731:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:730:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:745:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_passes_end_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:726:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_PASSES_END_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_31_WARMELTmiHOOKS_REGISTER_ALL_PASSES_END_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START */

    /** start of frame for meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START), clos) {};
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START)) {};
        MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START**/

    /* end of frame for routine meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START */ MeltFrame_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START */ struct meltframe_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_st*) meltfirstargp_;
            /* use arguments meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_ALL_IPA_PASSES_START", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:812:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:813:/ locexp");
            /* enable_all_ipa_passes_start ENALLPASSESSTART_CHK__2 */
            if (!melthk_all_ipa_passes_start_registered_flag)
                {
                    melthk_all_ipa_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_IPA_PASSES_START,
                                       melt_all_ipa_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_IPA_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_33_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_START*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST */

    /** start of frame for meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST**/

    /* end of frame for routine meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST */ MeltFrame_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST */ struct meltframe_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_IPA_PASSES_START_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:825:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:829:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:830:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:832:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:833:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:835:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:836:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:834:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:833:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:841:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:830:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:829:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:844:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_start_hook_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:825:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_34_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST */

    /** start of frame for meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST)) {};
        MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST**/

    /* end of frame for routine meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST */ MeltFrame_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST */ struct meltframe_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_IPA_PASSES_START_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:848:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:852:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:853:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:855:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:856:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:858:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:859:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:857:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:856:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:864:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:853:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:852:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:867:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:848:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_35_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_START_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END */

    /** start of frame for meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END), clos) {};
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END)) {};
        MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END**/

    /* end of frame for routine meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END */ MeltFrame_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END */ struct meltframe_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_st*) meltfirstargp_;
            /* use arguments meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_ALL_IPA_PASSES_END", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:935:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:936:/ locexp");
            /* enable_all_ipa_passes_end ENALLPASSESEND_CHK__2 */
            if (!melthk_all_ipa_passes_end_registered_flag)
                {
                    melthk_all_ipa_passes_end_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_ALL_IPA_PASSES_END,
                                       melt_all_ipa_passes_end_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_ALL_IPA_PASSES_END", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_37_WARMELTmiHOOKS_ENABLE_ALL_IPA_PASSES_END*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST */

    /** start of frame for meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST), clos) {};
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST)) {};
        MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST**/

    /* end of frame for routine meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST */ MeltFrame_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST */ struct meltframe_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_IPA_PASSES_END_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:948:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:952:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:953:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:955:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:956:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:958:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:959:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:957:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:956:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:964:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:953:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:952:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:967:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_end_first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:948:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_END_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_38_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST */

    /** start of frame for meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST), clos) {};
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST)) {};
        MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST**/

    /* end of frame for routine meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST */ MeltFrame_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST */ struct meltframe_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_ALL_IPA_PASSES_END_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:971:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:975:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:976:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:978:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_ALL_IPA_PASSES_END*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:979:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:981:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:982:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!ALL_IPA_PASSES_END_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:980:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:979:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:987:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:976:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_ALL_IPA_PASSES_END__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:975:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:990:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_all_ipa_passes_end_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:971:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_ALL_IPA_PASSES_END_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_39_WARMELTmiHOOKS_REGISTER_ALL_IPA_PASSES_END_LAST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START */

    /** start of frame for meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START// fromline 1519
        : public Melt_CallFrameWithValues<1>
    {
    public: /* fromline 1523*/
// no classy longs
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START), clos) {};
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START() //the constructor fromline 1594
            : Melt_CallFrameWithValues<1> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START)) {};
        MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<1> (fil,lin, sizeof(MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 1
        melt_ptr_t mcfr_varptr[1];
        /*no varnum fromline 1716*/
#define MELTFRAM_NBVARNUM /*none*/0
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START**/

    /* end of frame for routine meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START */ MeltFrame_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START */ struct meltframe_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_st*) meltfirstargp_;
            /* use arguments meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<1; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START nbval 1*/
    meltfram__.mcfr_nbvar = 1/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("ENABLE_EARLY_GIMPLE_PASSES_START", meltcallcount);
    /*getargs*/
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    MELT_LOCATION("warmelt-hooks.melt:1058:/ block");
    /*anyblock*/
    {


        {
            MELT_LOCATION("warmelt-hooks.melt:1059:/ locexp");
            /* enable_early_gimple_passes_start ENALLPASSESSTART_CHK__3 */
            if (!melthk_early_gimple_passes_start_registered_flag)
                {
                    melthk_early_gimple_passes_start_registered_flag = true;
                    register_callback (melt_plugin_name, PLUGIN_EARLY_GIMPLE_PASSES_START,
                                       melt_early_gimple_passes_start_hook_callback,
                                       NULL);
                }
            ;
        }
        ;
        /*epilog*/
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("ENABLE_EARLY_GIMPLE_PASSES_START", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_41_WARMELTmiHOOKS_ENABLE_EARLY_GIMPLE_PASSES_START*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST */

    /** start of frame for meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST), clos) {};
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST)) {};
        MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST**/

    /* end of frame for routine meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST */ MeltFrame_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST */ struct meltframe_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_st*) meltfirstargp_;
            /* use arguments meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_EARLY_GIMPLE_PASSES_START_FIRST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:1071:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:1075:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:1076:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "DELQU_FIRST");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.FIRSTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:1078:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_EARLY_GIMPLE_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.FIRSTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:1079:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1081:/ compute");
                                /*_.FIRSTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1082:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.FIRSTLIST__V3*/ meltfptr[2]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:1080:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:1079:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:1087:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.FIRSTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:1076:/ clear");
                    /*clear*/ /*_.FIRSTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:1075:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:1090:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_early_gimple_passes_start_hook_\
first"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:1071:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_EARLY_GIMPLE_PASSES_START_FIRST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_42_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_FIRST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1487

    /* start of frame for routine meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST */

    /** start of frame for meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST**/
#if MELT_HAVE_CLASSY_FRAME /* fromline 1506*/
    /*curframdeclclassy*/ class MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST// fromline 1519
        : public Melt_CallFrameWithValues<7>
    {
    public: /* fromline 1523*/
        long mcfr_varnum[2];
        /*classy others*/
        long _meltsparel;
        void melt_mark_stuff (void)
        {
        } /*end melt_mark_stuff*/
        virtual void melt_mark_ggc_data (void)
        {
            melt_mark_values ();
            melt_mark_stuff ();
        }; /*end melt_mark_ggc_data*/
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(meltclosure_ptr_t clos) //the closure constructor fromline 1582
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1586*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1590*/
                sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST), clos) {};
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST() //the constructor fromline 1594
            : Melt_CallFrameWithValues<7> (
#if MELT_HAVE_DEBUG /*fromline 1598*/
                __FILE__, __LINE__,
#endif /* MELT_HAVE_DEBUG fromline 1602*/
                sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST)) {};
#if MELT_HAVE_DEBUG /*fromline 1606*/
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(const char*fil, int lin) //the constructor fromline 1608
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST)) {};
        MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1613
            : Melt_CallFrameWithValues<7> (fil,lin, sizeof(MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST), clos) {};
#endif /* MELT_HAVE_DEBUG fromline 1618*/

    }; // end  class MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST

#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1650*/

    /*curframdeclstruct fromline 1654*/ struct meltframe_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_st
    {
        int mcfr_nbvar;
        const char* mcfr_flocs;
        struct meltclosure_st *mcfr_clos;
        struct excepth_melt_st *mcfr_exh;
        struct melt_callframe_st *mcfr_prev;
#undef MELTFRAM_NBVARPTR
#undef MELTFRAM_NBVARNUM
        /*varptr fromline 1690*/
#define MELTFRAM_NBVARPTR 7
        melt_ptr_t mcfr_varptr[7];
        /*varnum fromline 1706*/
#define MELTFRAM_NBVARNUM 2
        long mcfr_varnum[2];
        /*others fromline1722*/
        long _meltspare_;
    };
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1751*/
    /** end of frame for meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST**/

    /* end of frame for routine meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST */

#if MELT_HAVE_CLASSY_FRAME /*fromline 1875*/
    /* classy proc frame meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST */ MeltFrame_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST
#else /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 1894*/
    /* plain proc frame meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST */ struct meltframe_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_st
#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1909*/
    *meltframptr_=0,    meltfram__ /*declfrastruct fromline 1913*/
#if MELT_HAVE_CLASSY_FRAME /*fromline 1915*/
                  /*classyprocarg meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST fromline 1920*/
#if MELT_HAVE_DEBUG
                  (__FILE__, __LINE__, meltclosp_) /* fromline 1924*/
#else /*MELT_HAVE_DEBUG*/
                  (meltclosp_) /* fromline 1928*/
#endif /*MELT_HAVE_DEBUG*/

#endif /*MELT_HAVE_CLASSY_FRAME*/ /*fromline 1959*/
                  ;
#define meltframe meltfram__
#if !MELT_HAVE_CLASSY_FRAME /*fromline 1965*/
    /*meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST is not initial declstructinit*/
    if (MELT_UNLIKELY(meltxargdescr_ == MELTPAR_MARKGGC))   /*mark for ggc*/
        {
            int meltix;
            meltframptr_ = (struct meltframe_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_st*) meltfirstargp_;
            /* use arguments meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST output_curframe_declstruct_init */
            (void) meltclosp_;
            (void) meltfirstargp_;
            (void) meltxargdescr_;
            (void) meltxargtab_;
            (void) meltxresdescr_;
            (void) meltxrestab_;
            /* marking closure */
            gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
            for(meltix=0; meltix<7; meltix++)
                if (meltframptr_->mcfr_varptr[meltix])
                    gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
            return NULL;
        }/*end markggc*/;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2020*/
    memset(&meltfram__, 0, sizeof(meltfram__));
#endif /*MELT_HAVE_CLASSY_FRAME*/
    /* declstructinit plain routine meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST nbval 7*/
    meltfram__.mcfr_nbvar = 7/*nbval*/;
    meltfram__.mcfr_clos = meltclosp_;
    meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe /*declstructinit*/;
    melt_topframe = /* declstructinit */ (struct melt_callframe_st *) &meltfram__;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2044*/
    melt_trace_start("REGISTER_EARLY_GIMPLE_PASSES_START_LAST", meltcallcount);
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-hooks.melt:1094:/ getarg");
    /*_.FUN__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_CLOSURE__L1*/ meltfnum[0] =
            (melt_magic_discr((melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1])) == MELTOBMAG_CLOSURE);;
        MELT_LOCATION("warmelt-hooks.melt:1098:/ cond");
        /*cond*/ if (/*_#IS_CLOSURE__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-hooks.melt:1099:/ quasiblock");


                    /*^cond*/
                    /*cond*/ if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                      (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])) /*=obj*/;
                                melt_object_get_field(slot,obj, 3, "DELQU_LAST");
                                /*_.LASTLIST__V3*/ meltfptr[2] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LASTLIST__V3*/ meltfptr[2] =  /*fromline 1327*/ NULL ;;
                        }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-hooks.melt:1101:/ apply");
                    /*apply*/
                    {
                        /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!ENABLE_EARLY_GIMPLE_PASSES_START*/ meltfrout->tabval[2])), (melt_ptr_t)( /*fromline 1327*/ NULL ), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#NULL__L2*/ meltfnum[1] =
                        ((/*_.LASTLIST__V3*/ meltfptr[2]) == NULL);;
                    MELT_LOCATION("warmelt-hooks.melt:1102:/ cond");
                    /*cond*/ if (/*_#NULL__L2*/ meltfnum[1]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_.MAKE_LIST__V5*/ meltfptr[4] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1104:/ compute");
                                /*_.LASTLIST__V3*/ meltfptr[2] = /*_.SETQ___V6*/ meltfptr[5] = /*_.MAKE_LIST__V5*/ meltfptr[4];;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_.MAKE_LIST__V7*/ meltfptr[6] =
                                    (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[3]))));;
                                MELT_LOCATION("warmelt-hooks.melt:1105:/ cond");
                                /*cond*/ if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])),
                                                                  (melt_ptr_t)((/*!CLASS_DELAYED_QUEUE*/ meltfrout->tabval[1])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_FIRST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (2), (/*_.MAKE_LIST__V7*/ meltfptr[6]), "DELQU_FIRST");
                                            ;
                                            /*^putslot*/
                                            /*putslot*/
                                            melt_assertmsg("checkobj putslot  _ @DELQU_LAST", melt_magic_discr((melt_ptr_t)((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]))) == MELTOBMAG_OBJECT);
                                            melt_putfield_object(((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0])), (3), (/*_.LASTLIST__V3*/ meltfptr[2]), "DELQU_LAST");
                                            ;
                                            /*^touch*/
                                            meltgc_touch((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]));
                                            ;
                                            /*^touchobj*/

                                            melt_dbgtrace_written_object ((/*!EARLY_GIMPLE_PASSES_START_DELAYED_QUEUE*/ meltfrout->tabval[0]), "put-fields");
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;
                                MELT_LOCATION("warmelt-hooks.melt:1103:/ quasiblock");


                                /*epilog*/

                                MELT_LOCATION("warmelt-hooks.melt:1102:/ clear");
                                /*clear*/ /*_.MAKE_LIST__V5*/ meltfptr[4] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V6*/ meltfptr[5] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MAKE_LIST__V7*/ meltfptr[6] = 0 ;
                            }
                            ;
                        } /*noelse*/
                    ;

                    {
                        MELT_LOCATION("warmelt-hooks.melt:1110:/ locexp");
                        meltgc_append_list((melt_ptr_t)(/*_.LASTLIST__V3*/ meltfptr[2]), (melt_ptr_t)(/*_.FUN__V2*/ meltfptr[1]));
                    }
                    ;

                    MELT_LOCATION("warmelt-hooks.melt:1099:/ clear");
                    /*clear*/ /*_.LASTLIST__V3*/ meltfptr[2] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.ENABLE_EARLY_GIMPLE_PASSES_START__V4*/ meltfptr[3] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#NULL__L2*/ meltfnum[1] = 0 ;
                    /*epilog*/
                }
                ;
            }
        else
            {
                MELT_LOCATION("warmelt-hooks.melt:1098:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-hooks.melt:1113:/ locexp");
                        error ("MELT ERROR MSG [#%ld]::: %s", melt_dbgcounter, ( "Bad function (non closure) passed to register_early_gimple_passes_start_hook_last"));
                    }
                    ;
                    /*epilog*/
                }
                ;
            }
        ;
        /*epilog*/

        MELT_LOCATION("warmelt-hooks.melt:1094:/ clear");
        /*clear*/ /*_#IS_CLOSURE__L1*/ meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("REGISTER_EARLY_GIMPLE_PASSES_START_LAST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST_melt;
#if !MELT_HAVE_CLASSY_FRAME /*fromline 2191*/
    melt_topframe /*endprocroutine*/ = (struct melt_callframe_st*) meltfram__.mcfr_prev;
#endif /*!MELT_HAVE_CLASSY_FRAME*/ /*fromline 2195*/
    return (melt_ptr_t)(/*noretval*/ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_43_WARMELTmiHOOKS_REGISTER_EARLY_GIMPLE_PASSES_START_LAST*/



/**** end of warmelt-hooks+01.cc ****/
