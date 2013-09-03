/* GCC MELT GENERATED C++ FILE warmelt-macro+05.cc - DO NOT EDIT - see http://gcc-melt.org/ */
/* secondary MELT generated C++ file of rank #5 */
#include "melt-run.h"


/* used hash from melt-run.h when compiling this file: */
MELT_EXTERN const char meltrun_used_md5_melt_f5[] = MELT_RUN_HASHMD5 /* from melt-run.h */;


/**** warmelt-macro+05.cc declarations ****/
/**** MELT GENERATED DECLARATIONS for warmelt-macro ** DO NOT EDIT ; see gcc-melt.org ****/

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


/** ordinary MELT module meltbuild-sources/warmelt-macro**/
#define MELT_HAS_INITIAL_ENVIRONMENT 1 /*usualmodule*/



class Melt_InitialClassyFrame_WARMELTmiMACRO_h584434599; // forward declaration fromline 6543
typedef Melt_InitialClassyFrame_WARMELTmiMACRO_h584434599 Melt_InitialFrame;
/*** 6 MELT module variables declarations ****/
MELT_EXTERN void melt_forwarding_module_data (void);
MELT_EXTERN void melt_marking_module_data (void);

MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY melt_WARMELTmiMACRO_module_var_ptr_tab[16];
MELT_EXTERN bool MELT_MODULE_VISIBILITY melt_WARMELTmiMACRO_module_var_flags[1];

static inline melt_ptr_t
melt_module_var_fetch (int ix)
{
    return (ix > 0  &&  ix <= 6)?melt_WARMELTmiMACRO_module_var_ptr_tab[ix]:NULL;
}

static inline void
melt_module_var_put (int ix, melt_ptr_t val)
{
    if (ix > 0  &&  ix <= 6)
        {
            melt_WARMELTmiMACRO_module_var_ptr_tab[ix]= val;
            melt_WARMELTmiMACRO_module_var_flags[ix/16] = true;
        }
}

/* MELT module variables indexes */
enum
{
    meltmodatix_none,
    meltmodvarix_DIAGV_GIMPLE_symb = 1,
    meltmodvarix_DIAGV_GIMPLE_SEQ_symb = 2,
    meltmodvarix_DIAGV_TREE_symb = 3,
    meltmodvarix_DIAGV_BASIC_BLOCK_symb = 4,
    meltmodvarix_DIAGV_EDGE_symb = 5,
    meltmodvarix_MELT_TRANSRUNMACRO_CLOS_symb = 6,
    meltmodatix_last
}; /* end MELT module variables indexes */

/*** 6 MELT called hook declarations ***/

/*declare MELT called hook #0 HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_FRESH_ENVIRONMENT_REFERENCE_MAKER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_PREVENV, const char* meltinp1_MODULNAME);

/*declare MELT called hook #1 HOOK_MACRO_EXPORTER **/
MELT_EXTERN void melthook_HOOK_MACRO_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_VAL, melt_ptr_t meltinp2_CONTENV);

/*declare MELT called hook #2 HOOK_MELT_MAKE_LOCATION **/
MELT_EXTERN melt_ptr_t melthook_HOOK_MELT_MAKE_LOCATION (melt_ptr_t melthookdatap, const char* meltinp0_FILENAME, long meltinp1_LINENO);

/*declare MELT called hook #3 HOOK_PATMACRO_EXPORTER **/
MELT_EXTERN void melthook_HOOK_PATMACRO_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_MACVAL, melt_ptr_t meltinp2_PATVAL, melt_ptr_t meltinp3_CONTENV);

/*declare MELT called hook #4 HOOK_SYMBOL_IMPORTER **/
MELT_EXTERN melt_ptr_t melthook_HOOK_SYMBOL_IMPORTER (melt_ptr_t melthookdatap, const char* meltinp0_SYMNAMESTR, const char* meltinp1_MODULENAMESTR, melt_ptr_t meltinp2_PARENV);

/*declare MELT called hook #5 HOOK_VALUE_EXPORTER **/
MELT_EXTERN void melthook_HOOK_VALUE_EXPORTER (melt_ptr_t melthookdatap, melt_ptr_t meltinp0_SYM, melt_ptr_t meltinp1_VAL, melt_ptr_t meltinp2_CONTENV);

/*** end of 6 MELT called hook declarations ***/

