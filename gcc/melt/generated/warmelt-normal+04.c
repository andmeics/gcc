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
meltrout_90_WARMELTmiNORMAL_LAMBDA_cl27 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_91_WARMELTmiNORMAL_NORMALIZE_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_92_WARMELTmiNORMAL_LAMBDA_cl28 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_93_WARMELTmiNORMAL_NORMEXP_LAMBDA (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_94_WARMELTmiNORMAL_NORMEXP_MULTICALL (meltclosure_ptr_t meltclosp_,
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
meltrout_97_WARMELTmiNORMAL_LAMBDA_cl31 (meltclosure_ptr_t meltclosp_,
					 melt_ptr_t meltfirstargp_,
					 const melt_argdescr_cell_t
					 meltxargdescr_[],
					 union meltparam_un *meltxargtab_,
					 const melt_argdescr_cell_t
					 meltxresdescr_[],
					 union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_98_WARMELTmiNORMAL_NORMEXP_TUPLE (meltclosure_ptr_t meltclosp_,
					   melt_ptr_t meltfirstargp_,
					   const melt_argdescr_cell_t
					   meltxargdescr_[],
					   union meltparam_un *meltxargtab_,
					   const melt_argdescr_cell_t
					   meltxresdescr_[],
					   union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA (meltclosure_ptr_t meltclosp_,
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
meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE (meltclosure_ptr_t meltclosp_,
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
meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM (meltclosure_ptr_t
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
meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST (meltclosure_ptr_t meltclosp_,
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
meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE (meltclosure_ptr_t meltclosp_,
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
meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE (meltclosure_ptr_t
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
meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA (meltclosure_ptr_t meltclosp_,
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
meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA (meltclosure_ptr_t
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
meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS (meltclosure_ptr_t meltclosp_,
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
meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un *meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_121_WARMELTmiNORMAL_NORMEXP_COMMENT (meltclosure_ptr_t meltclosp_,
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
meltrout_122_WARMELTmiNORMAL_NORMEXP_KEYWORD (meltclosure_ptr_t meltclosp_,
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
meltrout_123_WARMELTmiNORMAL_FILL_NORMAL_FORMALBIND (meltclosure_ptr_t
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
meltrout_124_WARMELTmiNORMAL_FILL_NORMAL_FORMALS (meltclosure_ptr_t
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
meltrout_125_WARMELTmiNORMAL_FILL_NORMAL_EXPANSION (meltclosure_ptr_t
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
meltrout_126_WARMELTmiNORMAL_LAMBDA_cl34 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_127_WARMELTmiNORMAL_NORMEXP_DEFPRIMITIVE (meltclosure_ptr_t
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
meltrout_128_WARMELTmiNORMAL_NORMEXP_DEFCITERATOR (meltclosure_ptr_t
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
meltrout_129_WARMELTmiNORMAL_NORMEXP_CITERATION (meltclosure_ptr_t meltclosp_,
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
meltrout_136_WARMELTmiNORMAL_LAMBDA_cl41 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_137_WARMELTmiNORMAL_NORMEXP_DEFCMATCHER (meltclosure_ptr_t
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
meltrout_138_WARMELTmiNORMAL_NORMEXP_DEFUNMATCHER (meltclosure_ptr_t
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
meltrout_139_WARMELTmiNORMAL_NORMEXP_DEFCLASS (meltclosure_ptr_t meltclosp_,
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
meltrout_140_WARMELTmiNORMAL_NORMEXP_DEFINSTANCE (meltclosure_ptr_t
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
meltrout_141_WARMELTmiNORMAL_LAMBDA_cl42 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_142_WARMELTmiNORMAL_NORMEXP_DEFVAR (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_143_WARMELTmiNORMAL_NORMEXP_DEFINE (meltclosure_ptr_t meltclosp_,
					     melt_ptr_t meltfirstargp_,
					     const melt_argdescr_cell_t
					     meltxargdescr_[],
					     union meltparam_un *meltxargtab_,
					     const melt_argdescr_cell_t
					     meltxresdescr_[],
					     union meltparam_un
					     *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_144_WARMELTmiNORMAL_LAMBDA_cl43 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_145_WARMELTmiNORMAL_NORMEXP_DEFSELECTOR (meltclosure_ptr_t
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
meltrout_146_WARMELTmiNORMAL_LAMBDA_cl44 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_147_WARMELTmiNORMAL_NORMAL_EXPORTED_VALUE (meltclosure_ptr_t
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
meltrout_148_WARMELTmiNORMAL_NORMEXP_EXPORT_VALUES (meltclosure_ptr_t
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
meltrout_149_WARMELTmiNORMAL_NORMEXP_EXPORT_SYNONYM (meltclosure_ptr_t
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
meltrout_150_WARMELTmiNORMAL_NORMEXP_EXPORT_CLASS (meltclosure_ptr_t
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
meltrout_151_WARMELTmiNORMAL_LAMBDA_cl45 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_152_WARMELTmiNORMAL_LAMBDA_cl46 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_153_WARMELTmiNORMAL_NORMAL_EXPORTED_MACRO (meltclosure_ptr_t
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
meltrout_154_WARMELTmiNORMAL_NORMEXP_EXPORT_MACRO (meltclosure_ptr_t
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
meltrout_155_WARMELTmiNORMAL_NORMAL_EXPORTED_PATMACRO (meltclosure_ptr_t
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
meltrout_156_WARMELTmiNORMAL_NORMEXP_EXPORT_PATMACRO (meltclosure_ptr_t
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
meltrout_157_WARMELTmiNORMAL_NORMEXP_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_158_WARMELTmiNORMAL_NORMEXP_PARENT_MODULE_ENVIRONMENT
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_159_WARMELTmiNORMAL_NORMEXP_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE
(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[],
union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[],
union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_160_WARMELTmiNORMAL_NORMEXP_FETCH_PREDEFINED (meltclosure_ptr_t
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
meltrout_161_WARMELTmiNORMAL_LAMBDA_cl47 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_162_WARMELTmiNORMAL_NORMEXP_STORE_PREDEFINED (meltclosure_ptr_t
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
meltrout_163_WARMELTmiNORMAL_LAMBDA_cl48 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_);




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_164_WARMELTmiNORMAL_NORMEXP_CHEADER (meltclosure_ptr_t meltclosp_,
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
meltrout_165_WARMELTmiNORMAL_NORMEXP_CIMPLEMENT (meltclosure_ptr_t meltclosp_,
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
meltrout_166_WARMELTmiNORMAL_NORMEXP_USE_PACKAGE_FROM_PKG_CONFIG
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
meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un *meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un *meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST_melt =
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

  struct meltframe_meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST_st
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
#define MELTFRAM_NBVARPTR 115
    melt_ptr_t mcfr_varptr[115];
#define MELTFRAM_NBVARNUM 36
    long mcfr_varnum[36];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 115; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST nbval 115*/
  meltfram__.mcfr_nbvar = 115 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5495:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5496:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:5496:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5496:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check list recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5496) ? (5496) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5496:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:5497:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5497:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5497:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5497) ? (5497) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5497:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:5498:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5498:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5498:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5498) ? (5498) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5498:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:5499:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5499:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5499:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5499;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
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

	    MELT_LOCATION ("warmelt-normal.melt:5499:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5499:/ quasiblock");


      /*_.PROGN___V15*/ meltfptr[13] = /*_._IF___V13*/ meltfptr[12];;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_.PROGN___V15*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5499:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V13*/ meltfptr[12] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V15*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5500:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V17*/ meltfptr[13] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V17*/ meltfptr[13])	/*then */
      {
	/*^cond.then */
	/*_.SLOC__V18*/ meltfptr[17] = /*_.LOCA_LOCATION__V17*/ meltfptr[13];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5500:/ cond.else");

	/*_.SLOC__V18*/ meltfptr[17] = /*_.PSLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5501:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V19*/ meltfptr[18] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5502:/ apply");
    /*apply */
    {
      /*_.CSYMREC__V20*/ meltfptr[19] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[4])),
		    (melt_ptr_t) (( /*!konst_5_LISTREC_ */ meltfrout->
				   tabval[5])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5503:/ apply");
    /*apply */
    {
      /*_.CSYMLIST__V21*/ meltfptr[20] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[4])),
		    (melt_ptr_t) (( /*!konst_6_LIST_ */ meltfrout->
				   tabval[6])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5504:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V18*/ meltfptr[17];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_pair";
      /*_.NORMDISCRPAIR__V22*/ meltfptr[21] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->tabval[8])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5505:/ apply");
    /*apply */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^apply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V18*/ meltfptr[17];
      /*^apply.arg */
      argtab[2].meltbp_cstring = "discr_list";
      /*_.NORMDISCRLIST__V23*/ meltfptr[22] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->tabval[8])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5506:/ apply");
    /*apply */
    {
      /*_.NEWENV__V24*/ meltfptr[23] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!FRESH_ENV */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;
 /*_#NBARGS__L6*/ meltfnum[4] =
      (melt_multiple_length ((melt_ptr_t) ( /*_.SARGS__V19*/ meltfptr[18])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5508:/ msend");
    /*msend */
    {
      union meltparam_un argtab[3];
      memset (&argtab, 0, sizeof (argtab));
      /*^ojbmsend.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.CSYMLIST__V21*/ meltfptr[20];
      /*^ojbmsend.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
      /*^ojbmsend.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V18*/ meltfptr[17];
      /*_.PREPARE_CONSTRUCTOR_BINDING__V25*/ meltfptr[24] =
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
      /*_.CONSBINDTUP__V26*/ meltfptr[25] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_TO_MULTIPLE */ meltfrout->tabval[10])),
		    (melt_ptr_t) ( /*_.PREPARE_CONSTRUCTOR_BINDING__V25*/
				  meltfptr[24]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;
 /*_.RESBINDINGS__V27*/ meltfptr[26] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[12]))));;
    /*^compute */
 /*_.CONSLISTBIND__V28*/ meltfptr[27] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]), (-1)));;
    MELT_LOCATION ("warmelt-normal.melt:5513:/ quasiblock");


    /*^newclosure */
		 /*newclosure *//*_.LAMBDA___V30*/ meltfptr[29] =
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
				      ( /*_.LAMBDA___V30*/ meltfptr[29])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 0 >= 0
		    && 0 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V30*/ meltfptr[29])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V30*/ meltfptr[29])->tabval[0] =
      (melt_ptr_t) ( /*_.SLOC__V18*/ meltfptr[17]);
    ;
    /*_.LAMBDA___V29*/ meltfptr[28] = /*_.LAMBDA___V30*/ meltfptr[29];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5511:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.LAMBDA___V29*/ meltfptr[28];
      /*_.TUPRECLOC__V31*/ meltfptr[30] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!MULTIPLE_MAP */ meltfrout->tabval[13])),
		    (melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5524:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5524:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5524:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5524;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list csymrec=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CSYMREC__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " consbindtup=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSBINDTUP__V26*/ meltfptr[25];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " conslistbind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLISTBIND__V28*/ meltfptr[27];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " tuprecloc=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPRECLOC__V31*/ meltfptr[30];
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] =
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
	    /*_._IF___V33*/ meltfptr[32] =
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5524:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V33*/ meltfptr[32] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5524:/ quasiblock");


      /*_.PROGN___V35*/ meltfptr[33] = /*_._IF___V33*/ meltfptr[32];;
      /*^compute */
      /*_.IFCPP___V32*/ meltfptr[31] = /*_.PROGN___V35*/ meltfptr[33];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5524:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V33*/ meltfptr[32] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V35*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V32*/ meltfptr[31] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5527:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L9*/ meltfnum[7] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[20])));;
      MELT_LOCATION ("warmelt-normal.melt:5527:/ cond");
      /*cond */ if ( /*_#IS_A__L9*/ meltfnum[7])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V37*/ meltfptr[33] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5527:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check conslistbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5527) ? (5527) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V36*/ meltfptr[32] = /*_._IFELSE___V37*/ meltfptr[33];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5527:/ clear");
	     /*clear *//*_#IS_A__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V37*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V36*/ meltfptr[32] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5528:/ quasiblock");


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
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V18*/ meltfptr[17];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V40*/ meltfptr[39];
      /*^multiapply.appl */
      /*_.NARGS__V39*/ meltfptr[38] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[21])),
		    (melt_ptr_t) ( /*_.SARGS__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5531:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5531:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5531:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5531;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V39*/ meltfptr[38];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDINGS__V40*/ meltfptr[39];
	      /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42] =
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
	    /*_._IF___V42*/ meltfptr[41] =
	      /*_.MELT_DEBUG_FUN__V43*/ meltfptr[42];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5531:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[7] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5531:/ quasiblock");


      /*_.PROGN___V44*/ meltfptr[42] = /*_._IF___V42*/ meltfptr[41];;
      /*^compute */
      /*_.IFCPP___V41*/ meltfptr[40] = /*_.PROGN___V44*/ meltfptr[42];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5531:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V42*/ meltfptr[41] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V44*/ meltfptr[42] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V41*/ meltfptr[40] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5532:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L12*/ meltfnum[7] =
	(( /*_.NBINDINGS__V40*/ meltfptr[39]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDINGS__V40*/ meltfptr[39])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5532:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L12*/ meltfnum[7])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V46*/ meltfptr[42] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5532:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5532) ? (5532) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V46*/ meltfptr[42] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V45*/ meltfptr[41] = /*_._IFELSE___V46*/ meltfptr[42];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5532:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L12*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V46*/ meltfptr[42] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V45*/ meltfptr[41] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5533:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V40*/ meltfptr[39];
      /*_.LIST_APPEND2LIST__V47*/ meltfptr[42] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[22])),
		    (melt_ptr_t) ( /*_.RESBINDINGS__V27*/ meltfptr[26]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;
    /*citerblock FOREACH_IN_LIST */
    {
      /* start foreach_in_list meltcit1__EACHLIST */
      for ( /*_.CURPAIRBIND__V48*/ meltfptr[47] =
	   melt_list_first ((melt_ptr_t) /*_.RESBINDINGS__V27*/ meltfptr[26]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIRBIND__V48*/ meltfptr[47])
	   == MELTOBMAG_PAIR;
	   /*_.CURPAIRBIND__V48*/ meltfptr[47] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIRBIND__V48*/ meltfptr[47]))
	{
	  /*_.CURBIND__V49*/ meltfptr[48] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIRBIND__V48*/ meltfptr[47]);



	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5537:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURBIND__V49*/ meltfptr[48];
	    /*_.PUT_ENV__V50*/ meltfptr[49] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!PUT_ENV */ meltfrout->tabval[23])),
			  (melt_ptr_t) ( /*_.NEWENV__V24*/ meltfptr[23]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	}			/* end foreach_in_list meltcit1__EACHLIST */
     /*_.CURPAIRBIND__V48*/ meltfptr[47] = NULL;
     /*_.CURBIND__V49*/ meltfptr[48] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5534:/ clear");
	    /*clear *//*_.CURPAIRBIND__V48*/ meltfptr[47] = 0;
      /*^clear */
	    /*clear *//*_.CURBIND__V49*/ meltfptr[48] = 0;
      /*^clear */
	    /*clear *//*_.PUT_ENV__V50*/ meltfptr[49] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit2__EACHTUP */
      long meltcit2__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V39*/ meltfptr[38]);
      for ( /*_#NIX__L13*/ meltfnum[0] = 0;
	   ( /*_#NIX__L13*/ meltfnum[0] >= 0)
	   && ( /*_#NIX__L13*/ meltfnum[0] < meltcit2__EACHTUP_ln);
	/*_#NIX__L13*/ meltfnum[0]++)
	{
	  /*_.CURNARG__V51*/ meltfptr[50] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V39*/ meltfptr[38]),
			       /*_#NIX__L13*/ meltfnum[0]);




	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5542:/ msend");
	  /*msend */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NEWENV__V24*/ meltfptr[23];
	    /*_.GET_CTYPE__V52*/ meltfptr[51] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURNARG__V51*/ meltfptr[50]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[24])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;
  /*_#exeq__L14*/ meltfnum[7] =
	    (( /*_.GET_CTYPE__V52*/ meltfptr[51]) !=
	     (( /*!CTYPE_VALUE */ meltfrout->tabval[25])));;
	  MELT_LOCATION ("warmelt-normal.melt:5542:/ cond");
	  /*cond */ if ( /*_#exeq__L14*/ meltfnum[7])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:5544:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:5544:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:5544:/ apply");
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
			  argtab[2].meltbp_long = 5544;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_list bad curnarg";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURNARG__V51*/ meltfptr[50];
			  /*_.MELT_DEBUG_FUN__V56*/ meltfptr[55] =
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
			/*_._IF___V55*/ meltfptr[54] =
			  /*_.MELT_DEBUG_FUN__V56*/ meltfptr[55];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5544:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[15] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V56*/ meltfptr[55] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V55*/ meltfptr[54] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5544:/ quasiblock");


		  /*_.PROGN___V57*/ meltfptr[55] =
		    /*_._IF___V55*/ meltfptr[54];;
		  /*^compute */
		  /*_.IFCPP___V54*/ meltfptr[53] =
		    /*_.PROGN___V57*/ meltfptr[55];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5544:/ clear");
		/*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[14] = 0;
		  /*^clear */
		/*clear *//*_._IF___V55*/ meltfptr[54] = 0;
		  /*^clear */
		/*clear *//*_.PROGN___V57*/ meltfptr[55] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V54*/ meltfptr[53] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5545:/ locexp");
		  /* error_plain */
		    melt_error_str ((melt_ptr_t)
				    ( /*_.SLOC__V18*/ meltfptr[17]),
				    ("(LIST ...) arguments should be values"),
				    (melt_ptr_t) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:5546:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5546:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5543:/ quasiblock");


		/*_.PROGN___V59*/ meltfptr[55] =
		  /*_.RETURN___V58*/ meltfptr[54];;
		/*^compute */
		/*_._IF___V53*/ meltfptr[52] =
		  /*_.PROGN___V59*/ meltfptr[55];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5542:/ clear");
	      /*clear *//*_.IFCPP___V54*/ meltfptr[53] = 0;
		/*^clear */
	      /*clear *//*_.RETURN___V58*/ meltfptr[54] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V59*/ meltfptr[55] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V53*/ meltfptr[52] = NULL;;
	    }
	  ;
	  if ( /*_#NIX__L13*/ meltfnum[0] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit2__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5539:/ clear");
	    /*clear *//*_.CURNARG__V51*/ meltfptr[50] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L13*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_.GET_CTYPE__V52*/ meltfptr[51] = 0;
      /*^clear */
	    /*clear *//*_#exeq__L14*/ meltfnum[7] = 0;
      /*^clear */
	    /*clear *//*_._IF___V53*/ meltfptr[52] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5547:/ blockmultialloc");
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
  /*_.CRECLOCC__V61*/ meltfptr[54] =
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
 /*_.NBDY__V62*/ meltfptr[55] =
	(melt_ptr_t) & meltletrec_1_ptr->rtup_1__NBDY;
      meltletrec_1_ptr->rtup_1__NBDY.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
      meltletrec_1_ptr->rtup_1__NBDY.nbval = 1;

      /*iniobj rinst_2__NLETREC */
  /*_.NLETREC__V63*/ meltfptr[62] =
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
  /*_.CLISTBIND__V64*/ meltfptr[63] =
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
  /*_.CLISTLOCC__V65*/ meltfptr[64] =
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
   /*_.CLISTBIND__V66*/ meltfptr[65] =
	(melt_ptr_t) & meltletrec_1_ptr->rpair_5__CLISTBIND_x1;
      meltletrec_1_ptr->rpair_5__CLISTBIND_x1.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_PAIR))));

      /*inilist rlist_6__CLISTBINDLIST */
   /*_.CLISTBINDLIST__V67*/ meltfptr[66] =
	(melt_ptr_t) & meltletrec_1_ptr->rlist_6__CLISTBINDLIST;
      meltletrec_1_ptr->rlist_6__CLISTBINDLIST.discr =
	(meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_LIST))));



      MELT_LOCATION ("warmelt-normal.melt:5548:/ putslot");
      /*putslot */
      melt_assertmsg ("putslot checkobj @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V61*/ meltfptr[54]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V61*/ meltfptr[54]), (0),
			    ( /*_.SLOC__V18*/ meltfptr[17]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_SYMB",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V61*/ meltfptr[54]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V61*/ meltfptr[54]), (1),
			    ( /*_.CSYMREC__V20*/ meltfptr[19]), "NOCC_SYMB");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_CTYP",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V61*/ meltfptr[54]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V61*/ meltfptr[54]), (2),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "NOCC_CTYP");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_BIND",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CRECLOCC__V61*/ meltfptr[54]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CRECLOCC__V61*/ meltfptr[54]), (3),
			    ( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
			    "NOCC_BIND");
      ;
      /*^touch */
      meltgc_touch ( /*_.CRECLOCC__V61*/ meltfptr[54]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5553:/ putuple");
      /*putupl#40 */
      melt_assertmsg ("putupl [:5553] #40 checktup",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NBDY__V62*/ meltfptr[55])) ==
		      MELTOBMAG_MULTIPLE);
      melt_assertmsg ("putupl [:5553] #40 checkoff",
		      (0 >= 0
		       && 0 <
		       melt_multiple_length ((melt_ptr_t)
					     ( /*_.NBDY__V62*/
					      meltfptr[55]))));
      ((meltmultiple_ptr_t) ( /*_.NBDY__V62*/ meltfptr[55]))->tabval[0] =
	(melt_ptr_t) ( /*_.CRECLOCC__V61*/ meltfptr[54]);
      ;
      /*^touch */
      meltgc_touch ( /*_.NBDY__V62*/ meltfptr[55]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5554:/ putslot");
      /*putslot */
      melt_assertmsg ("putslot checkobj @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (0),
			    ( /*_.SLOC__V18*/ meltfptr[17]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NLET_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (1),
			    ( /*_.CONSBINDTUP__V26*/ meltfptr[25]),
			    "NLET_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NLET_BODY",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (2),
			    ( /*_.NBDY__V62*/ meltfptr[55]), "NLET_BODY");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NLETREC_FILL_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (3),
			    (( /*nil */ NULL)), "NLETREC_FILL_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NLETREC_BODY_BINDINGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (4),
			    (( /*nil */ NULL)), "NLETREC_BODY_BINDINGS");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NLETREC_LOCSYMS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.NLETREC__V63*/ meltfptr[62])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.NLETREC__V63*/ meltfptr[62]), (5),
			    ( /*_.TUPRECLOC__V31*/ meltfptr[30]),
			    "NLETREC_LOCSYMS");
      ;
      /*^touch */
      meltgc_touch ( /*_.NLETREC__V63*/ meltfptr[62]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5562:/ putslot");
      /*putslot */
      melt_assertmsg ("putslot checkobj @BINDER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V64*/ meltfptr[63]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V64*/ meltfptr[63]), (0),
			    ( /*_.CSYMLIST__V21*/ meltfptr[20]), "BINDER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LETBIND_TYPE",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V64*/ meltfptr[63]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V64*/ meltfptr[63]), (1),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "LETBIND_TYPE");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LETBIND_EXPR",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V64*/ meltfptr[63]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V64*/ meltfptr[63]), (2),
			    ( /*_.NLETREC__V63*/ meltfptr[62]),
			    "LETBIND_EXPR");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LETBIND_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V64*/ meltfptr[63]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTBIND__V64*/ meltfptr[63]), (3),
			    ( /*_.SLOC__V18*/ meltfptr[17]), "LETBIND_LOC");
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBIND__V64*/ meltfptr[63]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5567:/ putslot");
      /*putslot */
      melt_assertmsg ("putslot checkobj @NREP_LOC",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V65*/ meltfptr[64]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V65*/ meltfptr[64]), (0),
			    ( /*_.SLOC__V18*/ meltfptr[17]), "NREP_LOC");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_SYMB",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V65*/ meltfptr[64]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V65*/ meltfptr[64]), (1),
			    ( /*_.CSYMLIST__V21*/ meltfptr[20]), "NOCC_SYMB");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_CTYP",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V65*/ meltfptr[64]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V65*/ meltfptr[64]), (2),
			    (( /*!CTYPE_VALUE */ meltfrout->tabval[25])),
			    "NOCC_CTYP");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @NOCC_BIND",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTLOCC__V65*/ meltfptr[64]))
		      == MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.CLISTLOCC__V65*/ meltfptr[64]), (3),
			    ( /*_.CLISTBIND__V64*/ meltfptr[63]),
			    "NOCC_BIND");
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTLOCC__V65*/ meltfptr[64]);
      ;
      MELT_LOCATION ("warmelt-normal.melt:5572:/ putpairhead");
      /*putpairhead */
      melt_assertmsg ("putpairhead /d checkpair",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBIND__V66*/ meltfptr[65]))
		      == MELTOBMAG_PAIR);
      ((meltpair_ptr_t) ( /*_.CLISTBIND__V66*/ meltfptr[65]))->hd =
	(melt_ptr_t) ( /*_.CLISTBIND__V64*/ meltfptr[63]);
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBIND__V66*/ meltfptr[65]);
      ;
      /*^putlist */
      /*putlist */
      melt_assertmsg ("putlist checklist",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.CLISTBINDLIST__V67*/
					 meltfptr[66])) == MELTOBMAG_LIST);
      ((meltlist_ptr_t) ( /*_.CLISTBINDLIST__V67*/ meltfptr[66]))->first =
	(meltpair_ptr_t) ( /*_.CLISTBIND__V66*/ meltfptr[65]);
      ((meltlist_ptr_t) ( /*_.CLISTBINDLIST__V67*/ meltfptr[66]))->last =
	(meltpair_ptr_t) ( /*_.CLISTBIND__V66*/ meltfptr[65]);
      ;
      /*^touch */
      meltgc_touch ( /*_.CLISTBINDLIST__V67*/ meltfptr[66]);
      ;
      /*citerblock FOREACH_IN_MULTIPLE */
      {
	/* start foreach_in_multiple meltcit3__EACHTUP */
	long meltcit3__EACHTUP_ln =
	  melt_multiple_length ((melt_ptr_t) /*_.NARGS__V39*/ meltfptr[38]);
	for ( /*_#NIX__L17*/ meltfnum[15] = 0;
	     ( /*_#NIX__L17*/ meltfnum[15] >= 0)
	     && ( /*_#NIX__L17*/ meltfnum[15] < meltcit3__EACHTUP_ln);
	/*_#NIX__L17*/ meltfnum[15]++)
	  {
	    /*_.CURNARG__V68*/ meltfptr[67] =
	      melt_multiple_nth ((melt_ptr_t)
				 ( /*_.NARGS__V39*/ meltfptr[38]),
				 /*_#NIX__L17*/ meltfnum[15]);



	    MELT_LOCATION ("warmelt-normal.melt:5577:/ quasiblock");


   /*_.CURPAIRB__V70*/ meltfptr[69] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]),
		( /*_#NIX__L17*/ meltfnum[15])));;
	    /*^compute */
   /*_#plI__L18*/ meltfnum[14] =
	      (( /*_#NIX__L17*/ meltfnum[15]) + (1));;
	    /*^compute */
   /*_.NEXTB__V71*/ meltfptr[70] =
	      (melt_multiple_nth
	       ((melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]),
		( /*_#plI__L18*/ meltfnum[14])));;

	    {
	      MELT_LOCATION ("warmelt-normal.melt:5580:/ locexp");
	      melt_put_int ((melt_ptr_t) ( /*_.CURPAIRB__V70*/ meltfptr[69]),
			    ( /*_#NIX__L17*/ meltfnum[15]));
	    }
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5581:/ cppif.then");
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
	      MELT_LOCATION ("warmelt-normal.melt:5581:/ cond");
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
		    MELT_LOCATION ("warmelt-normal.melt:5581:/ apply");
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
		      argtab[2].meltbp_long = 5581;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring = "normexp_list curpairb";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURPAIRB__V70*/ meltfptr[69];
		      /*_.MELT_DEBUG_FUN__V74*/ meltfptr[73] =
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
		    /*_._IF___V73*/ meltfptr[72] =
		      /*_.MELT_DEBUG_FUN__V74*/ meltfptr[73];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5581:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[19] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V74*/ meltfptr[73] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V73*/ meltfptr[72] = NULL;;
		}
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5581:/ quasiblock");


	      /*_.PROGN___V75*/ meltfptr[73] = /*_._IF___V73*/ meltfptr[72];;
	      /*^compute */
	      /*_.IFCPP___V72*/ meltfptr[71] =
		/*_.PROGN___V75*/ meltfptr[73];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5581:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V73*/ meltfptr[72] = 0;
	      /*^clear */
	       /*clear *//*_.PROGN___V75*/ meltfptr[73] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V72*/ meltfptr[71] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5582:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L21*/ meltfnum[19] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.CURPAIRB__V70*/ meltfptr[69]),
				     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
	      MELT_LOCATION ("warmelt-normal.melt:5582:/ cond");
	      /*cond */ if ( /*_#IS_A__L21*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V77*/ meltfptr[73] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5582:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curpairb"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5582) ? (5582) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V77*/ meltfptr[73] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V76*/ meltfptr[72] =
		/*_._IFELSE___V77*/ meltfptr[73];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5582:/ clear");
	       /*clear *//*_#IS_A__L21*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V77*/ meltfptr[73] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V76*/ meltfptr[72] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5583:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#GET_INT__L22*/ meltfnum[18] =
		(melt_get_int
		 ((melt_ptr_t) ( /*_.CURPAIRB__V70*/ meltfptr[69])));;
	      /*^compute */
     /*_#eqeqI__L23*/ meltfnum[19] =
		(( /*_#GET_INT__L22*/ meltfnum[18]) ==
		 ( /*_#NIX__L17*/ meltfnum[15]));;
	      MELT_LOCATION ("warmelt-normal.melt:5583:/ cond");
	      /*cond */ if ( /*_#eqeqI__L23*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V79*/ meltfptr[78] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5583:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check curpairb objnum"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5583) ? (5583) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V79*/ meltfptr[78] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V78*/ meltfptr[73] =
		/*_._IFELSE___V79*/ meltfptr[78];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5583:/ clear");
	       /*clear *//*_#GET_INT__L22*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_#eqeqI__L23*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V79*/ meltfptr[78] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V78*/ meltfptr[73] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5584:/ cppif.then");
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
	      MELT_LOCATION ("warmelt-normal.melt:5584:/ cond");
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
		    MELT_LOCATION ("warmelt-normal.melt:5584:/ apply");
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
		      argtab[2].meltbp_long = 5584;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring = "normexp_list curnarg=";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURNARG__V68*/ meltfptr[67];
		      /*^apply.arg */
		      argtab[5].meltbp_cstring = " nextb=";
		      /*^apply.arg */
		      argtab[6].meltbp_aptr =
			(melt_ptr_t *) & /*_.NEXTB__V71*/ meltfptr[70];
		      /*_.MELT_DEBUG_FUN__V82*/ meltfptr[81] =
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
		    /*_._IF___V81*/ meltfptr[80] =
		      /*_.MELT_DEBUG_FUN__V82*/ meltfptr[81];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5584:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L25*/ meltfnum[19] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V82*/ meltfptr[81] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V81*/ meltfptr[80] = NULL;;
		}
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5584:/ quasiblock");


	      /*_.PROGN___V83*/ meltfptr[81] = /*_._IF___V81*/ meltfptr[80];;
	      /*^compute */
	      /*_.IFCPP___V80*/ meltfptr[78] =
		/*_.PROGN___V83*/ meltfptr[81];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5584:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L24*/ meltfnum[18] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V81*/ meltfptr[80] = 0;
	      /*^clear */
	       /*clear *//*_.PROGN___V83*/ meltfptr[81] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V80*/ meltfptr[78] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5585:/ cppif.then");
	    /*^block */
	    /*anyblock */
	    {


	      MELT_CHECK_SIGNAL ();
	      ;
     /*_#IS_A__L26*/ meltfnum[19] =
		melt_is_instance_of ((melt_ptr_t)
				     ( /*_.NEXTB__V71*/ meltfptr[70]),
				     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[30])));;
	      MELT_LOCATION ("warmelt-normal.melt:5585:/ cond");
	      /*cond */ if ( /*_#IS_A__L26*/ meltfnum[19])	/*then */
		{
		  /*^cond.then */
		  /*_._IFELSE___V85*/ meltfptr[81] = ( /*nil */ NULL);;
		}
	      else
		{
		  MELT_LOCATION ("warmelt-normal.melt:5585:/ cond.else");

		  /*^block */
		  /*anyblock */
		  {




		    {
		      /*^locexp */
		      melt_assert_failed (("check nextb"),
					  ("warmelt-normal.melt")
					  ? ("warmelt-normal.melt") :
					  __FILE__,
					  (5585) ? (5585) : __LINE__,
					  __FUNCTION__);
		      ;
		    }
		    ;
		 /*clear *//*_._IFELSE___V85*/ meltfptr[81] = 0;
		    /*epilog */
		  }
		  ;
		}
	      ;
	      /*^compute */
	      /*_.IFCPP___V84*/ meltfptr[80] =
		/*_._IFELSE___V85*/ meltfptr[81];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5585:/ clear");
	       /*clear *//*_#IS_A__L26*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IFELSE___V85*/ meltfptr[81] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V84*/ meltfptr[80] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5586:/ quasiblock");


	    /*^cond */
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.NEXTB__V71*/
						 meltfptr[70]),
						(melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[31])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^getslot */
		{
		  melt_ptr_t slot = NULL, obj = NULL;
		  obj =
		    (melt_ptr_t) ( /*_.NEXTB__V71*/ meltfptr[70]) /*=obj*/ ;
		  melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.NEXTSYM__V87*/ meltfptr[86] = slot;
		};
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.NEXTSYM__V87*/ meltfptr[86] = NULL;;
	      }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    /*^compute */
   /*_#IS_A__L27*/ meltfnum[18] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.NEXTB__V71*/ meltfptr[70]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
	    MELT_LOCATION ("warmelt-normal.melt:5587:/ cond");
	    /*cond */ if ( /*_#IS_A__L27*/ meltfnum[18])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5588:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[1];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NLETREC__V63*/ meltfptr[62];
		    /*_.NRECLIST_FIND_LOCSYM__V89*/ meltfptr[88] =
		      melt_apply ((meltclosure_ptr_t)
				  (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				    tabval[32])),
				  (melt_ptr_t) ( /*_.NEXTSYM__V87*/
						meltfptr[86]),
				  (MELTBPARSTR_PTR ""), argtab, "",
				  (union meltparam_un *) 0);
		  }
		  ;
		  /*_.NEXTLOC__V88*/ meltfptr[87] =
		    /*_.NRECLIST_FIND_LOCSYM__V89*/ meltfptr[88];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5587:/ clear");
	       /*clear *//*_.NRECLIST_FIND_LOCSYM__V89*/ meltfptr[88] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

    /*_.NEXTLOC__V88*/ meltfptr[87] = NULL;;
	      }
	    ;

	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5590:/ cond");
	    /*cond */ if (
			   /*ifisa */
			   melt_is_instance_of ((melt_ptr_t)
						( /*_.CURPAIRB__V70*/
						 meltfptr[69]),
						(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])))
	      )			/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @NPAIRB_HEAD",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V70*/
						     meltfptr[69])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V70*/ meltfptr[69]),
					(4),
					( /*_.CURNARG__V68*/ meltfptr[67]),
					"NPAIRB_HEAD");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @NPAIRB_TAIL",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V70*/
						     meltfptr[69])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V70*/ meltfptr[69]),
					(5),
					( /*_.NEXTLOC__V88*/ meltfptr[87]),
					"NPAIRB_TAIL");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @NCONSB_NLETREC",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.CURPAIRB__V70*/
						     meltfptr[69])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.CURPAIRB__V70*/ meltfptr[69]),
					(3),
					( /*_.NLETREC__V63*/ meltfptr[62]),
					"NCONSB_NLETREC");
		  ;
		  /*^touch */
		  meltgc_touch ( /*_.CURPAIRB__V70*/ meltfptr[69]);
		  ;
		  /*^touchobj */

		  melt_dbgtrace_written_object ( /*_.CURPAIRB__V70*/
						meltfptr[69], "put-fields");
		  ;
		  /*epilog */
		}
		;
	      }			/*noelse */
	    ;

#if MELT_HAVE_DEBUG
	    MELT_LOCATION ("warmelt-normal.melt:5593:/ cppif.then");
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
	      MELT_LOCATION ("warmelt-normal.melt:5593:/ cond");
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
		    MELT_LOCATION ("warmelt-normal.melt:5593:/ apply");
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
		      argtab[2].meltbp_long = 5593;
		      /*^apply.arg */
		      argtab[3].meltbp_cstring =
			"normexp_list updated curpairb";
		      /*^apply.arg */
		      argtab[4].meltbp_aptr =
			(melt_ptr_t *) & /*_.CURPAIRB__V70*/ meltfptr[69];
		      /*_.MELT_DEBUG_FUN__V92*/ meltfptr[91] =
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
		    /*_._IF___V91*/ meltfptr[90] =
		      /*_.MELT_DEBUG_FUN__V92*/ meltfptr[91];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5593:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L29*/ meltfnum[28] = 0;
		    /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V92*/ meltfptr[91] = 0;
		  }
		  ;
		}
	      else
		{		/*^cond.else */

      /*_._IF___V91*/ meltfptr[90] = NULL;;
		}
	      ;
	      MELT_LOCATION ("warmelt-normal.melt:5593:/ quasiblock");


	      /*_.PROGN___V93*/ meltfptr[91] = /*_._IF___V91*/ meltfptr[90];;
	      /*^compute */
	      /*_.IFCPP___V90*/ meltfptr[88] =
		/*_.PROGN___V93*/ meltfptr[91];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5593:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L28*/ meltfnum[19] = 0;
	      /*^clear */
	       /*clear *//*_._IF___V91*/ meltfptr[90] = 0;
	      /*^clear */
	       /*clear *//*_.PROGN___V93*/ meltfptr[91] = 0;
	    }

#else /*MELT_HAVE_DEBUG */
	    /*^cppif.else */
	    /*_.IFCPP___V90*/ meltfptr[88] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	    ;
	    /*^compute */
	    /*_.LET___V86*/ meltfptr[81] = /*_.IFCPP___V90*/ meltfptr[88];;

	    MELT_LOCATION ("warmelt-normal.melt:5586:/ clear");
	     /*clear *//*_.NEXTSYM__V87*/ meltfptr[86] = 0;
	    /*^clear */
	     /*clear *//*_#IS_A__L27*/ meltfnum[18] = 0;
	    /*^clear */
	     /*clear *//*_.NEXTLOC__V88*/ meltfptr[87] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V90*/ meltfptr[88] = 0;
	    /*_.LET___V69*/ meltfptr[68] = /*_.LET___V86*/ meltfptr[81];;

	    MELT_LOCATION ("warmelt-normal.melt:5577:/ clear");
	     /*clear *//*_.CURPAIRB__V70*/ meltfptr[69] = 0;
	    /*^clear */
	     /*clear *//*_#plI__L18*/ meltfnum[14] = 0;
	    /*^clear */
	     /*clear *//*_.NEXTB__V71*/ meltfptr[70] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V72*/ meltfptr[71] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V76*/ meltfptr[72] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V78*/ meltfptr[73] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V80*/ meltfptr[78] = 0;
	    /*^clear */
	     /*clear *//*_.IFCPP___V84*/ meltfptr[80] = 0;
	    /*^clear */
	     /*clear *//*_.LET___V86*/ meltfptr[81] = 0;
	    if ( /*_#NIX__L17*/ meltfnum[15] < 0)
	      break;
	  }			/* end  foreach_in_multiple meltcit3__EACHTUP */

	/*citerepilog */

	MELT_LOCATION ("warmelt-normal.melt:5574:/ clear");
	     /*clear *//*_.CURNARG__V68*/ meltfptr[67] = 0;
	/*^clear */
	     /*clear *//*_#NIX__L17*/ meltfnum[15] = 0;
	/*^clear */
	     /*clear *//*_.LET___V69*/ meltfptr[68] = 0;
      }				/*endciterblock FOREACH_IN_MULTIPLE */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5598:/ quasiblock");


  /*_.FIRSTPAIRB__V95*/ meltfptr[91] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]), (0)));;
      /*^compute */
  /*_.LASTPAIRB__V96*/ meltfptr[86] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.CONSBINDTUP__V26*/ meltfptr[25]), (-2)));;

      MELT_CHECK_SIGNAL ();
      ;
      /*^compute */
  /*_#IS_A__L30*/ meltfnum[28] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.FIRSTPAIRB__V95*/ meltfptr[91]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
      MELT_LOCATION ("warmelt-normal.melt:5601:/ cond");
      /*cond */ if ( /*_#IS_A__L30*/ meltfnum[28])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5603:/ getslot");
	    {
	      melt_ptr_t slot = NULL, obj = NULL;
	      obj =
		(melt_ptr_t) ( /*_.FIRSTPAIRB__V95*/ meltfptr[91]) /*=obj*/ ;
	      melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.BINDER__V98*/ meltfptr[88] = slot;
	    };
	    ;
	    /*_.FIRSTPAIRSYMB__V97*/ meltfptr[87] =
	      /*_.BINDER__V98*/ meltfptr[88];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5601:/ clear");
	      /*clear *//*_.BINDER__V98*/ meltfptr[88] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.FIRSTPAIRSYMB__V97*/ meltfptr[87] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      /*^compute */
  /*_#IS_A__L31*/ meltfnum[19] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.LASTPAIRB__V96*/ meltfptr[86]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[29])));;
      MELT_LOCATION ("warmelt-normal.melt:5605:/ cond");
      /*cond */ if ( /*_#IS_A__L31*/ meltfnum[19])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5607:/ getslot");
	    {
	      melt_ptr_t slot = NULL, obj = NULL;
	      obj =
		(melt_ptr_t) ( /*_.LASTPAIRB__V96*/ meltfptr[86]) /*=obj*/ ;
	      melt_object_get_field (slot, obj, 0, "BINDER");
     /*_.BINDER__V100*/ meltfptr[70] = slot;
	    };
	    ;
	    /*_.LASTPAIRSYMB__V99*/ meltfptr[69] =
	      /*_.BINDER__V100*/ meltfptr[70];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5605:/ clear");
	      /*clear *//*_.BINDER__V100*/ meltfptr[70] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.LASTPAIRSYMB__V99*/ meltfptr[69] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5609:/ cond");
      /*cond */ if ( /*_.FIRSTPAIRSYMB__V97*/ meltfptr[87])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5610:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[1];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V63*/ meltfptr[62];
	      /*_.NRECLIST_FIND_LOCSYM__V102*/ meltfptr[72] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
			      tabval[32])),
			    (melt_ptr_t) ( /*_.FIRSTPAIRSYMB__V97*/
					  meltfptr[87]), (MELTBPARSTR_PTR ""),
			    argtab, "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_.FIRSTPAIRLOC__V101*/ meltfptr[71] =
	      /*_.NRECLIST_FIND_LOCSYM__V102*/ meltfptr[72];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5609:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V102*/ meltfptr[72] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.FIRSTPAIRLOC__V101*/ meltfptr[71] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5612:/ cond");
      /*cond */ if ( /*_.LASTPAIRSYMB__V99*/ meltfptr[69])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5613:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[1];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V63*/ meltfptr[62];
	      /*_.NRECLIST_FIND_LOCSYM__V104*/ meltfptr[78] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
			      tabval[32])),
			    (melt_ptr_t) ( /*_.LASTPAIRSYMB__V99*/
					  meltfptr[69]), (MELTBPARSTR_PTR ""),
			    argtab, "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_.LASTPAIRLOC__V103*/ meltfptr[73] =
	      /*_.NRECLIST_FIND_LOCSYM__V104*/ meltfptr[78];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5612:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V104*/ meltfptr[78] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

   /*_.LASTPAIRLOC__V103*/ meltfptr[73] = NULL;;
	}
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5615:/ cond");
      /*cond */ if (
		     /*ifisa */
		     melt_is_instance_of ((melt_ptr_t)
					  ( /*_.CONSLISTBIND__V28*/
					   meltfptr[27]),
					  (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[20])))
	)			/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("putslot checkobj @NLISTB_FIRST",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V28*/
					       meltfptr[27])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
				  (4),
				  ( /*_.FIRSTPAIRLOC__V101*/ meltfptr[71]),
				  "NLISTB_FIRST");
	    ;
	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("putslot checkobj @NLISTB_LAST",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V28*/
					       meltfptr[27])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
				  (5),
				  ( /*_.LASTPAIRLOC__V103*/ meltfptr[73]),
				  "NLISTB_LAST");
	    ;
	    /*^putslot */
	    /*putslot */
	    melt_assertmsg ("putslot checkobj @NCONSB_NLETREC",
			    melt_magic_discr ((melt_ptr_t)
					      ( /*_.CONSLISTBIND__V28*/
					       meltfptr[27])) ==
			    MELTOBMAG_OBJECT);
	    melt_putfield_object (( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
				  (3), ( /*_.NLETREC__V63*/ meltfptr[62]),
				  "NCONSB_NLETREC");
	    ;
	    /*^touch */
	    meltgc_touch ( /*_.CONSLISTBIND__V28*/ meltfptr[27]);
	    ;
	    /*^touchobj */

	    melt_dbgtrace_written_object ( /*_.CONSLISTBIND__V28*/
					  meltfptr[27], "put-fields");
	    ;
	    /*epilog */
	  }
	  ;
	}			/*noelse */
      ;

      {
	MELT_LOCATION ("warmelt-normal.melt:5619:/ locexp");
	melt_put_int ((melt_ptr_t) ( /*_.CONSLISTBIND__V28*/ meltfptr[27]),
		      ( /*_#NBARGS__L6*/ meltfnum[4]));
      }
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5620:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5620:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5620:/ apply");
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
		argtab[2].meltbp_long = 5620;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_list updated conslistbind";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.CONSLISTBIND__V28*/ meltfptr[27];
		/*_.MELT_DEBUG_FUN__V107*/ meltfptr[88] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V106*/ meltfptr[81] =
		/*_.MELT_DEBUG_FUN__V107*/ meltfptr[88];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5620:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L33*/ meltfnum[14] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V107*/ meltfptr[88] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V106*/ meltfptr[81] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5620:/ quasiblock");


	/*_.PROGN___V108*/ meltfptr[70] = /*_._IF___V106*/ meltfptr[81];;
	/*^compute */
	/*_.IFCPP___V105*/ meltfptr[80] = /*_.PROGN___V108*/ meltfptr[70];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5620:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L32*/ meltfnum[18] = 0;
	/*^clear */
	      /*clear *//*_._IF___V106*/ meltfptr[81] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V108*/ meltfptr[70] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V105*/ meltfptr[80] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;
      /*^compute */
      /*_.LET___V94*/ meltfptr[90] = /*_.IFCPP___V105*/ meltfptr[80];;

      MELT_LOCATION ("warmelt-normal.melt:5598:/ clear");
	    /*clear *//*_.FIRSTPAIRB__V95*/ meltfptr[91] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRB__V96*/ meltfptr[86] = 0;
      /*^clear */
	    /*clear *//*_#IS_A__L30*/ meltfnum[28] = 0;
      /*^clear */
	    /*clear *//*_.FIRSTPAIRSYMB__V97*/ meltfptr[87] = 0;
      /*^clear */
	    /*clear *//*_#IS_A__L31*/ meltfnum[19] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRSYMB__V99*/ meltfptr[69] = 0;
      /*^clear */
	    /*clear *//*_.FIRSTPAIRLOC__V101*/ meltfptr[71] = 0;
      /*^clear */
	    /*clear *//*_.LASTPAIRLOC__V103*/ meltfptr[73] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V105*/ meltfptr[80] = 0;

      MELT_CHECK_SIGNAL ();
      ;
  /*_#NULL__L34*/ meltfnum[14] =
	(( /*_.NBINDINGS__V40*/ meltfptr[39]) == NULL);;
      MELT_LOCATION ("warmelt-normal.melt:5623:/ cond");
      /*cond */ if ( /*_#NULL__L34*/ meltfnum[14])	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    MELT_LOCATION ("warmelt-normal.melt:5624:/ compute");
	    /*_.NBINDINGS__V40*/ meltfptr[39] =
	      /*_.SETQ___V110*/ meltfptr[78] =
	      /*_.CLISTBINDLIST__V67*/ meltfptr[66];;
	    /*_._IFELSE___V109*/ meltfptr[72] =
	      /*_.SETQ___V110*/ meltfptr[78];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5623:/ clear");
	      /*clear *//*_.SETQ___V110*/ meltfptr[78] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

	  /*^block */
	  /*anyblock */
	  {




	    {
	      MELT_LOCATION ("warmelt-normal.melt:5625:/ locexp");
	      meltgc_append_list ((melt_ptr_t)
				  ( /*_.NBINDINGS__V40*/ meltfptr[39]),
				  (melt_ptr_t) ( /*_.CLISTBIND__V64*/
						meltfptr[63]));
	    }
	    ;
	      /*clear *//*_._IFELSE___V109*/ meltfptr[72] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5627:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5627:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5627:/ apply");
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
		argtab[2].meltbp_long = 5627;
		/*^apply.arg */
		argtab[3].meltbp_cstring = "normexp_list final nletrec=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NLETREC__V63*/ meltfptr[62];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " clistlocc=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.CLISTLOCC__V65*/ meltfptr[64];
		/*^apply.arg */
		argtab[7].meltbp_cstring = " nbindings=";
		/*^apply.arg */
		argtab[8].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NBINDINGS__V40*/ meltfptr[39];
		/*_.MELT_DEBUG_FUN__V113*/ meltfptr[70] =
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
	      /*_._IF___V112*/ meltfptr[81] =
		/*_.MELT_DEBUG_FUN__V113*/ meltfptr[70];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5627:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L36*/ meltfnum[28] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V113*/ meltfptr[70] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V112*/ meltfptr[81] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5627:/ quasiblock");


	/*_.PROGN___V114*/ meltfptr[91] = /*_._IF___V112*/ meltfptr[81];;
	/*^compute */
	/*_.IFCPP___V111*/ meltfptr[88] = /*_.PROGN___V114*/ meltfptr[91];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5627:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L35*/ meltfnum[18] = 0;
	/*^clear */
	      /*clear *//*_._IF___V112*/ meltfptr[81] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V114*/ meltfptr[91] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V111*/ meltfptr[88] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5629:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.CLISTLOCC__V65*/ meltfptr[64];;
      MELT_LOCATION ("warmelt-normal.melt:5629:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NBINDINGS__V40*/ meltfptr[39]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;
      /*_.LETREC___V60*/ meltfptr[53] = /*_.RETURN___V115*/ meltfptr[86];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5547:/ clear");
	    /*clear *//*_.CRECLOCC__V61*/ meltfptr[54] = 0;
      /*^clear */
	    /*clear *//*_.NBDY__V62*/ meltfptr[55] = 0;
      /*^clear */
	    /*clear *//*_.NLETREC__V63*/ meltfptr[62] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V64*/ meltfptr[63] = 0;
      /*^clear */
	    /*clear *//*_.CLISTLOCC__V65*/ meltfptr[64] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V66*/ meltfptr[65] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBINDLIST__V67*/ meltfptr[66] = 0;
      /*^clear */
	    /*clear *//*_.CRECLOCC__V61*/ meltfptr[54] = 0;
      /*^clear */
	    /*clear *//*_.NBDY__V62*/ meltfptr[55] = 0;
      /*^clear */
	    /*clear *//*_.NLETREC__V63*/ meltfptr[62] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V64*/ meltfptr[63] = 0;
      /*^clear */
	    /*clear *//*_.CLISTLOCC__V65*/ meltfptr[64] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBIND__V66*/ meltfptr[65] = 0;
      /*^clear */
	    /*clear *//*_.CLISTBINDLIST__V67*/ meltfptr[66] = 0;
      /*^clear */
	    /*clear *//*_.LET___V94*/ meltfptr[90] = 0;
      /*^clear */
	    /*clear *//*_#NULL__L34*/ meltfnum[14] = 0;
      /*^clear */
	    /*clear *//*_._IFELSE___V109*/ meltfptr[72] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V111*/ meltfptr[88] = 0;
      /*^clear */
	    /*clear *//*_.RETURN___V115*/ meltfptr[86] = 0;
    }				/*end multiallocblock */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V38*/ meltfptr[33] = /*_.LETREC___V60*/ meltfptr[53];;

    MELT_LOCATION ("warmelt-normal.melt:5528:/ clear");
	   /*clear *//*_.IFCPP___V41*/ meltfptr[40] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V45*/ meltfptr[41] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V47*/ meltfptr[42] = 0;
    /*^clear */
	   /*clear *//*_.LETREC___V60*/ meltfptr[53] = 0;

    /*^clear */
	   /*clear *//*_.NBINDINGS__V40*/ meltfptr[39] = 0;
    /*_.LET___V16*/ meltfptr[12] = /*_.MULTI___V38*/ meltfptr[33];;

    MELT_LOCATION ("warmelt-normal.melt:5500:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V17*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.CSYMREC__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.CSYMLIST__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.NORMDISCRPAIR__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.NORMDISCRLIST__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.NEWENV__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_#NBARGS__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_.PREPARE_CONSTRUCTOR_BINDING__V25*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.CONSBINDTUP__V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.RESBINDINGS__V27*/ meltfptr[26] = 0;
    /*^clear */
	   /*clear *//*_.CONSLISTBIND__V28*/ meltfptr[27] = 0;
    /*^clear */
	   /*clear *//*_.LAMBDA___V29*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.TUPRECLOC__V31*/ meltfptr[30] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V32*/ meltfptr[31] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V36*/ meltfptr[32] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V38*/ meltfptr[33] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5495:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V16*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5495:/ locexp");
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
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V16*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_99_WARMELTmiNORMAL_NORMEXP_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un * meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32_melt =
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

  struct meltframe_meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32_st
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
#define MELTFRAM_NBVARPTR 13
    melt_ptr_t mcfr_varptr[13];
#define MELTFRAM_NBVARNUM 4
    long mcfr_varnum[4];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32_st *)
	meltfirstargp_;
      /* use arguments meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 13; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 nbval 13*/
  meltfram__.mcfr_nbvar = 13 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl32", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5513:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5514:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5514:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5514:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5514;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_list curbind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CURBIND__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:5514:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:5514:/ quasiblock");


      /*_.PROGN___V6*/ meltfptr[4] = /*_._IF___V4*/ meltfptr[3];;
      /*^compute */
      /*_.IFCPP___V3*/ meltfptr[2] = /*_.PROGN___V6*/ meltfptr[4];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5514:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V4*/ meltfptr[3] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V6*/ meltfptr[4] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V3*/ meltfptr[2] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5515:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[2] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CURBIND__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5515:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[2])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V8*/ meltfptr[4] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5515:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check curbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5515) ? (5515) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V7*/ meltfptr[3] = /*_._IFELSE___V8*/ meltfptr[4];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5515:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[2] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V8*/ meltfptr[4] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5517:/ cond");
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
   /*_.NCONSB_LOC__V9*/ meltfptr[4] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NCONSB_LOC__V9*/ meltfptr[4] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5517:/ cond");
    /*cond */ if ( /*_.NCONSB_LOC__V9*/ meltfptr[4])	/*then */
      {
	/*^cond.then */
	/*_.OR___V10*/ meltfptr[9] = /*_.NCONSB_LOC__V9*/ meltfptr[4];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5517:/ cond.else");

	/*_.OR___V10*/ meltfptr[9] = ( /*~SLOC */ meltfclos->tabval[0]);;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5519:/ cond");
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
   /*_.BINDER__V11*/ meltfptr[10] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BINDER__V11*/ meltfptr[10] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5516:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[2])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V13*/ meltfptr[12] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (0),
			  ( /*_.OR___V10*/ meltfptr[9]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (2),
			  (( /*!CTYPE_VALUE */ meltfrout->tabval[3])),
			  "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NOCC_SYMB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (1),
			  ( /*_.BINDER__V11*/ meltfptr[10]), "NOCC_SYMB");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V13*/ meltfptr[12])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V13*/ meltfptr[12]), (3),
			  ( /*_.CURBIND__V2*/ meltfptr[1]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V13*/ meltfptr[12],
				  "newly made instance");
    ;
    /*_.INST___V12*/ meltfptr[11] = /*_.INST__V13*/ meltfptr[12];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5513:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.INST___V12*/ meltfptr[11];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5513:/ locexp");
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
	   /*clear *//*_.IFCPP___V7*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_.NCONSB_LOC__V9*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.OR___V10*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.BINDER__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.INST___V12*/ meltfptr[11] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("LAMBDA_cl32", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_100_WARMELTmiNORMAL_LAMBDA_cl32 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_melt
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

  struct meltframe_meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_st
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
#define MELTFRAM_NBVARPTR 105
    melt_ptr_t mcfr_varptr[105];
#define MELTFRAM_NBVARNUM 30
    long mcfr_varnum[30];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_st
	 *) meltfirstargp_;
      /* use arguments meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 105; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION nbval 105*/
  meltfram__.mcfr_nbvar = 105 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_ARITHMETIC_VARIADIC_OPERATION", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5635:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5636:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5636:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5636:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5636;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5636:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5636:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5636:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5637:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5637:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5637:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5637) ? (5637) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5637:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5638:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5638:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5638:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5638) ? (5638) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5638:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:5639:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5639:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[14] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5639:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5639) ? (5639) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5639:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5640:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V16*/ meltfptr[14] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V16*/ meltfptr[14])	/*then */
      {
	/*^cond.then */
	/*_.SLOC__V17*/ meltfptr[16] = /*_.LOCA_LOCATION__V16*/ meltfptr[14];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5640:/ cond.else");

	/*_.SLOC__V17*/ meltfptr[16] = /*_.PSLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5641:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5642:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SARITHVAR_NEUTRAL");
  /*_.SNEUTRAL__V19*/ meltfptr[18] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5643:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 4, "SARITHVAR_PRIMITIVE");
  /*_.SPRIMITIVE__V20*/ meltfptr[19] = slot;
    };
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5645:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5645:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5645:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5645;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation sprimitive=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SPRIMITIVE__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " sneutral=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.SNEUTRAL__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22] =
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
	    /*_._IF___V22*/ meltfptr[21] =
	      /*_.MELT_DEBUG_FUN__V23*/ meltfptr[22];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5645:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:5645:/ quasiblock");


      /*_.PROGN___V24*/ meltfptr[22] = /*_._IF___V22*/ meltfptr[21];;
      /*^compute */
      /*_.IFCPP___V21*/ meltfptr[20] = /*_.PROGN___V24*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5645:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V22*/ meltfptr[21] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V24*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V21*/ meltfptr[20] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5646:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.SPRIMITIVE__V20*/ meltfptr[19]),
			     (melt_ptr_t) (( /*!CLASS_PRIMITIVE */ meltfrout->
					    tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:5646:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V26*/ meltfptr[22] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5646:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check sprimitive"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5646) ? (5646) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V25*/ meltfptr[21] = /*_._IFELSE___V26*/ meltfptr[22];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5646:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V26*/ meltfptr[22] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V25*/ meltfptr[21] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5647:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_INTEGERBOX__L9*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.SNEUTRAL__V19*/ meltfptr[18]))
	 == MELTOBMAG_INT);;
      MELT_LOCATION ("warmelt-normal.melt:5647:/ cond");
      /*cond */ if ( /*_#IS_INTEGERBOX__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V28*/ meltfptr[27] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5647:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check sneutral"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5647) ? (5647) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V28*/ meltfptr[27] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V27*/ meltfptr[22] = /*_._IFELSE___V28*/ meltfptr[27];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5647:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V28*/ meltfptr[27] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V27*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5650:/ quasiblock");


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
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[16];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBINDINGS__V30*/ meltfptr[29];
      /*^multiapply.appl */
      /*_.NARGS__V29*/ meltfptr[27] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[5])),
		    (melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5653:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5653:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5653:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5653;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_arithmetic_variadic_operation nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V29*/ meltfptr[27];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDINGS__V30*/ meltfptr[29];
	      /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32] =
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
	    /*_._IF___V32*/ meltfptr[31] =
	      /*_.MELT_DEBUG_FUN__V33*/ meltfptr[32];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5653:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5653:/ quasiblock");


      /*_.PROGN___V34*/ meltfptr[32] = /*_._IF___V32*/ meltfptr[31];;
      /*^compute */
      /*_.IFCPP___V31*/ meltfptr[30] = /*_.PROGN___V34*/ meltfptr[32];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5653:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V32*/ meltfptr[31] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V34*/ meltfptr[32] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V31*/ meltfptr[30] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5654:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L12*/ meltfnum[0] =
	(( /*_.NBINDINGS__V30*/ meltfptr[29]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDINGS__V30*/ meltfptr[29])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5654:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L12*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V36*/ meltfptr[32] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5654:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5654) ? (5654) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V36*/ meltfptr[32] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V35*/ meltfptr[31] = /*_._IFELSE___V36*/ meltfptr[32];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5654:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V36*/ meltfptr[32] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V35*/ meltfptr[31] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V29*/ meltfptr[27]);
      for ( /*_#ARGIX__L13*/ meltfnum[1] = 0;
	   ( /*_#ARGIX__L13*/ meltfnum[1] >= 0)
	   && ( /*_#ARGIX__L13*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#ARGIX__L13*/ meltfnum[1]++)
	{
	  /*_.CURNARG__V37*/ meltfptr[32] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V29*/ meltfptr[27]),
			       /*_#ARGIX__L13*/ meltfnum[1]);



	  MELT_LOCATION ("warmelt-normal.melt:5659:/ quasiblock");



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
	    /*_.ARGCTYP__V39*/ meltfptr[38] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURNARG__V37*/ meltfptr[32]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[6])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#exeq__L14*/ meltfnum[0] =
	    (( /*_.ARGCTYP__V39*/ meltfptr[38]) !=
	     (( /*!CTYPE_LONG */ meltfrout->tabval[7])));;
	  MELT_LOCATION ("warmelt-normal.melt:5661:/ cond");
	  /*cond */ if ( /*_#exeq__L14*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


		{
		  MELT_LOCATION ("warmelt-normal.melt:5662:/ locexp");
		  /* error_plain */
		    melt_error_str ((melt_ptr_t)
				    ( /*_.SLOC__V17*/ meltfptr[16]),
				    ("variadic arithmetic operation requires only :long arguments"),
				    (melt_ptr_t) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:5663:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5663:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5661:/ quasiblock");


		/*_.PROGN___V42*/ meltfptr[41] =
		  /*_.RETURN___V41*/ meltfptr[40];;
		/*^compute */
		/*_._IF___V40*/ meltfptr[39] =
		  /*_.PROGN___V42*/ meltfptr[41];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5661:/ clear");
	      /*clear *//*_.RETURN___V41*/ meltfptr[40] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V42*/ meltfptr[41] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V40*/ meltfptr[39] = NULL;;
	    }
	  ;
	  /*^compute */
	  /*_.LET___V38*/ meltfptr[37] = /*_._IF___V40*/ meltfptr[39];;

	  MELT_LOCATION ("warmelt-normal.melt:5659:/ clear");
	    /*clear *//*_.ARGCTYP__V39*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_#exeq__L14*/ meltfnum[0] = 0;
	  /*^clear */
	    /*clear *//*_._IF___V40*/ meltfptr[39] = 0;
	  if ( /*_#ARGIX__L13*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5656:/ clear");
	    /*clear *//*_.CURNARG__V37*/ meltfptr[32] = 0;
      /*^clear */
	    /*clear *//*_#ARGIX__L13*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.LET___V38*/ meltfptr[37] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5665:/ block");
    /*anyblock */
    {

      /*^objgoto */
      /*objgoto */ goto mtch1_0;
      ;

    /*objlabel */ mtch1_0:;
      MELT_LOCATION ("warmelt-normal.melt:5667:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_8;
      meltlab_count_8++;
      debugeprintf
	("objlabel_8 mtch1_*CLASS_NORMTESTER_TUPLE/3082bb72. *CLASS_OBJLABELINSTR/2b42b1a6. %ld",
	 meltlab_count_8);
#endif

      ;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V43*/ meltfptr[40] = 0;
      /*^cond */
      /*cond */ if (
		     /*normtestertuple */
	(melt_magic_discr ((melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17])) ==
	 MELTOBMAG_MULTIPLE
	 && ((meltmultiple_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]))->nbval == 1))	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^compute */
    /*_.NTHCOMP__V43*/ meltfptr[40] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]))->
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

	    MELT_LOCATION ("warmelt-normal.melt:5682:/ objgoto");
	    /*objgoto */ goto mtch1_2;
	    ;
	  }
	  ;
	}
      ;

    /*objlabel */ mtch1_1:;
      MELT_LOCATION ("warmelt-normal.melt:5667:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_9;
      meltlab_count_9++;
      debugeprintf
	("objlabel_9 mtch1_*CLASS_NORMTESTER_SUCCESS/3996c723. *CLASS_OBJLABELINSTR/33aff11d. %ld",
	 meltlab_count_9);
#endif

      ;
      /*^quasiblock */


      /*_.S0__V44*/ meltfptr[41] = /*_.NTHCOMP__V43*/ meltfptr[40];;
      MELT_LOCATION ("warmelt-normal.melt:5668:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5671:/ blockmultialloc");
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
 /*_.TUPLREC___V46*/ meltfptr[39] =
	  (melt_ptr_t) & meltletrec_1_ptr->rtup_0__TUPLREC__x12;
	meltletrec_1_ptr->rtup_0__TUPLREC__x12.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_1_ptr->rtup_0__TUPLREC__x12.nbval = 2;


	/*^putuple */
	/*putupl#41 */
	melt_assertmsg ("putupl [:5671] #41 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V46*/ meltfptr[39]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5671] #41 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V46*/
						meltfptr[39]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V46*/ meltfptr[39]))->
	  tabval[0] = (melt_ptr_t) ( /*_.SNEUTRAL__V19*/ meltfptr[18]);
	;
	/*^putuple */
	/*putupl#42 */
	melt_assertmsg ("putupl [:5671] #42 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V46*/ meltfptr[39]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5671] #42 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V46*/
						meltfptr[39]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V46*/ meltfptr[39]))->
	  tabval[1] = (melt_ptr_t) ( /*_.S0__V44*/ meltfptr[41]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V46*/ meltfptr[39]);
	;
	/*_.TUPLE___V45*/ meltfptr[38] = /*_.TUPLREC___V46*/ meltfptr[39];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5671:/ clear");
	     /*clear *//*_.TUPLREC___V46*/ meltfptr[39] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V46*/ meltfptr[39] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5668:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V48*/ meltfptr[47] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V48*/ meltfptr[47])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (1),
			    ( /*_.SLOC__V17*/ meltfptr[16]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V48*/ meltfptr[47])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (3),
			    ( /*_.SPRIMITIVE__V20*/ meltfptr[19]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V48*/ meltfptr[47])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V48*/ meltfptr[47]), (2),
			    ( /*_.TUPLE___V45*/ meltfptr[38]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V48*/ meltfptr[47],
				    "newly made instance");
      ;
      /*_.SPRIM__V47*/ meltfptr[39] = /*_.INST__V48*/ meltfptr[47];;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5673:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5673:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5673:/ apply");
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
		argtab[2].meltbp_long = 5673;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation unary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V47*/ meltfptr[39];
		/*_.MELT_DEBUG_FUN__V51*/ meltfptr[50] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V50*/ meltfptr[49] =
		/*_.MELT_DEBUG_FUN__V51*/ meltfptr[50];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5673:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L16*/ meltfnum[15] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V51*/ meltfptr[50] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V50*/ meltfptr[49] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5673:/ quasiblock");


	/*_.PROGN___V52*/ meltfptr[50] = /*_._IF___V50*/ meltfptr[49];;
	/*^compute */
	/*_.IFCPP___V49*/ meltfptr[48] = /*_.PROGN___V52*/ meltfptr[50];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5673:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L15*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_._IF___V50*/ meltfptr[49] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V52*/ meltfptr[50] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V49*/ meltfptr[48] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5674:/ quasiblock");


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
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V54*/ meltfptr[50];
	/*^multiapply.appl */
	/*_.NREALARGS__V53*/ meltfptr[49] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V47*/ meltfptr[39]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5677:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5677:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5677:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[7];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[0];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5677;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation unary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V53*/ meltfptr[49];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V54*/ meltfptr[50];
		/*_.MELT_DEBUG_FUN__V57*/ meltfptr[56] =
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
	      /*_._IF___V56*/ meltfptr[55] =
		/*_.MELT_DEBUG_FUN__V57*/ meltfptr[56];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5677:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[0] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V57*/ meltfptr[56] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V56*/ meltfptr[55] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5677:/ quasiblock");


	/*_.PROGN___V58*/ meltfptr[56] = /*_._IF___V56*/ meltfptr[55];;
	/*^compute */
	/*_.IFCPP___V55*/ meltfptr[54] = /*_.PROGN___V58*/ meltfptr[56];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5677:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IF___V56*/ meltfptr[55] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V58*/ meltfptr[56] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V55*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5679:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V53*/ meltfptr[49];;
      MELT_LOCATION ("warmelt-normal.melt:5679:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V54*/ meltfptr[50]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5680:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5674:/ clear");
	    /*clear *//*_.IFCPP___V55*/ meltfptr[54] = 0;
      /*^clear */
	    /*clear *//*_.RETURN___V59*/ meltfptr[55] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V54*/ meltfptr[50] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5668:/ clear");
	    /*clear *//*_.TUPLE___V45*/ meltfptr[38] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V47*/ meltfptr[39] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V49*/ meltfptr[48] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5667:/ clear");
	    /*clear *//*_.S0__V44*/ meltfptr[41] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1_2:;
      MELT_LOCATION ("warmelt-normal.melt:5682:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_10;
      meltlab_count_10++;
      debugeprintf
	("objlabel_10 mtch1_*CLASS_NORMTESTER_TUPLE/2789740e. *CLASS_OBJLABELINSTR/176cecb3. %ld",
	 meltlab_count_10);
#endif

      ;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V60*/ meltfptr[56] = 0;
      /*^clear */
	    /*clear *//*_.NTHCOMP__V61*/ meltfptr[54] = 0;
      /*^cond */
      /*cond */ if (
		     /*normtestertuple */
	(melt_magic_discr ((melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17])) ==
	 MELTOBMAG_MULTIPLE
	 && ((meltmultiple_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]))->nbval == 2))	/*then */
	{
	  /*^cond.then */
	  /*^block */
	  /*anyblock */
	  {

	    /*^compute */
    /*_.NTHCOMP__V60*/ meltfptr[56] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]))->
	      tabval[0];;
	    /*^compute */
    /*_.NTHCOMP__V61*/ meltfptr[54] =
	      /*unsafenthcomp */
	      ((meltmultiple_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]))->
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

	    MELT_LOCATION ("warmelt-normal.melt:5697:/ objgoto");
	    /*objgoto */ goto mtch1_4;
	    ;
	  }
	  ;
	}
      ;

    /*objlabel */ mtch1_3:;
      MELT_LOCATION ("warmelt-normal.melt:5682:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_11;
      meltlab_count_11++;
      debugeprintf
	("objlabel_11 mtch1_*CLASS_NORMTESTER_SUCCESS/3753c6ef. *CLASS_OBJLABELINSTR/13728cd2. %ld",
	 meltlab_count_11);
#endif

      ;
      /*^quasiblock */


      /*_.S0__V62*/ meltfptr[55] = /*_.NTHCOMP__V60*/ meltfptr[56];;
      /*^compute */
      /*_.S1__V63*/ meltfptr[49] = /*_.NTHCOMP__V61*/ meltfptr[54];;
      MELT_LOCATION ("warmelt-normal.melt:5683:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5686:/ blockmultialloc");
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
 /*_.TUPLREC___V65*/ meltfptr[38] =
	  (melt_ptr_t) & meltletrec_2_ptr->rtup_0__TUPLREC__x13;
	meltletrec_2_ptr->rtup_0__TUPLREC__x13.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_2_ptr->rtup_0__TUPLREC__x13.nbval = 2;


	/*^putuple */
	/*putupl#43 */
	melt_assertmsg ("putupl [:5686] #43 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V65*/ meltfptr[38]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5686] #43 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V65*/
						meltfptr[38]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V65*/ meltfptr[38]))->
	  tabval[0] = (melt_ptr_t) ( /*_.S0__V62*/ meltfptr[55]);
	;
	/*^putuple */
	/*putupl#44 */
	melt_assertmsg ("putupl [:5686] #44 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V65*/ meltfptr[38]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5686] #44 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V65*/
						meltfptr[38]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V65*/ meltfptr[38]))->
	  tabval[1] = (melt_ptr_t) ( /*_.S1__V63*/ meltfptr[49]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V65*/ meltfptr[38]);
	;
	/*_.TUPLE___V64*/ meltfptr[50] = /*_.TUPLREC___V65*/ meltfptr[38];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5686:/ clear");
	     /*clear *//*_.TUPLREC___V65*/ meltfptr[38] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V65*/ meltfptr[38] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5683:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V67*/ meltfptr[48] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V67*/ meltfptr[48])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V67*/ meltfptr[48]), (1),
			    ( /*_.SLOC__V17*/ meltfptr[16]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V67*/ meltfptr[48])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V67*/ meltfptr[48]), (3),
			    ( /*_.SPRIMITIVE__V20*/ meltfptr[19]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V67*/ meltfptr[48])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V67*/ meltfptr[48]), (2),
			    ( /*_.TUPLE___V64*/ meltfptr[50]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V67*/ meltfptr[48],
				    "newly made instance");
      ;
      /*_.SPRIM__V66*/ meltfptr[39] = /*_.INST__V67*/ meltfptr[48];;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5688:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5688:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5688:/ apply");
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
		argtab[2].meltbp_long = 5688;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation binary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V66*/ meltfptr[39];
		/*_.MELT_DEBUG_FUN__V70*/ meltfptr[69] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V69*/ meltfptr[38] =
		/*_.MELT_DEBUG_FUN__V70*/ meltfptr[69];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5688:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[15] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V70*/ meltfptr[69] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V69*/ meltfptr[38] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5688:/ quasiblock");


	/*_.PROGN___V71*/ meltfptr[69] = /*_._IF___V69*/ meltfptr[38];;
	/*^compute */
	/*_.IFCPP___V68*/ meltfptr[41] = /*_.PROGN___V71*/ meltfptr[69];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5688:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_._IF___V69*/ meltfptr[38] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V71*/ meltfptr[69] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V68*/ meltfptr[41] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5689:/ quasiblock");


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
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V73*/ meltfptr[69];
	/*^multiapply.appl */
	/*_.NREALARGS__V72*/ meltfptr[38] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V66*/ meltfptr[39]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5692:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5692:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5692:/ apply");
	      /*apply */
	      {
		union meltparam_un argtab[7];
		memset (&argtab, 0, sizeof (argtab));
		/*^apply.arg */
		argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L22*/ meltfnum[0];
		/*^apply.arg */
		argtab[1].meltbp_cstring = "warmelt-normal.melt";
		/*^apply.arg */
		argtab[2].meltbp_long = 5692;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation binary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V72*/ meltfptr[38];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V73*/ meltfptr[69];
		/*_.MELT_DEBUG_FUN__V76*/ meltfptr[75] =
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
	      /*_._IF___V75*/ meltfptr[74] =
		/*_.MELT_DEBUG_FUN__V76*/ meltfptr[75];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5692:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L22*/ meltfnum[0] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V76*/ meltfptr[75] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V75*/ meltfptr[74] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5692:/ quasiblock");


	/*_.PROGN___V77*/ meltfptr[75] = /*_._IF___V75*/ meltfptr[74];;
	/*^compute */
	/*_.IFCPP___V74*/ meltfptr[73] = /*_.PROGN___V77*/ meltfptr[75];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5692:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L21*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IF___V75*/ meltfptr[74] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V77*/ meltfptr[75] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V74*/ meltfptr[73] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5694:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V72*/ meltfptr[38];;
      MELT_LOCATION ("warmelt-normal.melt:5694:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V73*/ meltfptr[69]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5695:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5689:/ clear");
	    /*clear *//*_.IFCPP___V74*/ meltfptr[73] = 0;
      /*^clear */
	    /*clear *//*_.RETURN___V78*/ meltfptr[74] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V73*/ meltfptr[69] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5683:/ clear");
	    /*clear *//*_.TUPLE___V64*/ meltfptr[50] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V66*/ meltfptr[39] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V68*/ meltfptr[41] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5682:/ clear");
	    /*clear *//*_.S0__V62*/ meltfptr[55] = 0;
      /*^clear */
	    /*clear *//*_.S1__V63*/ meltfptr[49] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1_4:;
      MELT_LOCATION ("warmelt-normal.melt:5697:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_12;
      meltlab_count_12++;
      debugeprintf
	("objlabel_12 mtch1_*CLASS_NORMTESTER_SUCCESS/3cde1ed3. *CLASS_OBJLABELINSTR/2a4d53e8. %ld",
	 meltlab_count_12);
#endif

      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5698:/ cppif.then");
      /*^block */
      /*anyblock */
      {


	MELT_CHECK_SIGNAL ();
	;
    /*_#MULTIPLE_LENGTH__L23*/ meltfnum[0] =
	  (melt_multiple_length
	   ((melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17])));;
	/*^compute */
    /*_#gtI__L24*/ meltfnum[15] =
	  (( /*_#MULTIPLE_LENGTH__L23*/ meltfnum[0]) > (2));;
	MELT_LOCATION ("warmelt-normal.melt:5698:/ cond");
	/*cond */ if ( /*_#gtI__L24*/ meltfnum[15])	/*then */
	  {
	    /*^cond.then */
	    /*_._IFELSE___V80*/ meltfptr[73] = ( /*nil */ NULL);;
	  }
	else
	  {
	    MELT_LOCATION ("warmelt-normal.melt:5698:/ cond.else");

	    /*^block */
	    /*anyblock */
	    {




	      {
		/*^locexp */
		melt_assert_failed (("check #args>2"),
				    ("warmelt-normal.melt")
				    ? ("warmelt-normal.melt") : __FILE__,
				    (5698) ? (5698) : __LINE__, __FUNCTION__);
		;
	      }
	      ;
		/*clear *//*_._IFELSE___V80*/ meltfptr[73] = 0;
	      /*epilog */
	    }
	    ;
	  }
	;
	/*^compute */
	/*_.IFCPP___V79*/ meltfptr[75] = /*_._IFELSE___V80*/ meltfptr[73];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5698:/ clear");
	      /*clear *//*_#MULTIPLE_LENGTH__L23*/ meltfnum[0] = 0;
	/*^clear */
	      /*clear *//*_#gtI__L24*/ meltfnum[15] = 0;
	/*^clear */
	      /*clear *//*_._IFELSE___V80*/ meltfptr[73] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V79*/ meltfptr[75] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5699:/ quasiblock");



      MELT_CHECK_SIGNAL ();
      ;
  /*_.MULTIPLE_NTH__V81*/ meltfptr[74] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]), (0)));;
      /*^compute */
  /*_.MULTIPLE_NTH__V82*/ meltfptr[38] =
	(melt_multiple_nth
	 ((melt_ptr_t) ( /*_.SARGS__V18*/ meltfptr[17]), (1)));;
      MELT_LOCATION ("warmelt-normal.melt:5702:/ blockmultialloc");
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
 /*_.TUPLREC___V84*/ meltfptr[50] =
	  (melt_ptr_t) & meltletrec_3_ptr->rtup_0__TUPLREC__x14;
	meltletrec_3_ptr->rtup_0__TUPLREC__x14.discr =
	  (meltobject_ptr_t) (((melt_ptr_t) (MELT_PREDEF (DISCR_MULTIPLE))));
	meltletrec_3_ptr->rtup_0__TUPLREC__x14.nbval = 2;


	/*^putuple */
	/*putupl#45 */
	melt_assertmsg ("putupl [:5702] #45 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V84*/ meltfptr[50]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5702] #45 checkoff",
			(0 >= 0
			 && 0 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V84*/
						meltfptr[50]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V84*/ meltfptr[50]))->
	  tabval[0] = (melt_ptr_t) ( /*_.MULTIPLE_NTH__V81*/ meltfptr[74]);
	;
	/*^putuple */
	/*putupl#46 */
	melt_assertmsg ("putupl [:5702] #46 checktup",
			melt_magic_discr ((melt_ptr_t)
					  ( /*_.TUPLREC___V84*/ meltfptr[50]))
			== MELTOBMAG_MULTIPLE);
	melt_assertmsg ("putupl [:5702] #46 checkoff",
			(1 >= 0
			 && 1 <
			 melt_multiple_length ((melt_ptr_t)
					       ( /*_.TUPLREC___V84*/
						meltfptr[50]))));
	((meltmultiple_ptr_t) ( /*_.TUPLREC___V84*/ meltfptr[50]))->
	  tabval[1] = (melt_ptr_t) ( /*_.MULTIPLE_NTH__V82*/ meltfptr[38]);
	;
	/*^touch */
	meltgc_touch ( /*_.TUPLREC___V84*/ meltfptr[50]);
	;
	/*_.TUPLE___V83*/ meltfptr[69] = /*_.TUPLREC___V84*/ meltfptr[50];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5702:/ clear");
	     /*clear *//*_.TUPLREC___V84*/ meltfptr[50] = 0;
	/*^clear */
	     /*clear *//*_.TUPLREC___V84*/ meltfptr[50] = 0;
      }				/*end multiallocblock */
      ;
      MELT_LOCATION ("warmelt-normal.melt:5699:/ quasiblock");


      /*^rawallocobj */
      /*rawallocobj */
      {
	melt_ptr_t newobj = 0;
	melt_raw_object_create (newobj,
				(melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */
					       meltfrout->tabval[8])), (4),
				"CLASS_SOURCE_PRIMITIVE");
   /*_.INST__V86*/ meltfptr[41] =
	  newobj;
      };
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @LOCA_LOCATION",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V86*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V86*/ meltfptr[41]), (1),
			    ( /*_.SLOC__V17*/ meltfptr[16]), "LOCA_LOCATION");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SPRIM_OPER",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V86*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V86*/ meltfptr[41]), (3),
			    ( /*_.SPRIMITIVE__V20*/ meltfptr[19]),
			    "SPRIM_OPER");
      ;
      /*^putslot */
      /*putslot */
      melt_assertmsg ("putslot checkobj @SARGOP_ARGS",
		      melt_magic_discr ((melt_ptr_t)
					( /*_.INST__V86*/ meltfptr[41])) ==
		      MELTOBMAG_OBJECT);
      melt_putfield_object (( /*_.INST__V86*/ meltfptr[41]), (2),
			    ( /*_.TUPLE___V83*/ meltfptr[69]), "SARGOP_ARGS");
      ;
      /*^touchobj */

      melt_dbgtrace_written_object ( /*_.INST__V86*/ meltfptr[41],
				    "newly made instance");
      ;
      /*_.SPRIM__V85*/ meltfptr[39] = /*_.INST__V86*/ meltfptr[41];;
      /*citerblock FOREACH_IN_MULTIPLE */
      {
	/* start foreach_in_multiple meltcit2__EACHTUP */
	long meltcit2__EACHTUP_ln =
	  melt_multiple_length ((melt_ptr_t) /*_.SARGS__V18*/ meltfptr[17]);
	for ( /*_#SIX__L25*/ meltfnum[0] = 0;
	     ( /*_#SIX__L25*/ meltfnum[0] >= 0)
	     && ( /*_#SIX__L25*/ meltfnum[0] < meltcit2__EACHTUP_ln);
	/*_#SIX__L25*/ meltfnum[0]++)
	  {
	    /*_.CURSARG__V87*/ meltfptr[55] =
	      melt_multiple_nth ((melt_ptr_t)
				 ( /*_.SARGS__V18*/ meltfptr[17]),
				 /*_#SIX__L25*/ meltfnum[0]);




	    MELT_CHECK_SIGNAL ();
	    ;
   /*_#gtI__L26*/ meltfnum[15] =
	      (( /*_#SIX__L25*/ meltfnum[0]) > (1));;
	    MELT_LOCATION ("warmelt-normal.melt:5707:/ cond");
	    /*cond */ if ( /*_#gtI__L26*/ meltfnum[15])	/*then */
	      {
		/*^cond.then */
		/*^block */
		/*anyblock */
		{

		  MELT_LOCATION ("warmelt-normal.melt:5708:/ quasiblock");



		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION
		    ("warmelt-normal.melt:5711:/ blockmultialloc");
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
 /*_.TUPLREC___V91*/ meltfptr[90] =
		      (melt_ptr_t) & meltletrec_4_ptr->rtup_0__TUPLREC__x15;
		    meltletrec_4_ptr->rtup_0__TUPLREC__x15.discr =
		      (meltobject_ptr_t) (((melt_ptr_t)
					   (MELT_PREDEF (DISCR_MULTIPLE))));
		    meltletrec_4_ptr->rtup_0__TUPLREC__x15.nbval = 2;


		    /*^putuple */
		    /*putupl#47 */
		    melt_assertmsg ("putupl [:5711] #47 checktup",
				    melt_magic_discr ((melt_ptr_t)
						      ( /*_.TUPLREC___V91*/
						       meltfptr[90])) ==
				    MELTOBMAG_MULTIPLE);
		    melt_assertmsg ("putupl [:5711] #47 checkoff",
				    (0 >= 0
				     && 0 <
				     melt_multiple_length ((melt_ptr_t)
							   ( /*_.TUPLREC___V91*/ meltfptr[90]))));
		    ((meltmultiple_ptr_t)
		     ( /*_.TUPLREC___V91*/ meltfptr[90]))->tabval[0] =
 (melt_ptr_t) ( /*_.SPRIM__V85*/ meltfptr[39]);
		    ;
		    /*^putuple */
		    /*putupl#48 */
		    melt_assertmsg ("putupl [:5711] #48 checktup",
				    melt_magic_discr ((melt_ptr_t)
						      ( /*_.TUPLREC___V91*/
						       meltfptr[90])) ==
				    MELTOBMAG_MULTIPLE);
		    melt_assertmsg ("putupl [:5711] #48 checkoff",
				    (1 >= 0
				     && 1 <
				     melt_multiple_length ((melt_ptr_t)
							   ( /*_.TUPLREC___V91*/ meltfptr[90]))));
		    ((meltmultiple_ptr_t)
		     ( /*_.TUPLREC___V91*/ meltfptr[90]))->tabval[1] =
 (melt_ptr_t) ( /*_.CURSARG__V87*/ meltfptr[55]);
		    ;
		    /*^touch */
		    meltgc_touch ( /*_.TUPLREC___V91*/ meltfptr[90]);
		    ;
		    /*_.TUPLE___V90*/ meltfptr[50] =
		      /*_.TUPLREC___V91*/ meltfptr[90];;
		    /*epilog */

		    MELT_LOCATION ("warmelt-normal.melt:5711:/ clear");
		/*clear *//*_.TUPLREC___V91*/ meltfptr[90] = 0;
		    /*^clear */
		/*clear *//*_.TUPLREC___V91*/ meltfptr[90] = 0;
		  }		/*end multiallocblock */
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5708:/ quasiblock");


		  /*^rawallocobj */
		  /*rawallocobj */
		  {
		    melt_ptr_t newobj = 0;
		    melt_raw_object_create (newobj,
					    (melt_ptr_t) (( /*!CLASS_SOURCE_PRIMITIVE */ meltfrout->tabval[8])), (4), "CLASS_SOURCE_PRIMITIVE");
      /*_.INST__V93*/ meltfptr[92] =
		      newobj;
		  };
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @LOCA_LOCATION",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V93*/
						     meltfptr[92])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V93*/ meltfptr[92]), (1),
					( /*_.SLOC__V17*/ meltfptr[16]),
					"LOCA_LOCATION");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @SPRIM_OPER",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V93*/
						     meltfptr[92])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V93*/ meltfptr[92]), (3),
					( /*_.SPRIMITIVE__V20*/ meltfptr[19]),
					"SPRIM_OPER");
		  ;
		  /*^putslot */
		  /*putslot */
		  melt_assertmsg ("putslot checkobj @SARGOP_ARGS",
				  melt_magic_discr ((melt_ptr_t)
						    ( /*_.INST__V93*/
						     meltfptr[92])) ==
				  MELTOBMAG_OBJECT);
		  melt_putfield_object (( /*_.INST__V93*/ meltfptr[92]), (2),
					( /*_.TUPLE___V90*/ meltfptr[50]),
					"SARGOP_ARGS");
		  ;
		  /*^touchobj */

		  melt_dbgtrace_written_object ( /*_.INST__V93*/ meltfptr[92],
						"newly made instance");
		  ;
		  /*_.NEWSPRIM__V92*/ meltfptr[90] =
		    /*_.INST__V93*/ meltfptr[92];;
		  MELT_LOCATION ("warmelt-normal.melt:5713:/ compute");
		  /*_.SPRIM__V85*/ meltfptr[39] =
		    /*_.SETQ___V94*/ meltfptr[93] =
		    /*_.NEWSPRIM__V92*/ meltfptr[90];;
		  /*_.LET___V89*/ meltfptr[73] =
		    /*_.SETQ___V94*/ meltfptr[93];;

		  MELT_LOCATION ("warmelt-normal.melt:5708:/ clear");
	       /*clear *//*_.TUPLE___V90*/ meltfptr[50] = 0;
		  /*^clear */
	       /*clear *//*_.NEWSPRIM__V92*/ meltfptr[90] = 0;
		  /*^clear */
	       /*clear *//*_.SETQ___V94*/ meltfptr[93] = 0;
		  /*_._IF___V88*/ meltfptr[49] =
		    /*_.LET___V89*/ meltfptr[73];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5707:/ clear");
	       /*clear *//*_.LET___V89*/ meltfptr[73] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

    /*_._IF___V88*/ meltfptr[49] = NULL;;
	      }
	    ;
	    if ( /*_#SIX__L25*/ meltfnum[0] < 0)
	      break;
	  }			/* end  foreach_in_multiple meltcit2__EACHTUP */

	/*citerepilog */

	MELT_LOCATION ("warmelt-normal.melt:5704:/ clear");
	     /*clear *//*_.CURSARG__V87*/ meltfptr[55] = 0;
	/*^clear */
	     /*clear *//*_#SIX__L25*/ meltfnum[0] = 0;
	/*^clear */
	     /*clear *//*_#gtI__L26*/ meltfnum[15] = 0;
	/*^clear */
	     /*clear *//*_._IF___V88*/ meltfptr[49] = 0;
      }				/*endciterblock FOREACH_IN_MULTIPLE */
      ;

#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5715:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5715:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5715:/ apply");
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
		argtab[2].meltbp_long = 5715;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation nary sprim=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.SPRIM__V85*/ meltfptr[39];
		/*_.MELT_DEBUG_FUN__V97*/ meltfptr[93] =
		  melt_apply ((meltclosure_ptr_t)
			      (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			      (melt_ptr_t) (( /*nil */ NULL)),
			      (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			       MELTBPARSTR_PTR ""), argtab, "",
			      (union meltparam_un *) 0);
	      }
	      ;
	      /*_._IF___V96*/ meltfptr[90] =
		/*_.MELT_DEBUG_FUN__V97*/ meltfptr[93];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5715:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L28*/ meltfnum[27] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V97*/ meltfptr[93] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V96*/ meltfptr[90] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5715:/ quasiblock");


	/*_.PROGN___V98*/ meltfptr[73] = /*_._IF___V96*/ meltfptr[90];;
	/*^compute */
	/*_.IFCPP___V95*/ meltfptr[50] = /*_.PROGN___V98*/ meltfptr[73];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5715:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L27*/ meltfnum[26] = 0;
	/*^clear */
	      /*clear *//*_._IF___V96*/ meltfptr[90] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V98*/ meltfptr[73] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V95*/ meltfptr[50] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5716:/ quasiblock");


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
	  (melt_ptr_t *) & /*_.NREALBINDINGS__V100*/ meltfptr[90];
	/*^multiapply.appl */
	/*_.NREALARGS__V99*/ meltfptr[93] =
	  melt_apply ((meltclosure_ptr_t)
		      (( /*!NORMEXP_PRIMITIVE */ meltfrout->tabval[9])),
		      (melt_ptr_t) ( /*_.SPRIM__V85*/ meltfptr[39]),
		      (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		      argtab, (MELTBPARSTR_PTR ""), restab);
      }
      ;
      /*^quasiblock */



#if MELT_HAVE_DEBUG
      MELT_LOCATION ("warmelt-normal.melt:5719:/ cppif.then");
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
	MELT_LOCATION ("warmelt-normal.melt:5719:/ cond");
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
	      MELT_LOCATION ("warmelt-normal.melt:5719:/ apply");
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
		argtab[2].meltbp_long = 5719;
		/*^apply.arg */
		argtab[3].meltbp_cstring =
		  "normexp_arithmetic_variadic_operation nary result nrealargs=";
		/*^apply.arg */
		argtab[4].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALARGS__V99*/ meltfptr[93];
		/*^apply.arg */
		argtab[5].meltbp_cstring = " nrealbindings=";
		/*^apply.arg */
		argtab[6].meltbp_aptr =
		  (melt_ptr_t *) & /*_.NREALBINDINGS__V100*/ meltfptr[90];
		/*_.MELT_DEBUG_FUN__V103*/ meltfptr[102] =
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
	      /*_._IF___V102*/ meltfptr[101] =
		/*_.MELT_DEBUG_FUN__V103*/ meltfptr[102];;
	      /*epilog */

	      MELT_LOCATION ("warmelt-normal.melt:5719:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L30*/ meltfnum[26] = 0;
	      /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V103*/ meltfptr[102] = 0;
	    }
	    ;
	  }
	else
	  {			/*^cond.else */

     /*_._IF___V102*/ meltfptr[101] = NULL;;
	  }
	;
	MELT_LOCATION ("warmelt-normal.melt:5719:/ quasiblock");


	/*_.PROGN___V104*/ meltfptr[102] = /*_._IF___V102*/ meltfptr[101];;
	/*^compute */
	/*_.IFCPP___V101*/ meltfptr[73] = /*_.PROGN___V104*/ meltfptr[102];;
	/*epilog */

	MELT_LOCATION ("warmelt-normal.melt:5719:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L29*/ meltfnum[27] = 0;
	/*^clear */
	      /*clear *//*_._IF___V102*/ meltfptr[101] = 0;
	/*^clear */
	      /*clear *//*_.PROGN___V104*/ meltfptr[102] = 0;
      }

#else /*MELT_HAVE_DEBUG */
      /*^cppif.else */
      /*_.IFCPP___V101*/ meltfptr[73] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
      ;

      MELT_CHECK_SIGNAL ();
      ;
      MELT_LOCATION ("warmelt-normal.melt:5721:/ quasiblock");


      /*_._RETVAL___V1*/ meltfptr[0] = /*_.NREALARGS__V99*/ meltfptr[93];;
      MELT_LOCATION ("warmelt-normal.melt:5721:/ putxtraresult");
      if (!meltxrestab_ || !meltxresdescr_)
	goto meltlabend_rout;
      if (meltxresdescr_[0] != MELTBPAR_PTR)
	goto meltlabend_rout;
      if (meltxrestab_[0].meltbp_aptr)
	*(meltxrestab_[0].meltbp_aptr) =
	  (melt_ptr_t) ( /*_.NREALBINDINGS__V100*/ meltfptr[90]);
      ;
      /*^finalreturn */
      ;
      /*finalret */ goto meltlabend_rout;

      {
	MELT_LOCATION ("warmelt-normal.melt:5722:/ locexp");
	/*void */ (void) 0;
      }
      ;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5716:/ clear");
	    /*clear *//*_.IFCPP___V101*/ meltfptr[73] = 0;
      /*^clear */
	    /*clear *//*_.RETURN___V105*/ meltfptr[101] = 0;

      /*^clear */
	    /*clear *//*_.NREALBINDINGS__V100*/ meltfptr[90] = 0;

      MELT_LOCATION ("warmelt-normal.melt:5699:/ clear");
	    /*clear *//*_.MULTIPLE_NTH__V81*/ meltfptr[74] = 0;
      /*^clear */
	    /*clear *//*_.MULTIPLE_NTH__V82*/ meltfptr[38] = 0;
      /*^clear */
	    /*clear *//*_.TUPLE___V83*/ meltfptr[69] = 0;
      /*^clear */
	    /*clear *//*_.SPRIM__V85*/ meltfptr[39] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V95*/ meltfptr[50] = 0;

      MELT_CHECK_SIGNAL ();
      ;

      MELT_LOCATION ("warmelt-normal.melt:5697:/ clear");
	    /*clear *//*_.IFCPP___V79*/ meltfptr[75] = 0;
      /*^objgoto */
      /*objgoto */ goto mtch1__end /*endmatch */ ;
      ;

    /*objlabel */ mtch1__end:;
      MELT_LOCATION ("warmelt-normal.melt:5665:/ objlabel");
      /* objlabel */
#if MELTDEBUG_MATCHING
      static long meltlab_count_13;
      meltlab_count_13++;
      debugeprintf
	("objlabel_13 mtch1__end_h141583633 *CLASS_OBJLABELINSTR/8706511. %ld",
	 meltlab_count_13);
#endif

      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_LOCATION ("warmelt-normal.melt:5650:/ clear");
	   /*clear *//*_.IFCPP___V31*/ meltfptr[30] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V35*/ meltfptr[31] = 0;

    /*^clear */
	   /*clear *//*_.NBINDINGS__V30*/ meltfptr[29] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5640:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V16*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.SNEUTRAL__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.SPRIMITIVE__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V25*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V27*/ meltfptr[22] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5635:/ clear");
	   /*clear *//*_.IFCPP___V6*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V14*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_ARITHMETIC_VARIADIC_OPERATION", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_101_WARMELTmiNORMAL_NORMEXP_ARITHMETIC_VARIADIC_OPERATION */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_melt
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

  struct meltframe_meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_st
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
  /*meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_st
	 *) meltfirstargp_;
      /* use arguments meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING nbval 14*/
  meltfram__.mcfr_nbvar = 14 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("BADMETH_PREPARE_CONSTRUCTOR_BINDING", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5736:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5737:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5737:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5737:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5737;
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
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
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
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5737:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5737:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5737:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5738:/ cond");
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
   /*_.NAMED_NAME__V10*/ meltfptr[6] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V10*/ meltfptr[6] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5738:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4]),
		      ("invalid constructor binding"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V10*/ meltfptr[6]));
    }
    ;
 /*_.DISCRIM__V11*/ meltfptr[7] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]))));;
    MELT_LOCATION ("warmelt-normal.melt:5740:/ cond");
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
      MELT_LOCATION ("warmelt-normal.melt:5739:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V5*/ meltfptr[4]),
		      ("receiver unprepared to constructor binding"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V12*/ meltfptr[11]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5741:/ cppif.then");
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
	  MELT_LOCATION ("warmelt-normal.melt:5741:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("@$@badmeth_prepare_constructor_binding"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5741) ? (5741) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5741:/ clear");
	     /*clear *//*_._IFELSE___V14*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V13*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5736:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.IFCPP___V13*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5736:/ locexp");
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
	   /*clear *//*_.NAMED_NAME__V10*/ meltfptr[6] = 0;
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
  melt_trace_end ("BADMETH_PREPARE_CONSTRUCTOR_BINDING", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_102_WARMELTmiNORMAL_BADMETH_PREPARE_CONSTRUCTOR_BINDING */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE
  (meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_,
   const melt_argdescr_cell_t meltxargdescr_[],
   union meltparam_un * meltxargtab_,
   const melt_argdescr_cell_t meltxresdescr_[],
   union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_melt
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

  struct meltframe_meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_st
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
#define MELTFRAM_NBVARNUM 2
    long mcfr_varnum[2];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct
	 meltframe_meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE nbval 16*/
  meltfram__.mcfr_nbvar = 16 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("BADMETH_NORMAL_LETREC_CONSTRUCTIVE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5754:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5755:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5755:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5755:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5755;
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
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
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
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5755:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5755:/ quasiblock");


      /*_.PROGN___V11*/ meltfptr[9] = /*_._IF___V9*/ meltfptr[8];;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[7] = /*_.PROGN___V11*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5755:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V11*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5757:/ cond");
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
   /*_.NAMED_NAME__V12*/ meltfptr[8] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V12*/ meltfptr[8] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5757:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
		      ("invalid letrec constructive symbol"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V12*/ meltfptr[8]));
    }
    ;
 /*_.DISCRIM__V13*/ meltfptr[9] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]))));;
    MELT_LOCATION ("warmelt-normal.melt:5759:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.DISCRIM__V13*/ meltfptr[9]),
					(melt_ptr_t) (( /*!CLASS_NAMED */
						       meltfrout->tabval[1])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.DISCRIM__V13*/ meltfptr[9]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 1, "NAMED_NAME");
   /*_.NAMED_NAME__V14*/ meltfptr[13] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NAMED_NAME__V14*/ meltfptr[13] = NULL;;
      }
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5758:/ locexp");
      melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
		      ("receiver unprepared to normal_letrec_constructive"),
		      (melt_ptr_t) ( /*_.NAMED_NAME__V14*/ meltfptr[13]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5760:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
      /*^cond */
      /*cond */ if (( /*nil */ NULL))	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V16*/ meltfptr[15] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5760:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("@$@badmeth_normal_letrec_constructive"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5760) ? (5760) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V16*/ meltfptr[15] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V15*/ meltfptr[14] = /*_._IFELSE___V16*/ meltfptr[15];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5760:/ clear");
	     /*clear *//*_._IFELSE___V16*/ meltfptr[15] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V15*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5754:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.IFCPP___V15*/ meltfptr[14];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5754:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.NAMED_NAME__V12*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.DISCRIM__V13*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.NAMED_NAME__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V15*/ meltfptr[14] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("BADMETH_NORMAL_LETREC_CONSTRUCTIVE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_103_WARMELTmiNORMAL_BADMETH_NORMAL_LETREC_CONSTRUCTIVE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA_melt
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

  struct meltframe_meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA_st
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
#define MELTFRAM_NBVARNUM 5
    long mcfr_varnum[5];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA_st *)
	meltfirstargp_;
      /* use arguments meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA nbval 20*/
  meltfram__.mcfr_nbvar = 20 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_LAMBDA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5765:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5766:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5766:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5766:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5766;
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
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
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
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5766:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5766:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5766:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5767:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LAMBDA */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5767:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5767:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5767) ? (5767) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5767:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5768:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5771:/ apply");
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
      /*_.NORMAL_PREDEF__V13*/ meltfptr[12] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[3])),
		    (melt_ptr_t) (( /*!DISCR_CLOSURE */ meltfrout->
				   tabval[4])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5768:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING */ meltfrout->tabval[2])), (7), "CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING");
  /*_.INST__V15*/ meltfptr[14] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V15*/ meltfptr[14])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V15*/ meltfptr[14])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (1),
			  ( /*_.SLOC__V5*/ meltfptr[4]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V15*/ meltfptr[14])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V15*/ meltfptr[14]), (2),
			  ( /*_.NORMAL_PREDEF__V13*/ meltfptr[12]),
			  "NCONSB_DISCR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V15*/ meltfptr[14],
				  "newly made instance");
    ;
    /*_.CONSLAM__V14*/ meltfptr[13] = /*_.INST__V15*/ meltfptr[14];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5774:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5774:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5774:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5774;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_lambda gives conslam";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLAM__V14*/ meltfptr[13];
	      /*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
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

	    MELT_LOCATION ("warmelt-normal.melt:5774:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V17*/ meltfptr[16] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5774:/ quasiblock");


      /*_.PROGN___V19*/ meltfptr[17] = /*_._IF___V17*/ meltfptr[16];;
      /*^compute */
      /*_.IFCPP___V16*/ meltfptr[15] = /*_.PROGN___V19*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5774:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V17*/ meltfptr[16] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V19*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V16*/ meltfptr[15] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5775:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSLAM__V14*/ meltfptr[13];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5775:/ locexp");
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
    /*_.LET___V12*/ meltfptr[7] = /*_.RETURN___V20*/ meltfptr[16];;

    MELT_LOCATION ("warmelt-normal.melt:5768:/ clear");
	   /*clear *//*_.NORMAL_PREDEF__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.CONSLAM__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V20*/ meltfptr[16] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5765:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[7];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5765:/ locexp");
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
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[7] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_LAMBDA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_104_WARMELTmiNORMAL_PREPCONS_LAMBDA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA_melt
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

  struct meltframe_meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA_st
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
#define MELTFRAM_NBVARPTR 37
    melt_ptr_t mcfr_varptr[37];
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA_st *)
	meltfirstargp_;
      /* use arguments meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 37; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA nbval 37*/
  meltfram__.mcfr_nbvar = 37 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_LAMBDA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5782:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5783:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5783:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5783:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5783;
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
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
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
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5783:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5783:/ quasiblock");


      /*_.PROGN___V11*/ meltfptr[9] = /*_._IF___V9*/ meltfptr[8];;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[7] = /*_.PROGN___V11*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5783:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V11*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5785:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LAMBDA_BINDING */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5785:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[9] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5785:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5785) ? (5785) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[8] = /*_._IFELSE___V13*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5785:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5786:/ quasiblock");



    MELT_CHECK_SIGNAL ();
    ;
    /*^apply */
    /*apply */
    {
      /*_.NEWENV__V14*/ meltfptr[9] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!FRESH_ENV */ meltfrout->tabval[2])),
		    (melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5788:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5788:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5788:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5788;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_lambda newenv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEWENV__V14*/ meltfptr[9];
	      /*_.MELT_DEBUG_FUN__V17*/ meltfptr[16] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
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

	    MELT_LOCATION ("warmelt-normal.melt:5788:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5788:/ quasiblock");


      /*_.PROGN___V18*/ meltfptr[16] = /*_._IF___V16*/ meltfptr[15];;
      /*^compute */
      /*_.IFCPP___V15*/ meltfptr[14] = /*_.PROGN___V18*/ meltfptr[16];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5788:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V16*/ meltfptr[15] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V18*/ meltfptr[16] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V15*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5789:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NEWENV__V14*/ meltfptr[9]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5789:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V20*/ meltfptr[16] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5789:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check newenv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5789) ? (5789) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V20*/ meltfptr[16] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V19*/ meltfptr[15] = /*_._IFELSE___V20*/ meltfptr[16];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5789:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V20*/ meltfptr[16] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V19*/ meltfptr[15] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5790:/ quasiblock");


    /*^multiapply */
    /*multiapply 5args, 8x.res */
    {
      union meltparam_un argtab[4];

      union meltparam_un restab[8];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.ENV__V5*/ meltfptr[4];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V14*/ meltfptr[9];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V6*/ meltfptr[5];	/*^multiapply.arg */
      argtab[3].meltbp_aptr = (melt_ptr_t *) & /*_.PSLOC__V7*/ meltfptr[6];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.CSYM__V22*/ meltfptr[21];
      /*^multiapply.xres */
      restab[1].meltbp_aptr = (melt_ptr_t *) & /*_.CLOCC__V23*/ meltfptr[22];
      /*^multiapply.xres */
      restab[2].meltbp_aptr =
	(melt_ptr_t *) & /*_.CONSTROUT__V24*/ meltfptr[23];
      /*^multiapply.xres */
      restab[3].meltbp_aptr =
	(melt_ptr_t *) & /*_.CLOVTUP__V25*/ meltfptr[24];
      /*^multiapply.xres */
      restab[4].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V26*/ meltfptr[25];
      /*^multiapply.xres */
      restab[5].meltbp_aptr =
	(melt_ptr_t *) & /*_.OLDPROC__V27*/ meltfptr[26];
      /*^multiapply.xres */
      restab[6].meltbp_aptr =
	(melt_ptr_t *) & /*_.NDATAROUT__V28*/ meltfptr[27];
      /*^multiapply.xres */
      restab[7].meltbp_longptr = & /*_#INSIDEFLAG__L7*/ meltfnum[0];
      /*^multiapply.appl */
      /*_.NPROC__V21*/ meltfptr[16] =
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
    MELT_LOCATION ("warmelt-normal.melt:5794:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5794:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5794:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[15];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5794;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_lambda after normalize_lambda csym=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CSYM__V22*/ meltfptr[21];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " clocc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOCC__V23*/ meltfptr[22];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " constrout=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSTROUT__V24*/ meltfptr[23];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " clovtup=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOVTUP__V25*/ meltfptr[24];
	      /*^apply.arg */
	      argtab[11].meltbp_cstring = " oldproc=";
	      /*^apply.arg */
	      argtab[12].meltbp_aptr =
		(melt_ptr_t *) & /*_.OLDPROC__V27*/ meltfptr[26];
	      /*^apply.arg */
	      argtab[13].meltbp_cstring = " ndatarout=";
	      /*^apply.arg */
	      argtab[14].meltbp_aptr =
		(melt_ptr_t *) & /*_.NDATAROUT__V28*/ meltfptr[27];
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30] =
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
	    /*_._IF___V30*/ meltfptr[29] =
	      /*_.MELT_DEBUG_FUN__V31*/ meltfptr[30];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5794:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[8] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5794:/ quasiblock");


      /*_.PROGN___V32*/ meltfptr[30] = /*_._IF___V30*/ meltfptr[29];;
      /*^compute */
      /*_.IFCPP___V29*/ meltfptr[28] = /*_.PROGN___V32*/ meltfptr[30];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5794:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V30*/ meltfptr[29] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V32*/ meltfptr[30] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V29*/ meltfptr[28] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5800:/ cond");
    /*cond */ if ( /*_#INSIDEFLAG__L7*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:5801:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.OLDPROC__V27*/ meltfptr[26]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 5, "NRPRO_CONST");
    /*_.NRPRO_CONST__V33*/ meltfptr[29] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRPRO_CONST__V33*/ meltfptr[29]),
				(melt_ptr_t) ( /*_.NDATAROUT__V28*/
					      meltfptr[27]));
	  }
	  ;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:5800:/ clear");
	     /*clear *//*_.NRPRO_CONST__V33*/ meltfptr[29] = 0;
	}
	;
      }				/*noelse */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5802:/ cond");
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
	  melt_assertmsg ("putslot checkobj @NLAMBDAB_NCLOSED",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (4),
				( /*_.CLOVTUP__V25*/ meltfptr[24]),
				"NLAMBDAB_NCLOSED");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NLAMBDAB_CONSTROUT",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (5),
				( /*_.CONSTROUT__V24*/ meltfptr[23]),
				"NLAMBDAB_CONSTROUT");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NLAMBDAB_DATAROUT",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.CBIND__V4*/ meltfptr[3])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.CBIND__V4*/ meltfptr[3]), (6),
				( /*_.NDATAROUT__V28*/ meltfptr[27]),
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
    MELT_LOCATION ("warmelt-normal.melt:5806:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5806:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5806:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5806;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_lambda updated cbind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CBIND__V4*/ meltfptr[3];
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V35*/ meltfptr[29] =
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[35];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5806:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V36*/ meltfptr[35] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V35*/ meltfptr[29] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5806:/ quasiblock");


      /*_.PROGN___V37*/ meltfptr[35] = /*_._IF___V35*/ meltfptr[29];;
      /*^compute */
      /*_.IFCPP___V34*/ meltfptr[30] = /*_.PROGN___V37*/ meltfptr[35];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5806:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V35*/ meltfptr[29] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V37*/ meltfptr[35] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V34*/ meltfptr[30] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5808:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normletrec_lambda ended"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_LOCATION ("warmelt-normal.melt:5790:/ clear");
	   /*clear *//*_.IFCPP___V29*/ meltfptr[28] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V34*/ meltfptr[30] = 0;

    /*^clear */
	   /*clear *//*_.CSYM__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.CLOCC__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.CONSTROUT__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.CLOVTUP__V25*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.SLOC__V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.OLDPROC__V27*/ meltfptr[26] = 0;
    /*^clear */
	   /*clear *//*_.NDATAROUT__V28*/ meltfptr[27] = 0;
    /*^clear */
	   /*clear *//*_#INSIDEFLAG__L7*/ meltfnum[0] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5786:/ clear");
	   /*clear *//*_.NEWENV__V14*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V19*/ meltfptr[15] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5782:/ clear");
	   /*clear *//*_.IFCPP___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_LAMBDA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_105_WARMELTmiNORMAL_NORMLETREC_LAMBDA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE_melt
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

  struct meltframe_meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE_st
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
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE_st *)
	meltfirstargp_;
      /* use arguments meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE nbval 24*/
  meltfram__.mcfr_nbvar = 24 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_TUPLE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5814:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5815:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5815:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5815:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5815;
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
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
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
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5815:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5815:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5815:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5816:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_TUPLE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5816:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5816:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5816) ? (5816) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5816:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5817:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:5818:/ cond");
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
   /*_.LOC__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V13*/ meltfptr[12] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5819:/ cond");
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
   /*_.TUPARG__V14*/ meltfptr[13] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.TUPARG__V14*/ meltfptr[13] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBTUPARG__L4*/ meltfnum[0] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.TUPARG__V14*/ meltfptr[13])));;
    /*^compute */
 /*_.NTUP__V15*/ meltfptr[14] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[4])),
	( /*_#NBTUPARG__L4*/ meltfnum[0])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5824:/ cond");
    /*cond */ if ( /*_.LOC__V13*/ meltfptr[12])	/*then */
      {
	/*^cond.then */
	/*_.OR___V16*/ meltfptr[15] = /*_.LOC__V13*/ meltfptr[12];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5824:/ cond.else");

	/*_.OR___V16*/ meltfptr[15] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5825:/ apply");
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
      /*_.NORMAL_PREDEF__V17*/ meltfptr[16] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[6])),
		    (melt_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->
				   tabval[4])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5822:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING */ meltfrout->tabval[5])), (5), "CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING");
  /*_.INST__V19*/ meltfptr[18] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (1),
			  ( /*_.OR___V16*/ meltfptr[15]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (2),
			  ( /*_.NORMAL_PREDEF__V17*/ meltfptr[16]),
			  "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NTUPB_COMP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V19*/ meltfptr[18])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V19*/ meltfptr[18]), (4),
			  ( /*_.NTUP__V15*/ meltfptr[14]), "NTUPB_COMP");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V19*/ meltfptr[18],
				  "newly made instance");
    ;
    /*_.CONSTUP__V18*/ meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5829:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5829:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5829:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5829;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_tuple gives constup";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSTUP__V18*/ meltfptr[17];
	      /*_.MELT_DEBUG_FUN__V22*/ meltfptr[21] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V21*/ meltfptr[20] =
	      /*_.MELT_DEBUG_FUN__V22*/ meltfptr[21];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5829:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V22*/ meltfptr[21] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V21*/ meltfptr[20] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5829:/ quasiblock");


      /*_.PROGN___V23*/ meltfptr[21] = /*_._IF___V21*/ meltfptr[20];;
      /*^compute */
      /*_.IFCPP___V20*/ meltfptr[19] = /*_.PROGN___V23*/ meltfptr[21];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5829:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V21*/ meltfptr[20] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V23*/ meltfptr[21] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V20*/ meltfptr[19] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5830:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSTUP__V18*/ meltfptr[17];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5830:/ locexp");
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
    /*_.LET___V12*/ meltfptr[7] = /*_.RETURN___V24*/ meltfptr[20];;

    MELT_LOCATION ("warmelt-normal.melt:5817:/ clear");
	   /*clear *//*_.LOC__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.TUPARG__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_#NBTUPARG__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.NTUP__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.OR___V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.NORMAL_PREDEF__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.CONSTUP__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V24*/ meltfptr[20] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5814:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[7];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5814:/ locexp");
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
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[7] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_TUPLE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_106_WARMELTmiNORMAL_PREPCONS_TUPLE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE_melt
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

  struct meltframe_meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE_st
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
#define MELTFRAM_NBVARPTR 51
    melt_ptr_t mcfr_varptr[51];
#define MELTFRAM_NBVARNUM 20
    long mcfr_varnum[20];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE_st *)
	meltfirstargp_;
      /* use arguments meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 51; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE nbval 51*/
  meltfram__.mcfr_nbvar = 51 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_TUPLE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5835:/ getarg");
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
   /*_#MELT_NEED_DBG__L1*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5836:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5836:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5836;
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
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
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
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5836:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5836:/ quasiblock");


      /*_.PROGN___V11*/ meltfptr[9] = /*_._IF___V9*/ meltfptr[8];;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[7] = /*_.PROGN___V11*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5836:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V11*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5837:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_TUPLE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5837:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[9] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5837:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cexpr"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5837) ? (5837) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[8] = /*_._IFELSE___V13*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5837:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5838:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5838:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[14] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5838:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5838) ? (5838) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V14*/ meltfptr[9] = /*_._IFELSE___V15*/ meltfptr[14];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5838:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[9] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5839:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_TUPLE_BINDING */ meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:5839:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V17*/ meltfptr[16] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5839:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5839) ? (5839) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V17*/ meltfptr[16] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V16*/ meltfptr[14] = /*_._IFELSE___V17*/ meltfptr[16];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5839:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V17*/ meltfptr[16] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V16*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5840:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:5841:/ cond");
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
   /*_.LOCA_LOCATION__V18*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOCA_LOCATION__V18*/ meltfptr[16] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5841:/ cond");
    /*cond */ if ( /*_.LOCA_LOCATION__V18*/ meltfptr[16])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V19*/ meltfptr[18] = /*_.LOCA_LOCATION__V18*/ meltfptr[16];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5841:/ cond.else");

	/*_.LOC__V19*/ meltfptr[18] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5842:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SARGOP_ARGS");
  /*_.SARGS__V20*/ meltfptr[19] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:5843:/ cond");
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
   /*_.BCOMP__V21*/ meltfptr[20] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BCOMP__V21*/ meltfptr[20] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5844:/ cond");
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
   /*_.NLETREC__V22*/ meltfptr[21] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V22*/ meltfptr[21] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5845:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V22*/ meltfptr[21]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[6])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V22*/ meltfptr[21]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V23*/ meltfptr[22] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V23*/ meltfptr[22] = NULL;;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5847:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5847:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5847:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[11];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5847;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple sargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SARGS__V20*/ meltfptr[19];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " bcomp=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.BCOMP__V21*/ meltfptr[20];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V22*/ meltfptr[21];
	      /*^apply.arg */
	      argtab[9].meltbp_cstring = " nrecbinds=";
	      /*^apply.arg */
	      argtab[10].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V23*/ meltfptr[22];
	      /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] =
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
	    /*_._IF___V25*/ meltfptr[24] =
	      /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5847:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[1] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5847:/ quasiblock");


      /*_.PROGN___V27*/ meltfptr[25] = /*_._IF___V25*/ meltfptr[24];;
      /*^compute */
      /*_.IFCPP___V24*/ meltfptr[23] = /*_.PROGN___V27*/ meltfptr[25];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5847:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V25*/ meltfptr[24] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V27*/ meltfptr[25] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V24*/ meltfptr[23] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5849:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L8*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V22*/ meltfptr[21]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:5849:/ cond");
      /*cond */ if ( /*_#IS_A__L8*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V29*/ meltfptr[25] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5849:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5849) ? (5849) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V29*/ meltfptr[25] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V28*/ meltfptr[24] = /*_._IFELSE___V29*/ meltfptr[25];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5849:/ clear");
	     /*clear *//*_#IS_A__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V29*/ meltfptr[25] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V28*/ meltfptr[24] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5850:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L9*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.NRECBINDS__V23*/ meltfptr[22]))
	 == MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:5850:/ cond");
      /*cond */ if ( /*_#IS_LIST__L9*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V31*/ meltfptr[30] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5850:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nrecbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5850) ? (5850) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V31*/ meltfptr[30] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V30*/ meltfptr[25] = /*_._IFELSE___V31*/ meltfptr[30];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5850:/ clear");
	     /*clear *//*_#IS_LIST__L9*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V31*/ meltfptr[30] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V30*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5851:/ quasiblock");


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
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.LOC__V19*/ meltfptr[18];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V33*/ meltfptr[32];
      /*^multiapply.appl */
      /*_.NARGS__V32*/ meltfptr[30] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[7])),
		    (melt_ptr_t) ( /*_.SARGS__V20*/ meltfptr[19]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



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
   /*_#MELT_NEED_DBG__L10*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5854:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5854:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L11*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5854;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V32*/ meltfptr[30];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbinds=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V33*/ meltfptr[32];
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

	    MELT_LOCATION ("warmelt-normal.melt:5854:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[0] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5854:/ quasiblock");


      /*_.PROGN___V37*/ meltfptr[35] = /*_._IF___V35*/ meltfptr[34];;
      /*^compute */
      /*_.IFCPP___V34*/ meltfptr[33] = /*_.PROGN___V37*/ meltfptr[35];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5854:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V35*/ meltfptr[34] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V37*/ meltfptr[35] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V34*/ meltfptr[33] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5855:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#MULTIPLE_LENGTH__L12*/ meltfnum[0] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.BCOMP__V21*/ meltfptr[20])));;
      /*^compute */
   /*_#MULTIPLE_LENGTH__L13*/ meltfnum[1] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.NARGS__V32*/ meltfptr[30])));;
      /*^compute */
   /*_#eqeqI__L14*/ meltfnum[13] =
	(( /*_#MULTIPLE_LENGTH__L12*/ meltfnum[0]) ==
	 ( /*_#MULTIPLE_LENGTH__L13*/ meltfnum[1]));;
      MELT_LOCATION ("warmelt-normal.melt:5855:/ cond");
      /*cond */ if ( /*_#eqeqI__L14*/ meltfnum[13])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V39*/ meltfptr[35] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5855:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nargs & bcomp samelength"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5855) ? (5855) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V39*/ meltfptr[35] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V38*/ meltfptr[34] = /*_._IFELSE___V39*/ meltfptr[35];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5855:/ clear");
	     /*clear *//*_#MULTIPLE_LENGTH__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L13*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_#eqeqI__L14*/ meltfnum[13] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V39*/ meltfptr[35] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V38*/ meltfptr[34] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5856:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L15*/ meltfnum[0] =
	(( /*_.NBINDS__V33*/ meltfptr[32]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDS__V33*/ meltfptr[32])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5856:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L15*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V41*/ meltfptr[40] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5856:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5856) ? (5856) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V40*/ meltfptr[35] = /*_._IFELSE___V41*/ meltfptr[40];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5856:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L15*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V41*/ meltfptr[40] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V40*/ meltfptr[35] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V32*/ meltfptr[30]);
      for ( /*_#NIX__L16*/ meltfnum[1] = 0;
	   ( /*_#NIX__L16*/ meltfnum[1] >= 0)
	   && ( /*_#NIX__L16*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#NIX__L16*/ meltfnum[1]++)
	{
	  /*_.CURNARG__V42*/ meltfptr[40] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V32*/ meltfptr[30]),
			       /*_#NIX__L16*/ meltfnum[1]);




	  {
	    MELT_LOCATION ("warmelt-normal.melt:5860:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.BCOMP__V21*/ meltfptr[20]),
				     ( /*_#NIX__L16*/ meltfnum[1]),
				     (melt_ptr_t) ( /*_.CURNARG__V42*/
						   meltfptr[40]));
	  }
	  ;
	  if ( /*_#NIX__L16*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5857:/ clear");
	    /*clear *//*_.CURNARG__V42*/ meltfptr[40] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L16*/ meltfnum[1] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5861:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5861:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5861:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5861;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple updated bcomp";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.BCOMP__V21*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V44*/ meltfptr[43] =
	      /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5861:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V44*/ meltfptr[43] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5861:/ quasiblock");


      /*_.PROGN___V46*/ meltfptr[44] = /*_._IF___V44*/ meltfptr[43];;
      /*^compute */
      /*_.IFCPP___V43*/ meltfptr[42] = /*_.PROGN___V46*/ meltfptr[44];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5861:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[13] = 0;
      /*^clear */
	     /*clear *//*_._IF___V44*/ meltfptr[43] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V46*/ meltfptr[44] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V43*/ meltfptr[42] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5862:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V33*/ meltfptr[32];
      /*_.LIST_APPEND2LIST__V47*/ meltfptr[43] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[8])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V23*/ meltfptr[22]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

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
   /*_#MELT_NEED_DBG__L19*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5863:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5863:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L20*/ meltfnum[13];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5863;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_tuple updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V23*/ meltfptr[22];
	      /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V49*/ meltfptr[48] =
	      /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5863:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L20*/ meltfnum[13] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V49*/ meltfptr[48] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5863:/ quasiblock");


      /*_.PROGN___V51*/ meltfptr[49] = /*_._IF___V49*/ meltfptr[48];;
      /*^compute */
      /*_.IFCPP___V48*/ meltfptr[44] = /*_.PROGN___V51*/ meltfptr[49];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5863:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L19*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V49*/ meltfptr[48] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V51*/ meltfptr[49] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V48*/ meltfptr[44] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5864:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normletrec_tuple ended"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;

    MELT_LOCATION ("warmelt-normal.melt:5851:/ clear");
	   /*clear *//*_.IFCPP___V34*/ meltfptr[33] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V38*/ meltfptr[34] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V40*/ meltfptr[35] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V43*/ meltfptr[42] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V47*/ meltfptr[43] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V48*/ meltfptr[44] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V33*/ meltfptr[32] = 0;

    MELT_LOCATION ("warmelt-normal.melt:5840:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V18*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.BCOMP__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V28*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V30*/ meltfptr[25] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:5835:/ clear");
	   /*clear *//*_.IFCPP___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V14*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V16*/ meltfptr[14] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_TUPLE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_107_WARMELTmiNORMAL_NORMLETREC_TUPLE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST_melt
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

  struct meltframe_meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST_st
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
#define MELTFRAM_NBVARPTR 38
    melt_ptr_t mcfr_varptr[38];
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 38; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST nbval 38*/
  meltfram__.mcfr_nbvar = 38 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5870:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5871:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5871:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5871:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5871;
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
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
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
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5871:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5871:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5871:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5872:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5872:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5872:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5872) ? (5872) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5872:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5873:/ quasiblock");


 /*_.RESLIST__V13*/ meltfptr[12] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[2]))));;
    MELT_LOCATION ("warmelt-normal.melt:5875:/ cond");
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
   /*_.LOC__V14*/ meltfptr[13] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V14*/ meltfptr[13] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5876:/ cond");
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
   /*_.LISTARG__V15*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LISTARG__V15*/ meltfptr[14] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBLISTARG__L4*/ meltfnum[0] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.LISTARG__V15*/ meltfptr[14])));;
    /*^compute */
 /*_.PAIRSB__V16*/ meltfptr[15] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[5])),
	( /*_#NBLISTARG__L4*/ meltfnum[0])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5881:/ cond");
    /*cond */ if ( /*_.LOC__V14*/ meltfptr[13])	/*then */
      {
	/*^cond.then */
	/*_.OR___V17*/ meltfptr[16] = /*_.LOC__V14*/ meltfptr[13];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5881:/ cond.else");

	/*_.OR___V17*/ meltfptr[16] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5882:/ apply");
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
      /*_.NORMAL_PREDEF__V18*/ meltfptr[17] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
		    (melt_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[2])),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING ""),
		    argtab, "", (union meltparam_un *) 0);
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5879:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])), (7), "CLASS_NORMAL_CONSTRUCTED_LIST_BINDING");
  /*_.INST__V20*/ meltfptr[19] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (1),
			  ( /*_.OR___V17*/ meltfptr[16]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (2),
			  ( /*_.NORMAL_PREDEF__V18*/ meltfptr[17]),
			  "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLISTB_FIRST",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (4),
			  (( /*nil */ NULL)), "NLISTB_FIRST");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLISTB_LAST",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (5),
			  (( /*nil */ NULL)), "NLISTB_LAST");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLISTB_PAIRSB",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V20*/ meltfptr[19])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V20*/ meltfptr[19]), (6),
			  ( /*_.PAIRSB__V16*/ meltfptr[15]), "NLISTB_PAIRSB");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V20*/ meltfptr[19],
				  "newly made instance");
    ;
    /*_.CONSLIST__V19*/ meltfptr[18] = /*_.INST__V20*/ meltfptr[19];;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.LISTARG__V15*/ meltfptr[14]);
      for ( /*_#CURIX__L5*/ meltfnum[1] = 0;
	   ( /*_#CURIX__L5*/ meltfnum[1] >= 0)
	   && ( /*_#CURIX__L5*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#CURIX__L5*/ meltfnum[1]++)
	{
	  /*_.CURARG__V21*/ meltfptr[20] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.LISTARG__V15*/ meltfptr[14]),
			       /*_#CURIX__L5*/ meltfnum[1]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5891:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:5891:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:5891:/ apply");
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
		    argtab[2].meltbp_long = 5891;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "prepcons_list curarg";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURARG__V21*/ meltfptr[20];
		    /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23] =
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
		  /*_._IF___V23*/ meltfptr[22] =
		    /*_.MELT_DEBUG_FUN__V24*/ meltfptr[23];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5891:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L7*/ meltfnum[6] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:5891:/ quasiblock");


	    /*_.PROGN___V25*/ meltfptr[23] = /*_._IF___V23*/ meltfptr[22];;
	    /*^compute */
	    /*_.IFCPP___V22*/ meltfptr[21] = /*_.PROGN___V25*/ meltfptr[23];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5891:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L6*/ meltfnum[5] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V23*/ meltfptr[22] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V25*/ meltfptr[23] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V22*/ meltfptr[21] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5892:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#IS_A__L8*/ meltfnum[6] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.CURARG__V21*/ meltfptr[20]),
				 (melt_ptr_t) (( /*!CLASS_NAMED */ meltfrout->
						tabval[9])));;
	  MELT_LOCATION ("warmelt-normal.melt:5892:/ cond");
	  /*cond */ if ( /*_#IS_A__L8*/ meltfnum[6])	/*then */
	    {
	      /*^cond.then */
	      /*_._IFELSE___V26*/ meltfptr[22] =
		/*_.CURARG__V21*/ meltfptr[20];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:5892:/ cond.else");

	      /*_._IFELSE___V26*/ meltfptr[22] =
		( /*!konst_10__PAIROFLIST */ meltfrout->tabval[10]);;
	    }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5892:/ apply");
	  /*apply */
	  {
	    /*_.PAIRSYMB__V27*/ meltfptr[23] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!CLONE_SYMBOL */ meltfrout->tabval[8])),
			  (melt_ptr_t) ( /*_._IFELSE___V26*/ meltfptr[22]),
			  (""), (union meltparam_un *) 0, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5895:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURARG__V21*/
					       meltfptr[20]),
					      (melt_ptr_t) (( /*!CLASS_LOCATED */ meltfrout->tabval[3])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURARG__V21*/ meltfptr[20]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
    /*_.LOCA_LOCATION__V28*/ meltfptr[27] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.LOCA_LOCATION__V28*/ meltfptr[27] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5895:/ cond");
	  /*cond */ if ( /*_.LOCA_LOCATION__V28*/ meltfptr[27])	/*then */
	    {
	      /*^cond.then */
	      /*_.OR___V29*/ meltfptr[28] =
		/*_.LOCA_LOCATION__V28*/ meltfptr[27];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:5895:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.LOC__V14*/ meltfptr[13])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V30*/ meltfptr[29] =
		      /*_.LOC__V14*/ meltfptr[13];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:5895:/ cond.else");

		    /*_.OR___V30*/ meltfptr[29] = /*_.SLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.OR___V29*/ meltfptr[28] = /*_.OR___V30*/ meltfptr[29];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5895:/ clear");
	      /*clear *//*_.OR___V30*/ meltfptr[29] = 0;
	      }
	      ;
	    }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5896:/ apply");
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
	    /*_.NORMAL_PREDEF__V31*/ meltfptr[29] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
			  (melt_ptr_t) (( /*!DISCR_PAIR */ meltfrout->
					 tabval[12])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5893:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[11])), (6), "CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING");
   /*_.INST__V33*/ meltfptr[32] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @BINDER",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V33*/ meltfptr[32]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]), (0),
				( /*_.PAIRSYMB__V27*/ meltfptr[23]),
				"BINDER");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NCONSB_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V33*/ meltfptr[32]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]), (1),
				( /*_.OR___V29*/ meltfptr[28]), "NCONSB_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V33*/ meltfptr[32]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]), (2),
				( /*_.NORMAL_PREDEF__V31*/ meltfptr[29]),
				"NCONSB_DISCR");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NPAIRB_HEAD",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V33*/ meltfptr[32]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]), (4),
				(( /*nil */ NULL)), "NPAIRB_HEAD");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NPAIRB_TAIL",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V33*/ meltfptr[32]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]), (5),
				(( /*nil */ NULL)), "NPAIRB_TAIL");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V33*/ meltfptr[32],
					"newly made instance");
	  ;
	  /*_.CONSPAIR__V32*/ meltfptr[31] = /*_.INST__V33*/ meltfptr[32];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:5901:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.PAIRSB__V16*/ meltfptr[15]),
				     ( /*_#CURIX__L5*/ meltfnum[1]),
				     (melt_ptr_t) ( /*_.CONSPAIR__V32*/
						   meltfptr[31]));
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:5902:/ locexp");
	    meltgc_append_list ((melt_ptr_t)
				( /*_.RESLIST__V13*/ meltfptr[12]),
				(melt_ptr_t) ( /*_.CONSPAIR__V32*/
					      meltfptr[31]));
	  }
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:5892:/ clear");
	    /*clear *//*_#IS_A__L8*/ meltfnum[6] = 0;
	  /*^clear */
	    /*clear *//*_._IFELSE___V26*/ meltfptr[22] = 0;
	  /*^clear */
	    /*clear *//*_.PAIRSYMB__V27*/ meltfptr[23] = 0;
	  /*^clear */
	    /*clear *//*_.LOCA_LOCATION__V28*/ meltfptr[27] = 0;
	  /*^clear */
	    /*clear *//*_.OR___V29*/ meltfptr[28] = 0;
	  /*^clear */
	    /*clear *//*_.NORMAL_PREDEF__V31*/ meltfptr[29] = 0;
	  /*^clear */
	    /*clear *//*_.CONSPAIR__V32*/ meltfptr[31] = 0;
	  if ( /*_#CURIX__L5*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5888:/ clear");
	    /*clear *//*_.CURARG__V21*/ meltfptr[20] = 0;
      /*^clear */
	    /*clear *//*_#CURIX__L5*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V22*/ meltfptr[21] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:5904:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.RESLIST__V13*/ meltfptr[12]),
			  (melt_ptr_t) ( /*_.CONSLIST__V19*/ meltfptr[18]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5905:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5905:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5905:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[6];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5905;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_list gives reslist";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RESLIST__V13*/ meltfptr[12];
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V35*/ meltfptr[23] =
	      /*_.MELT_DEBUG_FUN__V36*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5905:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V36*/ meltfptr[27] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V35*/ meltfptr[23] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5905:/ quasiblock");


      /*_.PROGN___V37*/ meltfptr[28] = /*_._IF___V35*/ meltfptr[23];;
      /*^compute */
      /*_.IFCPP___V34*/ meltfptr[22] = /*_.PROGN___V37*/ meltfptr[28];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5905:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IF___V35*/ meltfptr[23] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V37*/ meltfptr[28] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V34*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5906:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.RESLIST__V13*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5906:/ locexp");
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
    /*_.LET___V12*/ meltfptr[7] = /*_.RETURN___V38*/ meltfptr[29];;

    MELT_LOCATION ("warmelt-normal.melt:5873:/ clear");
	   /*clear *//*_.RESLIST__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.LISTARG__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_#NBLISTARG__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.PAIRSB__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.OR___V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.NORMAL_PREDEF__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CONSLIST__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V34*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V38*/ meltfptr[29] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5870:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[7];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5870:/ locexp");
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
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[7] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_108_WARMELTmiNORMAL_PREPCONS_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_melt
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

  struct meltframe_meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_st
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
#define MELTFRAM_NBVARNUM 10
    long mcfr_varnum[10];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_st
	 *) meltfirstargp_;
      /* use arguments meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM nbval 27*/
  meltfram__.mcfr_nbvar = 27 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NRECLIST_FIND_LOCSYM", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5913:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5914:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5914:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5914:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5914;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "nreclist_find_locsym symb";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYMB__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:5914:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:5914:/ quasiblock");


      /*_.PROGN___V7*/ meltfptr[5] = /*_._IF___V5*/ meltfptr[4];;
      /*^compute */
      /*_.IFCPP___V4*/ meltfptr[3] = /*_.PROGN___V7*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5914:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V5*/ meltfptr[4] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V7*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V4*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5915:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.SYMB__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					    tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5915:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5915:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check symb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5915) ? (5915) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V8*/ meltfptr[4] = /*_._IFELSE___V9*/ meltfptr[5];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5915:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V9*/ meltfptr[5] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5916:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:5916:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5916:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5916) ? (5916) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:5916:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5917:/ quasiblock");


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
   /*_.NLOCSYMS__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLOCSYMS__V13*/ meltfptr[12] = NULL;;
      }
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NLOCSYMS__V13*/ meltfptr[12]);
      for ( /*_#LOCSYMIX__L5*/ meltfnum[1] = 0;
	   ( /*_#LOCSYMIX__L5*/ meltfnum[1] >= 0)
	   && ( /*_#LOCSYMIX__L5*/ meltfnum[1] < meltcit1__EACHTUP_ln);
	/*_#LOCSYMIX__L5*/ meltfnum[1]++)
	{
	  /*_.CURLOCSYM__V14*/ meltfptr[13] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.NLOCSYMS__V13*/ meltfptr[12]),
			       /*_#LOCSYMIX__L5*/ meltfnum[1]);




	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5922:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURLOCSYM__V14*/
					       meltfptr[13]),
					      (melt_ptr_t) (( /*!CLASS_NREP_SYMOCC */ meltfrout->tabval[3])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURLOCSYM__V14*/ meltfptr[13]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NOCC_SYMB");
    /*_.NOCC_SYMB__V15*/ meltfptr[14] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NOCC_SYMB__V15*/ meltfptr[14] = NULL;;
	    }
	  ;
	  /*^compute */
  /*_#eqeq__L6*/ meltfnum[0] =
	    (( /*_.NOCC_SYMB__V15*/ meltfptr[14]) ==
	     ( /*_.SYMB__V2*/ meltfptr[1]));;
	  MELT_LOCATION ("warmelt-normal.melt:5922:/ cond");
	  /*cond */ if ( /*_#eqeq__L6*/ meltfnum[0])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:5924:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:5924:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:5924:/ apply");
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
			  argtab[2].meltbp_long = 5924;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "nreclist_find_locsym found curlocsym";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURLOCSYM__V14*/
			    meltfptr[13];
			  /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] =
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
			/*_._IF___V18*/ meltfptr[17] =
			  /*_.MELT_DEBUG_FUN__V19*/ meltfptr[18];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5924:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V19*/ meltfptr[18] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V18*/ meltfptr[17] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5924:/ quasiblock");


		  /*_.PROGN___V20*/ meltfptr[18] =
		    /*_._IF___V18*/ meltfptr[17];;
		  /*^compute */
		  /*_.IFCPP___V17*/ meltfptr[16] =
		    /*_.PROGN___V20*/ meltfptr[18];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5924:/ clear");
		/*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[6] = 0;
		  /*^clear */
		/*clear *//*_._IF___V18*/ meltfptr[17] = 0;
		  /*^clear */
		/*clear *//*_.PROGN___V20*/ meltfptr[18] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V17*/ meltfptr[16] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:5925:/ quasiblock");


		/*_._RETVAL___V1*/ meltfptr[0] =
		  /*_.CURLOCSYM__V14*/ meltfptr[13];;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5925:/ locexp");
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
		MELT_LOCATION ("warmelt-normal.melt:5923:/ quasiblock");


		/*_.PROGN___V22*/ meltfptr[18] =
		  /*_.RETURN___V21*/ meltfptr[17];;
		/*^compute */
		/*_._IF___V16*/ meltfptr[15] =
		  /*_.PROGN___V22*/ meltfptr[18];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5922:/ clear");
	      /*clear *//*_.IFCPP___V17*/ meltfptr[16] = 0;
		/*^clear */
	      /*clear *//*_.RETURN___V21*/ meltfptr[17] = 0;
		/*^clear */
	      /*clear *//*_.PROGN___V22*/ meltfptr[18] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_._IF___V16*/ meltfptr[15] = NULL;;
	    }
	  ;
	  if ( /*_#LOCSYMIX__L5*/ meltfnum[1] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5919:/ clear");
	    /*clear *//*_.CURLOCSYM__V14*/ meltfptr[13] = 0;
      /*^clear */
	    /*clear *//*_#LOCSYMIX__L5*/ meltfnum[1] = 0;
      /*^clear */
	    /*clear *//*_.NOCC_SYMB__V15*/ meltfptr[14] = 0;
      /*^clear */
	    /*clear *//*_#eqeq__L6*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_._IF___V16*/ meltfptr[15] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5926:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5926:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5926:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[4];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[6];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5926;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "nreclist_find_locsym not found";
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[18] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING ""), argtab,
			    "", (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V24*/ meltfptr[17] =
	      /*_.MELT_DEBUG_FUN__V25*/ meltfptr[18];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5926:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[6] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V25*/ meltfptr[18] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V24*/ meltfptr[17] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5926:/ quasiblock");


      /*_.PROGN___V26*/ meltfptr[18] = /*_._IF___V24*/ meltfptr[17];;
      /*^compute */
      /*_.IFCPP___V23*/ meltfptr[16] = /*_.PROGN___V26*/ meltfptr[18];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5926:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IF___V24*/ meltfptr[17] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V26*/ meltfptr[18] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V23*/ meltfptr[16] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5927:/ quasiblock");


 /*_._RETVAL___V1*/ meltfptr[0] = NULL;;

    {
      MELT_LOCATION ("warmelt-normal.melt:5927:/ locexp");
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
    /*_.LET___V12*/ meltfptr[10] = /*_.RETURN___V27*/ meltfptr[17];;

    MELT_LOCATION ("warmelt-normal.melt:5917:/ clear");
	   /*clear *//*_.NLOCSYMS__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V23*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V27*/ meltfptr[17] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5913:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[10];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5913:/ locexp");
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
	   /*clear *//*_.IFCPP___V4*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V8*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V10*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NRECLIST_FIND_LOCSYM", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_109_WARMELTmiNORMAL_NRECLIST_FIND_LOCSYM */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST_melt
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

  struct meltframe_meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST_st
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
#define MELTFRAM_NBVARPTR 104
    melt_ptr_t mcfr_varptr[104];
#define MELTFRAM_NBVARNUM 43
    long mcfr_varnum[43];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST_st *)
	meltfirstargp_;
      /* use arguments meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 104; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST nbval 104*/
  meltfram__.mcfr_nbvar = 104 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_LIST", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:5931:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:5932:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5932:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5932:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5932;
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
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
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
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5932:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5932:/ quasiblock");


      /*_.PROGN___V11*/ meltfptr[9] = /*_._IF___V9*/ meltfptr[8];;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[7] = /*_.PROGN___V11*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5932:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V11*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5933:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LIST */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:5933:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[9] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5933:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cexpr"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5933) ? (5933) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[8] = /*_._IFELSE___V13*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5933:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[8] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5936:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_MULTIPLE__L4*/ meltfnum[0] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3])) ==
	 MELTOBMAG_MULTIPLE);;
      MELT_LOCATION ("warmelt-normal.melt:5936:/ cond");
      /*cond */ if ( /*_#IS_MULTIPLE__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[14] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5936:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cbind is tuple"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5936) ? (5936) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V14*/ meltfptr[9] = /*_._IFELSE___V15*/ meltfptr[14];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5936:/ clear");
	     /*clear *//*_#IS_MULTIPLE__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[9] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:5937:/ quasiblock");


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
   /*_.LOCA_LOCATION__V17*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOCA_LOCATION__V17*/ meltfptr[16] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5937:/ cond");
    /*cond */ if ( /*_.LOCA_LOCATION__V17*/ meltfptr[16])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V18*/ meltfptr[17] = /*_.LOCA_LOCATION__V17*/ meltfptr[16];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:5937:/ cond.else");

	/*_.LOC__V18*/ meltfptr[17] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5938:/ cond");
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
   /*_.SARGS__V19*/ meltfptr[18] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.SARGS__V19*/ meltfptr[18] = NULL;;
      }
    ;
    /*^compute */
 /*_.CONSLIBIND__V20*/ meltfptr[19] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (-1)));;
    MELT_LOCATION ("warmelt-normal.melt:5940:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CONSLIBIND__V20*/ meltfptr[19]),
					(melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CONSLIBIND__V20*/ meltfptr[19]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NCONSB_NLETREC");
   /*_.NLETREC__V21*/ meltfptr[20] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V21*/ meltfptr[20] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5941:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V21*/ meltfptr[20]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[5])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V21*/ meltfptr[20]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V22*/ meltfptr[21] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V22*/ meltfptr[21] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:5942:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V21*/ meltfptr[20]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[5])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V21*/ meltfptr[20]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 5, "NLETREC_LOCSYMS");
   /*_.NLOCSYMS__V23*/ meltfptr[22] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLOCSYMS__V23*/ meltfptr[22] = NULL;;
      }
    ;
    /*^compute */
 /*_.FIRSTPAIRBIND__V24*/ meltfptr[23] =
      (melt_multiple_nth ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (0)));;
    /*^compute */
 /*_.LASTPAIRBIND__V25*/ meltfptr[24] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]), (-2)));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5946:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5946:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5946:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5946;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list conslibind";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLIBIND__V20*/ meltfptr[19];
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
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

	    MELT_LOCATION ("warmelt-normal.melt:5946:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[0] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:5946:/ quasiblock");


      /*_.PROGN___V29*/ meltfptr[27] = /*_._IF___V27*/ meltfptr[26];;
      /*^compute */
      /*_.IFCPP___V26*/ meltfptr[25] = /*_.PROGN___V29*/ meltfptr[27];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5946:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V27*/ meltfptr[26] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V29*/ meltfptr[27] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V26*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5947:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L7*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t)
			     ( /*_.CONSLIBIND__V20*/ meltfptr[19]),
			     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])));;
      MELT_LOCATION ("warmelt-normal.melt:5947:/ cond");
      /*cond */ if ( /*_#IS_A__L7*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V31*/ meltfptr[27] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5947:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check conslibind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5947) ? (5947) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V31*/ meltfptr[27] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V30*/ meltfptr[26] = /*_._IFELSE___V31*/ meltfptr[27];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5947:/ clear");
	     /*clear *//*_#IS_A__L7*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V31*/ meltfptr[27] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V30*/ meltfptr[26] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5949:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5949:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5949:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[0];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5949;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list sargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SARGS__V19*/ meltfptr[18];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V21*/ meltfptr[20];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " nrecbinds=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V22*/ meltfptr[21];
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] =
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
	    /*_._IF___V33*/ meltfptr[32] =
	      /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5949:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[0] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V33*/ meltfptr[32] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5949:/ quasiblock");


      /*_.PROGN___V35*/ meltfptr[33] = /*_._IF___V33*/ meltfptr[32];;
      /*^compute */
      /*_.IFCPP___V32*/ meltfptr[27] = /*_.PROGN___V35*/ meltfptr[33];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5949:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V33*/ meltfptr[32] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V35*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V32*/ meltfptr[27] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5951:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L10*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NLETREC__V21*/ meltfptr[20]),
			     (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					    meltfrout->tabval[5])));;
      MELT_LOCATION ("warmelt-normal.melt:5951:/ cond");
      /*cond */ if ( /*_#IS_A__L10*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V37*/ meltfptr[33] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5951:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nletrec"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5951) ? (5951) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V36*/ meltfptr[32] = /*_._IFELSE___V37*/ meltfptr[33];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5951:/ clear");
	     /*clear *//*_#IS_A__L10*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V37*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V36*/ meltfptr[32] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5952:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST__L11*/ meltfnum[1] =
	(melt_magic_discr ((melt_ptr_t) ( /*_.NRECBINDS__V22*/ meltfptr[21]))
	 == MELTOBMAG_LIST);;
      MELT_LOCATION ("warmelt-normal.melt:5952:/ cond");
      /*cond */ if ( /*_#IS_LIST__L11*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V39*/ meltfptr[38] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5952:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nrecbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5952) ? (5952) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V38*/ meltfptr[33] = /*_._IFELSE___V39*/ meltfptr[38];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5952:/ clear");
	     /*clear *//*_#IS_LIST__L11*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V39*/ meltfptr[38] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V38*/ meltfptr[33] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5953:/ quasiblock");


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
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.LOC__V18*/ meltfptr[17];
      /*^multiapply.xres */
      restab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V42*/ meltfptr[41];
      /*^multiapply.appl */
      /*_.NARGS__V41*/ meltfptr[40] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[7])),
		    (melt_ptr_t) ( /*_.SARGS__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5956:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5956:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5956:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L13*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5956;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list nargs=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NARGS__V41*/ meltfptr[40];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbinds=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V42*/ meltfptr[41];
	      /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] =
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
	    /*_._IF___V44*/ meltfptr[43] =
	      /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5956:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V44*/ meltfptr[43] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5956:/ quasiblock");


      /*_.PROGN___V46*/ meltfptr[44] = /*_._IF___V44*/ meltfptr[43];;
      /*^compute */
      /*_.IFCPP___V43*/ meltfptr[42] = /*_.PROGN___V46*/ meltfptr[44];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5956:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V44*/ meltfptr[43] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V46*/ meltfptr[44] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V43*/ meltfptr[42] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5957:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L14*/ meltfnum[1] =
	(( /*_.NBINDS__V42*/ meltfptr[41]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBINDS__V42*/ meltfptr[41])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:5957:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L14*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V48*/ meltfptr[44] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5957:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbinds"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (5957) ? (5957) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V48*/ meltfptr[44] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V47*/ meltfptr[43] = /*_._IFELSE___V48*/ meltfptr[44];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5957:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L14*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V48*/ meltfptr[44] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V47*/ meltfptr[43] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5958:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#MULTIPLE_LENGTH__L15*/ meltfnum[0] =
	(melt_multiple_length
	 ((melt_ptr_t) ( /*_.NARGS__V41*/ meltfptr[40])));;
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
      MELT_LOCATION ("warmelt-normal.melt:5958:/ cond");
      /*cond */ if ( /*_#eqeqI__L18*/ meltfnum[17])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V50*/ meltfptr[49] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:5958:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nargs\'s length vs cbind\'s length"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (5958) ? (5958) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V50*/ meltfptr[49] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V49*/ meltfptr[44] = /*_._IFELSE___V50*/ meltfptr[49];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5958:/ clear");
	     /*clear *//*_#MULTIPLE_LENGTH__L15*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L16*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_#miI__L17*/ meltfnum[16] = 0;
      /*^clear */
	     /*clear *//*_#eqeqI__L18*/ meltfnum[17] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V50*/ meltfptr[49] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V49*/ meltfptr[44] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NARGS__V41*/ meltfptr[40]);
      for ( /*_#NIX__L19*/ meltfnum[0] = 0;
	   ( /*_#NIX__L19*/ meltfnum[0] >= 0)
	   && ( /*_#NIX__L19*/ meltfnum[0] < meltcit1__EACHTUP_ln);
	/*_#NIX__L19*/ meltfnum[0]++)
	{
	  /*_.CURNARG__V51*/ meltfptr[49] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.NARGS__V41*/ meltfptr[40]),
			       /*_#NIX__L19*/ meltfnum[0]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5963:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:5963:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:5963:/ apply");
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
		    argtab[2].meltbp_long = 5963;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normletrec_list curnarg";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURNARG__V51*/ meltfptr[49];
		    /*_.MELT_DEBUG_FUN__V54*/ meltfptr[53] =
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
		  /*_._IF___V53*/ meltfptr[52] =
		    /*_.MELT_DEBUG_FUN__V54*/ meltfptr[53];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5963:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L21*/ meltfnum[16] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V54*/ meltfptr[53] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V53*/ meltfptr[52] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5963:/ quasiblock");


	    /*_.PROGN___V55*/ meltfptr[53] = /*_._IF___V53*/ meltfptr[52];;
	    /*^compute */
	    /*_.IFCPP___V52*/ meltfptr[51] = /*_.PROGN___V55*/ meltfptr[53];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5963:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L20*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V53*/ meltfptr[52] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V55*/ meltfptr[53] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V52*/ meltfptr[51] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5964:/ quasiblock");


  /*_.CURCBIND__V57*/ meltfptr[53] =
	    (melt_multiple_nth
	     ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
	      ( /*_#NIX__L19*/ meltfnum[0])));;
	  /*^compute */
  /*_#plI__L22*/ meltfnum[17] =
	    ((1) + ( /*_#NIX__L19*/ meltfnum[0]));;
	  /*^compute */
  /*_.NEXTCBIND__V58*/ meltfptr[57] =
	    (melt_multiple_nth
	     ((melt_ptr_t) ( /*_.CBIND__V4*/ meltfptr[3]),
	      ( /*_#plI__L22*/ meltfnum[17])));;

	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^compute */
  /*_#IS_A__L23*/ meltfnum[16] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.NEXTCBIND__V58*/ meltfptr[57]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	  MELT_LOCATION ("warmelt-normal.melt:5966:/ cond");
	  /*cond */ if ( /*_#IS_A__L23*/ meltfnum[16])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:5967:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.NEXTCBIND__V58*/
						     meltfptr[57]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.NEXTCBIND__V58*/ meltfptr[57])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
      /*_.BINDER__V60*/ meltfptr[59] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.BINDER__V60*/ meltfptr[59] = NULL;;
		  }
		;
		/*^compute */
		/*_.NEXTPAIRSYMB__V59*/ meltfptr[58] =
		  /*_.BINDER__V60*/ meltfptr[59];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5966:/ clear");
	      /*clear *//*_.BINDER__V60*/ meltfptr[59] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NEXTPAIRSYMB__V59*/ meltfptr[58] = NULL;;
	    }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5969:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:5969:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:5969:/ apply");
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
		    argtab[2].meltbp_long = 5969;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normletrec_list curcbind=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V57*/ meltfptr[53];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " nextcbind=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTCBIND__V58*/ meltfptr[57];
		    /*^apply.arg */
		    argtab[7].meltbp_cstring = " nextpairsymb=";
		    /*^apply.arg */
		    argtab[8].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTPAIRSYMB__V59*/ meltfptr[58];
		    /*_.MELT_DEBUG_FUN__V63*/ meltfptr[62] =
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
		  /*_._IF___V62*/ meltfptr[61] =
		    /*_.MELT_DEBUG_FUN__V63*/ meltfptr[62];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5969:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L25*/ meltfnum[24] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:5969:/ quasiblock");


	    /*_.PROGN___V64*/ meltfptr[62] = /*_._IF___V62*/ meltfptr[61];;
	    /*^compute */
	    /*_.IFCPP___V61*/ meltfptr[59] = /*_.PROGN___V64*/ meltfptr[62];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5969:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L24*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V62*/ meltfptr[61] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V64*/ meltfptr[62] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V61*/ meltfptr[59] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5971:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L26*/ meltfnum[24] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V57*/ meltfptr[53]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:5971:/ cond");
	    /*cond */ if ( /*_#IS_A__L26*/ meltfnum[24])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V66*/ meltfptr[62] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:5971:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(5971) ? (5971) : __LINE__,
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
	    /*_.IFCPP___V65*/ meltfptr[61] =
	      /*_._IFELSE___V66*/ meltfptr[62];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5971:/ clear");
	      /*clear *//*_#IS_A__L26*/ meltfnum[24] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V66*/ meltfptr[62] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V65*/ meltfptr[61] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5972:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.NEXTPAIRSYMB__V59*/ meltfptr[58])	/*then */
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
		    (melt_ptr_t *) & /*_.NLETREC__V21*/ meltfptr[20];
		  /*_.NRECLIST_FIND_LOCSYM__V69*/ meltfptr[68] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.NEXTPAIRSYMB__V59*/
					      meltfptr[58]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		/*_.NEXTPAIRLOC__V68*/ meltfptr[67] =
		  /*_.NRECLIST_FIND_LOCSYM__V69*/ meltfptr[68];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:5972:/ clear");
	      /*clear *//*_.NRECLIST_FIND_LOCSYM__V69*/ meltfptr[68] = 0;
	      }
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NEXTPAIRLOC__V68*/ meltfptr[67] = NULL;;
	    }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5973:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:5973:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:5973:/ apply");
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
		    argtab[2].meltbp_long = 5973;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_list got nextpairloc";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NEXTPAIRLOC__V68*/ meltfptr[67];
		    /*_.MELT_DEBUG_FUN__V72*/ meltfptr[71] =
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
		  /*_._IF___V71*/ meltfptr[70] =
		    /*_.MELT_DEBUG_FUN__V72*/ meltfptr[71];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5973:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L28*/ meltfnum[24] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V72*/ meltfptr[71] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V71*/ meltfptr[70] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5973:/ quasiblock");


	    /*_.PROGN___V73*/ meltfptr[71] = /*_._IF___V71*/ meltfptr[70];;
	    /*^compute */
	    /*_.IFCPP___V70*/ meltfptr[68] = /*_.PROGN___V73*/ meltfptr[71];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5973:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L27*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V71*/ meltfptr[70] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V73*/ meltfptr[71] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V70*/ meltfptr[68] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:5974:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V57*/
					       meltfptr[53]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("putslot checkobj @NPAIRB_HEAD",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V57*/
						   meltfptr[53])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V57*/ meltfptr[53]),
				      (4), ( /*_.CURNARG__V51*/ meltfptr[49]),
				      "NPAIRB_HEAD");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("putslot checkobj @NPAIRB_TAIL",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V57*/
						   meltfptr[53])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V57*/ meltfptr[53]),
				      (5),
				      ( /*_.NEXTPAIRLOC__V68*/ meltfptr[67]),
				      "NPAIRB_TAIL");
		;
		/*^touch */
		meltgc_touch ( /*_.CURCBIND__V57*/ meltfptr[53]);
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.CURCBIND__V57*/
					      meltfptr[53], "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5977:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:5977:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:5977:/ apply");
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
		    argtab[2].meltbp_long = 5977;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_list updated curcbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V57*/ meltfptr[53];
		    /*_.MELT_DEBUG_FUN__V76*/ meltfptr[75] =
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
		  /*_._IF___V75*/ meltfptr[71] =
		    /*_.MELT_DEBUG_FUN__V76*/ meltfptr[75];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5977:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L30*/ meltfnum[1] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V76*/ meltfptr[75] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V75*/ meltfptr[71] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:5977:/ quasiblock");


	    /*_.PROGN___V77*/ meltfptr[75] = /*_._IF___V75*/ meltfptr[71];;
	    /*^compute */
	    /*_.IFCPP___V74*/ meltfptr[70] = /*_.PROGN___V77*/ meltfptr[75];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5977:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L29*/ meltfnum[24] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V75*/ meltfptr[71] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V77*/ meltfptr[75] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V74*/ meltfptr[70] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:5978:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L31*/ meltfnum[1] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V57*/ meltfptr[53]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:5978:/ cond");
	    /*cond */ if ( /*_#IS_A__L31*/ meltfnum[1])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V79*/ meltfptr[75] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:5978:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(5978) ? (5978) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V79*/ meltfptr[75] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V78*/ meltfptr[71] =
	      /*_._IFELSE___V79*/ meltfptr[75];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5978:/ clear");
	      /*clear *//*_#IS_A__L31*/ meltfnum[1] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V79*/ meltfptr[75] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V78*/ meltfptr[71] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  /*^compute */
	  /*_.LET___V67*/ meltfptr[62] = /*_.IFCPP___V78*/ meltfptr[71];;

	  MELT_LOCATION ("warmelt-normal.melt:5972:/ clear");
	    /*clear *//*_.NEXTPAIRLOC__V68*/ meltfptr[67] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V70*/ meltfptr[68] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V74*/ meltfptr[70] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V78*/ meltfptr[71] = 0;
	  /*_.LET___V56*/ meltfptr[52] = /*_.LET___V67*/ meltfptr[62];;

	  MELT_LOCATION ("warmelt-normal.melt:5964:/ clear");
	    /*clear *//*_.CURCBIND__V57*/ meltfptr[53] = 0;
	  /*^clear */
	    /*clear *//*_#plI__L22*/ meltfnum[17] = 0;
	  /*^clear */
	    /*clear *//*_.NEXTCBIND__V58*/ meltfptr[57] = 0;
	  /*^clear */
	    /*clear *//*_#IS_A__L23*/ meltfnum[16] = 0;
	  /*^clear */
	    /*clear *//*_.NEXTPAIRSYMB__V59*/ meltfptr[58] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V61*/ meltfptr[59] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V65*/ meltfptr[61] = 0;
	  /*^clear */
	    /*clear *//*_.LET___V67*/ meltfptr[62] = 0;
	  if ( /*_#NIX__L19*/ meltfnum[0] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:5960:/ clear");
	    /*clear *//*_.CURNARG__V51*/ meltfptr[49] = 0;
      /*^clear */
	    /*clear *//*_#NIX__L19*/ meltfnum[0] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V52*/ meltfptr[51] = 0;
      /*^clear */
	    /*clear *//*_.LET___V56*/ meltfptr[52] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

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
   /*_#MELT_NEED_DBG__L32*/ meltfnum[24] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5980:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5980:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L33*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5980;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list firstpairbind=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.FIRSTPAIRBIND__V24*/ meltfptr[23];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " lastpairbind=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.LASTPAIRBIND__V25*/ meltfptr[24];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " conslibind=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSLIBIND__V20*/ meltfptr[19];
	      /*_.MELT_DEBUG_FUN__V82*/ meltfptr[68] =
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
	    /*_._IF___V81*/ meltfptr[67] =
	      /*_.MELT_DEBUG_FUN__V82*/ meltfptr[68];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5980:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L33*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V82*/ meltfptr[68] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V81*/ meltfptr[67] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5980:/ quasiblock");


      /*_.PROGN___V83*/ meltfptr[70] = /*_._IF___V81*/ meltfptr[67];;
      /*^compute */
      /*_.IFCPP___V80*/ meltfptr[75] = /*_.PROGN___V83*/ meltfptr[70];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5980:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L32*/ meltfnum[24] = 0;
      /*^clear */
	     /*clear *//*_._IF___V81*/ meltfptr[67] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V83*/ meltfptr[70] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V80*/ meltfptr[75] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L34*/ meltfnum[17] =
      melt_is_instance_of ((melt_ptr_t)
			   ( /*_.FIRSTPAIRBIND__V24*/ meltfptr[23]),
			   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
    MELT_LOCATION ("warmelt-normal.melt:5983:/ cond");
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
				 ( /*_.LASTPAIRBIND__V25*/ meltfptr[24]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_PAIR_BINDING */ meltfrout->tabval[8])));;
	  MELT_LOCATION ("warmelt-normal.melt:5983:/ cond");
	  /*cond */ if ( /*_#IS_A__L35*/ meltfnum[16])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:5985:/ quasiblock");


		/*^cond */
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.FIRSTPAIRBIND__V24*/
						     meltfptr[23]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.FIRSTPAIRBIND__V24*/ meltfptr[23])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
       /*_.FIRSTPAIRSYMB__V84*/ meltfptr[71] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_.FIRSTPAIRSYMB__V84*/ meltfptr[71] = NULL;;
		  }
		;
		MELT_LOCATION ("warmelt-normal.melt:5986:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.LASTPAIRBIND__V25*/
						     meltfptr[24]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[9])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.LASTPAIRBIND__V25*/ meltfptr[24])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
       /*_.LASTPAIRSYMB__V85*/ meltfptr[53] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

      /*_.LASTPAIRSYMB__V85*/ meltfptr[53] = NULL;;
		  }
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:5987:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NLETREC__V21*/ meltfptr[20];
		  /*_.FIRSTPAIRLOCSY__V86*/ meltfptr[57] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.FIRSTPAIRSYMB__V84*/
					      meltfptr[71]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:5988:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NLETREC__V21*/ meltfptr[20];
		  /*_.LASTPAIRLOCSY__V87*/ meltfptr[58] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NRECLIST_FIND_LOCSYM */ meltfrout->
				  tabval[10])),
				(melt_ptr_t) ( /*_.LASTPAIRSYMB__V85*/
					      meltfptr[53]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:5990:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:5990:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:5990:/ apply");
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
			  argtab[2].meltbp_long = 5990;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normletrec_list firstpairlocsy=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.FIRSTPAIRLOCSY__V86*/
			    meltfptr[57];
			  /*^apply.arg */
			  argtab[5].meltbp_cstring = " lastpairlocsy=";
			  /*^apply.arg */
			  argtab[6].meltbp_aptr =
			    (melt_ptr_t *) & /*_.LASTPAIRLOCSY__V87*/
			    meltfptr[58];
			  /*_.MELT_DEBUG_FUN__V90*/ meltfptr[62] =
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
			/*_._IF___V89*/ meltfptr[61] =
			  /*_.MELT_DEBUG_FUN__V90*/ meltfptr[62];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5990:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L37*/ meltfnum[24] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V90*/ meltfptr[62] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V89*/ meltfptr[61] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5990:/ quasiblock");


		  /*_.PROGN___V91*/ meltfptr[68] =
		    /*_._IF___V89*/ meltfptr[61];;
		  /*^compute */
		  /*_.IFCPP___V88*/ meltfptr[59] =
		    /*_.PROGN___V91*/ meltfptr[68];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5990:/ clear");
		 /*clear *//*_#MELT_NEED_DBG__L36*/ meltfnum[1] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V89*/ meltfptr[61] = 0;
		  /*^clear */
		 /*clear *//*_.PROGN___V91*/ meltfptr[68] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V88*/ meltfptr[59] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:5991:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CONSLIBIND__V20*/
						     meltfptr[19]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_LIST_BINDING */ meltfrout->tabval[6])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("putslot checkobj @NLISTB_FIRST",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CONSLIBIND__V20*/ meltfptr[19])) == MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CONSLIBIND__V20*/
					     meltfptr[19]), (4),
					    ( /*_.FIRSTPAIRLOCSY__V86*/
					     meltfptr[57]), "NLISTB_FIRST");
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("putslot checkobj @NLISTB_LAST",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CONSLIBIND__V20*/ meltfptr[19])) == MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CONSLIBIND__V20*/
					     meltfptr[19]), (5),
					    ( /*_.LASTPAIRLOCSY__V87*/
					     meltfptr[58]), "NLISTB_LAST");
		      ;
		      /*^touch */
		      meltgc_touch ( /*_.CONSLIBIND__V20*/ meltfptr[19]);
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.CONSLIBIND__V20*/
						    meltfptr[19],
						    "put-fields");
		      ;
		      /*epilog */
		    }
		    ;
		  }		/*noelse */
		;

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
       /*_#MELT_NEED_DBG__L38*/ meltfnum[24] =
		    /*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
		    ( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
		    0		/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
		    ;;
		  MELT_LOCATION ("warmelt-normal.melt:5994:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:5994:/ apply");
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
			  argtab[2].meltbp_long = 5994;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normletrec_list updated conslibind";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CONSLIBIND__V20*/
			    meltfptr[19];
			  /*_.MELT_DEBUG_FUN__V94*/ meltfptr[62] =
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
			/*_._IF___V93*/ meltfptr[70] =
			  /*_.MELT_DEBUG_FUN__V94*/ meltfptr[62];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:5994:/ clear");
		   /*clear *//*_#MELT_CALLCOUNT__L39*/ meltfnum[1] = 0;
			/*^clear */
		   /*clear *//*_.MELT_DEBUG_FUN__V94*/ meltfptr[62] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

	/*_._IF___V93*/ meltfptr[70] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:5994:/ quasiblock");


		  /*_.PROGN___V95*/ meltfptr[61] =
		    /*_._IF___V93*/ meltfptr[70];;
		  /*^compute */
		  /*_.IFCPP___V92*/ meltfptr[67] =
		    /*_.PROGN___V95*/ meltfptr[61];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:5994:/ clear");
		 /*clear *//*_#MELT_NEED_DBG__L38*/ meltfnum[24] = 0;
		  /*^clear */
		 /*clear *//*_._IF___V93*/ meltfptr[70] = 0;
		  /*^clear */
		 /*clear *//*_.PROGN___V95*/ meltfptr[61] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V92*/ meltfptr[67] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:5995:/ locexp");
		  /*void */ (void) 0;
		}
		;

		MELT_LOCATION ("warmelt-normal.melt:5985:/ clear");
	       /*clear *//*_.FIRSTPAIRSYMB__V84*/ meltfptr[71] = 0;
		/*^clear */
	       /*clear *//*_.LASTPAIRSYMB__V85*/ meltfptr[53] = 0;
		/*^clear */
	       /*clear *//*_.FIRSTPAIRLOCSY__V86*/ meltfptr[57] = 0;
		/*^clear */
	       /*clear *//*_.LASTPAIRLOCSY__V87*/ meltfptr[58] = 0;
		/*^clear */
	       /*clear *//*_.IFCPP___V88*/ meltfptr[59] = 0;
		/*^clear */
	       /*clear *//*_.IFCPP___V92*/ meltfptr[67] = 0;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:5983:/ clear");
	     /*clear *//*_#IS_A__L35*/ meltfnum[16] = 0;
	}
	;
      }				/*noelse */
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
   /*_#MELT_NEED_DBG__L40*/ meltfnum[1] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:5997:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5997:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L41*/ meltfnum[24];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5997;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_list appending nbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBINDS__V42*/ meltfptr[41];
	      /*_.MELT_DEBUG_FUN__V98*/ meltfptr[70] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V97*/ meltfptr[62] =
	      /*_.MELT_DEBUG_FUN__V98*/ meltfptr[70];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5997:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L41*/ meltfnum[24] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V98*/ meltfptr[70] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V97*/ meltfptr[62] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5997:/ quasiblock");


      /*_.PROGN___V99*/ meltfptr[61] = /*_._IF___V97*/ meltfptr[62];;
      /*^compute */
      /*_.IFCPP___V96*/ meltfptr[68] = /*_.PROGN___V99*/ meltfptr[61];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5997:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L40*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IF___V97*/ meltfptr[62] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V99*/ meltfptr[61] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V96*/ meltfptr[68] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5998:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBINDS__V42*/ meltfptr[41];
      /*_.LIST_APPEND2LIST__V100*/ meltfptr[71] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[11])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V22*/ meltfptr[21]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:5999:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:5999:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:5999:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L43*/ meltfnum[24];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 5999;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_list ended updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V22*/ meltfptr[21];
	      /*_.MELT_DEBUG_FUN__V103*/ meltfptr[58] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V102*/ meltfptr[57] =
	      /*_.MELT_DEBUG_FUN__V103*/ meltfptr[58];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:5999:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L43*/ meltfnum[24] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V103*/ meltfptr[58] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V102*/ meltfptr[57] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:5999:/ quasiblock");


      /*_.PROGN___V104*/ meltfptr[59] = /*_._IF___V102*/ meltfptr[57];;
      /*^compute */
      /*_.IFCPP___V101*/ meltfptr[53] = /*_.PROGN___V104*/ meltfptr[59];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:5999:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L42*/ meltfnum[16] = 0;
      /*^clear */
	     /*clear *//*_._IF___V102*/ meltfptr[57] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V104*/ meltfptr[59] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V101*/ meltfptr[53] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
    /*_.MULTI___V40*/ meltfptr[38] = /*_.IFCPP___V101*/ meltfptr[53];;

    MELT_LOCATION ("warmelt-normal.melt:5953:/ clear");
	   /*clear *//*_.IFCPP___V43*/ meltfptr[42] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V47*/ meltfptr[43] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V49*/ meltfptr[44] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V80*/ meltfptr[75] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L34*/ meltfnum[17] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V96*/ meltfptr[68] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V100*/ meltfptr[71] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V101*/ meltfptr[53] = 0;

    /*^clear */
	   /*clear *//*_.NBINDS__V42*/ meltfptr[41] = 0;
    /*_.LET___V16*/ meltfptr[14] = /*_.MULTI___V40*/ meltfptr[38];;

    MELT_LOCATION ("warmelt-normal.melt:5937:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.SARGS__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.CONSLIBIND__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.NLOCSYMS__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.FIRSTPAIRBIND__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.LASTPAIRBIND__V25*/ meltfptr[24] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V30*/ meltfptr[26] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V32*/ meltfptr[27] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V36*/ meltfptr[32] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V38*/ meltfptr[33] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V40*/ meltfptr[38] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:5931:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V16*/ meltfptr[14];;

    {
      MELT_LOCATION ("warmelt-normal.melt:5931:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[8] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V14*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.LET___V16*/ meltfptr[14] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_LIST", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_110_WARMELTmiNORMAL_NORMLETREC_LIST */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE_melt
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

  struct meltframe_meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE_st
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
#define MELTFRAM_NBVARNUM 8
    long mcfr_varnum[8];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE_st *)
	meltfirstargp_;
      /* use arguments meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE nbval 29*/
  meltfram__.mcfr_nbvar = 29 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("PREPCONS_INSTANCE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6005:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6006:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6006:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6006:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6006;
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
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
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
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6006:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6006:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6006:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6007:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_INSTANCE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6007:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6007:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6007) ? (6007) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6007:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6008:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6009:/ cond");
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
   /*_.LOC__V13*/ meltfptr[12] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.LOC__V13*/ meltfptr[12] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6010:/ cond");
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
   /*_.CLA__V14*/ meltfptr[13] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLA__V14*/ meltfptr[13] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6011:/ cond");
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
   /*_.CLABIND__V15*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLABIND__V15*/ meltfptr[14] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L4*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CLABIND__V15*/ meltfptr[14]),
			   (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->
					  tabval[3])));;
    MELT_LOCATION ("warmelt-normal.melt:6012:/ cond");
    /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CLABIND__V15*/ meltfptr[14]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
    /*_.BINDER__V17*/ meltfptr[16] = slot;
	  };
	  ;
	  /*_.SCLASYM__V16*/ meltfptr[15] = /*_.BINDER__V17*/ meltfptr[16];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6012:/ clear");
	     /*clear *//*_.BINDER__V17*/ meltfptr[16] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.SCLASYM__V16*/ meltfptr[15] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6013:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.CLA__V14*/ meltfptr[13]),
					(melt_ptr_t) (( /*!CLASS_CLASS */
						       meltfrout->tabval[4])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.CLA__V14*/ meltfptr[13]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
   /*_.CLASS_FIELDS__V18*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.CLASS_FIELDS__V18*/ meltfptr[16] = NULL;;
      }
    ;
    /*^compute */
 /*_#NBCLAFLD__L5*/ meltfnum[1] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.CLASS_FIELDS__V18*/ meltfptr[16])));;
    /*^compute */
 /*_.TUPSLOT__V19*/ meltfptr[18] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[5])),
	( /*_#NBCLAFLD__L5*/ meltfnum[1])));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6017:/ cond");
    /*cond */ if ( /*_.LOC__V13*/ meltfptr[12])	/*then */
      {
	/*^cond.then */
	/*_.OR___V20*/ meltfptr[19] = /*_.LOC__V13*/ meltfptr[12];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6017:/ cond.else");

	/*_.OR___V20*/ meltfptr[19] = /*_.SLOC__V5*/ meltfptr[4];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6015:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[6])), (6), "CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING");
  /*_.INST__V22*/ meltfptr[21] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (0),
			  ( /*_.SYMB__V3*/ meltfptr[2]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (1),
			  ( /*_.OR___V20*/ meltfptr[19]), "NCONSB_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (2),
			  (( /*nil */ NULL)), "NCONSB_DISCR");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NINSTB_SLOTS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (4),
			  ( /*_.TUPSLOT__V19*/ meltfptr[18]), "NINSTB_SLOTS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NINSTB_CLABIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (5),
			  ( /*_.CLABIND__V15*/ meltfptr[14]),
			  "NINSTB_CLABIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V22*/ meltfptr[21],
				  "newly made instance");
    ;
    /*_.CONSINST__V21*/ meltfptr[20] = /*_.INST__V22*/ meltfptr[21];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6023:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L6*/ meltfnum[5] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CLA__V14*/ meltfptr[13]),
			     (melt_ptr_t) (( /*!CLASS_CLASS */ meltfrout->
					    tabval[4])));;
      MELT_LOCATION ("warmelt-normal.melt:6023:/ cond");
      /*cond */ if ( /*_#IS_A__L6*/ meltfnum[5])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V24*/ meltfptr[23] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6023:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("prepcons_instance check class"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6023) ? (6023) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V23*/ meltfptr[22] = /*_._IFELSE___V24*/ meltfptr[23];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6023:/ clear");
	     /*clear *//*_#IS_A__L6*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V24*/ meltfptr[23] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V23*/ meltfptr[22] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6024:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6024:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6024:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6024;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "prepcons_instance gives consinst";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSINST__V21*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V27*/ meltfptr[26] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V26*/ meltfptr[25] =
	      /*_.MELT_DEBUG_FUN__V27*/ meltfptr[26];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6024:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V27*/ meltfptr[26] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V26*/ meltfptr[25] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6024:/ quasiblock");


      /*_.PROGN___V28*/ meltfptr[26] = /*_._IF___V26*/ meltfptr[25];;
      /*^compute */
      /*_.IFCPP___V25*/ meltfptr[23] = /*_.PROGN___V28*/ meltfptr[26];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6024:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L7*/ meltfnum[5] = 0;
      /*^clear */
	     /*clear *//*_._IF___V26*/ meltfptr[25] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V28*/ meltfptr[26] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V25*/ meltfptr[23] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6025:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CONSINST__V21*/ meltfptr[20];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6025:/ locexp");
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
    /*_.LET___V12*/ meltfptr[7] = /*_.RETURN___V29*/ meltfptr[25];;

    MELT_LOCATION ("warmelt-normal.melt:6008:/ clear");
	   /*clear *//*_.LOC__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.CLA__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.CLABIND__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.SCLASYM__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.CLASS_FIELDS__V18*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_#NBCLAFLD__L5*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_.TUPSLOT__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.OR___V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.CONSINST__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V25*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V29*/ meltfptr[25] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6005:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[7];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6005:/ locexp");
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
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[7] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("PREPCONS_INSTANCE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_111_WARMELTmiNORMAL_PREPCONS_INSTANCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE_melt
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

  struct meltframe_meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE_st
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
#define MELTFRAM_NBVARPTR 58
    melt_ptr_t mcfr_varptr[58];
#define MELTFRAM_NBVARNUM 18
    long mcfr_varnum[18];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE_st
	 *) meltfirstargp_;
      /* use arguments meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 58; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE nbval 58*/
  meltfram__.mcfr_nbvar = 58 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMLETREC_INSTANCE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6032:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6033:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6033:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6033:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6033;
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
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] =
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
	    /*_._IF___V9*/ meltfptr[8] =
	      /*_.MELT_DEBUG_FUN__V10*/ meltfptr[9];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6033:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V10*/ meltfptr[9] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V9*/ meltfptr[8] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6033:/ quasiblock");


      /*_.PROGN___V11*/ meltfptr[9] = /*_._IF___V9*/ meltfptr[8];;
      /*^compute */
      /*_.IFCPP___V8*/ meltfptr[7] = /*_.PROGN___V11*/ meltfptr[9];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6033:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V9*/ meltfptr[8] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V11*/ meltfptr[9] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V8*/ meltfptr[7] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6034:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.LOCA_LOCATION__V13*/ meltfptr[9] = slot;
    };
    ;
    /*^cond */
    /*cond */ if ( /*_.LOCA_LOCATION__V13*/ meltfptr[9])	/*then */
      {
	/*^cond.then */
	/*_.LOC__V14*/ meltfptr[13] = /*_.LOCA_LOCATION__V13*/ meltfptr[9];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6034:/ cond.else");

	/*_.LOC__V14*/ meltfptr[13] = /*_.SLOC__V7*/ meltfptr[6];;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6035:/ cond");
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
   /*_.BSLOTS__V15*/ meltfptr[14] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.BSLOTS__V15*/ meltfptr[14] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6036:/ cond");
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
   /*_.NLETREC__V16*/ meltfptr[15] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NLETREC__V16*/ meltfptr[15] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6037:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V16*/ meltfptr[15]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[3])))
      )				/*then */
      {
	/*^cond.then */
	/*^getslot */
	{
	  melt_ptr_t slot = NULL, obj = NULL;
	  obj = (melt_ptr_t) ( /*_.NLETREC__V16*/ meltfptr[15]) /*=obj*/ ;
	  melt_object_get_field (slot, obj, 3, "NLETREC_FILL_BINDINGS");
   /*_.NRECBINDS__V17*/ meltfptr[16] = slot;
	};
	;
      }
    else
      {				/*^cond.else */

  /*_.NRECBINDS__V17*/ meltfptr[16] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6038:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SMINS_CLASS");
  /*_.SCLASS__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6039:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SMINS_CLABIND");
  /*_.SCLABIND__V19*/ meltfptr[18] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6040:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CEXPR__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 4, "SMINS_FIELDS");
  /*_.SFIELDS__V20*/ meltfptr[19] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_#IS_A__L3*/ meltfnum[1] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SCLABIND__V19*/ meltfptr[18]),
			   (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->
					  tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:6041:/ cond");
    /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SCLABIND__V19*/ meltfptr[18]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
    /*_.BINDER__V22*/ meltfptr[21] = slot;
	  };
	  ;
	  /*_.SCLASYM__V21*/ meltfptr[20] = /*_.BINDER__V22*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6041:/ clear");
	     /*clear *//*_.BINDER__V22*/ meltfptr[21] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.SCLASYM__V21*/ meltfptr[20] = NULL;;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L4*/ meltfnum[0] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.SCLASYM__V21*/ meltfptr[20]),
			   (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					  tabval[5])));;
    MELT_LOCATION ("warmelt-normal.melt:6042:/ cond");
    /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6043:/ msend");
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
	    /*_.NORMAL_EXP__V24*/ meltfptr[23] =
	      meltgc_send ((melt_ptr_t) ( /*_.SCLASYM__V21*/ meltfptr[20]),
			   (melt_ptr_t) (( /*!NORMAL_EXP */ meltfrout->
					  tabval[6])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  /*_.CLADATA__V23*/ meltfptr[21] =
	    /*_.NORMAL_EXP__V24*/ meltfptr[23];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6042:/ clear");
	     /*clear *//*_.NORMAL_EXP__V24*/ meltfptr[23] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_.CLADATA__V23*/ meltfptr[21] = NULL;;
      }
    ;
    /*^compute */
 /*_.BINDLIST__V25*/ meltfptr[23] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[7]))));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6046:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6046:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6046:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6046;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V16*/ meltfptr[15];
	      /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6046:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:6046:/ quasiblock");


      /*_.PROGN___V29*/ meltfptr[27] = /*_._IF___V27*/ meltfptr[26];;
      /*^compute */
      /*_.IFCPP___V26*/ meltfptr[25] = /*_.PROGN___V29*/ meltfptr[27];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6046:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[4] = 0;
      /*^clear */
	     /*clear *//*_._IF___V27*/ meltfptr[26] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V29*/ meltfptr[27] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V26*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L7*/ meltfnum[5] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CLADATA__V23*/ meltfptr[21]),
			   (melt_ptr_t) (( /*!CLASS_NREP */ meltfrout->
					  tabval[8])));;
    /*^compute */
 /*_#NOT__L8*/ meltfnum[4] =
      (!( /*_#IS_A__L7*/ meltfnum[5]));;
    MELT_LOCATION ("warmelt-normal.melt:6047:/ cond");
    /*cond */ if ( /*_#NOT__L8*/ meltfnum[4])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6049:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SCLASS__V18*/ meltfptr[17]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.NAMED_NAME__V31*/ meltfptr[27] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    melt_error_str ((melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]),
			    ("invalid class in (INSTANCE ..)"),
			    (melt_ptr_t) ( /*_.NAMED_NAME__V31*/
					  meltfptr[27]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6050:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = ( /*nil */ NULL);;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6050:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6048:/ quasiblock");


	  /*_.PROGN___V33*/ meltfptr[32] = /*_.RETURN___V32*/ meltfptr[31];;
	  /*^compute */
	  /*_._IF___V30*/ meltfptr[26] = /*_.PROGN___V33*/ meltfptr[32];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6047:/ clear");
	     /*clear *//*_.NAMED_NAME__V31*/ meltfptr[27] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V32*/ meltfptr[31] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V33*/ meltfptr[32] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

  /*_._IF___V30*/ meltfptr[26] = NULL;;
      }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6051:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6054:/ quasiblock");


    /*^newclosure */
		 /*newclosure *//*_.LAMBDA___V36*/ meltfptr[32] =
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
				      ( /*_.LAMBDA___V36*/ meltfptr[32])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 0 >= 0
		    && 0 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V36*/ meltfptr[32])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V36*/ meltfptr[32])->tabval[0] =
      (melt_ptr_t) ( /*_.SLOC__V7*/ meltfptr[6]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V36*/ meltfptr[32])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 1 >= 0
		    && 1 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V36*/ meltfptr[32])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V36*/ meltfptr[32])->tabval[1] =
      (melt_ptr_t) ( /*_.ENV__V5*/ meltfptr[4]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V36*/ meltfptr[32])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 2 >= 0
		    && 2 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V36*/ meltfptr[32])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V36*/ meltfptr[32])->tabval[2] =
      (melt_ptr_t) ( /*_.NCX__V6*/ meltfptr[5]);
    ;
    /*^putclosedv */
    /*putclosv */
    melt_assertmsg ("putclosv checkclo",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.LAMBDA___V36*/ meltfptr[32])) ==
		    MELTOBMAG_CLOSURE);
    melt_assertmsg ("putclosv checkoff", 3 >= 0
		    && 3 <
		    melt_closure_size ((melt_ptr_t)
				       ( /*_.LAMBDA___V36*/ meltfptr[32])));
    ((meltclosure_ptr_t) /*_.LAMBDA___V36*/ meltfptr[32])->tabval[3] =
      (melt_ptr_t) ( /*_.BINDLIST__V25*/ meltfptr[23]);
    ;
    /*_.LAMBDA___V35*/ meltfptr[31] = /*_.LAMBDA___V36*/ meltfptr[32];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6052:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.LAMBDA___V35*/ meltfptr[31];
      /*_.NFIELDS__V37*/ meltfptr[36] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!MULTIPLE_MAP */ meltfrout->tabval[9])),
		    (melt_ptr_t) ( /*_.SFIELDS__V20*/ meltfptr[19]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
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
   /*_#MELT_NEED_DBG__L9*/ meltfnum[8] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6072:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6072:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6072;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nfields";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NFIELDS__V37*/ meltfptr[36];
	      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V39*/ meltfptr[38] =
	      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6072:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V39*/ meltfptr[38] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6072:/ quasiblock");


      /*_.PROGN___V41*/ meltfptr[39] = /*_._IF___V39*/ meltfptr[38];;
      /*^compute */
      /*_.IFCPP___V38*/ meltfptr[37] = /*_.PROGN___V41*/ meltfptr[39];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6072:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V39*/ meltfptr[38] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V41*/ meltfptr[39] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V38*/ meltfptr[37] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.NFIELDS__V37*/ meltfptr[36]);
      for ( /*_#FLDIX__L11*/ meltfnum[9] = 0;
	   ( /*_#FLDIX__L11*/ meltfnum[9] >= 0)
	   && ( /*_#FLDIX__L11*/ meltfnum[9] < meltcit1__EACHTUP_ln);
	/*_#FLDIX__L11*/ meltfnum[9]++)
	{
	  /*_.CURNFIELDASS__V42*/ meltfptr[38] =
	    melt_multiple_nth ((melt_ptr_t)
			       ( /*_.NFIELDS__V37*/ meltfptr[36]),
			       /*_#FLDIX__L11*/ meltfnum[9]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6076:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6076:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6076:/ apply");
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
		    argtab[2].meltbp_long = 6076;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normletrec_instance curnfieldass";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURNFIELDASS__V42*/ meltfptr[38];
		    /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] =
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
		  /*_._IF___V44*/ meltfptr[43] =
		    /*_.MELT_DEBUG_FUN__V45*/ meltfptr[44];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6076:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[12] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V45*/ meltfptr[44] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V44*/ meltfptr[43] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6076:/ quasiblock");


	    /*_.PROGN___V46*/ meltfptr[44] = /*_._IF___V44*/ meltfptr[43];;
	    /*^compute */
	    /*_.IFCPP___V43*/ meltfptr[39] = /*_.PROGN___V46*/ meltfptr[44];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6076:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[8] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V44*/ meltfptr[43] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V46*/ meltfptr[44] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V43*/ meltfptr[39] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6077:/ quasiblock");


	  /*^cond */
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V42*/
					       meltfptr[38]),
					      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */ meltfrout->tabval[16])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V42*/ meltfptr[38])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NFLA_FIELD");
    /*_.CURFIELD__V47*/ meltfptr[43] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFIELD__V47*/ meltfptr[43] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6078:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V42*/
					       meltfptr[38]),
					      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */ meltfrout->tabval[16])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V42*/ meltfptr[38])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 2, "NFLA_VAL");
    /*_.CURFVAL__V48*/ meltfptr[44] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFVAL__V48*/ meltfptr[44] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6079:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURNFIELDASS__V42*/
					       meltfptr[38]),
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
		  (melt_ptr_t) ( /*_.CURNFIELDASS__V42*/ meltfptr[38])
		  /*=obj*/ ;
		melt_object_get_field (slot, obj, 0, "NREP_LOC");
    /*_.CURFLOC__V49*/ meltfptr[48] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.CURFLOC__V49*/ meltfptr[48] = NULL;;
	    }
	  ;
	  /*^compute */
  /*_#CURFOFF__L14*/ meltfnum[12] =
	    (melt_get_int
	     ((melt_ptr_t) ( /*_.CURFIELD__V47*/ meltfptr[43])));;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6082:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L15*/ meltfnum[8] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURFIELD__V47*/ meltfptr[43]),
				   (melt_ptr_t) (( /*!CLASS_FIELD */
						  meltfrout->tabval[17])));;
	    MELT_LOCATION ("warmelt-normal.melt:6082:/ cond");
	    /*cond */ if ( /*_#IS_A__L15*/ meltfnum[8])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V51*/ meltfptr[50] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6082:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curfield "),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6082) ? (6082) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V51*/ meltfptr[50] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V50*/ meltfptr[49] =
	      /*_._IFELSE___V51*/ meltfptr[50];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6082:/ clear");
	      /*clear *//*_#IS_A__L15*/ meltfnum[8] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V51*/ meltfptr[50] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V50*/ meltfptr[49] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6083:/ quasiblock");



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
	    /*_.FCTYP__V52*/ meltfptr[50] =
	      meltgc_send ((melt_ptr_t) ( /*_.CURFVAL__V48*/ meltfptr[44]),
			   (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->
					  tabval[18])), (MELTBPARSTR_PTR ""),
			   argtab, "", (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#exeq__L16*/ meltfnum[8] =
	    (( /*_.FCTYP__V52*/ meltfptr[50]) !=
	     (( /*!CTYPE_VALUE */ meltfrout->tabval[19])));;
	  MELT_LOCATION ("warmelt-normal.melt:6085:/ cond");
	  /*cond */ if ( /*_#exeq__L16*/ meltfnum[8])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6089:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURFIELD__V47*/
						     meltfptr[43]),
						    (melt_ptr_t) (( /*!CLASS_NAMED */ meltfrout->tabval[20])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CURFIELD__V47*/ meltfptr[43])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 1, "NAMED_NAME");
      /*_.NAMED_NAME__V53*/ meltfptr[52] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.NAMED_NAME__V53*/ meltfptr[52] = NULL;;
		  }
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:6086:/ locexp");
		  melt_error_str ((melt_ptr_t)
				  ( /*_.CURFLOC__V49*/ meltfptr[48]),
				  ("invalid field type in (LETREC .. (INSTANCE ..); expecting a :value"),
				  (melt_ptr_t) ( /*_.NAMED_NAME__V53*/
						meltfptr[52]));
		}
		;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6085:/ clear");
	      /*clear *//*_.NAMED_NAME__V53*/ meltfptr[52] = 0;
	      }
	      ;
	    }			/*noelse */
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6083:/ clear");
	    /*clear *//*_.FCTYP__V52*/ meltfptr[50] = 0;
	  /*^clear */
	    /*clear *//*_#exeq__L16*/ meltfnum[8] = 0;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6090:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.BSLOTS__V15*/ meltfptr[14]),
				     ( /*_#CURFOFF__L14*/ meltfnum[12]),
				     (melt_ptr_t) ( /*_.CURFVAL__V48*/
						   meltfptr[44]));
	  }
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6077:/ clear");
	    /*clear *//*_.CURFIELD__V47*/ meltfptr[43] = 0;
	  /*^clear */
	    /*clear *//*_.CURFVAL__V48*/ meltfptr[44] = 0;
	  /*^clear */
	    /*clear *//*_.CURFLOC__V49*/ meltfptr[48] = 0;
	  /*^clear */
	    /*clear *//*_#CURFOFF__L14*/ meltfnum[12] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V50*/ meltfptr[49] = 0;
	  if ( /*_#FLDIX__L11*/ meltfnum[9] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6073:/ clear");
	    /*clear *//*_.CURNFIELDASS__V42*/ meltfptr[38] = 0;
      /*^clear */
	    /*clear *//*_#FLDIX__L11*/ meltfnum[9] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V43*/ meltfptr[39] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6092:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.BINDLIST__V25*/ meltfptr[23];
      /*_.LIST_APPEND2LIST__V54*/ meltfptr[52] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[21])),
		    (melt_ptr_t) ( /*_.NRECBINDS__V17*/ meltfptr[16]),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6093:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6093:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6093:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[12];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6093;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normletrec_instance ended updated nrecbinds";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NRECBINDS__V17*/ meltfptr[16];
	      /*_.MELT_DEBUG_FUN__V57*/ meltfptr[44] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V56*/ meltfptr[43] =
	      /*_.MELT_DEBUG_FUN__V57*/ meltfptr[44];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6093:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[12] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V57*/ meltfptr[44] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V56*/ meltfptr[43] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6093:/ quasiblock");


      /*_.PROGN___V58*/ meltfptr[48] = /*_._IF___V56*/ meltfptr[43];;
      /*^compute */
      /*_.IFCPP___V55*/ meltfptr[50] = /*_.PROGN___V58*/ meltfptr[48];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6093:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[8] = 0;
      /*^clear */
	     /*clear *//*_._IF___V56*/ meltfptr[43] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V58*/ meltfptr[48] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V55*/ meltfptr[50] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*^compute */
    /*_.LET___V34*/ meltfptr[27] = /*_.IFCPP___V55*/ meltfptr[50];;

    MELT_LOCATION ("warmelt-normal.melt:6051:/ clear");
	   /*clear *//*_.LAMBDA___V35*/ meltfptr[31] = 0;
    /*^clear */
	   /*clear *//*_.NFIELDS__V37*/ meltfptr[36] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V38*/ meltfptr[37] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V54*/ meltfptr[52] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V55*/ meltfptr[50] = 0;
    /*_.LET___V12*/ meltfptr[8] = /*_.LET___V34*/ meltfptr[27];;

    MELT_LOCATION ("warmelt-normal.melt:6034:/ clear");
	   /*clear *//*_.LOCA_LOCATION__V13*/ meltfptr[9] = 0;
    /*^clear */
	   /*clear *//*_.LOC__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.BSLOTS__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.NRECBINDS__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.SCLASS__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.SCLABIND__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.SFIELDS__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_.SCLASYM__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.CLADATA__V23*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_.BINDLIST__V25*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V26*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L7*/ meltfnum[5] = 0;
    /*^clear */
	   /*clear *//*_#NOT__L8*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_._IF___V30*/ meltfptr[26] = 0;
    /*^clear */
	   /*clear *//*_.LET___V34*/ meltfptr[27] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6032:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V12*/ meltfptr[8];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6032:/ locexp");
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
	   /*clear *//*_.IFCPP___V8*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.LET___V12*/ meltfptr[8] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMLETREC_INSTANCE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_112_WARMELTmiNORMAL_NORMLETREC_INSTANCE */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 (meltclosure_ptr_t meltclosp_,
					  melt_ptr_t meltfirstargp_,
					  const melt_argdescr_cell_t
					  meltxargdescr_[],
					  union meltparam_un * meltxargtab_,
					  const melt_argdescr_cell_t
					  meltxresdescr_[],
					  union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33_melt =
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

  struct meltframe_meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33_st
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
#define MELTFRAM_NBVARPTR 22
    melt_ptr_t mcfr_varptr[22];
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33_st *)
	meltfirstargp_;
      /* use arguments meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 22; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 nbval 22*/
  meltfram__.mcfr_nbvar = 22 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("LAMBDA_cl33", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6054:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6055:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_FIELDASSIGN */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6055:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V4*/ meltfptr[3] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6055:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check curflda"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6055) ? (6055) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6055:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V4*/ meltfptr[3] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V3*/ meltfptr[2] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6056:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.CURFLOC__V6*/ meltfptr[5] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6057:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CURFLDA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SFLA_FIELD");
  /*_.CURFIELD__V7*/ meltfptr[6] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6058:/ getslot");
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
    MELT_LOCATION ("warmelt-normal.melt:6059:/ cond");
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

	  MELT_LOCATION ("warmelt-normal.melt:6059:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6060:/ quasiblock");


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
    MELT_LOCATION ("warmelt-normal.melt:6063:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6063:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6063:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6063;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normletrec_instance nexp";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NEXP__V12*/ meltfptr[11];
	      /*_.MELT_DEBUG_FUN__V16*/ meltfptr[15] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[2])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6063:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V16*/ meltfptr[15] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V15*/ meltfptr[14] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6063:/ quasiblock");


      /*_.PROGN___V17*/ meltfptr[15] = /*_._IF___V15*/ meltfptr[14];;
      /*^compute */
      /*_.IFCPP___V14*/ meltfptr[13] = /*_.PROGN___V17*/ meltfptr[15];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6063:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[3] = 0;
      /*^clear */
	     /*clear *//*_._IF___V15*/ meltfptr[14] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V17*/ meltfptr[15] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[13] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6064:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6064:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L6*/ meltfnum[4])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V19*/ meltfptr[15] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6064:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nbind"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6064) ? (6064) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V19*/ meltfptr[15] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V18*/ meltfptr[14] = /*_._IFELSE___V19*/ meltfptr[15];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6064:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L6*/ meltfnum[4] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V19*/ meltfptr[15] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V18*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6065:/ apply");
    /*apply */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^apply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NBIND__V13*/ meltfptr[12];
      /*_.LIST_APPEND2LIST__V20*/ meltfptr[15] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!LIST_APPEND2LIST */ meltfrout->tabval[3])),
		    (melt_ptr_t) (( /*~BINDLIST */ meltfclos->tabval[3])),
		    (MELTBPARSTR_PTR ""), argtab, "",
		    (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6066:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_FIELDASSIGN */
					     meltfrout->tabval[4])), (3),
			      "CLASS_NREP_FIELDASSIGN");
  /*_.INST__V22*/ meltfptr[21] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (0),
			  ( /*_.CURFLOC__V6*/ meltfptr[5]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NFLA_FIELD",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (1),
			  ( /*_.CURFIELD__V7*/ meltfptr[6]), "NFLA_FIELD");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NFLA_VAL",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V22*/ meltfptr[21])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (2),
			  ( /*_.NEXP__V12*/ meltfptr[11]), "NFLA_VAL");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V22*/ meltfptr[21],
				  "newly made instance");
    ;
    /*_.INST___V21*/ meltfptr[20] = /*_.INST__V22*/ meltfptr[21];;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
    /*_.MULTI___V11*/ meltfptr[9] = /*_.INST___V21*/ meltfptr[20];;

    MELT_LOCATION ("warmelt-normal.melt:6060:/ clear");
	   /*clear *//*_.IFCPP___V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V18*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.LIST_APPEND2LIST__V20*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_.INST___V21*/ meltfptr[20] = 0;

    /*^clear */
	   /*clear *//*_.NBIND__V13*/ meltfptr[12] = 0;
    /*_.LET___V5*/ meltfptr[3] = /*_.MULTI___V11*/ meltfptr[9];;

    MELT_LOCATION ("warmelt-normal.melt:6056:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6054:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V5*/ meltfptr[3];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6054:/ locexp");
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
  melt_trace_end ("LAMBDA_cl33", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_113_WARMELTmiNORMAL_LAMBDA_cl33 */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC_melt
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

  struct meltframe_meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC_st
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
#define MELTFRAM_NBVARPTR 196
    melt_ptr_t mcfr_varptr[196];
#define MELTFRAM_NBVARNUM 72
    long mcfr_varnum[72];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC_st *)
	meltfirstargp_;
      /* use arguments meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 196; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC nbval 196*/
  meltfram__.mcfr_nbvar = 196 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_LETREC", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6101:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6102:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6102:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V7*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6102:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check letrec recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6102) ? (6102) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6102:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6103:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6103:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V9*/ meltfptr[8] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6103:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6103) ? (6103) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6103:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6104:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6104:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6104:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6104) ? (6104) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6104:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6105:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6105:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6105:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[4];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6105;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec recv";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6105:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[4] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:6105:/ quasiblock");


      /*_.PROGN___V15*/ meltfptr[13] = /*_._IF___V13*/ meltfptr[12];;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[10] = /*_.PROGN___V15*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6105:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V13*/ meltfptr[12] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V15*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[10] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6106:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V17*/ meltfptr[13] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6107:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SLET_BINDINGS");
  /*_.SBINDS__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6108:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 3, "SLET_BODY");
  /*_.SBODY__V19*/ meltfptr[18] = slot;
    };
    ;
 /*_#NBBIND__L6*/ meltfnum[4] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.SBINDS__V18*/ meltfptr[17])));;
    /*^compute */
 /*_.BINDLIST__V20*/ meltfptr[19] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;
    /*^compute */
 /*_.CONSBINDLIST__V21*/ meltfptr[20] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6112:/ apply");
    /*apply */
    {
      /*_.NEWENV__V22*/ meltfptr[21] =
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
 /*_.SYMBEXPRMAP__V23*/ meltfptr[22] =
      (meltgc_new_mapobjects
       ((meltobject_ptr_t) (( /*!DISCR_MAP_OBJECTS */ meltfrout->tabval[6])),
	( /*_#MAPLEN__L8*/ meltfnum[7])));;
    /*^compute */
 /*_.SYMBINDMAP__V24*/ meltfptr[23] =
      (meltgc_new_mapobjects
       ((meltobject_ptr_t) (( /*!DISCR_MAP_OBJECTS */ meltfrout->tabval[6])),
	( /*_#MAPLEN__L8*/ meltfnum[7])));;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit1__EACHTUP */
      long meltcit1__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.SBINDS__V18*/ meltfptr[17]);
      for ( /*_#SBIX__L9*/ meltfnum[8] = 0;
	   ( /*_#SBIX__L9*/ meltfnum[8] >= 0)
	   && ( /*_#SBIX__L9*/ meltfnum[8] < meltcit1__EACHTUP_ln);
	/*_#SBIX__L9*/ meltfnum[8]++)
	{
	  /*_.CURSBIND__V25*/ meltfptr[24] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.SBINDS__V18*/ meltfptr[17]),
			       /*_#SBIX__L9*/ meltfnum[8]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6121:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6121:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6121:/ apply");
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
		    argtab[2].meltbp_long = 6121;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec cursbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSBIND__V25*/ meltfptr[24];
		    /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27] =
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
		  /*_._IF___V27*/ meltfptr[26] =
		    /*_.MELT_DEBUG_FUN__V28*/ meltfptr[27];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6121:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:6121:/ quasiblock");


	    /*_.PROGN___V29*/ meltfptr[27] = /*_._IF___V27*/ meltfptr[26];;
	    /*^compute */
	    /*_.IFCPP___V26*/ meltfptr[25] = /*_.PROGN___V29*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6121:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V27*/ meltfptr[26] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V29*/ meltfptr[27] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V26*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6122:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L12*/ meltfnum[10] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSBIND__V25*/ meltfptr[24]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC_BINDING */ meltfrout->tabval[7])));;
	    MELT_LOCATION ("warmelt-normal.melt:6122:/ cond");
	    /*cond */ if ( /*_#IS_A__L12*/ meltfnum[10])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V31*/ meltfptr[27] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6122:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6122) ? (6122) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V31*/ meltfptr[27] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V30*/ meltfptr[26] =
	      /*_._IFELSE___V31*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6122:/ clear");
	      /*clear *//*_#IS_A__L12*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V31*/ meltfptr[27] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V30*/ meltfptr[26] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6123:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V25*/ meltfptr[24]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V33*/ meltfptr[32] = slot;
	  };
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.LOCA_LOCATION__V33*/ meltfptr[32])	/*then */
	    {
	      /*^cond.then */
	      /*_.LOCB__V34*/ meltfptr[33] =
		/*_.LOCA_LOCATION__V33*/ meltfptr[32];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6123:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V17*/ meltfptr[13])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V35*/ meltfptr[34] =
		      /*_.SLOC__V17*/ meltfptr[13];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6123:/ cond.else");

		    /*_.OR___V35*/ meltfptr[34] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.LOCB__V34*/ meltfptr[33] = /*_.OR___V35*/ meltfptr[34];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6123:/ clear");
	      /*clear *//*_.OR___V35*/ meltfptr[34] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6124:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V25*/ meltfptr[24]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 3, "SLETB_BINDER");
   /*_.CURSYMB__V36*/ meltfptr[34] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6125:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURSBIND__V25*/ meltfptr[24]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "SLETB_EXPR");
   /*_.CUREXPR__V37*/ meltfptr[36] = slot;
	  };
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6127:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6127:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6127:/ apply");
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
		    argtab[2].meltbp_long = 6127;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curexpr=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V37*/ meltfptr[36];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " cursymb=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSYMB__V36*/ meltfptr[34];
		    /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] =
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
		  /*_._IF___V39*/ meltfptr[38] =
		    /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6127:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L14*/ meltfnum[10] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V39*/ meltfptr[38] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6127:/ quasiblock");


	    /*_.PROGN___V41*/ meltfptr[39] = /*_._IF___V39*/ meltfptr[38];;
	    /*^compute */
	    /*_.IFCPP___V38*/ meltfptr[37] = /*_.PROGN___V41*/ meltfptr[39];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6127:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L13*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V39*/ meltfptr[38] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V41*/ meltfptr[39] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V38*/ meltfptr[37] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6128:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L15*/ meltfnum[10] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CUREXPR__V37*/ meltfptr[36]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE */
						  meltfrout->tabval[8])));;
	    MELT_LOCATION ("warmelt-normal.melt:6128:/ cond");
	    /*cond */ if ( /*_#IS_A__L15*/ meltfnum[10])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V43*/ meltfptr[39] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6128:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curexpr"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6128) ? (6128) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V43*/ meltfptr[39] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V42*/ meltfptr[38] =
	      /*_._IFELSE___V43*/ meltfptr[39];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6128:/ clear");
	      /*clear *//*_#IS_A__L15*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V43*/ meltfptr[39] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V42*/ meltfptr[38] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6129:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L16*/ meltfnum[9] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSYMB__V36*/ meltfptr[34]),
				   (melt_ptr_t) (( /*!CLASS_SYMBOL */
						  meltfrout->tabval[9])));;
	    MELT_LOCATION ("warmelt-normal.melt:6129:/ cond");
	    /*cond */ if ( /*_#IS_A__L16*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V45*/ meltfptr[44] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6129:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursymb"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6129) ? (6129) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V45*/ meltfptr[44] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V44*/ meltfptr[39] =
	      /*_._IFELSE___V45*/ meltfptr[44];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6129:/ clear");
	      /*clear *//*_#IS_A__L16*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V45*/ meltfptr[44] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V44*/ meltfptr[39] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6130:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.SYMBEXPRMAP__V23*/ meltfptr[22]),
				   (meltobject_ptr_t) ( /*_.CURSYMB__V36*/
						       meltfptr[34]),
				   (melt_ptr_t) ( /*_.CUREXPR__V37*/
						 meltfptr[36]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6131:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^msend */
	  /*msend */
	  {
	    union meltparam_un argtab[3];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURSYMB__V36*/ meltfptr[34];
	    /*^ojbmsend.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^ojbmsend.arg */
	    argtab[2].meltbp_aptr =
	      (melt_ptr_t *) & /*_.LOCB__V34*/ meltfptr[33];
	    /*_.CURCONSBIND__V47*/ meltfptr[46] =
	      meltgc_send ((melt_ptr_t) ( /*_.CUREXPR__V37*/ meltfptr[36]),
			   (melt_ptr_t) (( /*!PREPARE_CONSTRUCTOR_BINDING */
					  meltfrout->tabval[10])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6133:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6133:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6133:/ apply");
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
		    argtab[2].meltbp_long = 6133;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curconsbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCONSBIND__V47*/ meltfptr[46];
		    /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] =
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
		  /*_._IF___V49*/ meltfptr[48] =
		    /*_.MELT_DEBUG_FUN__V50*/ meltfptr[49];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6133:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L18*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V50*/ meltfptr[49] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V49*/ meltfptr[48] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6133:/ quasiblock");


	    /*_.PROGN___V51*/ meltfptr[49] = /*_._IF___V49*/ meltfptr[48];;
	    /*^compute */
	    /*_.IFCPP___V48*/ meltfptr[47] = /*_.PROGN___V51*/ meltfptr[49];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6133:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L17*/ meltfnum[10] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V49*/ meltfptr[48] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V51*/ meltfptr[49] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V48*/ meltfptr[47] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  /*^compute */
  /*_#IS_A__L19*/ meltfnum[9] =
	    melt_is_instance_of ((melt_ptr_t)
				 ( /*_.CURCONSBIND__V47*/ meltfptr[46]),
				 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
	  MELT_LOCATION ("warmelt-normal.melt:6134:/ cond");
	  /*cond */ if ( /*_#IS_A__L19*/ meltfnum[9])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {


#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6135:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:6135:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:6135:/ apply");
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
			  argtab[2].meltbp_long = 6135;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_letrec curconsbind plain consbind";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CURCONSBIND__V47*/
			    meltfptr[46];
			  /*_.MELT_DEBUG_FUN__V55*/ meltfptr[54] =
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
			/*_._IF___V54*/ meltfptr[53] =
			  /*_.MELT_DEBUG_FUN__V55*/ meltfptr[54];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6135:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L21*/ meltfnum[20] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V55*/ meltfptr[54] = 0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V54*/ meltfptr[53] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6135:/ quasiblock");


		  /*_.PROGN___V56*/ meltfptr[54] =
		    /*_._IF___V54*/ meltfptr[53];;
		  /*^compute */
		  /*_.IFCPP___V53*/ meltfptr[49] =
		    /*_.PROGN___V56*/ meltfptr[54];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6135:/ clear");
		/*clear *//*_#MELT_NEED_DBG__L20*/ meltfnum[10] = 0;
		  /*^clear */
		/*clear *//*_._IF___V54*/ meltfptr[53] = 0;
		  /*^clear */
		/*clear *//*_.PROGN___V56*/ meltfptr[54] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V53*/ meltfptr[49] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:6136:/ locexp");
		  meltgc_append_list ((melt_ptr_t)
				      ( /*_.CONSBINDLIST__V21*/ meltfptr[20]),
				      (melt_ptr_t) ( /*_.CURCONSBIND__V47*/
						    meltfptr[46]));
		}
		;

		{
		  MELT_LOCATION ("warmelt-normal.melt:6137:/ locexp");
		  meltgc_put_mapobjects ((meltmapobjects_ptr_t)
					 ( /*_.SYMBINDMAP__V24*/
					  meltfptr[23]),
					 (meltobject_ptr_t) ( /*_.CURSYMB__V36*/ meltfptr[34]),
					 (melt_ptr_t) ( /*_.CURCONSBIND__V47*/
						       meltfptr[46]));
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:6134:/ quasiblock");


		/*epilog */

		/*^clear */
	      /*clear *//*_.IFCPP___V53*/ meltfptr[49] = 0;
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
		   ((melt_ptr_t) ( /*_.CURCONSBIND__V47*/ meltfptr[46])) ==
		   MELTOBMAG_MULTIPLE);;
		MELT_LOCATION ("warmelt-normal.melt:6139:/ cond");
		/*cond */ if ( /*_#IS_MULTIPLE__L22*/ meltfnum[20])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {


#if MELT_HAVE_DEBUG
		      MELT_LOCATION ("warmelt-normal.melt:6140:/ cppif.then");
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
			MELT_LOCATION ("warmelt-normal.melt:6140:/ cond");
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
				("warmelt-normal.melt:6140:/ apply");
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
				argtab[2].meltbp_long = 6140;
				/*^apply.arg */
				argtab[3].meltbp_cstring =
				  "normexp_letrec curconsbind multiple";
				/*^apply.arg */
				argtab[4].meltbp_aptr =
				  (melt_ptr_t *) & /*_.CURCONSBIND__V47*/
				  meltfptr[46];
				/*_.MELT_DEBUG_FUN__V60*/ meltfptr[59] =
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
			      /*_._IF___V59*/ meltfptr[49] =
				/*_.MELT_DEBUG_FUN__V60*/ meltfptr[59];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6140:/ clear");
		    /*clear *//*_#MELT_CALLCOUNT__L24*/ meltfnum[23]
				= 0;
			      /*^clear */
		    /*clear *//*_.MELT_DEBUG_FUN__V60*/ meltfptr[59]
				= 0;
			    }
			    ;
			  }
			else
			  {	/*^cond.else */

	 /*_._IF___V59*/ meltfptr[49] = NULL;;
			  }
			;
			MELT_LOCATION
			  ("warmelt-normal.melt:6140:/ quasiblock");


			/*_.PROGN___V61*/ meltfptr[59] =
			  /*_._IF___V59*/ meltfptr[49];;
			/*^compute */
			/*_.IFCPP___V58*/ meltfptr[54] =
			  /*_.PROGN___V61*/ meltfptr[59];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6140:/ clear");
		  /*clear *//*_#MELT_NEED_DBG__L23*/ meltfnum[10] = 0;
			/*^clear */
		  /*clear *//*_._IF___V59*/ meltfptr[49] = 0;
			/*^clear */
		  /*clear *//*_.PROGN___V61*/ meltfptr[59] = 0;
		      }

#else /*MELT_HAVE_DEBUG */
		      /*^cppif.else */
		      /*_.IFCPP___V58*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		      ;
		      /*citerblock FOREACH_IN_MULTIPLE */
		      {
			/* start foreach_in_multiple meltcit2__EACHTUP */
			long meltcit2__EACHTUP_ln =
			  melt_multiple_length ((melt_ptr_t)
						/*_.CURCONSBIND__V47*/
						meltfptr[46]);
			for ( /*_#SUBIX__L25*/ meltfnum[23] = 0;
			     ( /*_#SUBIX__L25*/ meltfnum[23] >= 0)
			     && ( /*_#SUBIX__L25*/ meltfnum[23] <
				 meltcit2__EACHTUP_ln);
	/*_#SUBIX__L25*/ meltfnum[23]++)
			  {
			    /*_.SUBCONSBIND__V62*/ meltfptr[49] =
			      melt_multiple_nth ((melt_ptr_t)
						 ( /*_.CURCONSBIND__V47*/
						  meltfptr[46]),
						 /*_#SUBIX__L25*/
						 meltfnum[23]);




#if MELT_HAVE_DEBUG
			    MELT_LOCATION
			      ("warmelt-normal.melt:6144:/ cppif.then");
			    /*^block */
			    /*anyblock */
			    {


			      MELT_CHECK_SIGNAL ();
			      ;
	 /*_#IS_A__L26*/ meltfnum[10] =
				melt_is_instance_of ((melt_ptr_t)
						     ( /*_.SUBCONSBIND__V62*/
						      meltfptr[49]),
						     (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
			      MELT_LOCATION
				("warmelt-normal.melt:6144:/ cond");
			      /*cond */ if ( /*_#IS_A__L26*/ meltfnum[10])	/*then */
				{
				  /*^cond.then */
				  /*_._IFELSE___V64*/ meltfptr[63] =
				    ( /*nil */ NULL);;
				}
			      else
				{
				  MELT_LOCATION
				    ("warmelt-normal.melt:6144:/ cond.else");

				  /*^block */
				  /*anyblock */
				  {




				    {
				      /*^locexp */
				      melt_assert_failed (("normexp_letrec check subconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6144) ? (6144) : __LINE__, __FUNCTION__);
				      ;
				    }
				    ;
		     /*clear *//*_._IFELSE___V64*/ meltfptr[63]
				      = 0;
				    /*epilog */
				  }
				  ;
				}
			      ;
			      /*^compute */
			      /*_.IFCPP___V63*/ meltfptr[59] =
				/*_._IFELSE___V64*/ meltfptr[63];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6144:/ clear");
		   /*clear *//*_#IS_A__L26*/ meltfnum[10] = 0;
			      /*^clear */
		   /*clear *//*_._IFELSE___V64*/ meltfptr[63] = 0;
			    }

#else /*MELT_HAVE_DEBUG */
			    /*^cppif.else */
			    /*_.IFCPP___V63*/ meltfptr[59] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
			    ;

			    {
			      MELT_LOCATION
				("warmelt-normal.melt:6146:/ locexp");
			      meltgc_append_list ((melt_ptr_t)
						  ( /*_.CONSBINDLIST__V21*/
						   meltfptr[20]),
						  (melt_ptr_t) ( /*_.SUBCONSBIND__V62*/ meltfptr[49]));
			    }
			    ;
			    if ( /*_#SUBIX__L25*/ meltfnum[23] < 0)
			      break;
			  }	/* end  foreach_in_multiple meltcit2__EACHTUP */

			/*citerepilog */

			MELT_LOCATION ("warmelt-normal.melt:6141:/ clear");
		 /*clear *//*_.SUBCONSBIND__V62*/ meltfptr[49] = 0;
			/*^clear */
		 /*clear *//*_#SUBIX__L25*/ meltfnum[23] = 0;
			/*^clear */
		 /*clear *//*_.IFCPP___V63*/ meltfptr[59] = 0;
		      }		/*endciterblock FOREACH_IN_MULTIPLE */
		      ;

		      {
			MELT_LOCATION ("warmelt-normal.melt:6147:/ locexp");
			meltgc_put_mapobjects ((meltmapobjects_ptr_t)
					       ( /*_.SYMBINDMAP__V24*/
						meltfptr[23]),
					       (meltobject_ptr_t) ( /*_.CURSYMB__V36*/ meltfptr[34]),
					       (melt_ptr_t) ( /*_.CURCONSBIND__V47*/ meltfptr[46]));
		      }
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6139:/ quasiblock");


		      /*epilog */

		      /*^clear */
		/*clear *//*_.IFCPP___V58*/ meltfptr[54] = 0;
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
			 ((melt_ptr_t) ( /*_.CURCONSBIND__V47*/ meltfptr[46]))
			 == MELTOBMAG_LIST);;
		      MELT_LOCATION ("warmelt-normal.melt:6149:/ cond");
		      /*cond */ if ( /*_#IS_LIST__L27*/ meltfnum[10])	/*then */
			{
			  /*^cond.then */
			  /*^block */
			  /*anyblock */
			  {


#if MELT_HAVE_DEBUG
			    MELT_LOCATION
			      ("warmelt-normal.melt:6150:/ cppif.then");
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
				("warmelt-normal.melt:6150:/ cond");
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
				      ("warmelt-normal.melt:6150:/ apply");
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
				      argtab[2].meltbp_long = 6150;
				      /*^apply.arg */
				      argtab[3].meltbp_cstring =
					"normexp_letrec curconsbind list";
				      /*^apply.arg */
				      argtab[4].meltbp_aptr =
					(melt_ptr_t *) &
					/*_.CURCONSBIND__V47*/ meltfptr[46];
				      /*_.MELT_DEBUG_FUN__V68*/ meltfptr[67] =
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
				    /*_._IF___V67*/ meltfptr[66] =
				      /*_.MELT_DEBUG_FUN__V68*/ meltfptr[67];;
				    /*epilog */

				    MELT_LOCATION
				      ("warmelt-normal.melt:6150:/ clear");
		      /*clear *//*_#MELT_CALLCOUNT__L29*/
				      meltfnum[28] = 0;
				    /*^clear */
		      /*clear *//*_.MELT_DEBUG_FUN__V68*/
				      meltfptr[67] = 0;
				  }
				  ;
				}
			      else
				{	/*^cond.else */

	   /*_._IF___V67*/ meltfptr[66] = NULL;;
				}
			      ;
			      MELT_LOCATION
				("warmelt-normal.melt:6150:/ quasiblock");


			      /*_.PROGN___V69*/ meltfptr[67] =
				/*_._IF___V67*/ meltfptr[66];;
			      /*^compute */
			      /*_.IFCPP___V66*/ meltfptr[54] =
				/*_.PROGN___V69*/ meltfptr[67];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6150:/ clear");
		    /*clear *//*_#MELT_NEED_DBG__L28*/ meltfnum[27]
				= 0;
			      /*^clear */
		    /*clear *//*_._IF___V67*/ meltfptr[66] = 0;
			      /*^clear */
		    /*clear *//*_.PROGN___V69*/ meltfptr[67] = 0;
			    }

#else /*MELT_HAVE_DEBUG */
			    /*^cppif.else */
			    /*_.IFCPP___V66*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
			    ;
			    /*citerblock FOREACH_IN_LIST */
			    {
			      /* start foreach_in_list meltcit3__EACHLIST */
			      for ( /*_.SUBCONSPAIR__V70*/ meltfptr[66] =
				   melt_list_first ((melt_ptr_t)
						    /*_.CURCONSBIND__V47*/
						    meltfptr[46]);
				   melt_magic_discr ((melt_ptr_t)
						     /*_.SUBCONSPAIR__V70*/
						     meltfptr[66]) ==
				   MELTOBMAG_PAIR;
				   /*_.SUBCONSPAIR__V70*/ meltfptr[66] =
				   melt_pair_tail ((melt_ptr_t)
						   /*_.SUBCONSPAIR__V70*/
						   meltfptr[66]))
				{
				  /*_.SUBCONSBIND__V71*/ meltfptr[67] =
				    melt_pair_head ((melt_ptr_t)
						    /*_.SUBCONSPAIR__V70*/
						    meltfptr[66]);



#if MELT_HAVE_DEBUG
				  MELT_LOCATION
				    ("warmelt-normal.melt:6154:/ cppif.then");
				  /*^block */
				  /*anyblock */
				  {


				    MELT_CHECK_SIGNAL ();
				    ;
	   /*_#IS_A__L30*/ meltfnum[28] =
				      melt_is_instance_of ((melt_ptr_t)
							   ( /*_.SUBCONSBIND__V71*/ meltfptr[67]), (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
				    MELT_LOCATION
				      ("warmelt-normal.melt:6154:/ cond");
				    /*cond */ if ( /*_#IS_A__L30*/ meltfnum[28])	/*then */
				      {
					/*^cond.then */
					/*_._IFELSE___V73*/ meltfptr[72] =
					  ( /*nil */ NULL);;
				      }
				    else
				      {
					MELT_LOCATION
					  ("warmelt-normal.melt:6154:/ cond.else");

					/*^block */
					/*anyblock */
					{




					  {
					    /*^locexp */
					    melt_assert_failed (("normexp_letrec check subconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6154) ? (6154) : __LINE__, __FUNCTION__);
					    ;
					  }
					  ;
		       /*clear *//*_._IFELSE___V73*/
					    meltfptr[72] = 0;
					  /*epilog */
					}
					;
				      }
				    ;
				    /*^compute */
				    /*_.IFCPP___V72*/ meltfptr[71] =
				      /*_._IFELSE___V73*/ meltfptr[72];;
				    /*epilog */

				    MELT_LOCATION
				      ("warmelt-normal.melt:6154:/ clear");
		     /*clear *//*_#IS_A__L30*/ meltfnum[28] =
				      0;
				    /*^clear */
		     /*clear *//*_._IFELSE___V73*/ meltfptr[72]
				      = 0;
				  }

#else /*MELT_HAVE_DEBUG */
				  /*^cppif.else */
				  /*_.IFCPP___V72*/ meltfptr[71] =
				    ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
				  ;

				  {
				    MELT_LOCATION
				      ("warmelt-normal.melt:6156:/ locexp");
				    meltgc_append_list ((melt_ptr_t)
							( /*_.CONSBINDLIST__V21*/ meltfptr[20]), (melt_ptr_t) ( /*_.SUBCONSBIND__V71*/ meltfptr[67]));
				  }
				  ;
				}	/* end foreach_in_list meltcit3__EACHLIST */
     /*_.SUBCONSPAIR__V70*/ meltfptr[66] = NULL;
     /*_.SUBCONSBIND__V71*/ meltfptr[67] = NULL;


			      /*citerepilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6151:/ clear");
		   /*clear *//*_.SUBCONSPAIR__V70*/ meltfptr[66] =
				0;
			      /*^clear */
		   /*clear *//*_.SUBCONSBIND__V71*/ meltfptr[67] =
				0;
			      /*^clear */
		   /*clear *//*_.IFCPP___V72*/ meltfptr[71] = 0;
			    }	/*endciterblock FOREACH_IN_LIST */
			    ;

			    MELT_CHECK_SIGNAL ();
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6157:/ apply");
			    /*apply */
			    {
			      union meltparam_un argtab[1];
			      memset (&argtab, 0, sizeof (argtab));
			      /*^apply.arg */
			      argtab[0].meltbp_aptr =
				(melt_ptr_t *) & ( /*!DISCR_MULTIPLE */
						  meltfrout->tabval[13]);
			      /*_.LIST_TO_MULTIPLE__V74*/ meltfptr[72] =
				melt_apply ((meltclosure_ptr_t)
					    (( /*!LIST_TO_MULTIPLE */
					      meltfrout->tabval[12])),
					    (melt_ptr_t) ( /*_.CURCONSBIND__V47*/ meltfptr[46]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un *) 0);
			    }
			    ;

			    {
			      /*^locexp */
			      meltgc_put_mapobjects ((meltmapobjects_ptr_t)
						     ( /*_.SYMBINDMAP__V24*/
						      meltfptr[23]),
						     (meltobject_ptr_t) ( /*_.CURSYMB__V36*/ meltfptr[34]),
						     (melt_ptr_t) ( /*_.LIST_TO_MULTIPLE__V74*/ meltfptr[72]));
			    }
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6149:/ quasiblock");


			    /*epilog */

			    /*^clear */
		  /*clear *//*_.IFCPP___V66*/ meltfptr[54] = 0;
			    /*^clear */
		  /*clear *//*_.LIST_TO_MULTIPLE__V74*/ meltfptr[72]
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
			      ("warmelt-normal.melt:6160:/ cppif.then");
			    /*^block */
			    /*anyblock */
			    {


			      MELT_CHECK_SIGNAL ();
			      ;
			      /*^cond */
			      /*cond */ if (( /*nil */ NULL))	/*then */
				{
				  /*^cond.then */
				  /*_._IFELSE___V76*/ meltfptr[72] =
				    ( /*nil */ NULL);;
				}
			      else
				{
				  MELT_LOCATION
				    ("warmelt-normal.melt:6160:/ cond.else");

				  /*^block */
				  /*anyblock */
				  {




				    {
				      /*^locexp */
				      melt_assert_failed (("normexp_letrec bad curconsbind"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6160) ? (6160) : __LINE__, __FUNCTION__);
				      ;
				    }
				    ;
		      /*clear *//*_._IFELSE___V76*/ meltfptr[72]
				      = 0;
				    /*epilog */
				  }
				  ;
				}
			      ;
			      /*^compute */
			      /*_.IFCPP___V75*/ meltfptr[54] =
				/*_._IFELSE___V76*/ meltfptr[72];;
			      /*epilog */

			      MELT_LOCATION
				("warmelt-normal.melt:6160:/ clear");
		    /*clear *//*_._IFELSE___V76*/ meltfptr[72] = 0;
			    }

#else /*MELT_HAVE_DEBUG */
			    /*^cppif.else */
			    /*_.IFCPP___V75*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
			    ;
			    MELT_LOCATION
			      ("warmelt-normal.melt:6159:/ quasiblock");


			    /*_.PROGN___V77*/ meltfptr[72] =
			      /*_.IFCPP___V75*/ meltfptr[54];;
			    /*^compute */
			    /*_._IFELSE___V65*/ meltfptr[63] =
			      /*_.PROGN___V77*/ meltfptr[72];;
			    /*epilog */

			    MELT_LOCATION
			      ("warmelt-normal.melt:6149:/ clear");
		  /*clear *//*_.IFCPP___V75*/ meltfptr[54] = 0;
			    /*^clear */
		  /*clear *//*_.PROGN___V77*/ meltfptr[72] = 0;
			  }
			  ;
			}
		      ;
		      /*_._IFELSE___V57*/ meltfptr[53] =
			/*_._IFELSE___V65*/ meltfptr[63];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6139:/ clear");
		/*clear *//*_#IS_LIST__L27*/ meltfnum[10] = 0;
		      /*^clear */
		/*clear *//*_._IFELSE___V65*/ meltfptr[63] = 0;
		    }
		    ;
		  }
		;
		/*_._IFELSE___V52*/ meltfptr[48] =
		  /*_._IFELSE___V57*/ meltfptr[53];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6134:/ clear");
	      /*clear *//*_#IS_MULTIPLE__L22*/ meltfnum[20] = 0;
		/*^clear */
	      /*clear *//*_._IFELSE___V57*/ meltfptr[53] = 0;
	      }
	      ;
	    }
	  ;
	  /*_.LET___V46*/ meltfptr[44] = /*_._IFELSE___V52*/ meltfptr[48];;

	  MELT_LOCATION ("warmelt-normal.melt:6131:/ clear");
	    /*clear *//*_.CURCONSBIND__V47*/ meltfptr[46] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V48*/ meltfptr[47] = 0;
	  /*^clear */
	    /*clear *//*_#IS_A__L19*/ meltfnum[9] = 0;
	  /*^clear */
	    /*clear *//*_._IFELSE___V52*/ meltfptr[48] = 0;
	  /*_.LET___V32*/ meltfptr[27] = /*_.LET___V46*/ meltfptr[44];;

	  MELT_LOCATION ("warmelt-normal.melt:6123:/ clear");
	    /*clear *//*_.LOCA_LOCATION__V33*/ meltfptr[32] = 0;
	  /*^clear */
	    /*clear *//*_.LOCB__V34*/ meltfptr[33] = 0;
	  /*^clear */
	    /*clear *//*_.CURSYMB__V36*/ meltfptr[34] = 0;
	  /*^clear */
	    /*clear *//*_.CUREXPR__V37*/ meltfptr[36] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V38*/ meltfptr[37] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V42*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V44*/ meltfptr[39] = 0;
	  /*^clear */
	    /*clear *//*_.LET___V46*/ meltfptr[44] = 0;
	  if ( /*_#SBIX__L9*/ meltfnum[8] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit1__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6118:/ clear");
	    /*clear *//*_.CURSBIND__V25*/ meltfptr[24] = 0;
      /*^clear */
	    /*clear *//*_#SBIX__L9*/ meltfnum[8] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V26*/ meltfptr[25] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V30*/ meltfptr[26] = 0;
      /*^clear */
	    /*clear *//*_.LET___V32*/ meltfptr[27] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6165:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6165:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6165:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L32*/ meltfnum[28];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6165;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec consbindlist";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CONSBINDLIST__V21*/ meltfptr[20];
	      /*_.MELT_DEBUG_FUN__V80*/ meltfptr[63] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V79*/ meltfptr[72] =
	      /*_.MELT_DEBUG_FUN__V80*/ meltfptr[63];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6165:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L32*/ meltfnum[28] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V80*/ meltfptr[63] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V79*/ meltfptr[72] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6165:/ quasiblock");


      /*_.PROGN___V81*/ meltfptr[53] = /*_._IF___V79*/ meltfptr[72];;
      /*^compute */
      /*_.IFCPP___V78*/ meltfptr[54] = /*_.PROGN___V81*/ meltfptr[53];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6165:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L31*/ meltfnum[27] = 0;
      /*^clear */
	     /*clear *//*_._IF___V79*/ meltfptr[72] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V81*/ meltfptr[53] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V78*/ meltfptr[54] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6166:/ quasiblock");


 /*_#NBCONSBIND__L33*/ meltfnum[10] =
      (melt_list_length
       ((melt_ptr_t) ( /*_.CONSBINDLIST__V21*/ meltfptr[20])));;
    /*^compute */
 /*_#CURCIX__L34*/ meltfnum[20] = 0;;
    /*^compute */
 /*_.NLOCSYMS__V83*/ meltfptr[47] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[13])),
	( /*_#NBCONSBIND__L33*/ meltfnum[10])));;
    /*^compute */
 /*_.NCBINDTUP__V84*/ meltfptr[48] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[13])),
	( /*_#NBCONSBIND__L33*/ meltfnum[10])));;
    /*^compute */
 /*_.RECFILLBINDINGS__V85*/ meltfptr[32] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6172:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LETREC */
					     meltfrout->tabval[14])), (6),
			      "CLASS_NREP_LETREC");
  /*_.INST__V87*/ meltfptr[34] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (0),
			  ( /*_.SLOC__V17*/ meltfptr[13]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLET_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (1),
			  ( /*_.NCBINDTUP__V84*/ meltfptr[48]),
			  "NLET_BINDINGS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLETREC_FILL_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (3),
			  ( /*_.RECFILLBINDINGS__V85*/ meltfptr[32]),
			  "NLETREC_FILL_BINDINGS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLETREC_LOCSYMS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (5),
			  ( /*_.NLOCSYMS__V83*/ meltfptr[47]),
			  "NLETREC_LOCSYMS");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLET_BODY",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (2),
			  (( /*nil */ NULL)), "NLET_BODY");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NLETREC_BODY_BINDINGS",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V87*/ meltfptr[34])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V87*/ meltfptr[34]), (4),
			  (( /*nil */ NULL)), "NLETREC_BODY_BINDINGS");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V87*/ meltfptr[34],
				  "newly made instance");
    ;
    /*_.NLETREC__V86*/ meltfptr[33] = /*_.INST__V87*/ meltfptr[34];;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6182:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6182:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6182:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L36*/ meltfnum[28];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6182;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec unfilled nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V86*/ meltfptr[33];
	      /*_.MELT_DEBUG_FUN__V90*/ meltfptr[38] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V89*/ meltfptr[37] =
	      /*_.MELT_DEBUG_FUN__V90*/ meltfptr[38];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6182:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L36*/ meltfnum[28] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V90*/ meltfptr[38] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V89*/ meltfptr[37] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6182:/ quasiblock");


      /*_.PROGN___V91*/ meltfptr[39] = /*_._IF___V89*/ meltfptr[37];;
      /*^compute */
      /*_.IFCPP___V88*/ meltfptr[36] = /*_.PROGN___V91*/ meltfptr[39];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6182:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L35*/ meltfnum[9] = 0;
      /*^clear */
	     /*clear *//*_._IF___V89*/ meltfptr[37] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V91*/ meltfptr[39] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V88*/ meltfptr[36] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*citerblock FOREACH_IN_LIST */
    {
      /* start foreach_in_list meltcit4__EACHLIST */
      for ( /*_.CURPAIR__V92*/ meltfptr[44] =
	   melt_list_first ((melt_ptr_t) /*_.CONSBINDLIST__V21*/
			    meltfptr[20]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V92*/ meltfptr[44]) ==
	   MELTOBMAG_PAIR;
	   /*_.CURPAIR__V92*/ meltfptr[44] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V92*/ meltfptr[44]))
	{
	  /*_.CURCBIND__V93*/ meltfptr[63] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V92*/ meltfptr[44]);



#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6189:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6189:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6189:/ apply");
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
		    argtab[2].meltbp_long = 6189;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_letrec curcbind";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURCBIND__V93*/ meltfptr[63];
		    /*_.MELT_DEBUG_FUN__V96*/ meltfptr[38] =
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
		  /*_._IF___V95*/ meltfptr[53] =
		    /*_.MELT_DEBUG_FUN__V96*/ meltfptr[38];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6189:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L38*/ meltfnum[28] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V96*/ meltfptr[38] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V95*/ meltfptr[53] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6189:/ quasiblock");


	    /*_.PROGN___V97*/ meltfptr[37] = /*_._IF___V95*/ meltfptr[53];;
	    /*^compute */
	    /*_.IFCPP___V94*/ meltfptr[72] = /*_.PROGN___V97*/ meltfptr[37];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6189:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L37*/ meltfnum[27] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V95*/ meltfptr[53] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V97*/ meltfptr[37] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V94*/ meltfptr[72] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6190:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L39*/ meltfnum[9] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURCBIND__V93*/ meltfptr[63]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])));;
	    MELT_LOCATION ("warmelt-normal.melt:6190:/ cond");
	    /*cond */ if ( /*_#IS_A__L39*/ meltfnum[9])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V99*/ meltfptr[38] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6190:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curcbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6190) ? (6190) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V99*/ meltfptr[38] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V98*/ meltfptr[39] =
	      /*_._IFELSE___V99*/ meltfptr[38];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6190:/ clear");
	      /*clear *//*_#IS_A__L39*/ meltfnum[9] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V99*/ meltfptr[38] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V98*/ meltfptr[39] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6191:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.NCBINDTUP__V84*/ meltfptr[48]),
				     ( /*_#CURCIX__L34*/ meltfnum[20]),
				     (melt_ptr_t) ( /*_.CURCBIND__V93*/
						   meltfptr[63]));
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6192:/ locexp");
	    melt_put_int ((melt_ptr_t) ( /*_.CURCBIND__V93*/ meltfptr[63]),
			  ( /*_#CURCIX__L34*/ meltfnum[20]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6193:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V93*/
					       meltfptr[63]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		/*^putslot */
		/*putslot */
		melt_assertmsg ("putslot checkobj @NCONSB_NLETREC",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.CURCBIND__V93*/
						   meltfptr[63])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.CURCBIND__V93*/ meltfptr[63]),
				      (3), ( /*_.NLETREC__V86*/ meltfptr[33]),
				      "NCONSB_NLETREC");
		;
		/*^touch */
		meltgc_touch ( /*_.CURCBIND__V93*/ meltfptr[63]);
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.CURCBIND__V93*/
					      meltfptr[63], "put-fields");
		;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6194:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURCBIND__V93*/ meltfptr[63]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 2, "NCONSB_DISCR");
   /*_.CURBDISCR__V100*/ meltfptr[53] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6195:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURCBIND__V93*/ meltfptr[63]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
   /*_.CURBINDER__V101*/ meltfptr[37] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6197:/ cond");
	  /*cond */ if (
			 /*ifisa */
			 melt_is_instance_of ((melt_ptr_t)
					      ( /*_.CURCBIND__V93*/
					       meltfptr[63]),
					      (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
	    )			/*then */
	    {
	      /*^cond.then */
	      /*^getslot */
	      {
		melt_ptr_t slot = NULL, obj = NULL;
		obj =
		  (melt_ptr_t) ( /*_.CURCBIND__V93*/ meltfptr[63]) /*=obj*/ ;
		melt_object_get_field (slot, obj, 1, "NCONSB_LOC");
    /*_.NCONSB_LOC__V102*/ meltfptr[38] = slot;
	      };
	      ;
	    }
	  else
	    {			/*^cond.else */

   /*_.NCONSB_LOC__V102*/ meltfptr[38] = NULL;;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6197:/ cond");
	  /*cond */ if ( /*_.NCONSB_LOC__V102*/ meltfptr[38])	/*then */
	    {
	      /*^cond.then */
	      /*_.OR___V103*/ meltfptr[102] =
		/*_.NCONSB_LOC__V102*/ meltfptr[38];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6197:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V17*/ meltfptr[13])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V104*/ meltfptr[103] =
		      /*_.SLOC__V17*/ meltfptr[13];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6197:/ cond.else");

		    /*_.OR___V104*/ meltfptr[103] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.OR___V103*/ meltfptr[102] =
		  /*_.OR___V104*/ meltfptr[103];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6197:/ clear");
	      /*clear *//*_.OR___V104*/ meltfptr[103] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6196:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
						   meltfrout->tabval[15])),
				    (4), "CLASS_NREP_LOCSYMOCC");
   /*_.INST__V106*/ meltfptr[105] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V106*/ meltfptr[105]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V106*/ meltfptr[105]), (0),
				( /*_.OR___V103*/ meltfptr[102]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NOCC_CTYP",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V106*/ meltfptr[105]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V106*/ meltfptr[105]), (2),
				(( /*!CTYPE_VALUE */ meltfrout->tabval[16])),
				"NOCC_CTYP");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NOCC_SYMB",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V106*/ meltfptr[105]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V106*/ meltfptr[105]), (1),
				( /*_.CURBINDER__V101*/ meltfptr[37]),
				"NOCC_SYMB");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NOCC_BIND",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V106*/ meltfptr[105]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V106*/ meltfptr[105]), (3),
				( /*_.CURCBIND__V93*/ meltfptr[63]),
				"NOCC_BIND");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V106*/ meltfptr[105],
					"newly made instance");
	  ;
	  /*_.NLOCSYM__V105*/ meltfptr[103] = /*_.INST__V106*/ meltfptr[105];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6204:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.NLOCSYMS__V83*/ meltfptr[47]),
				     ( /*_#CURCIX__L34*/ meltfnum[20]),
				     (melt_ptr_t) ( /*_.NLOCSYM__V105*/
						   meltfptr[103]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
  /*_#NULL__L40*/ meltfnum[28] =
	    (( /*_.CURBDISCR__V100*/ meltfptr[53]) == NULL);;
	  MELT_LOCATION ("warmelt-normal.melt:6205:/ cond");
	  /*cond */ if ( /*_#NULL__L40*/ meltfnum[28])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6206:/ quasiblock");


		/*^cond */
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURCBIND__V93*/
						     meltfptr[63]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[17])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CURCBIND__V93*/ meltfptr[63])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 5, "NINSTB_CLABIND");
      /*_.CLABIND__V107*/ meltfptr[106] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.CLABIND__V107*/ meltfptr[106] = NULL;;
		  }
		;
		MELT_LOCATION ("warmelt-normal.melt:6207:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CLABIND__V107*/
						     meltfptr[106]),
						    (melt_ptr_t) (( /*!CLASS_ANY_BINDING */ meltfrout->tabval[18])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^getslot */
		    {
		      melt_ptr_t slot = NULL, obj = NULL;
		      obj =
			(melt_ptr_t) ( /*_.CLABIND__V107*/ meltfptr[106])
			/*=obj*/ ;
		      melt_object_get_field (slot, obj, 0, "BINDER");
      /*_.CLASYM__V108*/ meltfptr[107] = slot;
		    };
		    ;
		  }
		else
		  {		/*^cond.else */

     /*_.CLASYM__V108*/ meltfptr[107] = NULL;;
		  }
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6209:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:6209:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:6209:/ apply");
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
			  argtab[2].meltbp_long = 6209;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring =
			    "normexp_letrec clabind=";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLABIND__V107*/
			    meltfptr[106];
			  /*^apply.arg */
			  argtab[5].meltbp_cstring = " clasym=";
			  /*^apply.arg */
			  argtab[6].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLASYM__V108*/ meltfptr[107];
			  /*_.MELT_DEBUG_FUN__V111*/ meltfptr[110] =
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
			/*_._IF___V110*/ meltfptr[109] =
			  /*_.MELT_DEBUG_FUN__V111*/ meltfptr[110];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6209:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L42*/ meltfnum[9] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V111*/ meltfptr[110] =
			  0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V110*/ meltfptr[109] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6209:/ quasiblock");


		  /*_.PROGN___V112*/ meltfptr[110] =
		    /*_._IF___V110*/ meltfptr[109];;
		  /*^compute */
		  /*_.IFCPP___V109*/ meltfptr[108] =
		    /*_.PROGN___V112*/ meltfptr[110];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6209:/ clear");
		/*clear *//*_#MELT_NEED_DBG__L41*/ meltfnum[27] = 0;
		  /*^clear */
		/*clear *//*_._IF___V110*/ meltfptr[109] = 0;
		  /*^clear */
		/*clear *//*_.PROGN___V112*/ meltfptr[110] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V109*/ meltfptr[108] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6211:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
      /*_#IS_A__L43*/ meltfnum[9] =
		    melt_is_instance_of ((melt_ptr_t)
					 ( /*_.CURCBIND__V93*/ meltfptr[63]),
					 (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTED_INSTANCE_BINDING */ meltfrout->tabval[17])));;
		  MELT_LOCATION ("warmelt-normal.melt:6211:/ cond");
		  /*cond */ if ( /*_#IS_A__L43*/ meltfnum[9])	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V114*/ meltfptr[110] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:6211:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("check curcbind for instance"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (6211) ? (6211) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		  /*clear *//*_._IFELSE___V114*/ meltfptr[110] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V113*/ meltfptr[109] =
		    /*_._IFELSE___V114*/ meltfptr[110];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6211:/ clear");
		/*clear *//*_#IS_A__L43*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_._IFELSE___V114*/ meltfptr[110] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V113*/ meltfptr[109] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;
		MELT_LOCATION ("warmelt-normal.melt:6212:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6213:/ msend");
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
		    (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[13];
		  /*_.CLADATA__V115*/ meltfptr[110] =
		    meltgc_send ((melt_ptr_t)
				 ( /*_.CLASYM__V108*/ meltfptr[107]),
				 (melt_ptr_t) (( /*!NORMAL_EXP */ meltfrout->
						tabval[19])),
				 (MELTBPARSTR_PTR MELTBPARSTR_PTR
				  MELTBPARSTR_PTR ""), argtab, "",
				 (union meltparam_un *) 0);
		}
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6215:/ cppif.then");
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
		  MELT_LOCATION ("warmelt-normal.melt:6215:/ cond");
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
			MELT_LOCATION ("warmelt-normal.melt:6215:/ apply");
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
			  argtab[2].meltbp_long = 6215;
			  /*^apply.arg */
			  argtab[3].meltbp_cstring = "normexp_letrec cladata";
			  /*^apply.arg */
			  argtab[4].meltbp_aptr =
			    (melt_ptr_t *) & /*_.CLADATA__V115*/
			    meltfptr[110];
			  /*_.MELT_DEBUG_FUN__V118*/ meltfptr[117] =
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
			/*_._IF___V117*/ meltfptr[116] =
			  /*_.MELT_DEBUG_FUN__V118*/ meltfptr[117];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6215:/ clear");
		  /*clear *//*_#MELT_CALLCOUNT__L45*/ meltfnum[9] = 0;
			/*^clear */
		  /*clear *//*_.MELT_DEBUG_FUN__V118*/ meltfptr[117] =
			  0;
		      }
		      ;
		    }
		  else
		    {		/*^cond.else */

       /*_._IF___V117*/ meltfptr[116] = NULL;;
		    }
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6215:/ quasiblock");


		  /*_.PROGN___V119*/ meltfptr[117] =
		    /*_._IF___V117*/ meltfptr[116];;
		  /*^compute */
		  /*_.IFCPP___V116*/ meltfptr[115] =
		    /*_.PROGN___V119*/ meltfptr[117];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6215:/ clear");
		/*clear *//*_#MELT_NEED_DBG__L44*/ meltfnum[27] = 0;
		  /*^clear */
		/*clear *//*_._IF___V117*/ meltfptr[116] = 0;
		  /*^clear */
		/*clear *//*_.PROGN___V119*/ meltfptr[117] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V116*/ meltfptr[115] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

#if MELT_HAVE_DEBUG
		MELT_LOCATION ("warmelt-normal.melt:6216:/ cppif.then");
		/*^block */
		/*anyblock */
		{


		  MELT_CHECK_SIGNAL ();
		  ;
      /*_#IS_A__L46*/ meltfnum[9] =
		    melt_is_instance_of ((melt_ptr_t)
					 ( /*_.CLADATA__V115*/ meltfptr[110]),
					 (melt_ptr_t) (( /*!CLASS_NREP */
							meltfrout->
							tabval[20])));;
		  MELT_LOCATION ("warmelt-normal.melt:6216:/ cond");
		  /*cond */ if ( /*_#IS_A__L46*/ meltfnum[9])	/*then */
		    {
		      /*^cond.then */
		      /*_._IFELSE___V121*/ meltfptr[117] = ( /*nil */ NULL);;
		    }
		  else
		    {
		      MELT_LOCATION ("warmelt-normal.melt:6216:/ cond.else");

		      /*^block */
		      /*anyblock */
		      {




			{
			  /*^locexp */
			  melt_assert_failed (("check cladata"),
					      ("warmelt-normal.melt")
					      ? ("warmelt-normal.melt") :
					      __FILE__,
					      (6216) ? (6216) : __LINE__,
					      __FUNCTION__);
			  ;
			}
			;
		  /*clear *//*_._IFELSE___V121*/ meltfptr[117] = 0;
			/*epilog */
		      }
		      ;
		    }
		  ;
		  /*^compute */
		  /*_.IFCPP___V120*/ meltfptr[116] =
		    /*_._IFELSE___V121*/ meltfptr[117];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6216:/ clear");
		/*clear *//*_#IS_A__L46*/ meltfnum[9] = 0;
		  /*^clear */
		/*clear *//*_._IFELSE___V121*/ meltfptr[117] = 0;
		}

#else /*MELT_HAVE_DEBUG */
		/*^cppif.else */
		/*_.IFCPP___V120*/ meltfptr[116] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6217:/ cond");
		/*cond */ if (
			       /*ifisa */
			       melt_is_instance_of ((melt_ptr_t)
						    ( /*_.CURCBIND__V93*/
						     meltfptr[63]),
						    (melt_ptr_t) (( /*!CLASS_NORMAL_CONSTRUCTOR_BINDING */ meltfrout->tabval[11])))
		  )		/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("putslot checkobj @NCONSB_DISCR",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.CURCBIND__V93*/
							 meltfptr[63])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.CURCBIND__V93*/
					     meltfptr[63]), (2),
					    ( /*_.CLADATA__V115*/
					     meltfptr[110]), "NCONSB_DISCR");
		      ;
		      /*^touch */
		      meltgc_touch ( /*_.CURCBIND__V93*/ meltfptr[63]);
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.CURCBIND__V93*/
						    meltfptr[63],
						    "put-fields");
		      ;
		      /*epilog */
		    }
		    ;
		  }		/*noelse */
		;

		MELT_LOCATION ("warmelt-normal.melt:6212:/ clear");
	      /*clear *//*_.CLADATA__V115*/ meltfptr[110] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V116*/ meltfptr[115] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V120*/ meltfptr[116] = 0;

		MELT_LOCATION ("warmelt-normal.melt:6206:/ clear");
	      /*clear *//*_.CLABIND__V107*/ meltfptr[106] = 0;
		/*^clear */
	      /*clear *//*_.CLASYM__V108*/ meltfptr[107] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V109*/ meltfptr[108] = 0;
		/*^clear */
	      /*clear *//*_.IFCPP___V113*/ meltfptr[109] = 0;
		/*epilog */
	      }
	      ;
	    }			/*noelse */
	  ;

	  MELT_LOCATION ("warmelt-normal.melt:6194:/ clear");
	    /*clear *//*_.CURBDISCR__V100*/ meltfptr[53] = 0;
	  /*^clear */
	    /*clear *//*_.CURBINDER__V101*/ meltfptr[37] = 0;
	  /*^clear */
	    /*clear *//*_.NCONSB_LOC__V102*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_.OR___V103*/ meltfptr[102] = 0;
	  /*^clear */
	    /*clear *//*_.NLOCSYM__V105*/ meltfptr[103] = 0;
	  /*^clear */
	    /*clear *//*_#NULL__L40*/ meltfnum[28] = 0;
  /*_#plI__L47*/ meltfnum[27] =
	    (( /*_#CURCIX__L34*/ meltfnum[20]) + (1));;
	  MELT_LOCATION ("warmelt-normal.melt:6220:/ compute");
	  /*_#CURCIX__L34*/ meltfnum[20] = /*_#SETQ___L48*/ meltfnum[9] =
	    /*_#plI__L47*/ meltfnum[27];;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6221:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURCBIND__V93*/ meltfptr[63];
	    /*_.PUT_ENV__V122*/ meltfptr[117] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!PUT_ENV */ meltfrout->tabval[21])),
			  (melt_ptr_t) ( /*_.NEWENV__V22*/ meltfptr[21]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	}			/* end foreach_in_list meltcit4__EACHLIST */
     /*_.CURPAIR__V92*/ meltfptr[44] = NULL;
     /*_.CURCBIND__V93*/ meltfptr[63] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6186:/ clear");
	    /*clear *//*_.CURPAIR__V92*/ meltfptr[44] = 0;
      /*^clear */
	    /*clear *//*_.CURCBIND__V93*/ meltfptr[63] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V94*/ meltfptr[72] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V98*/ meltfptr[39] = 0;
      /*^clear */
	    /*clear *//*_#plI__L47*/ meltfnum[27] = 0;
      /*^clear */
	    /*clear *//*_#SETQ___L48*/ meltfnum[9] = 0;
      /*^clear */
	    /*clear *//*_.PUT_ENV__V122*/ meltfptr[117] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;
    /*citerblock FOREACH_IN_MULTIPLE */
    {
      /* start foreach_in_multiple meltcit5__EACHTUP */
      long meltcit5__EACHTUP_ln =
	melt_multiple_length ((melt_ptr_t) /*_.SBINDS__V18*/ meltfptr[17]);
      for ( /*_#SBIX__L49*/ meltfnum[28] = 0;
	   ( /*_#SBIX__L49*/ meltfnum[28] >= 0)
	   && ( /*_#SBIX__L49*/ meltfnum[28] < meltcit5__EACHTUP_ln);
	/*_#SBIX__L49*/ meltfnum[28]++)
	{
	  /*_.CURSBIND__V123*/ meltfptr[110] =
	    melt_multiple_nth ((melt_ptr_t) ( /*_.SBINDS__V18*/ meltfptr[17]),
			       /*_#SBIX__L49*/ meltfnum[28]);




#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6228:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6228:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6228:/ apply");
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
		    argtab[2].meltbp_long = 6228;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop cursbind=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSBIND__V123*/ meltfptr[110];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " sbix=";
		    /*^apply.arg */
		    argtab[6].meltbp_long = /*_#SBIX__L49*/ meltfnum[28];
		    /*_.MELT_DEBUG_FUN__V126*/ meltfptr[106] =
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
		  /*_._IF___V125*/ meltfptr[116] =
		    /*_.MELT_DEBUG_FUN__V126*/ meltfptr[106];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6228:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L51*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V126*/ meltfptr[106] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V125*/ meltfptr[116] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6228:/ quasiblock");


	    /*_.PROGN___V127*/ meltfptr[107] =
	      /*_._IF___V125*/ meltfptr[116];;
	    /*^compute */
	    /*_.IFCPP___V124*/ meltfptr[115] =
	      /*_.PROGN___V127*/ meltfptr[107];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6228:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L50*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V125*/ meltfptr[116] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V127*/ meltfptr[107] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V124*/ meltfptr[115] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6229:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L52*/ meltfnum[50] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.CURSBIND__V123*/ meltfptr[110]),
				   (melt_ptr_t) (( /*!CLASS_SOURCE_LETREC_BINDING */ meltfrout->tabval[7])));;
	    MELT_LOCATION ("warmelt-normal.melt:6229:/ cond");
	    /*cond */ if ( /*_#IS_A__L52*/ meltfnum[50])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V129*/ meltfptr[109] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6229:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check cursbind"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6229) ? (6229) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V129*/ meltfptr[109] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V128*/ meltfptr[108] =
	      /*_._IFELSE___V129*/ meltfptr[109];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6229:/ clear");
	      /*clear *//*_#IS_A__L52*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V129*/ meltfptr[109] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V128*/ meltfptr[108] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6230:/ quasiblock");


	  /*^getslot */
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) ( /*_.CURSBIND__V123*/ meltfptr[110]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
   /*_.LOCA_LOCATION__V131*/ meltfptr[37] = slot;
	  };
	  ;
	  /*^cond */
	  /*cond */ if ( /*_.LOCA_LOCATION__V131*/ meltfptr[37])	/*then */
	    {
	      /*^cond.then */
	      /*_.LOCB__V132*/ meltfptr[38] =
		/*_.LOCA_LOCATION__V131*/ meltfptr[37];;
	    }
	  else
	    {
	      MELT_LOCATION ("warmelt-normal.melt:6230:/ cond.else");

	      /*^block */
	      /*anyblock */
	      {

		/*^cond */
		/*cond */ if ( /*_.SLOC__V17*/ meltfptr[13])	/*then */
		  {
		    /*^cond.then */
		    /*_.OR___V133*/ meltfptr[102] =
		      /*_.SLOC__V17*/ meltfptr[13];;
		  }
		else
		  {
		    MELT_LOCATION ("warmelt-normal.melt:6230:/ cond.else");

		    /*_.OR___V133*/ meltfptr[102] =
		      /*_.PSLOC__V5*/ meltfptr[4];;
		  }
		;
		/*^compute */
		/*_.LOCB__V132*/ meltfptr[38] =
		  /*_.OR___V133*/ meltfptr[102];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6230:/ clear");
	      /*clear *//*_.OR___V133*/ meltfptr[102] = 0;
	      }
	      ;
	    }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6231:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) ( /*_.CURSBIND__V123*/ meltfptr[110]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 3, "SLETB_BINDER");
   /*_.CURSYMB__V134*/ meltfptr[103] = slot;
	  };
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6232:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) ( /*_.CURSBIND__V123*/ meltfptr[110]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "SLETB_EXPR");
   /*_.CUREXPR__V135*/ meltfptr[106] = slot;
	  };
	  ;
  /*_.CURBIND__V136*/ meltfptr[116] =
	    /*mapobject_get */
	    melt_get_mapobjects ((meltmapobjects_ptr_t)
				 ( /*_.SYMBINDMAP__V24*/ meltfptr[23]),
				 (meltobject_ptr_t) ( /*_.CURSYMB__V134*/
						     meltfptr[103]));;
	  /*^compute */
  /*_.CURSEXPR__V137*/ meltfptr[107] =
	    /*mapobject_get */
	    melt_get_mapobjects ((meltmapobjects_ptr_t)
				 ( /*_.SYMBEXPRMAP__V23*/ meltfptr[22]),
				 (meltobject_ptr_t) ( /*_.CURSYMB__V134*/
						     meltfptr[103]));;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6236:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6236:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6236:/ apply");
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
		    argtab[2].meltbp_long = 6236;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop curexpr=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V135*/ meltfptr[106];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " cursymb=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSYMB__V134*/ meltfptr[103];
		    /*^apply.arg */
		    argtab[7].meltbp_cstring = " curbind=";
		    /*^apply.arg */
		    argtab[8].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURBIND__V136*/ meltfptr[116];
		    /*^apply.arg */
		    argtab[9].meltbp_cstring = " cursexpr=";
		    /*^apply.arg */
		    argtab[10].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CURSEXPR__V137*/ meltfptr[107];
		    /*_.MELT_DEBUG_FUN__V140*/ meltfptr[139] =
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
		  /*_._IF___V139*/ meltfptr[102] =
		    /*_.MELT_DEBUG_FUN__V140*/ meltfptr[139];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6236:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L54*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V140*/ meltfptr[139] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V139*/ meltfptr[102] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6236:/ quasiblock");


	    /*_.PROGN___V141*/ meltfptr[139] =
	      /*_._IF___V139*/ meltfptr[102];;
	    /*^compute */
	    /*_.IFCPP___V138*/ meltfptr[109] =
	      /*_.PROGN___V141*/ meltfptr[139];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6236:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L53*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V139*/ meltfptr[102] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V141*/ meltfptr[139] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V138*/ meltfptr[109] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6240:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#eqeq__L55*/ meltfnum[50] =
	      (( /*_.CUREXPR__V135*/ meltfptr[106]) ==
	       ( /*_.CURSEXPR__V137*/ meltfptr[107]));;
	    MELT_LOCATION ("warmelt-normal.melt:6240:/ cond");
	    /*cond */ if ( /*_#eqeq__L55*/ meltfnum[50])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V143*/ meltfptr[139] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6240:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("check curxpr same cursexpr"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6240) ? (6240) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V143*/ meltfptr[139] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V142*/ meltfptr[102] =
	      /*_._IFELSE___V143*/ meltfptr[139];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6240:/ clear");
	      /*clear *//*_#eqeq__L55*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V143*/ meltfptr[139] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V142*/ meltfptr[102] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6241:/ msend");
	  /*msend */
	  {
	    union meltparam_un argtab[5];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^ojbmsend.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURSYMB__V134*/ meltfptr[103];
	    /*^ojbmsend.arg */
	    argtab[1].meltbp_aptr =
	      (melt_ptr_t *) & /*_.CURBIND__V136*/ meltfptr[116];
	    /*^ojbmsend.arg */
	    argtab[2].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NEWENV__V22*/ meltfptr[21];
	    /*^ojbmsend.arg */
	    argtab[3].meltbp_aptr =
	      (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
	    /*^ojbmsend.arg */
	    argtab[4].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[13];
	    /*_.NORMAL_LETREC_CONSTRUCTIVE__V144*/ meltfptr[139] =
	      meltgc_send ((melt_ptr_t) ( /*_.CUREXPR__V135*/ meltfptr[106]),
			   (melt_ptr_t) (( /*!NORMAL_LETREC_CONSTRUCTIVE */
					  meltfrout->tabval[22])),
			   (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR
			    MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
			   (union meltparam_un *) 0);
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6242:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6242:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6242:/ apply");
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
		    argtab[2].meltbp_long = 6242;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec thirdloop done curexpr";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.CUREXPR__V135*/ meltfptr[106];
		    /*_.MELT_DEBUG_FUN__V147*/ meltfptr[146] =
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
		  /*_._IF___V146*/ meltfptr[145] =
		    /*_.MELT_DEBUG_FUN__V147*/ meltfptr[146];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6242:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L57*/ meltfnum[50] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V147*/ meltfptr[146] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V146*/ meltfptr[145] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6242:/ quasiblock");


	    /*_.PROGN___V148*/ meltfptr[146] =
	      /*_._IF___V146*/ meltfptr[145];;
	    /*^compute */
	    /*_.IFCPP___V145*/ meltfptr[144] =
	      /*_.PROGN___V148*/ meltfptr[146];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6242:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L56*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V146*/ meltfptr[145] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V148*/ meltfptr[146] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V145*/ meltfptr[144] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  /*^compute */
	  /*_.LET___V130*/ meltfptr[53] = /*_.IFCPP___V145*/ meltfptr[144];;

	  MELT_LOCATION ("warmelt-normal.melt:6230:/ clear");
	    /*clear *//*_.LOCA_LOCATION__V131*/ meltfptr[37] = 0;
	  /*^clear */
	    /*clear *//*_.LOCB__V132*/ meltfptr[38] = 0;
	  /*^clear */
	    /*clear *//*_.CURSYMB__V134*/ meltfptr[103] = 0;
	  /*^clear */
	    /*clear *//*_.CUREXPR__V135*/ meltfptr[106] = 0;
	  /*^clear */
	    /*clear *//*_.CURBIND__V136*/ meltfptr[116] = 0;
	  /*^clear */
	    /*clear *//*_.CURSEXPR__V137*/ meltfptr[107] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V138*/ meltfptr[109] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V142*/ meltfptr[102] = 0;
	  /*^clear */
	    /*clear *//*_.NORMAL_LETREC_CONSTRUCTIVE__V144*/ meltfptr[139] = 0;
	  /*^clear */
	    /*clear *//*_.IFCPP___V145*/ meltfptr[144] = 0;
	  if ( /*_#SBIX__L49*/ meltfnum[28] < 0)
	    break;
	}			/* end  foreach_in_multiple meltcit5__EACHTUP */

      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6225:/ clear");
	    /*clear *//*_.CURSBIND__V123*/ meltfptr[110] = 0;
      /*^clear */
	    /*clear *//*_#SBIX__L49*/ meltfnum[28] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V124*/ meltfptr[115] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V128*/ meltfptr[108] = 0;
      /*^clear */
	    /*clear *//*_.LET___V130*/ meltfptr[53] = 0;
    }				/*endciterblock FOREACH_IN_MULTIPLE */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6245:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6245:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6245:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L59*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6245;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring =
		"normexp_letrec recfillbindings before normalizing the body";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECFILLBINDINGS__V85*/ meltfptr[32];
	      /*_.MELT_DEBUG_FUN__V151*/ meltfptr[37] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V150*/ meltfptr[146] =
	      /*_.MELT_DEBUG_FUN__V151*/ meltfptr[37];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6245:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L59*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V151*/ meltfptr[37] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V150*/ meltfptr[146] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6245:/ quasiblock");


      /*_.PROGN___V152*/ meltfptr[38] = /*_._IF___V150*/ meltfptr[146];;
      /*^compute */
      /*_.IFCPP___V149*/ meltfptr[145] = /*_.PROGN___V152*/ meltfptr[38];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6245:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L58*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V150*/ meltfptr[146] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V152*/ meltfptr[38] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V149*/ meltfptr[145] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6248:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6248:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6248:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L61*/ meltfnum[50];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6248;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec normalizing sbody";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SBODY__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V155*/ meltfptr[116] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V154*/ meltfptr[106] =
	      /*_.MELT_DEBUG_FUN__V155*/ meltfptr[116];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6248:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L61*/ meltfnum[50] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V155*/ meltfptr[116] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V154*/ meltfptr[106] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6248:/ quasiblock");


      /*_.PROGN___V156*/ meltfptr[107] = /*_._IF___V154*/ meltfptr[106];;
      /*^compute */
      /*_.IFCPP___V153*/ meltfptr[103] = /*_.PROGN___V156*/ meltfptr[107];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6248:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L60*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IF___V154*/ meltfptr[106] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V156*/ meltfptr[107] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V153*/ meltfptr[103] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6249:/ quasiblock");


    /*^multiapply */
    /*multiapply 4args, 1x.res */
    {
      union meltparam_un argtab[3];

      union meltparam_un restab[1];
      memset (&restab, 0, sizeof (restab));
      memset (&argtab, 0, sizeof (argtab));
      /*^multiapply.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V22*/ meltfptr[21];	/*^multiapply.arg */
      argtab[1].meltbp_aptr = (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];	/*^multiapply.arg */
      argtab[2].meltbp_aptr = (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[13];
      /*^multiapply.xres */
      restab[0].meltbp_aptr =
	(melt_ptr_t *) & /*_.NBODBINDINGS__V159*/ meltfptr[139];
      /*^multiapply.appl */
      /*_.NBODY__V158*/ meltfptr[102] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!NORMALIZE_TUPLE */ meltfrout->tabval[23])),
		    (melt_ptr_t) ( /*_.SBODY__V19*/ meltfptr[18]),
		    (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""),
		    argtab, (MELTBPARSTR_PTR ""), restab);
    }
    ;
    /*^quasiblock */



#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6252:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6252:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6252:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L63*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6252;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec nbody=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBODY__V158*/ meltfptr[102];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nbodbindings=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NBODBINDINGS__V159*/ meltfptr[139];
	      /*_.MELT_DEBUG_FUN__V162*/ meltfptr[146] =
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
	    /*_._IF___V161*/ meltfptr[37] =
	      /*_.MELT_DEBUG_FUN__V162*/ meltfptr[146];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6252:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L63*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V162*/ meltfptr[146] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V161*/ meltfptr[37] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6252:/ quasiblock");


      /*_.PROGN___V163*/ meltfptr[38] = /*_._IF___V161*/ meltfptr[37];;
      /*^compute */
      /*_.IFCPP___V160*/ meltfptr[144] = /*_.PROGN___V163*/ meltfptr[38];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6252:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L62*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V161*/ meltfptr[37] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V163*/ meltfptr[38] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V160*/ meltfptr[144] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6253:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L64*/ meltfnum[49] =
	(( /*_.NBODBINDINGS__V159*/ meltfptr[139]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.NBODBINDINGS__V159*/ meltfptr[139])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6253:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L64*/ meltfnum[49])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V165*/ meltfptr[106] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6253:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("normexp_letrec check nbodbindings"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6253) ? (6253) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V165*/ meltfptr[106] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V164*/ meltfptr[116] = /*_._IFELSE___V165*/ meltfptr[106];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6253:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L64*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V165*/ meltfptr[106] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V164*/ meltfptr[116] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6254:/ cond");
    /*cond */ if (
		   /*ifisa */
		   melt_is_instance_of ((melt_ptr_t)
					( /*_.NLETREC__V86*/ meltfptr[33]),
					(melt_ptr_t) (( /*!CLASS_NREP_LETREC */ meltfrout->tabval[14])))
      )				/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NLET_BODY",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.NLETREC__V86*/
					     meltfptr[33])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.NLETREC__V86*/ meltfptr[33]), (2),
				( /*_.NBODY__V158*/ meltfptr[102]),
				"NLET_BODY");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NLETREC_BODY_BINDINGS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.NLETREC__V86*/
					     meltfptr[33])) ==
			  MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.NLETREC__V86*/ meltfptr[33]), (4),
				( /*_.NBODBINDINGS__V159*/ meltfptr[139]),
				"NLETREC_BODY_BINDINGS");
	  ;
	  /*^touch */
	  meltgc_touch ( /*_.NLETREC__V86*/ meltfptr[33]);
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.NLETREC__V86*/ meltfptr[33],
					"put-fields");
	  ;
	  /*epilog */
	}
	;
      }				/*noelse */
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
   /*_#MELT_NEED_DBG__L65*/ meltfnum[50] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6257:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6257:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L66*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6257;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec updated nletrec";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V86*/ meltfptr[33];
	      /*_.MELT_DEBUG_FUN__V168*/ meltfptr[37] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[3])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V167*/ meltfptr[146] =
	      /*_.MELT_DEBUG_FUN__V168*/ meltfptr[37];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6257:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L66*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V168*/ meltfptr[37] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V167*/ meltfptr[146] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6257:/ quasiblock");


      /*_.PROGN___V169*/ meltfptr[38] = /*_._IF___V167*/ meltfptr[146];;
      /*^compute */
      /*_.IFCPP___V166*/ meltfptr[107] = /*_.PROGN___V169*/ meltfptr[38];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6257:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L65*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V167*/ meltfptr[146] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V169*/ meltfptr[38] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V166*/ meltfptr[107] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6258:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_LIST_OR_NULL__L67*/ meltfnum[49] =
	(( /*_.BINDLIST__V20*/ meltfptr[19]) == NULL
	 ||
	 (melt_unsafe_magic_discr
	  ((melt_ptr_t) ( /*_.BINDLIST__V20*/ meltfptr[19])) ==
	  MELTOBMAG_LIST));;
      MELT_LOCATION ("warmelt-normal.melt:6258:/ cond");
      /*cond */ if ( /*_#IS_LIST_OR_NULL__L67*/ meltfnum[49])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V171*/ meltfptr[37] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6258:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("normexp_letrec check bindlist"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6258) ? (6258) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V171*/ meltfptr[37] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V170*/ meltfptr[106] = /*_._IFELSE___V171*/ meltfptr[37];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6258:/ clear");
	     /*clear *//*_#IS_LIST_OR_NULL__L67*/ meltfnum[49] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V171*/ meltfptr[37] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V170*/ meltfptr[106] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6260:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 6, "NCTX_SYMBCACHEMAP");
  /*_.SYCMAP__V172*/ meltfptr[146] = slot;
    };
    ;
    /*citerblock FOREACH_IN_LIST */
    {
      /* start foreach_in_list meltcit6__EACHLIST */
      for ( /*_.CURPAIR__V173*/ meltfptr[38] =
	   melt_list_first ((melt_ptr_t) /*_.BINDLIST__V20*/ meltfptr[19]);
	   melt_magic_discr ((melt_ptr_t) /*_.CURPAIR__V173*/ meltfptr[38]) ==
	   MELTOBMAG_PAIR;
	   /*_.CURPAIR__V173*/ meltfptr[38] =
	   melt_pair_tail ((melt_ptr_t) /*_.CURPAIR__V173*/ meltfptr[38]))
	{
	  /*_.BND__V174*/ meltfptr[37] =
	    melt_pair_head ((melt_ptr_t) /*_.CURPAIR__V173*/ meltfptr[38]);



#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6264:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6264:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6264:/ apply");
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
		    argtab[2].meltbp_long = 6264;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_letrec removing from sycmap bnd";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.BND__V174*/ meltfptr[37];
		    /*_.MELT_DEBUG_FUN__V177*/ meltfptr[176] =
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
		  /*_._IF___V176*/ meltfptr[175] =
		    /*_.MELT_DEBUG_FUN__V177*/ meltfptr[176];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6264:/ clear");
		/*clear *//*_#MELT_CALLCOUNT__L69*/ meltfnum[49] = 0;
		  /*^clear */
		/*clear *//*_.MELT_DEBUG_FUN__V177*/ meltfptr[176] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

     /*_._IF___V176*/ meltfptr[175] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6264:/ quasiblock");


	    /*_.PROGN___V178*/ meltfptr[176] =
	      /*_._IF___V176*/ meltfptr[175];;
	    /*^compute */
	    /*_.IFCPP___V175*/ meltfptr[174] =
	      /*_.PROGN___V178*/ meltfptr[176];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6264:/ clear");
	      /*clear *//*_#MELT_NEED_DBG__L68*/ meltfnum[50] = 0;
	    /*^clear */
	      /*clear *//*_._IF___V176*/ meltfptr[175] = 0;
	    /*^clear */
	      /*clear *//*_.PROGN___V178*/ meltfptr[176] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V175*/ meltfptr[174] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6265:/ cppif.then");
	  /*^block */
	  /*anyblock */
	  {


	    MELT_CHECK_SIGNAL ();
	    ;
    /*_#IS_A__L70*/ meltfnum[49] =
	      melt_is_instance_of ((melt_ptr_t)
				   ( /*_.BND__V174*/ meltfptr[37]),
				   (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */ meltfrout->tabval[24])));;
	    MELT_LOCATION ("warmelt-normal.melt:6265:/ cond");
	    /*cond */ if ( /*_#IS_A__L70*/ meltfnum[49])	/*then */
	      {
		/*^cond.then */
		/*_._IFELSE___V180*/ meltfptr[176] = ( /*nil */ NULL);;
	      }
	    else
	      {
		MELT_LOCATION ("warmelt-normal.melt:6265:/ cond.else");

		/*^block */
		/*anyblock */
		{




		  {
		    /*^locexp */
		    melt_assert_failed (("normexp_letrec check bnd"),
					("warmelt-normal.melt")
					? ("warmelt-normal.melt") : __FILE__,
					(6265) ? (6265) : __LINE__,
					__FUNCTION__);
		    ;
		  }
		  ;
		/*clear *//*_._IFELSE___V180*/ meltfptr[176] = 0;
		  /*epilog */
		}
		;
	      }
	    ;
	    /*^compute */
	    /*_.IFCPP___V179*/ meltfptr[175] =
	      /*_._IFELSE___V180*/ meltfptr[176];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6265:/ clear");
	      /*clear *//*_#IS_A__L70*/ meltfnum[49] = 0;
	    /*^clear */
	      /*clear *//*_._IFELSE___V180*/ meltfptr[176] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V179*/ meltfptr[175] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6266:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.BND__V174*/ meltfptr[37]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 0, "BINDER");
   /*_.BINDER__V181*/ meltfptr[176] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_remove_mapobjects ((meltmapobjects_ptr_t)
				      ( /*_.SYCMAP__V172*/ meltfptr[146]),
				      (meltobject_ptr_t) ( /*_.BINDER__V181*/
							  meltfptr[176]));
	  }
	  ;
	}			/* end foreach_in_list meltcit6__EACHLIST */
     /*_.CURPAIR__V173*/ meltfptr[38] = NULL;
     /*_.BND__V174*/ meltfptr[37] = NULL;


      /*citerepilog */

      MELT_LOCATION ("warmelt-normal.melt:6261:/ clear");
	    /*clear *//*_.CURPAIR__V173*/ meltfptr[38] = 0;
      /*^clear */
	    /*clear *//*_.BND__V174*/ meltfptr[37] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V175*/ meltfptr[174] = 0;
      /*^clear */
	    /*clear *//*_.IFCPP___V179*/ meltfptr[175] = 0;
      /*^clear */
	    /*clear *//*_.BINDER__V181*/ meltfptr[176] = 0;
    }				/*endciterblock FOREACH_IN_LIST */
    ;

    MELT_LOCATION ("warmelt-normal.melt:6260:/ clear");
	   /*clear *//*_.SYCMAP__V172*/ meltfptr[146] = 0;
    MELT_LOCATION ("warmelt-normal.melt:6269:/ quasiblock");


 /*_.NLASTBODY__V183*/ meltfptr[182] =
      (melt_multiple_nth
       ((melt_ptr_t) ( /*_.NBODY__V158*/ meltfptr[102]), (-1)));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6272:/ msend");
    /*msend */
    {
      union meltparam_un argtab[1];
      memset (&argtab, 0, sizeof (argtab));
      /*^ojbmsend.arg */
      argtab[0].meltbp_aptr = (melt_ptr_t *) & /*_.NEWENV__V22*/ meltfptr[21];
      /*_.GET_CTYPE__V184*/ meltfptr[183] =
	meltgc_send ((melt_ptr_t) ( /*_.NLASTBODY__V183*/ meltfptr[182]),
		     (melt_ptr_t) (( /*!GET_CTYPE */ meltfrout->tabval[26])),
		     (MELTBPARSTR_PTR ""), argtab, "",
		     (union meltparam_un *) 0);
    }
    ;
    /*^cond */
    /*cond */ if ( /*_.GET_CTYPE__V184*/ meltfptr[183])	/*then */
      {
	/*^cond.then */
	/*_.NLASTYP__V185*/ meltfptr[184] =
	  /*_.GET_CTYPE__V184*/ meltfptr[183];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6272:/ cond.else");

	/*_.NLASTYP__V185*/ meltfptr[184] =
	  ( /*!CTYPE_VOID */ meltfrout->tabval[25]);;
      }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6273:/ apply");
    /*apply */
    {
      /*_.CSYM__V186*/ meltfptr[185] =
	melt_apply ((meltclosure_ptr_t)
		    (( /*!CLONE_SYMBOL */ meltfrout->tabval[27])),
		    (melt_ptr_t) (( /*!konst_28_LETREC_ */ meltfrout->
				   tabval[28])), (""),
		    (union meltparam_un *) 0, "", (union meltparam_un *) 0);
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6274:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NORMAL_LET_BINDING */
					     meltfrout->tabval[24])), (4),
			      "CLASS_NORMAL_LET_BINDING");
  /*_.INST__V188*/ meltfptr[187] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @BINDER",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V188*/ meltfptr[187])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V188*/ meltfptr[187]), (0),
			  ( /*_.CSYM__V186*/ meltfptr[185]), "BINDER");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @LETBIND_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V188*/ meltfptr[187])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V188*/ meltfptr[187]), (3),
			  ( /*_.SLOC__V17*/ meltfptr[13]), "LETBIND_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @LETBIND_TYPE",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V188*/ meltfptr[187])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V188*/ meltfptr[187]), (1),
			  ( /*_.NLASTYP__V185*/ meltfptr[184]),
			  "LETBIND_TYPE");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @LETBIND_EXPR",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V188*/ meltfptr[187])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V188*/ meltfptr[187]), (2),
			  ( /*_.NLETREC__V86*/ meltfptr[33]), "LETBIND_EXPR");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V188*/ meltfptr[187],
				  "newly made instance");
    ;
    /*_.CBIND__V187*/ meltfptr[186] = /*_.INST__V188*/ meltfptr[187];;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6279:/ quasiblock");


    /*^rawallocobj */
    /*rawallocobj */
    {
      melt_ptr_t newobj = 0;
      melt_raw_object_create (newobj,
			      (melt_ptr_t) (( /*!CLASS_NREP_LOCSYMOCC */
					     meltfrout->tabval[15])), (4),
			      "CLASS_NREP_LOCSYMOCC");
  /*_.INST__V190*/ meltfptr[189] =
	newobj;
    };
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NREP_LOC",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V190*/ meltfptr[189])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V190*/ meltfptr[189]), (0),
			  ( /*_.SLOC__V17*/ meltfptr[13]), "NREP_LOC");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NOCC_CTYP",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V190*/ meltfptr[189])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V190*/ meltfptr[189]), (2),
			  ( /*_.NLASTYP__V185*/ meltfptr[184]), "NOCC_CTYP");
    ;
    /*^putslot */
    /*putslot */
    melt_assertmsg ("putslot checkobj @NOCC_BIND",
		    melt_magic_discr ((melt_ptr_t)
				      ( /*_.INST__V190*/ meltfptr[189])) ==
		    MELTOBMAG_OBJECT);
    melt_putfield_object (( /*_.INST__V190*/ meltfptr[189]), (3),
			  ( /*_.CBIND__V187*/ meltfptr[186]), "NOCC_BIND");
    ;
    /*^touchobj */

    melt_dbgtrace_written_object ( /*_.INST__V190*/ meltfptr[189],
				  "newly made instance");
    ;
    /*_.CLOCC__V189*/ meltfptr[188] = /*_.INST__V190*/ meltfptr[189];;
    /*^compute */
 /*_.RESBINDS__V191*/ meltfptr[190] =
      (meltgc_new_list
       ((meltobject_ptr_t) (( /*!DISCR_LIST */ meltfrout->tabval[4]))));;

    {
      MELT_LOCATION ("warmelt-normal.melt:6285:/ locexp");
      meltgc_append_list ((melt_ptr_t) ( /*_.RESBINDS__V191*/ meltfptr[190]),
			  (melt_ptr_t) ( /*_.CBIND__V187*/ meltfptr[186]));
    }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6286:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6286:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6286:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[9];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L72*/ meltfnum[49];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6286;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_letrec result clocc=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLOCC__V189*/ meltfptr[188];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = " nletrec=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.NLETREC__V86*/ meltfptr[33];
	      /*^apply.arg */
	      argtab[7].meltbp_cstring = " resbinds=";
	      /*^apply.arg */
	      argtab[8].meltbp_aptr =
		(melt_ptr_t *) & /*_.RESBINDS__V191*/ meltfptr[190];
	      /*_.MELT_DEBUG_FUN__V194*/ meltfptr[193] =
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
	    /*_._IF___V193*/ meltfptr[192] =
	      /*_.MELT_DEBUG_FUN__V194*/ meltfptr[193];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6286:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L72*/ meltfnum[49] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V194*/ meltfptr[193] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V193*/ meltfptr[192] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6286:/ quasiblock");


      /*_.PROGN___V195*/ meltfptr[193] = /*_._IF___V193*/ meltfptr[192];;
      /*^compute */
      /*_.IFCPP___V192*/ meltfptr[191] = /*_.PROGN___V195*/ meltfptr[193];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6286:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L71*/ meltfnum[50] = 0;
      /*^clear */
	     /*clear *//*_._IF___V193*/ meltfptr[192] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V195*/ meltfptr[193] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V192*/ meltfptr[191] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:6288:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normexp_letrec ending"), (15));
#endif
      ;
    }
    ;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6289:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.CLOCC__V189*/ meltfptr[188];;
    MELT_LOCATION ("warmelt-normal.melt:6289:/ putxtraresult");
    if (!meltxrestab_ || !meltxresdescr_)
      goto meltlabend_rout;
    if (meltxresdescr_[0] != MELTBPAR_PTR)
      goto meltlabend_rout;
    if (meltxrestab_[0].meltbp_aptr)
      *(meltxrestab_[0].meltbp_aptr) =
	(melt_ptr_t) ( /*_.RESBINDS__V191*/ meltfptr[190]);
    ;
    /*^finalreturn */
    ;
    /*finalret */ goto meltlabend_rout;
    /*_.LET___V182*/ meltfptr[146] = /*_.RETURN___V196*/ meltfptr[192];;

    MELT_LOCATION ("warmelt-normal.melt:6269:/ clear");
	   /*clear *//*_.NLASTBODY__V183*/ meltfptr[182] = 0;
    /*^clear */
	   /*clear *//*_.GET_CTYPE__V184*/ meltfptr[183] = 0;
    /*^clear */
	   /*clear *//*_.NLASTYP__V185*/ meltfptr[184] = 0;
    /*^clear */
	   /*clear *//*_.CSYM__V186*/ meltfptr[185] = 0;
    /*^clear */
	   /*clear *//*_.CBIND__V187*/ meltfptr[186] = 0;
    /*^clear */
	   /*clear *//*_.CLOCC__V189*/ meltfptr[188] = 0;
    /*^clear */
	   /*clear *//*_.RESBINDS__V191*/ meltfptr[190] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V192*/ meltfptr[191] = 0;
    /*^clear */
	   /*clear *//*_.RETURN___V196*/ meltfptr[192] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*_.MULTI___V157*/ meltfptr[109] = /*_.LET___V182*/ meltfptr[146];;

    MELT_LOCATION ("warmelt-normal.melt:6249:/ clear");
	   /*clear *//*_.IFCPP___V160*/ meltfptr[144] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V164*/ meltfptr[116] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V166*/ meltfptr[107] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V170*/ meltfptr[106] = 0;
    /*^clear */
	   /*clear *//*_.LET___V182*/ meltfptr[146] = 0;

    /*^clear */
	   /*clear *//*_.NBODBINDINGS__V159*/ meltfptr[139] = 0;
    /*_.LET___V82*/ meltfptr[46] = /*_.MULTI___V157*/ meltfptr[109];;

    MELT_LOCATION ("warmelt-normal.melt:6166:/ clear");
	   /*clear *//*_#NBCONSBIND__L33*/ meltfnum[10] = 0;
    /*^clear */
	   /*clear *//*_#CURCIX__L34*/ meltfnum[20] = 0;
    /*^clear */
	   /*clear *//*_.NLOCSYMS__V83*/ meltfptr[47] = 0;
    /*^clear */
	   /*clear *//*_.NCBINDTUP__V84*/ meltfptr[48] = 0;
    /*^clear */
	   /*clear *//*_.RECFILLBINDINGS__V85*/ meltfptr[32] = 0;
    /*^clear */
	   /*clear *//*_.NLETREC__V86*/ meltfptr[33] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V88*/ meltfptr[36] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V149*/ meltfptr[145] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V153*/ meltfptr[103] = 0;
    /*^clear */
	   /*clear *//*_.MULTI___V157*/ meltfptr[109] = 0;
    /*_.LET___V16*/ meltfptr[12] = /*_.LET___V82*/ meltfptr[46];;

    MELT_LOCATION ("warmelt-normal.melt:6106:/ clear");
	   /*clear *//*_.SLOC__V17*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.SBINDS__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.SBODY__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_#NBBIND__L6*/ meltfnum[4] = 0;
    /*^clear */
	   /*clear *//*_.BINDLIST__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_.CONSBINDLIST__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.NEWENV__V22*/ meltfptr[21] = 0;
    /*^clear */
	   /*clear *//*_#stI__L7*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_#MAPLEN__L8*/ meltfnum[7] = 0;
    /*^clear */
	   /*clear *//*_.SYMBEXPRMAP__V23*/ meltfptr[22] = 0;
    /*^clear */
	   /*clear *//*_.SYMBINDMAP__V24*/ meltfptr[23] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V78*/ meltfptr[54] = 0;
    /*^clear */
	   /*clear *//*_.LET___V82*/ meltfptr[46] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6101:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V16*/ meltfptr[12];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6101:/ locexp");
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
	   /*clear *//*_.IFCPP___V12*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.LET___V16*/ meltfptr[12] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_LETREC", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_114_WARMELTmiNORMAL_NORMEXP_LETREC */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF_melt
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

  struct meltframe_meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF_st
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
#define MELTFRAM_NBVARPTR 35
    melt_ptr_t mcfr_varptr[35];
#define MELTFRAM_NBVARNUM 12
    long mcfr_varnum[12];
/*others*/
    const char *loc_CSTRING__o0;
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF_st *)
	meltfirstargp_;
      /* use arguments meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 35; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF nbval 35*/
  meltfram__.mcfr_nbvar = 35 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_PREDEF", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6298:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6299:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6299:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6299:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6299;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_predef pred=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.PRED__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:6299:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:6299:/ quasiblock");


      /*_.PROGN___V8*/ meltfptr[6] = /*_._IF___V6*/ meltfptr[5];;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[4] = /*_.PROGN___V8*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6299:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V8*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6300:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6300:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V10*/ meltfptr[6] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6300:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6300) ? (6300) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V10*/ meltfptr[6] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V9*/ meltfptr[5] = /*_._IFELSE___V10*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6300:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V10*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V9*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6301:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 7, "NCTX_PREDEFMAP");
  /*_.PREDEFMAP__V12*/ meltfptr[11] = slot;
    };
    ;
 /*_.MAPOBJECT_GET__V13*/ meltfptr[12] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.PREDEFMAP__V12*/ meltfptr[11]),
			   (meltobject_ptr_t) ( /*_.PRED__V2*/ meltfptr[1]));;
    MELT_LOCATION ("warmelt-normal.melt:6302:/ cond");
    /*cond */ if ( /*_.MAPOBJECT_GET__V13*/ meltfptr[12])	/*then */
      {
	/*^cond.then */
	/*_.BRK__V14*/ meltfptr[13] = /*_.MAPOBJECT_GET__V13*/ meltfptr[12];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6302:/ cond.else");

	/*^block */
	/*anyblock */
	{

   /*_.GET_RAW_SYMBOL__V15*/ meltfptr[14] =
	    melthookproc_HOOK_NAMED_SYMBOL ((const char *) ( /*_?*/
							    meltfram__.
							    loc_CSTRING__o0),
					    (long) MELT_GET);;
	  /*^compute */
	  /*_.BRK__V14*/ meltfptr[13] =
	    /*_.GET_RAW_SYMBOL__V15*/ meltfptr[14];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6302:/ clear");
	     /*clear *//*_.GET_RAW_SYMBOL__V15*/ meltfptr[14] = 0;
	}
	;
      }
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
   /*_#MELT_NEED_DBG__L4*/ meltfnum[0] =
	/*MELT_NEED_DBG */
#if MELT_HAVE_DEBUG
	( /*melt_need_dbg */ melt_need_debug ((int) 0))
#else
	0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	;;
      MELT_LOCATION ("warmelt-normal.melt:6305:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6305:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L5*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6305;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_predef brk=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.BRK__V14*/ meltfptr[13];
	      /*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6305:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V18*/ meltfptr[17] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V17*/ meltfptr[16] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6305:/ quasiblock");


      /*_.PROGN___V19*/ meltfptr[17] = /*_._IF___V17*/ meltfptr[16];;
      /*^compute */
      /*_.IFCPP___V16*/ meltfptr[14] = /*_.PROGN___V19*/ meltfptr[17];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6305:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V17*/ meltfptr[16] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V19*/ meltfptr[17] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V16*/ meltfptr[14] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_INTEGERBOX__L6*/ meltfnum[1] =
      (melt_magic_discr ((melt_ptr_t) ( /*_.BRK__V14*/ meltfptr[13])) ==
       MELTOBMAG_INT);;
    MELT_LOCATION ("warmelt-normal.melt:6306:/ cond");
    /*cond */ if ( /*_#IS_INTEGERBOX__L6*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*_#OR___L7*/ meltfnum[0] = /*_#IS_INTEGERBOX__L6*/ meltfnum[1];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6306:/ cond.else");

	/*^block */
	/*anyblock */
	{

   /*_#IS_A__L8*/ meltfnum[7] =
	    melt_is_instance_of ((melt_ptr_t) ( /*_.BRK__V14*/ meltfptr[13]),
				 (melt_ptr_t) (( /*!CLASS_SYMBOL */
						meltfrout->tabval[2])));;
	  /*^compute */
	  /*_#OR___L7*/ meltfnum[0] = /*_#IS_A__L8*/ meltfnum[7];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6306:/ clear");
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

	  MELT_LOCATION ("warmelt-normal.melt:6307:/ quasiblock");



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
    /*_.INST__V23*/ meltfptr[22] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V23*/ meltfptr[22]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V23*/ meltfptr[22]), (0),
				( /*_.SLOC__V4*/ meltfptr[3]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NRPREDEF",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V23*/ meltfptr[22]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V23*/ meltfptr[22]), (1),
				( /*_.BRK__V14*/ meltfptr[13]), "NRPREDEF");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V23*/ meltfptr[22],
					"newly made instance");
	  ;
	  /*_.RES__V22*/ meltfptr[21] = /*_.INST__V23*/ meltfptr[22];;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6311:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6311:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6311:/ apply");
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
		    argtab[2].meltbp_long = 6311;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normal_predef res=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.RES__V22*/ meltfptr[21];
		    /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25] =
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
		  /*_._IF___V25*/ meltfptr[24] =
		    /*_.MELT_DEBUG_FUN__V26*/ meltfptr[25];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6311:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[9] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:6311:/ quasiblock");


	    /*_.PROGN___V27*/ meltfptr[25] = /*_._IF___V25*/ meltfptr[24];;
	    /*^compute */
	    /*_.IFCPP___V24*/ meltfptr[23] = /*_.PROGN___V27*/ meltfptr[25];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6311:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V25*/ meltfptr[24] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V27*/ meltfptr[25] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V24*/ meltfptr[23] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6312:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.RES__V22*/ meltfptr[21];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6312:/ locexp");
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
	  /*_.LET___V21*/ meltfptr[17] = /*_.RETURN___V28*/ meltfptr[24];;

	  MELT_LOCATION ("warmelt-normal.melt:6307:/ clear");
	     /*clear *//*_.RES__V22*/ meltfptr[21] = 0;
	  /*^clear */
	     /*clear *//*_.IFCPP___V24*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V28*/ meltfptr[24] = 0;
	  /*_._IFELSE___V20*/ meltfptr[16] = /*_.LET___V21*/ meltfptr[17];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6306:/ clear");
	     /*clear *//*_.LET___V21*/ meltfptr[17] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6314:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6314:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6314:/ apply");
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
		    argtab[2].meltbp_long = 6314;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normalpredef fail predefmap=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.PREDEFMAP__V12*/ meltfptr[11];
		    /*^apply.arg */
		    argtab[5].meltbp_cstring = " pred=";
		    /*^apply.arg */
		    argtab[6].meltbp_aptr =
		      (melt_ptr_t *) & /*_.PRED__V2*/ meltfptr[1];
		    /*_.MELT_DEBUG_FUN__V31*/ meltfptr[23] =
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
		  /*_._IF___V30*/ meltfptr[21] =
		    /*_.MELT_DEBUG_FUN__V31*/ meltfptr[23];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6314:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L12*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V31*/ meltfptr[23] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V30*/ meltfptr[21] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6314:/ quasiblock");


	    /*_.PROGN___V32*/ meltfptr[24] = /*_._IF___V30*/ meltfptr[21];;
	    /*^compute */
	    /*_.IFCPP___V29*/ meltfptr[25] = /*_.PROGN___V32*/ meltfptr[24];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6314:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L11*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V30*/ meltfptr[21] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V32*/ meltfptr[24] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V29*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;
	  /*^compute */
   /*_.MAKE_STRINGCONST__V33*/ meltfptr[17] =
	    (meltgc_new_stringdup
	     ((meltobject_ptr_t)
	      (( /*!DISCR_VERBATIM_STRING */ meltfrout->tabval[4])),
	      ( /*_?*/ meltfram__.loc_CSTRING__o0)));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6315:/ locexp");
	    melt_error_str ((melt_ptr_t) ( /*_.SLOC__V4*/ meltfptr[3]),
			    ("not a predef:"),
			    (melt_ptr_t) ( /*_.MAKE_STRINGCONST__V33*/
					  meltfptr[17]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6316:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = ( /*nil */ NULL);;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6316:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6313:/ quasiblock");


	  /*_.PROGN___V35*/ meltfptr[21] = /*_.RETURN___V34*/ meltfptr[23];;
	  /*^compute */
	  /*_._IFELSE___V20*/ meltfptr[16] = /*_.PROGN___V35*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6306:/ clear");
	     /*clear *//*_.IFCPP___V29*/ meltfptr[25] = 0;
	  /*^clear */
	     /*clear *//*_.MAKE_STRINGCONST__V33*/ meltfptr[17] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V34*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V35*/ meltfptr[21] = 0;
	}
	;
      }
    ;
    /*_.LET___V11*/ meltfptr[6] = /*_._IFELSE___V20*/ meltfptr[16];;

    MELT_LOCATION ("warmelt-normal.melt:6301:/ clear");
	   /*clear *//*_.PREDEFMAP__V12*/ meltfptr[11] = 0;
    /*^clear */
	   /*clear *//*_.MAPOBJECT_GET__V13*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.BRK__V14*/ meltfptr[13] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V16*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_#IS_INTEGERBOX__L6*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_#OR___L7*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V20*/ meltfptr[16] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6298:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V11*/ meltfptr[6];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6298:/ locexp");
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
	   /*clear *//*_.IFCPP___V5*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V9*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.LET___V11*/ meltfptr[6] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_PREDEF", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_115_WARMELTmiNORMAL_NORMAL_PREDEF */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_melt
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

  struct meltframe_meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_st
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
#define MELTFRAM_NBVARNUM 11
    long mcfr_varnum[11];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_st
	 *) meltfirstargp_;
      /* use arguments meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA nbval 42*/
  meltfram__.mcfr_nbvar = 42 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_SYMBOL_DATA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6321:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6323:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6323:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6323:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6323;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_symbol_data start sym=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.SYM__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:6323:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:6323:/ quasiblock");


      /*_.PROGN___V8*/ meltfptr[6] = /*_._IF___V6*/ meltfptr[5];;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[4] = /*_.PROGN___V8*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6323:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V8*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6324:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_.DISCRIM__V10*/ meltfptr[6] =
	((melt_ptr_t)
	 (melt_discr ((melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]))));;
      /*^compute */
   /*_#eqeq__L3*/ meltfnum[1] =
	(( /*_.DISCRIM__V10*/ meltfptr[6]) ==
	 (( /*!CLASS_SYMBOL */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6324:/ cond");
      /*cond */ if ( /*_#eqeq__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6324:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check symb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6324) ? (6324) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V9*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6324:/ clear");
	     /*clear *//*_.DISCRIM__V10*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_#eqeq__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V9*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6325:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6325:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6325:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6325) ? (6325) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[6] = /*_._IFELSE___V13*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6325:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6326:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NCTX_VALMAP");
  /*_.VALMAP__V15*/ meltfptr[14] = slot;
    };
    ;
 /*_.OSYDATA__V16*/ meltfptr[15] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.VALMAP__V15*/ meltfptr[14]),
			   (meltobject_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6328:/ cond");
    /*cond */ if ( /*_.OSYDATA__V16*/ meltfptr[15])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6330:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6330:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6330:/ apply");
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
		    argtab[2].meltbp_long = 6330;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_symbol_data found osydata";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.OSYDATA__V16*/ meltfptr[15];
		    /*_.MELT_DEBUG_FUN__V20*/ meltfptr[19] =
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
		  /*_._IF___V19*/ meltfptr[18] =
		    /*_.MELT_DEBUG_FUN__V20*/ meltfptr[19];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6330:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[0] = 0;
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
	    MELT_LOCATION ("warmelt-normal.melt:6330:/ quasiblock");


	    /*_.PROGN___V21*/ meltfptr[19] = /*_._IF___V19*/ meltfptr[18];;
	    /*^compute */
	    /*_.IFCPP___V18*/ meltfptr[17] = /*_.PROGN___V21*/ meltfptr[19];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6330:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V19*/ meltfptr[18] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V21*/ meltfptr[19] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V18*/ meltfptr[17] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6331:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.OSYDATA__V16*/ meltfptr[15];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6331:/ locexp");
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
	  MELT_LOCATION ("warmelt-normal.melt:6329:/ quasiblock");


	  /*_.PROGN___V23*/ meltfptr[19] = /*_.RETURN___V22*/ meltfptr[18];;
	  /*^compute */
	  /*_._IFELSE___V17*/ meltfptr[16] = /*_.PROGN___V23*/ meltfptr[19];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6328:/ clear");
	     /*clear *//*_.IFCPP___V18*/ meltfptr[17] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V22*/ meltfptr[18] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V23*/ meltfptr[19] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6332:/ quasiblock");


   /*_#SYHASH__L7*/ meltfnum[0] =
	    (melt_obj_hash ((melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6333:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.SYM__V2*/ meltfptr[1]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.SYNAMSTR__V25*/ meltfptr[18] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6337:/ apply");
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
	    /*_.NORMAL_PREDEF__V26*/ meltfptr[19] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!DISCR_STRING */ meltfrout->
					 tabval[5])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6336:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[3])), (6), "CLASS_NREP_DATASTRING");
    /*_.INST__V28*/ meltfptr[27] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (4),
				( /*_.NORMAL_PREDEF__V26*/ meltfptr[19]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NSTR_STRING",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (5),
				( /*_.SYNAMSTR__V25*/ meltfptr[18]),
				"NSTR_STRING");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V28*/ meltfptr[27],
					"newly made instance");
	  ;
	  /*_.SYNAMSTRDATA__V27*/ meltfptr[26] =
	    /*_.INST__V28*/ meltfptr[27];;
	  MELT_LOCATION ("warmelt-normal.melt:6341:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
			     tabval[1])) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
    /*_.CLASS_FIELDS__V29*/ meltfptr[28] = slot;
	  };
	  ;
   /*_#MULTIPLE_LENGTH__L8*/ meltfnum[1] =
	    (melt_multiple_length
	     ((melt_ptr_t) ( /*_.CLASS_FIELDS__V29*/ meltfptr[28])));;
	  /*^compute */
   /*_.SYSLOTS__V30*/ meltfptr[29] =
	    (meltgc_new_multiple
	     ((meltobject_ptr_t)
	      (( /*!DISCR_MULTIPLE */ meltfrout->tabval[6])),
	      ( /*_#MULTIPLE_LENGTH__L8*/ meltfnum[1])));;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6344:/ apply");
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
	    /*_.NORMAL_PREDEF__V31*/ meltfptr[30] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!CLASS_SYMBOL */ meltfrout->
					 tabval[1])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
   /*_.MAKE_INTEGERBOX__V32*/ meltfptr[31] =
	    (meltgc_new_int
	     ((meltobject_ptr_t)
	      (( /*!DISCR_INTEGER */ meltfrout->tabval[8])),
	      ( /*_#SYHASH__L7*/ meltfnum[0])));;
	  MELT_LOCATION ("warmelt-normal.melt:6342:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASYMBOL */ meltfrout->tabval[7])), (10), "CLASS_NREP_DATASYMBOL");
    /*_.INST__V34*/ meltfptr[33] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_NAME",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (1),
				( /*_.SYM__V2*/ meltfptr[1]), "NDATA_NAME");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (4),
				( /*_.NORMAL_PREDEF__V31*/ meltfptr[30]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NINST_HASH",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (7),
				( /*_.MAKE_INTEGERBOX__V32*/ meltfptr[31]),
				"NINST_HASH");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NINST_SLOTS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (8),
				( /*_.SYSLOTS__V30*/ meltfptr[29]),
				"NINST_SLOTS");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDSY_NAMESTR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V34*/ meltfptr[33]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V34*/ meltfptr[33]), (9),
				( /*_.SYNAMSTR__V25*/ meltfptr[18]),
				"NDSY_NAMESTR");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V34*/ meltfptr[33],
					"newly made instance");
	  ;
	  /*_.SYDATA__V33*/ meltfptr[32] = /*_.INST__V34*/ meltfptr[33];;
	  /*^compute */
   /*_#OBJ_NUM__L9*/ meltfnum[8] =
	    (melt_obj_num
	     ((melt_ptr_t) (( /*!NAMED_NAME */ meltfrout->tabval[9]))));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6349:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.SYSLOTS__V30*/ meltfptr[29]),
				     ( /*_#OBJ_NUM__L9*/ meltfnum[8]),
				     (melt_ptr_t) ( /*_.SYNAMSTRDATA__V27*/
						   meltfptr[26]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6350:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYDATA__V33*/ meltfptr[32];
	    /*_.ADD_NCTX_DATA__V35*/ meltfptr[34] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6351:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYNAMSTRDATA__V27*/ meltfptr[26];
	    /*_.ADD_NCTX_DATA__V36*/ meltfptr[35] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6352:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.VALMAP__V15*/ meltfptr[14]),
				   (meltobject_ptr_t) ( /*_.SYM__V2*/
						       meltfptr[1]),
				   (melt_ptr_t) ( /*_.SYDATA__V33*/
						 meltfptr[32]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6353:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 4, "NCTX_SYMBMAP");
    /*_.NCTX_SYMBMAP__V37*/ meltfptr[36] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_put_mapstrings ((struct meltmapstrings_st *) ( /*_.NCTX_SYMBMAP__V37*/ meltfptr[36]),
				   melt_string_str ((melt_ptr_t)
						    ( /*_.SYNAMSTR__V25*/
						     meltfptr[18])),
				   (melt_ptr_t) ( /*_.SYDATA__V33*/
						 meltfptr[32]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6354:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6354:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6354:/ apply");
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
		    argtab[2].meltbp_long = 6354;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_symbol_data return sydata";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.SYDATA__V33*/ meltfptr[32];
		    /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] =
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
		  /*_._IF___V39*/ meltfptr[38] =
		    /*_.MELT_DEBUG_FUN__V40*/ meltfptr[39];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6354:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L11*/ meltfnum[10] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V40*/ meltfptr[39] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V39*/ meltfptr[38] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6354:/ quasiblock");


	    /*_.PROGN___V41*/ meltfptr[39] = /*_._IF___V39*/ meltfptr[38];;
	    /*^compute */
	    /*_.IFCPP___V38*/ meltfptr[37] = /*_.PROGN___V41*/ meltfptr[39];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6354:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L10*/ meltfnum[9] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V39*/ meltfptr[38] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V41*/ meltfptr[39] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V38*/ meltfptr[37] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6355:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.SYDATA__V33*/ meltfptr[32];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6355:/ locexp");
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
	  /*_.LET___V24*/ meltfptr[17] = /*_.RETURN___V42*/ meltfptr[38];;

	  MELT_LOCATION ("warmelt-normal.melt:6332:/ clear");
	     /*clear *//*_#SYHASH__L7*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTR__V25*/ meltfptr[18] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V26*/ meltfptr[19] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTRDATA__V27*/ meltfptr[26] = 0;
	  /*^clear */
	     /*clear *//*_.CLASS_FIELDS__V29*/ meltfptr[28] = 0;
	  /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L8*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_.SYSLOTS__V30*/ meltfptr[29] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V31*/ meltfptr[30] = 0;
	  /*^clear */
	     /*clear *//*_.MAKE_INTEGERBOX__V32*/ meltfptr[31] = 0;
	  /*^clear */
	     /*clear *//*_.SYDATA__V33*/ meltfptr[32] = 0;
	  /*^clear */
	     /*clear *//*_#OBJ_NUM__L9*/ meltfnum[8] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V35*/ meltfptr[34] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V36*/ meltfptr[35] = 0;
	  /*^clear */
	     /*clear *//*_.NCTX_SYMBMAP__V37*/ meltfptr[36] = 0;
	  /*^clear */
	     /*clear *//*_.IFCPP___V38*/ meltfptr[37] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V42*/ meltfptr[38] = 0;
	  /*_._IFELSE___V17*/ meltfptr[16] = /*_.LET___V24*/ meltfptr[17];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6328:/ clear");
	     /*clear *//*_.LET___V24*/ meltfptr[17] = 0;
	}
	;
      }
    ;
    /*_.LET___V14*/ meltfptr[10] = /*_._IFELSE___V17*/ meltfptr[16];;

    MELT_LOCATION ("warmelt-normal.melt:6326:/ clear");
	   /*clear *//*_.VALMAP__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.OSYDATA__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V17*/ meltfptr[16] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6321:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[10];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6321:/ locexp");
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
	   /*clear *//*_.IFCPP___V5*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V9*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_SYMBOL_DATA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_116_WARMELTmiNORMAL_NORMAL_SYMBOL_DATA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA (meltclosure_ptr_t
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
    current_blocklevel_signals_meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_melt
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

  struct meltframe_meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_st
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
#define MELTFRAM_NBVARNUM 9
    long mcfr_varnum[9];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_st
	 *) meltfirstargp_;
      /* use arguments meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA nbval 36*/
  meltfram__.mcfr_nbvar = 36 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMAL_KEYWORD_DATA", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6361:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6363:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6363:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6363:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6363;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normal_keyword_data keyw=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.KEYW__V2*/ meltfptr[1];
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

	    MELT_LOCATION ("warmelt-normal.melt:6363:/ clear");
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
      MELT_LOCATION ("warmelt-normal.melt:6363:/ quasiblock");


      /*_.PROGN___V8*/ meltfptr[6] = /*_._IF___V6*/ meltfptr[5];;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[4] = /*_.PROGN___V8*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6363:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V8*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[4] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6364:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_.DISCRIM__V10*/ meltfptr[6] =
	((melt_ptr_t)
	 (melt_discr ((melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]))));;
      /*^compute */
   /*_#eqeq__L3*/ meltfnum[1] =
	(( /*_.DISCRIM__V10*/ meltfptr[6]) ==
	 (( /*!CLASS_KEYWORD */ meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6364:/ cond");
      /*cond */ if ( /*_#eqeq__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6364:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check keywb"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6364) ? (6364) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V9*/ meltfptr[5] = /*_._IFELSE___V11*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6364:/ clear");
	     /*clear *//*_.DISCRIM__V10*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_#eqeq__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V9*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6365:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6365:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[10] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6365:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6365) ? (6365) : __LINE__, __FUNCTION__);
	      ;
	    }
	    ;
	       /*clear *//*_._IFELSE___V13*/ meltfptr[10] = 0;
	    /*epilog */
	  }
	  ;
	}
      ;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[6] = /*_._IFELSE___V13*/ meltfptr[10];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6365:/ clear");
	     /*clear *//*_#IS_A__L4*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V13*/ meltfptr[10] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6366:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NCTX_VALMAP");
  /*_.VALMAP__V15*/ meltfptr[14] = slot;
    };
    ;
 /*_.OSYDATA__V16*/ meltfptr[15] =
      /*mapobject_get */
      melt_get_mapobjects ((meltmapobjects_ptr_t)
			   ( /*_.VALMAP__V15*/ meltfptr[14]),
			   (meltobject_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]));;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6368:/ cond");
    /*cond */ if ( /*_.OSYDATA__V16*/ meltfptr[15])	/*then */
      {
	/*^cond.then */
	/*_._IFELSE___V17*/ meltfptr[16] = /*_.OSYDATA__V16*/ meltfptr[15];;
      }
    else
      {
	MELT_LOCATION ("warmelt-normal.melt:6368:/ cond.else");

	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6369:/ quasiblock");


   /*_#SYHASH__L5*/ meltfnum[1] =
	    (melt_obj_hash ((melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6370:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.KEYW__V2*/ meltfptr[1]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 1, "NAMED_NAME");
    /*_.SYNAMSTR__V19*/ meltfptr[18] = slot;
	  };
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6374:/ apply");
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
	    /*_.NORMAL_PREDEF__V20*/ meltfptr[19] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!DISCR_STRING */ meltfrout->
					 tabval[5])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6373:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[3])), (6), "CLASS_NREP_DATASTRING");
    /*_.INST__V22*/ meltfptr[21] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V22*/ meltfptr[21]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (4),
				( /*_.NORMAL_PREDEF__V20*/ meltfptr[19]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NSTR_STRING",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V22*/ meltfptr[21]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V22*/ meltfptr[21]), (5),
				( /*_.SYNAMSTR__V19*/ meltfptr[18]),
				"NSTR_STRING");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V22*/ meltfptr[21],
					"newly made instance");
	  ;
	  /*_.SYNAMSTRDATA__V21*/ meltfptr[20] =
	    /*_.INST__V22*/ meltfptr[21];;
	  MELT_LOCATION ("warmelt-normal.melt:6378:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj =
	      (melt_ptr_t) (( /*!CLASS_KEYWORD */ meltfrout->
			     tabval[1])) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
    /*_.CLASS_FIELDS__V23*/ meltfptr[22] = slot;
	  };
	  ;
   /*_#MULTIPLE_LENGTH__L6*/ meltfnum[0] =
	    (melt_multiple_length
	     ((melt_ptr_t) ( /*_.CLASS_FIELDS__V23*/ meltfptr[22])));;
	  /*^compute */
   /*_.SYSLOTS__V24*/ meltfptr[23] =
	    (meltgc_new_multiple
	     ((meltobject_ptr_t)
	      (( /*!DISCR_MULTIPLE */ meltfrout->tabval[6])),
	      ( /*_#MULTIPLE_LENGTH__L6*/ meltfnum[0])));;

	  MELT_CHECK_SIGNAL ();
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6381:/ apply");
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
	    /*_.NORMAL_PREDEF__V25*/ meltfptr[24] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_PREDEF */ meltfrout->tabval[4])),
			  (melt_ptr_t) (( /*!CLASS_KEYWORD */ meltfrout->
					 tabval[1])),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_CSTRING
			   ""), argtab, "", (union meltparam_un *) 0);
	  }
	  ;
   /*_.MAKE_INTEGERBOX__V26*/ meltfptr[25] =
	    (meltgc_new_int
	     ((meltobject_ptr_t)
	      (( /*!DISCR_INTEGER */ meltfrout->tabval[8])),
	      ( /*_#SYHASH__L5*/ meltfnum[1])));;
	  MELT_LOCATION ("warmelt-normal.melt:6379:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_DATAKEYWORD */ meltfrout->tabval[7])), (10), "CLASS_NREP_DATAKEYWORD");
    /*_.INST__V28*/ meltfptr[27] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_NAME",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (1),
				( /*_.KEYW__V2*/ meltfptr[1]), "NDATA_NAME");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (4),
				( /*_.NORMAL_PREDEF__V25*/ meltfptr[24]),
				"NDATA_DISCRX");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NINST_HASH",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (7),
				( /*_.MAKE_INTEGERBOX__V26*/ meltfptr[25]),
				"NINST_HASH");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NINST_SLOTS",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (8),
				( /*_.SYSLOTS__V24*/ meltfptr[23]),
				"NINST_SLOTS");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NDSY_NAMESTR",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V28*/ meltfptr[27]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V28*/ meltfptr[27]), (9),
				( /*_.SYNAMSTR__V19*/ meltfptr[18]),
				"NDSY_NAMESTR");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V28*/ meltfptr[27],
					"newly made instance");
	  ;
	  /*_.SYDATA__V27*/ meltfptr[26] = /*_.INST__V28*/ meltfptr[27];;
	  /*^compute */
   /*_#OBJ_NUM__L7*/ meltfnum[6] =
	    (melt_obj_num
	     ((melt_ptr_t) (( /*!NAMED_NAME */ meltfrout->tabval[9]))));;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6386:/ locexp");
	    meltgc_multiple_put_nth ((melt_ptr_t)
				     ( /*_.SYSLOTS__V24*/ meltfptr[23]),
				     ( /*_#OBJ_NUM__L7*/ meltfnum[6]),
				     (melt_ptr_t) ( /*_.SYNAMSTRDATA__V21*/
						   meltfptr[20]));
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6387:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYDATA__V27*/ meltfptr[26];
	    /*_.ADD_NCTX_DATA__V29*/ meltfptr[28] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6388:/ apply");
	  /*apply */
	  {
	    union meltparam_un argtab[1];
	    memset (&argtab, 0, sizeof (argtab));
	    /*^apply.arg */
	    argtab[0].meltbp_aptr =
	      (melt_ptr_t *) & /*_.SYNAMSTRDATA__V21*/ meltfptr[20];
	    /*_.ADD_NCTX_DATA__V30*/ meltfptr[29] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!ADD_NCTX_DATA */ meltfrout->tabval[10])),
			  (melt_ptr_t) ( /*_.NCX__V3*/ meltfptr[2]),
			  (MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6389:/ locexp");
	    meltgc_put_mapobjects ((meltmapobjects_ptr_t)
				   ( /*_.VALMAP__V15*/ meltfptr[14]),
				   (meltobject_ptr_t) ( /*_.KEYW__V2*/
						       meltfptr[1]),
				   (melt_ptr_t) ( /*_.SYDATA__V27*/
						 meltfptr[26]));
	  }
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6390:/ getslot");
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
						    ( /*_.SYNAMSTR__V19*/
						     meltfptr[18])),
				   (melt_ptr_t) ( /*_.SYDATA__V27*/
						 meltfptr[26]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6391:/ cppif.then");
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
	      0			/* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG */
	      ;;
	    MELT_LOCATION ("warmelt-normal.melt:6391:/ cond");
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
		    0L		/* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
		    ;;

		  MELT_CHECK_SIGNAL ();
		  ;
		  MELT_LOCATION ("warmelt-normal.melt:6391:/ apply");
		  /*apply */
		  {
		    union meltparam_un argtab[5];
		    memset (&argtab, 0, sizeof (argtab));
		    /*^apply.arg */
		    argtab[0].meltbp_long =
		      /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
		    /*^apply.arg */
		    argtab[1].meltbp_cstring = "warmelt-normal.melt";
		    /*^apply.arg */
		    argtab[2].meltbp_long = 6391;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normal_keyword_data return sydata=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.SYDATA__V27*/ meltfptr[26];
		    /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] =
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
		  /*_._IF___V33*/ meltfptr[32] =
		    /*_.MELT_DEBUG_FUN__V34*/ meltfptr[33];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6391:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L9*/ meltfnum[8] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V34*/ meltfptr[33] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V33*/ meltfptr[32] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6391:/ quasiblock");


	    /*_.PROGN___V35*/ meltfptr[33] = /*_._IF___V33*/ meltfptr[32];;
	    /*^compute */
	    /*_.IFCPP___V32*/ meltfptr[31] = /*_.PROGN___V35*/ meltfptr[33];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6391:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L8*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V33*/ meltfptr[32] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V35*/ meltfptr[33] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V32*/ meltfptr[31] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6392:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.SYDATA__V27*/ meltfptr[26];;

	  {
	    MELT_LOCATION ("warmelt-normal.melt:6392:/ locexp");
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
	  /*_.LET___V18*/ meltfptr[17] = /*_.RETURN___V36*/ meltfptr[32];;

	  MELT_LOCATION ("warmelt-normal.melt:6369:/ clear");
	     /*clear *//*_#SYHASH__L5*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTR__V19*/ meltfptr[18] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V20*/ meltfptr[19] = 0;
	  /*^clear */
	     /*clear *//*_.SYNAMSTRDATA__V21*/ meltfptr[20] = 0;
	  /*^clear */
	     /*clear *//*_.CLASS_FIELDS__V23*/ meltfptr[22] = 0;
	  /*^clear */
	     /*clear *//*_#MULTIPLE_LENGTH__L6*/ meltfnum[0] = 0;
	  /*^clear */
	     /*clear *//*_.SYSLOTS__V24*/ meltfptr[23] = 0;
	  /*^clear */
	     /*clear *//*_.NORMAL_PREDEF__V25*/ meltfptr[24] = 0;
	  /*^clear */
	     /*clear *//*_.MAKE_INTEGERBOX__V26*/ meltfptr[25] = 0;
	  /*^clear */
	     /*clear *//*_.SYDATA__V27*/ meltfptr[26] = 0;
	  /*^clear */
	     /*clear *//*_#OBJ_NUM__L7*/ meltfnum[6] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V29*/ meltfptr[28] = 0;
	  /*^clear */
	     /*clear *//*_.ADD_NCTX_DATA__V30*/ meltfptr[29] = 0;
	  /*^clear */
	     /*clear *//*_.NCTX_KEYWMAP__V31*/ meltfptr[30] = 0;
	  /*^clear */
	     /*clear *//*_.IFCPP___V32*/ meltfptr[31] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V36*/ meltfptr[32] = 0;
	  /*_._IFELSE___V17*/ meltfptr[16] = /*_.LET___V18*/ meltfptr[17];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6368:/ clear");
	     /*clear *//*_.LET___V18*/ meltfptr[17] = 0;
	}
	;
      }
    ;
    /*_.LET___V14*/ meltfptr[10] = /*_._IFELSE___V17*/ meltfptr[16];;

    MELT_LOCATION ("warmelt-normal.melt:6366:/ clear");
	   /*clear *//*_.VALMAP__V15*/ meltfptr[14] = 0;
    /*^clear */
	   /*clear *//*_.OSYDATA__V16*/ meltfptr[15] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V17*/ meltfptr[16] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6361:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V14*/ meltfptr[10];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6361:/ locexp");
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
	   /*clear *//*_.IFCPP___V5*/ meltfptr[4] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V9*/ meltfptr[5] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.LET___V14*/ meltfptr[10] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMAL_KEYWORD_DATA", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_117_WARMELTmiNORMAL_NORMAL_KEYWORD_DATA */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS_melt
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

  struct meltframe_meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS_st
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
#define MELTFRAM_NBVARPTR 15
    melt_ptr_t mcfr_varptr[15];
#define MELTFRAM_NBVARNUM 6
    long mcfr_varnum[6];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS_st *)
	meltfirstargp_;
      /* use arguments meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 15; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS nbval 15*/
  meltfram__.mcfr_nbvar = 15 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("CREATE_DATA_SLOTS", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6397:/ getarg");
 /*_.CLA__V2*/ meltfptr[1] = (melt_ptr_t) meltfirstargp_;
  ;
  goto meltlab_endgetargs;
meltlab_endgetargs:;
/*body*/
/*^block*/
/*anyblock*/
  {


#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6398:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.CLA__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_CLASS */ meltfrout->
					    tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6398:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V4*/ meltfptr[3] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6398:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check cla"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6398) ? (6398) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6398:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6399:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6399:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6399:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L3*/ meltfnum[2];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6399;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "create_data_slots cla";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.CLA__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[1])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6399:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L3*/ meltfnum[2] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:6399:/ quasiblock");


      /*_.PROGN___V8*/ meltfptr[6] = /*_._IF___V6*/ meltfptr[5];;
      /*^compute */
      /*_.IFCPP___V5*/ meltfptr[3] = /*_.PROGN___V8*/ meltfptr[6];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6399:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V6*/ meltfptr[5] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V8*/ meltfptr[6] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V5*/ meltfptr[3] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6400:/ quasiblock");


    MELT_LOCATION ("warmelt-normal.melt:6401:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.CLA__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 6, "CLASS_FIELDS");
  /*_.CLASS_FIELDS__V10*/ meltfptr[6] = slot;
    };
    ;
 /*_#MULTIPLE_LENGTH__L4*/ meltfnum[2] =
      (melt_multiple_length
       ((melt_ptr_t) ( /*_.CLASS_FIELDS__V10*/ meltfptr[6])));;
    /*^compute */
 /*_.TUPSLO__V11*/ meltfptr[10] =
      (meltgc_new_multiple
       ((meltobject_ptr_t) (( /*!DISCR_MULTIPLE */ meltfrout->tabval[2])),
	( /*_#MULTIPLE_LENGTH__L4*/ meltfnum[2])));;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6403:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6403:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6403:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[5];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6403;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "create_data_slots tupslo";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.TUPSLO__V11*/ meltfptr[10];
	      /*_.MELT_DEBUG_FUN__V14*/ meltfptr[13] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[1])),
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

	    MELT_LOCATION ("warmelt-normal.melt:6403:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L6*/ meltfnum[5] = 0;
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
      MELT_LOCATION ("warmelt-normal.melt:6403:/ quasiblock");


      /*_.PROGN___V15*/ meltfptr[13] = /*_._IF___V13*/ meltfptr[12];;
      /*^compute */
      /*_.IFCPP___V12*/ meltfptr[11] = /*_.PROGN___V15*/ meltfptr[13];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6403:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L5*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V13*/ meltfptr[12] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V15*/ meltfptr[13] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V12*/ meltfptr[11] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    /*^compute */
    /*_.LET___V9*/ meltfptr[5] = /*_.TUPSLO__V11*/ meltfptr[10];;

    MELT_LOCATION ("warmelt-normal.melt:6400:/ clear");
	   /*clear *//*_.CLASS_FIELDS__V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_#MULTIPLE_LENGTH__L4*/ meltfnum[2] = 0;
    /*^clear */
	   /*clear *//*_.TUPSLO__V11*/ meltfptr[10] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[11] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6397:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V9*/ meltfptr[5];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6397:/ locexp");
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
	   /*clear *//*_.IFCPP___V5*/ meltfptr[3] = 0;
    /*^clear */
	   /*clear *//*_.LET___V9*/ meltfptr[5] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("CREATE_DATA_SLOTS", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_118_WARMELTmiNORMAL_CREATE_DATA_SLOTS */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT (meltclosure_ptr_t meltclosp_,
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
    current_blocklevel_signals_meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT_melt
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

  struct meltframe_meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT_st
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
  /*meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT_st *)
	meltfirstargp_;
      /* use arguments meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT output_curframe_declstruct_init */
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
/* declstructinit plain routine meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT nbval 9*/
  meltfram__.mcfr_nbvar = 9 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("FILL_DATA_SLOT", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6408:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6409:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L1*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.DI__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_NREP_DATAINSTANCE */
					    meltfrout->tabval[0])));;
      MELT_LOCATION ("warmelt-normal.melt:6409:/ cond");
      /*cond */ if ( /*_#IS_A__L1*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V6*/ meltfptr[5] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6409:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check di"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6409) ? (6409) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6409:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6410:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L2*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.FIELD__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_FIELD */ meltfrout->
					    tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6410:/ cond");
      /*cond */ if ( /*_#IS_A__L2*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V8*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6410:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check field"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6410) ? (6410) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6410:/ clear");
	     /*clear *//*_#IS_A__L2*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V8*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V7*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;
    MELT_LOCATION ("warmelt-normal.melt:6411:/ quasiblock");


 /*_#FIX__L3*/ meltfnum[0] =
      (melt_obj_num ((melt_ptr_t) ( /*_.FIELD__V3*/ meltfptr[2])));;
    MELT_LOCATION ("warmelt-normal.melt:6412:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.DI__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 8, "NINST_SLOTS");
  /*_.SLOTS__V9*/ meltfptr[7] = slot;
    };
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:6413:/ locexp");
      meltgc_multiple_put_nth ((melt_ptr_t) ( /*_.SLOTS__V9*/ meltfptr[7]),
			       ( /*_#FIX__L3*/ meltfnum[0]),
			       (melt_ptr_t) ( /*_.VAL__V4*/ meltfptr[3]));
    }
    ;

    MELT_LOCATION ("warmelt-normal.melt:6411:/ clear");
	   /*clear *//*_#FIX__L3*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.SLOTS__V9*/ meltfptr[7] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    /*epilog */

    MELT_LOCATION ("warmelt-normal.melt:6408:/ clear");
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
    current_blocklevel_signals_meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*noretval */ NULL);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_119_WARMELTmiNORMAL_FILL_DATA_SLOT */





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE (meltclosure_ptr_t meltclosp_,
					    melt_ptr_t meltfirstargp_,
					    const melt_argdescr_cell_t
					    meltxargdescr_[],
					    union meltparam_un * meltxargtab_,
					    const melt_argdescr_cell_t
					    meltxresdescr_[],
					    union meltparam_un * meltxrestab_)
{
  long
    current_blocklevel_signals_meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE_melt
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

  struct meltframe_meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE_st
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
#define MELTFRAM_NBVARPTR 57
    melt_ptr_t mcfr_varptr[57];
#define MELTFRAM_NBVARNUM 15
    long mcfr_varnum[15];
/*others*/
    long _spare_;
  }
   *meltframptr_ = 0, meltfram__;	/*declfrastruct */
#define meltframe meltfram__
  /*meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE is not initial declstructinit */
  if (MELT_UNLIKELY (meltxargdescr_ == MELTPAR_MARKGGC))
    {				/*mark for ggc */
      int meltix;
      meltframptr_ =
	(struct meltframe_meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE_st *)
	meltfirstargp_;
      /* use arguments meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE output_curframe_declstruct_init */
      (void) meltclosp_;
      (void) meltfirstargp_;
      (void) meltxargdescr_;
      (void) meltxargtab_;
      (void) meltxresdescr_;
      (void) meltxrestab_;
      /* marking closure */
      gt_ggc_mx_melt_un (meltframptr_->mcfr_clos);
      for (meltix = 0; meltix < 57; meltix++)
	if (meltframptr_->mcfr_varptr[meltix])
	  gt_ggc_mx_melt_un (meltframptr_->mcfr_varptr[meltix]);
      return NULL;
    } /*end markggc */ ;
  memset (&meltfram__, 0, sizeof (meltfram__));
/* declstructinit plain routine meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE nbval 57*/
  meltfram__.mcfr_nbvar = 57 /*nbval */ ;
  meltfram__.mcfr_clos = meltclosp_;
  meltfram__.mcfr_prev = (struct melt_callframe_st *) melt_topframe;
  melt_topframe = (struct melt_callframe_st *) &meltfram__;
  melt_trace_start ("NORMEXP_QUOTE", meltcallcount);
/*getargs*/

  /*getarg#0 */
  MELT_LOCATION ("warmelt-normal.melt:6419:/ getarg");
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
    MELT_LOCATION ("warmelt-normal.melt:6420:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6420:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6420:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[5];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6420;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_quote recv=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.RECV__V2*/ meltfptr[1];
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] =
		melt_apply ((meltclosure_ptr_t)
			    (( /*!MELT_DEBUG_FUN */ meltfrout->tabval[0])),
			    (melt_ptr_t) (( /*nil */ NULL)),
			    (MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_LONG MELTBPARSTR_CSTRING
			     MELTBPARSTR_PTR ""), argtab, "",
			    (union meltparam_un *) 0);
	    }
	    ;
	    /*_._IF___V7*/ meltfptr[6] =
	      /*_.MELT_DEBUG_FUN__V8*/ meltfptr[7];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6420:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L2*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V8*/ meltfptr[7] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V7*/ meltfptr[6] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6420:/ quasiblock");


      /*_.PROGN___V9*/ meltfptr[7] = /*_._IF___V7*/ meltfptr[6];;
      /*^compute */
      /*_.IFCPP___V6*/ meltfptr[5] = /*_.PROGN___V9*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6420:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L1*/ meltfnum[0] = 0;
      /*^clear */
	     /*clear *//*_._IF___V7*/ meltfptr[6] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V9*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V6*/ meltfptr[5] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6421:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L3*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]),
			     (melt_ptr_t) (( /*!CLASS_SOURCE_QUOTE */
					    meltfrout->tabval[1])));;
      MELT_LOCATION ("warmelt-normal.melt:6421:/ cond");
      /*cond */ if ( /*_#IS_A__L3*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V11*/ meltfptr[7] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6421:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check quote recv"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6421) ? (6421) : __LINE__, __FUNCTION__);
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
      /*_.IFCPP___V10*/ meltfptr[6] = /*_._IFELSE___V11*/ meltfptr[7];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6421:/ clear");
	     /*clear *//*_#IS_A__L3*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V11*/ meltfptr[7] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V10*/ meltfptr[6] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6422:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L4*/ meltfnum[0] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.ENV__V3*/ meltfptr[2]),
			     (melt_ptr_t) (( /*!CLASS_ENVIRONMENT */
					    meltfrout->tabval[2])));;
      MELT_LOCATION ("warmelt-normal.melt:6422:/ cond");
      /*cond */ if ( /*_#IS_A__L4*/ meltfnum[0])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V13*/ meltfptr[12] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6422:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check env"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6422) ? (6422) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6422:/ clear");
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
    MELT_LOCATION ("warmelt-normal.melt:6423:/ cppif.then");
    /*^block */
    /*anyblock */
    {


      MELT_CHECK_SIGNAL ();
      ;
   /*_#IS_A__L5*/ meltfnum[1] =
	melt_is_instance_of ((melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
			     (melt_ptr_t) (( /*!CLASS_NORMALIZATION_CONTEXT */
					    meltfrout->tabval[3])));;
      MELT_LOCATION ("warmelt-normal.melt:6423:/ cond");
      /*cond */ if ( /*_#IS_A__L5*/ meltfnum[1])	/*then */
	{
	  /*^cond.then */
	  /*_._IFELSE___V15*/ meltfptr[14] = ( /*nil */ NULL);;
	}
      else
	{
	  MELT_LOCATION ("warmelt-normal.melt:6423:/ cond.else");

	  /*^block */
	  /*anyblock */
	  {




	    {
	      /*^locexp */
	      melt_assert_failed (("check nctxt"),
				  ("warmelt-normal.melt")
				  ? ("warmelt-normal.melt") : __FILE__,
				  (6423) ? (6423) : __LINE__, __FUNCTION__);
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

      MELT_LOCATION ("warmelt-normal.melt:6423:/ clear");
	     /*clear *//*_#IS_A__L5*/ meltfnum[1] = 0;
      /*^clear */
	     /*clear *//*_._IFELSE___V15*/ meltfptr[14] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V14*/ meltfptr[12] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    {
      MELT_LOCATION ("warmelt-normal.melt:6424:/ locexp");

#if MELT_HAVE_DEBUG
      if (melt_need_debug (0))
	melt_dbgshortbacktrace (("normexp_quote"), (10));
#endif
      ;
    }
    ;
    MELT_LOCATION ("warmelt-normal.melt:6425:/ quasiblock");


    /*^getslot */
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 1, "LOCA_LOCATION");
  /*_.SLOC__V17*/ meltfptr[16] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6426:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.RECV__V2*/ meltfptr[1]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 2, "SQUOTED");
  /*_.QUOTED__V18*/ meltfptr[17] = slot;
    };
    ;
    MELT_LOCATION ("warmelt-normal.melt:6427:/ getslot");
    {
      melt_ptr_t slot = NULL, obj = NULL;
      obj = (melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]) /*=obj*/ ;
      melt_object_get_field (slot, obj, 10, "NCTX_CURPROC");
  /*_.CURPROC__V19*/ meltfptr[18] = slot;
    };
    ;

    MELT_CHECK_SIGNAL ();
    ;
 /*_.DISCRIM__V20*/ meltfptr[19] =
      ((melt_ptr_t)
       (melt_discr ((melt_ptr_t) ( /*_.QUOTED__V18*/ meltfptr[17]))));;
    /*^compute */
 /*_#eqeq__L6*/ meltfnum[0] =
      (( /*_.DISCRIM__V20*/ meltfptr[19]) ==
       (( /*!CLASS_SYMBOL */ meltfrout->tabval[4])));;
    MELT_LOCATION ("warmelt-normal.melt:6430:/ cond");
    /*cond */ if ( /*_#eqeq__L6*/ meltfnum[0])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{


	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6431:/ apply");
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
	    /*_.NORMAL_SYMBOL_DATA__V22*/ meltfptr[21] =
	      melt_apply ((meltclosure_ptr_t)
			  (( /*!NORMAL_SYMBOL_DATA */ meltfrout->tabval[5])),
			  (melt_ptr_t) ( /*_.QUOTED__V18*/ meltfptr[17]),
			  (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "",
			  (union meltparam_un *) 0);
	  }
	  ;
	  /*_.NDATA__V21*/ meltfptr[20] =
	    /*_.NORMAL_SYMBOL_DATA__V22*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6430:/ clear");
	     /*clear *//*_.NORMAL_SYMBOL_DATA__V22*/ meltfptr[21] = 0;
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
	    (melt_magic_discr ((melt_ptr_t) ( /*_.QUOTED__V18*/ meltfptr[17]))
	     == MELTOBMAG_INT);;
	  MELT_LOCATION ("warmelt-normal.melt:6432:/ cond");
	  /*cond */ if ( /*_#IS_INTEGERBOX__L7*/ meltfnum[1])	/*then */
	    {
	      /*^cond.then */
	      /*^block */
	      /*anyblock */
	      {

		MELT_LOCATION ("warmelt-normal.melt:6433:/ quasiblock");



		MELT_CHECK_SIGNAL ();
		;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6435:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[3];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
		  /*^apply.arg */
		  argtab[1].meltbp_aptr =
		    (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[16];
		  /*^apply.arg */
		  argtab[2].meltbp_cstring = "discr_constant_integer";
		  /*_.NORMAL_PREDEF__V25*/ meltfptr[24] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!NORMAL_PREDEF */ meltfrout->tabval[7])),
				(melt_ptr_t) (( /*!DISCR_CONSTANT_INTEGER */
					       meltfrout->tabval[8])),
				(MELTBPARSTR_PTR MELTBPARSTR_PTR
				 MELTBPARSTR_CSTRING ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		MELT_LOCATION ("warmelt-normal.melt:6434:/ quasiblock");


		/*^rawallocobj */
		/*rawallocobj */
		{
		  melt_ptr_t newobj = 0;
		  melt_raw_object_create (newobj,
					  (melt_ptr_t) (( /*!CLASS_NREP_DATABOXEDINTEGER */ meltfrout->tabval[6])), (6), "CLASS_NREP_DATABOXEDINTEGER");
      /*_.INST__V27*/ meltfptr[26] =
		    newobj;
		};
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V27*/
						   meltfptr[26])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V27*/ meltfptr[26]), (4),
				      ( /*_.NORMAL_PREDEF__V25*/
				       meltfptr[24]), "NDATA_DISCRX");
		;
		/*^putslot */
		/*putslot */
		melt_assertmsg ("putslot checkobj @NBOXINT_NUM",
				melt_magic_discr ((melt_ptr_t)
						  ( /*_.INST__V27*/
						   meltfptr[26])) ==
				MELTOBMAG_OBJECT);
		melt_putfield_object (( /*_.INST__V27*/ meltfptr[26]), (5),
				      ( /*_.QUOTED__V18*/ meltfptr[17]),
				      "NBOXINT_NUM");
		;
		/*^touchobj */

		melt_dbgtrace_written_object ( /*_.INST__V27*/ meltfptr[26],
					      "newly made instance");
		;
		/*_.NINTDATA__V26*/ meltfptr[25] =
		  /*_.INST__V27*/ meltfptr[26];;

		MELT_CHECK_SIGNAL ();
		;
		MELT_LOCATION ("warmelt-normal.melt:6438:/ apply");
		/*apply */
		{
		  union meltparam_un argtab[1];
		  memset (&argtab, 0, sizeof (argtab));
		  /*^apply.arg */
		  argtab[0].meltbp_aptr =
		    (melt_ptr_t *) & /*_.NINTDATA__V26*/ meltfptr[25];
		  /*_.ADD_NCTX_DATA__V28*/ meltfptr[27] =
		    melt_apply ((meltclosure_ptr_t)
				(( /*!ADD_NCTX_DATA */ meltfrout->tabval[9])),
				(melt_ptr_t) ( /*_.NCX__V4*/ meltfptr[3]),
				(MELTBPARSTR_PTR ""), argtab, "",
				(union meltparam_un *) 0);
		}
		;
		/*_.LET___V24*/ meltfptr[23] =
		  /*_.NINTDATA__V26*/ meltfptr[25];;

		MELT_LOCATION ("warmelt-normal.melt:6433:/ clear");
	       /*clear *//*_.NORMAL_PREDEF__V25*/ meltfptr[24] = 0;
		/*^clear */
	       /*clear *//*_.NINTDATA__V26*/ meltfptr[25] = 0;
		/*^clear */
	       /*clear *//*_.ADD_NCTX_DATA__V28*/ meltfptr[27] = 0;
		/*_._IFELSE___V23*/ meltfptr[21] =
		  /*_.LET___V24*/ meltfptr[23];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6432:/ clear");
	       /*clear *//*_.LET___V24*/ meltfptr[23] = 0;
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
		   ((melt_ptr_t) ( /*_.QUOTED__V18*/ meltfptr[17])) ==
		   MELTOBMAG_STRING);;
		MELT_LOCATION ("warmelt-normal.melt:6441:/ cond");
		/*cond */ if ( /*_#IS_STRING__L8*/ meltfnum[7])	/*then */
		  {
		    /*^cond.then */
		    /*^block */
		    /*anyblock */
		    {

		      MELT_LOCATION ("warmelt-normal.melt:6442:/ quasiblock");



		      MELT_CHECK_SIGNAL ();
		      ;

		      MELT_CHECK_SIGNAL ();
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6444:/ apply");
		      /*apply */
		      {
			union meltparam_un argtab[3];
			memset (&argtab, 0, sizeof (argtab));
			/*^apply.arg */
			argtab[0].meltbp_aptr =
			  (melt_ptr_t *) & /*_.NCX__V4*/ meltfptr[3];
			/*^apply.arg */
			argtab[1].meltbp_aptr =
			  (melt_ptr_t *) & /*_.SLOC__V17*/ meltfptr[16];
			/*^apply.arg */
			argtab[2].meltbp_cstring = "discr_string";
			/*_.NORMAL_PREDEF__V31*/ meltfptr[27] =
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
		      MELT_LOCATION ("warmelt-normal.melt:6443:/ quasiblock");


		      /*^rawallocobj */
		      /*rawallocobj */
		      {
			melt_ptr_t newobj = 0;
			melt_raw_object_create (newobj,
						(melt_ptr_t) (( /*!CLASS_NREP_DATASTRING */ meltfrout->tabval[10])), (6), "CLASS_NREP_DATASTRING");
	/*_.INST__V33*/ meltfptr[32] =
			  newobj;
		      };
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("putslot checkobj @NDATA_DISCRX",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.INST__V33*/
							 meltfptr[32])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]),
					    (4),
					    ( /*_.NORMAL_PREDEF__V31*/
					     meltfptr[27]), "NDATA_DISCRX");
		      ;
		      /*^putslot */
		      /*putslot */
		      melt_assertmsg ("putslot checkobj @NSTR_STRING",
				      melt_magic_discr ((melt_ptr_t)
							( /*_.INST__V33*/
							 meltfptr[32])) ==
				      MELTOBMAG_OBJECT);
		      melt_putfield_object (( /*_.INST__V33*/ meltfptr[32]),
					    (5),
					    ( /*_.QUOTED__V18*/ meltfptr[17]),
					    "NSTR_STRING");
		      ;
		      /*^touchobj */

		      melt_dbgtrace_written_object ( /*_.INST__V33*/
						    meltfptr[32],
						    "newly made instance");
		      ;
		      /*_.NSTRDATA__V32*/ meltfptr[23] =
			/*_.INST__V33*/ meltfptr[32];;

		      MELT_CHECK_SIGNAL ();
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6447:/ apply");
		      /*apply */
		      {
			union meltparam_un argtab[1];
			memset (&argtab, 0, sizeof (argtab));
			/*^apply.arg */
			argtab[0].meltbp_aptr =
			  (melt_ptr_t *) & /*_.NSTRDATA__V32*/ meltfptr[23];
			/*_.ADD_NCTX_DATA__V34*/ meltfptr[33] =
			  melt_apply ((meltclosure_ptr_t)
				      (( /*!ADD_NCTX_DATA */ meltfrout->
					tabval[9])),
				      (melt_ptr_t) ( /*_.NCX__V4*/
						    meltfptr[3]),
				      (MELTBPARSTR_PTR ""), argtab, "",
				      (union meltparam_un *) 0);
		      }
		      ;
		      /*_.LET___V30*/ meltfptr[25] =
			/*_.NSTRDATA__V32*/ meltfptr[23];;

		      MELT_LOCATION ("warmelt-normal.melt:6442:/ clear");
		 /*clear *//*_.NORMAL_PREDEF__V31*/ meltfptr[27] = 0;
		      /*^clear */
		 /*clear *//*_.NSTRDATA__V32*/ meltfptr[23] = 0;
		      /*^clear */
		 /*clear *//*_.ADD_NCTX_DATA__V34*/ meltfptr[33] = 0;
		      /*_._IFELSE___V29*/ meltfptr[24] =
			/*_.LET___V30*/ meltfptr[25];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6441:/ clear");
		 /*clear *//*_.LET___V30*/ meltfptr[25] = 0;
		    }
		    ;
		  }
		else
		  {		/*^cond.else */

		    /*^block */
		    /*anyblock */
		    {


#if MELT_HAVE_DEBUG
		      MELT_LOCATION ("warmelt-normal.melt:6452:/ cppif.then");
		      /*^block */
		      /*anyblock */
		      {


			MELT_CHECK_SIGNAL ();
			;
			/*^cond */
			/*cond */ if (( /*nil */ NULL))	/*then */
			  {
			    /*^cond.then */
			    /*_._IFELSE___V36*/ meltfptr[23] =
			      ( /*nil */ NULL);;
			  }
			else
			  {
			    MELT_LOCATION
			      ("warmelt-normal.melt:6452:/ cond.else");

			    /*^block */
			    /*anyblock */
			    {




			      {
				/*^locexp */
				melt_assert_failed (("unexpected quoted stuff"), ("warmelt-normal.melt") ? ("warmelt-normal.melt") : __FILE__, (6452) ? (6452) : __LINE__, __FUNCTION__);
				;
			      }
			      ;
		     /*clear *//*_._IFELSE___V36*/ meltfptr[23] = 0;
			      /*epilog */
			    }
			    ;
			  }
			;
			/*^compute */
			/*_.IFCPP___V35*/ meltfptr[27] =
			  /*_._IFELSE___V36*/ meltfptr[23];;
			/*epilog */

			MELT_LOCATION ("warmelt-normal.melt:6452:/ clear");
		   /*clear *//*_._IFELSE___V36*/ meltfptr[23] = 0;
		      }

#else /*MELT_HAVE_DEBUG */
		      /*^cppif.else */
		      /*_.IFCPP___V35*/ meltfptr[27] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
		      ;
		      MELT_LOCATION ("warmelt-normal.melt:6449:/ quasiblock");


		      /*_.PROGN___V37*/ meltfptr[33] =
			/*_.IFCPP___V35*/ meltfptr[27];;
		      /*^compute */
		      /*_._IFELSE___V29*/ meltfptr[24] =
			/*_.PROGN___V37*/ meltfptr[33];;
		      /*epilog */

		      MELT_LOCATION ("warmelt-normal.melt:6441:/ clear");
		 /*clear *//*_.IFCPP___V35*/ meltfptr[27] = 0;
		      /*^clear */
		 /*clear *//*_.PROGN___V37*/ meltfptr[33] = 0;
		    }
		    ;
		  }
		;
		/*_._IFELSE___V23*/ meltfptr[21] =
		  /*_._IFELSE___V29*/ meltfptr[24];;
		/*epilog */

		MELT_LOCATION ("warmelt-normal.melt:6432:/ clear");
	       /*clear *//*_#IS_STRING__L8*/ meltfnum[7] = 0;
		/*^clear */
	       /*clear *//*_._IFELSE___V29*/ meltfptr[24] = 0;
	      }
	      ;
	    }
	  ;
	  /*_.NDATA__V21*/ meltfptr[20] = /*_._IFELSE___V23*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6430:/ clear");
	     /*clear *//*_#IS_INTEGERBOX__L7*/ meltfnum[1] = 0;
	  /*^clear */
	     /*clear *//*_._IFELSE___V23*/ meltfptr[21] = 0;
	}
	;
      }
    ;

#if MELT_HAVE_DEBUG
    MELT_LOCATION ("warmelt-normal.melt:6456:/ cppif.then");
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
      MELT_LOCATION ("warmelt-normal.melt:6456:/ cond");
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
	    MELT_LOCATION ("warmelt-normal.melt:6456:/ apply");
	    /*apply */
	    {
	      union meltparam_un argtab[7];
	      memset (&argtab, 0, sizeof (argtab));
	      /*^apply.arg */
	      argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[1];
	      /*^apply.arg */
	      argtab[1].meltbp_cstring = "warmelt-normal.melt";
	      /*^apply.arg */
	      argtab[2].meltbp_long = 6456;
	      /*^apply.arg */
	      argtab[3].meltbp_cstring = "normexp_quote ndata=";
	      /*^apply.arg */
	      argtab[4].meltbp_aptr =
		(melt_ptr_t *) & /*_.NDATA__V21*/ meltfptr[20];
	      /*^apply.arg */
	      argtab[5].meltbp_cstring = "\n.. curproc=";
	      /*^apply.arg */
	      argtab[6].meltbp_aptr =
		(melt_ptr_t *) & /*_.CURPROC__V19*/ meltfptr[18];
	      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[27] =
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
	    /*_._IF___V39*/ meltfptr[23] =
	      /*_.MELT_DEBUG_FUN__V40*/ meltfptr[27];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6456:/ clear");
	       /*clear *//*_#MELT_CALLCOUNT__L10*/ meltfnum[1] = 0;
	    /*^clear */
	       /*clear *//*_.MELT_DEBUG_FUN__V40*/ meltfptr[27] = 0;
	  }
	  ;
	}
      else
	{			/*^cond.else */

    /*_._IF___V39*/ meltfptr[23] = NULL;;
	}
      ;
      MELT_LOCATION ("warmelt-normal.melt:6456:/ quasiblock");


      /*_.PROGN___V41*/ meltfptr[33] = /*_._IF___V39*/ meltfptr[23];;
      /*^compute */
      /*_.IFCPP___V38*/ meltfptr[25] = /*_.PROGN___V41*/ meltfptr[33];;
      /*epilog */

      MELT_LOCATION ("warmelt-normal.melt:6456:/ clear");
	     /*clear *//*_#MELT_NEED_DBG__L9*/ meltfnum[7] = 0;
      /*^clear */
	     /*clear *//*_._IF___V39*/ meltfptr[23] = 0;
      /*^clear */
	     /*clear *//*_.PROGN___V41*/ meltfptr[33] = 0;
    }

#else /*MELT_HAVE_DEBUG */
    /*^cppif.else */
    /*_.IFCPP___V38*/ meltfptr[25] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
    ;

    MELT_CHECK_SIGNAL ();
    ;
    /*^compute */
 /*_#IS_A__L11*/ meltfnum[1] =
      melt_is_instance_of ((melt_ptr_t) ( /*_.CURPROC__V19*/ meltfptr[18]),
			   (melt_ptr_t) (( /*!CLASS_NREP_ROUTPROC */
					  meltfrout->tabval[12])));;
    MELT_LOCATION ("warmelt-normal.melt:6457:/ cond");
    /*cond */ if ( /*_#IS_A__L11*/ meltfnum[1])	/*then */
      {
	/*^cond.then */
	/*^block */
	/*anyblock */
	{

	  MELT_LOCATION ("warmelt-normal.melt:6458:/ quasiblock");



	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6459:/ quasiblock");


	  /*^rawallocobj */
	  /*rawallocobj */
	  {
	    melt_ptr_t newobj = 0;
	    melt_raw_object_create (newobj,
				    (melt_ptr_t) (( /*!CLASS_NREP_CONSTANT */
						   meltfrout->tabval[13])),
				    (4), "CLASS_NREP_CONSTANT");
    /*_.INST__V45*/ meltfptr[23] =
	      newobj;
	  };
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NREP_LOC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V45*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V45*/ meltfptr[23]), (0),
				( /*_.SLOC__V17*/ meltfptr[16]), "NREP_LOC");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NCONST_SVAL",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V45*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V45*/ meltfptr[23]), (1),
				( /*_.QUOTED__V18*/ meltfptr[17]),
				"NCONST_SVAL");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NCONST_DATA",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V45*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V45*/ meltfptr[23]), (3),
				( /*_.NDATA__V21*/ meltfptr[20]),
				"NCONST_DATA");
	  ;
	  /*^putslot */
	  /*putslot */
	  melt_assertmsg ("putslot checkobj @NCONST_PROC",
			  melt_magic_discr ((melt_ptr_t)
					    ( /*_.INST__V45*/ meltfptr[23]))
			  == MELTOBMAG_OBJECT);
	  melt_putfield_object (( /*_.INST__V45*/ meltfptr[23]), (2),
				( /*_.CURPROC__V19*/ meltfptr[18]),
				"NCONST_PROC");
	  ;
	  /*^touchobj */

	  melt_dbgtrace_written_object ( /*_.INST__V45*/ meltfptr[23],
					"newly made instance");
	  ;
	  /*_.NCONST__V44*/ meltfptr[27] = /*_.INST__V45*/ meltfptr[23];;
	  MELT_LOCATION ("warmelt-normal.melt:6465:/ getslot");
	  {
	    melt_ptr_t slot = NULL, obj = NULL;
	    obj = (melt_ptr_t) ( /*_.CURPROC__V19*/ meltfptr[18]) /*=obj*/ ;
	    melt_object_get_field (slot, obj, 5, "NRPRO_CONST");
    /*_.NRPRO_CONST__V46*/ meltfptr[33] = slot;
	  };
	  ;

	  {
	    /*^locexp */
	    meltgc_append_list ((melt_ptr_t)
				( /*_.NRPRO_CONST__V46*/ meltfptr[33]),
				(melt_ptr_t) ( /*_.NDATA__V21*/
					      meltfptr[20]));
	  }
	  ;

#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6466:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6466:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6466:/ apply");
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
		    argtab[2].meltbp_long = 6466;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring =
		      "normexp_quote in routine nconst=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NCONST__V44*/ meltfptr[27];
		    /*_.MELT_DEBUG_FUN__V49*/ meltfptr[48] =
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
		  /*_._IF___V48*/ meltfptr[47] =
		    /*_.MELT_DEBUG_FUN__V49*/ meltfptr[48];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6466:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L13*/ meltfnum[12] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V49*/ meltfptr[48] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V48*/ meltfptr[47] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6466:/ quasiblock");


	    /*_.PROGN___V50*/ meltfptr[48] = /*_._IF___V48*/ meltfptr[47];;
	    /*^compute */
	    /*_.IFCPP___V47*/ meltfptr[46] = /*_.PROGN___V50*/ meltfptr[48];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6466:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L12*/ meltfnum[7] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V48*/ meltfptr[47] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V50*/ meltfptr[48] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V47*/ meltfptr[46] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6467:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.NCONST__V44*/ meltfptr[27];;
	  MELT_LOCATION ("warmelt-normal.melt:6467:/ putxtraresult");
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
	  /*_.LET___V43*/ meltfptr[21] = /*_.RETURN___V51*/ meltfptr[47];;

	  MELT_LOCATION ("warmelt-normal.melt:6458:/ clear");
	     /*clear *//*_.NCONST__V44*/ meltfptr[27] = 0;
	  /*^clear */
	     /*clear *//*_.NRPRO_CONST__V46*/ meltfptr[33] = 0;
	  /*^clear */
	     /*clear *//*_.IFCPP___V47*/ meltfptr[46] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V51*/ meltfptr[47] = 0;
	  /*_._IFELSE___V42*/ meltfptr[24] = /*_.LET___V43*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6457:/ clear");
	     /*clear *//*_.LET___V43*/ meltfptr[21] = 0;
	}
	;
      }
    else
      {				/*^cond.else */

	/*^block */
	/*anyblock */
	{


#if MELT_HAVE_DEBUG
	  MELT_LOCATION ("warmelt-normal.melt:6469:/ cppif.then");
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
	    MELT_LOCATION ("warmelt-normal.melt:6469:/ cond");
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
		  MELT_LOCATION ("warmelt-normal.melt:6469:/ apply");
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
		    argtab[2].meltbp_long = 6469;
		    /*^apply.arg */
		    argtab[3].meltbp_cstring = "normexp_quote in init ndata=";
		    /*^apply.arg */
		    argtab[4].meltbp_aptr =
		      (melt_ptr_t *) & /*_.NDATA__V21*/ meltfptr[20];
		    /*_.MELT_DEBUG_FUN__V54*/ meltfptr[33] =
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
		  /*_._IF___V53*/ meltfptr[27] =
		    /*_.MELT_DEBUG_FUN__V54*/ meltfptr[33];;
		  /*epilog */

		  MELT_LOCATION ("warmelt-normal.melt:6469:/ clear");
		 /*clear *//*_#MELT_CALLCOUNT__L15*/ meltfnum[7] = 0;
		  /*^clear */
		 /*clear *//*_.MELT_DEBUG_FUN__V54*/ meltfptr[33] = 0;
		}
		;
	      }
	    else
	      {			/*^cond.else */

      /*_._IF___V53*/ meltfptr[27] = NULL;;
	      }
	    ;
	    MELT_LOCATION ("warmelt-normal.melt:6469:/ quasiblock");


	    /*_.PROGN___V55*/ meltfptr[46] = /*_._IF___V53*/ meltfptr[27];;
	    /*^compute */
	    /*_.IFCPP___V52*/ meltfptr[48] = /*_.PROGN___V55*/ meltfptr[46];;
	    /*epilog */

	    MELT_LOCATION ("warmelt-normal.melt:6469:/ clear");
	       /*clear *//*_#MELT_NEED_DBG__L14*/ meltfnum[12] = 0;
	    /*^clear */
	       /*clear *//*_._IF___V53*/ meltfptr[27] = 0;
	    /*^clear */
	       /*clear *//*_.PROGN___V55*/ meltfptr[46] = 0;
	  }

#else /*MELT_HAVE_DEBUG */
	  /*^cppif.else */
	  /*_.IFCPP___V52*/ meltfptr[48] = ( /*nil */ NULL);
#endif /*MELT_HAVE_DEBUG */
	  ;

	  MELT_CHECK_SIGNAL ();
	  ;
	  MELT_LOCATION ("warmelt-normal.melt:6470:/ quasiblock");


	  /*_._RETVAL___V1*/ meltfptr[0] = /*_.NDATA__V21*/ meltfptr[20];;
	  MELT_LOCATION ("warmelt-normal.melt:6470:/ putxtraresult");
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
	  MELT_LOCATION ("warmelt-normal.melt:6468:/ quasiblock");


	  /*_.PROGN___V57*/ meltfptr[21] = /*_.RETURN___V56*/ meltfptr[47];;
	  /*^compute */
	  /*_._IFELSE___V42*/ meltfptr[24] = /*_.PROGN___V57*/ meltfptr[21];;
	  /*epilog */

	  MELT_LOCATION ("warmelt-normal.melt:6457:/ clear");
	     /*clear *//*_.IFCPP___V52*/ meltfptr[48] = 0;
	  /*^clear */
	     /*clear *//*_.RETURN___V56*/ meltfptr[47] = 0;
	  /*^clear */
	     /*clear *//*_.PROGN___V57*/ meltfptr[21] = 0;
	}
	;
      }
    ;
    /*_.LET___V16*/ meltfptr[14] = /*_._IFELSE___V42*/ meltfptr[24];;

    MELT_LOCATION ("warmelt-normal.melt:6425:/ clear");
	   /*clear *//*_.SLOC__V17*/ meltfptr[16] = 0;
    /*^clear */
	   /*clear *//*_.QUOTED__V18*/ meltfptr[17] = 0;
    /*^clear */
	   /*clear *//*_.CURPROC__V19*/ meltfptr[18] = 0;
    /*^clear */
	   /*clear *//*_.DISCRIM__V20*/ meltfptr[19] = 0;
    /*^clear */
	   /*clear *//*_#eqeq__L6*/ meltfnum[0] = 0;
    /*^clear */
	   /*clear *//*_.NDATA__V21*/ meltfptr[20] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V38*/ meltfptr[25] = 0;
    /*^clear */
	   /*clear *//*_#IS_A__L11*/ meltfnum[1] = 0;
    /*^clear */
	   /*clear *//*_._IFELSE___V42*/ meltfptr[24] = 0;

    MELT_CHECK_SIGNAL ();
    ;
    MELT_LOCATION ("warmelt-normal.melt:6419:/ quasiblock");


    /*_._RETVAL___V1*/ meltfptr[0] = /*_.LET___V16*/ meltfptr[14];;

    {
      MELT_LOCATION ("warmelt-normal.melt:6419:/ locexp");
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
	   /*clear *//*_.IFCPP___V10*/ meltfptr[6] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V12*/ meltfptr[7] = 0;
    /*^clear */
	   /*clear *//*_.IFCPP___V14*/ meltfptr[12] = 0;
    /*^clear */
	   /*clear *//*_.LET___V16*/ meltfptr[14] = 0;
  }

  ;
  goto meltlabend_rout;
meltlabend_rout:
  melt_trace_end ("NORMEXP_QUOTE", meltcallcount);
  MELT_TRACE_EXIT_LOCATION ();
  melt_blocklevel_signals =
    current_blocklevel_signals_meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE_melt;
  melt_topframe = (struct melt_callframe_st *) meltfram__.mcfr_prev;
  return (melt_ptr_t) ( /*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
}				/*end meltrout_120_WARMELTmiNORMAL_NORMEXP_QUOTE */



/**** end of warmelt-normal+04.c ****/
