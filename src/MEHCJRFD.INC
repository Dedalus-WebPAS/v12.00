. *****************************************************************************
. *                                                                           *
. * Include Name  : MEHCJRFD.INC                                              *
. *                                                                           *
. * Function      : File Def'n Include for Mental Health                      *
. *                 CJA Status Review History                                 *
. *                                                                           *
. * File Type     : SQL                                                       *
. *                                                                           *
. * File Name     : mehcjraf.dat                                              *
. *                                                                           *
. * Keys          : KEY21                                                     *
. *                                                                           *
. * I/O Include   : MEHCJRIO.INC                                              *
. *                                                                           *
. * Author        : Steve Armstrong 08/01/1997                                *
. *                                                                           *
. * Modifications :                                                           *
. *****************************************************************************
. * V12.00.01 28/04/2025 Thanh T     TSK 0955096                              *
. *           Changed MHCRADMN from FORM(8) to DIM(8)                         *
. *****************************************************************************
.
.Data File Definition
.--------------------
MEHCJRA1  IFILE     SQL, FIXED=68, KEY="U1-8,9-16,17-21"
.
. Name    Type      Length  Phys.  Start  Description
. ----    ----      ------  -----  -----  -----------
DMHCRADM  DIM       8           8      1  Admission Number
MHCRDATE  DIM       8           8      9  Date of review
MHCRTIME  DIM       5           5     17  Time of review (HH:MM)
MHCRDECI  FORM      1           2     22  Review decision
.                                           1 = Yes ; 2 = No
MHCRLDAT  DIM       8           8     24  Date of new cja status (Yes only)
MHCRLTIM  DIM       5           5     32  Time of new cja status (Yes only)
MHCRREAS  DIM       3           3     37  Reason for decision (Cat DE) (No only)
MHCRNDAT  DIM       8           8     40  Date of next review
MHCRSPAR  DIM       20         20     48  Spare variable
.End of Record                        68
.
.Redefine form fields from key
.-----------------------------
. Name    Type      Length  Start  Description
. ----    ----      ------  -----  -----------
MHCRADMN  DIM       8           1  Admission Number
.