/*** no extra MELT c-headers ***/




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_1_WARMELTmiMACRO_REGISTER_DIAG_GIMPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_2_WARMELTmiMACRO_REGISTER_DIAG_GIMPLE_SEQ(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_3_WARMELTmiMACRO_REGISTER_DIAG_TREE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_4_WARMELTmiMACRO_REGISTER_DIAG_BASIC_BLOCK(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_5_WARMELTmiMACRO_REGISTER_DIAG_EDGE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_6_WARMELTmiMACRO_DIAGNOSTIC_ARGS_MACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_7_WARMELTmiMACRO_DIAGNOSTIC_EXPAND_MESSAGE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_8_WARMELTmiMACRO_ERROR_AT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_9_WARMELTmiMACRO_WARNING_AT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_10_WARMELTmiMACRO_INFORM_AT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_11_WARMELTmiMACRO_MELT_MAKE_SEXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_12_WARMELTmiMACRO_S_EXPR_WEIGHT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_13_WARMELTmiMACRO_LAMBDA_cl1(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_14_WARMELTmiMACRO_EXPAND_RESTLIST_AS_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_15_WARMELTmiMACRO_EXPAND_RESTLIST_AS_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_16_WARMELTmiMACRO_EXPAND_PAIRLIST_AS_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_17_WARMELTmiMACRO_EXPAND_PAIRLIST_AS_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_18_WARMELTmiMACRO_REGISTER_GENERATOR_DEVICE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_19_WARMELTmiMACRO_EXPAND_APPLY(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_20_WARMELTmiMACRO_EXPAND_MSEND(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_21_WARMELTmiMACRO_EXPAND_FIELDEXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_22_WARMELTmiMACRO_EXPAND_CITERATION(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_23_WARMELTmiMACRO_EXPAND_CMATCHEXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_24_WARMELTmiMACRO_EXPAND_FUNMATCHEXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_25_WARMELTmiMACRO_EXPAND_KEYWORDFUN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_26_WARMELTmiMACRO_MACROEXPAND_1(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_27_WARMELTmiMACRO_LAMBDA_cl2(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_28_WARMELTmiMACRO_EXPAND_PRIMITIVE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_29_WARMELTmiMACRO_EXPAND_HOOK(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_30_WARMELTmiMACRO_PATTERNEXPAND_PAIRLIST_AS_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_31_WARMELTmiMACRO_LAMBDA_cl3(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_32_WARMELTmiMACRO_PATMACEXPAND_FOR_MATCHER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_33_WARMELTmiMACRO_LAMBDA_cl4(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_34_WARMELTmiMACRO_LAMBDA_cl5(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_35_WARMELTmiMACRO_PATTERN_WEIGHT_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_36_WARMELTmiMACRO_LAMBDA_cl6(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_37_WARMELTmiMACRO_PATTERNEXPAND_EXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_38_WARMELTmiMACRO_PATTERNEXPAND_1(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_39_WARMELTmiMACRO_MACROEXPAND_TOPLEVEL_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_40_WARMELTmiMACRO_LAMBDA_ARG_BINDINGS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_41_WARMELTmiMACRO_INSTALL_INITIAL_MACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_42_WARMELTmiMACRO_INSTALL_INITIAL_PATMACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_43_WARMELTmiMACRO_WARN_IF_REDEFINED(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_44_WARMELTmiMACRO_FLATTEN_FOR_C_CODE_EXPANSION(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_45_WARMELTmiMACRO_PARSE_PAIRLIST_C_CODE_EXPANSION(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_46_WARMELTmiMACRO_CHECK_C_EXPANSION(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_47_WARMELTmiMACRO_MELT_REGISTER_TRANSLATOR_RUNNER_MACROEXPANSIONS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_48_WARMELTmiMACRO_MELT_INVOKE_TRANSLATOR_RUNNER_MACROEXPANSIONS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_49_WARMELTmiMACRO_MEXPAND_DEFPRIMITIVE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_50_WARMELTmiMACRO_MEXPAND_DEFCITERATOR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_51_WARMELTmiMACRO_MEXPAND_DEFCMATCHER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_52_WARMELTmiMACRO_LAMBDA_cl7(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_53_WARMELTmiMACRO_MEXPAND_DEFUNMATCHER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_54_WARMELTmiMACRO_LAMBDA_cl8(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_55_WARMELTmiMACRO_MEXPAND_DEFUN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_56_WARMELTmiMACRO_MELT_DELAYED_MACRO_EXPANDER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_57_WARMELTmiMACRO_MEXPAND_DEFMACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_58_WARMELTmiMACRO_LAMBDA_cl9(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);

/** start of declaration for hook melthook_HOOK_MACRO_INSTALLER**/

/** declaration of hook melthook_HOOK_MACRO_INSTALLER */
MELT_EXTERN
void melthook_HOOK_MACRO_INSTALLER(melt_ptr_t melthookdatap,
                                   melt_ptr_t meltinp0_MBIND,
                                   melt_ptr_t meltinp1_MEXPCLOS)
;



/** end of declaration for hook melthook_HOOK_MACRO_INSTALLER**/






MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_60_WARMELTmiMACRO_MEXPAND_DEFVAR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_61_WARMELTmiMACRO_MEXPAND_DEFHOOK(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_62_WARMELTmiMACRO_MEXPAND_DEFINE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_63_WARMELTmiMACRO_LAMBDA_cl10(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_64_WARMELTmiMACRO_SCAN_DEFCLASS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_65_WARMELTmiMACRO_MEXPAND_DEFCLASS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_66_WARMELTmiMACRO_PARSE_FIELD_ASSIGNMENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_67_WARMELTmiMACRO_LAMBDA_cl11(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_68_WARMELTmiMACRO_MEXPAND_DEFINSTANCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_69_WARMELTmiMACRO_MEXPAND_DEFSELECTOR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_70_WARMELTmiMACRO_MEXPAND_INSTANCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_71_WARMELTmiMACRO_MEXPAND_LOAD(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_72_WARMELTmiMACRO_PARSE_FIELD_PATTERN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_73_WARMELTmiMACRO_LAMBDA_cl12(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_74_WARMELTmiMACRO_PATEXPAND_INSTANCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_75_WARMELTmiMACRO_LAMBDA_cl13(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_76_WARMELTmiMACRO_PATEXPAND_OBJECT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_77_WARMELTmiMACRO_LAMBDA_cl14(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_78_WARMELTmiMACRO_MEXPAND_OBJECT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_79_WARMELTmiMACRO_EXPAND_MACROSTRING_PAIRS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_80_WARMELTmiMACRO_LAMBDA_cl15(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_81_WARMELTmiMACRO_MEXPAND_CODE_CHUNK(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_82_WARMELTmiMACRO_MEXPAND_EXPR_CHUNK(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_83_WARMELTmiMACRO_MEXPAND_UNSAFE_PUT_FIELDS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_84_WARMELTmiMACRO_MEXPAND_PUT_FIELDS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_85_WARMELTmiMACRO_MEXPAND_UNSAFE_GET_FIELD(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_86_WARMELTmiMACRO_MEXPAND_GET_FIELD(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_87_WARMELTmiMACRO_PAIRLIST_TO_PROGN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_88_WARMELTmiMACRO_LAMBDA_cl16(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_89_WARMELTmiMACRO_MEXPAND_SETQ(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_90_WARMELTmiMACRO_MEXPAND_IF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_91_WARMELTmiMACRO_MEXPAND_WHEN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_92_WARMELTmiMACRO_MEXPAND_UNLESS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_93_WARMELTmiMACRO_MEXPAND_WITH_CLONED_SYMB(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_94_WARMELTmiMACRO_LAMBDA_cl17(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_95_WARMELTmiMACRO_MEXPAND_CPPIF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_96_WARMELTmiMACRO_FILTERGCCVERSION(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_97_WARMELTmiMACRO_MEXPAND_GCCIF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_98_WARMELTmiMACRO_MEXPAND_COND(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_99_WARMELTmiMACRO_LAMBDA_cl18(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_100_WARMELTmiMACRO_MEXPAND_AND(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_101_WARMELTmiMACRO_LAMBDA_cl19(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_102_WARMELTmiMACRO_PATEXPAND_AS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_103_WARMELTmiMACRO_MEXPAND_AS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_104_WARMELTmiMACRO_PATEXPAND_WHEN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_105_WARMELTmiMACRO_PATEXPAND_AND(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_106_WARMELTmiMACRO_MEXPAND_OR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_107_WARMELTmiMACRO_LAMBDA_cl20(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_108_WARMELTmiMACRO_PATEXPAND_OR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_119_WARMELTmiMACRO_MEXPAND_DIV(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_122_WARMELTmiMACRO_MEXPAND_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_125_WARMELTmiMACRO_LAMBDA_cl21(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_127_WARMELTmiMACRO_LAMBDA_cl22(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_129_WARMELTmiMACRO_MEXPAND_LET(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_130_WARMELTmiMACRO_LAMBDA_cl23(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_131_WARMELTmiMACRO_LAMBDA_cl24(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_133_WARMELTmiMACRO_MEXPAND_LETREC(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_134_WARMELTmiMACRO_LAMBDA_cl25(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_135_WARMELTmiMACRO_LAMBDA_cl26(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_136_WARMELTmiMACRO_MEXPAND_LAMBDA(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_137_WARMELTmiMACRO_LAMBDA_cl27(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_138_WARMELTmiMACRO_MEXPAND_VARIADIC(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_139_WARMELTmiMACRO_LAMBDA_cl28(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_140_WARMELTmiMACRO_LAMBDA_cl29(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_141_WARMELTmiMACRO_LAMBDA_cl30(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_142_WARMELTmiMACRO_LAMBDA_cl31(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_143_WARMELTmiMACRO_MEXPAND_MULTICALL(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_144_WARMELTmiMACRO_LAMBDA_cl32(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_145_WARMELTmiMACRO_LAMBDA_cl33(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_146_WARMELTmiMACRO_EXPAND_QUOTED_SEXPR(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_147_WARMELTmiMACRO_MEXPAND_QUOTE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_148_WARMELTmiMACRO_ANTIQUOTER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_149_WARMELTmiMACRO_MEXPAND_BACKQUOTE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_150_WARMELTmiMACRO_MEXPAND_COMMA(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_151_WARMELTmiMACRO_MEXPAND_BOX(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_152_WARMELTmiMACRO_MEXPAND_CONSTANT_BOX(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_153_WARMELTmiMACRO_MEXPAND_UNBOX(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_154_WARMELTmiMACRO_MEXPAND_COMMENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_155_WARMELTmiMACRO_MEXPAND_CHEADER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_156_WARMELTmiMACRO_MEXPAND_CIMPLEMENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_157_WARMELTmiMACRO_MEXPAND_USE_PACKAGE_FROM_PKG_CONFIG(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_158_WARMELTmiMACRO_PAIRLIST_TO_RETURN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_159_WARMELTmiMACRO_LAMBDA_cl34(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_160_WARMELTmiMACRO_MEXPAND_PROGN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_161_WARMELTmiMACRO_MEXPAND_RETURN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_162_WARMELTmiMACRO_MEXPAND_FOREVER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_163_WARMELTmiMACRO_LAMBDA_cl35(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_164_WARMELTmiMACRO_MEXPAND_EXIT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_165_WARMELTmiMACRO_LAMBDA_cl36(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_166_WARMELTmiMACRO_MEXPAND_AGAIN(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_167_WARMELTmiMACRO_MEXPAND_COMPILE_WARNING(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_168_WARMELTmiMACRO_MEXPAND_ASSERT_MSG(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_169_WARMELTmiMACRO_MEXPAND_THIS_LINE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_170_WARMELTmiMACRO_MEXPAND_THIS_FILE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_171_WARMELTmiMACRO_MEXPAND_DEBUG(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_172_WARMELTmiMACRO_MEXPAND_EXPORT_VALUES(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_173_WARMELTmiMACRO_LAMBDA_cl37(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_174_WARMELTmiMACRO_MEXPAND_EXPORT_MACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_175_WARMELTmiMACRO_MEXPAND_EXPORT_PATMACRO(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_176_WARMELTmiMACRO_MEXPAND_EXPORT_CLASS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_177_WARMELTmiMACRO_LAMBDA_cl38(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_178_WARMELTmiMACRO_MEXPAND_EXPORT_SYNONYM(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_179_WARMELTmiMACRO_MEXPAND_CURRENT_MODULE_ENVIRONMENT_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_180_WARMELTmiMACRO_MEXPAND_PARENT_MODULE_ENVIRONMENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_181_WARMELTmiMACRO_MEXPAND_UPDATE_CURRENT_MODULE_ENVIRONMENT_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_182_WARMELTmiMACRO_MEXPAND_FETCH_PREDEFINED(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);




MELT_EXTERN melt_ptr_t MELT_MODULE_VISIBILITY meltrout_183_WARMELTmiMACRO_MEXPAND_STORE_PREDEFINED(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_, const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_);


MELT_EXTERN void* melt_start_this_module (void*); /*mandatory start of module*/


/*declare opaque initial frame: */

typedef Melt_InitialClassyFrame_WARMELTmiMACRO_h584434599 /*opaqueinitialclassy*/ meltinitial_frame_t;


/* define different names when debugging or not */
#if MELT_HAVE_DEBUG
MELT_EXTERN const char meltmodule_WARMELTmiMACRO__melt_have_debug_enabled[];
#define melt_have_debug_string meltmodule_WARMELTmiMACRO__melt_have_debug_enabled
#else /*!MELT_HAVE_DEBUG*/
MELT_EXTERN const char meltmodule_WARMELTmiMACRO__melt_have_debug_disabled[];
#define melt_have_debug_string meltmodule_WARMELTmiMACRO__melt_have_debug_disabled
#endif /*!MELT_HAVE_DEBUG*/



void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_0 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_1 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_2 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_3 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_4 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_5 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_6 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_7 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_8 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_9 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_10 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_11 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_12 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_13 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_14 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_15 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_16 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_17 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_18 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_19 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_20 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_21 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_22 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_23 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_24 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_25 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_26 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_27 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_28 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_29 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_30 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_31 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_32 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_33 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_34 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_35 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_36 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_37 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_38 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_39 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_40 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_41 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_42 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_43 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_44 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_45 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_46 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_47 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_48 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_49 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_50 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_51 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_52 (meltinitial_frame_t*, char*);
void MELT_MODULE_VISIBILITY meltmod__WARMELTmiMACRO__initialmeltchunk_53 (meltinitial_frame_t*, char*);


/**** warmelt-macro+05.cc implementations ****/




melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE fromline 1718 */

    /** start of frame for meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE// fromline 1534
        : public Melt_CallFrameWithValues<41>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[13];
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
        MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<41> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE), clos) {};
        MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE() //the constructor fromline 1608
            : Melt_CallFrameWithValues<41> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<41> (fil,lin, sizeof(MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE)) {};
        MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<41> (fil,lin, sizeof(MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE


    /** end of frame for meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE fromline 1663**/

    /* end of frame for routine meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE fromline 1722 */

    /* classy proc frame meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE */
    MeltFrame_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_REFERENCE", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6050:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6051:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6051:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6051:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6051;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_reference sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6051:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6051:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6052:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6052:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6052:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6052;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6052:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6052:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6053:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6053:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6053:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6053;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6053:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6053:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L5*/
        meltfnum[1] =
            ((/*_.MEXPANDER__V4*/ meltfptr[3]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6054:/ cond");
        /*cond*/
        if (/*_#NULL__L5*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    /*^compute*/
                    /*_.MEXPANDER__V4*/ meltfptr[3] = /*_.SETQ___V15*/ meltfptr[5] = (/*!MACROEXPAND_1*/ meltfrout->tabval[4]);;
                    /*_._IF___V14*/
                    meltfptr[12] = /*_.SETQ___V15*/ meltfptr[5];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6054:/ clear");
                    /*clear*/ /*_.SETQ___V15*/
                    meltfptr[5] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V14*/ meltfptr[12] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6055:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L6*/
            meltfnum[0] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6055:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L6*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V17*/ meltfptr[16] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6055:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6055;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                            meltfptr[17] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V17*/
                        meltfptr[16] = /*_.MELT_ASSERT_FAILURE_FUN__V18*/ meltfptr[17];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6055:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                        meltfptr[17] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V16*/
            meltfptr[5] = /*_._IFELSE___V17*/ meltfptr[16];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6055:/ clear");
            /*clear*/ /*_#IS_OBJECT__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V17*/
            meltfptr[16] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V16*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6056:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            MELT_LOCATION("warmelt-macro.melt:6058:/ cond");
            /*cond*/
            if (
                /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[5])),
                                              (melt_ptr_t)((/*!CLASS_CLASS*/ meltfrout->tabval[6])))
            ) /*then*/
                {
                    /*^cond.then*/
                    /*^getslot*/
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[5])) /*=obj*/;
                        melt_object_get_field(slot,obj, 6, "CLASS_FIELDS");
                        /*_.CLASS_FIELDS__V20*/
                        meltfptr[16] = slot;
                    };
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_.CLASS_FIELDS__V20*/ meltfptr[16] =  /*reallynil*/ NULL ;;
                }
            ;
            /*^compute*/
            /*_#MULTIPLE_LENGTH__L7*/
            meltfnum[0] =
                (melt_multiple_length((melt_ptr_t)(/*_.CLASS_FIELDS__V20*/ meltfptr[16])));;
            /*^compute*/
            /*_#eqeqI__L8*/
            meltfnum[7] =
                ((1) == (/*_#MULTIPLE_LENGTH__L7*/ meltfnum[0]));;
            MELT_LOCATION("warmelt-macro.melt:6056:/ cond");
            /*cond*/
            if (/*_#eqeqI__L8*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V21*/ meltfptr[20] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6056:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check class_reference has one field";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6056;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &(/*!CLASS_FIELDS*/ meltfrout->tabval[7]);
                            /*_.MELT_ASSERT_FAILURE_FUN__V22*/
                            meltfptr[21] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V21*/
                        meltfptr[20] = /*_.MELT_ASSERT_FAILURE_FUN__V22*/ meltfptr[21];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6056:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V22*/
                        meltfptr[21] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V19*/
            meltfptr[17] = /*_._IFELSE___V21*/ meltfptr[20];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6056:/ clear");
            /*clear*/ /*_.CLASS_FIELDS__V20*/
            meltfptr[16] = 0 ;
            /*^clear*/
            /*clear*/ /*_#MULTIPLE_LENGTH__L7*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_#eqeqI__L8*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V21*/
            meltfptr[20] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V19*/ meltfptr[17] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6061:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6062:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V24*/
            meltfptr[16] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6063:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V25*/
            meltfptr[20] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6064:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V26*/
            meltfptr[25] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[8])), (melt_ptr_t)(/*_.CONT__V24*/ meltfptr[16]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_#NBARG__L9*/
        meltfnum[0] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V26*/ meltfptr[25])));;
        /*^compute*/
        /*_.ARG1__V27*/
        meltfptr[26] =
            (melt_multiple_nth((melt_ptr_t)(/*_.XARGTUP__V26*/ meltfptr[25]), (0)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6067:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_FETCH_PREDEFINED*/ meltfrout->tabval[9])), (3), "CLASS_SOURCE_FETCH_PREDEFINED");
            /*_.INST__V29*/
            meltfptr[28] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V29*/ meltfptr[28])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V29*/ meltfptr[28]), (1), (/*_.LOC__V25*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SFEPD_PREDEF", melt_magic_discr((melt_ptr_t)(/*_.INST__V29*/ meltfptr[28])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V29*/ meltfptr[28]), (2), ((/*!konst_10_CLASS_REFERENCE*/ meltfrout->tabval[10])), "SFEPD_PREDEF");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V29*/ meltfptr[28], "newly made instance");
        ;
        /*_.SPREDCLASSCONT__V28*/
        meltfptr[27] = /*_.INST__V29*/ meltfptr[28];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6070:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!konst_10_CLASS_REFERENCE*/ meltfrout->tabval[10]);
            /*_.CLABIND__V30*/
            meltfptr[29] =  melt_apply ((meltclosure_ptr_t)((/*!FIND_ENV*/ meltfrout->tabval[11])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6071:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[6];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.LOC__V25*/ meltfptr[20];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &(/*!konst_14_REFERENCED_VALUE*/ meltfrout->tabval[14]);
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.ARG1__V27*/ meltfptr[26];
            /*^apply.arg*/
            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[5].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.FLDA__V31*/
            meltfptr[30] =  melt_apply ((meltclosure_ptr_t)((/*!PARSE_FIELD_ASSIGNMENT*/ meltfrout->tabval[13])), (melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[5])), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6078:/ blockmultialloc");
        /*multiallocblock*/
        {
            struct meltletrec_1_st
            {
                struct MELT_MULTIPLE_STRUCT(1) rtup_0__TUPLREC__x6;
                long meltletrec_1_endgap;
            } *meltletrec_1_ptr = 0;
            meltletrec_1_ptr = (struct meltletrec_1_st *) meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
            /*^blockmultialloc.initfill*/
            /*inimult rtup_0__TUPLREC__x6*/
            /*_.TUPLREC___V33*/
            meltfptr[32] = (melt_ptr_t) &meltletrec_1_ptr->rtup_0__TUPLREC__x6;
            meltletrec_1_ptr->rtup_0__TUPLREC__x6.discr = (meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_MULTIPLE))));
            meltletrec_1_ptr->rtup_0__TUPLREC__x6.nbval = 1;


            /*^putuple*/
            /*putupl#9*/
            melt_assertmsg("putupl [:6078] #9 checktup", melt_magic_discr((melt_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))== MELTOBMAG_MULTIPLE);
            melt_assertmsg("putupl [:6078] #9 checkoff", (0>=0 && 0< melt_multiple_length((melt_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))));
            ((meltmultiple_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))->tabval[0] = (melt_ptr_t)(/*_.FLDA__V31*/ meltfptr[30]);
            ;
            /*^touch*/
            meltgc_touch(/*_.TUPLREC___V33*/ meltfptr[32]);
            ;
            /*_.TUPLE___V32*/
            meltfptr[31] = /*_.TUPLREC___V33*/ meltfptr[32];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6078:/ clear");
            /*clear*/ /*_.TUPLREC___V33*/
            meltfptr[32] = 0 ;
            /*^clear*/
            /*clear*/ /*_.TUPLREC___V33*/
            meltfptr[32] = 0 ;
        } /*end multiallocblock*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6073:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_INSTANCE*/ meltfrout->tabval[15])), (5), "CLASS_SOURCE_INSTANCE");
            /*_.INST__V35*/
            meltfptr[34] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (1), (/*_.LOC__V25*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMINS_CLASS", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (2), ((/*!CLASS_REFERENCE*/ meltfrout->tabval[5])), "SMINS_CLASS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMINS_CLABIND", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (3), (/*_.CLABIND__V30*/ meltfptr[29]), "SMINS_CLABIND");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMINS_FIELDS", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (4), (/*_.TUPLE___V32*/ meltfptr[31]), "SMINS_FIELDS");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V35*/ meltfptr[34], "newly made instance");
        ;
        /*_.SINST__V34*/
        meltfptr[32] = /*_.INST__V35*/ meltfptr[34];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#exeqI__L10*/
        meltfnum[7] =
            ((/*_#NBARG__L9*/ meltfnum[0]) != (1));;
        MELT_LOCATION("warmelt-macro.melt:6080:/ cond");
        /*cond*/
        if (/*_#exeqI__L10*/ meltfnum[7]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6082:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V25*/ meltfptr[20]), ( "(REFERENCE <value>) needs exactly one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6083:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6083:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6081:/ quasiblock");


                    /*_.PROGN___V38*/
                    meltfptr[37] = /*_.RETURN___V37*/ meltfptr[36];;
                    /*^compute*/
                    /*_._IF___V36*/
                    meltfptr[35] = /*_.PROGN___V38*/ meltfptr[37];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6080:/ clear");
                    /*clear*/ /*_.RETURN___V37*/
                    meltfptr[36] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V38*/
                    meltfptr[37] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V36*/ meltfptr[35] =  /*reallynil*/ NULL ;;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L11*/
        meltfnum[10] =
            ((/*_.CLABIND__V30*/ meltfptr[29]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6086:/ cond");
        /*cond*/
        if (/*_#NULL__L11*/ meltfnum[10]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6087:/ locexp");
                        melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V25*/ meltfptr[20]), ( "(REFERENCE <value>) where CLASS_REFERENCE is not visible"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6089:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6089:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L12*/ meltfnum[11]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L13*/ meltfnum[12] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6089:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L13*/ meltfnum[12];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6089;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_reference returns sinst";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SINST__V34*/ meltfptr[32];
                            /*_.MELT_DEBUG_FUN__V40*/
                            meltfptr[37] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V39*/
                        meltfptr[36] = /*_.MELT_DEBUG_FUN__V40*/ meltfptr[37];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6089:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L13*/
                        meltfnum[12] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V40*/
                        meltfptr[37] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V39*/ meltfptr[36] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6089:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V39*/
            meltfptr[36] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6090:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.SINST__V34*/ meltfptr[32];;

        {
            MELT_LOCATION("warmelt-macro.melt:6090:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V23*/
        meltfptr[21] = /*_.RETURN___V41*/ meltfptr[37];;

        MELT_LOCATION("warmelt-macro.melt:6061:/ clear");
        /*clear*/ /*_.CONT__V24*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V25*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NBARG__L9*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARG1__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SPREDCLASSCONT__V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CLABIND__V30*/
        meltfptr[29] = 0 ;
        /*^clear*/
        /*clear*/ /*_.FLDA__V31*/
        meltfptr[30] = 0 ;
        /*^clear*/
        /*clear*/ /*_.TUPLE___V32*/
        meltfptr[31] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SINST__V34*/
        meltfptr[32] = 0 ;
        /*^clear*/
        /*clear*/ /*_#exeqI__L10*/
        meltfnum[7] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V36*/
        meltfptr[35] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L11*/
        meltfnum[10] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V41*/
        meltfptr[37] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6050:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V23*/ meltfptr[21];;

        {
            MELT_LOCATION("warmelt-macro.melt:6050:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V16*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V19*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V23*/
        meltfptr[21] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_REFERENCE", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_109_WARMELTmiMACRO_MEXPAND_REFERENCE*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE fromline 1718 */

    /** start of frame for meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE// fromline 1534
        : public Melt_CallFrameWithValues<33>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[9];
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
        MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<33> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE), clos) {};
        MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE() //the constructor fromline 1608
            : Melt_CallFrameWithValues<33> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<33> (fil,lin, sizeof(MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE)) {};
        MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<33> (fil,lin, sizeof(MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE


    /** end of frame for meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE fromline 1663**/

    /* end of frame for routine meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE fromline 1722 */

    /* classy proc frame meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE */
    MeltFrame_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("PATEXPAND_REFERENCE", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6094:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.PCTX__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6095:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6095:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6095:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6095;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_reference sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V6*/
                            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V5*/
                        meltfptr[4] = /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6095:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V6*/
                        meltfptr[5] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V5*/ meltfptr[4] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6095:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V5*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6096:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6096:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V8*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6096:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6096;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                            meltfptr[8] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V8*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V9*/ meltfptr[8];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6096:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                        meltfptr[8] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V7*/
            meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6096:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V8*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V7*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6097:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6097:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V11*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6097:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6097;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                            meltfptr[11] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V11*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V12*/ meltfptr[11];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6097:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                        meltfptr[11] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V10*/
            meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6097:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V11*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V10*/ meltfptr[8] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6098:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L5*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3]), (melt_ptr_t)((/*!CLASS_PATTERN_EXPANSION_CONTEXT*/ meltfrout->tabval[4])));;
            MELT_LOCATION("warmelt-macro.melt:6098:/ cond");
            /*cond*/
            if (/*_#IS_A__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V14*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6098:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check pctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6098;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
                            /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                            meltfptr[14] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V14*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V15*/ meltfptr[14];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6098:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                        meltfptr[14] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V13*/
            meltfptr[11] = /*_._IFELSE___V14*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6098:/ clear");
            /*clear*/ /*_#IS_A__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V14*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V13*/ meltfptr[11] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6099:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6100:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V17*/
            meltfptr[4] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6101:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V18*/
            meltfptr[17] = slot;
        };
        ;
        /*_.LIST_FIRST__V19*/
        meltfptr[18] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V17*/ meltfptr[4])));;
        /*^compute*/
        /*_.CURPAIR__V20*/
        meltfptr[19] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V19*/ meltfptr[18])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6103:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.LOC__V18*/ meltfptr[17];
            /*_.ARGSP__V21*/
            meltfptr[20] =  melt_apply ((meltclosure_ptr_t)((/*!PATTERNEXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.CURPAIR__V20*/ meltfptr[19]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_.ARG1__V22*/
        meltfptr[21] =
            (melt_multiple_nth((melt_ptr_t)(/*_.ARGSP__V21*/ meltfptr[20]), (0)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6105:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[5];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!CLASS_REFERENCE*/ meltfrout->tabval[8]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.ARG1__V22*/ meltfptr[21];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.LOC__V18*/ meltfptr[17];
            /*_.FLDP__V23*/
            meltfptr[22] =  melt_apply ((meltclosure_ptr_t)((/*!PARSE_FIELD_PATTERN*/ meltfrout->tabval[6])), (melt_ptr_t)((/*!konst_7_REFERENCED_VALUE*/ meltfrout->tabval[7])), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6110:/ blockmultialloc");
        /*multiallocblock*/
        {
            struct meltletrec_1_st
            {
                struct MELT_MULTIPLE_STRUCT(1) rtup_0__TUPLREC__x7;
                long meltletrec_1_endgap;
            } *meltletrec_1_ptr = 0;
            meltletrec_1_ptr = (struct meltletrec_1_st *) meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
            /*^blockmultialloc.initfill*/
            /*inimult rtup_0__TUPLREC__x7*/
            /*_.TUPLREC___V25*/
            meltfptr[24] = (melt_ptr_t) &meltletrec_1_ptr->rtup_0__TUPLREC__x7;
            meltletrec_1_ptr->rtup_0__TUPLREC__x7.discr = (meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_MULTIPLE))));
            meltletrec_1_ptr->rtup_0__TUPLREC__x7.nbval = 1;


            /*^putuple*/
            /*putupl#10*/
            melt_assertmsg("putupl [:6110] #10 checktup", melt_magic_discr((melt_ptr_t)(/*_.TUPLREC___V25*/ meltfptr[24]))== MELTOBMAG_MULTIPLE);
            melt_assertmsg("putupl [:6110] #10 checkoff", (0>=0 && 0< melt_multiple_length((melt_ptr_t)(/*_.TUPLREC___V25*/ meltfptr[24]))));
            ((meltmultiple_ptr_t)(/*_.TUPLREC___V25*/ meltfptr[24]))->tabval[0] = (melt_ptr_t)(/*_.FLDP__V23*/ meltfptr[22]);
            ;
            /*^touch*/
            meltgc_touch(/*_.TUPLREC___V25*/ meltfptr[24]);
            ;
            /*_.TUPLE___V24*/
            meltfptr[23] = /*_.TUPLREC___V25*/ meltfptr[24];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6110:/ clear");
            /*clear*/ /*_.TUPLREC___V25*/
            meltfptr[24] = 0 ;
            /*^clear*/
            /*clear*/ /*_.TUPLREC___V25*/
            meltfptr[24] = 0 ;
        } /*end multiallocblock*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6106:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_PATTERN_INSTANCE*/ meltfrout->tabval[9])), (5), "CLASS_SOURCE_PATTERN_INSTANCE");
            /*_.INST__V27*/
            meltfptr[26] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (1), (/*_.LOC__V18*/ meltfptr[17]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @PAT_WEIGHT", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (2), ((/*!konst_10*/ meltfrout->tabval[10])), "PAT_WEIGHT");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SPAT_CLASS", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (3), ((/*!CLASS_REFERENCE*/ meltfrout->tabval[8])), "SPAT_CLASS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SPAT_FIELDS", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (4), (/*_.TUPLE___V24*/ meltfptr[23]), "SPAT_FIELDS");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V27*/ meltfptr[26], "newly made instance");
        ;
        /*_.RES__V26*/
        meltfptr[24] = /*_.INST__V27*/ meltfptr[26];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#MULTIPLE_LENGTH__L6*/
        meltfnum[0] =
            (melt_multiple_length((melt_ptr_t)(/*_.ARGSP__V21*/ meltfptr[20])));;
        /*^compute*/
        /*_#exeqI__L7*/
        meltfnum[1] =
            ((/*_#MULTIPLE_LENGTH__L6*/ meltfnum[0]) != (1));;
        MELT_LOCATION("warmelt-macro.melt:6112:/ cond");
        /*cond*/
        if (/*_#exeqI__L7*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6114:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V18*/ meltfptr[17]), ( "(REFERENCE <subpattern>) pattern needs one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6115:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6115:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6113:/ quasiblock");


                    /*_.PROGN___V30*/
                    meltfptr[29] = /*_.RETURN___V29*/ meltfptr[28];;
                    /*^compute*/
                    /*_._IF___V28*/
                    meltfptr[27] = /*_.PROGN___V30*/ meltfptr[29];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6112:/ clear");
                    /*clear*/ /*_.RETURN___V29*/
                    meltfptr[28] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V30*/
                    meltfptr[29] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V28*/ meltfptr[27] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6116:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6116:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L8*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L9*/ meltfnum[8] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6116:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6116;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_reference res";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V26*/ meltfptr[24];
                            /*_.MELT_DEBUG_FUN__V32*/
                            meltfptr[29] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V31*/
                        meltfptr[28] = /*_.MELT_DEBUG_FUN__V32*/ meltfptr[29];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6116:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L9*/
                        meltfnum[8] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V32*/
                        meltfptr[29] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V31*/ meltfptr[28] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6116:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V31*/
            meltfptr[28] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6117:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V26*/ meltfptr[24];;

        {
            MELT_LOCATION("warmelt-macro.melt:6117:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V16*/
        meltfptr[14] = /*_.RETURN___V33*/ meltfptr[29];;

        MELT_LOCATION("warmelt-macro.melt:6099:/ clear");
        /*clear*/ /*_.CONT__V17*/
        meltfptr[4] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V19*/
        meltfptr[18] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CURPAIR__V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARGSP__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARG1__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.FLDP__V23*/
        meltfptr[22] = 0 ;
        /*^clear*/
        /*clear*/ /*_.TUPLE___V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V26*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_#MULTIPLE_LENGTH__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_#exeqI__L7*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V33*/
        meltfptr[29] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6094:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V16*/ meltfptr[14];;

        {
            MELT_LOCATION("warmelt-macro.melt:6094:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V7*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V10*/
        meltfptr[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V13*/
        meltfptr[11] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V16*/
        meltfptr[14] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("PATEXPAND_REFERENCE", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_110_WARMELTmiMACRO_PATEXPAND_REFERENCE*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER fromline 1718 */

    /** start of frame for meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER// fromline 1534
        : public Melt_CallFrameWithValues<12>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[3];
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
        MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<12> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER), clos) {};
        MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER() //the constructor fromline 1608
            : Melt_CallFrameWithValues<12> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<12> (fil,lin, sizeof(MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER)) {};
        MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<12> (fil,lin, sizeof(MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER


    /** end of frame for meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER fromline 1663**/

    /* end of frame for routine meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER fromline 1722 */

    /* classy proc frame meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER */
    MeltFrame_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPANDOBSOLETE_CONTAINER", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6133:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6134:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6134:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6134:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6134;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpandobsolete_container sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6134:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6134:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6135:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6135:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6135:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6135;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6135:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6135:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6136:/ cond");
        /*cond*/
        if (
            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]),
                                          (melt_ptr_t)((/*!CLASS_LOCATED*/ meltfrout->tabval[3])))
        ) /*then*/
            {
                /*^cond.then*/
                /*^getslot*/
                {
                    melt_ptr_t slot=NULL, obj=NULL;
                    obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
                    melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                    /*_.LOCA_LOCATION__V11*/
                    meltfptr[9] = slot;
                };
                ;
            }
        else    /*^cond.else*/
            {

                /*_.LOCA_LOCATION__V11*/ meltfptr[9] =  /*reallynil*/ NULL ;;
            }
        ;

        {
            MELT_LOCATION("warmelt-macro.melt:6136:/ locexp");
            melt_warning_str(0, (melt_ptr_t)(/*_.LOCA_LOCATION__V11*/ meltfptr[9]), ( "obsolete use of CONTAINER in expression; use REFERENCE instead"), (melt_ptr_t)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6138:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.MEXPAND_REFERENCE__V12*/
            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MEXPAND_REFERENCE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6133:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.MEXPAND_REFERENCE__V12*/ meltfptr[5];;

        {
            MELT_LOCATION("warmelt-macro.melt:6133:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOCA_LOCATION__V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MEXPAND_REFERENCE__V12*/
        meltfptr[5] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPANDOBSOLETE_CONTAINER", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_111_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTAINER*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER fromline 1718 */

    /** start of frame for meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER// fromline 1534
        : public Melt_CallFrameWithValues<11>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[3];
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
        MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<11> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER), clos) {};
        MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER() //the constructor fromline 1608
            : Melt_CallFrameWithValues<11> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<11> (fil,lin, sizeof(MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER)) {};
        MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<11> (fil,lin, sizeof(MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER


    /** end of frame for meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER fromline 1663**/

    /* end of frame for routine meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER fromline 1722 */

    /* classy proc frame meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER */
    MeltFrame_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("PATEXPANDOBSOLETE_CONTAINER", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6140:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.PCTX__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6141:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6141:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6141:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6141;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpandobsolete_container sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V6*/
                            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V5*/
                        meltfptr[4] = /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6141:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V6*/
                        meltfptr[5] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V5*/ meltfptr[4] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6141:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V5*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6142:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6142:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V8*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6142:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6142;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                            meltfptr[8] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V8*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V9*/ meltfptr[8];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6142:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                        meltfptr[8] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V7*/
            meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6142:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V8*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V7*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6143:/ cond");
        /*cond*/
        if (
            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]),
                                          (melt_ptr_t)((/*!CLASS_LOCATED*/ meltfrout->tabval[3])))
        ) /*then*/
            {
                /*^cond.then*/
                /*^getslot*/
                {
                    melt_ptr_t slot=NULL, obj=NULL;
                    obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
                    melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                    /*_.LOCA_LOCATION__V10*/
                    meltfptr[8] = slot;
                };
                ;
            }
        else    /*^cond.else*/
            {

                /*_.LOCA_LOCATION__V10*/ meltfptr[8] =  /*reallynil*/ NULL ;;
            }
        ;

        {
            MELT_LOCATION("warmelt-macro.melt:6143:/ locexp");
            melt_warning_str(0, (melt_ptr_t)(/*_.LOCA_LOCATION__V10*/ meltfptr[8]), ( "obsolete use of CONTAINER in pattern; use REFERENCE instead"), (melt_ptr_t)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6145:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[2];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
            /*_.PATEXPAND_REFERENCE__V11*/
            meltfptr[4] =  melt_apply ((meltclosure_ptr_t)((/*!PATEXPAND_REFERENCE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6140:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.PATEXPAND_REFERENCE__V11*/ meltfptr[4];;

        {
            MELT_LOCATION("warmelt-macro.melt:6140:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V7*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOCA_LOCATION__V10*/
        meltfptr[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PATEXPAND_REFERENCE__V11*/
        meltfptr[4] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("PATEXPANDOBSOLETE_CONTAINER", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_112_WARMELTmiMACRO_PATEXPANDOBSOLETE_CONTAINER*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF fromline 1718 */

    /** start of frame for meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF// fromline 1534
        : public Melt_CallFrameWithValues<39>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[13];
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
        MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<39> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF), clos) {};
        MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF() //the constructor fromline 1608
            : Melt_CallFrameWithValues<39> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<39> (fil,lin, sizeof(MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF)) {};
        MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<39> (fil,lin, sizeof(MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF


    /** end of frame for meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF fromline 1663**/

    /* end of frame for routine meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF fromline 1722 */

    /* classy proc frame meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF */
    MeltFrame_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_DEREF", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6154:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6155:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6155:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6155:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6155;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_deref sexpr";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6155:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6155:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6156:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6156:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6156:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6156;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6156:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6156:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6157:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6157:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6157:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6157;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6157:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6157:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6158:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L5*/
            meltfnum[1] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6158:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V15*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6158:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6158;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                            meltfptr[15] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V15*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V16*/ meltfptr[15];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6158:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                        meltfptr[15] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V14*/
            meltfptr[12] = /*_._IFELSE___V15*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6158:/ clear");
            /*clear*/ /*_#IS_OBJECT__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V15*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V14*/ meltfptr[12] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6159:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            MELT_LOCATION("warmelt-macro.melt:6161:/ cond");
            /*cond*/
            if (
                /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[4])),
                                              (melt_ptr_t)((/*!CLASS_CLASS*/ meltfrout->tabval[5])))
            ) /*then*/
                {
                    /*^cond.then*/
                    /*^getslot*/
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[4])) /*=obj*/;
                        melt_object_get_field(slot,obj, 6, "CLASS_FIELDS");
                        /*_.CLASS_FIELDS__V18*/
                        meltfptr[5] = slot;
                    };
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_.CLASS_FIELDS__V18*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;
            /*^compute*/
            /*_#MULTIPLE_LENGTH__L6*/
            meltfnum[0] =
                (melt_multiple_length((melt_ptr_t)(/*_.CLASS_FIELDS__V18*/ meltfptr[5])));;
            /*^compute*/
            /*_#eqeqI__L7*/
            meltfnum[1] =
                ((1) == (/*_#MULTIPLE_LENGTH__L6*/ meltfnum[0]));;
            MELT_LOCATION("warmelt-macro.melt:6159:/ cond");
            /*cond*/
            if (/*_#eqeqI__L7*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V19*/ meltfptr[18] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6159:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check class_reference has one field";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6159;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &(/*!CLASS_REFERENCE*/ meltfrout->tabval[4]);
                            /*_.MELT_ASSERT_FAILURE_FUN__V20*/
                            meltfptr[19] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V19*/
                        meltfptr[18] = /*_.MELT_ASSERT_FAILURE_FUN__V20*/ meltfptr[19];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6159:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V20*/
                        meltfptr[19] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V17*/
            meltfptr[15] = /*_._IFELSE___V19*/ meltfptr[18];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6159:/ clear");
            /*clear*/ /*_.CLASS_FIELDS__V18*/
            meltfptr[5] = 0 ;
            /*^clear*/
            /*clear*/ /*_#MULTIPLE_LENGTH__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_#eqeqI__L7*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V19*/
            meltfptr[18] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V17*/ meltfptr[15] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6163:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6164:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V22*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6165:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V23*/
            meltfptr[18] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6166:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V24*/
            meltfptr[23] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[6])), (melt_ptr_t)(/*_.CONT__V22*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_#NBARG__L8*/
        meltfnum[0] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V24*/ meltfptr[23])));;
        /*^compute*/
        /*_.ARG1__V25*/
        meltfptr[24] =
            (melt_multiple_nth((melt_ptr_t)(/*_.XARGTUP__V24*/ meltfptr[23]), (0)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6169:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_FETCH_PREDEFINED*/ meltfrout->tabval[7])), (3), "CLASS_SOURCE_FETCH_PREDEFINED");
            /*_.INST__V27*/
            meltfptr[26] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (1), (/*_.LOC__V23*/ meltfptr[18]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SFEPD_PREDEF", melt_magic_discr((melt_ptr_t)(/*_.INST__V27*/ meltfptr[26])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V27*/ meltfptr[26]), (2), ((/*!konst_8_CLASS_REFERENCE*/ meltfrout->tabval[8])), "SFEPD_PREDEF");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V27*/ meltfptr[26], "newly made instance");
        ;
        /*_.SPREDCLASSCONT__V26*/
        meltfptr[25] = /*_.INST__V27*/ meltfptr[26];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6172:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!konst_8_CLASS_REFERENCE*/ meltfrout->tabval[8]);
            /*_.CLABIND__V28*/
            meltfptr[27] =  melt_apply ((meltclosure_ptr_t)((/*!FIND_ENV*/ meltfrout->tabval[9])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6173:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_GET_FIELD*/ meltfrout->tabval[11])), (4), "CLASS_SOURCE_GET_FIELD");
            /*_.INST__V30*/
            meltfptr[29] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V30*/ meltfptr[29])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V30*/ meltfptr[29]), (1), (/*_.LOC__V23*/ meltfptr[18]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SUGET_OBJ", melt_magic_discr((melt_ptr_t)(/*_.INST__V30*/ meltfptr[29])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V30*/ meltfptr[29]), (2), (/*_.ARG1__V25*/ meltfptr[24]), "SUGET_OBJ");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SUGET_FIELD", melt_magic_discr((melt_ptr_t)(/*_.INST__V30*/ meltfptr[29])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V30*/ meltfptr[29]), (3), ((/*!REFERENCED_VALUE*/ meltfrout->tabval[12])), "SUGET_FIELD");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V30*/ meltfptr[29], "newly made instance");
        ;
        /*_.SGET__V29*/
        meltfptr[28] = /*_.INST__V30*/ meltfptr[29];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6179:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L9*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)((/*!REFERENCED_VALUE*/ meltfrout->tabval[12])), (melt_ptr_t)((/*!CLASS_FIELD*/ meltfrout->tabval[13])));;
            MELT_LOCATION("warmelt-macro.melt:6179:/ cond");
            /*cond*/
            if (/*_#IS_A__L9*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V32*/ meltfptr[31] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6179:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check referenced_value";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6179;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &(/*!REFERENCED_VALUE*/ meltfrout->tabval[12]);
                            /*_.MELT_ASSERT_FAILURE_FUN__V33*/
                            meltfptr[32] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V32*/
                        meltfptr[31] = /*_.MELT_ASSERT_FAILURE_FUN__V33*/ meltfptr[32];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6179:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V33*/
                        meltfptr[32] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V31*/
            meltfptr[30] = /*_._IFELSE___V32*/ meltfptr[31];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6179:/ clear");
            /*clear*/ /*_#IS_A__L9*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V32*/
            meltfptr[31] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V31*/ meltfptr[30] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#exeqI__L10*/
        meltfnum[1] =
            ((/*_#NBARG__L8*/ meltfnum[0]) != (1));;
        MELT_LOCATION("warmelt-macro.melt:6180:/ cond");
        /*cond*/
        if (/*_#exeqI__L10*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6182:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V23*/ meltfptr[18]), ( "(DEREF <value>) needs exactly one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6183:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6183:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6181:/ quasiblock");


                    /*_.PROGN___V36*/
                    meltfptr[35] = /*_.RETURN___V35*/ meltfptr[31];;
                    /*^compute*/
                    /*_._IF___V34*/
                    meltfptr[32] = /*_.PROGN___V36*/ meltfptr[35];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6180:/ clear");
                    /*clear*/ /*_.RETURN___V35*/
                    meltfptr[31] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V36*/
                    meltfptr[35] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V34*/ meltfptr[32] =  /*reallynil*/ NULL ;;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L11*/
        meltfnum[10] =
            ((/*_.CLABIND__V28*/ meltfptr[27]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6186:/ cond");
        /*cond*/
        if (/*_#NULL__L11*/ meltfnum[10]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6187:/ locexp");
                        melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V23*/ meltfptr[18]), ( "(DEREF <value>) where CLASS_REFERENCE is not visible"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6188:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6188:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L12*/ meltfnum[11]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L13*/ meltfnum[12] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6188:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L13*/ meltfnum[12];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6188;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_deref returns sget";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SGET__V29*/ meltfptr[28];
                            /*_.MELT_DEBUG_FUN__V38*/
                            meltfptr[35] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V37*/
                        meltfptr[31] = /*_.MELT_DEBUG_FUN__V38*/ meltfptr[35];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6188:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L13*/
                        meltfnum[12] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V38*/
                        meltfptr[35] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V37*/ meltfptr[31] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6188:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V37*/
            meltfptr[31] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6189:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.SGET__V29*/ meltfptr[28];;

        {
            MELT_LOCATION("warmelt-macro.melt:6189:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V21*/
        meltfptr[19] = /*_.RETURN___V39*/ meltfptr[35];;

        MELT_LOCATION("warmelt-macro.melt:6163:/ clear");
        /*clear*/ /*_.CONT__V22*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V23*/
        meltfptr[18] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NBARG__L8*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARG1__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SPREDCLASSCONT__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CLABIND__V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SGET__V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V31*/
        meltfptr[30] = 0 ;
        /*^clear*/
        /*clear*/ /*_#exeqI__L10*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V34*/
        meltfptr[32] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L11*/
        meltfnum[10] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V39*/
        meltfptr[35] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6154:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V21*/ meltfptr[19];;

        {
            MELT_LOCATION("warmelt-macro.melt:6154:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V17*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V21*/
        meltfptr[19] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_DEREF", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_113_WARMELTmiMACRO_MEXPAND_DEREF*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT fromline 1718 */

    /** start of frame for meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT// fromline 1534
        : public Melt_CallFrameWithValues<12>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[3];
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
        MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<12> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT), clos) {};
        MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT() //the constructor fromline 1608
            : Melt_CallFrameWithValues<12> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<12> (fil,lin, sizeof(MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT)) {};
        MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<12> (fil,lin, sizeof(MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT


    /** end of frame for meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT fromline 1663**/

    /* end of frame for routine meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT fromline 1722 */

    /* classy proc frame meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT */
    MeltFrame_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPANDOBSOLETE_CONTENT", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6199:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6200:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6200:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6200:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6200;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpandobsolete_content sexpr";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6200:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6200:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6201:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6201:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6201:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6201;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6201:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6201:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6202:/ cond");
        /*cond*/
        if (
            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]),
                                          (melt_ptr_t)((/*!CLASS_LOCATED*/ meltfrout->tabval[3])))
        ) /*then*/
            {
                /*^cond.then*/
                /*^getslot*/
                {
                    melt_ptr_t slot=NULL, obj=NULL;
                    obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
                    melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                    /*_.LOCA_LOCATION__V11*/
                    meltfptr[9] = slot;
                };
                ;
            }
        else    /*^cond.else*/
            {

                /*_.LOCA_LOCATION__V11*/ meltfptr[9] =  /*reallynil*/ NULL ;;
            }
        ;

        {
            MELT_LOCATION("warmelt-macro.melt:6202:/ locexp");
            melt_warning_str(0, (melt_ptr_t)(/*_.LOCA_LOCATION__V11*/ meltfptr[9]), ( "obsolete use of CONTENT in expression; use DEREF instead"), (melt_ptr_t)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6204:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.MEXPAND_DEREF__V12*/
            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MEXPAND_DEREF*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6199:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.MEXPAND_DEREF__V12*/ meltfptr[5];;

        {
            MELT_LOCATION("warmelt-macro.melt:6199:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOCA_LOCATION__V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MEXPAND_DEREF__V12*/
        meltfptr[5] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPANDOBSOLETE_CONTENT", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_114_WARMELTmiMACRO_MEXPANDOBSOLETE_CONTENT*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF fromline 1718 */

    /** start of frame for meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF// fromline 1534
        : public Melt_CallFrameWithValues<44>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[13];
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
        MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<44> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF), clos) {};
        MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF() //the constructor fromline 1608
            : Melt_CallFrameWithValues<44> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<44> (fil,lin, sizeof(MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF)) {};
        MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<44> (fil,lin, sizeof(MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF


    /** end of frame for meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF fromline 1663**/

    /* end of frame for routine meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF fromline 1722 */

    /* classy proc frame meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF */
    MeltFrame_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_SET_REF", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6221:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6222:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6222:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6222:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6222;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_set_ref sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6222:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6222:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6223:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6223:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6223:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6223;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6223:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6223:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6224:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6224:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6224:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6224;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6224:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6224:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6225:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L5*/
            meltfnum[1] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6225:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V15*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6225:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6225;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                            meltfptr[15] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V15*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V16*/ meltfptr[15];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6225:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                        meltfptr[15] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V14*/
            meltfptr[12] = /*_._IFELSE___V15*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6225:/ clear");
            /*clear*/ /*_#IS_OBJECT__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V15*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V14*/ meltfptr[12] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6226:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            MELT_LOCATION("warmelt-macro.melt:6228:/ cond");
            /*cond*/
            if (
                /*ifisa*/ melt_is_instance_of((melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[4])),
                                              (melt_ptr_t)((/*!CLASS_CLASS*/ meltfrout->tabval[5])))
            ) /*then*/
                {
                    /*^cond.then*/
                    /*^getslot*/
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)((/*!CLASS_REFERENCE*/ meltfrout->tabval[4])) /*=obj*/;
                        melt_object_get_field(slot,obj, 6, "CLASS_FIELDS");
                        /*_.CLASS_FIELDS__V18*/
                        meltfptr[5] = slot;
                    };
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_.CLASS_FIELDS__V18*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;
            /*^compute*/
            /*_#MULTIPLE_LENGTH__L6*/
            meltfnum[0] =
                (melt_multiple_length((melt_ptr_t)(/*_.CLASS_FIELDS__V18*/ meltfptr[5])));;
            /*^compute*/
            /*_#eqeqI__L7*/
            meltfnum[1] =
                ((1) == (/*_#MULTIPLE_LENGTH__L6*/ meltfnum[0]));;
            MELT_LOCATION("warmelt-macro.melt:6226:/ cond");
            /*cond*/
            if (/*_#eqeqI__L7*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V19*/ meltfptr[18] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6226:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check class_reference has one field";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6226;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &(/*!CLASS_REFERENCE*/ meltfrout->tabval[4]);
                            /*_.MELT_ASSERT_FAILURE_FUN__V20*/
                            meltfptr[19] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V19*/
                        meltfptr[18] = /*_.MELT_ASSERT_FAILURE_FUN__V20*/ meltfptr[19];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6226:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V20*/
                        meltfptr[19] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V17*/
            meltfptr[15] = /*_._IFELSE___V19*/ meltfptr[18];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6226:/ clear");
            /*clear*/ /*_.CLASS_FIELDS__V18*/
            meltfptr[5] = 0 ;
            /*^clear*/
            /*clear*/ /*_#MULTIPLE_LENGTH__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_#eqeqI__L7*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V19*/
            meltfptr[18] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V17*/ meltfptr[15] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6230:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6231:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V22*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6232:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V23*/
            meltfptr[18] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6233:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V24*/
            meltfptr[23] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[6])), (melt_ptr_t)(/*_.CONT__V22*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_#NBARG__L8*/
        meltfnum[0] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V24*/ meltfptr[23])));;
        /*^compute*/
        /*_.ARG1__V25*/
        meltfptr[24] =
            (melt_multiple_nth((melt_ptr_t)(/*_.XARGTUP__V24*/ meltfptr[23]), (0)));;
        /*^compute*/
        /*_.ARG2__V26*/
        meltfptr[25] =
            (melt_multiple_nth((melt_ptr_t)(/*_.XARGTUP__V24*/ meltfptr[23]), (1)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6237:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_FETCH_PREDEFINED*/ meltfrout->tabval[7])), (3), "CLASS_SOURCE_FETCH_PREDEFINED");
            /*_.INST__V28*/
            meltfptr[27] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V28*/ meltfptr[27])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V28*/ meltfptr[27]), (1), (/*_.LOC__V23*/ meltfptr[18]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SFEPD_PREDEF", melt_magic_discr((melt_ptr_t)(/*_.INST__V28*/ meltfptr[27])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V28*/ meltfptr[27]), (2), ((/*!konst_8_CLASS_REFERENCE*/ meltfrout->tabval[8])), "SFEPD_PREDEF");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V28*/ meltfptr[27], "newly made instance");
        ;
        /*_.SPREDCLASSCONT__V27*/
        meltfptr[26] = /*_.INST__V28*/ meltfptr[27];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6240:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!konst_8_CLASS_REFERENCE*/ meltfrout->tabval[8]);
            /*_.CLABIND__V29*/
            meltfptr[28] =  melt_apply ((meltclosure_ptr_t)((/*!FIND_ENV*/ meltfrout->tabval[9])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6241:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_FIELDASSIGN*/ meltfrout->tabval[11])), (4), "CLASS_SOURCE_FIELDASSIGN");
            /*_.INST__V31*/
            meltfptr[30] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V31*/ meltfptr[30])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V31*/ meltfptr[30]), (1), (/*_.LOC__V23*/ meltfptr[18]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SFLA_FIELD", melt_magic_discr((melt_ptr_t)(/*_.INST__V31*/ meltfptr[30])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V31*/ meltfptr[30]), (2), ((/*!REFERENCED_VALUE*/ meltfrout->tabval[12])), "SFLA_FIELD");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SFLA_EXPR", melt_magic_discr((melt_ptr_t)(/*_.INST__V31*/ meltfptr[30])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V31*/ meltfptr[30]), (3), (/*_.ARG2__V26*/ meltfptr[25]), "SFLA_EXPR");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V31*/ meltfptr[30], "newly made instance");
        ;
        /*_.INST___V30*/
        meltfptr[29] = /*_.INST__V31*/ meltfptr[30];;
        MELT_LOCATION("warmelt-macro.melt:6241:/ blockmultialloc");
        /*multiallocblock*/
        {
            struct meltletrec_1_st
            {
                struct MELT_MULTIPLE_STRUCT(1) rtup_0__TUPLREC__x8;
                long meltletrec_1_endgap;
            } *meltletrec_1_ptr = 0;
            meltletrec_1_ptr = (struct meltletrec_1_st *) meltgc_allocate (sizeof (struct meltletrec_1_st), 0);
            /*^blockmultialloc.initfill*/
            /*inimult rtup_0__TUPLREC__x8*/
            /*_.TUPLREC___V33*/
            meltfptr[32] = (melt_ptr_t) &meltletrec_1_ptr->rtup_0__TUPLREC__x8;
            meltletrec_1_ptr->rtup_0__TUPLREC__x8.discr = (meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_MULTIPLE))));
            meltletrec_1_ptr->rtup_0__TUPLREC__x8.nbval = 1;


            /*^putuple*/
            /*putupl#11*/
            melt_assertmsg("putupl [:6241] #11 checktup", melt_magic_discr((melt_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))== MELTOBMAG_MULTIPLE);
            melt_assertmsg("putupl [:6241] #11 checkoff", (0>=0 && 0< melt_multiple_length((melt_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))));
            ((meltmultiple_ptr_t)(/*_.TUPLREC___V33*/ meltfptr[32]))->tabval[0] = (melt_ptr_t)(/*_.INST___V30*/ meltfptr[29]);
            ;
            /*^touch*/
            meltgc_touch(/*_.TUPLREC___V33*/ meltfptr[32]);
            ;
            /*_.PUTUP__V32*/
            meltfptr[31] = /*_.TUPLREC___V33*/ meltfptr[32];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6241:/ clear");
            /*clear*/ /*_.TUPLREC___V33*/
            meltfptr[32] = 0 ;
            /*^clear*/
            /*clear*/ /*_.TUPLREC___V33*/
            meltfptr[32] = 0 ;
        } /*end multiallocblock*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6247:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_PUT_FIELDS*/ meltfrout->tabval[13])), (4), "CLASS_SOURCE_PUT_FIELDS");
            /*_.INST__V35*/
            meltfptr[34] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (1), (/*_.LOC__V23*/ meltfptr[18]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SUPUT_OBJ", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (2), (/*_.ARG1__V25*/ meltfptr[24]), "SUPUT_OBJ");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SUPUT_FIELDS", melt_magic_discr((melt_ptr_t)(/*_.INST__V35*/ meltfptr[34])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V35*/ meltfptr[34]), (3), (/*_.PUTUP__V32*/ meltfptr[31]), "SUPUT_FIELDS");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V35*/ meltfptr[34], "newly made instance");
        ;
        /*_.SPUT__V34*/
        meltfptr[32] = /*_.INST__V35*/ meltfptr[34];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6253:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L9*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)((/*!REFERENCED_VALUE*/ meltfrout->tabval[12])), (melt_ptr_t)((/*!CLASS_FIELD*/ meltfrout->tabval[14])));;
            MELT_LOCATION("warmelt-macro.melt:6253:/ cond");
            /*cond*/
            if (/*_#IS_A__L9*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V37*/ meltfptr[36] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6253:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check referenced_value";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6253;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &(/*!REFERENCED_VALUE*/ meltfrout->tabval[12]);
                            /*_.MELT_ASSERT_FAILURE_FUN__V38*/
                            meltfptr[37] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V37*/
                        meltfptr[36] = /*_.MELT_ASSERT_FAILURE_FUN__V38*/ meltfptr[37];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6253:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V38*/
                        meltfptr[37] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V36*/
            meltfptr[35] = /*_._IFELSE___V37*/ meltfptr[36];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6253:/ clear");
            /*clear*/ /*_#IS_A__L9*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V37*/
            meltfptr[36] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V36*/ meltfptr[35] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#exeqI__L10*/
        meltfnum[1] =
            ((/*_#NBARG__L8*/ meltfnum[0]) != (2));;
        MELT_LOCATION("warmelt-macro.melt:6254:/ cond");
        /*cond*/
        if (/*_#exeqI__L10*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6256:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V23*/ meltfptr[18]), ( "(SET_REF <ref> <value>) needs exactly two arguments"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6257:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6257:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6255:/ quasiblock");


                    /*_.PROGN___V41*/
                    meltfptr[40] = /*_.RETURN___V40*/ meltfptr[36];;
                    /*^compute*/
                    /*_._IF___V39*/
                    meltfptr[37] = /*_.PROGN___V41*/ meltfptr[40];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6254:/ clear");
                    /*clear*/ /*_.RETURN___V40*/
                    meltfptr[36] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V41*/
                    meltfptr[40] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V39*/ meltfptr[37] =  /*reallynil*/ NULL ;;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L11*/
        meltfnum[10] =
            ((/*_.CLABIND__V29*/ meltfptr[28]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6260:/ cond");
        /*cond*/
        if (/*_#NULL__L11*/ meltfnum[10]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6261:/ locexp");
                        melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V23*/ meltfptr[18]), ( "(SET_REF <ref> <value>) where CLASS_REFERENCE is not visible"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6262:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6262:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L12*/ meltfnum[11]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L13*/ meltfnum[12] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6262:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L13*/ meltfnum[12];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6262;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_set_ref returns sput";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SPUT__V34*/ meltfptr[32];
                            /*_.MELT_DEBUG_FUN__V43*/
                            meltfptr[40] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V42*/
                        meltfptr[36] = /*_.MELT_DEBUG_FUN__V43*/ meltfptr[40];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6262:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L13*/
                        meltfnum[12] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V43*/
                        meltfptr[40] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V42*/ meltfptr[36] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6262:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L12*/
            meltfnum[11] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V42*/
            meltfptr[36] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6263:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.SPUT__V34*/ meltfptr[32];;

        {
            MELT_LOCATION("warmelt-macro.melt:6263:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V21*/
        meltfptr[19] = /*_.RETURN___V44*/ meltfptr[40];;

        MELT_LOCATION("warmelt-macro.melt:6230:/ clear");
        /*clear*/ /*_.CONT__V22*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V23*/
        meltfptr[18] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NBARG__L8*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARG1__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARG2__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SPREDCLASSCONT__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CLABIND__V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_.INST___V30*/
        meltfptr[29] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PUTUP__V32*/
        meltfptr[31] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SPUT__V34*/
        meltfptr[32] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V36*/
        meltfptr[35] = 0 ;
        /*^clear*/
        /*clear*/ /*_#exeqI__L10*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V39*/
        meltfptr[37] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L11*/
        meltfnum[10] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V44*/
        meltfptr[40] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6221:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V21*/ meltfptr[19];;

        {
            MELT_LOCATION("warmelt-macro.melt:6221:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V17*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V21*/
        meltfptr[19] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_SET_REF", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_115_WARMELTmiMACRO_MEXPAND_SET_REF*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS fromline 1718 */

    /** start of frame for meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS// fromline 1534
        : public Melt_CallFrameWithValues<25>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[8];
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
        MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS), clos) {};
        MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS() //the constructor fromline 1608
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS)) {};
        MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS


    /** end of frame for meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS fromline 1663**/

    /* end of frame for routine meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS fromline 1722 */

    /* classy proc frame meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS */
    MeltFrame_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_PLUS", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6274:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6275:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6275:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6275:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6275;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_plus sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6275:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6275:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6276:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6276:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6276:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6276;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6276:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6276:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6277:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6277:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6277:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6277;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6277:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6277:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6278:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6279:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6280:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6281:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6282:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION*/ meltfrout->tabval[5])), (5), "CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_NEUTRAL", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (3), ((/*!konst_6*/ meltfrout->tabval[6])), "SARITHVAR_NEUTRAL");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_PRIMITIVE", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (4), ((/*!+I*/ meltfrout->tabval[7])), "SARITHVAR_PRIMITIVE");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V17*/ meltfptr[16])));;
        /*^compute*/
        /*_#eqeqI__L6*/
        meltfnum[0] =
            ((0) == (/*_#MULTIPLE_LENGTH__L5*/ meltfnum[1]));;
        MELT_LOCATION("warmelt-macro.melt:6289:/ cond");
        /*cond*/
        if (/*_#eqeqI__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6290:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V16*/ meltfptr[15]), ( "+ operator needs at least one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6291:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6291:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6289:/ quasiblock");


                    /*_.PROGN___V22*/
                    meltfptr[21] = /*_.RETURN___V21*/ meltfptr[20];;
                    /*^compute*/
                    /*_._IF___V20*/
                    meltfptr[19] = /*_.PROGN___V22*/ meltfptr[21];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6289:/ clear");
                    /*clear*/ /*_.RETURN___V21*/
                    meltfptr[20] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V22*/
                    meltfptr[21] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6292:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6292:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L7*/ meltfnum[6]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6292:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6292;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_plus result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V24*/
                            meltfptr[21] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V23*/
                        meltfptr[20] = /*_.MELT_DEBUG_FUN__V24*/ meltfptr[21];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6292:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L8*/
                        meltfnum[7] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V24*/
                        meltfptr[21] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V23*/ meltfptr[20] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6292:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V23*/
            meltfptr[20] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6293:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6293:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V25*/ meltfptr[21];;

        MELT_LOCATION("warmelt-macro.melt:6278:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_#eqeqI__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V25*/
        meltfptr[21] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6274:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6274:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_PLUS", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_116_WARMELTmiMACRO_MEXPAND_PLUS*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS fromline 1718 */

    /** start of frame for meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS// fromline 1534
        : public Melt_CallFrameWithValues<25>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[8];
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
        MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS), clos) {};
        MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS() //the constructor fromline 1608
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS)) {};
        MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS


    /** end of frame for meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS fromline 1663**/

    /* end of frame for routine meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS fromline 1722 */

    /* classy proc frame meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS */
    MeltFrame_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_MINUS", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6303:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6304:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6304:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6304:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6304;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_minus sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6304:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6304:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6305:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6305:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6305:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6305;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6305:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6305:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6306:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6306:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6306:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6306;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6306:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6306:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6307:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6308:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6309:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6310:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6311:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION*/ meltfrout->tabval[5])), (5), "CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_NEUTRAL", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (3), ((/*!konst_6*/ meltfrout->tabval[6])), "SARITHVAR_NEUTRAL");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_PRIMITIVE", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (4), ((/*!-I*/ meltfrout->tabval[7])), "SARITHVAR_PRIMITIVE");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V17*/ meltfptr[16])));;
        /*^compute*/
        /*_#eqeqI__L6*/
        meltfnum[0] =
            ((0) == (/*_#MULTIPLE_LENGTH__L5*/ meltfnum[1]));;
        MELT_LOCATION("warmelt-macro.melt:6318:/ cond");
        /*cond*/
        if (/*_#eqeqI__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6319:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V16*/ meltfptr[15]), ( "- operator needs at least one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6320:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6320:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6318:/ quasiblock");


                    /*_.PROGN___V22*/
                    meltfptr[21] = /*_.RETURN___V21*/ meltfptr[20];;
                    /*^compute*/
                    /*_._IF___V20*/
                    meltfptr[19] = /*_.PROGN___V22*/ meltfptr[21];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6318:/ clear");
                    /*clear*/ /*_.RETURN___V21*/
                    meltfptr[20] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V22*/
                    meltfptr[21] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6321:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6321:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L7*/ meltfnum[6]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6321:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6321;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_minus result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V24*/
                            meltfptr[21] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V23*/
                        meltfptr[20] = /*_.MELT_DEBUG_FUN__V24*/ meltfptr[21];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6321:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L8*/
                        meltfnum[7] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V24*/
                        meltfptr[21] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V23*/ meltfptr[20] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6321:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V23*/
            meltfptr[20] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6322:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6322:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V25*/ meltfptr[21];;

        MELT_LOCATION("warmelt-macro.melt:6307:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_#eqeqI__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V25*/
        meltfptr[21] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6303:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6303:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_MINUS", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_117_WARMELTmiMACRO_MEXPAND_MINUS*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES fromline 1718 */

    /** start of frame for meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES// fromline 1534
        : public Melt_CallFrameWithValues<25>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[8];
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
        MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES), clos) {};
        MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES() //the constructor fromline 1608
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES)) {};
        MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES


    /** end of frame for meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES fromline 1663**/

    /* end of frame for routine meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES fromline 1722 */

    /* classy proc frame meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES */
    MeltFrame_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_TIMES", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6332:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6333:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6333:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6333:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6333;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_times sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6333:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6333:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6334:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6334:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6334:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6334;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6334:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6334:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6335:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6335:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6335:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6335;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6335:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6335:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6336:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6337:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6338:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6339:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6340:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION*/ meltfrout->tabval[5])), (5), "CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_NEUTRAL", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (3), ((/*!konst_6*/ meltfrout->tabval[6])), "SARITHVAR_NEUTRAL");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_PRIMITIVE", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (4), ((/*!*I*/ meltfrout->tabval[7])), "SARITHVAR_PRIMITIVE");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V17*/ meltfptr[16])));;
        /*^compute*/
        /*_#eqeqI__L6*/
        meltfnum[0] =
            ((0) == (/*_#MULTIPLE_LENGTH__L5*/ meltfnum[1]));;
        MELT_LOCATION("warmelt-macro.melt:6347:/ cond");
        /*cond*/
        if (/*_#eqeqI__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6348:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V16*/ meltfptr[15]), ( "* operator needs at least one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6349:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6349:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6347:/ quasiblock");


                    /*_.PROGN___V22*/
                    meltfptr[21] = /*_.RETURN___V21*/ meltfptr[20];;
                    /*^compute*/
                    /*_._IF___V20*/
                    meltfptr[19] = /*_.PROGN___V22*/ meltfptr[21];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6347:/ clear");
                    /*clear*/ /*_.RETURN___V21*/
                    meltfptr[20] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V22*/
                    meltfptr[21] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6350:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6350:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L7*/ meltfnum[6]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6350:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6350;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_times result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V24*/
                            meltfptr[21] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V23*/
                        meltfptr[20] = /*_.MELT_DEBUG_FUN__V24*/ meltfptr[21];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6350:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L8*/
                        meltfnum[7] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V24*/
                        meltfptr[21] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V23*/ meltfptr[20] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6350:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V23*/
            meltfptr[20] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6351:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6351:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V25*/ meltfptr[21];;

        MELT_LOCATION("warmelt-macro.melt:6336:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_#eqeqI__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V25*/
        meltfptr[21] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6332:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6332:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_TIMES", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_118_WARMELTmiMACRO_MEXPAND_TIMES*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_119_WARMELTmiMACRO_MEXPAND_DIV(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_119_WARMELTmiMACRO_MEXPAND_DIV fromline 1718 */

    /** start of frame for meltrout_119_WARMELTmiMACRO_MEXPAND_DIV of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV// fromline 1534
        : public Melt_CallFrameWithValues<25>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[8];
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
        MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV), clos) {};
        MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV() //the constructor fromline 1608
            : Melt_CallFrameWithValues<25> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV)) {};
        MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<25> (fil,lin, sizeof(MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV


    /** end of frame for meltrout_119_WARMELTmiMACRO_MEXPAND_DIV fromline 1663**/

    /* end of frame for routine meltrout_119_WARMELTmiMACRO_MEXPAND_DIV fromline 1722 */

    /* classy proc frame meltrout_119_WARMELTmiMACRO_MEXPAND_DIV */
    MeltFrame_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_119_WARMELTmiMACRO_MEXPAND_DIV fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_DIV", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6361:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6362:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6362:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6362:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6362;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_div sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6362:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6362:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6363:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6363:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6363:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6363;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6363:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6363:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6364:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6364:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6364:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6364;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6364:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6364:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6365:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6366:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6367:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6368:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6369:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION*/ meltfrout->tabval[5])), (5), "CLASS_SOURCE_ARITHMETIC_VARIADIC_OPERATION");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_NEUTRAL", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (3), ((/*!konst_6*/ meltfrout->tabval[6])), "SARITHVAR_NEUTRAL");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARITHVAR_PRIMITIVE", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (4), ((/*!/I*/ meltfrout->tabval[7])), "SARITHVAR_PRIMITIVE");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.XARGTUP__V17*/ meltfptr[16])));;
        /*^compute*/
        /*_#eqeqI__L6*/
        meltfnum[0] =
            ((0) == (/*_#MULTIPLE_LENGTH__L5*/ meltfnum[1]));;
        MELT_LOCATION("warmelt-macro.melt:6376:/ cond");
        /*cond*/
        if (/*_#eqeqI__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6377:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V16*/ meltfptr[15]), ( "/ operator needs at least one argument"), (melt_ptr_t)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6378:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] =  /*reallynil*/ NULL ;;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6378:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    MELT_LOCATION("warmelt-macro.melt:6376:/ quasiblock");


                    /*_.PROGN___V22*/
                    meltfptr[21] = /*_.RETURN___V21*/ meltfptr[20];;
                    /*^compute*/
                    /*_._IF___V20*/
                    meltfptr[19] = /*_.PROGN___V22*/ meltfptr[21];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6376:/ clear");
                    /*clear*/ /*_.RETURN___V21*/
                    meltfptr[20] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PROGN___V22*/
                    meltfptr[21] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6379:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6379:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L7*/ meltfnum[6]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L8*/ meltfnum[7] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6379:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L8*/ meltfnum[7];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6379;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_div result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V24*/
                            meltfptr[21] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V23*/
                        meltfptr[20] = /*_.MELT_DEBUG_FUN__V24*/ meltfptr[21];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6379:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L8*/
                        meltfnum[7] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V24*/
                        meltfptr[21] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V23*/ meltfptr[20] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6379:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L7*/
            meltfnum[6] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V23*/
            meltfptr[20] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6380:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6380:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V25*/ meltfptr[21];;

        MELT_LOCATION("warmelt-macro.melt:6365:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_#MULTIPLE_LENGTH__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_#eqeqI__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V25*/
        meltfptr[21] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6361:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6361:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_DIV", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_119_WARMELTmiMACRO_MEXPAND_DIV_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_119_WARMELTmiMACRO_MEXPAND_DIV*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE fromline 1718 */

    /** start of frame for meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE// fromline 1534
        : public Melt_CallFrameWithValues<22>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[6];
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
        MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<22> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE), clos) {};
        MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE() //the constructor fromline 1608
            : Melt_CallFrameWithValues<22> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<22> (fil,lin, sizeof(MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE)) {};
        MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<22> (fil,lin, sizeof(MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE


    /** end of frame for meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE fromline 1663**/

    /* end of frame for routine meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE fromline 1722 */

    /* classy proc frame meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE */
    MeltFrame_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_TUPLE", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6390:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6391:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6391:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6391:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6391;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_tuple sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6391:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6391:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6392:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6392:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6392:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6392;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6392:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6392:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6393:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6393:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6393:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6393;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6393:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6393:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6394:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6395:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6396:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6397:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6398:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_TUPLE*/ meltfrout->tabval[5])), (3), "CLASS_SOURCE_TUPLE");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6402:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L5*/
            meltfnum[1] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6402:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L6*/ meltfnum[0] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6402:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[0];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6402;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_tuple result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V21*/
                            meltfptr[20] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V20*/
                        meltfptr[19] = /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6402:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L6*/
                        meltfnum[0] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V21*/
                        meltfptr[20] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6402:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V20*/
            meltfptr[19] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6403:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6403:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V22*/ meltfptr[20];;

        MELT_LOCATION("warmelt-macro.melt:6394:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V22*/
        meltfptr[20] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6390:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6390:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_TUPLE", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_120_WARMELTmiMACRO_MEXPAND_TUPLE*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE fromline 1718 */

    /** start of frame for meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE// fromline 1534
        : public Melt_CallFrameWithValues<26>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[7];
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
        MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<26> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE), clos) {};
        MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE() //the constructor fromline 1608
            : Melt_CallFrameWithValues<26> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<26> (fil,lin, sizeof(MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE)) {};
        MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<26> (fil,lin, sizeof(MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE


    /** end of frame for meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE fromline 1663**/

    /* end of frame for routine meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE fromline 1722 */

    /* classy proc frame meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE */
    MeltFrame_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("PATEXPAND_TUPLE", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6407:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.PCTX__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6408:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6408:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6408:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6408;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_tuple sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V6*/
                            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V5*/
                        meltfptr[4] = /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6408:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V6*/
                        meltfptr[5] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V5*/ meltfptr[4] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6408:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V5*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6409:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6409:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V8*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6409:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6409;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                            meltfptr[8] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V8*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V9*/ meltfptr[8];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6409:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                        meltfptr[8] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V7*/
            meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6409:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V8*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V7*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6410:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6410:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V11*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6410:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6410;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                            meltfptr[11] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V11*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V12*/ meltfptr[11];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6410:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                        meltfptr[11] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V10*/
            meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6410:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V11*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V10*/ meltfptr[8] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6411:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L5*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3]), (melt_ptr_t)((/*!CLASS_PATTERN_EXPANSION_CONTEXT*/ meltfrout->tabval[4])));;
            MELT_LOCATION("warmelt-macro.melt:6411:/ cond");
            /*cond*/
            if (/*_#IS_A__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V14*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6411:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check pctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6411;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
                            /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                            meltfptr[14] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V14*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V15*/ meltfptr[14];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6411:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                        meltfptr[14] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V13*/
            meltfptr[11] = /*_._IFELSE___V14*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6411:/ clear");
            /*clear*/ /*_#IS_A__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V14*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V13*/ meltfptr[11] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6412:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6413:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V17*/
            meltfptr[4] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6414:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V18*/
            meltfptr[17] = slot;
        };
        ;
        /*_.LIST_FIRST__V19*/
        meltfptr[18] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V17*/ meltfptr[4])));;
        /*^compute*/
        /*_.CURPAIR__V20*/
        meltfptr[19] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V19*/ meltfptr[18])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6416:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.LOC__V18*/ meltfptr[17];
            /*_.ARGSP__V21*/
            meltfptr[20] =  melt_apply ((meltclosure_ptr_t)((/*!PATTERNEXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.CURPAIR__V20*/ meltfptr[19]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6417:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_PATTERN_TUPLE*/ meltfrout->tabval[6])), (4), "CLASS_SOURCE_PATTERN_TUPLE");
            /*_.INST__V23*/
            meltfptr[22] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V23*/ meltfptr[22])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V23*/ meltfptr[22]), (1), (/*_.LOC__V18*/ meltfptr[17]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @CTPAT_SUBPA", melt_magic_discr((melt_ptr_t)(/*_.INST__V23*/ meltfptr[22])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V23*/ meltfptr[22]), (3), (/*_.ARGSP__V21*/ meltfptr[20]), "CTPAT_SUBPA");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V23*/ meltfptr[22], "newly made instance");
        ;
        /*_.RES__V22*/
        meltfptr[21] = /*_.INST__V23*/ meltfptr[22];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6421:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L6*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6421:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L6*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6421:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6421;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_tuple res";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V22*/ meltfptr[21];
                            /*_.MELT_DEBUG_FUN__V25*/
                            meltfptr[24] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V24*/
                        meltfptr[23] = /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6421:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L7*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V25*/
                        meltfptr[24] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V24*/ meltfptr[23] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6421:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V24*/
            meltfptr[23] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6422:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V22*/ meltfptr[21];;

        {
            MELT_LOCATION("warmelt-macro.melt:6422:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V16*/
        meltfptr[14] = /*_.RETURN___V26*/ meltfptr[24];;

        MELT_LOCATION("warmelt-macro.melt:6412:/ clear");
        /*clear*/ /*_.CONT__V17*/
        meltfptr[4] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V19*/
        meltfptr[18] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CURPAIR__V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARGSP__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V26*/
        meltfptr[24] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6407:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V16*/ meltfptr[14];;

        {
            MELT_LOCATION("warmelt-macro.melt:6407:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V7*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V10*/
        meltfptr[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V13*/
        meltfptr[11] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V16*/
        meltfptr[14] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("PATEXPAND_TUPLE", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_121_WARMELTmiMACRO_PATEXPAND_TUPLE*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_122_WARMELTmiMACRO_MEXPAND_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_122_WARMELTmiMACRO_MEXPAND_LIST fromline 1718 */

    /** start of frame for meltrout_122_WARMELTmiMACRO_MEXPAND_LIST of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST// fromline 1534
        : public Melt_CallFrameWithValues<22>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[6];
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
        MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<22> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST), clos) {};
        MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST() //the constructor fromline 1608
            : Melt_CallFrameWithValues<22> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<22> (fil,lin, sizeof(MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST)) {};
        MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<22> (fil,lin, sizeof(MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST


    /** end of frame for meltrout_122_WARMELTmiMACRO_MEXPAND_LIST fromline 1663**/

    /* end of frame for routine meltrout_122_WARMELTmiMACRO_MEXPAND_LIST fromline 1722 */

    /* classy proc frame meltrout_122_WARMELTmiMACRO_MEXPAND_LIST */
    MeltFrame_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_122_WARMELTmiMACRO_MEXPAND_LIST fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_LIST", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6436:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6437:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6437:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6437:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6437;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_list sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6437:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6437:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6438:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6438:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6438:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6438;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6438:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6438:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6439:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6439:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6439:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6439;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6439:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6439:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6440:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6441:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V15*/
            meltfptr[5] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6442:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V16*/
            meltfptr[15] = slot;
        };
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6443:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.XARGTUP__V17*/
            meltfptr[16] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_RESTLIST_AS_TUPLE*/ meltfrout->tabval[4])), (melt_ptr_t)(/*_.CONT__V15*/ meltfptr[5]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6444:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_LIST*/ meltfrout->tabval[5])), (3), "CLASS_SOURCE_LIST");
            /*_.INST__V19*/
            meltfptr[18] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (1), (/*_.LOC__V16*/ meltfptr[15]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SARGOP_ARGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V19*/ meltfptr[18])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V19*/ meltfptr[18]), (2), (/*_.XARGTUP__V17*/ meltfptr[16]), "SARGOP_ARGS");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V19*/ meltfptr[18], "newly made instance");
        ;
        /*_.RES__V18*/
        meltfptr[17] = /*_.INST__V19*/ meltfptr[18];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6448:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L5*/
            meltfnum[1] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6448:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L6*/ meltfnum[0] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6448:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L6*/ meltfnum[0];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6448;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_list result";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V18*/ meltfptr[17];
                            /*_.MELT_DEBUG_FUN__V21*/
                            meltfptr[20] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V20*/
                        meltfptr[19] = /*_.MELT_DEBUG_FUN__V21*/ meltfptr[20];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6448:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L6*/
                        meltfnum[0] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V21*/
                        meltfptr[20] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V20*/ meltfptr[19] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6448:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V20*/
            meltfptr[19] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6449:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V18*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6449:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V14*/
        meltfptr[12] = /*_.RETURN___V22*/ meltfptr[20];;

        MELT_LOCATION("warmelt-macro.melt:6440:/ clear");
        /*clear*/ /*_.CONT__V15*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V16*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.XARGTUP__V17*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V22*/
        meltfptr[20] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6436:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V14*/ meltfptr[12];;

        {
            MELT_LOCATION("warmelt-macro.melt:6436:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V14*/
        meltfptr[12] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_LIST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_122_WARMELTmiMACRO_MEXPAND_LIST_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_122_WARMELTmiMACRO_MEXPAND_LIST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST fromline 1718 */

    /** start of frame for meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST// fromline 1534
        : public Melt_CallFrameWithValues<26>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[7];
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
        MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<26> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST), clos) {};
        MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST() //the constructor fromline 1608
            : Melt_CallFrameWithValues<26> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<26> (fil,lin, sizeof(MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST)) {};
        MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<26> (fil,lin, sizeof(MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST


    /** end of frame for meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST fromline 1663**/

    /* end of frame for routine meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST fromline 1722 */

    /* classy proc frame meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST */
    MeltFrame_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("PATEXPAND_LIST", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6453:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.PCTX__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6454:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6454:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6454:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6454;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_list sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V6*/
                            meltfptr[5] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V5*/
                        meltfptr[4] = /*_.MELT_DEBUG_FUN__V6*/ meltfptr[5];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6454:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V6*/
                        meltfptr[5] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V5*/ meltfptr[4] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6454:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V5*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6455:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6455:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V8*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6455:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6455;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                            meltfptr[8] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V8*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V9*/ meltfptr[8];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6455:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V9*/
                        meltfptr[8] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V7*/
            meltfptr[5] = /*_._IFELSE___V8*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6455:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V8*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V7*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6456:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6456:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V11*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6456:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6456;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                            meltfptr[11] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V11*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V12*/ meltfptr[11];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6456:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V12*/
                        meltfptr[11] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V10*/
            meltfptr[8] = /*_._IFELSE___V11*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6456:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V11*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V10*/ meltfptr[8] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6457:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L5*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.PCTX__V4*/ meltfptr[3]), (melt_ptr_t)((/*!CLASS_PATTERN_EXPANSION_CONTEXT*/ meltfrout->tabval[4])));;
            MELT_LOCATION("warmelt-macro.melt:6457:/ cond");
            /*cond*/
            if (/*_#IS_A__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V14*/ meltfptr[4] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6457:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check pctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6457;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
                            /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                            meltfptr[14] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V14*/
                        meltfptr[4] = /*_.MELT_ASSERT_FAILURE_FUN__V15*/ meltfptr[14];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6457:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V15*/
                        meltfptr[14] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V13*/
            meltfptr[11] = /*_._IFELSE___V14*/ meltfptr[4];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6457:/ clear");
            /*clear*/ /*_#IS_A__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V14*/
            meltfptr[4] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V13*/ meltfptr[11] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6458:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6459:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V17*/
            meltfptr[4] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6460:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V18*/
            meltfptr[17] = slot;
        };
        ;
        /*_.LIST_FIRST__V19*/
        meltfptr[18] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V17*/ meltfptr[4])));;
        /*^compute*/
        /*_.CURPAIR__V20*/
        meltfptr[19] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V19*/ meltfptr[18])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6462:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.PCTX__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.LOC__V18*/ meltfptr[17];
            /*_.ARGSP__V21*/
            meltfptr[20] =  melt_apply ((meltclosure_ptr_t)((/*!PATTERNEXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.CURPAIR__V20*/ meltfptr[19]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6463:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_PATTERN_LIST*/ meltfrout->tabval[6])), (4), "CLASS_SOURCE_PATTERN_LIST");
            /*_.INST__V23*/
            meltfptr[22] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V23*/ meltfptr[22])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V23*/ meltfptr[22]), (1), (/*_.LOC__V18*/ meltfptr[17]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @CTPAT_SUBPA", melt_magic_discr((melt_ptr_t)(/*_.INST__V23*/ meltfptr[22])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V23*/ meltfptr[22]), (3), (/*_.ARGSP__V21*/ meltfptr[20]), "CTPAT_SUBPA");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V23*/ meltfptr[22], "newly made instance");
        ;
        /*_.RES__V22*/
        meltfptr[21] = /*_.INST__V23*/ meltfptr[22];;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6467:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L6*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6467:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L6*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L7*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6467:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L7*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6467;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "patexpand_list res";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RES__V22*/ meltfptr[21];
                            /*_.MELT_DEBUG_FUN__V25*/
                            meltfptr[24] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V24*/
                        meltfptr[23] = /*_.MELT_DEBUG_FUN__V25*/ meltfptr[24];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6467:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L7*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V25*/
                        meltfptr[24] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V24*/ meltfptr[23] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6467:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V24*/
            meltfptr[23] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6468:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RES__V22*/ meltfptr[21];;

        {
            MELT_LOCATION("warmelt-macro.melt:6468:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V16*/
        meltfptr[14] = /*_.RETURN___V26*/ meltfptr[24];;

        MELT_LOCATION("warmelt-macro.melt:6458:/ clear");
        /*clear*/ /*_.CONT__V17*/
        meltfptr[4] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V18*/
        meltfptr[17] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V19*/
        meltfptr[18] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CURPAIR__V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.ARGSP__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RES__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V26*/
        meltfptr[24] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6453:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V16*/ meltfptr[14];;

        {
            MELT_LOCATION("warmelt-macro.melt:6453:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V7*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V10*/
        meltfptr[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V13*/
        meltfptr[11] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V16*/
        meltfptr[14] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("PATEXPAND_LIST", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_123_WARMELTmiMACRO_PATEXPAND_LIST*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH fromline 1718 */

    /** start of frame for meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH// fromline 1534
        : public Melt_CallFrameWithValues<77>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[27];
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
        MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<77> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH), clos) {};
        MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH() //the constructor fromline 1608
            : Melt_CallFrameWithValues<77> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<77> (fil,lin, sizeof(MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH)) {};
        MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<77> (fil,lin, sizeof(MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH


    /** end of frame for meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH fromline 1663**/

    /* end of frame for routine meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH fromline 1722 */

    /* classy proc frame meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH */
    MeltFrame_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_MATCH", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6483:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6484:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6484:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6484:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6484;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_match sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6484:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6484:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6485:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6485:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6485:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6485;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6485:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6485:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6486:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6486:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6486:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6486;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6486:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6486:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6487:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L5*/
            meltfnum[1] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6487:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V15*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6487:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6487;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                            meltfptr[15] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V15*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V16*/ meltfptr[15];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6487:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                        meltfptr[15] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V14*/
            meltfptr[12] = /*_._IFELSE___V15*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6487:/ clear");
            /*clear*/ /*_#IS_OBJECT__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V15*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V14*/ meltfptr[12] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L6*/
        meltfnum[0] =
            ((/*_.MEXPANDER__V4*/ meltfptr[3]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6488:/ cond");
        /*cond*/
        if (/*_#NULL__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    /*^compute*/
                    /*_.MEXPANDER__V4*/ meltfptr[3] = /*_.SETQ___V18*/ meltfptr[5] = (/*!MACROEXPAND_1*/ meltfrout->tabval[4]);;
                    /*_._IF___V17*/
                    meltfptr[15] = /*_.SETQ___V18*/ meltfptr[5];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6488:/ clear");
                    /*clear*/ /*_.SETQ___V18*/
                    meltfptr[5] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V17*/ meltfptr[15] =  /*reallynil*/ NULL ;;
            }
        ;
        MELT_LOCATION("warmelt-macro.melt:6489:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6490:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V20*/
            meltfptr[19] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6491:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V21*/
            meltfptr[20] = slot;
        };
        ;
        /*_.LIST_FIRST__V22*/
        meltfptr[21] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[19])));;
        /*^compute*/
        /*_.PAIR_TAIL__V23*/
        meltfptr[22] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V22*/ meltfptr[21])));;
        /*^compute*/
        /*_.MSEXP__V24*/
        meltfptr[23] =
            (melt_pair_head((melt_ptr_t)(/*_.PAIR_TAIL__V23*/ meltfptr[22])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6493:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.MATSX__V25*/
            meltfptr[24] =  melt_apply ((meltclosure_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3]), (melt_ptr_t)(/*_.MSEXP__V24*/ meltfptr[23]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_.LIST_FIRST__V26*/
        meltfptr[25] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[19])));;
        /*^compute*/
        /*_.PAIR_TAIL__V27*/
        meltfptr[26] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V26*/ meltfptr[25])));;
        /*^compute*/
        /*_.PAIR_TAIL__V28*/
        meltfptr[27] =
            (melt_pair_tail((melt_ptr_t)(/*_.PAIR_TAIL__V27*/ meltfptr[26])));;
        MELT_LOCATION("warmelt-macro.melt:6497:/ quasiblock");


        /*^newclosure*/
        /*newclosure*/ /*_.LAMBDA___V30*/
        meltfptr[29] =
            (melt_ptr_t) meltgc_new_closure((meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_CLOSURE)))), (meltroutine_ptr_t)((/*!konst_8*/ meltfrout->tabval[8])), (1));
        ;
        /*^putclosedv*/
        /*putclosv*/
        melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V30*/ meltfptr[29])) == MELTOBMAG_CLOSURE);
        melt_assertmsg("putclosv checkoff", 0>= 0 && 0< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V30*/ meltfptr[29])));
        ((meltclosure_ptr_t)/*_.LAMBDA___V30*/ meltfptr[29])->tabval[0] = (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]);
        ;
        /*_.LAMBDA___V29*/
        meltfptr[28] = /*_.LAMBDA___V30*/ meltfptr[29];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6494:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[2];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[6]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.LAMBDA___V29*/ meltfptr[28];
            /*_.MEXPTUPLE__V31*/
            meltfptr[30] =  melt_apply ((meltclosure_ptr_t)((/*!PAIRLIST_TO_MULTIPLE*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.PAIR_TAIL__V28*/ meltfptr[27]), (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_#NBMATCH__L7*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30])));;
        MELT_LOCATION("warmelt-macro.melt:6503:/ quasiblock");


        /*_.LX__V33*/
        meltfptr[32] =
            (melt_multiple_nth((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30]), (-1)));;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6504:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6504:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L8*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L9*/ meltfnum[8] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6504:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6504;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_match lastmexp lx";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.LX__V33*/ meltfptr[32];
                            /*_.MELT_DEBUG_FUN__V35*/
                            meltfptr[34] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V34*/
                        meltfptr[33] = /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6504:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L9*/
                        meltfnum[8] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V35*/
                        meltfptr[34] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V34*/ meltfptr[33] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6504:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V34*/
            meltfptr[33] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        /*_.LET___V32*/
        meltfptr[31] = /*_.LX__V33*/ meltfptr[32];;

        MELT_LOCATION("warmelt-macro.melt:6503:/ clear");
        /*clear*/ /*_.LX__V33*/
        meltfptr[32] = 0 ;
        /*_.LASTMEXP__V36*/
        meltfptr[34] = /*_.LET___V32*/ meltfptr[31];;
        /*^compute*/
        /*_#IX__L10*/
        meltfnum[8] =
            ((/*_#NBMATCH__L7*/ meltfnum[1]) - (1));;
        /*^compute*/
        /*_.CASELIST__V37*/
        meltfptr[33] =
            (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[9]))));;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6509:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L11*/
            meltfnum[7] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6509:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L11*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L12*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6509:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L12*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6509;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_match mexptuple";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPTUPLE__V31*/ meltfptr[30];
                            /*_.MELT_DEBUG_FUN__V39*/
                            meltfptr[38] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V38*/
                        meltfptr[32] = /*_.MELT_DEBUG_FUN__V39*/ meltfptr[38];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6509:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L12*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V39*/
                        meltfptr[38] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V38*/ meltfptr[32] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6509:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L11*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V38*/
            meltfptr[32] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6510:/ loop");
        /*loop*/
        {
meltlabloop_MATCHLOOP_1:;/*^loopbody*/

            /*^block*/
            /*anyblock*/
            {


                MELT_CHECK_SIGNAL();
                ;

                MELT_CHECK_SIGNAL();
                ;
                /*_#ltI__L13*/
                meltfnum[11] =
                    ((/*_#IX__L10*/ meltfnum[8]) < (0));;
                MELT_LOCATION("warmelt-macro.melt:6511:/ cond");
                /*cond*/
                if (/*_#ltI__L13*/ meltfnum[11]) /*then*/
                    {
                        /*^cond.then*/
                        /*^block*/
                        /*anyblock*/
                        {

                            /*^quasiblock*/


                            /*^compute*/
                            /*_.MATCHLOOP__V41*/ meltfptr[32] =  /*reallynil*/ NULL ;;

                            /*^exit*/
                            /*exit*/
                            {
                                goto meltlabexit_MATCHLOOP_1;
                            }
                            ;
                            /*epilog*/
                        }
                        ;
                    } /*noelse*/
                ;
                MELT_LOCATION("warmelt-macro.melt:6512:/ quasiblock");


                /*_.CURMATCH__V42*/
                meltfptr[41] =
                    (melt_multiple_nth((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30]), (/*_#IX__L10*/ meltfnum[8])));;

#if MELT_HAVE_DEBUG
                MELT_LOCATION("warmelt-macro.melt:6513:/ cppif.then");
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                        melt_dbgcounter++;
#endif
                        ;
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#MELT_NEED_DBG__L14*/
                    meltfnum[7] =
                        /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                        (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                        0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                        ;;
                    MELT_LOCATION("warmelt-macro.melt:6513:/ cond");
                    /*cond*/
                    if (/*_#MELT_NEED_DBG__L14*/ meltfnum[7]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_#MELT_CALLCOUNT__L15*/ meltfnum[14] =
                                    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                    meltcallcount  /* melt_callcount debugging */
#else
                                    0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                    ;;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6513:/ apply");
                                /*apply*/
                                {
                                    union meltparam_un argtab[5];
                                    memset(&argtab, 0, sizeof(argtab));
                                    /*^apply.arg*/
                                    argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L15*/ meltfnum[14];
                                    /*^apply.arg*/
                                    argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                    /*^apply.arg*/
                                    argtab[2].meltbp_long = 6513;
                                    /*^apply.arg*/
                                    argtab[3].meltbp_cstring =  "mexpand_match curmatch";
                                    /*^apply.arg*/
                                    argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CURMATCH__V42*/ meltfptr[41];
                                    /*_.MELT_DEBUG_FUN__V44*/
                                    meltfptr[43] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                }
                                ;
                                /*_._IF___V43*/
                                meltfptr[42] = /*_.MELT_DEBUG_FUN__V44*/ meltfptr[43];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6513:/ clear");
                                /*clear*/ /*_#MELT_CALLCOUNT__L15*/
                                meltfnum[14] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MELT_DEBUG_FUN__V44*/
                                meltfptr[43] = 0 ;
                            }
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_._IF___V43*/ meltfptr[42] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6513:/ locexp");
                        /*void*/
                        (void)0;
                    }
                    ;
                    /*^quasiblock*/


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_#MELT_NEED_DBG__L14*/
                    meltfnum[7] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IF___V43*/
                    meltfptr[42] = 0 ;
                }

#else /*MELT_HAVE_DEBUG*/
                /*^cppif.else*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        /*void*/(void)0;
                    }
                    ;
                    /*epilog*/
                }

#endif /*MELT_HAVE_DEBUG*/
                ;

                MELT_CHECK_SIGNAL();
                ;
                /*_#IS_A__L16*/
                meltfnum[14] =
                    melt_is_instance_of((melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
                MELT_LOCATION("warmelt-macro.melt:6516:/ cond");
                /*cond*/
                if (/*_#IS_A__L16*/ meltfnum[14]) /*then*/
                    {
                        /*^cond.then*/
                        /*^block*/
                        /*anyblock*/
                        {

                            MELT_LOCATION("warmelt-macro.melt:6517:/ quasiblock");


                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
                                /*_.CURMATCHCONT__V45*/
                                meltfptr[43] = slot;
                            };
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6518:/ getslot");
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]) /*=obj*/;
                                melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                                /*_.CURMATCHLOC__V46*/
                                meltfptr[42] = slot;
                            };
                            ;
                            /*_.LIST_FIRST__V47*/
                            meltfptr[46] =
                                (melt_list_first((melt_ptr_t)(/*_.CURMATCHCONT__V45*/ meltfptr[43])));;
                            /*^compute*/
                            /*_.CURMATCHPATX__V48*/
                            meltfptr[47] =
                                (melt_pair_head((melt_ptr_t)(/*_.LIST_FIRST__V47*/ meltfptr[46])));;
                            /*^compute*/
                            /*_.LIST_FIRST__V49*/
                            meltfptr[48] =
                                (melt_list_first((melt_ptr_t)(/*_.CURMATCHCONT__V45*/ meltfptr[43])));;
                            /*^compute*/
                            /*_.CURMATCHRESTPAIRS__V50*/
                            meltfptr[49] =
                                (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V49*/ meltfptr[48])));;

                            MELT_CHECK_SIGNAL();
                            ;
                            /*^compute*/
                            /*_.MAKE_MAPOBJECT__V51*/
                            meltfptr[50] =
                                (meltgc_new_mapobjects( (meltobject_ptr_t) ((/*!DISCR_MAP_OBJECTS*/ meltfrout->tabval[12])), (17)));;
                            MELT_LOCATION("warmelt-macro.melt:6521:/ quasiblock");


                            /*^rawallocobj*/
                            /*rawallocobj*/
                            {
                                melt_ptr_t newobj = 0;
                                melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_PATTERN_EXPANSION_CONTEXT*/ meltfrout->tabval[10])), (4), "CLASS_PATTERN_EXPANSION_CONTEXT");
                                /*_.INST__V53*/
                                meltfptr[52] =
                                    newobj;
                            };
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_MEXPANDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (0), (/*_.MEXPANDER__V4*/ meltfptr[3]), "PCTX_MEXPANDER");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_PEXPANDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (1), ((/*!PATTERNEXPAND_1*/ meltfrout->tabval[11])), "PCTX_PEXPANDER");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_VARMAP", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (2), (/*_.MAKE_MAPOBJECT__V51*/ meltfptr[50]), "PCTX_VARMAP");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_MODCTX", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (3), (/*_.MODCTX__V5*/ meltfptr[4]), "PCTX_MODCTX");
                            ;
                            /*^touchobj*/

                            melt_dbgtrace_written_object (/*_.INST__V53*/ meltfptr[52], "newly made instance");
                            ;
                            /*_.CURPATCTX__V52*/
                            meltfptr[51] = /*_.INST__V53*/ meltfptr[52];;
                            MELT_LOCATION("warmelt-macro.melt:6527:/ quasiblock");



                            MELT_CHECK_SIGNAL();
                            ;
                            /*^apply*/
                            /*apply*/
                            {
                                union meltparam_un argtab[3];
                                memset(&argtab, 0, sizeof(argtab));
                                /*^apply.arg*/
                                argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                                /*^apply.arg*/
                                argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.CURPATCTX__V52*/ meltfptr[51];
                                /*^apply.arg*/
                                argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.CURMATCHLOC__V46*/ meltfptr[42];
                                /*_.CP__V55*/
                                meltfptr[54] =  melt_apply ((meltclosure_ptr_t)((/*!PATTERNEXPAND_1*/ meltfrout->tabval[11])), (melt_ptr_t)(/*_.CURMATCHPATX__V48*/ meltfptr[47]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                            }
                            ;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6528:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                                    melt_dbgcounter++;
#endif
                                    ;
                                }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_#MELT_NEED_DBG__L17*/
                                meltfnum[7] =
                                    /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                                    (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                                    0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                                    ;;
                                MELT_LOCATION("warmelt-macro.melt:6528:/ cond");
                                /*cond*/
                                if (/*_#MELT_NEED_DBG__L17*/ meltfnum[7]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*_#MELT_CALLCOUNT__L18*/ meltfnum[17] =
                                                /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                                meltcallcount  /* melt_callcount debugging */
#else
                                                0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                                ;;

                                            MELT_CHECK_SIGNAL();
                                            ;
                                            MELT_LOCATION("warmelt-macro.melt:6528:/ apply");
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[5];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[17];
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6528;
                                                /*^apply.arg*/
                                                argtab[3].meltbp_cstring =  "mexpand_match curpat";
                                                /*^apply.arg*/
                                                argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CP__V55*/ meltfptr[54];
                                                /*_.MELT_DEBUG_FUN__V57*/
                                                meltfptr[56] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IF___V56*/
                                            meltfptr[55] = /*_.MELT_DEBUG_FUN__V57*/ meltfptr[56];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6528:/ clear");
                                            /*clear*/ /*_#MELT_CALLCOUNT__L18*/
                                            meltfnum[17] = 0 ;
                                            /*^clear*/
                                            /*clear*/ /*_.MELT_DEBUG_FUN__V57*/
                                            meltfptr[56] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IF___V56*/ meltfptr[55] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                {
                                    MELT_LOCATION("warmelt-macro.melt:6528:/ locexp");
                                    /*void*/
                                    (void)0;
                                }
                                ;
                                /*^quasiblock*/


                                /*epilog*/

                                /*^clear*/
                                /*clear*/ /*_#MELT_NEED_DBG__L17*/
                                meltfnum[7] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IF___V56*/
                                meltfptr[55] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*void*/(void)0;
                                }
                                ;
                                /*epilog*/
                            }

#endif /*MELT_HAVE_DEBUG*/
                            ;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6529:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                MELT_CHECK_SIGNAL();
                                ;
                                /*^cond*/
                                /*cond*/
                                if (/*_.CP__V55*/ meltfptr[54]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*_._IFELSE___V59*/ meltfptr[55] = (/*nil*/NULL);;
                                    }
                                else
                                    {
                                        MELT_LOCATION("warmelt-macro.melt:6529:/ cond.else");

                                        /*^block*/
                                        /*anyblock*/
                                        {


                                            MELT_CHECK_SIGNAL();
                                            ;
                                            /*^apply*/
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[3];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_cstring =  "check curpat";
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6529;
                                                /*_.MELT_ASSERT_FAILURE_FUN__V60*/
                                                meltfptr[59] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IFELSE___V59*/
                                            meltfptr[55] = /*_.MELT_ASSERT_FAILURE_FUN__V60*/ meltfptr[59];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6529:/ clear");
                                            /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V60*/
                                            meltfptr[59] = 0 ;
                                        }
                                        ;
                                    }
                                ;
                                /*_.IFCPP___V58*/
                                meltfptr[56] = /*_._IFELSE___V59*/ meltfptr[55];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6529:/ clear");
                                /*clear*/ /*_._IFELSE___V59*/
                                meltfptr[55] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*_.IFCPP___V58*/ meltfptr[56] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
                            ;
                            /*^compute*/
                            /*_.LET___V54*/
                            meltfptr[53] = /*_.CP__V55*/ meltfptr[54];;

                            MELT_LOCATION("warmelt-macro.melt:6527:/ clear");
                            /*clear*/ /*_.CP__V55*/
                            meltfptr[54] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.IFCPP___V58*/
                            meltfptr[56] = 0 ;
                            /*_.CURPAT__V61*/
                            meltfptr[59] = /*_.LET___V54*/ meltfptr[53];;

                            MELT_CHECK_SIGNAL();
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6531:/ apply");
                            /*apply*/
                            {
                                union meltparam_un argtab[3];
                                memset(&argtab, 0, sizeof(argtab));
                                /*^apply.arg*/
                                argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                                /*^apply.arg*/
                                argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
                                /*^apply.arg*/
                                argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                                /*_.CURBODY__V62*/
                                meltfptr[55] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[13])), (melt_ptr_t)(/*_.CURMATCHRESTPAIRS__V50*/ meltfptr[49]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                            }
                            ;

                            MELT_CHECK_SIGNAL();
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6532:/ quasiblock");


                            /*^rawallocobj*/
                            /*rawallocobj*/
                            {
                                melt_ptr_t newobj = 0;
                                melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_MATCH_CASE*/ meltfrout->tabval[14])), (4), "CLASS_SOURCE_MATCH_CASE");
                                /*_.INST__V64*/
                                meltfptr[56] =
                                    newobj;
                            };
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (1), (/*_.CURMATCHLOC__V46*/ meltfptr[42]), "LOCA_LOCATION");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @SCAM_PATT", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (2), (/*_.CURPAT__V61*/ meltfptr[59]), "SCAM_PATT");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @SCAM_BODY", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (3), (/*_.CURBODY__V62*/ meltfptr[55]), "SCAM_BODY");
                            ;
                            /*^touchobj*/

                            melt_dbgtrace_written_object (/*_.INST__V64*/ meltfptr[56], "newly made instance");
                            ;
                            /*_.CURCASE__V63*/
                            meltfptr[54] = /*_.INST__V64*/ meltfptr[56];;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6537:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                                    melt_dbgcounter++;
#endif
                                    ;
                                }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_#MELT_NEED_DBG__L19*/
                                meltfnum[17] =
                                    /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                                    (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                                    0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                                    ;;
                                MELT_LOCATION("warmelt-macro.melt:6537:/ cond");
                                /*cond*/
                                if (/*_#MELT_NEED_DBG__L19*/ meltfnum[17]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*_#MELT_CALLCOUNT__L20*/ meltfnum[7] =
                                                /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                                meltcallcount  /* melt_callcount debugging */
#else
                                                0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                                ;;

                                            MELT_CHECK_SIGNAL();
                                            ;
                                            MELT_LOCATION("warmelt-macro.melt:6537:/ apply");
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[5];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L20*/ meltfnum[7];
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6537;
                                                /*^apply.arg*/
                                                argtab[3].meltbp_cstring =  "mexpand_match curcase";
                                                /*^apply.arg*/
                                                argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CURCASE__V63*/ meltfptr[54];
                                                /*_.MELT_DEBUG_FUN__V66*/
                                                meltfptr[65] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IF___V65*/
                                            meltfptr[64] = /*_.MELT_DEBUG_FUN__V66*/ meltfptr[65];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6537:/ clear");
                                            /*clear*/ /*_#MELT_CALLCOUNT__L20*/
                                            meltfnum[7] = 0 ;
                                            /*^clear*/
                                            /*clear*/ /*_.MELT_DEBUG_FUN__V66*/
                                            meltfptr[65] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IF___V65*/ meltfptr[64] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                {
                                    MELT_LOCATION("warmelt-macro.melt:6537:/ locexp");
                                    /*void*/
                                    (void)0;
                                }
                                ;
                                /*^quasiblock*/


                                /*epilog*/

                                /*^clear*/
                                /*clear*/ /*_#MELT_NEED_DBG__L19*/
                                meltfnum[17] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IF___V65*/
                                meltfptr[64] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*void*/(void)0;
                                }
                                ;
                                /*epilog*/
                            }

#endif /*MELT_HAVE_DEBUG*/
                            ;

                            {
                                MELT_LOCATION("warmelt-macro.melt:6538:/ locexp");
                                meltgc_prepend_list((melt_ptr_t)(/*_.CASELIST__V37*/ meltfptr[33]), (melt_ptr_t)(/*_.CURCASE__V63*/ meltfptr[54]));
                            }
                            ;

                            MELT_LOCATION("warmelt-macro.melt:6517:/ clear");
                            /*clear*/ /*_.CURMATCHCONT__V45*/
                            meltfptr[43] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHLOC__V46*/
                            meltfptr[42] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LIST_FIRST__V47*/
                            meltfptr[46] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHPATX__V48*/
                            meltfptr[47] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LIST_FIRST__V49*/
                            meltfptr[48] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHRESTPAIRS__V50*/
                            meltfptr[49] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.MAKE_MAPOBJECT__V51*/
                            meltfptr[50] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURPATCTX__V52*/
                            meltfptr[51] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LET___V54*/
                            meltfptr[53] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURPAT__V61*/
                            meltfptr[59] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURBODY__V62*/
                            meltfptr[55] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURCASE__V63*/
                            meltfptr[54] = 0 ;
                            /*epilog*/
                        }
                        ;
                    }
                else
                    {
                        MELT_LOCATION("warmelt-macro.melt:6516:/ cond.else");

                        /*^block*/
                        /*anyblock*/
                        {


                            {
                                MELT_LOCATION("warmelt-macro.melt:6542:/ locexp");
                                /* error_plain */
                                melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "(MATCH <expr> <match-case>...) with non sexpr matchcase"), (melt_ptr_t)0);
                            }
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6541:/ quasiblock");


                            /*epilog*/
                        }
                        ;
                    }
                ;

                MELT_LOCATION("warmelt-macro.melt:6512:/ clear");
                /*clear*/ /*_.CURMATCH__V42*/
                meltfptr[41] = 0 ;
                /*^clear*/
                /*clear*/ /*_#IS_A__L16*/
                meltfnum[14] = 0 ;
                /*_#miI__L21*/
                meltfnum[7] =
                    ((/*_#IX__L10*/ meltfnum[8]) - (1));;
                MELT_LOCATION("warmelt-macro.melt:6544:/ compute");
                /*_#IX__L10*/
                meltfnum[8] = /*_#SETQ___L22*/ meltfnum[17] = /*_#miI__L21*/ meltfnum[7];;

                MELT_CHECK_SIGNAL();
                ;
                /*epilog*/

                MELT_LOCATION("warmelt-macro.melt:6510:/ clear");
                /*clear*/ /*_#ltI__L13*/
                meltfnum[11] = 0 ;
                /*^clear*/
                /*clear*/ /*_#miI__L21*/
                meltfnum[7] = 0 ;
                /*^clear*/
                /*clear*/ /*_#SETQ___L22*/
                meltfnum[17] = 0 ;
            }
            ;
            ;
            goto meltlabloop_MATCHLOOP_1;
meltlabexit_MATCHLOOP_1:;/*^loopepilog*/
            /*loopepilog*/
            /*_.FOREVER___V40*/
            meltfptr[38] = /*_.MATCHLOOP__V41*/ meltfptr[32];;
        }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6545:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L23*/
            meltfnum[14] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6545:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L23*/ meltfnum[14]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L24*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6545:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L24*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6545;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_match caselist";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CASELIST__V37*/ meltfptr[33];
                            /*_.MELT_DEBUG_FUN__V68*/
                            meltfptr[64] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V67*/
                        meltfptr[65] = /*_.MELT_DEBUG_FUN__V68*/ meltfptr[64];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6545:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L24*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V68*/
                        meltfptr[64] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V67*/ meltfptr[65] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6545:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L23*/
            meltfnum[14] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V67*/
            meltfptr[65] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6546:/ quasiblock");



        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6547:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[6]);
            /*_.CASETUPL__V70*/
            meltfptr[42] =  melt_apply ((meltclosure_ptr_t)((/*!LIST_TO_MULTIPLE*/ meltfrout->tabval[15])), (melt_ptr_t)(/*_.CASELIST__V37*/ meltfptr[33]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_.LASTCASE__V71*/
        meltfptr[46] =
            (melt_multiple_nth((melt_ptr_t)(/*_.CASETUPL__V70*/ meltfptr[42]), (-1)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6549:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_MATCH*/ meltfrout->tabval[16])), (4), "CLASS_SOURCE_MATCH");
            /*_.INST__V73*/
            meltfptr[48] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (1), (/*_.LOC__V21*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMAT_MATCHEDX", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (2), (/*_.MATSX__V25*/ meltfptr[24]), "SMAT_MATCHEDX");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMAT_CASES", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (3), (/*_.CASETUPL__V70*/ meltfptr[42]), "SMAT_CASES");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V73*/ meltfptr[48], "newly made instance");
        ;
        /*_.SMAT__V72*/
        meltfptr[47] = /*_.INST__V73*/ meltfptr[48];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6557:/ cond");
        /*cond*/
        if (
            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.LASTCASE__V71*/ meltfptr[46]),
                                          (melt_ptr_t)((/*!CLASS_SOURCE_MATCH_CASE*/ meltfrout->tabval[14])))
        ) /*then*/
            {
                /*^cond.then*/
                /*^getslot*/
                {
                    melt_ptr_t slot=NULL, obj=NULL;
                    obj = (melt_ptr_t)(/*_.LASTCASE__V71*/ meltfptr[46]) /*=obj*/;
                    melt_object_get_field(slot,obj, 2, "SCAM_PATT");
                    /*_.SCAM_PATT__V74*/
                    meltfptr[49] = slot;
                };
                ;
            }
        else    /*^cond.else*/
            {

                /*_.SCAM_PATT__V74*/ meltfptr[49] =  /*reallynil*/ NULL ;;
            }
        ;
        /*^compute*/
        /*_#IS_NOT_A__L25*/
        meltfnum[7] =
            !melt_is_instance_of((melt_ptr_t)(/*_.SCAM_PATT__V74*/ meltfptr[49]), (melt_ptr_t)((/*!CLASS_SOURCE_PATTERN_JOKER_VARIABLE*/ meltfrout->tabval[17])));;
        MELT_LOCATION("warmelt-macro.melt:6556:/ cond");
        /*cond*/
        if (/*_#IS_NOT_A__L25*/ meltfnum[7]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6559:/ locexp");
                        melt_inform_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "last (MATCH ...) clause is not a joker"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6561:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L26*/
            meltfnum[17] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6561:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L26*/ meltfnum[17]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L27*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6561:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L27*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6561;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_match result smat";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SMAT__V72*/ meltfptr[47];
                            /*_.MELT_DEBUG_FUN__V76*/
                            meltfptr[51] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V75*/
                        meltfptr[50] = /*_.MELT_DEBUG_FUN__V76*/ meltfptr[51];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6561:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L27*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V76*/
                        meltfptr[51] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V75*/ meltfptr[50] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6561:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L26*/
            meltfnum[17] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V75*/
            meltfptr[50] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6562:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.SMAT__V72*/ meltfptr[47];;

        {
            MELT_LOCATION("warmelt-macro.melt:6562:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V69*/
        meltfptr[43] = /*_.RETURN___V77*/ meltfptr[53];;

        MELT_LOCATION("warmelt-macro.melt:6546:/ clear");
        /*clear*/ /*_.CASETUPL__V70*/
        meltfptr[42] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LASTCASE__V71*/
        meltfptr[46] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SMAT__V72*/
        meltfptr[47] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SCAM_PATT__V74*/
        meltfptr[49] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_NOT_A__L25*/
        meltfnum[7] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V77*/
        meltfptr[53] = 0 ;
        /*_.LET___V19*/
        meltfptr[5] = /*_.LET___V69*/ meltfptr[43];;

        MELT_LOCATION("warmelt-macro.melt:6489:/ clear");
        /*clear*/ /*_.CONT__V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V23*/
        meltfptr[22] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MSEXP__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MATSX__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LAMBDA___V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MEXPTUPLE__V31*/
        meltfptr[30] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NBMATCH__L7*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V32*/
        meltfptr[31] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LASTMEXP__V36*/
        meltfptr[34] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IX__L10*/
        meltfnum[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CASELIST__V37*/
        meltfptr[33] = 0 ;
        /*^clear*/
        /*clear*/ /*_.FOREVER___V40*/
        meltfptr[38] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V69*/
        meltfptr[43] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6483:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V19*/ meltfptr[5];;

        {
            MELT_LOCATION("warmelt-macro.melt:6483:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V17*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V19*/
        meltfptr[5] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_MATCH", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_124_WARMELTmiMACRO_MEXPAND_MATCH*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_125_WARMELTmiMACRO_LAMBDA_cl21(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 fromline 1718 */

    /** start of frame for meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21// fromline 1534
        : public Melt_CallFrameWithValues<2>
    {
    public: /* fromline 1538*/
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
        MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<2> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21), clos) {};
        MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21() //the constructor fromline 1608
            : Melt_CallFrameWithValues<2> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21)) {};
        MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21


    /** end of frame for meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 fromline 1663**/

    /* end of frame for routine meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 fromline 1722 */

    /* classy proc frame meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 */
    MeltFrame_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_125_WARMELTmiMACRO_LAMBDA_cl21 fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl21", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6497:/ getarg");
    /*_.C__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;
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
        /*_#IS_NOT_A__L1*/
        meltfnum[0] =
            !melt_is_instance_of((melt_ptr_t)(/*_.C__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[0])));;
        MELT_LOCATION("warmelt-macro.melt:6498:/ cond");
        /*cond*/
        if (/*_#IS_NOT_A__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6499:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)((/*~LOC*/ meltfclos->tabval[0])), ( "MATCH with non-sexpr"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6497:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.C__V2*/ meltfptr[1];;

        {
            MELT_LOCATION("warmelt-macro.melt:6497:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_#IS_NOT_A__L1*/
        meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl21", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_125_WARMELTmiMACRO_LAMBDA_cl21_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_125_WARMELTmiMACRO_LAMBDA_cl21*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT fromline 1718 */

    /** start of frame for meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT// fromline 1534
        : public Melt_CallFrameWithValues<77>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[27];
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
        MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<77> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT), clos) {};
        MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT() //the constructor fromline 1608
            : Melt_CallFrameWithValues<77> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<77> (fil,lin, sizeof(MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT)) {};
        MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<77> (fil,lin, sizeof(MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT


    /** end of frame for meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT fromline 1663**/

    /* end of frame for routine meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT fromline 1722 */

    /* classy proc frame meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT */
    MeltFrame_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_MATCHALT", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6577:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6578:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6578:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6578:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6578;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_matchalt sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6578:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6578:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6579:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6579:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6579:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6579;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6579:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6579:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6580:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6580:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6580:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6580;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6580:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6580:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6581:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L5*/
            meltfnum[1] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6581:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L5*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V15*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6581:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6581;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                            meltfptr[15] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V15*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V16*/ meltfptr[15];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6581:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V16*/
                        meltfptr[15] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V14*/
            meltfptr[12] = /*_._IFELSE___V15*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6581:/ clear");
            /*clear*/ /*_#IS_OBJECT__L5*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V15*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V14*/ meltfptr[12] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L6*/
        meltfnum[0] =
            ((/*_.MEXPANDER__V4*/ meltfptr[3]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6582:/ cond");
        /*cond*/
        if (/*_#NULL__L6*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    /*^compute*/
                    /*_.MEXPANDER__V4*/ meltfptr[3] = /*_.SETQ___V18*/ meltfptr[5] = (/*!MACROEXPAND_1*/ meltfrout->tabval[4]);;
                    /*_._IF___V17*/
                    meltfptr[15] = /*_.SETQ___V18*/ meltfptr[5];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6582:/ clear");
                    /*clear*/ /*_.SETQ___V18*/
                    meltfptr[5] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V17*/ meltfptr[15] =  /*reallynil*/ NULL ;;
            }
        ;
        MELT_LOCATION("warmelt-macro.melt:6583:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6584:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V20*/
            meltfptr[19] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6585:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V21*/
            meltfptr[20] = slot;
        };
        ;
        /*_.LIST_FIRST__V22*/
        meltfptr[21] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[19])));;
        /*^compute*/
        /*_.PAIR_TAIL__V23*/
        meltfptr[22] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V22*/ meltfptr[21])));;
        /*^compute*/
        /*_.MSEXP__V24*/
        meltfptr[23] =
            (melt_pair_head((melt_ptr_t)(/*_.PAIR_TAIL__V23*/ meltfptr[22])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6587:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
            /*_.MATSX__V25*/
            meltfptr[24] =  melt_apply ((meltclosure_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3]), (melt_ptr_t)(/*_.MSEXP__V24*/ meltfptr[23]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_.LIST_FIRST__V26*/
        meltfptr[25] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[19])));;
        /*^compute*/
        /*_.PAIR_TAIL__V27*/
        meltfptr[26] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V26*/ meltfptr[25])));;
        /*^compute*/
        /*_.PAIR_TAIL__V28*/
        meltfptr[27] =
            (melt_pair_tail((melt_ptr_t)(/*_.PAIR_TAIL__V27*/ meltfptr[26])));;
        MELT_LOCATION("warmelt-macro.melt:6591:/ quasiblock");


        /*^newclosure*/
        /*newclosure*/ /*_.LAMBDA___V30*/
        meltfptr[29] =
            (melt_ptr_t) meltgc_new_closure((meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_CLOSURE)))), (meltroutine_ptr_t)((/*!konst_8*/ meltfrout->tabval[8])), (1));
        ;
        /*^putclosedv*/
        /*putclosv*/
        melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V30*/ meltfptr[29])) == MELTOBMAG_CLOSURE);
        melt_assertmsg("putclosv checkoff", 0>= 0 && 0< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V30*/ meltfptr[29])));
        ((meltclosure_ptr_t)/*_.LAMBDA___V30*/ meltfptr[29])->tabval[0] = (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]);
        ;
        /*_.LAMBDA___V29*/
        meltfptr[28] = /*_.LAMBDA___V30*/ meltfptr[29];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6588:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[2];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[6]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.LAMBDA___V29*/ meltfptr[28];
            /*_.MEXPTUPLE__V31*/
            meltfptr[30] =  melt_apply ((meltclosure_ptr_t)((/*!PAIRLIST_TO_MULTIPLE*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.PAIR_TAIL__V28*/ meltfptr[27]), (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_#NBMATCH__L7*/
        meltfnum[1] =
            (melt_multiple_length((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30])));;
        MELT_LOCATION("warmelt-macro.melt:6597:/ quasiblock");


        /*_.LX__V33*/
        meltfptr[32] =
            (melt_multiple_nth((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30]), (-1)));;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6598:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6598:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L8*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L9*/ meltfnum[8] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6598:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L9*/ meltfnum[8];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6598;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_matchalt lastmexp lx";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.LX__V33*/ meltfptr[32];
                            /*_.MELT_DEBUG_FUN__V35*/
                            meltfptr[34] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V34*/
                        meltfptr[33] = /*_.MELT_DEBUG_FUN__V35*/ meltfptr[34];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6598:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L9*/
                        meltfnum[8] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V35*/
                        meltfptr[34] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V34*/ meltfptr[33] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6598:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L8*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V34*/
            meltfptr[33] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        /*_.LET___V32*/
        meltfptr[31] = /*_.LX__V33*/ meltfptr[32];;

        MELT_LOCATION("warmelt-macro.melt:6597:/ clear");
        /*clear*/ /*_.LX__V33*/
        meltfptr[32] = 0 ;
        /*_.LASTMEXP__V36*/
        meltfptr[34] = /*_.LET___V32*/ meltfptr[31];;
        /*^compute*/
        /*_#IX__L10*/
        meltfnum[8] =
            ((/*_#NBMATCH__L7*/ meltfnum[1]) - (1));;
        /*^compute*/
        /*_.CASELIST__V37*/
        meltfptr[33] =
            (meltgc_new_list((meltobject_ptr_t)((/*!DISCR_LIST*/ meltfrout->tabval[9]))));;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6603:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L11*/
            meltfnum[7] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6603:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L11*/ meltfnum[7]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L12*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6603:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L12*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6603;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_matchalt mexptuple";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPTUPLE__V31*/ meltfptr[30];
                            /*_.MELT_DEBUG_FUN__V39*/
                            meltfptr[38] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V38*/
                        meltfptr[32] = /*_.MELT_DEBUG_FUN__V39*/ meltfptr[38];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6603:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L12*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V39*/
                        meltfptr[38] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V38*/ meltfptr[32] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6603:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L11*/
            meltfnum[7] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V38*/
            meltfptr[32] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6604:/ loop");
        /*loop*/
        {
meltlabloop_MATCHLOOP_2:;/*^loopbody*/

            /*^block*/
            /*anyblock*/
            {


                MELT_CHECK_SIGNAL();
                ;

                MELT_CHECK_SIGNAL();
                ;
                /*_#ltI__L13*/
                meltfnum[11] =
                    ((/*_#IX__L10*/ meltfnum[8]) < (0));;
                MELT_LOCATION("warmelt-macro.melt:6605:/ cond");
                /*cond*/
                if (/*_#ltI__L13*/ meltfnum[11]) /*then*/
                    {
                        /*^cond.then*/
                        /*^block*/
                        /*anyblock*/
                        {

                            /*^quasiblock*/


                            /*^compute*/
                            /*_.MATCHLOOP__V41*/ meltfptr[32] =  /*reallynil*/ NULL ;;

                            /*^exit*/
                            /*exit*/
                            {
                                goto meltlabexit_MATCHLOOP_2;
                            }
                            ;
                            /*epilog*/
                        }
                        ;
                    } /*noelse*/
                ;
                MELT_LOCATION("warmelt-macro.melt:6606:/ quasiblock");


                /*_.CURMATCH__V42*/
                meltfptr[41] =
                    (melt_multiple_nth((melt_ptr_t)(/*_.MEXPTUPLE__V31*/ meltfptr[30]), (/*_#IX__L10*/ meltfnum[8])));;

#if MELT_HAVE_DEBUG
                MELT_LOCATION("warmelt-macro.melt:6607:/ cppif.then");
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                        melt_dbgcounter++;
#endif
                        ;
                    }
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#MELT_NEED_DBG__L14*/
                    meltfnum[7] =
                        /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                        (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                        0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                        ;;
                    MELT_LOCATION("warmelt-macro.melt:6607:/ cond");
                    /*cond*/
                    if (/*_#MELT_NEED_DBG__L14*/ meltfnum[7]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                /*_#MELT_CALLCOUNT__L15*/ meltfnum[14] =
                                    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                    meltcallcount  /* melt_callcount debugging */
#else
                                    0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                    ;;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6607:/ apply");
                                /*apply*/
                                {
                                    union meltparam_un argtab[5];
                                    memset(&argtab, 0, sizeof(argtab));
                                    /*^apply.arg*/
                                    argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L15*/ meltfnum[14];
                                    /*^apply.arg*/
                                    argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                    /*^apply.arg*/
                                    argtab[2].meltbp_long = 6607;
                                    /*^apply.arg*/
                                    argtab[3].meltbp_cstring =  "mexpand_matchalt curmatch";
                                    /*^apply.arg*/
                                    argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CURMATCH__V42*/ meltfptr[41];
                                    /*_.MELT_DEBUG_FUN__V44*/
                                    meltfptr[43] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                }
                                ;
                                /*_._IF___V43*/
                                meltfptr[42] = /*_.MELT_DEBUG_FUN__V44*/ meltfptr[43];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6607:/ clear");
                                /*clear*/ /*_#MELT_CALLCOUNT__L15*/
                                meltfnum[14] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.MELT_DEBUG_FUN__V44*/
                                meltfptr[43] = 0 ;
                            }
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_._IF___V43*/ meltfptr[42] =  /*reallynil*/ NULL ;;
                        }
                    ;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6607:/ locexp");
                        /*void*/
                        (void)0;
                    }
                    ;
                    /*^quasiblock*/


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_#MELT_NEED_DBG__L14*/
                    meltfnum[7] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IF___V43*/
                    meltfptr[42] = 0 ;
                }

