/* Definitions for C++ parsing and type checking.
   Copyright (C) 1987, 92-97, 1998, 1999 Free Software Foundation, Inc.
   Hacked by Michael Tiemann (tiemann@cygnus.com)

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

#include "c-common.h"
#include "function.h"
#include "varray.h"

#ifndef _CP_TREE_H
#define _CP_TREE_H

/* Usage of TREE_LANG_FLAG_?:
   0: BINFO_MARKED (BINFO nodes).
      COMPOUND_STMT_NO_SCOPE (in COMPOUND_STMT).
      NEW_EXPR_USE_GLOBAL (in NEW_EXPR).
      DELETE_EXPR_USE_GLOBAL (in DELETE_EXPR).
      LOOKUP_EXPR_GLOBAL (in LOOKUP_EXPR).
      TREE_NEGATED_INT (in INTEGER_CST).
      TREE_INDIRECT_USING (in NAMESPACE_DECL).
      IDENTIFIER_MARKED (used by search routines).
      LOCAL_BINDING_P (in CPLUS_BINDING)
      ICS_USER_FLAG (in _CONV)
      CLEANUP_P (in TRY_BLOCK)
      AGGR_INIT_VIA_CTOR_P (in AGGR_INIT_EXPR)
      SCOPE_BEGIN_P (in SCOPE_STMT)
   1: IDENTIFIER_VIRTUAL_P.
      TI_PENDING_TEMPLATE_FLAG.
      TEMPLATE_PARMS_FOR_INLINE.
      DELETE_EXPR_USE_VEC (in DELETE_EXPR).
      (TREE_CALLS_NEW) (in _EXPR or _REF) (commented-out).
      TYPE_USES_COMPLEX_INHERITANCE (in _TYPE).
      C_DECLARED_LABEL_FLAG (in LABEL_DECL)
      INHERITED_VALUE_BINDING_P (in CPLUS_BINDING)
      BASELINK_P (in TREE_LIST)
      ICS_ELLIPSIS_FLAG (in _CONV)
      STMT_IS_FULL_EXPR_P (in _STMT)
   2: IDENTIFIER_OPNAME_P.
      BINFO_VBASE_MARKED.
      BINFO_FIELDS_MARKED.
      TYPE_VIRTUAL_P.
      ICS_THIS_FLAG (in _CONV)
      STMT_LINENO_FOR_FN_P (in _STMT)
      BINDING_HAS_LEVEL_P (in CPLUS_BINDING)
   3: TYPE_USES_VIRTUAL_BASECLASSES (in a class TYPE).
      BINFO_VTABLE_PATH_MARKED.
      BINFO_PUSHDECLS_MARKED.
      (TREE_REFERENCE_EXPR) (in NON_LVALUE_EXPR) (commented-out).
      ICS_BAD_FLAG (in _CONV)
      FN_TRY_BLOCK_P (in TRY_BLOCK)
      SCOPE_NULLIFIED_P (in SCOPE_STMT)
   4: BINFO_NEW_VTABLE_MARKED.
      TREE_HAS_CONSTRUCTOR (in INDIRECT_REF, SAVE_EXPR, CONSTRUCTOR,
          or FIELD_DECL).
      NEED_TEMPORARY_P (in REF_BIND, BASE_CONV)
      SCOPE_PARTIAL_P (in SCOPE_STMT)
   5: Not used.
   6: Not used.

   Usage of TYPE_LANG_FLAG_?:
   0: C_TYPE_FIELDS_READONLY (in RECORD_TYPE or UNION_TYPE).
   1: TYPE_HAS_CONSTRUCTOR.
   2: TYPE_HAS_DESTRUCTOR.
   3: TYPE_FOR_JAVA.
   4: TYPE_NEEDS_DESTRUCTOR.
   5: IS_AGGR_TYPE.
   6: TYPE_BUILT_IN.

   Usage of DECL_LANG_FLAG_?:
   0: DECL_ERROR_REPORTED (in VAR_DECL).
      DECL_TEMPLATE_PARM_P (in CONST_DECL, TYPE_DECL, or TEMPLATE_DECL)
      DECL_LOCAL_FUNCTION_P (in FUNCTION_DECL)
   1: C_TYPEDEF_EXPLICITLY_SIGNED (in TYPE_DECL).
      DECL_TEMPLATE_INSTANTIATED (in a VAR_DECL or a FUNCTION_DECL)
   2: DECL_THIS_EXTERN (in VAR_DECL or FUNCTION_DECL).
      DECL_IMPLICIT_TYPEDEF_P (in a TYPE_DECL)
   3: DECL_IN_AGGR_P.
   4: DECL_MAYBE_TEMPLATE.
   5: DECL_INTERFACE_KNOWN.
   6: DECL_THIS_STATIC (in VAR_DECL or FUNCTION_DECL).
   7: DECL_DEAD_FOR_LOCAL (in VAR_DECL).

   Usage of language-independent fields in a language-dependent manner:
   
   TYPE_ALIAS_SET
     This field is used by TYPENAME_TYPEs, TEMPLATE_TYPE_PARMs, and so
     forth as a substitute for the mark bits provided in `lang_type'.
     At present, only the six low-order bits are used.

   TYPE_BINFO
     For an ENUMERAL_TYPE, this is ENUM_TEMPLATE_INFO.
     For a TYPENAME_TYPE, this is TYPENAME_TYPE_FULLNAME.
     For a TEMPLATE_TEMPLATE_PARM, this is
     TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO.

   DECL_SAVED_INSNS/DECL_FIELD_SIZE
     For a static VAR_DECL, this is DECL_INIT_PRIORITY.

   BINFO_VIRTUALS
     For a binfo, this is a TREE_LIST.  The TREE_PURPOSE of each node
     gives the amount by which to adjust the `this' pointer when
     calling the function.  The TREE_VALUE is the declaration for the 
     virtual function itself.  When CLASSTYPE_COM_INTERFACE_P does not
     hold, the first entry does not have a TREE_VALUE; it is just an
     offset.

   DECL_ARGUMENTS
     For a VAR_DECL this is DECL_ANON_UNION_ELEMS.  */

/* Language-specific tree checkers. */

#if defined ENABLE_CHECKING && (GCC_VERSION >= 2007)

#define VAR_OR_FUNCTION_DECL_CHECK(NODE)			\
({  const tree __t = NODE;					\
    enum tree_code __c = TREE_CODE(__t);			\
    if (__c != VAR_DECL && __c != FUNCTION_DECL)		\
      tree_check_failed (__t, VAR_DECL, __FILE__,		\
			 __LINE__, __PRETTY_FUNCTION__);	\
    __t; })

#define VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK(NODE)		\
({  const tree __t = NODE;					\
    enum tree_code __c = TREE_CODE(__t);			\
    if (__c != VAR_DECL 					\
	&& __c != FUNCTION_DECL					\
	&& __c != TYPE_DECL					\
	&& __c != TEMPLATE_DECL)				\
      tree_check_failed (__t, VAR_DECL, __FILE__,		\
			 __LINE__, __PRETTY_FUNCTION__);	\
    __t; })

#define RECORD_OR_UNION_TYPE_CHECK(NODE)			\
({  const tree __t = NODE;					\
    enum tree_code __c = TREE_CODE(__t);			\
    if (__c != RECORD_TYPE && __c != UNION_TYPE)		\
      tree_check_failed (__t, RECORD_TYPE, __FILE__,		\
			 __LINE__, __PRETTY_FUNCTION__);	\
    __t; })

#else /* not ENABLE_CHECKING, or not gcc */

#define VAR_OR_FUNCTION_DECL_CHECK(NODE)	NODE
#define VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK(NODE)	NODE
#define RECORD_OR_UNION_TYPE_CHECK(NODE)	NODE

#endif

/* Language-dependent contents of an identifier.  */

struct lang_identifier
{
  struct tree_identifier ignore;
  tree namespace_bindings;
  tree bindings;
  tree class_value;
  tree class_template_info;
  struct lang_id2 *x;
};

#define LANG_IDENTIFIER_CAST(NODE) \
	((struct lang_identifier*)IDENTIFIER_NODE_CHECK (NODE))

struct lang_id2
{
  tree label_value, implicit_decl;
  tree error_locus;
};

typedef struct 
{
  tree t;
  int new_type_flag;
} flagged_type_tree;

typedef struct 
{
  char common[sizeof (struct tree_common)];
  HOST_WIDE_INT index;
  HOST_WIDE_INT level;
  HOST_WIDE_INT orig_level;
  tree decl;
} template_parm_index;

typedef struct ptrmem_cst
{
  char common[sizeof (struct tree_common)];
  /* This isn't used, but the middle-end expects all constants to have 
     this field.  */
  struct rtx_def *rtl;
  tree member;
}* ptrmem_cst_t;

/* Nonzero if this binding is for a local scope, as opposed to a class
   or namespace scope.  */
#define LOCAL_BINDING_P(NODE) TREE_LANG_FLAG_0(NODE)

/* Nonzero if BINDING_VALUE is from a base class of the class which is
   currently being defined.  */
#define INHERITED_VALUE_BINDING_P(NODE) TREE_LANG_FLAG_1(NODE)

/* For a binding between a name and an entity at a non-local scope,
   defines the scope where the binding is declared.  (Either a class
   _TYPE node, or a NAMESPACE_DECL.)  This macro should be used only
   for namespace-level bindings; on the IDENTIFIER_BINDING list
   BINDING_LEVEL is used instead.  */
#define BINDING_SCOPE(NODE) (((struct tree_binding*)CPLUS_BINDING_CHECK (NODE))->scope.scope)

/* Nonzero if NODE has BINDING_LEVEL, rather than BINDING_SCOPE.  */
#define BINDING_HAS_LEVEL_P(NODE) TREE_LANG_FLAG_2 ((NODE))

/* This is the declaration bound to the name. Possible values:
   variable, overloaded function, namespace, template, enumerator.  */
#define BINDING_VALUE(NODE)    (((struct tree_binding*)CPLUS_BINDING_CHECK (NODE))->value)

/* If name is bound to a type, this is the type (struct, union, enum).  */
#define BINDING_TYPE(NODE)     TREE_TYPE(NODE)

#define IDENTIFIER_GLOBAL_VALUE(NODE) \
  namespace_binding (NODE, global_namespace)
#define SET_IDENTIFIER_GLOBAL_VALUE(NODE, VAL) \
  set_namespace_binding (NODE, global_namespace, VAL)
#define IDENTIFIER_NAMESPACE_VALUE(NODE) \
  namespace_binding (NODE, current_namespace)
#define SET_IDENTIFIER_NAMESPACE_VALUE(NODE, VAL) \
  set_namespace_binding (NODE, current_namespace, VAL)

struct tree_binding
{
  char common[sizeof (struct tree_common)];
  union {
    tree scope;
    struct binding_level *level;
  } scope;
  tree value;
};

/* The overloaded FUNCTION_DECL. */
#define OVL_FUNCTION(NODE)   (((struct tree_overload*)OVERLOAD_CHECK (NODE))->function)
#define OVL_CHAIN(NODE)      TREE_CHAIN(NODE)
/* Polymorphic access to FUNCTION and CHAIN. */
#define OVL_CURRENT(NODE)     \
  ((TREE_CODE(NODE)==OVERLOAD) ? OVL_FUNCTION(NODE) : NODE)
#define OVL_NEXT(NODE)        \
  ((TREE_CODE(NODE)==OVERLOAD) ? TREE_CHAIN(NODE) : NULL_TREE)
/* If set, this was imported in a using declaration.
   This is not to confuse with being used somewhere, which
   is not important for this node. */
#define OVL_USED(NODE)        TREE_USED(NODE)

struct tree_overload
{
  char common[sizeof (struct tree_common)];
  tree function;
};

/* A `baselink' is a TREE_LIST whose TREE_PURPOSE is a BINFO
   indicating a particular base class, and whose TREE_VALUE is a
   (possibly overloaded) function from that base class.  */
#define BASELINK_P(NODE) \
  (TREE_CODE (NODE) == TREE_LIST && TREE_LANG_FLAG_1 (NODE))
#define SET_BASELINK_P(NODE) \
  (TREE_LANG_FLAG_1 (NODE) = 1)

#define WRAPPER_PTR(NODE) (((struct tree_wrapper*)WRAPPER_CHECK (NODE))->u.ptr)
#define WRAPPER_INT(NODE) (((struct tree_wrapper*)WRAPPER_CHECK (NODE))->u.i)

struct tree_wrapper
{
  char common[sizeof (struct tree_common)];
  union {
    void *ptr;
    int i;
  } u;
};

#define SRCLOC_FILE(NODE) (((struct tree_srcloc*)SRCLOC_CHECK (NODE))->filename)
#define SRCLOC_LINE(NODE) (((struct tree_srcloc*)SRCLOC_CHECK (NODE))->linenum)
struct tree_srcloc
{
  char common[sizeof (struct tree_common)];
  char *filename;
  int linenum;
};

/* To identify to the debug emitters if it should pay attention to the
   flag `-Wtemplate-debugging'.  */
#define HAVE_TEMPLATES 1

/* Macros for access to language-specific slots in an identifier.  */

#define IDENTIFIER_NAMESPACE_BINDINGS(NODE)	\
  (LANG_IDENTIFIER_CAST (NODE)->namespace_bindings)
#define IDENTIFIER_TEMPLATE(NODE)	\
  (LANG_IDENTIFIER_CAST (NODE)->class_template_info)

/* The IDENTIFIER_BINDING is the innermost CPLUS_BINDING for the
    identifier.  It's TREE_CHAIN is the next outermost binding.  Each
    BINDING_VALUE is a DECL for the associated declaration.  Thus,
    name lookup consists simply of pulling off the node at the front
    of the list (modulo oddities for looking up the names of types,
    and such.)  You can use BINDING_SCOPE or BINDING_LEVEL to
    determine the scope that bound the name.  */
#define IDENTIFIER_BINDING(NODE) \
  (LANG_IDENTIFIER_CAST (NODE)->bindings)

/* The IDENTIFIER_VALUE is the value of the IDENTIFIER_BINDING, or
   NULL_TREE if there is no binding.  */
#define IDENTIFIER_VALUE(NODE)			\
  (IDENTIFIER_BINDING (NODE) 			\
   ? BINDING_VALUE (IDENTIFIER_BINDING (NODE))	\
   : NULL_TREE)

/* If IDENTIFIER_CLASS_VALUE is set, then NODE is bound in the current
   class, and IDENTIFIER_CLASS_VALUE is the value binding.  This is
   just a pointer to the BINDING_VALUE of one of the bindings in the
   IDENTIFIER_BINDINGs list, so any time that this is non-NULL so is
   IDENTIFIER_BINDING.  */
#define IDENTIFIER_CLASS_VALUE(NODE) \
  (LANG_IDENTIFIER_CAST (NODE)->class_value)

/* The amount of time used by the file whose special "time identifier"
   is NODE, represented as an INTEGER_CST.  See get_time_identifier.  */
#define TIME_IDENTIFIER_TIME(NODE) IDENTIFIER_BINDING(NODE)

/* For a "time identifier" this is a INTEGER_CST.  The
   TREE_INT_CST_LOW is 1 if the corresponding file is "interface only".
   The TRE_INT_CST_HIGH is 1 if it is "interface unknown".  */
#define TIME_IDENTIFIER_FILEINFO(NODE) IDENTIFIER_CLASS_VALUE (NODE)

/* TREE_TYPE only indicates on local and class scope the current
   type. For namespace scope, the presence of a type in any namespace
   is indicated with global_type_node, and the real type behind must
   be found through lookup. */
#define IDENTIFIER_TYPE_VALUE(NODE) (identifier_type_value(NODE))
#define REAL_IDENTIFIER_TYPE_VALUE(NODE) (TREE_TYPE (NODE))
#define SET_IDENTIFIER_TYPE_VALUE(NODE,TYPE) (TREE_TYPE (NODE) = TYPE)
#define IDENTIFIER_HAS_TYPE_VALUE(NODE) (IDENTIFIER_TYPE_VALUE (NODE) ? 1 : 0)

#define LANG_ID_FIELD(NAME,NODE)			\
  (LANG_IDENTIFIER_CAST (NODE)->x			\
   ? LANG_IDENTIFIER_CAST (NODE)->x->NAME : 0)	 

#define SET_LANG_ID(NODE,VALUE,NAME)					  \
  (LANG_IDENTIFIER_CAST (NODE)->x == 0				  \
   ? LANG_IDENTIFIER_CAST (NODE)->x					  \
      = (struct lang_id2 *)perm_calloc (1, sizeof (struct lang_id2)) : 0, \
   LANG_IDENTIFIER_CAST (NODE)->x->NAME = (VALUE))

#define IDENTIFIER_LABEL_VALUE(NODE)	    LANG_ID_FIELD(label_value, NODE)
#define SET_IDENTIFIER_LABEL_VALUE(NODE,VALUE)   \
	SET_LANG_ID(NODE, VALUE, label_value)

#define IDENTIFIER_IMPLICIT_DECL(NODE)	    LANG_ID_FIELD(implicit_decl, NODE)
#define SET_IDENTIFIER_IMPLICIT_DECL(NODE,VALUE) \
	SET_LANG_ID(NODE, VALUE, implicit_decl)

#define IDENTIFIER_ERROR_LOCUS(NODE)	    LANG_ID_FIELD(error_locus, NODE)
#define SET_IDENTIFIER_ERROR_LOCUS(NODE,VALUE)	\
	SET_LANG_ID(NODE, VALUE, error_locus)


#define IDENTIFIER_VIRTUAL_P(NODE) TREE_LANG_FLAG_1(NODE)

/* Nonzero if this identifier is the prefix for a mangled C++ operator
   name.  */
#define IDENTIFIER_OPNAME_P(NODE) TREE_LANG_FLAG_2(NODE)

/* Nonzero if this identifier is the name of a type-conversion
   operator.  */
#define IDENTIFIER_TYPENAME_P(NODE)			\
  (! strncmp (IDENTIFIER_POINTER (NODE),		\
              OPERATOR_TYPENAME_FORMAT,			\
	      strlen (OPERATOR_TYPENAME_FORMAT)))

/* Nonzero means reject anything that ANSI standard C forbids.  */
extern int pedantic;

/* In a RECORD_TYPE or UNION_TYPE, nonzero if any component is read-only.  */
#define C_TYPE_FIELDS_READONLY(type) TYPE_LANG_FLAG_0 (type)

/* Record in each node resulting from a binary operator
   what operator was specified for it.  */
#define C_EXP_ORIGINAL_CODE(exp) ((enum tree_code) TREE_COMPLEXITY (exp))

/* Store a value in that field.  */
#define C_SET_EXP_ORIGINAL_CODE(exp, code) \
  (TREE_COMPLEXITY (exp) = (int)(code))

/* If non-zero, a VAR_DECL whose cleanup will cause a throw to the
   next exception handler.  */
extern tree exception_throw_decl;

enum cp_tree_index
{
    CPTI_JAVA_BYTE_TYPE,
    CPTI_JAVA_SHORT_TYPE,
    CPTI_JAVA_INT_TYPE,
    CPTI_JAVA_LONG_TYPE,
    CPTI_JAVA_FLOAT_TYPE,
    CPTI_JAVA_DOUBLE_TYPE,
    CPTI_JAVA_CHAR_TYPE,
    CPTI_JAVA_BOOLEAN_TYPE,

    CPTI_VOID_ZERO,
    CPTI_WCHAR_DECL,
    CPTI_VTABLE_ENTRY_TYPE,
    CPTI_DELTA_TYPE,
    CPTI_CLEANUP_TYPE,

    CPTI_TP_DESC_TYPE,
    CPTI_ACCESS_MODE_TYPE,
    CPTI_BLTN_DESC_TYPE,
    CPTI_USER_DESC_TYPE,
    CPTI_CLASS_DESC_TYPE,
    CPTI_PTR_DESC_TYPE,
    CPTI_ATTR_DESC_TYPE,
    CPTI_FUNC_DESC_TYPE,
    CPTI_PTMF_DESC_TYPE,
    CPTI_PTMD_DESC_TYPE,
    
    CPTI_CLASS_STAR_TYPE,
    CPTI_CLASS_TYPE,
    CPTI_RECORD_TYPE,
    CPTI_UNION_TYPE,
    CPTI_ENUM_TYPE,
    CPTI_UNKNOWN_TYPE,
    CPTI_VTBL_TYPE,
    CPTI_VTBL_PTR_TYPE,
    CPTI_STD,
    CPTI_TYPE_INFO_TYPE,
    CPTI_TINFO_FN_ID,
    CPTI_TINFO_FN_TYPE,
    CPTI_ABORT_FNDECL,
    CPTI_GLOBAL_DELETE_FNDECL,

    CPTI_ACCESS_DEFAULT,
    CPTI_ACCESS_PUBLIC,
    CPTI_ACCESS_PROTECTED,
    CPTI_ACCESS_PRIVATE,
    CPTI_ACCESS_DEFAULT_VIRTUAL,
    CPTI_ACCESS_PUBLIC_VIRTUAL,
    CPTI_ACCESS_PROTECTED_VIRTUAL,
    CPTI_ACCESS_PRIVATE_VIRTUAL,

    CPTI_CTOR_IDENTIFIER,
    CPTI_DELTA2_IDENTIFIER,
    CPTI_DELTA_IDENTIFIER,
    CPTI_DTOR_IDENTIFIER,
    CPTI_IN_CHARGE_IDENTIFIER,
    CPTI_INDEX_IDENTIFIER,
    CPTI_NELTS_IDENTIFIER,
    CPTI_THIS_IDENTIFIER,
    CPTI_PFN_IDENTIFIER,
    CPTI_PFN_OR_DELTA2_IDENTIFIER,
    CPTI_VPTR_IDENTIFIER,

    CPTI_LANG_NAME_C,
    CPTI_LANG_NAME_CPLUSPLUS,
    CPTI_LANG_NAME_JAVA,

    CPTI_EMPTY_EXCEPT_SPEC,
    CPTI_NULL,
    CPTI_JCLASS,
    CPTI_MINUS_ONE,
    CPTI_TERMINATE,
    CPTI_ATEXIT,

    CPTI_MAX
};

extern tree cp_global_trees[CPTI_MAX];

#define java_byte_type_node		cp_global_trees[CPTI_JAVA_BYTE_TYPE]
#define java_short_type_node		cp_global_trees[CPTI_JAVA_SHORT_TYPE]
#define java_int_type_node		cp_global_trees[CPTI_JAVA_INT_TYPE]
#define java_long_type_node		cp_global_trees[CPTI_JAVA_LONG_TYPE]
#define java_float_type_node		cp_global_trees[CPTI_JAVA_FLOAT_TYPE]
#define java_double_type_node		cp_global_trees[CPTI_JAVA_DOUBLE_TYPE]
#define java_char_type_node		cp_global_trees[CPTI_JAVA_CHAR_TYPE]
#define java_boolean_type_node		cp_global_trees[CPTI_JAVA_BOOLEAN_TYPE]

#define void_zero_node			cp_global_trees[CPTI_VOID_ZERO]
#define wchar_decl_node			cp_global_trees[CPTI_WCHAR_DECL]
#define vtable_entry_type		cp_global_trees[CPTI_VTABLE_ENTRY_TYPE]
#define delta_type_node			cp_global_trees[CPTI_DELTA_TYPE]
#define __tp_desc_type_node		cp_global_trees[CPTI_TP_DESC_TYPE]
#define __access_mode_type_node		cp_global_trees[CPTI_ACCESS_MODE_TYPE]
#define __bltn_desc_type_node		cp_global_trees[CPTI_BLTN_DESC_TYPE]
#define __user_desc_type_node		cp_global_trees[CPTI_USER_DESC_TYPE]
#define __class_desc_type_node		cp_global_trees[CPTI_CLASS_DESC_TYPE]
#define __ptr_desc_type_node		cp_global_trees[CPTI_PTR_DESC_TYPE]
#define __attr_desc_type_node		cp_global_trees[CPTI_ATTR_DESC_TYPE]
#define __func_desc_type_node		cp_global_trees[CPTI_FUNC_DESC_TYPE]
#define __ptmf_desc_type_node		cp_global_trees[CPTI_PTMF_DESC_TYPE]
#define __ptmd_desc_type_node		cp_global_trees[CPTI_PTMD_DESC_TYPE]
#define class_star_type_node		cp_global_trees[CPTI_CLASS_STAR_TYPE]
#define class_type_node			cp_global_trees[CPTI_CLASS_TYPE]
#define record_type_node		cp_global_trees[CPTI_RECORD_TYPE]
#define union_type_node			cp_global_trees[CPTI_UNION_TYPE]
#define enum_type_node			cp_global_trees[CPTI_ENUM_TYPE]
#define unknown_type_node		cp_global_trees[CPTI_UNKNOWN_TYPE]
#define vtbl_type_node			cp_global_trees[CPTI_VTBL_TYPE]
#define vtbl_ptr_type_node		cp_global_trees[CPTI_VTBL_PTR_TYPE]
#define std_node			cp_global_trees[CPTI_STD]
#define type_info_type_node		cp_global_trees[CPTI_TYPE_INFO_TYPE]
#define tinfo_fn_id			cp_global_trees[CPTI_TINFO_FN_ID]
#define tinfo_fn_type			cp_global_trees[CPTI_TINFO_FN_TYPE]
#define abort_fndecl			cp_global_trees[CPTI_ABORT_FNDECL]
#define global_delete_fndecl		cp_global_trees[CPTI_GLOBAL_DELETE_FNDECL]

/* Define the sets of attributes that member functions and baseclasses
   can have.  These are sensible combinations of {public,private,protected}
   cross {virtual,non-virtual}.  */

