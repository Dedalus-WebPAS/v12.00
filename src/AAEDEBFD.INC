.  **********************************************************************
.  *                                                                    *
.  *     Include Name : AAEDEBFD.INC                                    *
.  *                                                                    *
.  *     Function     : File Definition include for Accident & Emergency*
.  *                    A&E Comments                                    *
.  *                                                                    *
.  *                                                                    *
.  *     File Type    : SQL                                             *
.  *                                                                    *
.  *     File Name    : aaedetbf.dat                                    *
.  *                                                                    *
.  *     Keys         : KEY 10                                          *
.  *                                                                    *
.  *     Modifications:                                                 *
.  **********************************************************************
.  * V12.00.01 28/04/2025 Thanh T     TSK 0955096                       *
.  *           Changed ADBNUMB from FORM(8) to DIM(8)                   *
.  **********************************************************************
.  *                    V5.00 22.03.89 J.Clark     (IBA)                *
.  *                          Change includes heading                   *
.  *                    V5.01 20.04.89 K.Peak      (IBA)                *
.  *                          Changes made to keys SRF  (RENO)          *
.  *                                                                    *
.  **********************************************************************
.
AAEDETB1  IFILE    SQL, FIXED=100, KEY="U1-8,9-10"
.
. NAME     TYPE   LENGTH   PHYSICAL  START LOC.   DESCRIPTION
. ----     ----   ------   --------  ----------   -----------
DADBNUMB   DIM      8            8          1      A & E NUMBER
DADBCLNO   DIM      2            2          9      CURRENT LINE NUMBER
ADBLINE    DIM     70           70         11      COMMENT LINE
ADBSPARE   DIM     19           19         81      ** SPARE **
.
.End of Record                  100
.
.  redefine form fields from key
.  -----------------------------
. NAME     TYPE      LENGTH     START LOC.   DESCRIPTION
. ----     ----      ------     ----------   -----------
ADBNUMB    DIM         8             1       A & E NUMBER
ADBCLNO    FORM        2             7       CURRENT LINE NUMBER