#else /*MELT_HAVE_DEBUG*/
                /*^cppif.else*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        /*^locexp*/
                        /*void*/(void)0;
                    }
                    ;
                    /*epilog*/
                }

#endif /*MELT_HAVE_DEBUG*/
                ;

                MELT_CHECK_SIGNAL();
                ;
                /*_#IS_A__L16*/
                meltfnum[14] =
                    melt_is_instance_of((melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
                MELT_LOCATION("warmelt-macro.melt:6610:/ cond");
                /*cond*/
                if (/*_#IS_A__L16*/ meltfnum[14]) /*then*/
                    {
                        /*^cond.then*/
                        /*^block*/
                        /*anyblock*/
                        {

                            MELT_LOCATION("warmelt-macro.melt:6611:/ quasiblock");


                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]) /*=obj*/;
                                melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
                                /*_.CURMATCHCONT__V45*/
                                meltfptr[43] = slot;
                            };
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6612:/ getslot");
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)(/*_.CURMATCH__V42*/ meltfptr[41]) /*=obj*/;
                                melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                                /*_.CURMATCHLOC__V46*/
                                meltfptr[42] = slot;
                            };
                            ;
                            /*_.LIST_FIRST__V47*/
                            meltfptr[46] =
                                (melt_list_first((melt_ptr_t)(/*_.CURMATCHCONT__V45*/ meltfptr[43])));;
                            /*^compute*/
                            /*_.CURMATCHPATX__V48*/
                            meltfptr[47] =
                                (melt_pair_head((melt_ptr_t)(/*_.LIST_FIRST__V47*/ meltfptr[46])));;
                            /*^compute*/
                            /*_.LIST_FIRST__V49*/
                            meltfptr[48] =
                                (melt_list_first((melt_ptr_t)(/*_.CURMATCHCONT__V45*/ meltfptr[43])));;
                            /*^compute*/
                            /*_.CURMATCHRESTPAIRS__V50*/
                            meltfptr[49] =
                                (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V49*/ meltfptr[48])));;

                            MELT_CHECK_SIGNAL();
                            ;
                            /*^compute*/
                            /*_.MAKE_MAPOBJECT__V51*/
                            meltfptr[50] =
                                (meltgc_new_mapobjects( (meltobject_ptr_t) ((/*!DISCR_MAP_OBJECTS*/ meltfrout->tabval[12])), (17)));;
                            MELT_LOCATION("warmelt-macro.melt:6615:/ quasiblock");


                            /*^rawallocobj*/
                            /*rawallocobj*/
                            {
                                melt_ptr_t newobj = 0;
                                melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_PATTERN_EXPANSION_CONTEXT*/ meltfrout->tabval[10])), (4), "CLASS_PATTERN_EXPANSION_CONTEXT");
                                /*_.INST__V53*/
                                meltfptr[52] =
                                    newobj;
                            };
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_MEXPANDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (0), (/*_.MEXPANDER__V4*/ meltfptr[3]), "PCTX_MEXPANDER");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_PEXPANDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (1), ((/*!PATTERNEXPAND_1*/ meltfrout->tabval[11])), "PCTX_PEXPANDER");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_VARMAP", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (2), (/*_.MAKE_MAPOBJECT__V51*/ meltfptr[50]), "PCTX_VARMAP");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @PCTX_MODCTX", melt_magic_discr((melt_ptr_t)(/*_.INST__V53*/ meltfptr[52])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V53*/ meltfptr[52]), (3), (/*_.MODCTX__V5*/ meltfptr[4]), "PCTX_MODCTX");
                            ;
                            /*^touchobj*/

                            melt_dbgtrace_written_object (/*_.INST__V53*/ meltfptr[52], "newly made instance");
                            ;
                            /*_.CURPATCTX__V52*/
                            meltfptr[51] = /*_.INST__V53*/ meltfptr[52];;
                            MELT_LOCATION("warmelt-macro.melt:6621:/ quasiblock");



                            MELT_CHECK_SIGNAL();
                            ;
                            /*^apply*/
                            /*apply*/
                            {
                                union meltparam_un argtab[3];
                                memset(&argtab, 0, sizeof(argtab));
                                /*^apply.arg*/
                                argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                                /*^apply.arg*/
                                argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.CURPATCTX__V52*/ meltfptr[51];
                                /*^apply.arg*/
                                argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.CURMATCHLOC__V46*/ meltfptr[42];
                                /*_.CP__V55*/
                                meltfptr[54] =  melt_apply ((meltclosure_ptr_t)((/*!PATTERNEXPAND_1*/ meltfrout->tabval[11])), (melt_ptr_t)(/*_.CURMATCHPATX__V48*/ meltfptr[47]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                            }
                            ;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6622:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                                    melt_dbgcounter++;
#endif
                                    ;
                                }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_#MELT_NEED_DBG__L17*/
                                meltfnum[7] =
                                    /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                                    (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                                    0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                                    ;;
                                MELT_LOCATION("warmelt-macro.melt:6622:/ cond");
                                /*cond*/
                                if (/*_#MELT_NEED_DBG__L17*/ meltfnum[7]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*_#MELT_CALLCOUNT__L18*/ meltfnum[17] =
                                                /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                                meltcallcount  /* melt_callcount debugging */
#else
                                                0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                                ;;

                                            MELT_CHECK_SIGNAL();
                                            ;
                                            MELT_LOCATION("warmelt-macro.melt:6622:/ apply");
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[5];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L18*/ meltfnum[17];
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6622;
                                                /*^apply.arg*/
                                                argtab[3].meltbp_cstring =  "mexpand_matchalt curpat";
                                                /*^apply.arg*/
                                                argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CP__V55*/ meltfptr[54];
                                                /*_.MELT_DEBUG_FUN__V57*/
                                                meltfptr[56] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IF___V56*/
                                            meltfptr[55] = /*_.MELT_DEBUG_FUN__V57*/ meltfptr[56];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6622:/ clear");
                                            /*clear*/ /*_#MELT_CALLCOUNT__L18*/
                                            meltfnum[17] = 0 ;
                                            /*^clear*/
                                            /*clear*/ /*_.MELT_DEBUG_FUN__V57*/
                                            meltfptr[56] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IF___V56*/ meltfptr[55] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                {
                                    MELT_LOCATION("warmelt-macro.melt:6622:/ locexp");
                                    /*void*/
                                    (void)0;
                                }
                                ;
                                /*^quasiblock*/


                                /*epilog*/

                                /*^clear*/
                                /*clear*/ /*_#MELT_NEED_DBG__L17*/
                                meltfnum[7] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IF___V56*/
                                meltfptr[55] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*void*/(void)0;
                                }
                                ;
                                /*epilog*/
                            }

#endif /*MELT_HAVE_DEBUG*/
                            ;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6623:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                MELT_CHECK_SIGNAL();
                                ;
                                /*^cond*/
                                /*cond*/
                                if (/*_.CP__V55*/ meltfptr[54]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*_._IFELSE___V59*/ meltfptr[55] = (/*nil*/NULL);;
                                    }
                                else
                                    {
                                        MELT_LOCATION("warmelt-macro.melt:6623:/ cond.else");

                                        /*^block*/
                                        /*anyblock*/
                                        {


                                            MELT_CHECK_SIGNAL();
                                            ;
                                            /*^apply*/
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[3];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_cstring =  "check curpat";
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6623;
                                                /*_.MELT_ASSERT_FAILURE_FUN__V60*/
                                                meltfptr[59] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IFELSE___V59*/
                                            meltfptr[55] = /*_.MELT_ASSERT_FAILURE_FUN__V60*/ meltfptr[59];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6623:/ clear");
                                            /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V60*/
                                            meltfptr[59] = 0 ;
                                        }
                                        ;
                                    }
                                ;
                                /*_.IFCPP___V58*/
                                meltfptr[56] = /*_._IFELSE___V59*/ meltfptr[55];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6623:/ clear");
                                /*clear*/ /*_._IFELSE___V59*/
                                meltfptr[55] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*_.IFCPP___V58*/ meltfptr[56] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
                            ;
                            /*^compute*/
                            /*_.LET___V54*/
                            meltfptr[53] = /*_.CP__V55*/ meltfptr[54];;

                            MELT_LOCATION("warmelt-macro.melt:6621:/ clear");
                            /*clear*/ /*_.CP__V55*/
                            meltfptr[54] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.IFCPP___V58*/
                            meltfptr[56] = 0 ;
                            /*_.CURPAT__V61*/
                            meltfptr[59] = /*_.LET___V54*/ meltfptr[53];;

                            MELT_CHECK_SIGNAL();
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6625:/ apply");
                            /*apply*/
                            {
                                union meltparam_un argtab[3];
                                memset(&argtab, 0, sizeof(argtab));
                                /*^apply.arg*/
                                argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                                /*^apply.arg*/
                                argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
                                /*^apply.arg*/
                                argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                                /*_.CURBODY__V62*/
                                meltfptr[55] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[13])), (melt_ptr_t)(/*_.CURMATCHRESTPAIRS__V50*/ meltfptr[49]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                            }
                            ;

                            MELT_CHECK_SIGNAL();
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6626:/ quasiblock");


                            /*^rawallocobj*/
                            /*rawallocobj*/
                            {
                                melt_ptr_t newobj = 0;
                                melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_MATCH_CASE*/ meltfrout->tabval[14])), (4), "CLASS_SOURCE_MATCH_CASE");
                                /*_.INST__V64*/
                                meltfptr[56] =
                                    newobj;
                            };
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (1), (/*_.CURMATCHLOC__V46*/ meltfptr[42]), "LOCA_LOCATION");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @SCAM_PATT", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (2), (/*_.CURPAT__V61*/ meltfptr[59]), "SCAM_PATT");
                            ;
                            /*^putslot*/
                            /*putslot*/
                            melt_assertmsg("checkobj putslot  _ @SCAM_BODY", melt_magic_discr((melt_ptr_t)(/*_.INST__V64*/ meltfptr[56])) == MELTOBMAG_OBJECT);
                            melt_putfield_object((/*_.INST__V64*/ meltfptr[56]), (3), (/*_.CURBODY__V62*/ meltfptr[55]), "SCAM_BODY");
                            ;
                            /*^touchobj*/

                            melt_dbgtrace_written_object (/*_.INST__V64*/ meltfptr[56], "newly made instance");
                            ;
                            /*_.CURCASE__V63*/
                            meltfptr[54] = /*_.INST__V64*/ meltfptr[56];;

