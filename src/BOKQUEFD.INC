.  ************************************************************************
.  *                                                                      *
.  *  Include Name      :   BOKQUEFD.INC                                  *
.  *                                                                      *
.  *  Function          :   Queuing Patient Booking Message File          *
.  *                                                                      *
.  *  File Type         :   SQL                                           *
.  *                                                                      *
.  *  File Name         :   bokqueaf.dat                                  * 
.  *                                                                      * 
.  *  Keys              :   KEY20                                         *
.  *                                                                      *
.  *  Modifications     :                                                 *
.  ************************************************************************
.  * V12.00.01 28/04/2025 Thanh T     TSK 0955096                         *
.  *           Changed BKREBOOK, BKREADMN from FORM(8) to DIM(8)          *
.  ************************************************************************
.  *     V10.06.01 25/06/2015  Steve Armstrong CAR 318558                 *
.  *               Changed BKRERFGP to XXXXRFGP                           *
.  *      V9.02.00 01/10/2001  Steve Armstrong                            *
.  *               FD Created                                             *
.  *                                                                      *
.  ************************************************************************
.
.Data File Definition
.--------------------
BOKQUEA1   IFILE SQL, FIXED=600, KEY="U1-20"
.
.Name      Type  Length Physical Start Description
.----      ----  ------ -------- ----- -----------
DBKQUMES   DIM     20      20       1   Message Id
.
.          BOKRC1FD variables
.
.BKREBOOK  DIM      8       8      21   Booking/Admission No.
.BKREURNO  DIM      8       8      29   U/R Number
.BKREADOC  DIM      6       6      37   Attending Doctor
.BKRESDOC  DIM      6       6      43   Referring Doctor
.BKREEDAT  DIM      8       8      49   Expected due date (CCYYMMDD)
.BKREATIM  DIM      8       8      57   Expected assessment time
.BKREPDAT  DIM      8       8      65   Pre-assessment date
.BKREPTIM  DIM      8       8      73   Pre-assessment time
.BKREADAT  DIM      8       8      81   Date booking was made CCYYMMDD
.BKRETYPE  DIM      3       3      89   Booking type (Cat "BK")
.BKRECANC  DIM      3       3      92   Cancellation reason (Cat "BC")
.BKREOMEM  DIM      1       1      95   Benefit fund member (Y/N/U)
.BKREPREV  DIM      1       1      96   Previous inpatient (Y/N/U)
.BKREACCM  DIM      3       3      97   Preferred accommodation (Cat BP)
.BKREPROC  DIM      9       9     100   Waiting list procedure code
.BKRECNT   FORM     2       2     109   Waiting list procedure count
.BKREWARD  DIM      3       3     111   Expected ward
.BKREADMN  DIM      8       8     114   Maternity admission number
.BKREPREA  DIM      1       1     122   Deposit paid (Y/N) Matern only
.BKREEBED  DIM      3       3     123   Expected bed
.BKRECLSS  DIM      3       3     126   Patient Cat./Adm Class. (Cat P)
.BKREATYP  DIM      3       3     129   Adm Type/Pat. Class (Cat A)
.BKREDEPT  DIM      3       3     132   Department (Cat AC)
.BKRETDOC  DIM      6       6     135   Associated Doctor
.BKRECLMT  DIM      3       3     141   Claim type (Cat CL)
XXXXRFGP   DIM      8       8     144   Referring GP
.BKREGPPC  DIM      6       6     152   GP Practice code
.BKREGPFA  DIM      20      20    158   GPFH Approval Number
.BKRERESI  DIM      3       3     178   Resident Status (Cat T)
.BKREEATY  DIM      3       3     181   Elective Admission Type  (Cat CC)
.BKREECRA  DIM      20      20    184   ECR Approval Number
.BKREGPPT  DIM      2       2     204   GP Practice count
.BKREDOFR  DIM      3       3     206   District of Residence (Cat DA)
.BKREOPER  DIM      4       4     209   Operator who made I/P Booking
.BKREELOS  FORM     3       3     213   Expected Length of Stay (Days)
.BKREBKDT  DIM      8       8     216   Booking date (ccyymmdd)
.
.          BOKRX1FD variables
.
.BKRXPOWD  DIM      3       3     224   Post-Op Ward (patwr1af)
.BKRXADWD  DIM      3       3     227   Admitting Ward (patwr1af)
.BKRXCDTE  DIM      8       8     230   Contact Date (ccyymmdd)
.BKRXPSTY  DIM      1       1     238   Parent Staying (0=NO,1=YES)
.BKRXCNDT  DIM      8       8     239   Confirmation Date (ccyymmdd)
.BKRXUDF1  DIM      3       3     247   User Defined Field 1 (Cat BE)
.BKRXUDF2  DIM      3       3     250   User Defined Field 2 (Cat BF)
.BKRXUDF3  DIM      3       3     253   User Defined Field 3 (Cat BG)
.BKRXUDF4  DIM      3       3     256   User Defined Field 4 (Cat BH)
.BKRXUDF5  DIM      3       3     259   User Defined Field 5 (Cat BL)
.BKRXUDD1  DIM      8       8     262   User Defined Date 1 (ccyymmdd)
.BKRXUDD2  DIM      8       8     270   User Defined Date 2 (ccyymmdd)
.BKRXUDD3  DIM      8       8     278   User Defined Date 3 (ccyymmdd)
.BKRXUDD4  DIM      8       8     286   User Defined Date 4 (ccyymmdd)
.BKRXUFF1  DIM     50      50     294   Procedure Description 1
.BKRXUFF2  DIM     50      50     344   Procedure Description 2
.BKRXUFF3  DIM     50      50     394   Procedure Description 3
.BKRXUFF4  DIM     50      50     444   User Defined Free Format 4
.BKRXEDC1  DIM     10      10     494   Extra Doctor Code 1 (pmshcpaf)
.BKRXEDC2  DIM     10      10     504   Extra Doctor Code 2 (pmshcpaf)
.BKRXEDC3  DIM     10      10     514   Extra Doctor Code 3 (pmshcpaf)
.BKRXODTE  DIM      8       8     524   Operation Date (ccyymmdd)
.BKRXOPRD  DIM      3       3     532   Operation Period (Cat SP)
BKQUSPAR   DIM     65      65     535   Spare Variable
.
.End of Record                   600
.
.
. Redefine form fields from key
. -----------------------------
BKQUMESI   FORM    20

