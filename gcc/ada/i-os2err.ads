------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--               I N T E R F A C E S . O S 2 L I B . E R R O R S            --
--                                                                          --
--                                  S p e c                                 --
--                                                                          --
--                             $Revision: 1.1.16.1 $
--                                                                          --
--        Copyright (C) 1993,1994,1995 Free Software Foundation, Inc.       --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  Definition of values for OS/2 error returns

package Interfaces.OS2Lib.Errors is
pragma Preelaborate (Errors);

   NO_ERROR                        : constant :=     0;
   ERROR_INVALID_FUNCTION          : constant :=     1;
   ERROR_FILE_NOT_FOUND            : constant :=     2;
   ERROR_PATH_NOT_FOUND            : constant :=     3;
   ERROR_TOO_MANY_OPEN_FILES       : constant :=     4;
   ERROR_ACCESS_DENIED             : constant :=     5;
   ERROR_INVALID_HANDLE            : constant :=     6;
   ERROR_ARENA_TRASHED             : constant :=     7;
   ERROR_NOT_ENOUGH_MEMORY         : constant :=     8;
   ERROR_INVALID_BLOCK             : constant :=     9;
   ERROR_BAD_ENVIRONMENT           : constant :=    10;
   ERROR_BAD_FORMAT                : constant :=    11;
   ERROR_INVALID_ACCESS            : constant :=    12;
   ERROR_INVALID_DATA              : constant :=    13;
   ERROR_INVALID_DRIVE             : constant :=    15;
   ERROR_CURRENT_DIRECTORY         : constant :=    16;
   ERROR_NOT_SAME_DEVICE           : constant :=    17;
   ERROR_NO_MORE_FILES             : constant :=    18;
   ERROR_WRITE_PROTECT             : constant :=    19;
   ERROR_BAD_UNIT                  : constant :=    20;
   ERROR_NOT_READY                 : constant :=    21;
   ERROR_BAD_COMMAND               : constant :=    22;
   ERROR_CRC                       : constant :=    23;
   ERROR_BAD_LENGTH                : constant :=    24;
   ERROR_SEEK                      : constant :=    25;
   ERROR_NOT_DOS_DISK              : constant :=    26;
   ERROR_SECTOR_NOT_FOUND          : constant :=    27;
   ERROR_OUT_OF_PAPER              : constant :=    28;
   ERROR_WRITE_FAULT               : constant :=    29;
   ERROR_READ_FAULT                : constant :=    30;
   ERROR_GEN_FAILURE               : constant :=    31;
   ERROR_SHARING_VIOLATION         : constant :=    32;
   ERROR_LOCK_VIOLATION            : constant :=    33;
   ERROR_WRONG_DISK                : constant :=    34;
   ERROR_FCB_UNAVAILABLE           : constant :=    35;
   ERROR_SHARING_BUFFER_EXCEEDED   : constant :=    36;
   ERROR_CODE_PAGE_MISMATCHED      : constant :=    37;
   ERROR_HANDLE_EOF                : constant :=    38;
   ERROR_HANDLE_DISK_FULL          : constant :=    39;
   ERROR_NOT_SUPPORTED             : constant :=    50;
   ERROR_REM_NOT_LIST              : constant :=    51;
   ERROR_DUP_NAME                  : constant :=    52;
   ERROR_BAD_NETPATH               : constant :=    53;
   ERROR_NETWORK_BUSY              : constant :=    54;
   ERROR_DEV_NOT_EXIST             : constant :=    55;
   ERROR_TOO_MANY_CMDS             : constant :=    56;
   ERROR_ADAP_HDW_ERR              : constant :=    57;
   ERROR_BAD_NET_RESP              : constant :=    58;
   ERROR_UNEXP_NET_ERR             : constant :=    59;
   ERROR_BAD_REM_ADAP              : constant :=    60;
   ERROR_PRINTQ_FULL               : constant :=    61;
   ERROR_NO_SPOOL_SPACE            : constant :=    62;
   ERROR_PRINT_CANCELLED           : constant :=    63;
   ERROR_NETNAME_DELETED           : constant :=    64;
   ERROR_NETWORK_ACCESS_DENIED     : constant :=    65;
   ERROR_BAD_DEV_TYPE              : constant :=    66;
   ERROR_BAD_NET_NAME              : constant :=    67;
   ERROR_TOO_MANY_NAMES            : constant :=    68;
   ERROR_TOO_MANY_SESS             : constant :=    69;
   ERROR_SHARING_PAUSED            : constant :=    70;
   ERROR_REQ_NOT_ACCEP             : constant :=    71;
   ERROR_REDIR_PAUSED              : constant :=    72;
   ERROR_SBCS_ATT_WRITE_PROT       : constant :=    73;
   ERROR_SBCS_GENERAL_FAILURE      : constant :=    74;
   ERROR_XGA_OUT_MEMORY            : constant :=    75;
   ERROR_FILE_EXISTS               : constant :=    80;
   ERROR_DUP_FCB                   : constant :=    81;
   ERROR_CANNOT_MAKE               : constant :=    82;
   ERROR_FAIL_I24                  : constant :=    83;
   ERROR_OUT_OF_STRUCTURES         : constant :=    84;
   ERROR_ALREADY_ASSIGNED          : constant :=    85;
   ERROR_INVALID_PASSWORD          : constant :=    86;
   ERROR_INVALID_PARAMETER         : constant :=    87;
   ERROR_NET_WRITE_FAULT           : constant :=    88;
   ERROR_NO_PROC_SLOTS             : constant :=    89;
   ERROR_NOT_FROZEN                : constant :=    90;
   ERROR_SYS_COMP_NOT_LOADED       : constant :=    90;
   ERR_TSTOVFL                     : constant :=    91;
   ERR_TSTDUP                      : constant :=    92;
   ERROR_NO_ITEMS                  : constant :=    93;
   ERROR_INTERRUPT                 : constant :=    95;
   ERROR_DEVICE_IN_USE             : constant :=    99;
   ERROR_TOO_MANY_SEMAPHORES       : constant :=   100;
   ERROR_EXCL_SEM_ALREADY_OWNED    : constant :=   101;
   ERROR_SEM_IS_SET                : constant :=   102;
   ERROR_TOO_MANY_SEM_REQUESTS     : constant :=   103;
   ERROR_INVALID_AT_INTERRUPT_TIME : constant :=   104;
   ERROR_SEM_OWNER_DIED            : constant :=   105;
   ERROR_SEM_USER_LIMIT            : constant :=   106;
   ERROR_DISK_CHANGE               : constant :=   107;
   ERROR_DRIVE_LOCKED              : constant :=   108;
   ERROR_BROKEN_PIPE               : constant :=   109;
   ERROR_OPEN_FAILED               : constant :=   110;
   ERROR_BUFFER_OVERFLOW           : constant :=   111;
   ERROR_DISK_FULL                 : constant :=   112;
   ERROR_NO_MORE_SEARCH_HANDLES    : constant :=   113;
   ERROR_INVALID_TARGET_HANDLE     : constant :=   114;
   ERROR_PROTECTION_VIOLATION      : constant :=   115;
   ERROR_VIOKBD_REQUEST            : constant :=   116;
   ERROR_INVALID_CATEGORY          : constant :=   117;
   ERROR_INVALID_VERIFY_SWITCH     : constant :=   118;
   ERROR_BAD_DRIVER_LEVEL          : constant :=   119;
   ERROR_CALL_NOT_IMPLEMENTED      : constant :=   120;
   ERROR_SEM_TIMEOUT               : constant :=   121;
   ERROR_INSUFFICIENT_BUFFER       : constant :=   122;
   ERROR_INVALID_NAME              : constant :=   123;
   ERROR_INVALID_LEVEL             : constant :=   124;
   ERROR_NO_VOLUME_LABEL           : constant :=   125;
   ERROR_MOD_NOT_FOUND             : constant :=   126;
   ERROR_PROC_NOT_FOUND            : constant :=   127;
   ERROR_WAIT_NO_CHILDREN          : constant :=   128;
   ERROR_CHILD_NOT_COMPLETE        : constant :=   129;
   ERROR_DIRECT_ACCESS_HANDLE      : constant :=   130;
   ERROR_NEGATIVE_SEEK             : constant :=   131;
   ERROR_SEEK_ON_DEVICE            : constant :=   132;
   ERROR_IS_JOIN_TARGET            : constant :=   133;
   ERROR_IS_JOINED                 : constant :=   134;
   ERROR_IS_SUBSTED                : constant :=   135;
   ERROR_NOT_JOINED                : constant :=   136;
   ERROR_NOT_SUBSTED               : constant :=   137;
   ERROR_JOIN_TO_JOIN              : constant :=   138;
   ERROR_SUBST_TO_SUBST            : constant :=   139;
   ERROR_JOIN_TO_SUBST             : constant :=   140;
   ERROR_SUBST_TO_JOIN             : constant :=   141;
   ERROR_BUSY_DRIVE                : constant :=   142;
   ERROR_SAME_DRIVE                : constant :=   143;
   ERROR_DIR_NOT_ROOT              : constant :=   144;
   ERROR_DIR_NOT_EMPTY             : constant :=   145;
   ERROR_IS_SUBST_PATH             : constant :=   146;
   ERROR_IS_JOIN_PATH              : constant :=   147;
   ERROR_PATH_BUSY                 : constant :=   148;
   ERROR_IS_SUBST_TARGET           : constant :=   149;
   ERROR_SYSTEM_TRACE              : constant :=   150;
   ERROR_INVALID_EVENT_COUNT       : constant :=   151;
   ERROR_TOO_MANY_MUXWAITERS       : constant :=   152;
   ERROR_INVALID_LIST_FORMAT       : constant :=   153;
   ERROR_LABEL_TOO_LONG            : constant :=   154;
   ERROR_TOO_MANY_TCBS             : constant :=   155;
   ERROR_SIGNAL_REFUSED            : constant :=   156;
   ERROR_DISCARDED                 : constant :=   157;
   ERROR_NOT_LOCKED                : constant :=   158;
   ERROR_BAD_THREADID_ADDR         : constant :=   159;
   ERROR_BAD_ARGUMENTS             : constant :=   160;
   ERROR_BAD_PATHNAME              : constant :=   161;
   ERROR_SIGNAL_PENDING            : constant :=   162;
   ERROR_UNCERTAIN_MEDIA           : constant :=   163;
   ERROR_MAX_THRDS_REACHED         : constant :=   164;
   ERROR_MONITORS_NOT_SUPPORTED    : constant :=   165;
   ERROR_UNC_DRIVER_NOT_INSTALLED  : constant :=   166;
   ERROR_LOCK_FAILED               : constant :=   167;
   ERROR_SWAPIO_FAILED             : constant :=   168;
   ERROR_SWAPIN_FAILED             : constant :=   169;
   ERROR_BUSY                      : constant :=   170;
   ERROR_CANCEL_VIOLATION          : constant :=   173;
   ERROR_ATOMIC_LOCK_NOT_SUPPORTED : constant :=   174;
   ERROR_READ_LOCKS_NOT_SUPPORTED  : constant :=   175;
   ERROR_INVALID_SEGMENT_NUMBER    : constant :=   180;
   ERROR_INVALID_CALLGATE          : constant :=   181;
   ERROR_INVALID_ORDINAL           : constant :=   182;
   ERROR_ALREADY_EXISTS            : constant :=   183;
   ERROR_NO_CHILD_PROCESS          : constant :=   184;
   ERROR_CHILD_ALIVE_NOWAIT        : constant :=   185;
   ERROR_INVALID_FLAG_NUMBER       : constant :=   186;
   ERROR_SEM_NOT_FOUND             : constant :=   187;
   ERROR_INVALID_STARTING_CODESEG  : constant :=   188;
   ERROR_INVALID_STACKSEG          : constant :=   189;
   ERROR_INVALID_MODULETYPE        : constant :=   190;
   ERROR_INVALID_EXE_SIGNATURE     : constant :=   191;
   ERROR_EXE_MARKED_INVALID        : constant :=   192;
   ERROR_BAD_EXE_FORMAT            : constant :=   193;
   ERROR_ITERATED_DATA_EXCEEDS_64k : constant :=   194;
   ERROR_INVALID_MINALLOCSIZE      : constant :=   195;
   ERROR_DYNLINK_FROM_INVALID_RING : constant :=   196;
   ERROR_IOPL_NOT_ENABLED          : constant :=   197;
   ERROR_INVALID_SEGDPL            : constant :=   198;
   ERROR_AUTODATASEG_EXCEEDS_64k   : constant :=   199;
   ERROR_RING2SEG_MUST_BE_MOVABLE  : constant :=   200;
   ERROR_RELOC_CHAIN_XEEDS_SEGLIM  : constant :=   201;
   ERROR_INFLOOP_IN_RELOC_CHAIN    : constant :=   202;
   ERROR_ENVVAR_NOT_FOUND          : constant :=   203;
   ERROR_NOT_CURRENT_CTRY          : constant :=   204;
   ERROR_NO_SIGNAL_SENT            : constant :=   205;
   ERROR_FILENAME_EXCED_RANGE      : constant :=   206;
   ERROR_RING2_STACK_IN_USE        : constant :=   207;
   ERROR_META_EXPANSION_TOO_LONG   : constant :=   208;
   ERROR_INVALID_SIGNAL_NUMBER     : constant :=   209;
   ERROR_THREAD_1_INACTIVE         : constant :=   210;
   ERROR_INFO_NOT_AVAIL            : constant :=   211;
   ERROR_LOCKED                    : constant :=   212;
   ERROR_BAD_DYNALINK              : constant :=   213;
   ERROR_TOO_MANY_MODULES          : constant :=   214;
   ERROR_NESTING_NOT_ALLOWED       : constant :=   215;
   ERROR_CANNOT_SHRINK             : constant :=   216;
   ERROR_ZOMBIE_PROCESS            : constant :=   217;
   ERROR_STACK_IN_HIGH_MEMORY      : constant :=   218;
   ERROR_INVALID_EXITROUTINE_RING  : constant :=   219;
   ERROR_GETBUF_FAILED             : constant :=   220;
   ERROR_FLUSHBUF_FAILED           : constant :=   221;
   ERROR_TRANSFER_TOO_LONG         : constant :=   222;
   ERROR_FORCENOSWAP_FAILED        : constant :=   223;
   ERROR_SMG_NO_TARGET_WINDOW      : constant :=   224;
   ERROR_NO_CHILDREN               : constant :=   228;
   ERROR_INVALID_SCREEN_GROUP      : constant :=   229;
   ERROR_BAD_PIPE                  : constant :=   230;
   ERROR_PIPE_BUSY                 : constant :=   231;
   ERROR_NO_DATA                   : constant :=   232;
   ERROR_PIPE_NOT_CONNECTED        : constant :=   233;
   ERROR_MORE_DATA                 : constant :=   234;
   ERROR_VC_DISCONNECTED           : constant :=   240;
   ERROR_CIRCULARITY_REQUESTED     : constant :=   250;
   ERROR_DIRECTORY_IN_CDS          : constant :=   251;
   ERROR_INVALID_FSD_NAME          : constant :=   252;
   ERROR_INVALID_PATH              : constant :=   253;
   ERROR_INVALID_EA_NAME           : constant :=   254;
   ERROR_EA_LIST_INCONSISTENT      : constant :=   255;
   ERROR_EA_LIST_TOO_LONG          : constant :=   256;
   ERROR_NO_META_MATCH             : constant :=   257;
   ERROR_FINDNOTIFY_TIMEOUT        : constant :=   258;
   ERROR_NO_MORE_ITEMS             : constant :=   259;
   ERROR_SEARCH_STRUC_REUSED       : constant :=   260;
   ERROR_CHAR_NOT_FOUND            : constant :=   261;
   ERROR_TOO_MUCH_STACK            : constant :=   262;
   ERROR_INVALID_ATTR              : constant :=   263;
   ERROR_INVALID_STARTING_RING     : constant :=   264;
   ERROR_INVALID_DLL_INIT_RING     : constant :=   265;
   ERROR_CANNOT_COPY               : constant :=   266;
   ERROR_DIRECTORY                 : constant :=   267;
   ERROR_OPLOCKED_FILE             : constant :=   268;
   ERROR_OPLOCK_THREAD_EXISTS      : constant :=   269;
   ERROR_VOLUME_CHANGED            : constant :=   270;
   ERROR_FINDNOTIFY_HANDLE_IN_USE  : constant :=   271;
   ERROR_FINDNOTIFY_HANDLE_CLOSED  : constant :=   272;
   ERROR_NOTIFY_OBJECT_REMOVED     : constant :=   273;
   ERROR_ALREADY_SHUTDOWN          : constant :=   274;
   ERROR_EAS_DIDNT_FIT             : constant :=   275;
   ERROR_EA_FILE_CORRUPT           : constant :=   276;
   ERROR_EA_TABLE_FULL             : constant :=   277;
   ERROR_INVALID_EA_HANDLE         : constant :=   278;
   ERROR_NO_CLUSTER                : constant :=   279;
   ERROR_CREATE_EA_FILE            : constant :=   280;
   ERROR_CANNOT_OPEN_EA_FILE       : constant :=   281;
   ERROR_EAS_NOT_SUPPORTED         : constant :=   282;
   ERROR_NEED_EAS_FOUND            : constant :=   283;
   ERROR_DUPLICATE_HANDLE          : constant :=   284;
   ERROR_DUPLICATE_NAME            : constant :=   285;
   ERROR_EMPTY_MUXWAIT             : constant :=   286;
   ERROR_MUTEX_OWNED               : constant :=   287;
   ERROR_NOT_OWNER                 : constant :=   288;
   ERROR_PARAM_TOO_SMALL           : constant :=   289;
   ERROR_TOO_MANY_HANDLES          : constant :=   290;
   ERROR_TOO_MANY_OPENS            : constant :=   291;
   ERROR_WRONG_TYPE                : constant :=   292;
   ERROR_UNUSED_CODE               : constant :=   293;
   ERROR_THREAD_NOT_TERMINATED     : constant :=   294;
   ERROR_INIT_ROUTINE_FAILED       : constant :=   295;
   ERROR_MODULE_IN_USE             : constant :=   296;
   ERROR_NOT_ENOUGH_WATCHPOINTS    : constant :=   297;
   ERROR_TOO_MANY_POSTS            : constant :=   298;
   ERROR_ALREADY_POSTED            : constant :=   299;
   ERROR_ALREADY_RESET             : constant :=   300;
   ERROR_SEM_BUSY                  : constant :=   301;
   ERROR_INVALID_PROCID            : constant :=   303;
   ERROR_INVALID_PDELTA            : constant :=   304;
   ERROR_NOT_DESCENDANT            : constant :=   305;
   ERROR_NOT_SESSION_MANAGER       : constant :=   306;
   ERROR_INVALID_PCLASS            : constant :=   307;
   ERROR_INVALID_SCOPE             : constant :=   308;
   ERROR_INVALID_THREADID          : constant :=   309;
   ERROR_DOSSUB_SHRINK             : constant :=   310;
   ERROR_DOSSUB_NOMEM              : constant :=   311;
   ERROR_DOSSUB_OVERLAP            : constant :=   312;
   ERROR_DOSSUB_BADSIZE            : constant :=   313;
   ERROR_DOSSUB_BADFLAG            : constant :=   314;
   ERROR_DOSSUB_BADSELECTOR        : constant :=   315;
   ERROR_MR_MSG_TOO_LONG           : constant :=   316;
   MGS_MR_MSG_TOO_LONG             : constant :=   316;
   ERROR_MR_MID_NOT_FOUND          : constant :=   317;
   ERROR_MR_UN_ACC_MSGF            : constant :=   318;
   ERROR_MR_INV_MSGF_FORMAT        : constant :=   319;
   ERROR_MR_INV_IVCOUNT            : constant :=   320;
   ERROR_MR_UN_PERFORM             : constant :=   321;
   ERROR_TS_WAKEUP                 : constant :=   322;
   ERROR_TS_SEMHANDLE              : constant :=   323;
   ERROR_TS_NOTIMER                : constant :=   324;
   ERROR_TS_HANDLE                 : constant :=   326;
   ERROR_TS_DATETIME               : constant :=   327;
   ERROR_SYS_INTERNAL              : constant :=   328;
   ERROR_QUE_CURRENT_NAME          : constant :=   329;
   ERROR_QUE_PROC_NOT_OWNED        : constant :=   330;
   ERROR_QUE_PROC_OWNED            : constant :=   331;
   ERROR_QUE_DUPLICATE             : constant :=   332;
   ERROR_QUE_ELEMENT_NOT_EXIST     : constant :=   333;
   ERROR_QUE_NO_MEMORY             : constant :=   334;
   ERROR_QUE_INVALID_NAME          : constant :=   335;
   ERROR_QUE_INVALID_PRIORITY      : constant :=   336;
   ERROR_QUE_INVALID_HANDLE        : constant :=   337;
   ERROR_QUE_LINK_NOT_FOUND        : constant :=   338;
   ERROR_QUE_MEMORY_ERROR          : constant :=   339;
   ERROR_QUE_PREV_AT_END           : constant :=   340;
   ERROR_QUE_PROC_NO_ACCESS        : constant :=   341;
   ERROR_QUE_EMPTY                 : constant :=   342;
   ERROR_QUE_NAME_NOT_EXIST        : constant :=   343;
   ERROR_QUE_NOT_INITIALIZED       : constant :=   344;
   ERROR_QUE_UNABLE_TO_ACCESS      : constant :=   345;
   ERROR_QUE_UNABLE_TO_ADD         : constant :=   346;
   ERROR_QUE_UNABLE_TO_INIT        : constant :=   347;
   ERROR_VIO_INVALID_MASK          : constant :=   349;
   ERROR_VIO_PTR                   : constant :=   350;
   ERROR_VIO_APTR                  : constant :=   351;
   ERROR_VIO_RPTR                  : constant :=   352;
   ERROR_VIO_CPTR                  : constant :=   353;
   ERROR_VIO_LPTR                  : constant :=   354;
   ERROR_VIO_MODE                  : constant :=   355;
   ERROR_VIO_WIDTH                 : constant :=   356;
   ERROR_VIO_ATTR                  : constant :=   357;
   ERROR_VIO_ROW                   : constant :=   358;
   ERROR_VIO_COL                   : constant :=   359;
   ERROR_VIO_TOPROW                : constant :=   360;
   ERROR_VIO_BOTROW                : constant :=   361;
   ERROR_VIO_RIGHTCOL              : constant :=   362;
   ERROR_VIO_LEFTCOL               : constant :=   363;
   ERROR_SCS_CALL                  : constant :=   364;
   ERROR_SCS_VALUE                 : constant :=   365;
   ERROR_VIO_WAIT_FLAG             : constant :=   366;
   ERROR_VIO_UNLOCK                : constant :=   367;
   ERROR_SGS_NOT_SESSION_MGR       : constant :=   368;
   ERROR_SMG_INVALID_SGID          : constant :=   369;
   ERROR_SMG_INVALID_SESSION_ID    : constant :=   369;
   ERROR_SMG_NOSG                  : constant :=   370;
   ERROR_SMG_NO_SESSIONS           : constant :=   370;
   ERROR_SMG_GRP_NOT_FOUND         : constant :=   371;
   ERROR_SMG_SESSION_NOT_FOUND     : constant :=   371;
   ERROR_SMG_SET_TITLE             : constant :=   372;
   ERROR_KBD_PARAMETER             : constant :=   373;
   ERROR_KBD_NO_DEVICE             : constant :=   374;
   ERROR_KBD_INVALID_IOWAIT        : constant :=   375;
   ERROR_KBD_INVALID_LENGTH        : constant :=   376;
   ERROR_KBD_INVALID_ECHO_MASK     : constant :=   377;
   ERROR_KBD_INVALID_INPUT_MASK    : constant :=   378;
   ERROR_MON_INVALID_PARMS         : constant :=   379;
   ERROR_MON_INVALID_DEVNAME       : constant :=   380;
   ERROR_MON_INVALID_HANDLE        : constant :=   381;
   ERROR_MON_BUFFER_TOO_SMALL      : constant :=   382;
   ERROR_MON_BUFFER_EMPTY          : constant :=   383;
   ERROR_MON_DATA_TOO_LARGE        : constant :=   384;
   ERROR_MOUSE_NO_DEVICE           : constant :=   385;
   ERROR_MOUSE_INV_HANDLE          : constant :=   386;
   ERROR_MOUSE_INV_PARMS           : constant :=   387;
   ERROR_MOUSE_CANT_RESET          : constant :=   388;
   ERROR_MOUSE_DISPLAY_PARMS       : constant :=   389;
   ERROR_MOUSE_INV_MODULE          : constant :=   390;
   ERROR_MOUSE_INV_ENTRY_PT        : constant :=   391;
   ERROR_MOUSE_INV_MASK            : constant :=   392;
   NO_ERROR_MOUSE_NO_DATA          : constant :=   393;
   NO_ERROR_MOUSE_PTR_DRAWN        : constant :=   394;
   ERROR_INVALID_FREQUENCY         : constant :=   395;
   ERROR_NLS_NO_COUNTRY_FILE       : constant :=   396;
   ERROR_NLS_OPEN_FAILED           : constant :=   397;
   ERROR_NLS_NO_CTRY_CODE          : constant :=   398;
   ERROR_NO_COUNTRY_OR_CODEPAGE    : constant :=   398;
   ERROR_NLS_TABLE_TRUNCATED       : constant :=   399;
   ERROR_NLS_BAD_TYPE              : constant :=   400;
   ERROR_NLS_TYPE_NOT_FOUND        : constant :=   401;
   ERROR_VIO_SMG_ONLY              : constant :=   402;
   ERROR_VIO_INVALID_ASCIIZ        : constant :=   403;
   ERROR_VIO_DEREGISTER            : constant :=   404;
   ERROR_VIO_NO_POPUP              : constant :=   405;
   ERROR_VIO_EXISTING_POPUP        : constant :=   406;
   ERROR_KBD_SMG_ONLY              : constant :=   407;
   ERROR_KBD_INVALID_ASCIIZ        : constant :=   408;
   ERROR_KBD_INVALID_MASK          : constant :=   409;
   ERROR_KBD_REGISTER              : constant :=   410;
   ERROR_KBD_DEREGISTER            : constant :=   411;
   ERROR_MOUSE_SMG_ONLY            : constant :=   412;
   ERROR_MOUSE_INVALID_ASCIIZ      : constant :=   413;
   ERROR_MOUSE_INVALID_MASK        : constant :=   414;
   ERROR_MOUSE_REGISTER            : constant :=   415;
   ERROR_MOUSE_DEREGISTER          : constant :=   416;
   ERROR_SMG_BAD_ACTION            : constant :=   417;
   ERROR_SMG_INVALID_CALL          : constant :=   418;
   ERROR_SCS_SG_NOTFOUND           : constant :=   419;
   ERROR_SCS_NOT_SHELL             : constant :=   420;
   ERROR_VIO_INVALID_PARMS         : constant :=   421;
   ERROR_VIO_FUNCTION_OWNED        : constant :=   422;
   ERROR_VIO_RETURN                : constant :=   423;
   ERROR_SCS_INVALID_FUNCTION      : constant :=   424;
   ERROR_SCS_NOT_SESSION_MGR       : constant :=   425;
   ERROR_VIO_REGISTER              : constant :=   426;
   ERROR_VIO_NO_MODE_THREAD        : constant :=   427;
   ERROR_VIO_NO_SAVE_RESTORE_THD   : constant :=   428;
   ERROR_VIO_IN_BG                 : constant :=   429;
   ERROR_VIO_ILLEGAL_DURING_POPUP  : constant :=   430;
   ERROR_SMG_NOT_BASESHELL         : constant :=   431;
   ERROR_SMG_BAD_STATUSREQ         : constant :=   432;
   ERROR_QUE_INVALID_WAIT          : constant :=   433;
   ERROR_VIO_LOCK                  : constant :=   434;
   ERROR_MOUSE_INVALID_IOWAIT      : constant :=   435;
   ERROR_VIO_INVALID_HANDLE        : constant :=   436;
   ERROR_VIO_ILLEGAL_DURING_LOCK   : constant :=   437;
   ERROR_VIO_INVALID_LENGTH        : constant :=   438;
   ERROR_KBD_INVALID_HANDLE        : constant :=   439;
   ERROR_KBD_NO_MORE_HANDLE        : constant :=   440;
   ERROR_KBD_CANNOT_CREATE_KCB     : constant :=   441;
   ERROR_KBD_CODEPAGE_LOAD_INCOMPL : constant :=   442;
   ERROR_KBD_INVALID_CODEPAGE_ID   : constant :=   443;
   ERROR_KBD_NO_CODEPAGE_SUPPORT   : constant :=   444;
   ERROR_KBD_FOCUS_REQUIRED        : constant :=   445;
   ERROR_KBD_FOCUS_ALREADY_ACTIVE  : constant :=   446;
   ERROR_KBD_KEYBOARD_BUSY         : constant :=   447;
   ERROR_KBD_INVALID_CODEPAGE      : constant :=   448;
   ERROR_KBD_UNABLE_TO_FOCUS       : constant :=   449;
   ERROR_SMG_SESSION_NON_SELECT    : constant :=   450;
   ERROR_SMG_SESSION_NOT_FOREGRND  : constant :=   451;
   ERROR_SMG_SESSION_NOT_PARENT    : constant :=   452;
   ERROR_SMG_INVALID_START_MODE    : constant :=   453;
   ERROR_SMG_INVALID_RELATED_OPT   : constant :=   454;
   ERROR_SMG_INVALID_BOND_OPTION   : constant :=   455;
   ERROR_SMG_INVALID_SELECT_OPT    : constant :=   456;
   ERROR_SMG_START_IN_BACKGROUND   : constant :=   457;
   ERROR_SMG_INVALID_STOP_OPTION   : constant :=   458;
   ERROR_SMG_BAD_RESERVE           : constant :=   459;
   ERROR_SMG_PROCESS_NOT_PARENT    : constant :=   460;
   ERROR_SMG_INVALID_DATA_LENGTH   : constant :=   461;
   ERROR_SMG_NOT_BOUND             : constant :=   462;
   ERROR_SMG_RETRY_SUB_ALLOC       : constant :=   463;
   ERROR_KBD_DETACHED              : constant :=   464;
   ERROR_VIO_DETACHED              : constant :=   465;
   ERROR_MOU_DETACHED              : constant :=   466;
   ERROR_VIO_FONT                  : constant :=   467;
   ERROR_VIO_USER_FONT             : constant :=   468;
   ERROR_VIO_BAD_CP                : constant :=   469;
   ERROR_VIO_NO_CP                 : constant :=   470;
   ERROR_VIO_NA_CP                 : constant :=   471;
   ERROR_INVALID_CODE_PAGE         : constant :=   472;
   ERROR_CPLIST_TOO_SMALL          : constant :=   473;
   ERROR_CP_NOT_MOVED              : constant :=   474;
   ERROR_MODE_SWITCH_INIT          : constant :=   475;
   ERROR_CODE_PAGE_NOT_FOUND       : constant :=   476;
   ERROR_UNEXPECTED_SLOT_RETURNED  : constant :=   477;
   ERROR_SMG_INVALID_TRACE_OPTION  : constant :=   478;
   ERROR_VIO_INTERNAL_RESOURCE     : constant :=   479;
   ERROR_VIO_SHELL_INIT            : constant :=   480;
   ERROR_SMG_NO_HARD_ERRORS        : constant :=   481;
   ERROR_CP_SWITCH_INCOMPLETE      : constant :=   482;
   ERROR_VIO_TRANSPARENT_POPUP     : constant :=   483;
   ERROR_CRITSEC_OVERFLOW          : constant :=   484;
   ERROR_CRITSEC_UNDERFLOW         : constant :=   485;
   ERROR_VIO_BAD_RESERVE           : constant :=   486;
   ERROR_INVALID_ADDRESS           : constant :=   487;
   ERROR_ZERO_SELECTORS_REQUESTED  : constant :=   488;
   ERROR_NOT_ENOUGH_SELECTORS_AVA  : constant :=   489;
   ERROR_INVALID_SELECTOR          : constant :=   490;
   ERROR_SMG_INVALID_PROGRAM_TYPE  : constant :=   491;
   ERROR_SMG_INVALID_PGM_CONTROL   : constant :=   492;
   ERROR_SMG_INVALID_INHERIT_OPT   : constant :=   493;
   ERROR_VIO_EXTENDED_SG           : constant :=   494;
   ERROR_VIO_NOT_PRES_MGR_SG       : constant :=   495;
   ERROR_VIO_SHIELD_OWNED          : constant :=   496;
   ERROR_VIO_NO_MORE_HANDLES       : constant :=   497;
   ERROR_VIO_SEE_ERROR_LOG         : constant :=   498;
   ERROR_VIO_ASSOCIATED_DC         : constant :=   499;
   ERROR_KBD_NO_CONSOLE            : constant :=   500;
   ERROR_MOUSE_NO_CONSOLE          : constant :=   501;
   ERROR_MOUSE_INVALID_HANDLE      : constant :=   502;
   ERROR_SMG_INVALID_DEBUG_PARMS   : constant :=   503;
   ERROR_KBD_EXTENDED_SG           : constant :=   504;
   ERROR_MOU_EXTENDED_SG           : constant :=   505;
   ERROR_SMG_INVALID_ICON_FILE     : constant :=   506;
   ERROR_TRC_PID_NON_EXISTENT      : constant :=   507;
   ERROR_TRC_COUNT_ACTIVE          : constant :=   508;
   ERROR_TRC_SUSPENDED_BY_COUNT    : constant :=   509;
   ERROR_TRC_COUNT_INACTIVE        : constant :=   510;
   ERROR_TRC_COUNT_REACHED         : constant :=   511;
   ERROR_NO_MC_TRACE               : constant :=   512;
   ERROR_MC_TRACE                  : constant :=   513;
   ERROR_TRC_COUNT_ZERO            : constant :=   514;
   ERROR_SMG_TOO_MANY_DDS          : constant :=   515;
   ERROR_SMG_INVALID_NOTIFICATION  : constant :=   516;
   ERROR_LF_INVALID_FUNCTION       : constant :=   517;
   ERROR_LF_NOT_AVAIL              : constant :=   518;
   ERROR_LF_SUSPENDED              : constant :=   519;
   ERROR_LF_BUF_TOO_SMALL          : constant :=   520;
   ERROR_LF_BUFFER_CORRUPTED       : constant :=   521;
   ERROR_LF_BUFFER_FULL            : constant :=   521;
   ERROR_LF_INVALID_DAEMON         : constant :=   522;
   ERROR_LF_INVALID_RECORD         : constant :=   522;
   ERROR_LF_INVALID_TEMPL          : constant :=   523;
   ERROR_LF_INVALID_SERVICE        : constant :=   523;
   ERROR_LF_GENERAL_FAILURE        : constant :=   524;
   ERROR_LF_INVALID_ID             : constant :=   525;
   ERROR_LF_INVALID_HANDLE         : constant :=   526;
   ERROR_LF_NO_ID_AVAIL            : constant :=   527;
   ERROR_LF_TEMPLATE_AREA_FULL     : constant :=   528;
   ERROR_LF_ID_IN_USE              : constant :=   529;
   ERROR_MOU_NOT_INITIALIZED       : constant :=   530;
   ERROR_MOUINITREAL_DONE          : constant :=   531;
   ERROR_DOSSUB_CORRUPTED          : constant :=   532;
   ERROR_MOUSE_CALLER_NOT_SUBSYS   : constant :=   533;
   ERROR_ARITHMETIC_OVERFLOW       : constant :=   534;
   ERROR_TMR_NO_DEVICE             : constant :=   535;
   ERROR_TMR_INVALID_TIME          : constant :=   536;
   ERROR_PVW_INVALID_ENTITY        : constant :=   537;
   ERROR_PVW_INVALID_ENTITY_TYPE   : constant :=   538;
   ERROR_PVW_INVALID_SPEC          : constant :=   539;
   ERROR_PVW_INVALID_RANGE_TYPE    : constant :=   540;
   ERROR_PVW_INVALID_COUNTER_BLK   : constant :=   541;
   ERROR_PVW_INVALID_TEXT_BLK      : constant :=   542;
   ERROR_PRF_NOT_INITIALIZED       : constant :=   543;
   ERROR_PRF_ALREADY_INITIALIZED   : constant :=   544;
   ERROR_PRF_NOT_STARTED           : constant :=   545;
   ERROR_PRF_ALREADY_STARTED       : constant :=   546;
   ERROR_PRF_TIMER_OUT_OF_RANGE    : constant :=   547;
   ERROR_PRF_TIMER_RESET           : constant :=   548;
   ERROR_VDD_LOCK_USEAGE_DENIED    : constant :=   639;
   ERROR_TIMEOUT                   : constant :=   640;
   ERROR_VDM_DOWN                  : constant :=   641;
   ERROR_VDM_LIMIT                 : constant :=   642;
   ERROR_VDD_NOT_FOUND             : constant :=   643;
   ERROR_INVALID_CALLER            : constant :=   644;
   ERROR_PID_MISMATCH              : constant :=   645;
   ERROR_INVALID_VDD_HANDLE        : constant :=   646;
   ERROR_VLPT_NO_SPOOLER           : constant :=   647;
   ERROR_VCOM_DEVICE_BUSY          : constant :=   648;
   ERROR_VLPT_DEVICE_BUSY          : constant :=   649;
   ERROR_NESTING_TOO_DEEP          : constant :=   650;
   ERROR_VDD_MISSING               : constant :=   651;
   ERROR_BIDI_INVALID_LENGTH       : constant :=   671;
   ERROR_BIDI_INVALID_INCREMENT    : constant :=   672;
   ERROR_BIDI_INVALID_COMBINATION  : constant :=   673;
   ERROR_BIDI_INVALID_RESERVED     : constant :=   674;
   ERROR_BIDI_INVALID_EFFECT       : constant :=   675;
   ERROR_BIDI_INVALID_CSDREC       : constant :=   676;
   ERROR_BIDI_INVALID_CSDSTATE     : constant :=   677;
   ERROR_BIDI_INVALID_LEVEL        : constant :=   678;
   ERROR_BIDI_INVALID_TYPE_SUPPORT : constant :=   679;
   ERROR_BIDI_INVALID_ORIENTATION  : constant :=   680;
   ERROR_BIDI_INVALID_NUM_SHAPE    : constant :=   681;
   ERROR_BIDI_INVALID_CSD          : constant :=   682;
   ERROR_BIDI_NO_SUPPORT           : constant :=   683;
   NO_ERROR_BIDI_RW_INCOMPLETE     : constant :=   684;
   ERROR_IMP_INVALID_PARM          : constant :=   691;
   ERROR_IMP_INVALID_LENGTH        : constant :=   692;
   MSG_HPFS_DISK_ERROR_WARN        : constant :=   693;
   ERROR_MON_BAD_BUFFER            : constant :=   730;
   ERROR_MODULE_CORRUPTED          : constant :=   731;
   ERROR_SM_OUTOF_SWAPFILE         : constant :=  1477;
   ERROR_LF_TIMEOUT                : constant :=  2055;
   ERROR_LF_SUSPEND_SUCCESS        : constant :=  2057;
   ERROR_LF_RESUME_SUCCESS         : constant :=  2058;
   ERROR_LF_REDIRECT_SUCCESS       : constant :=  2059;
   ERROR_LF_REDIRECT_FAILURE       : constant :=  2060;
   ERROR_SWAPPER_NOT_ACTIVE        : constant := 32768;
   ERROR_INVALID_SWAPID            : constant := 32769;
   ERROR_IOERR_SWAP_FILE           : constant := 32770;
   ERROR_SWAP_TABLE_FULL           : constant := 32771;
   ERROR_SWAP_FILE_FULL            : constant := 32772;
   ERROR_CANT_INIT_SWAPPER         : constant := 32773;
   ERROR_SWAPPER_ALREADY_INIT      : constant := 32774;
   ERROR_PMM_INSUFFICIENT_MEMORY   : constant := 32775;
   ERROR_PMM_INVALID_FLAGS         : constant := 32776;
   ERROR_PMM_INVALID_ADDRESS       : constant := 32777;
   ERROR_PMM_LOCK_FAILED           : constant := 32778;
   ERROR_PMM_UNLOCK_FAILED         : constant := 32779;
   ERROR_PMM_MOVE_INCOMPLETE       : constant := 32780;
   ERROR_UCOM_DRIVE_RENAMED        : constant := 32781;
   ERROR_UCOM_FILENAME_TRUNCATED   : constant := 32782;
   ERROR_UCOM_BUFFER_LENGTH        : constant := 32783;
   ERROR_MON_CHAIN_HANDLE          : constant := 32784;
   ERROR_MON_NOT_REGISTERED        : constant := 32785;
   ERROR_SMG_ALREADY_TOP           : constant := 32786;
   ERROR_PMM_ARENA_MODIFIED        : constant := 32787;
   ERROR_SMG_PRINTER_OPEN          : constant := 32788;
   ERROR_PMM_SET_FLAGS_FAILED      : constant := 32789;
   ERROR_INVALID_DOS_DD            : constant := 32790;
   ERROR_BLOCKED                   : constant := 32791;
   ERROR_NOBLOCK                   : constant := 32792;
   ERROR_INSTANCE_SHARED           : constant := 32793;
   ERROR_NO_OBJECT                 : constant := 32794;
   ERROR_PARTIAL_ATTACH            : constant := 32795;
   ERROR_INCACHE                   : constant := 32796;
   ERROR_SWAP_IO_PROBLEMS          : constant := 32797;
   ERROR_CROSSES_OBJECT_BOUNDARY   : constant := 32798;
   ERROR_LONGLOCK                  : constant := 32799;
   ERROR_SHORTLOCK                 : constant := 32800;
   ERROR_UVIRTLOCK                 : constant := 32801;
   ERROR_ALIASLOCK                 : constant := 32802;
   ERROR_ALIAS                     : constant := 32803;
   ERROR_NO_MORE_HANDLES           : constant := 32804;
   ERROR_SCAN_TERMINATED           : constant := 32805;
   ERROR_TERMINATOR_NOT_FOUND      : constant := 32806;
   ERROR_NOT_DIRECT_CHILD          : constant := 32807;
   ERROR_DELAY_FREE                : constant := 32808;
   ERROR_GUARDPAGE                 : constant := 32809;
   ERROR_SWAPERROR                 : constant := 32900;
   ERROR_LDRERROR                  : constant := 32901;
   ERROR_NOMEMORY                  : constant := 32902;
   ERROR_NOACCESS                  : constant := 32903;
   ERROR_NO_DLL_TERM               : constant := 32904;
   ERROR_CPSIO_CODE_PAGE_INVALID   : constant := 65026;
   ERROR_CPSIO_NO_SPOOLER          : constant := 65027;
   ERROR_CPSIO_FONT_ID_INVALID     : constant := 65028;
   ERROR_CPSIO_INTERNAL_ERROR      : constant := 65033;
   ERROR_CPSIO_INVALID_PTR_NAME    : constant := 65034;
   ERROR_CPSIO_NOT_ACTIVE          : constant := 65037;
   ERROR_CPSIO_PID_FULL            : constant := 65039;
   ERROR_CPSIO_PID_NOT_FOUND       : constant := 65040;
   ERROR_CPSIO_READ_CTL_SEQ        : constant := 65043;
   ERROR_CPSIO_READ_FNT_DEF        : constant := 65045;
   ERROR_CPSIO_WRITE_ERROR         : constant := 65047;
   ERROR_CPSIO_WRITE_FULL_ERROR    : constant := 65048;
   ERROR_CPSIO_WRITE_HANDLE_BAD    : constant := 65049;
   ERROR_CPSIO_SWIT_LOAD           : constant := 65074;
   ERROR_CPSIO_INV_COMMAND         : constant := 65077;
   ERROR_CPSIO_NO_FONT_SWIT        : constant := 65078;
   ERROR_ENTRY_IS_CALLGATE         : constant := 65079;

end Interfaces.OS2Lib.Errors;
