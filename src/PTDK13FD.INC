. V11.05.00 11/03/2025  Davin       TSK 0956210 - Created ICD10 Ed.13 Dis.KI FD
. *----------------------------------------------------------------------
. * Include Name  :   PTDK13FD.INC
. *
. * Function      :   File Def'n Include for WEB          
. *                   Patient ICD10 Edition 13 Diagnosis Codes Keyword Index
. *
. * File Type     :   SQL
. *
. * File Name     :   patdk13f.dat
. *
. * Modifications :
. *      V11.05.00  11/03/2025  Davin            TSK 0956210
. *                 Created ICD10 Ed.13 Diagnosis Codes Keyword Index
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PTDK13A1   IFILE    SQL, FIXED=35, KEY="U1-9,10-24"                             
PTDK13A2   IFILE    SQL, FIXED=35, KEY="U10-24,1-9"                             
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
.PTCDITM   DIM       9      9        1     ICD10 Diagnosis Code               
.PTCDKWD   DIM       15     15       10    Key Word                           
.PTCDSPA   DIM       10     10       25    Spare                              
.
.End of Record                      35   
.
