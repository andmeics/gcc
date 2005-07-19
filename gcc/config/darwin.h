/* Target definitions for Darwin (Mac OS X) systems.
   Copyright (C) 1989, 1990, 1991, 1992, 1993, 2000, 2001, 2002, 2003, 2004,
   2005
   Free Software Foundation, Inc.
   Contributed by Apple Computer Inc.

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
the Free Software Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  */

#ifndef CONFIG_DARWIN_H
#define CONFIG_DARWIN_H

/* The definitions in this file are common to all processor types
   running Darwin, which is the kernel for Mac OS X.  Darwin is
   basically a BSD user layer laid over a Mach kernel, then evolved
   for many years (at NeXT) in parallel with other Unix systems.  So
   while the runtime is a somewhat idiosyncratic Mach-based thing,
   other definitions look like they would for a BSD variant.  */

/* Although NeXT ran on many different architectures, as of Jan 2001
   the only supported Darwin targets are PowerPC and x86.  */

/* One of Darwin's NeXT legacies is the Mach-O format, which is partly
   like a.out and partly like COFF, with additional features like
   multi-architecture binary support.  */

#define OBJECT_FORMAT_MACHO

/* Suppress g++ attempt to link in the math library automatically. */
#define MATH_LIBRARY ""

/* We have atexit.  */

#define HAVE_ATEXIT

/* Define an empty body for the function do_global_dtors() in libgcc2.c.  */

#define DO_GLOBAL_DTORS_BODY

/* The string value for __SIZE_TYPE__.  */

#ifndef SIZE_TYPE
#define SIZE_TYPE "long unsigned int"
#endif

/* Type used for ptrdiff_t, as a string used in a declaration.  */

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

/* wchar_t is int.  */

#undef	WCHAR_TYPE
#define WCHAR_TYPE "int"
#undef	WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32

/* Default to using the NeXT-style runtime, since that's what is
   pre-installed on Darwin systems.  */

#define NEXT_OBJC_RUNTIME

/* Don't default to pcc-struct-return, because gcc is the only compiler, and
   we want to retain compatibility with older gcc versions.  */

#undef	DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 0

/* This table intercepts weirdo options whose names would interfere
   with normal driver conventions, and either translates them into
   standardly-named options, or adds a 'Z' so that they can get to
   specs processing without interference.

   Do not expand a linker option to "-Xlinker -<option>", since that
   forfeits the ability to control via spec strings later.  However,
   as a special exception, do this translation with -filelist, because
   otherwise the driver will think there are no input files and quit.
   (The alternative would be to hack the driver to recognize -filelist
   specially, but it's simpler to use the translation table.)

   Note that an option name with a prefix that matches another option
   name, that also takes an argument, needs to be modified so the
   prefix is different, otherwise a '*' after the shorter option will
   match with the longer one.
   
   The SUBTARGET_OPTION_TRANSLATE_TABLE macro, which _must_ be defined
   in gcc/config/{i386,rs6000}/darwin.h, should contain any additional
   command-line option translations specific to the particular target
   architecture.  */
   
#define TARGET_OPTION_TRANSLATE_TABLE \
  { "-all_load", "-Zall_load" },  \
  { "-allowable_client", "-Zallowable_client" },  \
  { "-arch_errors_fatal", "-Zarch_errors_fatal" },  \
  { "-bind_at_load", "-Zbind_at_load" },  \
  { "-bundle", "-Zbundle" },  \
  { "-bundle_loader", "-Zbundle_loader" },  \
  { "-weak_reference_mismatches", "-Zweak_reference_mismatches" },  \
  { "-dead_strip", "-Zdead_strip" }, \
  { "-no_dead_strip_inits_and_terms", "-Zno_dead_strip_inits_and_terms" }, \
  { "-dependency-file", "-MF" }, \
  { "-dylib_file", "-Zdylib_file" }, \
  { "-dynamic", "-Zdynamic" },  \
  { "-dynamiclib", "-Zdynamiclib" },  \
  { "-exported_symbols_list", "-Zexported_symbols_list" },  \
  { "-gfull", "-g -fno-eliminate-unused-debug-symbols" }, \
  { "-gused", "-g -feliminate-unused-debug-symbols" }, \
  { "-segaddr", "-Zsegaddr" }, \
  { "-segs_read_only_addr", "-Zsegs_read_only_addr" }, \
  { "-segs_read_write_addr", "-Zsegs_read_write_addr" }, \
  { "-seg_addr_table", "-Zseg_addr_table" }, \
  { "-seg_addr_table_filename", "-Zseg_addr_table_filename" }, \
  { "-filelist", "-Xlinker -filelist -Xlinker" },  \
  { "-framework", "-Xlinker -framework -Xlinker" },  \
  { "-flat_namespace", "-Zflat_namespace" },  \
  { "-force_cpusubtype_ALL", "-Zforce_cpusubtype_ALL" },  \
  { "-force_flat_namespace", "-Zforce_flat_namespace" },  \
  { "-image_base", "-Zimage_base" },  \
  { "-init", "-Zinit" },  \
  { "-install_name", "-Zinstall_name" },  \
  { "-multiply_defined_unused", "-Zmultiplydefinedunused" },  \
  { "-multiply_defined", "-Zmultiply_defined" },  \
  { "-multi_module", "-Zmulti_module" },  \
  { "-static", "-static -Wa,-static" },  \
  { "-single_module", "-Zsingle_module" },  \
  { "-unexported_symbols_list", "-Zunexported_symbols_list" }, \
  SUBTARGET_OPTION_TRANSLATE_TABLE

/* These compiler options take n arguments.  */

