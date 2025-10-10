.  ************************************************************************
.  *                                                                      *
.  *  Include Name      :   EMRVDGFD.INC                                  *
.  *                                                                      *
.  *  Function          :   File Definition include for Emergency         *
.  *                        Visit Diagnosis Details                       *
.  *                                                                      *
.  *  File Type         :   SQL                                           *
.  *                                                                      *
.  *  File Name         :   emrvdgaf.dat                                  * 
.  *  Audit File                                                          *
.  *                                                                      * 
.  *  Keys              :   Key 17                                        *
.  *                                                                      *
.  *  Modifications     :                                                 *
.  ************************************************************************
.  * V12.00.01 28/04/2025 Thanh T     TSK 0955096                         *
.  *           Changed EMVDADMN from FORM(8) to DIM(8)                    *
.  ************************************************************************
.
.Data File Definition
.--------------------
EMRVDGA1   IFILE SQL, FIXED=30, KEY="U1-8,9-17"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
DEMVDADM  DIM         8        8      1   Emergency Visit Number
EMVDCODE  DIM         9        9      9   Diagnosis Code (ICD9)
EMVDPRIM  DIM         1        1     18   Primary Diagnosis
.                                            "Y"es or "N"o
EMVDSEND  DIM         1        1     19   Send in Extract Flag
.                                            "Y"es or "N"o
EMVDSPAR  DIM        10       10     20   Spare Variable
.
.End of Record                       30
.
. Redefine form fields from key
. -----------------------------
EMVDADMN  DIM       8
