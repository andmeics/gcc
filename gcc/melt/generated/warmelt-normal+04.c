/* GCC MELT GENERATED FILE warmelt-normal+04.c - DO NOT EDIT */
/* secondary MELT generated C file of rank #4 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f4[] =
  MELT_RUN_HASHMD5 /* from melt-run.h */ ;


/**** warmelt-normal+04.c declarations ****/
/**** MELT GENERATED DECLARATIONS for warmelt-normal ** DO NOT EDIT ; see gcc-melt.org ****/

/****++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
***
    Copyright 2008 - 2013 Free Software Foundation, Inc.
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


/** ordinary MELT module meltbuild-sources/warmelt-normal**/
#define MELT_HAS_INITIAL_ENVIRONMENT 1	/*usualmodule */


/**** no MELT module variables ****/

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

/*** no extra MELT c-headers ***/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_1_WARMELTmiNORMAL_NORMAL_IMPORT (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_2_WARMELTmiNORMAL_ADD_NCTX_DATA (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_3_WARMELTmiNORMAL_FILL_INITIAL_PREDEFMAP (meltclosure_ptr_t
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
meltrout_4_WARMELTmiNORMAL_REGISTER_LITERAL_VALUE (meltclosure_ptr_t
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
meltrout_5_WARMELTmiNORMAL_CREATE_NORMCONTEXT (meltclosure_ptr_t meltclosp_,
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
meltrout_6_WARMELTmiNORMAL_CREATE_NORMAL_EXTENDING_CONTEXT (meltclosure_ptr_t
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
meltrout_7_WARMELTmiNORMAL_NORMEXP_IDENTICAL (meltclosure_ptr_t meltclosp_,
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
meltrout_8_WARMELTmiNORMAL_NORMEXP_NULL (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_9_WARMELTmiNORMAL_NORMEXP_ANY_OBJECT (meltclosure_ptr_t meltclosp_,
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
meltrout_10_WARMELTmiNORMAL_NORMEXP_ANY_VALUE (meltclosure_ptr_t meltclosp_,
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
meltrout_11_WARMELTmiNORMAL_NORMEXP_SRC_CATCHALL (meltclosure_ptr_t
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
meltrout_12_WARMELTmiNORMAL_NORMEXP_LAZYMACROEXP (meltclosure_ptr_t
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
meltrout_13_WARMELTmiNORMAL_GECTYP_ANYRECV (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_14_WARMELTmiNORMAL_GECTYP_ROOT (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_15_WARMELTmiNORMAL_GECTYP_INTEGER (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_16_WARMELTmiNORMAL_GECTYP_STRING (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_17_WARMELTmiNORMAL_NORMALIZE_TUPLE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_18_WARMELTmiNORMAL_LAMBDA_cl1 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_19_WARMELTmiNORMAL_WRAP_NORMAL_LET1 (meltclosure_ptr_t meltclosp_,
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
meltrout_20_WARMELTmiNORMAL_LAMBDA_cl2 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_21_WARMELTmiNORMAL_WRAP_NORMAL_LETSEQ (meltclosure_ptr_t meltclosp_,
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
meltrout_22_WARMELTmiNORMAL_LAMBDA_cl3 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_23_WARMELTmiNORMAL_CHECK_CTYPE_NARGS (meltclosure_ptr_t meltclosp_,
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
meltrout_24_WARMELTmiNORMAL_LAMBDA_cl4 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_25_WARMELTmiNORMAL_NORMBIND_FAILANY (meltclosure_ptr_t meltclosp_,
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
meltrout_26_WARMELTmiNORMAL_NORMBIND_ANYBIND (meltclosure_ptr_t meltclosp_,
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
meltrout_27_WARMELTmiNORMAL_NORMBIND_FORMALBIND (meltclosure_ptr_t meltclosp_,
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
meltrout_28_WARMELTmiNORMAL_NORMBIND_LETBIND (meltclosure_ptr_t meltclosp_,
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
meltrout_29_WARMELTmiNORMAL_NORMBIND_FIXBIND (meltclosure_ptr_t meltclosp_,
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
meltrout_30_WARMELTmiNORMAL_NORMBIND_DEFINEDVALBIND (meltclosure_ptr_t
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
meltrout_31_WARMELTmiNORMAL_NORMBIND_CONSTRUCTBIND (meltclosure_ptr_t
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
meltrout_32_WARMELTmiNORMAL_NORMEXP_SYMBOL (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_33_WARMELTmiNORMAL_GECTYP_SYMOCC (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_34_WARMELTmiNORMAL_GECTYP_MODVAROCC (meltclosure_ptr_t meltclosp_,
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
meltrout_35_WARMELTmiNORMAL_NORMEXP_CLASS (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_36_WARMELTmiNORMAL_NORMEXP_PRIMITIVE (meltclosure_ptr_t meltclosp_,
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
meltrout_37_WARMELTmiNORMAL_NORMEXP_HOOK_CALL (meltclosure_ptr_t meltclosp_,
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
meltrout_38_WARMELTmiNORMAL_NORMEXP_BOX (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_39_WARMELTmiNORMAL_NORMEXP_CONSTBOX (meltclosure_ptr_t meltclosp_,
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
meltrout_40_WARMELTmiNORMAL_NORMEXP_UNBOX (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_41_WARMELTmiNORMAL_NORMEXP_CODE_CHUNK (meltclosure_ptr_t meltclosp_,
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
meltrout_42_WARMELTmiNORMAL_LAMBDA_cl5 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_43_WARMELTmiNORMAL_NORMEXP_EXPR_CHUNK (meltclosure_ptr_t meltclosp_,
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
meltrout_44_WARMELTmiNORMAL_NORMEXP_CMATCHEXPR (meltclosure_ptr_t meltclosp_,
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
meltrout_45_WARMELTmiNORMAL_LAMBDA_cl6 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_46_WARMELTmiNORMAL_LAMBDA_cl7 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_47_WARMELTmiNORMAL_NORMEXP_FUNMATCHEXPR (meltclosure_ptr_t
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
meltrout_48_WARMELTmiNORMAL_NORMEXP_APPLY (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_49_WARMELTmiNORMAL_NORMEXP_MSEND (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_50_WARMELTmiNORMAL_NORMEXP_RETURN (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_51_WARMELTmiNORMAL_NORMEXP_IF (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_52_WARMELTmiNORMAL_LAMBDA_cl8 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_53_WARMELTmiNORMAL_NORMEXP_IFELSE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_54_WARMELTmiNORMAL_LAMBDA_cl9 (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_55_WARMELTmiNORMAL_LAMBDA_cl10 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_56_WARMELTmiNORMAL_NORMEXP_CPPIF (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_57_WARMELTmiNORMAL_LAMBDA_cl11 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_58_WARMELTmiNORMAL_LAMBDA_cl12 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_59_WARMELTmiNORMAL_NORMEXP_OR (meltclosure_ptr_t meltclosp_,
					melt_ptr_t meltfirstargp_,
					const melt_argdescr_cell_t
					meltxargdescr_[],
					union meltparam_un *meltxargtab_,
					const melt_argdescr_cell_t
					meltxresdescr_[],
					union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_60_WARMELTmiNORMAL_LAMBDA_cl13 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_61_WARMELTmiNORMAL_LAMBDA_cl14 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_62_WARMELTmiNORMAL_NORMEXP_PROGN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_63_WARMELTmiNORMAL_LAMBDA_cl15 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_64_WARMELTmiNORMAL_NORMEXP_LET (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_65_WARMELTmiNORMAL_LAMBDA_cl16 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_66_WARMELTmiNORMAL_LAMBDA_cl17 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_67_WARMELTmiNORMAL_NORMEXP_UNSAFE_GET_FIELD (meltclosure_ptr_t
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
meltrout_68_WARMELTmiNORMAL_NORMEXP_GET_FIELD (meltclosure_ptr_t meltclosp_,
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
meltrout_69_WARMELTmiNORMAL_NORMEXP_UNSAFE_PUT_FIELDS (meltclosure_ptr_t
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
meltrout_70_WARMELTmiNORMAL_LAMBDA_cl18 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_71_WARMELTmiNORMAL_LAMBDA_cl19 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_72_WARMELTmiNORMAL_NORMEXP_PUT_FIELDS (meltclosure_ptr_t meltclosp_,
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
meltrout_73_WARMELTmiNORMAL_NORMEXP_SETQ (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_74_WARMELTmiNORMAL_LAMBDA_cl20 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_75_WARMELTmiNORMAL_NORMEXP_INSTANCE (meltclosure_ptr_t meltclosp_,
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
meltrout_76_WARMELTmiNORMAL_LAMBDA_cl21 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_77_WARMELTmiNORMAL_LAMBDA_cl22 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_78_WARMELTmiNORMAL_NORMEXP_FOREVER (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_79_WARMELTmiNORMAL_NORMEXP_EXIT (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_80_WARMELTmiNORMAL_NORMEXP_AGAIN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_81_WARMELTmiNORMAL_NORMEXP_IFVARIADIC (meltclosure_ptr_t meltclosp_,
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
meltrout_82_WARMELTmiNORMAL_NORMEXP_COMPILEWARNING (meltclosure_ptr_t
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
meltrout_83_WARMELTmiNORMAL_LAMBDA_cl23 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_84_WARMELTmiNORMAL_REPLACE_LAST_BY_RETURN (meltclosure_ptr_t
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
meltrout_85_WARMELTmiNORMAL_LAMBDA_cl24 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_86_WARMELTmiNORMAL_NORMEXP_DEFUN (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_87_WARMELTmiNORMAL_LAMBDA_cl25 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_88_WARMELTmiNORMAL_LAMBDA_cl26 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_89_WARMELTmiNORMAL_NORMEXP_DEFHOOK (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_90_WARMELTmiNORMAL_NORMALIZE_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_91_WARMELTmiNORMAL_LAMBDA_cl27 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_92_WARMELTmiNORMAL_NORMEXP_LAMBDA (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_93_WARMELTmiNORMAL_NORMEXP_MULTICALL (meltclosure_ptr_t meltclosp_,
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
meltrout_94_WARMELTmiNORMAL_LAMBDA_cl28 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_95_WARMELTmiNORMAL_LAMBDA_cl29 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_96_WARMELTmiNORMAL_LAMBDA_cl30 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_97_WARMELTmiNORMAL_NORMEXP_TUPLE (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE (meltclosure_ptr_t meltclosp_,
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
meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM (meltclosure_ptr_t
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
meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST (meltclosure_ptr_t meltclosp_,
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
meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE (meltclosure_ptr_t meltclosp_,
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
meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE (meltclosure_ptr_t
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
meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA (meltclosure_ptr_t meltclosp_,
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
meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA (meltclosure_ptr_t
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
meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS (meltclosure_ptr_t meltclosp_,
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
meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_120_WARMELTmiNORMAL_NORMEXP_COMMENT (meltclosure_ptr_t meltclosp_,
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
meltrout_121_WARMELTmiNORMAL_NORMEXP_KEYWORD (meltclosure_ptr_t meltclosp_,
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
meltrout_122_WARMELTmiNORMAL_FILL_NORMAL_FORMALBIND (meltclosure_ptr_t
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
meltrout_123_WARMELTmiNORMAL_FILL_NORMAL_FORMALS (meltclosure_ptr_t
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
meltrout_124_WARMELTmiNORMAL_FILL_NORMAL_EXPANSION (meltclosure_ptr_t
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
meltrout_125_WARMELTmiNORMAL_LAMBDA_cl33 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_126_WARMELTmiNORMAL_NORMEXP_DEFPRIMITIVE (meltclosure_ptr_t
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
meltrout_127_WARMELTmiNORMAL_NORMEXP_DEFCITERATOR (meltclosure_ptr_t
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
meltrout_128_WARMELTmiNORMAL_NORMEXP_CITERATION (meltclosure_ptr_t meltclosp_,
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
meltrout_129_WARMELTmiNORMAL_LAMBDA_cl34 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_130_WARMELTmiNORMAL_LAMBDA_cl35 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_131_WARMELTmiNORMAL_LAMBDA_cl36 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_132_WARMELTmiNORMAL_LAMBDA_cl37 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_133_WARMELTmiNORMAL_LAMBDA_cl38 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_134_WARMELTmiNORMAL_LAMBDA_cl39 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_135_WARMELTmiNORMAL_LAMBDA_cl40 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_136_WARMELTmiNORMAL_NORMEXP_DEFCMATCHER (meltclosure_ptr_t
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
meltrout_137_WARMELTmiNORMAL_NORMEXP_DEFUNMATCHER (meltclosure_ptr_t
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
meltrout_138_WARMELTmiNORMAL_NORMEXP_DEFCLASS (meltclosure_ptr_t meltclosp_,
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
meltrout_139_WARMELTmiNORMAL_NORMEXP_DEFINSTANCE (meltclosure_ptr_t
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
meltrout_140_WARMELTmiNORMAL_LAMBDA_cl41 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_141_WARMELTmiNORMAL_NORMEXP_DEFVAR (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_142_WARMELTmiNORMAL_NORMEXP_DEFINE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_143_WARMELTmiNORMAL_LAMBDA_cl42 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_144_WARMELTmiNORMAL_NORMEXP_DEFSELECTOR (meltclosure_ptr_t
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
meltrout_145_WARMELTmiNORMAL_LAMBDA_cl43 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_146_WARMELTmiNORMAL_NORMAL_EXPORTED_VALUE (meltclosure_ptr_t
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
meltrout_147_WARMELTmiNORMAL_NORMEXP_EXPORT_VALUES (meltclosure_ptr_t
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
meltrout_148_WARMELTmiNORMAL_NORMEXP_EXPORT_SYNONYM (meltclosure_ptr_t
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
meltrout_149_WARMELTmiNORMAL_NORMEXP_EXPORT_CLASS (meltclosure_ptr_t
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
meltrout_150_WARMELTmiNORMAL_LAMBDA_cl44 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_151_WARMELTmiNORMAL_LAMBDA_cl45 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_152_WARMELTmiNORMAL_NORMAL_EXPORTED_MACRO (meltclosure_ptr_t
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
meltrout_153_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO (meltclosure_ptr_t
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
meltrout_154_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO (meltclosure_ptr_t
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
meltrout_155_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO (meltclosure_ptr_t
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
meltrout_156_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_157_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_158_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_159_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED (meltclosure_ptr_t
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
meltrout_160_WARMELTmiNORMAL_LAMBDA_cl46 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_161_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED (meltclosure_ptr_t
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
meltrout_162_WARMELTmiNORMAL_LAMBDA_cl47 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_163_WARMELTmiNORMAL_NORMEXP_CHEADER (meltclosure_ptr_t meltclosp_,
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
meltrout_164_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT (meltclosure_ptr_t meltclosp_,
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
meltrout_165_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);



MELT_EXTERN void *melt_start_this_module (void *);
struct melt_initial_frame_st;

/*declare opaque initial frame: */
typedef struct melt_initial_frame_st meltinitial_frame_t;


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG
MELT_EXTERN const char meltmodule_WARMELTmiNORMAL__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiNORMAL__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG */
MELT_EXTERN const char meltmodule_WARMELTmiNORMAL__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiNORMAL__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG */



void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_0 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_1 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_2 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_3 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_4 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_5 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_6 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_7 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_8 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_9 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_10 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_11 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_12 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_13 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_14 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_15 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_16 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_17 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_18 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_19 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_20 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_21 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_22 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_23 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_24 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_25 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_26 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_27 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_28 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_29 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_30 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_31 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_32 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_33 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_34 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_35 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_36 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_37 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_38 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_39 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_40 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_41 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_42 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_43 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_44 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_45 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_46 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_47 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_48 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_49 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_50 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_51 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_52 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_53 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_54 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_55 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__initialmeltchunk_56 (meltinitial_frame_t *, char *);
void MELT_MODULE_VISIBILITY
meltmod__WARMELTmiNORMAL__forward_or_mark_module_start_frame (struct
							      melt_callframe_st
							      *fp,
							      int marking);



/**** warmelt-normal+04.c implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST_melt =
    melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST_st
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
#define MELTFRAM_NBVARPTR 94
    melt_ptr_t mcfr_varptr[94];
#define MELTFRAM_NBVARNUM 36
    long mcfr_varnum[36];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 94; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST nbval 94*/
  meltfram__.mcfr_nbvar = 94 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5543:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5544:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:5544:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5544:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check list recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5544) ? (5544) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5544:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5545:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5545:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5545:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5545) ? (5545) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5545:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5546:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5546:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5546:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5546) ? (5546) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5546:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5547:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5547:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5547:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5547;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5547:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5547:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5548:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V15*/ meltfptr[10] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V15*/ meltfptr[10])	/*then */
      {
	/*^cond.then */
	/*_.SLOC__V16*/ meltfptr[15] = /*_.LOCA_LOCATION__V15*/ meltfptr[10];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5548:/ cond.else");

	/*_.SLOC__V16*/ meltfptr[15] = /*_.PSLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5549:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V17*/ meltfptr[16] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5550:/ apply");
    /*apply */
    {
      /*_.CSYMREC__V18*/ meltfptr[17] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[4])),
		    (melt_ptr_t) (( /*!konst_5_LISTREC_ */ meltfrout->
				   tabval[5])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5551:/ apply");
    /*apply */
    {
      /*_.CSYMLIST__V19*/ meltfptr[18] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[4])),
		    (melt_ptr_t) (( /*!konst_6_LIST_ */ meltfrout->
				   tabval[6])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5552:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V16*/ meltfptr[15];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_pair";
      /*_.NORMDISCRPAIR__V20*/ meltfptr[19] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->tabval[8])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5553:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V16*/ meltfptr[15];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_list";
      /*_.NORMDISCRLIST__V21*/ meltfptr[20] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->tabval[8])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5554:/ apply");
    /*apply */
    {
      /*_.NEWENV__V22*/ meltfptr[21] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!FRESH_ENV */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;
 /*_#NBARGS__L6*/ meltfnum[4] =
      (melt_multiple_length ((melt_ptr_t) ( /*_.SARGS__V17*/ meltfptr[16])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5556:/ msend");
    /*msend */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^ojbmsend.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.CSYMLIST__V19*/ meltfptr[18];
      /*^ojbmsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^ojbmsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V16*/ meltfptr[15];
      /*_.PREPARE_CONSTRUCTOR_BINDING__V23*/ meltfptr[22] =
	meltgc_send ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
		     (melt_ptr_t) (( /*!PREPARE_CONSTRUCTOR_BINDING */
				    meltfrout->tabval[11])),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      /*_.CONSBINDTUP__V24*/ meltfptr[23] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_TO_MULTIPLE */ meltfrout->tabval[10])),
		    (melt_ptr_t) ( /*_.PREPARE_CONSTRUCTOR_BINDING__V23*/
				  meltfptr[22]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;
 /*_.RESBINDINGS__V25*/ meltfptr[24] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[12]))));;
    /*^compute */
 /*_.CONSLISTBIND__V26*/ meltfptr[25] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]), (-1)));;
    MELT_LOCATION ("warmelt-normal.melt:5561:/ quasiblock");


    /*^newclosure */
		 /*newclosure *//*_.LAMBDA___V28*/ meltfptr[27] =
      (melt_ptr_t)
      meltgc_new_closure ((meltobject_ptr_t)
			  (((melt_ptr_t) (MELT_PREDEF (DISCR_CLOSURE)))),
			  (meltroutine_ptr_t) (( /*!konst_19 */ meltfrout->
						tabval[19])), (1));
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V28*/ meltfptr[27])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 0 >= 0
		    && 0 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V28*/ meltfptr[27])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V28*/ meltfptr[27])->tabval[0] =
      (melt_ptr_t) ( /*_.SLOC__V16*/ meltfptr[15]);
    ;
    /*_.LAMBDA___V27*/ meltfptr[26] = /*_.LAMBDA___V28*/ meltfptr[27];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5559:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.LAMBDA___V27*/ meltfptr[26];
      /*_.TUPRECLOC__V29*/ meltfptr[28] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!MULTIPLE_MAP */ meltfrout->tabval[13])),
		    (melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5572:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L7*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5572:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L7*/ meltfnum[0])	/*then */
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
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5572:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5572;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list csymrec=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CSYMREC__V18*/ meltfptr[17];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " consbindtup=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSBINDTUP__V24*/ meltfptr[23];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " conslistbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLISTBIND__V26*/ meltfptr[25];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " tuprecloc=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPRECLOC__V29*/ meltfptr[28];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V30*/ meltfptr[29] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5572:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V30*/ meltfptr[29] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5572:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[29] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5575:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L9*/ meltfnum[7] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[20])));;
      MELT_LOCATION ("warmelt-normal.melt:5575:/ cond");
      /*cond */ if ( /*_#IS_A__L9*/ meltfnum[7])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V33*/ meltfptr[29] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5575:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check conslistbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5575) ? (5575) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V33*/ meltfptr[29] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V32*/ meltfptr[30] = /*_._IFELSE___V33*/ meltfptr[29];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5575:/ clear");
	     /*clear *//*_#IS_A__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V33*/ meltfptr[29] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V32*/ meltfptr[30] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5576:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V16*/ meltfptr[15];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V36*/ meltfptr[35];
      /*^multiapply.appl */
      /*_.NARGS__V35*/ meltfptr[34] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[21])),
		    (melt_ptr_t) ( /*_.SARGS__V17*/ meltfptr[16]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5579:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L10*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5579:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[7] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5579:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5579;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V35*/ meltfptr[34];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDINGS__V36*/ meltfptr[35];
	      /*_.MELT_DEBUG_FUN__V38*/ meltfptr[37] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V37*/ meltfptr[36] =
	      /*_.MELT_DEBUG_FUN__V38*/ meltfptr[37];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5579:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V38*/ meltfptr[37] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V37*/ meltfptr[36] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5579:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V37*/ meltfptr[36] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5580:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L12*/ meltfnum[7] =
	(( /*_.NBINDINGS__V36*/ meltfptr[35]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDINGS__V36*/ meltfptr[35])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5580:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L12*/ meltfnum[7])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V40*/ meltfptr[36] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5580:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5580) ? (5580) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V40*/ meltfptr[36] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V39*/ meltfptr[37] = /*_._IFELSE___V40*/ meltfptr[36];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5580:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L12*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V40*/ meltfptr[36] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V39*/ meltfptr[37] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5581:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V36*/ meltfptr[35];
      /*_.LIST_APPEND2LIST__V41*/ meltfptr[36] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[22])),
		    (melt_ptr_t) ( /*_.RESBINDINGS__V25*/ meltfptr[24]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;
    /*citerblock FOREACH_IN_LIST */
    {
      /* start foreach_in_list meltcit1__EACHLIST */
      for ( /*_.CURPAIRBIND__V42*/ meltfptr[41] =
	   melt_list_first ((melt_ptr_t) /*_.RESBINDINGS__V25*/ meltfptr[24]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIRBIND__V42*/ meltfptr[41])
	   == MELTOBMAG_PAIR;
	   /*_.CURPAIRBIND__V42*/ meltfptr[41] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIRBIND__V42*/ meltfptr[41]))
	{
	  /*_.CURBIND__V43*/ meltfptr[42] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIRBIND__V42*/ meltfptr[41]);



	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5585:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURBIND__V43*/ meltfptr[42];
	    /*_.PUT_ENV__V44*/ meltfptr[43] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!PUT_ENV */ meltfrout->tabval[23])),
			  (melt_ptr_t) ( /*_.NEWENV__V22*/ meltfptr[21]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	}			/* end foreach_in_list meltcit1__EACHLIST */
     /*_.CURPAIRBIND__V42*/ meltfptr[41] = NULL;
     /*_.CURBIND__V43*/ meltfptr[42] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5582:/ clear");
	    /*clear *//*_.CURPAIRBIND__V42*/ meltfptr[41] = 0;
      /*^clear */
	    /*clear *//*_.CURBIND__V43*/ meltfptr[42] = 0;
      /*^clear */
	    /*clear *//*_.PUT_ENV__V44*/ meltfptr[43] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit2__EACHTUP */
      long meltcit2__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V35*/ meltfptr[34]);
      for ( /*_#NIX__L13*/ meltfnum[0] = 0;
	   ( /*_#NIX__L13*/ meltfnum[0] >= 0)
	   && ( /*_#NIX__L13*/ meltfnum[0] < meltcit2__EACHTUP_ln);
	/*_#NIX__L13*/ meltfnum[0]++)
	{
	  /*_.CURNARG__V45*/ meltfptr[44] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V35*/ meltfptr[34]),
			       /*_#NIX__L13*/ meltfnum[0]);




	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5590:/ msend");
	  /*msend */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NEWENV__V22*/ meltfptr[21];
	    /*_.GET_CTYPE__V46*/ meltfptr[45] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURNARG__V45*/ meltfptr[44]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[24])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;
  /*_#exeq__L14*/ meltfnum[7] =
	    (( /*_.GET_CTYPE__V46*/ meltfptr[45]) !=
	     (( /*!CTYPE_VALUE */ meltfrout->tabval[25])));;
	  MELT_LOCATION ("warmelt-normal.melt:5590:/ cond");
	  /*cond */ if ( /*_#exeq__L14*/ meltfnum[7])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:5592:/ cppif.then");
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
      /*_#MELT_NEED_DBG__L15*/ meltfnum[14] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:5592:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L15*/ meltfnum[14])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	/*_#MELT_CALLCOUNT__L16*/ meltfnum[15] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:5592:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L16*/ meltfnum[15];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 5592;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_list bad curnarg";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURNARG__V45*/ meltfptr[44];
			  /*_.MELT_DEBUG_FUN__V49*/ meltfptr[48] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[3])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V48*/ meltfptr[47] =
			  /*_.MELT_DEBUG_FUN__V49*/ meltfptr[48];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5592:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[15] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V49*/ meltfptr[48] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V48*/ meltfptr[47] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:5592:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		/*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[14] = 0;
		  /*^clear */
		/*clear *//*_._IF___V48*/ meltfptr[47] = 0;
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

		{
		  MELT_LOCATION ("warmelt-normal.melt:5593:/ locexp");
		  /* error_plain */
		    melt_error_str ((melt_ptr_t)
				    ( /*_.SLOC__V16*/ meltfptr[15]),
				    ("(LIST ...) arguments should be values"),
				    (melt_ptr_t) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:5594:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5594:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5591:/ quasiblock");


		/*_.PROGN___V51*/ meltfptr[47] =
		  /*_.RETURN___V50*/ meltfptr[48];;
		/*^compute */
		/*_._IF___V47*/ meltfptr[46] =
		  /*_.PROGN___V51*/ meltfptr[47];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5590:/ clear");
	      /*clear *//*_.RETURN___V50*/ meltfptr[48] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V51*/ meltfptr[47] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V47*/ meltfptr[46] = NULL;;
	    }
	  ;
	  if ( /*_#NIX__L13*/ meltfnum[0] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit2__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5587:/ clear");
	    /*clear *//*_.CURNARG__V45*/ meltfptr[44] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L13*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_.GET_CTYPE__V46*/ meltfptr[45] = 0;
      /*^clear */
	    /*clear *//*_#exeq__L14*/ meltfnum[7] = 0;
      /*^clear */
	    /*clear *//*_._IF___V47*/ meltfptr[46] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5595:/ blockmultialloc");
    /*multiallocblock */
    {
      struct meltletrec_1_st
      {
	struct MELT_OBJECT_STRUCT (4) rinst_0__CRECLOCC;
	struct MELT_MULTIPLE_STRUCT (1) rtup_1__NBDY;
	struct MELT_OBJECT_STRUCT (6) rinst_2__NLETREC;
	struct MELT_OBJECT_STRUCT (4) rinst_3__CLISTBIND;
	struct MELT_OBJECT_STRUCT (4) rinst_4__CLISTLOCC;
	struct meltpair_st rpair_5__CLISTBIND_x1;
	struct meltlist_st rlist_6__CLISTBINDLIST;
	long meltletrec_1_endgap;
      } *meltletrec_1_ptr = 0;
      meltletrec_1_ptr =
	(struct meltletrec_1_st *)
	meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
      /*^blockmultialloc.initfill */

      /*iniobj rinst_0__CRECLOCC */
  /*_.CRECLOCC__V53*/ meltfptr[47] =
	(melt_ptr_t) & meltletrec_1_ptr->rinst_0__CRECLOCC;
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr isobj rinst_0__CRECLOCC",
			melt_magic_discr ((melt_ptr_t)
					  (( /*!CLASS_NREP_LOCSYMOCC */
					    meltfrout->tabval[26]))) ==
			MELTOBMAG_OBJECT);
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr objmagic rinst_0__CRECLOCC",
			((meltobject_ptr_t)
			 (( /*!CLASS_NREP_LOCSYMOCC */ meltfrout->
			   tabval[26])))->meltobj_magic == MELTOBMAG_OBJECT);
      meltletrec_1_ptr->rinst_0__CRECLOCC.meltobj_class =
	(meltobject_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */ meltfrout->
			     tabval[26]));
      meltletrec_1_ptr->rinst_0__CRECLOCC.obj_hash = melt_nonzerohash ();
      meltletrec_1_ptr->rinst_0__CRECLOCC.obj_len = 4;

      /*inimult rtup_1__NBDY */
 /*_.NBDY__V54*/ meltfptr[53] =
	(melt_ptr_t) & meltletrec_1_ptr->rtup_1__NBDY;
      meltletrec_1_ptr->rtup_1__NBDY.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
      meltletrec_1_ptr->rtup_1__NBDY.nbval = 1;

      /*iniobj rinst_2__NLETREC */
  /*_.NLETREC__V55*/ meltfptr[54] =
	(melt_ptr_t) & meltletrec_1_ptr->rinst_2__NLETREC;
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr isobj rinst_2__NLETREC",
			melt_magic_discr ((melt_ptr_t)
					  (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[27]))) ==
			MELTOBMAG_OBJECT);
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr objmagic rinst_2__NLETREC",
			((meltobject_ptr_t)
			 (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[27])))->
			meltobj_magic == MELTOBMAG_OBJECT);
      meltletrec_1_ptr->rinst_2__NLETREC.meltobj_class =
	(meltobject_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[27]));
      meltletrec_1_ptr->rinst_2__NLETREC.obj_hash = melt_nonzerohash ();
      meltletrec_1_ptr->rinst_2__NLETREC.obj_len = 6;


      /*iniobj rinst_3__CLISTBIND */
  /*_.CLISTBIND__V56*/ meltfptr[55] =
	(melt_ptr_t) & meltletrec_1_ptr->rinst_3__CLISTBIND;
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr isobj rinst_3__CLISTBIND",
			melt_magic_discr ((melt_ptr_t)
					  (( /*!CLASS_NORMAL_LET_BINDING */
					    meltfrout->tabval[28]))) ==
			MELTOBMAG_OBJECT);
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr objmagic rinst_3__CLISTBIND",
			((meltobject_ptr_t)
			 (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->
			   tabval[28])))->meltobj_magic == MELTOBMAG_OBJECT);
      meltletrec_1_ptr->rinst_3__CLISTBIND.meltobj_class =
	(meltobject_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->
			     tabval[28]));
      meltletrec_1_ptr->rinst_3__CLISTBIND.obj_hash = melt_nonzerohash ();
      meltletrec_1_ptr->rinst_3__CLISTBIND.obj_len = 4;


      /*iniobj rinst_4__CLISTLOCC */
  /*_.CLISTLOCC__V57*/ meltfptr[56] =
	(melt_ptr_t) & meltletrec_1_ptr->rinst_4__CLISTLOCC;
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr isobj rinst_4__CLISTLOCC",
			melt_magic_discr ((melt_ptr_t)
					  (( /*!CLASS_NREP_LOCSYMOCC */
					    meltfrout->tabval[26]))) ==
			MELTOBMAG_OBJECT);
      if (MELT_LIKELY (!melt_prohibit_garbcoll))
	melt_assertmsg ("iniobj check.discr objmagic rinst_4__CLISTLOCC",
			((meltobject_ptr_t)
			 (( /*!CLASS_NREP_LOCSYMOCC */ meltfrout->
			   tabval[26])))->meltobj_magic == MELTOBMAG_OBJECT);
      meltletrec_1_ptr->rinst_4__CLISTLOCC.meltobj_class =
	(meltobject_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */ meltfrout->
			     tabval[26]));
      meltletrec_1_ptr->rinst_4__CLISTLOCC.obj_hash = melt_nonzerohash ();
      meltletrec_1_ptr->rinst_4__CLISTLOCC.obj_len = 4;

      /*inipair rpair_5__CLISTBIND_x1 */
   /*_.CLISTBIND__V58*/ meltfptr[57] =
	(melt_ptr_t) & meltletrec_1_ptr->rpair_5__CLISTBIND_x1;
      meltletrec_1_ptr->rpair_5__CLISTBIND_x1.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_PAIR))));

      /*inilist rlist_6__CLISTBINDLIST */
   /*_.CLISTBINDLIST__V59*/ meltfptr[58] =
	(melt_ptr_t) & meltletrec_1_ptr->rlist_6__CLISTBINDLIST;
      meltletrec_1_ptr->rlist_6__CLISTBINDLIST.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_LIST))));



      MELT_LOCATION ("warmelt-normal.melt:5596:/ putslot");
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V53*/ meltfptr[47]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V53*/ meltfptr[47]), (0),
			    ( /*_.SLOC__V16*/ meltfptr[15]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V53*/ meltfptr[47]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V53*/ meltfptr[47]), (1),
			    ( /*_.CSYMREC__V18*/ meltfptr[17]), "NOCC_SYMB");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V53*/ meltfptr[47]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V53*/ meltfptr[47]), (2),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "NOCC_CTYP");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V53*/ meltfptr[47]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V53*/ meltfptr[47]), (3),
			    ( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
			    "NOCC_BIND");
      ;
      /*^touch */
      meltgc_touch ( /*_.CRECLOCC__V53*/ meltfptr[47]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5601:/ putuple");
      /*putupl#40 */
      melt_assertmsg ("putupl [:5601] #40 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NBDY__V54*/ meltfptr[53])) ==
		      MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:5601] #40 checkoff",
		      (0 >= 0
		       && 0 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.NBDY__V54*/
					      meltfptr[53]))));
      ((meltmultiple_ptr_t) ( /*_.NBDY__V54*/ meltfptr[53]))->tabval[0] =
	(melt_ptr_t) ( /*_.CRECLOCC__V53*/ meltfptr[47]);
      ;
      /*^touch */
      meltgc_touch ( /*_.NBDY__V54*/ meltfptr[53]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5602:/ putslot");
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (0),
			    ( /*_.SLOC__V16*/ meltfptr[15]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NLET_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (1),
			    ( /*_.CONSBINDTUP__V24*/ meltfptr[23]),
			    "NLET_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NLET_BODY",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (2),
			    ( /*_.NBDY__V54*/ meltfptr[53]), "NLET_BODY");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NLETREC_FILL_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (3),
			    (( /*nil */ NULL)), "NLETREC_FILL_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NLETREC_BODY_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (4),
			    (( /*nil */ NULL)), "NLETREC_BODY_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NLETREC_LOCSYMS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V55*/ meltfptr[54])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V55*/ meltfptr[54]), (5),
			    ( /*_.TUPRECLOC__V29*/ meltfptr[28]),
			    "NLETREC_LOCSYMS");
      ;
      /*^touch */
      meltgc_touch ( /*_.NLETREC__V55*/ meltfptr[54]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5610:/ putslot");
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @BINDER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V56*/ meltfptr[55]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V56*/ meltfptr[55]), (0),
			    ( /*_.CSYMLIST__V19*/ meltfptr[18]), "BINDER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V56*/ meltfptr[55]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V56*/ meltfptr[55]), (1),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "LETBIND_TYPE");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V56*/ meltfptr[55]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V56*/ meltfptr[55]), (2),
			    ( /*_.NLETREC__V55*/ meltfptr[54]),
			    "LETBIND_EXPR");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LETBIND_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V56*/ meltfptr[55]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V56*/ meltfptr[55]), (3),
			    ( /*_.SLOC__V16*/ meltfptr[15]), "LETBIND_LOC");
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBIND__V56*/ meltfptr[55]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5615:/ putslot");
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V57*/ meltfptr[56]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V57*/ meltfptr[56]), (0),
			    ( /*_.SLOC__V16*/ meltfptr[15]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V57*/ meltfptr[56]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V57*/ meltfptr[56]), (1),
			    ( /*_.CSYMLIST__V19*/ meltfptr[18]), "NOCC_SYMB");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V57*/ meltfptr[56]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V57*/ meltfptr[56]), (2),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "NOCC_CTYP");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V57*/ meltfptr[56]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V57*/ meltfptr[56]), (3),
			    ( /*_.CLISTBIND__V56*/ meltfptr[55]),
			    "NOCC_BIND");
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTLOCC__V57*/ meltfptr[56]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5620:/ putpairhead");
      /*putpairhead */
      melt_assertmsg ("putpairhead /d checkpair",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V58*/ meltfptr[57]))
		      == MELTOBMAG_PAIR);
      ((meltpair_ptr_t) ( /*_.CLISTBIND__V58*/ meltfptr[57]))->hd =
	(melt_ptr_t) ( /*_.CLISTBIND__V56*/ meltfptr[55]);
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBIND__V58*/ meltfptr[57]);
      ;
      /*^putlist */
      /*putlist */
      melt_assertmsg ("putlist checklist",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBINDLIST__V59*/
					 meltfptr[58])) == MELTOBMAG_LIST);
      ((meltlist_ptr_t) ( /*_.CLISTBINDLIST__V59*/ meltfptr[58]))->first =
	(meltpair_ptr_t) ( /*_.CLISTBIND__V58*/ meltfptr[57]);
      ((meltlist_ptr_t) ( /*_.CLISTBINDLIST__V59*/ meltfptr[58]))->last =
	(meltpair_ptr_t) ( /*_.CLISTBIND__V58*/ meltfptr[57]);
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBINDLIST__V59*/ meltfptr[58]);
      ;
      /*citerblock FOREACH_IN_MULTIPLE */
      {
	/* start foreach_in_multiple meltcit3__EACHTUP */
	long meltcit3__EACHTUP_ln =
	  melt_multiple_length ((melt_ptr_t) /*_.NARGS__V35*/ meltfptr[34]);
	for ( /*_#NIX__L17*/ meltfnum[15] = 0;
	     ( /*_#NIX__L17*/ meltfnum[15] >= 0)
	     && ( /*_#NIX__L17*/ meltfnum[15] < meltcit3__EACHTUP_ln);
	/*_#NIX__L17*/ meltfnum[15]++)
	  {
	    /*_.CURNARG__V60*/ meltfptr[59] =
	      melt_multiple_nth ((melt_ptr_t)
				 ( /*_.NARGS__V35*/ meltfptr[34]),
				 /*_#NIX__L17*/ meltfnum[15]);



	    MELT_LOCATION ("warmelt-normal.melt:5625:/ quasiblock");


   /*_.CURPAIRB__V61*/ meltfptr[60] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]),
		( /*_#NIX__L17*/ meltfnum[15])));;
	    /*^compute */
   /*_#plI__L18*/ meltfnum[14] =
	      (( /*_#NIX__L17*/ meltfnum[15]) + (1));;
	    /*^compute */
   /*_.NEXTB__V62*/ meltfptr[61] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]),
		( /*_#plI__L18*/ meltfnum[14])));;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:5628:/ locexp");
	      melt_put_int ((melt_ptr_t) ( /*_.CURPAIRB__V61*/ meltfptr[60]),
			    ( /*_#NIX__L17*/ meltfnum[15]));
	    }
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5629:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L19*/ meltfnum[18] =
		/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		;;
	      MELT_LOCATION ("warmelt-normal.melt:5629:/ cond");
	      /*cond */ if ( /*_#MELT_NEED_DBG__L19*/ meltfnum[18])	/*then */
		{
		  /*^cond.then */
		  /*^block */
		  /*anyblock */
		  {

       /*_#MELT_CALLCOUNT__L20*/ meltfnum[19] =
		      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		      meltcallcount	/* melt_callcount debugging */
#else
		      0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		      ;;

		    MELT_CHECK_SIGNAL ();
		    ;
		    MELT_LOCATION ("warmelt-normal.melt:5629:/ apply");
		    /*apply */
		    {
		      union meltparam_un argtab[5];
		      memset (&argtab, 0, sizeof (argtab));
		      /*^apply.arg */
		      argtab[0].meltbp_long =
			/*_#MELT_CALLCOUNT__L20*/ meltfnum[19];
		      /*^apply.arg */
		      argtab[1].meltbp_cstring = "warmelt-normal.melt";
		      /*^apply.arg */
		      argtab[2].meltbp_long = 5629;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring = "normexp_list curpairb";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURPAIRB__V61*/ meltfptr[60];
		      /*_.MELT_DEBUG_FUN__V64*/ meltfptr[63] =
			melt_apply ((meltclosure_ptr_t)
				    (( /*!MELT_DEBUG_FUN */ meltfrout->
				      tabval[3])),
				    (melt_ptr_t) (( /*nil */ NULL)),
				    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR ""), argtab, "",
				    (union meltparam_un *) 0);
		    }
		    ;
		    /*_._IF___V63*/ meltfptr[62] =
		      /*_.MELT_DEBUG_FUN__V64*/ meltfptr[63];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5629:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[19] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V64*/ meltfptr[63] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V63*/ meltfptr[62] = NULL;;
		}
	      ;

	      {
		MELT_LOCATION ("warmelt-normal.melt:5629:/ locexp");
		/*void */ (void) 0;
	      }
	      ;
	      /*^quasiblock */


	      /*epilog */

	      /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V63*/ meltfptr[62] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:5630:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L21*/ meltfnum[19] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.CURPAIRB__V61*/ meltfptr[60]),
				     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
	      MELT_LOCATION ("warmelt-normal.melt:5630:/ cond");
	      /*cond */ if ( /*_#IS_A__L21*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V66*/ meltfptr[62] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5630:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curpairb"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5630) ? (5630) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V66*/ meltfptr[62] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V65*/ meltfptr[63] =
		/*_._IFELSE___V66*/ meltfptr[62];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5630:/ clear");
	       /*clear *//*_#IS_A__L21*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V66*/ meltfptr[62] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V65*/ meltfptr[63] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5631:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#GET_INT__L22*/ meltfnum[18] =
		(melt_get_int
		 ((melt_ptr_t) ( /*_.CURPAIRB__V61*/ meltfptr[60])));;
	      /*^compute */
     /*_#eqeqI__L23*/ meltfnum[19] =
		(( /*_#GET_INT__L22*/ meltfnum[18]) ==
		 ( /*_#NIX__L17*/ meltfnum[15]));;
	      MELT_LOCATION ("warmelt-normal.melt:5631:/ cond");
	      /*cond */ if ( /*_#eqeqI__L23*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V68*/ meltfptr[67] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5631:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curpairb objnum"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5631) ? (5631) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V68*/ meltfptr[67] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V67*/ meltfptr[62] =
		/*_._IFELSE___V68*/ meltfptr[67];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5631:/ clear");
	       /*clear *//*_#GET_INT__L22*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_#eqeqI__L23*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V68*/ meltfptr[67] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V67*/ meltfptr[62] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5632:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L24*/ meltfnum[18] =
		/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		;;
	      MELT_LOCATION ("warmelt-normal.melt:5632:/ cond");
	      /*cond */ if ( /*_#MELT_NEED_DBG__L24*/ meltfnum[18])	/*then */
		{
		  /*^cond.then */
		  /*^block */
		  /*anyblock */
		  {

       /*_#MELT_CALLCOUNT__L25*/ meltfnum[19] =
		      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		      meltcallcount	/* melt_callcount debugging */
#else
		      0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		      ;;

		    MELT_CHECK_SIGNAL ();
		    ;
		    MELT_LOCATION ("warmelt-normal.melt:5632:/ apply");
		    /*apply */
		    {
		      union meltparam_un argtab[7];
		      memset (&argtab, 0, sizeof (argtab));
		      /*^apply.arg */
		      argtab[0].meltbp_long =
			/*_#MELT_CALLCOUNT__L25*/ meltfnum[19];
		      /*^apply.arg */
		      argtab[1].meltbp_cstring = "warmelt-normal.melt";
		      /*^apply.arg */
		      argtab[2].meltbp_long = 5632;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring = "normexp_list curnarg=";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURNARG__V60*/ meltfptr[59];
		      /*^apply.arg */
		      argtab[5].meltbp_cstring = " nextb=";
		      /*^apply.arg */
		      argtab[6].meltbp_aptr =
			(melt_ptr_t *) & /*_.NEXTB__V62*/ meltfptr[61];
		      /*_.MELT_DEBUG_FUN__V70*/ meltfptr[69] =
			melt_apply ((meltclosure_ptr_t)
				    (( /*!MELT_DEBUG_FUN */ meltfrout->
				      tabval[3])),
				    (melt_ptr_t) (( /*nil */ NULL)),
				    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR ""), argtab, "",
				    (union meltparam_un *) 0);
		    }
		    ;
		    /*_._IF___V69*/ meltfptr[67] =
		      /*_.MELT_DEBUG_FUN__V70*/ meltfptr[69];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5632:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L25*/ meltfnum[19] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V70*/ meltfptr[69] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V69*/ meltfptr[67] = NULL;;
		}
	      ;

	      {
		MELT_LOCATION ("warmelt-normal.melt:5632:/ locexp");
		/*void */ (void) 0;
	      }
	      ;
	      /*^quasiblock */


	      /*epilog */

	      /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L24*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V69*/ meltfptr[67] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:5633:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L26*/ meltfnum[19] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.NEXTB__V62*/ meltfptr[61]),
				     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[30])));;
	      MELT_LOCATION ("warmelt-normal.melt:5633:/ cond");
	      /*cond */ if ( /*_#IS_A__L26*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V72*/ meltfptr[67] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5633:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check nextb"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5633) ? (5633) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V72*/ meltfptr[67] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V71*/ meltfptr[69] =
		/*_._IFELSE___V72*/ meltfptr[67];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5633:/ clear");
	       /*clear *//*_#IS_A__L26*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V72*/ meltfptr[67] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V71*/ meltfptr[69] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5634:/ quasiblock");


	    /*^cond */
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.NEXTB__V62*/
						 meltfptr[61]),
						(melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[31])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^getslot */
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.NEXTB__V62*/ meltfptr[61]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.NEXTSYM__V73*/ meltfptr[67] = slot;
		};
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.NEXTSYM__V73*/ meltfptr[67] = NULL;;
	      }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    /*^compute */
   /*_#IS_A__L27*/ meltfnum[18] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.NEXTB__V62*/ meltfptr[61]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
	    MELT_LOCATION ("warmelt-normal.melt:5635:/ cond");
	    /*cond */ if ( /*_#IS_A__L27*/ meltfnum[18])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5636:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[1];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NLETREC__V55*/ meltfptr[54];
		    /*_.NRECLIST_FIND_LOCSYM__V75*/ meltfptr[74] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				    tabval[32])),
				  (melt_ptr_t) ( /*_.NEXTSYM__V73*/
						meltfptr[67]),
				  (MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_.NEXTLOC__V74*/ meltfptr[73] =
		    /*_.NRECLIST_FIND_LOCSYM__V75*/ meltfptr[74];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5635:/ clear");
	       /*clear *//*_.NRECLIST_FIND_LOCSYM__V75*/ meltfptr[74] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.NEXTLOC__V74*/ meltfptr[73] = NULL;;
	      }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5638:/ cond");
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.CURPAIRB__V61*/
						 meltfptr[60]),
						(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @NPAIRB_HEAD",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V61*/
						     meltfptr[60])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V61*/ meltfptr[60]),
					(4),
					( /*_.CURNARG__V60*/ meltfptr[59]),
					"NPAIRB_HEAD");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @NPAIRB_TAIL",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V61*/
						     meltfptr[60])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V61*/ meltfptr[60]),
					(5),
					( /*_.NEXTLOC__V74*/ meltfptr[73]),
					"NPAIRB_TAIL");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @NCONSB_NLETREC",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V61*/
						     meltfptr[60])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V61*/ meltfptr[60]),
					(3),
					( /*_.NLETREC__V55*/ meltfptr[54]),
					"NCONSB_NLETREC");
		  ;
		  /*^touch */
		  meltgc_touch ( /*_.CURPAIRB__V61*/ meltfptr[60]);
		  ;
		  /*^touchobj */

		  melt_dbgtrace_written_object ( /*_.CURPAIRB__V61*/
						meltfptr[60], "put-fields");
		  ;
		  /*epilog */
		}
		;
	      }			/*noelse */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5641:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L28*/ meltfnum[19] =
		/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		;;
	      MELT_LOCATION ("warmelt-normal.melt:5641:/ cond");
	      /*cond */ if ( /*_#MELT_NEED_DBG__L28*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*^block */
		  /*anyblock */
		  {

       /*_#MELT_CALLCOUNT__L29*/ meltfnum[28] =
		      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		      meltcallcount	/* melt_callcount debugging */
#else
		      0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		      ;;

		    MELT_CHECK_SIGNAL ();
		    ;
		    MELT_LOCATION ("warmelt-normal.melt:5641:/ apply");
		    /*apply */
		    {
		      union meltparam_un argtab[5];
		      memset (&argtab, 0, sizeof (argtab));
		      /*^apply.arg */
		      argtab[0].meltbp_long =
			/*_#MELT_CALLCOUNT__L29*/ meltfnum[28];
		      /*^apply.arg */
		      argtab[1].meltbp_cstring = "warmelt-normal.melt";
		      /*^apply.arg */
		      argtab[2].meltbp_long = 5641;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring =
			"normexp_list updated curpairb";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURPAIRB__V61*/ meltfptr[60];
		      /*_.MELT_DEBUG_FUN__V77*/ meltfptr[76] =
			melt_apply ((meltclosure_ptr_t)
				    (( /*!MELT_DEBUG_FUN */ meltfrout->
				      tabval[3])),
				    (melt_ptr_t) (( /*nil */ NULL)),
				    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				     MELTBPARSTR_PTR ""), argtab, "",
				    (union meltparam_un *) 0);
		    }
		    ;
		    /*_._IF___V76*/ meltfptr[74] =
		      /*_.MELT_DEBUG_FUN__V77*/ meltfptr[76];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5641:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L29*/ meltfnum[28] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V77*/ meltfptr[76] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V76*/ meltfptr[74] = NULL;;
		}
	      ;

	      {
		MELT_LOCATION ("warmelt-normal.melt:5641:/ locexp");
		/*void */ (void) 0;
	      }
	      ;
	      /*^quasiblock */


	      /*epilog */

	      /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L28*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V76*/ meltfptr[74] = 0;
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

	    MELT_LOCATION ("warmelt-normal.melt:5634:/ clear");
	     /*clear *//*_.NEXTSYM__V73*/ meltfptr[67] = 0;
	    /*^clear */
	     /*clear *//*_#IS_A__L27*/ meltfnum[18] = 0;
	    /*^clear */
	     /*clear *//*_.NEXTLOC__V74*/ meltfptr[73] = 0;

	    MELT_LOCATION ("warmelt-normal.melt:5625:/ clear");
	     /*clear *//*_.CURPAIRB__V61*/ meltfptr[60] = 0;
	    /*^clear */
	     /*clear *//*_#plI__L18*/ meltfnum[14] = 0;
	    /*^clear */
	     /*clear *//*_.NEXTB__V62*/ meltfptr[61] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V65*/ meltfptr[63] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V67*/ meltfptr[62] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V71*/ meltfptr[69] = 0;
	    if ( /*_#NIX__L17*/ meltfnum[15] < 0)
	      break;
	  }			/* end  foreach_in_multiple meltcit3__EACHTUP */

	/*citerepilog */

	MELT_LOCATION ("warmelt-normal.melt:5622:/ clear");
	     /*clear *//*_.CURNARG__V60*/ meltfptr[59] = 0;
	/*^clear */
	     /*clear *//*_#NIX__L17*/ meltfnum[15] = 0;
      }				/*endciterblock FOREACH_IN_MULTIPLE */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5646:/ quasiblock");


  /*_.FIRSTPAIRB__V78*/ meltfptr[76] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]), (0)));;
      /*^compute */
  /*_.LASTPAIRB__V79*/ meltfptr[74] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.CONSBINDTUP__V24*/ meltfptr[23]), (-2)));;

      MELT_CHECK_SIGNAL ();
      ;
      /*^compute */
  /*_#IS_A__L30*/ meltfnum[28] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.FIRSTPAIRB__V78*/ meltfptr[76]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
      MELT_LOCATION ("warmelt-normal.melt:5649:/ cond");
      /*cond */ if ( /*_#IS_A__L30*/ meltfnum[28])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5651:/ getslot");
	    {
	      melt_ptr_t slot = NULL, obj = NULL;
	      obj =
		(melt_ptr_t) ( /*_.FIRSTPAIRB__V78*/ meltfptr[76]) /*=obj*/ ;
	      melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.BINDER__V81*/ meltfptr[73] = slot;
	    };
	    ;
	    /*_.FIRSTPAIRSYMB__V80*/ meltfptr[67] =
	      /*_.BINDER__V81*/ meltfptr[73];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5649:/ clear");
	      /*clear *//*_.BINDER__V81*/ meltfptr[73] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.FIRSTPAIRSYMB__V80*/ meltfptr[67] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      /*^compute */
  /*_#IS_A__L31*/ meltfnum[19] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.LASTPAIRB__V79*/ meltfptr[74]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
      MELT_LOCATION ("warmelt-normal.melt:5653:/ cond");
      /*cond */ if ( /*_#IS_A__L31*/ meltfnum[19])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5655:/ getslot");
	    {
	      melt_ptr_t slot = NULL, obj = NULL;
	      obj =
		(melt_ptr_t) ( /*_.LASTPAIRB__V79*/ meltfptr[74]) /*=obj*/ ;
	      melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.BINDER__V83*/ meltfptr[61] = slot;
	    };
	    ;
	    /*_.LASTPAIRSYMB__V82*/ meltfptr[60] =
	      /*_.BINDER__V83*/ meltfptr[61];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5653:/ clear");
	      /*clear *//*_.BINDER__V83*/ meltfptr[61] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.LASTPAIRSYMB__V82*/ meltfptr[60] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5657:/ cond");
      /*cond */ if ( /*_.FIRSTPAIRSYMB__V80*/ meltfptr[67])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5658:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[1];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V55*/ meltfptr[54];
	      /*_.NRECLIST_FIND_LOCSYM__V85*/ meltfptr[62] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
			      tabval[32])),
			    (melt_ptr_t) ( /*_.FIRSTPAIRSYMB__V80*/
					  meltfptr[67]), (MELTBPARSTR_PTR ""),
			    argtab, "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_.FIRSTPAIRLOC__V84*/ meltfptr[63] =
	      /*_.NRECLIST_FIND_LOCSYM__V85*/ meltfptr[62];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5657:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V85*/ meltfptr[62] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.FIRSTPAIRLOC__V84*/ meltfptr[63] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5660:/ cond");
      /*cond */ if ( /*_.LASTPAIRSYMB__V82*/ meltfptr[60])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5661:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[1];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V55*/ meltfptr[54];
	      /*_.NRECLIST_FIND_LOCSYM__V87*/ meltfptr[73] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
			      tabval[32])),
			    (melt_ptr_t) ( /*_.LASTPAIRSYMB__V82*/
					  meltfptr[60]), (MELTBPARSTR_PTR ""),
			    argtab, "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_.LASTPAIRLOC__V86*/ meltfptr[69] =
	      /*_.NRECLIST_FIND_LOCSYM__V87*/ meltfptr[73];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5660:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V87*/ meltfptr[73] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.LASTPAIRLOC__V86*/ meltfptr[69] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5663:/ cond");
      /*cond */ if (
		     /*ifisa */
		     melt_is_instance_of ((melt_ptr_t)
					  ( /*_.CONSLISTBIND__V26*/
					   meltfptr[25]),
					  (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[20])))
	)			/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("checkobj putslot  _ @NLISTB_FIRST",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V26*/
					       meltfptr[25])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
				  (4),
				  ( /*_.FIRSTPAIRLOC__V84*/ meltfptr[63]),
				  "NLISTB_FIRST");
	    ;
	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("checkobj putslot  _ @NLISTB_LAST",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V26*/
					       meltfptr[25])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
				  (5), ( /*_.LASTPAIRLOC__V86*/ meltfptr[69]),
				  "NLISTB_LAST");
	    ;
	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("checkobj putslot  _ @NCONSB_NLETREC",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V26*/
					       meltfptr[25])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
				  (3), ( /*_.NLETREC__V55*/ meltfptr[54]),
				  "NCONSB_NLETREC");
	    ;
	    /*^touch */
	    meltgc_touch ( /*_.CONSLISTBIND__V26*/ meltfptr[25]);
	    ;
	    /*^touchobj */

	    melt_dbgtrace_written_object ( /*_.CONSLISTBIND__V26*/
					  meltfptr[25], "put-fields");
	    ;
	    /*epilog */
	  }
	  ;
	}			/*noelse */
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5667:/ locexp");
	melt_put_int ((melt_ptr_t) ( /*_.CONSLISTBIND__V26*/ meltfptr[25]),
		      ( /*_#NBARGS__L6*/ meltfnum[4]));
      }
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5668:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L32*/ meltfnum[18] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5668:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L32*/ meltfnum[18])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L33*/ meltfnum[14] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5668:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[5];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L33*/ meltfnum[14];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5668;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_list updated conslistbind";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.CONSLISTBIND__V26*/ meltfptr[25];
		/*_.MELT_DEBUG_FUN__V89*/ meltfptr[62] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V88*/ meltfptr[61] =
		/*_.MELT_DEBUG_FUN__V89*/ meltfptr[62];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5668:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L33*/ meltfnum[14] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V89*/ meltfptr[62] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V88*/ meltfptr[61] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5668:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L32*/ meltfnum[18] = 0;
	/*^clear */
	      /*clear *//*_._IF___V88*/ meltfptr[61] = 0;
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

      MELT_LOCATION ("warmelt-normal.melt:5646:/ clear");
	    /*clear *//*_.FIRSTPAIRB__V78*/ meltfptr[76] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRB__V79*/ meltfptr[74] = 0;
      /*^clear */
	    /*clear *//*_#IS_A__L30*/ meltfnum[28] = 0;
      /*^clear */
	    /*clear *//*_.FIRSTPAIRSYMB__V80*/ meltfptr[67] = 0;
      /*^clear */
	    /*clear *//*_#IS_A__L31*/ meltfnum[19] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRSYMB__V82*/ meltfptr[60] = 0;
      /*^clear */
	    /*clear *//*_.FIRSTPAIRLOC__V84*/ meltfptr[63] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRLOC__V86*/ meltfptr[69] = 0;

      MELT_CHECK_SIGNAL ();
      ;
  /*_#NULL__L34*/ meltfnum[14] =
	(( /*_.NBINDINGS__V36*/ meltfptr[35]) == NULL);;
      MELT_LOCATION ("warmelt-normal.melt:5671:/ cond");
      /*cond */ if ( /*_#NULL__L34*/ meltfnum[14])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5672:/ compute");
	    /*_.NBINDINGS__V36*/ meltfptr[35] =
	      /*_.SETQ___V91*/ meltfptr[62] =
	      /*_.CLISTBINDLIST__V59*/ meltfptr[58];;
	    /*_._IFELSE___V90*/ meltfptr[73] = /*_.SETQ___V91*/ meltfptr[62];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5671:/ clear");
	      /*clear *//*_.SETQ___V91*/ meltfptr[62] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

	  /*^block */
	  /*anyblock */
	  {




	    {
	      MELT_LOCATION ("warmelt-normal.melt:5673:/ locexp");
	      meltgc_append_list ((melt_ptr_t)
				  ( /*_.NBINDINGS__V36*/ meltfptr[35]),
				  (melt_ptr_t) ( /*_.CLISTBIND__V56*/
						meltfptr[55]));
	    }
	    ;
	      /*clear *//*_._IFELSE___V90*/ meltfptr[73] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5675:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L35*/ meltfnum[18] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5675:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L35*/ meltfnum[18])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L36*/ meltfnum[28] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5675:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[9];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L36*/ meltfnum[28];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5675;
		/*^apply.arg */
		argtab[3].meltbp_cstring = "normexp_list final nletrec=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NLETREC__V55*/ meltfptr[54];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " clistlocc=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.CLISTLOCC__V57*/ meltfptr[56];
		/*^apply.arg */
		argtab[7].meltbp_cstring = " nbindings=";
		/*^apply.arg */
		argtab[8].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NBINDINGS__V36*/ meltfptr[35];
		/*_.MELT_DEBUG_FUN__V93*/ meltfptr[76] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V92*/ meltfptr[61] =
		/*_.MELT_DEBUG_FUN__V93*/ meltfptr[76];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5675:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L36*/ meltfnum[28] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V93*/ meltfptr[76] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V92*/ meltfptr[61] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5675:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L35*/ meltfnum[18] = 0;
	/*^clear */
	      /*clear *//*_._IF___V92*/ meltfptr[61] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5677:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.CLISTLOCC__V57*/ meltfptr[56];;
      MELT_LOCATION ("warmelt-normal.melt:5677:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NBINDINGS__V36*/ meltfptr[35]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;
      /*_.LETREC___V52*/ meltfptr[48] = /*_.RETURN___V94*/ meltfptr[74];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5595:/ clear");
	    /*clear *//*_.CRECLOCC__V53*/ meltfptr[47] = 0;
      /*^clear */
	    /*clear *//*_.NBDY__V54*/ meltfptr[53] = 0;
      /*^clear */
	    /*clear *//*_.NLETREC__V55*/ meltfptr[54] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V56*/ meltfptr[55] = 0;
      /*^clear */
	    /*clear *//*_.CLISTLOCC__V57*/ meltfptr[56] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V58*/ meltfptr[57] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBINDLIST__V59*/ meltfptr[58] = 0;
      /*^clear */
	    /*clear *//*_.CRECLOCC__V53*/ meltfptr[47] = 0;
      /*^clear */
	    /*clear *//*_.NBDY__V54*/ meltfptr[53] = 0;
      /*^clear */
	    /*clear *//*_.NLETREC__V55*/ meltfptr[54] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V56*/ meltfptr[55] = 0;
      /*^clear */
	    /*clear *//*_.CLISTLOCC__V57*/ meltfptr[56] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V58*/ meltfptr[57] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBINDLIST__V59*/ meltfptr[58] = 0;
      /*^clear */
	    /*clear *//*_#NULL__L34*/ meltfnum[14] = 0;
      /*^clear */
	    /*clear *//*_._IFELSE___V90*/ meltfptr[73] = 0;
      /*^clear */
	    /*clear *//*_.RETURN___V94*/ meltfptr[74] = 0;
    }				/*end multiallocblock */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V34*/ meltfptr[29] = /*_.LETREC___V52*/ meltfptr[48];;

    MELT_LOCATION ("warmelt-normal.melt:5576:/ clear");
	   /*clear *//*_.IFCPP___V39*/ meltfptr[37] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V41*/ meltfptr[36] = 0;
    /*^clear */
	   /*clear *//*_.LETREC___V52*/ meltfptr[48] = 0;

    /*^clear */
	   /*clear *//*_.NBINDINGS__V36*/ meltfptr[35] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.MULTI___V34*/ meltfptr[29];;

    MELT_LOCATION ("warmelt-normal.melt:5548:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.CSYMREC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CSYMLIST__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NORMDISCRPAIR__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.NORMDISCRLIST__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.NEWENV__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_#NBARGS__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_.PREPARE_CONSTRUCTOR_BINDING__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.CONSBINDTUP__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.RESBINDINGS__V25*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.CONSLISTBIND__V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.LAMBDA___V27*/ meltfptr[26] = 0;
    /*^clear */
	   /*clear *//*_.TUPRECLOC__V29*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V32*/ meltfptr[30] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V34*/ meltfptr[29] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5543:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5543:/ locexp");
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
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_98_WARMELTmiNORMAL_NORMEXP_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un * meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un * meltxrestab_)
{
  long current_blocklevel_signals_meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31_melt
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

  struct meltframe_meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31_st
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
#define MELTFRAM_NBVARPTR 11
    melt_ptr_t mcfr_varptr[11];
#define MELTFRAM_NBVARNUM 4
    long mcfr_varnum[4];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31_st *)
	meltfirstargp_;
      /* use arguments meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 11; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 nbval 11*/
  meltfram__.mcfr_nbvar = 11 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl31", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5561:/ getarg");
 /*_.CURBIND__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#BINDIX__L1*/ meltfnum[0] = meltxargtab_[0].meltbp_long;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5562:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5562:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5562:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5562;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list curbind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CURBIND__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:5562:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
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
	MELT_LOCATION ("warmelt-normal.melt:5562:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5563:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[2] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CURBIND__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5563:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[2])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V6*/ meltfptr[2] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5563:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check curbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5563) ? (5563) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5563:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[2] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V6*/ meltfptr[2] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5565:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CURBIND__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CURBIND__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NCONSB_LOC");
   /*_.NCONSB_LOC__V7*/ meltfptr[2] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NCONSB_LOC__V7*/ meltfptr[2] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5565:/ cond");
    /*cond */ if ( /*_.NCONSB_LOC__V7*/ meltfptr[2])	/*then */
      {
	/*^cond.then */
	/*_.OR___V8*/ meltfptr[7] = /*_.NCONSB_LOC__V7*/ meltfptr[2];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5565:/ cond.else");

	/*_.OR___V8*/ meltfptr[7] = ( /*~SLOC */ meltfclos->tabval[0]);;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5567:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CURBIND__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CURBIND__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 0, "BINDER");
   /*_.BINDER__V9*/ meltfptr[8] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BINDER__V9*/ meltfptr[8] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5564:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[2])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V11*/ meltfptr[10] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (0),
			  ( /*_.OR___V8*/ meltfptr[7]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (2),
			  (( /*!CTYPE_VALUE */ meltfrout->tabval[3])),
			  "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (1),
			  ( /*_.BINDER__V9*/ meltfptr[8]), "NOCC_SYMB");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V11*/ meltfptr[10])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V11*/ meltfptr[10]), (3),
			  ( /*_.CURBIND__V2*/ meltfptr[1]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V11*/ meltfptr[10],
				  "newly made instance");
    ;
    /*_.INST___V10*/ meltfptr[9] = /*_.INST__V11*/ meltfptr[10];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5561:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.INST___V10*/ meltfptr[9];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5561:/ locexp");
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
    /*^clear */
	   /*clear *//*_.NCONSB_LOC__V7*/ meltfptr[2] = 0;
    /*^clear */
	   /*clear *//*_.OR___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.BINDER__V9*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.INST___V10*/ meltfptr[9] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("LAMBDA_cl31", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_99_WARMELTmiNORMAL_LAMBDA_cl31 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_melt
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

  struct meltframe_meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_st
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
#define MELTFRAM_NBVARPTR 87
    melt_ptr_t mcfr_varptr[87];
#define MELTFRAM_NBVARNUM 30
    long mcfr_varnum[30];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_st
	 *) meltfirstargp_;
      /* use arguments meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 87; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION nbval 87*/
  meltfram__.mcfr_nbvar = 87 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_ARITHMETIC_VARIADIC_OPERATION", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5683:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5684:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5684:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5684:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5684;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5684:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5684:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5685:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5685:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5685:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5685) ? (5685) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5685:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5686:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5686:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5686:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5686) ? (5686) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5686:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5687:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5687:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5687:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5687) ? (5687) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5687:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5688:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V14*/ meltfptr[12] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V14*/ meltfptr[12])	/*then */
      {
	/*^cond.then */
	/*_.SLOC__V15*/ meltfptr[14] = /*_.LOCA_LOCATION__V14*/ meltfptr[12];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5688:/ cond.else");

	/*_.SLOC__V15*/ meltfptr[14] = /*_.PSLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5689:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5690:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SARITHVAR_NEUTRAL");
  /*_.SNEUTRAL__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5691:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 4, "SARITHVAR_PRIMITIVE");
  /*_.SPRIMITIVE__V18*/ meltfptr[17] = slot;
    };
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5693:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5693:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5693:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5693;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation sprimitive=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SPRIMITIVE__V18*/ meltfptr[17];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " sneutral=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SNEUTRAL__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V20*/ meltfptr[19] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V19*/ meltfptr[18] =
	      /*_.MELT_DEBUG_FUN__V20*/ meltfptr[19];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5693:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V20*/ meltfptr[19] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V19*/ meltfptr[18] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5693:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V19*/ meltfptr[18] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5694:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.SPRIMITIVE__V18*/ meltfptr[17]),
			     (melt_ptr_t) (( /*!CLASS_PRIMITIVE */ meltfrout->
					    tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:5694:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V22*/ meltfptr[18] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5694:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check sprimitive"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5694) ? (5694) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V22*/ meltfptr[18] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V21*/ meltfptr[19] = /*_._IFELSE___V22*/ meltfptr[18];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5694:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V22*/ meltfptr[18] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V21*/ meltfptr[19] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5695:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_INTEGERBOX__L9*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.SNEUTRAL__V17*/ meltfptr[16]))
	 == MELTOBMAG_INT);;
      MELT_LOCATION ("warmelt-normal.melt:5695:/ cond");
      /*cond */ if ( /*_#IS_INTEGERBOX__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V24*/ meltfptr[23] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5695:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check sneutral"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5695) ? (5695) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V24*/ meltfptr[23] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V23*/ meltfptr[18] = /*_._IFELSE___V24*/ meltfptr[23];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5695:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V24*/ meltfptr[23] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V23*/ meltfptr[18] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5698:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V26*/ meltfptr[25];
      /*^multiapply.appl */
      /*_.NARGS__V25*/ meltfptr[23] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[5])),
		    (melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5701:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5701:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5701:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5701;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V25*/ meltfptr[23];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDINGS__V26*/ meltfptr[25];
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V27*/ meltfptr[26] =
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5701:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V27*/ meltfptr[26] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5701:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V27*/ meltfptr[26] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5702:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L12*/ meltfnum[0] =
	(( /*_.NBINDINGS__V26*/ meltfptr[25]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDINGS__V26*/ meltfptr[25])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5702:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L12*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V30*/ meltfptr[26] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5702:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5702) ? (5702) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V30*/ meltfptr[26] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V29*/ meltfptr[27] = /*_._IFELSE___V30*/ meltfptr[26];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5702:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V30*/ meltfptr[26] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V29*/ meltfptr[27] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V25*/ meltfptr[23]);
      for ( /*_#ARGIX__L13*/ meltfnum[1] = 0;
	   ( /*_#ARGIX__L13*/ meltfnum[1] >= 0)
	   && ( /*_#ARGIX__L13*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#ARGIX__L13*/ meltfnum[1]++)
	{
	  /*_.CURNARG__V31*/ meltfptr[26] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V25*/ meltfptr[23]),
			       /*_#ARGIX__L13*/ meltfnum[1]);



	  MELT_LOCATION ("warmelt-normal.melt:5707:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^msend */
	  /*msend */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];
	    /*_.ARGCTYP__V33*/ meltfptr[32] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURNARG__V31*/ meltfptr[26]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[6])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#exeq__L14*/ meltfnum[0] =
	    (( /*_.ARGCTYP__V33*/ meltfptr[32]) !=
	     (( /*!CTYPE_LONG */ meltfrout->tabval[7])));;
	  MELT_LOCATION ("warmelt-normal.melt:5709:/ cond");
	  /*cond */ if ( /*_#exeq__L14*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


		{
		  MELT_LOCATION ("warmelt-normal.melt:5710:/ locexp");
		  /* error_plain */
		    melt_error_str ((melt_ptr_t)
				    ( /*_.SLOC__V15*/ meltfptr[14]),
				    ("variadic arithmetic operation requires only :long arguments"),
				    (melt_ptr_t) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:5711:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5711:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5709:/ quasiblock");


		/*_.PROGN___V36*/ meltfptr[35] =
		  /*_.RETURN___V35*/ meltfptr[34];;
		/*^compute */
		/*_._IF___V34*/ meltfptr[33] =
		  /*_.PROGN___V36*/ meltfptr[35];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5709:/ clear");
	      /*clear *//*_.RETURN___V35*/ meltfptr[34] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V36*/ meltfptr[35] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V34*/ meltfptr[33] = NULL;;
	    }
	  ;
	  /*^compute */
	  /*_.LET___V32*/ meltfptr[31] = /*_._IF___V34*/ meltfptr[33];;

	  MELT_LOCATION ("warmelt-normal.melt:5707:/ clear");
	    /*clear *//*_.ARGCTYP__V33*/ meltfptr[32] = 0;
	  /*^clear */
	    /*clear *//*_#exeq__L14*/ meltfnum[0] = 0;
	  /*^clear */
	    /*clear *//*_._IF___V34*/ meltfptr[33] = 0;
	  if ( /*_#ARGIX__L13*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5704:/ clear");
	    /*clear *//*_.CURNARG__V31*/ meltfptr[26] = 0;
      /*^clear */
	    /*clear *//*_#ARGIX__L13*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.LET___V32*/ meltfptr[31] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5713:/ block");
    /*anyblock */
    {

      /*^objgoto */
      /*objgoto */ goto mtch1_0;
      ;

    /*objlabel */ mtch1_0:;
      MELT_LOCATION ("warmelt-normal.melt:5715:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_8;
      meltlab_count_8++;
      debugeprintf
	("objlabel_8 mtch1_*CLASS_NORMTESTER_TUPLE/36d4fbc3. *CLASS_OBJLABELINSTR/2e7e9fc1. %ld",
	 meltlab_count_8);
#endif

      ;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V37*/ meltfptr[34] = 0;
      /*^cond */
      /*cond */ if (
		     /*normtestertuple */
	(melt_magic_discr ((melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15])) ==
	 MELTOBMAG_MULTIPLE
	 && ((meltmultiple_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]))->nbval == 1))	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^compute */
    /*_.NTHCOMP__V37*/ meltfptr[34] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]))->
	      tabval[0];;
	    /*^objgoto */
	    /*objgoto */ goto mtch1_1;
	    ;
	  }
	  ;
	}
      else
	{			/*^cond.else */

	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5730:/ objgoto");
	    /*objgoto */ goto mtch1_2;
	    ;
	  }
	  ;
	}
      ;

    /*objlabel */ mtch1_1:;
      MELT_LOCATION ("warmelt-normal.melt:5715:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_9;
      meltlab_count_9++;
      debugeprintf
	("objlabel_9 mtch1_*CLASS_NORMTESTER_SUCCESS/3702acae. *CLASS_OBJLABELINSTR/1389885e. %ld",
	 meltlab_count_9);
#endif

      ;
      /*^quasiblock */


      /*_.S0__V38*/ meltfptr[35] = /*_.NTHCOMP__V37*/ meltfptr[34];;
      MELT_LOCATION ("warmelt-normal.melt:5716:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5719:/ blockmultialloc");
      /*multiallocblock */
      {
	struct meltletrec_1_st
	{
	  struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x12;
	  long meltletrec_1_endgap;
	} *meltletrec_1_ptr = 0;
	meltletrec_1_ptr =
	  (struct meltletrec_1_st *)
	  meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
	/*^blockmultialloc.initfill */
	/*inimult rtup_0__TUPLREC__x12 */
 /*_.TUPLREC___V40*/ meltfptr[33] =
	  (melt_ptr_t) & meltletrec_1_ptr->rtup_0__TUPLREC__x12;
	meltletrec_1_ptr->rtup_0__TUPLREC__x12.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_1_ptr->rtup_0__TUPLREC__x12.nbval = 2;


	/*^putuple */
	/*putupl#41 */
	melt_assertmsg ("putupl [:5719] #41 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V40*/ meltfptr[33]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5719] #41 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V40*/
						meltfptr[33]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V40*/ meltfptr[33]))->
	  tabval[0] = (melt_ptr_t) ( /*_.SNEUTRAL__V17*/ meltfptr[16]);
	;
	/*^putuple */
	/*putupl#42 */
	melt_assertmsg ("putupl [:5719] #42 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V40*/ meltfptr[33]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5719] #42 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V40*/
						meltfptr[33]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V40*/ meltfptr[33]))->
	  tabval[1] = (melt_ptr_t) ( /*_.S0__V38*/ meltfptr[35]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V40*/ meltfptr[33]);
	;
	/*_.TUPLE___V39*/ meltfptr[32] = /*_.TUPLREC___V40*/ meltfptr[33];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5719:/ clear");
	     /*clear *//*_.TUPLREC___V40*/ meltfptr[33] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V40*/ meltfptr[33] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5716:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V42*/ meltfptr[41] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V42*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (1),
			    ( /*_.SLOC__V15*/ meltfptr[14]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V42*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (3),
			    ( /*_.SPRIMITIVE__V18*/ meltfptr[17]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V42*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V42*/ meltfptr[41]), (2),
			    ( /*_.TUPLE___V39*/ meltfptr[32]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V42*/ meltfptr[41],
				    "newly made instance");
      ;
      /*_.SPRIM__V41*/ meltfptr[33] = /*_.INST__V42*/ meltfptr[41];;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5721:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L15*/ meltfnum[0] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5721:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L15*/ meltfnum[0])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L16*/ meltfnum[15] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5721:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[5];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L16*/ meltfnum[15];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5721;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation unary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V41*/ meltfptr[33];
		/*_.MELT_DEBUG_FUN__V44*/ meltfptr[43] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V43*/ meltfptr[42] =
		/*_.MELT_DEBUG_FUN__V44*/ meltfptr[43];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5721:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[15] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V44*/ meltfptr[43] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V43*/ meltfptr[42] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5721:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_._IF___V43*/ meltfptr[42] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5722:/ quasiblock");


      /*^multiapply */
      /*multiapply 4args, 1x.res */
      {
	union meltparam_un argtab[3];

	union meltparam_un restab[1];
	memset (&restab, 0, sizeof (restab));
	memset (&argtab, 0, sizeof (argtab));
	/*^multiapply.arg */
	argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multiapply.arg */
	argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
	argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V5*/ meltfptr[4];
	/*^multiapply.xres */
	restab[0].meltbp_aptr =
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V46*/ meltfptr[42];
	/*^multiapply.appl */
	/*_.NREALARGS__V45*/ meltfptr[43] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V41*/ meltfptr[33]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5725:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L17*/ meltfnum[15] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5725:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[15])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L18*/ meltfnum[0] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5725:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[7];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[0];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5725;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation unary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V45*/ meltfptr[43];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V46*/ meltfptr[42];
		/*_.MELT_DEBUG_FUN__V48*/ meltfptr[47] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V47*/ meltfptr[46] =
		/*_.MELT_DEBUG_FUN__V48*/ meltfptr[47];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5725:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[0] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V48*/ meltfptr[47] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V47*/ meltfptr[46] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5725:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IF___V47*/ meltfptr[46] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5727:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V45*/ meltfptr[43];;
      MELT_LOCATION ("warmelt-normal.melt:5727:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V46*/ meltfptr[42]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5728:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5722:/ clear");
	    /*clear *//*_.RETURN___V49*/ meltfptr[47] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V46*/ meltfptr[42] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5716:/ clear");
	    /*clear *//*_.TUPLE___V39*/ meltfptr[32] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V41*/ meltfptr[33] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5715:/ clear");
	    /*clear *//*_.S0__V38*/ meltfptr[35] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1_2:;
      MELT_LOCATION ("warmelt-normal.melt:5730:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_10;
      meltlab_count_10++;
      debugeprintf
	("objlabel_10 mtch1_*CLASS_NORMTESTER_TUPLE/20292d22. *CLASS_OBJLABELINSTR/302283c1. %ld",
	 meltlab_count_10);
#endif

      ;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V50*/ meltfptr[46] = 0;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V51*/ meltfptr[47] = 0;
      /*^cond */
      /*cond */ if (
		     /*normtestertuple */
	(melt_magic_discr ((melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15])) ==
	 MELTOBMAG_MULTIPLE
	 && ((meltmultiple_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]))->nbval == 2))	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^compute */
    /*_.NTHCOMP__V50*/ meltfptr[46] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]))->
	      tabval[0];;
	    /*^compute */
    /*_.NTHCOMP__V51*/ meltfptr[47] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]))->
	      tabval[1];;
	    /*^objgoto */
	    /*objgoto */ goto mtch1_3;
	    ;
	  }
	  ;
	}
      else
	{			/*^cond.else */

	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5745:/ objgoto");
	    /*objgoto */ goto mtch1_4;
	    ;
	  }
	  ;
	}
      ;

    /*objlabel */ mtch1_3:;
      MELT_LOCATION ("warmelt-normal.melt:5730:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_11;
      meltlab_count_11++;
      debugeprintf
	("objlabel_11 mtch1_*CLASS_NORMTESTER_SUCCESS/3fd1e241. *CLASS_OBJLABELINSTR/13834ba0. %ld",
	 meltlab_count_11);
#endif

      ;
      /*^quasiblock */


      /*_.S0__V52*/ meltfptr[43] = /*_.NTHCOMP__V50*/ meltfptr[46];;
      /*^compute */
      /*_.S1__V53*/ meltfptr[42] = /*_.NTHCOMP__V51*/ meltfptr[47];;
      MELT_LOCATION ("warmelt-normal.melt:5731:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5734:/ blockmultialloc");
      /*multiallocblock */
      {
	struct meltletrec_2_st
	{
	  struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x13;
	  long meltletrec_2_endgap;
	} *meltletrec_2_ptr = 0;
	meltletrec_2_ptr =
	  (struct meltletrec_2_st *)
	  meltgc_allocate (sizeof (struct meltletrec_2_st), 0);
	/*^blockmultialloc.initfill */
	/*inimult rtup_0__TUPLREC__x13 */
 /*_.TUPLREC___V55*/ meltfptr[33] =
	  (melt_ptr_t) & meltletrec_2_ptr->rtup_0__TUPLREC__x13;
	meltletrec_2_ptr->rtup_0__TUPLREC__x13.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_2_ptr->rtup_0__TUPLREC__x13.nbval = 2;


	/*^putuple */
	/*putupl#43 */
	melt_assertmsg ("putupl [:5734] #43 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V55*/ meltfptr[33]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5734] #43 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V55*/
						meltfptr[33]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V55*/ meltfptr[33]))->
	  tabval[0] = (melt_ptr_t) ( /*_.S0__V52*/ meltfptr[43]);
	;
	/*^putuple */
	/*putupl#44 */
	melt_assertmsg ("putupl [:5734] #44 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V55*/ meltfptr[33]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5734] #44 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V55*/
						meltfptr[33]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V55*/ meltfptr[33]))->
	  tabval[1] = (melt_ptr_t) ( /*_.S1__V53*/ meltfptr[42]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V55*/ meltfptr[33]);
	;
	/*_.TUPLE___V54*/ meltfptr[32] = /*_.TUPLREC___V55*/ meltfptr[33];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5734:/ clear");
	     /*clear *//*_.TUPLREC___V55*/ meltfptr[33] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V55*/ meltfptr[33] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5731:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V57*/ meltfptr[33] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V57*/ meltfptr[33])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V57*/ meltfptr[33]), (1),
			    ( /*_.SLOC__V15*/ meltfptr[14]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V57*/ meltfptr[33])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V57*/ meltfptr[33]), (3),
			    ( /*_.SPRIMITIVE__V18*/ meltfptr[17]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V57*/ meltfptr[33])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V57*/ meltfptr[33]), (2),
			    ( /*_.TUPLE___V54*/ meltfptr[32]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V57*/ meltfptr[33],
				    "newly made instance");
      ;
      /*_.SPRIM__V56*/ meltfptr[35] = /*_.INST__V57*/ meltfptr[33];;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5736:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L19*/ meltfnum[0] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5736:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L19*/ meltfnum[0])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L20*/ meltfnum[15] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5736:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[5];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L20*/ meltfnum[15];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5736;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation binary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V56*/ meltfptr[35];
		/*_.MELT_DEBUG_FUN__V59*/ meltfptr[58] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V58*/ meltfptr[57] =
		/*_.MELT_DEBUG_FUN__V59*/ meltfptr[58];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5736:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[15] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V59*/ meltfptr[58] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V58*/ meltfptr[57] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5736:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_._IF___V58*/ meltfptr[57] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5737:/ quasiblock");


      /*^multiapply */
      /*multiapply 4args, 1x.res */
      {
	union meltparam_un argtab[3];

	union meltparam_un restab[1];
	memset (&restab, 0, sizeof (restab));
	memset (&argtab, 0, sizeof (argtab));
	/*^multiapply.arg */
	argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multiapply.arg */
	argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
	argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V5*/ meltfptr[4];
	/*^multiapply.xres */
	restab[0].meltbp_aptr =
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V61*/ meltfptr[57];
	/*^multiapply.appl */
	/*_.NREALARGS__V60*/ meltfptr[58] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V56*/ meltfptr[35]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5740:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L21*/ meltfnum[15] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5740:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L21*/ meltfnum[15])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L22*/ meltfnum[0] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5740:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[7];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L22*/ meltfnum[0];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5740;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation binary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V60*/ meltfptr[58];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V61*/ meltfptr[57];
		/*_.MELT_DEBUG_FUN__V63*/ meltfptr[62] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V62*/ meltfptr[61] =
		/*_.MELT_DEBUG_FUN__V63*/ meltfptr[62];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5740:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L22*/ meltfnum[0] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V63*/ meltfptr[62] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V62*/ meltfptr[61] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5740:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L21*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IF___V62*/ meltfptr[61] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5742:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V60*/ meltfptr[58];;
      MELT_LOCATION ("warmelt-normal.melt:5742:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V61*/ meltfptr[57]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5743:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5737:/ clear");
	    /*clear *//*_.RETURN___V64*/ meltfptr[62] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V61*/ meltfptr[57] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5731:/ clear");
	    /*clear *//*_.TUPLE___V54*/ meltfptr[32] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V56*/ meltfptr[35] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5730:/ clear");
	    /*clear *//*_.S0__V52*/ meltfptr[43] = 0;
      /*^clear */
	    /*clear *//*_.S1__V53*/ meltfptr[42] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1_4:;
      MELT_LOCATION ("warmelt-normal.melt:5745:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_12;
      meltlab_count_12++;
      debugeprintf
	("objlabel_12 mtch1_*CLASS_NORMTESTER_SUCCESS/333e18ac. *CLASS_OBJLABELINSTR/1aff4df2. %ld",
	 meltlab_count_12);
#endif

      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5746:/ cppif.then");
      /*^block */
      /*anyblock */
      {


	MELT_CHECK_SIGNAL ();
	;
    /*_#MULTIPLE_LENGTH__L23*/ meltfnum[0] =
	  (melt_multiple_length
	   ((melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15])));;
	/*^compute */
    /*_#gtI__L24*/ meltfnum[15] =
	  (( /*_#MULTIPLE_LENGTH__L23*/ meltfnum[0]) > (2));;
	MELT_LOCATION ("warmelt-normal.melt:5746:/ cond");
	/*cond */ if ( /*_#gtI__L24*/ meltfnum[15])	/*then */
	  {
	    /*^cond.then */
	    /*_._IFELSE___V66*/ meltfptr[62] = ( /*nil */ NULL);;
	  }
	else
	  {
	    MELT_LOCATION ("warmelt-normal.melt:5746:/ cond.else");

	    /*^block */
	    /*anyblock */
	    {




	      {
		/*^locexp */
		melt_assert_failed (("check #args>2"),
				    ("warmelt-normal.melt")
				    ? ("warmelt-normal.melt") : __FILE__,
				    (5746) ? (5746) : __LINE__, __FUNCTION__);
		;
	      }
	      ;
		/*clear *//*_._IFELSE___V66*/ meltfptr[62] = 0;
	      /*epilog */
	    }
	    ;
	  }
	;
	/*^compute */
	/*_.IFCPP___V65*/ meltfptr[61] = /*_._IFELSE___V66*/ meltfptr[62];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5746:/ clear");
	      /*clear *//*_#MULTIPLE_LENGTH__L23*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_#gtI__L24*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IFELSE___V66*/ meltfptr[62] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V65*/ meltfptr[61] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5747:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
  /*_.MULTIPLE_NTH__V67*/ meltfptr[58] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]), (0)));;
      /*^compute */
  /*_.MULTIPLE_NTH__V68*/ meltfptr[57] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]), (1)));;
      MELT_LOCATION ("warmelt-normal.melt:5750:/ blockmultialloc");
      /*multiallocblock */
      {
	struct meltletrec_3_st
	{
	  struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x14;
	  long meltletrec_3_endgap;
	} *meltletrec_3_ptr = 0;
	meltletrec_3_ptr =
	  (struct meltletrec_3_st *)
	  meltgc_allocate (sizeof (struct meltletrec_3_st), 0);
	/*^blockmultialloc.initfill */
	/*inimult rtup_0__TUPLREC__x14 */
 /*_.TUPLREC___V70*/ meltfptr[35] =
	  (melt_ptr_t) & meltletrec_3_ptr->rtup_0__TUPLREC__x14;
	meltletrec_3_ptr->rtup_0__TUPLREC__x14.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_3_ptr->rtup_0__TUPLREC__x14.nbval = 2;


	/*^putuple */
	/*putupl#45 */
	melt_assertmsg ("putupl [:5750] #45 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V70*/ meltfptr[35]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5750] #45 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V70*/
						meltfptr[35]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V70*/ meltfptr[35]))->
	  tabval[0] = (melt_ptr_t) ( /*_.MULTIPLE_NTH__V67*/ meltfptr[58]);
	;
	/*^putuple */
	/*putupl#46 */
	melt_assertmsg ("putupl [:5750] #46 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V70*/ meltfptr[35]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5750] #46 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V70*/
						meltfptr[35]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V70*/ meltfptr[35]))->
	  tabval[1] = (melt_ptr_t) ( /*_.MULTIPLE_NTH__V68*/ meltfptr[57]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V70*/ meltfptr[35]);
	;
	/*_.TUPLE___V69*/ meltfptr[32] = /*_.TUPLREC___V70*/ meltfptr[35];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5750:/ clear");
	     /*clear *//*_.TUPLREC___V70*/ meltfptr[35] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V70*/ meltfptr[35] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5747:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V72*/ meltfptr[42] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V72*/ meltfptr[42])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V72*/ meltfptr[42]), (1),
			    ( /*_.SLOC__V15*/ meltfptr[14]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V72*/ meltfptr[42])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V72*/ meltfptr[42]), (3),
			    ( /*_.SPRIMITIVE__V18*/ meltfptr[17]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("checkobj putslot  _ @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V72*/ meltfptr[42])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V72*/ meltfptr[42]), (2),
			    ( /*_.TUPLE___V69*/ meltfptr[32]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V72*/ meltfptr[42],
				    "newly made instance");
      ;
      /*_.SPRIM__V71*/ meltfptr[43] = /*_.INST__V72*/ meltfptr[42];;
      /*citerblock FOREACH_IN_MULTIPLE */
      {
	/* start foreach_in_multiple meltcit2__EACHTUP */
	long meltcit2__EACHTUP_ln =
	  melt_multiple_length ((melt_ptr_t) /*_.SARGS__V16*/ meltfptr[15]);
	for ( /*_#SIX__L25*/ meltfnum[0] = 0;
	     ( /*_#SIX__L25*/ meltfnum[0] >= 0)
	     && ( /*_#SIX__L25*/ meltfnum[0] < meltcit2__EACHTUP_ln);
	/*_#SIX__L25*/ meltfnum[0]++)
	  {
	    /*_.CURSARG__V73*/ meltfptr[62] =
	      melt_multiple_nth ((melt_ptr_t)
				 ( /*_.SARGS__V16*/ meltfptr[15]),
				 /*_#SIX__L25*/ meltfnum[0]);




	    MELT_CHECK_SIGNAL ();
	    ;
   /*_#gtI__L26*/ meltfnum[15] =
	      (( /*_#SIX__L25*/ meltfnum[0]) > (1));;
	    MELT_LOCATION ("warmelt-normal.melt:5755:/ cond");
	    /*cond */ if ( /*_#gtI__L26*/ meltfnum[15])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

		  MELT_LOCATION ("warmelt-normal.melt:5756:/ quasiblock");



		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION
		    ("warmelt-normal.melt:5759:/ blockmultialloc");
		  /*multiallocblock */
		  {
		    struct meltletrec_4_st
		    {
		      struct MELT_MULTIPLE_STRUCT (2) rtup_0__TUPLREC__x15;
		      long meltletrec_4_endgap;
		    } *meltletrec_4_ptr = 0;
		    meltletrec_4_ptr =
		      (struct meltletrec_4_st *)
		      meltgc_allocate (sizeof (struct meltletrec_4_st), 0);
		    /*^blockmultialloc.initfill */
		    /*inimult rtup_0__TUPLREC__x15 */
 /*_.TUPLREC___V77*/ meltfptr[76] =
		      (melt_ptr_t) & meltletrec_4_ptr->rtup_0__TUPLREC__x15;
		    meltletrec_4_ptr->rtup_0__TUPLREC__x15.discr =
		      (meltobject_ptr_t) (((melt_ptr_t)
					   (MELT_PREDEF (DISCR_MULTIPLE))));
		    meltletrec_4_ptr->rtup_0__TUPLREC__x15.nbval = 2;


		    /*^putuple */
		    /*putupl#47 */
		    melt_assertmsg ("putupl [:5759] #47 checktup",
				    melt_magic_discr ((melt_ptr_t)
						      ( /*_.TUPLREC___V77*/
						       meltfptr[76])) ==
				    MELTOBMAG_MULTIPLE);
		    melt_assertmsg ("putupl [:5759] #47 checkoff",
				    (0 >= 0
				     && 0 <
				     melt_multiple_length ((melt_ptr_t)
							   ( /*_.TUPLREC___V77*/ meltfptr[76]))));
		    ((meltmultiple_ptr_t)
		     ( /*_.TUPLREC___V77*/ meltfptr[76]))->tabval[0] =
 (melt_ptr_t) ( /*_.SPRIM__V71*/ meltfptr[43]);
		    ;
		    /*^putuple */
		    /*putupl#48 */
		    melt_assertmsg ("putupl [:5759] #48 checktup",
				    melt_magic_discr ((melt_ptr_t)
						      ( /*_.TUPLREC___V77*/
						       meltfptr[76])) ==
				    MELTOBMAG_MULTIPLE);
		    melt_assertmsg ("putupl [:5759] #48 checkoff",
				    (1 >= 0
				     && 1 <
				     melt_multiple_length ((melt_ptr_t)
							   ( /*_.TUPLREC___V77*/ meltfptr[76]))));
		    ((meltmultiple_ptr_t)
		     ( /*_.TUPLREC___V77*/ meltfptr[76]))->tabval[1] =
 (melt_ptr_t) ( /*_.CURSARG__V73*/ meltfptr[62]);
		    ;
		    /*^touch */
		    meltgc_touch ( /*_.TUPLREC___V77*/ meltfptr[76]);
		    ;
		    /*_.TUPLE___V76*/ meltfptr[75] =
		      /*_.TUPLREC___V77*/ meltfptr[76];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5759:/ clear");
		/*clear *//*_.TUPLREC___V77*/ meltfptr[76] = 0;
		    /*^clear */
		/*clear *//*_.TUPLREC___V77*/ meltfptr[76] = 0;
		  }		/*end multiallocblock */
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5756:/ quasiblock");


		  /*^rawallocobj */
		  /*rawallocobj */
		  {
		    melt_ptr_t newobj = 0;
		    melt_raw_object_create (newobj,
					    (melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */ meltfrout->tabval[8])), (4), "CLASS_SOURCE_PRIMITIVE");
      /*_.INST__V79*/ meltfptr[78] =
		      newobj;
		  };
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @LOCA_LOCATION",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V79*/
						     meltfptr[78])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V79*/ meltfptr[78]), (1),
					( /*_.SLOC__V15*/ meltfptr[14]),
					"LOCA_LOCATION");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @SPRIM_OPER",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V79*/
						     meltfptr[78])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V79*/ meltfptr[78]), (3),
					( /*_.SPRIMITIVE__V18*/ meltfptr[17]),
					"SPRIM_OPER");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("checkobj putslot  _ @SARGOP_ARGS",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V79*/
						     meltfptr[78])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V79*/ meltfptr[78]), (2),
					( /*_.TUPLE___V76*/ meltfptr[75]),
					"SARGOP_ARGS");
		  ;
		  /*^touchobj */

		  melt_dbgtrace_written_object ( /*_.INST__V79*/ meltfptr[78],
						"newly made instance");
		  ;
		  /*_.NEWSPRIM__V78*/ meltfptr[76] =
		    /*_.INST__V79*/ meltfptr[78];;
		  MELT_LOCATION ("warmelt-normal.melt:5761:/ compute");
		  /*_.SPRIM__V71*/ meltfptr[43] =
		    /*_.SETQ___V80*/ meltfptr[79] =
		    /*_.NEWSPRIM__V78*/ meltfptr[76];;
		  /*_.LET___V75*/ meltfptr[74] =
		    /*_.SETQ___V80*/ meltfptr[79];;

		  MELT_LOCATION ("warmelt-normal.melt:5756:/ clear");
	       /*clear *//*_.TUPLE___V76*/ meltfptr[75] = 0;
		  /*^clear */
	       /*clear *//*_.NEWSPRIM__V78*/ meltfptr[76] = 0;
		  /*^clear */
	       /*clear *//*_.SETQ___V80*/ meltfptr[79] = 0;
		  /*_._IF___V74*/ meltfptr[35] =
		    /*_.LET___V75*/ meltfptr[74];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5755:/ clear");
	       /*clear *//*_.LET___V75*/ meltfptr[74] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

    /*_._IF___V74*/ meltfptr[35] = NULL;;
	      }
	    ;
	    if ( /*_#SIX__L25*/ meltfnum[0] < 0)
	      break;
	  }			/* end  foreach_in_multiple meltcit2__EACHTUP */

	/*citerepilog */

	MELT_LOCATION ("warmelt-normal.melt:5752:/ clear");
	     /*clear *//*_.CURSARG__V73*/ meltfptr[62] = 0;
	/*^clear */
	     /*clear *//*_#SIX__L25*/ meltfnum[0] = 0;
	/*^clear */
	     /*clear *//*_#gtI__L26*/ meltfnum[15] = 0;
	/*^clear */
	     /*clear *//*_._IF___V74*/ meltfptr[35] = 0;
      }				/*endciterblock FOREACH_IN_MULTIPLE */
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5763:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L27*/ meltfnum[26] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5763:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L27*/ meltfnum[26])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L28*/ meltfnum[27] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5763:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[5];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L28*/ meltfnum[27];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5763;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation nary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V71*/ meltfptr[43];
		/*_.MELT_DEBUG_FUN__V82*/ meltfptr[76] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V81*/ meltfptr[75] =
		/*_.MELT_DEBUG_FUN__V82*/ meltfptr[76];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5763:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L28*/ meltfnum[27] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V82*/ meltfptr[76] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V81*/ meltfptr[75] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5763:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L27*/ meltfnum[26] = 0;
	/*^clear */
	      /*clear *//*_._IF___V81*/ meltfptr[75] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5764:/ quasiblock");


      /*^multiapply */
      /*multiapply 4args, 1x.res */
      {
	union meltparam_un argtab[3];

	union meltparam_un restab[1];
	memset (&restab, 0, sizeof (restab));
	memset (&argtab, 0, sizeof (argtab));
	/*^multiapply.arg */
	argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];	/*^multiapply.arg */
	argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
	argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V5*/ meltfptr[4];
	/*^multiapply.xres */
	restab[0].meltbp_aptr =
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V84*/ meltfptr[74];
	/*^multiapply.appl */
	/*_.NREALARGS__V83*/ meltfptr[79] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V71*/ meltfptr[43]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5767:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L29*/ meltfnum[27] =
	  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	  0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	  ;;
	MELT_LOCATION ("warmelt-normal.melt:5767:/ cond");
	/*cond */ if ( /*_#MELT_NEED_DBG__L29*/ meltfnum[27])	/*then */
	  {
	    /*^cond.then */
	    /*^block */
	    /*anyblock */
	    {

      /*_#MELT_CALLCOUNT__L30*/ meltfnum[26] =
		/* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		meltcallcount	/* melt_callcount debugging */
#else
		0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		;;

	      MELT_CHECK_SIGNAL ();
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5767:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[7];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long =
		  /*_#MELT_CALLCOUNT__L30*/ meltfnum[26];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5767;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation nary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V83*/ meltfptr[79];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V84*/ meltfptr[74];
		/*_.MELT_DEBUG_FUN__V86*/ meltfptr[75] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V85*/ meltfptr[76] =
		/*_.MELT_DEBUG_FUN__V86*/ meltfptr[75];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5767:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L30*/ meltfnum[26] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V86*/ meltfptr[75] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V85*/ meltfptr[76] = NULL;;
	  }
	;

	{
	  MELT_LOCATION ("warmelt-normal.melt:5767:/ locexp");
	  /*void */ (void) 0;
	}
	;
	/*^quasiblock */


	/*epilog */

	/*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L29*/ meltfnum[27] = 0;
	/*^clear */
	      /*clear *//*_._IF___V85*/ meltfptr[76] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5769:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V83*/ meltfptr[79];;
      MELT_LOCATION ("warmelt-normal.melt:5769:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V84*/ meltfptr[74]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5770:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5764:/ clear");
	    /*clear *//*_.RETURN___V87*/ meltfptr[75] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V84*/ meltfptr[74] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5747:/ clear");
	    /*clear *//*_.MULTIPLE_NTH__V67*/ meltfptr[58] = 0;
      /*^clear */
	    /*clear *//*_.MULTIPLE_NTH__V68*/ meltfptr[57] = 0;
      /*^clear */
	    /*clear *//*_.TUPLE___V69*/ meltfptr[32] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V71*/ meltfptr[43] = 0;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5745:/ clear");
	    /*clear *//*_.IFCPP___V65*/ meltfptr[61] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1__end:;
      MELT_LOCATION ("warmelt-normal.melt:5713:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_13;
      meltlab_count_13++;
      debugeprintf
	("objlabel_13 mtch1__end_h960487570 *CLASS_OBJLABELINSTR/393fe092. %ld",
	 meltlab_count_13);
#endif

      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_LOCATION ("warmelt-normal.melt:5698:/ clear");
	   /*clear *//*_.IFCPP___V29*/ meltfptr[27] = 0;

    /*^clear */
	   /*clear *//*_.NBINDINGS__V26*/ meltfptr[25] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5688:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V14*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.SNEUTRAL__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.SPRIMITIVE__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V21*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V23*/ meltfptr[18] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5683:/ clear");
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_ARITHMETIC_VARIADIC_OPERATION", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_100_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_melt
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

  struct meltframe_meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_st
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
#define MELTFRAM_NBVARPTR 12
    melt_ptr_t mcfr_varptr[12];
#define MELTFRAM_NBVARNUM 2
    long mcfr_varnum[2];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_st
	 *) meltfirstargp_;
      /* use arguments meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 12; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING nbval 12*/
  meltfram__.mcfr_nbvar = 12 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("BADMETH_PREPARE_CONSTRUCTOR_BINDING", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5784:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5785:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5785:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5785:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5785;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"bad_prepare_constructor_binding recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5785:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5785:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5786:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.SYMB__V3*/ meltfptr[2]),
					(melt_ptr_t) (( /*!CLASS_NAMED */
						       meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
   /*_.NAMED_NAME__V8*/ meltfptr[6] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V8*/ meltfptr[6] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5786:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4]),
		      ("invalid constructor binding"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V8*/ meltfptr[6]));
    }
    ;
 /*_.DISCRIM__V9*/ meltfptr[5] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]))));;
    MELT_LOCATION ("warmelt-normal.melt:5788:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.DISCRIM__V9*/ meltfptr[5]),
					(melt_ptr_t) (( /*!CLASS_NAMED */
						       meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.DISCRIM__V9*/ meltfptr[5]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
   /*_.NAMED_NAME__V10*/ meltfptr[9] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V10*/ meltfptr[9] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5787:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4]),
		      ("receiver unprepared to constructor binding"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V10*/ meltfptr[9]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5789:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
      /*^cond */
      /*cond */ if (( /*nil */ NULL))	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V12*/ meltfptr[11] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5789:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("@$@badmeth_prepare_constructor_binding"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5789) ? (5789) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V12*/ meltfptr[11] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V11*/ meltfptr[10] = /*_._IFELSE___V12*/ meltfptr[11];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5789:/ clear");
	     /*clear *//*_._IFELSE___V12*/ meltfptr[11] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V11*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5784:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.IFCPP___V11*/ meltfptr[10];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5784:/ locexp");
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
	   /*clear *//*_.NAMED_NAME__V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.DISCRIM__V9*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.NAMED_NAME__V10*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V11*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("BADMETH_PREPARE_CONSTRUCTOR_BINDING", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_101_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_melt
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

  struct meltframe_meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_st
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
#define MELTFRAM_NBVARPTR 14
    melt_ptr_t mcfr_varptr[14];
#define MELTFRAM_NBVARNUM 2
    long mcfr_varnum[2];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 14; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE nbval 14*/
  meltfram__.mcfr_nbvar = 14 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("BADMETH_NORMAL_LETREC_CONSTRUCTIVE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5802:/ getarg");
 /*_.CEXPR__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.CBIND__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5803:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5803:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5803:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5803;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"badmeth_normal_letrec_constructive cexpr=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CEXPR__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " cbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V8*/ meltfptr[7] =
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5803:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V8*/ meltfptr[7] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5803:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V8*/ meltfptr[7] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5805:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.SYMB__V3*/ meltfptr[2]),
					(melt_ptr_t) (( /*!CLASS_NAMED */
						       meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
   /*_.NAMED_NAME__V10*/ meltfptr[8] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V10*/ meltfptr[8] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5805:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
		      ("invalid letrec constructive symbol"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V10*/ meltfptr[8]));
    }
    ;
 /*_.DISCRIM__V11*/ meltfptr[7] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]))));;
    MELT_LOCATION ("warmelt-normal.melt:5807:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.DISCRIM__V11*/ meltfptr[7]),
					(melt_ptr_t) (( /*!CLASS_NAMED */
						       meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.DISCRIM__V11*/ meltfptr[7]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
   /*_.NAMED_NAME__V12*/ meltfptr[11] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V12*/ meltfptr[11] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5806:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
		      ("receiver unprepared to normal_letrec_constructive"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V12*/ meltfptr[11]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5808:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
      /*^cond */
      /*cond */ if (( /*nil */ NULL))	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V14*/ meltfptr[13] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5808:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("@$@badmeth_normal_letrec_constructive"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5808) ? (5808) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V14*/ meltfptr[13] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V13*/ meltfptr[12] = /*_._IFELSE___V14*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5808:/ clear");
	     /*clear *//*_._IFELSE___V14*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V13*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5802:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.IFCPP___V13*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5802:/ locexp");
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
	   /*clear *//*_.NAMED_NAME__V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.DISCRIM__V11*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.NAMED_NAME__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V13*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("BADMETH_NORMAL_LETREC_CONSTRUCTIVE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_102_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA_melt
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

  struct meltframe_meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA_st
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
#define MELTFRAM_NBVARPTR 16
    melt_ptr_t mcfr_varptr[16];
#define MELTFRAM_NBVARNUM 5
    long mcfr_varnum[5];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA_st *)
	meltfirstargp_;
      /* use arguments meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 16; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA nbval 16*/
  meltfram__.mcfr_nbvar = 16 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_LAMBDA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5813:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5814:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5814:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5814:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5814;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_lambda recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5814:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5814:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5815:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LAMBDA */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5815:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5815:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5815) ? (5815) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5815:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5816:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5819:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V5*/ meltfptr[4];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_closure";
      /*_.NORMAL_PREDEF__V11*/ meltfptr[10] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[3])),
		    (melt_ptr_t) (( /*!DISCR_CLOSURE */ meltfrout->
				   tabval[4])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5816:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING */ meltfrout->tabval[2])), (7), "CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING");
  /*_.INST__V13*/ meltfptr[12] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (1),
			  ( /*_.SLOC__V5*/ meltfptr[4]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (2),
			  ( /*_.NORMAL_PREDEF__V11*/ meltfptr[10]),
			  "NCONSB_DISCR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V13*/ meltfptr[12],
				  "newly made instance");
    ;
    /*_.CONSLAM__V12*/ meltfptr[11] = /*_.INST__V13*/ meltfptr[12];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5822:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5822:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5822:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5822;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_lambda gives conslam";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLAM__V12*/ meltfptr[11];
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V14*/ meltfptr[13] =
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5822:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V14*/ meltfptr[13] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5822:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V14*/ meltfptr[13] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5823:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSLAM__V12*/ meltfptr[11];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5823:/ locexp");
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
    /*_.LET___V10*/ meltfptr[5] = /*_.RETURN___V16*/ meltfptr[14];;

    MELT_LOCATION ("warmelt-normal.melt:5816:/ clear");
	   /*clear *//*_.NORMAL_PREDEF__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.CONSLAM__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V16*/ meltfptr[14] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5813:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V10*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5813:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V10*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_LAMBDA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_103_WARMELTmiNORMAL_PREPCONS_LAMBDA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA_melt
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

  struct meltframe_meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA_st
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
#define MELTFRAM_NBVARPTR 29
    melt_ptr_t mcfr_varptr[29];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA_st *)
	meltfirstargp_;
      /* use arguments meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 29; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA nbval 29*/
  meltfram__.mcfr_nbvar = 29 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_LAMBDA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5830:/ getarg");
 /*_.CEXPR__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.CBIND__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V7*/ meltfptr[6])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5831:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5831:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5831:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5831;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_lambda cexpr=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CEXPR__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " cbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " env=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V8*/ meltfptr[7] =
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5831:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V8*/ meltfptr[7] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5831:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V8*/ meltfptr[7] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5833:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5833:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5833:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5833) ? (5833) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5833:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5834:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      /*_.NEWENV__V12*/ meltfptr[7] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!FRESH_ENV */ meltfrout->tabval[2])),
		    (melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5836:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5836:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5836:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5836;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_lambda newenv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEWENV__V12*/ meltfptr[7];
	      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V13*/ meltfptr[12] =
	      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5836:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V13*/ meltfptr[12] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5836:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5837:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NEWENV__V12*/ meltfptr[7]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5837:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V16*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5837:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check newenv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5837) ? (5837) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V15*/ meltfptr[13] = /*_._IFELSE___V16*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5837:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V16*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V15*/ meltfptr[13] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5838:/ quasiblock");


    /*^multiapply */
    /*multiapply 5args, 8x.res */
    {
      union meltparam_un argtab[4];

      union meltparam_un restab[8];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V12*/ meltfptr[7];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];	/*^multiapply.arg */
      argtab[3].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V7*/ meltfptr[6];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.CSYM__V18*/ meltfptr[17];
      /*^multiapply.xres */
      restab[1].meltbp_aptr = (melt_ptr_t *) & /*_.CLOCC__V19*/ meltfptr[18];
      /*^multiapply.xres */
      restab[2].meltbp_aptr =
	(melt_ptr_t *) & /*_.CONSTROUT__V20*/ meltfptr[19];
      /*^multiapply.xres */
      restab[3].meltbp_aptr =
	(melt_ptr_t *) & /*_.CLOVTUP__V21*/ meltfptr[20];
      /*^multiapply.xres */
      restab[4].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V22*/ meltfptr[21];
      /*^multiapply.xres */
      restab[5].meltbp_aptr =
	(melt_ptr_t *) & /*_.OLDPROC__V23*/ meltfptr[22];
      /*^multiapply.xres */
      restab[6].meltbp_aptr =
	(melt_ptr_t *) & /*_.NDATAROUT__V24*/ meltfptr[23];
      /*^multiapply.xres */
      restab[7].meltbp_longptr = & /*_#INSIDEFLAG__L7*/ meltfnum[0];
      /*^multiapply.appl */
      /*_.NPROC__V17*/ meltfptr[12] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_LAMBDA */ meltfrout->tabval[4])),
		    (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
		     MELTBPARSTR_PTR ""), argtab,
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
		     MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
		     MELTBPARSTR_PTR MELTBPARSTR_LONG ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5842:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L8*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5842:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L8*/ meltfnum[1])	/*then */
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
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5842:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[15];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5842;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_lambda after normalize_lambda csym=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CSYM__V18*/ meltfptr[17];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " clocc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOCC__V19*/ meltfptr[18];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " constrout=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSTROUT__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " clovtup=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOVTUP__V21*/ meltfptr[20];
	      /*^apply.arg */
	      argtab[11].meltbp_cstring = " oldproc=";
	      /*^apply.arg */
	      argtab[12].meltbp_aptr =
		(melt_ptr_t *) & /*_.OLDPROC__V23*/ meltfptr[22];
	      /*^apply.arg */
	      argtab[13].meltbp_cstring = " ndatarout=";
	      /*^apply.arg */
	      argtab[14].meltbp_aptr =
		(melt_ptr_t *) & /*_.NDATAROUT__V24*/ meltfptr[23];
	      /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V25*/ meltfptr[24] =
	      /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5842:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[8] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V25*/ meltfptr[24] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5842:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V25*/ meltfptr[24] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5848:/ cond");
    /*cond */ if ( /*_#INSIDEFLAG__L7*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:5849:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.OLDPROC__V23*/
					       meltfptr[22]),
					      (melt_ptr_t) (( /*!CLASS_NREP_CLOSPROC */ meltfrout->tabval[5])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.OLDPROC__V23*/ meltfptr[22]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 5, "NRCLOP_CONSTLIST");
     /*_.NRCLOP_CONSTLIST__V27*/ meltfptr[25] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_.NRCLOP_CONSTLIST__V27*/ meltfptr[25] = NULL;;
	    }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:5849:/ locexp");
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRCLOP_CONSTLIST__V27*/ meltfptr[25]),
				(melt_ptr_t) ( /*_.NDATAROUT__V24*/
					      meltfptr[23]));
	  }
	  ;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:5848:/ clear");
	     /*clear *//*_.NRCLOP_CONSTLIST__V27*/ meltfptr[25] = 0;
	}
	;
      }				/*noelse */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5850:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CBIND__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NLAMBDAB_NCLOSED",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (4),
				( /*_.CLOVTUP__V21*/ meltfptr[20]),
				"NLAMBDAB_NCLOSED");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NLAMBDAB_CONSTROUT",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (5),
				( /*_.CONSTROUT__V20*/ meltfptr[19]),
				"NLAMBDAB_CONSTROUT");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NLAMBDAB_DATAROUT",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (6),
				( /*_.NDATAROUT__V24*/ meltfptr[23]),
				"NLAMBDAB_DATAROUT");
	  ;
	  /*^touch */
	  meltgc_touch ( /*_.CBIND__V4*/ meltfptr[3]);
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.CBIND__V4*/ meltfptr[3],
					"put-fields");
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5854:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L10*/ meltfnum[8] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5854:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[8])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5854:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5854;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_lambda updated cbind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[25] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V28*/ meltfptr[24] =
	      /*_.MELT_DEBUG_FUN__V29*/ meltfptr[25];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5854:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V29*/ meltfptr[25] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V28*/ meltfptr[24] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5854:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V28*/ meltfptr[24] = 0;
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

    {
      MELT_LOCATION ("warmelt-normal.melt:5856:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normletrec_lambda ended"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;


    MELT_LOCATION ("warmelt-normal.melt:5838:/ clear");
	   /*clear *//*_.CSYM__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CLOCC__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.CONSTROUT__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.CLOVTUP__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.OLDPROC__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.NDATAROUT__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_#INSIDEFLAG__L7*/ meltfnum[0] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5834:/ clear");
	   /*clear *//*_.NEWENV__V12*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V15*/ meltfptr[13] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5830:/ clear");
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_LAMBDA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_104_WARMELTmiNORMAL_NORMLETREC_LAMBDA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE_melt
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

  struct meltframe_meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE_st
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
#define MELTFRAM_NBVARPTR 20
    melt_ptr_t mcfr_varptr[20];
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE_st *)
	meltfirstargp_;
      /* use arguments meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 20; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE nbval 20*/
  meltfram__.mcfr_nbvar = 20 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_TUPLE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5862:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5863:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5863:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5863:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5863;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_tuple recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5863:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5863:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5864:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_TUPLE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5864:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5864:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5864) ? (5864) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5864:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5865:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:5866:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_LOCATED */
						       meltfrout->tabval[2])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOC__V11*/ meltfptr[10] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V11*/ meltfptr[10] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5867:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_ARGUMENTED_OPERATOR */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
   /*_.TUPARG__V12*/ meltfptr[11] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.TUPARG__V12*/ meltfptr[11] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBTUPARG__L4*/ meltfnum[0] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.TUPARG__V12*/ meltfptr[11])));;
    /*^compute */
 /*_.NTUP__V13*/ meltfptr[12] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[4])),
	( /*_#NBTUPARG__L4*/ meltfnum[0])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5872:/ cond");
    /*cond */ if ( /*_.LOC__V11*/ meltfptr[10])	/*then */
      {
	/*^cond.then */
	/*_.OR___V14*/ meltfptr[13] = /*_.LOC__V11*/ meltfptr[10];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5872:/ cond.else");

	/*_.OR___V14*/ meltfptr[13] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5873:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V5*/ meltfptr[4];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_multiple";
      /*_.NORMAL_PREDEF__V15*/ meltfptr[14] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[6])),
		    (melt_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->
				   tabval[4])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5870:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING */ meltfrout->tabval[5])), (5), "CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING");
  /*_.INST__V17*/ meltfptr[16] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V17*/ meltfptr[16])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V17*/ meltfptr[16]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V17*/ meltfptr[16])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V17*/ meltfptr[16]), (1),
			  ( /*_.OR___V14*/ meltfptr[13]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V17*/ meltfptr[16])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V17*/ meltfptr[16]), (2),
			  ( /*_.NORMAL_PREDEF__V15*/ meltfptr[14]),
			  "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NTUPB_COMP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V17*/ meltfptr[16])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V17*/ meltfptr[16]), (4),
			  ( /*_.NTUP__V13*/ meltfptr[12]), "NTUPB_COMP");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V17*/ meltfptr[16],
				  "newly made instance");
    ;
    /*_.CONSTUP__V16*/ meltfptr[15] = /*_.INST__V17*/ meltfptr[16];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5877:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L5*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5877:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L6*/ meltfnum[5] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5877:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5877;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_tuple gives constup";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSTUP__V16*/ meltfptr[15];
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V18*/ meltfptr[17] =
	      /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5877:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V18*/ meltfptr[17] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5877:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V18*/ meltfptr[17] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5878:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSTUP__V16*/ meltfptr[15];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5878:/ locexp");
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
    /*_.LET___V10*/ meltfptr[5] = /*_.RETURN___V20*/ meltfptr[18];;

    MELT_LOCATION ("warmelt-normal.melt:5865:/ clear");
	   /*clear *//*_.LOC__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.TUPARG__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_#NBTUPARG__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.NTUP__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.OR___V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.NORMAL_PREDEF__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.CONSTUP__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V20*/ meltfptr[18] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5862:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V10*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5862:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V10*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_TUPLE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_105_WARMELTmiNORMAL_PREPCONS_TUPLE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE_melt
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

  struct meltframe_meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE_st
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
#define MELTFRAM_NBVARPTR 41
    melt_ptr_t mcfr_varptr[41];
