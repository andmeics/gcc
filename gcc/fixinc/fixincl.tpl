[= autogen template -*- Mode: C -*-
x =]
/*
 *  DO NOT EDIT THIS FILE - it has been generated
 *
 * Install modified versions of certain ANSI-incompatible system header
 * files which are fixed to work correctly with ANSI C and placed in a
 * directory that GNU C will search.
 *
 * This file contains [=_eval fix _count =] fixup descriptions.
 *
 * See README-fixinc for more information.
 *
 *  inclhack copyright (c) 1998, 1999, 2000
 *  The Free Software Foundation, Inc.
 *
[=_eval inclhack "# *  " _gpl=]
 */
[= _SETENV re_ct 0 =][= _SETENV max_mach 0 =][=

_FOR fix =]
/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Description of [=hackname _cap=] fix
 */[=

# Note that this is not just for debugging purposes, but in case
  some C fix wishes to refer to the regexps it is paired with.
  See commentary at the top of fixfixes.c.
=]
#define [=hackname _up #_FIXIDX + #%-32s _printf=] [=_eval _index=]
tSCC z[=hackname _cap=]Name[] =
     [=hackname _krstr=];

/*
 *  File name selection pattern
 */[=

  _IF files _exist=]
tSCC z[=hackname _cap=]List[] =
  "[=_FOR files =]|[=files=][=/files=]|";[=

  _ELSE =]
#define z[=hackname _cap=]List (char*)NULL[=
  _ENDIF "files _exist" =]
/*
 *  Machine/OS name selection pattern
 */[=

  _IF mach _exist=]
tSCC* apz[=hackname _cap=]Machs[] = {[=
    _SETENV this_mach 0 =][=

    _FOR mach =]
        [=mach _krstr=],[=
      _SETENV this_mach mach _len this_mach _env _val 5 + +
      =][= /mach=]
        (const char*)NULL };[=

    _SETENV max_mach _mark this_mach _env _val max_mach _env _val _max =][=

  _ELSE =]
#define apz[=hackname _cap=]Machs (const char**)NULL[=
  _ENDIF "files _exist" =][=

  _IF select _exist=]

/*
 *  content selection pattern - do fix if pattern found
 */[=
    _FOR select =]
tSCC z[=hackname _cap=]Select[=_eval _index=][] =
       [=select _krstr=];[=
    /select =][=
  _ENDIF =][=

  _IF bypass _exist=]

/*
 *  content bypass pattern - skip fix if pattern found
 */[=
    _FOR bypass =]
tSCC z[=hackname _cap=]Bypass[=_eval _index=][] =
       [=bypass _krstr=];[=
    /bypass =][=
  _ENDIF =][=

  _IF test _exist=]

/*
 *  perform the 'test' shell command - do fix on success
 */[=
    _FOR test =]
tSCC z[=hackname _cap=]Test[=_eval _index=][] =
       [=test _krstr=];[=
    /test =][=
  _ENDIF =][=

  _IF c_test _exist=]

/*
 *  perform the C function call test
 */[=
    _FOR c_test =]
tSCC z[=hackname _cap=]FTst[=_eval _index=][] = "[=c_test=]";[=
    /c_test =][=
  _ENDIF =][=


#  Build the array of test descriptions for this fix: =][=

  _IF select  _exist
      bypass  _exist |
      test    _exist |
      c_test  _exist |
=]

#define    [=hackname _up =]_TEST_CT  [=
       _eval select       _count
             bypass       _count +
             test         _count + 
             c_test       _count + =][=
_SETENV re_ct
	re_ct _env _val
	select _count +
	bypass _count + =]
tTestDesc a[=hackname _cap=]Tests[] = {[=

    _FOR test =]
  { TT_TEST,     z[=hackname _cap=]Test[=_eval _index=],   0 /* unused */ },[=
    /test =][=

    _FOR c_test =]
  { TT_FUNCTION, z[=hackname _cap=]FTst[=_eval _index=],   0 /* unused */ },[=
    /c_test =][=

    _FOR bypass =]
  { TT_NEGREP,   z[=hackname _cap=]Bypass[=_eval _index=], (regex_t*)NULL },[=
    /bypass =][=

      _FOR select =]
  { TT_EGREP,    z[=hackname _cap=]Select[=_eval _index=], (regex_t*)NULL },[=
      /select =] };[=
  _ELSE =]
#define [=hackname _up=]_TEST_CT  0
#define a[=hackname _cap=]Tests   (tTestDesc*)NULL[=
  _ENDIF =]

/*
 *  Fix Command Arguments for [=hackname _cap=]
 */
const char* apz[=hackname _cap=]Patch[] = {[=
    _IF   sed         _exist =] "sed"[=
      _FOR sed=],
    "-e", [=sed _krstr=][=
      /sed=],[=

    _ELIF shell       _exist =] "sh", "-c",
    [=shell _krstr=],[=

    _ELIF c_fix _exist =]"[=c_fix=]",[=

    _ELIF replace _len =]
[=replace _krstr=],[=

    _ENDIF=]
    (char*)NULL };
[=/fix=]

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  List of all fixes
 */[=
#  as of this writing, 49 bytes are needed by the case statement format.
   We also must allow for the size of the target machine machine name.
   This allows for a 79 byte machine name.  Better be enough.
=]
#define REGEX_COUNT          [= _eval re_ct _env =]
#define MACH_LIST_SIZE_LIMIT [= _eval max_mach _env _val 128 + =]
#define FIX_COUNT            [= _eval fix _count =]

tFixDesc fixDescList[ FIX_COUNT ] = {[=


_FOR fix ",\n" =]
  {  z[=hackname _cap=]Name,    z[=hackname _cap=]List,
     apz[=hackname _cap=]Machs, (regex_t*)NULL,
     [=hackname  _up=]_TEST_CT, [=
       _IF not_machine _exist =]FD_MACH_IFNOT[=
       _ELSE                  =]FD_MACH_ONLY[=
       _ENDIF =][=
       _IF    shell    _exist =] | FD_SHELL_SCRIPT[=
       _ELIF  c_fix    _exist =] | FD_SUBROUTINE[=
       _ELIF  replace  _exist =] | FD_REPLACEMENT[=
       _ENDIF =],
     a[=hackname _cap=]Tests,   apz[=hackname _cap=]Patch }[=

/fix=]
};