#undef  WORD_SWITCH_TAKES_ARG
#define WORD_SWITCH_TAKES_ARG(STR)              \
  (DEFAULT_WORD_SWITCH_TAKES_ARG (STR) ? 1 :    \
   !strcmp (STR, "Zallowable_client") ? 1 :     \
   !strcmp (STR, "arch") ? 1 :                  \
   !strcmp (STR, "arch_only") ? 1 :             \
   !strcmp (STR, "Zbundle_loader") ? 1 :        \
   !strcmp (STR, "client_name") ? 1 :           \
   !strcmp (STR, "compatibility_version") ? 1 : \
   !strcmp (STR, "current_version") ? 1 :       \
   !strcmp (STR, "Zdylib_file") ? 1 :           \
   !strcmp (STR, "Zexported_symbols_list") ? 1 : \
   !strcmp (STR, "Zimage_base") ? 1 :           \
   !strcmp (STR, "Zinit") ? 1 :                 \
   !strcmp (STR, "Zinstall_name") ? 1 :         \
   !strcmp (STR, "Zmultiplydefinedunused") ? 1 : \
   !strcmp (STR, "Zmultiply_defined") ? 1 :     \
   !strcmp (STR, "precomp-trustfile") ? 1 :     \
   !strcmp (STR, "read_only_relocs") ? 1 :      \
   !strcmp (STR, "sectcreate") ? 3 :            \
   !strcmp (STR, "sectorder") ? 3 :             \
   !strcmp (STR, "Zsegaddr") ? 2 :              \
   !strcmp (STR, "Zsegs_read_only_addr") ? 1 :  \
   !strcmp (STR, "Zsegs_read_write_addr") ? 1 : \
   !strcmp (STR, "Zseg_addr_table") ? 1 :       \
   !strcmp (STR, "Zseg_addr_table_filename") ?1 :\
   !strcmp (STR, "seg1addr") ? 1 :              \
   !strcmp (STR, "segprot") ? 3 :               \
   !strcmp (STR, "sub_library") ? 1 :           \
   !strcmp (STR, "sub_umbrella") ? 1 :          \
   !strcmp (STR, "umbrella") ? 1 :              \
   !strcmp (STR, "undefined") ? 1 :             \
   !strcmp (STR, "Zunexported_symbols_list") ? 1 : \
   !strcmp (STR, "Zweak_reference_mismatches") ? 1 : \
   !strcmp (STR, "pagezero_size") ? 1 :         \
   !strcmp (STR, "segs_read_only_addr") ? 1 :   \
   !strcmp (STR, "segs_read_write_addr") ? 1 :  \
   !strcmp (STR, "sectalign") ? 3 :             \
   !strcmp (STR, "sectobjectsymbols") ? 2 :     \
   !strcmp (STR, "segcreate") ? 3 :             \
   !strcmp (STR, "dylinker_install_name") ? 1 : \
   0)

/* Machine dependent cpp options.  Don't add more options here, add
   them to darwin_cpp_builtins in darwin-c.c.  */

#undef	CPP_SPEC
#define CPP_SPEC "%{static:%{!dynamic:-D__STATIC__}}%{!static:-D__DYNAMIC__}"

/* This is mostly a clone of the standard LINK_COMMAND_SPEC, plus
   precomp, libtool, and fat build additions.  Also we
   don't specify a second %G after %L because libSystem is
   self-contained and doesn't need to link against libgcc.a.  */
/* In general, random Darwin linker flags should go into LINK_SPEC
   instead of LINK_COMMAND_SPEC.  The command spec is better for
   specifying the handling of options understood by generic Unix
   linkers, and for positional arguments like libraries.  */
#define LINK_COMMAND_SPEC "\
%{!fdump=*:%{!fsyntax-only:%{!precomp:%{!c:%{!M:%{!MM:%{!E:%{!S:\
    %{!Zdynamiclib:%(linker)}%{Zdynamiclib:/usr/bin/libtool} \
    %l %X %{d} %{s} %{t} %{Z} \
    %{!Zdynamiclib:%{A} %{e*} %{m} %{N} %{n} %{r} %{u*} %{x} %{z}} \
    %{@:-o %f%u.out}%{!@:%{o*}%{!o:-o a.out}} \
    %{!Zdynamiclib:%{!A:%{!nostdlib:%{!nostartfiles:%S}}}} \
    %{L*} %(link_libgcc) %o %{fprofile-arcs|fprofile-generate|coverage:-lgcov} \
    %{!nostdlib:%{!nodefaultlibs:%G %L}} \
    %{!A:%{!nostdlib:%{!nostartfiles:%E}}} %{T*} %{F*} }}}}}}}}"

/* Please keep the random linker options in alphabetical order (modulo
   'Z' and 'no' prefixes).  Options that can only go to one of libtool
   or ld must be listed twice, under both !Zdynamiclib and
   Zdynamiclib, with one of the cases reporting an error.  */
/* Note that options taking arguments may appear multiple times on a
   command line with different arguments each time, so put a * after
   their names so all of them get passed.  */
