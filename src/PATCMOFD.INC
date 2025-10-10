.  **********************************************************************
.  *                                                                    *
.  *     Include Name : PATCMOFD.INC                                    *
.  *                                                                    *
.  *     Function     : File Definition include for Patient             *
.  *                    Morbidity Changes                               *
.  *                                                                    *
.  *     File Type    : SQL                                             *
.  *                                                                    *
.  *     File Name    : patcmorf.dat                                    *
.  *                                                                    *
.  *     Keys         : KEY 16                                          *
.  *                                                                    *
.  *     Modifications:                                                 *
.  **********************************************************************
.  * V12.00.01 29/04/2025 Thanh T     TSK 0955096                       *
.  *           Changed CMADMNO from FORM(8) to DIM(8)                   *
.  **********************************************************************
.  *                                                                    *
.  **********************************************************************
.
PATCMOR1  IFILE  SQL, FIXED=30, KEY="U1-8,9-16"
PATCMOR2  IFILE  SQL, FIXED=30, KEY="U9-16,1-8"
.
.Name     Type   Length   Physical   Start   Description
.----     ----   ------   --------   -----   -----------
DCMADMNO  DIM       8         8          1   ADMISSION NUMBER
CMCDATE   DIM       8         8          9   DATE OF MORBIDITY CHANGE (CCYYMMDD)
CMNEWFLG  DIM       1         1         17   FIRST RECORD FLAG
.                                              " " means new record
.                                              "C" means change record
CMSPARE   DIM       12        12        18   SPARE VARIABLE
.
.End of Record                          30
.
. redefine form fields in key
. ---------------------------
CMADMNO   DIM       8         8          1   ADMISSION NUMBER