#define MELTFRAM_NBVARNUM 20
    long mcfr_varnum[20];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE_st *)
	meltfirstargp_;
      /* use arguments meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 41; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE nbval 41*/
  meltfram__.mcfr_nbvar = 41 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_TUPLE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5883:/ getarg");
 /*_.CEXPR__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.CBIND__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5884:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5884:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5884:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5884;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple cexpr=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CEXPR__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " cbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V8*/ meltfptr[7] =
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5884:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V8*/ meltfptr[7] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5884:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V8*/ meltfptr[7] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5885:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_TUPLE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5885:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5885:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cexpr"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5885) ? (5885) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5885:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5886:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5886:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5886:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5886) ? (5886) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[7] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5886:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5887:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING */ meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5887:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[14] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5887:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5887) ? (5887) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V14*/ meltfptr[12] = /*_._IFELSE___V15*/ meltfptr[14];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5887:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5888:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:5889:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CEXPR__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_LOCATED */
						       meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V16*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOCA_LOCATION__V16*/ meltfptr[14] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5889:/ cond");
    /*cond */ if ( /*_.LOCA_LOCATION__V16*/ meltfptr[14])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V17*/ meltfptr[16] = /*_.LOCA_LOCATION__V16*/ meltfptr[14];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5889:/ cond.else");

	/*_.LOC__V17*/ meltfptr[16] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5890:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5891:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CBIND__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 4, "NTUPB_COMP");
   /*_.BCOMP__V19*/ meltfptr[18] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BCOMP__V19*/ meltfptr[18] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5892:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CBIND__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[5])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NCONSB_NLETREC");
   /*_.NLETREC__V20*/ meltfptr[19] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V20*/ meltfptr[19] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5893:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V20*/ meltfptr[19]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[6])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V20*/ meltfptr[19]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V21*/ meltfptr[20] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V21*/ meltfptr[20] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5895:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L6*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5895:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5895:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5895;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple sargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SARGS__V18*/ meltfptr[17];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " bcomp=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.BCOMP__V19*/ meltfptr[18];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " nrecbinds=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V21*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V22*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5895:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V23*/ meltfptr[22] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V22*/ meltfptr[21] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5895:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V22*/ meltfptr[21] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5897:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V20*/ meltfptr[19]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:5897:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V25*/ meltfptr[21] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5897:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5897) ? (5897) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V25*/ meltfptr[21] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V24*/ meltfptr[22] = /*_._IFELSE___V25*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5897:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V25*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V24*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5898:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L9*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.NRECBINDS__V21*/ meltfptr[20]))
	 == MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:5898:/ cond");
      /*cond */ if ( /*_#IS_LIST__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V27*/ meltfptr[26] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5898:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nrecbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5898) ? (5898) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V27*/ meltfptr[26] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V26*/ meltfptr[21] = /*_._IFELSE___V27*/ meltfptr[26];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5898:/ clear");
	     /*clear *//*_#IS_LIST__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V27*/ meltfptr[26] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V26*/ meltfptr[21] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5899:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.LOC__V17*/ meltfptr[16];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V29*/ meltfptr[28];
      /*^multiapply.appl */
      /*_.NARGS__V28*/ meltfptr[26] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[7])),
		    (melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5902:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5902:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L11*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5902:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5902;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V28*/ meltfptr[26];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbinds=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V29*/ meltfptr[28];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V30*/ meltfptr[29] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5902:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V30*/ meltfptr[29] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5902:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[29] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5903:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#MULTIPLE_LENGTH__L12*/ meltfnum[0] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.BCOMP__V19*/ meltfptr[18])));;
      /*^compute */
   /*_#MULTIPLE_LENGTH__L13*/ meltfnum[1] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.NARGS__V28*/ meltfptr[26])));;
      /*^compute */
   /*_#eqeqI__L14*/ meltfnum[13] =
	(( /*_#MULTIPLE_LENGTH__L12*/ meltfnum[0]) ==
	 ( /*_#MULTIPLE_LENGTH__L13*/ meltfnum[1]));;
      MELT_LOCATION ("warmelt-normal.melt:5903:/ cond");
      /*cond */ if ( /*_#eqeqI__L14*/ meltfnum[13])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V33*/ meltfptr[29] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5903:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nargs & bcomp samelength"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5903) ? (5903) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V33*/ meltfptr[29] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V32*/ meltfptr[30] = /*_._IFELSE___V33*/ meltfptr[29];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5903:/ clear");
	     /*clear *//*_#MULTIPLE_LENGTH__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L13*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_#eqeqI__L14*/ meltfnum[13] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V33*/ meltfptr[29] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V32*/ meltfptr[30] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5904:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L15*/ meltfnum[0] =
	(( /*_.NBINDS__V29*/ meltfptr[28]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDS__V29*/ meltfptr[28])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5904:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L15*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V35*/ meltfptr[34] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5904:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5904) ? (5904) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V35*/ meltfptr[34] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V34*/ meltfptr[29] = /*_._IFELSE___V35*/ meltfptr[34];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5904:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L15*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V35*/ meltfptr[34] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V34*/ meltfptr[29] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V28*/ meltfptr[26]);
      for ( /*_#NIX__L16*/ meltfnum[1] = 0;
	   ( /*_#NIX__L16*/ meltfnum[1] >= 0)
	   && ( /*_#NIX__L16*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#NIX__L16*/ meltfnum[1]++)
	{
	  /*_.CURNARG__V36*/ meltfptr[34] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V28*/ meltfptr[26]),
			       /*_#NIX__L16*/ meltfnum[1]);




	  {
	    MELT_LOCATION ("warmelt-normal.melt:5908:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.BCOMP__V19*/ meltfptr[18]),
				     ( /*_#NIX__L16*/ meltfnum[1]),
				     (melt_ptr_t) ( /*_.CURNARG__V36*/
						   meltfptr[34]));
	  }
	  ;
	  if ( /*_#NIX__L16*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5905:/ clear");
	    /*clear *//*_.CURNARG__V36*/ meltfptr[34] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L16*/ meltfnum[1] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5909:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L17*/ meltfnum[13] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5909:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[13])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L18*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5909:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5909;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple updated bcomp";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.BCOMP__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V38*/ meltfptr[37] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V37*/ meltfptr[36] =
	      /*_.MELT_DEBUG_FUN__V38*/ meltfptr[37];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5909:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V38*/ meltfptr[37] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V37*/ meltfptr[36] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5909:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[13] = 0;
      /*^clear */
	     /*clear *//*_._IF___V37*/ meltfptr[36] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5910:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V29*/ meltfptr[28];
      /*_.LIST_APPEND2LIST__V39*/ meltfptr[37] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[8])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V21*/ meltfptr[20]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5911:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L19*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5911:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L19*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L20*/ meltfnum[13] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5911:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L20*/ meltfnum[13];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5911;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V21*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V41*/ meltfptr[40] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V40*/ meltfptr[36] =
	      /*_.MELT_DEBUG_FUN__V41*/ meltfptr[40];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5911:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[13] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V41*/ meltfptr[40] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V40*/ meltfptr[36] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5911:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V40*/ meltfptr[36] = 0;
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

    {
      MELT_LOCATION ("warmelt-normal.melt:5912:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normletrec_tuple ended"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_LOCATION ("warmelt-normal.melt:5899:/ clear");
	   /*clear *//*_.IFCPP___V32*/ meltfptr[30] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V34*/ meltfptr[29] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V39*/ meltfptr[37] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V29*/ meltfptr[28] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5888:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V16*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.BCOMP__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V24*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V26*/ meltfptr[21] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5883:/ clear");
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_TUPLE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_106_WARMELTmiNORMAL_NORMLETREC_TUPLE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST_melt
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

  struct meltframe_meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST_st
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
#define MELTFRAM_NBVARPTR 32
    melt_ptr_t mcfr_varptr[32];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 32; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST nbval 32*/
  meltfram__.mcfr_nbvar = 32 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5918:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5919:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5919:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5919:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5919;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_list recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5919:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5919:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5920:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5920:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5920:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5920) ? (5920) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5920:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5921:/ quasiblock");


 /*_.RESLIST__V11*/ meltfptr[10] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[2]))));;
    MELT_LOCATION ("warmelt-normal.melt:5923:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_LOCATED */
						       meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOC__V12*/ meltfptr[11] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V12*/ meltfptr[11] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5924:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_ARGUMENTED_OPERATOR */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
   /*_.LISTARG__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LISTARG__V13*/ meltfptr[12] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBLISTARG__L4*/ meltfnum[0] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.LISTARG__V13*/ meltfptr[12])));;
    /*^compute */
 /*_.PAIRSB__V14*/ meltfptr[13] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[5])),
	( /*_#NBLISTARG__L4*/ meltfnum[0])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5929:/ cond");
    /*cond */ if ( /*_.LOC__V12*/ meltfptr[11])	/*then */
      {
	/*^cond.then */
	/*_.OR___V15*/ meltfptr[14] = /*_.LOC__V12*/ meltfptr[11];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5929:/ cond.else");

	/*_.OR___V15*/ meltfptr[14] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5930:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V5*/ meltfptr[4];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_list";
      /*_.NORMAL_PREDEF__V16*/ meltfptr[15] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[2])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5927:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])), (7), "CLASS_NORMAL_CONSTRUCTED_LIST_BINDING");
  /*_.INST__V18*/ meltfptr[17] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (1),
			  ( /*_.OR___V15*/ meltfptr[14]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (2),
			  ( /*_.NORMAL_PREDEF__V16*/ meltfptr[15]),
			  "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLISTB_FIRST",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (4),
			  (( /*nil */ NULL)), "NLISTB_FIRST");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLISTB_LAST",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (5),
			  (( /*nil */ NULL)), "NLISTB_LAST");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLISTB_PAIRSB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V18*/ meltfptr[17])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V18*/ meltfptr[17]), (6),
			  ( /*_.PAIRSB__V14*/ meltfptr[13]), "NLISTB_PAIRSB");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V18*/ meltfptr[17],
				  "newly made instance");
    ;
    /*_.CONSLIST__V17*/ meltfptr[16] = /*_.INST__V18*/ meltfptr[17];;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.LISTARG__V13*/ meltfptr[12]);
      for ( /*_#CURIX__L5*/ meltfnum[1] = 0;
	   ( /*_#CURIX__L5*/ meltfnum[1] >= 0)
	   && ( /*_#CURIX__L5*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#CURIX__L5*/ meltfnum[1]++)
	{
	  /*_.CURARG__V19*/ meltfptr[18] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.LISTARG__V13*/ meltfptr[12]),
			       /*_#CURIX__L5*/ meltfnum[1]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5939:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L6*/ meltfnum[5] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:5939:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L6*/ meltfnum[5])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L7*/ meltfnum[6] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5939:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L7*/ meltfnum[6];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 5939;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "prepcons_list curarg";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURARG__V19*/ meltfptr[18];
		    /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20] =
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
		  /*_._IF___V20*/ meltfptr[19] =
		    /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5939:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[6] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V21*/ meltfptr[20] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V20*/ meltfptr[19] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:5939:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[5] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V20*/ meltfptr[19] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:5940:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#IS_A__L8*/ meltfnum[6] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.CURARG__V19*/ meltfptr[18]),
				 (melt_ptr_t) (( /*!CLASS_NAMED */ meltfrout->
						tabval[9])));;
	  MELT_LOCATION ("warmelt-normal.melt:5940:/ cond");
	  /*cond */ if ( /*_#IS_A__L8*/ meltfnum[6])	/*then */
	    {
	      /*^cond.then */
	      /*_._IFELSE___V22*/ meltfptr[20] =
		/*_.CURARG__V19*/ meltfptr[18];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:5940:/ cond.else");

	      /*_._IFELSE___V22*/ meltfptr[20] =
		( /*!konst_10__PAIROFLIST */ meltfrout->tabval[10]);;
	    }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5940:/ apply");
	  /*apply */
	  {
	    /*_.PAIRSYMB__V23*/ meltfptr[19] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!CLONE_SYMBOL */ meltfrout->tabval[8])),
			  (melt_ptr_t) ( /*_._IFELSE___V22*/ meltfptr[20]),
			  (""), (union meltparam_un *) 0, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5943:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURARG__V19*/
					       meltfptr[18]),
					      (melt_ptr_t) (( /*!CLASS_LOCATED */ meltfrout->tabval[3])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURARG__V19*/ meltfptr[18]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
    /*_.LOCA_LOCATION__V24*/ meltfptr[23] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.LOCA_LOCATION__V24*/ meltfptr[23] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5943:/ cond");
	  /*cond */ if ( /*_.LOCA_LOCATION__V24*/ meltfptr[23])	/*then */
	    {
	      /*^cond.then */
	      /*_.OR___V25*/ meltfptr[24] =
		/*_.LOCA_LOCATION__V24*/ meltfptr[23];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:5943:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.LOC__V12*/ meltfptr[11])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V26*/ meltfptr[25] =
		      /*_.LOC__V12*/ meltfptr[11];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:5943:/ cond.else");

		    /*_.OR___V26*/ meltfptr[25] = /*_.SLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.OR___V25*/ meltfptr[24] = /*_.OR___V26*/ meltfptr[25];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5943:/ clear");
	      /*clear *//*_.OR___V26*/ meltfptr[25] = 0;
	      }
	      ;
	    }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5944:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V5*/ meltfptr[4];
	    /*^apply.arg */
	    argtab[2].meltbp_cstring = "discr_pair";
	    /*_.NORMAL_PREDEF__V27*/ meltfptr[25] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
			  (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->
					 tabval[12])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5941:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[11])), (6), "CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING");
   /*_.INST__V29*/ meltfptr[28] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @BINDER",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (0),
				( /*_.PAIRSYMB__V23*/ meltfptr[19]),
				"BINDER");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCONSB_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (1),
				( /*_.OR___V25*/ meltfptr[24]), "NCONSB_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (2),
				( /*_.NORMAL_PREDEF__V27*/ meltfptr[25]),
				"NCONSB_DISCR");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NPAIRB_HEAD",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (4),
				(( /*nil */ NULL)), "NPAIRB_HEAD");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NPAIRB_TAIL",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V29*/ meltfptr[28]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V29*/ meltfptr[28]), (5),
				(( /*nil */ NULL)), "NPAIRB_TAIL");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V29*/ meltfptr[28],
					"newly made instance");
	  ;
	  /*_.CONSPAIR__V28*/ meltfptr[27] = /*_.INST__V29*/ meltfptr[28];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:5949:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.PAIRSB__V14*/ meltfptr[13]),
				     ( /*_#CURIX__L5*/ meltfnum[1]),
				     (melt_ptr_t) ( /*_.CONSPAIR__V28*/
						   meltfptr[27]));
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:5950:/ locexp");
	    meltgc_append_list ((melt_ptr_t)
				( /*_.RESLIST__V11*/ meltfptr[10]),
				(melt_ptr_t) ( /*_.CONSPAIR__V28*/
					      meltfptr[27]));
	  }
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:5940:/ clear");
	    /*clear *//*_#IS_A__L8*/ meltfnum[6] = 0;
	  /*^clear */
	    /*clear *//*_._IFELSE___V22*/ meltfptr[20] = 0;
	  /*^clear */
	    /*clear *//*_.PAIRSYMB__V23*/ meltfptr[19] = 0;
	  /*^clear */
	    /*clear *//*_.LOCA_LOCATION__V24*/ meltfptr[23] = 0;
	  /*^clear */
	    /*clear *//*_.OR___V25*/ meltfptr[24] = 0;
	  /*^clear */
	    /*clear *//*_.NORMAL_PREDEF__V27*/ meltfptr[25] = 0;
	  /*^clear */
	    /*clear *//*_.CONSPAIR__V28*/ meltfptr[27] = 0;
	  if ( /*_#CURIX__L5*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5936:/ clear");
	    /*clear *//*_.CURARG__V19*/ meltfptr[18] = 0;
      /*^clear */
	    /*clear *//*_#CURIX__L5*/ meltfnum[1] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5952:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.RESLIST__V11*/ meltfptr[10]),
			  (melt_ptr_t) ( /*_.CONSLIST__V17*/ meltfptr[16]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5953:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L9*/ meltfnum[5] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5953:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[5])	/*then */
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
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5953:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[6];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5953;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_list gives reslist";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RESLIST__V11*/ meltfptr[10];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[19] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V30*/ meltfptr[20] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[19];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5953:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[19] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V30*/ meltfptr[20] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5953:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[20] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5954:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.RESLIST__V11*/ meltfptr[10];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5954:/ locexp");
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
    /*_.LET___V10*/ meltfptr[5] = /*_.RETURN___V32*/ meltfptr[23];;

    MELT_LOCATION ("warmelt-normal.melt:5921:/ clear");
	   /*clear *//*_.RESLIST__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.LISTARG__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_#NBLISTARG__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.PAIRSB__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.OR___V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.NORMAL_PREDEF__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.CONSLIST__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V32*/ meltfptr[23] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5918:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V10*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5918:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V10*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_107_WARMELTmiNORMAL_PREPCONS_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_melt
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

  struct meltframe_meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_st
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
#define MELTFRAM_NBVARPTR 21
    melt_ptr_t mcfr_varptr[21];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_st
	 *) meltfirstargp_;
      /* use arguments meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 21; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM nbval 21*/
  meltfram__.mcfr_nbvar = 21 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NRECLIST_FIND_LOCSYM", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5961:/ getarg");
 /*_.SYMB__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NLETREC__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NLETREC__V3*/ meltfptr[2])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5962:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5962:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5962:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5962;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "nreclist_find_locsym symb";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V4*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V5*/ meltfptr[4];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5962:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
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
	MELT_LOCATION ("warmelt-normal.melt:5962:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
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

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5963:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.SYMB__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					    tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5963:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[3] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5963:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check symb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5963) ? (5963) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[3] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[4] = /*_._IFELSE___V7*/ meltfptr[3];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5963:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5964:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5964:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5964:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5964) ? (5964) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[3] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5964:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5965:/ quasiblock");


    /*^cond */
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V3*/ meltfptr[2]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[2])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V3*/ meltfptr[2]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 5, "NLETREC_LOCSYMS");
   /*_.NLOCSYMS__V11*/ meltfptr[10] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLOCSYMS__V11*/ meltfptr[10] = NULL;;
      }
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NLOCSYMS__V11*/ meltfptr[10]);
      for ( /*_#LOCSYMIX__L5*/ meltfnum[1] = 0;
	   ( /*_#LOCSYMIX__L5*/ meltfnum[1] >= 0)
	   && ( /*_#LOCSYMIX__L5*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#LOCSYMIX__L5*/ meltfnum[1]++)
	{
	  /*_.CURLOCSYM__V12*/ meltfptr[11] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.NLOCSYMS__V11*/ meltfptr[10]),
			       /*_#LOCSYMIX__L5*/ meltfnum[1]);




	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5970:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURLOCSYM__V12*/
					       meltfptr[11]),
					      (melt_ptr_t) (( /*!CLASS_NREP_SYMOCC */ meltfrout->tabval[3])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURLOCSYM__V12*/ meltfptr[11]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NOCC_SYMB");
    /*_.NOCC_SYMB__V13*/ meltfptr[12] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NOCC_SYMB__V13*/ meltfptr[12] = NULL;;
	    }
	  ;
	  /*^compute */
  /*_#eqeq__L6*/ meltfnum[0] =
	    (( /*_.NOCC_SYMB__V13*/ meltfptr[12]) ==
	     ( /*_.SYMB__V2*/ meltfptr[1]));;
	  MELT_LOCATION ("warmelt-normal.melt:5970:/ cond");
	  /*cond */ if ( /*_#eqeq__L6*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:5972:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:5972:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:5972:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 5972;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "nreclist_find_locsym found curlocsym";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURLOCSYM__V12*/
			    meltfptr[11];
			  /*_.MELT_DEBUG_FUN__V16*/ meltfptr[15] =
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
			/*_._IF___V15*/ meltfptr[14] =
			  /*_.MELT_DEBUG_FUN__V16*/ meltfptr[15];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5972:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V16*/ meltfptr[15] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V15*/ meltfptr[14] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:5972:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		/*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[6] = 0;
		  /*^clear */
		/*clear *//*_._IF___V15*/ meltfptr[14] = 0;
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
		MELT_LOCATION ("warmelt-normal.melt:5973:/ quasiblock");


		/*_._RETVAL___V1*/ meltfptr[0] =
		  /*_.CURLOCSYM__V12*/ meltfptr[11];;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5973:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5971:/ quasiblock");


		/*_.PROGN___V18*/ meltfptr[14] =
		  /*_.RETURN___V17*/ meltfptr[15];;
		/*^compute */
		/*_._IF___V14*/ meltfptr[13] =
		  /*_.PROGN___V18*/ meltfptr[14];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5970:/ clear");
	      /*clear *//*_.RETURN___V17*/ meltfptr[15] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V18*/ meltfptr[14] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V14*/ meltfptr[13] = NULL;;
	    }
	  ;
	  if ( /*_#LOCSYMIX__L5*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5967:/ clear");
	    /*clear *//*_.CURLOCSYM__V12*/ meltfptr[11] = 0;
      /*^clear */
	    /*clear *//*_#LOCSYMIX__L5*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.NOCC_SYMB__V13*/ meltfptr[12] = 0;
      /*^clear */
	    /*clear *//*_#eqeq__L6*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_._IF___V14*/ meltfptr[13] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5974:/ cppif.then");
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
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5974:/ cond");
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
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5974:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[4];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[6];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5974;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "nreclist_find_locsym not found";
	      /*_.MELT_DEBUG_FUN__V20*/ meltfptr[14] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING ""), argtab,
			    "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V19*/ meltfptr[15] =
	      /*_.MELT_DEBUG_FUN__V20*/ meltfptr[14];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5974:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V20*/ meltfptr[14] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V19*/ meltfptr[15] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5974:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IF___V19*/ meltfptr[15] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5975:/ quasiblock");


 /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

    {
      MELT_LOCATION ("warmelt-normal.melt:5975:/ locexp");
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
    /*_.LET___V10*/ meltfptr[8] = /*_.RETURN___V21*/ meltfptr[14];;

    MELT_LOCATION ("warmelt-normal.melt:5965:/ clear");
	   /*clear *//*_.NLOCSYMS__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V21*/ meltfptr[14] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5961:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V10*/ meltfptr[8];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5961:/ locexp");
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
	   /*clear *//*_.IFCPP___V6*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_.LET___V10*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NRECLIST_FIND_LOCSYM", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_108_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST_melt
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

  struct meltframe_meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST_st
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
#define MELTFRAM_NBVARPTR 76
    melt_ptr_t mcfr_varptr[76];
#define MELTFRAM_NBVARNUM 43
    long mcfr_varnum[43];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 76; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST nbval 76*/
  meltfram__.mcfr_nbvar = 76 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5979:/ getarg");
 /*_.CEXPR__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.CBIND__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5980:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5980:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5980:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5980;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list cexpr=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CEXPR__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " cbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V8*/ meltfptr[7] =
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5980:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V8*/ meltfptr[7] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5980:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V8*/ meltfptr[7] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5981:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5981:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5981:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cexpr"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5981) ? (5981) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5981:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5984:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_MULTIPLE__L4*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) ==
	 MELTOBMAG_MULTIPLE);;
      MELT_LOCATION ("warmelt-normal.melt:5984:/ cond");
      /*cond */ if ( /*_#IS_MULTIPLE__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5984:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind is tuple"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5984) ? (5984) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[7] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5984:/ clear");
	     /*clear *//*_#IS_MULTIPLE__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5985:/ quasiblock");


    /*^cond */
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CEXPR__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_LOCATED */
						       meltfrout->tabval[2])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V14*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOCA_LOCATION__V14*/ meltfptr[12] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5985:/ cond");
    /*cond */ if ( /*_.LOCA_LOCATION__V14*/ meltfptr[12])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V15*/ meltfptr[14] = /*_.LOCA_LOCATION__V14*/ meltfptr[12];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5985:/ cond.else");

	/*_.LOC__V15*/ meltfptr[14] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5986:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CEXPR__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_ARGUMENTED_OPERATOR */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
   /*_.SARGS__V16*/ meltfptr[15] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.SARGS__V16*/ meltfptr[15] = NULL;;
      }
    ;
    /*^compute */
 /*_.CONSLIBIND__V17*/ meltfptr[16] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (-1)));;
    MELT_LOCATION ("warmelt-normal.melt:5988:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CONSLIBIND__V17*/ meltfptr[16]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CONSLIBIND__V17*/ meltfptr[16]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NCONSB_NLETREC");
   /*_.NLETREC__V18*/ meltfptr[17] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V18*/ meltfptr[17] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5989:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V18*/ meltfptr[17]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[5])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V18*/ meltfptr[17]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V19*/ meltfptr[18] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V19*/ meltfptr[18] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5990:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V18*/ meltfptr[17]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[5])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V18*/ meltfptr[17]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 5, "NLETREC_LOCSYMS");
   /*_.NLOCSYMS__V20*/ meltfptr[19] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLOCSYMS__V20*/ meltfptr[19] = NULL;;
      }
    ;
    /*^compute */
 /*_.FIRSTPAIRBIND__V21*/ meltfptr[20] =
      (melt_multiple_nth ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (0)));;
    /*^compute */
 /*_.LASTPAIRBIND__V22*/ meltfptr[21] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (-2)));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5994:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L5*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5994:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L6*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5994:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5994;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list conslibind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLIBIND__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V23*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5994:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V23*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5994:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V23*/ meltfptr[22] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5995:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L7*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.CONSLIBIND__V17*/ meltfptr[16]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:5995:/ cond");
      /*cond */ if ( /*_#IS_A__L7*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V26*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5995:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check conslibind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5995) ? (5995) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V26*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V25*/ meltfptr[23] = /*_._IFELSE___V26*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5995:/ clear");
	     /*clear *//*_#IS_A__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V26*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V25*/ meltfptr[23] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5997:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L8*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5997:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L9*/ meltfnum[0] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5997:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5997;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list sargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SARGS__V16*/ meltfptr[15];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V18*/ meltfptr[17];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " nrecbinds=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V27*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5997:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V27*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5997:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V27*/ meltfptr[22] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:5999:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L10*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V18*/ meltfptr[17]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[5])));;
      MELT_LOCATION ("warmelt-normal.melt:5999:/ cond");
      /*cond */ if ( /*_#IS_A__L10*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V30*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5999:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5999) ? (5999) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V30*/ meltfptr[22] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V29*/ meltfptr[27] = /*_._IFELSE___V30*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5999:/ clear");
	     /*clear *//*_#IS_A__L10*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V30*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V29*/ meltfptr[27] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6000:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L11*/ meltfnum[1] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.NRECBINDS__V19*/ meltfptr[18]))
	 == MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:6000:/ cond");
      /*cond */ if ( /*_#IS_LIST__L11*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V32*/ meltfptr[31] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6000:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nrecbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6000) ? (6000) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V32*/ meltfptr[31] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V31*/ meltfptr[22] = /*_._IFELSE___V32*/ meltfptr[31];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6000:/ clear");
	     /*clear *//*_#IS_LIST__L11*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V32*/ meltfptr[31] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V31*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6001:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.LOC__V15*/ meltfptr[14];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V34*/ meltfptr[33];
      /*^multiapply.appl */
      /*_.NARGS__V33*/ meltfptr[31] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[7])),
		    (melt_ptr_t) ( /*_.SARGS__V16*/ meltfptr[15]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6004:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L12*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6004:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L12*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L13*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6004:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L13*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6004;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V33*/ meltfptr[31];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbinds=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V34*/ meltfptr[33];
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V35*/ meltfptr[34] =
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6004:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V35*/ meltfptr[34] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6004:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V35*/ meltfptr[34] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6005:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L14*/ meltfnum[1] =
	(( /*_.NBINDS__V34*/ meltfptr[33]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDS__V34*/ meltfptr[33])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6005:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L14*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V38*/ meltfptr[34] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6005:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6005) ? (6005) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V38*/ meltfptr[34] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V37*/ meltfptr[35] = /*_._IFELSE___V38*/ meltfptr[34];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6005:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L14*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V38*/ meltfptr[34] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V37*/ meltfptr[35] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6006:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#MULTIPLE_LENGTH__L15*/ meltfnum[0] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.NARGS__V33*/ meltfptr[31])));;
      /*^compute */
   /*_#MULTIPLE_LENGTH__L16*/ meltfnum[1] =
	(melt_multiple_length ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])));;
      /*^compute */
   /*_#miI__L17*/ meltfnum[16] =
	(( /*_#MULTIPLE_LENGTH__L16*/ meltfnum[1]) - (1));;
      /*^compute */
   /*_#eqeqI__L18*/ meltfnum[17] =
	(( /*_#MULTIPLE_LENGTH__L15*/ meltfnum[0]) ==
	 ( /*_#miI__L17*/ meltfnum[16]));;
      MELT_LOCATION ("warmelt-normal.melt:6006:/ cond");
      /*cond */ if ( /*_#eqeqI__L18*/ meltfnum[17])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V40*/ meltfptr[39] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6006:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nargs\'s length vs cbind\'s length"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6006) ? (6006) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V40*/ meltfptr[39] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V39*/ meltfptr[34] = /*_._IFELSE___V40*/ meltfptr[39];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6006:/ clear");
	     /*clear *//*_#MULTIPLE_LENGTH__L15*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L16*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_#miI__L17*/ meltfnum[16] = 0;
      /*^clear */
	     /*clear *//*_#eqeqI__L18*/ meltfnum[17] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V40*/ meltfptr[39] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V39*/ meltfptr[34] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V33*/ meltfptr[31]);
      for ( /*_#NIX__L19*/ meltfnum[0] = 0;
	   ( /*_#NIX__L19*/ meltfnum[0] >= 0)
	   && ( /*_#NIX__L19*/ meltfnum[0] < meltcit1__EACHTUP_ln);
	/*_#NIX__L19*/ meltfnum[0]++)
	{
	  /*_.CURNARG__V41*/ meltfptr[39] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V33*/ meltfptr[31]),
			       /*_#NIX__L19*/ meltfnum[0]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6011:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L20*/ meltfnum[1] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6011:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L20*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L21*/ meltfnum[16] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6011:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L21*/ meltfnum[16];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6011;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normletrec_list curnarg";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURNARG__V41*/ meltfptr[39];
		    /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42] =
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
		  /*_._IF___V42*/ meltfptr[41] =
		    /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6011:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L21*/ meltfnum[16] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V43*/ meltfptr[42] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V42*/ meltfptr[41] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6011:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L20*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V42*/ meltfptr[41] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6012:/ quasiblock");


  /*_.CURCBIND__V45*/ meltfptr[41] =
	    (melt_multiple_nth
	     ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
	      ( /*_#NIX__L19*/ meltfnum[0])));;
	  /*^compute */
  /*_#plI__L22*/ meltfnum[17] =
	    ((1) + ( /*_#NIX__L19*/ meltfnum[0]));;
	  /*^compute */
  /*_.NEXTCBIND__V46*/ meltfptr[45] =
	    (melt_multiple_nth
	     ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
	      ( /*_#plI__L22*/ meltfnum[17])));;

	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^compute */
  /*_#IS_A__L23*/ meltfnum[16] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.NEXTCBIND__V46*/ meltfptr[45]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	  MELT_LOCATION ("warmelt-normal.melt:6014:/ cond");
	  /*cond */ if ( /*_#IS_A__L23*/ meltfnum[16])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6015:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.NEXTCBIND__V46*/
						     meltfptr[45]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.NEXTCBIND__V46*/ meltfptr[45])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
      /*_.BINDER__V48*/ meltfptr[47] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.BINDER__V48*/ meltfptr[47] = NULL;;
		  }
		;
		/*^compute */
		/*_.NEXTPAIRSYMB__V47*/ meltfptr[46] =
		  /*_.BINDER__V48*/ meltfptr[47];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6014:/ clear");
	      /*clear *//*_.BINDER__V48*/ meltfptr[47] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NEXTPAIRSYMB__V47*/ meltfptr[46] = NULL;;
	    }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6017:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L24*/ meltfnum[1] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6017:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L24*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L25*/ meltfnum[24] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6017:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[9];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L25*/ meltfnum[24];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6017;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normletrec_list curcbind=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V45*/ meltfptr[41];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " nextcbind=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTCBIND__V46*/ meltfptr[45];
		    /*^apply.arg */
		    argtab[7].meltbp_cstring = " nextpairsymb=";
		    /*^apply.arg */
		    argtab[8].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTPAIRSYMB__V47*/ meltfptr[46];
		    /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[0])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V49*/ meltfptr[47] =
		    /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6017:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L25*/ meltfnum[24] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V49*/ meltfptr[47] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6017:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L24*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V49*/ meltfptr[47] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6019:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L26*/ meltfnum[24] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V45*/ meltfptr[41]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:6019:/ cond");
	    /*cond */ if ( /*_#IS_A__L26*/ meltfnum[24])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V52*/ meltfptr[47] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6019:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6019) ? (6019) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V52*/ meltfptr[47] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V51*/ meltfptr[49] =
	      /*_._IFELSE___V52*/ meltfptr[47];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6019:/ clear");
	      /*clear *//*_#IS_A__L26*/ meltfnum[24] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V52*/ meltfptr[47] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V51*/ meltfptr[49] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6020:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.NEXTPAIRSYMB__V47*/ meltfptr[46])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


		MELT_CHECK_SIGNAL ();
		;
		/*^apply */
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NLETREC__V18*/ meltfptr[17];
		  /*_.NRECLIST_FIND_LOCSYM__V55*/ meltfptr[54] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.NEXTPAIRSYMB__V47*/
					      meltfptr[46]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		/*_.NEXTPAIRLOC__V54*/ meltfptr[53] =
		  /*_.NRECLIST_FIND_LOCSYM__V55*/ meltfptr[54];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6020:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V55*/ meltfptr[54] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NEXTPAIRLOC__V54*/ meltfptr[53] = NULL;;
	    }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6021:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L27*/ meltfnum[1] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6021:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L27*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L28*/ meltfnum[24] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6021:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L28*/ meltfnum[24];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6021;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_list got nextpairloc";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTPAIRLOC__V54*/ meltfptr[53];
		    /*_.MELT_DEBUG_FUN__V57*/ meltfptr[56] =
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
		  /*_._IF___V56*/ meltfptr[54] =
		    /*_.MELT_DEBUG_FUN__V57*/ meltfptr[56];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6021:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L28*/ meltfnum[24] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V57*/ meltfptr[56] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V56*/ meltfptr[54] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6021:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L27*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V56*/ meltfptr[54] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6022:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V45*/
					       meltfptr[41]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NPAIRB_HEAD",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V45*/
						   meltfptr[41])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V45*/ meltfptr[41]),
				      (4), ( /*_.CURNARG__V41*/ meltfptr[39]),
				      "NPAIRB_HEAD");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NPAIRB_TAIL",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V45*/
						   meltfptr[41])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V45*/ meltfptr[41]),
				      (5),
				      ( /*_.NEXTPAIRLOC__V54*/ meltfptr[53]),
				      "NPAIRB_TAIL");
		;
		/*^touch */
		meltgc_touch ( /*_.CURCBIND__V45*/ meltfptr[41]);
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.CURCBIND__V45*/
					      meltfptr[41], "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6025:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L29*/ meltfnum[24] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6025:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L29*/ meltfnum[24])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L30*/ meltfnum[1] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6025:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L30*/ meltfnum[1];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6025;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_list updated curcbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V45*/ meltfptr[41];
		    /*_.MELT_DEBUG_FUN__V59*/ meltfptr[54] =
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
		  /*_._IF___V58*/ meltfptr[56] =
		    /*_.MELT_DEBUG_FUN__V59*/ meltfptr[54];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6025:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L30*/ meltfnum[1] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V59*/ meltfptr[54] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V58*/ meltfptr[56] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6025:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L29*/ meltfnum[24] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V58*/ meltfptr[56] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6026:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L31*/ meltfnum[1] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V45*/ meltfptr[41]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:6026:/ cond");
	    /*cond */ if ( /*_#IS_A__L31*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V61*/ meltfptr[56] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6026:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6026) ? (6026) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V61*/ meltfptr[56] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V60*/ meltfptr[54] =
	      /*_._IFELSE___V61*/ meltfptr[56];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6026:/ clear");
	      /*clear *//*_#IS_A__L31*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V61*/ meltfptr[56] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V60*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  /*^compute */
	  /*_.LET___V53*/ meltfptr[47] = /*_.IFCPP___V60*/ meltfptr[54];;

	  MELT_LOCATION ("warmelt-normal.melt:6020:/ clear");
	    /*clear *//*_.NEXTPAIRLOC__V54*/ meltfptr[53] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V60*/ meltfptr[54] = 0;
	  /*_.LET___V44*/ meltfptr[42] = /*_.LET___V53*/ meltfptr[47];;

	  MELT_LOCATION ("warmelt-normal.melt:6012:/ clear");
	    /*clear *//*_.CURCBIND__V45*/ meltfptr[41] = 0;
	  /*^clear */
	    /*clear *//*_#plI__L22*/ meltfnum[17] = 0;
	  /*^clear */
	    /*clear *//*_.NEXTCBIND__V46*/ meltfptr[45] = 0;
	  /*^clear */
	    /*clear *//*_#IS_A__L23*/ meltfnum[16] = 0;
	  /*^clear */
	    /*clear *//*_.NEXTPAIRSYMB__V47*/ meltfptr[46] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V51*/ meltfptr[49] = 0;
	  /*^clear */
	    /*clear *//*_.LET___V53*/ meltfptr[47] = 0;
	  if ( /*_#NIX__L19*/ meltfnum[0] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6008:/ clear");
	    /*clear *//*_.CURNARG__V41*/ meltfptr[39] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L19*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_.LET___V44*/ meltfptr[42] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6028:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L32*/ meltfnum[24] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6028:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L32*/ meltfnum[24])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L33*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6028:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L33*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6028;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list firstpairbind=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.FIRSTPAIRBIND__V21*/ meltfptr[20];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " lastpairbind=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.LASTPAIRBIND__V22*/ meltfptr[21];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " conslibind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLIBIND__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V63*/ meltfptr[53] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V62*/ meltfptr[56] =
	      /*_.MELT_DEBUG_FUN__V63*/ meltfptr[53];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6028:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L33*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V63*/ meltfptr[53] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V62*/ meltfptr[56] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6028:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L32*/ meltfnum[24] = 0;
      /*^clear */
	     /*clear *//*_._IF___V62*/ meltfptr[56] = 0;
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
 /*_#IS_A__L34*/ meltfnum[17] =
      melt_is_instance_of ((melt_ptr_t)
			   ( /*_.FIRSTPAIRBIND__V21*/ meltfptr[20]),
			   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
    MELT_LOCATION ("warmelt-normal.melt:6031:/ cond");
    /*cond */ if ( /*_#IS_A__L34*/ meltfnum[17])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#IS_A__L35*/ meltfnum[16] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.LASTPAIRBIND__V22*/ meltfptr[21]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	  MELT_LOCATION ("warmelt-normal.melt:6031:/ cond");
	  /*cond */ if ( /*_#IS_A__L35*/ meltfnum[16])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6033:/ quasiblock");


		/*^cond */
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.FIRSTPAIRBIND__V21*/
						     meltfptr[20]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.FIRSTPAIRBIND__V21*/ meltfptr[20])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
       /*_.FIRSTPAIRSYMB__V64*/ meltfptr[54] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_.FIRSTPAIRSYMB__V64*/ meltfptr[54] = NULL;;
		  }
		;
		MELT_LOCATION ("warmelt-normal.melt:6034:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.LASTPAIRBIND__V22*/
						     meltfptr[21]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.LASTPAIRBIND__V22*/ meltfptr[21])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
       /*_.LASTPAIRSYMB__V65*/ meltfptr[41] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_.LASTPAIRSYMB__V65*/ meltfptr[41] = NULL;;
		  }
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6035:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NLETREC__V18*/ meltfptr[17];
		  /*_.FIRSTPAIRLOCSY__V66*/ meltfptr[45] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.FIRSTPAIRSYMB__V64*/
					      meltfptr[54]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6036:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NLETREC__V18*/ meltfptr[17];
		  /*_.LASTPAIRLOCSY__V67*/ meltfptr[46] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.LASTPAIRSYMB__V65*/
					      meltfptr[41]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6038:/ cppif.then");
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
       /*_#MELT_NEED_DBG__L36*/ meltfnum[1] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:6038:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L36*/ meltfnum[1])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	 /*_#MELT_CALLCOUNT__L37*/ meltfnum[24] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:6038:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[7];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L37*/ meltfnum[24];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 6038;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normletrec_list firstpairlocsy=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.FIRSTPAIRLOCSY__V66*/
			    meltfptr[45];
			  /*^apply.arg */
			  argtab[5].meltbp_cstring = " lastpairlocsy=";
			  /*^apply.arg */
			  argtab[6].meltbp_aptr =
			    (melt_ptr_t *) & /*_.LASTPAIRLOCSY__V67*/
			    meltfptr[46];
			  /*_.MELT_DEBUG_FUN__V69*/ meltfptr[47] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[0])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V68*/ meltfptr[49] =
			  /*_.MELT_DEBUG_FUN__V69*/ meltfptr[47];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6038:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L37*/ meltfnum[24] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V69*/ meltfptr[47] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V68*/ meltfptr[49] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:6038:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L36*/ meltfnum[1] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V68*/ meltfptr[49] = 0;
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
		MELT_LOCATION ("warmelt-normal.melt:6039:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CONSLIBIND__V17*/
						     meltfptr[16]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("checkobj putslot  _ @NLISTB_FIRST",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CONSLIBIND__V17*/ meltfptr[16])) == MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CONSLIBIND__V17*/
					     meltfptr[16]), (4),
					    ( /*_.FIRSTPAIRLOCSY__V66*/
					     meltfptr[45]), "NLISTB_FIRST");
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("checkobj putslot  _ @NLISTB_LAST",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CONSLIBIND__V17*/ meltfptr[16])) == MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CONSLIBIND__V17*/
					     meltfptr[16]), (5),
					    ( /*_.LASTPAIRLOCSY__V67*/
					     meltfptr[46]), "NLISTB_LAST");
		      ;
		      /*^touch */
		      meltgc_touch ( /*_.CONSLIBIND__V17*/ meltfptr[16]);
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.CONSLIBIND__V17*/
						    meltfptr[16],
						    "put-fields");
		      ;
		      /*epilog */
		    }
		    ;
		  }		/*noelse */
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6042:/ cppif.then");
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
       /*_#MELT_NEED_DBG__L38*/ meltfnum[24] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:6042:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L38*/ meltfnum[24])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	 /*_#MELT_CALLCOUNT__L39*/ meltfnum[1] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:6042:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L39*/ meltfnum[1];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 6042;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normletrec_list updated conslibind";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CONSLIBIND__V17*/
			    meltfptr[16];
			  /*_.MELT_DEBUG_FUN__V71*/ meltfptr[56] =
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
			/*_._IF___V70*/ meltfptr[53] =
			  /*_.MELT_DEBUG_FUN__V71*/ meltfptr[56];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6042:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L39*/ meltfnum[1] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V71*/ meltfptr[56] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V70*/ meltfptr[53] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:6042:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		 /*clear *//*_#MELT_NEED_DBG__L38*/ meltfnum[24] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V70*/ meltfptr[53] = 0;
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

		{
		  MELT_LOCATION ("warmelt-normal.melt:6043:/ locexp");
		  /*void */ (void) 0;
		}
		;

		MELT_LOCATION ("warmelt-normal.melt:6033:/ clear");
	       /*clear *//*_.FIRSTPAIRSYMB__V64*/ meltfptr[54] = 0;
		/*^clear */
	       /*clear *//*_.LASTPAIRSYMB__V65*/ meltfptr[41] = 0;
		/*^clear */
	       /*clear *//*_.FIRSTPAIRLOCSY__V66*/ meltfptr[45] = 0;
		/*^clear */
	       /*clear *//*_.LASTPAIRLOCSY__V67*/ meltfptr[46] = 0;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6031:/ clear");
	     /*clear *//*_#IS_A__L35*/ meltfnum[16] = 0;
	}
	;
      }				/*noelse */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6045:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L40*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6045:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L40*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L41*/ meltfnum[24] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6045:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L41*/ meltfnum[24];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6045;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list appending nbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V34*/ meltfptr[33];
	      /*_.MELT_DEBUG_FUN__V73*/ meltfptr[49] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V72*/ meltfptr[47] =
	      /*_.MELT_DEBUG_FUN__V73*/ meltfptr[49];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6045:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L41*/ meltfnum[24] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V73*/ meltfptr[49] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V72*/ meltfptr[47] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6045:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L40*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V72*/ meltfptr[47] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6046:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V34*/ meltfptr[33];
      /*_.LIST_APPEND2LIST__V74*/ meltfptr[56] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[11])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6047:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L42*/ meltfnum[16] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6047:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L42*/ meltfnum[16])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L43*/ meltfnum[24] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6047:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L43*/ meltfnum[24];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6047;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_list ended updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V76*/ meltfptr[54] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V75*/ meltfptr[53] =
	      /*_.MELT_DEBUG_FUN__V76*/ meltfptr[54];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6047:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L43*/ meltfnum[24] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V76*/ meltfptr[54] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V75*/ meltfptr[53] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6047:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L42*/ meltfnum[16] = 0;
      /*^clear */
	     /*clear *//*_._IF___V75*/ meltfptr[53] = 0;
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

    MELT_LOCATION ("warmelt-normal.melt:6001:/ clear");
	   /*clear *//*_.IFCPP___V37*/ meltfptr[35] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V39*/ meltfptr[34] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L34*/ meltfnum[17] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V74*/ meltfptr[56] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V34*/ meltfptr[33] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5985:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V14*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.CONSLIBIND__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NLOCSYMS__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.FIRSTPAIRBIND__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.LASTPAIRBIND__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V25*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V29*/ meltfptr[27] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V31*/ meltfptr[22] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5979:/ clear");
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[7] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_109_WARMELTmiNORMAL_NORMLETREC_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE_melt
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

  struct meltframe_meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE_st
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
#define MELTFRAM_NBVARNUM 8
    long mcfr_varnum[8];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE_st *)
	meltfirstargp_;
      /* use arguments meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE nbval 25*/
  meltfram__.mcfr_nbvar = 25 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_INSTANCE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6053:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6054:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6054:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6054:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6054;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_instance recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6054:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6054:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6055:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_INSTANCE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6055:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6055:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6055) ? (6055) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6055:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6056:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6057:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_LOCATED */
						       meltfrout->tabval[2])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOC__V11*/ meltfptr[10] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V11*/ meltfptr[10] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6058:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_INSTANCE */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 2, "SMINS_CLASS");
   /*_.CLA__V12*/ meltfptr[11] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLA__V12*/ meltfptr[11] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6059:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.RECV__V2*/ meltfptr[1]),
					(melt_ptr_t) (( /*!CLASS_SOURCE_INSTANCE */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "SMINS_CLABIND");
   /*_.CLABIND__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLABIND__V13*/ meltfptr[12] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L4*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CLABIND__V13*/ meltfptr[12]),
			   (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->
					  tabval[3])));;
    MELT_LOCATION ("warmelt-normal.melt:6060:/ cond");
    /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CLABIND__V13*/ meltfptr[12]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
    /*_.BINDER__V15*/ meltfptr[14] = slot;
	  };
	  ;
	  /*_.SCLASYM__V14*/ meltfptr[13] = /*_.BINDER__V15*/ meltfptr[14];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6060:/ clear");
	     /*clear *//*_.BINDER__V15*/ meltfptr[14] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.SCLASYM__V14*/ meltfptr[13] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6061:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CLA__V12*/ meltfptr[11]),
					(melt_ptr_t) (( /*!CLASS_CLASS */
						       meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CLA__V12*/ meltfptr[11]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
   /*_.CLASS_FIELDS__V16*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLASS_FIELDS__V16*/ meltfptr[14] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBCLAFLD__L5*/ meltfnum[1] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.CLASS_FIELDS__V16*/ meltfptr[14])));;
    /*^compute */
 /*_.TUPSLOT__V17*/ meltfptr[16] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[5])),
	( /*_#NBCLAFLD__L5*/ meltfnum[1])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6065:/ cond");
    /*cond */ if ( /*_.LOC__V11*/ meltfptr[10])	/*then */
      {
	/*^cond.then */
	/*_.OR___V18*/ meltfptr[17] = /*_.LOC__V11*/ meltfptr[10];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6065:/ cond.else");

	/*_.OR___V18*/ meltfptr[17] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6063:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[6])), (6), "CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING");
  /*_.INST__V20*/ meltfptr[19] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (1),
			  ( /*_.OR___V18*/ meltfptr[17]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (2),
			  (( /*nil */ NULL)), "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NINSTB_SLOTS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (4),
			  ( /*_.TUPSLOT__V17*/ meltfptr[16]), "NINSTB_SLOTS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NINSTB_CLABIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (5),
			  ( /*_.CLABIND__V13*/ meltfptr[12]),
			  "NINSTB_CLABIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
				  "newly made instance");
    ;
    /*_.CONSINST__V19*/ meltfptr[18] = /*_.INST__V20*/ meltfptr[19];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6071:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[5] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CLA__V12*/ meltfptr[11]),
			     (melt_ptr_t) (( /*!CLASS_CLASS */ meltfrout->
					    tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:6071:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[5])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V22*/ meltfptr[21] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6071:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("prepcons_instance check class"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6071) ? (6071) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V21*/ meltfptr[20] = /*_._IFELSE___V22*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6071:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V22*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V21*/ meltfptr[20] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6072:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L7*/ meltfnum[5] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6072:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L7*/ meltfnum[5])	/*then */
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
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6072:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6072;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_instance gives consinst";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSINST__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V23*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6072:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V23*/ meltfptr[21] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6072:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IF___V23*/ meltfptr[21] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6073:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSINST__V19*/ meltfptr[18];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6073:/ locexp");
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
    /*_.LET___V10*/ meltfptr[5] = /*_.RETURN___V25*/ meltfptr[23];;

    MELT_LOCATION ("warmelt-normal.melt:6056:/ clear");
	   /*clear *//*_.LOC__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.CLA__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.CLABIND__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.SCLASYM__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.CLASS_FIELDS__V16*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_#NBCLAFLD__L5*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_.TUPSLOT__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.OR___V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CONSINST__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V25*/ meltfptr[23] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6053:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V10*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6053:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V10*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_INSTANCE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_110_WARMELTmiNORMAL_PREPCONS_INSTANCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE_melt
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

  struct meltframe_meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE_st
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
#define MELTFRAM_NBVARPTR 46
    melt_ptr_t mcfr_varptr[46];