#define access_default_node             cp_global_trees[CPTI_ACCESS_DEFAULT]
#define access_public_node              cp_global_trees[CPTI_ACCESS_PUBLIC]
#define access_protected_node           cp_global_trees[CPTI_ACCESS_PROTECTED]
#define access_private_node             cp_global_trees[CPTI_ACCESS_PRIVATE]
#define access_default_virtual_node     cp_global_trees[CPTI_ACCESS_DEFAULT_VIRTUAL]
#define access_public_virtual_node      cp_global_trees[CPTI_ACCESS_PUBLIC_VIRTUAL]
#define access_protected_virtual_node   cp_global_trees[CPTI_ACCESS_PROTECTED_VIRTUAL]
#define access_private_virtual_node     cp_global_trees[CPTI_ACCESS_PRIVATE_VIRTUAL]

/* We cache these tree nodes so as to call get_identifier less
   frequently.  */

#define ctor_identifier                 cp_global_trees[CPTI_CTOR_IDENTIFIER]
#define delta2_identifier               cp_global_trees[CPTI_DELTA2_IDENTIFIER]
#define delta_identifier                cp_global_trees[CPTI_DELTA_IDENTIFIER]
#define dtor_identifier                 cp_global_trees[CPTI_DTOR_IDENTIFIER]
#define in_charge_identifier            cp_global_trees[CPTI_IN_CHARGE_IDENTIFIER]
#define index_identifier                cp_global_trees[CPTI_INDEX_IDENTIFIER]
#define nelts_identifier                cp_global_trees[CPTI_NELTS_IDENTIFIER]
#define this_identifier                 cp_global_trees[CPTI_THIS_IDENTIFIER]
#define pfn_identifier                  cp_global_trees[CPTI_PFN_IDENTIFIER]
#define pfn_or_delta2_identifier        cp_global_trees[CPTI_PFN_OR_DELTA2_IDENTIFIER]
#define vptr_identifier                 cp_global_trees[CPTI_VPTR_IDENTIFIER]

#define lang_name_c                     cp_global_trees[CPTI_LANG_NAME_C]
#define lang_name_cplusplus             cp_global_trees[CPTI_LANG_NAME_CPLUSPLUS]
#define lang_name_java                  cp_global_trees[CPTI_LANG_NAME_JAVA]

/* Exception specifier used for throw().  */
#define empty_except_spec               cp_global_trees[CPTI_EMPTY_EXCEPT_SPEC]

/* The node for `__null'.  */
#define null_node                       cp_global_trees[CPTI_NULL]

/* If non-NULL, a POINTER_TYPE equivalent to (java::lang::Class*). */
#define jclass_node                     cp_global_trees[CPTI_JCLASS]

/* A node for `(int) -1'.  */
#define minus_one_node                  cp_global_trees[CPTI_MINUS_ONE]

/* The declaration for `std::terminate'.  */
#define terminate_node                  cp_global_trees[CPTI_TERMINATE]

/* The declaration for `std::atexit'.  */
#define atexit_node                     cp_global_trees[CPTI_ATEXIT]

/* The type of a destructor.  */
#define cleanup_type                    cp_global_trees[CPTI_CLEANUP_TYPE]

/* Global state.  */

struct stmt_tree {
  tree x_last_stmt;
  tree x_last_expr_type;
  int stmts_are_full_exprs_p; 
};

struct saved_scope {
  tree old_bindings;
  tree old_namespace;
  tree class_name;
  tree class_type;
  tree access_specifier;
  tree function_decl;
  varray_type lang_base;
  tree *lang_stack;
  tree lang_name;
  tree x_function_parms;
  tree template_parms;
  tree x_previous_class_type;
  tree x_previous_class_values;
  tree x_saved_tree;

  HOST_WIDE_INT x_processing_template_decl;
  int x_processing_specialization;
  int x_processing_explicit_instantiation;
  int need_pop_function_context;

  struct stmt_tree x_stmt_tree;

  struct binding_level *class_bindings;
  struct binding_level *bindings;

  struct saved_scope *prev;
};

/* The current open namespace.  */

#define current_namespace scope_chain->old_namespace

/* IDENTIFIER_NODE: name of current class */

#define current_class_name scope_chain->class_name

/* _TYPE: the type of the current class */

#define current_class_type scope_chain->class_type

/* When parsing a class definition, the access specifier most recently
   given by the user, or, if no access specifier was given, the
   default value appropriate for the kind of class (i.e., struct,
   class, or union).  */

#define current_access_specifier scope_chain->access_specifier

/* Pointer to the top of the language name stack.  */

#define current_lang_stack scope_chain->lang_stack
#define current_lang_base scope_chain->lang_base
#define current_lang_name scope_chain->lang_name

/* Parsing a function declarator leaves a list of parameter names
   or a chain or parameter decls here.  */

#define current_function_parms scope_chain->x_function_parms
#define current_template_parms scope_chain->template_parms

#define processing_template_decl scope_chain->x_processing_template_decl
#define processing_specialization scope_chain->x_processing_specialization
#define processing_explicit_instantiation scope_chain->x_processing_explicit_instantiation

/* _TYPE: the previous type that was a class */

#define previous_class_type scope_chain->x_previous_class_type

/* This is a copy of the class_shadowed list of the previous class
   binding contour when at global scope.  It's used to reset
   IDENTIFIER_CLASS_VALUEs when entering another class scope (i.e. a
   cache miss).  */

#define previous_class_values scope_chain->x_previous_class_values

extern struct saved_scope *scope_chain;

/* Global state pertinent to the current function.  */

struct language_function
{
  tree x_named_labels;
  tree x_ctor_label;
  tree x_dtor_label;
  tree x_base_init_list;
  tree x_member_init_list;
  tree x_current_class_ptr;
  tree x_current_class_ref;
  tree x_eh_spec_try_block;
  tree x_scope_stmt_stack;
  tree x_in_charge_parm;

  tree *x_vcalls_possible_p;

  struct rtx_def *x_result_rtx;

  int returns_value;
  int returns_null;
  int parms_stored;
  int temp_name_counter;
  int in_function_try_handler;
  int x_expanding_p;
  int name_declared;
  int vtbls_set_up_p;

  struct stmt_tree x_stmt_tree;

  struct named_label_list *x_named_label_uses;
  struct binding_level *bindings;

  const char *cannot_inline;
};

/* The current C++-specific per-function global variables.  */

#define cp_function_chain (current_function->language)

/* In a destructor, the point at which all derived class destroying
   has been done, just before any base class destroying will be done.  */

#define dtor_label cp_function_chain->x_dtor_label

/* In a constructor, the point at which we are ready to return
   the pointer to the initialized object.  */

#define ctor_label cp_function_chain->x_ctor_label

/* In C++, structures with well-defined constructors are initialized by
   those constructors, unasked.  CURRENT_BASE_INIT_LIST
   holds a list of stmts for a BASE_INIT term in the grammar.
   This list has one element for each base class which must be
   initialized.  The list elements are [basename, init], with
   type basetype.  This allows the possibly anachronistic form
   (assuming d : a, b, c) "d (int a) : c(a+5), b (a-4), a (a+3)"
   where each successive term can be handed down the constructor
   line.  Perhaps this was not intended.  */

#define current_base_init_list cp_function_chain->x_base_init_list
#define current_member_init_list cp_function_chain->x_member_init_list

/* When we're processing a member function, current_class_ptr is the
   PARM_DECL for the `this' pointer.  The current_class_ref is an
   expression for `*this'.  */

#define current_class_ptr \
  (current_function ? cp_function_chain->x_current_class_ptr : NULL_TREE)
#define current_class_ref \
  (current_function ? cp_function_chain->x_current_class_ref : NULL_TREE)

/* Information about the current statement tree.  */

#define current_stmt_tree			\
  (current_function 				\
   ? &cp_function_chain->x_stmt_tree		\
   : &scope_chain->x_stmt_tree)

/* When building a statement-tree, this is the last statement added to
   the tree.  */

#define last_tree current_stmt_tree->x_last_stmt

/* The type of the last expression-statement we have seen.  This is
   required because the type of a statement-expression is the type of
   the last expression statement.  */

#define last_expr_type current_stmt_tree->x_last_expr_type

/* The TRY_BLOCK for the exception-specifiers for the current
   function, if any.  */

#define current_eh_spec_try_block cp_function_chain->x_eh_spec_try_block

/* The stack of SCOPE_STMTs for the current function.  */

#define current_scope_stmt_stack cp_function_chain->x_scope_stmt_stack

/* The `__in_chrg' parameter for the current function.  Only used for
   destructors.  */

#define current_in_charge_parm cp_function_chain->x_in_charge_parm

/* In destructors, this is a pointer to a condition in an
   if-statement.  If the pointed-to value is boolean_true_node, then
   there may be virtual function calls in this destructor.  */

#define current_vcalls_possible_p cp_function_chain->x_vcalls_possible_p

/* Set to 0 at beginning of a function definition, set to 1 if
   a return statement that specifies a return value is seen.  */

#define current_function_returns_value cp_function_chain->returns_value

/* Set to 0 at beginning of a function definition, set to 1 if
   a return statement with no argument is seen.  */

#define current_function_returns_null cp_function_chain->returns_null

#define current_function_just_assigned_this \
  cp_function_chain->just_assigned_this

#define current_function_parms_stored \
  cp_function_chain->parms_stored

/* Non-zero if we have already declared __FUNCTION__ (and related
   variables) in the current function.  */

#define current_function_name_declared \
  cp_function_chain->name_declared

/* Nonzero if we have already generated code to initialize virtual
   function tables in this function.  */

#define vtbls_set_up_p cp_function_chain->vtbls_set_up_p

/* Used to help generate temporary names which are unique within
   a function.  Reset to 0 by start_function.  */

#define temp_name_counter cp_function_chain->temp_name_counter

/* Non-zero if we should generate RTL for functions that we process.
   When this is zero, we just accumulate tree structure, without
   interacting with the back end.  */

#define expanding_p cp_function_chain->x_expanding_p

/* Non-zero if we are in the semantic analysis phase for the current
   function.  */

#define doing_semantic_analysis_p() (!expanding_p)

/* Non-zero if we should treat statements as full expressions.  In
   particular, this variable is no-zero if at the end of a statement
   we should destroy any temporaries created during that statement.
   Similarly, if, at the end of a block, we should destroy any local
   variables in this block.  Normally, this variable is non-zero,
   since those are the normal semantics of C++.

   However, in order to represent aggregate initialization code as
   tree structure, we use statement-expressions.  The statements
   within the statement expression should not result in cleanups being
   run until the entire enclosing statement is complete.  */

#define stmts_are_full_exprs_p \
  current_stmt_tree->stmts_are_full_exprs_p

#define in_function_try_handler cp_function_chain->in_function_try_handler

extern tree current_function_return_value;
extern tree global_namespace;

extern tree ridpointers[];
extern tree ansi_opname[];
extern tree ansi_assopname[];

/* Nonzero means `$' can be in an identifier.  */

extern int dollars_in_ident;

/* Nonzero means allow type mismatches in conditional expressions;
   just make their values `void'.   */

extern int flag_cond_mismatch;

/* Nonzero means don't recognize the keyword `asm'.  */

extern int flag_no_asm;

/* For cross referencing.  */

extern int flag_gnu_xref;

/* For environments where you can use GNU binutils (as, ld in particular).  */

extern int flag_gnu_binutils;

/* Nonzero means warn about implicit declarations.  */

extern int warn_implicit;

/* Nonzero means warn about usage of long long when `-pedantic'.  */

extern int warn_long_long;

/* Nonzero means warn when all ctors or dtors are private, and the class
   has no friends.  */

extern int warn_ctor_dtor_privacy;

/* Nonzero means warn about function definitions that default the return type
   or that use a null return and have a return-type other than void.  */

extern int warn_return_type;

/* Nonzero means give string constants the type `const char *', as mandated
   by the standard.  */

extern int flag_const_strings;

/* If non-NULL, dump the tree structure for the entire translation
   unit to this file.  */

extern char *flag_dump_translation_unit;

/* Nonzero means warn about deprecated conversion from string constant to
   `char *'.  */

extern int warn_write_strings;

/* Nonzero means warn about sizeof(function) or addition/subtraction
   of function pointers.  */

extern int warn_pointer_arith;

/* Nonzero means warn about suggesting putting in ()'s.  */

extern int warn_parentheses;

/* Nonzero means warn about multiple (redundant) decls for the same single
   variable or function.  */

extern int warn_redundant_decls;

/* Warn if initializer is not completely bracketed.  */

extern int warn_missing_braces;

/* Warn about comparison of signed and unsigned values.  */

extern int warn_sign_compare;

/* Warn about testing equality of floating point numbers. */

extern int warn_float_equal;

/* Warn about a subscript that has type char.  */

extern int warn_char_subscripts;

/* Nonzero means warn about pointer casts that can drop a type qualifier
   from the pointer target type.  */

extern int warn_cast_qual;

/* Warn about *printf or *scanf format/argument anomalies.  */

extern int warn_format;

/* Nonzero means warn about non virtual destructors in classes that have
   virtual functions.  */

extern int warn_nonvdtor;

/* Non-zero means warn when we convert a pointer to member function
   into a pointer to (void or function).  */

extern int warn_pmf2ptr;

/* Nonzero means warn about violation of some Effective C++ style rules.  */

extern int warn_ecpp;

/* Nonzero means warn where overload resolution chooses a promotion from
   unsigned to signed over a conversion to an unsigned of the same size.  */

extern int warn_sign_promo;

/* Non-zero means warn when a function is declared extern and later inline.  */

extern int warn_extern_inline;

/* Non-zero means warn when an old-style cast is used.  */

extern int warn_old_style_cast;

/* Nonzero means to treat bitfields as unsigned unless they say `signed'.  */

extern int flag_signed_bitfields;

/* True for more efficient but incompatible (not fully tested)
   vtable implementation (using thunks).
   0 is old behavior; 1 is new behavior.  */
extern int flag_vtable_thunks;

/* INTERFACE_ONLY nonzero means that we are in an "interface"
   section of the compiler.  INTERFACE_UNKNOWN nonzero means
   we cannot trust the value of INTERFACE_ONLY.  If INTERFACE_UNKNOWN
   is zero and INTERFACE_ONLY is zero, it means that we are responsible
   for exporting definitions that others might need.  */
extern int interface_only, interface_unknown;

/* Nonzero means we should attempt to elide constructors when possible.  */

extern int flag_elide_constructors;

/* Nonzero means enable obscure ANSI features and disable GNU extensions
   that might cause ANSI-compliant code to be miscompiled.  */

extern int flag_ansi;

/* Nonzero means that member functions defined in class scope are
   inline by default.  */

extern int flag_default_inline;

/* The name-mangling scheme to use.  Versions of gcc before 2.8 use
   version 0.  */
extern int name_mangling_version;

/* Nonzero means that guiding declarations are allowed.  */
extern int flag_guiding_decls;

/* Nonzero if wchar_t should be `unsigned short' instead of whatever it
   would normally be, for use with WINE.  */
extern int flag_short_wchar;

/* Nonzero if squashed mangling is to be performed. 
   This uses the B and K codes to reference previously seen class types 
   and class qualifiers.       */
extern int flag_do_squangling;

/* Nonzero means generate separate instantiation control files and juggle
   them at link time.  */
extern int flag_use_repository;

/* Nonzero if we want to issue diagnostics that the standard says are not
   required.  */
extern int flag_optional_diags;

/* Nonzero means do not consider empty argument prototype to mean function
   takes no arguments.  */
extern int flag_strict_prototype;

/* Nonzero means output .vtable_{entry,inherit} for use in doing vtable gc.  */
extern int flag_vtable_gc;

/* Nonzero means make the default pedwarns warnings instead of errors.
   The value of this flag is ignored if -pedantic is specified.  */
extern int flag_permissive;

/* Nonzero if we want to obey access control semantics.  */

extern int flag_access_control;

/* If this variable is defined to a non-NULL value, it will be called
   after the file has been completely parsed.  The argument will be
   the GLOBAL_NAMESPACE.  */

extern void (*back_end_hook) PROTO((tree));


/* C++ language-specific tree codes.  */
#define DEFTREECODE(SYM, NAME, TYPE, LENGTH) SYM,
enum cplus_tree_code {
  __DUMMY = LAST_AND_UNUSED_TREE_CODE,
#include "cp-tree.def"
  LAST_CPLUS_TREE_CODE
};
#undef DEFTREECODE

enum languages { lang_c, lang_cplusplus, lang_java };

/* Macros to make error reporting functions' lives easier.  */
#define TYPE_IDENTIFIER(NODE) (DECL_NAME (TYPE_NAME (NODE)))
#define TYPE_NAME_STRING(NODE) (IDENTIFIER_POINTER (TYPE_IDENTIFIER (NODE)))
#define TYPE_NAME_LENGTH(NODE) (IDENTIFIER_LENGTH (TYPE_IDENTIFIER (NODE)))

#define TYPE_ASSEMBLER_NAME_STRING(NODE) (IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (TYPE_NAME  (NODE))))
#define TYPE_ASSEMBLER_NAME_LENGTH(NODE) (IDENTIFIER_LENGTH (DECL_ASSEMBLER_NAME (TYPE_NAME (NODE))))

/* The _DECL for this _TYPE.  */
#define TYPE_MAIN_DECL(NODE) (TYPE_STUB_DECL (TYPE_MAIN_VARIANT (NODE)))

/* Nonzero if T is a class (or struct or union) type.  Also nonzero
   for template type parameters, typename types, and instantiated
   template template parameters.  Despite its name,
   this macro has nothing to do with the definition of aggregate given
   in the standard.  Think of this macro as MAYBE_CLASS_TYPE_P.  */
#define IS_AGGR_TYPE(t)				\
  (TREE_CODE (t) == TEMPLATE_TYPE_PARM		\
   || TREE_CODE (t) == TYPENAME_TYPE		\
   || TREE_CODE (t) == TYPEOF_TYPE		\
   || (TREE_CODE (t) == TEMPLATE_TEMPLATE_PARM	\
       && TYPE_TEMPLATE_INFO (t))		\
   || TYPE_LANG_FLAG_5 (t))

/* Set IS_AGGR_TYPE for T to VAL.  T must be a class, struct, or 
   union type.  */ 
#define SET_IS_AGGR_TYPE(T, VAL) \
  (TYPE_LANG_FLAG_5 (T) = (VAL))

/* Nonzero if T is a class type.  Zero for template type parameters,
   typename types, and so forth.  */
#define CLASS_TYPE_P(t) \
  (IS_AGGR_TYPE_CODE (TREE_CODE (t)) && IS_AGGR_TYPE (t))

#define IS_AGGR_TYPE_CODE(t)	(t == RECORD_TYPE || t == UNION_TYPE)
#define IS_AGGR_TYPE_2(TYPE1,TYPE2) \
  (TREE_CODE (TYPE1) == TREE_CODE (TYPE2)	\
   && IS_AGGR_TYPE (TYPE1) && IS_AGGR_TYPE (TYPE2))
#define IS_OVERLOAD_TYPE(t) \
  (IS_AGGR_TYPE (t) || TREE_CODE (t) == ENUMERAL_TYPE)

/* In a *_TYPE, nonzero means a built-in type.  */
#define TYPE_BUILT_IN(NODE) TYPE_LANG_FLAG_6(NODE)

/* True if this a "Java" type, defined in 'extern "Java"'. */
#define TYPE_FOR_JAVA(NODE) TYPE_LANG_FLAG_3(NODE)

/* The type qualifiers for this type, including the qualifiers on the
   elements for an array type.  */
#define CP_TYPE_QUALS(NODE)			\
  ((TREE_CODE (NODE) != ARRAY_TYPE) 		\
   ? TYPE_QUALS (NODE) : cp_type_quals (NODE))

/* Nonzero if this type is const-qualified.  */
#define CP_TYPE_CONST_P(NODE)				\
  ((CP_TYPE_QUALS (NODE) & TYPE_QUAL_CONST) != 0)

/* Nonzero if this type is volatile-qualified.  */
#define CP_TYPE_VOLATILE_P(NODE)			\
  ((CP_TYPE_QUALS (NODE) & TYPE_QUAL_VOLATILE) != 0)

/* Nonzero if this type is restrict-qualified.  */
#define CP_TYPE_RESTRICT_P(NODE)			\
  ((CP_TYPE_QUALS (NODE) & TYPE_QUAL_RESTRICT) != 0)

/* Nonzero if this type is const-qualified, but not
   volatile-qualified.  Other qualifiers are ignored.  This macro is
   used to test whether or not it is OK to bind an rvalue to a
   reference.  */
#define CP_TYPE_CONST_NON_VOLATILE_P(NODE)				\
  ((CP_TYPE_QUALS (NODE) & (TYPE_QUAL_CONST | TYPE_QUAL_VOLATILE))	\
   == TYPE_QUAL_CONST)

#define DELTA_FROM_VTABLE_ENTRY(ENTRY) \
  (!flag_vtable_thunks ? \
     TREE_VALUE (CONSTRUCTOR_ELTS (ENTRY)) \
   : TREE_CODE (TREE_OPERAND ((ENTRY), 0)) != THUNK_DECL ? integer_zero_node \
   : build_int_2 (THUNK_DELTA (TREE_OPERAND ((ENTRY), 0)), 0))

/* Virtual function addresses can be gotten from a virtual function
   table entry using this macro.  */
#define FNADDR_FROM_VTABLE_ENTRY(ENTRY) \
  (!flag_vtable_thunks ? \
     TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY)))) \
   : TREE_CODE (TREE_OPERAND ((ENTRY), 0)) != THUNK_DECL ? (ENTRY) \
   : DECL_INITIAL (TREE_OPERAND ((ENTRY), 0)))
#define SET_FNADDR_FROM_VTABLE_ENTRY(ENTRY,VALUE) \
  (TREE_VALUE (TREE_CHAIN (TREE_CHAIN (CONSTRUCTOR_ELTS (ENTRY)))) = (VALUE))
#define FUNCTION_ARG_CHAIN(NODE) (TREE_CHAIN (TYPE_ARG_TYPES (TREE_TYPE (NODE))))
#define PROMOTES_TO_AGGR_TYPE(NODE,CODE)	\
  (((CODE) == TREE_CODE (NODE)			\
       && IS_AGGR_TYPE (TREE_TYPE (NODE)))	\
   || IS_AGGR_TYPE (NODE))

/* Nonzero iff TYPE is uniquely derived from PARENT.  Under MI, PARENT can
   be an ambiguous base class of TYPE, and this macro will be false.  */
#define UNIQUELY_DERIVED_FROM_P(PARENT, TYPE) (get_base_distance (PARENT, TYPE, 0, (tree *)0) >= 0)
#define ACCESSIBLY_DERIVED_FROM_P(PARENT, TYPE) (get_base_distance (PARENT, TYPE, -1, (tree *)0) >= 0)
#define ACCESSIBLY_UNIQUELY_DERIVED_P(PARENT, TYPE) (get_base_distance (PARENT, TYPE, 1, (tree *)0) >= 0)
#define DERIVED_FROM_P(PARENT, TYPE) (get_base_distance (PARENT, TYPE, 0, (tree *)0) != -1)

/* This structure provides additional information above and beyond
   what is provide in the ordinary tree_type.  In the past, we used it
   for the types of class types, template parameters types, typename
   types, and so forth.  However, there can be many (tens to hundreds
   of thousands) of template parameter types in a compilation, and
   there's no need for this additional information in that case.
   Therefore, we now use this data structure only for class types.

   In the past, it was thought that there would be relatively few
   class types.  However, in the presence of heavy use of templates,
   many (i.e., thousands) of classes can easily be generated.
   Therefore, we should endeavor to keep the size of this structure to
   a minimum.  */
struct lang_type
{
  unsigned char align;

  unsigned has_type_conversion : 1;
  unsigned has_init_ref : 1;
  unsigned has_default_ctor : 1;
  unsigned uses_multiple_inheritance : 1;
  unsigned const_needs_init : 1;
  unsigned ref_needs_init : 1;
  unsigned has_const_assign_ref : 1;
  unsigned anon_aggr : 1;

  unsigned has_nonpublic_ctor : 2;
  unsigned has_nonpublic_assign_ref : 2;
  unsigned vtable_needs_writing : 1;
  unsigned has_assign_ref : 1;
  unsigned gets_new : 2;

  unsigned gets_delete : 2;
  unsigned has_call_overloaded : 1;
  unsigned has_array_ref_overloaded : 1;
  unsigned has_arrow_overloaded : 1;
  unsigned interface_only : 1;
  unsigned interface_unknown : 1;
  unsigned needs_virtual_reinit : 1;

  unsigned marks: 6;
  unsigned vec_delete_takes_size : 1;
  unsigned declared_class : 1;

  unsigned being_defined : 1;
  unsigned redefined : 1;
  unsigned debug_requested : 1;
  unsigned use_template : 2;
  unsigned got_semicolon : 1;
  unsigned ptrmemfunc_flag : 1;
  unsigned was_anonymous : 1;

  unsigned has_real_assign_ref : 1;
  unsigned has_const_init_ref : 1;
  unsigned has_complex_init_ref : 1;
  unsigned has_complex_assign_ref : 1;
  unsigned has_abstract_assign_ref : 1;
  unsigned non_aggregate : 1;
  unsigned is_partial_instantiation : 1;
  unsigned has_mutable : 1;

  unsigned com_interface : 1;
  unsigned non_pod_class : 1;

  /* When adding a flag here, consider whether or not it ought to
     apply to a template instance if it applies to the template.  If
     so, make sure to copy it in instantiate_class_template!  */

  /* There are six bits left to fill out a 32-bit word.  Keep track of
     this by updating the size of this bitfield whenever you add or
     remove a flag.  */
  unsigned dummy : 6;
      
  int vsize;
  int vfield_parent;