#define LINK_SPEC  \
  "%{static}%{!static:-dynamic} \
   %{fgnu-runtime:%:replace-outfile(-lobjc -lobjc-gnu)}\
   %{!Zdynamiclib: \
     %{Zforce_cpusubtype_ALL:-arch %(darwin_arch) -force_cpusubtype_ALL} \
     %{!Zforce_cpusubtype_ALL:-arch %(darwin_subarch)} \
     %{Zbundle:-bundle} \
     %{Zbundle_loader*:-bundle_loader %*} \
     %{client_name*} \
     %{compatibility_version*:%e-compatibility_version only allowed with -dynamiclib\
} \
     %{current_version*:%e-current_version only allowed with -dynamiclib} \
     %{Zforce_flat_namespace:-force_flat_namespace} \
     %{Zinstall_name*:%e-install_name only allowed with -dynamiclib} \
     %{keep_private_externs} \
     %{private_bundle} \
    } \
   %{Zdynamiclib: \
     %{Zbundle:%e-bundle not allowed with -dynamiclib} \
     %{Zbundle_loader*:%e-bundle_loader not allowed with -dynamiclib} \
     %{client_name*:%e-client_name not allowed with -dynamiclib} \
     %{compatibility_version*} \
     %{current_version*} \
     %{Zforce_cpusubtype_ALL:-arch_only %(darwin_arch)} \
     %{!Zforce_cpusubtype_ALL: -arch_only %(darwin_subarch)} \
     %{Zforce_flat_namespace:%e-force_flat_namespace not allowed with -dynamiclib} \
     %{Zinstall_name*:-install_name %*} \
     %{keep_private_externs:%e-keep_private_externs not allowed with -dynamiclib} \
     %{private_bundle:%e-private_bundle not allowed with -dynamiclib} \
    } \
   %{Zall_load:-all_load}%{Zdynamiclib:%{!Zall_load:-noall_load}} \
   %{Zallowable_client*:-allowable_client %*} \
   %{Zbind_at_load:-bind_at_load} \
   %{Zarch_errors_fatal:-arch_errors_fatal} \
   %{Zdead_strip:-dead_strip} \
   %{Zno_dead_strip_inits_and_terms:-no_dead_strip_inits_and_terms} \
   %{Zdylib_file*:-dylib_file %*} \
   %{Zdynamic:-dynamic}\
   %{Zexported_symbols_list*:-exported_symbols_list %*} \
   %{Zflat_namespace:-flat_namespace} \
   %{headerpad_max_install_names*} \
   %{Zimage_base*:-image_base %*} \
   %{Zinit*:-init %*} \
   %{nomultidefs} \
   %{Zmulti_module:-multi_module} %{Zsingle_module:-single_module} \
   %{Zmultiply_defined*:-multiply_defined %*} \
   %{Zmultiplydefinedunused*:-multiply_defined_unused %*} \
   %{prebind} %{noprebind} %{nofixprebinding} %{prebind_all_twolevel_modules} \
   %{read_only_relocs} \
   %{sectcreate*} %{sectorder*} %{seg1addr*} %{segprot*} \
   %{Zsegaddr*:-segaddr %*} \
   %{Zsegs_read_only_addr*:-segs_read_only_addr %*} \
   %{Zsegs_read_write_addr*:-segs_read_write_addr %*} \
   %{Zseg_addr_table*: -seg_addr_table %*} \
   %{Zseg_addr_table_filename*:-seg_addr_table_filename %*} \
   %{sub_library*} %{sub_umbrella*} \
   %{isysroot*:-syslibroot %*} \
   %{twolevel_namespace} %{twolevel_namespace_hints} \
   %{umbrella*} \
   %{undefined*} \
   %{Zunexported_symbols_list*:-unexported_symbols_list %*} \
   %{Zweak_reference_mismatches*:-weak_reference_mismatches %*} \
   %{!Zweak_reference_mismatches*:-weak_reference_mismatches non-weak} \
   %{X} \
   %{y*} \
   %{w} \
   %{pagezero_size*} %{segs_read_*} %{seglinkedit} %{noseglinkedit}  \
   %{sectalign*} %{sectobjectsymbols*} %{segcreate*} %{whyload} \
   %{whatsloaded} %{dylinker_install_name*} \
   %{dylinker} %{Mach} "


/* Machine dependent libraries.  */

#define LIB_SPEC "%{!static:-lSystem}"

/* -dynamiclib implies -shared-libgcc just like -shared would on linux.  */
#define REAL_LIBGCC_SPEC \
   "%{static|static-libgcc:-lgcc -lgcc_eh}\
    %{!static:%{!static-libgcc:\
      %{!Zdynamiclib:%{!shared-libgcc:-lgcc -lgcc_eh}\
      %{shared-libgcc:-lgcc_s -lgcc}} %{Zdynamiclib:-lgcc_s -lgcc}}}"

/* We specify crt0.o as -lcrt0.o so that ld will search the library path.  */
/* We don't want anything to do with crt2.o in the 64-bit case;
   testing the PowerPC-specific -m64 flag here is a little irregular,
   but it's overkill to make copies of this spec for each target
   arch.  */

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC  \
  "%{!Zdynamiclib:%{Zbundle:%{!static:-lbundle1.o}} \
     %{!Zbundle:%{pg:%{static:-lgcrt0.o} \
                     %{!static:%{object:-lgcrt0.o} \
                               %{!object:%{preload:-lgcrt0.o} \
                                 %{!preload:-lgcrt1.o %{!m64: crt2.o%s}}}}} \
                %{!pg:%{static:-lcrt0.o} \
                      %{!static:%{object:-lcrt0.o} \
                                %{!object:%{preload:-lcrt0.o} \
                                  %{!preload:-lcrt1.o %{!m64: crt2.o%s}}}}}}}"

/* The native Darwin linker doesn't necessarily place files in the order
   that they're specified on the link line.  Thus, it is pointless
   to put anything in ENDFILE_SPEC.  */
/* #define ENDFILE_SPEC "" */

/* Default Darwin ASM_SPEC, very simple.  */
#define ASM_SPEC "-arch %(darwin_arch) \
  %{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL}"

/* We use Dbx symbol format.  */

#define DBX_DEBUGGING_INFO 1

/* Also enable Dwarf 2 as an option.  */
#define DWARF2_DEBUGGING_INFO
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG

#define DEBUG_FRAME_SECTION   "__DWARFA,__debug_frame,coalesced,no_toc+strip_static_syms"
#define DEBUG_INFO_SECTION    "__DWARFA,__debug_info"
#define DEBUG_ABBREV_SECTION  "__DWARFA,__debug_abbrev"
#define DEBUG_ARANGES_SECTION "__DWARFA,__debug_aranges"
#define DEBUG_MACINFO_SECTION "__DWARFA,__debug_macinfo"
#define DEBUG_LINE_SECTION    "__DWARFA,__debug_line"
#define DEBUG_LOC_SECTION     "__DWARFA,__debug_loc"
#define DEBUG_PUBNAMES_SECTION        "__DWARFA,__debug_pubnames"
#define DEBUG_STR_SECTION     "__DWARFA,__debug_str"
#define DEBUG_RANGES_SECTION  "__DWARFA,__debug_ranges"

/* When generating stabs debugging, use N_BINCL entries.  */

#define DBX_USE_BINCL

/* There is no limit to the length of stabs strings.  */

#define DBX_CONTIN_LENGTH 0

/* gdb needs a null N_SO at the end of each file for scattered loading.  */

#define DBX_OUTPUT_NULL_N_SO_AT_MAIN_SOURCE_FILE_END

