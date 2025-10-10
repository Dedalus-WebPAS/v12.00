.  **********************************************************************
.  *                                                                    *
.  *     Include Name : PATDAYFD.INC                                    *
.  *                                                                    *
.  *     Function     : File Definition include for Patient             *
.  *                    Daily Patient List                              *
.  *                                                                    *
.  *     File Type    : SQL                                             *
.  *                                                                    *
.  *     File Name    : patdayaf.dat                                    *
.  *                                                                    *
.  *     Keys         : KEY 12,                                         *
.  *                                                                    *
.  *     Modifications:                                                 *
.  **********************************************************************
.  * V12.00.01 29/04/2025 Thanh T     TSK 0955096                       *
.  *           Changed PTDYADMN from FORM(8) to DIM(8)                  *
.  **********************************************************************
.  *                                                                    *
.  **********************************************************************
.
PATDAYA1  IFILE     SQL, FIXED=13, KEY="U1-4,5-12"      * both are the same file
PATDBYB1  IFILE     SQL, FIXED=13, KEY="U1-4,5-12"      
FILDAYA1  INIT      "patd"
.
. NAME    TYPE   LENGTH  PHYSICAL  START     DECRIPTION
. ----    ----   ------  --------  ------    ----------
PTDYDATE  DIM         4         4       1    Date (MMDD)
DPTDYADM  DIM         8         8       5    Admission Number
.
.End of Record                         13
.
. redefine form fields from key
. -----------------------------
. NAME    TYPE   LENGTH  DECRIPTION
. ----    ----   ------  ----------
PTDYADMN  DIM         8  Admission Number