#define MELTFRAM_NBVARNUM 18
    long mcfr_varnum[18];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 46; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE nbval 46*/
  meltfram__.mcfr_nbvar = 46 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_INSTANCE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6080:/ getarg");
 /*_.CEXPR__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SYMB__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SYMB__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.CBIND__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4])) != NULL);


  /*getarg#4 */
  /*^getarg */
  if (meltxargdescr_[3] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V6*/ meltfptr[5] =
    (meltxargtab_[3].meltbp_aptr) ? (*(meltxargtab_[3].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5])) != NULL);


  /*getarg#5 */
  /*^getarg */
  if (meltxargdescr_[4] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V7*/ meltfptr[6] =
    (meltxargtab_[4].meltbp_aptr) ? (*(meltxargtab_[4].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6081:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6081:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6081:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6081;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance cexpr=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CEXPR__V2*/ meltfptr[1];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " symb=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V3*/ meltfptr[2];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " cbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V8*/ meltfptr[7] =
	      /*_.MELT_DEBUG_FUN__V9*/ meltfptr[8];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6081:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V9*/ meltfptr[8] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V8*/ meltfptr[7] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6081:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V8*/ meltfptr[7] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6082:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V10*/ meltfptr[8] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V10*/ meltfptr[8])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V11*/ meltfptr[7] = /*_.LOCA_LOCATION__V10*/ meltfptr[8];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6082:/ cond.else");

	/*_.LOC__V11*/ meltfptr[7] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6083:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CBIND__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 4, "NINSTB_SLOTS");
   /*_.BSLOTS__V12*/ meltfptr[11] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BSLOTS__V12*/ meltfptr[11] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6084:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CBIND__V4*/ meltfptr[3]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[2])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NCONSB_NLETREC");
   /*_.NLETREC__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V13*/ meltfptr[12] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6085:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V13*/ meltfptr[12]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V13*/ meltfptr[12]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V14*/ meltfptr[13] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V14*/ meltfptr[13] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6086:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SMINS_CLASS");
  /*_.SCLASS__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6087:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SMINS_CLABIND");
  /*_.SCLABIND__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6088:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 4, "SMINS_FIELDS");
  /*_.SFIELDS__V17*/ meltfptr[16] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_A__L3*/ meltfnum[1] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SCLABIND__V16*/ meltfptr[15]),
			   (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->
					  tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:6089:/ cond");
    /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SCLABIND__V16*/ meltfptr[15]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
    /*_.BINDER__V19*/ meltfptr[18] = slot;
	  };
	  ;
	  /*_.SCLASYM__V18*/ meltfptr[17] = /*_.BINDER__V19*/ meltfptr[18];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6089:/ clear");
	     /*clear *//*_.BINDER__V19*/ meltfptr[18] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.SCLASYM__V18*/ meltfptr[17] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L4*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SCLASYM__V18*/ meltfptr[17]),
			   (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					  tabval[5])));;
    MELT_LOCATION ("warmelt-normal.melt:6090:/ cond");
    /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6091:/ msend");
	  /*msend */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];
	    /*^ojbmsend.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];
	    /*^ojbmsend.arg */
	    argtab[2].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V7*/ meltfptr[6];
	    /*_.NORMAL_EXP__V21*/ meltfptr[20] =
	      meltgc_send ((melt_ptr_t) ( /*_.SCLASYM__V18*/ meltfptr[17]),
			   (melt_ptr_t) (( /*!NORMAL_EXP */ meltfrout->
					  tabval[6])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  /*_.CLADATA__V20*/ meltfptr[18] =
	    /*_.NORMAL_EXP__V21*/ meltfptr[20];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6090:/ clear");
	     /*clear *//*_.NORMAL_EXP__V21*/ meltfptr[20] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.CLADATA__V20*/ meltfptr[18] = NULL;;
      }
    ;
    /*^compute */
 /*_.BINDLIST__V22*/ meltfptr[20] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[7]))));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6094:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L5*/ meltfnum[4] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6094:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L5*/ meltfnum[4])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L6*/ meltfnum[5] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6094:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6094;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V13*/ meltfptr[12];
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V23*/ meltfptr[22] =
	      /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6094:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V23*/ meltfptr[22] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6094:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[4] = 0;
      /*^clear */
	     /*clear *//*_._IF___V23*/ meltfptr[22] = 0;
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
 /*_#IS_A__L7*/ meltfnum[5] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CLADATA__V20*/ meltfptr[18]),
			   (melt_ptr_t) (( /*!CLASS_NREP */ meltfrout->
					  tabval[8])));;
    /*^compute */
 /*_#NOT__L8*/ meltfnum[4] =
      (!( /*_#IS_A__L7*/ meltfnum[5]));;
    MELT_LOCATION ("warmelt-normal.melt:6095:/ cond");
    /*cond */ if ( /*_#NOT__L8*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6097:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SCLASS__V15*/ meltfptr[14]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.NAMED_NAME__V26*/ meltfptr[22] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
			    ("invalid class in (INSTANCE ..)"),
			    (melt_ptr_t) ( /*_.NAMED_NAME__V26*/
					  meltfptr[22]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6098:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = ( /*nil */ NULL);;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6098:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6096:/ quasiblock");


	  /*_.PROGN___V28*/ meltfptr[27] = /*_.RETURN___V27*/ meltfptr[26];;
	  /*^compute */
	  /*_._IF___V25*/ meltfptr[23] = /*_.PROGN___V28*/ meltfptr[27];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6095:/ clear");
	     /*clear *//*_.NAMED_NAME__V26*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V27*/ meltfptr[26] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V28*/ meltfptr[27] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V25*/ meltfptr[23] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6099:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6102:/ quasiblock");


    /*^newclosure */
		 /*newclosure *//*_.LAMBDA___V30*/ meltfptr[26] =
      (melt_ptr_t)
      meltgc_new_closure ((meltobject_ptr_t)
			  (((melt_ptr_t) (MELT_PREDEF (DISCR_CLOSURE)))),
			  (meltroutine_ptr_t) (( /*!konst_15 */ meltfrout->
						tabval[15])), (4));
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V30*/ meltfptr[26])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 0 >= 0
		    && 0 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V30*/ meltfptr[26])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V30*/ meltfptr[26])->tabval[0] =
      (melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V30*/ meltfptr[26])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 1 >= 0
		    && 1 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V30*/ meltfptr[26])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V30*/ meltfptr[26])->tabval[1] =
      (melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V30*/ meltfptr[26])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 2 >= 0
		    && 2 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V30*/ meltfptr[26])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V30*/ meltfptr[26])->tabval[2] =
      (melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V30*/ meltfptr[26])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 3 >= 0
		    && 3 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V30*/ meltfptr[26])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V30*/ meltfptr[26])->tabval[3] =
      (melt_ptr_t) ( /*_.BINDLIST__V22*/ meltfptr[20]);
    ;
    /*_.LAMBDA___V29*/ meltfptr[22] = /*_.LAMBDA___V30*/ meltfptr[26];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6100:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.LAMBDA___V29*/ meltfptr[22];
      /*_.NFIELDS__V31*/ meltfptr[27] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!MULTIPLE_MAP */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.SFIELDS__V17*/ meltfptr[16]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6120:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L9*/ meltfnum[8] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6120:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[8])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[9] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6120:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6120;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nfields";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NFIELDS__V31*/ meltfptr[27];
	      /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V32*/ meltfptr[31] =
	      /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6120:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V33*/ meltfptr[32] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V32*/ meltfptr[31] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6120:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V32*/ meltfptr[31] = 0;
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
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NFIELDS__V31*/ meltfptr[27]);
      for ( /*_#FLDIX__L11*/ meltfnum[9] = 0;
	   ( /*_#FLDIX__L11*/ meltfnum[9] >= 0)
	   && ( /*_#FLDIX__L11*/ meltfnum[9] < meltcit1__EACHTUP_ln);
	/*_#FLDIX__L11*/ meltfnum[9]++)
	{
	  /*_.CURNFIELDASS__V34*/ meltfptr[32] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.NFIELDS__V31*/ meltfptr[27]),
			       /*_#FLDIX__L11*/ meltfnum[9]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6124:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L12*/ meltfnum[8] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6124:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L12*/ meltfnum[8])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L13*/ meltfnum[12] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6124:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L13*/ meltfnum[12];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6124;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_instance curnfieldass";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURNFIELDASS__V34*/ meltfptr[32];
		    /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] =
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
		  /*_._IF___V35*/ meltfptr[31] =
		    /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6124:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[12] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V35*/ meltfptr[31] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6124:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[8] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V35*/ meltfptr[31] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6125:/ quasiblock");


	  /*^cond */
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V34*/
					       meltfptr[32]),
					      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */ meltfrout->tabval[16])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V34*/ meltfptr[32])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NFLA_FIELD");
    /*_.CURFIELD__V37*/ meltfptr[35] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFIELD__V37*/ meltfptr[35] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6126:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V34*/
					       meltfptr[32]),
					      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */ meltfrout->tabval[16])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V34*/ meltfptr[32])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 2, "NFLA_VAL");
    /*_.CURFVAL__V38*/ meltfptr[31] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFVAL__V38*/ meltfptr[31] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6127:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V34*/
					       meltfptr[32]),
					      (melt_ptr_t) (( /*!CLASS_NREP */
							     meltfrout->
							     tabval[8])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V34*/ meltfptr[32])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 0, "NREP_LOC");
    /*_.CURFLOC__V39*/ meltfptr[38] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFLOC__V39*/ meltfptr[38] = NULL;;
	    }
	  ;
	  /*^compute */
  /*_#CURFOFF__L14*/ meltfnum[12] =
	    (melt_get_int
	     ((melt_ptr_t) ( /*_.CURFIELD__V37*/ meltfptr[35])));;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6130:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L15*/ meltfnum[8] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURFIELD__V37*/ meltfptr[35]),
				   (melt_ptr_t) (( /*!CLASS_FIELD */
						  meltfrout->tabval[17])));;
	    MELT_LOCATION ("warmelt-normal.melt:6130:/ cond");
	    /*cond */ if ( /*_#IS_A__L15*/ meltfnum[8])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V41*/ meltfptr[40] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6130:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curfield "),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6130) ? (6130) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V41*/ meltfptr[40] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V40*/ meltfptr[39] =
	      /*_._IFELSE___V41*/ meltfptr[40];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6130:/ clear");
	      /*clear *//*_#IS_A__L15*/ meltfnum[8] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V41*/ meltfptr[40] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V40*/ meltfptr[39] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6131:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^msend */
	  /*msend */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];
	    /*_.FCTYP__V42*/ meltfptr[40] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURFVAL__V38*/ meltfptr[31]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[18])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#exeq__L16*/ meltfnum[8] =
	    (( /*_.FCTYP__V42*/ meltfptr[40]) !=
	     (( /*!CTYPE_VALUE */ meltfrout->tabval[19])));;
	  MELT_LOCATION ("warmelt-normal.melt:6133:/ cond");
	  /*cond */ if ( /*_#exeq__L16*/ meltfnum[8])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6137:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURFIELD__V37*/
						     meltfptr[35]),
						    (melt_ptr_t) (( /*!CLASS_NAMED */ meltfrout->tabval[20])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CURFIELD__V37*/ meltfptr[35])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 1, "NAMED_NAME");
      /*_.NAMED_NAME__V43*/ meltfptr[42] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.NAMED_NAME__V43*/ meltfptr[42] = NULL;;
		  }
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:6134:/ locexp");
		  melt_error_str ((melt_ptr_t)
				  ( /*_.CURFLOC__V39*/ meltfptr[38]),
				  ("invalid field type in (LETREC .. (INSTANCE ..); expecting a :value"),
				  (melt_ptr_t) ( /*_.NAMED_NAME__V43*/
						meltfptr[42]));
		}
		;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6133:/ clear");
	      /*clear *//*_.NAMED_NAME__V43*/ meltfptr[42] = 0;
	      }
	      ;
	    }			/*noelse */
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6131:/ clear");
	    /*clear *//*_.FCTYP__V42*/ meltfptr[40] = 0;
	  /*^clear */
	    /*clear *//*_#exeq__L16*/ meltfnum[8] = 0;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6138:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.BSLOTS__V12*/ meltfptr[11]),
				     ( /*_#CURFOFF__L14*/ meltfnum[12]),
				     (melt_ptr_t) ( /*_.CURFVAL__V38*/
						   meltfptr[31]));
	  }
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6125:/ clear");
	    /*clear *//*_.CURFIELD__V37*/ meltfptr[35] = 0;
	  /*^clear */
	    /*clear *//*_.CURFVAL__V38*/ meltfptr[31] = 0;
	  /*^clear */
	    /*clear *//*_.CURFLOC__V39*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_#CURFOFF__L14*/ meltfnum[12] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V40*/ meltfptr[39] = 0;
	  if ( /*_#FLDIX__L11*/ meltfnum[9] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6121:/ clear");
	    /*clear *//*_.CURNFIELDASS__V34*/ meltfptr[32] = 0;
      /*^clear */
	    /*clear *//*_#FLDIX__L11*/ meltfnum[9] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6140:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.BINDLIST__V22*/ meltfptr[20];
      /*_.LIST_APPEND2LIST__V44*/ meltfptr[42] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[21])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V14*/ meltfptr[13]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6141:/ cppif.then");
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
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6141:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[8])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L18*/ meltfnum[12] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6141:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[12];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6141;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_instance ended updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V14*/ meltfptr[13];
	      /*_.MELT_DEBUG_FUN__V46*/ meltfptr[35] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V45*/ meltfptr[40] =
	      /*_.MELT_DEBUG_FUN__V46*/ meltfptr[35];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6141:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[12] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V46*/ meltfptr[35] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V45*/ meltfptr[40] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6141:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V45*/ meltfptr[40] = 0;
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

    MELT_LOCATION ("warmelt-normal.melt:6099:/ clear");
	   /*clear *//*_.LAMBDA___V29*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.NFIELDS__V31*/ meltfptr[27] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V44*/ meltfptr[42] = 0;

    MELT_LOCATION ("warmelt-normal.melt:6082:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V11*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.BSLOTS__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.SCLASS__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.SCLABIND__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.SFIELDS__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_.SCLASYM__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.CLADATA__V20*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.BINDLIST__V22*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L7*/ meltfnum[5] = 0;
    /*^clear */
	   /*clear *//*_#NOT__L8*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IF___V25*/ meltfptr[23] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_INSTANCE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_111_WARMELTmiNORMAL_NORMLETREC_INSTANCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un * meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32_melt =
    melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
  static long melt_call_counter__;
  long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif

  struct meltframe_meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32_st
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
#define MELTFRAM_NBVARPTR 20
    melt_ptr_t mcfr_varptr[20];
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32_st *)
	meltfirstargp_;
      /* use arguments meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 20; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 nbval 20*/
  meltfram__.mcfr_nbvar = 20 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl32", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6102:/ getarg");
 /*_.CURFLDA__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_LONG)
    goto meltlab_endgetargs;
 /*_#CURK__L1*/ meltfnum[0] = meltxargtab_[0].meltbp_long;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6103:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_FIELDASSIGN */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6103:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V4*/ meltfptr[3] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6103:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check curflda"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6103) ? (6103) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V4*/ meltfptr[3] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V3*/ meltfptr[2] = /*_._IFELSE___V4*/ meltfptr[3];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6103:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V3*/ meltfptr[2] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6104:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.CURFLOC__V6*/ meltfptr[5] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6105:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SFLA_FIELD");
  /*_.CURFIELD__V7*/ meltfptr[6] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6106:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SFLA_EXPR");
  /*_.CUREXP__V8*/ meltfptr[7] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#NULL__L3*/ meltfnum[1] =
      (( /*_.CURFLOC__V6*/ meltfptr[5]) == NULL);;
    MELT_LOCATION ("warmelt-normal.melt:6107:/ cond");
    /*cond */ if ( /*_#NULL__L3*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^compute */
	  /*_.CURFLOC__V6*/ meltfptr[5] = /*_.SETQ___V10*/ meltfptr[9] =
	    ( /*~SLOC */ meltfclos->tabval[0]);;
	  /*_._IF___V9*/ meltfptr[8] = /*_.SETQ___V10*/ meltfptr[9];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6107:/ clear");
	     /*clear *//*_.SETQ___V10*/ meltfptr[9] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V9*/ meltfptr[8] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6108:/ quasiblock");


    /*^multimsend */
    /*multimsend */
    {
      union meltparam_un argtab[3];
      union meltparam_un restab[1];
      memset (&argtab, 0, sizeof (argtab));
      memset (&restab, 0, sizeof (restab));
      /*^multimsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & ( /*~ENV */ meltfclos->tabval[1]);	/*^multimsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & ( /*~NCX */ meltfclos->tabval[2]);	/*^multimsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.CURFLOC__V6*/ meltfptr[5];
      /*^multimsend.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBIND__V13*/ meltfptr[12];	/*^multimsend.send */
      /*_.NEXP__V12*/ meltfptr[11] =
	meltgc_send ((melt_ptr_t) ( /*_.CUREXP__V8*/ meltfptr[7]),
		     ((melt_ptr_t)
		      (( /*!NORMAL_EXP */ meltfrout->tabval[1]))),
		     (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		     argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6111:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[3] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6111:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[3])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6111:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6111;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nexp";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXP__V12*/ meltfptr[11];
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[2])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V14*/ meltfptr[13] =
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6111:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V14*/ meltfptr[13] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6111:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[3] = 0;
      /*^clear */
	     /*clear *//*_._IF___V14*/ meltfptr[13] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6112:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L6*/ meltfnum[4] =
	(( /*_.NBIND__V13*/ meltfptr[12]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBIND__V13*/ meltfptr[12])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6112:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L6*/ meltfnum[4])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V17*/ meltfptr[13] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6112:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6112) ? (6112) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V17*/ meltfptr[13] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V16*/ meltfptr[14] = /*_._IFELSE___V17*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6112:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L6*/ meltfnum[4] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V17*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V16*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6113:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBIND__V13*/ meltfptr[12];
      /*_.LIST_APPEND2LIST__V18*/ meltfptr[13] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[3])),
		    (melt_ptr_t) (( /*~BINDLIST */ meltfclos->tabval[3])),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6114:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */
					     meltfrout->tabval[4])), (3),
			      "CLASS_NREP_FIELDASSIGN");
  /*_.INST__V20*/ meltfptr[19] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (0),
			  ( /*_.CURFLOC__V6*/ meltfptr[5]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NFLA_FIELD",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (1),
			  ( /*_.CURFIELD__V7*/ meltfptr[6]), "NFLA_FIELD");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NFLA_VAL",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (2),
			  ( /*_.NEXP__V12*/ meltfptr[11]), "NFLA_VAL");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
				  "newly made instance");
    ;
    /*_.INST___V19*/ meltfptr[18] = /*_.INST__V20*/ meltfptr[19];;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
    /*_.MULTI___V11*/ meltfptr[9] = /*_.INST___V19*/ meltfptr[18];;

    MELT_LOCATION ("warmelt-normal.melt:6108:/ clear");
	   /*clear *//*_.IFCPP___V16*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V18*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.INST___V19*/ meltfptr[18] = 0;

    /*^clear */
	   /*clear *//*_.NBIND__V13*/ meltfptr[12] = 0;
    /*_.LET___V5*/ meltfptr[3] = /*_.MULTI___V11*/ meltfptr[9];;

    MELT_LOCATION ("warmelt-normal.melt:6104:/ clear");
	   /*clear *//*_.CURFLOC__V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.CURFIELD__V7*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.CUREXP__V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_#NULL__L3*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V11*/ meltfptr[9] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6102:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V5*/ meltfptr[3];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6102:/ locexp");
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
	   /*clear *//*_.IFCPP___V3*/ meltfptr[2] = 0;
    /*^clear */
	   /*clear *//*_.LET___V5*/ meltfptr[3] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("LAMBDA_cl32", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_112_WARMELTmiNORMAL_LAMBDA_cl32 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC_melt
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

  struct meltframe_meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC_st
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
#define MELTFRAM_NBVARPTR 153
    melt_ptr_t mcfr_varptr[153];
#define MELTFRAM_NBVARNUM 72
    long mcfr_varnum[72];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC_st *)
	meltfirstargp_;
      /* use arguments meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 153; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC nbval 153*/
  meltfram__.mcfr_nbvar = 153 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_LETREC", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6149:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6150:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6150:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6150:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check letrec recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6150) ? (6150) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_._IFELSE___V7*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6150:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V7*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6151:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6151:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6151:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6151) ? (6151) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6151:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6152:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6152:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6152:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6152) ? (6152) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6152:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6153:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6153:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[4] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6153:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6153;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V12*/ meltfptr[10] =
	      /*_.MELT_DEBUG_FUN__V13*/ meltfptr[12];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6153:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V13*/ meltfptr[12] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V12*/ meltfptr[10] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6153:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V12*/ meltfptr[10] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6154:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[10] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6155:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SLET_BINDINGS");
  /*_.SBINDS__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6156:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SLET_BODY");
  /*_.SBODY__V17*/ meltfptr[16] = slot;
    };
    ;
 /*_#NBBIND__L6*/ meltfnum[4] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.SBINDS__V16*/ meltfptr[15])));;
    /*^compute */
 /*_.BINDLIST__V18*/ meltfptr[17] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;
    /*^compute */
 /*_.CONSBINDLIST__V19*/ meltfptr[18] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6160:/ apply");
    /*apply */
    {
      /*_.NEWENV__V20*/ meltfptr[19] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!FRESH_ENV */ meltfrout->tabval[5])),
		    (melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;
 /*_#stI__L7*/ meltfnum[0] =
      (( /*_#NBBIND__L6*/ meltfnum[4]) * (2));;
    /*^compute */
 /*_#MAPLEN__L8*/ meltfnum[7] =
      ((5) + ( /*_#stI__L7*/ meltfnum[0]));;
    /*^compute */
 /*_.SYMBEXPRMAP__V21*/ meltfptr[20] =
      (meltgc_new_mapobjects
       ((meltobject_ptr_t) (( /*!DISCR_MAP_OBJECTS */ meltfrout->tabval[6])),
	( /*_#MAPLEN__L8*/ meltfnum[7])));;
    /*^compute */
 /*_.SYMBINDMAP__V22*/ meltfptr[21] =
      (meltgc_new_mapobjects
       ((meltobject_ptr_t) (( /*!DISCR_MAP_OBJECTS */ meltfrout->tabval[6])),
	( /*_#MAPLEN__L8*/ meltfnum[7])));;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.SBINDS__V16*/ meltfptr[15]);
      for ( /*_#SBIX__L9*/ meltfnum[8] = 0;
	   ( /*_#SBIX__L9*/ meltfnum[8] >= 0)
	   && ( /*_#SBIX__L9*/ meltfnum[8] < meltcit1__EACHTUP_ln);
	/*_#SBIX__L9*/ meltfnum[8]++)
	{
	  /*_.CURSBIND__V23*/ meltfptr[22] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.SBINDS__V16*/ meltfptr[15]),
			       /*_#SBIX__L9*/ meltfnum[8]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6169:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L10*/ meltfnum[9] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6169:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L11*/ meltfnum[10] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6169:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L11*/ meltfnum[10];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6169;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec cursbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSBIND__V23*/ meltfptr[22];
		    /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V24*/ meltfptr[23] =
		    /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6169:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V25*/ meltfptr[24] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V24*/ meltfptr[23] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6169:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V24*/ meltfptr[23] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6170:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L12*/ meltfnum[10] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSBIND__V23*/ meltfptr[22]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC_BINDING */ meltfrout->tabval[7])));;
	    MELT_LOCATION ("warmelt-normal.melt:6170:/ cond");
	    /*cond */ if ( /*_#IS_A__L12*/ meltfnum[10])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V27*/ meltfptr[23] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6170:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6170) ? (6170) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V27*/ meltfptr[23] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V26*/ meltfptr[24] =
	      /*_._IFELSE___V27*/ meltfptr[23];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6170:/ clear");
	      /*clear *//*_#IS_A__L12*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V27*/ meltfptr[23] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V26*/ meltfptr[24] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6171:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V23*/ meltfptr[22]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V29*/ meltfptr[28] = slot;
	  };
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.LOCA_LOCATION__V29*/ meltfptr[28])	/*then */
	    {
	      /*^cond.then */
	      /*_.LOCB__V30*/ meltfptr[29] =
		/*_.LOCA_LOCATION__V29*/ meltfptr[28];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6171:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V15*/ meltfptr[10])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V31*/ meltfptr[30] =
		      /*_.SLOC__V15*/ meltfptr[10];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6171:/ cond.else");

		    /*_.OR___V31*/ meltfptr[30] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.LOCB__V30*/ meltfptr[29] = /*_.OR___V31*/ meltfptr[30];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6171:/ clear");
	      /*clear *//*_.OR___V31*/ meltfptr[30] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6172:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V23*/ meltfptr[22]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 3, "SLETB_BINDER");
   /*_.CURSYMB__V32*/ meltfptr[30] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6173:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V23*/ meltfptr[22]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "SLETB_EXPR");
   /*_.CUREXPR__V33*/ meltfptr[32] = slot;
	  };
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6175:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L13*/ meltfnum[9] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6175:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L13*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L14*/ meltfnum[10] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6175:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[7];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L14*/ meltfnum[10];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6175;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curexpr=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V33*/ meltfptr[32];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " cursymb=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSYMB__V32*/ meltfptr[30];
		    /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V34*/ meltfptr[33] =
		    /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6175:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L14*/ meltfnum[10] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V35*/ meltfptr[34] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V34*/ meltfptr[33] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6175:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L13*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V34*/ meltfptr[33] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6176:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L15*/ meltfnum[10] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CUREXPR__V33*/ meltfptr[32]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE */
						  meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:6176:/ cond");
	    /*cond */ if ( /*_#IS_A__L15*/ meltfnum[10])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V37*/ meltfptr[33] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6176:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curexpr"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6176) ? (6176) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V37*/ meltfptr[33] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V36*/ meltfptr[34] =
	      /*_._IFELSE___V37*/ meltfptr[33];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6176:/ clear");
	      /*clear *//*_#IS_A__L15*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V37*/ meltfptr[33] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V36*/ meltfptr[34] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6177:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L16*/ meltfnum[9] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSYMB__V32*/ meltfptr[30]),
				   (melt_ptr_t) (( /*!CLASS_SYMBOL */
						  meltfrout->tabval[9])));;
	    MELT_LOCATION ("warmelt-normal.melt:6177:/ cond");
	    /*cond */ if ( /*_#IS_A__L16*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V39*/ meltfptr[38] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6177:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursymb"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6177) ? (6177) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V39*/ meltfptr[38] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V38*/ meltfptr[33] =
	      /*_._IFELSE___V39*/ meltfptr[38];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6177:/ clear");
	      /*clear *//*_#IS_A__L16*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V39*/ meltfptr[38] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V38*/ meltfptr[33] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6178:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.SYMBEXPRMAP__V21*/ meltfptr[20]),
				   (meltobject_ptr_t) ( /*_.CURSYMB__V32*/
						       meltfptr[30]),
				   (melt_ptr_t) ( /*_.CUREXPR__V33*/
						 meltfptr[32]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6179:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^msend */
	  /*msend */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURSYMB__V32*/ meltfptr[30];
	    /*^ojbmsend.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^ojbmsend.arg */
	    argtab[2].meltbp_aptr =
	      (melt_ptr_t *) & /*_.LOCB__V30*/ meltfptr[29];
	    /*_.CURCONSBIND__V41*/ meltfptr[40] =
	      meltgc_send ((melt_ptr_t) ( /*_.CUREXPR__V33*/ meltfptr[32]),
			   (melt_ptr_t) (( /*!PREPARE_CONSTRUCTOR_BINDING */
					  meltfrout->tabval[10])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6181:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L17*/ meltfnum[10] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6181:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L17*/ meltfnum[10])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L18*/ meltfnum[9] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6181:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L18*/ meltfnum[9];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6181;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curconsbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCONSBIND__V41*/ meltfptr[40];
		    /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V42*/ meltfptr[41] =
		    /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6181:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V43*/ meltfptr[42] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V42*/ meltfptr[41] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6181:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V42*/ meltfptr[41] = 0;
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
  /*_#IS_A__L19*/ meltfnum[9] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.CURCONSBIND__V41*/ meltfptr[40]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
	  MELT_LOCATION ("warmelt-normal.melt:6182:/ cond");
	  /*cond */ if ( /*_#IS_A__L19*/ meltfnum[9])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6183:/ cppif.then");
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
      /*_#MELT_NEED_DBG__L20*/ meltfnum[10] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:6183:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L20*/ meltfnum[10])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	/*_#MELT_CALLCOUNT__L21*/ meltfnum[20] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:6183:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L21*/ meltfnum[20];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 6183;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_letrec curconsbind plain consbind";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURCONSBIND__V41*/
			    meltfptr[40];
			  /*_.MELT_DEBUG_FUN__V46*/ meltfptr[45] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[3])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V45*/ meltfptr[41] =
			  /*_.MELT_DEBUG_FUN__V46*/ meltfptr[45];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6183:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L21*/ meltfnum[20] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V46*/ meltfptr[45] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V45*/ meltfptr[41] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:6183:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		/*clear *//*_#MELT_NEED_DBG__L20*/ meltfnum[10] = 0;
		  /*^clear */
		/*clear *//*_._IF___V45*/ meltfptr[41] = 0;
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

		{
		  MELT_LOCATION ("warmelt-normal.melt:6184:/ locexp");
		  meltgc_append_list ((melt_ptr_t)
				      ( /*_.CONSBINDLIST__V19*/ meltfptr[18]),
				      (melt_ptr_t) ( /*_.CURCONSBIND__V41*/
						    meltfptr[40]));
		}
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:6185:/ locexp");
		  meltgc_put_mapobjects ((meltmapobjects_ptr_t)
					 ( /*_.SYMBINDMAP__V22*/
					  meltfptr[21]),
					 (meltobject_ptr_t) ( /*_.CURSYMB__V32*/ meltfptr[30]),
					 (melt_ptr_t) ( /*_.CURCONSBIND__V41*/
						       meltfptr[40]));
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:6182:/ quasiblock");


		/*epilog */
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

	      /*^block */
	      /*anyblock */
	      {


		MELT_CHECK_SIGNAL ();
		;
    /*_#IS_MULTIPLE__L22*/ meltfnum[20] =
		  (melt_magic_discr
		   ((melt_ptr_t) ( /*_.CURCONSBIND__V41*/ meltfptr[40])) ==
		   MELTOBMAG_MULTIPLE);;
		MELT_LOCATION ("warmelt-normal.melt:6187:/ cond");
		/*cond */ if ( /*_#IS_MULTIPLE__L22*/ meltfnum[20])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {


#if MELT_HAVE_DEBUG
		      MELT_LOCATION ("warmelt-normal.melt:6188:/ cppif.then");
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
	/*_#MELT_NEED_DBG__L23*/ meltfnum[10] =
			  /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
			  ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
			  0	/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
			  ;;
			MELT_LOCATION ("warmelt-normal.melt:6188:/ cond");
			/*cond */ if ( /*_#MELT_NEED_DBG__L23*/ meltfnum[10])	/*then */
			  {
			    /*^cond.then */
			    /*^block */
			    /*anyblock */
			    {

	  /*_#MELT_CALLCOUNT__L24*/ meltfnum[23] =
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
				("warmelt-normal.melt:6188:/ apply");
			      /*apply */
			      {
				union meltparam_un argtab[5];
				memset (&argtab, 0, sizeof (argtab));
				/*^apply.arg */
				argtab[0].meltbp_long =
				  /*_#MELT_CALLCOUNT__L24*/ meltfnum[23];
				/*^apply.arg */
				argtab[1].meltbp_cstring =
				  "warmelt-normal.melt";
				/*^apply.arg */
				argtab[2].meltbp_long = 6188;
				/*^apply.arg */
				argtab[3].meltbp_cstring =
				  "normexp_letrec curconsbind multiple";
				/*^apply.arg */
				argtab[4].meltbp_aptr =
				  (melt_ptr_t *) & /*_.CURCONSBIND__V41*/
				  meltfptr[40];
				/*_.MELT_DEBUG_FUN__V49*/ meltfptr[48] =
				  melt_apply ((meltclosure_ptr_t)
					      (( /*!MELT_DEBUG_FUN */
						meltfrout->tabval[3])),
					      (melt_ptr_t) (( /*nil */ NULL)),
					      (MELTBPARSTR_LONG
					       MELTBPARSTR_CSTRING
					       MELTBPARSTR_LONG
					       MELTBPARSTR_CSTRING
					       MELTBPARSTR_PTR ""), argtab,
					      "", (union meltparam_un *) 0);
			      }
			      ;
			      /*_._IF___V48*/ meltfptr[41] =
				/*_.MELT_DEBUG_FUN__V49*/ meltfptr[48];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6188:/ clear");
		    /*clear *//*_#MELT_CALLCOUNT__L24*/ meltfnum[23]
				= 0;
			      /*^clear */
		    /*clear *//*_.MELT_DEBUG_FUN__V49*/ meltfptr[48]
				= 0;
			    }
			    ;
			  }
			else
			  {	/*^cond.else */

	 /*_._IF___V48*/ meltfptr[41] = NULL;;
			  }
			;

			{
			  MELT_LOCATION ("warmelt-normal.melt:6188:/ locexp");
			  /*void */ (void) 0;
			}
			;
			/*^quasiblock */


			/*epilog */

			/*^clear */
		  /*clear *//*_#MELT_NEED_DBG__L23*/ meltfnum[10] = 0;
			/*^clear */
		  /*clear *//*_._IF___V48*/ meltfptr[41] = 0;
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
		      /*citerblock FOREACH_IN_MULTIPLE */
		      {
			/* start foreach_in_multiple meltcit2__EACHTUP */
			long meltcit2__EACHTUP_ln =
			  melt_multiple_length ((melt_ptr_t)
						/*_.CURCONSBIND__V41*/
						meltfptr[40]);
			for ( /*_#SUBIX__L25*/ meltfnum[23] = 0;
			     ( /*_#SUBIX__L25*/ meltfnum[23] >= 0)
			     && ( /*_#SUBIX__L25*/ meltfnum[23] <
				 meltcit2__EACHTUP_ln);
	/*_#SUBIX__L25*/ meltfnum[23]++)
			  {
			    /*_.SUBCONSBIND__V50*/ meltfptr[48] =
			      melt_multiple_nth ((melt_ptr_t)
						 ( /*_.CURCONSBIND__V41*/
						  meltfptr[40]),
						 /*_#SUBIX__L25*/
						 meltfnum[23]);




#if MELT_HAVE_DEBUG
			    MELT_LOCATION
			      ("warmelt-normal.melt:6192:/ cppif.then");
			    /*^block */
			    /*anyblock */
			    {


			      MELT_CHECK_SIGNAL ();
			      ;
	 /*_#IS_A__L26*/ meltfnum[10] =
				melt_is_instance_of ((melt_ptr_t)
						     ( /*_.SUBCONSBIND__V50*/
						      meltfptr[48]),
						     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
			      MELT_LOCATION
				("warmelt-normal.melt:6192:/ cond");
			      /*cond */ if ( /*_#IS_A__L26*/ meltfnum[10])	/*then */
				{
				  /*^cond.then */
				  /*_._IFELSE___V52*/ meltfptr[51] =
				    ( /*nil */ NULL);;
				}
			      else
				{
				  MELT_LOCATION
				    ("warmelt-normal.melt:6192:/ cond.else");

				  /*^block */
				  /*anyblock */
				  {




				    {
				      /*^locexp */
				      melt_assert_failed (("normexp_letrec check subconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6192) ? (6192) : __LINE__, __FUNCTION__);
				      ;
				    }
				    ;
		     /*clear *//*_._IFELSE___V52*/ meltfptr[51]
				      = 0;
				    /*epilog */
				  }
				  ;
				}
			      ;
			      /*^compute */
			      /*_.IFCPP___V51*/ meltfptr[41] =
				/*_._IFELSE___V52*/ meltfptr[51];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6192:/ clear");
		   /*clear *//*_#IS_A__L26*/ meltfnum[10] = 0;
			      /*^clear */
		   /*clear *//*_._IFELSE___V52*/ meltfptr[51] = 0;
			    }

#else /*MELT_HAVE_DEBUG */
			    /*^cppif.else */
			    /*_.IFCPP___V51*/ meltfptr[41] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
			    ;

			    {
			      MELT_LOCATION
				("warmelt-normal.melt:6194:/ locexp");
			      meltgc_append_list ((melt_ptr_t)
						  ( /*_.CONSBINDLIST__V19*/
						   meltfptr[18]),
						  (melt_ptr_t) ( /*_.SUBCONSBIND__V50*/ meltfptr[48]));
			    }
			    ;
			    if ( /*_#SUBIX__L25*/ meltfnum[23] < 0)
			      break;
			  }	/* end  foreach_in_multiple meltcit2__EACHTUP */

			/*citerepilog */

			MELT_LOCATION ("warmelt-normal.melt:6189:/ clear");
		 /*clear *//*_.SUBCONSBIND__V50*/ meltfptr[48] = 0;
			/*^clear */
		 /*clear *//*_#SUBIX__L25*/ meltfnum[23] = 0;
			/*^clear */
		 /*clear *//*_.IFCPP___V51*/ meltfptr[41] = 0;
		      }		/*endciterblock FOREACH_IN_MULTIPLE */
		      ;

		      {
			MELT_LOCATION ("warmelt-normal.melt:6195:/ locexp");
			meltgc_put_mapobjects ((meltmapobjects_ptr_t)
					       ( /*_.SYMBINDMAP__V22*/
						meltfptr[21]),
					       (meltobject_ptr_t) ( /*_.CURSYMB__V32*/ meltfptr[30]),
					       (melt_ptr_t) ( /*_.CURCONSBIND__V41*/ meltfptr[40]));
		      }
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6187:/ quasiblock");


		      /*epilog */
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

		    /*^block */
		    /*anyblock */
		    {


		      MELT_CHECK_SIGNAL ();
		      ;
      /*_#IS_LIST__L27*/ meltfnum[10] =
			(melt_magic_discr
			 ((melt_ptr_t) ( /*_.CURCONSBIND__V41*/ meltfptr[40]))
			 == MELTOBMAG_LIST);;
		      MELT_LOCATION ("warmelt-normal.melt:6197:/ cond");
		      /*cond */ if ( /*_#IS_LIST__L27*/ meltfnum[10])	/*then */
			{
			  /*^cond.then */
			  /*^block */
			  /*anyblock */
			  {


#if MELT_HAVE_DEBUG
			    MELT_LOCATION
			      ("warmelt-normal.melt:6198:/ cppif.then");
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
	  /*_#MELT_NEED_DBG__L28*/ meltfnum[27] =
				/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
				( /*melt_need_dbg */
				 melt_need_debug ((int) 0))
#else
				0	/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
				;;
			      MELT_LOCATION
				("warmelt-normal.melt:6198:/ cond");
			      /*cond */ if ( /*_#MELT_NEED_DBG__L28*/ meltfnum[27])	/*then */
				{
				  /*^cond.then */
				  /*^block */
				  /*anyblock */
				  {

	    /*_#MELT_CALLCOUNT__L29*/ meltfnum[28] =
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
				      ("warmelt-normal.melt:6198:/ apply");
				    /*apply */
				    {
				      union meltparam_un argtab[5];
				      memset (&argtab, 0, sizeof (argtab));
				      /*^apply.arg */
				      argtab[0].meltbp_long =
					/*_#MELT_CALLCOUNT__L29*/
					meltfnum[28];
				      /*^apply.arg */
				      argtab[1].meltbp_cstring =
					"warmelt-normal.melt";
				      /*^apply.arg */
				      argtab[2].meltbp_long = 6198;
				      /*^apply.arg */
				      argtab[3].meltbp_cstring =
					"normexp_letrec curconsbind list";
				      /*^apply.arg */
				      argtab[4].meltbp_aptr =
					(melt_ptr_t *) &
					/*_.CURCONSBIND__V41*/ meltfptr[40];
				      /*_.MELT_DEBUG_FUN__V55*/ meltfptr[54] =
					melt_apply ((meltclosure_ptr_t)
						    (( /*!MELT_DEBUG_FUN */
						      meltfrout->tabval[3])),
						    (melt_ptr_t) (( /*nil */
								   NULL)),
						    (MELTBPARSTR_LONG
						     MELTBPARSTR_CSTRING
						     MELTBPARSTR_LONG
						     MELTBPARSTR_CSTRING
						     MELTBPARSTR_PTR ""),
						    argtab, "",
						    (union meltparam_un *) 0);
				    }
				    ;
				    /*_._IF___V54*/ meltfptr[53] =
				      /*_.MELT_DEBUG_FUN__V55*/ meltfptr[54];;
				    /*epilog */

				    MELT_LOCATION
				      ("warmelt-normal.melt:6198:/ clear");
		      /*clear *//*_#MELT_CALLCOUNT__L29*/
				      meltfnum[28] = 0;
				    /*^clear */
		      /*clear *//*_.MELT_DEBUG_FUN__V55*/
				      meltfptr[54] = 0;
				  }
				  ;
				}
			      else
				{	/*^cond.else */

	   /*_._IF___V54*/ meltfptr[53] = NULL;;
				}
			      ;

			      {
				MELT_LOCATION
				  ("warmelt-normal.melt:6198:/ locexp");
				/*void */ (void) 0;
			      }
			      ;
			      /*^quasiblock */


			      /*epilog */

			      /*^clear */
		    /*clear *//*_#MELT_NEED_DBG__L28*/ meltfnum[27]
				= 0;
			      /*^clear */
		    /*clear *//*_._IF___V54*/ meltfptr[53] = 0;
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
			      for ( /*_.SUBCONSPAIR__V56*/ meltfptr[54] =
				   melt_list_first ((melt_ptr_t)
						    /*_.CURCONSBIND__V41*/
						    meltfptr[40]);
				   melt_magic_discr ((melt_ptr_t)
						     /*_.SUBCONSPAIR__V56*/
						     meltfptr[54]) ==
				   MELTOBMAG_PAIR;
				   /*_.SUBCONSPAIR__V56*/ meltfptr[54] =
				   melt_pair_tail ((melt_ptr_t)
						   /*_.SUBCONSPAIR__V56*/
						   meltfptr[54]))
				{
				  /*_.SUBCONSBIND__V57*/ meltfptr[53] =
				    melt_pair_head ((melt_ptr_t)
						    /*_.SUBCONSPAIR__V56*/
						    meltfptr[54]);



#if MELT_HAVE_DEBUG
				  MELT_LOCATION
				    ("warmelt-normal.melt:6202:/ cppif.then");
				  /*^block */
				  /*anyblock */
				  {


				    MELT_CHECK_SIGNAL ();
				    ;
	   /*_#IS_A__L30*/ meltfnum[28] =
				      melt_is_instance_of ((melt_ptr_t)
							   ( /*_.SUBCONSBIND__V57*/ meltfptr[53]), (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
				    MELT_LOCATION
				      ("warmelt-normal.melt:6202:/ cond");
				    /*cond */ if ( /*_#IS_A__L30*/ meltfnum[28])	/*then */
				      {
					/*^cond.then */
					/*_._IFELSE___V59*/ meltfptr[58] =
					  ( /*nil */ NULL);;
				      }
				    else
				      {
					MELT_LOCATION
					  ("warmelt-normal.melt:6202:/ cond.else");

					/*^block */
					/*anyblock */
					{




					  {
					    /*^locexp */
					    melt_assert_failed (("normexp_letrec check subconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6202) ? (6202) : __LINE__, __FUNCTION__);
					    ;
					  }
					  ;
		       /*clear *//*_._IFELSE___V59*/
					    meltfptr[58] = 0;
					  /*epilog */
					}
					;
				      }
				    ;
				    /*^compute */
				    /*_.IFCPP___V58*/ meltfptr[57] =
				      /*_._IFELSE___V59*/ meltfptr[58];;
				    /*epilog */

				    MELT_LOCATION
				      ("warmelt-normal.melt:6202:/ clear");
		     /*clear *//*_#IS_A__L30*/ meltfnum[28] =
				      0;
				    /*^clear */
		     /*clear *//*_._IFELSE___V59*/ meltfptr[58]
				      = 0;
				  }

#else /*MELT_HAVE_DEBUG */
				  /*^cppif.else */
				  /*_.IFCPP___V58*/ meltfptr[57] =
				    ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
				  ;

				  {
				    MELT_LOCATION
				      ("warmelt-normal.melt:6204:/ locexp");
				    meltgc_append_list ((melt_ptr_t)
							( /*_.CONSBINDLIST__V19*/ meltfptr[18]), (melt_ptr_t) ( /*_.SUBCONSBIND__V57*/ meltfptr[53]));
				  }
				  ;
				}	/* end foreach_in_list meltcit3__EACHLIST */
     /*_.SUBCONSPAIR__V56*/ meltfptr[54] = NULL;
     /*_.SUBCONSBIND__V57*/ meltfptr[53] = NULL;


			      /*citerepilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6199:/ clear");
		   /*clear *//*_.SUBCONSPAIR__V56*/ meltfptr[54] =
				0;
			      /*^clear */
		   /*clear *//*_.SUBCONSBIND__V57*/ meltfptr[53] =
				0;
			      /*^clear */
		   /*clear *//*_.IFCPP___V58*/ meltfptr[57] = 0;
			    }	/*endciterblock FOREACH_IN_LIST */
			    ;

			    MELT_CHECK_SIGNAL ();
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6205:/ apply");
			    /*apply */
			    {
			      union meltparam_un argtab[1];
			      memset (&argtab, 0, sizeof (argtab));
			      /*^apply.arg */
			      argtab[0].meltbp_aptr =
				(melt_ptr_t *) & ( /*!DISCR_MULTIPLE */
						  meltfrout->tabval[13]);
			      /*_.LIST_TO_MULTIPLE__V60*/ meltfptr[58] =
				melt_apply ((meltclosure_ptr_t)
					    (( /*!LIST_TO_MULTIPLE */
					      meltfrout->tabval[12])),
					    (melt_ptr_t) ( /*_.CURCONSBIND__V41*/ meltfptr[40]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un *) 0);
			    }
			    ;

			    {
			      /*^locexp */
			      meltgc_put_mapobjects ((meltmapobjects_ptr_t)
						     ( /*_.SYMBINDMAP__V22*/
						      meltfptr[21]),
						     (meltobject_ptr_t) ( /*_.CURSYMB__V32*/ meltfptr[30]),
						     (melt_ptr_t) ( /*_.LIST_TO_MULTIPLE__V60*/ meltfptr[58]));
			    }
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6197:/ quasiblock");


			    /*epilog */

			    /*^clear */
		  /*clear *//*_.LIST_TO_MULTIPLE__V60*/ meltfptr[58]
			      = 0;
			  }
			  ;
			}
		      else
			{	/*^cond.else */

			  /*^block */
			  /*anyblock */
			  {


#if MELT_HAVE_DEBUG
			    MELT_LOCATION
			      ("warmelt-normal.melt:6208:/ cppif.then");
			    /*^block */
			    /*anyblock */
			    {


			      MELT_CHECK_SIGNAL ();
			      ;
			      /*^cond */
			      /*cond */ if (( /*nil */ NULL))	/*then */
				{
				  /*^cond.then */
				  /*_._IFELSE___V62*/ meltfptr[61] =
				    ( /*nil */ NULL);;
				}
			      else
				{
				  MELT_LOCATION
				    ("warmelt-normal.melt:6208:/ cond.else");

				  /*^block */
				  /*anyblock */
				  {




				    {
				      /*^locexp */
				      melt_assert_failed (("normexp_letrec bad curconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6208) ? (6208) : __LINE__, __FUNCTION__);
				      ;
				    }
				    ;
		      /*clear *//*_._IFELSE___V62*/ meltfptr[61]
				      = 0;
				    /*epilog */
				  }
				  ;
				}
			      ;
			      /*^compute */
			      /*_.IFCPP___V61*/ meltfptr[58] =
				/*_._IFELSE___V62*/ meltfptr[61];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6208:/ clear");
		    /*clear *//*_._IFELSE___V62*/ meltfptr[61] = 0;
			    }

#else /*MELT_HAVE_DEBUG */
			    /*^cppif.else */
			    /*_.IFCPP___V61*/ meltfptr[58] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6207:/ quasiblock");


			    /*_.PROGN___V63*/ meltfptr[61] =
			      /*_.IFCPP___V61*/ meltfptr[58];;
			    /*^compute */
			    /*_._IFELSE___V53*/ meltfptr[51] =
			      /*_.PROGN___V63*/ meltfptr[61];;
			    /*epilog */

			    MELT_LOCATION
			      ("warmelt-normal.melt:6197:/ clear");
		  /*clear *//*_.IFCPP___V61*/ meltfptr[58] = 0;
			    /*^clear */
		  /*clear *//*_.PROGN___V63*/ meltfptr[61] = 0;
			  }
			  ;
			}
		      ;
		      /*_._IFELSE___V47*/ meltfptr[45] =
			/*_._IFELSE___V53*/ meltfptr[51];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6187:/ clear");
		/*clear *//*_#IS_LIST__L27*/ meltfnum[10] = 0;
		      /*^clear */
		/*clear *//*_._IFELSE___V53*/ meltfptr[51] = 0;
		    }
		    ;
		  }
		;
		/*_._IFELSE___V44*/ meltfptr[42] =
		  /*_._IFELSE___V47*/ meltfptr[45];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6182:/ clear");
	      /*clear *//*_#IS_MULTIPLE__L22*/ meltfnum[20] = 0;
		/*^clear */
	      /*clear *//*_._IFELSE___V47*/ meltfptr[45] = 0;
	      }
	      ;
	    }
	  ;
	  /*_.LET___V40*/ meltfptr[38] = /*_._IFELSE___V44*/ meltfptr[42];;

	  MELT_LOCATION ("warmelt-normal.melt:6179:/ clear");
	    /*clear *//*_.CURCONSBIND__V41*/ meltfptr[40] = 0;
	  /*^clear */
	    /*clear *//*_#IS_A__L19*/ meltfnum[9] = 0;
	  /*^clear */
	    /*clear *//*_._IFELSE___V44*/ meltfptr[42] = 0;
	  /*_.LET___V28*/ meltfptr[23] = /*_.LET___V40*/ meltfptr[38];;

	  MELT_LOCATION ("warmelt-normal.melt:6171:/ clear");
	    /*clear *//*_.LOCA_LOCATION__V29*/ meltfptr[28] = 0;
	  /*^clear */
	    /*clear *//*_.LOCB__V30*/ meltfptr[29] = 0;
	  /*^clear */
	    /*clear *//*_.CURSYMB__V32*/ meltfptr[30] = 0;
	  /*^clear */
	    /*clear *//*_.CUREXPR__V33*/ meltfptr[32] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V36*/ meltfptr[34] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V38*/ meltfptr[33] = 0;
	  /*^clear */
	    /*clear *//*_.LET___V40*/ meltfptr[38] = 0;
	  if ( /*_#SBIX__L9*/ meltfnum[8] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6166:/ clear");
	    /*clear *//*_.CURSBIND__V23*/ meltfptr[22] = 0;
      /*^clear */
	    /*clear *//*_#SBIX__L9*/ meltfnum[8] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V26*/ meltfptr[24] = 0;
      /*^clear */
	    /*clear *//*_.LET___V28*/ meltfptr[23] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6213:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L31*/ meltfnum[27] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6213:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L31*/ meltfnum[27])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L32*/ meltfnum[28] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6213:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L32*/ meltfnum[28];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6213;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec consbindlist";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSBINDLIST__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V65*/ meltfptr[61] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V64*/ meltfptr[58] =
	      /*_.MELT_DEBUG_FUN__V65*/ meltfptr[61];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6213:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L32*/ meltfnum[28] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V65*/ meltfptr[61] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V64*/ meltfptr[58] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6213:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L31*/ meltfnum[27] = 0;
      /*^clear */
	     /*clear *//*_._IF___V64*/ meltfptr[58] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6214:/ quasiblock");


 /*_#NBCONSBIND__L33*/ meltfnum[10] =
      (melt_list_length
       ((melt_ptr_t) ( /*_.CONSBINDLIST__V19*/ meltfptr[18])));;
    /*^compute */
 /*_#CURCIX__L34*/ meltfnum[20] = 0;;
    /*^compute */
 /*_.NLOCSYMS__V67*/ meltfptr[45] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[13])),
	( /*_#NBCONSBIND__L33*/ meltfnum[10])));;
    /*^compute */
 /*_.NCBINDTUP__V68*/ meltfptr[40] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[13])),
	( /*_#NBCONSBIND__L33*/ meltfnum[10])));;
    /*^compute */
 /*_.RECFILLBINDINGS__V69*/ meltfptr[42] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6220:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					     meltfrout->tabval[14])), (6),
			      "CLASS_NREP_LETREC");
  /*_.INST__V71*/ meltfptr[29] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLET_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (1),
			  ( /*_.NCBINDTUP__V68*/ meltfptr[40]),
			  "NLET_BINDINGS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLETREC_FILL_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (3),
			  ( /*_.RECFILLBINDINGS__V69*/ meltfptr[42]),
			  "NLETREC_FILL_BINDINGS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLETREC_LOCSYMS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (5),
			  ( /*_.NLOCSYMS__V67*/ meltfptr[45]),
			  "NLETREC_LOCSYMS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLET_BODY",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (2),
			  (( /*nil */ NULL)), "NLET_BODY");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NLETREC_BODY_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V71*/ meltfptr[29])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V71*/ meltfptr[29]), (4),
			  (( /*nil */ NULL)), "NLETREC_BODY_BINDINGS");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V71*/ meltfptr[29],
				  "newly made instance");
    ;
    /*_.NLETREC__V70*/ meltfptr[28] = /*_.INST__V71*/ meltfptr[29];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6230:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L35*/ meltfnum[9] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6230:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L35*/ meltfnum[9])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L36*/ meltfnum[28] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6230:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L36*/ meltfnum[28];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6230;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec unfilled nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V70*/ meltfptr[28];
	      /*_.MELT_DEBUG_FUN__V73*/ meltfptr[32] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V72*/ meltfptr[30] =
	      /*_.MELT_DEBUG_FUN__V73*/ meltfptr[32];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6230:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L36*/ meltfnum[28] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V73*/ meltfptr[32] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V72*/ meltfptr[30] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6230:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L35*/ meltfnum[9] = 0;
      /*^clear */
	     /*clear *//*_._IF___V72*/ meltfptr[30] = 0;
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
      /* start foreach_in_list meltcit4__EACHLIST */
      for ( /*_.CURPAIR__V74*/ meltfptr[34] =
	   melt_list_first ((melt_ptr_t) /*_.CONSBINDLIST__V19*/
			    meltfptr[18]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V74*/ meltfptr[34]) ==
	   MELTOBMAG_PAIR;
	   /*_.CURPAIR__V74*/ meltfptr[34] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V74*/ meltfptr[34]))
	{
	  /*_.CURCBIND__V75*/ meltfptr[33] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V74*/ meltfptr[34]);



