// { dg-xfail-if "ICE instantiate_decl - bad merge" { "*-*-*" } { "-fpph-map=pph.map" } }
// { dg-bogus "internal compiler error: in instantiate_decl, at cp/pt.c" "" { xfail *-*-* } 0 }
// { dg-excess-errors "decl merge problems" { xfail *-*-* } }
#include "x0tmplfuncinln3.h"
#include "x0tmplfuncinln4.h"
#include "a0tmplfuncinln_u.h"
