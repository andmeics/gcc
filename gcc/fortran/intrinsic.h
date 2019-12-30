/* Header file for intrinsics check, resolve and simplify function
   prototypes.
   Copyright (C) 2000-2019 Free Software Foundation, Inc.
   Contributed by Andy Vaught & Katherine Holcomb

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

/* Expression returned when simplification fails.  */

extern gfc_expr gfc_bad_expr;


/* Check functions.  */
bool gfc_check_a_ikind (gfc_expr *, gfc_expr *);
bool gfc_check_a_xkind (gfc_expr *, gfc_expr *);
bool gfc_check_a_p (gfc_expr *, gfc_expr *);
bool gfc_check_x_yd (gfc_expr *, gfc_expr *);

bool gfc_check_abs (gfc_expr *);
bool gfc_check_access_func (gfc_expr *, gfc_expr *);
bool gfc_check_achar (gfc_expr *, gfc_expr *);
bool gfc_check_all_any (gfc_expr *, gfc_expr *);
bool gfc_check_allocated (gfc_expr *);
bool gfc_check_associated (gfc_expr *, gfc_expr *);
bool gfc_check_atan_2 (gfc_expr *, gfc_expr *);
bool gfc_check_atan2 (gfc_expr *, gfc_expr *);
bool gfc_check_atomic_cas (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			   gfc_expr *);
bool gfc_check_atomic_def (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_atomic_fetch_op (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_atomic_op (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_atomic_ref (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_besn (gfc_expr *, gfc_expr *);
bool gfc_check_bessel_n2 (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_bge_bgt_ble_blt (gfc_expr *, gfc_expr *);
bool gfc_check_bitfcn (gfc_expr *, gfc_expr *);
bool gfc_check_char (gfc_expr *, gfc_expr *);
bool gfc_check_chdir (gfc_expr *);
bool gfc_check_chmod (gfc_expr *, gfc_expr *);
bool gfc_check_cmplx (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_complex (gfc_expr *, gfc_expr *);
bool gfc_check_co_broadcast (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_co_minmax (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_co_sum (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_co_reduce (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			  gfc_expr *);
bool gfc_check_count (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_cshift (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ctime (gfc_expr *);
bool gfc_check_datan2 (gfc_expr *, gfc_expr *);
bool gfc_check_dcmplx (gfc_expr *, gfc_expr *);
bool gfc_check_dble (gfc_expr *);
bool gfc_check_digits (gfc_expr *);
bool gfc_check_dot_product (gfc_expr *, gfc_expr *);
bool gfc_check_dprod (gfc_expr *, gfc_expr *);
bool gfc_check_dshift (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_eoshift (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_dtime_etime (gfc_expr *);
bool gfc_check_event_query (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_failed_or_stopped_images (gfc_expr *, gfc_expr *);
bool gfc_check_fgetputc (gfc_expr *, gfc_expr *);
bool gfc_check_fgetput (gfc_expr *);
bool gfc_check_findloc (gfc_actual_arglist *);
bool gfc_check_float (gfc_expr *);
bool gfc_check_fstat (gfc_expr *, gfc_expr *);
bool gfc_check_ftell (gfc_expr *);
bool gfc_check_fn_c (gfc_expr *);
bool gfc_check_fn_d (gfc_expr *);
bool gfc_check_fn_r (gfc_expr *);
bool gfc_check_fn_rc (gfc_expr *);
bool gfc_check_fn_rc2008 (gfc_expr *);
bool gfc_check_fnum (gfc_expr *);
bool gfc_check_get_team (gfc_expr *);
bool gfc_check_hostnm (gfc_expr *);
bool gfc_check_huge (gfc_expr *);
bool gfc_check_hypot (gfc_expr *, gfc_expr *);
bool gfc_check_i (gfc_expr *);
bool gfc_check_iand_ieor_ior (gfc_expr *, gfc_expr *);
bool gfc_check_and (gfc_expr *, gfc_expr *);
bool gfc_check_ibits (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ichar_iachar (gfc_expr *, gfc_expr *);
bool gfc_check_idnint (gfc_expr *);
bool gfc_check_image_status (gfc_expr *, gfc_expr *);
bool gfc_check_index (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_int (gfc_expr *, gfc_expr *);
bool gfc_check_intconv (gfc_expr *);
bool gfc_check_irand (gfc_expr *);
bool gfc_check_is_contiguous (gfc_expr *);
bool gfc_check_isatty (gfc_expr *);
bool gfc_check_isnan (gfc_expr *);
bool gfc_check_ishft (gfc_expr *, gfc_expr *);
bool gfc_check_ishftc (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_kill (gfc_expr *, gfc_expr *);
bool gfc_check_kind (gfc_expr *);
bool gfc_check_lbound (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_lcobound (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_len_lentrim (gfc_expr *, gfc_expr *);
bool gfc_check_link (gfc_expr *, gfc_expr *);
bool gfc_check_lge_lgt_lle_llt (gfc_expr *, gfc_expr *);
bool gfc_check_loc (gfc_expr *);
bool gfc_check_logical (gfc_expr *, gfc_expr *);
bool gfc_check_min_max (gfc_actual_arglist *);
bool gfc_check_min_max_integer (gfc_actual_arglist *);
bool gfc_check_min_max_real (gfc_actual_arglist *);
bool gfc_check_min_max_double (gfc_actual_arglist *);
bool gfc_check_malloc (gfc_expr *);
bool gfc_check_mask (gfc_expr *, gfc_expr *);
bool gfc_check_matmul (gfc_expr *, gfc_expr *);
bool gfc_check_merge (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_merge_bits (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_minloc_maxloc (gfc_actual_arglist *);
bool gfc_check_minval_maxval (gfc_actual_arglist *);
bool gfc_check_nearest (gfc_expr *, gfc_expr *);
bool gfc_check_new_line (gfc_expr *);
bool gfc_check_norm2 (gfc_expr *, gfc_expr *);
bool gfc_check_null (gfc_expr *);
bool gfc_check_num_images (gfc_expr *, gfc_expr *);
bool gfc_check_pack (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_parity (gfc_expr *, gfc_expr *);
bool gfc_check_precision (gfc_expr *);
bool gfc_check_present (gfc_expr *);
bool gfc_check_product_sum (gfc_actual_arglist *);
bool gfc_check_radix (gfc_expr *);
bool gfc_check_rand (gfc_expr *);
bool gfc_check_range (gfc_expr *);
bool gfc_check_rank (gfc_expr *);
bool gfc_check_real (gfc_expr *, gfc_expr *);
bool gfc_check_rename (gfc_expr *, gfc_expr *);
bool gfc_check_repeat (gfc_expr *, gfc_expr *);
bool gfc_check_reshape (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_same_type_as (gfc_expr *, gfc_expr *);
bool gfc_check_scale (gfc_expr *, gfc_expr *);
bool gfc_check_scan (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_second_sub (gfc_expr *);
bool gfc_check_secnds (gfc_expr *);
bool gfc_check_selected_char_kind (gfc_expr *);
bool gfc_check_selected_int_kind (gfc_expr *);
bool gfc_check_selected_real_kind (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_set_exponent (gfc_expr *, gfc_expr *);
bool gfc_check_shape (gfc_expr *, gfc_expr *);
bool gfc_check_shift (gfc_expr *, gfc_expr *);
bool gfc_check_size (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_sign (gfc_expr *, gfc_expr *);
bool gfc_check_signal (gfc_expr *, gfc_expr *);
bool gfc_check_sizeof (gfc_expr *);
bool gfc_check_c_associated (gfc_expr *, gfc_expr *);
bool gfc_check_c_f_pointer (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_c_f_procpointer (gfc_expr *, gfc_expr *);
bool gfc_check_c_funloc (gfc_expr *);
bool gfc_check_c_loc (gfc_expr *);
bool gfc_check_c_sizeof (gfc_expr *);
bool gfc_check_sngl (gfc_expr *);
bool gfc_check_spread (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_srand (gfc_expr *);
bool gfc_check_stat (gfc_expr *, gfc_expr *);
bool gfc_check_storage_size (gfc_expr *, gfc_expr *);
bool gfc_check_sum (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_symlnk (gfc_expr *, gfc_expr *);
bool gfc_check_team_number (gfc_expr *);
bool gfc_check_transf_bit_intrins (gfc_actual_arglist *);
bool gfc_check_transfer (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_transpose (gfc_expr *);
bool gfc_check_trim (gfc_expr *);
bool gfc_check_ttynam (gfc_expr *);
bool gfc_check_ubound (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ucobound (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_umask (gfc_expr *);
bool gfc_check_unlink (gfc_expr *);
bool gfc_check_unpack (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_verify (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_x (gfc_expr *);


/* Intrinsic subroutines.  */
bool gfc_check_alarm_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_chdir_sub (gfc_expr *, gfc_expr *);
bool gfc_check_chmod_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_cpu_time (gfc_expr *);
bool gfc_check_ctime_sub (gfc_expr *, gfc_expr *);
bool gfc_check_system_clock (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_date_and_time (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_exit (gfc_expr *);
bool gfc_check_fdate_sub (gfc_expr *);
bool gfc_check_fe_runtime_error (gfc_actual_arglist *);
bool gfc_check_flush (gfc_expr *);
bool gfc_check_free (gfc_expr *);
bool gfc_check_fstat_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_gerror (gfc_expr *);
bool gfc_check_getarg (gfc_expr *, gfc_expr *);
bool gfc_check_getlog (gfc_expr *);
bool gfc_check_move_alloc (gfc_expr *, gfc_expr *);
bool gfc_check_mvbits (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
		      gfc_expr *);
bool gfc_check_random_init (gfc_expr *, gfc_expr *);
bool gfc_check_random_number (gfc_expr *);
bool gfc_check_random_seed (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_dtime_etime_sub (gfc_expr *, gfc_expr *);
bool gfc_check_fgetputc_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_fgetput_sub (gfc_expr *, gfc_expr *);
bool gfc_check_fseek_sub (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ftell_sub (gfc_expr *, gfc_expr *);
bool gfc_check_getcwd_sub (gfc_expr *, gfc_expr *);
bool gfc_check_hostnm_sub (gfc_expr *, gfc_expr *);
bool gfc_check_image_index (gfc_expr *, gfc_expr *);
bool gfc_check_itime_idate (gfc_expr *);
bool gfc_check_kill_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ltime_gmtime (gfc_expr *, gfc_expr *);
bool gfc_check_perror (gfc_expr *);
bool gfc_check_rename_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_link_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_symlnk_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_signal_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_sleep_sub (gfc_expr *);
bool gfc_check_stat_sub (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_system_sub (gfc_expr *, gfc_expr *);
bool gfc_check_this_image (gfc_expr *, gfc_expr *, gfc_expr *);
bool gfc_check_ttynam_sub (gfc_expr *, gfc_expr *);
bool gfc_check_umask_sub (gfc_expr *, gfc_expr *);
bool gfc_check_unlink_sub (gfc_expr *, gfc_expr *);


/* Simplification functions.  */
gfc_expr *gfc_simplify_abs (gfc_expr *);
gfc_expr *gfc_simplify_achar (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_acos (gfc_expr *);
gfc_expr *gfc_simplify_acosh (gfc_expr *);
gfc_expr *gfc_simplify_adjustl (gfc_expr *);
gfc_expr *gfc_simplify_adjustr (gfc_expr *);
gfc_expr *gfc_simplify_aimag (gfc_expr *);
gfc_expr *gfc_simplify_aint (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_all (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_atrigd (gfc_expr *);
gfc_expr *gfc_simplify_dint (gfc_expr *);
gfc_expr *gfc_simplify_anint (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dnint (gfc_expr *);
gfc_expr *gfc_simplify_and (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_any (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_asin (gfc_expr *);
gfc_expr *gfc_simplify_asinh (gfc_expr *);
gfc_expr *gfc_simplify_atan (gfc_expr *);
gfc_expr *gfc_simplify_atanh (gfc_expr *);
gfc_expr *gfc_simplify_atan2 (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_atan2d (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bessel_j0 (gfc_expr *);
gfc_expr *gfc_simplify_bessel_j1 (gfc_expr *);
gfc_expr *gfc_simplify_bessel_jn (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bessel_jn2 (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bessel_y0 (gfc_expr *);
gfc_expr *gfc_simplify_bessel_y1 (gfc_expr *);
gfc_expr *gfc_simplify_bessel_yn (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bessel_yn2 (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bge (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bgt (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_bit_size (gfc_expr *);
gfc_expr *gfc_simplify_ble (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_blt (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_btest (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ceiling (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_char (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_cmplx (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_compiler_options (void);
gfc_expr *gfc_simplify_compiler_version (void);
gfc_expr *gfc_simplify_complex (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_conjg (gfc_expr *);
gfc_expr *gfc_simplify_cos (gfc_expr *);
gfc_expr *gfc_simplify_cosh (gfc_expr *);
gfc_expr *gfc_simplify_cotan (gfc_expr *);
gfc_expr *gfc_simplify_count (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_cshift (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dcmplx (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dble (gfc_expr *);
gfc_expr *gfc_simplify_digits (gfc_expr *);
gfc_expr *gfc_simplify_dim (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dprod (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dot_product (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dreal (gfc_expr *);
gfc_expr *gfc_simplify_dshiftl (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_dshiftr (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_eoshift (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_epsilon (gfc_expr *);
gfc_expr *gfc_simplify_erf (gfc_expr *);
gfc_expr *gfc_simplify_erfc (gfc_expr *);
gfc_expr *gfc_simplify_erfc_scaled (gfc_expr *);
gfc_expr *gfc_simplify_exp (gfc_expr *);
gfc_expr *gfc_simplify_exponent (gfc_expr *);
gfc_expr *gfc_simplify_extends_type_of (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_failed_or_stopped_images (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_findloc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
				gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_float (gfc_expr *);
gfc_expr *gfc_simplify_floor (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_fraction (gfc_expr *);
gfc_expr *gfc_simplify_gamma (gfc_expr *);
gfc_expr *gfc_simplify_get_team (gfc_expr *);
gfc_expr *gfc_simplify_huge (gfc_expr *);
gfc_expr *gfc_simplify_hypot (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_iachar (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_iall (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_iand (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_iany (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ibclr (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ibits (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ibset (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ichar (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ieor (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_image_index (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_image_status (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_index (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_int (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_int2 (gfc_expr *);
gfc_expr *gfc_simplify_int8 (gfc_expr *);
gfc_expr *gfc_simplify_long (gfc_expr *);
gfc_expr *gfc_simplify_ifix (gfc_expr *);
gfc_expr *gfc_simplify_idint (gfc_expr *);
gfc_expr *gfc_simplify_ior (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_iparity (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_is_contiguous (gfc_expr *);
gfc_expr *gfc_simplify_is_iostat_end (gfc_expr *);
gfc_expr *gfc_simplify_is_iostat_eor (gfc_expr *);
gfc_expr *gfc_simplify_isnan (gfc_expr *);
gfc_expr *gfc_simplify_ishft (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ishftc (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_kind (gfc_expr *);
gfc_expr *gfc_simplify_lbound (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_lcobound (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_leadz (gfc_expr *);
gfc_expr *gfc_simplify_len (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_len_trim (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_lgamma (gfc_expr *);
gfc_expr *gfc_simplify_lge (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_lgt (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_lle (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_llt (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_log (gfc_expr *);
gfc_expr *gfc_simplify_log10 (gfc_expr *);
gfc_expr *gfc_simplify_logical (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_lshift (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_matmul (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_maskl (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_maskr (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_merge (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_merge_bits (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_min (gfc_expr *);
gfc_expr *gfc_simplify_minloc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			       gfc_expr *);
gfc_expr *gfc_simplify_minval (gfc_expr *, gfc_expr*, gfc_expr*);
gfc_expr *gfc_simplify_max (gfc_expr *);
gfc_expr *gfc_simplify_maxloc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			       gfc_expr *);
gfc_expr *gfc_simplify_maxval (gfc_expr *, gfc_expr*, gfc_expr*);
gfc_expr *gfc_simplify_maxexponent (gfc_expr *);
gfc_expr *gfc_simplify_minexponent (gfc_expr *);
gfc_expr *gfc_simplify_mod (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_modulo (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_nearest (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_new_line (gfc_expr *);
gfc_expr *gfc_simplify_nint (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_norm2 (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_null (gfc_expr *);
gfc_expr *gfc_simplify_num_images (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_idnint (gfc_expr *);
gfc_expr *gfc_simplify_not (gfc_expr *);
gfc_expr *gfc_simplify_or (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_pack (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_parity (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_popcnt (gfc_expr *);
gfc_expr *gfc_simplify_poppar (gfc_expr *);
gfc_expr *gfc_simplify_precision (gfc_expr *);
gfc_expr *gfc_simplify_product (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_radix (gfc_expr *);
gfc_expr *gfc_simplify_range (gfc_expr *);
gfc_expr *gfc_simplify_rank (gfc_expr *);
gfc_expr *gfc_simplify_real (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_realpart (gfc_expr *);
gfc_expr *gfc_simplify_repeat (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_reshape (gfc_expr *, gfc_expr *, gfc_expr *,
				gfc_expr *);
gfc_expr *gfc_simplify_rrspacing (gfc_expr *);
gfc_expr *gfc_simplify_rshift (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_same_type_as (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_scale (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_scan (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_selected_char_kind (gfc_expr *);
gfc_expr *gfc_simplify_selected_int_kind (gfc_expr *);
gfc_expr *gfc_simplify_selected_real_kind (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_set_exponent (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_sign (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_shape (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_shifta (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_shiftl (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_shiftr (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_sin (gfc_expr *);
gfc_expr *gfc_simplify_sinh (gfc_expr *);
gfc_expr *gfc_simplify_size (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_sizeof (gfc_expr *);
gfc_expr *gfc_simplify_storage_size (gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_sngl (gfc_expr *);
gfc_expr *gfc_simplify_spacing (gfc_expr *);
gfc_expr *gfc_simplify_spread (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_sqrt (gfc_expr *);
gfc_expr *gfc_simplify_sum (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_tan (gfc_expr *);
gfc_expr *gfc_simplify_tanh (gfc_expr *);
gfc_expr *gfc_simplify_this_image (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_tiny (gfc_expr *);
gfc_expr *gfc_simplify_trailz (gfc_expr *);
gfc_expr *gfc_simplify_transfer (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_transpose (gfc_expr *);
gfc_expr *gfc_simplify_trigd (gfc_expr *);
gfc_expr *gfc_simplify_trim (gfc_expr *);
gfc_expr *gfc_simplify_ubound (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_ucobound (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_unpack (gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_verify (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
gfc_expr *gfc_simplify_xor (gfc_expr *, gfc_expr *);

/* Constant conversion simplification.  */
gfc_expr *gfc_convert_constant (gfc_expr *, bt, int);
gfc_expr *gfc_convert_char_constant (gfc_expr *, bt, int);


/* Resolution functions.  */
void gfc_resolve_abs (gfc_expr *, gfc_expr *);
void gfc_resolve_access (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_adjustl (gfc_expr *, gfc_expr *);
void gfc_resolve_adjustr (gfc_expr *, gfc_expr *);
void gfc_resolve_achar (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_acos (gfc_expr *, gfc_expr *);
void gfc_resolve_acosh (gfc_expr *, gfc_expr *);
void gfc_resolve_aimag (gfc_expr *, gfc_expr *);
void gfc_resolve_aint (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dint (gfc_expr *, gfc_expr *);
void gfc_resolve_all (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_anint (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dnint (gfc_expr *, gfc_expr *);
void gfc_resolve_and (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_any (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_asin (gfc_expr *, gfc_expr *);
void gfc_resolve_asinh (gfc_expr *, gfc_expr *);
void gfc_resolve_atan (gfc_expr *, gfc_expr *);
void gfc_resolve_atanh (gfc_expr *, gfc_expr *);
void gfc_resolve_atan2 (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_atan2d (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_atomic_def (gfc_code *);
void gfc_resolve_atomic_ref (gfc_code *);
void gfc_resolve_besn (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_bessel_n2 (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *a);
void gfc_resolve_btest (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_c_loc (gfc_expr *, gfc_expr *);
void gfc_resolve_c_funloc (gfc_expr *, gfc_expr *);
void gfc_resolve_ceiling (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_char (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_chdir (gfc_expr *, gfc_expr *);
void gfc_resolve_chmod (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_cmplx (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dcmplx (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_complex (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_conjg (gfc_expr *, gfc_expr *);
void gfc_resolve_cos (gfc_expr *, gfc_expr *);
void gfc_resolve_cosh (gfc_expr *, gfc_expr *);
void gfc_resolve_count (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_cotan (gfc_expr *, gfc_expr *);
void gfc_resolve_cshift (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ctime (gfc_expr *, gfc_expr *);
void gfc_resolve_dble (gfc_expr *, gfc_expr *);
void gfc_resolve_dim (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dot_product (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dprod (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dshift (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_dtime_sub (gfc_code *);
void gfc_resolve_eoshift (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			  gfc_expr *);
void gfc_resolve_etime_sub (gfc_code *);
void gfc_resolve_event_query (gfc_code *);
void gfc_resolve_exp (gfc_expr *, gfc_expr *);
void gfc_resolve_exponent (gfc_expr *, gfc_expr *);
void gfc_resolve_extends_type_of (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_failed_images (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_fdate (gfc_expr *);
void gfc_resolve_findloc (gfc_expr *,gfc_expr *, gfc_expr *, gfc_expr *,
			  gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_floor (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_fnum (gfc_expr *, gfc_expr *);
void gfc_resolve_fraction (gfc_expr *, gfc_expr *);
void gfc_resolve_fstat (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ftell (gfc_expr *, gfc_expr *);
void gfc_resolve_fgetc (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_fget (gfc_expr *, gfc_expr *);
void gfc_resolve_fputc (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_fput (gfc_expr *, gfc_expr *);
void gfc_resolve_g77_math1 (gfc_expr *, gfc_expr *);
void gfc_resolve_gamma (gfc_expr *, gfc_expr *);
void gfc_resolve_getcwd (gfc_expr *, gfc_expr *);
void gfc_resolve_getgid (gfc_expr *);
void gfc_resolve_getpid (gfc_expr *);
void gfc_resolve_get_team (gfc_expr *, gfc_expr *);
void gfc_resolve_getuid (gfc_expr *);
void gfc_resolve_hostnm (gfc_expr *, gfc_expr *);
void gfc_resolve_hypot (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_iand (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ibclr (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ibits (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ibset (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_image_index (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_image_status (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_index_func (gfc_expr *, gfc_actual_arglist *);
void gfc_resolve_ierrno (gfc_expr *);
void gfc_resolve_ieor (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ichar (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_iachar (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_iall (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_iany (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_idnint (gfc_expr *, gfc_expr *);
void gfc_resolve_int (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_int2 (gfc_expr *, gfc_expr *);
void gfc_resolve_int8 (gfc_expr *, gfc_expr *);
void gfc_resolve_long (gfc_expr *, gfc_expr *);
void gfc_resolve_ior (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_iparity (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_isatty (gfc_expr *, gfc_expr *);
void gfc_resolve_is_contiguous (gfc_expr *, gfc_expr *);
void gfc_resolve_rank (gfc_expr *, gfc_expr *);
void gfc_resolve_rshift (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_lshift (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ishft (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ishftc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_kill (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_lbound (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_lcobound (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_len (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_len_trim (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_lgamma (gfc_expr *, gfc_expr *);
void gfc_resolve_link (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_loc (gfc_expr *, gfc_expr *);
void gfc_resolve_log (gfc_expr *, gfc_expr *);
void gfc_resolve_log10 (gfc_expr *, gfc_expr *);
void gfc_resolve_logical (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_lstat (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_matmul (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_max (gfc_expr *, gfc_actual_arglist *);
void gfc_resolve_maxloc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_maxval (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_mclock (gfc_expr *);
void gfc_resolve_mclock8 (gfc_expr *);
void gfc_resolve_mask (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_merge (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_merge_bits (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_min (gfc_expr *, gfc_actual_arglist *);
void gfc_resolve_minloc (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_minval (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_mod (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_modulo (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_nearest (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_nint (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_norm2 (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_not (gfc_expr *, gfc_expr *);
void gfc_resolve_or (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_pack (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_parity (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_product (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_real (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_realpart (gfc_expr *, gfc_expr *);
void gfc_resolve_rename (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_repeat (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_reshape (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			  gfc_expr *);
void gfc_resolve_rrspacing (gfc_expr *, gfc_expr *);
void gfc_resolve_scale (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_scan (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
		       gfc_expr *);
void gfc_resolve_second_sub (gfc_code *);
void gfc_resolve_secnds (gfc_expr *, gfc_expr *);
void gfc_resolve_set_exponent (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_shape (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_shift (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_sign (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_signal (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_sin (gfc_expr *, gfc_expr *);
void gfc_resolve_sinh (gfc_expr *, gfc_expr *);
void gfc_resolve_size (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_spacing (gfc_expr *, gfc_expr *);
void gfc_resolve_spread (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_sqrt (gfc_expr *, gfc_expr *);
void gfc_resolve_stat (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_stopped_images (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_storage_size (gfc_expr *f, gfc_expr *a, gfc_expr *kind);
void gfc_resolve_stride (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_srand (gfc_code *);
void gfc_resolve_sum (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_symlnk (gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_system (gfc_expr *, gfc_expr *);
void gfc_resolve_tan (gfc_expr *, gfc_expr *);
void gfc_resolve_tanh (gfc_expr *, gfc_expr *);
void gfc_resolve_team_number (gfc_expr *, gfc_expr *);
void gfc_resolve_this_image (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_time (gfc_expr *);
void gfc_resolve_time8 (gfc_expr *);
void gfc_resolve_transfer (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_transpose (gfc_expr *, gfc_expr *);
void gfc_resolve_trigd (gfc_expr *, gfc_expr *);
void gfc_resolve_atrigd (gfc_expr *, gfc_expr *);
void gfc_resolve_trim (gfc_expr *, gfc_expr *);
void gfc_resolve_ttynam (gfc_expr *, gfc_expr *);
void gfc_resolve_ubound (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_ucobound (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_umask (gfc_expr *, gfc_expr *);
void gfc_resolve_unlink (gfc_expr *, gfc_expr *);
void gfc_resolve_unpack (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *);
void gfc_resolve_verify (gfc_expr *, gfc_expr *, gfc_expr *, gfc_expr *,
			 gfc_expr *);
void gfc_resolve_xor (gfc_expr *, gfc_expr *, gfc_expr *);


/* Intrinsic subroutine resolution.  */
void gfc_resolve_alarm_sub (gfc_code *);
void gfc_resolve_chdir_sub (gfc_code *);
void gfc_resolve_chmod_sub (gfc_code *);
void gfc_resolve_cpu_time (gfc_code *);
void gfc_resolve_ctime_sub (gfc_code *);
void gfc_resolve_execute_command_line (gfc_code *);
void gfc_resolve_exit (gfc_code *);
void gfc_resolve_fdate_sub (gfc_code *);
void gfc_resolve_fe_runtime_error (gfc_code *);
void gfc_resolve_flush (gfc_code *);
void gfc_resolve_fseek_sub (gfc_code *);
void gfc_resolve_fstat_sub (gfc_code *);
void gfc_resolve_ftell_sub (gfc_code *);
void gfc_resolve_fgetc_sub (gfc_code *);
void gfc_resolve_fget_sub (gfc_code *);
void gfc_resolve_fputc_sub (gfc_code *);
void gfc_resolve_fput_sub (gfc_code *);
void gfc_resolve_gerror (gfc_code *);
void gfc_resolve_getarg (gfc_code *);
void gfc_resolve_getcwd_sub (gfc_code *);
void gfc_resolve_getlog (gfc_code *);
void gfc_resolve_get_command (gfc_code *);
void gfc_resolve_get_command_argument (gfc_code *);
void gfc_resolve_get_environment_variable (gfc_code *);
void gfc_resolve_gmtime (gfc_code *);
void gfc_resolve_hostnm_sub (gfc_code *);
void gfc_resolve_idate (gfc_code *);
void gfc_resolve_itime (gfc_code *);
void gfc_resolve_kill_sub (gfc_code *);
void gfc_resolve_lstat_sub (gfc_code *);
void gfc_resolve_ltime (gfc_code *);
void gfc_resolve_mvbits (gfc_code *);
void gfc_resolve_perror (gfc_code *);
void gfc_resolve_random_init (gfc_code *);
void gfc_resolve_random_number (gfc_code *);
void gfc_resolve_random_seed (gfc_code *);
void gfc_resolve_rename_sub (gfc_code *);
void gfc_resolve_link_sub (gfc_code *);
void gfc_resolve_symlnk_sub (gfc_code *);
void gfc_resolve_signal_sub (gfc_code *);
void gfc_resolve_sleep_sub (gfc_code *);
void gfc_resolve_stat_sub (gfc_code *);
void gfc_resolve_system_clock (gfc_code *);
void gfc_resolve_system_sub (gfc_code *);
void gfc_resolve_ttynam_sub (gfc_code *);
void gfc_resolve_umask_sub (gfc_code *);
void gfc_resolve_unlink_sub (gfc_code *);


/* The findloc() subroutine requires the most arguments: six.  */

#define MAX_INTRINSIC_ARGS 6

extern const char *gfc_current_intrinsic;
extern gfc_intrinsic_arg *gfc_current_intrinsic_arg[MAX_INTRINSIC_ARGS];
extern locus *gfc_current_intrinsic_where;
