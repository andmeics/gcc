/* Frv prototypes.
   Copyright (C) 1999, 2000, 2001, 2003, 2004 Free Software Foundation, Inc.
   Contributed by Red Hat, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Define the information needed to generate branch and scc insns.  This is
   stored from the compare operation.  Note that we can't use "rtx" here
   since it hasn't been defined!  */

/* Define global data defined in frv.c.  */
extern const char *frv_branch_cost_string;	/* -mbranch-cost option */
extern int frv_branch_cost_int;			/* value of -mbranch_cost */

extern const char *frv_cpu_string;		/* -mcpu= option */

extern const char *frv_condexec_insns_str;	/* -mcond-exec-insns= option */
extern int frv_condexec_insns;			/* value of -mcond-exec-insns */

extern const char *frv_condexec_temps_str;	/* -mcond-exec-temps= option */
extern int frv_condexec_temps;			/* value of -mcond-exec-temps */

extern const char *frv_sched_lookahead_str;	/* -msched-lookahead= option */
extern int frv_sched_lookahead;			/* value -msched-lookahead= */

/* CPU type.  This must be identical to the cpu enumeration in frv.md.  */
typedef enum frv_cpu
{
  FRV_CPU_GENERIC,
  FRV_CPU_FR500,
  FRV_CPU_FR400,
  FRV_CPU_FR300,
  FRV_CPU_SIMPLE,
  FRV_CPU_TOMCAT
} frv_cpu_t;

extern frv_cpu_t frv_cpu_type;			/* value of -mcpu= */

/* Define functions defined in frv.c */
extern void frv_expand_prologue			(void);
extern void frv_expand_epilogue			(int);
extern void frv_override_options		(void);
extern void frv_optimization_options		(int, int);
extern void frv_conditional_register_usage	(void);
extern frv_stack_t *frv_stack_info		(void);
extern void frv_debug_stack			(frv_stack_t *);
extern int frv_frame_pointer_required		(void);
extern int frv_initial_elimination_offset	(int, int);

#ifdef RTX_CODE
extern int frv_legitimate_address_p 		(enum machine_mode, rtx,
						 int, int);
extern rtx frv_legitimize_address		(rtx, rtx, enum machine_mode);

#ifdef TREE_CODE
extern void frv_init_cumulative_args		(CUMULATIVE_ARGS *, tree,
						 rtx, tree, int);

extern int frv_function_arg_boundary		(enum machine_mode, tree);
extern rtx frv_function_arg			(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int, int);

extern void frv_function_arg_advance		(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int);

extern int frv_function_arg_partial_nregs	(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int);

extern int frv_function_arg_pass_by_reference	(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int);

extern int frv_function_arg_callee_copies	(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int);

extern int frv_function_arg_keep_as_reference	(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int);

extern void frv_setup_incoming_varargs		(CUMULATIVE_ARGS *,
						 enum machine_mode,
						 tree, int *, int);

extern void frv_expand_builtin_va_start		(tree, rtx);
extern rtx frv_expand_builtin_va_arg		(tree, tree);
#endif /* TREE_CODE */

extern int frv_expand_block_move		(rtx *);
extern int frv_expand_block_clear		(rtx *);
extern rtx frv_dynamic_chain_address		(rtx);
extern rtx frv_return_addr_rtx			(int, rtx);
extern rtx frv_index_memory			(rtx, enum machine_mode, int);
extern const char *frv_asm_output_opcode
				 	(FILE *, const char *);
extern void frv_final_prescan_insn	(rtx, rtx *, int);
extern void frv_print_operand		(FILE *, rtx, int);
extern void frv_print_operand_address	(FILE *, rtx);
extern int frv_emit_movsi		(rtx, rtx);
extern const char *output_move_single	(rtx *, rtx);
extern const char *output_move_double	(rtx *, rtx);
extern const char *output_condmove_single
					(rtx *, rtx);
extern int frv_emit_cond_branch		(enum rtx_code, rtx);
extern int frv_emit_scc			(enum rtx_code, rtx);
extern rtx frv_split_scc		(rtx, rtx, rtx, rtx, HOST_WIDE_INT);
extern int frv_emit_cond_move		(rtx, rtx, rtx, rtx);
extern rtx frv_split_cond_move		(rtx *);
extern rtx frv_split_minmax		(rtx *);
extern rtx frv_split_abs		(rtx *);
extern void frv_split_double_load	(rtx, rtx);
extern void frv_split_double_store	(rtx, rtx);
#ifdef BLOCK_HEAD
extern void frv_ifcvt_init_extra_fields	(ce_if_block_t *);
extern void frv_ifcvt_modify_tests	(ce_if_block_t *, rtx *, rtx *);
extern void frv_ifcvt_modify_multiple_tests
					(ce_if_block_t *, basic_block,
					 rtx *, rtx *);
extern rtx frv_ifcvt_modify_insn	(ce_if_block_t *, rtx, rtx);
extern void frv_ifcvt_modify_final	(ce_if_block_t *);
extern void frv_ifcvt_modify_cancel	(ce_if_block_t *);
#endif
extern int frv_trampoline_size		(void);
extern void frv_initialize_trampoline	(rtx, rtx, rtx);
extern enum reg_class frv_secondary_reload_class
					(enum reg_class class,
					 enum machine_mode mode,
					 rtx x, int);
