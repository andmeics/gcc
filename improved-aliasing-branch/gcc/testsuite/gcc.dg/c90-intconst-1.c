/* Test for integer constant types.  */

/* Origin: Joseph Myers <jsm28@cam.ac.uk>.  */
/* { dg-do compile } */
/* { dg-options "-std=iso9899:1990 -pedantic-errors" } */

#include <limits.h>

/* Assertion that constant C is of type T.  */
#define ASSERT_CONST_TYPE(C, T)			\
	do {					\
	  typedef T type;			\
	  typedef type **typepp;		\
	  typedef __typeof__((C)) ctype;	\
	  typedef ctype **ctypepp;		\
	  typepp x = 0;				\
	  ctypepp y = 0;			\
	  x = y;				\
	  y = x;				\
	} while (0)

/* (T *) if E is zero, (void *) otherwise.  */
#define type_if_not(T, E) __typeof__(0 ? (T *)0 : (void *)(E))

/* (T *) if E is nonzero, (void *) otherwise.  */
#define type_if(T, E) type_if_not(T, !(E))

/* Combine pointer types, all but one (void *).  */
#define type_comb2(T1, T2) __typeof__(0 ? (T1)0 : (T2)0)
#define type_comb3(T1, T2, T3) type_comb2(T1, type_comb2(T2, T3))
#define type_comb4(T1, T2, T3, T4)				\
	type_comb2(T1, type_comb2(T2, type_comb2(T3, T4)))

/* (T1 *) if E1, otherwise (T2 *) if E2.  */
#define first_of2p(T1, E1, T2, E2) type_comb2(type_if(T1, (E1)),	   \
					     type_if(T2, (!(E1) && (E2))))
/* (T1 *) if E1, otherwise (T2 *) if E2, otherwise (T3 *) if E3.  */
#define first_of3p(T1, E1, T2, E2, T3, E3)			\
	type_comb3(type_if(T1, (E1)),				\
		   type_if(T2, (!(E1) && (E2))),		\
		   type_if(T3, (!(E1) && !(E2) && (E3))))
/* (T1 *) if E1, otherwise (T2 *) if E2, otherwise (T3 *) if E3, otherwise
   (T4 *) if E4.  */
#define first_of4p(T1, E1, T2, E2, T3, E3, T4, E4)			\
	type_comb4(type_if(T1, (E1)),					\
		   type_if(T2, (!(E1) && (E2))),			\
		   type_if(T3, (!(E1) && !(E2) && (E3))),		\
		   type_if(T4, (!(E1) && !(E2) && !(E3) && (E4))))

/* Likewise, but return the original type rather than a pointer type.  */
#define first_of2(T1, E1, T2, E2)			\
	__typeof__(*((first_of2p(T1, (E1), T2, (E2)))0))
#define first_of3(T1, E1, T2, E2, T3, E3)				\
	__typeof__(*((first_of3p(T1, (E1), T2, (E2), T3, (E3)))0))
#define first_of4(T1, E1, T2, E2, T3, E3, T4, E4)			    \
	__typeof__(*((first_of4p(T1, (E1), T2, (E2), T3, (E3), T4, (E4)))0))

/* Types of constants according to the C90 rules.  */
#define C90_UNSUF_DEC_TYPE(C)				\
	first_of3(int, (C) <= INT_MAX,			\
		  long int, (C) <= LONG_MAX,		\
		  unsigned long int, (C) <= ULONG_MAX)
#define C90_UNSUF_OCTHEX_TYPE(C)			\
	first_of4(int, (C) <= INT_MAX,			\
		  unsigned int, (C) <= UINT_MAX,	\
		  long int, (C) <= LONG_MAX,		\
		  unsigned long int, (C) <= ULONG_MAX)
#define C90_SUFu_TYPE(C)				\
	first_of2(unsigned int, (C) <= UINT_MAX,	\
		  unsigned long int, (C) <= ULONG_MAX)
#define C90_SUFl_TYPE(C)				\
	first_of2(long int, (C) <= LONG_MAX,		\
		  unsigned long int, (C) <= ULONG_MAX)

/* Checks that constants have correct type.  */
#define CHECK_UNSUF_DEC_TYPE(C) ASSERT_CONST_TYPE((C), C90_UNSUF_DEC_TYPE((C)))
#define CHECK_UNSUF_OCTHEX_TYPE(C)				\
	ASSERT_CONST_TYPE((C), C90_UNSUF_OCTHEX_TYPE((C)))
