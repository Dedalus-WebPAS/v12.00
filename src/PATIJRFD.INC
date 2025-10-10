.  **********************************************************************
.  *                                                                    *
.  *     Include Name : PATIJRFD.INC                                    *
.  *                                                                    *
.  *     Function     : File Definition include for Patient             *
.  *                    Invoices with Journals Entered                  *
.  *                                                                    *
.  *     File Type    : SQL                                             *
.  *                                                                    *
.  *     File Name    : patijrnf.dat                                    *
.  *                                                                    *
.  *     Keys         : KEY 16                                          * 
.  *                                                                    *
.  *     Modifications:                                                 *
.  **********************************************************************
.  * V12.00.01 29/04/2025 Thanh T     TSK 0955096                       *
.  *           Changed IJADMNO from FORM(8) to DIM(8)                   *
.  **********************************************************************
.  *                    V5.01.01 18/08/89 J.Tan                         *
.  *                             Added batch number                     *
.  *                    V5.01.02 09/10/90 J.Tan    SRF 106481           *
.  *                             Remove the first index                 *
.  *                                                                    *
.  **********************************************************************
.
PATIJRN1  IFILE    SQL, FIXED=37, KEY="U17-24,1-8"
.
. NAME     TYPE   LENGTH   PHYSICAL  START LOC.   DESCRIPTION
. ----     ----   ------   --------  ----------   -----------
IJINVNO    DIM     8          8          1         Invoice Number
IJADMNO    DIM     8          8          9         Admission Number
DIJBATCH   DIM     8          8          17        Batch Number
IJSPARE    DIM     12         12         25        Spare
.
.End of Record                           37
.
. Redefines form fields from key  
. ------------------------------
. NAME     TYPE    LENGTH  START     DESCRIPTION
. ----     ----    ------  -----     -----------
IJBATCH    FORM         8      17    Batch Number
.