  union tree_node *vfields;
  union tree_node *vbases;

  union tree_node *tags;

  union tree_node *search_slot;

  union tree_node *size;

  union tree_node *abstract_virtuals;
  union tree_node *friend_classes;

  union tree_node *rtti;

  union tree_node *methods;

  union tree_node *template_info;
  tree befriending_classes;
};

/* Indicates whether or not (and how) a template was expanded for this class.
     0=no information yet/non-template class
     1=implicit template instantiation
     2=explicit template specialization
     3=explicit template instantiation  */
#define CLASSTYPE_USE_TEMPLATE(NODE) (TYPE_LANG_SPECIFIC(NODE)->use_template)

/* Fields used for storing information before the class is defined.
   After the class is defined, these fields hold other information.  */

/* List of friends which were defined inline in this class definition.  */
#define CLASSTYPE_INLINE_FRIENDS(NODE) (TYPE_NONCOPIED_PARTS (NODE))

/* Nonzero for _CLASSTYPE means that operator new and delete are defined,
   respectively.  */
#define TYPE_GETS_NEW(NODE) (TYPE_LANG_SPECIFIC(NODE)->gets_new)
#define TYPE_GETS_DELETE(NODE) (TYPE_LANG_SPECIFIC(NODE)->gets_delete)
#define TYPE_GETS_REG_DELETE(NODE) (TYPE_GETS_DELETE (NODE) & 1)

/* Nonzero for _CLASSTYPE means that operator vec delete is defined and
   takes the optional size_t argument.  */
#define TYPE_VEC_DELETE_TAKES_SIZE(NODE) \
  (TYPE_LANG_SPECIFIC(NODE)->vec_delete_takes_size)
#define TYPE_VEC_NEW_USES_COOKIE(NODE) \
  (TYPE_NEEDS_DESTRUCTOR (NODE) \
   || (TYPE_LANG_SPECIFIC (NODE) && TYPE_VEC_DELETE_TAKES_SIZE (NODE)))

/* Nonzero means that this _CLASSTYPE node defines ways of converting
   itself to other types.  */
#define TYPE_HAS_CONVERSION(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_type_conversion)

/* Nonzero means that this _CLASSTYPE node overloads operator=(X&).  */
#define TYPE_HAS_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_assign_ref)
#define TYPE_HAS_CONST_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_const_assign_ref)

/* Nonzero means that this _CLASSTYPE node has an X(X&) constructor.  */
#define TYPE_HAS_INIT_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_init_ref)
#define TYPE_HAS_CONST_INIT_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_const_init_ref)

/* Nonzero means that this type is being defined.  I.e., the left brace
   starting the definition of this type has been seen.  */
#define TYPE_BEING_DEFINED(NODE) (TYPE_LANG_SPECIFIC(NODE)->being_defined)
/* Nonzero means that this type has been redefined.  In this case, if
   convenient, don't reprocess any methods that appear in its redefinition.  */
#define TYPE_REDEFINED(NODE) (TYPE_LANG_SPECIFIC(NODE)->redefined)

/* The is the basetype that contains NODE's rtti.  */
#define CLASSTYPE_RTTI(NODE) (TYPE_LANG_SPECIFIC(NODE)->rtti)

/* Nonzero means that this _CLASSTYPE node overloads operator().  */
#define TYPE_OVERLOADS_CALL_EXPR(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_call_overloaded)

/* Nonzero means that this _CLASSTYPE node overloads operator[].  */
#define TYPE_OVERLOADS_ARRAY_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_array_ref_overloaded)

/* Nonzero means that this _CLASSTYPE node overloads operator->.  */
#define TYPE_OVERLOADS_ARROW(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_arrow_overloaded)

/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses
   multiple inheritance.  If this is 0 for the root of a type
   hierarchy, then we can use more efficient search techniques.  */
#define TYPE_USES_MULTIPLE_INHERITANCE(NODE) (TYPE_LANG_SPECIFIC(NODE)->uses_multiple_inheritance)

/* Nonzero means that this _CLASSTYPE (or one of its ancestors) uses
   virtual base classes.  If this is 0 for the root of a type
   hierarchy, then we can use more efficient search techniques.  */
#define TYPE_USES_VIRTUAL_BASECLASSES(NODE) (TREE_LANG_FLAG_3(NODE))

/* Vector member functions defined in this class.  Each element is
   either a FUNCTION_DECL, a TEMPLATE_DECL, or an OVERLOAD.  All
   functions with the same name end up in the same slot.  The first
   two elements are for constructors, and destructors, respectively.
   These are followed by ordinary member functions.  There may be
   empty entries at the end of the vector.  */
#define CLASSTYPE_METHOD_VEC(NODE) (TYPE_LANG_SPECIFIC(NODE)->methods)

/* The first type conversion operator in the class (the others can be
   searched with TREE_CHAIN), or the first non-constructor function if
   there are no type conversion operators.  */
#define CLASSTYPE_FIRST_CONVERSION(NODE) \
  TREE_VEC_LENGTH (CLASSTYPE_METHOD_VEC (NODE)) > 2 \
    ? TREE_VEC_ELT (CLASSTYPE_METHOD_VEC (NODE), 2) \
    : NULL_TREE;

/* Mark bits for depth-first and breath-first searches.  */

/* Get the value of the Nth mark bit.  */
#define CLASSTYPE_MARKED_N(NODE, N)					\
  (((CLASS_TYPE_P (NODE) ? TYPE_LANG_SPECIFIC (NODE)->marks	\
     : TYPE_ALIAS_SET (NODE)) & (1 << N)) != 0)

/* Set the Nth mark bit.  */
#define SET_CLASSTYPE_MARKED_N(NODE, N)					\
  (CLASS_TYPE_P (NODE)							\
   ? (TYPE_LANG_SPECIFIC (NODE)->marks |= (1 << (N)))	\
   : (TYPE_ALIAS_SET (NODE) |= (1 << (N))))

/* Clear the Nth mark bit.  */
#define CLEAR_CLASSTYPE_MARKED_N(NODE, N)				\
  (CLASS_TYPE_P (NODE)							\
   ? (TYPE_LANG_SPECIFIC (NODE)->marks &= ~(1 << (N)))	\
   : (TYPE_ALIAS_SET (NODE) &= ~(1 << (N))))

/* Get the value of the mark bits.  */
#define CLASSTYPE_MARKED(NODE) CLASSTYPE_MARKED_N(NODE, 0)
#define CLASSTYPE_MARKED2(NODE) CLASSTYPE_MARKED_N(NODE, 1)
#define CLASSTYPE_MARKED3(NODE) CLASSTYPE_MARKED_N(NODE, 2)
#define CLASSTYPE_MARKED4(NODE) CLASSTYPE_MARKED_N(NODE, 3)
#define CLASSTYPE_MARKED5(NODE) CLASSTYPE_MARKED_N(NODE, 4)
#define CLASSTYPE_MARKED6(NODE) CLASSTYPE_MARKED_N(NODE, 5)

/* Macros to modify the above flags */
#define SET_CLASSTYPE_MARKED(NODE)    SET_CLASSTYPE_MARKED_N(NODE, 0)
#define CLEAR_CLASSTYPE_MARKED(NODE)  CLEAR_CLASSTYPE_MARKED_N(NODE, 0)
#define SET_CLASSTYPE_MARKED2(NODE)   SET_CLASSTYPE_MARKED_N(NODE, 1)
#define CLEAR_CLASSTYPE_MARKED2(NODE) CLEAR_CLASSTYPE_MARKED_N(NODE, 1)
#define SET_CLASSTYPE_MARKED3(NODE)   SET_CLASSTYPE_MARKED_N(NODE, 2)
#define CLEAR_CLASSTYPE_MARKED3(NODE) CLEAR_CLASSTYPE_MARKED_N(NODE, 2)	
#define SET_CLASSTYPE_MARKED4(NODE)   SET_CLASSTYPE_MARKED_N(NODE, 3)
#define CLEAR_CLASSTYPE_MARKED4(NODE) CLEAR_CLASSTYPE_MARKED_N(NODE, 3)
#define SET_CLASSTYPE_MARKED5(NODE)   SET_CLASSTYPE_MARKED_N(NODE, 4)
#define CLEAR_CLASSTYPE_MARKED5(NODE) CLEAR_CLASSTYPE_MARKED_N(NODE, 4)
#define SET_CLASSTYPE_MARKED6(NODE)   SET_CLASSTYPE_MARKED_N(NODE, 5)
#define CLEAR_CLASSTYPE_MARKED6(NODE) CLEAR_CLASSTYPE_MARKED_N(NODE, 5)

/* A list of the nested tag-types (class, struct, union, or enum)
   found within this class.  The TREE_PURPOSE of each node is the name
   of the type; the TREE_VALUE is the type itself.  This list includes
   nested member class templates.  */
#define CLASSTYPE_TAGS(NODE)		(TYPE_LANG_SPECIFIC(NODE)->tags)

/* If this class has any bases, this is the number of the base class from
   which our VFIELD is based, -1 otherwise.  If this class has no base
   classes, this is not used.
   In D : B1, B2, PARENT would be 0, if D's vtable came from B1,
   1, if D's vtable came from B2.  */
#define CLASSTYPE_VFIELD_PARENT(NODE)	(TYPE_LANG_SPECIFIC(NODE)->vfield_parent)

/* The number of virtual functions defined for this
   _CLASSTYPE node.  */
#define CLASSTYPE_VSIZE(NODE) (TYPE_LANG_SPECIFIC(NODE)->vsize)
/* The virtual base classes that this type uses.  */
#define CLASSTYPE_VBASECLASSES(NODE) (TYPE_LANG_SPECIFIC(NODE)->vbases)
/* The virtual function pointer fields that this type contains.  */
#define CLASSTYPE_VFIELDS(NODE) (TYPE_LANG_SPECIFIC(NODE)->vfields)

/* Number of baseclasses defined for this type.
   0 means no base classes.  */
#define CLASSTYPE_N_BASECLASSES(NODE) \
  (TYPE_BINFO_BASETYPES (NODE) ? TREE_VEC_LENGTH (TYPE_BINFO_BASETYPES(NODE)) : 0)

/* Used for keeping search-specific information.  Any search routine
   which uses this must define what exactly this slot is used for.  */
#define CLASSTYPE_SEARCH_SLOT(NODE) (TYPE_LANG_SPECIFIC(NODE)->search_slot)

/* These are the size, mode and alignment of the type without its
   virtual base classes, for when we use this type as a base itself.  */
#define CLASSTYPE_SIZE(NODE) (TYPE_LANG_SPECIFIC(NODE)->size)
#define CLASSTYPE_ALIGN(NODE) (TYPE_LANG_SPECIFIC(NODE)->align)

/* A cons list of virtual functions which cannot be inherited by
   derived classes.  When deriving from this type, the derived
   class must provide its own definition for each of these functions.  */
#define CLASSTYPE_ABSTRACT_VIRTUALS(NODE) (TYPE_LANG_SPECIFIC(NODE)->abstract_virtuals)

/* Nonzero means that this aggr type has been `closed' by a semicolon.  */
#define CLASSTYPE_GOT_SEMICOLON(NODE) (TYPE_LANG_SPECIFIC (NODE)->got_semicolon)

/* Nonzero means that the main virtual function table pointer needs to be
   set because base constructors have placed the wrong value there.
   If this is zero, it means that they placed the right value there,
   and there is no need to change it.  */
#define CLASSTYPE_NEEDS_VIRTUAL_REINIT(NODE) (TYPE_LANG_SPECIFIC(NODE)->needs_virtual_reinit)

/* Nonzero means that if this type has virtual functions, that
   the virtual function table will be written out.  */
#define CLASSTYPE_VTABLE_NEEDS_WRITING(NODE) (TYPE_LANG_SPECIFIC(NODE)->vtable_needs_writing)

/* Nonzero means that this type has an X() constructor.  */
#define TYPE_HAS_DEFAULT_CONSTRUCTOR(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_default_ctor)

/* Nonzero means the type declared a ctor as private or protected.  We
   use this to make sure we don't try to generate a copy ctor for a 
   class that has a member of type NODE.  */
#define TYPE_HAS_NONPUBLIC_CTOR(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_nonpublic_ctor)

/* Ditto, for operator=.  */
#define TYPE_HAS_NONPUBLIC_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_nonpublic_assign_ref)

/* Nonzero means that this type contains a mutable member */
#define CLASSTYPE_HAS_MUTABLE(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_mutable)
#define TYPE_HAS_MUTABLE_P(NODE) (cp_has_mutable_p (NODE))

/*  Nonzero means that this class type is a non-POD class.  */
#define CLASSTYPE_NON_POD_P(NODE) (TYPE_LANG_SPECIFIC (NODE)->non_pod_class)

/* Nonzero means that this type is meant for communication via COM.  */
#define CLASSTYPE_COM_INTERFACE(NODE) \
  (TYPE_LANG_SPECIFIC(NODE)->com_interface)

/* A list of class types of which this type is a friend.  The
   TREE_VALUE is normally a TYPE, but will be a TEMPLATE_DECL in the
   case of a template friend.  */
#define CLASSTYPE_FRIEND_CLASSES(NODE) (TYPE_LANG_SPECIFIC(NODE)->friend_classes)

/* A list of the classes which grant friendship to this class.  */
#define CLASSTYPE_BEFRIENDING_CLASSES(NODE) \
  (TYPE_LANG_SPECIFIC (NODE)->befriending_classes)

/* Say whether this node was declared as a "class" or a "struct".  */
#define CLASSTYPE_DECLARED_CLASS(NODE) (TYPE_LANG_SPECIFIC(NODE)->declared_class)

/* Nonzero if this class has const members which have no specified initialization.  */
#define CLASSTYPE_READONLY_FIELDS_NEED_INIT(NODE) (TYPE_LANG_SPECIFIC(NODE)->const_needs_init)

/* Nonzero if this class has ref members which have no specified initialization.  */
#define CLASSTYPE_REF_FIELDS_NEED_INIT(NODE) (TYPE_LANG_SPECIFIC(NODE)->ref_needs_init)

/* Nonzero if this class is included from a header file which employs
   `#pragma interface', and it is not included in its implementation file.  */
#define CLASSTYPE_INTERFACE_ONLY(NODE) (TYPE_LANG_SPECIFIC(NODE)->interface_only)

/* Same as above, but for classes whose purpose we do not know.  */
#define CLASSTYPE_INTERFACE_UNKNOWN(NODE) (TYPE_LANG_SPECIFIC(NODE)->interface_unknown)
#define CLASSTYPE_INTERFACE_KNOWN(NODE) (TYPE_LANG_SPECIFIC(NODE)->interface_unknown == 0)
#define SET_CLASSTYPE_INTERFACE_UNKNOWN_X(NODE,X) (TYPE_LANG_SPECIFIC(NODE)->interface_unknown = !!(X))
#define SET_CLASSTYPE_INTERFACE_UNKNOWN(NODE) (TYPE_LANG_SPECIFIC(NODE)->interface_unknown = 1)
#define SET_CLASSTYPE_INTERFACE_KNOWN(NODE) (TYPE_LANG_SPECIFIC(NODE)->interface_unknown = 0)

/* Nonzero if a _DECL node requires us to output debug info for this class.  */
#define CLASSTYPE_DEBUG_REQUESTED(NODE) (TYPE_LANG_SPECIFIC(NODE)->debug_requested)

/* Additional macros for inheritance information.  */

/* The BINFO_INHERITANCE_CHAIN is used opposite to the description in
   gcc/tree.h.  In particular if D is derived from B then the BINFO
   for B (in D) will have a BINFO_INHERITANCE_CHAIN pointing to
   D.  In tree.h, this pointer is described as pointing in other
   direction.  There is a different BINFO for each path to a virtual
   base; BINFOs for virtual bases are not shared.  In addition, shared
   versions of each of the virtual class BINFOs are stored in
   CLASSTYPE_VBASECLASSES.

   We use TREE_VIA_PROTECTED and TREE_VIA_PUBLIC, but private
   inheritance is indicated by the absence of the other two flags, not
   by TREE_VIA_PRIVATE, which is unused.

   The TREE_CHAIN is for scratch space in search.c.  */

/* Nonzero means marked by DFS or BFS search, including searches
   by `get_binfo' and `get_base_distance'.  */
#define BINFO_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED(BINFO_TYPE(NODE)):TREE_LANG_FLAG_0(NODE))
/* Macros needed because of C compilers that don't allow conditional
   expressions to be lvalues.  Grr!  */
#define SET_BINFO_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=1))
#define CLEAR_BINFO_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_0(NODE)=0))

/* Nonzero means marked in search through virtual inheritance hierarchy.  */
#define BINFO_VBASE_MARKED(NODE) CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
/* Modifier macros */
#define SET_BINFO_VBASE_MARKED(NODE) SET_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))
#define CLEAR_BINFO_VBASE_MARKED(NODE) CLEAR_CLASSTYPE_MARKED2 (BINFO_TYPE (NODE))

/* Nonzero means marked in search for members or member functions.  */
#define BINFO_FIELDS_MARKED(NODE) \
  (TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED2 (BINFO_TYPE (NODE)):TREE_LANG_FLAG_2(NODE))
#define SET_BINFO_FIELDS_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=1))
#define CLEAR_BINFO_FIELDS_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED2(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_2(NODE)=0))

/* Nonzero means that this class is on a path leading to a new vtable.  */
#define BINFO_VTABLE_PATH_MARKED(NODE) \
  (TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):TREE_LANG_FLAG_3(NODE))
#define SET_BINFO_VTABLE_PATH_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=1))
#define CLEAR_BINFO_VTABLE_PATH_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED3(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_3(NODE)=0))

/* Nonzero means that this class has a new vtable.  */
#define BINFO_NEW_VTABLE_MARKED(NODE) \
  (TREE_VIA_VIRTUAL(NODE)?CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):TREE_LANG_FLAG_4(NODE))
#define SET_BINFO_NEW_VTABLE_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?SET_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=1))
#define CLEAR_BINFO_NEW_VTABLE_MARKED(NODE) (TREE_VIA_VIRTUAL(NODE)?CLEAR_CLASSTYPE_MARKED4(BINFO_TYPE(NODE)):(TREE_LANG_FLAG_4(NODE)=0))

/* Nonzero means this class has done dfs_pushdecls.  */
#define BINFO_PUSHDECLS_MARKED(NODE) BINFO_VTABLE_PATH_MARKED (NODE)
#define SET_BINFO_PUSHDECLS_MARKED(NODE) SET_BINFO_VTABLE_PATH_MARKED (NODE)
#define CLEAR_BINFO_PUSHDECLS_MARKED(NODE) CLEAR_BINFO_VTABLE_PATH_MARKED (NODE)

/* Used by various search routines.  */
#define IDENTIFIER_MARKED(NODE) TREE_LANG_FLAG_0 (NODE)

/* Accessor macros for the vfield slots in structures.  */

/* Get the assoc info that caused this vfield to exist.  */
#define VF_BINFO_VALUE(NODE) TREE_PURPOSE (NODE)

/* Get that same information as a _TYPE.  */
#define VF_BASETYPE_VALUE(NODE) TREE_VALUE (NODE)

/* Get the value of the top-most type dominating the non-`normal' vfields.  */
#define VF_DERIVED_VALUE(NODE) (VF_BINFO_VALUE (NODE) ? BINFO_TYPE (VF_BINFO_VALUE (NODE)) : NULL_TREE)

/* Get the value of the top-most type that's `normal' for the vfield.  */
#define VF_NORMAL_VALUE(NODE) TREE_TYPE (NODE)

/* Nonzero for TREE_LIST node means that this list of things
   is a list of parameters, as opposed to a list of expressions.  */
#define TREE_PARMLIST(NODE) ((NODE)->common.unsigned_flag) /* overloaded! */

/* For FUNCTION_TYPE or METHOD_TYPE, a list of the exceptions that
   this type can raise.  Each TREE_VALUE is a _TYPE.  The TREE_VALUE
   will be NULL_TREE to indicate a throw specification of `()', or
   no exceptions allowed.  */
#define TYPE_RAISES_EXCEPTIONS(NODE) TYPE_NONCOPIED_PARTS (NODE)

/* For FUNCTION_TYPE or METHOD_TYPE, return 1 iff it is declared `throw()'.  */
#define TYPE_NOTHROW_P(NODE) \
  (TYPE_RAISES_EXCEPTIONS (NODE) \
   && TREE_VALUE (TYPE_RAISES_EXCEPTIONS (NODE)) == NULL_TREE)

/* The binding level associated with the namespace.  */
#define NAMESPACE_LEVEL(NODE) \
  (DECL_LANG_SPECIFIC(NODE)->decl_flags.u.level)


/* If a DECL has DECL_LANG_SPECIFIC, it is either a lang_decl_flags or
   a lang_decl (which has lang_decl_flags as its initial prefix).
   This macro is nonzero for tree nodes whose DECL_LANG_SPECIFIC is
   the full lang_decl, and not just lang_decl_flags.  */
#define CAN_HAVE_FULL_LANG_DECL_P(NODE)		\
  (!(TREE_CODE ((NODE)) == VAR_DECL		\
     || TREE_CODE ((NODE)) == CONST_DECL	\
     || TREE_CODE ((NODE)) == FIELD_DECL 	\
     || TREE_CODE ((NODE)) == USING_DECL))

struct lang_decl_flags
{
#ifdef ONLY_INT_FIELDS
  int language : 8;
#else
  enum languages language : 8;
#endif

  unsigned operator_attr : 1;
  unsigned constructor_attr : 1;
  unsigned friend_attr : 1;
  unsigned static_function : 1;
  unsigned const_memfunc : 1;
  unsigned volatile_memfunc : 1;
  unsigned abstract_virtual : 1;
  unsigned constructor_for_vbase_attr : 1;

  unsigned mutable_flag : 1;
  unsigned saved_inline : 1;
  unsigned use_template : 2;
  unsigned nonconverting : 1;
  unsigned declared_inline : 1;
  unsigned not_really_extern : 1;
  unsigned needs_final_overrider : 1;

  unsigned bitfield : 1;
  unsigned defined_in_class : 1;
  unsigned pending_inline_p : 1;
  unsigned global_ctor_p : 1;
  unsigned global_dtor_p : 1;
  unsigned dummy : 3;

  tree context;

  union {
    /* In a FUNCTION_DECL, VAR_DECL, TYPE_DECL, or TEMPLATE_DECL, this
       is DECL_TEMPLATE_INFO.  */
    tree template_info;

    /* In a NAMESPACE_DECL, this is NAMESPACE_LEVEL.  */
    struct binding_level *level;
  } u;

  union {
    /* This is DECL_ACCESS.  */
    tree access;

    /* In a namespace-scope FUNCTION_DECL, this is
       GLOBAL_INIT_PRIORITY.  */
    int init_priority;
  } u2;
};

struct lang_decl
{
  struct lang_decl_flags decl_flags;

  tree main_decl_variant;
  tree befriending_classes;

  /* In a FUNCTION_DECL, this is DECL_SAVED_TREE.  */
  tree saved_tree;

  union
  {
    tree sorted_fields;
    struct pending_inline *pending_inline_info;
    struct language_function *saved_language_function;
  } u;
};

/* Non-zero if NODE is a _DECL with TREE_READONLY set.  */
#define TREE_READONLY_DECL_P(NODE) \
  (TREE_READONLY (NODE) && TREE_CODE_CLASS (TREE_CODE (NODE)) == 'd')

/* Non-zero iff DECL is memory-based.  The DECL_RTL of
   certain const variables might be a CONST_INT, or a REG
   in some cases.  We cannot use `memory_operand' as a test
   here because on most RISC machines, a variable's address
   is not, by itself, a legitimate address.  */
#define DECL_IN_MEMORY_P(NODE) \
  (DECL_RTL (NODE) != NULL_RTX && GET_CODE (DECL_RTL (NODE)) == MEM)

/* For FUNCTION_DECLs: return the language in which this decl
   was declared.  */
#define DECL_LANGUAGE(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.language)

/* For FUNCTION_DECLs: nonzero means that this function is a constructor.  */
#define DECL_CONSTRUCTOR_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_attr)

/* There ought to be a better way to find out whether or not something is
   a destructor.  */
#define DECL_DESTRUCTOR_P(NODE)				\
  (DESTRUCTOR_NAME_P (DECL_ASSEMBLER_NAME (NODE))	\
   && DECL_LANGUAGE (NODE) == lang_cplusplus)

/* Non-zero if NODE is a user-defined conversion operator.  */
#define DECL_CONV_FN_P(NODE)						     \
  (IDENTIFIER_TYPENAME_P (DECL_NAME (NODE)) && TREE_TYPE (DECL_NAME (NODE)))

/* Non-zero if NODE is an overloaded operator.  */
#define DECL_OVERLOADED_OPERATOR_P(NODE)	\
  (IDENTIFIER_OPNAME_P (DECL_NAME ((NODE))))

/* For FUNCTION_DECLs: nonzero means that this function is a constructor
   for an object with virtual baseclasses.  */
#define DECL_CONSTRUCTOR_FOR_VBASE_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.constructor_for_vbase_attr)

/* Non-zero for a FUNCTION_DECL that declares a type-info function.  */
#define DECL_TINFO_FN_P(NODE) 					\
  (TREE_CODE (NODE) == FUNCTION_DECL				\
   && DECL_ARTIFICIAL (NODE)					\
   && DECL_LANG_SPECIFIC(NODE)->decl_flags.mutable_flag)

/* Mark NODE as a type-info function.  */
#define SET_DECL_TINFO_FN_P(NODE) \
  (DECL_LANG_SPECIFIC((NODE))->decl_flags.mutable_flag = 1)