#define CHECK_SUFu_TYPE(C) ASSERT_CONST_TYPE((C), C90_SUFu_TYPE((C)))
#define CHECK_SUFl_TYPE(C) ASSERT_CONST_TYPE((C), C90_SUFl_TYPE((C)))
#define CHECK_SUFul_TYPE(C) ASSERT_CONST_TYPE((C), unsigned long int)

/* Check a decimal value, with all suffixes.  */
#define CHECK_DEC_CONST(C)			\
	CHECK_UNSUF_DEC_TYPE(C);		\
	CHECK_SUFu_TYPE(C##u);			\
	CHECK_SUFu_TYPE(C##U);			\
	CHECK_SUFl_TYPE(C##l);			\
	CHECK_SUFl_TYPE(C##L);			\
	CHECK_SUFul_TYPE(C##ul);		\
	CHECK_SUFul_TYPE(C##uL);		\
	CHECK_SUFul_TYPE(C##Ul);		\
	CHECK_SUFul_TYPE(C##UL);

/* Check an octal or hexadecimal value, with all suffixes.  */
#define CHECK_OCTHEX_CONST(C)			\
	CHECK_UNSUF_OCTHEX_TYPE(C);		\
	CHECK_SUFu_TYPE(C##u);			\
	CHECK_SUFu_TYPE(C##U);			\
	CHECK_SUFl_TYPE(C##l);			\
	CHECK_SUFl_TYPE(C##L);			\
	CHECK_SUFul_TYPE(C##ul);		\
	CHECK_SUFul_TYPE(C##uL);		\
	CHECK_SUFul_TYPE(C##Ul);		\
	CHECK_SUFul_TYPE(C##UL);

#define CHECK_OCT_CONST(C) CHECK_OCTHEX_CONST(C)
#define CHECK_HEX_CONST(C)			\
	CHECK_OCTHEX_CONST(0x##C);		\
	CHECK_OCTHEX_CONST(0X##C);

/* True iff "long" is at least B bits.  This presumes that (B-2)/3 is at
   most 31.  */
#define LONG_AT_LEAST(B)						\
	(LONG_MAX >> ((B)-2)/3 >> ((B)-2)/3 >> ((B)-2 - ((B)-2)/3 - ((B)-2)/3))

#define LONG_HAS_BITS(B) (LONG_AT_LEAST((B)) && !LONG_AT_LEAST((B) + 1))

/* Decimal values that are large enough to be unsigned.  Allow for up to
   64 bits in long.  */
#if LONG_HAS_BITS(32)
#define LARGE_UNSIGNED_DECIMAL 2147483648
#endif
#if LONG_HAS_BITS(33)
#define LARGE_UNSIGNED_DECIMAL 4294967296
#endif
#if LONG_HAS_BITS(34)
#define LARGE_UNSIGNED_DECIMAL 8589934592
#endif
#if LONG_HAS_BITS(35)
#define LARGE_UNSIGNED_DECIMAL 17179869184
#endif
#if LONG_HAS_BITS(36)
#define LARGE_UNSIGNED_DECIMAL 34359738368
#endif
#if LONG_HAS_BITS(37)
#define LARGE_UNSIGNED_DECIMAL 68719476736
#endif
#if LONG_HAS_BITS(38)
#define LARGE_UNSIGNED_DECIMAL 137438953472
#endif
#if LONG_HAS_BITS(39)
#define LARGE_UNSIGNED_DECIMAL 274877906944
#endif
#if LONG_HAS_BITS(40)
#define LARGE_UNSIGNED_DECIMAL 549755813888
#endif
#if LONG_HAS_BITS(41)
#define LARGE_UNSIGNED_DECIMAL 1099511627776
#endif
#if LONG_HAS_BITS(42)
#define LARGE_UNSIGNED_DECIMAL 2199023255552
#endif
#if LONG_HAS_BITS(43)
#define LARGE_UNSIGNED_DECIMAL 4398046511104
#endif
#if LONG_HAS_BITS(44)
#define LARGE_UNSIGNED_DECIMAL 8796093022208
#endif
#if LONG_HAS_BITS(45)
#define LARGE_UNSIGNED_DECIMAL 17592186044416
#endif
#if LONG_HAS_BITS(46)
#define LARGE_UNSIGNED_DECIMAL 35184372088832
#endif
#if LONG_HAS_BITS(47)
#define LARGE_UNSIGNED_DECIMAL 70368744177664
#endif
#if LONG_HAS_BITS(48)
#define LARGE_UNSIGNED_DECIMAL 140737488355328
#endif
#if LONG_HAS_BITS(49)
#define LARGE_UNSIGNED_DECIMAL 281474976710656
#endif
#if LONG_HAS_BITS(50)
#define LARGE_UNSIGNED_DECIMAL 562949953421312
#endif
#if LONG_HAS_BITS(51)
#define LARGE_UNSIGNED_DECIMAL 1125899906842624
#endif
#if LONG_HAS_BITS(52)
#define LARGE_UNSIGNED_DECIMAL 2251799813685248
#endif
#if LONG_HAS_BITS(53)
#define LARGE_UNSIGNED_DECIMAL 4503599627370496
#endif
#if LONG_HAS_BITS(54)
#define LARGE_UNSIGNED_DECIMAL 9007199254740992
#endif
#if LONG_HAS_BITS(55)
#define LARGE_UNSIGNED_DECIMAL 18014398509481984
#endif
#if LONG_HAS_BITS(56)
#define LARGE_UNSIGNED_DECIMAL 36028797018963968
#endif
#if LONG_HAS_BITS(57)
#define LARGE_UNSIGNED_DECIMAL 72057594037927936
#endif
#if LONG_HAS_BITS(58)
#define LARGE_UNSIGNED_DECIMAL 144115188075855872
#endif
#if LONG_HAS_BITS(59)
#define LARGE_UNSIGNED_DECIMAL 288230376151711744
#endif
#if LONG_HAS_BITS(60)
#define LARGE_UNSIGNED_DECIMAL 576460752303423488
#endif
#if LONG_HAS_BITS(61)
#define LARGE_UNSIGNED_DECIMAL 1152921504606846976
#endif
#if LONG_HAS_BITS(62)
#define LARGE_UNSIGNED_DECIMAL 2305843009213693952
#endif
#if LONG_HAS_BITS(63)
#define LARGE_UNSIGNED_DECIMAL 4611686018427387904
#endif
#if LONG_HAS_BITS(64)
#define LARGE_UNSIGNED_DECIMAL 9223372036854775808
#endif
#if LONG_AT_LEAST(65)
#error "extend this test to allow for long larger than 64 bits"
#endif

#define cat(x, y) x ## y
#define xcat(x, y) cat(x, y)

#define LARGE_UNSIGNED_DECIMALl xcat(LARGE_UNSIGNED_DECIMAL, l)
#define LARGE_UNSIGNED_DECIMALL xcat(LARGE_UNSIGNED_DECIMAL, L)
#define LARGE_UNSIGNED_DECIMALu xcat(LARGE_UNSIGNED_DECIMAL, u)
#define LARGE_UNSIGNED_DECIMALU xcat(LARGE_UNSIGNED_DECIMAL, U)
#define LARGE_UNSIGNED_DECIMALul xcat(LARGE_UNSIGNED_DECIMAL, ul)
#define LARGE_UNSIGNED_DECIMALuL xcat(LARGE_UNSIGNED_DECIMAL, uL)
#define LARGE_UNSIGNED_DECIMALUl xcat(LARGE_UNSIGNED_DECIMAL, Ul)
#define LARGE_UNSIGNED_DECIMALUL xcat(LARGE_UNSIGNED_DECIMAL, UL)

void
foo (void)
{
  /* Decimal.  */
  /* Check all 2^n and 2^n - 1 up to 2^63 - 1.  Check values that would be
     unsigned separately since they generate a warning.  */
  CHECK_DEC_CONST(1);
  CHECK_DEC_CONST(2);
  CHECK_DEC_CONST(3);
  CHECK_DEC_CONST(4);
  CHECK_DEC_CONST(7);
  CHECK_DEC_CONST(8);
  CHECK_DEC_CONST(15);
  CHECK_DEC_CONST(16);
  CHECK_DEC_CONST(31);
  CHECK_DEC_CONST(32);
  CHECK_DEC_CONST(63);
  CHECK_DEC_CONST(64);
  CHECK_DEC_CONST(127);
  CHECK_DEC_CONST(128);
  CHECK_DEC_CONST(255);
  CHECK_DEC_CONST(256);
  CHECK_DEC_CONST(511);
  CHECK_DEC_CONST(512);
  CHECK_DEC_CONST(1023);
  CHECK_DEC_CONST(1024);
  CHECK_DEC_CONST(2047);
  CHECK_DEC_CONST(2048);
  CHECK_DEC_CONST(4095);
  CHECK_DEC_CONST(4096);
  CHECK_DEC_CONST(8191);
  CHECK_DEC_CONST(8192);
  CHECK_DEC_CONST(16383);
  CHECK_DEC_CONST(16384);
  CHECK_DEC_CONST(32767);
  CHECK_DEC_CONST(32768);
  CHECK_DEC_CONST(65535);
  CHECK_DEC_CONST(65536);
  CHECK_DEC_CONST(131071);
  CHECK_DEC_CONST(131072);
  CHECK_DEC_CONST(262143);
  CHECK_DEC_CONST(262144);
  CHECK_DEC_CONST(524287);
  CHECK_DEC_CONST(524288);
  CHECK_DEC_CONST(1048575);
  CHECK_DEC_CONST(1048576);
  CHECK_DEC_CONST(2097151);
  CHECK_DEC_CONST(2097152);
  CHECK_DEC_CONST(4194303);
  CHECK_DEC_CONST(4194304);
  CHECK_DEC_CONST(8388607);
  CHECK_DEC_CONST(8388608);
  CHECK_DEC_CONST(16777215);
  CHECK_DEC_CONST(16777216);
  CHECK_DEC_CONST(33554431);
  CHECK_DEC_CONST(33554432);
  CHECK_DEC_CONST(67108863);
  CHECK_DEC_CONST(67108864);
  CHECK_DEC_CONST(134217727);
  CHECK_DEC_CONST(134217728);
  CHECK_DEC_CONST(268435455);
  CHECK_DEC_CONST(268435456);
  CHECK_DEC_CONST(536870911);
  CHECK_DEC_CONST(536870912);
  CHECK_DEC_CONST(1073741823);
  CHECK_DEC_CONST(1073741824);
  CHECK_DEC_CONST(2147483647);
#if LONG_AT_LEAST(33)
  CHECK_DEC_CONST(2147483648);
  CHECK_DEC_CONST(4294967295);
#endif
#if LONG_AT_LEAST(34)
  CHECK_DEC_CONST(4294967296);
  CHECK_DEC_CONST(8589934591);
#endif
#if LONG_AT_LEAST(35)
  CHECK_DEC_CONST(8589934592);
  CHECK_DEC_CONST(17179869183);
#endif
#if LONG_AT_LEAST(36)
  CHECK_DEC_CONST(17179869184);
  CHECK_DEC_CONST(34359738367);
#endif
#if LONG_AT_LEAST(37)
  CHECK_DEC_CONST(34359738368);
  CHECK_DEC_CONST(68719476735);
#endif
#if LONG_AT_LEAST(38)
  CHECK_DEC_CONST(68719476736);
  CHECK_DEC_CONST(137438953471);
#endif
#if LONG_AT_LEAST(39)
  CHECK_DEC_CONST(137438953472);
  CHECK_DEC_CONST(274877906943);
#endif
#if LONG_AT_LEAST(40)
  CHECK_DEC_CONST(274877906944);
  CHECK_DEC_CONST(549755813887);
#endif
#if LONG_AT_LEAST(41)
  CHECK_DEC_CONST(549755813888);
  CHECK_DEC_CONST(1099511627775);
#endif
#if LONG_AT_LEAST(42)
  CHECK_DEC_CONST(1099511627776);
  CHECK_DEC_CONST(2199023255551);
#endif
#if LONG_AT_LEAST(43)
  CHECK_DEC_CONST(2199023255552);
  CHECK_DEC_CONST(4398046511103);
#endif
#if LONG_AT_LEAST(44)
  CHECK_DEC_CONST(4398046511104);
  CHECK_DEC_CONST(8796093022207);
#endif
#if LONG_AT_LEAST(45)
  CHECK_DEC_CONST(8796093022208);
  CHECK_DEC_CONST(17592186044415);
#endif
#if LONG_AT_LEAST(46)
  CHECK_DEC_CONST(17592186044416);
  CHECK_DEC_CONST(35184372088831);
#endif
#if LONG_AT_LEAST(47)
  CHECK_DEC_CONST(35184372088832);
  CHECK_DEC_CONST(70368744177663);
#endif
#if LONG_AT_LEAST(48)
  CHECK_DEC_CONST(70368744177664);
  CHECK_DEC_CONST(140737488355327);
#endif
#if LONG_AT_LEAST(49)
  CHECK_DEC_CONST(140737488355328);
  CHECK_DEC_CONST(281474976710655);
#endif
#if LONG_AT_LEAST(50)
  CHECK_DEC_CONST(281474976710656);
  CHECK_DEC_CONST(562949953421311);
#endif
#if LONG_AT_LEAST(51)
  CHECK_DEC_CONST(562949953421312);
  CHECK_DEC_CONST(1125899906842623);
#endif
#if LONG_AT_LEAST(52)
  CHECK_DEC_CONST(1125899906842624);
  CHECK_DEC_CONST(2251799813685247);
#endif
#if LONG_AT_LEAST(53)
  CHECK_DEC_CONST(2251799813685248);
  CHECK_DEC_CONST(4503599627370495);
#endif
#if LONG_AT_LEAST(54)
  CHECK_DEC_CONST(4503599627370496);
  CHECK_DEC_CONST(9007199254740991);
#endif
#if LONG_AT_LEAST(55)
  CHECK_DEC_CONST(9007199254740992);
  CHECK_DEC_CONST(18014398509481983);
#endif
#if LONG_AT_LEAST(56)
  CHECK_DEC_CONST(18014398509481984);
  CHECK_DEC_CONST(36028797018963967);
#endif
#if LONG_AT_LEAST(57)
  CHECK_DEC_CONST(36028797018963968);
  CHECK_DEC_CONST(72057594037927935);
#endif
#if LONG_AT_LEAST(58)
  CHECK_DEC_CONST(72057594037927936);
  CHECK_DEC_CONST(144115188075855871);
#endif
#if LONG_AT_LEAST(59)
  CHECK_DEC_CONST(144115188075855872);
  CHECK_DEC_CONST(288230376151711743);
#endif
#if LONG_AT_LEAST(60)
  CHECK_DEC_CONST(288230376151711744);
  CHECK_DEC_CONST(576460752303423487);
#endif
#if LONG_AT_LEAST(61)
  CHECK_DEC_CONST(576460752303423488);
  CHECK_DEC_CONST(1152921504606846975);
#endif
#if LONG_AT_LEAST(62)
  CHECK_DEC_CONST(1152921504606846976);
  CHECK_DEC_CONST(2305843009213693951);
#endif
#if LONG_AT_LEAST(63)
  CHECK_DEC_CONST(2305843009213693952);
  CHECK_DEC_CONST(4611686018427387903);
#endif
#if LONG_AT_LEAST(64)
  CHECK_DEC_CONST(4611686018427387904);
  CHECK_DEC_CONST(9223372036854775807);
#endif
  /* Separate checks for values that are unsigned.  */
  CHECK_UNSUF_DEC_TYPE(LARGE_UNSIGNED_DECIMAL); /* { dg-warning "unsigned" "unsigned decimal no suffix" } */
  CHECK_SUFl_TYPE(LARGE_UNSIGNED_DECIMALl); /* { dg-warning "unsigned" "unsigned decimal long suffix" } */
  CHECK_SUFl_TYPE(LARGE_UNSIGNED_DECIMALL); /* { dg-warning "unsigned" "unsigned decimal long suffix" } */
  CHECK_SUFu_TYPE(LARGE_UNSIGNED_DECIMALu);
  CHECK_SUFu_TYPE(LARGE_UNSIGNED_DECIMALU);
  CHECK_SUFul_TYPE(LARGE_UNSIGNED_DECIMALul);
  CHECK_SUFul_TYPE(LARGE_UNSIGNED_DECIMALuL);
  CHECK_SUFul_TYPE(LARGE_UNSIGNED_DECIMALUl);
  CHECK_SUFul_TYPE(LARGE_UNSIGNED_DECIMALUL);
  /* Octal and hexadecimal.  */
  /* Check all 2^n and 2^n - 1 up to 2^64 - 1.  */
  CHECK_OCT_CONST(0);
  CHECK_HEX_CONST(0);
  CHECK_OCT_CONST(01);
  CHECK_HEX_CONST(1);
  CHECK_OCT_CONST(02);
  CHECK_HEX_CONST(2);
  CHECK_OCT_CONST(03);
  CHECK_HEX_CONST(3);
  CHECK_OCT_CONST(04);
  CHECK_HEX_CONST(4);
  CHECK_OCT_CONST(07);
  CHECK_HEX_CONST(7);
  CHECK_OCT_CONST(010);
  CHECK_HEX_CONST(8);
  CHECK_OCT_CONST(017);
  CHECK_HEX_CONST(f);
  CHECK_OCT_CONST(020);
  CHECK_HEX_CONST(10);
  CHECK_OCT_CONST(037);
  CHECK_HEX_CONST(1f);
  CHECK_OCT_CONST(040);
  CHECK_HEX_CONST(20);
  CHECK_OCT_CONST(077);
  CHECK_HEX_CONST(3f);
  CHECK_OCT_CONST(0100);
  CHECK_HEX_CONST(40);
  CHECK_OCT_CONST(0177);
  CHECK_HEX_CONST(7f);
  CHECK_OCT_CONST(0200);
  CHECK_HEX_CONST(80);
  CHECK_OCT_CONST(0377);
  CHECK_HEX_CONST(ff);
  CHECK_OCT_CONST(0400);
  CHECK_HEX_CONST(100);
  CHECK_OCT_CONST(0777);
  CHECK_HEX_CONST(1ff);
  CHECK_OCT_CONST(01000);
  CHECK_HEX_CONST(200);
  CHECK_OCT_CONST(01777);
  CHECK_HEX_CONST(3ff);
  CHECK_OCT_CONST(02000);
  CHECK_HEX_CONST(400);
  CHECK_OCT_CONST(03777);
  CHECK_HEX_CONST(7ff);
  CHECK_OCT_CONST(04000);
  CHECK_HEX_CONST(800);
  CHECK_OCT_CONST(07777);
  CHECK_HEX_CONST(fff);
  CHECK_OCT_CONST(010000);
  CHECK_HEX_CONST(1000);
  CHECK_OCT_CONST(017777);
  CHECK_HEX_CONST(1fff);
  CHECK_OCT_CONST(020000);
  CHECK_HEX_CONST(2000);
  CHECK_OCT_CONST(037777);
  CHECK_HEX_CONST(3fff);
  CHECK_OCT_CONST(040000);
  CHECK_HEX_CONST(4000);
  CHECK_OCT_CONST(077777);
  CHECK_HEX_CONST(7fff);
  CHECK_OCT_CONST(0100000);
  CHECK_HEX_CONST(8000);
  CHECK_OCT_CONST(0177777);
  CHECK_HEX_CONST(ffff);
  CHECK_OCT_CONST(0200000);
  CHECK_HEX_CONST(10000);
  CHECK_OCT_CONST(0377777);
  CHECK_HEX_CONST(1ffff);
  CHECK_OCT_CONST(0400000);
  CHECK_HEX_CONST(20000);
  CHECK_OCT_CONST(0777777);
  CHECK_HEX_CONST(3ffff);
  CHECK_OCT_CONST(01000000);
  CHECK_HEX_CONST(40000);
  CHECK_OCT_CONST(01777777);
  CHECK_HEX_CONST(7ffff);
  CHECK_OCT_CONST(02000000);
  CHECK_HEX_CONST(80000);
  CHECK_OCT_CONST(03777777);
  CHECK_HEX_CONST(fffff);
  CHECK_OCT_CONST(04000000);
  CHECK_HEX_CONST(100000);
  CHECK_OCT_CONST(07777777);
  CHECK_HEX_CONST(1fffff);
  CHECK_OCT_CONST(010000000);
  CHECK_HEX_CONST(200000);
  CHECK_OCT_CONST(017777777);
  CHECK_HEX_CONST(3fffff);
  CHECK_OCT_CONST(020000000);
  CHECK_HEX_CONST(400000);
  CHECK_OCT_CONST(037777777);
  CHECK_HEX_CONST(7fffff);
  CHECK_OCT_CONST(040000000);
  CHECK_HEX_CONST(800000);
  CHECK_OCT_CONST(077777777);
  CHECK_HEX_CONST(ffffff);
  CHECK_OCT_CONST(0100000000);
  CHECK_HEX_CONST(1000000);
  CHECK_OCT_CONST(0177777777);
  CHECK_HEX_CONST(1ffffff);
  CHECK_OCT_CONST(0200000000);
  CHECK_HEX_CONST(2000000);
  CHECK_OCT_CONST(0377777777);
  CHECK_HEX_CONST(3ffffff);
  CHECK_OCT_CONST(0400000000);
  CHECK_HEX_CONST(4000000);
  CHECK_OCT_CONST(0777777777);
  CHECK_HEX_CONST(7ffffff);
  CHECK_OCT_CONST(01000000000);
  CHECK_HEX_CONST(8000000);
  CHECK_OCT_CONST(01777777777);
  CHECK_HEX_CONST(fffffff);
  CHECK_OCT_CONST(02000000000);
  CHECK_HEX_CONST(10000000);
  CHECK_OCT_CONST(03777777777);
  CHECK_HEX_CONST(1fffffff);
  CHECK_OCT_CONST(04000000000);
  CHECK_HEX_CONST(20000000);
  CHECK_OCT_CONST(07777777777);
  CHECK_HEX_CONST(3fffffff);
  CHECK_OCT_CONST(010000000000);
  CHECK_HEX_CONST(40000000);
  CHECK_OCT_CONST(017777777777);
  CHECK_HEX_CONST(7fffffff);
  CHECK_OCT_CONST(020000000000);
  CHECK_HEX_CONST(80000000);
  CHECK_OCT_CONST(037777777777);
  CHECK_HEX_CONST(ffffffff);
#if LONG_AT_LEAST(33)
  CHECK_OCT_CONST(040000000000);
  CHECK_HEX_CONST(100000000);
  CHECK_OCT_CONST(077777777777);
  CHECK_HEX_CONST(1ffffffff);
#endif
#if LONG_AT_LEAST(34)
  CHECK_OCT_CONST(0100000000000);
  CHECK_HEX_CONST(200000000);
  CHECK_OCT_CONST(0177777777777);
  CHECK_HEX_CONST(3ffffffff);
#endif
#if LONG_AT_LEAST(35)
  CHECK_OCT_CONST(0200000000000);
  CHECK_HEX_CONST(400000000);
  CHECK_OCT_CONST(0377777777777);
  CHECK_HEX_CONST(7ffffffff);
#endif
#if LONG_AT_LEAST(36)
  CHECK_OCT_CONST(0400000000000);
  CHECK_HEX_CONST(800000000);
  CHECK_OCT_CONST(0777777777777);
  CHECK_HEX_CONST(fffffffff);
#endif
#if LONG_AT_LEAST(37)
  CHECK_OCT_CONST(01000000000000);
  CHECK_HEX_CONST(1000000000);
  CHECK_OCT_CONST(01777777777777);
  CHECK_HEX_CONST(1fffffffff);
#endif
#if LONG_AT_LEAST(38)
  CHECK_OCT_CONST(02000000000000);
  CHECK_HEX_CONST(2000000000);
  CHECK_OCT_CONST(03777777777777);
  CHECK_HEX_CONST(3fffffffff);
#endif
#if LONG_AT_LEAST(39)
  CHECK_OCT_CONST(04000000000000);
  CHECK_HEX_CONST(4000000000);
  CHECK_OCT_CONST(07777777777777);
  CHECK_HEX_CONST(7fffffffff);
#endif
#if LONG_AT_LEAST(40)
  CHECK_OCT_CONST(010000000000000);
  CHECK_HEX_CONST(8000000000);
  CHECK_OCT_CONST(017777777777777);
  CHECK_HEX_CONST(ffffffffff);
#endif
#if LONG_AT_LEAST(41)
  CHECK_OCT_CONST(020000000000000);
  CHECK_HEX_CONST(10000000000);
  CHECK_OCT_CONST(037777777777777);
  CHECK_HEX_CONST(1ffffffffff);
#endif
#if LONG_AT_LEAST(42)
  CHECK_OCT_CONST(040000000000000);
  CHECK_HEX_CONST(20000000000);
  CHECK_OCT_CONST(077777777777777);
  CHECK_HEX_CONST(3ffffffffff);
#endif
#if LONG_AT_LEAST(43)
  CHECK_OCT_CONST(0100000000000000);
  CHECK_HEX_CONST(40000000000);
  CHECK_OCT_CONST(0177777777777777);
  CHECK_HEX_CONST(7ffffffffff);
#endif
#if LONG_AT_LEAST(44)
  CHECK_OCT_CONST(0200000000000000);
  CHECK_HEX_CONST(80000000000);
  CHECK_OCT_CONST(0377777777777777);
  CHECK_HEX_CONST(fffffffffff);
#endif
#if LONG_AT_LEAST(45)
  CHECK_OCT_CONST(0400000000000000);
  CHECK_HEX_CONST(100000000000);
  CHECK_OCT_CONST(0777777777777777);
  CHECK_HEX_CONST(1fffffffffff);
#endif
#if LONG_AT_LEAST(46)
  CHECK_OCT_CONST(01000000000000000);
  CHECK_HEX_CONST(200000000000);
  CHECK_OCT_CONST(01777777777777777);
  CHECK_HEX_CONST(3fffffffffff);
#endif
#if LONG_AT_LEAST(47)
  CHECK_OCT_CONST(02000000000000000);
  CHECK_HEX_CONST(400000000000);
  CHECK_OCT_CONST(03777777777777777);
  CHECK_HEX_CONST(7fffffffffff);
#endif
#if LONG_AT_LEAST(48)
  CHECK_OCT_CONST(04000000000000000);
  CHECK_HEX_CONST(800000000000);
  CHECK_OCT_CONST(07777777777777777);
  CHECK_HEX_CONST(ffffffffffff);
#endif
#if LONG_AT_LEAST(49)
  CHECK_OCT_CONST(010000000000000000);
  CHECK_HEX_CONST(1000000000000);
  CHECK_OCT_CONST(017777777777777777);
  CHECK_HEX_CONST(1ffffffffffff);
#endif
#if LONG_AT_LEAST(50)
  CHECK_OCT_CONST(020000000000000000);
  CHECK_HEX_CONST(2000000000000);
  CHECK_OCT_CONST(037777777777777777);
  CHECK_HEX_CONST(3ffffffffffff);
#endif
#if LONG_AT_LEAST(51)
  CHECK_OCT_CONST(040000000000000000);
  CHECK_HEX_CONST(4000000000000);
  CHECK_OCT_CONST(077777777777777777);
  CHECK_HEX_CONST(7ffffffffffff);
#endif
#if LONG_AT_LEAST(52)
  CHECK_OCT_CONST(0100000000000000000);
  CHECK_HEX_CONST(8000000000000);
  CHECK_OCT_CONST(0177777777777777777);
  CHECK_HEX_CONST(fffffffffffff);
#endif
#if LONG_AT_LEAST(53)
  CHECK_OCT_CONST(0200000000000000000);
  CHECK_HEX_CONST(10000000000000);
  CHECK_OCT_CONST(0377777777777777777);
  CHECK_HEX_CONST(1fffffffffffff);
#endif
#if LONG_AT_LEAST(54)
  CHECK_OCT_CONST(0400000000000000000);
  CHECK_HEX_CONST(20000000000000);
  CHECK_OCT_CONST(0777777777777777777);
  CHECK_HEX_CONST(3fffffffffffff);
#endif
#if LONG_AT_LEAST(55)
  CHECK_OCT_CONST(01000000000000000000);
  CHECK_HEX_CONST(40000000000000);
  CHECK_OCT_CONST(01777777777777777777);
  CHECK_HEX_CONST(7fffffffffffff);
#endif
#if LONG_AT_LEAST(56)
  CHECK_OCT_CONST(02000000000000000000);
  CHECK_HEX_CONST(80000000000000);
  CHECK_OCT_CONST(03777777777777777777);
  CHECK_HEX_CONST(ffffffffffffff);
#endif
#if LONG_AT_LEAST(57)
  CHECK_OCT_CONST(04000000000000000000);
  CHECK_HEX_CONST(100000000000000);
  CHECK_OCT_CONST(07777777777777777777);
  CHECK_HEX_CONST(1ffffffffffffff);
#endif
#if LONG_AT_LEAST(58)
  CHECK_OCT_CONST(010000000000000000000);
  CHECK_HEX_CONST(200000000000000);
  CHECK_OCT_CONST(017777777777777777777);
  CHECK_HEX_CONST(3ffffffffffffff);
#endif
#if LONG_AT_LEAST(59)
  CHECK_OCT_CONST(020000000000000000000);
  CHECK_HEX_CONST(400000000000000);
  CHECK_OCT_CONST(037777777777777777777);
  CHECK_HEX_CONST(7ffffffffffffff);
#endif
#if LONG_AT_LEAST(60)
  CHECK_OCT_CONST(040000000000000000000);
  CHECK_HEX_CONST(800000000000000);
  CHECK_OCT_CONST(077777777777777777777);
  CHECK_HEX_CONST(fffffffffffffff);
#endif
#if LONG_AT_LEAST(61)
  CHECK_OCT_CONST(0100000000000000000000);
  CHECK_HEX_CONST(1000000000000000);
  CHECK_OCT_CONST(0177777777777777777777);
  CHECK_HEX_CONST(1fffffffffffffff);
#endif
#if LONG_AT_LEAST(62)
  CHECK_OCT_CONST(0200000000000000000000);
  CHECK_HEX_CONST(2000000000000000);
  CHECK_OCT_CONST(0377777777777777777777);
  CHECK_HEX_CONST(3fffffffffffffff);
#endif
#if LONG_AT_LEAST(63)
  CHECK_OCT_CONST(0400000000000000000000);
  CHECK_HEX_CONST(4000000000000000);
  CHECK_OCT_CONST(0777777777777777777777);
  CHECK_HEX_CONST(7fffffffffffffff);
#endif
#if LONG_AT_LEAST(64)
  CHECK_OCT_CONST(01000000000000000000000);
  CHECK_HEX_CONST(8000000000000000);
  CHECK_OCT_CONST(01777777777777777777777);
  CHECK_HEX_CONST(ffffffffffffffff);
#endif
}