extern int frv_class_likely_spilled_p	(enum reg_class class);
extern int frv_hard_regno_mode_ok	(int, enum machine_mode);
extern int frv_hard_regno_nregs		(int, enum machine_mode);
extern int frv_class_max_nregs		(enum reg_class class,
					 enum machine_mode mode);
extern int frv_legitimate_constant_p	(rtx);
#endif	/* RTX_CODE */

extern int direct_return_p		(void);
extern int frv_register_move_cost	(enum reg_class, enum reg_class);

#ifdef TREE_CODE
extern int frv_adjust_field_align	(tree, int);
#endif

extern void fixup_section		(void);
extern void sdata_section		(void);
extern void sbss_section		(void);
extern void data_section		(void);

#ifdef RTX_CODE
extern int integer_register_operand	(rtx, enum machine_mode);
extern int frv_load_operand		(rtx, enum machine_mode);
extern int gpr_or_fpr_operand		(rtx, enum machine_mode);
extern int gpr_no_subreg_operand	(rtx, enum machine_mode);
extern int gpr_or_int6_operand		(rtx, enum machine_mode);
extern int fpr_or_int6_operand		(rtx, enum machine_mode);
extern int gpr_or_int_operand		(rtx, enum machine_mode);
extern int gpr_or_int12_operand		(rtx, enum machine_mode);
extern int gpr_fpr_or_int12_operand	(rtx, enum machine_mode);
extern int gpr_or_int10_operand		(rtx, enum machine_mode);
extern int move_source_operand		(rtx, enum machine_mode);
extern int move_destination_operand	(rtx, enum machine_mode);
extern int condexec_source_operand	(rtx, enum machine_mode);
extern int condexec_dest_operand	(rtx, enum machine_mode);
extern int lr_operand			(rtx, enum machine_mode);
extern int gpr_or_memory_operand	(rtx, enum machine_mode);
extern int fpr_or_memory_operand	(rtx, enum machine_mode);
extern int reg_or_0_operand		(rtx, enum machine_mode);
extern int fcc_operand			(rtx, enum machine_mode);
extern int icc_operand			(rtx, enum machine_mode);
extern int cc_operand			(rtx, enum machine_mode);
extern int fcr_operand			(rtx, enum machine_mode);
extern int icr_operand			(rtx, enum machine_mode);
extern int cr_operand			(rtx, enum machine_mode);
extern int call_operand			(rtx, enum machine_mode);
extern int fpr_operand			(rtx, enum machine_mode);
extern int even_reg_operand		(rtx, enum machine_mode);
extern int odd_reg_operand		(rtx, enum machine_mode);
extern int even_gpr_operand		(rtx, enum machine_mode);
extern int odd_gpr_operand		(rtx, enum machine_mode);
extern int quad_fpr_operand		(rtx, enum machine_mode);
extern int even_fpr_operand		(rtx, enum machine_mode);
extern int odd_fpr_operand		(rtx, enum machine_mode);
extern int dbl_memory_one_insn_operand	(rtx, enum machine_mode);
extern int dbl_memory_two_insn_operand	(rtx, enum machine_mode);
extern int int12_operand		(rtx, enum machine_mode);
extern int int6_operand			(rtx, enum machine_mode);
extern int int5_operand			(rtx, enum machine_mode);
extern int uint5_operand		(rtx, enum machine_mode);
extern int uint4_operand		(rtx, enum machine_mode);
extern int uint1_operand		(rtx, enum machine_mode);
extern int int_2word_operand		(rtx, enum machine_mode);
extern int pic_register_operand		(rtx, enum machine_mode);
extern int pic_symbolic_operand		(rtx, enum machine_mode);
extern int small_data_register_operand	(rtx, enum machine_mode);
extern int small_data_symbolic_operand	(rtx, enum machine_mode);
extern int upper_int16_operand		(rtx, enum machine_mode);
extern int uint16_operand		(rtx, enum machine_mode);
extern int relational_operator		(rtx, enum machine_mode);
extern int signed_relational_operator	(rtx, enum machine_mode);
extern int unsigned_relational_operator	(rtx, enum machine_mode);
extern int float_relational_operator	(rtx, enum machine_mode);
extern int ccr_eqne_operator		(rtx, enum machine_mode);
extern int minmax_operator		(rtx, enum machine_mode);
extern int condexec_si_binary_operator	(rtx, enum machine_mode);
extern int condexec_si_media_operator	(rtx, enum machine_mode);
extern int condexec_si_divide_operator	(rtx, enum machine_mode);
extern int condexec_si_unary_operator	(rtx, enum machine_mode);
extern int condexec_sf_conv_operator	(rtx, enum machine_mode);
extern int condexec_sf_add_operator	(rtx, enum machine_mode);
extern int condexec_memory_operand	(rtx, enum machine_mode);
extern int intop_compare_operator	(rtx, enum machine_mode);
extern int condexec_intop_cmp_operator	(rtx, enum machine_mode);
extern int acc_operand			(rtx, enum machine_mode);
extern int even_acc_operand		(rtx, enum machine_mode);
extern int quad_acc_operand		(rtx, enum machine_mode);
extern int accg_operand			(rtx, enum machine_mode);
extern rtx frv_matching_accg_for_acc	(rtx);
#endif

