/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-dom3-details -w" } */

/* There should be a reference to usecount that turn into
   constants.  */
/* { dg-final { scan-tree-dump-times "Replaced .usecount_\[0-9\]+. with constant .1." 1 "dom3"} } */

/* And an assignment using usecount ought to fold down to constants.  */
/* { dg-final { scan-tree-dump-times "Folded to: usecount_\[0-9\]+ = 2;" 1 "dom3"} } */

/* The arithmetic using usecount should be gone, except for the one in the
   details debugging.  */
/* { dg-final { scan-tree-dump-times "usecount_\[0-9\]+ = usecount_\[0-9\]+ . 1;" 1 "dom3"} } */

typedef union tree_node *tree;
typedef union gimple_statement_d *gimple;
extern const int tree_code_type[];
union tree_node
{
  int code:16;
};
typedef struct immediate_use_iterator_d
{
}
imm_use_iterator;
void
insert_debug_temp_for_var_def (gimple stmt)
{
  gimple def_stmt = ((void *) 0);
  int usecount = 0;
  tree value = ((void *) 0);
  for (; arf ();)
    {
      if (!gimple_debug_bind_p (stmt))
        continue;
      if (usecount++)
        break;
      unsigned char no_value = 0;
      if (!gimple_bb (def_stmt))
        no_value = 1;
      if (!no_value)
        value = gimple_assign_rhs_to_tree ();
    }
  if (value)
    {
      if ((tree_code_type[(int) (((value)->code))] == 42)
          || (usecount == 1 && (is_gimple_min_invariant (value))))
        value = unshare_expr (value);
    }
}