#if MELT_HAVE_DEBUG
                            MELT_LOCATION("warmelt-macro.melt:6631:/ cppif.then");
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                                    melt_dbgcounter++;
#endif
                                    ;
                                }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                /*_#MELT_NEED_DBG__L19*/
                                meltfnum[17] =
                                    /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                                    (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                                    0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                                    ;;
                                MELT_LOCATION("warmelt-macro.melt:6631:/ cond");
                                /*cond*/
                                if (/*_#MELT_NEED_DBG__L19*/ meltfnum[17]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            /*_#MELT_CALLCOUNT__L20*/ meltfnum[7] =
                                                /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                                meltcallcount  /* melt_callcount debugging */
#else
                                                0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                                ;;

                                            MELT_CHECK_SIGNAL();
                                            ;
                                            MELT_LOCATION("warmelt-macro.melt:6631:/ apply");
                                            /*apply*/
                                            {
                                                union meltparam_un argtab[5];
                                                memset(&argtab, 0, sizeof(argtab));
                                                /*^apply.arg*/
                                                argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L20*/ meltfnum[7];
                                                /*^apply.arg*/
                                                argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                /*^apply.arg*/
                                                argtab[2].meltbp_long = 6631;
                                                /*^apply.arg*/
                                                argtab[3].meltbp_cstring =  "mexpand_matchalt curcase";
                                                /*^apply.arg*/
                                                argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CURCASE__V63*/ meltfptr[54];
                                                /*_.MELT_DEBUG_FUN__V66*/
                                                meltfptr[65] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                            }
                                            ;
                                            /*_._IF___V65*/
                                            meltfptr[64] = /*_.MELT_DEBUG_FUN__V66*/ meltfptr[65];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6631:/ clear");
                                            /*clear*/ /*_#MELT_CALLCOUNT__L20*/
                                            meltfnum[7] = 0 ;
                                            /*^clear*/
                                            /*clear*/ /*_.MELT_DEBUG_FUN__V66*/
                                            meltfptr[65] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IF___V65*/ meltfptr[64] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                {
                                    MELT_LOCATION("warmelt-macro.melt:6631:/ locexp");
                                    /*void*/
                                    (void)0;
                                }
                                ;
                                /*^quasiblock*/


                                /*epilog*/

                                /*^clear*/
                                /*clear*/ /*_#MELT_NEED_DBG__L19*/
                                meltfnum[17] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IF___V65*/
                                meltfptr[64] = 0 ;
                            }

#else /*MELT_HAVE_DEBUG*/
                            /*^cppif.else*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /*void*/(void)0;
                                }
                                ;
                                /*epilog*/
                            }

