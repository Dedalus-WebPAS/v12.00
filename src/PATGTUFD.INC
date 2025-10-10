. **********************************************************************
. *                                                                    *
. *     Include Name : PATGTUFD.INC                                    *
. *                                                                    *
. *     Function     : File Definition include for Patient             *
. *                    GST Unknown                                     *
. *                                                                    *
. *     File Type    : SQL                                             *
. *                                                                    *
. *     File Name    : patgtuaf.dat                                    *
. *                                                                    *
. *     Keys         : KEY8                                            *
. *                                                                    *
. *     Modifications:                                                 *
. **********************************************************************
. * V12.00.01 29/04/2025 Thanh T     TSK 0955096                       *
. *           Changed PTGTADMN from FORM(8) to DIM(8)                  *
. **********************************************************************
.
PATGTUA1  IFILE SQL, FIXED=40, KEY="U1-8"
.
.NAME     TYPE   LENGTH  PHYSICAL   START     DESCRIPTION
.----     ----   ------  --------   -----     -----------
DPTGTADM  DIM      8        8         1       Admission Number
PTGTGSTA  FORM     1        2         9       Unknown Accommodation GST (1-Yes)
PTGTGSTM  FORM     1        2        11       Unknown MBS/Item GST (1-Yes)
PTGTSPAR  DIM      27      27        13       Spare variable
.
.End of Record                       40
.
.  redefine form fields for key
.  ----------------------------
.Name     Type      Length  Description
.-------  ----      ------  ---------------------
PTGTADMN  DIM         8     Admission Number
