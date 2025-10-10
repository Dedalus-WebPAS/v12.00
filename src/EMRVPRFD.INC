.  ************************************************************************
.  *                                                                      *
.  *  Include Name      :   EMRVPRFD.INC                                  *
.  *                                                                      *
.  *  Function          :   File Definition include for Emergency         *
.  *                        Visit Procedure Details                       *
.  *                                                                      *
.  *  File Type         :   SQL                                           *
.  *                                                                      *
.  *  File Name         :   emrvpraf.dat                                  * 
.  *  Audit File                                                          *
.  *                                                                      * 
.  *  Keys              :   Key 17                                        *
.  *                                                                      *
.  *  Modifications     :                                                 *
.  ************************************************************************
.  * V12.00.01 28/04/2025 Thanh T     TSK 0955096                         *
.  *           Changed EMVPADMN from FORM(8) to DIM(8)                    *
.  ************************************************************************
.
.Data File Definition
.--------------------
EMRVPRA1   IFILE SQL, FIXED=30, KEY="U1-8,9-17"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
DEMVPADM  DIM         8        8      1   Emergency Visit Number
EMVPCODE  DIM         9        9      9   Procedure Code
EMVPSEND  DIM         1        1     18   Send in Extract Flag
.                                            "Y"es or "N"o
EMVPSPAR  DIM        11       11     19   Spare Variable
.
.End of Record                       30
.
. Redefine form fields from key
. -----------------------------
EMVPADMN  DIM       8