#endif /*MELT_HAVE_DEBUG*/
                            ;

                            {
                                MELT_LOCATION("warmelt-macro.melt:6632:/ locexp");
                                meltgc_prepend_list((melt_ptr_t)(/*_.CASELIST__V37*/ meltfptr[33]), (melt_ptr_t)(/*_.CURCASE__V63*/ meltfptr[54]));
                            }
                            ;

                            MELT_LOCATION("warmelt-macro.melt:6611:/ clear");
                            /*clear*/ /*_.CURMATCHCONT__V45*/
                            meltfptr[43] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHLOC__V46*/
                            meltfptr[42] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LIST_FIRST__V47*/
                            meltfptr[46] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHPATX__V48*/
                            meltfptr[47] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LIST_FIRST__V49*/
                            meltfptr[48] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURMATCHRESTPAIRS__V50*/
                            meltfptr[49] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.MAKE_MAPOBJECT__V51*/
                            meltfptr[50] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURPATCTX__V52*/
                            meltfptr[51] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.LET___V54*/
                            meltfptr[53] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURPAT__V61*/
                            meltfptr[59] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURBODY__V62*/
                            meltfptr[55] = 0 ;
                            /*^clear*/
                            /*clear*/ /*_.CURCASE__V63*/
                            meltfptr[54] = 0 ;
                            /*epilog*/
                        }
                        ;
                    }
                else
                    {
                        MELT_LOCATION("warmelt-macro.melt:6610:/ cond.else");

                        /*^block*/
                        /*anyblock*/
                        {


                            {
                                MELT_LOCATION("warmelt-macro.melt:6636:/ locexp");
                                /* error_plain */
                                melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "(MATCHALT <expr> <match-case>...) with non sexpr matchcase"), (melt_ptr_t)0);
                            }
                            ;
                            MELT_LOCATION("warmelt-macro.melt:6635:/ quasiblock");


                            /*epilog*/
                        }
                        ;
                    }
                ;

                MELT_LOCATION("warmelt-macro.melt:6606:/ clear");
                /*clear*/ /*_.CURMATCH__V42*/
                meltfptr[41] = 0 ;
                /*^clear*/
                /*clear*/ /*_#IS_A__L16*/
                meltfnum[14] = 0 ;
                /*_#miI__L21*/
                meltfnum[7] =
                    ((/*_#IX__L10*/ meltfnum[8]) - (1));;
                MELT_LOCATION("warmelt-macro.melt:6638:/ compute");
                /*_#IX__L10*/
                meltfnum[8] = /*_#SETQ___L22*/ meltfnum[17] = /*_#miI__L21*/ meltfnum[7];;

                MELT_CHECK_SIGNAL();
                ;
                /*epilog*/

                MELT_LOCATION("warmelt-macro.melt:6604:/ clear");
                /*clear*/ /*_#ltI__L13*/
                meltfnum[11] = 0 ;
                /*^clear*/
                /*clear*/ /*_#miI__L21*/
                meltfnum[7] = 0 ;
                /*^clear*/
                /*clear*/ /*_#SETQ___L22*/
                meltfnum[17] = 0 ;
            }
            ;
            ;
            goto meltlabloop_MATCHLOOP_2;