/* GCC's definition of 'one_only' is the same as its definition of 'weak'.  */
#define MAKE_DECL_ONE_ONLY(DECL) (DECL_WEAK (DECL) = 1)

/* Mach-O supports 'weak imports', and 'weak definitions' in coalesced
   sections.  machopic_select_section ensures that weak variables go in
   coalesced sections.  Weak aliases (or any other kind of aliases) are
   not supported.  Weak symbols that aren't visible outside the .s file
   are not supported.  */
#define ASM_WEAKEN_DECL(FILE, DECL, NAME, ALIAS)			\
  do {									\
    if (ALIAS)								\
      {									\
	warning (0, "alias definitions not supported in Mach-O; ignored");	\
	break;								\
      }									\
 									\
    if (! DECL_EXTERNAL (DECL) && TREE_PUBLIC (DECL))			\
      targetm.asm_out.globalize_label (FILE, NAME);			\
    if (DECL_EXTERNAL (DECL))						\
      fputs ("\t.weak_reference ", FILE);				\
    else if (! lookup_attribute ("weak", DECL_ATTRIBUTES (DECL))	\
	&& lookup_attribute ("weak_import", DECL_ATTRIBUTES (DECL)))	\
      break;								\
    else if (TREE_PUBLIC (DECL))					\
      fputs ("\t.weak_definition ", FILE);				\
    else								\
      break;								\
    assemble_name (FILE, NAME);						\
    fputc ('\n', FILE);							\
  } while (0)

/* Darwin has the pthread routines in libSystem, which every program
   links to, so there's no need for weak-ness for that.  */
#define GTHREAD_USE_WEAK 0

/* The Darwin linker imposes two limitations on common symbols: they 
   can't have hidden visibility, and they can't appear in dylibs.  As
   a consequence, we should never use common symbols to represent 
   vague linkage. */
#undef USE_COMMON_FOR_ONE_ONLY
#define USE_COMMON_FOR_ONE_ONLY 0

/* The Darwin linker doesn't want coalesced symbols to appear in
   a static archive's table of contents. */
#undef TARGET_WEAK_NOT_IN_ARCHIVE_TOC
#define TARGET_WEAK_NOT_IN_ARCHIVE_TOC 1

/* We make exception information linkonce. */
#undef TARGET_USES_WEAK_UNWIND_INFO
#define TARGET_USES_WEAK_UNWIND_INFO 1

/* We need to use a nonlocal label for the start of an EH frame: the
   Darwin linker requires that a coalesced section start with a label. */
#undef FRAME_BEGIN_LABEL
#define FRAME_BEGIN_LABEL "EH_frame"

/* Emit a label for the FDE corresponding to DECL.  EMPTY means 
   emit a label for an empty FDE. */
#define TARGET_ASM_EMIT_UNWIND_LABEL darwin_emit_unwind_label

/* Our profiling scheme doesn't LP labels and counter words.  */

#define NO_PROFILE_COUNTERS	1

#undef	INIT_SECTION_ASM_OP
#define INIT_SECTION_ASM_OP

#undef	INVOKE__main

#define TARGET_ASM_CONSTRUCTOR  machopic_asm_out_constructor
#define TARGET_ASM_DESTRUCTOR   machopic_asm_out_destructor

/* Always prefix with an underscore.  */

#define USER_LABEL_PREFIX "_"

/* Don't output a .file directive.  That is only used by the assembler for
   error reporting.  */
#undef	TARGET_ASM_FILE_START_FILE_DIRECTIVE
#define TARGET_ASM_FILE_START_FILE_DIRECTIVE false

#undef  TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END darwin_file_end

#define ASM_OUTPUT_SKIP(FILE,SIZE)  \
  fprintf (FILE, "\t.space "HOST_WIDE_INT_PRINT_UNSIGNED"\n", SIZE)

/* Give ObjC methods pretty symbol names.  */

#undef	OBJC_GEN_METHOD_LABEL
#define OBJC_GEN_METHOD_LABEL(BUF,IS_INST,CLASS_NAME,CAT_NAME,SEL_NAME,NUM) \
  do { if (CAT_NAME)							\
	 sprintf (BUF, "%c[%s(%s) %s]", (IS_INST) ? '-' : '+',		\
		  (CLASS_NAME), (CAT_NAME), (SEL_NAME));		\
       else								\
	 sprintf (BUF, "%c[%s %s]", (IS_INST) ? '-' : '+',		\
		  (CLASS_NAME), (SEL_NAME));				\
     } while (0)

/* The RTTI data (e.g., __ti4name) is common and public (and static),
   but it does need to be referenced via indirect PIC data pointers.
   The machopic_define_symbol calls are telling the machopic subsystem
   that the name *is* defined in this module, so it doesn't need to
   make them indirect.  */