#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6237:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L37*/ meltfnum[27] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6237:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L37*/ meltfnum[27])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L38*/ meltfnum[28] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6237:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L38*/ meltfnum[28];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6237;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curcbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V75*/ meltfptr[33];
		    /*_.MELT_DEBUG_FUN__V77*/ meltfptr[61] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V76*/ meltfptr[38] =
		    /*_.MELT_DEBUG_FUN__V77*/ meltfptr[61];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6237:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L38*/ meltfnum[28] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V77*/ meltfptr[61] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V76*/ meltfptr[38] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6237:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L37*/ meltfnum[27] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V76*/ meltfptr[38] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6238:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L39*/ meltfnum[9] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V75*/ meltfptr[33]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
	    MELT_LOCATION ("warmelt-normal.melt:6238:/ cond");
	    /*cond */ if ( /*_#IS_A__L39*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V79*/ meltfptr[32] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6238:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6238) ? (6238) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V79*/ meltfptr[32] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V78*/ meltfptr[58] =
	      /*_._IFELSE___V79*/ meltfptr[32];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6238:/ clear");
	      /*clear *//*_#IS_A__L39*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V79*/ meltfptr[32] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V78*/ meltfptr[58] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6239:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.NCBINDTUP__V68*/ meltfptr[40]),
				     ( /*_#CURCIX__L34*/ meltfnum[20]),
				     (melt_ptr_t) ( /*_.CURCBIND__V75*/
						   meltfptr[33]));
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6240:/ locexp");
	    melt_put_int ((melt_ptr_t) ( /*_.CURCBIND__V75*/ meltfptr[33]),
			  ( /*_#CURCIX__L34*/ meltfnum[20]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6241:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V75*/
					       meltfptr[33]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NCONSB_NLETREC",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V75*/
						   meltfptr[33])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V75*/ meltfptr[33]),
				      (3), ( /*_.NLETREC__V70*/ meltfptr[28]),
				      "NCONSB_NLETREC");
		;
		/*^touch */
		meltgc_touch ( /*_.CURCBIND__V75*/ meltfptr[33]);
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.CURCBIND__V75*/
					      meltfptr[33], "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6242:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURCBIND__V75*/ meltfptr[33]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 2, "NCONSB_DISCR");
   /*_.CURBDISCR__V80*/ meltfptr[30] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6243:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURCBIND__V75*/ meltfptr[33]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
   /*_.CURBINDER__V81*/ meltfptr[61] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6245:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V75*/
					       meltfptr[33]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURCBIND__V75*/ meltfptr[33]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NCONSB_LOC");
    /*_.NCONSB_LOC__V82*/ meltfptr[38] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NCONSB_LOC__V82*/ meltfptr[38] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6245:/ cond");
	  /*cond */ if ( /*_.NCONSB_LOC__V82*/ meltfptr[38])	/*then */
	    {
	      /*^cond.then */
	      /*_.OR___V83*/ meltfptr[32] =
		/*_.NCONSB_LOC__V82*/ meltfptr[38];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6245:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V15*/ meltfptr[10])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V84*/ meltfptr[83] =
		      /*_.SLOC__V15*/ meltfptr[10];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6245:/ cond.else");

		    /*_.OR___V84*/ meltfptr[83] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.OR___V83*/ meltfptr[32] = /*_.OR___V84*/ meltfptr[83];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6245:/ clear");
	      /*clear *//*_.OR___V84*/ meltfptr[83] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6244:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
						   meltfrout->tabval[15])),
				    (4), "CLASS_NREP_LOCSYMOCC");
   /*_.INST__V86*/ meltfptr[85] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V86*/ meltfptr[85]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V86*/ meltfptr[85]), (0),
				( /*_.OR___V83*/ meltfptr[32]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V86*/ meltfptr[85]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V86*/ meltfptr[85]), (2),
				(( /*!CTYPE_VALUE */ meltfrout->tabval[16])),
				"NOCC_CTYP");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_SYMB",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V86*/ meltfptr[85]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V86*/ meltfptr[85]), (1),
				( /*_.CURBINDER__V81*/ meltfptr[61]),
				"NOCC_SYMB");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V86*/ meltfptr[85]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V86*/ meltfptr[85]), (3),
				( /*_.CURCBIND__V75*/ meltfptr[33]),
				"NOCC_BIND");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V86*/ meltfptr[85],
					"newly made instance");
	  ;
	  /*_.NLOCSYM__V85*/ meltfptr[83] = /*_.INST__V86*/ meltfptr[85];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6252:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.NLOCSYMS__V67*/ meltfptr[45]),
				     ( /*_#CURCIX__L34*/ meltfnum[20]),
				     (melt_ptr_t) ( /*_.NLOCSYM__V85*/
						   meltfptr[83]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#NULL__L40*/ meltfnum[28] =
	    (( /*_.CURBDISCR__V80*/ meltfptr[30]) == NULL);;
	  MELT_LOCATION ("warmelt-normal.melt:6253:/ cond");
	  /*cond */ if ( /*_#NULL__L40*/ meltfnum[28])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6254:/ quasiblock");


		/*^cond */
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURCBIND__V75*/
						     meltfptr[33]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[17])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CURCBIND__V75*/ meltfptr[33])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 5, "NINSTB_CLABIND");
      /*_.CLABIND__V87*/ meltfptr[86] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.CLABIND__V87*/ meltfptr[86] = NULL;;
		  }
		;
		MELT_LOCATION ("warmelt-normal.melt:6255:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CLABIND__V87*/
						     meltfptr[86]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[18])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CLABIND__V87*/ meltfptr[86])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
      /*_.CLASYM__V88*/ meltfptr[87] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.CLASYM__V88*/ meltfptr[87] = NULL;;
		  }
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6257:/ cppif.then");
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
      /*_#MELT_NEED_DBG__L41*/ meltfnum[27] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:6257:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L41*/ meltfnum[27])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	/*_#MELT_CALLCOUNT__L42*/ meltfnum[9] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:6257:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[7];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L42*/ meltfnum[9];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 6257;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_letrec clabind=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLABIND__V87*/ meltfptr[86];
			  /*^apply.arg */
			  argtab[5].meltbp_cstring = " clasym=";
			  /*^apply.arg */
			  argtab[6].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLASYM__V88*/ meltfptr[87];
			  /*_.MELT_DEBUG_FUN__V90*/ meltfptr[89] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[3])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V89*/ meltfptr[88] =
			  /*_.MELT_DEBUG_FUN__V90*/ meltfptr[89];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6257:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L42*/ meltfnum[9] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V90*/ meltfptr[89] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V89*/ meltfptr[88] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:6257:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		/*clear *//*_#MELT_NEED_DBG__L41*/ meltfnum[27] = 0;
		  /*^clear */
		/*clear *//*_._IF___V89*/ meltfptr[88] = 0;
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
		MELT_LOCATION ("warmelt-normal.melt:6259:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
      /*_#IS_A__L43*/ meltfnum[9] =
		    melt_is_instance_of ((melt_ptr_t)
					 ( /*_.CURCBIND__V75*/ meltfptr[33]),
					 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[17])));;
		  MELT_LOCATION ("warmelt-normal.melt:6259:/ cond");
		  /*cond */ if ( /*_#IS_A__L43*/ meltfnum[9])	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V92*/ meltfptr[88] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:6259:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("check curcbind for instance"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (6259) ? (6259) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		  /*clear *//*_._IFELSE___V92*/ meltfptr[88] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V91*/ meltfptr[89] =
		    /*_._IFELSE___V92*/ meltfptr[88];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6259:/ clear");
		/*clear *//*_#IS_A__L43*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_._IFELSE___V92*/ meltfptr[88] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V91*/ meltfptr[89] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:6260:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6261:/ msend");
		/*msend */
		{
		  union meltparam_un argtab[3];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^ojbmsend.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.ENV__V3*/ meltfptr[2];
		  /*^ojbmsend.arg */
		  argtab[1].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
		  /*^ojbmsend.arg */
		  argtab[2].meltbp_aptr =
		    (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[10];
		  /*_.CLADATA__V93*/ meltfptr[88] =
		    meltgc_send ((melt_ptr_t)
				 ( /*_.CLASYM__V88*/ meltfptr[87]),
				 (melt_ptr_t) (( /*!NORMAL_EXP */ meltfrout->
						tabval[19])),
				 (MELTBPARSTR_PTR MELTBPARSTR_PTR
				  MELTBPARSTR_PTR ""), argtab, "",
				 (union meltparam_un *) 0);
		}
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6263:/ cppif.then");
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
      /*_#MELT_NEED_DBG__L44*/ meltfnum[27] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:6263:/ cond");
		  /*cond */ if ( /*_#MELT_NEED_DBG__L44*/ meltfnum[27])	/*then */
		    {
		      /*^cond.then */
		      /*^block */
		      /*anyblock */
		      {

	/*_#MELT_CALLCOUNT__L45*/ meltfnum[9] =
			  /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
			  meltcallcount	/* melt_callcount debugging */
#else
			  0L	/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
			  ;;

			MELT_CHECK_SIGNAL ();
			;
			MELT_LOCATION ("warmelt-normal.melt:6263:/ apply");
			/*apply */
			{
			  union meltparam_un argtab[5];
			  memset (&argtab, 0, sizeof (argtab));
			  /*^apply.arg */
			  argtab[0].meltbp_long =
			    /*_#MELT_CALLCOUNT__L45*/ meltfnum[9];
			  /*^apply.arg */
			  argtab[1].meltbp_cstring = "warmelt-normal.melt";
			  /*^apply.arg */
			  argtab[2].meltbp_long = 6263;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring = "normexp_letrec cladata";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLADATA__V93*/ meltfptr[88];
			  /*_.MELT_DEBUG_FUN__V95*/ meltfptr[94] =
			    melt_apply ((meltclosure_ptr_t)
					(( /*!MELT_DEBUG_FUN */ meltfrout->
					  tabval[3])),
					(melt_ptr_t) (( /*nil */ NULL)),
					(MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_LONG MELTBPARSTR_CSTRING
					 MELTBPARSTR_PTR ""), argtab, "",
					(union meltparam_un *) 0);
			}
			;
			/*_._IF___V94*/ meltfptr[93] =
			  /*_.MELT_DEBUG_FUN__V95*/ meltfptr[94];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6263:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L45*/ meltfnum[9] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V95*/ meltfptr[94] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V94*/ meltfptr[93] = NULL;;
		    }
		  ;

		  {
		    MELT_LOCATION ("warmelt-normal.melt:6263:/ locexp");
		    /*void */ (void) 0;
		  }
		  ;
		  /*^quasiblock */


		  /*epilog */

		  /*^clear */
		/*clear *//*_#MELT_NEED_DBG__L44*/ meltfnum[27] = 0;
		  /*^clear */
		/*clear *//*_._IF___V94*/ meltfptr[93] = 0;
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
		MELT_LOCATION ("warmelt-normal.melt:6264:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
      /*_#IS_A__L46*/ meltfnum[9] =
		    melt_is_instance_of ((melt_ptr_t)
					 ( /*_.CLADATA__V93*/ meltfptr[88]),
					 (melt_ptr_t) (( /*!CLASS_NREP */
							meltfrout->
							tabval[20])));;
		  MELT_LOCATION ("warmelt-normal.melt:6264:/ cond");
		  /*cond */ if ( /*_#IS_A__L46*/ meltfnum[9])	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V97*/ meltfptr[93] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:6264:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("check cladata"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (6264) ? (6264) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		  /*clear *//*_._IFELSE___V97*/ meltfptr[93] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V96*/ meltfptr[94] =
		    /*_._IFELSE___V97*/ meltfptr[93];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6264:/ clear");
		/*clear *//*_#IS_A__L46*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_._IFELSE___V97*/ meltfptr[93] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V96*/ meltfptr[94] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6265:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURCBIND__V75*/
						     meltfptr[33]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("checkobj putslot  _ @NCONSB_DISCR",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CURCBIND__V75*/
							 meltfptr[33])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CURCBIND__V75*/
					     meltfptr[33]), (2),
					    ( /*_.CLADATA__V93*/
					     meltfptr[88]), "NCONSB_DISCR");
		      ;
		      /*^touch */
		      meltgc_touch ( /*_.CURCBIND__V75*/ meltfptr[33]);
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.CURCBIND__V75*/
						    meltfptr[33],
						    "put-fields");
		      ;
		      /*epilog */
		    }
		    ;
		  }		/*noelse */
		;

		MELT_LOCATION ("warmelt-normal.melt:6260:/ clear");
	      /*clear *//*_.CLADATA__V93*/ meltfptr[88] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V96*/ meltfptr[94] = 0;

		MELT_LOCATION ("warmelt-normal.melt:6254:/ clear");
	      /*clear *//*_.CLABIND__V87*/ meltfptr[86] = 0;
		/*^clear */
	      /*clear *//*_.CLASYM__V88*/ meltfptr[87] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V91*/ meltfptr[89] = 0;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6242:/ clear");
	    /*clear *//*_.CURBDISCR__V80*/ meltfptr[30] = 0;
	  /*^clear */
	    /*clear *//*_.CURBINDER__V81*/ meltfptr[61] = 0;
	  /*^clear */
	    /*clear *//*_.NCONSB_LOC__V82*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_.OR___V83*/ meltfptr[32] = 0;
	  /*^clear */
	    /*clear *//*_.NLOCSYM__V85*/ meltfptr[83] = 0;
	  /*^clear */
	    /*clear *//*_#NULL__L40*/ meltfnum[28] = 0;
  /*_#plI__L47*/ meltfnum[27] =
	    (( /*_#CURCIX__L34*/ meltfnum[20]) + (1));;
	  MELT_LOCATION ("warmelt-normal.melt:6268:/ compute");
	  /*_#CURCIX__L34*/ meltfnum[20] = /*_#SETQ___L48*/ meltfnum[9] =
	    /*_#plI__L47*/ meltfnum[27];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6269:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURCBIND__V75*/ meltfptr[33];
	    /*_.PUT_ENV__V98*/ meltfptr[93] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!PUT_ENV */ meltfrout->tabval[21])),
			  (melt_ptr_t) ( /*_.NEWENV__V20*/ meltfptr[19]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	}			/* end foreach_in_list meltcit4__EACHLIST */
     /*_.CURPAIR__V74*/ meltfptr[34] = NULL;
     /*_.CURCBIND__V75*/ meltfptr[33] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6234:/ clear");
	    /*clear *//*_.CURPAIR__V74*/ meltfptr[34] = 0;
      /*^clear */
	    /*clear *//*_.CURCBIND__V75*/ meltfptr[33] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V78*/ meltfptr[58] = 0;
      /*^clear */
	    /*clear *//*_#plI__L47*/ meltfnum[27] = 0;
      /*^clear */
	    /*clear *//*_#SETQ___L48*/ meltfnum[9] = 0;
      /*^clear */
	    /*clear *//*_.PUT_ENV__V98*/ meltfptr[93] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit5__EACHTUP */
      long meltcit5__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.SBINDS__V16*/ meltfptr[15]);
      for ( /*_#SBIX__L49*/ meltfnum[28] = 0;
	   ( /*_#SBIX__L49*/ meltfnum[28] >= 0)
	   && ( /*_#SBIX__L49*/ meltfnum[28] < meltcit5__EACHTUP_ln);
	/*_#SBIX__L49*/ meltfnum[28]++)
	{
	  /*_.CURSBIND__V99*/ meltfptr[88] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.SBINDS__V16*/ meltfptr[15]),
			       /*_#SBIX__L49*/ meltfnum[28]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6276:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L50*/ meltfnum[49] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6276:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L50*/ meltfnum[49])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L51*/ meltfnum[50] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6276:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[7];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L51*/ meltfnum[50];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6276;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop cursbind=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSBIND__V99*/ meltfptr[88];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " sbix=";
		    /*^apply.arg */
		    argtab[6].meltbp_long = /*_#SBIX__L49*/ meltfnum[28];
		    /*_.MELT_DEBUG_FUN__V101*/ meltfptr[86] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V100*/ meltfptr[94] =
		    /*_.MELT_DEBUG_FUN__V101*/ meltfptr[86];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6276:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L51*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V101*/ meltfptr[86] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V100*/ meltfptr[94] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6276:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L50*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V100*/ meltfptr[94] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6277:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L52*/ meltfnum[50] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSBIND__V99*/ meltfptr[88]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC_BINDING */ meltfrout->tabval[7])));;
	    MELT_LOCATION ("warmelt-normal.melt:6277:/ cond");
	    /*cond */ if ( /*_#IS_A__L52*/ meltfnum[50])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V103*/ meltfptr[89] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6277:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6277) ? (6277) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V103*/ meltfptr[89] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V102*/ meltfptr[87] =
	      /*_._IFELSE___V103*/ meltfptr[89];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6277:/ clear");
	      /*clear *//*_#IS_A__L52*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V103*/ meltfptr[89] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V102*/ meltfptr[87] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6278:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V99*/ meltfptr[88]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V104*/ meltfptr[30] = slot;
	  };
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.LOCA_LOCATION__V104*/ meltfptr[30])	/*then */
	    {
	      /*^cond.then */
	      /*_.LOCB__V105*/ meltfptr[61] =
		/*_.LOCA_LOCATION__V104*/ meltfptr[30];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6278:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V15*/ meltfptr[10])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V106*/ meltfptr[38] =
		      /*_.SLOC__V15*/ meltfptr[10];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6278:/ cond.else");

		    /*_.OR___V106*/ meltfptr[38] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.LOCB__V105*/ meltfptr[61] = /*_.OR___V106*/ meltfptr[38];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6278:/ clear");
	      /*clear *//*_.OR___V106*/ meltfptr[38] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6279:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V99*/ meltfptr[88]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 3, "SLETB_BINDER");
   /*_.CURSYMB__V107*/ meltfptr[32] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6280:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V99*/ meltfptr[88]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "SLETB_EXPR");
   /*_.CUREXPR__V108*/ meltfptr[83] = slot;
	  };
	  ;
  /*_.CURBIND__V109*/ meltfptr[86] =
	    /*mapobject_get */
	    melt_get_mapobjects ((meltmapobjects_ptr_t)
				 ( /*_.SYMBINDMAP__V22*/ meltfptr[21]),
				 (meltobject_ptr_t) ( /*_.CURSYMB__V107*/
						     meltfptr[32]));;
	  /*^compute */
  /*_.CURSEXPR__V110*/ meltfptr[94] =
	    /*mapobject_get */
	    melt_get_mapobjects ((meltmapobjects_ptr_t)
				 ( /*_.SYMBEXPRMAP__V21*/ meltfptr[20]),
				 (meltobject_ptr_t) ( /*_.CURSYMB__V107*/
						     meltfptr[32]));;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6284:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L53*/ meltfnum[49] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6284:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L53*/ meltfnum[49])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L54*/ meltfnum[50] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6284:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[11];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L54*/ meltfnum[50];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6284;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop curexpr=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V108*/ meltfptr[83];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " cursymb=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSYMB__V107*/ meltfptr[32];
		    /*^apply.arg */
		    argtab[7].meltbp_cstring = " curbind=";
		    /*^apply.arg */
		    argtab[8].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURBIND__V109*/ meltfptr[86];
		    /*^apply.arg */
		    argtab[9].meltbp_cstring = " cursexpr=";
		    /*^apply.arg */
		    argtab[10].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSEXPR__V110*/ meltfptr[94];
		    /*_.MELT_DEBUG_FUN__V112*/ meltfptr[38] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V111*/ meltfptr[89] =
		    /*_.MELT_DEBUG_FUN__V112*/ meltfptr[38];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6284:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L54*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V112*/ meltfptr[38] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V111*/ meltfptr[89] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6284:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L53*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V111*/ meltfptr[89] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6288:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#eqeq__L55*/ meltfnum[50] =
	      (( /*_.CUREXPR__V108*/ meltfptr[83]) ==
	       ( /*_.CURSEXPR__V110*/ meltfptr[94]));;
	    MELT_LOCATION ("warmelt-normal.melt:6288:/ cond");
	    /*cond */ if ( /*_#eqeq__L55*/ meltfnum[50])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V114*/ meltfptr[89] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6288:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curxpr same cursexpr"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6288) ? (6288) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V114*/ meltfptr[89] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V113*/ meltfptr[38] =
	      /*_._IFELSE___V114*/ meltfptr[89];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6288:/ clear");
	      /*clear *//*_#eqeq__L55*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V114*/ meltfptr[89] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V113*/ meltfptr[38] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6289:/ msend");
	  /*msend */
	  {
	    union meltparam_un argtab[5];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURSYMB__V107*/ meltfptr[32];
	    /*^ojbmsend.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURBIND__V109*/ meltfptr[86];
	    /*^ojbmsend.arg */
	    argtab[2].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NEWENV__V20*/ meltfptr[19];
	    /*^ojbmsend.arg */
	    argtab[3].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^ojbmsend.arg */
	    argtab[4].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[10];
	    /*_.NORMAL_LETREC_CONSTRUCTIVE__V115*/ meltfptr[89] =
	      meltgc_send ((melt_ptr_t) ( /*_.CUREXPR__V108*/ meltfptr[83]),
			   (melt_ptr_t) (( /*!NORMAL_LETREC_CONSTRUCTIVE */
					  meltfrout->tabval[22])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
			   (union meltparam_un *) 0);
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6290:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L56*/ meltfnum[49] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6290:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L56*/ meltfnum[49])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L57*/ meltfnum[50] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6290:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L57*/ meltfnum[50];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6290;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop done curexpr";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V108*/ meltfptr[83];
		    /*_.MELT_DEBUG_FUN__V117*/ meltfptr[116] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V116*/ meltfptr[115] =
		    /*_.MELT_DEBUG_FUN__V117*/ meltfptr[116];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6290:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L57*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V117*/ meltfptr[116] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V116*/ meltfptr[115] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6290:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L56*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V116*/ meltfptr[115] = 0;
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

	  MELT_LOCATION ("warmelt-normal.melt:6278:/ clear");
	    /*clear *//*_.LOCA_LOCATION__V104*/ meltfptr[30] = 0;
	  /*^clear */
	    /*clear *//*_.LOCB__V105*/ meltfptr[61] = 0;
	  /*^clear */
	    /*clear *//*_.CURSYMB__V107*/ meltfptr[32] = 0;
	  /*^clear */
	    /*clear *//*_.CUREXPR__V108*/ meltfptr[83] = 0;
	  /*^clear */
	    /*clear *//*_.CURBIND__V109*/ meltfptr[86] = 0;
	  /*^clear */
	    /*clear *//*_.CURSEXPR__V110*/ meltfptr[94] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V113*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_.NORMAL_LETREC_CONSTRUCTIVE__V115*/ meltfptr[89] = 0;
	  if ( /*_#SBIX__L49*/ meltfnum[28] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit5__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6273:/ clear");
	    /*clear *//*_.CURSBIND__V99*/ meltfptr[88] = 0;
      /*^clear */
	    /*clear *//*_#SBIX__L49*/ meltfnum[28] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V102*/ meltfptr[87] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6293:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L58*/ meltfnum[50] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6293:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L58*/ meltfnum[50])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L59*/ meltfnum[49] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6293:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L59*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6293;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_letrec recfillbindings before normalizing the body";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECFILLBINDINGS__V69*/ meltfptr[42];
	      /*_.MELT_DEBUG_FUN__V119*/ meltfptr[115] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V118*/ meltfptr[116] =
	      /*_.MELT_DEBUG_FUN__V119*/ meltfptr[115];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6293:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L59*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V119*/ meltfptr[115] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V118*/ meltfptr[116] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6293:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L58*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V118*/ meltfptr[116] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6296:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L60*/ meltfnum[49] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6296:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L60*/ meltfnum[49])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L61*/ meltfnum[50] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6296:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L61*/ meltfnum[50];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6296;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec normalizing sbody";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SBODY__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V121*/ meltfptr[61] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V120*/ meltfptr[30] =
	      /*_.MELT_DEBUG_FUN__V121*/ meltfptr[61];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6296:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L61*/ meltfnum[50] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V121*/ meltfptr[61] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V120*/ meltfptr[30] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6296:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L60*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IF___V120*/ meltfptr[30] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6297:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V20*/ meltfptr[19];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[10];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBODBINDINGS__V124*/ meltfptr[86];
      /*^multiapply.appl */
      /*_.NBODY__V123*/ meltfptr[83] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[23])),
		    (melt_ptr_t) ( /*_.SBODY__V17*/ meltfptr[16]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6300:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L62*/ meltfnum[50] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6300:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L62*/ meltfnum[50])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L63*/ meltfnum[49] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6300:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L63*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6300;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec nbody=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBODY__V123*/ meltfptr[83];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbodbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBODBINDINGS__V124*/ meltfptr[86];
	      /*_.MELT_DEBUG_FUN__V126*/ meltfptr[38] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V125*/ meltfptr[94] =
	      /*_.MELT_DEBUG_FUN__V126*/ meltfptr[38];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6300:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L63*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V126*/ meltfptr[38] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V125*/ meltfptr[94] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6300:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L62*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V125*/ meltfptr[94] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6301:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L64*/ meltfnum[49] =
	(( /*_.NBODBINDINGS__V124*/ meltfptr[86]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBODBINDINGS__V124*/ meltfptr[86])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6301:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L64*/ meltfnum[49])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V128*/ meltfptr[115] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6301:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("normexp_letrec check nbodbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6301) ? (6301) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V128*/ meltfptr[115] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V127*/ meltfptr[89] = /*_._IFELSE___V128*/ meltfptr[115];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6301:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L64*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V128*/ meltfptr[115] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V127*/ meltfptr[89] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6302:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V70*/ meltfptr[28]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[14])))
      )				/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NLET_BODY",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.NLETREC__V70*/
					     meltfptr[28])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.NLETREC__V70*/ meltfptr[28]), (2),
				( /*_.NBODY__V123*/ meltfptr[83]),
				"NLET_BODY");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NLETREC_BODY_BINDINGS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.NLETREC__V70*/
					     meltfptr[28])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.NLETREC__V70*/ meltfptr[28]), (4),
				( /*_.NBODBINDINGS__V124*/ meltfptr[86]),
				"NLETREC_BODY_BINDINGS");
	  ;
	  /*^touch */
	  meltgc_touch ( /*_.NLETREC__V70*/ meltfptr[28]);
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.NLETREC__V70*/ meltfptr[28],
					"put-fields");
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6305:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L65*/ meltfnum[50] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6305:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L65*/ meltfnum[50])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L66*/ meltfnum[49] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6305:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L66*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6305;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec updated nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V70*/ meltfptr[28];
	      /*_.MELT_DEBUG_FUN__V130*/ meltfptr[61] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V129*/ meltfptr[116] =
	      /*_.MELT_DEBUG_FUN__V130*/ meltfptr[61];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6305:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L66*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V130*/ meltfptr[61] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V129*/ meltfptr[116] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6305:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L65*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V129*/ meltfptr[116] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6306:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L67*/ meltfnum[49] =
	(( /*_.BINDLIST__V18*/ meltfptr[17]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.BINDLIST__V18*/ meltfptr[17])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6306:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L67*/ meltfnum[49])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V132*/ meltfptr[38] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6306:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("normexp_letrec check bindlist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6306) ? (6306) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V132*/ meltfptr[38] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V131*/ meltfptr[30] = /*_._IFELSE___V132*/ meltfptr[38];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6306:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L67*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V132*/ meltfptr[38] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V131*/ meltfptr[30] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6308:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 6, "NCTX_SYMBCACHEMAP");
  /*_.SYCMAP__V133*/ meltfptr[94] = slot;
    };
    ;
    /*citerblock FOREACH_IN_LIST */
    {
      /* start foreach_in_list meltcit6__EACHLIST */
      for ( /*_.CURPAIR__V134*/ meltfptr[115] =
	   melt_list_first ((melt_ptr_t) /*_.BINDLIST__V18*/ meltfptr[17]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V134*/ meltfptr[115])
	   == MELTOBMAG_PAIR;
	   /*_.CURPAIR__V134*/ meltfptr[115] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V134*/ meltfptr[115]))
	{
	  /*_.BND__V135*/ meltfptr[61] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V134*/ meltfptr[115]);