/* Nonzero for _DECL means that this decl appears in (or will appear
   in) as a member in a RECORD_TYPE or UNION_TYPE node.  It is also for
   detecting circularity in case members are multiply defined.  In the
   case of a VAR_DECL, it is also used to determine how program storage
   should be allocated.  */
#define DECL_IN_AGGR_P(NODE) (DECL_LANG_FLAG_3(NODE))

/* Nonzero if the DECL was defined in the class definition itself,
   rather than outside the class.  */
#define DECL_DEFINED_IN_CLASS_P(DECL) \
 (DECL_LANG_SPECIFIC (DECL)->decl_flags.defined_in_class)

/* Nonzero for FUNCTION_DECL means that this decl is just a
   friend declaration, and should not be added to the list of
   member functions for this class.  */
#define DECL_FRIEND_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.friend_attr)

/* A TREE_LIST of the types which have befriended this FUNCTION_DECL.  */
#define DECL_BEFRIENDING_CLASSES(NODE) \
  (DECL_LANG_SPECIFIC(NODE)->befriending_classes)

/* Nonzero for FUNCTION_DECL means that this decl is a static
   member function.  */
#define DECL_STATIC_FUNCTION_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.static_function)

/* Nonzero for a class member means that it is shared between all objects
   of that class.  */
#define SHARED_MEMBER_P(NODE) \
  (TREE_CODE (NODE) == VAR_DECL || TREE_CODE (NODE) == TYPE_DECL \
   || TREE_CODE (NODE) == CONST_DECL)
				
/* Nonzero for FUNCTION_DECL means that this decl is a non-static
   member function.  */
#define DECL_NONSTATIC_MEMBER_FUNCTION_P(NODE) \
  (TREE_CODE (TREE_TYPE (NODE)) == METHOD_TYPE)

/* Nonzero for FUNCTION_DECL means that this decl is a member function
   (static or non-static).  */
#define DECL_FUNCTION_MEMBER_P(NODE) \
 (DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE) || DECL_STATIC_FUNCTION_P (NODE))

/* Nonzero for FUNCTION_DECL means that this member function
   has `this' as const X *const.  */
#define DECL_CONST_MEMFUNC_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.const_memfunc)

/* Nonzero for FUNCTION_DECL means that this member function
   has `this' as volatile X *const.  */
#define DECL_VOLATILE_MEMFUNC_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.volatile_memfunc)

/* Nonzero for a DECL means that this member is a non-static member.  */
#define DECL_NONSTATIC_MEMBER_P(NODE) 		\
  ((TREE_CODE (NODE) == FUNCTION_DECL 		\
    && DECL_NONSTATIC_MEMBER_FUNCTION_P (NODE))	\
   || TREE_CODE (NODE) == FIELD_DECL)

/* Nonzero for _DECL means that this member object type
   is mutable.  */
#define DECL_MUTABLE_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.mutable_flag)

/* Nonzero for _DECL means that this constructor is a non-converting
   constructor.  */
#define DECL_NONCONVERTING_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.nonconverting)

/* Nonzero for FUNCTION_DECL means that this member function
   exists as part of an abstract class's interface.  */
#define DECL_ABSTRACT_VIRTUAL_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.abstract_virtual)

/* Nonzero for FUNCTION_DECL means that this member function
   must be overridden by derived classes.  */
#define DECL_NEEDS_FINAL_OVERRIDER_P(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.needs_final_overrider)

/* The _TYPE context in which this _DECL appears.  This field holds the
   class where a virtual function instance is actually defined, and the
   lexical scope of a friend function defined in a class body. */
#define DECL_CLASS_CONTEXT(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.context)
#define DECL_REAL_CONTEXT(NODE) \
  ((TREE_CODE (NODE) == FUNCTION_DECL && DECL_FUNCTION_MEMBER_P (NODE)) \
   ? DECL_CLASS_CONTEXT (NODE) : CP_DECL_CONTEXT (NODE))

/* NULL_TREE in DECL_CONTEXT represents the global namespace. */
#define CP_DECL_CONTEXT(NODE) \
  (DECL_CONTEXT (NODE) ? DECL_CONTEXT (NODE) : global_namespace)
#define FROB_CONTEXT(NODE)   ((NODE) == global_namespace ? NULL_TREE : (NODE))

/* For a virtual function, the base where we find its vtable entry.
   For a non-virtual function, the base where it is defined.  */
#define DECL_VIRTUAL_CONTEXT(NODE) DECL_CONTEXT (NODE)

/* 1 iff NODE has namespace scope, including the global namespace.  */
#define DECL_NAMESPACE_SCOPE_P(NODE)				\
  (!DECL_TEMPLATE_PARM_P (NODE)					\
   && TREE_CODE (CP_DECL_CONTEXT (NODE)) == NAMESPACE_DECL)

/* 1 iff NODE is a class member.  */
#define DECL_CLASS_SCOPE_P(NODE) \
  (DECL_CONTEXT (NODE) \
   && TREE_CODE_CLASS (TREE_CODE (DECL_CONTEXT (NODE))) == 't')

/* 1 iff NODE is function-local.  */
#define DECL_FUNCTION_SCOPE_P(NODE) \
  (DECL_CONTEXT (NODE) \
   && TREE_CODE (DECL_CONTEXT (NODE)) == FUNCTION_DECL)
     
/* For a NAMESPACE_DECL: the list of using namespace directives
   The PURPOSE is the used namespace, the value is the namespace
   that is the common ancestor. */
#define DECL_NAMESPACE_USING(NODE) DECL_VINDEX (NAMESPACE_DECL_CHECK (NODE))

/* In a NAMESPACE_DECL, the DECL_INITIAL is used to record all users
   of a namespace, to record the transitive closure of using namespace. */
#define DECL_NAMESPACE_USERS(NODE) DECL_INITIAL (NAMESPACE_DECL_CHECK (NODE))

/* In a NAMESPACE_DECL, points to the original namespace if this is
   a namespace alias.  */
#define DECL_NAMESPACE_ALIAS(NODE) \
	DECL_ABSTRACT_ORIGIN (NAMESPACE_DECL_CHECK (NODE))
#define ORIGINAL_NAMESPACE(NODE)  \
  (DECL_NAMESPACE_ALIAS (NODE) ? DECL_NAMESPACE_ALIAS (NODE) : (NODE))

/* In a non-local VAR_DECL with static storage duration, this is the
   initialization priority.  If this value is zero, the NODE will be
   initialized at the DEFAULT_INIT_PRIORITY.  */
#define DECL_INIT_PRIORITY(NODE) (DECL_FIELD_SIZE (VAR_DECL_CHECK (NODE)))

/* In a TREE_LIST concatenating using directives, indicate indirekt
   directives  */
#define TREE_INDIRECT_USING(NODE) (TREE_LIST_CHECK (NODE)->common.lang_flag_0)

/* In a VAR_DECL for a variable declared in a for statement,
   this is the shadowed (local) variable.  */
#define DECL_SHADOWED_FOR_VAR(NODE) DECL_RESULT(VAR_DECL_CHECK (NODE))

/* Points back to the decl which caused this lang_decl to be allocated.  */
#define DECL_MAIN_VARIANT(NODE) (DECL_LANG_SPECIFIC(NODE)->main_decl_variant)

/* In a FUNCTION_DECL, this is nonzero if this function was defined in
   the class definition.  We have saved away the text of the function,
   but have not yet processed it.  */
#define DECL_PENDING_INLINE_P(NODE) \
  (DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (NODE))->decl_flags.pending_inline_p)
   
/* If DECL_PENDING_INLINE_P holds, this is the saved text of the
   function.  */
#define DECL_PENDING_INLINE_INFO(NODE) \
  (DECL_LANG_SPECIFIC(NODE)->u.pending_inline_info)

/* For a TYPE_DECL: if this function has many fields, we'll sort them
   and put them into a TREE_VEC. */
#define DECL_SORTED_FIELDS(NODE) \
	(DECL_LANG_SPECIFIC (TYPE_DECL_CHECK (NODE))->u.sorted_fields)

/* True if on the saved_inlines (see decl2.c) list.  */
#define DECL_SAVED_INLINE(DECL) \
  (DECL_LANG_SPECIFIC(DECL)->decl_flags.saved_inline)

/* For a VAR_DECL, FUNCTION_DECL, TYPE_DECL or TEMPLATE_DECL:
   template-specific information.  */
#define DECL_TEMPLATE_INFO(NODE) \
  (DECL_LANG_SPECIFIC(VAR_TEMPL_TYPE_OR_FUNCTION_DECL_CHECK (NODE))->decl_flags.u.template_info)

/* Template information for a RECORD_TYPE or UNION_TYPE.  */
#define CLASSTYPE_TEMPLATE_INFO(NODE) \
  (TYPE_LANG_SPECIFIC(RECORD_OR_UNION_TYPE_CHECK (NODE))->template_info)

/* Template information for an ENUMERAL_TYPE.  Although an enumeration may
   not be a primary template, it may be declared within the scope of a
   primary template and the enumeration constants may depend on
   non-type template parameters.  */
#define ENUM_TEMPLATE_INFO(NODE) (TYPE_BINFO (ENUMERAL_TYPE_CHECK (NODE)))

/* Template information for a template template parameter.  */
#define TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO(NODE) (TYPE_BINFO (NODE))

/* Template information for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
#define TYPE_TEMPLATE_INFO(NODE)			\
  (TREE_CODE (NODE) == ENUMERAL_TYPE			\
   ? ENUM_TEMPLATE_INFO (NODE) : 			\
   (TREE_CODE (NODE) == TEMPLATE_TEMPLATE_PARM		\
    ? TEMPLATE_TEMPLATE_PARM_TEMPLATE_INFO (NODE)	\
    : CLASSTYPE_TEMPLATE_INFO (NODE)))

/* Set the template information for an ENUMERAL_, RECORD_, or
   UNION_TYPE to VAL.  */
#define SET_TYPE_TEMPLATE_INFO(NODE, VAL) 	\
  (TREE_CODE (NODE) == ENUMERAL_TYPE 		\
   ? (ENUM_TEMPLATE_INFO (NODE) = VAL) 		\
   : (CLASSTYPE_TEMPLATE_INFO (NODE) = VAL))

#define TI_TEMPLATE(NODE) (TREE_PURPOSE (NODE))
#define TI_ARGS(NODE) (TREE_VALUE (NODE))
#define TI_SPEC_INFO(NODE) (TREE_CHAIN (NODE))
#define TI_PENDING_TEMPLATE_FLAG(NODE) TREE_LANG_FLAG_1 (NODE)

/* We use TREE_VECs to hold template arguments.  If there is only one
   level of template arguments, then the TREE_VEC contains the
   arguments directly.  If there is more than one level of template
   arguments, then each entry in the TREE_VEC is itself a TREE_VEC,
   containing the template arguments for a single level.  The first
   entry in the outer TREE_VEC is the outermost level of template
   parameters; the last is the innermost.  

   It is incorrect to ever form a template argument vector containing
   only one level of arguments, but which is a TREE_VEC containing as
   its only entry the TREE_VEC for that level.  */

/* Non-zero if the template arguments is actually a vector of vectors,
   rather than just a vector.  */
#define TMPL_ARGS_HAVE_MULTIPLE_LEVELS(NODE) \
  (NODE != NULL_TREE						\
   && TREE_CODE (NODE) == TREE_VEC				\
   && TREE_VEC_LENGTH (NODE) > 0				\
   && TREE_VEC_ELT (NODE, 0) != NULL_TREE			\
   && TREE_CODE (TREE_VEC_ELT (NODE, 0)) == TREE_VEC)

/* The depth of a template argument vector.  When called directly by
   the parser, we use a TREE_LIST rather than a TREE_VEC to represent
   template arguments.  In fact, we may even see NULL_TREE if there
   are no template arguments.  In both of those cases, there is only
   one level of template arguments.  */
#define TMPL_ARGS_DEPTH(NODE)					\
  (TMPL_ARGS_HAVE_MULTIPLE_LEVELS (NODE) ? TREE_VEC_LENGTH (NODE) : 1)

/* The LEVELth level of the template ARGS.  Note that template
   parameter levels are indexed from 1, not from 0.  */
#define TMPL_ARGS_LEVEL(ARGS, LEVEL)		\
  (TMPL_ARGS_HAVE_MULTIPLE_LEVELS (ARGS) 	\
   ? TREE_VEC_ELT ((ARGS), (LEVEL) - 1) : ARGS)

/* Set the LEVELth level of the template ARGS to VAL.  This macro does
   not work with single-level argument vectors.  */
#define SET_TMPL_ARGS_LEVEL(ARGS, LEVEL, VAL)	\
  (TREE_VEC_ELT ((ARGS), (LEVEL) - 1) = (VAL))

/* Accesses the IDXth parameter in the LEVELth level of the ARGS.  */
#define TMPL_ARG(ARGS, LEVEL, IDX)				\
  (TREE_VEC_ELT (TMPL_ARGS_LEVEL (ARGS, LEVEL), IDX))

/* Set the IDXth element in the LEVELth level of ARGS to VAL.  This
   macro does not work with single-level argument vectors.  */
#define SET_TMPL_ARG(ARGS, LEVEL, IDX, VAL)			\
  (TREE_VEC_ELT (TREE_VEC_ELT ((ARGS), (LEVEL) - 1), (IDX)) = (VAL))

/* Given a single level of template arguments in NODE, return the
   number of arguments.  */
#define NUM_TMPL_ARGS(NODE) 				\
  ((NODE) == NULL_TREE ? 0 				\
   : (TREE_CODE (NODE) == TREE_VEC 			\
      ? TREE_VEC_LENGTH (NODE) : list_length (NODE)))

/* The number of levels of template parameters given by NODE.  */
#define TMPL_PARMS_DEPTH(NODE) \
  (TREE_INT_CST_HIGH (TREE_PURPOSE (NODE)))

/* The TEMPLATE_DECL instantiated or specialized by NODE.  This
   TEMPLATE_DECL will be the immediate parent, not the most general
   template.  For example, in:

      template <class T> struct S { template <class U> void f(U); }

   the FUNCTION_DECL for S<int>::f<double> will have, as its
   DECL_TI_TEMPLATE, `template <class U> S<int>::f<U>'. 

   As a special case, for a member friend template of a template
   class, this value will not be a TEMPLATE_DECL, but rather a
   LOOKUP_EXPR or IDENTIFIER_NODE indicating the name of the template
   and any explicit template arguments provided.  For example, in:

     template <class T> struct S { friend void f<int>(int, double); }

   the DECL_TI_TEMPLATE will be a LOOKUP_EXPR for `f' and the
   DECL_TI_ARGS will be {int}.  */ 
#define DECL_TI_TEMPLATE(NODE)      TI_TEMPLATE (DECL_TEMPLATE_INFO (NODE))

/* The template arguments used to obtain this decl from the most
   general form of DECL_TI_TEMPLATE.  For the example given for
   DECL_TI_TEMPLATE, the DECL_TI_ARGS will be {int, double}.  These
   are always the full set of arguments required to instantiate this
   declaration from the most general template specialized here.  */
#define DECL_TI_ARGS(NODE)          TI_ARGS (DECL_TEMPLATE_INFO (NODE))
#define CLASSTYPE_TI_TEMPLATE(NODE) TI_TEMPLATE (CLASSTYPE_TEMPLATE_INFO (NODE))
#define CLASSTYPE_TI_ARGS(NODE)     TI_ARGS (CLASSTYPE_TEMPLATE_INFO (NODE))
#define CLASSTYPE_TI_SPEC_INFO(NODE) TI_SPEC_INFO (CLASSTYPE_TEMPLATE_INFO (NODE))
#define ENUM_TI_TEMPLATE(NODE) 			\
  TI_TEMPLATE (ENUM_TEMPLATE_INFO (NODE))
#define ENUM_TI_ARGS(NODE)			\
  TI_ARGS (ENUM_TEMPLATE_INFO (NODE))

/* Like DECL_TI_TEMPLATE, but for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
#define TYPE_TI_TEMPLATE(NODE)			\
  (TI_TEMPLATE (TYPE_TEMPLATE_INFO (NODE)))

/* Like DECL_TI_ARGS, but for an ENUMERAL_, RECORD_, or UNION_TYPE.  */
#define TYPE_TI_ARGS(NODE)			\
  (TI_ARGS (TYPE_TEMPLATE_INFO (NODE)))

#define INNERMOST_TEMPLATE_PARMS(NODE)  TREE_VALUE(NODE)

/* Nonzero if the NODE corresponds to the template parameters for a
   member template, whose inline definition is being processed after
   the class definition is complete.  */
#define TEMPLATE_PARMS_FOR_INLINE(NODE) TREE_LANG_FLAG_1 (NODE)

/* In a FUNCTION_DECL, the saved representation of the body of the
   entire function.  Usually a COMPOUND_STMT, but this may also be a
   RETURN_INIT, CTOR_INITIALIZER, or TRY_BLOCK.  */
#define DECL_SAVED_TREE(NODE) \
  (DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (NODE))->saved_tree)

/* In a FUNCTION_DECL, the saved language-specific per-function data.  */
#define DECL_SAVED_FUNCTION_DATA(NODE) \
  (DECL_LANG_SPECIFIC (FUNCTION_DECL_CHECK (NODE))->u.saved_language_function)

#define COMPOUND_STMT_NO_SCOPE(NODE)	TREE_LANG_FLAG_0 (NODE)
#define NEW_EXPR_USE_GLOBAL(NODE)	TREE_LANG_FLAG_0 (NODE)
#define DELETE_EXPR_USE_GLOBAL(NODE)	TREE_LANG_FLAG_0 (NODE)
#define DELETE_EXPR_USE_VEC(NODE)	TREE_LANG_FLAG_1 (NODE)
#define LOOKUP_EXPR_GLOBAL(NODE)	TREE_LANG_FLAG_0 (NODE)

/* Nonzero if this AGGR_INIT_EXPR provides for initialization via a
   constructor call, rather than an ordinary function call.  */
#define AGGR_INIT_VIA_CTOR_P(NODE) \
  TREE_LANG_FLAG_0 (AGGR_INIT_EXPR_CHECK (NODE))

/* Nonzero if this statement should be considered a full-expression.  */
#define STMT_IS_FULL_EXPR_P(NODE) TREE_LANG_FLAG_1 ((NODE))

/* The TYPE_MAIN_DECL for a class template type is a TYPE_DECL, not a
   TEMPLATE_DECL.  This macro determines whether or not a given class
   type is really a template type, as opposed to an instantiation or
   specialization of one.  */
#define CLASSTYPE_IS_TEMPLATE(NODE)  \
  (CLASSTYPE_TEMPLATE_INFO (NODE)    \
   && !CLASSTYPE_USE_TEMPLATE (NODE) \
   && PRIMARY_TEMPLATE_P (CLASSTYPE_TI_TEMPLATE (NODE)))

/* The name used by the user to name the typename type.  Typically,
   this is an IDENTIFIER_NODE, and the same as the DECL_NAME on the
   corresponding TYPE_DECL.  However, this may also be a
   TEMPLATE_ID_EXPR if we had something like `typename X::Y<T>'.  */
#define TYPENAME_TYPE_FULLNAME(NODE) TYPE_BINFO (NODE)

/* Nonzero if NODE is an implicit typename.  */
#define IMPLICIT_TYPENAME_P(NODE) \
  (TREE_CODE (NODE) == TYPENAME_TYPE && TREE_TYPE (NODE))

/* Nonzero if NODE is a TYPE_DECL that should not be visible because
   it is from a dependent base class.  */
#define IMPLICIT_TYPENAME_TYPE_DECL_P(NODE) 	\
  (TREE_CODE (NODE) == TYPE_DECL		\
   && DECL_ARTIFICIAL (NODE)			\
   && IMPLICIT_TYPENAME_P (TREE_TYPE (NODE)))

/* Nonzero in INTEGER_CST means that this int is negative by dint of
   using a twos-complement negated operand.  */
#define TREE_NEGATED_INT(NODE) TREE_LANG_FLAG_0 (INTEGER_CST_CHECK (NODE))

#if 0				/* UNUSED */
/* Nonzero in any kind of _EXPR or _REF node means that it is a call
   to a storage allocation routine.  If, later, alternate storage
   is found to hold the object, this call can be ignored.  */
#define TREE_CALLS_NEW(NODE) (TREE_LANG_FLAG_1 (NODE))
#endif

/* Nonzero in any kind of _TYPE that uses multiple inheritance
   or virtual baseclasses.  */
#define TYPE_USES_COMPLEX_INHERITANCE(NODE) (TREE_LANG_FLAG_1 (NODE))

#if 0				/* UNUSED */
/* Nonzero in IDENTIFIER_NODE means that this name is not the name the user
   gave; it's a DECL_NESTED_TYPENAME.  Someone may want to set this on
   mangled function names, too, but it isn't currently.  */
#define TREE_MANGLED(NODE) (FOO)
#endif

#if 0				/* UNUSED */
/* Nonzero in IDENTIFIER_NODE means that this name is overloaded, and
   should be looked up in a non-standard way.  */
#define DECL_OVERLOADED(NODE) (FOO)
#endif

/* Nonzero if this (non-TYPE)_DECL has its virtual attribute set.
   For a FUNCTION_DECL, this is when the function is a virtual function.
   For a VAR_DECL, this is when the variable is a virtual function table.
   For a FIELD_DECL, when the field is the field for the virtual function table.
   For an IDENTIFIER_NODE, nonzero if any function with this name
   has been declared virtual.

   For a _TYPE if it uses virtual functions (or is derived from
   one that does).  */
#define TYPE_VIRTUAL_P(NODE) (TREE_LANG_FLAG_2 (NODE))

extern int flag_new_for_scope;

/* This flag is true of a local VAR_DECL if it was declared in a for
   statement, but we are no longer in the scope of the for.  */
#define DECL_DEAD_FOR_LOCAL(NODE) DECL_LANG_FLAG_7 (VAR_DECL_CHECK (NODE))

/* This flag is set on a VAR_DECL that is a DECL_DEAD_FOR_LOCAL
   if we already emitted a warning about using it.  */
#define DECL_ERROR_REPORTED(NODE) DECL_LANG_FLAG_0 (VAR_DECL_CHECK (NODE))

/* Nonzero if NODE is a FUNCTION_DECL (for a function with global
   scope) declared in a local scope.  */
#define DECL_LOCAL_FUNCTION_P(NODE) \
  DECL_LANG_FLAG_0 (FUNCTION_DECL_CHECK (NODE))

/* This _DECL represents a compiler-generated entity.  */
#define SET_DECL_ARTIFICIAL(NODE) (DECL_ARTIFICIAL (NODE) = 1)

/* Record whether a typedef for type `int' was actually `signed int'.  */
#define C_TYPEDEF_EXPLICITLY_SIGNED(exp) DECL_LANG_FLAG_1 ((exp))

/* In a FIELD_DECL, nonzero if the decl was originally a bitfield.  */
#define DECL_C_BIT_FIELD(NODE) \
  (DECL_LANG_SPECIFIC (FIELD_DECL_CHECK (NODE))\
   && DECL_LANG_SPECIFIC (NODE)->decl_flags.bitfield)
#define SET_DECL_C_BIT_FIELD(NODE) \
  (DECL_LANG_SPECIFIC (FIELD_DECL_CHECK (NODE))->decl_flags.bitfield = 1)

#define INTEGRAL_CODE_P(CODE) \
  (CODE == INTEGER_TYPE || CODE == ENUMERAL_TYPE || CODE == BOOLEAN_TYPE)

/* [basic.fundamental]

   Types  bool, char, wchar_t, and the signed and unsigned integer types
   are collectively called integral types.  

   Note that INTEGRAL_TYPE_P, as defined in tree.h, allows enumeration
   types as well, which is incorrect in C++.  */
#define CP_INTEGRAL_TYPE_P(TYPE) 		\
  (TREE_CODE ((TYPE)) == BOOLEAN_TYPE 		\
   || TREE_CODE ((TYPE)) == INTEGER_TYPE)

/* [basic.fundamental]

   Integral and floating types are collectively called arithmetic
   types.  */
#define ARITHMETIC_TYPE_P(TYPE) \
  (CP_INTEGRAL_TYPE_P (TYPE) || TREE_CODE (TYPE) == REAL_TYPE)

/* Mark which labels are explicitly declared.
   These may be shadowed, and may be referenced from nested functions.  */
#define C_DECLARED_LABEL_FLAG(label) TREE_LANG_FLAG_1 (label)

/* Nonzero for _TYPE means that the _TYPE defines
   at least one constructor.  */
#define TYPE_HAS_CONSTRUCTOR(NODE) (TYPE_LANG_FLAG_1(NODE))

/* When appearing in an INDIRECT_REF, it means that the tree structure
   underneath is actually a call to a constructor.  This is needed
   when the constructor must initialize local storage (which can
   be automatically destroyed), rather than allowing it to allocate
   space from the heap.

   When appearing in a SAVE_EXPR, it means that underneath
   is a call to a constructor.

   When appearing in a CONSTRUCTOR, it means that it was
   a GNU C constructor expression.

   When appearing in a FIELD_DECL, it means that this field
   has been duly initialized in its constructor.  */
#define TREE_HAS_CONSTRUCTOR(NODE) (TREE_LANG_FLAG_4(NODE))

#define EMPTY_CONSTRUCTOR_P(NODE) (TREE_CODE (NODE) == CONSTRUCTOR	   \
				   && CONSTRUCTOR_ELTS (NODE) == NULL_TREE \
				   && ! TREE_HAS_CONSTRUCTOR (NODE))

#if 0
/* Indicates that a NON_LVALUE_EXPR came from a C++ reference.
   Used to generate more helpful error message in case somebody
   tries to take its address.  */
#define TREE_REFERENCE_EXPR(NODE) (TREE_LANG_FLAG_3(NODE))
#endif

