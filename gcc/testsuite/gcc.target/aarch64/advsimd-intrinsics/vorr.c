#define INSN_NAME vorr
#define TEST_MSG "VORR/VORRQ"

#include "binary_op.inc"

/* Expected results.  */
VECT_VAR_DECL(expected,int,8,8) [] = { 0xf2, 0xf3, 0xf2, 0xf3,
				       0xf6, 0xf7, 0xf6, 0xf7 };
VECT_VAR_DECL(expected,int,16,4) [] = { 0xfffc, 0xfffd, 0xfffe, 0xffff };
VECT_VAR_DECL(expected,int,32,2) [] = { 0xfffffff3, 0xfffffff3 };
VECT_VAR_DECL(expected,int,64,1) [] = { 0xfffffffffffffff4 };
VECT_VAR_DECL(expected,uint,8,8) [] = { 0xf4, 0xf5, 0xf6, 0xf7,
					0xf4, 0xf5, 0xf6, 0xf7 };
VECT_VAR_DECL(expected,uint,16,4) [] = { 0xfffe, 0xffff, 0xfffe, 0xffff };
VECT_VAR_DECL(expected,uint,32,2) [] = { 0xfffffff8, 0xfffffff9 };
VECT_VAR_DECL(expected,uint,64,1) [] = { 0xfffffffffffffff2 };
VECT_VAR_DECL(expected,int,8,16) [] = { 0xf6, 0xf7, 0xf6, 0xf7,
					0xf6, 0xf7, 0xf6, 0xf7,
					0xfe, 0xff, 0xfe, 0xff,
					0xfe, 0xff, 0xfe, 0xff };
VECT_VAR_DECL(expected,int,16,8) [] = { 0xfffc, 0xfffd, 0xfffe, 0xffff,
					0xfffc, 0xfffd, 0xfffe, 0xffff };
VECT_VAR_DECL(expected,int,32,4) [] = { 0xfffffff2, 0xfffffff3,
					0xfffffff2, 0xfffffff3 };
VECT_VAR_DECL(expected,int,64,2) [] = { 0xfffffffffffffff8,
					0xfffffffffffffff9 };
VECT_VAR_DECL(expected,uint,8,16) [] = { 0xfc, 0xfd, 0xfe, 0xff,
					 0xfc, 0xfd, 0xfe, 0xff,
					 0xfc, 0xfd, 0xfe, 0xff,
					 0xfc, 0xfd, 0xfe, 0xff };
VECT_VAR_DECL(expected,uint,16,8) [] = { 0xfff3, 0xfff3, 0xfff3, 0xfff3,
					 0xfff7, 0xfff7, 0xfff7, 0xfff7 };
VECT_VAR_DECL(expected,uint,32,4) [] = { 0xfffffff7, 0xfffffff7,
					 0xfffffff7, 0xfffffff7 };
VECT_VAR_DECL(expected,uint,64,2) [] = { 0xfffffffffffffff3,
					 0xfffffffffffffff3 };