#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6312:/ cppif.then");
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
    /*_#MELT_NEED_DBG__L68*/ meltfnum[50] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6312:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L68*/ meltfnum[50])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

      /*_#MELT_CALLCOUNT__L69*/ meltfnum[49] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6312:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L69*/ meltfnum[49];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6312;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec removing from sycmap bnd";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.BND__V135*/ meltfptr[61];
		    /*_.MELT_DEBUG_FUN__V137*/ meltfptr[38] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[3])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V136*/ meltfptr[116] =
		    /*_.MELT_DEBUG_FUN__V137*/ meltfptr[38];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6312:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L69*/ meltfnum[49] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V137*/ meltfptr[38] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V136*/ meltfptr[116] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6312:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	      /*clear *//*_#MELT_NEED_DBG__L68*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V136*/ meltfptr[116] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6313:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L70*/ meltfnum[49] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.BND__V135*/ meltfptr[61]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->tabval[24])));;
	    MELT_LOCATION ("warmelt-normal.melt:6313:/ cond");
	    /*cond */ if ( /*_#IS_A__L70*/ meltfnum[49])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V139*/ meltfptr[116] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6313:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("normexp_letrec check bnd"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6313) ? (6313) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V139*/ meltfptr[116] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V138*/ meltfptr[38] =
	      /*_._IFELSE___V139*/ meltfptr[116];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6313:/ clear");
	      /*clear *//*_#IS_A__L70*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V139*/ meltfptr[116] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V138*/ meltfptr[38] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6314:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.BND__V135*/ meltfptr[61]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
   /*_.BINDER__V140*/ meltfptr[116] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_remove_mapobjects ((meltmapobjects_ptr_t)
				      ( /*_.SYCMAP__V133*/ meltfptr[94]),
				      (meltobject_ptr_t) ( /*_.BINDER__V140*/
							  meltfptr[116]));
	  }
	  ;
	}			/* end foreach_in_list meltcit6__EACHLIST */
     /*_.CURPAIR__V134*/ meltfptr[115] = NULL;
     /*_.BND__V135*/ meltfptr[61] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6309:/ clear");
	    /*clear *//*_.CURPAIR__V134*/ meltfptr[115] = 0;
      /*^clear */
	    /*clear *//*_.BND__V135*/ meltfptr[61] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V138*/ meltfptr[38] = 0;
      /*^clear */
	    /*clear *//*_.BINDER__V140*/ meltfptr[116] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;

    MELT_LOCATION ("warmelt-normal.melt:6308:/ clear");
	   /*clear *//*_.SYCMAP__V133*/ meltfptr[94] = 0;
    MELT_LOCATION ("warmelt-normal.melt:6317:/ quasiblock");


 /*_.NLASTBODY__V142*/ meltfptr[141] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.NBODY__V123*/ meltfptr[83]), (-1)));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6320:/ msend");
    /*msend */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^ojbmsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V20*/ meltfptr[19];
      /*_.GET_CTYPE__V143*/ meltfptr[142] =
	meltgc_send ((melt_ptr_t) ( /*_.NLASTBODY__V142*/ meltfptr[141]),
		     (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->tabval[26])),
		     (MELTBPARSTR_PTR ""), argtab, "",
		     (union meltparam_un *) 0);
    }
    ;
    /*^cond */
    /*cond */ if ( /*_.GET_CTYPE__V143*/ meltfptr[142])	/*then */
      {
	/*^cond.then */
	/*_.NLASTYP__V144*/ meltfptr[143] =
	  /*_.GET_CTYPE__V143*/ meltfptr[142];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6320:/ cond.else");

	/*_.NLASTYP__V144*/ meltfptr[143] =
	  ( /*!CTYPE_VOID */ meltfrout->tabval[25]);;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6321:/ apply");
    /*apply */
    {
      /*_.CSYM__V145*/ meltfptr[144] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[27])),
		    (melt_ptr_t) (( /*!konst_28_LETREC_ */ meltfrout->
				   tabval[28])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6322:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */
					     meltfrout->tabval[24])), (4),
			      "CLASS_NORMAL_LET_BINDING");
  /*_.INST__V147*/ meltfptr[146] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V147*/ meltfptr[146])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V147*/ meltfptr[146]), (0),
			  ( /*_.CSYM__V145*/ meltfptr[144]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V147*/ meltfptr[146])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V147*/ meltfptr[146]), (3),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "LETBIND_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_TYPE",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V147*/ meltfptr[146])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V147*/ meltfptr[146]), (1),
			  ( /*_.NLASTYP__V144*/ meltfptr[143]),
			  "LETBIND_TYPE");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @LETBIND_EXPR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V147*/ meltfptr[146])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V147*/ meltfptr[146]), (2),
			  ( /*_.NLETREC__V70*/ meltfptr[28]), "LETBIND_EXPR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V147*/ meltfptr[146],
				  "newly made instance");
    ;
    /*_.CBIND__V146*/ meltfptr[145] = /*_.INST__V147*/ meltfptr[146];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6327:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[15])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V149*/ meltfptr[148] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V149*/ meltfptr[148])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V149*/ meltfptr[148]), (0),
			  ( /*_.SLOC__V15*/ meltfptr[10]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V149*/ meltfptr[148])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V149*/ meltfptr[148]), (2),
			  ( /*_.NLASTYP__V144*/ meltfptr[143]), "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("checkobj putslot  _ @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V149*/ meltfptr[148])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V149*/ meltfptr[148]), (3),
			  ( /*_.CBIND__V146*/ meltfptr[145]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V149*/ meltfptr[148],
				  "newly made instance");
    ;
    /*_.CLOCC__V148*/ meltfptr[147] = /*_.INST__V149*/ meltfptr[148];;
    /*^compute */
 /*_.RESBINDS__V150*/ meltfptr[149] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    {
      MELT_LOCATION ("warmelt-normal.melt:6333:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.RESBINDS__V150*/ meltfptr[149]),
			  (melt_ptr_t) ( /*_.CBIND__V146*/ meltfptr[145]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6334:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L71*/ meltfnum[50] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6334:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L71*/ meltfnum[50])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L72*/ meltfnum[49] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6334:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L72*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6334;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec result clocc=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOCC__V148*/ meltfptr[147];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V70*/ meltfptr[28];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " resbinds=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.RESBINDS__V150*/ meltfptr[149];
	      /*_.MELT_DEBUG_FUN__V152*/ meltfptr[151] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V151*/ meltfptr[150] =
	      /*_.MELT_DEBUG_FUN__V152*/ meltfptr[151];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6334:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L72*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V152*/ meltfptr[151] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V151*/ meltfptr[150] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6334:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L71*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V151*/ meltfptr[150] = 0;
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

    {
      MELT_LOCATION ("warmelt-normal.melt:6336:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normexp_letrec ending"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6337:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CLOCC__V148*/ meltfptr[147];;
    MELT_LOCATION ("warmelt-normal.melt:6337:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) =
	(melt_ptr_t) ( /*_.RESBINDS__V150*/ meltfptr[149]);
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V141*/ meltfptr[94] = /*_.RETURN___V153*/ meltfptr[151];;

    MELT_LOCATION ("warmelt-normal.melt:6317:/ clear");
	   /*clear *//*_.NLASTBODY__V142*/ meltfptr[141] = 0;
    /*^clear */
	   /*clear *//*_.GET_CTYPE__V143*/ meltfptr[142] = 0;
    /*^clear */
	   /*clear *//*_.NLASTYP__V144*/ meltfptr[143] = 0;
    /*^clear */
	   /*clear *//*_.CSYM__V145*/ meltfptr[144] = 0;
    /*^clear */
	   /*clear *//*_.CBIND__V146*/ meltfptr[145] = 0;
    /*^clear */
	   /*clear *//*_.CLOCC__V148*/ meltfptr[147] = 0;
    /*^clear */
	   /*clear *//*_.RESBINDS__V150*/ meltfptr[149] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V153*/ meltfptr[151] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V122*/ meltfptr[32] = /*_.LET___V141*/ meltfptr[94];;

    MELT_LOCATION ("warmelt-normal.melt:6297:/ clear");
	   /*clear *//*_.IFCPP___V127*/ meltfptr[89] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V131*/ meltfptr[30] = 0;
    /*^clear */
	   /*clear *//*_.LET___V141*/ meltfptr[94] = 0;

    /*^clear */
	   /*clear *//*_.NBODBINDINGS__V124*/ meltfptr[86] = 0;
    /*_.LET___V66*/ meltfptr[51] = /*_.MULTI___V122*/ meltfptr[32];;

    MELT_LOCATION ("warmelt-normal.melt:6214:/ clear");
	   /*clear *//*_#NBCONSBIND__L33*/ meltfnum[10] = 0;
    /*^clear */
	   /*clear *//*_#CURCIX__L34*/ meltfnum[20] = 0;
    /*^clear */
	   /*clear *//*_.NLOCSYMS__V67*/ meltfptr[45] = 0;
    /*^clear */
	   /*clear *//*_.NCBINDTUP__V68*/ meltfptr[40] = 0;
    /*^clear */
	   /*clear *//*_.RECFILLBINDINGS__V69*/ meltfptr[42] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V70*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V122*/ meltfptr[32] = 0;
    /*_.LET___V14*/ meltfptr[12] = /*_.LET___V66*/ meltfptr[51];;

    MELT_LOCATION ("warmelt-normal.melt:6154:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.SBINDS__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.SBODY__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_#NBBIND__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_.BINDLIST__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CONSBINDLIST__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.NEWENV__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_#stI__L7*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_#MAPLEN__L8*/ meltfnum[7] = 0;
    /*^clear */
	   /*clear *//*_.SYMBEXPRMAP__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.SYMBINDMAP__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.LET___V66*/ meltfptr[51] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6149:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6149:/ locexp");
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
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_LETREC", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_113_WARMELTmiNORMAL_NORMEXP_LETREC */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF_melt
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

  struct meltframe_meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF_st
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
#define MELTFRAM_NBVARPTR 27
    melt_ptr_t mcfr_varptr[27];
#define MELTFRAM_NBVARNUM 12
    long mcfr_varnum[12];
/*others*/
    const char *loc_CSTRING__o0;
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF_st *)
	meltfirstargp_;
      /* use arguments meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 27; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF nbval 27*/
  meltfram__.mcfr_nbvar = 27 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_PREDEF", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6346:/ getarg");
 /*_.PRED__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V4*/ meltfptr[3])) !=
	      NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_CSTRING)
    goto meltlab_endgetargs;
 /*_?*/ meltfram__.loc_CSTRING__o0 = meltxargtab_[2].meltbp_cstring;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6347:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6347:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6347:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6347;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_predef pred=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.PRED__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V5*/ meltfptr[4] =
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6347:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V5*/ meltfptr[4] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6347:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V5*/ meltfptr[4] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6348:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6348:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V8*/ meltfptr[4] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6348:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6348) ? (6348) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V8*/ meltfptr[4] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V7*/ meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[4];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6348:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V8*/ meltfptr[4] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6349:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 7, "NCTX_PREDEFMAP");
  /*_.PREDEFMAP__V10*/ meltfptr[9] = slot;
    };
    ;
 /*_.MAPOBJECT_GET__V11*/ meltfptr[10] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.PREDEFMAP__V10*/ meltfptr[9]),
			   (meltobject_ptr_t) ( /*_.PRED__V2*/ meltfptr[1]));;
    MELT_LOCATION ("warmelt-normal.melt:6350:/ cond");
    /*cond */ if ( /*_.MAPOBJECT_GET__V11*/ meltfptr[10])	/*then */
      {
	/*^cond.then */
	/*_.BRK__V12*/ meltfptr[11] = /*_.MAPOBJECT_GET__V11*/ meltfptr[10];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6350:/ cond.else");

	/*^block */
	/*anyblock */
	{

   /*_.GET_RAW_SYMBOL__V13*/ meltfptr[12] =
	    melthookproc_HOOK_NAMED_SYMBOL ((const char *) ( /*_?*/
							    meltfram__.
							    loc_CSTRING__o0),
					    (long) MELT_GET);;
	  /*^compute */
	  /*_.BRK__V12*/ meltfptr[11] =
	    /*_.GET_RAW_SYMBOL__V13*/ meltfptr[12];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6350:/ clear");
	     /*clear *//*_.GET_RAW_SYMBOL__V13*/ meltfptr[12] = 0;
	}
	;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6353:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6353:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L5*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6353:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6353;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_predef brk=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.BRK__V12*/ meltfptr[11];
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V14*/ meltfptr[12] =
	      /*_.MELT_DEBUG_FUN__V15*/ meltfptr[14];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6353:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V15*/ meltfptr[14] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V14*/ meltfptr[12] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6353:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V14*/ meltfptr[12] = 0;
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
 /*_#IS_INTEGERBOX__L6*/ meltfnum[1] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.BRK__V12*/ meltfptr[11])) ==
       MELTOBMAG_INT);;
    MELT_LOCATION ("warmelt-normal.melt:6354:/ cond");
    /*cond */ if ( /*_#IS_INTEGERBOX__L6*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*_#OR___L7*/ meltfnum[0] = /*_#IS_INTEGERBOX__L6*/ meltfnum[1];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6354:/ cond.else");

	/*^block */
	/*anyblock */
	{

   /*_#IS_A__L8*/ meltfnum[7] =
	    melt_is_instance_of ((melt_ptr_t) ( /*_.BRK__V12*/ meltfptr[11]),
				 (melt_ptr_t) (( /*!CLASS_SYMBOL */
						meltfrout->tabval[2])));;
	  /*^compute */
	  /*_#OR___L7*/ meltfnum[0] = /*_#IS_A__L8*/ meltfnum[7];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6354:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[7] = 0;
	}
	;
      }
    ;
    /*^cond */
    /*cond */ if ( /*_#OR___L7*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6355:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^quasiblock */


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_PREDEF */
						   meltfrout->tabval[3])),
				    (2), "CLASS_NREP_PREDEF");
    /*_.INST__V19*/ meltfptr[18] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V19*/ meltfptr[18]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (0),
				( /*_.SLOC__V4*/ meltfptr[3]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NRPREDEF",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V19*/ meltfptr[18]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (1),
				( /*_.BRK__V12*/ meltfptr[11]), "NRPREDEF");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V19*/ meltfptr[18],
					"newly made instance");
	  ;
	  /*_.RES__V18*/ meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6359:/ cppif.then");
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
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6359:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[7])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L10*/ meltfnum[9] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6359:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6359;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normal_predef res=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.RES__V18*/ meltfptr[17];
		    /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20] =
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
		  /*_._IF___V20*/ meltfptr[19] =
		    /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6359:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V21*/ meltfptr[20] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V20*/ meltfptr[19] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6359:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V20*/ meltfptr[19] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6360:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6360:/ locexp");
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
	  /*_.LET___V17*/ meltfptr[12] = /*_.RETURN___V22*/ meltfptr[20];;

	  MELT_LOCATION ("warmelt-normal.melt:6355:/ clear");
	     /*clear *//*_.RES__V18*/ meltfptr[17] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V22*/ meltfptr[20] = 0;
	  /*_._IFELSE___V16*/ meltfptr[14] = /*_.LET___V17*/ meltfptr[12];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6354:/ clear");
	     /*clear *//*_.LET___V17*/ meltfptr[12] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6362:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L11*/ meltfnum[9] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6362:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L11*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L12*/ meltfnum[7] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6362:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[7];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L12*/ meltfnum[7];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6362;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normalpredef fail predefmap=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.PREDEFMAP__V10*/ meltfptr[9];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " pred=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.PRED__V2*/ meltfptr[1];
		    /*_.MELT_DEBUG_FUN__V24*/ meltfptr[17] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!MELT_DEBUG_FUN */ meltfrout->
				    tabval[0])),
				  (melt_ptr_t) (( /*nil */ NULL)),
				  (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_LONG MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR MELTBPARSTR_CSTRING
				   MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_._IF___V23*/ meltfptr[19] =
		    /*_.MELT_DEBUG_FUN__V24*/ meltfptr[17];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6362:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L12*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V24*/ meltfptr[17] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V23*/ meltfptr[19] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6362:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L11*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V23*/ meltfptr[19] = 0;
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
   /*_.MAKE_STRINGCONST__V25*/ meltfptr[20] =
	    (meltgc_new_stringdup
	     ((meltobject_ptr_t)
	      (( /*!DISCR_VERBATIM_STRING */ meltfrout->tabval[4])),
	      ( /*_?*/ meltfram__.loc_CSTRING__o0)));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6363:/ locexp");
	    melt_error_str ((melt_ptr_t) ( /*_.SLOC__V4*/ meltfptr[3]),
			    ("not a predef:"),
			    (melt_ptr_t) ( /*_.MAKE_STRINGCONST__V25*/
					  meltfptr[20]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6364:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = ( /*nil */ NULL);;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6364:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6361:/ quasiblock");


	  /*_.PROGN___V27*/ meltfptr[17] = /*_.RETURN___V26*/ meltfptr[12];;
	  /*^compute */
	  /*_._IFELSE___V16*/ meltfptr[14] = /*_.PROGN___V27*/ meltfptr[17];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6354:/ clear");
	     /*clear *//*_.MAKE_STRINGCONST__V25*/ meltfptr[20] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V26*/ meltfptr[12] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V27*/ meltfptr[17] = 0;
	}
	;
      }
    ;
    /*_.LET___V9*/ meltfptr[4] = /*_._IFELSE___V16*/ meltfptr[14];;

    MELT_LOCATION ("warmelt-normal.melt:6349:/ clear");
	   /*clear *//*_.PREDEFMAP__V10*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.MAPOBJECT_GET__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.BRK__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_#IS_INTEGERBOX__L6*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_#OR___L7*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V16*/ meltfptr[14] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6346:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V9*/ meltfptr[4];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6346:/ locexp");
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
	   /*clear *//*_.IFCPP___V7*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.LET___V9*/ meltfptr[4] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_PREDEF", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_114_WARMELTmiNORMAL_NORMAL_PREDEF */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_melt
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

  struct meltframe_meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_st
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
#define MELTFRAM_NBVARPTR 36
    melt_ptr_t mcfr_varptr[36];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_st
	 *) meltfirstargp_;
      /* use arguments meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 36; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA nbval 36*/
  meltfram__.mcfr_nbvar = 36 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_SYMBOL_DATA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6369:/ getarg");
 /*_.SYM__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V4*/ meltfptr[3])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6371:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6371:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6371:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6371;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_symbol_data start sym=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYM__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V5*/ meltfptr[4] =
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6371:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V5*/ meltfptr[4] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6371:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V5*/ meltfptr[4] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6372:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_.DISCRIM__V8*/ meltfptr[4] =
	((melt_ptr_t)
	 (melt_discr ((melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]))));;
      /*^compute */
   /*_#eqeq__L3*/ meltfnum[1] =
	(( /*_.DISCRIM__V8*/ meltfptr[4]) ==
	 (( /*!CLASS_SYMBOL */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6372:/ cond");
      /*cond */ if ( /*_#eqeq__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6372:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check symb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6372) ? (6372) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V7*/ meltfptr[5] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6372:/ clear");
	     /*clear *//*_.DISCRIM__V8*/ meltfptr[4] = 0;
      /*^clear */
	     /*clear *//*_#eqeq__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6373:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6373:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6373:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6373) ? (6373) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[4] = /*_._IFELSE___V11*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6373:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6374:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NCTX_VALMAP");
  /*_.VALMAP__V13*/ meltfptr[12] = slot;
    };
    ;
 /*_.OSYDATA__V14*/ meltfptr[13] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.VALMAP__V13*/ meltfptr[12]),
			   (meltobject_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6376:/ cond");
    /*cond */ if ( /*_.OSYDATA__V14*/ meltfptr[13])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6378:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L5*/ meltfnum[1] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6378:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L5*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L6*/ meltfnum[0] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6378:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L6*/ meltfnum[0];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6378;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_symbol_data found osydata";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.OSYDATA__V14*/ meltfptr[13];
		    /*_.MELT_DEBUG_FUN__V17*/ meltfptr[16] =
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
		  /*_._IF___V16*/ meltfptr[15] =
		    /*_.MELT_DEBUG_FUN__V17*/ meltfptr[16];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6378:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[0] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V17*/ meltfptr[16] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V16*/ meltfptr[15] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6378:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V16*/ meltfptr[15] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6379:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.OSYDATA__V14*/ meltfptr[13];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6379:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6377:/ quasiblock");


	  /*_.PROGN___V19*/ meltfptr[15] = /*_.RETURN___V18*/ meltfptr[16];;
	  /*^compute */
	  /*_._IFELSE___V15*/ meltfptr[14] = /*_.PROGN___V19*/ meltfptr[15];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6376:/ clear");
	     /*clear *//*_.RETURN___V18*/ meltfptr[16] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V19*/ meltfptr[15] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6380:/ quasiblock");


   /*_#SYHASH__L7*/ meltfnum[0] =
	    (melt_obj_hash ((melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6381:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.SYNAMSTR__V21*/ meltfptr[15] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6385:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V3*/ meltfptr[2];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[2].meltbp_cstring = "discr_string";
	    /*_.NORMAL_PREDEF__V22*/ meltfptr[21] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!DISCR_STRING */ meltfrout->
					 tabval[5])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6384:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[3])), (6), "CLASS_NREP_DATASTRING");
    /*_.INST__V24*/ meltfptr[23] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V24*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V24*/ meltfptr[23]), (4),
				( /*_.NORMAL_PREDEF__V22*/ meltfptr[21]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NSTR_STRING",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V24*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V24*/ meltfptr[23]), (5),
				( /*_.SYNAMSTR__V21*/ meltfptr[15]),
				"NSTR_STRING");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V24*/ meltfptr[23],
					"newly made instance");
	  ;
	  /*_.SYNAMSTRDATA__V23*/ meltfptr[22] =
	    /*_.INST__V24*/ meltfptr[23];;
	  MELT_LOCATION ("warmelt-normal.melt:6389:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
			     tabval[1])) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
    /*_.CLASS_FIELDS__V25*/ meltfptr[24] = slot;
	  };
	  ;
   /*_#MULTIPLE_LENGTH__L8*/ meltfnum[1] =
	    (melt_multiple_length
	     ((melt_ptr_t) ( /*_.CLASS_FIELDS__V25*/ meltfptr[24])));;
	  /*^compute */
   /*_.SYSLOTS__V26*/ meltfptr[25] =
	    (meltgc_new_multiple
	     ((meltobject_ptr_t)
	      (( /*!DISCR_MULTIPLE */ meltfrout->tabval[6])),
	      ( /*_#MULTIPLE_LENGTH__L8*/ meltfnum[1])));;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6392:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V3*/ meltfptr[2];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[2].meltbp_cstring = "class_symbol";
	    /*_.NORMAL_PREDEF__V27*/ meltfptr[26] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					 tabval[1])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
   /*_.MAKE_INTEGERBOX__V28*/ meltfptr[27] =
	    (meltgc_new_int
	     ((meltobject_ptr_t)
	      (( /*!DISCR_INTEGER */ meltfrout->tabval[8])),
	      ( /*_#SYHASH__L7*/ meltfnum[0])));;
	  MELT_LOCATION ("warmelt-normal.melt:6390:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASYMBOL */ meltfrout->tabval[7])), (10), "CLASS_NREP_DATASYMBOL");
    /*_.INST__V30*/ meltfptr[29] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_NAME",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V30*/ meltfptr[29]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (1),
				( /*_.SYM__V2*/ meltfptr[1]), "NDATA_NAME");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V30*/ meltfptr[29]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (4),
				( /*_.NORMAL_PREDEF__V27*/ meltfptr[26]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NINST_HASH",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V30*/ meltfptr[29]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (7),
				( /*_.MAKE_INTEGERBOX__V28*/ meltfptr[27]),
				"NINST_HASH");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NINST_SLOTS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V30*/ meltfptr[29]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (8),
				( /*_.SYSLOTS__V26*/ meltfptr[25]),
				"NINST_SLOTS");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDSY_NAMESTR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V30*/ meltfptr[29]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V30*/ meltfptr[29]), (9),
				( /*_.SYNAMSTR__V21*/ meltfptr[15]),
				"NDSY_NAMESTR");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V30*/ meltfptr[29],
					"newly made instance");
	  ;
	  /*_.SYDATA__V29*/ meltfptr[28] = /*_.INST__V30*/ meltfptr[29];;
	  /*^compute */
   /*_#OBJ_NUM__L9*/ meltfnum[8] =
	    (melt_obj_num
	     ((melt_ptr_t) (( /*!NAMED_NAME */ meltfrout->tabval[9]))));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6397:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.SYSLOTS__V26*/ meltfptr[25]),
				     ( /*_#OBJ_NUM__L9*/ meltfnum[8]),
				     (melt_ptr_t) ( /*_.SYNAMSTRDATA__V23*/
						   meltfptr[22]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6398:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYDATA__V29*/ meltfptr[28];
	    /*_.ADD_NCTX_DATA__V31*/ meltfptr[30] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6399:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYNAMSTRDATA__V23*/ meltfptr[22];
	    /*_.ADD_NCTX_DATA__V32*/ meltfptr[31] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6400:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.VALMAP__V13*/ meltfptr[12]),
				   (meltobject_ptr_t) ( /*_.SYM__V2*/
						       meltfptr[1]),
				   (melt_ptr_t) ( /*_.SYDATA__V29*/
						 meltfptr[28]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6401:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "NCTX_SYMBMAP");
    /*_.NCTX_SYMBMAP__V33*/ meltfptr[32] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_put_mapstrings ((struct meltmapstrings_st *) ( /*_.NCTX_SYMBMAP__V33*/ meltfptr[32]),
				   melt_string_str ((melt_ptr_t)
						    ( /*_.SYNAMSTR__V21*/
						     meltfptr[15])),
				   (melt_ptr_t) ( /*_.SYDATA__V29*/
						 meltfptr[28]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6402:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L10*/ meltfnum[9] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6402:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L11*/ meltfnum[10] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6402:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L11*/ meltfnum[10];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6402;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_symbol_data return sydata";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.SYDATA__V29*/ meltfptr[28];
		    /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34] =
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
		  /*_._IF___V34*/ meltfptr[33] =
		    /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6402:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V35*/ meltfptr[34] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V34*/ meltfptr[33] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6402:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V34*/ meltfptr[33] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6403:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.SYDATA__V29*/ meltfptr[28];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6403:/ locexp");
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
	  /*_.LET___V20*/ meltfptr[16] = /*_.RETURN___V36*/ meltfptr[34];;

	  MELT_LOCATION ("warmelt-normal.melt:6380:/ clear");
	     /*clear *//*_#SYHASH__L7*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTR__V21*/ meltfptr[15] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V22*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTRDATA__V23*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_.CLASS_FIELDS__V25*/ meltfptr[24] = 0;
	  /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L8*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_.SYSLOTS__V26*/ meltfptr[25] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V27*/ meltfptr[26] = 0;
	  /*^clear */
	     /*clear *//*_.MAKE_INTEGERBOX__V28*/ meltfptr[27] = 0;
	  /*^clear */
	     /*clear *//*_.SYDATA__V29*/ meltfptr[28] = 0;
	  /*^clear */
	     /*clear *//*_#OBJ_NUM__L9*/ meltfnum[8] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V31*/ meltfptr[30] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V32*/ meltfptr[31] = 0;
	  /*^clear */
	     /*clear *//*_.NCTX_SYMBMAP__V33*/ meltfptr[32] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V36*/ meltfptr[34] = 0;
	  /*_._IFELSE___V15*/ meltfptr[14] = /*_.LET___V20*/ meltfptr[16];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6376:/ clear");
	     /*clear *//*_.LET___V20*/ meltfptr[16] = 0;
	}
	;
      }
    ;
    /*_.LET___V12*/ meltfptr[8] = /*_._IFELSE___V15*/ meltfptr[14];;

    MELT_LOCATION ("warmelt-normal.melt:6374:/ clear");
	   /*clear *//*_.VALMAP__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.OSYDATA__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6369:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[8];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6369:/ locexp");
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
	   /*clear *//*_.IFCPP___V7*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_SYMBOL_DATA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_115_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_melt
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

  struct meltframe_meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_st
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
#define MELTFRAM_NBVARPTR 34
    melt_ptr_t mcfr_varptr[34];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_st
	 *) meltfirstargp_;
      /* use arguments meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 34; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA nbval 34*/
  meltfram__.mcfr_nbvar = 34 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_KEYWORD_DATA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6409:/ getarg");
 /*_.KEYW__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.SLOC__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.SLOC__V4*/ meltfptr[3])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6411:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6411:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6411:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6411;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_keyword_data keyw=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.KEYW__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V5*/ meltfptr[4] =
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6411:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V5*/ meltfptr[4] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6411:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V5*/ meltfptr[4] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6412:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_.DISCRIM__V8*/ meltfptr[4] =
	((melt_ptr_t)
	 (melt_discr ((melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]))));;
      /*^compute */
   /*_#eqeq__L3*/ meltfnum[1] =
	(( /*_.DISCRIM__V8*/ meltfptr[4]) ==
	 (( /*!CLASS_KEYWORD */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6412:/ cond");
      /*cond */ if ( /*_#eqeq__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6412:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check keywb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6412) ? (6412) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V7*/ meltfptr[5] = /*_._IFELSE___V9*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6412:/ clear");
	     /*clear *//*_.DISCRIM__V8*/ meltfptr[4] = 0;
      /*^clear */
	     /*clear *//*_#eqeq__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6413:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6413:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6413:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6413) ? (6413) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[8] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[4] = /*_._IFELSE___V11*/ meltfptr[8];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6413:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[8] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6414:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NCTX_VALMAP");
  /*_.VALMAP__V13*/ meltfptr[12] = slot;
    };
    ;
 /*_.OSYDATA__V14*/ meltfptr[13] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.VALMAP__V13*/ meltfptr[12]),
			   (meltobject_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6416:/ cond");
    /*cond */ if ( /*_.OSYDATA__V14*/ meltfptr[13])	/*then */
      {
	/*^cond.then */
	/*_._IFELSE___V15*/ meltfptr[14] = /*_.OSYDATA__V14*/ meltfptr[13];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6416:/ cond.else");

	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6417:/ quasiblock");


   /*_#SYHASH__L5*/ meltfnum[1] =
	    (melt_obj_hash ((melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6418:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.SYNAMSTR__V17*/ meltfptr[16] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6422:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V3*/ meltfptr[2];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[2].meltbp_cstring = "discr_string";
	    /*_.NORMAL_PREDEF__V18*/ meltfptr[17] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!DISCR_STRING */ meltfrout->
					 tabval[5])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6421:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[3])), (6), "CLASS_NREP_DATASTRING");
    /*_.INST__V20*/ meltfptr[19] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V20*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (4),
				( /*_.NORMAL_PREDEF__V18*/ meltfptr[17]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NSTR_STRING",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V20*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (5),
				( /*_.SYNAMSTR__V17*/ meltfptr[16]),
				"NSTR_STRING");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
					"newly made instance");
	  ;
	  /*_.SYNAMSTRDATA__V19*/ meltfptr[18] =
	    /*_.INST__V20*/ meltfptr[19];;
	  MELT_LOCATION ("warmelt-normal.melt:6426:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) (( /*!CLASS_KEYWORD */ meltfrout->
			     tabval[1])) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
    /*_.CLASS_FIELDS__V21*/ meltfptr[20] = slot;
	  };
	  ;
   /*_#MULTIPLE_LENGTH__L6*/ meltfnum[0] =
	    (melt_multiple_length
	     ((melt_ptr_t) ( /*_.CLASS_FIELDS__V21*/ meltfptr[20])));;
	  /*^compute */
   /*_.SYSLOTS__V22*/ meltfptr[21] =
	    (meltgc_new_multiple
	     ((meltobject_ptr_t)
	      (( /*!DISCR_MULTIPLE */ meltfrout->tabval[6])),
	      ( /*_#MULTIPLE_LENGTH__L6*/ meltfnum[0])));;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6429:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V3*/ meltfptr[2];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[2].meltbp_cstring = "class_keyword";
	    /*_.NORMAL_PREDEF__V23*/ meltfptr[22] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!CLASS_KEYWORD */ meltfrout->
					 tabval[1])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
   /*_.MAKE_INTEGERBOX__V24*/ meltfptr[23] =
	    (meltgc_new_int
	     ((meltobject_ptr_t)
	      (( /*!DISCR_INTEGER */ meltfrout->tabval[8])),
	      ( /*_#SYHASH__L5*/ meltfnum[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6427:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATAKEYWORD */ meltfrout->tabval[7])), (10), "CLASS_NREP_DATAKEYWORD");
    /*_.INST__V26*/ meltfptr[25] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_NAME",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V26*/ meltfptr[25]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V26*/ meltfptr[25]), (1),
				( /*_.KEYW__V2*/ meltfptr[1]), "NDATA_NAME");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V26*/ meltfptr[25]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V26*/ meltfptr[25]), (4),
				( /*_.NORMAL_PREDEF__V23*/ meltfptr[22]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NINST_HASH",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V26*/ meltfptr[25]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V26*/ meltfptr[25]), (7),
				( /*_.MAKE_INTEGERBOX__V24*/ meltfptr[23]),
				"NINST_HASH");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NINST_SLOTS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V26*/ meltfptr[25]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V26*/ meltfptr[25]), (8),
				( /*_.SYSLOTS__V22*/ meltfptr[21]),
				"NINST_SLOTS");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NDSY_NAMESTR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V26*/ meltfptr[25]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V26*/ meltfptr[25]), (9),
				( /*_.SYNAMSTR__V17*/ meltfptr[16]),
				"NDSY_NAMESTR");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V26*/ meltfptr[25],
					"newly made instance");
	  ;
	  /*_.SYDATA__V25*/ meltfptr[24] = /*_.INST__V26*/ meltfptr[25];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6434:/ locexp");

