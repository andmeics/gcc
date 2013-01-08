/* Gimple folding definitions.

   Copyright 2011, 2012 Free Software Foundation, Inc.
   Contributed by Richard Guenther <rguenther@suse.de>

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

#ifndef GCC_GIMPLE_FOLD_H
#define GCC_GIMPLE_FOLD_H

tree fold_const_aggregate_ref_1 (tree, tree (*) (tree));
tree fold_const_aggregate_ref (tree);

tree gimple_fold_stmt_to_constant_1 (gimple, tree (*) (tree));
tree gimple_fold_stmt_to_constant (gimple, tree (*) (tree));

#endif  /* GCC_GIMPLE_FOLD_H */
