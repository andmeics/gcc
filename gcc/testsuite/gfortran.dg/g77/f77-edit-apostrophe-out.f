C Test Fortran 77 apostrophe edit descriptor 
C      (ANSI X3.9-1978 Section 13.5.1)
C
C Origin: David Billinghurst <David.Billinghurst@riotinto.com>
C
C { dg-do run }
C { dg-output "^" }
 10   format('abcde') 
 20   format('and an apostrophe -''-')
 30   format('''a leading apostrophe')
 40   format('a trailing apostrophe''')
 50   format('''and all of the above -''-''')

      write(*,10)        ! { dg-output "abcde(\n|\r\n|\r)" } 
      write(*,20)        ! { dg-output "and an apostrophe -'-(\n|\r\n|\r)" }
      write(*,30)        ! { dg-output "'a leading apostrophe(\n|\r\n|\r)" }
      write(*,40)        ! { dg-output "a trailing apostrophe'(\n|\r\n|\r)" }
      write(*,50)        ! { dg-output "'and all of the above -'-'(\n|\r\n|\r)" }

C { dg-output "\$" }
      end
