/* Tests of duplication.  */
/* { dg-do compile } */

@interface class1
- (int) meth1;
- (void) meth1;  /* { dg-error "duplicate declaration of method .\\-meth1." } */
@end

@interface class2
+ (void) meth1;
+ (int) meth1;  /* { dg-error "duplicate declaration of method .\\+meth1." } */
@end

@interface class3
- (int) meth1;
@end

@implementation class3
- (int) meth1 { return 0; }
- (int) meth1 { return 0; } /* { dg-error "redefinition of" } */
/* { dg-error "previously defined here" "" { target *-*-* } 19 } */
@end

@interface class4
+ (void) meth1;
@end

@implementation class4
+ (void) meth1 {}
+ (void) meth1 {} /* { dg-error "redefinition of" } */
/* { dg-error "previously defined here" "" { target *-*-* } 29 } */
@end
