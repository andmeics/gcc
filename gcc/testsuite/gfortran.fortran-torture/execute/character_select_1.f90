CHARACTER(LEN=6) :: C = "STEVEN"

SELECT CASE (C)
   CASE ("AAA":"EEE")
      STOP 1
   CASE ("R":"T")
      CONTINUE
   CASE DEFAULT
      STOP 2
END SELECT
END