meltlabexit_MATCHLOOP_2:;/*^loopepilog*/
            /*loopepilog*/
            /*_.FOREVER___V40*/
            meltfptr[38] = /*_.MATCHLOOP__V41*/ meltfptr[32];;
        }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6639:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L23*/
            meltfnum[14] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6639:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L23*/ meltfnum[14]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L24*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6639:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L24*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6639;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_matchalt caselist";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CASELIST__V37*/ meltfptr[33];
                            /*_.MELT_DEBUG_FUN__V68*/
                            meltfptr[64] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V67*/
                        meltfptr[65] = /*_.MELT_DEBUG_FUN__V68*/ meltfptr[64];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6639:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L24*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V68*/
                        meltfptr[64] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V67*/ meltfptr[65] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6639:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L23*/
            meltfnum[14] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V67*/
            meltfptr[65] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6640:/ quasiblock");



        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6641:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[6]);
            /*_.CASETUPL__V70*/
            meltfptr[42] =  melt_apply ((meltclosure_ptr_t)((/*!LIST_TO_MULTIPLE*/ meltfrout->tabval[15])), (melt_ptr_t)(/*_.CASELIST__V37*/ meltfptr[33]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*_.LASTCASE__V71*/
        meltfptr[46] =
            (melt_multiple_nth((melt_ptr_t)(/*_.CASETUPL__V70*/ meltfptr[42]), (-1)));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6643:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_MATCHALT*/ meltfrout->tabval[16])), (4), "CLASS_SOURCE_MATCHALT");
            /*_.INST__V73*/
            meltfptr[48] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (1), (/*_.LOC__V21*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMAT_MATCHEDX", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (2), (/*_.MATSX__V25*/ meltfptr[24]), "SMAT_MATCHEDX");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SMAT_CASES", melt_magic_discr((melt_ptr_t)(/*_.INST__V73*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V73*/ meltfptr[48]), (3), (/*_.CASETUPL__V70*/ meltfptr[42]), "SMAT_CASES");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V73*/ meltfptr[48], "newly made instance");
        ;
        /*_.SMAT__V72*/
        meltfptr[47] = /*_.INST__V73*/ meltfptr[48];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6651:/ cond");
        /*cond*/
        if (
            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.LASTCASE__V71*/ meltfptr[46]),
                                          (melt_ptr_t)((/*!CLASS_SOURCE_MATCH_CASE*/ meltfrout->tabval[14])))
        ) /*then*/
            {
                /*^cond.then*/
                /*^getslot*/
                {
                    melt_ptr_t slot=NULL, obj=NULL;
                    obj = (melt_ptr_t)(/*_.LASTCASE__V71*/ meltfptr[46]) /*=obj*/;
                    melt_object_get_field(slot,obj, 2, "SCAM_PATT");
                    /*_.SCAM_PATT__V74*/
                    meltfptr[49] = slot;
                };
                ;
            }
        else    /*^cond.else*/
            {

                /*_.SCAM_PATT__V74*/ meltfptr[49] =  /*reallynil*/ NULL ;;
            }
        ;
        /*^compute*/
        /*_#IS_NOT_A__L25*/
        meltfnum[7] =
            !melt_is_instance_of((melt_ptr_t)(/*_.SCAM_PATT__V74*/ meltfptr[49]), (melt_ptr_t)((/*!CLASS_SOURCE_PATTERN_JOKER_VARIABLE*/ meltfrout->tabval[17])));;
        MELT_LOCATION("warmelt-macro.melt:6650:/ cond");
        /*cond*/
        if (/*_#IS_NOT_A__L25*/ meltfnum[7]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6653:/ locexp");
                        melt_inform_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "last (MATCHALT ...) clause is not a joker"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6655:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L26*/
            meltfnum[17] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6655:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L26*/ meltfnum[17]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L27*/ meltfnum[11] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6655:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L27*/ meltfnum[11];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6655;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_matchalt result smat";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SMAT__V72*/ meltfptr[47];
                            /*_.MELT_DEBUG_FUN__V76*/
                            meltfptr[51] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V75*/
                        meltfptr[50] = /*_.MELT_DEBUG_FUN__V76*/ meltfptr[51];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6655:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L27*/
                        meltfnum[11] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V76*/
                        meltfptr[51] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V75*/ meltfptr[50] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6655:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L26*/
            meltfnum[17] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V75*/
            meltfptr[50] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6656:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.SMAT__V72*/ meltfptr[47];;

        {
            MELT_LOCATION("warmelt-macro.melt:6656:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V69*/
        meltfptr[43] = /*_.RETURN___V77*/ meltfptr[53];;

        MELT_LOCATION("warmelt-macro.melt:6640:/ clear");
        /*clear*/ /*_.CASETUPL__V70*/
        meltfptr[42] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LASTCASE__V71*/
        meltfptr[46] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SMAT__V72*/
        meltfptr[47] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SCAM_PATT__V74*/
        meltfptr[49] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_NOT_A__L25*/
        meltfnum[7] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V77*/
        meltfptr[53] = 0 ;
        /*_.LET___V19*/
        meltfptr[5] = /*_.LET___V69*/ meltfptr[43];;

        MELT_LOCATION("warmelt-macro.melt:6583:/ clear");
        /*clear*/ /*_.CONT__V20*/
        meltfptr[19] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V23*/
        meltfptr[22] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MSEXP__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MATSX__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_TAIL__V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LAMBDA___V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MEXPTUPLE__V31*/
        meltfptr[30] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NBMATCH__L7*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V32*/
        meltfptr[31] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LASTMEXP__V36*/
        meltfptr[34] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IX__L10*/
        meltfnum[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CASELIST__V37*/
        meltfptr[33] = 0 ;
        /*^clear*/
        /*clear*/ /*_.FOREVER___V40*/
        meltfptr[38] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V69*/
        meltfptr[43] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6577:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V19*/ meltfptr[5];;

        {
            MELT_LOCATION("warmelt-macro.melt:6577:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L6*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V17*/
        meltfptr[15] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V19*/
        meltfptr[5] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_MATCHALT", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_126_WARMELTmiMACRO_MEXPAND_MATCHALT*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_127_WARMELTmiMACRO_LAMBDA_cl22(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 fromline 1718 */

    /** start of frame for meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22// fromline 1534
        : public Melt_CallFrameWithValues<2>
    {
    public: /* fromline 1538*/
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
        MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<2> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22), clos) {};
        MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22() //the constructor fromline 1608
            : Melt_CallFrameWithValues<2> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22)) {};
        MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<2> (fil,lin, sizeof(MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22


    /** end of frame for meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 fromline 1663**/

    /* end of frame for routine meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 fromline 1722 */

    /* classy proc frame meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 */
    MeltFrame_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_127_WARMELTmiMACRO_LAMBDA_cl22 fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl22", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6591:/ getarg");
    /*_.C__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;
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
        /*_#IS_NOT_A__L1*/
        meltfnum[0] =
            !melt_is_instance_of((melt_ptr_t)(/*_.C__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[0])));;
        MELT_LOCATION("warmelt-macro.melt:6592:/ cond");
        /*cond*/
        if (/*_#IS_NOT_A__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6593:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)((/*~LOC*/ meltfclos->tabval[0])), ( "MATCHALT with non-sexpr"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6591:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.C__V2*/ meltfptr[1];;

        {
            MELT_LOCATION("warmelt-macro.melt:6591:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_#IS_NOT_A__L1*/
        meltfnum[0] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl22", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_127_WARMELTmiMACRO_LAMBDA_cl22_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_127_WARMELTmiMACRO_LAMBDA_cl22*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING fromline 1718 */

    /** start of frame for meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING// fromline 1534
        : public Melt_CallFrameWithValues<105>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[31];
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
        MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<105> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING), clos) {};
        MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING() //the constructor fromline 1608
            : Melt_CallFrameWithValues<105> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<105> (fil,lin, sizeof(MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING)) {};
        MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<105> (fil,lin, sizeof(MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING


    /** end of frame for meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING fromline 1663**/

    /* end of frame for routine meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING fromline 1722 */

    /* classy proc frame meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING */
    MeltFrame_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_LETBINDING", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6669:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6670:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6670:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6670:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6670;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_letbinding sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6670:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6670:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6671:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6671:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6671:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6671;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6671:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6671:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6672:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6672:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6672:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6672;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6672:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6672:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L5*/
        meltfnum[1] =
            ((/*_.MEXPANDER__V4*/ meltfptr[3]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6673:/ cond");
        /*cond*/
        if (/*_#NULL__L5*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    /*^compute*/
                    /*_.MEXPANDER__V4*/ meltfptr[3] = /*_.SETQ___V15*/ meltfptr[5] = (/*!MACROEXPAND_1*/ meltfrout->tabval[4]);;
                    /*_._IF___V14*/
                    meltfptr[12] = /*_.SETQ___V15*/ meltfptr[5];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6673:/ clear");
                    /*clear*/ /*_.SETQ___V15*/
                    meltfptr[5] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V14*/ meltfptr[12] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6674:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L6*/
            meltfnum[0] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6674:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L6*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V17*/ meltfptr[16] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6674:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6674;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                            meltfptr[17] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V17*/
                        meltfptr[16] = /*_.MELT_ASSERT_FAILURE_FUN__V18*/ meltfptr[17];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6674:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                        meltfptr[17] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V16*/
            meltfptr[5] = /*_._IFELSE___V17*/ meltfptr[16];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6674:/ clear");
            /*clear*/ /*_#IS_OBJECT__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V17*/
            meltfptr[16] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V16*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6675:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6676:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V20*/
            meltfptr[16] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6677:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V21*/
            meltfptr[20] = slot;
        };
        ;
        /*_.CTYP__V22*/
        meltfptr[21] = (/*!QUASI_CTYPE_AUTO*/ meltfrout->tabval[5]);;
        /*^compute*/
        /*_.VAR__V23*/
        meltfptr[22] = (/*nil*/NULL);;
        /*^compute*/
        /*_.EXPR__V24*/
        meltfptr[23] = (/*nil*/NULL);;
        /*^compute*/
        /*_.CURPAIR__V25*/
        meltfptr[24] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[16])));;
        /*^compute*/
        /*_.CURARG__V26*/
        meltfptr[25] = (/*nil*/NULL);;
        /*^compute*/
        /*_.PAIR_HEAD__V27*/
        meltfptr[26] =
            (melt_pair_head((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
        MELT_LOCATION("warmelt-macro.melt:6684:/ compute");
        /*_.CURARG__V26*/
        meltfptr[25] = /*_.SETQ___V28*/ meltfptr[27] = /*_.PAIR_HEAD__V27*/ meltfptr[26];;

        MELT_CHECK_SIGNAL();
        ;
        /*_#IS_A__L7*/
        meltfnum[0] =
            melt_is_instance_of((melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]), (melt_ptr_t)((/*!CLASS_KEYWORD*/ meltfrout->tabval[6])));;
        MELT_LOCATION("warmelt-macro.melt:6686:/ cond");
        /*cond*/
        if (/*_#IS_A__L7*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-macro.melt:6687:/ quasiblock");


                    /*^getslot*/
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]) /*=obj*/;
                        melt_object_get_field(slot,obj, 2, "SYMB_DATA");
                        /*_.CTY__V31*/
                        meltfptr[30] = slot;
                    };
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6688:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]) /*=obj*/;
                        melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                        /*_.TYNAM__V32*/
                        meltfptr[31] = slot;
                    };
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#IS_NOT_A__L8*/
                    meltfnum[7] =
                        !melt_is_instance_of((melt_ptr_t)(/*_.CTY__V31*/ meltfptr[30]), (melt_ptr_t)((/*!CLASS_QUASI_CTYPE*/ meltfrout->tabval[7])));;
                    MELT_LOCATION("warmelt-macro.melt:6691:/ cond");
                    /*cond*/
                    if (/*_#IS_NOT_A__L8*/ meltfnum[7]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {




                                {
                                    MELT_LOCATION("warmelt-macro.melt:6692:/ locexp");
                                    melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "letbinding with invalid type keyword"), (melt_ptr_t)(/*_.TYNAM__V32*/ meltfptr[31]));
                                }
                                ;
                                /*clear*/ /*_._IFELSE___V33*/
                                meltfptr[32] = 0 ;
                                /*epilog*/
                            }
                            ;
                        }
                    else
                        {
                            MELT_LOCATION("warmelt-macro.melt:6691:/ cond.else");

                            /*^block*/
                            /*anyblock*/
                            {


                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6693:/ cond");
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CTY__V31*/ meltfptr[30]),
                                                                  (melt_ptr_t)((/*!CLASS_QUASI_CTYPE*/ meltfrout->tabval[7])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.CTY__V31*/ meltfptr[30]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 2, "CTYPE_KEYWORD");
                                            /*_.CTYPE_KEYWORD__V34*/
                                            meltfptr[33] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.CTYPE_KEYWORD__V34*/ meltfptr[33] =  /*reallynil*/ NULL ;;
                                    }
                                ;
                                /*^compute*/
                                /*_#eqeq__L9*/
                                meltfnum[8] =
                                    ((/*_.CTYPE_KEYWORD__V34*/ meltfptr[33]) == (/*_.CURARG__V26*/ meltfptr[25]));;
                                MELT_LOCATION("warmelt-macro.melt:6693:/ cond");
                                /*cond*/
                                if (/*_#eqeq__L9*/ meltfnum[8]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            MELT_LOCATION("warmelt-macro.melt:6694:/ compute");
                                            /*_.CTYP__V22*/
                                            meltfptr[21] = /*_.SETQ___V36*/ meltfptr[35] = /*_.CTY__V31*/ meltfptr[30];;
                                            /*_._IFELSE___V35*/
                                            meltfptr[34] = /*_.SETQ___V36*/ meltfptr[35];;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6693:/ clear");
                                            /*clear*/ /*_.SETQ___V36*/
                                            meltfptr[35] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*^block*/
                                        /*anyblock*/
                                        {


                                            MELT_CHECK_SIGNAL();
                                            ;
                                            MELT_LOCATION("warmelt-macro.melt:6695:/ cond");
                                            /*cond*/
                                            if (
                                                /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CTY__V31*/ meltfptr[30]),
                                                                              (melt_ptr_t)((/*!CLASS_CTYPE*/ meltfrout->tabval[8])))
                                            ) /*then*/
                                                {
                                                    /*^cond.then*/
                                                    /*^getslot*/
                                                    {
                                                        melt_ptr_t slot=NULL, obj=NULL;
                                                        obj = (melt_ptr_t)(/*_.CTY__V31*/ meltfptr[30]) /*=obj*/;
                                                        melt_object_get_field(slot,obj, 10, "CTYPE_ALTKEYWORD");
                                                        /*_.CTYPE_ALTKEYWORD__V37*/
                                                        meltfptr[35] = slot;
                                                    };
                                                    ;
                                                }
                                            else    /*^cond.else*/
                                                {

                                                    /*_.CTYPE_ALTKEYWORD__V37*/ meltfptr[35] =  /*reallynil*/ NULL ;;
                                                }
                                            ;
                                            /*^compute*/
                                            /*_#eqeq__L10*/
                                            meltfnum[9] =
                                                ((/*_.CTYPE_ALTKEYWORD__V37*/ meltfptr[35]) == (/*_.CURARG__V26*/ meltfptr[25]));;
                                            MELT_LOCATION("warmelt-macro.melt:6695:/ cond");
                                            /*cond*/
                                            if (/*_#eqeq__L10*/ meltfnum[9]) /*then*/
                                                {
                                                    /*^cond.then*/
                                                    /*^block*/
                                                    /*anyblock*/
                                                    {

                                                        MELT_LOCATION("warmelt-macro.melt:6696:/ compute");
                                                        /*_.CTYP__V22*/
                                                        meltfptr[21] = /*_.SETQ___V38*/ meltfptr[37] = /*_.CTY__V31*/ meltfptr[30];;

                                                        {
                                                            MELT_LOCATION("warmelt-macro.melt:6697:/ locexp");
                                                            melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "obsolete alternate ctype keyword in let binding"), (melt_ptr_t)(/*_.TYNAM__V32*/ meltfptr[31]));
                                                        }
                                                        ;
                                                        MELT_LOCATION("warmelt-macro.melt:6699:/ cond");
                                                        /*cond*/
                                                        if (
                                                            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CTYP__V22*/ meltfptr[21]),
                                                                                          (melt_ptr_t)((/*!CLASS_QUASI_CTYPE*/ meltfrout->tabval[7])))
                                                        ) /*then*/
                                                            {
                                                                /*^cond.then*/
                                                                /*^getslot*/
                                                                {
                                                                    melt_ptr_t slot=NULL, obj=NULL;
                                                                    obj = (melt_ptr_t)(/*_.CTYP__V22*/ meltfptr[21]) /*=obj*/;
                                                                    melt_object_get_field(slot,obj, 2, "CTYPE_KEYWORD");
                                                                    /*_.CTYPE_KEYWORD__V39*/
                                                                    meltfptr[38] = slot;
                                                                };
                                                                ;
                                                            }
                                                        else    /*^cond.else*/
                                                            {

                                                                /*_.CTYPE_KEYWORD__V39*/ meltfptr[38] =  /*reallynil*/ NULL ;;
                                                            }
                                                        ;
                                                        MELT_LOCATION("warmelt-macro.melt:6699:/ cond");
                                                        /*cond*/
                                                        if (
                                                            /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CTYPE_KEYWORD__V39*/ meltfptr[38]),
                                                                                          (melt_ptr_t)((/*!CLASS_NAMED*/ meltfrout->tabval[9])))
                                                        ) /*then*/
                                                            {
                                                                /*^cond.then*/
                                                                /*^getslot*/
                                                                {
                                                                    melt_ptr_t slot=NULL, obj=NULL;
                                                                    obj = (melt_ptr_t)(/*_.CTYPE_KEYWORD__V39*/ meltfptr[38]) /*=obj*/;
                                                                    melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                                                                    /*_.NAMED_NAME__V40*/
                                                                    meltfptr[39] = slot;
                                                                };
                                                                ;
                                                            }
                                                        else    /*^cond.else*/
                                                            {

                                                                /*_.NAMED_NAME__V40*/ meltfptr[39] =  /*reallynil*/ NULL ;;
                                                            }
                                                        ;

                                                        {
                                                            MELT_LOCATION("warmelt-macro.melt:6699:/ locexp");
                                                            melt_inform_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "prefered ctype keyword"), (melt_ptr_t)(/*_.NAMED_NAME__V40*/ meltfptr[39]));
                                                        }
                                                        ;
                                                        MELT_LOCATION("warmelt-macro.melt:6695:/ quasiblock");


                                                        /*epilog*/

                                                        /*^clear*/
                                                        /*clear*/ /*_.SETQ___V38*/
                                                        meltfptr[37] = 0 ;
                                                        /*^clear*/
                                                        /*clear*/ /*_.CTYPE_KEYWORD__V39*/
                                                        meltfptr[38] = 0 ;
                                                        /*^clear*/
                                                        /*clear*/ /*_.NAMED_NAME__V40*/
                                                        meltfptr[39] = 0 ;
                                                    }
                                                    ;
                                                }
                                            else    /*^cond.else*/
                                                {

                                                    /*^block*/
                                                    /*anyblock*/
                                                    {


                                                        {
                                                            MELT_LOCATION("warmelt-macro.melt:6702:/ locexp");
                                                            melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "let-binding with invalid type keyword"), (melt_ptr_t)(/*_.TYNAM__V32*/ meltfptr[31]));
                                                        }
                                                        ;
                                                        MELT_LOCATION("warmelt-macro.melt:6701:/ quasiblock");


                                                        /*epilog*/
                                                    }
                                                    ;
                                                }
                                            ;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6693:/ clear");
                                            /*clear*/ /*_.CTYPE_ALTKEYWORD__V37*/
                                            meltfptr[35] = 0 ;
                                            /*^clear*/
                                            /*clear*/ /*_#eqeq__L10*/
                                            meltfnum[9] = 0 ;
                                        }
                                        ;
                                    }
                                ;
                                /*_._IFELSE___V33*/
                                meltfptr[32] = /*_._IFELSE___V35*/ meltfptr[34];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6691:/ clear");
                                /*clear*/ /*_.CTYPE_KEYWORD__V34*/
                                meltfptr[33] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_#eqeq__L9*/
                                meltfnum[8] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IFELSE___V35*/
                                meltfptr[34] = 0 ;
                            }
                            ;
                        }
                    ;
                    /*_.PAIR_TAIL__V41*/
                    meltfptr[37] =
                        (melt_pair_tail((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                    MELT_LOCATION("warmelt-macro.melt:6704:/ compute");
                    /*_.CURPAIR__V25*/
                    meltfptr[24] = /*_.SETQ___V42*/ meltfptr[38] = /*_.PAIR_TAIL__V41*/ meltfptr[37];;
                    /*_.PAIR_HEAD__V43*/
                    meltfptr[39] =
                        (melt_pair_head((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                    MELT_LOCATION("warmelt-macro.melt:6705:/ compute");
                    /*_.CURARG__V26*/
                    meltfptr[25] = /*_.SETQ___V44*/ meltfptr[35] = /*_.PAIR_HEAD__V43*/ meltfptr[39];;
                    /*_.LET___V30*/
                    meltfptr[29] = /*_.SETQ___V44*/ meltfptr[35];;

                    MELT_LOCATION("warmelt-macro.melt:6687:/ clear");
                    /*clear*/ /*_.CTY__V31*/
                    meltfptr[30] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.TYNAM__V32*/
                    meltfptr[31] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#IS_NOT_A__L8*/
                    meltfnum[7] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IFELSE___V33*/
                    meltfptr[32] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PAIR_TAIL__V41*/
                    meltfptr[37] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V42*/
                    meltfptr[38] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PAIR_HEAD__V43*/
                    meltfptr[39] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V44*/
                    meltfptr[35] = 0 ;
                    /*_._IF___V29*/
                    meltfptr[28] = /*_.LET___V30*/ meltfptr[29];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6686:/ clear");
                    /*clear*/ /*_.LET___V30*/
                    meltfptr[29] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V29*/ meltfptr[28] =  /*reallynil*/ NULL ;;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#IS_A__L11*/
        meltfnum[9] =
            melt_is_instance_of((melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]), (melt_ptr_t)((/*!CLASS_KEYWORD*/ meltfrout->tabval[6])));;
        MELT_LOCATION("warmelt-macro.melt:6708:/ cond");
        /*cond*/
        if (/*_#IS_A__L11*/ meltfnum[9]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-macro.melt:6710:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]) /*=obj*/;
                        melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                        /*_.NAMED_NAME__V46*/
                        meltfptr[34] = slot;
                    };
                    ;



                    {
                        MELT_LOCATION("warmelt-macro.melt:6709:/ locexp");
                        melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "letbinding cannot bind keyword"), (melt_ptr_t)(/*_.NAMED_NAME__V46*/ meltfptr[34]));
                    }
                    ;
                    /*clear*/ /*_._IFELSE___V45*/
                    meltfptr[33] = 0 ;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6708:/ clear");
                    /*clear*/ /*_.NAMED_NAME__V46*/
                    meltfptr[34] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#IS_A__L12*/
                    meltfnum[8] =
                        melt_is_instance_of((melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]), (melt_ptr_t)((/*!CLASS_SYMBOL*/ meltfrout->tabval[10])));;
                    MELT_LOCATION("warmelt-macro.melt:6711:/ cond");
                    /*cond*/
                    if (/*_#IS_A__L12*/ meltfnum[8]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                MELT_LOCATION("warmelt-macro.melt:6712:/ compute");
                                /*_.VAR__V23*/
                                meltfptr[22] = /*_.SETQ___V48*/ meltfptr[31] = /*_.CURARG__V26*/ meltfptr[25];;
                                /*_.PAIR_TAIL__V49*/
                                meltfptr[32] =
                                    (melt_pair_tail((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                                MELT_LOCATION("warmelt-macro.melt:6713:/ compute");
                                /*_.CURPAIR__V25*/
                                meltfptr[24] = /*_.SETQ___V50*/ meltfptr[37] = /*_.PAIR_TAIL__V49*/ meltfptr[32];;
                                /*_.PAIR_HEAD__V51*/
                                meltfptr[38] =
                                    (melt_pair_head((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                                MELT_LOCATION("warmelt-macro.melt:6714:/ compute");
                                /*_.CURARG__V26*/
                                meltfptr[25] = /*_.SETQ___V52*/ meltfptr[39] = /*_.PAIR_HEAD__V51*/ meltfptr[38];;
                                MELT_LOCATION("warmelt-macro.melt:6711:/ quasiblock");


                                /*_.PROGN___V53*/
                                meltfptr[35] = /*_.SETQ___V52*/ meltfptr[39];;
                                /*^compute*/
                                /*_._IFELSE___V47*/
                                meltfptr[30] = /*_.PROGN___V53*/ meltfptr[35];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6711:/ clear");
                                /*clear*/ /*_.SETQ___V48*/
                                meltfptr[31] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.PAIR_TAIL__V49*/
                                meltfptr[32] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V50*/
                                meltfptr[37] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.PAIR_HEAD__V51*/
                                meltfptr[38] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V52*/
                                meltfptr[39] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.PROGN___V53*/
                                meltfptr[35] = 0 ;
                            }
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_._IFELSE___V47*/ meltfptr[30] =  /*reallynil*/ NULL ;;
                        }
                    ;
                    /*^compute*/
                    /*_._IFELSE___V45*/
                    meltfptr[33] = /*_._IFELSE___V47*/ meltfptr[30];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6708:/ clear");
                    /*clear*/ /*_#IS_A__L12*/
                    meltfnum[8] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IFELSE___V47*/
                    meltfptr[30] = 0 ;
                }
                ;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#NULL__L13*/
        meltfnum[7] =
            ((/*_.VAR__V23*/ meltfptr[22]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6716:/ cond");
        /*cond*/
        if (/*_#NULL__L13*/ meltfnum[7]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6717:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "missing variable in letbinding"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#eqeq__L14*/
        meltfnum[8] =
            ((/*_.CTYP__V22*/ meltfptr[21]) == ((/*!QUASI_CTYPE_MACRO*/ meltfrout->tabval[11])));;
        MELT_LOCATION("warmelt-macro.melt:6720:/ cond");
        /*cond*/
        if (/*_#eqeq__L14*/ meltfnum[8]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    MELT_LOCATION("warmelt-macro.melt:6721:/ quasiblock");



                    MELT_CHECK_SIGNAL();
                    ;
                    /*^apply*/
                    /*apply*/
                    {
                        union meltparam_un argtab[1];
                        memset(&argtab, 0, sizeof(argtab));
                        /*^apply.arg*/
                        argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!konst_13_TRUE*/ meltfrout->tabval[13]);
                        /*_.MACFORMALS__V56*/
                        meltfptr[31] =  melt_apply ((meltclosure_ptr_t)((/*!LAMBDA_ARG_BINDINGS*/ meltfrout->tabval[12])), (melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                    }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6722:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]) /*=obj*/;
                        melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                        /*_.VARNAME__V57*/
                        meltfptr[32] = slot;
                    };
                    ;
                    /*_.MACBODY__V58*/
                    meltfptr[37] = (/*nil*/NULL);;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6724:/ apply");
                    /*apply*/
                    {
                        /*_.NEWENV__V59*/ meltfptr[38] =  melt_apply ((meltclosure_ptr_t)((/*!FRESH_ENV*/ meltfrout->tabval[14])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
                    }
                    ;

#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6726:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                            melt_dbgcounter++;
#endif
                            ;
                        }
                        ;

                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#MELT_NEED_DBG__L15*/
                        meltfnum[14] =
                            /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                            (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                            0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                            ;;
                        MELT_LOCATION("warmelt-macro.melt:6726:/ cond");
                        /*cond*/
                        if (/*_#MELT_NEED_DBG__L15*/ meltfnum[14]) /*then*/
                            {
                                /*^cond.then*/
                                /*^block*/
                                /*anyblock*/
                                {

                                    /*_#MELT_CALLCOUNT__L16*/ meltfnum[15] =
                                        /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                        meltcallcount  /* melt_callcount debugging */
#else
                                        0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                        ;;

                                    MELT_CHECK_SIGNAL();
                                    ;
                                    MELT_LOCATION("warmelt-macro.melt:6726:/ apply");
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[5];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L16*/ meltfnum[15];
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6726;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_cstring =  "mexpand_letbinding macformals=";
                                        /*^apply.arg*/
                                        argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.MACFORMALS__V56*/ meltfptr[31];
                                        /*_.MELT_DEBUG_FUN__V61*/
                                        meltfptr[35] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IF___V60*/
                                    meltfptr[39] = /*_.MELT_DEBUG_FUN__V61*/ meltfptr[35];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6726:/ clear");
                                    /*clear*/ /*_#MELT_CALLCOUNT__L16*/
                                    meltfnum[15] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_.MELT_DEBUG_FUN__V61*/
                                    meltfptr[35] = 0 ;
                                }
                                ;
                            }
                        else    /*^cond.else*/
                            {

                                /*_._IF___V60*/ meltfptr[39] =  /*reallynil*/ NULL ;;
                            }
                        ;

                        {
                            MELT_LOCATION("warmelt-macro.melt:6726:/ locexp");
                            /*void*/
                            (void)0;
                        }
                        ;
                        /*^quasiblock*/


                        /*epilog*/

                        /*^clear*/
                        /*clear*/ /*_#MELT_NEED_DBG__L15*/
                        meltfnum[14] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IF___V60*/
                        meltfptr[39] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*void*/(void)0;
                        }
                        ;
                        /*epilog*/
                    }

#endif /*MELT_HAVE_DEBUG*/
                    ;
                    /*_.PAIR_TAIL__V62*/
                    meltfptr[30] =
                        (melt_pair_tail((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                    MELT_LOCATION("warmelt-macro.melt:6727:/ compute");
                    /*_.CURPAIR__V25*/
                    meltfptr[24] = /*_.SETQ___V63*/ meltfptr[35] = /*_.PAIR_TAIL__V62*/ meltfptr[30];;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#IS_A__L17*/
                    meltfnum[15] =
                        melt_is_instance_of((melt_ptr_t)(/*_.MACFORMALS__V56*/ meltfptr[31]), (melt_ptr_t)((/*!DISCR_VARIADIC_FORMAL_SEQUENCE*/ meltfrout->tabval[15])));;
                    MELT_LOCATION("warmelt-macro.melt:6728:/ cond");
                    /*cond*/
                    if (/*_#IS_A__L17*/ meltfnum[15]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    MELT_LOCATION("warmelt-macro.melt:6729:/ locexp");
                                    melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( ":macro let-binding cannot be variadic"), (melt_ptr_t)(/*_.VARNAME__V57*/ meltfptr[32]));
                                }
                                ;
                                /*epilog*/
                            }
                            ;
                        } /*noelse*/
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#MULTIPLE_LENGTH__L18*/
                    meltfnum[14] =
                        (melt_multiple_length((melt_ptr_t)(/*_.MACFORMALS__V56*/ meltfptr[31])));;
                    /*^compute*/
                    /*_#gtI__L19*/
                    meltfnum[18] =
                        ((/*_#MULTIPLE_LENGTH__L18*/ meltfnum[14]) > (4));;
                    MELT_LOCATION("warmelt-macro.melt:6730:/ cond");
                    /*cond*/
                    if (/*_#gtI__L19*/ meltfnum[18]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    MELT_LOCATION("warmelt-macro.melt:6731:/ locexp");
                                    melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( ":macro let-binding should have at most 4 formals"), (melt_ptr_t)(/*_.VARNAME__V57*/ meltfptr[32]));
                                }
                                ;
                                /*epilog*/
                            }
                            ;
                        } /*noelse*/
                    ;
                    /*citerblock FOREACH_IN_MULTIPLE*/
                    {
                        /* start foreach_in_multiple meltcit1__EACHTUP */
                        long  meltcit1__EACHTUP_ln = melt_multiple_length((melt_ptr_t)/*_.MACFORMALS__V56*/ meltfptr[31]);
                        for (/*_#IX__L20*/ meltfnum[19] = 0;
                                           (/*_#IX__L20*/ meltfnum[19] >= 0) && (/*_#IX__L20*/ meltfnum[19] <  meltcit1__EACHTUP_ln);
                                           /*_#IX__L20*/ meltfnum[19]++)
                            {
                                /*_.CURMACFORMAL__V64*/ meltfptr[39] = melt_multiple_nth((melt_ptr_t)(/*_.MACFORMALS__V56*/ meltfptr[31]),  /*_#IX__L20*/ meltfnum[19]);




#if MELT_HAVE_DEBUG
                                MELT_LOCATION("warmelt-macro.melt:6735:/ cppif.then");
                                /*^block*/
                                /*anyblock*/
                                {


                                    {
                                        /*^locexp*/
                                        /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                                        melt_dbgcounter++;
#endif
                                        ;
                                    }
                                    ;

                                    MELT_CHECK_SIGNAL();
                                    ;
                                    /*_#MELT_NEED_DBG__L21*/
                                    meltfnum[20] =
                                        /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                                        (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                                        0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                                        ;;
                                    MELT_LOCATION("warmelt-macro.melt:6735:/ cond");
                                    /*cond*/
                                    if (/*_#MELT_NEED_DBG__L21*/ meltfnum[20]) /*then*/
                                        {
                                            /*^cond.then*/
                                            /*^block*/
                                            /*anyblock*/
                                            {

                                                /*_#MELT_CALLCOUNT__L22*/ meltfnum[21] =
                                                    /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                                    meltcallcount  /* melt_callcount debugging */
#else
                                                    0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                                    ;;

                                                MELT_CHECK_SIGNAL();
                                                ;
                                                MELT_LOCATION("warmelt-macro.melt:6735:/ apply");
                                                /*apply*/
                                                {
                                                    union meltparam_un argtab[5];
                                                    memset(&argtab, 0, sizeof(argtab));
                                                    /*^apply.arg*/
                                                    argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L22*/ meltfnum[21];
                                                    /*^apply.arg*/
                                                    argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                    /*^apply.arg*/
                                                    argtab[2].meltbp_long = 6735;
                                                    /*^apply.arg*/
                                                    argtab[3].meltbp_cstring =  "mexpand_letbinding curmacformal=";
                                                    /*^apply.arg*/
                                                    argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.CURMACFORMAL__V64*/ meltfptr[39];
                                                    /*_.MELT_DEBUG_FUN__V66*/
                                                    meltfptr[65] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                                }
                                                ;
                                                /*_._IF___V65*/
                                                meltfptr[64] = /*_.MELT_DEBUG_FUN__V66*/ meltfptr[65];;
                                                /*epilog*/

                                                MELT_LOCATION("warmelt-macro.melt:6735:/ clear");
                                                /*clear*/ /*_#MELT_CALLCOUNT__L22*/
                                                meltfnum[21] = 0 ;
                                                /*^clear*/
                                                /*clear*/ /*_.MELT_DEBUG_FUN__V66*/
                                                meltfptr[65] = 0 ;
                                            }
                                            ;
                                        }
                                    else    /*^cond.else*/
                                        {

                                            /*_._IF___V65*/ meltfptr[64] =  /*reallynil*/ NULL ;;
                                        }
                                    ;

                                    {
                                        MELT_LOCATION("warmelt-macro.melt:6735:/ locexp");
                                        /*void*/
                                        (void)0;
                                    }
                                    ;
                                    /*^quasiblock*/


                                    /*epilog*/

                                    /*^clear*/
                                    /*clear*/ /*_#MELT_NEED_DBG__L21*/
                                    meltfnum[20] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_._IF___V65*/
                                    meltfptr[64] = 0 ;
                                }

#else /*MELT_HAVE_DEBUG*/
                                /*^cppif.else*/
                                /*^block*/
                                /*anyblock*/
                                {


                                    {
                                        /*^locexp*/
                                        /*void*/(void)0;
                                    }
                                    ;
                                    /*epilog*/
                                }

#endif /*MELT_HAVE_DEBUG*/
                                ;

#if MELT_HAVE_DEBUG
                                MELT_LOCATION("warmelt-macro.melt:6736:/ cppif.then");
                                /*^block*/
                                /*anyblock*/
                                {


                                    MELT_CHECK_SIGNAL();
                                    ;
                                    /*_#IS_A__L23*/
                                    meltfnum[21] =
                                        melt_is_instance_of((melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]), (melt_ptr_t)((/*!CLASS_FORMAL_BINDING*/ meltfrout->tabval[16])));;
                                    MELT_LOCATION("warmelt-macro.melt:6736:/ cond");
                                    /*cond*/
                                    if (/*_#IS_A__L23*/ meltfnum[21]) /*then*/
                                        {
                                            /*^cond.then*/
                                            /*_._IFELSE___V68*/ meltfptr[64] = (/*nil*/NULL);;
                                        }
                                    else
                                        {
                                            MELT_LOCATION("warmelt-macro.melt:6736:/ cond.else");

                                            /*^block*/
                                            /*anyblock*/
                                            {


                                                MELT_CHECK_SIGNAL();
                                                ;
                                                /*^apply*/
                                                /*apply*/
                                                {
                                                    union meltparam_un argtab[4];
                                                    memset(&argtab, 0, sizeof(argtab));
                                                    /*^apply.arg*/
                                                    argtab[0].meltbp_cstring =  "check curmacformal";
                                                    /*^apply.arg*/
                                                    argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                                    /*^apply.arg*/
                                                    argtab[2].meltbp_long = 6736;
                                                    /*^apply.arg*/
                                                    argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.CURMACFORMAL__V64*/ meltfptr[39];
                                                    /*_.MELT_ASSERT_FAILURE_FUN__V69*/
                                                    meltfptr[68] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                                }
                                                ;
                                                /*_._IFELSE___V68*/
                                                meltfptr[64] = /*_.MELT_ASSERT_FAILURE_FUN__V69*/ meltfptr[68];;
                                                /*epilog*/

                                                MELT_LOCATION("warmelt-macro.melt:6736:/ clear");
                                                /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V69*/
                                                meltfptr[68] = 0 ;
                                            }
                                            ;
                                        }
                                    ;
                                    /*_.IFCPP___V67*/
                                    meltfptr[65] = /*_._IFELSE___V68*/ meltfptr[64];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6736:/ clear");
                                    /*clear*/ /*_#IS_A__L23*/
                                    meltfnum[21] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_._IFELSE___V68*/
                                    meltfptr[64] = 0 ;
                                }

#else /*MELT_HAVE_DEBUG*/
                                /*^cppif.else*/
                                /*_.IFCPP___V67*/ meltfptr[65] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6737:/ quasiblock");


                                /*^cond*/
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]),
                                                                  (melt_ptr_t)((/*!CLASS_ANY_BINDING*/ meltfrout->tabval[17])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 0, "BINDER");
                                            /*_.BINDER__V71*/
                                            meltfptr[64] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.BINDER__V71*/ meltfptr[64] =  /*reallynil*/ NULL ;;
                                    }
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6737:/ cond");
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.BINDER__V71*/ meltfptr[64]),
                                                                  (melt_ptr_t)((/*!CLASS_NAMED*/ meltfrout->tabval[9])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.BINDER__V71*/ meltfptr[64]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                                            /*_.CURFORMALNAME__V72*/
                                            meltfptr[71] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.CURFORMALNAME__V72*/ meltfptr[71] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6739:/ cond");
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]),
                                                                  (melt_ptr_t)((/*!CLASS_FORMAL_BINDING*/ meltfrout->tabval[16])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 1, "FBIND_TYPE");
                                            /*_.FBIND_TYPE__V73*/
                                            meltfptr[72] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.FBIND_TYPE__V73*/ meltfptr[72] =  /*reallynil*/ NULL ;;
                                    }
                                ;
                                /*^compute*/
                                /*_#exeq__L24*/
                                meltfnum[20] =
                                    ((/*_.FBIND_TYPE__V73*/ meltfptr[72]) != ((/*!CTYPE_VALUE*/ meltfrout->tabval[18])));;
                                MELT_LOCATION("warmelt-macro.melt:6739:/ cond");
                                /*cond*/
                                if (/*_#exeq__L24*/ meltfnum[20]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {


                                            {
                                                MELT_LOCATION("warmelt-macro.melt:6740:/ locexp");
                                                melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( ":macro let-binding should be :value"), (melt_ptr_t)(/*_.CURFORMALNAME__V72*/ meltfptr[71]));
                                            }
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6741:/ cond");
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]),
                                                                  (melt_ptr_t)((/*!CLASS_ANY_BINDING*/ meltfrout->tabval[17])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.CURMACFORMAL__V64*/ meltfptr[39]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 0, "BINDER");
                                            /*_.BINDER__V74*/
                                            meltfptr[73] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.BINDER__V74*/ meltfptr[73] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6741:/ apply");
                                /*apply*/
                                {
                                    union meltparam_un argtab[1];
                                    memset(&argtab, 0, sizeof(argtab));
                                    /*^apply.arg*/
                                    argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.BINDER__V74*/ meltfptr[73];
                                    /*_.FIND_ENV__V75*/
                                    meltfptr[74] =  melt_apply ((meltclosure_ptr_t)((/*!FIND_ENV*/ meltfrout->tabval[19])), (melt_ptr_t)(/*_.NEWENV__V59*/ meltfptr[38]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                }
                                ;
                                /*^cond*/
                                /*cond*/
                                if (/*_.FIND_ENV__V75*/ meltfptr[74]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {


                                            {
                                                MELT_LOCATION("warmelt-macro.melt:6742:/ locexp");
                                                melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( ":macro formal already bound"), (melt_ptr_t)(/*_.CURFORMALNAME__V72*/ meltfptr[71]));
                                            }
                                            ;
                                            /*epilog*/
                                        }
                                        ;
                                    } /*noelse*/
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6743:/ apply");
                                /*apply*/
                                {
                                    union meltparam_un argtab[1];
                                    memset(&argtab, 0, sizeof(argtab));
                                    /*^apply.arg*/
                                    argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.CURMACFORMAL__V64*/ meltfptr[39];
                                    /*_.PUT_ENV__V76*/
                                    meltfptr[75] =  melt_apply ((meltclosure_ptr_t)((/*!PUT_ENV*/ meltfrout->tabval[20])), (melt_ptr_t)(/*_.NEWENV__V59*/ meltfptr[38]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                }
                                ;
                                /*_.LET___V70*/
                                meltfptr[68] = /*_.PUT_ENV__V76*/ meltfptr[75];;

                                MELT_LOCATION("warmelt-macro.melt:6737:/ clear");
                                /*clear*/ /*_.BINDER__V71*/
                                meltfptr[64] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.CURFORMALNAME__V72*/
                                meltfptr[71] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.FBIND_TYPE__V73*/
                                meltfptr[72] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_#exeq__L24*/
                                meltfnum[20] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.BINDER__V74*/
                                meltfptr[73] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.FIND_ENV__V75*/
                                meltfptr[74] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.PUT_ENV__V76*/
                                meltfptr[75] = 0 ;
                                if (/*_#IX__L20*/ meltfnum[19]<0) break;
                            } /* end  foreach_in_multiple meltcit1__EACHTUP */

                        /*citerepilog*/

                        MELT_LOCATION("warmelt-macro.melt:6732:/ clear");
                        /*clear*/ /*_.CURMACFORMAL__V64*/
                        meltfptr[39] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_#IX__L20*/
                        meltfnum[19] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.IFCPP___V67*/
                        meltfptr[65] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.LET___V70*/
                        meltfptr[68] = 0 ;
                    } /*endciterblock FOREACH_IN_MULTIPLE*/
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6745:/ apply");
                    /*apply*/
                    {
                        union meltparam_un argtab[3];
                        memset(&argtab, 0, sizeof(argtab));
                        /*^apply.arg*/
                        argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.NEWENV__V59*/ meltfptr[38];
                        /*^apply.arg*/
                        argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
                        /*^apply.arg*/
                        argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                        /*_.EXPAND_PAIRLIST_AS_TUPLE__V77*/
                        meltfptr[64] =  melt_apply ((meltclosure_ptr_t)((/*!EXPAND_PAIRLIST_AS_TUPLE*/ meltfrout->tabval[21])), (melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                    }
                    ;
                    /*^compute*/
                    /*_.MACBODY__V58*/
                    meltfptr[37] = /*_.SETQ___V78*/ meltfptr[71] = /*_.EXPAND_PAIRLIST_AS_TUPLE__V77*/ meltfptr[64];;

#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6746:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                            melt_dbgcounter++;
#endif
                            ;
                        }
                        ;

                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#MELT_NEED_DBG__L25*/
                        meltfnum[21] =
                            /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                            (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                            0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                            ;;
                        MELT_LOCATION("warmelt-macro.melt:6746:/ cond");
                        /*cond*/
                        if (/*_#MELT_NEED_DBG__L25*/ meltfnum[21]) /*then*/
                            {
                                /*^cond.then*/
                                /*^block*/
                                /*anyblock*/
                                {

                                    /*_#MELT_CALLCOUNT__L26*/ meltfnum[20] =
                                        /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                        meltcallcount  /* melt_callcount debugging */
#else
                                        0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                        ;;

                                    MELT_CHECK_SIGNAL();
                                    ;
                                    MELT_LOCATION("warmelt-macro.melt:6746:/ apply");
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[5];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L26*/ meltfnum[20];
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6746;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_cstring =  "mexpand_letbinding macbody=";
                                        /*^apply.arg*/
                                        argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.MACBODY__V58*/ meltfptr[37];
                                        /*_.MELT_DEBUG_FUN__V80*/
                                        meltfptr[73] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IF___V79*/
                                    meltfptr[72] = /*_.MELT_DEBUG_FUN__V80*/ meltfptr[73];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6746:/ clear");
                                    /*clear*/ /*_#MELT_CALLCOUNT__L26*/
                                    meltfnum[20] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_.MELT_DEBUG_FUN__V80*/
                                    meltfptr[73] = 0 ;
                                }
                                ;
                            }
                        else    /*^cond.else*/
                            {

                                /*_._IF___V79*/ meltfptr[72] =  /*reallynil*/ NULL ;;
                            }
                        ;

                        {
                            MELT_LOCATION("warmelt-macro.melt:6746:/ locexp");
                            /*void*/
                            (void)0;
                        }
                        ;
                        /*^quasiblock*/


                        /*epilog*/

                        /*^clear*/
                        /*clear*/ /*_#MELT_NEED_DBG__L25*/
                        meltfnum[21] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IF___V79*/
                        meltfptr[72] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*void*/(void)0;
                        }
                        ;
                        /*epilog*/
                    }

#endif /*MELT_HAVE_DEBUG*/
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6747:/ quasiblock");



                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6748:/ quasiblock");


                    /*^rawallocobj*/
                    /*rawallocobj*/
                    {
                        melt_ptr_t newobj = 0;
                        melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_MACRO_LET_BINDING*/ meltfrout->tabval[22])), (5), "CLASS_SOURCE_MACRO_LET_BINDING");
                        /*_.INST__V83*/
                        meltfptr[73] =
                            newobj;
                    };
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V83*/ meltfptr[73])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V83*/ meltfptr[73]), (1), (/*_.LOC__V21*/ meltfptr[20]), "LOCA_LOCATION");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @SLETB_BINDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V83*/ meltfptr[73])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V83*/ meltfptr[73]), (2), (/*_.VAR__V23*/ meltfptr[22]), "SLETB_BINDER");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @SLETM_MACRO_FORMALS", melt_magic_discr((melt_ptr_t)(/*_.INST__V83*/ meltfptr[73])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V83*/ meltfptr[73]), (3), (/*_.MACFORMALS__V56*/ meltfptr[31]), "SLETM_MACRO_FORMALS");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @SLETM_MACRO_BODY", melt_magic_discr((melt_ptr_t)(/*_.INST__V83*/ meltfptr[73])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V83*/ meltfptr[73]), (4), (/*_.MACBODY__V58*/ meltfptr[37]), "SLETM_MACRO_BODY");
                    ;
                    /*^touchobj*/

                    melt_dbgtrace_written_object (/*_.INST__V83*/ meltfptr[73], "newly made instance");
                    ;
                    /*_.SMACBIND__V82*/
                    meltfptr[75] = /*_.INST__V83*/ meltfptr[73];;

#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6755:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                            melt_dbgcounter++;
#endif
                            ;
                        }
                        ;

                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#MELT_NEED_DBG__L27*/
                        meltfnum[20] =
                            /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                            (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                            0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                            ;;
                        MELT_LOCATION("warmelt-macro.melt:6755:/ cond");
                        /*cond*/
                        if (/*_#MELT_NEED_DBG__L27*/ meltfnum[20]) /*then*/
                            {
                                /*^cond.then*/
                                /*^block*/
                                /*anyblock*/
                                {

                                    /*_#MELT_CALLCOUNT__L28*/ meltfnum[21] =
                                        /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                        meltcallcount  /* melt_callcount debugging */
#else
                                        0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                        ;;

                                    MELT_CHECK_SIGNAL();
                                    ;
                                    MELT_LOCATION("warmelt-macro.melt:6755:/ apply");
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[5];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L28*/ meltfnum[21];
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6755;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_cstring =  "mexpand_letbinding smacbind=";
                                        /*^apply.arg*/
                                        argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SMACBIND__V82*/ meltfptr[75];
                                        /*_.MELT_DEBUG_FUN__V85*/
                                        meltfptr[84] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IF___V84*/
                                    meltfptr[72] = /*_.MELT_DEBUG_FUN__V85*/ meltfptr[84];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6755:/ clear");
                                    /*clear*/ /*_#MELT_CALLCOUNT__L28*/
                                    meltfnum[21] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_.MELT_DEBUG_FUN__V85*/
                                    meltfptr[84] = 0 ;
                                }
                                ;
                            }
                        else    /*^cond.else*/
                            {

                                /*_._IF___V84*/ meltfptr[72] =  /*reallynil*/ NULL ;;
                            }
                        ;

                        {
                            MELT_LOCATION("warmelt-macro.melt:6755:/ locexp");
                            /*void*/
                            (void)0;
                        }
                        ;
                        /*^quasiblock*/


                        /*epilog*/

                        /*^clear*/
                        /*clear*/ /*_#MELT_NEED_DBG__L27*/
                        meltfnum[20] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IF___V84*/
                        meltfptr[72] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*void*/(void)0;
                        }
                        ;
                        /*epilog*/
                    }