#if MELT_HAVE_DEBUG
	    if (melt_need_debug (0))
	      melt_dbgshortbacktrace (("normal_keyword_data"), (8));
#endif
	    ;
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6435:/ cppif.then");
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
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6435:/ cond");
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
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6435:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6435;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normal_keyword_data sydata=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.SYDATA__V25*/ meltfptr[24];
		    /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
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
		  /*_._IF___V27*/ meltfptr[26] =
		    /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6435:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V27*/ meltfptr[26] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6435:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V27*/ meltfptr[26] = 0;
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
   /*_#OBJ_NUM__L9*/ meltfnum[7] =
	    (melt_obj_num
	     ((melt_ptr_t) (( /*!NAMED_NAME */ meltfrout->tabval[9]))));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6436:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.SYSLOTS__V22*/ meltfptr[21]),
				     ( /*_#OBJ_NUM__L9*/ meltfnum[7]),
				     (melt_ptr_t) ( /*_.SYNAMSTRDATA__V19*/
						   meltfptr[18]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6437:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYDATA__V25*/ meltfptr[24];
	    /*_.ADD_NCTX_DATA__V29*/ meltfptr[27] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6438:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYNAMSTRDATA__V19*/ meltfptr[18];
	    /*_.ADD_NCTX_DATA__V30*/ meltfptr[26] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6439:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.VALMAP__V13*/ meltfptr[12]),
				   (meltobject_ptr_t) ( /*_.KEYW__V2*/
						       meltfptr[1]),
				   (melt_ptr_t) ( /*_.SYDATA__V25*/
						 meltfptr[24]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6440:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 5, "NCTX_KEYWMAP");
    /*_.NCTX_KEYWMAP__V31*/ meltfptr[30] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_put_mapstrings ((struct meltmapstrings_st *) ( /*_.NCTX_KEYWMAP__V31*/ meltfptr[30]),
				   melt_string_str ((melt_ptr_t)
						    ( /*_.SYNAMSTR__V17*/
						     meltfptr[16])),
				   (melt_ptr_t) ( /*_.SYDATA__V25*/
						 meltfptr[24]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6441:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L10*/ meltfnum[6] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6441:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L10*/ meltfnum[6])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L11*/ meltfnum[10] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6441:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L11*/ meltfnum[10];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6441;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_keyword_data return sydata=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.SYDATA__V25*/ meltfptr[24];
		    /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32] =
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
		  /*_._IF___V32*/ meltfptr[31] =
		    /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6441:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V33*/ meltfptr[32] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V32*/ meltfptr[31] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6441:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V32*/ meltfptr[31] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6442:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.SYDATA__V25*/ meltfptr[24];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6442:/ locexp");
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
	  /*_.LET___V16*/ meltfptr[15] = /*_.RETURN___V34*/ meltfptr[32];;

	  MELT_LOCATION ("warmelt-normal.melt:6417:/ clear");
	     /*clear *//*_#SYHASH__L5*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTR__V17*/ meltfptr[16] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V18*/ meltfptr[17] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTRDATA__V19*/ meltfptr[18] = 0;
	  /*^clear */
	     /*clear *//*_.CLASS_FIELDS__V21*/ meltfptr[20] = 0;
	  /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L6*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_.SYSLOTS__V22*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V23*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_.MAKE_INTEGERBOX__V24*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_.SYDATA__V25*/ meltfptr[24] = 0;
	  /*^clear */
	     /*clear *//*_#OBJ_NUM__L9*/ meltfnum[7] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V29*/ meltfptr[27] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V30*/ meltfptr[26] = 0;
	  /*^clear */
	     /*clear *//*_.NCTX_KEYWMAP__V31*/ meltfptr[30] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V34*/ meltfptr[32] = 0;
	  /*_._IFELSE___V15*/ meltfptr[14] = /*_.LET___V16*/ meltfptr[15];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6416:/ clear");
	     /*clear *//*_.LET___V16*/ meltfptr[15] = 0;
	}
	;
      }
    ;
    /*_.LET___V12*/ meltfptr[8] = /*_._IFELSE___V15*/ meltfptr[14];;

    MELT_LOCATION ("warmelt-normal.melt:6414:/ clear");
	   /*clear *//*_.VALMAP__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.OSYDATA__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6409:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[8];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6409:/ locexp");
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
	   /*clear *//*_.IFCPP___V7*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_KEYWORD_DATA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_116_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS_melt
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

  struct meltframe_meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS_st
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
#define MELTFRAM_NBVARPTR 11
    melt_ptr_t mcfr_varptr[11];
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS_st *)
	meltfirstargp_;
      /* use arguments meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 11; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS nbval 11*/
  meltfram__.mcfr_nbvar = 11 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("CREATE_DATA_SLOTS", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6447:/ getarg");
 /*_.CLA__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6448:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CLA__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_CLASS */ meltfrout->
					    tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6448:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V4*/ meltfptr[3] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6448:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cla"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6448) ? (6448) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V4*/ meltfptr[3] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V3*/ meltfptr[2] = /*_._IFELSE___V4*/ meltfptr[3];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6448:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V3*/ meltfptr[2] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6449:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L2*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6449:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L2*/ meltfnum[0])	/*then */
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
	    MELT_LOCATION ("warmelt-normal.melt:6449:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6449;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "create_data_slots cla";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLA__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[1])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V5*/ meltfptr[3] =
	      /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6449:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V6*/ meltfptr[5] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V5*/ meltfptr[3] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6449:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V5*/ meltfptr[3] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6450:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6451:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CLA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
  /*_.CLASS_FIELDS__V8*/ meltfptr[3] = slot;
    };
    ;
 /*_#MULTIPLE_LENGTH__L4*/ meltfnum[2] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.CLASS_FIELDS__V8*/ meltfptr[3])));;
    /*^compute */
 /*_.TUPSLO__V9*/ meltfptr[8] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[2])),
	( /*_#MULTIPLE_LENGTH__L4*/ meltfnum[2])));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6453:/ cppif.then");
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
   /*_#MELT_NEED_DBG__L5*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6453:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L5*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L6*/ meltfnum[5] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6453:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6453;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "create_data_slots tupslo";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPSLO__V9*/ meltfptr[8];
	      /*_.MELT_DEBUG_FUN__V11*/ meltfptr[10] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[1])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V10*/ meltfptr[9] =
	      /*_.MELT_DEBUG_FUN__V11*/ meltfptr[10];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6453:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V11*/ meltfptr[10] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V10*/ meltfptr[9] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6453:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V10*/ meltfptr[9] = 0;
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
    /*_.LET___V7*/ meltfptr[5] = /*_.TUPSLO__V9*/ meltfptr[8];;

    MELT_LOCATION ("warmelt-normal.melt:6450:/ clear");
	   /*clear *//*_.CLASS_FIELDS__V8*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_#MULTIPLE_LENGTH__L4*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_.TUPSLO__V9*/ meltfptr[8] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6447:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V7*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6447:/ locexp");
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
	   /*clear *//*_.IFCPP___V3*/ meltfptr[2] = 0;
    /*^clear */
	   /*clear *//*_.LET___V7*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("CREATE_DATA_SLOTS", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_117_WARMELTmiNORMAL_CREATE_DATA_SLOTS */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT_melt
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

  struct meltframe_meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT_st
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
#define MELTFRAM_NBVARPTR 9
    melt_ptr_t mcfr_varptr[9];
