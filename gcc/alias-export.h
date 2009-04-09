/* Export of alias information to RTL.  
   Copyright (C) 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_ALIAS_EXPORT_H
#define GCC_ALIAS_EXPORT_H

#include "tree-ssa-alias.h"

extern void record_stmt_substitution (gimple, gimple, tree, tree);
extern void record_stmt_pta_info (gimple, tree, tree);
extern tree unshare_and_record_pta_info (tree);
extern void record_escaped_solution (struct pt_solution *);
extern void record_stack_var_partition_for (tree, tree);
extern void record_addressable_bases (tree);
extern void rewrite_mem_exprs (gimple, rtx);
extern void set_current_expand_info (gimple, tree);
extern void release_temporary_export_maps (void);
extern struct ptr_info_def * get_exported_ptr_info (tree);

extern bool alias_export_may_alias_p (tree, tree, const_rtx, const_rtx);
extern bool alias_export_test (tree, tree);

extern bool ddg_export_may_alias_p (tree, tree, int);
extern void replace_var_in_datarefs (tree, tree);


#endif /* GCC_ALIAS_EXPORT_H */