#endif /*MELT_HAVE_DEBUG*/
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6756:/ quasiblock");


                    /*_._RETVAL___V1*/
                    meltfptr[0] = /*_.SMACBIND__V82*/ meltfptr[75];;

                    {
                        MELT_LOCATION("warmelt-macro.melt:6756:/ locexp");
                        /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
                        if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                            melt_warn_for_no_expected_secondary_results();
                        /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
                        ;
                    }
                    ;
                    /*^finalreturn*/
                    ;
                    /*finalret*/
                    goto meltlabend_rout ;
                    /*_.LET___V81*/
                    meltfptr[74] = /*_.RETURN___V86*/ meltfptr[84];;

                    MELT_LOCATION("warmelt-macro.melt:6747:/ clear");
                    /*clear*/ /*_.SMACBIND__V82*/
                    meltfptr[75] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.RETURN___V86*/
                    meltfptr[84] = 0 ;
                    /*_.LET___V55*/
                    meltfptr[34] = /*_.LET___V81*/ meltfptr[74];;

                    MELT_LOCATION("warmelt-macro.melt:6721:/ clear");
                    /*clear*/ /*_.MACFORMALS__V56*/
                    meltfptr[31] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.VARNAME__V57*/
                    meltfptr[32] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.MACBODY__V58*/
                    meltfptr[37] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.NEWENV__V59*/
                    meltfptr[38] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PAIR_TAIL__V62*/
                    meltfptr[30] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V63*/
                    meltfptr[35] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#IS_A__L17*/
                    meltfnum[15] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#MULTIPLE_LENGTH__L18*/
                    meltfnum[14] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_#gtI__L19*/
                    meltfnum[18] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.EXPAND_PAIRLIST_AS_TUPLE__V77*/
                    meltfptr[64] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V78*/
                    meltfptr[71] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.LET___V81*/
                    meltfptr[74] = 0 ;
                    /*_._IF___V54*/
                    meltfptr[29] = /*_.LET___V55*/ meltfptr[34];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6720:/ clear");
                    /*clear*/ /*_.LET___V55*/
                    meltfptr[34] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V54*/ meltfptr[29] =  /*reallynil*/ NULL ;;
            }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6759:/ cond");
        /*cond*/
        if (/*_.CURARG__V26*/ meltfptr[25]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6760:/ apply");
                    /*apply*/
                    {
                        union meltparam_un argtab[3];
                        memset(&argtab, 0, sizeof(argtab));
                        /*^apply.arg*/
                        argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                        /*^apply.arg*/
                        argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.MEXPANDER__V4*/ meltfptr[3];
                        /*^apply.arg*/
                        argtab[2].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                        /*_.MEXPANDER__V87*/
                        meltfptr[72] =  melt_apply ((meltclosure_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3]), (melt_ptr_t)(/*_.CURARG__V26*/ meltfptr[25]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                    }
                    ;
                    /*^compute*/
                    /*_.EXPR__V24*/
                    meltfptr[23] = /*_.SETQ___V88*/ meltfptr[75] = /*_.MEXPANDER__V87*/ meltfptr[72];;
                    /*_.PAIR_TAIL__V89*/
                    meltfptr[84] =
                        (melt_pair_tail((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                    MELT_LOCATION("warmelt-macro.melt:6761:/ compute");
                    /*_.CURPAIR__V25*/
                    meltfptr[24] = /*_.SETQ___V90*/ meltfptr[31] = /*_.PAIR_TAIL__V89*/ meltfptr[84];;
                    /*_.PAIR_HEAD__V91*/
                    meltfptr[32] =
                        (melt_pair_head((melt_ptr_t)(/*_.CURPAIR__V25*/ meltfptr[24])));;
                    MELT_LOCATION("warmelt-macro.melt:6762:/ compute");
                    /*_.CURARG__V26*/
                    meltfptr[25] = /*_.SETQ___V92*/ meltfptr[37] = /*_.PAIR_HEAD__V91*/ meltfptr[32];;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6763:/ cond");
                    /*cond*/
                    if (/*_.CURARG__V26*/ meltfptr[25]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {


                                {
                                    /*^locexp*/
                                    /* error_plain */ melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "too long letbinding"), (melt_ptr_t)0);
                                }
                                ;
                                /*epilog*/
                            }
                            ;
                        } /*noelse*/
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6759:/ quasiblock");


                    /*epilog*/

                    /*^clear*/
                    /*clear*/ /*_.MEXPANDER__V87*/
                    meltfptr[72] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V88*/
                    meltfptr[75] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PAIR_TAIL__V89*/
                    meltfptr[84] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V90*/
                    meltfptr[31] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PAIR_HEAD__V91*/
                    meltfptr[32] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SETQ___V92*/
                    meltfptr[37] = 0 ;
                }
                ;
            } /*noelse*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6765:/ quasiblock");



        MELT_CHECK_SIGNAL();
        ;
        /*^apply*/
        /*apply*/
        {
            union meltparam_un argtab[1];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.VAR__V23*/ meltfptr[22];
            /*_.PREVBIND__V94*/
            meltfptr[30] =  melt_apply ((meltclosure_ptr_t)((/*!FIND_ENV*/ meltfrout->tabval[19])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*_#NULL__L29*/
        meltfnum[21] =
            ((/*_.PREVBIND__V94*/ meltfptr[30]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6767:/ cond");
        /*cond*/
        if (/*_#NULL__L29*/ meltfnum[21]) /*then*/
            {
                /*^cond.then*/
                /*_._IFELSE___V95*/ meltfptr[35] = (/*nil*/NULL);;
            }
        else
            {
                MELT_LOCATION("warmelt-macro.melt:6767:/ cond.else");

                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#IS_A__L30*/
                    meltfnum[20] =
                        melt_is_instance_of((melt_ptr_t)(/*_.PREVBIND__V94*/ meltfptr[30]), (melt_ptr_t)((/*!CLASS_LET_BINDING*/ meltfrout->tabval[23])));;
                    MELT_LOCATION("warmelt-macro.melt:6768:/ cond");
                    /*cond*/
                    if (/*_#IS_A__L30*/ meltfnum[20]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                MELT_LOCATION("warmelt-macro.melt:6769:/ quasiblock");


                                /*^cond*/
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.PREVBIND__V94*/ meltfptr[30]),
                                                                  (melt_ptr_t)((/*!CLASS_LET_BINDING*/ meltfrout->tabval[23])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.PREVBIND__V94*/ meltfptr[30]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 3, "LETBIND_LOC");
                                            /*_.PREVLOC__V97*/
                                            meltfptr[71] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.PREVLOC__V97*/ meltfptr[71] =  /*reallynil*/ NULL ;;
                                    }
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6772:/ cond");
                                /*cond*/
                                if (
                                    /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]),
                                                                  (melt_ptr_t)((/*!CLASS_NAMED*/ meltfrout->tabval[9])))
                                ) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^getslot*/
                                        {
                                            melt_ptr_t slot=NULL, obj=NULL;
                                            obj = (melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]) /*=obj*/;
                                            melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                                            /*_.NAMED_NAME__V98*/
                                            meltfptr[74] = slot;
                                        };
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_.NAMED_NAME__V98*/ meltfptr[74] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                {
                                    MELT_LOCATION("warmelt-macro.melt:6770:/ locexp");
                                    melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "local let binding hides upper one"), (melt_ptr_t)(/*_.NAMED_NAME__V98*/ meltfptr[74]));
                                }
                                ;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6773:/ cond");
                                /*cond*/
                                if (/*_.PREVLOC__V97*/ meltfptr[71]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            MELT_LOCATION("warmelt-macro.melt:6776:/ cond");
                                            /*cond*/
                                            if (
                                                /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]),
                                                                              (melt_ptr_t)((/*!CLASS_NAMED*/ meltfrout->tabval[9])))
                                            ) /*then*/
                                                {
                                                    /*^cond.then*/
                                                    /*^getslot*/
                                                    {
                                                        melt_ptr_t slot=NULL, obj=NULL;
                                                        obj = (melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]) /*=obj*/;
                                                        melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                                                        /*_.NAMED_NAME__V99*/
                                                        meltfptr[34] = slot;
                                                    };
                                                    ;
                                                }
                                            else    /*^cond.else*/
                                                {

                                                    /*_.NAMED_NAME__V99*/ meltfptr[34] =  /*reallynil*/ NULL ;;
                                                }
                                            ;



                                            {
                                                MELT_LOCATION("warmelt-macro.melt:6774:/ locexp");
                                                melt_warning_str(0, (melt_ptr_t)(/*_.PREVLOC__V97*/ meltfptr[71]), ( "here is the hidden binding"), (melt_ptr_t)(/*_.NAMED_NAME__V99*/ meltfptr[34]));
                                            }
                                            ;
                                            /*clear*/ /*_._IFELSE___V96*/
                                            meltfptr[64] = 0 ;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6773:/ clear");
                                            /*clear*/ /*_.NAMED_NAME__V99*/
                                            meltfptr[34] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IFELSE___V96*/ meltfptr[64] =  /*reallynil*/ NULL ;;
                                    }
                                ;

                                MELT_LOCATION("warmelt-macro.melt:6769:/ clear");
                                /*clear*/ /*_.PREVLOC__V97*/
                                meltfptr[71] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.NAMED_NAME__V98*/
                                meltfptr[74] = 0 ;
                                /*epilog*/
                            }
                            ;
                        }
                    else
                        {
                            MELT_LOCATION("warmelt-macro.melt:6768:/ cond.else");

                            /*^block*/
                            /*anyblock*/
                            {


                                MELT_CHECK_SIGNAL();
                                ;
                                /*_#IS_A__L31*/
                                meltfnum[15] =
                                    melt_is_instance_of((melt_ptr_t)(/*_.PREVBIND__V94*/ meltfptr[30]), (melt_ptr_t)((/*!CLASS_FIXED_BINDING*/ meltfrout->tabval[24])));;
                                MELT_LOCATION("warmelt-macro.melt:6779:/ cond");
                                /*cond*/
                                if (/*_#IS_A__L31*/ meltfnum[15]) /*then*/
                                    {
                                        /*^cond.then*/
                                        /*^block*/
                                        /*anyblock*/
                                        {

                                            MELT_LOCATION("warmelt-macro.melt:6782:/ cond");
                                            /*cond*/
                                            if (
                                                /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]),
                                                                              (melt_ptr_t)((/*!CLASS_NAMED*/ meltfrout->tabval[9])))
                                            ) /*then*/
                                                {
                                                    /*^cond.then*/
                                                    /*^getslot*/
                                                    {
                                                        melt_ptr_t slot=NULL, obj=NULL;
                                                        obj = (melt_ptr_t)(/*_.VAR__V23*/ meltfptr[22]) /*=obj*/;
                                                        melt_object_get_field(slot,obj, 1, "NAMED_NAME");
                                                        /*_.NAMED_NAME__V101*/
                                                        meltfptr[75] = slot;
                                                    };
                                                    ;
                                                }
                                            else    /*^cond.else*/
                                                {

                                                    /*_.NAMED_NAME__V101*/ meltfptr[75] =  /*reallynil*/ NULL ;;
                                                }
                                            ;



                                            {
                                                MELT_LOCATION("warmelt-macro.melt:6780:/ locexp");
                                                melt_warning_str(0, (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "local let binding hides definition"), (melt_ptr_t)(/*_.NAMED_NAME__V101*/ meltfptr[75]));
                                            }
                                            ;
                                            /*clear*/ /*_._IFELSE___V100*/
                                            meltfptr[72] = 0 ;
                                            /*epilog*/

                                            MELT_LOCATION("warmelt-macro.melt:6779:/ clear");
                                            /*clear*/ /*_.NAMED_NAME__V101*/
                                            meltfptr[75] = 0 ;
                                        }
                                        ;
                                    }
                                else    /*^cond.else*/
                                    {

                                        /*_._IFELSE___V100*/ meltfptr[72] =  /*reallynil*/ NULL ;;
                                    }
                                ;
                                /*^compute*/
                                /*_._IFELSE___V96*/
                                meltfptr[64] = /*_._IFELSE___V100*/ meltfptr[72];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6768:/ clear");
                                /*clear*/ /*_#IS_A__L31*/
                                meltfnum[15] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_._IFELSE___V100*/
                                meltfptr[72] = 0 ;
                            }
                            ;
                        }
                    ;
                    /*_._IFELSE___V95*/
                    meltfptr[35] = /*_._IFELSE___V96*/ meltfptr[64];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6767:/ clear");
                    /*clear*/ /*_#IS_A__L30*/
                    meltfnum[20] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IFELSE___V96*/
                    meltfptr[64] = 0 ;
                }
                ;
            }
        ;
        /*_.LET___V93*/
        meltfptr[38] = /*_._IFELSE___V95*/ meltfptr[35];;

        MELT_LOCATION("warmelt-macro.melt:6765:/ clear");
        /*clear*/ /*_.PREVBIND__V94*/
        meltfptr[30] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L29*/
        meltfnum[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IFELSE___V95*/
        meltfptr[35] = 0 ;
        MELT_LOCATION("warmelt-macro.melt:6785:/ quasiblock");



        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6786:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_LET_BINDING*/ meltfrout->tabval[25])), (5), "CLASS_SOURCE_LET_BINDING");
            /*_.INST__V104*/
            meltfptr[32] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V104*/ meltfptr[32])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V104*/ meltfptr[32]), (1), (/*_.LOC__V21*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SLETB_TYPE", melt_magic_discr((melt_ptr_t)(/*_.INST__V104*/ meltfptr[32])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V104*/ meltfptr[32]), (3), (/*_.CTYP__V22*/ meltfptr[21]), "SLETB_TYPE");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SLETB_BINDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V104*/ meltfptr[32])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V104*/ meltfptr[32]), (2), (/*_.VAR__V23*/ meltfptr[22]), "SLETB_BINDER");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SLETB_EXPR", melt_magic_discr((melt_ptr_t)(/*_.INST__V104*/ meltfptr[32])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V104*/ meltfptr[32]), (4), (/*_.EXPR__V24*/ meltfptr[23]), "SLETB_EXPR");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V104*/ meltfptr[32], "newly made instance");
        ;
        /*_.LETB__V103*/
        meltfptr[31] = /*_.INST__V104*/ meltfptr[32];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6791:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LETB__V103*/ meltfptr[31];;

        {
            MELT_LOCATION("warmelt-macro.melt:6791:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V102*/
        meltfptr[84] = /*_.RETURN___V105*/ meltfptr[37];;

        MELT_LOCATION("warmelt-macro.melt:6785:/ clear");
        /*clear*/ /*_.LETB__V103*/
        meltfptr[31] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V105*/
        meltfptr[37] = 0 ;
        /*_.LET___V19*/
        meltfptr[17] = /*_.LET___V102*/ meltfptr[84];;

        MELT_LOCATION("warmelt-macro.melt:6675:/ clear");
        /*clear*/ /*_.CONT__V20*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CTYP__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.VAR__V23*/
        meltfptr[22] = 0 ;
        /*^clear*/
        /*clear*/ /*_.EXPR__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CURPAIR__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.CURARG__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIR_HEAD__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SETQ___V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_A__L7*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_#IS_A__L11*/
        meltfnum[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IFELSE___V45*/
        meltfptr[33] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L13*/
        meltfnum[7] = 0 ;
        /*^clear*/
        /*clear*/ /*_#eqeq__L14*/
        meltfnum[8] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V54*/
        meltfptr[29] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V93*/
        meltfptr[38] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V102*/
        meltfptr[84] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6669:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V19*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6669:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V16*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V19*/
        meltfptr[17] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_LETBINDING", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_128_WARMELTmiMACRO_MEXPAND_LETBINDING*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_129_WARMELTmiMACRO_MEXPAND_LET(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_129_WARMELTmiMACRO_MEXPAND_LET_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_129_WARMELTmiMACRO_MEXPAND_LET fromline 1718 */

    /** start of frame for meltrout_129_WARMELTmiMACRO_MEXPAND_LET of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET// fromline 1534
        : public Melt_CallFrameWithValues<62>
    {
    public: /* fromline 1538*/
        long mcfr_varnum[13];
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
        MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<62> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET), clos) {};
        MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET() //the constructor fromline 1608
            : Melt_CallFrameWithValues<62> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<62> (fil,lin, sizeof(MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET)) {};
        MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<62> (fil,lin, sizeof(MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET


    /** end of frame for meltrout_129_WARMELTmiMACRO_MEXPAND_LET fromline 1663**/

    /* end of frame for routine meltrout_129_WARMELTmiMACRO_MEXPAND_LET fromline 1722 */

    /* classy proc frame meltrout_129_WARMELTmiMACRO_MEXPAND_LET */
    MeltFrame_meltrout_129_WARMELTmiMACRO_MEXPAND_LET
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_129_WARMELTmiMACRO_MEXPAND_LET fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("MEXPAND_LET", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6797:/ getarg");
    /*_.SEXPR__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;

    /*getarg#1*/
    /*^getarg*/
    if (meltxargdescr_[0] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.ENV__V3*/
    meltfptr[2] = (meltxargtab_[0].meltbp_aptr) ? (*(meltxargtab_[0].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2])) != NULL);


    /*getarg#2*/
    /*^getarg*/
    if (meltxargdescr_[1] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MEXPANDER__V4*/
    meltfptr[3] = (meltxargtab_[1].meltbp_aptr) ? (*(meltxargtab_[1].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3])) != NULL);


    /*getarg#3*/
    /*^getarg*/
    if (meltxargdescr_[2] != MELTBPAR_PTR) goto meltlab_endgetargs;
    /*_.MODCTX__V5*/
    meltfptr[4] = (meltxargtab_[2].meltbp_aptr) ? (*(meltxargtab_[2].meltbp_aptr)) : NULL;
    gcc_assert(melt_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) != NULL);

    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6798:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6798:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6798:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6798;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "mexpand_let sexpr=";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V7*/
                            meltfptr[6] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V6*/
                        meltfptr[5] = /*_.MELT_DEBUG_FUN__V7*/ meltfptr[6];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6798:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V7*/
                        meltfptr[6] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V6*/ meltfptr[5] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6798:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V6*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6799:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L3*/
            meltfnum[1] =
                melt_is_instance_of((melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
            MELT_LOCATION("warmelt-macro.melt:6799:/ cond");
            /*cond*/
            if (/*_#IS_A__L3*/ meltfnum[1]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V9*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6799:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check sexpr";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6799;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SEXPR__V2*/ meltfptr[1];
                            /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                            meltfptr[9] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V9*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V10*/ meltfptr[9];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6799:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V10*/
                        meltfptr[9] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V8*/
            meltfptr[6] = /*_._IFELSE___V9*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6799:/ clear");
            /*clear*/ /*_#IS_A__L3*/
            meltfnum[1] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V9*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V8*/ meltfptr[6] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6800:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_A__L4*/
            meltfnum[0] =
                melt_is_instance_of((melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (melt_ptr_t)((/*!CLASS_ENVIRONMENT*/ meltfrout->tabval[3])));;
            MELT_LOCATION("warmelt-macro.melt:6800:/ cond");
            /*cond*/
            if (/*_#IS_A__L4*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V12*/ meltfptr[5] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6800:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check env";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6800;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.ENV__V3*/ meltfptr[2];
                            /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                            meltfptr[12] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V12*/
                        meltfptr[5] = /*_.MELT_ASSERT_FAILURE_FUN__V13*/ meltfptr[12];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6800:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V13*/
                        meltfptr[12] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V11*/
            meltfptr[9] = /*_._IFELSE___V12*/ meltfptr[5];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6800:/ clear");
            /*clear*/ /*_#IS_A__L4*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V12*/
            meltfptr[5] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V11*/ meltfptr[9] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        /*^compute*/
        /*_#NULL__L5*/
        meltfnum[1] =
            ((/*_.MEXPANDER__V4*/ meltfptr[3]) == NULL);;
        MELT_LOCATION("warmelt-macro.melt:6801:/ cond");
        /*cond*/
        if (/*_#NULL__L5*/ meltfnum[1]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {

                    /*^compute*/
                    /*_.MEXPANDER__V4*/ meltfptr[3] = /*_.SETQ___V15*/ meltfptr[5] = (/*!MACROEXPAND_1*/ meltfrout->tabval[4]);;
                    /*_._IF___V14*/
                    meltfptr[12] = /*_.SETQ___V15*/ meltfptr[5];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6801:/ clear");
                    /*clear*/ /*_.SETQ___V15*/
                    meltfptr[5] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V14*/ meltfptr[12] =  /*reallynil*/ NULL ;;
            }
        ;

#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6802:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            MELT_CHECK_SIGNAL();
            ;
            /*_#IS_OBJECT__L6*/
            meltfnum[0] =
                (melt_magic_discr((melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4])) == MELTOBMAG_OBJECT);;
            MELT_LOCATION("warmelt-macro.melt:6802:/ cond");
            /*cond*/
            if (/*_#IS_OBJECT__L6*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*_._IFELSE___V17*/ meltfptr[16] = (/*nil*/NULL);;
                }
            else
                {
                    MELT_LOCATION("warmelt-macro.melt:6802:/ cond.else");

                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*^apply*/
                        /*apply*/
                        {
                            union meltparam_un argtab[4];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_cstring =  "check modctx";
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6802;
                            /*^apply.arg*/
                            argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.MODCTX__V5*/ meltfptr[4];
                            /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                            meltfptr[17] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IFELSE___V17*/
                        meltfptr[16] = /*_.MELT_ASSERT_FAILURE_FUN__V18*/ meltfptr[17];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6802:/ clear");
                        /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V18*/
                        meltfptr[17] = 0 ;
                    }
                    ;
                }
            ;
            /*_.IFCPP___V16*/
            meltfptr[5] = /*_._IFELSE___V17*/ meltfptr[16];;
            /*epilog*/

            MELT_LOCATION("warmelt-macro.melt:6802:/ clear");
            /*clear*/ /*_#IS_OBJECT__L6*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IFELSE___V17*/
            meltfptr[16] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*_.IFCPP___V16*/ meltfptr[5] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6803:/ quasiblock");


        MELT_LOCATION("warmelt-macro.melt:6804:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
            /*_.CONT__V20*/
            meltfptr[16] = slot;
        };
        ;
        MELT_LOCATION("warmelt-macro.melt:6805:/ getslot");
        {
            melt_ptr_t slot=NULL, obj=NULL;
            obj = (melt_ptr_t)(/*_.SEXPR__V2*/ meltfptr[1]) /*=obj*/;
            melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
            /*_.LOC__V21*/
            meltfptr[20] = slot;
        };
        ;
        /*_.LIST_FIRST__V22*/
        meltfptr[21] =
            (melt_list_first((melt_ptr_t)(/*_.CONT__V20*/ meltfptr[16])));;
        /*^compute*/
        /*_.SECPAIR__V23*/
        meltfptr[22] =
            (melt_pair_tail((melt_ptr_t)(/*_.LIST_FIRST__V22*/ meltfptr[21])));;
        /*^compute*/
        /*_.RESTPAIR__V24*/
        meltfptr[23] =
            (melt_pair_tail((melt_ptr_t)(/*_.SECPAIR__V23*/ meltfptr[22])));;
        /*^compute*/
        /*_.BINDEXPR__V25*/
        meltfptr[24] =
            (melt_pair_head((melt_ptr_t)(/*_.SECPAIR__V23*/ meltfptr[22])));;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6809:/ apply");
        /*apply*/
        {
            /*_.NEWENV__V26*/ meltfptr[25] =  melt_apply ((meltclosure_ptr_t)((/*!FRESH_ENV*/ meltfrout->tabval[5])), (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]), (""), (union meltparam_un*)0, "", (union meltparam_un*)0);
        }
        ;
        /*_.BINDTUP__V27*/
        meltfptr[26] = (/*nil*/NULL);;
        /*^compute*/
        /*_.BODYTUP__V28*/
        meltfptr[27] = (/*nil*/NULL);;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6813:/ cond");
        /*cond*/
        if (/*_.BINDEXPR__V25*/ meltfptr[24]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    MELT_CHECK_SIGNAL();
                    ;
                    /*_#IS_A__L7*/
                    meltfnum[0] =
                        melt_is_instance_of((melt_ptr_t)(/*_.BINDEXPR__V25*/ meltfptr[24]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[1])));;
                    MELT_LOCATION("warmelt-macro.melt:6814:/ cond");
                    /*cond*/
                    if (/*_#IS_A__L7*/ meltfnum[0]) /*then*/
                        {
                            /*^cond.then*/
                            /*^block*/
                            /*anyblock*/
                            {

                                MELT_LOCATION("warmelt-macro.melt:6817:/ getslot");
                                {
                                    melt_ptr_t slot=NULL, obj=NULL;
                                    obj = (melt_ptr_t)(/*_.BINDEXPR__V25*/ meltfptr[24]) /*=obj*/;
                                    melt_object_get_field(slot,obj, 2, "SEXP_CONTENTS");
                                    /*_.SEXP_CONTENTS__V31*/
                                    meltfptr[30] = slot;
                                };
                                ;
                                /*_.LIST_FIRST__V32*/
                                meltfptr[31] =
                                    (melt_list_first((melt_ptr_t)(/*_.SEXP_CONTENTS__V31*/ meltfptr[30])));;
                                MELT_LOCATION("warmelt-macro.melt:6819:/ quasiblock");


                                /*^newclosure*/
                                /*newclosure*/ /*_.LAMBDA___V34*/
                                meltfptr[33] =
                                    (melt_ptr_t) meltgc_new_closure((meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_CLOSURE)))), (meltroutine_ptr_t)((/*!konst_10*/ meltfrout->tabval[10])), (4));
                                ;
                                /*^putclosedv*/
                                /*putclosv*/
                                melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V34*/ meltfptr[33])) == MELTOBMAG_CLOSURE);
                                melt_assertmsg("putclosv checkoff", 0>= 0 && 0< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V34*/ meltfptr[33])));
                                ((meltclosure_ptr_t)/*_.LAMBDA___V34*/ meltfptr[33])->tabval[0] = (melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]);
                                ;
                                /*^putclosedv*/
                                /*putclosv*/
                                melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V34*/ meltfptr[33])) == MELTOBMAG_CLOSURE);
                                melt_assertmsg("putclosv checkoff", 1>= 0 && 1< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V34*/ meltfptr[33])));
                                ((meltclosure_ptr_t)/*_.LAMBDA___V34*/ meltfptr[33])->tabval[1] = (melt_ptr_t)(/*_.ENV__V3*/ meltfptr[2]);
                                ;
                                /*^putclosedv*/
                                /*putclosv*/
                                melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V34*/ meltfptr[33])) == MELTOBMAG_CLOSURE);
                                melt_assertmsg("putclosv checkoff", 2>= 0 && 2< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V34*/ meltfptr[33])));
                                ((meltclosure_ptr_t)/*_.LAMBDA___V34*/ meltfptr[33])->tabval[2] = (melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3]);
                                ;
                                /*^putclosedv*/
                                /*putclosv*/
                                melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V34*/ meltfptr[33])) == MELTOBMAG_CLOSURE);
                                melt_assertmsg("putclosv checkoff", 3>= 0 && 3< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V34*/ meltfptr[33])));
                                ((meltclosure_ptr_t)/*_.LAMBDA___V34*/ meltfptr[33])->tabval[3] = (melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4]);
                                ;
                                /*_.LAMBDA___V33*/
                                meltfptr[32] = /*_.LAMBDA___V34*/ meltfptr[33];;

                                MELT_CHECK_SIGNAL();
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6816:/ apply");
                                /*apply*/
                                {
                                    union meltparam_un argtab[2];
                                    memset(&argtab, 0, sizeof(argtab));
                                    /*^apply.arg*/
                                    argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[7]);
                                    /*^apply.arg*/
                                    argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.LAMBDA___V33*/ meltfptr[32];
                                    /*_.PAIRLIST_TO_MULTIPLE__V35*/
                                    meltfptr[34] =  melt_apply ((meltclosure_ptr_t)((/*!PAIRLIST_TO_MULTIPLE*/ meltfrout->tabval[6])), (melt_ptr_t)(/*_.LIST_FIRST__V32*/ meltfptr[31]), (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                }
                                ;
                                MELT_LOCATION("warmelt-macro.melt:6815:/ compute");
                                /*_.BINDTUP__V27*/
                                meltfptr[26] = /*_.SETQ___V36*/ meltfptr[35] = /*_.PAIRLIST_TO_MULTIPLE__V35*/ meltfptr[34];;
                                /*_._IFELSE___V30*/
                                meltfptr[29] = /*_.SETQ___V36*/ meltfptr[35];;
                                /*epilog*/

                                MELT_LOCATION("warmelt-macro.melt:6814:/ clear");
                                /*clear*/ /*_.SEXP_CONTENTS__V31*/
                                meltfptr[30] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.LIST_FIRST__V32*/
                                meltfptr[31] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.LAMBDA___V33*/
                                meltfptr[32] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.PAIRLIST_TO_MULTIPLE__V35*/
                                meltfptr[34] = 0 ;
                                /*^clear*/
                                /*clear*/ /*_.SETQ___V36*/
                                meltfptr[35] = 0 ;
                            }
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*^block*/
                            /*anyblock*/
                            {




                                {
                                    MELT_LOCATION("warmelt-macro.melt:6823:/ locexp");
                                    /* error_plain */
                                    melt_error_str((melt_ptr_t)(/*_.LOC__V21*/ meltfptr[20]), ( "missing letbinding-s in LET"), (melt_ptr_t)0);
                                }
                                ;
                                /*clear*/ /*_._IFELSE___V30*/
                                meltfptr[29] = 0 ;
                                /*epilog*/
                            }
                            ;
                        }
                    ;
                    /*^compute*/
                    /*_._IF___V29*/
                    meltfptr[28] = /*_._IFELSE___V30*/ meltfptr[29];;
                    /*epilog*/

                    MELT_LOCATION("warmelt-macro.melt:6813:/ clear");
                    /*clear*/ /*_#IS_A__L7*/
                    meltfnum[0] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_._IFELSE___V30*/
                    meltfptr[29] = 0 ;
                }
                ;
            }
        else    /*^cond.else*/
            {

                /*_._IF___V29*/ meltfptr[28] =  /*reallynil*/ NULL ;;
            }
        ;
        /*citerblock FOREACH_IN_MULTIPLE*/
        {
            /* start foreach_in_multiple meltcit1__EACHTUP */
            long  meltcit1__EACHTUP_ln = melt_multiple_length((melt_ptr_t)/*_.BINDTUP__V27*/ meltfptr[26]);
            for (/*_#BIX__L8*/ meltfnum[0] = 0;
                               (/*_#BIX__L8*/ meltfnum[0] >= 0) && (/*_#BIX__L8*/ meltfnum[0] <  meltcit1__EACHTUP_ln);
                               /*_#BIX__L8*/ meltfnum[0]++)
                {
                    /*_.SLB__V37*/ meltfptr[30] = melt_multiple_nth((melt_ptr_t)(/*_.BINDTUP__V27*/ meltfptr[26]),  /*_#BIX__L8*/ meltfnum[0]);




#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6828:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                            melt_dbgcounter++;
#endif
                            ;
                        }
                        ;

                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#MELT_NEED_DBG__L9*/
                        meltfnum[8] =
                            /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                            (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                            0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                            ;;
                        MELT_LOCATION("warmelt-macro.melt:6828:/ cond");
                        /*cond*/
                        if (/*_#MELT_NEED_DBG__L9*/ meltfnum[8]) /*then*/
                            {
                                /*^cond.then*/
                                /*^block*/
                                /*anyblock*/
                                {

                                    /*_#MELT_CALLCOUNT__L10*/ meltfnum[9] =
                                        /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                                        meltcallcount  /* melt_callcount debugging */
#else
                                        0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                                        ;;

                                    MELT_CHECK_SIGNAL();
                                    ;
                                    MELT_LOCATION("warmelt-macro.melt:6828:/ apply");
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[7];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L10*/ meltfnum[9];
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6828;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_cstring =  "mexpand_let slb=";
                                        /*^apply.arg*/
                                        argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.SLB__V37*/ meltfptr[30];
                                        /*^apply.arg*/
                                        argtab[5].meltbp_cstring =  " bix=";
                                        /*^apply.arg*/
                                        argtab[6].meltbp_long = /*_#BIX__L8*/ meltfnum[0];
                                        /*_.MELT_DEBUG_FUN__V39*/
                                        meltfptr[32] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR MELTBPARSTR_CSTRING MELTBPARSTR_LONG ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IF___V38*/
                                    meltfptr[31] = /*_.MELT_DEBUG_FUN__V39*/ meltfptr[32];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6828:/ clear");
                                    /*clear*/ /*_#MELT_CALLCOUNT__L10*/
                                    meltfnum[9] = 0 ;
                                    /*^clear*/
                                    /*clear*/ /*_.MELT_DEBUG_FUN__V39*/
                                    meltfptr[32] = 0 ;
                                }
                                ;
                            }
                        else    /*^cond.else*/
                            {

                                /*_._IF___V38*/ meltfptr[31] =  /*reallynil*/ NULL ;;
                            }
                        ;

                        {
                            MELT_LOCATION("warmelt-macro.melt:6828:/ locexp");
                            /*void*/
                            (void)0;
                        }
                        ;
                        /*^quasiblock*/


                        /*epilog*/

                        /*^clear*/
                        /*clear*/ /*_#MELT_NEED_DBG__L9*/
                        meltfnum[8] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IF___V38*/
                        meltfptr[31] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*^block*/
                    /*anyblock*/
                    {


                        {
                            /*^locexp*/
                            /*void*/(void)0;
                        }
                        ;
                        /*epilog*/
                    }

#endif /*MELT_HAVE_DEBUG*/
                    ;

#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6829:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#IS_A__L11*/
                        meltfnum[9] =
                            melt_is_instance_of((melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]), (melt_ptr_t)((/*!CLASS_SOURCE_LET_BINDING*/ meltfrout->tabval[11])));;
                        MELT_LOCATION("warmelt-macro.melt:6829:/ cond");
                        /*cond*/
                        if (/*_#IS_A__L11*/ meltfnum[9]) /*then*/
                            {
                                /*^cond.then*/
                                /*_._IFELSE___V41*/ meltfptr[35] = (/*nil*/NULL);;
                            }
                        else
                            {
                                MELT_LOCATION("warmelt-macro.melt:6829:/ cond.else");

                                /*^block*/
                                /*anyblock*/
                                {


                                    MELT_CHECK_SIGNAL();
                                    ;
                                    /*^apply*/
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[4];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_cstring =  "mexpand_let check slb";
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6829;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.SLB__V37*/ meltfptr[30];
                                        /*_.MELT_ASSERT_FAILURE_FUN__V42*/
                                        meltfptr[29] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IFELSE___V41*/
                                    meltfptr[35] = /*_.MELT_ASSERT_FAILURE_FUN__V42*/ meltfptr[29];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6829:/ clear");
                                    /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V42*/
                                    meltfptr[29] = 0 ;
                                }
                                ;
                            }
                        ;
                        /*_.IFCPP___V40*/
                        meltfptr[34] = /*_._IFELSE___V41*/ meltfptr[35];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6829:/ clear");
                        /*clear*/ /*_#IS_A__L11*/
                        meltfnum[9] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IFELSE___V41*/
                        meltfptr[35] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*_.IFCPP___V40*/ meltfptr[34] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6830:/ quasiblock");


                    MELT_LOCATION("warmelt-macro.melt:6831:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]) /*=obj*/;
                        melt_object_get_field(slot,obj, 4, "SLETB_EXPR");
                        /*_.SX__V44*/
                        meltfptr[31] = slot;
                    };
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6833:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]) /*=obj*/;
                        melt_object_get_field(slot,obj, 2, "SLETB_BINDER");
                        /*_.SLETB_BINDER__V45*/
                        meltfptr[29] = slot;
                    };
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6834:/ getslot");
                    {
                        melt_ptr_t slot=NULL, obj=NULL;
                        obj = (melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]) /*=obj*/;
                        melt_object_get_field(slot,obj, 3, "SLETB_TYPE");
                        /*_.SLETB_TYPE__V46*/
                        meltfptr[35] = slot;
                    };
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6836:/ cond");
                    /*cond*/
                    if (
                        /*ifisa*/ melt_is_instance_of((melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]),
                                                      (melt_ptr_t)((/*!CLASS_LOCATED*/ meltfrout->tabval[13])))
                    ) /*then*/
                        {
                            /*^cond.then*/
                            /*^getslot*/
                            {
                                melt_ptr_t slot=NULL, obj=NULL;
                                obj = (melt_ptr_t)(/*_.SLB__V37*/ meltfptr[30]) /*=obj*/;
                                melt_object_get_field(slot,obj, 1, "LOCA_LOCATION");
                                /*_.LOCA_LOCATION__V47*/
                                meltfptr[46] = slot;
                            };
                            ;
                        }
                    else    /*^cond.else*/
                        {

                            /*_.LOCA_LOCATION__V47*/ meltfptr[46] =  /*reallynil*/ NULL ;;
                        }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6836:/ cond");
                    /*cond*/
                    if (/*_.LOCA_LOCATION__V47*/ meltfptr[46]) /*then*/
                        {
                            /*^cond.then*/
                            /*_.OR___V48*/ meltfptr[47] = /*_.LOCA_LOCATION__V47*/ meltfptr[46];;
                        }
                    else
                        {
                            MELT_LOCATION("warmelt-macro.melt:6836:/ cond.else");

                            /*_.OR___V48*/
                            meltfptr[47] = /*_.LOC__V21*/ meltfptr[20];;
                        }
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6832:/ quasiblock");


                    /*^rawallocobj*/
                    /*rawallocobj*/
                    {
                        melt_ptr_t newobj = 0;
                        melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_LET_BINDING*/ meltfrout->tabval[12])), (4), "CLASS_LET_BINDING");
                        /*_.INST__V50*/
                        meltfptr[49] =
                            newobj;
                    };
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @BINDER", melt_magic_discr((melt_ptr_t)(/*_.INST__V50*/ meltfptr[49])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V50*/ meltfptr[49]), (0), (/*_.SLETB_BINDER__V45*/ meltfptr[29]), "BINDER");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @LETBIND_TYPE", melt_magic_discr((melt_ptr_t)(/*_.INST__V50*/ meltfptr[49])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V50*/ meltfptr[49]), (1), (/*_.SLETB_TYPE__V46*/ meltfptr[35]), "LETBIND_TYPE");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @LETBIND_EXPR", melt_magic_discr((melt_ptr_t)(/*_.INST__V50*/ meltfptr[49])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V50*/ meltfptr[49]), (2), (/*_.SX__V44*/ meltfptr[31]), "LETBIND_EXPR");
                    ;
                    /*^putslot*/
                    /*putslot*/
                    melt_assertmsg("checkobj putslot  _ @LETBIND_LOC", melt_magic_discr((melt_ptr_t)(/*_.INST__V50*/ meltfptr[49])) == MELTOBMAG_OBJECT);
                    melt_putfield_object((/*_.INST__V50*/ meltfptr[49]), (3), (/*_.OR___V48*/ meltfptr[47]), "LETBIND_LOC");
                    ;
                    /*^touchobj*/

                    melt_dbgtrace_written_object (/*_.INST__V50*/ meltfptr[49], "newly made instance");
                    ;
                    /*_.LB__V49*/
                    meltfptr[48] = /*_.INST__V50*/ meltfptr[49];;