#define MELTFRAM_NBVARNUM 3
    long mcfr_varnum[3];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT_st *)
	meltfirstargp_;
      /* use arguments meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 9; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT nbval 9*/
  meltfram__.mcfr_nbvar = 9 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("FILL_DATA_SLOT", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6458:/ getarg");
 /*_.DI__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.FIELD__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.FIELD__V3*/ meltfptr[2])) !=
	      NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.VAL__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.VAL__V4*/ meltfptr[3])) != NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6459:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.DI__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_NREP_DATAINSTANCE */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6459:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V6*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6459:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check di"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6459) ? (6459) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V6*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[4] = /*_._IFELSE___V6*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6459:/ clear");
	     /*clear *//*_#IS_A__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V6*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6460:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.FIELD__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_FIELD */ meltfrout->
					    tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6460:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V8*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6460:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check field"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6460) ? (6460) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V8*/ meltfptr[7] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V7*/ meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6460:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V8*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6461:/ quasiblock");


 /*_#FIX__L3*/ meltfnum[0] =
      (melt_obj_num ((melt_ptr_t) ( /*_.FIELD__V3*/ meltfptr[2])));;
    MELT_LOCATION ("warmelt-normal.melt:6462:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.DI__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NINST_SLOTS");
  /*_.SLOTS__V9*/ meltfptr[7] = slot;
    };
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:6463:/ locexp");
      meltgc_multiple_put_nth ((melt_ptr_t) ( /*_.SLOTS__V9*/ meltfptr[7]),
			       ( /*_#FIX__L3*/ meltfnum[0]),
			       (melt_ptr_t) ( /*_.VAL__V4*/ meltfptr[3]));
    }
    ;

    MELT_LOCATION ("warmelt-normal.melt:6461:/ clear");
	   /*clear *//*_#FIX__L3*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.SLOTS__V9*/ meltfptr[7] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:6458:/ clear");
	   /*clear *//*_.IFCPP___V5*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V7*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("FILL_DATA_SLOT", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_118_WARMELTmiNORMAL_FILL_DATA_SLOT */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE_melt
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

  struct meltframe_meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE_st
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
#define MELTFRAM_NBVARPTR 49
    melt_ptr_t mcfr_varptr[49];
