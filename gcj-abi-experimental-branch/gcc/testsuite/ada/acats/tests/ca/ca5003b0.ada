-- CA5003B0.ADA

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
-- WKB 7/22/81
-- JBG 10/6/83
-- BHS 8/02/84
-- JRK 9/20/84


PACKAGE CA5003B0 IS

     ORDER : STRING (1..4) := "    ";

     INDEX : NATURAL := 1;

     FUNCTION SHOW_ELAB (UNIT : CHARACTER) RETURN INTEGER;

END CA5003B0;


PACKAGE BODY CA5003B0 IS

     FUNCTION SHOW_ELAB (UNIT : CHARACTER) RETURN INTEGER IS
     BEGIN
          ORDER (INDEX) := UNIT;
          INDEX := INDEX + 1;
          RETURN INDEX - 1;
     END SHOW_ELAB;

END CA5003B0;