/* Nonzero for _TYPE means that the _TYPE defines a destructor.  */
#define TYPE_HAS_DESTRUCTOR(NODE) (TYPE_LANG_FLAG_2(NODE))

/* Nonzero means that an object of this type can not be initialized using
   an initializer list.  */
#define CLASSTYPE_NON_AGGREGATE(NODE) \
  (TYPE_LANG_SPECIFIC (NODE)->non_aggregate)
#define TYPE_NON_AGGREGATE_CLASS(NODE) \
  (IS_AGGR_TYPE (NODE) && CLASSTYPE_NON_AGGREGATE (NODE))

/* Nonzero if there is a user-defined X::op=(x&) for this class.  */
#define TYPE_HAS_REAL_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_real_assign_ref)
#define TYPE_HAS_COMPLEX_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_complex_assign_ref)
#define TYPE_HAS_ABSTRACT_ASSIGN_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_abstract_assign_ref)
#define TYPE_HAS_COMPLEX_INIT_REF(NODE) (TYPE_LANG_SPECIFIC(NODE)->has_complex_init_ref)

/* Nonzero for _TYPE node means that destroying an object of this type
   will involve a call to a destructor.  This can apply to objects
   of ARRAY_TYPE is the type of the elements needs a destructor.  */
#define TYPE_NEEDS_DESTRUCTOR(NODE) (TYPE_LANG_FLAG_4(NODE))

/* Nonzero for class type means that initialization of this type can use
   a bitwise copy.  */
#define TYPE_HAS_TRIVIAL_INIT_REF(NODE) \
  (TYPE_HAS_INIT_REF (NODE) && ! TYPE_HAS_COMPLEX_INIT_REF (NODE))

/* Nonzero for class type means that assignment of this type can use
   a bitwise copy.  */
#define TYPE_HAS_TRIVIAL_ASSIGN_REF(NODE) \
  (TYPE_HAS_ASSIGN_REF (NODE) && ! TYPE_HAS_COMPLEX_ASSIGN_REF (NODE))

#define TYPE_PTRMEM_P(NODE)					\
  (TREE_CODE (NODE) == POINTER_TYPE				\
   && TREE_CODE (TREE_TYPE (NODE)) == OFFSET_TYPE)
#define TYPE_PTR_P(NODE)				\
  (TREE_CODE (NODE) == POINTER_TYPE			\
   && TREE_CODE (TREE_TYPE (NODE)) != OFFSET_TYPE)
#define TYPE_PTROB_P(NODE)						\
  (TYPE_PTR_P (NODE) && TREE_CODE (TREE_TYPE (NODE)) != FUNCTION_TYPE	\
   && TREE_CODE (TREE_TYPE (NODE)) != VOID_TYPE)
#define TYPE_PTROBV_P(NODE)						\
  (TYPE_PTR_P (NODE) && TREE_CODE (TREE_TYPE (NODE)) != FUNCTION_TYPE)
#define TYPE_PTRFN_P(NODE)				\
  (TREE_CODE (NODE) == POINTER_TYPE			\
   && TREE_CODE (TREE_TYPE (NODE)) == FUNCTION_TYPE)

/* Nonzero for _TYPE node means that this type is a pointer to member
   function type.  */
#define TYPE_PTRMEMFUNC_P(NODE)		\
  (TREE_CODE(NODE) == RECORD_TYPE	\
   && TYPE_LANG_SPECIFIC(NODE)		\
   && TYPE_PTRMEMFUNC_FLAG (NODE))

#define TYPE_PTRMEMFUNC_FLAG(NODE) \
  (TYPE_LANG_SPECIFIC(NODE)->ptrmemfunc_flag)

/* A pointer-to-function member type looks like:

   struct {
     short __delta;
     short __index;
     union {
       P __pfn;
       short __delta2;
     } __pfn_or_delta2;
   };

   where P is a POINTER_TYPE to a METHOD_TYPE appropriate for the
   pointer to member.  The fields are used as follows:

     If __INDEX is -1, then the function to call is non-virtual, and
     is located at the address given by __PFN.

     If __INDEX is zero, then this a NULL pointer-to-member.

     Otherwise, the function to call is virtual.  Then, __DELTA2 gives
     the offset from an instance of the object to the virtual function
     table, and __INDEX - 1 is the index into the vtable to use to
     find the function.

     The value to use for the THIS parameter is the address of the
     object plus __DELTA.

   For example, given:

     struct B1 {
       int i;
     };

     struct B2 {
       double d;
       void f();
     };

     struct S : public B1, B2 {};

   the pointer-to-member for `&S::f' looks like:

     { 4, -1, { &f__2B2 } };

   The `4' means that given an `S*' you have to add 4 bytes to get to
   the address of the `B2*'.  Then, the -1 indicates that this is a
   non-virtual function.  Of course, `&f__2B2' is the name of that
   function.

   (Of course, the exact values may differ depending on the mangling
   scheme, sizes of types, and such.).  */
     
/* Get the POINTER_TYPE to the METHOD_TYPE associated with this
   pointer to member function.  TYPE_PTRMEMFUNC_P _must_ be true,
   before using this macro.  */
#define TYPE_PTRMEMFUNC_FN_TYPE(NODE) (TREE_TYPE (TYPE_FIELDS (TREE_TYPE (TREE_CHAIN (TREE_CHAIN (TYPE_FIELDS (NODE)))))))

/* Returns `A' for a type like `int (A::*)(double)' */
#define TYPE_PTRMEMFUNC_OBJECT_TYPE(NODE) \
  TYPE_METHOD_BASETYPE (TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE (NODE)))

/* These are use to manipulate the canonical RECORD_TYPE from the
   hashed POINTER_TYPE, and can only be used on the POINTER_TYPE.  */
#define TYPE_GET_PTRMEMFUNC_TYPE(NODE) ((tree)TYPE_LANG_SPECIFIC(NODE))
#define TYPE_SET_PTRMEMFUNC_TYPE(NODE, VALUE) (TYPE_LANG_SPECIFIC(NODE) = ((struct lang_type *)(void*)(VALUE)))
/* These are to get the delta2 and pfn fields from a TYPE_PTRMEMFUNC_P.  */
#define DELTA2_FROM_PTRMEMFUNC(NODE) delta2_from_ptrmemfunc ((NODE))
#define PFN_FROM_PTRMEMFUNC(NODE) pfn_from_ptrmemfunc ((NODE))

/* For a pointer-to-member type of the form `T X::*', this is `X'.  */
#define TYPE_PTRMEM_CLASS_TYPE(NODE)			\
  (TYPE_PTRMEM_P ((NODE))				\
   ? TYPE_OFFSET_BASETYPE (TREE_TYPE ((NODE)))		\
   : TYPE_PTRMEMFUNC_OBJECT_TYPE ((NODE)))

/* For a pointer-to-member type of the form `T X::*', this is `T'.  */
#define TYPE_PTRMEM_POINTED_TO_TYPE(NODE)		\
   (TYPE_PTRMEM_P ((NODE))				\
    ? TREE_TYPE (TREE_TYPE (NODE))			\
    : TREE_TYPE (TYPE_PTRMEMFUNC_FN_TYPE ((NODE))))

/* For a pointer-to-member constant `X::Y' this is the RECORD_TYPE for
   `X'.  */
#define PTRMEM_CST_CLASS(NODE) \
  TYPE_PTRMEM_CLASS_TYPE (TREE_TYPE (PTRMEM_CST_CHECK (NODE)))

/* For a pointer-to-member constant `X::Y' this is the _DECL for 
   `Y'.  */
#define PTRMEM_CST_MEMBER(NODE) (((ptrmem_cst_t)PTRMEM_CST_CHECK (NODE))->member)

/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `extern' was
   specified in its declaration.  */
#define DECL_THIS_EXTERN(NODE) \
  DECL_LANG_FLAG_2 (VAR_OR_FUNCTION_DECL_CHECK (NODE))

/* Nonzero for VAR_DECL and FUNCTION_DECL node means that `static' was
   specified in its declaration.  */
#define DECL_THIS_STATIC(NODE) \
  DECL_LANG_FLAG_6 (VAR_OR_FUNCTION_DECL_CHECK (NODE))

/* Nonzero in FUNCTION_DECL means it is really an operator.
   Just used to communicate formatting information to dbxout.c.  */
#define DECL_OPERATOR(NODE) \
  (DECL_LANG_SPECIFIC(FUNCTION_DECL_CHECK (NODE))->decl_flags.operator_attr)

/* Nonzero if TYPE is an anonymous union or struct type.  We have to use a
   flag for this because "A union for which objects or pointers are
   declared is not an anonymous union" [class.union].  */
#define ANON_AGGR_TYPE_P(NODE)				\
  (CLASS_TYPE_P (NODE) && TYPE_LANG_SPECIFIC (NODE)->anon_aggr)
#define SET_ANON_AGGR_TYPE_P(NODE)			\
  (TYPE_LANG_SPECIFIC (NODE)->anon_aggr = 1)

/* Nonzero if TYPE is an anonymous union type.  */
#define ANON_UNION_TYPE_P(NODE) \
  (TREE_CODE (NODE) == UNION_TYPE && ANON_AGGR_TYPE_P (NODE))

/* For a VAR_DECL that is an anonymous union, these are the various
   sub-variables that make up the anonymous union.  */
#define DECL_ANON_UNION_ELEMS(NODE) DECL_ARGUMENTS ((NODE))

#define UNKNOWN_TYPE LANG_TYPE

/* Define fields and accessors for nodes representing declared names.  */

#if 0
/* C++: A derived class may be able to directly use the virtual
   function table of a base class.  When it does so, it may
   still have a decl node used to access the virtual function
   table (so that variables of this type can initialize their
   virtual function table pointers by name).  When such thievery
   is committed, know exactly which base class's virtual function
   table is the one being stolen.  This effectively computes the
   transitive closure.  */
#define DECL_VPARENT(NODE) ((NODE)->decl.arguments)
#endif

#define TYPE_WAS_ANONYMOUS(NODE) (TYPE_LANG_SPECIFIC (NODE)->was_anonymous)

/* C++: all of these are overloaded!  These apply only to TYPE_DECLs.  */

/* The format of each node in the DECL_FRIENDLIST is as follows:

   The TREE_PURPOSE will be the name of a function, i.e., an
   IDENTIFIER_NODE.  The TREE_VALUE will be itself a TREE_LIST, the
   list of functions with that name which are friends.  The
   TREE_PURPOSE of each node in this sublist will be error_mark_node,
   if the function was declared a friend individually, in which case
   the TREE_VALUE will be the function_decl.  If, however, all
   functions with a given name in a class were declared to be friends,
   the TREE_PUROSE will be the class type, and the TREE_VALUE will be
   NULL_TREE.  */
#define DECL_FRIENDLIST(NODE)		(DECL_INITIAL (NODE))
#define FRIEND_NAME(LIST) (TREE_PURPOSE (LIST))
#define FRIEND_DECLS(LIST) (TREE_VALUE (LIST))

/* The DECL_ACCESS, if non-NULL, is a TREE_LIST.  The TREE_PURPOSE of
   each node is a type; the TREE_VALUE is the access granted for this
   DECL in that type.  The DECL_ACCESS is set by access declarations.
   For example, if a member that would normally be public in a
   derived class is made protected, then the derived class and the
   protected_access_node will appear in the DECL_ACCESS for the node.  */
#define DECL_ACCESS(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.u2.access)

/* Nonzero if the FUNCTION_DECL is a global constructor.  */
#define DECL_GLOBAL_CTOR_P(NODE) \
  (DECL_LANG_SPECIFIC ((NODE))->decl_flags.global_ctor_p)

/* Nonzero if the FUNCTION_DECL is a global destructor.  */
#define DECL_GLOBAL_DTOR_P(NODE) \
  (DECL_LANG_SPECIFIC ((NODE))->decl_flags.global_dtor_p)

/* If DECL_GLOBAL_CTOR_P or DECL_GLOBAL_DTOR_P holds, this macro
   returns the initialization priority for the function.  Constructors
   with lower numbers should be run first.  Destructors should be run
   in the reverse order of constructors.  */
#define GLOBAL_INIT_PRIORITY(NODE) \
  (DECL_LANG_SPECIFIC ((NODE))->decl_flags.u2.init_priority)

/* Accessor macros for C++ template decl nodes.  */

/* The DECL_TEMPLATE_PARMS are a list.  The TREE_PURPOSE of each node
   is a INT_CST whose TREE_INT_CST_HIGH indicates the level of the
   template parameters, with 1 being the outermost set of template
   parameters.  The TREE_VALUE is a vector, whose elements are the
   template parameters at each level.  Each element in the vector is a
   TREE_LIST, whose TREE_VALUE is a PARM_DECL (if the parameter is a
   non-type parameter), or a TYPE_DECL (if the parameter is a type
   parameter).  The TREE_PURPOSE is the default value, if any.  The
   TEMPLATE_PARM_INDEX for the parameter is avilable as the
   DECL_INITIAL (for a PARM_DECL) or as the TREE_TYPE (for a
   TYPE_DECL).  */
#define DECL_TEMPLATE_PARMS(NODE)       DECL_ARGUMENTS(NODE)
#define DECL_INNERMOST_TEMPLATE_PARMS(NODE) \
   INNERMOST_TEMPLATE_PARMS (DECL_TEMPLATE_PARMS (NODE))
#define DECL_NTPARMS(NODE) \
   TREE_VEC_LENGTH (DECL_INNERMOST_TEMPLATE_PARMS (NODE))
/* For function, method, class-data templates.  */
#define DECL_TEMPLATE_RESULT(NODE)      DECL_RESULT(NODE)
/* For a static member variable template, the
   DECL_TEMPLATE_INSTANTIATIONS list contains the explicitly and
   implicitly generated instantiations of the variable.  There are no
   partial instantiations of static member variables, so all of these
   will be full instantiations.

   For a class template the DECL_TEMPLATE_INSTANTIATIONS lists holds
   all instantiations and specializations of the class type, including
   partial instantiations and partial specializations.

   In both cases, the TREE_PURPOSE of each node contains the arguments
   used; the TREE_VALUE contains the generated variable.  The template
   arguments are always complete.  For example, given:

      template <class T> struct S1 {
        template <class U> struct S2 {};
	template <class U> struct S2<U*> {};
      };

   the record for the partial specialization will contain, as its
   argument list, { {T}, {U*} }, and will be on the
   DECL_TEMPLATE_INSTANTIATIONS list for `template <class T> template
   <class U> struct S1<T>::S2'.

   This list is not used for function templates.  */
#define DECL_TEMPLATE_INSTANTIATIONS(NODE) DECL_VINDEX(NODE)
/* For a function template, the DECL_TEMPLATE_SPECIALIZATIONS lists
   contains all instantiations and specializations of the function,
   including partial instantiations.  For a partial instantiation
   which is a specialization, this list holds only full
   specializations of the template that are instantiations of the
   partial instantiation.  For example, given:

      template <class T> struct S {
        template <class U> void f(U);
	template <> void f(T); 
      };

   the `S<int>::f<int>(int)' function will appear on the
   DECL_TEMPLATE_SPECIALIZATIONS list for both `template <class T>
   template <class U> void S<T>::f(U)' and `template <class T> void
   S<int>::f(T)'.  In the latter case, however, it will have only the
   innermost set of arguments (T, in this case).  The DECL_TI_TEMPLATE
   for the function declaration will point at the specialization, not
   the fully general template.

   For a class template, this list contains the partial
   specializations of this template.  (Full specializations are not
   recorded on this list.)  The TREE_PURPOSE holds the innermost
   arguments used in the partial specialization (e.g., for `template
   <class T> struct S<T*, int>' this will be `T*'.)  The TREE_VALUE
   holds the innermost template parameters for the specialization
   (e.g., `T' in the example above.)  The TREE_TYPE is the _TYPE node
   for the partial specialization.

   This list is not used for static variable templates.  */
#define DECL_TEMPLATE_SPECIALIZATIONS(NODE)     DECL_SIZE(NODE)

/* Nonzero for a DECL which is actually a template parameter.  */
#define DECL_TEMPLATE_PARM_P(NODE) 		\
  (DECL_LANG_FLAG_0 (NODE)			\
   && (TREE_CODE (NODE) == CONST_DECL		\
       || TREE_CODE (NODE) == TYPE_DECL		\
       || TREE_CODE (NODE) == TEMPLATE_DECL))

/* Mark NODE as a template parameter.  */
#define SET_DECL_TEMPLATE_PARM_P(NODE) \
  (DECL_LANG_FLAG_0 (NODE) = 1)

/* Nonzero if NODE is a template template parameter.  */
#define DECL_TEMPLATE_TEMPLATE_PARM_P(NODE) \
  (TREE_CODE (NODE) == TEMPLATE_DECL && DECL_TEMPLATE_PARM_P (NODE))

#define DECL_FUNCTION_TEMPLATE_P(NODE)  \
  (TREE_CODE (NODE) == TEMPLATE_DECL \
   && TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == FUNCTION_DECL)

/* Nonzero for a DECL that represents a template class.  */
#define DECL_CLASS_TEMPLATE_P(NODE) \
  (TREE_CODE (NODE) == TEMPLATE_DECL \
   && TREE_CODE (DECL_TEMPLATE_RESULT (NODE)) == TYPE_DECL \
   && !DECL_TEMPLATE_TEMPLATE_PARM_P (NODE))

/* Nonzero if NODE which declares a type.  */
#define DECL_DECLARES_TYPE_P(NODE) \
  (TREE_CODE (NODE) == TYPE_DECL || DECL_CLASS_TEMPLATE_P (NODE))

/* Nonzero if NODE is the typedef implicitly generated for a type when
   the type is declared.  (In C++, `struct S {};' is roughly equivalent
   to `struct S {}; typedef struct S S;' in C.  This macro will hold
   for the typedef indicated in this example.  Note that in C++, there
   is a second implicit typedef for each class, in the scope of `S'
   itself, so that you can `S::S'.  This macro does *not* hold for
   those typedefs.  */
#define DECL_IMPLICIT_TYPEDEF_P(NODE) \
  (TREE_CODE ((NODE)) == TYPE_DECL && DECL_LANG_FLAG_2 ((NODE)))
#define SET_DECL_IMPLICIT_TYPEDEF_P(NODE) \
  (DECL_LANG_FLAG_2 ((NODE)) = 1)

/* A `primary' template is one that has its own template header.  A
   member function of a class template is a template, but not primary.
   A member template is primary.  Friend templates are primary, too.  */

/* Returns the primary template corresponding to these parameters.  */
#define DECL_PRIMARY_TEMPLATE(NODE) \
  (TREE_TYPE (DECL_INNERMOST_TEMPLATE_PARMS (NODE)))

/* Returns non-zero if NODE is a primary template.  */
#define PRIMARY_TEMPLATE_P(NODE) (DECL_PRIMARY_TEMPLATE (NODE) == NODE)

#define CLASSTYPE_TEMPLATE_LEVEL(NODE) \
  (TREE_INT_CST_HIGH (TREE_PURPOSE (CLASSTYPE_TI_TEMPLATE (NODE))))

/* Indicates whether or not (and how) a template was expanded for this
   FUNCTION_DECL or VAR_DECL.
     0=normal declaration, e.g. int min (int, int);
     1=implicit template instantiation
     2=explicit template specialization, e.g. int min<int> (int, int);
     3=explicit template instantiation, e.g. template int min<int> (int, int);  */
#define DECL_USE_TEMPLATE(NODE) (DECL_LANG_SPECIFIC(NODE)->decl_flags.use_template)

#define DECL_TEMPLATE_INSTANTIATION(NODE) (DECL_USE_TEMPLATE (NODE) & 1)
#define CLASSTYPE_TEMPLATE_INSTANTIATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE (NODE) & 1)

#define DECL_TEMPLATE_SPECIALIZATION(NODE) (DECL_USE_TEMPLATE (NODE) == 2)
#define SET_DECL_TEMPLATE_SPECIALIZATION(NODE) (DECL_USE_TEMPLATE (NODE) = 2)
#define CLASSTYPE_TEMPLATE_SPECIALIZATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE (NODE) == 2)
#define SET_CLASSTYPE_TEMPLATE_SPECIALIZATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE (NODE) = 2)

#define DECL_IMPLICIT_INSTANTIATION(NODE) (DECL_USE_TEMPLATE (NODE) == 1)
#define SET_DECL_IMPLICIT_INSTANTIATION(NODE) (DECL_USE_TEMPLATE (NODE) = 1)
#define CLASSTYPE_IMPLICIT_INSTANTIATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE(NODE) == 1)
#define SET_CLASSTYPE_IMPLICIT_INSTANTIATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE(NODE) = 1)

#define DECL_EXPLICIT_INSTANTIATION(NODE) (DECL_USE_TEMPLATE (NODE) == 3)
#define SET_DECL_EXPLICIT_INSTANTIATION(NODE) (DECL_USE_TEMPLATE (NODE) = 3)
#define CLASSTYPE_EXPLICIT_INSTANTIATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE(NODE) == 3)
#define SET_CLASSTYPE_EXPLICIT_INSTANTIATION(NODE) \
  (CLASSTYPE_USE_TEMPLATE(NODE) = 3)

/* Non-zero if DECL is a friend function which is an instantiation
   from the point of view of the compiler, but not from the point of
   view of the language.  For example given:
      template <class T> struct S { friend void f(T) {}; };
   the declaration of `void f(int)' generated when S<int> is
   instantiated will not be a DECL_TEMPLATE_INSTANTIATION, but will be
   a DECL_FRIEND_PSUEDO_TEMPLATE_INSTANTIATION.  */
#define DECL_FRIEND_PSEUDO_TEMPLATE_INSTANTIATION(DECL) \
  (DECL_TEMPLATE_INFO (DECL) && !DECL_USE_TEMPLATE (DECL))

/* Non-zero if TYPE is a partial instantiation of a template class,
   i.e., an instantiation whose instantiation arguments involve
   template types.  */
#define PARTIAL_INSTANTIATION_P(TYPE) \
  (TYPE_LANG_SPECIFIC (TYPE)->is_partial_instantiation)

/* Non-zero iff we are currently processing a declaration for an
   entity with its own template parameter list, and which is not a
   full specialization.  */
#define PROCESSING_REAL_TEMPLATE_DECL_P() \
  (processing_template_decl > template_class_depth (current_class_type))

/* This function may be a guiding decl for a template.  */
#define DECL_MAYBE_TEMPLATE(NODE) DECL_LANG_FLAG_4 (NODE)

/* Nonzero if this VAR_DECL or FUNCTION_DECL has already been
   instantiated, i.e. its definition has been generated from the
   pattern given in the the template.  */
#define DECL_TEMPLATE_INSTANTIATED(NODE) \
  DECL_LANG_FLAG_1 (VAR_OR_FUNCTION_DECL_CHECK (NODE))

/* We know what we're doing with this decl now.  */
#define DECL_INTERFACE_KNOWN(NODE) DECL_LANG_FLAG_5 (NODE)

/* This function was declared inline.  This flag controls the linkage
   semantics of 'inline'; whether or not the function is inlined is
   controlled by DECL_INLINE.  */
#define DECL_THIS_INLINE(NODE) \
  (DECL_LANG_SPECIFIC (NODE)->decl_flags.declared_inline)

/* DECL_EXTERNAL must be set on a decl until the decl is actually emitted,
   so that assemble_external will work properly.  So we have this flag to
   tell us whether the decl is really not external.  */
#define DECL_NOT_REALLY_EXTERN(NODE) \
  (DECL_LANG_SPECIFIC (NODE)->decl_flags.not_really_extern)

#define DECL_REALLY_EXTERN(NODE) \
  (DECL_EXTERNAL (NODE) && ! DECL_NOT_REALLY_EXTERN (NODE))

#define THUNK_DELTA(DECL) ((DECL)->decl.frame_size.i)

/* DECL_NEEDED_P holds of a declaration when we need to emit its
   definition.  This is true when the back-end tells us that
   the symbol has been referenced in the generated code.  If, however,
   we are not generating code, then it is also true when a symbol has
   just been used somewhere, even if it's not really needed.  */
#define DECL_NEEDED_P(DECL)				  \
  (TREE_SYMBOL_REFERENCED (DECL_ASSEMBLER_NAME ((DECL)))) \

/* An un-parsed default argument looks like an identifier.  */
#define DEFARG_LENGTH(NODE)  (DEFAULT_ARG_CHECK(NODE)->identifier.length)
#define DEFARG_POINTER(NODE) (DEFAULT_ARG_CHECK(NODE)->identifier.pointer)

/* These macros provide convenient access to the various _STMT nodes
   created when parsing template declarations.  */