#define MELTFRAM_NBVARNUM 15
    long mcfr_varnum[15];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE_st *)
	meltfirstargp_;
      /* use arguments meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 49; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE nbval 49*/
  meltfram__.mcfr_nbvar = 49 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_QUOTE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6469:/ getarg");
 /*_.RECV__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;

  /*getarg#1 */
  /*^getarg */
  if (meltxargdescr_[0] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.ENV__V3*/ meltfptr[2] =
    (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2])) != NULL);


  /*getarg#2 */
  /*^getarg */
  if (meltxargdescr_[1] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.NCX__V4*/ meltfptr[3] =
    (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3])) != NULL);


  /*getarg#3 */
  /*^getarg */
  if (meltxargdescr_[2] != MELTBPAR_PTR)
    goto meltlab_endgetargs;
 /*_.PSLOC__V5*/ meltfptr[4] =
    (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
  gcc_assert (melt_discr ((melt_ptr_t) ( /*_.PSLOC__V5*/ meltfptr[4])) !=
	      NULL);

  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6470:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6470:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6470:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6470;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_quote recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V6*/ meltfptr[5] =
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6470:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V6*/ meltfptr[5] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6470:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
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
    MELT_LOCATION ("warmelt-normal.melt:6471:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_QUOTE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6471:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6471:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check quote recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6471) ? (6471) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6471:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6472:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6472:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6472:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6472) ? (6472) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V10*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6472:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6473:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:6473:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6473:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6473) ? (6473) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_._IFELSE___V13*/ meltfptr[12];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6473:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[12] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:6474:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normexp_quote"), (10));
#endif
      ;
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6475:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V15*/ meltfptr[14] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6476:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SQUOTED");
  /*_.QUOTED__V16*/ meltfptr[15] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6477:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 10, "NCTX_CURPROC");
  /*_.CURPROC__V17*/ meltfptr[16] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_.DISCRIM__V18*/ meltfptr[17] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.QUOTED__V16*/ meltfptr[15]))));;
    /*^compute */
 /*_#eqeq__L6*/ meltfnum[0] =
      (( /*_.DISCRIM__V18*/ meltfptr[17]) ==
       (( /*!CLASS_SYMBOL */ meltfrout->tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:6480:/ cond");
    /*cond */ if ( /*_#eqeq__L6*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6481:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[2];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^apply.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.PSLOC__V5*/ meltfptr[4];
	    /*_.NORMAL_SYMBOL_DATA__V20*/ meltfptr[19] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_SYMBOL_DATA */ meltfrout->tabval[5])),
			  (melt_ptr_t) ( /*_.QUOTED__V16*/ meltfptr[15]),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	  /*_.NDATA__V19*/ meltfptr[18] =
	    /*_.NORMAL_SYMBOL_DATA__V20*/ meltfptr[19];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6480:/ clear");
	     /*clear *//*_.NORMAL_SYMBOL_DATA__V20*/ meltfptr[19] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
   /*_#IS_INTEGERBOX__L7*/ meltfnum[1] =
	    (melt_magic_discr ((melt_ptr_t) ( /*_.QUOTED__V16*/ meltfptr[15]))
	     == MELTOBMAG_INT);;
	  MELT_LOCATION ("warmelt-normal.melt:6482:/ cond");
	  /*cond */ if ( /*_#IS_INTEGERBOX__L7*/ meltfnum[1])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6483:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6485:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[3];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
		  /*^apply.arg */
		  argtab[1].meltbp_aptr =
		    (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
		  /*^apply.arg */
		  argtab[2].meltbp_cstring = "discr_constant_integer";
		  /*_.NORMAL_PREDEF__V23*/ meltfptr[22] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
				(melt_ptr_t) (( /*!DISCR_CONSTANT_INTEGER */
					       meltfrout->tabval[8])),
				(MELTBPARSTR_PTR MELTBPARSTR_PTR
				 MELTBPARSTR_CSTRING ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:6484:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_NREP_DATABOXEDINTEGER */ meltfrout->tabval[6])), (6), "CLASS_NREP_DATABOXEDINTEGER");
      /*_.INST__V25*/ meltfptr[24] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V25*/
						   meltfptr[24])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V25*/ meltfptr[24]), (4),
				      ( /*_.NORMAL_PREDEF__V23*/
				       meltfptr[22]), "NDATA_DISCRX");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("checkobj putslot  _ @NBOXINT_NUM",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V25*/
						   meltfptr[24])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V25*/ meltfptr[24]), (5),
				      ( /*_.QUOTED__V16*/ meltfptr[15]),
				      "NBOXINT_NUM");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V25*/ meltfptr[24],
					      "newly made instance");
		;
		/*_.NINTDATA__V24*/ meltfptr[23] =
		  /*_.INST__V25*/ meltfptr[24];;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6488:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NINTDATA__V24*/ meltfptr[23];
		  /*_.ADD_NCTX_DATA__V26*/ meltfptr[25] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!ADD_NCTX_DATA */ meltfrout->tabval[9])),
				(melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		/*_.LET___V22*/ meltfptr[21] =
		  /*_.NINTDATA__V24*/ meltfptr[23];;

		MELT_LOCATION ("warmelt-normal.melt:6483:/ clear");
	       /*clear *//*_.NORMAL_PREDEF__V23*/ meltfptr[22] = 0;
		/*^clear */
	       /*clear *//*_.NINTDATA__V24*/ meltfptr[23] = 0;
		/*^clear */
	       /*clear *//*_.ADD_NCTX_DATA__V26*/ meltfptr[25] = 0;
		/*_._IFELSE___V21*/ meltfptr[19] =
		  /*_.LET___V22*/ meltfptr[21];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6482:/ clear");
	       /*clear *//*_.LET___V22*/ meltfptr[21] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

	      /*^block */
	      /*anyblock */
	      {


		MELT_CHECK_SIGNAL ();
		;
     /*_#IS_STRING__L8*/ meltfnum[7] =
		  (melt_magic_discr
		   ((melt_ptr_t) ( /*_.QUOTED__V16*/ meltfptr[15])) ==
		   MELTOBMAG_STRING);;
		MELT_LOCATION ("warmelt-normal.melt:6491:/ cond");
		/*cond */ if ( /*_#IS_STRING__L8*/ meltfnum[7])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      MELT_LOCATION ("warmelt-normal.melt:6492:/ quasiblock");



		      MELT_CHECK_SIGNAL ();
		      ;

		      MELT_CHECK_SIGNAL ();
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6494:/ apply");
		      /*apply */
		      {
			union meltparam_un argtab[3];
			memset (&argtab, 0, sizeof (argtab));
			/*^apply.arg */
			argtab[0].meltbp_aptr =
			  (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
			/*^apply.arg */
			argtab[1].meltbp_aptr =
			  (melt_ptr_t *) & /*_.SLOC__V15*/ meltfptr[14];
			/*^apply.arg */
			argtab[2].meltbp_cstring = "discr_string";
			/*_.NORMAL_PREDEF__V29*/ meltfptr[25] =
			  melt_apply ((meltclosure_ptr_t)
				      (( /*!NORMAL_PREDEF */ meltfrout->
					tabval[7])),
				      (melt_ptr_t) (( /*!DISCR_STRING */
						     meltfrout->tabval[11])),
				      (MELTBPARSTR_PTR MELTBPARSTR_PTR
				       MELTBPARSTR_CSTRING ""), argtab, "",
				      (union meltparam_un *) 0);
		      }
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6493:/ quasiblock");


		      /*^rawallocobj */
		      /*rawallocobj */
		      {
			melt_ptr_t newobj = 0;
			melt_raw_object_create (newobj,
						(melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[10])), (6), "CLASS_NREP_DATASTRING");
	/*_.INST__V31*/ meltfptr[30] =
			  newobj;
		      };
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("checkobj putslot  _ @NDATA_DISCRX",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.INST__V31*/
							 meltfptr[30])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.INST__V31*/ meltfptr[30]),
					    (4),
					    ( /*_.NORMAL_PREDEF__V29*/
					     meltfptr[25]), "NDATA_DISCRX");
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("checkobj putslot  _ @NSTR_STRING",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.INST__V31*/
							 meltfptr[30])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.INST__V31*/ meltfptr[30]),
					    (5),
					    ( /*_.QUOTED__V16*/ meltfptr[15]),
					    "NSTR_STRING");
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.INST__V31*/
						    meltfptr[30],
						    "newly made instance");
		      ;
		      /*_.NSTRDATA__V30*/ meltfptr[21] =
			/*_.INST__V31*/ meltfptr[30];;

		      MELT_CHECK_SIGNAL ();
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6497:/ apply");
		      /*apply */
		      {
			union meltparam_un argtab[1];
			memset (&argtab, 0, sizeof (argtab));
			/*^apply.arg */
			argtab[0].meltbp_aptr =
			  (melt_ptr_t *) & /*_.NSTRDATA__V30*/ meltfptr[21];
			/*_.ADD_NCTX_DATA__V32*/ meltfptr[31] =
			  melt_apply ((meltclosure_ptr_t)
				      (( /*!ADD_NCTX_DATA */ meltfrout->
					tabval[9])),
				      (melt_ptr_t) ( /*_.NCX__V4*/
						    meltfptr[3]),
				      (MELTBPARSTR_PTR ""), argtab, "",
				      (union meltparam_un *) 0);
		      }
		      ;
		      /*_.LET___V28*/ meltfptr[23] =
			/*_.NSTRDATA__V30*/ meltfptr[21];;

		      MELT_LOCATION ("warmelt-normal.melt:6492:/ clear");
		 /*clear *//*_.NORMAL_PREDEF__V29*/ meltfptr[25] = 0;
		      /*^clear */
		 /*clear *//*_.NSTRDATA__V30*/ meltfptr[21] = 0;
		      /*^clear */
		 /*clear *//*_.ADD_NCTX_DATA__V32*/ meltfptr[31] = 0;
		      /*_._IFELSE___V27*/ meltfptr[22] =
			/*_.LET___V28*/ meltfptr[23];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6491:/ clear");
		 /*clear *//*_.LET___V28*/ meltfptr[23] = 0;
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

		    /*^block */
		    /*anyblock */
		    {


#if MELT_HAVE_DEBUG
		      MELT_LOCATION ("warmelt-normal.melt:6502:/ cppif.then");
		      /*^block */
		      /*anyblock */
		      {


			MELT_CHECK_SIGNAL ();
			;
			/*^cond */
			/*cond */ if (( /*nil */ NULL))	/*then */
			  {
			    /*^cond.then */
			    /*_._IFELSE___V34*/ meltfptr[21] =
			      ( /*nil */ NULL);;
			  }
			else
			  {
			    MELT_LOCATION
			      ("warmelt-normal.melt:6502:/ cond.else");

			    /*^block */
			    /*anyblock */
			    {




			      {
				/*^locexp */
				melt_assert_failed (("unexpected quoted stuff"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6502) ? (6502) : __LINE__, __FUNCTION__);
				;
			      }
			      ;
		     /*clear *//*_._IFELSE___V34*/ meltfptr[21] = 0;
			      /*epilog */
			    }
			    ;
			  }
			;
			/*^compute */
			/*_.IFCPP___V33*/ meltfptr[25] =
			  /*_._IFELSE___V34*/ meltfptr[21];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6502:/ clear");
		   /*clear *//*_._IFELSE___V34*/ meltfptr[21] = 0;
		      }

#else /*MELT_HAVE_DEBUG */
		      /*^cppif.else */
		      /*_.IFCPP___V33*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6499:/ quasiblock");


		      /*_.PROGN___V35*/ meltfptr[31] =
			/*_.IFCPP___V33*/ meltfptr[25];;
		      /*^compute */
		      /*_._IFELSE___V27*/ meltfptr[22] =
			/*_.PROGN___V35*/ meltfptr[31];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6491:/ clear");
		 /*clear *//*_.IFCPP___V33*/ meltfptr[25] = 0;
		      /*^clear */
		 /*clear *//*_.PROGN___V35*/ meltfptr[31] = 0;
		    }
		    ;
		  }
		;
		/*_._IFELSE___V21*/ meltfptr[19] =
		  /*_._IFELSE___V27*/ meltfptr[22];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6482:/ clear");
	       /*clear *//*_#IS_STRING__L8*/ meltfnum[7] = 0;
		/*^clear */
	       /*clear *//*_._IFELSE___V27*/ meltfptr[22] = 0;
	      }
	      ;
	    }
	  ;
	  /*_.NDATA__V19*/ meltfptr[18] = /*_._IFELSE___V21*/ meltfptr[19];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6480:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L7*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_._IFELSE___V21*/ meltfptr[19] = 0;
	}
	;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6506:/ cppif.then");
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
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6506:/ cond");
      /*cond */ if ( /*_#MELT_NEED_DBG__L9*/ meltfnum[7])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

     /*_#MELT_CALLCOUNT__L10*/ meltfnum[1] =
	      /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
	      meltcallcount	/* melt_callcount debugging */
#else
	      0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
	      ;;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6506:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6506;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_quote ndata=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NDATA__V19*/ meltfptr[18];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n.. curproc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CURPROC__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[21] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V36*/ meltfptr[23] =
	      /*_.MELT_DEBUG_FUN__V37*/ meltfptr[21];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6506:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V37*/ meltfptr[21] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V36*/ meltfptr[23] = NULL;;
	}
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:6506:/ locexp");
	/*void */ (void) 0;
      }
      ;
      /*^quasiblock */


      /*epilog */

      /*^clear */
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IF___V36*/ meltfptr[23] = 0;
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
 /*_#IS_A__L11*/ meltfnum[1] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V17*/ meltfptr[16]),
			   (melt_ptr_t) (( /*!CLASS_NREP_ROUTPROC */
					  meltfrout->tabval[12])));;
    MELT_LOCATION ("warmelt-normal.melt:6507:/ cond");
    /*cond */ if ( /*_#IS_A__L11*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6508:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6509:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_CONSTANT */
						   meltfrout->tabval[13])),
				    (4), "CLASS_NREP_CONSTANT");
    /*_.INST__V41*/ meltfptr[19] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V41*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V41*/ meltfptr[19]), (0),
				( /*_.SLOC__V15*/ meltfptr[14]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCONST_SVAL",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V41*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V41*/ meltfptr[19]), (1),
				( /*_.QUOTED__V16*/ meltfptr[15]),
				"NCONST_SVAL");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCONST_DATA",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V41*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V41*/ meltfptr[19]), (3),
				( /*_.NDATA__V19*/ meltfptr[18]),
				"NCONST_DATA");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("checkobj putslot  _ @NCONST_PROC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V41*/ meltfptr[19]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V41*/ meltfptr[19]), (2),
				( /*_.CURPROC__V17*/ meltfptr[16]),
				"NCONST_PROC");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V41*/ meltfptr[19],
					"newly made instance");
	  ;
	  /*_.NCONST__V40*/ meltfptr[22] = /*_.INST__V41*/ meltfptr[19];;
	  MELT_LOCATION ("warmelt-normal.melt:6515:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURPROC__V17*/
					       meltfptr[16]),
					      (melt_ptr_t) (( /*!CLASS_NREP_CLOSPROC */ meltfrout->tabval[14])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURPROC__V17*/ meltfptr[16]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 5, "NRCLOP_CONSTLIST");
     /*_.NRCLOP_CONSTLIST__V42*/ meltfptr[21] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

    /*_.NRCLOP_CONSTLIST__V42*/ meltfptr[21] = NULL;;
	    }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6515:/ locexp");
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRCLOP_CONSTLIST__V42*/ meltfptr[21]),
				(melt_ptr_t) ( /*_.NDATA__V19*/
					      meltfptr[18]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6516:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L12*/ meltfnum[7] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6516:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L12*/ meltfnum[7])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L13*/ meltfnum[12] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6516:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L13*/ meltfnum[12];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6516;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_quote in routine nconst=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NCONST__V40*/ meltfptr[22];
		    /*_.MELT_DEBUG_FUN__V44*/ meltfptr[43] =
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
		  /*_._IF___V43*/ meltfptr[23] =
		    /*_.MELT_DEBUG_FUN__V44*/ meltfptr[43];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6516:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[12] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V44*/ meltfptr[43] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V43*/ meltfptr[23] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6516:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V43*/ meltfptr[23] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6517:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.NCONST__V40*/ meltfptr[22];;
	  MELT_LOCATION ("warmelt-normal.melt:6517:/ putxtraresult");
	  if (!meltxrestab_ || !meltxresdescr_)
	    goto meltlabend_rout;
	  if (meltxresdescr_[0] != MELTBPAR_PTR)
	    goto meltlabend_rout;
	  if (meltxrestab_[0].meltbp_aptr)
	    *(meltxrestab_[0].meltbp_aptr) = (melt_ptr_t) (( /*nil */ NULL));
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  /*_.LET___V39*/ meltfptr[31] = /*_.RETURN___V45*/ meltfptr[43];;

	  MELT_LOCATION ("warmelt-normal.melt:6508:/ clear");
	     /*clear *//*_.NCONST__V40*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_.NRCLOP_CONSTLIST__V42*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V45*/ meltfptr[43] = 0;
	  /*_._IFELSE___V38*/ meltfptr[25] = /*_.LET___V39*/ meltfptr[31];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6507:/ clear");
	     /*clear *//*_.LET___V39*/ meltfptr[31] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6519:/ cppif.then");
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
     /*_#MELT_NEED_DBG__L14*/ meltfnum[12] =
	      /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	      ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6519:/ cond");
	    /*cond */ if ( /*_#MELT_NEED_DBG__L14*/ meltfnum[12])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

       /*_#MELT_CALLCOUNT__L15*/ meltfnum[7] =
		    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
		    meltcallcount	/* melt_callcount debugging */
#else
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6519:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L15*/ meltfnum[7];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6519;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_quote in init ndata=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NDATA__V19*/ meltfptr[18];
		    /*_.MELT_DEBUG_FUN__V47*/ meltfptr[22] =
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
		  /*_._IF___V46*/ meltfptr[23] =
		    /*_.MELT_DEBUG_FUN__V47*/ meltfptr[22];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6519:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L15*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V47*/ meltfptr[22] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V46*/ meltfptr[23] = NULL;;
	      }
	    ;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:6519:/ locexp");
	      /*void */ (void) 0;
	    }
	    ;
	    /*^quasiblock */


	    /*epilog */

	    /*^clear */
	       /*clear *//*_#MELT_NEED_DBG__L14*/ meltfnum[12] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V46*/ meltfptr[23] = 0;
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
	  MELT_LOCATION ("warmelt-normal.melt:6520:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.NDATA__V19*/ meltfptr[18];;
	  MELT_LOCATION ("warmelt-normal.melt:6520:/ putxtraresult");
	  if (!meltxrestab_ || !meltxresdescr_)
	    goto meltlabend_rout;
	  if (meltxresdescr_[0] != MELTBPAR_PTR)
	    goto meltlabend_rout;
	  if (meltxrestab_[0].meltbp_aptr)
	    *(meltxrestab_[0].meltbp_aptr) = (melt_ptr_t) (( /*nil */ NULL));
	  ;
	  /*^finalreturn */
	  ;
	  /*finalret */ goto meltlabend_rout;
	  MELT_LOCATION ("warmelt-normal.melt:6518:/ quasiblock");


	  /*_.PROGN___V49*/ meltfptr[43] = /*_.RETURN___V48*/ meltfptr[21];;
	  /*^compute */
	  /*_._IFELSE___V38*/ meltfptr[25] = /*_.PROGN___V49*/ meltfptr[43];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6507:/ clear");
	     /*clear *//*_.RETURN___V48*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V49*/ meltfptr[43] = 0;
	}
	;
      }
    ;
    /*_.LET___V14*/ meltfptr[12] = /*_._IFELSE___V38*/ meltfptr[25];;

    MELT_LOCATION ("warmelt-normal.melt:6475:/ clear");
	   /*clear *//*_.SLOC__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.QUOTED__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.CURPROC__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.DISCRIM__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_#eqeq__L6*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.NDATA__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L11*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V38*/ meltfptr[25] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6469:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6469:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_QUOTE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_119_WARMELTmiNORMAL_NORMEXP_QUOTE */



/**** end of warmelt-normal+04.c ****/
