. V11.05.00 11/03/2025  Davin       TSK 0956210 - Created ICD10 Ed.13 Opr.KI FD
. *----------------------------------------------------------------------
. * Include Name  :   PTOK13FD.INC
. *
. * Function      :   File Def'n Include for WEB          
. *                   Patient ICD10 Edition 13 Procedure Codes Keyword Index
. *
. * File Type     :   SQL
. *
. * File Name     :   patok13f.dat
. *
. * Modifications :
. *      V11.05.00  11/03/2025  Davin            TSK 0956210
. *                 Created ICD10 Ed.13 Procedure Codes Keyword Index
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PTOK13A1   IFILE    SQL, FIXED=35, KEY="U1-9,10-24"                             
PTOK13A2   IFILE    SQL, FIXED=35, KEY="U10-24,1-9"                             
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
.PTCOITM   DIM       9      9        1     ICD10 Proc Code                    
.PTCOKWD   DIM       15     15       10    Key Word                           
.PTCOSPA   DIM       10     10       25    Spare                              
.
.End of Record                      35   
.