#define IF_COND(NODE)           TREE_OPERAND (IF_STMT_CHECK (NODE), 0)
#define THEN_CLAUSE(NODE)       TREE_OPERAND (IF_STMT_CHECK (NODE), 1)
#define ELSE_CLAUSE(NODE)       TREE_OPERAND (IF_STMT_CHECK (NODE), 2)
#define WHILE_COND(NODE)        TREE_OPERAND (WHILE_STMT_CHECK (NODE), 0)
#define WHILE_BODY(NODE)        TREE_OPERAND (WHILE_STMT_CHECK (NODE), 1)
#define DO_COND(NODE)           TREE_OPERAND (DO_STMT_CHECK (NODE), 0)
#define DO_BODY(NODE)           TREE_OPERAND (DO_STMT_CHECK (NODE), 1)
#define RETURN_EXPR(NODE)       TREE_OPERAND (RETURN_STMT_CHECK (NODE), 0)
#define EXPR_STMT_EXPR(NODE)    TREE_OPERAND (EXPR_STMT_CHECK (NODE), 0)
#define FOR_INIT_STMT(NODE)     TREE_OPERAND (FOR_STMT_CHECK (NODE), 0)
#define FOR_COND(NODE)          TREE_OPERAND (FOR_STMT_CHECK (NODE), 1)
#define FOR_EXPR(NODE)          TREE_OPERAND (FOR_STMT_CHECK (NODE), 2)
#define FOR_BODY(NODE)          TREE_OPERAND (FOR_STMT_CHECK (NODE), 3)
#define SWITCH_COND(NODE)       TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 0)
#define SWITCH_BODY(NODE)       TREE_OPERAND (SWITCH_STMT_CHECK (NODE), 1)
#define CASE_LOW(NODE)          TREE_OPERAND (CASE_LABEL_CHECK (NODE), 0)
#define CASE_HIGH(NODE)         TREE_OPERAND (CASE_LABEL_CHECK (NODE), 1)
#define GOTO_DESTINATION(NODE)  TREE_OPERAND (GOTO_STMT_CHECK (NODE), 0)
#define TRY_STMTS(NODE)         TREE_OPERAND (TRY_BLOCK_CHECK (NODE), 0)
#define TRY_HANDLERS(NODE)      TREE_OPERAND (TRY_BLOCK_CHECK (NODE), 1)
#define CLEANUP_P(NODE)         TREE_LANG_FLAG_0 (TRY_BLOCK_CHECK (NODE))
/* Nonzero if this try block is a function try block.  */
#define FN_TRY_BLOCK_P(NODE)    TREE_LANG_FLAG_3 (TRY_BLOCK_CHECK (NODE))
#define HANDLER_PARMS(NODE)     TREE_OPERAND (HANDLER_CHECK (NODE), 0)
#define HANDLER_BODY(NODE)      TREE_OPERAND (HANDLER_CHECK (NODE), 1)
#define COMPOUND_BODY(NODE)     TREE_OPERAND (COMPOUND_STMT_CHECK (NODE), 0)
#define ASM_CV_QUAL(NODE)       TREE_OPERAND (ASM_STMT_CHECK (NODE), 0)
#define ASM_STRING(NODE)        TREE_OPERAND (ASM_STMT_CHECK (NODE), 1)
#define ASM_OUTPUTS(NODE)       TREE_OPERAND (ASM_STMT_CHECK (NODE), 2)
#define ASM_INPUTS(NODE)        TREE_OPERAND (ASM_STMT_CHECK (NODE), 3)
#define ASM_CLOBBERS(NODE)      TREE_OPERAND (ASM_STMT_CHECK (NODE), 4)
#define DECL_STMT_DECL(NODE)    TREE_OPERAND (DECL_STMT_CHECK (NODE), 0)
#define STMT_EXPR_STMT(NODE)    TREE_OPERAND (STMT_EXPR_CHECK (NODE), 0)
#define SUBOBJECT_CLEANUP(NODE) TREE_OPERAND (SUBOBJECT_CHECK (NODE), 0)
#define CLEANUP_DECL(NODE)      TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 0)
#define CLEANUP_EXPR(NODE)      TREE_OPERAND (CLEANUP_STMT_CHECK (NODE), 1)
#define START_CATCH_TYPE(NODE)  TREE_TYPE (START_CATCH_STMT_CHECK (NODE))
#define LABEL_STMT_LABEL(NODE)  TREE_OPERAND (LABEL_STMT_CHECK (NODE), 0)

/* Nonzero if this SCOPE_STMT is for the beginning of a scope.  */
#define SCOPE_BEGIN_P(NODE) \
  (TREE_LANG_FLAG_0 (SCOPE_STMT_CHECK (NODE))) 

/* Nonzero if this SCOPE_STMT is for the end of a scope.  */
#define SCOPE_END_P(NODE) \
  (!SCOPE_BEGIN_P (SCOPE_STMT_CHECK (NODE)))

/* Nonzero for a SCOPE_STMT if there were no variables in this scope.  */
#define SCOPE_NULLIFIED_P(NODE) \
  (TREE_LANG_FLAG_3 (SCOPE_STMT_CHECK (NODE)))

/* Nonzero for a SCOPE_STMT if this statement is for a partial scope.
   For example, in:
  
     S s;
     l:
     S s2;
     goto l;

   there is (implicitly) a new scope after `l', even though there are
   no curly braces.  In particular, when we hit the goto, we must
   destroy s2 and then re-construct it.  For the implicit scope,
   SCOPE_PARTIAL_P will be set.  */
#define SCOPE_PARTIAL_P(NODE) \
  (TREE_LANG_FLAG_4 (SCOPE_STMT_CHECK (NODE)))

/* Nonzero for an ASM_STMT if the assembly statement is volatile.  */
#define ASM_VOLATILE_P(NODE)			\
  (ASM_CV_QUAL (ASM_STMT_CHECK (NODE)) != NULL_TREE)

/* The line-number at which a statement began.  But if
   STMT_LINENO_FOR_FN_P does holds, then this macro gives the
   line number for the end of the current function instead.  */
#define STMT_LINENO(NODE)			\
  (TREE_COMPLEXITY ((NODE)))

/* If non-zero, the STMT_LINENO for NODE is the line at which the
   function ended.  */
#define STMT_LINENO_FOR_FN_P(NODE) 		\
  (TREE_LANG_FLAG_2 ((NODE)))

/* The parameters for a call-declarator.  */
#define CALL_DECLARATOR_PARMS(NODE) \
  (TREE_PURPOSE (TREE_OPERAND ((NODE), 1)))

/* The cv-qualifiers for a call-declarator.  */
#define CALL_DECLARATOR_QUALS(NODE) \
  (TREE_VALUE (TREE_OPERAND ((NODE), 1)))

/* The exception-specification for a call-declarator.  */
#define CALL_DECLARATOR_EXCEPTION_SPEC(NODE) \
  (TREE_TYPE ((NODE)))

/* An enumeration of the kind of tags that C++ accepts.  */
enum tag_types { record_type, class_type, union_type, enum_type };

/* The various kinds of lvalues we distinguish.  */
typedef enum cp_lvalue_kind {
  clk_none = 0,     /* Things that are not an lvalue.  */
  clk_ordinary = 1, /* An ordinary lvalue.  */
  clk_class = 2,    /* An rvalue of class-type.  */
  clk_bitfield = 4, /* An lvalue for a bit-field.  */
} cp_lvalue_kind;

/* Zero means prototype weakly, as in ANSI C (no args means nothing).
   Each language context defines how this variable should be set.  */
extern int strict_prototype;
extern int strict_prototypes_lang_c, strict_prototypes_lang_cplusplus;

/* Non-zero means that if a label exists, and no other identifier
   applies, use the value of the label.  */
extern int flag_labels_ok;

/* Nonzero means allow Microsoft extensions without a pedwarn.  */
extern int flag_ms_extensions;

/* Non-zero means to collect statistics which might be expensive
   and to print them when we are done.  */
extern int flag_detailed_statistics;

/* Non-zero means warn in function declared in derived class has the
   same name as a virtual in the base class, but fails to match the
   type signature of any virtual function in the base class.  */
extern int warn_overloaded_virtual;

/* Nonzero means warn about use of multicharacter literals.  */
extern int warn_multichar;

/* Non-zero means warn if a non-templatized friend function is
   declared in a templatized class. This behavior is warned about with
   flag_guiding_decls in do_friend. */
extern int warn_nontemplate_friend;

/* in c-common.c */
extern void declare_function_name               PROTO((void));
extern void decl_attributes                     PROTO((tree, tree, tree));
extern void init_function_format_info		PROTO((void));
extern void record_function_format		PROTO((tree, tree, int, int, int));
extern void check_function_format		PROTO((tree, tree, tree));
/* Print an error message for invalid operands to arith operation CODE.
   NOP_EXPR is used as a special case (see truthvalue_conversion).  */
extern void binary_op_error                     PROTO((enum tree_code));
extern tree canonical_type_variant              PROTO((tree));
extern void c_expand_expr_stmt                  PROTO((tree));
/* Validate the expression after `case' and apply default promotions.  */
extern tree check_case_value                    PROTO((tree));
/* Concatenate a list of STRING_CST nodes into one STRING_CST.  */
extern tree combine_strings                     PROTO((tree));
extern void constant_expression_warning         PROTO((tree));
extern tree convert_and_check			PROTO((tree, tree));
extern void overflow_warning			PROTO((tree));
extern void unsigned_conversion_warning		PROTO((tree, tree));
extern void c_apply_type_quals_to_decl          PROTO((int, tree));

/* Read the rest of the current #-directive line.  */
#if USE_CPPLIB
extern char *get_directive_line                 PROTO((void));
#define GET_DIRECTIVE_LINE() get_directive_line ()
#else
extern char *get_directive_line                 PROTO((FILE *));
#define GET_DIRECTIVE_LINE() get_directive_line (finput)
#endif
/* Subroutine of build_binary_op, used for comparison operations.
   See if the operands have both been converted from subword integer types
   and, if so, perhaps change them both back to their original type.  */
extern tree shorten_compare                     PROTO((tree *, tree *, tree *, enum tree_code *));
/* Prepare expr to be an argument of a TRUTH_NOT_EXPR,
   or validate its data type for an `if' or `while' statement or ?..: exp.  */
extern tree truthvalue_conversion               PROTO((tree));
extern tree type_for_mode                       PROTO((enum machine_mode, int));
extern tree type_for_size                       PROTO((unsigned, int));
extern int c_get_alias_set                      PROTO((tree));

/* in decl{2}.c */
/* A node that is a list (length 1) of error_mark_nodes.  */
extern tree error_mark_list;

/* A list of virtual function tables we must make sure to write out.  */
extern tree pending_vtables;

/* Node for "pointer to (virtual) function".
   This may be distinct from ptr_type_node so gdb can distinguish them.  */
#define vfunc_ptr_type_node \
  (flag_vtable_thunks ? vtable_entry_type : ptr_type_node)


/* For building calls to `delete'.  */
extern tree integer_two_node, integer_three_node;

extern tree anonymous_namespace_name;

/* in pt.c  */

/* These values are used for the `STRICT' parameter to type_unfication and
   fn_type_unification.  Their meanings are described with the
   documentation for fn_type_unification.  */

typedef enum unification_kind_t {
  DEDUCE_CALL,
  DEDUCE_CONV,
  DEDUCE_EXACT
} unification_kind_t;

/* The template currently being instantiated, and where the instantiation
   was triggered.  */
struct tinst_level
{
  tree decl;
  int line;
  char *file;
  struct tinst_level *next;
};

extern void maybe_print_template_context	PROTO ((void));

/* in class.c */

extern int current_class_depth;

/* Points to the name of that function. May not be the DECL_NAME
   of CURRENT_FUNCTION_DECL due to overloading */
extern tree original_function_name;

/* in init.c  */
extern tree global_base_init_list;


/* Here's where we control how name mangling takes place.  */

#define OPERATOR_ASSIGN_FORMAT "__a%s"
#define OPERATOR_FORMAT "__%s"
#define OPERATOR_TYPENAME_FORMAT "__op"

/* Cannot use '$' up front, because this confuses gdb
   (names beginning with '$' are gdb-local identifiers).

   Note that all forms in which the '$' is significant are long enough
   for direct indexing (meaning that if we know there is a '$'
   at a particular location, we can index into the string at
   any other location that provides distinguishing characters).  */

/* Define NO_DOLLAR_IN_LABEL in your favorite tm file if your assembler
   doesn't allow '$' in symbol names.  */
#ifndef NO_DOLLAR_IN_LABEL

#define JOINER '$'

#define VPTR_NAME "$v"
#define THROW_NAME "$eh_throw"
#define DESTRUCTOR_DECL_PREFIX "_$_"
#define AUTO_VTABLE_NAME "__vtbl$me__"
#define AUTO_TEMP_NAME "_$tmp_"
#define AUTO_TEMP_FORMAT "_$tmp_%d"
#define VTABLE_BASE "$vb"
#define VTABLE_NAME_FORMAT (flag_vtable_thunks ? "__vt_%s" : "_vt$%s")
#define VFIELD_BASE "$vf"
#define VFIELD_NAME "_vptr$"
#define VFIELD_NAME_FORMAT "_vptr$%s"
#define VBASE_NAME "_vb$"
#define VBASE_NAME_FORMAT "_vb$%s"
#define STATIC_NAME_FORMAT "_%s$%s"
#define ANON_AGGRNAME_FORMAT "$_%d"

#else /* NO_DOLLAR_IN_LABEL */

#ifndef NO_DOT_IN_LABEL

#define JOINER '.'

#define VPTR_NAME ".v"
#define THROW_NAME ".eh_throw"
#define DESTRUCTOR_DECL_PREFIX "_._"
#define AUTO_VTABLE_NAME "__vtbl.me__"
#define AUTO_TEMP_NAME "_.tmp_"
#define AUTO_TEMP_FORMAT "_.tmp_%d"
#define VTABLE_BASE ".vb"
#define VTABLE_NAME_FORMAT (flag_vtable_thunks ? "__vt_%s" : "_vt.%s")
#define VFIELD_BASE ".vf"
#define VFIELD_NAME "_vptr."
#define VFIELD_NAME_FORMAT "_vptr.%s"
#define VBASE_NAME "_vb."
#define VBASE_NAME_FORMAT "_vb.%s"
#define STATIC_NAME_FORMAT "_%s.%s"

#define ANON_AGGRNAME_FORMAT "._%d"

#else /* NO_DOT_IN_LABEL */

#define VPTR_NAME "__vptr"
#define VPTR_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), VPTR_NAME, sizeof (VPTR_NAME) - 1))
#define THROW_NAME "__eh_throw"
#define DESTRUCTOR_DECL_PREFIX "__destr_"
#define DESTRUCTOR_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), DESTRUCTOR_DECL_PREFIX, \
	     sizeof (DESTRUCTOR_DECL_PREFIX) - 1))
#define IN_CHARGE_NAME "__in_chrg"
#define AUTO_VTABLE_NAME "__vtbl_me__"
#define AUTO_TEMP_NAME "__tmp_"
#define TEMP_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, \
	     sizeof (AUTO_TEMP_NAME) - 1))
#define AUTO_TEMP_FORMAT "__tmp_%d"
#define VTABLE_BASE "__vtb"
#define VTABLE_NAME "__vt_"
#define VTABLE_NAME_FORMAT (flag_vtable_thunks ? "__vt_%s" : "_vt_%s")
#define VTABLE_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), VTABLE_NAME, \
	     sizeof (VTABLE_NAME) - 1))
#define VFIELD_BASE "__vfb"
#define VFIELD_NAME "__vptr_"
#define VFIELD_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, \
	    sizeof (VFIELD_NAME) - 1))
#define VFIELD_NAME_FORMAT "_vptr_%s"
#define VBASE_NAME "__vb_"
#define VBASE_NAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), VBASE_NAME, \
	     sizeof (VBASE_NAME) - 1))
#define VBASE_NAME_FORMAT "__vb_%s"
#define STATIC_NAME_FORMAT "__static_%s_%s"

#define ANON_AGGRNAME_PREFIX "__anon_"
#define ANON_AGGRNAME_P(ID_NODE) \
  (!strncmp (IDENTIFIER_POINTER (ID_NODE), ANON_AGGRNAME_PREFIX, \
	     sizeof (ANON_AGGRNAME_PREFIX) - 1))
#define ANON_AGGRNAME_FORMAT "__anon_%d"
#define ANON_PARMNAME_FORMAT "__%d"
#define ANON_PARMNAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[0] == '_' \
				  && IDENTIFIER_POINTER (ID_NODE)[1] == '_' \
				  && IDENTIFIER_POINTER (ID_NODE)[2] <= '9')

#endif	/* NO_DOT_IN_LABEL */
#endif	/* NO_DOLLAR_IN_LABEL */

#define THIS_NAME "this"
#define DESTRUCTOR_NAME_FORMAT "~%s"
#define FILE_FUNCTION_PREFIX_LEN 9
#define CTOR_NAME "__ct"
#define DTOR_NAME "__dt"

#define IN_CHARGE_NAME "__in_chrg"

#define VTBL_PTR_TYPE		"__vtbl_ptr_type"
#define VTABLE_DELTA_NAME	"__delta"
#define VTABLE_INDEX_NAME	"__index"
#define VTABLE_PFN_NAME		"__pfn"
#define VTABLE_DELTA2_NAME	"__delta2"

#define EXCEPTION_CLEANUP_NAME 	"exception cleanup"

#define THIS_NAME_P(ID_NODE) (strcmp(IDENTIFIER_POINTER (ID_NODE), "this") == 0)

#if !defined(NO_DOLLAR_IN_LABEL) || !defined(NO_DOT_IN_LABEL)

#define VPTR_NAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \
			      && IDENTIFIER_POINTER (ID_NODE)[1] == 'v')
#define DESTRUCTOR_NAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[1] == JOINER \
                                    && IDENTIFIER_POINTER (ID_NODE)[2] == '_') 

#define VTABLE_NAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[1] == 'v' \
  && IDENTIFIER_POINTER (ID_NODE)[2] == 't' \
  && IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)

#define VBASE_NAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[1] == 'v' \
  && IDENTIFIER_POINTER (ID_NODE)[2] == 'b' \
  && IDENTIFIER_POINTER (ID_NODE)[3] == JOINER)

#define TEMP_NAME_P(ID_NODE) (!strncmp (IDENTIFIER_POINTER (ID_NODE), AUTO_TEMP_NAME, sizeof (AUTO_TEMP_NAME)-1))
#define VFIELD_NAME_P(ID_NODE) (!strncmp (IDENTIFIER_POINTER (ID_NODE), VFIELD_NAME, sizeof(VFIELD_NAME)-1))

/* For anonymous aggregate types, we need some sort of name to
   hold on to.  In practice, this should not appear, but it should
   not be harmful if it does.  */
#define ANON_AGGRNAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[0] == JOINER \
				  && IDENTIFIER_POINTER (ID_NODE)[1] == '_')
#define ANON_PARMNAME_FORMAT "_%d"
#define ANON_PARMNAME_P(ID_NODE) (IDENTIFIER_POINTER (ID_NODE)[0] == '_' \
				  && IDENTIFIER_POINTER (ID_NODE)[1] <= '9')
#endif /* !defined(NO_DOLLAR_IN_LABEL) || !defined(NO_DOT_IN_LABEL) */

/* Store the vbase pointer field name for type TYPE into pointer BUF.  */
#define FORMAT_VBASE_NAME(BUF,TYPE) do { 				\
  char *wbuf = (char *) alloca (TYPE_ASSEMBLER_NAME_LENGTH (TYPE)	\
			 + sizeof (VBASE_NAME) + 1);			\
  sprintf (wbuf, VBASE_NAME_FORMAT, TYPE_ASSEMBLER_NAME_STRING (TYPE));	\
  (BUF) = wbuf;								\
} while (0)

/* Returns non-zero iff ID_NODE is an IDENTIFIER_NODE whose name is
   `main'.  */
#define MAIN_NAME_P(ID_NODE) \
   (strcmp (IDENTIFIER_POINTER (ID_NODE), "main") == 0)

/* Returns non-zero iff NODE is a declaration for the global function
   `main'.  */
#define DECL_MAIN_P(NODE)				\
   (TREE_CODE (NODE) == FUNCTION_DECL			\
    && DECL_LANGUAGE (NODE) == lang_c	 		\
    && DECL_NAME (NODE) != NULL_TREE			\
    && MAIN_NAME_P (DECL_NAME (NODE)))


/* Things for handling inline functions.  */

struct pending_inline
{
  struct pending_inline *next;	/* pointer to next in chain */
  int lineno;			/* line number we got the text from */
  char *filename;		/* name of file we were processing */
  tree fndecl;			/* FUNCTION_DECL that brought us here */
  int token;			/* token we were scanning */
  int token_value;		/* value of token we were scanning (YYSTYPE) */

  char *buf;			/* pointer to character stream */
  int len;			/* length of stream */
  unsigned int can_free : 1;	/* free this after we're done with it? */
  unsigned int deja_vu : 1;	/* set iff we don't want to see it again.  */
  unsigned int interface : 2;	/* 0=interface 1=unknown 2=implementation */
};

/* in method.c */
extern struct pending_inline *pending_inlines;

/* Negative values means we know `this' to be of static type.  */

extern int flag_this_is_variable;

/* Nonzero means generate 'rtti' that give run-time type information.  */

extern int flag_rtti;

/* Nonzero means do emit exported implementations of functions even if
   they can be inlined.  */

extern int flag_implement_inlines;

/* Nonzero means templates obey #pragma interface and implementation.  */

extern int flag_external_templates;

/* Nonzero means templates are emitted where they are instantiated.  */

extern int flag_alt_external_templates;

/* Nonzero means implicit template instantiations are emitted.  */

extern int flag_implicit_templates;

/* Nonzero if we want to emit defined symbols with common-like linkage as
   weak symbols where possible, in order to conform to C++ semantics.
   Otherwise, emit them as local symbols.  */

extern int flag_weak;

/* Nonzero to enable experimental ABI changes.  */

extern int flag_new_abi;

/* Nonzero to not ignore namespace std. */

extern int flag_honor_std;

/* Nonzero if we're done parsing and into end-of-file activities.  */

extern int at_eof;

enum overload_flags { NO_SPECIAL = 0, DTOR_FLAG, OP_FLAG, TYPENAME_FLAG };

/* Some macros for char-based bitfields.  */
#define B_SET(a,x) (a[x>>3] |= (1 << (x&7)))
#define B_CLR(a,x) (a[x>>3] &= ~(1 << (x&7)))
#define B_TST(a,x) (a[x>>3] & (1 << (x&7)))

/* These are uses as bits in flags passed to build_method_call
   to control its error reporting behavior.

   LOOKUP_PROTECT means flag access violations.
   LOOKUP_COMPLAIN mean complain if no suitable member function
     matching the arguments is found.
   LOOKUP_NORMAL is just a combination of these two.
   LOOKUP_NONVIRTUAL means make a direct call to the member function found
   LOOKUP_GLOBAL means search through the space of overloaded functions,
     as well as the space of member functions.
   LOOKUP_HAS_IN_CHARGE means that the "in charge" variable is already
     in the parameter list.
   LOOKUP_ONLYCONVERTING means that non-conversion constructors are not tried.
   DIRECT_BIND means that if a temporary is created, it should be created so
     that it lives as long as the current variable bindings; otherwise it
     only lives until the end of the complete-expression.
   LOOKUP_SPECULATIVELY means return NULL_TREE if we cannot find what we are
     after.  Note, LOOKUP_COMPLAIN is checked and error messages printed
     before LOOKUP_SPECULATIVELY is checked.
   LOOKUP_NO_CONVERSION means that user-defined conversions are not
     permitted.  Built-in conversions are permitted.
   LOOKUP_DESTRUCTOR means explicit call to destructor.
   LOOKUP_NO_TEMP_BIND means temporaries will not be bound to references.

   These are used in global lookup to support elaborated types and
   qualifiers.
   
   LOOKUP_PREFER_TYPES means not to accept objects, and possibly namespaces.
   LOOKUP_PREFER_NAMESPACES means not to accept objects, and possibly types.
   LOOKUP_PREFER_BOTH means class-or-namespace-name.
   LOOKUP_TEMPLATES_EXPECTED means that class templates also count
     as types.  */

#define LOOKUP_PROTECT (1)
#define LOOKUP_COMPLAIN (2)
#define LOOKUP_NORMAL (3)
/* #define LOOKUP_UNUSED (4) */
#define LOOKUP_NONVIRTUAL (8)
#define LOOKUP_GLOBAL (16)
#define LOOKUP_HAS_IN_CHARGE (32)
#define LOOKUP_SPECULATIVELY (64)
#define LOOKUP_ONLYCONVERTING (128)
#define DIRECT_BIND (256)
#define LOOKUP_NO_CONVERSION (512)
#define LOOKUP_DESTRUCTOR (512)
#define LOOKUP_NO_TEMP_BIND (1024)
#define LOOKUP_PREFER_TYPES (2048)
#define LOOKUP_PREFER_NAMESPACES (4096)
#define LOOKUP_PREFER_BOTH (6144)
#define LOOKUP_TEMPLATES_EXPECTED (8192)

#define LOOKUP_NAMESPACES_ONLY(f)  \
  (((f) & LOOKUP_PREFER_NAMESPACES) && !((f) & LOOKUP_PREFER_TYPES))
#define LOOKUP_TYPES_ONLY(f)  \
  (!((f) & LOOKUP_PREFER_NAMESPACES) && ((f) & LOOKUP_PREFER_TYPES))
#define LOOKUP_QUALIFIERS_ONLY(f)     ((f) & LOOKUP_PREFER_BOTH)
     

/* These flags are used by the conversion code.
   CONV_IMPLICIT   :  Perform implicit conversions (standard and user-defined).
   CONV_STATIC     :  Perform the explicit conversions for static_cast.
   CONV_CONST      :  Perform the explicit conversions for const_cast.
   CONV_REINTERPRET:  Perform the explicit conversions for reinterpret_cast.
   CONV_PRIVATE    :  Perform upcasts to private bases.
   CONV_FORCE_TEMP :  Require a new temporary when converting to the same
   		      aggregate type.  */

#define CONV_IMPLICIT    1
#define CONV_STATIC      2
#define CONV_CONST       4
#define CONV_REINTERPRET 8
#define CONV_PRIVATE	 16
/* #define CONV_NONCONVERTING 32 */
#define CONV_FORCE_TEMP  64
#define CONV_STATIC_CAST (CONV_IMPLICIT | CONV_STATIC | CONV_FORCE_TEMP)
#define CONV_OLD_CONVERT (CONV_IMPLICIT | CONV_STATIC | CONV_CONST \
			  | CONV_REINTERPRET)
