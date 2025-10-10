. ************************************************************************
. *                                                                      *
. *  Include Name      :   PMSQVIFD.INC                                  *
. *                                                                      *
. *  Function          :   Queuing Visit Details Message File            *
. *                                                                      *
. *  File Type         :   SQL                                           *
. *                                                                      *
. *  File Name         :   pmsqviaf.dat                                  * 
. *                                                                      * 
. *  Keys              :   KEY22                                         *
. *                                                                      *
. *  Modifications     :                                                 *
. *                                                                      *
. ************************************************************************
. * V12.00.01 29/04/2025 Thanh T     TSK 0955096                         *
. *           Changed AADMNO, AMUMADM, TADMN, WSTBY from FORM(8) to      *
. *           DIM(8)                                                     *
. ************************************************************************
. *       V11.05.01 20/11/2024 Thanh T        TSK 0951086                *
. *                 Changed adyhosp and ptmi3bdy size from 3 to 4        *
. ************************************************************************
. *       V11.04.01 19/01/2024 Thanh T        TSK 0936282                *
. *                 Changed AFNDMM size from 10 to 19                    *
. ************************************************************************
. *       V11.00.01 01.04.2020  J.Tan          TSK 0868813               *
. *                 Changed PKNAME from DIM30 to DIM80                   *
. *       V10.13.01 08/10/2018 Steve Armstrong  TSK 0860678              *
. *                 Added variables PMBRREQD to PTDSCLGP (including      *
. *                 moving PMBRREQD & PMRQREQT from SPARE into normal FD *
.*                  fields.                                              *
. ************************************************************************
. *       V10.12.01 20/06/2018 Steve Armstrong  TSK 0854259              *
. *                 Added new variables PMBRREQD & PMRQREQT.             *
. ************************************************************************
. *       V10.10.01 21/06/2017 Steve Armstrong                           *
. *                 Changed description for PTMSFHAN from "GPFH Approval *
. *                 Number" to "eAdmission ID".                          *
. ************************************************************************
. *               V10.08.01 01/04/2016 Steve Armstrong  TSK 0296379      *
. *                         Added new variables from PATTRNFD            *
. *                         (PTTRFSRC, PTTRHFND, PTTRFTBL, PTTRHFMN &    *
. *                         PTTRHFCN)                                    *
. ************************************************************************
. *               V10.06.02 28/07/2015 Steve Armstrong                   *
. *                         Fixed spelling mistakes in field             *
. *                         descriptions for ACANCEL and AELIG           *
. *               V10.05.01 12/08/2014  Steve Armstrong   CAR 304812     *
. *                         Extended AINVPRT from FORM2 to FORM3.        *
. *                         Also moved a number of fields and added      *
. *                         some new fields which have been added to the *
. *                         corresponding FD's.                          *
. *               V10.04.02 06/01/2014  Ania P            CAR 294384     *
. *                         Added PMVXCPDD and PMVXPBMI                  *
. *               V10.04.01 02/01/2014  Patrick Adair     CAR 295320     *
. *                         Moved ACLSSFT, ADOCTA & ATYPE out of SPARE   *
. ************************************************************************
. *               V10.03.02 18/07/2013  Steve Armstrong   CAR 268961     *
. *                         Added ACLSSFT, ADOCTA & ATYPE into SPARE     *
. *                         variable.                                    *
. *               V10.03.01 11/11/2011  Mike Laming       CAR 251323     *
. *                         Moved OERDATE, OERTIME, PTMILSDN, & PTMIOGNO *
. *                         out of Spare                                 *
. ************************************************************************
. *               V10.02.03 27/10/2011  Steve Armstrong   CAR 251323     *
. *                         Added PTMILSDN and PTMIOGNO as extra         *
. *                         variables.                                   *
. *               V10.02.02 12/10/2011  Steve Armstrong   CAR 251644     *
. *                         Added OERDATE and OERTIME as extra variables *
. *               V10.02.01 27.07.2011  Steve Armstrong   CAR 246136     *
. *                         Updated table to contain all the new fields  *
. *                         added to the relevant tables.                *
. ************************************************************************
. *               V10.01.01 23.11.2011  Steve Armstrong   CAR 233088     *
. *                         Added PMVXFNDM.                              *
. ************************************************************************
. *               V9.11.02  23.12.2008  Ebon Clements     CAR 184296     *
. *                         Changed PKNAME from 20 to 30 character       *
. *               V9.11.01  20/10/2008  Davin             CAR 175736     *
. *                         Added WTSBY and increased length to 1615     *
. ************************************************************************
. *               V9.10.01  04/06/2008  Ebon Clements     CAR 151025     *
. *                         Added PTREMOBL                               *
. ************************************************************************
. *               V9.05.B02 13/12/2005  Steve Armstrong   CAR 88619      *
. *                         Added ASTAT                                  *
. *               V9.05.B01 30/01/2006  Peter Vela        CAR 54614      *
. *                         Added PATRE1FD variables                     *
. ************************************************************************
. *                V9.04.02 30/08/2005  Davin   CAR 64087                *
. *                         Changed pattranf amounts to 12.2             *
. *                         Added PMQVTDAT & PMQVTTIM                    *
. *                         Increased spare and table length             *
. *                V9.04.01 09/05/2004  Davin   CAR 22680                *
. *                         Added PMVXRH1G,PMVXRH1C                      *
. *                V9.02.00 01/10/2001  Steve Armstrong                  *
. *                         FD Created                                   *
. *                                                                      *
. ************************************************************************
.
.Data File Definition
.--------------------
PMSQVIA1   IFILE SQL, FIXED=2789, KEY="U1-20,21-22"
.
.Name      Type   Length  Physical Start Description
.----      ----   ------  -------- ----- -----------
DPMQVMES   DIM      20       20       1  Message Id
DPMQVTRN   DIM       2        2      21  Transaction Number
.
.          PATMI1FD variables
.
.AADMNO    DIM       8        8      23  PATIENT ADMISSION NO.
.AURNO     DIM       8        8      31  PATIENT U.R NO.
.ADATE     DIM       8        8      39  Admission Date (CCYYMMDD)
.ATIME     DIM       8        8      47  PATIENT ADMISSION TIME
.ASTAT     FORM      1        2      55  Admission Status
.                                             1 = Pre-Admission
.                                             2 = Current Admission
.                                             3 = Discharged
.                                             4 = On Leave
.                                             5 = Cancelled
.AINVPRT   FORM      3        3      57  NUMBER OF INVOICES PRINTED
.ALACDTE   DIM       8        8      60  last accom date invd (CCYYMMDD)
.ACANCEL   DIM       3        3      68  REASON PRE-ADMISS CANCELATION
.ADOCTR    DIM       6        6      71  DOCTOR REFERRED BY.
.ADOCTA    DIM       6        6      77  Attending Doctor (patdo1af)
.ADOCTL    DIM      30       30      83  LOCAL DOCTOR
.ASRCE     DIM       3        3     113  PATIENT ADMISSIONS SOURCE  (CAT S )
.ATYPE     DIM       3        3     116  Admission Type (Cat A)
.ACLSS     DIM       3        3     119  PATIENT ADMISSIONS CLASS   (CAT P )
.ACARE     DIM       3        3     122  PATIENT CARE CLASS         (CAT CC)
.AFUNDH    DIM       6        6     125  PATIENT HEALTH FUND
.AFNDTB    DIM       8        8     131  PATIENT FUND TABLE
.AFNDMM    DIM      19       19     139  PATIENT FUND MEMBERSHIP NO
.AELIG     FORM      1        2     158  PATIENT ELIGIBILITY FOR GOV'T
.                                         REBATE. 1 = YES  2 = NO
.                                         STH - DISCHARGE DIAG.PRINTED
.AVISIT    FORM      1        2     160  PATIENT RELIGIOUS VISIT
.                                                 1 = YES, 2 = NO
.AALERG    FORM      1        2     162  PATIENT ALLERGIES (Y/N)
.                                                 1 = YES, 2 = NO
.AILLN     FORM      1        2     164  PRE-EXISTING ILLNESS
.                                                 1 = YES, 2 = NO
.ADIAG1    DIM      80       80     166  PATIENTS ADMITTING DIAG 1
.ADIAG2    DIM      80       80     246   "   "     "   "     "  2
.ADISC     FORM      6.2      5     326  PATIENT DISCOUNT PERCENTAGE
.ADOCTT    DIM       6        6     331  TREATING DOCTOR
.ACLSSFT   DIM       3        3     337  Department (Cat AC)
.AALLOW    DIM       2        2     340  PATIENT ALLOWANCE CODE
.AMBS      DIM       9        9     342  ADMITTING MBS CODE
.ACLAIM    DIM       3        3     351  CLAIM CODE (CAT CL)
.ADIET     DIM       3        3     354  DIET CODE (CAT DC)
.APLOCCR   DIM       3        3     357  PLACE OF OCCR (CATEGORY PO)
.ASTAY     FORM      3        3     360  EXPECTED LENGTH OF STAY (DAYS)
.ADYHOSP   FORM      4        3     363  No OF DAYS OF HOSPITALIZATION
.AMEMB     FORM      1        2     366  DIAMOND VALLEY MEMBERSHIP
.                                                 1 = YES, 2 = NO
.AMEMBNO   FORM      6        4     368  MEMBERSHIP NUMBER
.ACOMM1    DIM      40       40     372  COMMENTS FIELD 1
.ACOMM2    DIM      30       30     412  COMMENTS FIELD 2
.APLUR     FORM      1        2     442  PLURATILY OF BABY (0=NORMAL)
.APURGE    FORM      1        2     444  PURGE INDICATOR
.                                                 OTHER = NO PURGE
.                                                 1     = PARTIAL
.                                                 2     = FULLY
.AUSR1     DIM       3        3     446  USER DEFINED FIELD 1 (CAT U1)
.AUSR2     DIM       3        3     449  USER DEFINED FIELD 2 (CAT U2)
.AUSR3     DIM       3        3     452  USER DEFINED FIELD 3 (CAT U3)
.AUSR4     DIM       3        3     455  USER DEFINED FIELD 4 (CAT U4)
.AUSR5     DIM       3        3     458  USER DEFINED FIELD 5 (CAT U5)
.AUSR6     DIM       3        3     461  USER DEFINED FIELD 6 (CAT U6)
.                                                 - Clinic Unit No. for Publics
.AUSR7     DIM       3        3     464  USER DEFINED FIELD 7 (CAT U7)
.                                                 - Coding status for Publics
.ADSCHI    FORM      1        2     467  DISCHARGE INVOICE INDICATOR
.                                                 0 = Discharge inv not printed
.                                                 1 = Have printed discharge inv
.ARDRNAM   DIM      22       22     469  FREE FORMAT REFERRING DOCTOR
.AFNDYY    DIM       2        2     491  YRS OF FUND MEMBERSHIP (JR,DE)
.AFNDCG    DIM       6        6     493  fund cover change (CCYYMM)
.AOCCDTE   DIM       8        8     499  DATE OF OCCURRENCE (CCYYMMDD)
.ACODDTE   DIM       8        8     507  DATE CODING COMPLETED
.ARETDTE   DIM       8        8     515 EXPECTED RETURN DATE FROM LVE
.AMUMADM   DIM       8        8     523  MOTHERS ADMSS NUMBER(IF BABY)
.PTMIPVIS  FORM      3        3     531  No of prev. visits charged
.ABWGHT    DIM       6        6     534  Baby's /Admission weight
.PTMSRFGP  DIM       8        8     540  Referring GP.
.PTMSGPPC  DIM       6        6     548  GP Practice Code
.PTMSFHAN  DIM      20       20     554  eAdmission ID
.PTMSECRA  DIM      20       20     574  ECR Approval Number
.PTMSMGIN  DIM       3        3     594  Management Intent   (CAT MI)
.PTMIDDIG  FORM      1        2     597  Discharged diagnosis printed?
.PTMIGPPT  DIM       2        2     599  GP Practice count
.PTMIDOFR  DIM       3        3     601  District of Residence (Cat DA)
.PTMIREFD  DIM       8        8     604  Date of Referral (EDI nz)
.PTMIDFCN  DIM       8        8     612  Date of 1st consultation (EDI nz)
.PTMIPHPU  DIM       3        3     620  Principal Health Service Purchaser
.                                         (EDI nz) (CAT HP)
.PTMIAGNC  DIM       3        3     623  Health Agency (EDI nz) (CAT HA)
.PTMIESSF  DIM       1        1     626  Event Summary supress flag Y/N(EDI nz)
.                                         "Y" = Suppress event summary
.                                         "N" = Don't supress
.PTMIUSR8  DIM       3        3     627  User defined field 8 (CAT U8)
.PTMIUSR9  DIM       3        3     630  User defined field 9 (CAT U9)
.PTMIUSR0  DIM       3        3     633  User defined field 0 (CAT U0)
.PTMIPDRG  DIM       4        4     636  Provisional DRG
.PTMIOPER  DIM       4        4     640  Operator who pre-admitted patient
.PTMIXWRD  DIM       3        3     644  Expected Ward for Pre-Admission
.PTMIADOC  DIM       6        6     647  Associated Doctor
.PTMIREGS  DIM       6        6     653  Registrar
.PTMIUYN1  FORM      1        2     659  User Defined Y/N Field (1=Yes, 0=No)
.PTMIUYN2  FORM      1        2     661  User Defined Y/N Field (1=Yes, 0=No)
.PTMIPANO  DIM       8        8     663  Previous admission number 
.PTMIPADT  DIM       8        8     671  Previous admission date (ccyymmdd)
.PTMIPCMX  DIM       9        9     679  Casemix Code (Provisional MBS/DRG)
.PTMIGSTA  DIM       1        1     688  Is GST applicable to this event
.                                         Y=Yes, N/Space=No, U=Unknown
.PTMICMXP  DIM       1        1     689  Casemix Payment (Y/N)
.                                         NZ Billing - FFS has been charged(Y/N)
.PTMIEBED  DIM       3        3     690  Expected Bed
.PTMIDMOV  DIM       1        1     693  Pre-admission movement indicator
.PTMIDFAS  DIM       8        8     694  Date Patient First Aware of Symptoms
.PTMICRCD  DIM       1        1     702  Credit Card Details on File (1=Yes)
.PTMIFINV  DIM       1        1     703  Follow-up for implant invoicing(1=Yes)
.PTMICONB  DIM       1        1     704  Continuous Billing Event (1=Yes)
.PTMIDATC  DIM       8        8     705  Date Created CCYYMMDD
.PTMITIMC  DIM       8        8     713  Time Created hh:mm:ss
.PTMIWEBC  DIM      10       10     721  Web user Id Created
.PTMIDATU  DIM       8        8     731  Date Updated CCYYMMDD
.PTMITIMU  DIM       8        8     739  Time Updated hh:mm:ss
.PTMIWEBU  DIM      10       10     747  Web user Id Updated
.PTMI3BDY  DIM       4        4     757  3B certificate days
.PTMI3BAD  DIM       8        8     761  3B certificate admission date
.PTMILSDN  DIM       8        8     769  Linked Statistical Discharge Number
.PTMIOGNO  DIM       8        8     777  Original Admission Number
.
.         PATTRNFD variables
.
.TWARD     DIM       3        3     785  TRANSFER WARD NUMBER
.TBED      DIM       3        3     788  TRANSFER BED NUMBER
.TDATE     DIM       8        8     791  TRANSFER DATE (CCYYMMDD)
.TTIME     DIM       8        8     799  TRANSFER TIME (HH:MM)
.TURNO     DIM       8        8     807  PATIENT U/R  NUMBER
.TADMN     DIM       8        8     815  PATIENT ADMISSION  NUMBER
.TRATEF    FORM      12.2     8     823  PAT PORTION OF DAILY CHARGE
.                                             Daily rate = TRATEF + TRATEH
.                                                          - TDISC - TALLW
.                                          Accommodation Charge - Nursing Home
.TRATEG    FORM      12.2     8     831  GOVERNMENT  CHARGEABLE
.TDISC     FORM      12.2     8     839  PAT DISC (SUB FROM TRATEF)
.TALLW     FORM      12.2     8     847  PAT ALLOW (SUB FROM TRATEF)
.TATYPE    DIM       3        3     855  ADMISSION TYPE
.TADOCT    DIM       6        6     858  ATTENDING DOCTOR
.TRATEH    FORM      12.2     8     864  H/FND PORTION OF DAILY CHARGE
.TEXTRA    FORM      12.2     8     872  EXTRA CHGE PER DAY (PUB HOSP)
.PTTRITFS  FORM      12.2     8     880  Nursing Home Income Tested fee
.TRBTYP    DIM       3        3     888  E.F.R. BED TYPE FOR THIS BED
.TRBEND    FORM      3        3     891  END DAY IN RNGE FOR THIS RATE
.TCHSTAT   DIM       3        3     894  CHRGEABLE STATUS (USER DEF.2)
.                                          (PUBLIC HOSPITAL ONLY)
.TDEPT     DIM       3        3     897  DEPARTMENT CODE (CAT AC)
.PTTRLTYP  DIM       3        3     900  Type of Patient leave (Cat TL)
.PTTREPNO  FORM      2        2     903  Episode number
.PTTREPSD  FORM      1        2     905  Manual Stepdown
.                                           0 - Normal
.                                           1 - Forced Stepdown
.                                           2 - Bed Fee Update
.PTTRLSPT  FORM     12.2      8     907  Patient portion of lumpsum
.PTTRLSRB  FORM     12.2      8     915  Rebate portion of lumpsum
.PTTRAEND  FORM      4        3     923  End day for additional rate
.PTTRADPT  FORM     12.2      8     926  Additional daily rate - pat.
.                                          Resident contribution - Nursing Home
.PTTRADRB  FORM     12.2      8     934  Additional daily rate - rebate
.PTTRNHAC  DIM        3       3     942  Nursing Home Account code (Catg NH)
.PTTROPER  DIM        4       4     945  Operator Id
.PTTRAUAT  DIM        1       1     949  Auto update of admission type
.PTTRCDAT  DIM        8       8     950  Date Record Created (CCYYMMDD)
.PTTRCTIM  DIM        8       8     958  Time Record Created (hh:mm:ss)
.PTTRCUID  DIM        4       4     966  Passcode Created
.PTTRLTSC  DIM        5       5     970  Leave Transfer Source
.PTTRUCID  DIM       10      10     975  Web User Id who Created Record
.PTTRUUID  DIM       10      10     985  Web User Id who Updated Record
.PTTRCLTY  DIM        3       3     995  Claim Type (Cat CL)
.PTTRTRTY  DIM        3       3     998  Transfer Type (Cat RB)
.PTTRTEAM  DIM        5       5    1001  Team
.PTTRRSTR  DIM       10      10    1006  Registrar
.PTTRRESI  DIM       10      10    1016  Resident
.PTTRFSRC  DIM       3       3     1026  Funding Source (Cat cx)
.PTTRHFND  DIM       6       6     1029  Health Fund Code (patfn1af)
.PTTRFTBL  DIM       8       8     1035  Health Fund Table (patfn1af)
.PTTRHFMN  DIM       19      19    1043  Health Fund Membership Number
.PTTRHFCN  DIM       40      40    1062  Health Fund Contributor Name
.
.         PMSVX1FD variables
.
.PMVXCSNR  DIM       1        1    1102  Consent release info (0=NO,1=YES)
.PMVXPOST  DIM       8        8    1103  Post Code
.PMVXPIND  DIM       3        3    1111  Privacy Indicator (Cat PV)
.PMVXVLOC  DIM      40       40    1114  Valuables Location
.PMVXCFSG  DIM       1        1    1154  Claim Form Signed (0=NO,1=YES)
.PMVXINGP  DIM       1        1    1155  Inform Registered GP
.                                         (0=NO,1=YES,2=Not Stated)
.PMVXCPTH  DIM       3        3    1156  Critical Pathway (Cat PW)
.PMVXHCP1  DIM       1        1    1159  Notify HCP1 (0=NO,1=YES)
.PMVXHCP2  DIM       1        1    1160  Notify HCP2 (0=NO,1=YES)
.PMVXHCP3  DIM       1        1    1161  Notify HCP3 (0=NO,1=YES)
.PMVXHCP4  DIM       1        1    1162  Notify HCP4 (0=NO,1=YES)
.PMVXRHC1  DIM      10       10    1163  Referring HCP 1 (pmshcpaf)
.PMVXRH1G  DIM      10       10    1173  Referring HCP 1 Practice (pmshclaf)
.PMVXRH1C  DIM       2        2    1183  Referring HCP 1 Grp Count (pmshcgaf
.PMVXRHC2  DIM      10       10    1185  Referring HCP 2 (pmshcpaf)
.PMVXRH2G  DIM      10       10    1195  Referring HCP 2 Practice (pmshclaf)
.PMVXRH2C  DIM       2        2    1205  Referring HCP 2 Grp Count (pmshcgaf
.PMVXRHC3  DIM      10       10    1207  Referring HCP 3 (pmshcpaf)
.PMVXRH3G  DIM      10       10    1217  Referring HCP 3 Practice (pmshclaf)
.PMVXRH3C  DIM       2        2    1227  Referring HCP 3 Grp Count (pmshcgaf
.PMVXRHC4  DIM      10       10    1229  Referring HCP 4 (pmshcpaf)
.PMVXRH4G  DIM      10       10    1239  Referring HCP 4 Practice (pmshclaf)
.PMVXRH4C  DIM       2        2    1249  Referring HCP 4 Grp Count (pmshclaf
.PMVXABRG  DIM       3        3    1251  Aboriginality (PRS/2) (Cat VA)
.PMVXCADM  DIM       3        3    1254  Admission Criterion (PRS/2) (Cat VB
.PMVXIRAD  DIM       3        3    1257  Intent to Readmit (PRS/2) (Cat VR)
.PMVXIDUS  DIM       3        3    1260  Intend Stay Duration (PRS/2) Cat VI
.PMVXCRAV  DIM       3        3    1263  Carer Availability (PRS/2) (Cat VK)
.PMVXRCCT  DIM       3        3    1266  Crit. Care Xfer Reason (PRS/2) (VJ)
.PMVXAPWD  DIM       3        3    1269  Admitting Point Ward (patwr1af)
.PMVXAPBD  DIM       3        3    1272  Admitting Point Bed (patwr1af)
.PMVXPOWD  DIM       3        3    1275  Post-Op Ward (patwr1af)
.PMVXPOBD  DIM       3        3    1278  Post-Op Bed (patwr1af)
.PMVXPSTY  DIM       1        1    1281  Parent Staying (0=NO,1=YES)
.PMVXVALW  DIM       1        1    1282  Visitor Allowed (0=NO,1=YES)
.PMVXPALW  DIM       1        1    1283  Phone Calls Allowed? (0=NO,1=YES)
.PMVXINDC  DIM       1        1    1284  Intended Day Case (0=NO,1=YES)
.PMVXMDAV  DIM       3        3    1285  Mode of Arrival (Cat VM)
.PMVXFRMS  DIM       3        3    1288  Forms (Cat VF)
.PMVXCSNG  DIM       3        3    1291  Coder Snags (Cat VN)
.PMVXPWGT  FORM      6        4    1294  Patient Weight(Convert to FORM 4.2)
.PMVXPHGT  FORM      6        4    1298  Patient Height
.PMVXDHWR  DIM       8        8    1302  Date Height/Weight Record. ccyymmdd
.PMVXEDC1  DIM      10       10    1310  Extra Doctor Code 1 (patdo1af)
.PMVXEDC2  DIM      10       10    1320  Extra Doctor Code 2 (patdo1af)
.PMVXEDC3  DIM      10       10    1330  Extra Doctor Code 3 (patdo1af)
.PMVXHOME  DIM       1        1    1340  Homeless Person (0=NO,1=YES)
.PMVXUDF1  DIM      50       50    1341  User Defined Free Format 1
.PMVXUDF2  DIM      50       50    1391  User Defined Free Format 2
.PMVXUDF3  DIM      50       50    1441  User Defined Free Format 3
.PMVXUDF4  DIM      50       50    1491  User Defined Free Format 4
.PMVXUDT1  DIM      13       13    1541  User Def. Date/Time 1 ccyymmddhh:mm
.PMVXUDT2  DIM      13       13    1554  User Def. Date/Time 2 ccyymmddhh:mm
.PMVXUDT3  DIM      13       13    1567  User Def. Date/Time 3 ccyymmddhh:mm
.PMVXUDT4  DIM      13       13    1580  User Def. Date/Time 4 ccyymmddhh:mm
.PMVXUDT5  DIM      13       13    1593  User Def. Date/Time 5 ccyymmddhh:mm
.PMVXUDT6  DIM      13       13    1606  User Def. Date/time 6 ccyymmddhh:mm
.PMVXCDTE  DIM      8        8     1619  Date record created (ccyymmdd)
.PMVXCTIM  DIM      8        8     1627  Time record created (hh:mm:ss)
.PMVXWEBC  DIM      10       10    1635  WEB User Id rec. creator (websecaf)
.PMVXLUPD  DIM      8        8     1645  Last Update Date (ccyymmdd)
.PMVXLUPT  DIM      8        8     1653  Last Update Time (hh:mm:ss)
.PMVXWEBU  DIM      10       10    1661  WEB User Id rec. update (websecaf)
.PMVXMHLS  DIM      3        3     1671  Mental Health Legal Status (LS)
.PMVXPICD  DIM      9        9     1674  Provisional ICD10 Code
.PMVXRMOR  DIM      3        3     1683  RMO Responsible Cat MO
.PMVXASUT  DIM      3        3     1686  Admission Service Unit Type Cat KA
.PMVXELPS  DIM      3        3     1689  Elective Patient Status Cat KC
.PMVXEMPL  DIM      3        3     1692  Employment Status Cat KD
.PMVXFINP  DIM      3        3     1695  Which Financial Program Cat KE
.PMVXOCCP  DIM      3        3     1698  Occupation Cat KF
.PMVXPALC  DIM      3        3     1701  Involvement in Palliat Care Cat KG
.PMVXPPAL  DIM      3        3     1704  Prev Non-Admitt Palliat Care Cat KH
.PMVXPPPT  DIM      3        3     1707  Public/Private Patients Cat KI
.PMVXPSOS  DIM      3        3     1710  Pension Status on Separation Cat KJ
.PMVXPYSP  DIM      3        3     1713  Payment Status on Separation Cat KK
.PMVXQLDB  DIM      3        3     1716  Banding/Type of Episode for QLDHDP
.PMVXREAD  DIM      3        3     1719  Re-Admission in 28 Days Cat KM
.PMVXUDIN  DIM      3        3     1722  Discharge Intention Cat KN
.PMVXUREA  DIM      3        3     1725  Unplanned Readmission Cat KO
.PMVXUSAC  DIM      3        3     1728  Usual Accommodation Cat KP
.PMVXUVTH  DIM      3        3     1731  Unplanned Visit to Theatre Cat KB
.PMVXINTR  DIM      1        1     1734  Interpreter Required? (0=NO,1=YES)
.PMVXLNG1  DIM      3        3     1735  Preferred Language 1 (Cat LA)
.PMVXASGC  DIM      9        9     1738  ABS AGSC
.PMVXMHOS  DIM      3        3     1747  Multi Hospital ID (pathspaf)
.PMVXDSPD  DIM      8        8     1750  Disch Summary Produced (ccyymmdd)
.PMVXDSIF  DIM      1        1     1758  Disch Summary (I)nterim / (F)inal
.PMVXPRMI  DIM      1        1     1759  Participate/Receive Marketing Info
.PMVXPRAI  DIM      1        1     1760  Participate/Receive Advertising Inf
.PMVXPRES  DIM      1        1     1761  Participate in Research Projects
.PMVXUITR  DIM      1        1     1762  Use Information for Training
.PMVXRPOA  DIM      1        1     1763  Release to Enduring POA / IFC
.PMVXRCN1  DIM      1        1     1764  Release to Contact 1 ptmxnrnm
.PMVXRCN2  DIM      1        1     1765  Release to Contact 2 ptmxexnm
.PMVXRHFU  DIM      1        1     1766  Release to Health Fund
.PMVXRDVA  DIM      1        1     1767  Release to DVA
.PMVXRSLO  DIM      1        1     1768  RSL Visit OK
.PMVXMLOC  DIM      3        3     1769  Medical Record Location (Cat MV)
.PMVXPACC  DIM      3        3     1772  Preferred Accommodation (Cat BP)
.PMVXEDU1  DIM      3        3     1775  Extra Doctor Unit 1 (Cat AC)
.PMVXEDU2  DIM      3        3     1778  Extra Doctor Unit 2 (Cat AC)
.PMVXEDU3  DIM      3        3     1781  Extra Doctor Unit 3 (Cat AC)
.PMVXPRGM  DIM      8        8     1784  Program Code
.PMVXCONF  DIM      1        1     1792  Appointment Confirmed 0=No 1=Yes
.PMVXEOCL  DIM      8        8     1793  EOC Link admission no.
.PMVXSLOC  DIM      3        3     1801  Location SOR (Cat SG)
.PMVXSCLI  DIM      3        3     1804  Clinical SOR (Cat SH)
.PMVXSTRA  DIM      3        3     1807  Transport SOR (Cat.SI)
.PMVXQASN  DIM      12       12    1810  QAS Number
.PMVXATCP  DIM      1        1     1822  All theatre charges posted (1=yes)
.PMVXATIM  DIM      8        8     1823  Arrival Time (hh:mm:ss)
.PMVXITIM  DIM      8        8     1831  Interview Time (hh:mm:ss)
.PMVXHFGN  DIM      40       40    1839  Health Fund First Given Name Alias
.PMVXHFSN  DIM      40       40    1879  Health Fund Surname Alias
.PMVXFUPI  DIM      2        2     1919  Health Fund UPI
.PMVXPOEC  DIM      1        1     1921  Patient Online Eligibility Consent
.PMVXPGID  DIM      3        3     1922  Program Identifier (Cat PK)
.PMVXTICM  DIM      3        3     1925  Reason Theatre Incomplete Catg Rt
.PMVXPILC  DIM      3        3     1928  Presenting Illness Code CAT (il)
.PMVXFVIO  DIM      3        3     1931  Family Violence (Cat fv)
.PMVXFNDM  DIM      19       19    1934  Health Fund Membership Number
.PMVXUDF5  DIM      3        3     1953  User defined Category Code
.PMVXUDF6  DIM      3        3     1956  User defined Category Code
.PMVXUDF7  DIM      3        3     1959  User defined Category Code
.PMVXUDF8  DIM      3        3     1962  User defined Category Code
.PMVXUDF9  DIM      3        3     1965  User defined Category Code
.PMVXUD10  DIM      3        3     1968  User defined Category Code
.PMVXUD11  DIM      3        3     1971  User defined Category Code
.PMVXUD12  DIM      3        3     1974  User defined Category Code
.PMVXUD13  DIM      3        3     1977  User defined Category Code
.PMVXUD14  DIM      3        3     1980  User defined Category Code
.PMVXUD15  DIM      3        3     1983  User defined Category Code
.PMVXTEAM  DIM      5        5     1986  Team
.PMVXNWHC  DIM      3        3     1991  Non WA Hospital Contact (Cat cw)
.PMVXEDDT  DIM      8        8     1994  Expected Delivery Date (ccyymmdd)
.PMVXPHLD  DIM      3        3     2002  Property Held (Cat ps)
.PMVXPLOC  DIM      3        3     2005  Property Location (Cat pt)
.PMVXDTRT  DIM      8        8     2008  Date Returned (ccyymmdd)
.PMVXDFLG  DIM      9        9     2016  Disaster Flag
.PMVXFSRC  DIM      3        3     2025  Funding Source (Cat cx)
.PMVXCONM  DIM      40       40    2028  Contributor Name
.PMVXCPDD  DIM       8       8     2068  Care Plan Documented Date
.PMVXPBMI  DIM       5       5     2076  Patient Body Mass Index
.
.          PATDSCFD variables
.
.DDATE     DIM       8        8    2081   PATIENT DIS. DATE (CCYYMMDD)
.DTIME     DIM       8        8    2089   PATIENT DISCHARGE TIME
.DSTAT     DIM       3        3    2097   DISCHARGE STATUS      (CAT D )
.DDEST     DIM       3        3    2100   DISCHARGE DESTINATION (CAT DD)
.DDIAG     DIM      50       50    2103   DISCHARGE DIAGNOSIS
.DDIAG2    DIM      50       50    2153   DISCHARGE DIAGNOSIS (PART 2)
.DUSD1     DIM       3        3    2203   USER DEFINED FIELD 1 (CAT D1)
.DUSD2     DIM       3        3    2206   USER DEFINED FIELD 2 (CAT D2)
.DUSD3     DIM       3        3    2209   USER DEFINED FIELD 3 (CAT D3)
.DUSD4     DIM       3        3    2212   USER DEFINED FIELD 4 (CAT D4)
.DUSD5     DIM       3        3    2215   USER DEFINED FIELD 5 (CAT D5)
.DFMBS     DIM       9        9    2218   DISCHARGE DIAGNOSIS CODE
.PTDSDMDC  DIM       4        4    2227   MDC code
.PTDSDDRG  DIM       4        4    2231   DRG code
.DWLREASN  DIM       3        3    2235   Reason Discharged Patient was
.                                                put back on Waiting List (RW)
.PTDSSIDX  DIM       1        1    2238   DRG severity index
.PTDSVOGU  DIM       3        3    2239   Vers grouper used when grouping
.PTDSOPER  DIM       4        4    2242   Operator who discharged patie
.PTDSUYN1  FORM      1        2    2246   User Defined Y/N Field 1
.PTDSUYN2  FORM      1        2    2248   User Defined Y/N Field 2
.PTDSUYN3  FORM      1        2    2250   User Defined Y/N Field 3
.PTDSUYN4  FORM      1        2    2252   User Defined Y/N Field 4
.PTDSDWRD  DIM       3        3    2254   Discharge Ward
.PTDSDLOS  FORM      4        3    2257   Length of Stay     
.PTDSSREF  DIM       4        4    2260   Separation referral
.PTDSPALD  DIM       3        3    2264   Palliative care days (PRS2)
.PTDSDPMN  DIM       3        3    2267   Departure Means (Cat SI)
.
.          MEHLERFD variables
.
.MHLRCODE  DIM       3        3    2270  Leave end reason code (CAT LE)
.
.          PATRE1FD variables
.
.PKNAME    DIM      80       80    2273   PERSON RESP FOR A/C NAME
.PKADD1    DIM      35       35    2353   P.R.A ADDRESS LINE 1
.PKADD2    DIM      35       35    2388   P.R.A ADDRESS LINE 2
.PKSUBR    DIM      35       35    2423   P.R.A SUBURB
.PKADD4    DIM      35       35    2458   P.R.A ADDRESS LINE 2
.PKPOST    DIM       8        8    2493   P.R.A POSTCODE
.PKTELEP   DIM      20       20    2501   P.R.A PRIVATE TELEPHONE
.PKTELEB   DIM      20       20    2521   P.R.A BUSINESS TELEPHONE
.PKRELP    DIM      10       10    2541   P.R.A RELATIONSHIP
.PTREMOBL  DIM      20       20    2551   P.R.A MOBILE TELEPHONE
.PTRESNAM  DIM      40       40    2571   Surname or
.                                             Contact Name for Insurance
.PTREGNAM  DIM      40       40    2611   Given Name
.
.          Other variables
.
.WSTBY     DIM      8        8     2651   Standby Number
PMQVTDAT   DIM      8        8     2659   Transfer Date (for cancelled transfer)
.                                                       (ccyymmdd)
PMQVTTIM   DIM      8        8     2667   Transfer Date (for cancelled transfer)
.                                                       (hh:mm:ss)
.
.OERDATE   DIM      8        8     2675   Expected Return Date (ccyymmdd)
.OERTIME   DIM      8        8     2683   Expected Return Time (hh:mm:ss)
.
.PMBRREQD  DIM      8        8     2691   Request Date (ccyymmdd)
.PMBRREQT  DIM      8        8     2699   Request Time (hh:mm:ss)
.PMVXCNID  DIM      10      10     2707   Visit Confirmed WEB User Id
.                                         (websecaf)
.PMVXCNDT  DIM      13      13     2717   Visit Confirmed Date and Time
.                                         (ccyymmddhh:mm)
.PMVXCASE  DIM      10      10     2730   Case Team (allcasaf)
.PMVXEAFL  DIM      1        1     2740   Eclipse Adjustment Flag
.                                         Blank or 0 = No
.                                         1 = Yes
.PTDSLSDN  DIM      8        8     2741   Linked Statistical Discharge No
.PTDSCLGP  DIM     12       12     2749   Clinical Group
PMQVSPAR   DIM     28       28     2761   Spare Variable
.
.End of Record                    2789
.
.
. Redefined FORM fields from key
. ------------------------------
PMQVMESI  FORM      20
PMQVTRAN  FORM      2