#undef ASM_DECLARE_OBJECT_NAME
#define ASM_DECLARE_OBJECT_NAME(FILE, NAME, DECL)			\
  do {									\
    const char *xname = NAME;						\
    if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\
      xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\
    if (! DECL_WEAK (DECL)						\
        && ((TREE_STATIC (DECL)						\
	     && (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
            || DECL_INITIAL (DECL)))					\
        machopic_define_symbol (DECL_RTL (DECL));			\
    if ((TREE_STATIC (DECL)						\
	 && (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
        || DECL_INITIAL (DECL))						\
      (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\
    ASM_OUTPUT_LABEL (FILE, xname);					\
    /* Darwin doesn't support zero-size objects, so give them a		\
       byte.  */							\
    if (tree_low_cst (DECL_SIZE_UNIT (DECL), 1) == 0)			\
      assemble_zeros (1);						\
  } while (0)

#define ASM_DECLARE_FUNCTION_NAME(FILE, NAME, DECL)			\
  do {									\
    const char *xname = NAME;						\
    if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\
      xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\
    if (! DECL_WEAK (DECL)						\
        && ((TREE_STATIC (DECL)						\
	     && (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
            || DECL_INITIAL (DECL)))					\
        machopic_define_symbol (DECL_RTL (DECL));			\
    if ((TREE_STATIC (DECL)						\
	 && (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
        || DECL_INITIAL (DECL))						\
      (* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\
    ASM_OUTPUT_LABEL (FILE, xname);					\
  } while (0)

#define ASM_DECLARE_CONSTANT_NAME(FILE, NAME, EXP, SIZE)	\
  do {								\
    ASM_OUTPUT_LABEL (FILE, NAME);				\
    /* Darwin doesn't support zero-size objects, so give them a	\
       byte.  */						\
    if ((SIZE) == 0)						\
      assemble_zeros (1);					\
  } while (0)

/* Wrap new method names in quotes so the assembler doesn't gag.
   Make Objective-C internal symbols local.  */

#undef	ASM_OUTPUT_LABELREF
#define ASM_OUTPUT_LABELREF(FILE,NAME)					     \
  do {									     \
       const char *xname = (NAME);					     \
       if (! strcmp (xname, "<pic base>"))				     \
         machopic_output_function_base_name(FILE);                           \
       else if (xname[0] == '&' || xname[0] == '*')			     \
         {								     \
           int len = strlen (xname);					     \
	   if (len > 6 && !strcmp ("$stub", xname + len - 5))		     \
	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \
	   else if (len > 7 && !strcmp ("$stub\"", xname + len - 6))	     \
	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \
	   else if (len > 14 && !strcmp ("$non_lazy_ptr", xname + len - 13)) \
	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \
	   else if (len > 15 && !strcmp ("$non_lazy_ptr\"", xname + len - 14)) \
	     machopic_validate_stub_or_non_lazy_ptr (xname);		     \
	   if (xname[1] != '"' && name_needs_quotes (&xname[1]))	     \
	     fprintf (FILE, "\"%s\"", &xname[1]);			     \
	   else								     \
	     fputs (&xname[1], FILE); 					     \
	 }								     \
       else if (xname[0] == '+' || xname[0] == '-')			     \
         fprintf (FILE, "\"%s\"", xname);				     \
       else if (!strncmp (xname, "_OBJC_", 6))				     \
         fprintf (FILE, "L%s", xname);					     \
       else if (!strncmp (xname, ".objc_class_name_", 17))		     \
	 fprintf (FILE, "%s", xname);					     \
       else if (xname[0] != '"' && name_needs_quotes (xname))		     \
	 fprintf (FILE, "\"%s\"", xname);				     \
       else								     \
         asm_fprintf (FILE, "%U%s", xname);				     \
  } while (0)

/* Output before executable code.  */
#undef TEXT_SECTION_ASM_OP
#define TEXT_SECTION_ASM_OP "\t.text"

/* Output before writable data.  */

#undef DATA_SECTION_ASM_OP
#define DATA_SECTION_ASM_OP "\t.data"

#undef	ALIGN_ASM_OP
#define ALIGN_ASM_OP		".align"

#undef	ASM_OUTPUT_ALIGN
#define ASM_OUTPUT_ALIGN(FILE,LOG)	\
  if ((LOG) != 0)			\
    fprintf (FILE, "\t%s %d\n", ALIGN_ASM_OP, (LOG))

/* Ensure correct alignment of bss data.  */

#undef	ASM_OUTPUT_ALIGNED_DECL_LOCAL					
#define ASM_OUTPUT_ALIGNED_DECL_LOCAL(FILE, DECL, NAME, SIZE, ALIGN)	\
  do {									\
    unsigned HOST_WIDE_INT _new_size = SIZE;				\
    fputs (".lcomm ", (FILE));						\
    assemble_name ((FILE), (NAME));					\
    if (_new_size == 0) _new_size = 1;					\
    fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", _new_size,	\
	     floor_log2 ((ALIGN) / BITS_PER_UNIT));			\
    if ((DECL) && ((TREE_STATIC (DECL)					\
	 && (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
        || DECL_INITIAL (DECL)))					\
      {									\
	(* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\
	machopic_define_symbol (DECL_RTL (DECL));			\
      }									\
  } while (0)

/* The maximum alignment which the object file format can support.
   For Mach-O, this is 2^15.  */

#undef	MAX_OFILE_ALIGNMENT
#define MAX_OFILE_ALIGNMENT 0x8000

/* Create new Mach-O sections.  */

#undef	SECTION_FUNCTION
#define SECTION_FUNCTION(FUNCTION, SECTION, DIRECTIVE, OBJC)		\
extern void FUNCTION (void);						\
void									\
FUNCTION (void)								\
{									\
  if (in_section != SECTION)						\
    {									\
      if (OBJC)								\
	objc_section_init ();						\
      if (asm_out_file)							\
	fputs ("\t" DIRECTIVE "\n", asm_out_file);			\
      in_section = SECTION;						\
      if ((SECTION == in_text_coal)                                     \
	  || (SECTION == in_text_unlikely)                              \
	  || (SECTION == in_text_unlikely_coal))                        \
        last_text_section = SECTION;                                    \
    }									\
}									\

/* Darwin uses many types of special sections.  */

#undef	EXTRA_SECTIONS
#define EXTRA_SECTIONS							\
  in_text_coal, in_text_unlikely, in_text_unlikely_coal,		\
  in_const, in_const_data, in_cstring, in_literal4, in_literal8,	\
  in_const_coal, in_const_data_coal, in_data_coal,			\
  in_constructor, in_destructor, in_mod_init, in_mod_term,		\
  in_objc_class, in_objc_meta_class, in_objc_category,			\
  in_objc_class_vars, in_objc_instance_vars,				\
  in_objc_cls_meth, in_objc_inst_meth,					\
  in_objc_cat_cls_meth, in_objc_cat_inst_meth,				\
  in_objc_selector_refs,						\
  in_objc_selector_fixup,						\
  in_objc_symbols, in_objc_module_info,					\
  in_objc_protocol, in_objc_string_object,				\
  in_objc_constant_string_object,					\
  in_objc_image_info,							\
  in_objc_class_names, in_objc_meth_var_names,				\
  in_objc_meth_var_types, in_objc_cls_refs,				\
  in_machopic_nl_symbol_ptr,						\
  in_machopic_lazy_symbol_ptr,						\
  in_machopic_symbol_stub,						\
  in_machopic_symbol_stub1,						\
  in_machopic_picsymbol_stub,						\
  in_machopic_picsymbol_stub1,						\
  in_darwin_exception, in_darwin_eh_frame,				\
  num_sections

#undef	EXTRA_SECTION_FUNCTIONS
#define EXTRA_SECTION_FUNCTIONS					\
static void objc_section_init (void);				\
SECTION_FUNCTION (text_coal_section,				\
		  in_text_coal,					\
		  ".section __TEXT,__textcoal_nt,coalesced,"	\
		    "pure_instructions", 0)			\
SECTION_FUNCTION (text_unlikely_coal_section,			\
		  in_text_unlikely_coal,			\
		  ".section __TEXT,__text_unlikely_coal,"	\
		    "coalesced,pure_instructions", 0)		\
SECTION_FUNCTION (const_section,				\
                  in_const,					\
                  ".const", 0)					\
SECTION_FUNCTION (const_coal_section,				\
		  in_const_coal,				\
		  ".section __TEXT,__const_coal,coalesced", 0)	\
SECTION_FUNCTION (const_data_section,				\
                  in_const_data,				\
                  ".const_data", 0)				\
SECTION_FUNCTION (const_data_coal_section,			\
                  in_const_data_coal,				\
                  ".section __DATA,__const_coal,coalesced", 0)	\
SECTION_FUNCTION (data_coal_section,				\
                  in_data_coal,					\
                  ".section __DATA,__datacoal_nt,coalesced", 0)	\
SECTION_FUNCTION (cstring_section,				\
		  in_cstring,					\
		  ".cstring", 0)				\
SECTION_FUNCTION (literal4_section,				\
		  in_literal4,					\
		  ".literal4", 0)				\
SECTION_FUNCTION (literal8_section,				\
		  in_literal8,					\
		  ".literal8", 0)				\
SECTION_FUNCTION (constructor_section,				\
		  in_constructor,				\
		  ".constructor", 0)				\
SECTION_FUNCTION (mod_init_section,				\
		  in_mod_init,					\
		  ".mod_init_func", 0)				\
SECTION_FUNCTION (mod_term_section,				\
		  in_mod_term,					\
		  ".mod_term_func", 0)				\
SECTION_FUNCTION (destructor_section,				\
		  in_destructor,				\
		  ".destructor", 0)				\
SECTION_FUNCTION (objc_class_section,				\
		  in_objc_class,				\
		  ".objc_class", 1)				\
SECTION_FUNCTION (objc_meta_class_section,			\
		  in_objc_meta_class,				\
		  ".objc_meta_class", 1)			\
SECTION_FUNCTION (objc_category_section,			\
		  in_objc_category,				\
		".objc_category", 1)				\
SECTION_FUNCTION (objc_class_vars_section,			\
		  in_objc_class_vars,				\
		  ".objc_class_vars", 1)			\
SECTION_FUNCTION (objc_instance_vars_section,			\
		  in_objc_instance_vars,			\
		  ".objc_instance_vars", 1)			\
SECTION_FUNCTION (objc_cls_meth_section,			\
		  in_objc_cls_meth,				\
		  ".objc_cls_meth", 1)				\
SECTION_FUNCTION (objc_inst_meth_section,			\
		  in_objc_inst_meth,				\
		  ".objc_inst_meth", 1)				\
SECTION_FUNCTION (objc_cat_cls_meth_section,			\
		  in_objc_cat_cls_meth,				\
		  ".objc_cat_cls_meth", 1)			\
SECTION_FUNCTION (objc_cat_inst_meth_section,			\
		  in_objc_cat_inst_meth,			\
		  ".objc_cat_inst_meth", 1)			\
SECTION_FUNCTION (objc_selector_refs_section,			\
		  in_objc_selector_refs,			\
		  ".objc_message_refs", 1)			\
SECTION_FUNCTION (objc_selector_fixup_section,				     \
		  in_objc_selector_fixup,				     \
		  ".section __OBJC, __sel_fixup, regular, no_dead_strip", 1) \
SECTION_FUNCTION (objc_symbols_section,					\
		  in_objc_symbols,					\
		  ".objc_symbols", 1)					\
SECTION_FUNCTION (objc_module_info_section,				\
		  in_objc_module_info,					\
		  ".objc_module_info", 1)				\
SECTION_FUNCTION (objc_protocol_section,				\
		  in_objc_protocol,					\
		  ".objc_protocol", 1)					\
SECTION_FUNCTION (objc_string_object_section,				\
		  in_objc_string_object,				\
		  ".objc_string_object", 1)				\
SECTION_FUNCTION (objc_constant_string_object_section,			\
		  in_objc_constant_string_object,			\
		  ".section __OBJC, __cstring_object, regular, "	\
		    "no_dead_strip", 1)					\
/* Fix-and-Continue image marker.  */					\
SECTION_FUNCTION (objc_image_info_section,				\
                  in_objc_image_info,					\
                  ".section __OBJC, __image_info, regular, "		\
		    "no_dead_strip", 1)					\
SECTION_FUNCTION (objc_class_names_section,				\
		in_objc_class_names,					\
		".objc_class_names", 1)					\
SECTION_FUNCTION (objc_meth_var_names_section,				\
		in_objc_meth_var_names,					\
		".objc_meth_var_names", 1)				\
SECTION_FUNCTION (objc_meth_var_types_section,				\
		in_objc_meth_var_types,					\
		".objc_meth_var_types", 1)				\
SECTION_FUNCTION (objc_cls_refs_section,				\
		in_objc_cls_refs,					\
		".objc_cls_refs", 1)					\
\
SECTION_FUNCTION (machopic_lazy_symbol_ptr_section,			\
		in_machopic_lazy_symbol_ptr,				\
		".lazy_symbol_pointer", 0)				\
SECTION_FUNCTION (machopic_nl_symbol_ptr_section,			\
		in_machopic_nl_symbol_ptr,				\
		".non_lazy_symbol_pointer", 0)				\
SECTION_FUNCTION (machopic_symbol_stub_section,				\
		in_machopic_symbol_stub,				\
		".symbol_stub", 0)					\
SECTION_FUNCTION (machopic_symbol_stub1_section,			\
		in_machopic_symbol_stub1,				\
		".section __TEXT,__symbol_stub1,symbol_stubs,"		\
		  "pure_instructions,16", 0)				\
SECTION_FUNCTION (machopic_picsymbol_stub_section,			\
		in_machopic_picsymbol_stub,				\
		".picsymbol_stub", 0)					\
SECTION_FUNCTION (machopic_picsymbol_stub1_section,			\
		in_machopic_picsymbol_stub1,				\
		".section __TEXT,__picsymbolstub1,symbol_stubs,"	\
		  "pure_instructions,32", 0)				\
SECTION_FUNCTION (darwin_exception_section,				\
		in_darwin_exception,					\
		".section __DATA,__gcc_except_tab", 0)			\
SECTION_FUNCTION (darwin_eh_frame_section,				\
		in_darwin_eh_frame,					\
		".section " EH_FRAME_SECTION_NAME ",__eh_frame"		\
		  EH_FRAME_SECTION_ATTR, 0)				\
\
static void					\
objc_section_init (void)			\
{						\
  static int been_here = 0;			\
						\
  if (been_here == 0)				\
    {						\
      been_here = 1;				\
          /* written, cold -> hot */		\
      objc_cat_cls_meth_section ();		\
      objc_cat_inst_meth_section ();		\
      objc_string_object_section ();		\
      objc_constant_string_object_section ();	\
      objc_selector_refs_section ();		\
      objc_selector_fixup_section ();		\
      objc_cls_refs_section ();			\
      objc_class_section ();			\
      objc_meta_class_section ();		\
          /* shared, hot -> cold */		\
      objc_cls_meth_section ();			\
      objc_inst_meth_section ();		\
      objc_protocol_section ();			\
      objc_class_names_section ();		\
      objc_meth_var_types_section ();		\
      objc_meth_var_names_section ();		\
      objc_category_section ();			\
      objc_class_vars_section ();		\
      objc_instance_vars_section ();		\
      objc_module_info_section ();		\
      objc_symbols_section ();			\
    }						\
}

#define READONLY_DATA_SECTION const_section

#undef	TARGET_ASM_SELECT_SECTION
#define TARGET_ASM_SELECT_SECTION machopic_select_section
#define USE_SELECT_SECTION_FOR_FUNCTIONS

#undef	TARGET_ASM_SELECT_RTX_SECTION
#define TARGET_ASM_SELECT_RTX_SECTION machopic_select_rtx_section
#undef  TARGET_ASM_UNIQUE_SECTION
#define TARGET_ASM_UNIQUE_SECTION darwin_unique_section
#undef  TARGET_ASM_FUNCTION_RODATA_SECTION
#define TARGET_ASM_FUNCTION_RODATA_SECTION default_no_function_rodata_section


#define ASM_DECLARE_UNRESOLVED_REFERENCE(FILE,NAME)			\
    do {								\
	 if (FILE) {							\
	   if (MACHOPIC_INDIRECT)					\
	     fprintf (FILE, "\t.lazy_reference ");			\
	   else								\
	     fprintf (FILE, "\t.reference ");				\
	   assemble_name (FILE, NAME);					\
	   fprintf (FILE, "\n");					\
	 }                                                              \
       } while (0)

#define ASM_DECLARE_CLASS_REFERENCE(FILE,NAME)				\
    do {								\
	 if (FILE) {							\
	   fprintf (FILE, "\t");					\
	   assemble_name (FILE, NAME);					\
	   fprintf (FILE, "=0\n");					\
	   (*targetm.asm_out.globalize_label) (FILE, NAME);		\
	 }								\
       } while (0)

/* Globalizing directive for a label.  */
#define GLOBAL_ASM_OP ".globl "
#define TARGET_ASM_GLOBALIZE_LABEL darwin_globalize_label

/* Emit an assembler directive to set visibility for a symbol.  Used
   to support visibility attribute and Darwin's private extern
   feature.  */
#undef TARGET_ASM_ASSEMBLE_VISIBILITY
#define TARGET_ASM_ASSEMBLE_VISIBILITY darwin_assemble_visibility

/* Extra attributes for Darwin.  */
#define SUBTARGET_ATTRIBUTE_TABLE					     \
  /* { name, min_len, max_len, decl_req, type_req, fn_type_req, handler } */ \
  { "weak_import", 0, 0, true, false, false,				     \
    darwin_handle_weak_import_attribute }

#undef ASM_GENERATE_INTERNAL_LABEL
#define ASM_GENERATE_INTERNAL_LABEL(LABEL,PREFIX,NUM)	\
  sprintf (LABEL, "*%s%ld", PREFIX, (long)(NUM))

#undef TARGET_ASM_MARK_DECL_PRESERVED
#define TARGET_ASM_MARK_DECL_PRESERVED darwin_mark_decl_preserved

/* Set on a symbol with SYMBOL_FLAG_FUNCTION or
   MACHO_SYMBOL_FLAG_VARIABLE to indicate that the function or
   variable has been defined in this translation unit.  */

#define MACHO_SYMBOL_FLAG_VARIABLE (SYMBOL_FLAG_MACH_DEP)
#define MACHO_SYMBOL_FLAG_DEFINED ((SYMBOL_FLAG_MACH_DEP) << 1)

/* Set on a symbol to indicate when fix-and-continue style code
   generation is being used and the symbol refers to a static symbol
   that should be rebound from new instances of a translation unit to
   the original instance of the data.  */

#define MACHO_SYMBOL_STATIC ((SYMBOL_FLAG_MACH_DEP) << 2)

/* Symbolic names for various things we might know about a symbol.  */

enum machopic_addr_class {
  MACHOPIC_UNDEFINED,
  MACHOPIC_DEFINED_DATA,
  MACHOPIC_UNDEFINED_DATA,
  MACHOPIC_DEFINED_FUNCTION,
  MACHOPIC_UNDEFINED_FUNCTION
};

/* Macros defining the various PIC cases.  */

#define MACHO_DYNAMIC_NO_PIC_P	(TARGET_DYNAMIC_NO_PIC)
#define MACHOPIC_INDIRECT	(flag_pic || MACHO_DYNAMIC_NO_PIC_P)
#define MACHOPIC_JUST_INDIRECT	(flag_pic == 1 || MACHO_DYNAMIC_NO_PIC_P)
#define MACHOPIC_PURE		(flag_pic == 2 && ! MACHO_DYNAMIC_NO_PIC_P)

#undef TARGET_ENCODE_SECTION_INFO
#define TARGET_ENCODE_SECTION_INFO  darwin_encode_section_info
#undef TARGET_STRIP_NAME_ENCODING
#define TARGET_STRIP_NAME_ENCODING  default_strip_name_encoding

#define GEN_BINDER_NAME_FOR_STUB(BUF,STUB,STUB_LENGTH)		\
  do {								\
    const char *const stub_ = (STUB);				\
    char *buffer_ = (BUF);					\
    strcpy (buffer_, stub_);					\
    if (stub_[0] == '"')					\
      {								\
	strcpy (buffer_ + (STUB_LENGTH) - 1, "_binder\"");	\
      }								\
    else							\
      {								\
	strcpy (buffer_ + (STUB_LENGTH), "_binder");		\
      }								\
  } while (0)

#define GEN_SYMBOL_NAME_FOR_SYMBOL(BUF,SYMBOL,SYMBOL_LENGTH)	\
  do {								\
    const char *const symbol_ = (SYMBOL);			\
    char *buffer_ = (BUF);					\
    if (name_needs_quotes (symbol_) && symbol_[0] != '"')	\
      {								\
	  sprintf (buffer_, "\"%s\"", symbol_);			\
      }								\
    else							\
      {								\
	strcpy (buffer_, symbol_);				\
      }								\
  } while (0)

/* Given a symbol name string, create the lazy pointer version
   of the symbol name.  */

#define GEN_LAZY_PTR_NAME_FOR_SYMBOL(BUF,SYMBOL,SYMBOL_LENGTH)	\
  do {								\
    const char *symbol_ = (SYMBOL);                             \
    char *buffer_ = (BUF);					\
    if (symbol_[0] == '"')					\
      {								\
        strcpy (buffer_, "\"L");				\
        strcpy (buffer_ + 2, symbol_ + 1);			\
	strcpy (buffer_ + (SYMBOL_LENGTH), "$lazy_ptr\"");	\
      }								\
    else if (name_needs_quotes (symbol_))			\
      {								\
        strcpy (buffer_, "\"L");				\
        strcpy (buffer_ + 2, symbol_);				\
	strcpy (buffer_ + (SYMBOL_LENGTH) + 2, "$lazy_ptr\"");	\
      }								\
    else							\
      {								\
        strcpy (buffer_, "L");					\
        strcpy (buffer_ + 1, symbol_);				\
	strcpy (buffer_ + (SYMBOL_LENGTH) + 1, "$lazy_ptr");	\
      }								\
  } while (0)

#define TARGET_ASM_EXCEPTION_SECTION darwin_exception_section

#define TARGET_ASM_EH_FRAME_SECTION darwin_eh_frame_section

#define EH_FRAME_SECTION_NAME   "__TEXT"
#define EH_FRAME_SECTION_ATTR ",coalesced,no_toc+strip_static_syms+live_support"

/* Java runtime class list.  */
#define JCR_SECTION_NAME "__DATA,jcr,regular,no_dead_strip"

#undef ASM_PREFERRED_EH_DATA_FORMAT
#define ASM_PREFERRED_EH_DATA_FORMAT(CODE,GLOBAL)  \
  (((CODE) == 2 && (GLOBAL) == 1) \
   ? (DW_EH_PE_pcrel | DW_EH_PE_indirect | DW_EH_PE_sdata4) : \
     ((CODE) == 1 || (GLOBAL) == 0) ? DW_EH_PE_pcrel : DW_EH_PE_absptr)

#define ASM_OUTPUT_DWARF_DELTA(FILE,SIZE,LABEL1,LABEL2)  \
  darwin_asm_output_dwarf_delta (FILE, SIZE, LABEL1, LABEL2)

#define ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX(ASM_OUT_FILE, ENCODING, SIZE, ADDR, DONE)	\
      if (ENCODING == ASM_PREFERRED_EH_DATA_FORMAT (2, 1)) {				\
	darwin_non_lazy_pcrel (ASM_OUT_FILE, ADDR);					\
	goto DONE;									\
      }

/* Experimentally, putting jump tables in text is faster on SPEC.
   Also this is needed for correctness for coalesced functions.  */

#ifndef JUMP_TABLES_IN_TEXT_SECTION
#define JUMP_TABLES_IN_TEXT_SECTION 1
#endif

#define TARGET_TERMINATE_DW2_EH_FRAME_INFO false

#undef TARGET_ASM_NAMED_SECTION
#define TARGET_ASM_NAMED_SECTION darwin_asm_named_section

#define DARWIN_REGISTER_TARGET_PRAGMAS()			\
  do {								\
    c_register_pragma (0, "mark", darwin_pragma_ignore);	\
    c_register_pragma (0, "options", darwin_pragma_options);	\
    c_register_pragma (0, "segment", darwin_pragma_ignore);	\
    c_register_pragma (0, "unused", darwin_pragma_unused);	\
  } while (0)

#undef ASM_APP_ON
#define ASM_APP_ON ""
#undef ASM_APP_OFF
#define ASM_APP_OFF ""

void darwin_register_frameworks (const char *, const char *, int);
void darwin_register_objc_includes (const char *, const char *, int);
#define TARGET_EXTRA_PRE_INCLUDES darwin_register_objc_includes
#define TARGET_EXTRA_INCLUDES darwin_register_frameworks

void add_framework_path (char *);
#define TARGET_OPTF add_framework_path

#define TARGET_POSIX_IO

/* All new versions of Darwin have C99 functions.  */
#define TARGET_C99_FUNCTIONS 1

#define WINT_TYPE "int"

#endif /* CONFIG_DARWIN_H */