#define CONV_C_CAST      (CONV_IMPLICIT | CONV_STATIC | CONV_CONST \
			  | CONV_REINTERPRET | CONV_PRIVATE | CONV_FORCE_TEMP)

/* Used by build_expr_type_conversion to indicate which types are
   acceptable as arguments to the expression under consideration.  */

#define WANT_INT	1 /* integer types, including bool */
#define WANT_FLOAT	2 /* floating point types */
#define WANT_ENUM	4 /* enumerated types */
#define WANT_POINTER	8 /* pointer types */
#define WANT_NULL      16 /* null pointer constant */
#define WANT_ARITH	(WANT_INT | WANT_FLOAT)

/* Used with comptypes, and related functions, to guide type
   comparison.  */

#define COMPARE_STRICT        0 /* Just check if the types are the
				   same.  */
#define COMPARE_BASE          1 /* Check to see if the second type is
				   derived from the first, or if both
				   are pointers (or references) and
				   the types pointed to by the second
				   type is derived from the pointed to
				   by the first.  */
#define COMPARE_RELAXED       2 /* Like COMPARE_DERIVED, but in
				   reverse.  Also treat enmeration
				   types as the same as integer types
				   of the same width.  */
#define COMPARE_REDECLARATION 4 /* The comparsion is being done when
				   another declaration of an existing
				   entity is seen.  */
#define COMPARE_NO_ATTRIBUTES 8 /* The comparison should ignore
				   extra-linguistic type attributes.  */

/* Used with push_overloaded_decl.  */
#define PUSH_GLOBAL          0  /* Push the DECL into namespace scope,
				   regardless of the current scope.  */
#define PUSH_LOCAL           1  /* Push the DECL into the current
				   scope.  */
#define PUSH_USING           2  /* We are pushing this DECL as the
				   result of a using declaration.  */

/* Used with start function.  */
#define SF_DEFAULT           0  /* No flags.  */
#define SF_PRE_PARSED        1  /* The function declaration has
				   already been parsed.  */
#define SF_INCLASS_INLINE    2  /* The function is an inline, defined
				   in the class body.  */
#define SF_EXPAND            4  /* Generate RTL for this function.  */

/* Returns nonzero iff TYPE1 and TYPE2 are the same type, in the usual
   sense of `same'.  */
#define same_type_p(type1, type2) \
  comptypes ((type1), (type2), COMPARE_STRICT)

/* Returns nonzero iff TYPE1 and TYPE2 are the same type, or if TYPE2
   is derived from TYPE1, or if TYPE2 is a pointer (reference) to a
   class derived from the type pointed to (referred to) by TYPE1.  */
#define same_or_base_type_p(type1, type2) \
  comptypes ((type1), (type2), COMPARE_BASE)

/* These macros are used to access a TEMPLATE_PARM_INDEX.  */
#define TEMPLATE_PARM_INDEX_CAST(NODE) \
	((template_parm_index*)TEMPLATE_PARM_INDEX_CHECK (NODE))
#define TEMPLATE_PARM_IDX(NODE) (TEMPLATE_PARM_INDEX_CAST (NODE)->index)
#define TEMPLATE_PARM_LEVEL(NODE) (TEMPLATE_PARM_INDEX_CAST (NODE)->level)
#define TEMPLATE_PARM_DESCENDANTS(NODE) (TREE_CHAIN (NODE))
#define TEMPLATE_PARM_ORIG_LEVEL(NODE) (TEMPLATE_PARM_INDEX_CAST (NODE)->orig_level)
#define TEMPLATE_PARM_DECL(NODE) (TEMPLATE_PARM_INDEX_CAST (NODE)->decl)

/* These macros are for accessing the fields of TEMPLATE_TYPE_PARM 
   and TEMPLATE_TEMPLATE_PARM nodes.  */
#define TEMPLATE_TYPE_PARM_INDEX(NODE) (TYPE_FIELDS (NODE))
#define TEMPLATE_TYPE_IDX(NODE) \
  (TEMPLATE_PARM_IDX (TEMPLATE_TYPE_PARM_INDEX (NODE)))
#define TEMPLATE_TYPE_LEVEL(NODE) \
  (TEMPLATE_PARM_LEVEL (TEMPLATE_TYPE_PARM_INDEX (NODE)))
#define TEMPLATE_TYPE_ORIG_LEVEL(NODE) \
  (TEMPLATE_PARM_ORIG_LEVEL (TEMPLATE_TYPE_PARM_INDEX (NODE)))
#define TEMPLATE_TYPE_DECL(NODE) \
  (TEMPLATE_PARM_DECL (TEMPLATE_TYPE_PARM_INDEX (NODE)))

/* Control stringification of trees (types, decls & exprs).
   Bit or them together.  */
enum tree_string_flags
{
    TS_PLAIN,                    /* nothing special */
    TS_CHASE_TYPEDEFS = 1 <<  0, /* look through typedefs */
    TS_DECORATE       = 1 <<  1, /* decorate things */
    TS_FUNC_NORETURN  = 1 <<  2, /* inhibit function return type */
    TS_FUNC_THROW     = 1 <<  3, /* show throw spec */
    TS_PARM_DEFAULTS  = 1 <<  4, /* show parm defaults */
    TS_EXPR_PARENS    = 1 <<  5, /* enclose in parens */
    TS_AGGR_TAGS      = 1 <<  6, /* show struct tags */
    TS_DECL_TYPE      = 1 <<  7, /* show decl's type */
    TS_FUNC_SCOPE     = 1 <<  8, /* show function scope */
    TS_PEDANTIC_NAME  = 1 <<  9, /* pedantically name things */
    TS_TEMPLATE_PREFIX= 1 << 10, /* show template <parms> prefix */
    
    /* Internal use flags */
    TS_TEMPLATE_PARM  = 1 << 11, /* decl is really a non-type template parm */
    TS_TEMPLATE_PLAIN = 1 << 12, /* don't decorate primary template_name */
    
    TS_NEXT_BIT       = 13       /* next available bit */
};

/* in lex.c  */
/* Indexed by TREE_CODE, these tables give C-looking names to
   operators represented by TREE_CODES.  For example,
   opname_tab[(int) MINUS_EXPR] == "-".  */
extern const char **opname_tab, **assignop_tab;

/* in call.c */
extern int check_dtor_name			PROTO((tree, tree));
extern int get_arglist_len_in_bytes		PROTO((tree));

extern tree build_vfield_ref			PROTO((tree, tree));
extern tree resolve_scope_to_name		PROTO((tree, tree));
extern tree build_scoped_method_call		PROTO((tree, tree, tree, tree));
extern tree build_addr_func			PROTO((tree));
extern tree build_call				PROTO((tree, tree, tree));
extern tree build_method_call			PROTO((tree, tree, tree, tree, int));
extern int null_ptr_cst_p			PROTO((tree));
extern tree type_decays_to			PROTO((tree));
extern tree build_user_type_conversion		PROTO((tree, tree, int));
extern tree build_new_function_call		PROTO((tree, tree));
extern tree build_new_op			PROTO((enum tree_code, int, tree, tree, tree));
extern tree build_op_new_call			PROTO((enum tree_code, tree, tree, int));
extern tree build_op_delete_call		PROTO((enum tree_code, tree, tree, int, tree));
extern int can_convert				PROTO((tree, tree));
extern int can_convert_arg			PROTO((tree, tree, tree));
extern int enforce_access                       PROTO((tree, tree));
extern tree convert_default_arg                 PROTO((tree, tree, tree));
extern tree convert_arg_to_ellipsis             PROTO((tree));
extern tree build_x_va_arg                      PROTO((tree, tree));
extern tree convert_type_from_ellipsis          PROTO((tree));
extern int is_properly_derived_from             PROTO((tree, tree));
extern tree initialize_reference                PROTO((tree, tree));
extern tree strip_top_quals                     PROTO((tree));
extern tree perform_implicit_conversion         PROTO((tree, tree));

/* in class.c */
extern tree build_vbase_path			PROTO((enum tree_code, tree, tree, tree, int));
extern tree build_vtbl_ref			PROTO((tree, tree));
extern tree build_vfn_ref			PROTO((tree *, tree, tree));
extern void add_method				PROTO((tree, tree *, tree));
extern int currently_open_class			PROTO((tree));
extern tree get_vfield_offset			PROTO((tree));
extern void duplicate_tag_error			PROTO((tree));
extern tree finish_struct			PROTO((tree, tree));
extern void finish_struct_1			PROTO((tree));
extern int resolves_to_fixed_type_p		PROTO((tree, int *));
extern void init_class_processing		PROTO((void));
extern int is_empty_class			PROTO((tree));
extern void pushclass				PROTO((tree, int));
extern void popclass				PROTO((void));
extern void push_nested_class			PROTO((tree, int));
extern void pop_nested_class			PROTO((void));
extern void push_lang_context			PROTO((tree));
extern void pop_lang_context			PROTO((void));
extern tree instantiate_type			PROTO((tree, tree, int));
extern void print_class_statistics		PROTO((void));
extern unsigned HOST_WIDE_INT skip_rtti_stuff	PROTO((tree *, tree));
extern void build_self_reference		PROTO((void));
extern void warn_hidden				PROTO((tree));
extern tree get_enclosing_class			PROTO((tree));
int is_base_of_enclosing_class			PROTO((tree, tree));
extern void unreverse_member_declarations       PROTO((tree));
extern void invalidate_class_lookup_cache       PROTO((void));
extern void maybe_note_name_used_in_class       PROTO((tree, tree));
extern void note_name_declared_in_class         PROTO((tree, tree));

/* in cvt.c */
extern tree convert_to_reference		PROTO((tree, tree, int, int, tree));
extern tree convert_from_reference		PROTO((tree));
extern tree convert_pointer_to_real		PROTO((tree, tree));
extern tree convert_pointer_to			PROTO((tree, tree));
extern tree ocp_convert				PROTO((tree, tree, int, int));
extern tree cp_convert				PROTO((tree, tree));
extern tree convert_to_void			PROTO((tree, const char */*implicit context*/));
extern tree convert				PROTO((tree, tree));
extern tree convert_force			PROTO((tree, tree, int));
extern tree build_type_conversion		PROTO((tree, tree, int));
extern tree build_expr_type_conversion		PROTO((int, tree, int));
extern tree type_promotes_to			PROTO((tree));
extern tree perform_qualification_conversions   PROTO((tree, tree));

/* decl.c */
/* resume_binding_level */
extern void set_identifier_local_value		PROTO((tree, tree));
extern int global_bindings_p			PROTO((void));
extern int toplevel_bindings_p			PROTO((void));
extern int namespace_bindings_p			PROTO((void));
extern void keep_next_level			PROTO((int));
extern int kept_level_p				PROTO((void));
extern void declare_pseudo_global_level		PROTO((void));
extern int pseudo_global_level_p		PROTO((void));
extern void set_class_shadows			PROTO((tree));
extern void pushlevel				PROTO((int));
extern void note_level_for_for			PROTO((void));
extern void resume_level			PROTO((struct binding_level *));
extern void delete_block			PROTO((tree));
extern void insert_block			PROTO((tree));
extern void add_block_current_level		PROTO((tree));
extern void set_block				PROTO((tree));
extern void pushlevel_class			PROTO((void));
extern void poplevel_class                      PROTO((void));
extern void print_binding_stack			PROTO((void));
extern void print_binding_level			PROTO((struct binding_level *));
extern void push_namespace			PROTO((tree));
extern void pop_namespace			PROTO((void));
extern void push_nested_namespace		PROTO((tree));
extern void pop_nested_namespace		PROTO((tree));
extern void maybe_push_to_top_level		PROTO((int));
extern void push_to_top_level			PROTO((void));
extern void pop_from_top_level			PROTO((void));
extern tree identifier_type_value		PROTO((tree));
extern void set_identifier_type_value		PROTO((tree, tree));
extern void pop_everything			PROTO((void));
extern void pushtag				PROTO((tree, tree, int));
extern tree make_anon_name			PROTO((void));
extern void clear_anon_tags			PROTO((void));
extern int decls_match				PROTO((tree, tree));
extern int duplicate_decls			PROTO((tree, tree));
extern tree pushdecl				PROTO((tree));
extern tree pushdecl_top_level			PROTO((tree));
extern void pushdecl_class_level		PROTO((tree));
#if 0
extern void pushdecl_nonclass_level		PROTO((tree));
#endif
extern tree pushdecl_namespace_level            PROTO((tree));
extern tree push_using_decl                     PROTO((tree, tree));
extern tree push_using_directive                PROTO((tree));
extern void push_class_level_binding		PROTO((tree, tree));
extern tree implicitly_declare			PROTO((tree));
extern tree lookup_label			PROTO((tree));
extern tree declare_local_label                 PROTO((tree));
extern tree define_label			PROTO((char *, int, tree));
extern void push_switch				PROTO((void));
extern void pop_switch				PROTO((void));
extern void define_case_label			PROTO((void));
extern tree getdecls				PROTO((void));
extern tree gettags				PROTO((void));
#if 0
extern void set_current_level_tags_transparency	PROTO((int));
#endif
extern tree binding_for_name                    PROTO((tree, tree));
extern tree namespace_binding                   PROTO((tree, tree));
extern void set_namespace_binding               PROTO((tree, tree, tree));
extern tree lookup_namespace_name		PROTO((tree, tree));
extern tree build_typename_type                 PROTO((tree, tree, tree, tree));
extern tree make_typename_type			PROTO((tree, tree, int));
extern tree lookup_name_nonclass		PROTO((tree));
extern tree lookup_function_nonclass            PROTO((tree, tree));
extern tree lookup_name				PROTO((tree, int));
extern tree lookup_name_current_level		PROTO((tree));
extern tree lookup_type_current_level		PROTO((tree));
extern tree lookup_name_namespace_only          PROTO((tree));
extern void begin_only_namespace_names          PROTO((void));
extern void end_only_namespace_names            PROTO((void));
extern tree namespace_ancestor			PROTO((tree, tree));
extern tree unqualified_namespace_lookup	PROTO((tree, int, tree *));
extern int  lookup_using_namespace              PROTO((tree, tree, tree, tree, int, tree *));
extern int  qualified_lookup_using_namespace    PROTO((tree, tree, tree, int));
extern tree auto_function			PROTO((tree, tree));
extern void init_decl_processing		PROTO((void));
extern int init_type_desc			PROTO((void));
extern tree define_function			PROTO((const char *, tree,
						       void (*) (tree),
						       const char *));
extern tree check_tag_decl			PROTO((tree));
extern void shadow_tag				PROTO((tree));
extern tree groktypename			PROTO((tree));
extern tree start_decl				PROTO((tree, tree, int, tree, tree));
extern void start_decl_1			PROTO((tree));
extern void cp_finish_decl			PROTO((tree, tree, tree, int));
extern void finish_decl				PROTO((tree, tree, tree));
extern void maybe_inject_for_scope_var          PROTO((tree));
extern void initialize_local_var                PROTO((tree, tree, int));
extern void expand_static_init			PROTO((tree, tree));
extern tree start_handler_parms                 PROTO((tree, tree));
extern int complete_array_type			PROTO((tree, tree, int));
extern tree build_ptrmemfunc_type		PROTO((tree));
/* the grokdeclarator prototype is in decl.h */
extern int parmlist_is_exprlist			PROTO((tree));
extern int copy_args_p				PROTO((tree));
extern int grok_ctor_properties			PROTO((tree, tree));
extern void grok_op_properties			PROTO((tree, int, int));
extern tree xref_tag				PROTO((tree, tree, int));
extern tree xref_tag_from_type			PROTO((tree, tree, int));
extern void xref_basetypes			PROTO((tree, tree, tree, tree));
extern tree start_enum				PROTO((tree));
extern tree finish_enum				PROTO((tree));
extern void build_enumerator			PROTO((tree, tree, tree));
extern int start_function			PROTO((tree, tree, tree, int));
extern void expand_start_early_try_stmts	PROTO((void));
extern void store_parm_decls			PROTO((void));
extern void store_return_init			PROTO((tree));
extern tree finish_function			PROTO((int, int));
extern tree start_method			PROTO((tree, tree, tree));
extern tree finish_method			PROTO((tree));
extern void hack_incomplete_structures		PROTO((tree));
extern tree maybe_build_cleanup_and_delete	PROTO((tree));
extern tree maybe_build_cleanup			PROTO((tree));
extern void cplus_expand_expr_stmt		PROTO((tree));
extern void finish_stmt				PROTO((void));
extern int in_function_p			PROTO((void));
extern void replace_defarg			PROTO((tree, tree));
extern void print_other_binding_stack		PROTO((struct binding_level *));
extern void revert_static_member_fn             PROTO((tree*, tree*, tree*));
extern void fixup_anonymous_aggr                PROTO((tree));
extern int check_static_variable_definition     PROTO((tree, tree));
extern tree compute_array_index_type		PROTO((tree, tree));
extern void push_local_binding                  PROTO((tree, tree, int));
extern int push_class_binding                   PROTO((tree, tree));
extern tree check_default_argument              PROTO((tree, tree));
extern tree push_overloaded_decl		PROTO((tree, int));
extern void clear_identifier_class_values       PROTO((void));
extern void storetags                           PROTO((tree));
extern int vtable_decl_p                        PROTO((tree, void *));
extern int vtype_decl_p                         PROTO((tree, void *));
extern int sigtable_decl_p                      PROTO((tree, void *));
typedef int (*walk_globals_pred)                PROTO((tree, void *));
typedef int (*walk_globals_fn)                  PROTO((tree *, void *));
extern int walk_globals                         PROTO((walk_globals_pred,
						       walk_globals_fn,
						       void *));
typedef int (*walk_namespaces_fn)               PROTO((tree, void *));
extern int walk_namespaces                      PROTO((walk_namespaces_fn,
						       void *));
extern int wrapup_globals_for_namespace         PROTO((tree, void *));
extern tree cp_namespace_decls                  PROTO((tree));
extern tree create_implicit_typedef             PROTO((tree, tree));
extern tree maybe_push_decl                     PROTO((tree));
extern void emit_local_var                      PROTO((tree));
extern tree build_target_expr_with_type         PROTO((tree, tree));
extern void make_rtl_for_local_static           PROTO((tree));

/* in decl2.c */
extern void init_decl2				PROTO((void));
extern int check_java_method			PROTO((tree));
extern int lang_decode_option			PROTO((int, char **));
extern int grok_method_quals			PROTO((tree, tree, tree));
extern void warn_if_unknown_interface		PROTO((tree));
extern void grok_x_components			PROTO((tree));
extern void maybe_retrofit_in_chrg		PROTO((tree));
extern void maybe_make_one_only			PROTO((tree));
extern void grokclassfn				PROTO((tree, tree, enum overload_flags, tree));
extern tree grok_alignof			PROTO((tree));
extern tree grok_array_decl			PROTO((tree, tree));
extern tree delete_sanity			PROTO((tree, tree, int, int));
extern tree check_classfn			PROTO((tree, tree));
extern void check_member_template               PROTO((tree));
extern tree grokfield				PROTO((tree, tree, tree, tree, tree));
extern tree grokbitfield			PROTO((tree, tree, tree));
extern tree groktypefield			PROTO((tree, tree));
extern tree grokoptypename			PROTO((tree, tree));
extern int copy_assignment_arg_p		PROTO((tree, int));
extern void cplus_decl_attributes		PROTO((tree, tree, tree)); 
extern tree constructor_name_full		PROTO((tree));
extern tree constructor_name			PROTO((tree));
extern void setup_vtbl_ptr			PROTO((void));
extern void mark_inline_for_output		PROTO((tree));
extern tree get_temp_name			PROTO((tree, int));
extern void finish_anon_union			PROTO((tree));
extern tree finish_table			PROTO((tree, tree, tree, int));
extern void finish_builtin_type			PROTO((tree, const char *,
						       tree *, int, tree));
extern tree coerce_new_type			PROTO((tree));
extern tree coerce_delete_type			PROTO((tree));
extern void comdat_linkage			PROTO((tree));
extern void import_export_class			PROTO((tree));
extern void import_export_vtable		PROTO((tree, tree, int));
extern void import_export_decl			PROTO((tree));
extern tree build_cleanup			PROTO((tree));
extern void finish_file				PROTO((void));
extern tree reparse_absdcl_as_expr		PROTO((tree, tree));
extern tree reparse_absdcl_as_casts		PROTO((tree, tree));
extern tree build_expr_from_tree		PROTO((tree));
extern tree reparse_decl_as_expr		PROTO((tree, tree));
extern tree finish_decl_parsing			PROTO((tree));
extern tree check_cp_case_value			PROTO((tree));
extern void set_decl_namespace                  PROTO((tree, tree, int));
extern tree current_decl_namespace              PROTO((void));
extern void push_decl_namespace                 PROTO((tree));
extern void pop_decl_namespace                  PROTO((void));
extern void push_scope				PROTO((tree));
extern void pop_scope				PROTO((tree));
extern void do_namespace_alias			PROTO((tree, tree));
extern void do_toplevel_using_decl		PROTO((tree));
extern void do_local_using_decl                 PROTO((tree));
extern tree do_class_using_decl			PROTO((tree));
extern void do_using_directive			PROTO((tree));
extern void check_default_args			PROTO((tree));
extern void mark_used				PROTO((tree));
extern tree handle_class_head			PROTO((tree, tree, tree));
extern tree lookup_arg_dependent                PROTO((tree, tree, tree));
extern void finish_static_data_member_decl      PROTO((tree, tree, tree, int));

/* in parse.y */
extern void cp_parse_init			PROTO((void));

/* in errfn.c */
/* The cp_* functions aren't suitable for ATTRIBUTE_PRINTF. */
extern void cp_error				PVPROTO((const char *, ...));
extern void cp_error_at				PVPROTO((const char *, ...));
extern void cp_warning				PVPROTO((const char *, ...));
extern void cp_warning_at			PVPROTO((const char *, ...));
extern void cp_pedwarn				PVPROTO((const char *, ...));
extern void cp_pedwarn_at			PVPROTO((const char *, ...));
extern void cp_compiler_error			PVPROTO((const char *, ...));
extern void cp_sprintf				PVPROTO((const char *, ...));
extern void cp_deprecated                       PROTO((const char*));

/* in error.c */
extern void init_error				PROTO((void));
extern const char *type_as_string		PROTO((tree, enum tree_string_flags));
extern const char *decl_as_string		PROTO((tree, enum tree_string_flags));
extern const char *expr_as_string		PROTO((tree, enum tree_string_flags));
extern const char *context_as_string            PROTO((tree, enum tree_string_flags));
extern const char *lang_decl_name		PROTO((tree, int));
extern const char *cp_file_of			PROTO((tree));
extern int cp_line_of				PROTO((tree));

/* in except.c */
extern void init_exception_processing		PROTO((void));
extern tree expand_start_catch_block		PROTO((tree));
extern void expand_end_catch_block		PROTO((tree));
extern void expand_builtin_throw		PROTO((void));
extern tree expand_start_eh_spec		PROTO((void));
extern void expand_end_eh_spec		        PROTO((tree, tree));
extern void expand_exception_blocks		PROTO((void));
extern tree start_anon_func			PROTO((void));
extern void end_anon_func			PROTO((void));
extern tree build_throw				PROTO((tree));
extern void mark_all_runtime_matches            PROTO((void));

/* in expr.c */
extern void init_cplus_expand			PROTO((void));
extern void fixup_result_decl			PROTO((tree, struct rtx_def *));
extern int extract_init				PROTO((tree, tree));
extern void do_case				PROTO((tree, tree));
extern tree cplus_expand_constant               PROTO((tree));

/* friend.c */
extern int is_friend				PROTO((tree, tree));
extern void make_friend_class			PROTO((tree, tree));
extern void add_friend                          PROTO((tree, tree));
extern void add_friends                         PROTO((tree, tree, tree));
extern tree do_friend				PROTO((tree, tree, tree, tree, tree, enum overload_flags, tree, int));

/* in init.c */
extern void init_init_processing		PROTO((void));
extern void expand_direct_vtbls_init		PROTO((tree, tree, int, int, tree));
extern tree emit_base_init			PROTO((tree));
extern void check_base_init			PROTO((tree));
extern void expand_member_init			PROTO((tree, tree, tree));
extern tree build_aggr_init			PROTO((tree, tree, int));
extern int is_aggr_typedef			PROTO((tree, int));
extern int is_aggr_type				PROTO((tree, int));
extern tree get_aggr_from_typedef		PROTO((tree, int));
extern tree get_type_value			PROTO((tree));
extern tree build_member_call			PROTO((tree, tree, tree));
extern tree build_offset_ref			PROTO((tree, tree));
extern tree resolve_offset_ref			PROTO((tree));
extern tree decl_constant_value			PROTO((tree));
extern tree build_new				PROTO((tree, tree, tree, int));
extern tree build_new_1				PROTO((tree));
extern tree build_vec_init			PROTO((tree, tree, tree, tree, int));
extern tree build_x_delete			PROTO((tree, int, tree));
extern tree build_delete			PROTO((tree, tree, tree, int, int));
extern tree build_vbase_delete			PROTO((tree, tree));
extern tree build_vec_delete			PROTO((tree, tree, tree, tree, int));
extern tree create_temporary_var                PROTO((tree));
extern void begin_init_stmts                    PROTO((tree *, tree *));
extern tree finish_init_stmts                   PROTO((tree, tree));

/* in input.c */

