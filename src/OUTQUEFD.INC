.  **************************************************************************
.  *                                                                        *
.  *  Include Name      :   OUTQUEFD.INC                                    *
.  *                                                                        *
.  *  Function          :   Queuing Outpatient Details Message File         *
.  *                                                                        *
.  *  File Type         :   SQL                                             *
.  *                                                                        *
.  *  File Name         :   outqueaf.dat                                    * 
.  *                                                                        *   
.  *  Keys              :                                                   *
.  *                                                                        *
.  *  Modifications     :                                                   *
.  **************************************************************************
.  * V12.00.01 08/05/2025 Thanh T     TSK 0955096                           *
.  *           Changed OBAOUTNO, OPRSOUTN, OPCNOUTN from FORM(8) to DIM(8)  *
.  **************************************************************************
.  * V10.15.01 08/10/2019  Richa Phogat  TSK 0861253                        *
.  *           Added OUTTHIFD: OTTHSTAT, OTTHRSIT, OTTHRCOD, OTTHRADD,      *
.  *           OTTHWURL, OTTHE164                                           *
.  **************************************************************************
.  * V10.13.01 08/10/2018  Steve Armstrong    TSK 0859743                   *
.  *           Added OTBBRDAT                                               *
.  *           02/10/2018  Thanh T            TSK 0859743                   *
.  *           Added OTBBBKOV OTBBBKPR OTBBBKPM OTBBBKBA                    *
.  **************************************************************************
.  * V10.10.01 27/03/2017  Steve Armstrong    TSK 0833314                   *  
.  *           Added OTBBPURC.                                              *
.  **************************************************************************
.  * V10.06.01 18/03/2015  Ebon Clements      CAR 298921                    *
.  *           Changed OTBBADCS from DIM 6 to DIM 10                        *
.  **************************************************************************
.  * V10.05.01 17/07/2014  Ebon Clements      CAR 251384                    *
.  *           Added OTBBTCOD from OUTBB1FD                                 *
.  **************************************************************************
.  * V10.04.01 26/02/2014  Steve Armstrong    CAR 208234                    *
.  *           Added new fields from OUTBB1FD: OTBBSPAR, OBALADMN, OTBBSNDL,* 
.  *           OTBBGPPT, OTBBFLUP, OTBBSCAR, OTBBGLDT, OTBBSNGL, OTBBNMDS,  *
.  *           OTBBCART, OTBBSRVD, OTBBCLHR, OTBBCONT                       *
.  **************************************************************************
.  * V9.06.01  08/05/2006  Steve Armstrong    CAR 103759                    *
.  *           Fixed OTBBRFGP & OTBBGPPC lengths (10 char)                  * 
.  **************************************************************************
.  * V9.05.01  03/03/2006  Steve Armstrong    CAR 88829                     *
.  *           Added OBASTAT                                                *
.  **************************************************************************
.  * V9.03.01  22/12/2003  Steve Armstrong    CAR 45916                     * 
.  *           Added OTBBCIND                                               *
.  **************************************************************************
.  * V9.02.01  10/02/2003  Davin CAR 33610                                  *
.  *           Added OTMALTYP                                               *
.  * V9.02.00  03/10/2001  Steve Armstrong                                  *
.  *           FD Created                                                   *
.  **************************************************************************
.
.Data File Definition
.--------------------
OUTQUEA1   IFILE SQL, FIXED=1581, KEY="U1-20"
.
.Name      Type   Length Physical Start Description
.----      ----   ------ -------- ----- -----------
DOTQUMES   DIM      20      20       1   Message Id
.
.         OUTBOAFD variables
.
.OBASITE   DIM       6       6      21   SITE ID
.OBACLIN   DIM       6       6      27   CLINIC ID
.OBADATE   DIM       8       8      33   DATE (CCYYMMDD)
.OBASTRT   DIM       5       5      41   START TIME (HH:MM)
.OBASLOT   FORM      3       3      46   SLOT NUMBER
.OBATIME   DIM       5       5      49   SLOT TIME  (HH:MM)
.OBACTYP   DIM       6       6      54   CLINIC TYPE
.OBAVISIT  DIM       3       3      60   VISIT TYPE (N,R,S)(CV)
.OBAOUTNO  DIM       8       8      63   OUTPATIENT NUMBER
.OBASESST  DIM       3       3      71   SESSION STATUS CODE (CS)
.
.          OUTBB1FD variables
.
.OBASRCR   DIM       3       3      74   Source of Referral (S)
.OBACOMP   DIM       3       3      77   Compensation Eligibility (CL)
.OBACLASS  DIM       3       3      80   Patient Classification (A )
.OBAINS    DIM       3       3      83   Insurance Status (U1)
.OBAATTN   DIM       3       3      86   Attendance Code (CA)
.OBADOCT   DIM       6       6      89   Doctor's Code
.OBACOMM   DIM      25      25      95   Comments
.OTBBFUND  DIM       6       6     120   Health fund code
.OTBBTBLE  DIM       8       8     126   Health fund table
.OTBBPVIS  FORM      3       3     134   No. of prev. visits charged
.OTBBCLAL  DIM       3       3     137   Clinic Allocation (OX) (Anne Caudle)
.OTBBSPAR  DIM       4       4     140   Spare variable
.OBACAT    DIM       3       3     144   Patient Category (P )
.OBAPRTY   DIM       3       3     147   Priority Code (PR)
.OBARSCHD  DIM       3       3     150   Reason for Reschedule (RR)
.OBBBOOK   DIM       1       1     153   Non-booked attendee flag
.                                            " " = Booked attendee
.                                            "N" = Non-booked attendee, no slot
.                                            "S" = Non-booked attendee with slot
.OBOUSR1   DIM       3       3     154   User Defined Field 1 (O1)
.OBOUSR2   DIM       3       3     157   User Defined Field 2 (O2)
.OBOUSR3   DIM       3       3     160   User Defined Field 3 (O3)
.OBOUSR4   DIM       3       3     163   User Defined Field 4 (O4)
.OBALADMN  DIM       8       8     166   Linked Outpatient Visit Number
.                                          from re-appointments module
.OTBBDEPT  DIM       3       3     174   Department code (Cat AC)
.OTBBTRAN  DIM       3       3     177   Transport Allocation (Cat OB)
.OTBBLNGI  DIM       3       3     180   Language of Interpreter (Cat OL)
.OTBBTMFS  DIM       8       8     183   Time First Seen
.OTBBTMBO  DIM       8       8     191   Time Booked Out
.OTBBGPFA  DIM      20      20     199   GPFH Approval Number
.OTBBECRA  DIM      20      20     219   ECR Approval Number
.OTBBRFGP  DIM      10      10     239   Referring GP
.OTBBGPPC  DIM      10      10     249   GP Practice Code
.OTBBADCS  DIM      10      10     259   Actual Doctor Seen
.OTBBCITM  DIM       5       5     269   Check In Time
.OTBBASTM  DIM       5       5     274   Time Actually Seen
.OTBBDPTM  DIM       5       5     279   Time of Departure
.OTBBOUTC  DIM       3       3     284   Outcome    (CAT OZ)
.OTBBSNDL  DIM       1       1     287   Send Letter (Notify GP) (Y/N)
.OTBBGPPT  DIM       2       2     288   GP Practice count
.OTBBDOFR  DIM       3       3     290   District of Residence (Cat DA)
.OBOUSR5   DIM       3       3     293   User Defined Field 5 (O5)
.OBOUSR6   DIM       3       3     296   User Defined Field 6 (O6)
.OBOUSR7   DIM       3       3     299   User Defined Field 7 (O7)
.OBOUSR8   DIM       3       3     302   User Defined Field 8 (O8)
.OTBBRANK  DIM       6       6     305   Patient Rank
.OTBBSPCA  DIM       3       3     311   Special Arrangements
.OTBBCIND  DIM       3       3     314   Clinic Indicator (CI) M=MEDICAL
.                                                              N=NON-MEDICAL
.OTBBFLUP  DIM       1       1     317   Follow Up App. Made Flag 1=Yes
.OTBBSCAR  DIM       1       1     318   Send Correspondence to Carer
.                                           0=No 1=Yes
.OTBBGLDT  DIM       8       8     319   Generate Letter Date (ccyymmdd)
.OTBBSNGL  DIM       1       1     327   Send Generate Letter (Y/N)
.                                           0=No, 1=Yes, 2=N/A
.OTBBNMDS  DIM       3       3     328   NMDS Code (Category NM)
.OTBBCART  DIM       3       3     331   Care Type (Category CC)
.OTBBSRVD  DIM       3       3     334   Service Delivery Mode(Cat sd)
.OTBBCLHR  DIM       1       1     337   Clinical High Risk
.                                           0=No, 1=Yes
.OTBBCONT  DIM       3       3     338   Contract Code (Cat gb)
.OTBBTCOD  DIM       3       3     341   Tier 2 Code (category NC)
.
.          OUTRSHFD variables
.
.OPRSSITE  DIM       6       6     344   Site of booking
.OPRSCLIN  DIM       6       6     350   Original clinic of booking
.OPRSDATE  DIM       8       8     356   Original date of booking
.OPRSSTRT  DIM       5       5     364   Original session start time
.OPRSSLOT  FORM      3       3     369   Original session slot number
.OPRSTIME  DIM       5       5     372   Original session slot time
.OPRSOUTN  DIM       8       8     377   Outpatient number rescheduled
.OPRSREAS  DIM       3       3     385   Reason for reschedule (RR)
.OPRSNCLI  DIM       6       6     388   New clinic of booking
.OPRSNDAT  DIM       8       8     394   New date of booking
.OPRSNSTR  DIM       5       5     402   New session start time
.OPRSNSLO  FORM      3       3     407   New session slot number
.OPRSNTIM  DIM       5       5     410   New session slot time
.
.OPRSNVIS  DIM       3       3     415   New Visit Type  (Cat CV)
.OPRSNTYP  DIM       6       6     418   New Clinic Type
.OPRSVIST  DIM       3       3     424   Old Visit Type  (Cat CV)
.OPRSCTYP  DIM       6       6     427   Old Clinic Type
.
.          OUTCANFD variables
.
.OPCNSITE  DIM       6       6     433   Site of cancelled booking
.OPCNCLIN  DIM       6       6     439   Clinic of cancelled booking
.OPCNDATE  DIM       8       8     445   Date of cancelled booking
.OPCNSTRT  DIM       5       5     453   Cancelled session start time
.OPCNSLOT  FORM      3       3     458   Cancelled session slot number
.OPCNTIME  DIM       5       5     461   Cancelled session slot time
.OPCNOUTN  DIM       8       8     466   Outpatient number cancelled
.OPCNREAS  DIM       3       3     474   Reason for cancellation (CB)
.OPCNVTYP  DIM       3       3     477   Visit Type of Booking (CV)
.
.          OUTMA1FD variables
.
.OTMALTYP  DIM       3       3     480   Location Type (Category CT)
.
.OBASTAT   FORM      1       2     483   Booking Status
.OTBBPURC  DIM       3       3     485   Health Purchaser (Cat HP)
.OTBBBKOV  DIM       3       3     488   Referral Override (Cat ro)
.OTBBBKPR  DIM       3       3     491   Referral Period (Cat RF)
.OTBBBKPM  DIM       2       2     494   Referral Period Months (1-98)
.OTBBBKBA  DIM       1       1     496   Benefit Assignment Authorised
.                                         0 or Blank - No
.                                         1 - Yes
.OTBBRDAT  DIM       8       8     497   Date of Referral (CCYYMMDD)
.
.          OUTTHIFD variables
.
.OTTHSTAT  DIM       3      3      505   Telehealth Status (Category OM)
.OTTHRSIT  DIM       255    255    508   Telehealth Receiving Site Name
.OTTHRCOD  DIM       10     10     763   Telehealth Receiving Code
.OTTHRADD  DIM       512    512    773   Telehealth Receiving Address
.OTTHWURL  DIM       255    255    1285  Telehealth Waiting Room URL
.OTTHE164  DIM       20     20     1540  Telehealth Receiving E164
.
OTQUSPAR   DIM      21     21     1560  Spare Variable
.
.End of Record                    1581
.
. Redefine form fields from key
. -----------------------------
OTQUMESG   FORM     20