#if MELT_HAVE_DEBUG
                    MELT_LOCATION("warmelt-macro.melt:6838:/ cppif.then");
                    /*^block*/
                    /*anyblock*/
                    {


                        MELT_CHECK_SIGNAL();
                        ;
                        /*_#IS_LIST__L12*/
                        meltfnum[8] =
                            (melt_magic_discr((melt_ptr_t)(/*_.LB__V49*/ meltfptr[48])) == MELTOBMAG_LIST);;
                        /*^compute*/
                        /*_#NOT__L13*/
                        meltfnum[9] =
                            (!(/*_#IS_LIST__L12*/ meltfnum[8]));;
                        MELT_LOCATION("warmelt-macro.melt:6838:/ cond");
                        /*cond*/
                        if (/*_#NOT__L13*/ meltfnum[9]) /*then*/
                            {
                                /*^cond.then*/
                                /*_._IFELSE___V52*/ meltfptr[51] = (/*nil*/NULL);;
                            }
                        else
                            {
                                MELT_LOCATION("warmelt-macro.melt:6838:/ cond.else");

                                /*^block*/
                                /*anyblock*/
                                {


                                    MELT_CHECK_SIGNAL();
                                    ;
                                    /*^apply*/
                                    /*apply*/
                                    {
                                        union meltparam_un argtab[4];
                                        memset(&argtab, 0, sizeof(argtab));
                                        /*^apply.arg*/
                                        argtab[0].meltbp_cstring =  "mexpand_let not list lb";
                                        /*^apply.arg*/
                                        argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                                        /*^apply.arg*/
                                        argtab[2].meltbp_long = 6838;
                                        /*^apply.arg*/
                                        argtab[3].meltbp_aptr = (melt_ptr_t*) &/*_.LB__V49*/ meltfptr[48];
                                        /*_.MELT_ASSERT_FAILURE_FUN__V53*/
                                        meltfptr[52] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_ASSERT_FAILURE_FUN*/ meltfrout->tabval[2])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_CSTRING MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                                    }
                                    ;
                                    /*_._IFELSE___V52*/
                                    meltfptr[51] = /*_.MELT_ASSERT_FAILURE_FUN__V53*/ meltfptr[52];;
                                    /*epilog*/

                                    MELT_LOCATION("warmelt-macro.melt:6838:/ clear");
                                    /*clear*/ /*_.MELT_ASSERT_FAILURE_FUN__V53*/
                                    meltfptr[52] = 0 ;
                                }
                                ;
                            }
                        ;
                        /*_.IFCPP___V51*/
                        meltfptr[50] = /*_._IFELSE___V52*/ meltfptr[51];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6838:/ clear");
                        /*clear*/ /*_#IS_LIST__L12*/
                        meltfnum[8] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_#NOT__L13*/
                        meltfnum[9] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_._IFELSE___V52*/
                        meltfptr[51] = 0 ;
                    }

#else /*MELT_HAVE_DEBUG*/
                    /*^cppif.else*/
                    /*_.IFCPP___V51*/ meltfptr[50] = (/*nil*/NULL);
#endif /*MELT_HAVE_DEBUG*/
                    ;

                    MELT_CHECK_SIGNAL();
                    ;
                    MELT_LOCATION("warmelt-macro.melt:6839:/ apply");
                    /*apply*/
                    {
                        union meltparam_un argtab[1];
                        memset(&argtab, 0, sizeof(argtab));
                        /*^apply.arg*/
                        argtab[0].meltbp_aptr = (melt_ptr_t*) &/*_.LB__V49*/ meltfptr[48];
                        /*_.PUT_ENV__V54*/
                        meltfptr[52] =  melt_apply ((meltclosure_ptr_t)((/*!PUT_ENV*/ meltfrout->tabval[14])), (melt_ptr_t)(/*_.NEWENV__V26*/ meltfptr[25]), (MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                    }
                    ;
                    /*_.LET___V43*/
                    meltfptr[32] = /*_.PUT_ENV__V54*/ meltfptr[52];;

                    MELT_LOCATION("warmelt-macro.melt:6830:/ clear");
                    /*clear*/ /*_.SX__V44*/
                    meltfptr[31] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SLETB_BINDER__V45*/
                    meltfptr[29] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.SLETB_TYPE__V46*/
                    meltfptr[35] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.LOCA_LOCATION__V47*/
                    meltfptr[46] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.OR___V48*/
                    meltfptr[47] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.LB__V49*/
                    meltfptr[48] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.IFCPP___V51*/
                    meltfptr[50] = 0 ;
                    /*^clear*/
                    /*clear*/ /*_.PUT_ENV__V54*/
                    meltfptr[52] = 0 ;
                    if (/*_#BIX__L8*/ meltfnum[0]<0) break;
                } /* end  foreach_in_multiple meltcit1__EACHTUP */

            /*citerepilog*/

            MELT_LOCATION("warmelt-macro.melt:6825:/ clear");
            /*clear*/ /*_.SLB__V37*/
            meltfptr[30] = 0 ;
            /*^clear*/
            /*clear*/ /*_#BIX__L8*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_.IFCPP___V40*/
            meltfptr[34] = 0 ;
            /*^clear*/
            /*clear*/ /*_.LET___V43*/
            meltfptr[32] = 0 ;
        } /*endciterblock FOREACH_IN_MULTIPLE*/
        ;
        MELT_LOCATION("warmelt-macro.melt:6843:/ quasiblock");


        /*^newclosure*/
        /*newclosure*/ /*_.LAMBDA___V56*/
        meltfptr[31] =
            (melt_ptr_t) meltgc_new_closure((meltobject_ptr_t)(((melt_ptr_t)(MELT_PREDEF(DISCR_CLOSURE)))), (meltroutine_ptr_t)((/*!konst_15*/ meltfrout->tabval[15])), (3));
        ;
        /*^putclosedv*/
        /*putclosv*/
        melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V56*/ meltfptr[31])) == MELTOBMAG_CLOSURE);
        melt_assertmsg("putclosv checkoff", 0>= 0 && 0< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V56*/ meltfptr[31])));
        ((meltclosure_ptr_t)/*_.LAMBDA___V56*/ meltfptr[31])->tabval[0] = (melt_ptr_t)(/*_.MEXPANDER__V4*/ meltfptr[3]);
        ;
        /*^putclosedv*/
        /*putclosv*/
        melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V56*/ meltfptr[31])) == MELTOBMAG_CLOSURE);
        melt_assertmsg("putclosv checkoff", 1>= 0 && 1< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V56*/ meltfptr[31])));
        ((meltclosure_ptr_t)/*_.LAMBDA___V56*/ meltfptr[31])->tabval[1] = (melt_ptr_t)(/*_.NEWENV__V26*/ meltfptr[25]);
        ;
        /*^putclosedv*/
        /*putclosv*/
        melt_assertmsg("putclosv checkclo", melt_magic_discr((melt_ptr_t)(/*_.LAMBDA___V56*/ meltfptr[31])) == MELTOBMAG_CLOSURE);
        melt_assertmsg("putclosv checkoff", 2>= 0 && 2< melt_closure_size((melt_ptr_t) (/*_.LAMBDA___V56*/ meltfptr[31])));
        ((meltclosure_ptr_t)/*_.LAMBDA___V56*/ meltfptr[31])->tabval[2] = (melt_ptr_t)(/*_.MODCTX__V5*/ meltfptr[4]);
        ;
        /*_.LAMBDA___V55*/
        meltfptr[51] = /*_.LAMBDA___V56*/ meltfptr[31];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6841:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[2];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*!DISCR_MULTIPLE*/ meltfrout->tabval[7]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &/*_.LAMBDA___V55*/ meltfptr[51];
            /*_.PAIRLIST_TO_MULTIPLE__V57*/
            meltfptr[29] =  melt_apply ((meltclosure_ptr_t)((/*!PAIRLIST_TO_MULTIPLE*/ meltfrout->tabval[6])), (melt_ptr_t)(/*_.RESTPAIR__V24*/ meltfptr[23]), (MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*^compute*/
        /*_.BODYTUP__V28*/
        meltfptr[27] = /*_.SETQ___V58*/ meltfptr[35] = /*_.PAIRLIST_TO_MULTIPLE__V57*/ meltfptr[29];;
        MELT_LOCATION("warmelt-macro.melt:6844:/ quasiblock");



        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6845:/ quasiblock");


        /*^rawallocobj*/
        /*rawallocobj*/
        {
            melt_ptr_t newobj = 0;
            melt_raw_object_create(newobj,(melt_ptr_t)((/*!CLASS_SOURCE_LET*/ meltfrout->tabval[16])), (4), "CLASS_SOURCE_LET");
            /*_.INST__V61*/
            meltfptr[48] =
                newobj;
        };
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @LOCA_LOCATION", melt_magic_discr((melt_ptr_t)(/*_.INST__V61*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V61*/ meltfptr[48]), (1), (/*_.LOC__V21*/ meltfptr[20]), "LOCA_LOCATION");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SLET_BINDINGS", melt_magic_discr((melt_ptr_t)(/*_.INST__V61*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V61*/ meltfptr[48]), (2), (/*_.BINDTUP__V27*/ meltfptr[26]), "SLET_BINDINGS");
        ;
        /*^putslot*/
        /*putslot*/
        melt_assertmsg("checkobj putslot  _ @SLET_BODY", melt_magic_discr((melt_ptr_t)(/*_.INST__V61*/ meltfptr[48])) == MELTOBMAG_OBJECT);
        melt_putfield_object((/*_.INST__V61*/ meltfptr[48]), (3), (/*_.BODYTUP__V28*/ meltfptr[27]), "SLET_BODY");
        ;
        /*^touchobj*/

        melt_dbgtrace_written_object (/*_.INST__V61*/ meltfptr[48], "newly made instance");
        ;
        /*_.LETR__V60*/
        meltfptr[47] = /*_.INST__V61*/ meltfptr[48];;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6849:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LETR__V60*/ meltfptr[47];;

        {
            MELT_LOCATION("warmelt-macro.melt:6849:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*_.LET___V59*/
        meltfptr[46] = /*_.RETURN___V62*/ meltfptr[50];;

        MELT_LOCATION("warmelt-macro.melt:6844:/ clear");
        /*clear*/ /*_.LETR__V60*/
        meltfptr[47] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RETURN___V62*/
        meltfptr[50] = 0 ;
        /*_.LET___V19*/
        meltfptr[17] = /*_.LET___V59*/ meltfptr[46];;

        MELT_LOCATION("warmelt-macro.melt:6803:/ clear");
        /*clear*/ /*_.CONT__V20*/
        meltfptr[16] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LOC__V21*/
        meltfptr[20] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LIST_FIRST__V22*/
        meltfptr[21] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SECPAIR__V23*/
        meltfptr[22] = 0 ;
        /*^clear*/
        /*clear*/ /*_.RESTPAIR__V24*/
        meltfptr[23] = 0 ;
        /*^clear*/
        /*clear*/ /*_.BINDEXPR__V25*/
        meltfptr[24] = 0 ;
        /*^clear*/
        /*clear*/ /*_.NEWENV__V26*/
        meltfptr[25] = 0 ;
        /*^clear*/
        /*clear*/ /*_.BINDTUP__V27*/
        meltfptr[26] = 0 ;
        /*^clear*/
        /*clear*/ /*_.BODYTUP__V28*/
        meltfptr[27] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V29*/
        meltfptr[28] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LAMBDA___V55*/
        meltfptr[51] = 0 ;
        /*^clear*/
        /*clear*/ /*_.PAIRLIST_TO_MULTIPLE__V57*/
        meltfptr[29] = 0 ;
        /*^clear*/
        /*clear*/ /*_.SETQ___V58*/
        meltfptr[35] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V59*/
        meltfptr[46] = 0 ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6797:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.LET___V19*/ meltfptr[17];;

        {
            MELT_LOCATION("warmelt-macro.melt:6797:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.IFCPP___V8*/
        meltfptr[6] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V11*/
        meltfptr[9] = 0 ;
        /*^clear*/
        /*clear*/ /*_#NULL__L5*/
        meltfnum[1] = 0 ;
        /*^clear*/
        /*clear*/ /*_._IF___V14*/
        meltfptr[12] = 0 ;
        /*^clear*/
        /*clear*/ /*_.IFCPP___V16*/
        meltfptr[5] = 0 ;
        /*^clear*/
        /*clear*/ /*_.LET___V19*/
        meltfptr[17] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("MEXPAND_LET", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_129_WARMELTmiMACRO_MEXPAND_LET_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_129_WARMELTmiMACRO_MEXPAND_LET*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_130_WARMELTmiMACRO_LAMBDA_cl23(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 fromline 1718 */

    /** start of frame for meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23// fromline 1534
        : public Melt_CallFrameWithValues<3>
    {
    public: /* fromline 1538*/
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
        MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<3> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23), clos) {};
        MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23() //the constructor fromline 1608
            : Melt_CallFrameWithValues<3> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<3> (fil,lin, sizeof(MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23)) {};
        MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<3> (fil,lin, sizeof(MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23


    /** end of frame for meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 fromline 1663**/

    /* end of frame for routine meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 fromline 1722 */

    /* classy proc frame meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 */
    MeltFrame_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_130_WARMELTmiMACRO_LAMBDA_cl23 fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl23", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6819:/ getarg");
    /*_.B__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;
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
        /*_#IS_NOT_A__L1*/
        meltfnum[0] =
            !melt_is_instance_of((melt_ptr_t)(/*_.B__V2*/ meltfptr[1]), (melt_ptr_t)((/*!CLASS_SEXPR*/ meltfrout->tabval[0])));;
        MELT_LOCATION("warmelt-macro.melt:6820:/ cond");
        /*cond*/
        if (/*_#IS_NOT_A__L1*/ meltfnum[0]) /*then*/
            {
                /*^cond.then*/
                /*^block*/
                /*anyblock*/
                {


                    {
                        MELT_LOCATION("warmelt-macro.melt:6821:/ locexp");
                        /* error_plain */
                        melt_error_str((melt_ptr_t)((/*~LOC*/ meltfclos->tabval[0])), ( "sexpr expected in LET binding"), (melt_ptr_t)0);
                    }
                    ;
                    /*epilog*/
                }
                ;
            } /*noelse*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6822:/ apply");
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*~ENV*/ meltfclos->tabval[1]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &(/*~MEXPANDER*/ meltfclos->tabval[2]);
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &(/*~MODCTX*/ meltfclos->tabval[3]);
            /*_.MEXPAND_LETBINDING__V3*/
            meltfptr[2] =  melt_apply ((meltclosure_ptr_t)((/*!MEXPAND_LETBINDING*/ meltfrout->tabval[1])), (melt_ptr_t)(/*_.B__V2*/ meltfptr[1]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6819:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.MEXPAND_LETBINDING__V3*/ meltfptr[2];;

        {
            MELT_LOCATION("warmelt-macro.melt:6819:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_#IS_NOT_A__L1*/
        meltfnum[0] = 0 ;
        /*^clear*/
        /*clear*/ /*_.MEXPAND_LETBINDING__V3*/
        meltfptr[2] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl23", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_130_WARMELTmiMACRO_LAMBDA_cl23_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_130_WARMELTmiMACRO_LAMBDA_cl23*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_131_WARMELTmiMACRO_LAMBDA_cl24(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
                                        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 fromline 1718 */

    /** start of frame for meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24// fromline 1534
        : public Melt_CallFrameWithValues<3>
    {
    public: /* fromline 1538*/
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
        MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<3> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24), clos) {};
        MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24() //the constructor fromline 1608
            : Melt_CallFrameWithValues<3> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<3> (fil,lin, sizeof(MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24)) {};
        MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<3> (fil,lin, sizeof(MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24


    /** end of frame for meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 fromline 1663**/

    /* end of frame for routine meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 fromline 1722 */

    /* classy proc frame meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 */
    MeltFrame_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_131_WARMELTmiMACRO_LAMBDA_cl24 fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("LAMBDA_cl24", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6843:/ getarg");
    /*_.E__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;
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
        /*^apply*/
        /*apply*/
        {
            union meltparam_un argtab[3];
            memset(&argtab, 0, sizeof(argtab));
            /*^apply.arg*/
            argtab[0].meltbp_aptr = (melt_ptr_t*) &(/*~NEWENV*/ meltfclos->tabval[1]);
            /*^apply.arg*/
            argtab[1].meltbp_aptr = (melt_ptr_t*) &(/*~MEXPANDER*/ meltfclos->tabval[0]);
            /*^apply.arg*/
            argtab[2].meltbp_aptr = (melt_ptr_t*) &(/*~MODCTX*/ meltfclos->tabval[2]);
            /*_.MEXPANDER__V3*/
            meltfptr[2] =  melt_apply ((meltclosure_ptr_t)((/*~MEXPANDER*/ meltfclos->tabval[0])), (melt_ptr_t)(/*_.E__V2*/ meltfptr[1]), (MELTBPARSTR_PTR MELTBPARSTR_PTR MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
        }
        ;
        /*^quasiblock*/


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.MEXPANDER__V3*/ meltfptr[2];;

        {
            MELT_LOCATION("warmelt-macro.melt:6843:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.MEXPANDER__V3*/
        meltfptr[2] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("LAMBDA_cl24", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_131_WARMELTmiMACRO_LAMBDA_cl24_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_131_WARMELTmiMACRO_LAMBDA_cl24*/





melt_ptr_t MELT_MODULE_VISIBILITY
meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE(meltclosure_ptr_t meltclosp_, melt_ptr_t meltfirstargp_, const melt_argdescr_cell_t meltxargdescr_[], union meltparam_un *meltxargtab_,
        const melt_argdescr_cell_t meltxresdescr_[], union meltparam_un *meltxrestab_)
{
    long current_blocklevel_signals_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE_melt =  melt_blocklevel_signals;

#if MELT_HAVE_DEBUG
    static long melt_call_counter__;
    long melt_thiscallcounter__ ATTRIBUTE_UNUSED = ++ melt_call_counter__;
#undef meltcallcount
#define meltcallcount melt_thiscallcounter__
#else
#undef meltcallcount
#define meltcallcount 0L
#endif
//// emitted by output_curframe_declstruct_init using OUTPUT_CURFRAME_DECLSTRUCT @warmelt-outobj.melt:1504

    /* start of frame for routine meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE fromline 1718 */

    /** start of frame for meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE of CLASS_PROCROUTINEOBJ from 1521**/

    /*curframdeclclassy*/ class MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE// fromline 1534
        : public Melt_CallFrameWithValues<5>
    {
    public: /* fromline 1538*/
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
        MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE(meltclosure_ptr_t clos) //the closure constructor fromline 1596
            : Melt_CallFrameWithValues<5> (
#if ENABLE_CHECKING /*fromline 1600*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1604*/
                sizeof(MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE), clos) {};
        MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE() //the constructor fromline 1608
            : Melt_CallFrameWithValues<5> (
#if ENABLE_CHECKING /*fromline 1612*/
                __FILE__, __LINE__,
#endif /* ENABLE_CHECKING fromline 1616*/
                sizeof(MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE)) {};
#if ENABLE_CHECKING /*fromline 1620*/
        MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE(const char*fil, int lin) //the constructor fromline 1622
            : Melt_CallFrameWithValues<5> (fil,lin, sizeof(MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE)) {};
        MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE(const char*fil, int lin, meltclosure_ptr_t clos) //the closure constructor fromline 1627
            : Melt_CallFrameWithValues<5> (fil,lin, sizeof(MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE), clos) {};
#endif /* ENABLE_CHECKING fromline 1632*/

    }; // end  class MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE


    /** end of frame for meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE fromline 1663**/

    /* end of frame for routine meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE fromline 1722 */

    /* classy proc frame meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE */
    MeltFrame_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE
    meltfram__ /*declfrastruct fromline 1746*/
    /*classyprocarg meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE fromline 1751*/
#if ENABLE_CHECKING
    (__FILE__, __LINE__, meltclosp_) /* fromline 1755*/
#else /*ENABLE_CHECKING */
    (meltclosp_) /* fromline 1759*/
#endif /*ENABLE_CHECKING */

    ;
#define meltframe meltfram__

    melt_trace_start("YES_RECURSIVELY_CONSTRUCTIBLE", meltcallcount);
    /*use arguments*/
    (void) meltclosp_;
    (void)meltfirstargp_;
    (void)meltxargdescr_;
    (void)meltxargtab_;
    (void)meltxresdescr_;
    (void)meltxrestab_;
    /*getargs*/

    /*getarg#0*/
    MELT_LOCATION("warmelt-macro.melt:6868:/ getarg");
    /*_.RECV__V2*/
    meltfptr[1] = (melt_ptr_t) meltfirstargp_;
    ;
    goto meltlab_endgetargs;
meltlab_endgetargs:
    ;
    /*body*/
    /*^block*/
    /*anyblock*/
    {


#if MELT_HAVE_DEBUG
        MELT_LOCATION("warmelt-macro.melt:6869:/ cppif.then");
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*melt_increment_dbgcounter*/
#if MELT_HAVE_DEBUG
                melt_dbgcounter++;
#endif
                ;
            }
            ;

            MELT_CHECK_SIGNAL();
            ;
            /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] =
                /*MELT_NEED_DBG*/
#if MELT_HAVE_DEBUG
                (/*melt_need_dbg*/ melt_need_debug ((int) 0))
#else
                0 /* no melt_need_dbg */
#endif /*MELT_HAVE_DEBUG*/
                ;;
            MELT_LOCATION("warmelt-macro.melt:6869:/ cond");
            /*cond*/
            if (/*_#MELT_NEED_DBG__L1*/ meltfnum[0]) /*then*/
                {
                    /*^cond.then*/
                    /*^block*/
                    /*anyblock*/
                    {

                        /*_#MELT_CALLCOUNT__L2*/ meltfnum[1] =
                            /* for melt_callcount */
#if MELT_HAVE_DEBUG && defined (meltcallcount)
                            meltcallcount  /* melt_callcount debugging */
#else
                            0L  /* melt_callcount without debug */
#endif /* MELT_HAVE_DEBUG melt_callcount */
                            ;;

                        MELT_CHECK_SIGNAL();
                        ;
                        MELT_LOCATION("warmelt-macro.melt:6869:/ apply");
                        /*apply*/
                        {
                            union meltparam_un argtab[5];
                            memset(&argtab, 0, sizeof(argtab));
                            /*^apply.arg*/
                            argtab[0].meltbp_long = /*_#MELT_CALLCOUNT__L2*/ meltfnum[1];
                            /*^apply.arg*/
                            argtab[1].meltbp_cstring =  "warmelt-macro.melt";
                            /*^apply.arg*/
                            argtab[2].meltbp_long = 6869;
                            /*^apply.arg*/
                            argtab[3].meltbp_cstring =  "yes_recursively_constructible recv";
                            /*^apply.arg*/
                            argtab[4].meltbp_aptr = (melt_ptr_t*) &/*_.RECV__V2*/ meltfptr[1];
                            /*_.MELT_DEBUG_FUN__V4*/
                            meltfptr[3] =  melt_apply ((meltclosure_ptr_t)((/*!MELT_DEBUG_FUN*/ meltfrout->tabval[0])), (melt_ptr_t)((/*nil*/NULL)), (MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_LONG MELTBPARSTR_CSTRING MELTBPARSTR_PTR ""), argtab, "", (union meltparam_un*)0);
                        }
                        ;
                        /*_._IF___V3*/
                        meltfptr[2] = /*_.MELT_DEBUG_FUN__V4*/ meltfptr[3];;
                        /*epilog*/

                        MELT_LOCATION("warmelt-macro.melt:6869:/ clear");
                        /*clear*/ /*_#MELT_CALLCOUNT__L2*/
                        meltfnum[1] = 0 ;
                        /*^clear*/
                        /*clear*/ /*_.MELT_DEBUG_FUN__V4*/
                        meltfptr[3] = 0 ;
                    }
                    ;
                }
            else    /*^cond.else*/
                {

                    /*_._IF___V3*/ meltfptr[2] =  /*reallynil*/ NULL ;;
                }
            ;

            {
                MELT_LOCATION("warmelt-macro.melt:6869:/ locexp");
                /*void*/
                (void)0;
            }
            ;
            /*^quasiblock*/


            /*epilog*/

            /*^clear*/
            /*clear*/ /*_#MELT_NEED_DBG__L1*/
            meltfnum[0] = 0 ;
            /*^clear*/
            /*clear*/ /*_._IF___V3*/
            meltfptr[2] = 0 ;
        }

#else /*MELT_HAVE_DEBUG*/
        /*^cppif.else*/
        /*^block*/
        /*anyblock*/
        {


            {
                /*^locexp*/
                /*void*/(void)0;
            }
            ;
            /*epilog*/
        }

#endif /*MELT_HAVE_DEBUG*/
        ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6870:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RECV__V2*/ meltfptr[1];;

        {
            MELT_LOCATION("warmelt-macro.melt:6870:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;

        MELT_CHECK_SIGNAL();
        ;
        MELT_LOCATION("warmelt-macro.melt:6868:/ quasiblock");


        /*_._RETVAL___V1*/
        meltfptr[0] = /*_.RETURN___V5*/ meltfptr[3];;

        {
            MELT_LOCATION("warmelt-macro.melt:6868:/ locexp");
            /*ochecknores compilobj_nrep_return*/
#if MELT_HAVE_DEBUG
            if (meltxresdescr_ && meltxresdescr_[0] && meltxrestab_)
                melt_warn_for_no_expected_secondary_results();
            /* we warned when secondary results are expected but not returned. */
#endif /*MELT_HAVE_DEBUG*/
            ;
        }
        ;
        /*^finalreturn*/
        ;
        /*finalret*/
        goto meltlabend_rout ;
        /*epilog*/

        /*^clear*/
        /*clear*/ /*_.RETURN___V5*/
        meltfptr[3] = 0 ;
    }

    ;
    goto meltlabend_rout;
meltlabend_rout:
    melt_trace_end("YES_RECURSIVELY_CONSTRUCTIBLE", meltcallcount);
    melt_blocklevel_signals = current_blocklevel_signals_meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE_melt;
    return (melt_ptr_t)(/*_._RETVAL___V1*/ meltfptr[0]);
#undef meltcallcount
#undef meltfram__
#undef MELTFRAM_NBVARNUM
#undef MELTFRAM_NBVARPTR
} /*end meltrout_132_WARMELTmiMACRO_YES_RECURSIVELY_CONSTRUCTIBLE*/



/**** end of warmelt-macro+05.cc ****/