/* in lex.c */
extern char *file_name_nondirectory		PROTO((const char *));
extern tree make_pointer_declarator		PROTO((tree, tree));
extern tree make_reference_declarator		PROTO((tree, tree));
extern tree make_call_declarator		PROTO((tree, tree, tree, tree));
extern void set_quals_and_spec			PROTO((tree, tree, tree));
extern const char *operator_name_string		PROTO((tree));
extern void lang_init				PROTO((void));
extern void lang_finish				PROTO((void));
#if 0
extern void reinit_lang_specific		PROTO((void));
#endif
extern void reinit_parse_for_function		PROTO((void));
extern void print_parse_statistics		PROTO((void));
extern void extract_interface_info		PROTO((void));
extern void do_pending_inlines			PROTO((void));
extern void process_next_inline			PROTO((struct pending_inline *));
extern struct pending_input *save_pending_input PROTO((void));
extern void restore_pending_input		PROTO((struct pending_input *));
extern void yyungetc				PROTO((int, int));
extern void reinit_parse_for_method		PROTO((int, tree));
extern void reinit_parse_for_block		PROTO((int, struct obstack *));
extern tree cons_up_default_function		PROTO((tree, tree, int));
extern void check_for_missing_semicolon		PROTO((tree));
extern void note_got_semicolon			PROTO((tree));
extern void note_list_got_semicolon		PROTO((tree));
extern void do_pending_lang_change		PROTO((void));
extern int identifier_type			PROTO((tree));
extern void see_typename			PROTO((void));
extern tree do_identifier			PROTO((tree, int, tree));
extern tree do_scoped_id			PROTO((tree, int));
extern tree identifier_typedecl_value		PROTO((tree));
extern int real_yylex				PROTO((void));
extern int is_rid				PROTO((tree));
extern tree build_lang_decl			PROTO((enum tree_code, tree, tree));
extern void retrofit_lang_decl			PROTO((tree));
extern void copy_lang_decl			PROTO((tree));
extern tree cp_make_lang_type			PROTO((enum tree_code));
extern void dump_time_statistics		PROTO((void));
extern void compiler_error			PVPROTO((const char *, ...))
  ATTRIBUTE_PRINTF_1;
extern void yyerror				PROTO((const char *));
extern void clear_inline_text_obstack		PROTO((void));
extern void maybe_snarf_defarg			PROTO((void));
extern tree snarf_defarg			PROTO((void));
extern void add_defarg_fn			PROTO((tree));
extern void do_pending_defargs			PROTO((void));
extern int identifier_type			PROTO((tree));
extern void yyhook				PROTO((int));
extern int cp_type_qual_from_rid                PROTO((tree));

/* in method.c */
extern void init_method				PROTO((void));
extern void do_inline_function_hair		PROTO((tree, tree));
extern char *build_overload_name		PROTO((tree, int, int));
extern tree build_static_name			PROTO((tree, tree));
extern tree build_decl_overload			PROTO((tree, tree, int));
extern tree build_decl_overload_real            PROTO((tree, tree, tree, tree,
						       tree, int)); 
extern void set_mangled_name_for_decl           PROTO((tree));
extern tree build_typename_overload		PROTO((tree));
extern tree build_overload_with_type		PROTO((tree, tree));
extern tree build_destructor_name		PROTO((tree));
extern tree build_opfncall			PROTO((enum tree_code, int, tree, tree, tree));
extern tree hack_identifier			PROTO((tree, tree));
extern tree make_thunk				PROTO((tree, int));
extern void emit_thunk				PROTO((tree));
extern void synthesize_method			PROTO((tree));
extern tree get_id_2				PROTO((const char *, tree));

/* in pt.c */
extern void init_pt                             PROTO ((void));
extern void check_template_shadow		PROTO ((tree));
extern tree innermost_args			PROTO ((tree));
extern tree tsubst				PROTO ((tree, tree, int, tree));
extern tree tsubst_expr				PROTO ((tree, tree, int, tree));
extern tree tsubst_copy				PROTO ((tree, tree, int, tree));
extern void maybe_begin_member_template_processing PROTO((tree));
extern void maybe_end_member_template_processing PROTO((void));
extern tree finish_member_template_decl         PROTO((tree));
extern void begin_template_parm_list		PROTO((void));
extern void begin_specialization                PROTO((void));
extern void reset_specialization                PROTO((void));
extern void end_specialization                  PROTO((void));
extern void begin_explicit_instantiation        PROTO((void));
extern void end_explicit_instantiation          PROTO((void));
extern tree check_explicit_specialization       PROTO((tree, tree, int, int));
extern tree process_template_parm		PROTO((tree, tree));
extern tree end_template_parm_list		PROTO((tree));
extern void end_template_decl			PROTO((void));
extern tree current_template_args		PROTO((void));
extern tree push_template_decl			PROTO((tree));
extern tree push_template_decl_real             PROTO((tree, int));
extern void redeclare_class_template            PROTO((tree, tree));
extern tree lookup_template_class		PROTO((tree, tree, tree, tree, int));
extern tree lookup_template_function            PROTO((tree, tree));
extern int uses_template_parms			PROTO((tree));
extern tree instantiate_class_template		PROTO((tree));
extern tree instantiate_template		PROTO((tree, tree));
extern void overload_template_name		PROTO((tree));
extern int fn_type_unification                  PROTO((tree, tree, tree, tree, tree, unification_kind_t));
struct tinst_level *tinst_for_decl		PROTO((void));
extern void mark_decl_instantiated		PROTO((tree, int));
extern int more_specialized			PROTO((tree, tree, tree));
extern void mark_class_instantiated		PROTO((tree, int));
extern void do_decl_instantiation		PROTO((tree, tree, tree));
extern void do_type_instantiation		PROTO((tree, tree));
extern tree instantiate_decl			PROTO((tree));
extern tree get_bindings			PROTO((tree, tree, tree));
extern void add_tree				PROTO((tree));
extern void add_maybe_template			PROTO((tree, tree));
extern void pop_tinst_level			PROTO((void));
extern int more_specialized_class		PROTO((tree, tree));
extern int is_member_template                   PROTO((tree));
extern int template_parms_equal                 PROTO((tree, tree));
extern int comp_template_parms                  PROTO((tree, tree));
extern int template_class_depth                 PROTO((tree));
extern int is_specialization_of                 PROTO((tree, tree));
extern int comp_template_args                   PROTO((tree, tree));
extern void maybe_process_partial_specialization PROTO((tree));
extern void maybe_check_template_type           PROTO((tree));
extern tree most_specialized_instantiation      PROTO((tree, tree));
extern void print_candidates                    PROTO((tree));
extern int instantiate_pending_templates        PROTO((void));
extern tree tsubst_default_argument             PROTO((tree, tree, tree));
extern tree most_general_template		PROTO((tree));

extern int processing_template_parmlist;

/* in repo.c */
extern void repo_template_used			PROTO((tree));
extern void repo_template_instantiated		PROTO((tree, int));
extern void init_repo				PROTO((const char *));
extern void finish_repo				PROTO((void));

/* in rtti.c */
extern void init_rtti_processing		PROTO((void));
extern tree get_tinfo_fn_dynamic		PROTO((tree));
extern tree build_typeid			PROTO((tree));
extern tree build_x_typeid			PROTO((tree));
extern tree get_tinfo_fn			PROTO((tree));
extern tree get_tinfo_fn_unused			PROTO((tree));
extern tree get_typeid				PROTO((tree));
extern tree get_typeid_1			PROTO((tree));
extern tree build_dynamic_cast			PROTO((tree, tree));
extern void synthesize_tinfo_fn			PROTO((tree));

/* in search.c */
extern int types_overlap_p			PROTO((tree, tree));
extern tree get_vbase				PROTO((tree, tree));
extern tree get_binfo				PROTO((tree, tree, int));
extern int get_base_distance			PROTO((tree, tree, int, tree *));
extern tree get_dynamic_cast_base_type          PROTO((tree, tree));
extern int accessible_p                         PROTO((tree, tree));
extern tree lookup_field			PROTO((tree, tree, int, int));
extern int lookup_fnfields_1                    PROTO((tree, tree));
extern tree lookup_fnfields			PROTO((tree, tree, int));
extern tree lookup_member			PROTO((tree, tree, int, int));
extern tree lookup_nested_tag			PROTO((tree, tree));
extern tree get_matching_virtual		PROTO((tree, tree, int));
extern tree get_abstract_virtuals		PROTO((tree));
extern tree init_vbase_pointers			PROTO((tree, tree));
extern void expand_indirect_vtbls_init		PROTO((tree, tree, tree));
extern void clear_search_slots			PROTO((tree));
extern tree get_vbase_types			PROTO((tree));
extern void maybe_suppress_debug_info		PROTO((tree));
extern void note_debug_info_needed		PROTO((tree));
extern void push_class_decls			PROTO((tree));
extern void pop_class_decls			PROTO((void));
extern void unuse_fields			PROTO((tree));
extern void print_search_statistics		PROTO((void));
extern void init_search_processing		PROTO((void));
extern void reinit_search_statistics		PROTO((void));
extern tree current_scope			PROTO((void));
extern int at_function_scope_p                  PROTO((void));
extern tree lookup_conversions			PROTO((tree));
extern tree binfo_for_vtable			PROTO((tree));
extern int  binfo_from_vbase			PROTO((tree));
extern tree dfs_walk                            PROTO((tree, 
						       tree (*)(tree, void *),
						       tree (*) (tree, void *),
						       void *));
extern tree dfs_unmark                          PROTO((tree, void *));
extern tree markedp                             PROTO((tree, void *));

/* in semantics.c */
extern void finish_expr_stmt                    PROTO((tree));
extern tree begin_if_stmt                       PROTO((void));
extern void finish_if_stmt_cond                 PROTO((tree, tree));
extern tree finish_then_clause                  PROTO((tree));
extern void begin_else_clause                   PROTO((void));
extern void finish_else_clause                  PROTO((tree));
extern void finish_if_stmt                      PROTO((void));
extern tree begin_while_stmt                    PROTO((void));
extern void finish_while_stmt_cond              PROTO((tree, tree));
extern void finish_while_stmt                   PROTO((tree));
extern tree begin_do_stmt                       PROTO((void));
extern void finish_do_body                      PROTO((tree));
extern void finish_do_stmt                      PROTO((tree, tree));
extern void finish_return_stmt                  PROTO((tree));
extern tree begin_for_stmt                      PROTO((void));
extern void finish_for_init_stmt                PROTO((tree));
extern void finish_for_cond                     PROTO((tree, tree));
extern void finish_for_expr                     PROTO((tree, tree));
extern void finish_for_stmt                     PROTO((tree, tree));
extern void finish_break_stmt                   PROTO((void));
extern void finish_continue_stmt                PROTO((void));
extern tree begin_switch_stmt                   PROTO((void));
extern void finish_switch_cond                  PROTO((tree, tree));
extern void finish_switch_stmt                  PROTO((tree, tree));
extern void finish_case_label                   PROTO((tree, tree));
extern void finish_goto_stmt                    PROTO((tree));
extern tree begin_try_block                     PROTO((void));
extern void finish_try_block                    PROTO((tree));
extern void finish_handler_sequence             PROTO((tree));
extern tree begin_function_try_block            PROTO((void));
extern void finish_function_try_block           PROTO((tree));
extern void finish_function_handler_sequence    PROTO((tree));
extern void finish_cleanup_try_block            PROTO((tree));
extern tree begin_handler                       PROTO((void));
extern tree finish_handler_parms                PROTO((tree, tree));
extern void begin_catch_block                   PROTO((tree));
extern void finish_handler                      PROTO((tree, tree));
extern void finish_cleanup                      PROTO((tree, tree));
extern tree begin_compound_stmt                 PROTO((int));
extern tree finish_compound_stmt                PROTO((int, tree));
extern void finish_asm_stmt                     PROTO((tree, tree, tree, tree, tree));
extern void finish_label_stmt                   PROTO((tree));
extern void finish_label_decl                   PROTO((tree));
extern void finish_subobject                    PROTO((tree));
extern tree finish_parenthesized_expr           PROTO((tree));
extern tree begin_stmt_expr                     PROTO((void));
extern tree finish_stmt_expr                    PROTO((tree));
extern tree finish_call_expr                    PROTO((tree, tree, int));
extern tree finish_increment_expr               PROTO((tree, enum tree_code));
extern tree finish_this_expr                    PROTO((void));
extern tree finish_object_call_expr             PROTO((tree, tree, tree));
extern tree finish_qualified_object_call_expr   PROTO((tree, tree, tree));
extern tree finish_pseudo_destructor_call_expr  PROTO((tree, tree, tree));
extern tree finish_qualified_call_expr          PROTO ((tree, tree));
extern tree finish_label_address_expr           PROTO((tree));
extern tree finish_unary_op_expr                PROTO((enum tree_code, tree));
extern tree finish_id_expr                      PROTO((tree));
extern int begin_function_definition            PROTO((tree, tree));
extern tree begin_constructor_declarator        PROTO((tree, tree));
extern tree finish_declarator                   PROTO((tree, tree, tree, tree, int));
extern void finish_translation_unit             PROTO((void));
extern tree finish_template_type_parm           PROTO((tree, tree));
extern tree finish_template_template_parm       PROTO((tree, tree));
extern tree finish_parmlist                     PROTO((tree, int));
extern tree begin_class_definition              PROTO((tree));
extern tree finish_class_definition             PROTO((tree, tree, int, int));
extern void finish_default_args                 PROTO((void));
extern void begin_inline_definitions            PROTO((void));
extern void finish_inline_definitions           PROTO((void));
extern tree finish_member_class_template        PROTO((tree));
extern void finish_template_decl                PROTO((tree));
extern tree finish_template_type                PROTO((tree, tree, int));
extern void enter_scope_of                      PROTO((tree));
extern tree finish_base_specifier               PROTO((tree, tree));
extern void finish_member_declaration           PROTO((tree));
extern void check_multiple_declarators          PROTO((void));
extern tree finish_typeof			PROTO((tree));
extern void add_decl_stmt                       PROTO((tree));
extern void finish_decl_cleanup                 PROTO((tree, tree));
extern void finish_named_return_value           PROTO((tree, tree));
extern tree expand_stmt                         PROTO((tree));
extern void expand_body                         PROTO((tree));
extern void begin_stmt_tree                     PROTO((tree *));
extern void finish_stmt_tree                    PROTO((tree *));
extern void prep_stmt                           PROTO((tree));
extern void add_scope_stmt                      PROTO((int, int));
extern void do_pushlevel                        PROTO((void));
extern tree do_poplevel                         PROTO((void));
/* Non-zero if we are presently building a statement tree, rather
   than expanding each statement as we encounter it.  */
#define building_stmt_tree() (last_tree != NULL_TREE)

/* in spew.c */
extern void init_spew				PROTO((void));
extern int peekyylex				PROTO((void));
extern int yylex				PROTO((void));
extern tree arbitrate_lookup			PROTO((tree, tree, tree));

/* in tree.c */
extern void init_tree			        PROTO((void));
extern void cplus_unsave_expr_now               PROTO((tree));
extern int pod_type_p				PROTO((tree));
extern void unshare_base_binfos			PROTO((tree));
extern int member_p				PROTO((tree));
extern cp_lvalue_kind real_lvalue_p		PROTO((tree));
extern tree build_min				PVPROTO((enum tree_code, tree, ...));
extern tree build_min_nt			PVPROTO((enum tree_code, ...));
extern tree min_tree_cons			PROTO((tree, tree, tree));
extern int lvalue_p				PROTO((tree));
extern int lvalue_or_else			PROTO((tree, const char *));
extern tree build_cplus_new			PROTO((tree, tree));
extern tree get_target_expr			PROTO((tree));
extern tree break_out_cleanups			PROTO((tree));
extern tree break_out_calls			PROTO((tree));
extern tree build_cplus_method_type		PROTO((tree, tree, tree));
extern tree build_cplus_staticfn_type		PROTO((tree, tree, tree));
extern tree build_cplus_array_type		PROTO((tree, tree));
extern int layout_basetypes			PROTO((tree, int));
extern tree build_vbase_pointer_fields		PROTO((tree));
extern tree build_base_fields			PROTO((tree));
extern tree hash_tree_cons			PROTO((tree, tree, tree));
extern tree hash_tree_chain			PROTO((tree, tree));
extern tree hash_chainon			PROTO((tree, tree));
extern tree make_binfo				PROTO((tree, tree, tree, tree));
extern tree binfo_value				PROTO((tree, tree));
extern tree reverse_path			PROTO((tree));
extern int count_functions			PROTO((tree));
extern int is_overloaded_fn			PROTO((tree));
extern tree get_first_fn			PROTO((tree));
extern int bound_pmf_p				PROTO((tree));
extern tree ovl_cons                            PROTO((tree, tree));
extern tree scratch_ovl_cons                    PROTO((tree, tree));
extern int ovl_member                           PROTO((tree, tree));
extern tree build_overload                      PROTO((tree, tree));
extern tree fnaddr_from_vtable_entry		PROTO((tree));
extern tree function_arg_chain			PROTO((tree));
extern int promotes_to_aggr_type		PROTO((tree, enum tree_code));
extern int is_aggr_type_2			PROTO((tree, tree));
extern const char *lang_printable_name		PROTO((tree, int));
extern tree build_exception_variant		PROTO((tree, tree));
extern tree copy_template_template_parm		PROTO((tree));
extern void print_lang_statistics		PROTO((void));
extern void __eprintf
	PROTO((const char *, const char *, unsigned, const char *));
extern tree array_type_nelts_total		PROTO((tree));
extern tree array_type_nelts_top		PROTO((tree));
extern tree break_out_target_exprs		PROTO((tree));
extern tree get_type_decl			PROTO((tree));
extern tree vec_binfo_member			PROTO((tree, tree));
extern tree hack_decl_function_context 		PROTO((tree));
extern tree decl_namespace_context 		PROTO((tree));
extern tree lvalue_type				PROTO((tree));
extern tree error_type				PROTO((tree));
extern tree build_ptr_wrapper			PROTO((void *));
extern tree build_expr_ptr_wrapper		PROTO((void *));
extern tree build_int_wrapper			PROTO((int));
extern tree build_srcloc_here			PROTO((void));
extern int varargs_function_p			PROTO((tree));
extern int really_overloaded_fn			PROTO((tree));
extern int cp_tree_equal			PROTO((tree, tree));
extern int can_free				PROTO((struct obstack *, tree));
extern tree no_linkage_check			PROTO((tree));
extern void debug_binfo				PROTO((tree));
extern tree build_dummy_object			PROTO((tree));
extern tree maybe_dummy_object			PROTO((tree, tree *));
extern int is_dummy_object			PROTO((tree));
typedef tree (*walk_tree_fn)                    PROTO((tree *, int *, void *));
extern tree walk_tree                           PROTO((tree *, walk_tree_fn, void *));
extern int cp_valid_lang_attribute		PROTO((tree, tree, tree, tree));
extern tree make_ptrmem_cst                     PROTO((tree, tree));
extern tree cp_build_qualified_type_real        PROTO((tree, int, int));
#define cp_build_qualified_type(TYPE, QUALS) \
  cp_build_qualified_type_real ((TYPE), (QUALS), /*complain=*/1)

#define scratchalloc expralloc
#define build_scratch_list build_expr_list

/* in typeck.c */
extern int string_conv_p			PROTO((tree, tree, int));
extern tree condition_conversion		PROTO((tree));
extern tree target_type				PROTO((tree));
extern tree require_complete_type		PROTO((tree));
extern tree complete_type			PROTO((tree));
extern tree complete_type_or_else               PROTO((tree, tree));
extern int type_unknown_p			PROTO((tree));
extern int fntype_p				PROTO((tree));
extern tree commonparms				PROTO((tree, tree));
extern tree original_type			PROTO((tree));
extern tree common_type				PROTO((tree, tree));
extern int comp_except_specs			PROTO((tree, tree, int));
extern int comptypes				PROTO((tree, tree, int));
extern int comp_target_types			PROTO((tree, tree, int));
extern int compparms				PROTO((tree, tree));
extern int comp_target_types			PROTO((tree, tree, int));
extern int comp_cv_qualification                PROTO((tree, tree));
extern int comp_cv_qual_signature               PROTO((tree, tree));
extern tree unsigned_type			PROTO((tree));
extern tree signed_type				PROTO((tree));
extern tree signed_or_unsigned_type		PROTO((int, tree));
extern tree expr_sizeof				PROTO((tree));
extern tree c_sizeof				PROTO((tree));
extern tree c_sizeof_nowarn			PROTO((tree));
extern tree c_alignof				PROTO((tree));
extern tree inline_conversion			PROTO((tree));
extern tree decay_conversion			PROTO((tree));
extern tree default_conversion			PROTO((tree));
extern tree build_object_ref			PROTO((tree, tree, tree));
extern tree build_component_ref_1		PROTO((tree, tree, int));
extern tree build_component_ref			PROTO((tree, tree, tree, int));
extern tree build_x_component_ref		PROTO((tree, tree, tree, int));
extern tree build_x_indirect_ref		PROTO((tree, const char *));
extern tree build_indirect_ref			PROTO((tree, const char *));
extern tree build_array_ref			PROTO((tree, tree));
extern tree build_x_function_call		PROTO((tree, tree, tree));
extern tree get_member_function_from_ptrfunc	PROTO((tree *, tree));
extern tree build_function_call_real		PROTO((tree, tree, int, int));
extern tree build_function_call			PROTO((tree, tree));
extern tree build_function_call_maybe		PROTO((tree, tree));
extern tree convert_arguments			PROTO((tree, tree, tree, int));
extern tree build_x_binary_op			PROTO((enum tree_code, tree, tree));
extern tree build_binary_op			PROTO((enum tree_code, tree, tree));
extern tree build_binary_op_nodefault		PROTO((enum tree_code, tree, tree, enum tree_code));
extern tree build_x_unary_op			PROTO((enum tree_code, tree));
extern tree build_unary_op			PROTO((enum tree_code, tree, int));
extern tree unary_complex_lvalue		PROTO((enum tree_code, tree));
extern int mark_addressable			PROTO((tree));
extern tree build_x_conditional_expr		PROTO((tree, tree, tree));
extern tree build_conditional_expr		PROTO((tree, tree, tree));
extern tree build_x_compound_expr		PROTO((tree));
extern tree build_compound_expr			PROTO((tree));
extern tree build_static_cast			PROTO((tree, tree));
extern tree build_reinterpret_cast		PROTO((tree, tree));
extern tree build_const_cast			PROTO((tree, tree));
extern tree build_c_cast			PROTO((tree, tree));
extern tree build_x_modify_expr			PROTO((tree, enum tree_code, tree));
extern tree build_modify_expr			PROTO((tree, enum tree_code, tree));
extern tree convert_for_initialization		PROTO((tree, tree, tree, int, const char *, tree, int));
extern void c_expand_asm_operands		PROTO((tree, tree, tree, tree, int, char *, int));
extern void c_expand_return			PROTO((tree));
extern tree c_expand_start_case			PROTO((tree));
extern int comp_ptr_ttypes			PROTO((tree, tree));
extern int ptr_reasonably_similar		PROTO((tree, tree));
extern tree build_ptrmemfunc			PROTO((tree, tree, int));
extern tree strip_array_types                   PROTO((tree));
extern int cp_type_quals                        PROTO((tree));
extern int cp_has_mutable_p                     PROTO((tree));
extern int at_least_as_qualified_p              PROTO((tree, tree));
extern int more_qualified_p                     PROTO((tree, tree));
extern tree build_ptrmemfunc1                   PROTO((tree, tree, tree, tree, tree));
extern void expand_ptrmemfunc_cst               PROTO((tree, tree *, tree *, tree *, tree *));
extern tree delta2_from_ptrmemfunc              PROTO((tree));
extern tree pfn_from_ptrmemfunc                 PROTO((tree));
extern tree type_after_usual_arithmetic_conversions PROTO((tree, tree));
extern tree composite_pointer_type              PROTO((tree, tree, tree, tree,
						       const char*));
extern tree check_return_expr                   PROTO((tree));

/* in typeck2.c */
extern tree error_not_base_type			PROTO((tree, tree));
extern tree binfo_or_else			PROTO((tree, tree));
extern void readonly_error			PROTO((tree, const char *, int));
extern int abstract_virtuals_error		PROTO((tree, tree));
extern void incomplete_type_error		PROTO((tree, tree));
extern void my_friendly_abort			PROTO((int))
  ATTRIBUTE_NORETURN;
extern void my_friendly_assert			PROTO((int, int));
extern tree store_init_value			PROTO((tree, tree));
extern tree digest_init				PROTO((tree, tree, tree *));
extern tree build_scoped_ref			PROTO((tree, tree));
extern tree build_x_arrow			PROTO((tree));
extern tree build_m_component_ref		PROTO((tree, tree));
extern tree build_functional_cast		PROTO((tree, tree));
extern char *enum_name_string			PROTO((tree, tree));
extern void report_case_error			PROTO((int, tree, tree, tree));
extern void check_for_new_type			PROTO((const char *, flagged_type_tree));
extern tree add_exception_specifier             PROTO((tree, tree, int));

/* in xref.c */
extern void GNU_xref_begin			PROTO((const char *));
extern void GNU_xref_end			PROTO((int));
extern void GNU_xref_file			PROTO((const char *));
extern void GNU_xref_start_scope		PROTO((HOST_WIDE_INT));
extern void GNU_xref_end_scope			PROTO((HOST_WIDE_INT, HOST_WIDE_INT, int, int));
extern void GNU_xref_ref			PROTO((tree, const char *));
extern void GNU_xref_decl			PROTO((tree, tree));
extern void GNU_xref_call			PROTO((tree, const char *));
extern void GNU_xref_function			PROTO((tree, tree));
extern void GNU_xref_assign			PROTO((tree));
extern void GNU_xref_hier			PROTO((tree, tree, int, int, int));
extern void GNU_xref_member			PROTO((tree, tree));

/* in dump.c */
extern void dump_node_to_file                   PROTO ((tree, const char *));

/* -- end of C++ */

#endif /* not _CP_TREE_H */
