-- C23006G.ADA

--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
-- CHECK THAT UNDERSCORES ARE SIGNIFICANT IN LIBRARY SUBPROGRAM NAMES
-- CREATED BY A GENERIC INSTANTIATION.

-- JBG 5/26/85

GENERIC
     C : INTEGER;
PROCEDURE C23006G_PROC (X : OUT INTEGER);

PROCEDURE C23006G_PROC (X : OUT INTEGER) IS
BEGIN
     X := C;
END C23006G_PROC;

GENERIC
     C : INTEGER;
FUNCTION C23006G_FUNC RETURN INTEGER;

WITH REPORT; USE REPORT;
PRAGMA ELABORATE (REPORT);
FUNCTION C23006G_FUNC RETURN INTEGER IS
BEGIN
     RETURN IDENT_INT(C);
END C23006G_FUNC;

WITH C23006G_PROC;
PRAGMA ELABORATE (C23006G_PROC);
PROCEDURE C23006G_INSTP IS NEW C23006G_PROC (1);

WITH REPORT; USE REPORT;
WITH C23006G_PROC;
PRAGMA ELABORATE (REPORT, C23006G_PROC);
PROCEDURE C23006GINSTP IS NEW C23006G_PROC (IDENT_INT(2));

WITH C23006G_FUNC;
PRAGMA ELABORATE (C23006G_FUNC);
FUNCTION C23006G_INSTF IS NEW C23006G_FUNC (3);

WITH C23006G_FUNC;
PRAGMA ELABORATE (C23006G_FUNC);
FUNCTION C23006GINSTF IS NEW C23006G_FUNC (4);

WITH C23006G_INSTP, C23006GINSTP, C23006G_INSTF, C23006GINSTF;
WITH REPORT; USE REPORT;
PROCEDURE C23006G IS
     X1, X2 : INTEGER;
BEGIN
     TEST ("C23006G", "CHECK THAT UNDERSCORES ARE SIGNFICANT IN NAMES "&
                      "USED FOR A LIBRARY SUBPROGRAM INSTANTIATION");
     C23006G_INSTP (X1);
     C23006GINSTP (X2);

     IF X1 + IDENT_INT(1) /= X2 THEN
          FAILED ("INCORRECT PROCEDURE IDENTIFICATION");
     END IF;

     IF C23006G_INSTF + IDENT_INT(1) /= C23006GINSTF THEN
          FAILED ("INCORRECT FUNCTION IDENTIFICATION");
     END IF;

     RESULT;
END C23006G;
