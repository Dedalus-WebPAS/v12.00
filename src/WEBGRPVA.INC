.******************************************************************************
.*                                                                            *
.* Include Name     : WEBGRPVA.INC (was VAR41GRP.INC)                         *
.*                                                                            *
.* Description      : Common variables for WEBGROUP.PBL (was PAT41GRP)        *
.*                                                                            *
.* Author           : Davin Sloan  13/10/1999                                 *
.*                                                                            *
.* Modifications    :                                                         *
.******************************************************************************
.*        V12.00.01 29/05/2025  Ebon Clements    TSK 0950532                  *
.*                  Added VALDDCID - Validate DCID                            *
.*        V11.05.03 22/04/2025  Ebon Clements    TSK 0950532                  *
.*                  Added cluster id fields to CGS unix grouper input         *
.*                  and output file layouts - XDRGDI01 to XDRDI100            *
.*        V11.05.02 17/04/2025  Ebon Clements    TSK 0950532                  *
.*                  Added TurboGrouper vars XTRB0148 to XTRB0155              *
.*                  Added XTRB154A, DIAGDCID to LOADFILE                      *
.*        V11.05.01 27/03/2025  Davin            TSK 0956210                  *
.*                  Added DOUT120, DRG120FN & DRG120 for DRG Version 12.0     *
.*        V11.04.03 05/09/2024  Davin            TSK 0922271                  *
.*                  Added vars to cater for 100 Diag/Op codes (3mcgs grouper) *
.*        V11.04.02 14/06/2024  Davin            TSK 0937495                  *
.*                  Added XDRGCF01 - XDRGCF40 (DCL values if grouper >= v11.0)*
.*        V11.04.01 23/01/2024  Davin            TSK 0928468                  *
.*                  Added AMHCC Grouper input/output files and variables      *
.*        V11.02.02 14/06/2022  Ebon Clements    TSK 0906596                  *
.*                  Added TurboGrouper vars XTRB0120 to XTRB0147              *
.*                  Added XDRGCHSC                                            *
.*        V11.02.01 11/02/2022  Ebon Clements    TSK 0915238                  *
.*                  Activated XTRB104X to export operation end dates and times*
.*        V11.01.08 19/11/2021  Ebon Clements    TSK 0911383                  *
.*                  Added condition onset vars XDRGDC01 to XDRGDC50 for NWAU  *
.*                  unix grouper                                              *
.*        V11.01.07 17/11/2021  Ebon Clements    TSK 0911414                  *
.*                  Changed XTRB0022 - TG post code to a DIM 4                *
.*                  Changed XTRB0034 - TG Psychiatric Care Days to a DIM 5    *
.*                  Changed XTRB0035 - TG Qualified Days for Newborns to a    *
.*                  DIM 5                                                     *
.*        V11.01.06 05/08/2021  Ebon Clements    TSK 0909694                  *
.*                  Added XDRGCCTY - NWAU Care type - Codefinder input        *
.*        V11.01.05 04/08/2021  Ebon Clements    TSK 0909442                  *
.*                  Added XDRGATYP - Admit Type - NZ - Codefinder input       *
.*        V11.01.04 29/06/2021  Ebon Clements    TSK 0902615                  *
.*                  Changed OUTFILE2 length to 327                            *
.*        V11.01.03 22/06/2021  Ebon Clements    TSK 0907810                  *
.*                  Added CONTCARF - Contract care flag to LOADFILE           *
.*        V11.01.02 18/06/2021  Ebon Clements    TSK 0902615                  *
.*                  Added UNIXNWAU - Unix grouper export and import NWAU      *
.*                  fields                                                    *
.*        V11.01.01 05/05/2021  Ebon Clements    TSK 0902615                  *
.*                  Changed sized of TurboGrouper var XTRB0024 and XTRB0090   *
.*        V11.00.04 16/11/2020  Ebon Clements    TSK 0892694                  *
.*                  Added TurboGrouper vars XTRB0115 to XTRB0119              *
.*        V11.00.03 08/07/2020  Ebon Clements    TSK 0894249                  *
.*                  Added TURBODRG                                            *
.*        V11.00.02 15/05/2020  Ebon Clements    TSK 0891590                  *
.*                  Changed TurboGrouper XTRB0053 DRG version to a dim 4 to   *
.*                  load DRG version 6.2 from 6.0x                            *
.*        V11.00.01 31/03/2020  Jill Parkinson Task 0890087                   *
.*                  Increased DATA150B and CODELINE to allow up to 250 chars  *
.*        V10.15.01 09/10/2019  Ebon Clements    TSK 0877429                  *
.*                  Added TURBFTIM - TurboGrouper import/export file time     *
.*        V10.14.09 03/10/2019  Thanh T          TSK 0882260                  *
.*                  Added DOUT110, DRG110FN & DRG110 for DRG Version 11.0     *
.*        V10.14.08 30/09/2019  Ebon Clements    TSK 0877430                  *
.*                  Added TurboGrouper fields XTRB0106 to XTRB114X            *
.*        V10.14.07 30/09/2019  Ebon Clements    TSK 0877428                  *
.*                  Changed TurboGrouper campus code XTRB0007 to a DIM 4      *
.*        V10.14.06 04/06/2019  Ebon Clements    TSK 0875790                  *
.*                  Added TurboGrouper operation prefix - XTRB105X            *
.*        V10.14.05 31/05/2019  Ebon Clements    TSK 0875696                  *
.*                  Added TurboGrouper save of original principal             *
.*                  diagnosis code and coder id - XTRB45SV, XTRB45CI          *
.*        V10.14.04 30/04/2019  Ebon Clements    TSK 0873995                  *
.*                  Added TURBOSAV - Retain previous details                  *
.*        V10.14.03 27/03/2019  Ebon Clements    TSK 0872200                  *
.*                  Changed TurboGrouper XTRB0030 leave days to DIM 4         *
.*        V10.14.02 04/03/2019  Ebon Clements    TSK 0870711                  *
.*                  Added TurboGrouper retain operation time vars             *
.*                  27/02/2019  Richa Phogat     TSK 0870439                  *
.*                  Added DOUT100, DRG100FN & DRG100 for DRG Version 10.0     *
.*        V10.14.01 26/02/2019  Ebon Clements    TSK 0870711                  *
.*                  Changed TurboGrouper to accept 200 diagnosis/procedure    *
.*                  codes                                                     *
.******************************************************************************
.*        V10.12.02 04/05/2018  Ebon Clements    TSK 0845772                  *
.*                  New fields for TurboGrouper                               *
.*        V10.12.01 22/03/2018  Tracey Nguyen    TSK 0852793                  *
.*                  Added DOUT90, DRGO90FN & DRG090 for DRG Version 9.0       *
.*        V10.08.05 21/09/2016  Davin            TSK 0307316                  *
.*                  Added WEBCODER for web Interface to 3M Codefinder         *
.*        V10.08.04 26/08/2016  Don Nguyen       TSK 0312570                  *
.*                  Added CFPAYCOD used by WEBGROUP (GETDRG / GTEDRG00)       *
.*        V10.08.03 18/07/2016  Davin            TSK 0822753                  *
.*                  Changed ADNODAYS and EPSNOLOS to FORM4 (same as NBRDAYS)  *
.*        V10.08.02 27/04/2016  Don Nguyen       TSK 0815007                  *
.*                  Moved XDRGECRW to relevant file positions                 *
.*        V10.08.01 12/04/2016  Don Nguyen       TSK 0815007                  *
.*                  Added XDRGECRW - ECCS Raw Format                          *
.*        V10.06.02 30/07/2015  Don Nguyen       CAR 318792                   *
.*                  Changed ICDCDESC to be 200 chars for (PTEDDESC & PTEODESC)*
.*        V10.06.01 29/05/2015  Ebon Clements    CAR 317094                   *
.*                  Added DOUT80, DRGO80FN & DRG080 for DRG Ver 8.0           *
.*                  Changed OPENFLG from FORM 1 to FORM 2                     *
.*        V10.04.02 03/07/2014  Ebon Clements    CAR 302036                   *
.*                  Added XDRGURGA - DRG Urgency of Admission                 *
.*        V10.04.01 13/03/2014  Don Nguyen       CAR 294888                   *
.*                  Added SYSTGVAL                                            *
.*        V10.03.06 14/10/2013  Don Nguyen       CAR 282453                   *
.*                  Added var DACCDATE                                        *
.*        V10.03.05 26/09/2013  Ania P           CAR 292081                   *
.*                  Added var AUTHFLAG                                        *
.*        V10.03.04 03/05/2013  Davin            CAR 284669 HDP 2013 DRG 7.0  *
.*                  Added DOUT70, DRGO70FN & DRG070 for DRG Ver 7.0           *
.*        V10.03.03 01/10/2012  Mike Laming      CAR 271756                   *
.*                  October Codefinder changes - added Codefinder vars and    *
.*                  NZ Wies Tags USENZWIS NZTOTWIS & FORM84                   *
.*        V10.03.02 26/06/2012  Mike Laming      CAR 267797 HDP 2012 DRG 6.2  *
.*                  Added DOUT62, DRGO62FD & DRG062 for DRG Ver 6.2           *
.*        V10.03.01 05/06/2012  Mike Laming      CAR 266421                   *
.*                  Added GRPSWICH to switch CPDATS00 in SETGRP00, also added *
.*                  SETCLACC, variables for CPDATS00 (now in WEBGROUP)        *
.*        V10.02.04 29/09/2011  Mike Laming      CAR 249011                   *
.*                  Added WAHEALTH to allow bypassing Oper.Date processing    *
.*        V10.02.03 26/09/2011  Mike Laming      CAR 241939                   *
.*                  Added ENCDTYPE (CodeFinder returned Disease Prefix)       *
.*        V10.02.02 07/09/2011  Mike Laming      CAR 241939                   *
.*                  Added ENCSTDAT & ENCENDAT (replaces ADATE & DDATE for     *
.*                  Codefinder upload Tags "ADT:" & "DDT:"                    *
.*        V10.02.01 24/08/2011  Mike Laming      CAR 249284 & 249210          *
.*                  Added DRGIND for "DRG Driver in use" indicator (for ARE:) *
.*                  Added CCCLASS for "CC Class Level" indicator (for ARCL:)  *
.*        V9.12.01  19/06/2009  Mike Laming      CAR 197814 HDP 2009 DRG 6.0  *
.*                  Moved all variables DRGOnnFN & DRG0nn to here             *
.*                  Added DOUT60, DRGO60FD & DRG060 for DRG Ver 6.0           *
.*        V9.11.01  03/03/2009  Mike Laming      CAR 190769 plus              *
.*                  Changes for new Tags in '09 Codefinder  and PAT41GRP mods *
.* ****************************************************************************
.*        V9.08.01  12/04/2007  Mike Laming      CAR 137125 HDP 2007 DRG 5.2  *
.*                  Added DOUT52 for DRG Ver 5.2                              *
.*        V9.04.01  23/05/2005  Mike Laming   CAR 61562                       *
.*                  July 2005 mods for DRG 5.1 - Add DOUT51                   *
.*        V9.03.02  30/07/2004  Henry Son        CAR 51504                    *
.*                  CME changes put in with WIES12.                           *
.*        V9.03.01  27/05/2004  Henry Son        CAR 50344                    *
.*                  Group using 3M CME                                        *
.*                  Change format of UNIX Quickgroup input and output files.  *
.*        V9.02.01  08/11/2001  Davin                                         *
.*                  Added OPENFLG - determine which grouper out file to open  *
.*                  08/11/2001  Pat Dirito                                    *
.*                  Added File Variables for Unix Grouper                     *
.*        V5.08.01  27/06/2000  Greg Horvat                                   *
.*                  Added INPFIL41 - 4.1 grouper input file                   *
.*        V5.07.02  14/01/2000  Greg Horvat                                   *
.*                  Changed the ICD9 input file procedure variables to be 4   *
.*                  characters & added FILRFGRP                               *
.*        V5.07.01  06/12/1999  Greg Horvat                                   *
.*                  Added RUNGRP - Run grouper on this machine flag           *
.*                                                                            *
.******************************************************************************
.
INPFIL41  FILE      ASCII, FIXED=319        * ICD10 grouper file
.
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
XDRGADMN  DIM       8       1   Admission number
XDRGADAT  DIM      10       9   Admission date (dd/mm/ccyy)
XDRGATIM  DIM       2      19   Admission time (hh)
XDRGDDAT  DIM      10      21   Discharge date (dd/mm/ccyy)
XDRGDTIM  DIM       2      31   Discharge time (hh)
XDRGBDAT  DIM      10      33   Birth date (dd/mm/ccyy)
XDRGAGEY  DIM       3      43   Age in years (if > 364 days)
XDRGAGED  DIM       3      46   Age in days (if <= 364 days)
XDRGSEX   DIM       1      49   Sex
XDRGSEP   DIM       2      50   Separation mode
XDRGAWHT  DIM       4      52   Admission weight
XDRGILOS  DIM       1      56   Intended los
.                                 0 = not entered
.                                 1 = same day
.                                 2 = overnight
XDRGSDAY  DIM       1      57   Same day (0 = not sameday, 1 = sameday)
XDRGMHLS  DIM       1      58   Mental health legal status
XDRGHMV   DIM       4      59   Hours on mechanical ventiliation
XDRGALOS  DIM       4      63   Acute los
XDRGDS01  DIM       5      67   diagnosis 1
XDRGDS02  DIM       5      72   diagnosis 2
XDRGDS03  DIM       5      77   diagnosis 3
XDRGDS04  DIM       5      82   diagnosis 4
XDRGDS05  DIM       5      87   diagnosis 5
XDRGDS06  DIM       5      92   diagnosis 6
XDRGDS07  DIM       5      97   diagnosis 7
XDRGDS08  DIM       5     102   diagnosis 8
XDRGDS09  DIM       5     107   diagnosis 9
XDRGDS10  DIM       5     112   diagnosis 10
XDRGDS11  DIM       5     117   diagnosis 11
XDRGDS12  DIM       5     122   diagnosis 12
XDRGDS13  DIM       5     127   diagnosis 13
XDRGDS14  DIM       5     132   diagnosis 14
XDRGDS15  DIM       5     137   diagnosis 15
XDRGDS16  DIM       5     142   diagnosis 16
XDRGDS17  DIM       5     147   diagnosis 17
XDRGDS18  DIM       5     152   diagnosis 18
XDRGDS19  DIM       5     157   diagnosis 19
XDRGDS20  DIM       5     162   diagnosis 20
XDRGDS21  DIM       5     167   diagnosis 21
XDRGOP01  DIM       7     172   operation code 1
XDRGOP02  DIM       7     179   operation code 2
XDRGOP03  DIM       7     186   operation code 3
XDRGOP04  DIM       7     193   operation code 4
XDRGOP05  DIM       7     200   operation code 5
XDRGOP06  DIM       7     207   operation code 6
XDRGOP07  DIM       7     214   operation code 7
XDRGOP08  DIM       7     221   operation code 8
XDRGOP09  DIM       7     228   operation code 9
XDRGOP10  DIM       7     235   operation code 10
XDRGOP11  DIM       7     242   operation code 11
XDRGOP12  DIM       7     249   operation code 12
XDRGOP13  DIM       7     256   operation code 13
XDRGOP14  DIM       7     263   operation code 14
XDRGOP15  DIM       7     270   operation code 15
XDRGOP16  DIM       7     277   operation code 16
XDRGOP17  DIM       7     284   operation code 17
XDRGOP18  DIM       7     291   operation code 18
XDRGOP19  DIM       7     298   operation code 19
XDRGOP20  DIM       7     305   operation code 20
XDRGOP21  DIM       7     312   operation code 21
.
.End of Record            319
.
.************************************************************************
.                  Unix Grouper File Variables
.************************************************************************
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
XDRGSTAT  DIM       1       1   State Code
XDRGHOSP  DIM      10       2   Hospital ID
XDRGMEDN  DIM      13      12   Medical Record Number(Admission Number)
XDRGHTYP  DIM       1      25   Hospital Type
.XDRGADAT  DIM      10      26   Admission date (dd/mm/ccyy)
.XDRGDDAT  DIM      10      36   Seperation(Discharge) date (dd/mm/ccyy)
.XDRGSEP   DIM       2      46   Separation mode
.XDRGBDAT  DIM      10      48   Birth date (dd/mm/ccyy)
.XDRGAWHT  DIM       4      58   Admission weight
.XDRGAGEY  DIM       3      62   Age in years (if > 364 days)
.XDRGAGED  DIM       3      65   Age in days (if <= 364 days)
.XDRGSEX   DIM       1      68   Sex
.XDRGHMV   DIM       4      69   Hours on mechanical ventiliation
.XDRGDS01  DIM       5      73   Principle Diagnosis 1
.XDRGDS02  DIM       5      78   diagnosis 2
.XDRGDS03  DIM       5      83   diagnosis 3
.XDRGDS04  DIM       5      88   diagnosis 4
.XDRGDS05  DIM       5      93   diagnosis 5
.XDRGDS06  DIM       5      98   diagnosis 6
.XDRGDS07  DIM       5     103   diagnosis 7
.XDRGDS08  DIM       5     108   diagnosis 8
.XDRGDS09  DIM       5     113   diagnosis 9
.XDRGDS10  DIM       5     118   diagnosis 10
.XDRGDS11  DIM       5     123   diagnosis 11
.XDRGDS12  DIM       5     128   diagnosis 12
.XDRGDS13  DIM       5     133   diagnosis 13
.XDRGDS14  DIM       5     138   diagnosis 14
.XDRGDS15  DIM       5     143   diagnosis 15
.XDRGDS16  DIM       5     148   diagnosis 16
.XDRGDS17  DIM       5     153   diagnosis 17
.XDRGDS18  DIM       5     158   diagnosis 18
.XDRGDS19  DIM       5     163   diagnosis 19
.XDRGDS20  DIM       5     168   diagnosis 20
.XDRGDS21  DIM       5     173   diagnosis 21
XDRGDS22   DIM       5     178   diagnosis 22                          
XDRGDS23   DIM       5     183   diagnosis 23                          
XDRGDS24   DIM       5     188   diagnosis 24                          
XDRGDS25   DIM       5     193   diagnosis 25                          
XDRGDS26   DIM       5     198   diagnosis 26                          
XDRGDS27   DIM       5     203   diagnosis 27                          
XDRGDS28   DIM       5     208   diagnosis 28                          
XDRGDS29   DIM       5     213   diagnosis 29                          
XDRGDS30   DIM       5     218   diagnosis 30                          
XDRGDS31   DIM       5     223   diagnosis 31                          
XDRGDS32   DIM       5     228   diagnosis 32                          
XDRGDS33   DIM       5     233   diagnosis 33                          
XDRGDS34   DIM       5     238   diagnosis 34                          
XDRGDS35   DIM       5     243   diagnosis 35                          
XDRGDS36   DIM       5     248   diagnosis 36                          
XDRGDS37   DIM       5     253   diagnosis 37                          
XDRGDS38   DIM       5     258   diagnosis 38                          
XDRGDS39   DIM       5     263   diagnosis 39                          
XDRGDS40   DIM       5     268   diagnosis 40                          
XDRGDS41   DIM       5     273   diagnosis 41                          
XDRGDS42   DIM       5     278   diagnosis 42                          
XDRGDS43   DIM       5     283   diagnosis 43                          
XDRGDS44   DIM       5     288   diagnosis 44                          
XDRGDS45   DIM       5     293   diagnosis 45                          
XDRGDS46   DIM       5     298   diagnosis 46                          
XDRGDS47   DIM       5     303   diagnosis 47                          
XDRGDS48   DIM       5     308   diagnosis 48                          
XDRGDS49   DIM       5     313   diagnosis 49                          
XDRGDS50   DIM       5     318   diagnosis 50                          
XDRGDS51   DIM       5     323   diagnosis 51
XDRGDS52   DIM       5     328   diagnosis 52
XDRGDS53   DIM       5     333   diagnosis 53
XDRGDS54   DIM       5     338   diagnosis 54
XDRGDS55   DIM       5     343   diagnosis 55
XDRGDS56   DIM       5     348   diagnosis 56
XDRGDS57   DIM       5     353   diagnosis 57
XDRGDS58   DIM       5     358   diagnosis 58
XDRGDS59   DIM       5     363   diagnosis 59
XDRGDS60   DIM       5     368   diagnosis 60
XDRGDS61   DIM       5     373   diagnosis 61
XDRGDS62   DIM       5     378   diagnosis 62
XDRGDS63   DIM       5     383   diagnosis 63
XDRGDS64   DIM       5     388   diagnosis 64
XDRGDS65   DIM       5     393   diagnosis 65
XDRGDS66   DIM       5     398   diagnosis 66
XDRGDS67   DIM       5     403   diagnosis 67
XDRGDS68   DIM       5     408   diagnosis 68
XDRGDS69   DIM       5     413   diagnosis 69
XDRGDS70   DIM       5     418   diagnosis 70
XDRGDS71   DIM       5     423   diagnosis 71
XDRGDS72   DIM       5     428   diagnosis 72
XDRGDS73   DIM       5     433   diagnosis 73
XDRGDS74   DIM       5     438   diagnosis 74
XDRGDS75   DIM       5     443   diagnosis 75
XDRGDS76   DIM       5     448   diagnosis 76
XDRGDS77   DIM       5     453   diagnosis 77
XDRGDS78   DIM       5     458   diagnosis 78
XDRGDS79   DIM       5     463   diagnosis 79
XDRGDS80   DIM       5     468   diagnosis 80
XDRGDS81   DIM       5     473   diagnosis 81
XDRGDS82   DIM       5     478   diagnosis 82
XDRGDS83   DIM       5     483   diagnosis 83
XDRGDS84   DIM       5     488   diagnosis 84
XDRGDS85   DIM       5     493   diagnosis 85
XDRGDS86   DIM       5     498   diagnosis 86
XDRGDS87   DIM       5     503   diagnosis 87
XDRGDS88   DIM       5     508   diagnosis 88
XDRGDS89   DIM       5     513   diagnosis 89
XDRGDS90   DIM       5     518   diagnosis 90
XDRGDS91   DIM       5     523   diagnosis 91
XDRGDS92   DIM       5     528   diagnosis 92
XDRGDS93   DIM       5     533   diagnosis 93
XDRGDS94   DIM       5     538   diagnosis 94
XDRGDS95   DIM       5     543   diagnosis 95
XDRGDS96   DIM       5     548   diagnosis 96
XDRGDS97   DIM       5     553   diagnosis 97
XDRGDS98   DIM       5     558   diagnosis 98
XDRGDS99   DIM       5     563   diagnosis 99
XDRDS100   DIM       5     568   diagnosis 100
.XDRGOP01  DIM       7     573   operation code 1
.XDRGOP02  DIM       7     580   operation code 2
.XDRGOP03  DIM       7     587   operation code 3
.XDRGOP04  DIM       7     594   operation code 4
.XDRGOP05  DIM       7     601   operation code 5
.XDRGOP06  DIM       7     608   operation code 6
.XDRGOP07  DIM       7     615   operation code 7
.XDRGOP08  DIM       7     622   operation code 8
.XDRGOP09  DIM       7     629   operation code 9
.XDRGOP10  DIM       7     636   operation code 10
.XDRGOP11  DIM       7     643   operation code 11
.XDRGOP12  DIM       7     650   operation code 12
.XDRGOP13  DIM       7     657   operation code 13
.XDRGOP14  DIM       7     664   operation code 14
.XDRGOP15  DIM       7     671   operation code 15
.XDRGOP16  DIM       7     678   operation code 16
.XDRGOP17  DIM       7     685   operation code 17
.XDRGOP18  DIM       7     692   operation code 18
.XDRGOP19  DIM       7     699   operation code 19
.XDRGOP20  DIM       7     706   operation code 20
.XDRGOP21  DIM       7     713   operation code 21                     
XDRGOP22   DIM       7     720   operation code 22                     
XDRGOP23   DIM       7     727   operation code 23                     
XDRGOP24   DIM       7     734   operation code 24                     
XDRGOP25   DIM       7     741   operation code 25                     
XDRGOP26   DIM       7     748   operation code 26                     
XDRGOP27   DIM       7     755   operation code 27                     
XDRGOP28   DIM       7     762   operation code 28                     
XDRGOP29   DIM       7     769   operation code 29                     
XDRGOP30   DIM       7     776   operation code 30                     
XDRGOP31   DIM       7     783   operation code 31                     
XDRGOP32   DIM       7     790   operation code 32                     
XDRGOP33   DIM       7     797   operation code 33                     
XDRGOP34   DIM       7     804   operation code 34                     
XDRGOP35   DIM       7     811   operation code 35                     
XDRGOP36   DIM       7     818   operation code 36                     
XDRGOP37   DIM       7     825   operation code 37                     
XDRGOP38   DIM       7     832   operation code 38                     
XDRGOP39   DIM       7     839   operation code 39                     
XDRGOP40   DIM       7     846   operation code 40                     
XDRGOP41   DIM       7     853   operation code 41                     
XDRGOP42   DIM       7     860   operation code 42                     
XDRGOP43   DIM       7     867   operation code 43                     
XDRGOP44   DIM       7     874   operation code 44                     
XDRGOP45   DIM       7     881   operation code 45                     
XDRGOP46   DIM       7     888   operation code 46                     
XDRGOP47   DIM       7     895   operation code 47                     
XDRGOP48   DIM       7     902   operation code 48                     
XDRGOP49   DIM       7     909   operation code 49                     
XDRGOP50   DIM       7     916   operation code 50                     
XDRGOP51   DIM       7     923   operation code 51
XDRGOP52   DIM       7     930   operation code 52
XDRGOP53   DIM       7     937   operation code 53
XDRGOP54   DIM       7     944   operation code 54
XDRGOP55   DIM       7     951   operation code 55
XDRGOP56   DIM       7     958   operation code 56
XDRGOP57   DIM       7     965   operation code 57
XDRGOP58   DIM       7     972   operation code 58
XDRGOP59   DIM       7     979   operation code 59
XDRGOP60   DIM       7     986   operation code 60
XDRGOP61   DIM       7     993   operation code 61
XDRGOP62   DIM       7    1000   operation code 62
XDRGOP63   DIM       7    1007   operation code 63
XDRGOP64   DIM       7    1014   operation code 64
XDRGOP65   DIM       7    1021   operation code 65
XDRGOP66   DIM       7    1028   operation code 66
XDRGOP67   DIM       7    1035   operation code 67
XDRGOP68   DIM       7    1042   operation code 68
XDRGOP69   DIM       7    1049   operation code 69
XDRGOP70   DIM       7    1056   operation code 70
XDRGOP71   DIM       7    1063   operation code 71
XDRGOP72   DIM       7    1070   operation code 72
XDRGOP73   DIM       7    1077   operation code 73
XDRGOP74   DIM       7    1084   operation code 74
XDRGOP75   DIM       7    1091   operation code 75
XDRGOP76   DIM       7    1098   operation code 76
XDRGOP77   DIM       7    1105   operation code 77
XDRGOP78   DIM       7    1112   operation code 78
XDRGOP79   DIM       7    1119   operation code 79
XDRGOP80   DIM       7    1126   operation code 80
XDRGOP81   DIM       7    1133   operation code 81
XDRGOP82   DIM       7    1140   operation code 82
XDRGOP83   DIM       7    1147   operation code 83
XDRGOP84   DIM       7    1154   operation code 84
XDRGOP85   DIM       7    1161   operation code 85
XDRGOP86   DIM       7    1168   operation code 86
XDRGOP87   DIM       7    1175   operation code 87
XDRGOP88   DIM       7    1182   operation code 88
XDRGOP89   DIM       7    1189   operation code 89
XDRGOP90   DIM       7    1196   operation code 90
XDRGOP91   DIM       7    1203   operation code 91
XDRGOP92   DIM       7    1210   operation code 92
XDRGOP93   DIM       7    1217   operation code 93
XDRGOP94   DIM       7    1224   operation code 94
XDRGOP95   DIM       7    1231   operation code 95
XDRGOP96   DIM       7    1238   operation code 96
XDRGOP97   DIM       7    1245   operation code 97
XDRGOP98   DIM       7    1252   operation code 98
XDRGOP99   DIM       7    1259   operation code 99
XDROP100   DIM       7    1266   operation code 100
XDRGALS2   DIM       5    1273   Acute los Same as XDRGALOS but 5 digit
XDRGNLOS   DIM       4    1278   Non-acceptable los
XDRGTOTL   DIM       4    1282   Total Leave Days
.XDRGSDAY  DIM       1    1286   Same day (0 = not sameday, 1 = sameday)
.XDRGMHLS  DIM       1    1287   Mental health legal status
.USERKEY1  DIM       2    1288   User Key 1
.USERKEY2  DIM       2    1290   User Key 2
.
.End of Record            1292   Non-NWAU Input File
.
.************************************************************************
. * ICD10 unix grouper file when using NWAU
.************************************************************************
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
.XDRGSTAT DIM       1        1  State Code
.XDRGHOSP DIM      10        2  Hospital ID
.XDRGMEDN DIM      13       12  Medical Record Number(Admission Number)
.XDRGHTYP DIM       1       25  Hospital Type
.XDRGADAT DIM      10       26  Admission date (dd/mm/ccyy)
.XDRGDDAT DIM      10       36  Discharge date (dd/mm/ccyy)
.XDRGSEP  DIM       2       46  Separation mode
.XDRGBDAT DIM      10       48  Birth date (dd/mm/ccyy)
.XDRGAWHT DIM       4       58  Admission weight
.XDRGAGEY DIM       3       62  Age in years (if > 364 days)
.XDRGAGED DIM       3       65  Age in days (if <= 364 days)
.XDRGSEX  DIM       1       68  Sex
.XDRGHMV  DIM       4       69  Hours on mechanical ventiliation
.XDRGDS01 DIM       5       73  diagnosis 1
XDRGDC01  DIM       2       78  diagnosis 1 Condition Onset
.XDRGDS02 DIM       5       80  diagnosis 2
.XDRGDS03 DIM       5       85  diagnosis 3
.XDRGDS04 DIM       5       90  diagnosis 4
.XDRGDS05 DIM       5       95  diagnosis 5
.XDRGDS06 DIM       5      100  diagnosis 6
.XDRGDS07 DIM       5      105  diagnosis 7
.XDRGDS08 DIM       5      110  diagnosis 8
.XDRGDS09 DIM       5      115  diagnosis 9
.XDRGDS10 DIM       5      120  diagnosis 10
.XDRGDS11 DIM       5      125  diagnosis 11
.XDRGDS12 DIM       5      130  diagnosis 12
.XDRGDS13 DIM       5      135  diagnosis 13
.XDRGDS14 DIM       5      140  diagnosis 14
.XDRGDS15 DIM       5      145  diagnosis 15
.XDRGDS16 DIM       5      150  diagnosis 16
.XDRGDS17 DIM       5      155  diagnosis 17
.XDRGDS18 DIM       5      160  diagnosis 18
.XDRGDS19 DIM       5      165  diagnosis 19
.XDRGDS20 DIM       5      170  diagnosis 20
.XDRGDS21 DIM       5      175  diagnosis 21
.XDRGDS22 DIM       5      180  diagnosis 22
.XDRGDS23 DIM       5      185  diagnosis 23
.XDRGDS24 DIM       5      190  diagnosis 24
.XDRGDS25 DIM       5      195  diagnosis 25
.XDRGDS26 DIM       5      200  diagnosis 26
.XDRGDS27 DIM       5      205  diagnosis 27
.XDRGDS28 DIM       5      210  diagnosis 28
.XDRGDS29 DIM       5      215  diagnosis 29
.XDRGDS30 DIM       5      220  diagnosis 30
.XDRGDS31 DIM       5      225  diagnosis 31
.XDRGDS32 DIM       5      230  diagnosis 32
.XDRGDS33 DIM       5      235  diagnosis 33
.XDRGDS34 DIM       5      240  diagnosis 34
.XDRGDS35 DIM       5      245  diagnosis 35
.XDRGDS36 DIM       5      250  diagnosis 36
.XDRGDS37 DIM       5      255  diagnosis 37
.XDRGDS38 DIM       5      260  diagnosis 38
.XDRGDS39 DIM       5      265  diagnosis 39
.XDRGDS40 DIM       5      270  diagnosis 40
.XDRGDS41 DIM       5      275  diagnosis 41
.XDRGDS42 DIM       5      280  diagnosis 42
.XDRGDS43 DIM       5      285  diagnosis 43
.XDRGDS44 DIM       5      290  diagnosis 44
.XDRGDS45 DIM       5      295  diagnosis 45
.XDRGDS46 DIM       5      300  diagnosis 46
.XDRGDS47 DIM       5      305  diagnosis 47
.XDRGDS48 DIM       5      310  diagnosis 48
.XDRGDS49 DIM       5      315  diagnosis 49
.XDRGDS50 DIM       5      320  diagnosis 50
.XDRGDS51 DIM       5      325  diagnosis 51
.XDRGDS52 DIM       5      330  diagnosis 52
.XDRGDS53 DIM       5      335  diagnosis 53
.XDRGDS54 DIM       5      340  diagnosis 54
.XDRGDS55 DIM       5      345  diagnosis 55
.XDRGDS56 DIM       5      350  diagnosis 56
.XDRGDS57 DIM       5      355  diagnosis 57
.XDRGDS58 DIM       5      360  diagnosis 58
.XDRGDS59 DIM       5      365  diagnosis 59
.XDRGDS60 DIM       5      370  diagnosis 60
.XDRGDS61 DIM       5      375  diagnosis 61
.XDRGDS62 DIM       5      380  diagnosis 62
.XDRGDS63 DIM       5      385  diagnosis 63
.XDRGDS64 DIM       5      390  diagnosis 64
.XDRGDS65 DIM       5      395  diagnosis 65
.XDRGDS66 DIM       5      400  diagnosis 66
.XDRGDS67 DIM       5      405  diagnosis 67
.XDRGDS68 DIM       5      410  diagnosis 68
.XDRGDS69 DIM       5      415  diagnosis 69
.XDRGDS70 DIM       5      420  diagnosis 70
.XDRGDS71 DIM       5      425  diagnosis 71
.XDRGDS72 DIM       5      430  diagnosis 72
.XDRGDS73 DIM       5      435  diagnosis 73
.XDRGDS74 DIM       5      440  diagnosis 74
.XDRGDS75 DIM       5      445  diagnosis 75
.XDRGDS76 DIM       5      450  diagnosis 76
.XDRGDS77 DIM       5      455  diagnosis 77
.XDRGDS78 DIM       5      460  diagnosis 78
.XDRGDS79 DIM       5      465  diagnosis 79
.XDRGDS80 DIM       5      470  diagnosis 80
.XDRGDS81 DIM       5      475  diagnosis 81
.XDRGDS82 DIM       5      480  diagnosis 82
.XDRGDS83 DIM       5      485  diagnosis 83
.XDRGDS84 DIM       5      490  diagnosis 84
.XDRGDS85 DIM       5      495  diagnosis 85
.XDRGDS86 DIM       5      500  diagnosis 86
.XDRGDS87 DIM       5      505  diagnosis 87
.XDRGDS88 DIM       5      510  diagnosis 88
.XDRGDS89 DIM       5      515  diagnosis 89
.XDRGDS90 DIM       5      520  diagnosis 90
.XDRGDS91 DIM       5      525  diagnosis 91
.XDRGDS92 DIM       5      530  diagnosis 92
.XDRGDS93 DIM       5      535  diagnosis 93
.XDRGDS94 DIM       5      540  diagnosis 94
.XDRGDS95 DIM       5      545  diagnosis 95
.XDRGDS96 DIM       5      550  diagnosis 96
.XDRGDS97 DIM       5      555  diagnosis 97
.XDRGDS98 DIM       5      560  diagnosis 98
.XDRGDS99 DIM       5      565  diagnosis 99
.XDRDS100 DIM       5      570  diagnosis 100
XDRGDC02  DIM       2      575  diagnosis 2 Condition Onset
XDRGDC03  DIM       2      577  diagnosis 3 Condition Onset
XDRGDC04  DIM       2      579  diagnosis 4 Condition Onset
XDRGDC05  DIM       2      581  diagnosis 5 Condition Onset
XDRGDC06  DIM       2      583  diagnosis 6 Condition Onset
XDRGDC07  DIM       2      585  diagnosis 7 Condition Onset
XDRGDC08  DIM       2      587  diagnosis 8 Condition Onset
XDRGDC09  DIM       2      589  diagnosis 9 Condition Onset
XDRGDC10  DIM       2      591  diagnosis 10 Condition Onset
XDRGDC11  DIM       2      593  diagnosis 11 Condition Onset
XDRGDC12  DIM       2      595  diagnosis 12 Condition Onset
XDRGDC13  DIM       2      597  diagnosis 13 Condition Onset
XDRGDC14  DIM       2      599  diagnosis 14 Condition Onset
XDRGDC15  DIM       2      601  diagnosis 15 Condition Onset
XDRGDC16  DIM       2      603  diagnosis 16 Condition Onset
XDRGDC17  DIM       2      605  diagnosis 17 Condition Onset
XDRGDC18  DIM       2      607  diagnosis 18 Condition Onset
XDRGDC19  DIM       2      609  diagnosis 19 Condition Onset
XDRGDC20  DIM       2      611  diagnosis 20 Condition Onset
XDRGDC21  DIM       2      613  diagnosis 21 Condition Onset
XDRGDC22  DIM       2      615  diagnosis 22 Condition Onset
XDRGDC23  DIM       2      617  diagnosis 23 Condition Onset
XDRGDC24  DIM       2      619  diagnosis 24 Condition Onset
XDRGDC25  DIM       2      621  diagnosis 25 Condition Onset
XDRGDC26  DIM       2      623  diagnosis 26 Condition Onset
XDRGDC27  DIM       2      625  diagnosis 27 Condition Onset
XDRGDC28  DIM       2      627  diagnosis 28 Condition Onset
XDRGDC29  DIM       2      629  diagnosis 29 Condition Onset
XDRGDC30  DIM       2      631  diagnosis 30 Condition Onset
XDRGDC31  DIM       2      633  diagnosis 31 Condition Onset
XDRGDC32  DIM       2      635  diagnosis 32 Condition Onset
XDRGDC33  DIM       2      637  diagnosis 33 Condition Onset
XDRGDC34  DIM       2      639  diagnosis 34 Condition Onset
XDRGDC35  DIM       2      641  diagnosis 35 Condition Onset
XDRGDC36  DIM       2      643  diagnosis 36 Condition Onset
XDRGDC37  DIM       2      645  diagnosis 37 Condition Onset
XDRGDC38  DIM       2      647  diagnosis 38 Condition Onset
XDRGDC39  DIM       2      649  diagnosis 39 Condition Onset
XDRGDC40  DIM       2      651  diagnosis 40 Condition Onset
XDRGDC41  DIM       2      653  diagnosis 41 Condition Onset
XDRGDC42  DIM       2      655  diagnosis 42 Condition Onset
XDRGDC43  DIM       2      657  diagnosis 43 Condition Onset
XDRGDC44  DIM       2      659  diagnosis 44 Condition Onset
XDRGDC45  DIM       2      661  diagnosis 45 Condition Onset
XDRGDC46  DIM       2      663  diagnosis 46 Condition Onset
XDRGDC47  DIM       2      665  diagnosis 47 Condition Onset
XDRGDC48  DIM       2      667  diagnosis 48 Condition Onset
XDRGDC49  DIM       2      669  diagnosis 49 Condition Onset
XDRGDC50  DIM       2      671  diagnosis 50 Condition Onset
XDRGDC51  DIM       2      673  diagnosis 51 Condition Onset
XDRGDC52  DIM       2      675  diagnosis 52 Condition Onset
XDRGDC53  DIM       2      677  diagnosis 53 Condition Onset
XDRGDC54  DIM       2      679  diagnosis 54 Condition Onset
XDRGDC55  DIM       2      681  diagnosis 55 Condition Onset
XDRGDC56  DIM       2      683  diagnosis 56 Condition Onset
XDRGDC57  DIM       2      685  diagnosis 57 Condition Onset
XDRGDC58  DIM       2      687  diagnosis 58 Condition Onset
XDRGDC59  DIM       2      689  diagnosis 59 Condition Onset
XDRGDC60  DIM       2      691  diagnosis 60 Condition Onset
XDRGDC61  DIM       2      693  diagnosis 61 Condition Onset
XDRGDC62  DIM       2      695  diagnosis 62 Condition Onset
XDRGDC63  DIM       2      697  diagnosis 63 Condition Onset
XDRGDC64  DIM       2      699  diagnosis 64 Condition Onset
XDRGDC65  DIM       2      701  diagnosis 65 Condition Onset
XDRGDC66  DIM       2      703  diagnosis 66 Condition Onset
XDRGDC67  DIM       2      705  diagnosis 67 Condition Onset
XDRGDC68  DIM       2      707  diagnosis 68 Condition Onset
XDRGDC69  DIM       2      709  diagnosis 69 Condition Onset
XDRGDC70  DIM       2      711  diagnosis 70 Condition Onset
XDRGDC71  DIM       2      713  diagnosis 71 Condition Onset
XDRGDC72  DIM       2      715  diagnosis 72 Condition Onset
XDRGDC73  DIM       2      717  diagnosis 73 Condition Onset
XDRGDC74  DIM       2      719  diagnosis 74 Condition Onset
XDRGDC75  DIM       2      721  diagnosis 75 Condition Onset
XDRGDC76  DIM       2      723  diagnosis 76 Condition Onset
XDRGDC77  DIM       2      725  diagnosis 77 Condition Onset
XDRGDC78  DIM       2      727  diagnosis 78 Condition Onset
XDRGDC79  DIM       2      729  diagnosis 79 Condition Onset
XDRGDC80  DIM       2      731  diagnosis 80 Condition Onset
XDRGDC81  DIM       2      733  diagnosis 81 Condition Onset
XDRGDC82  DIM       2      735  diagnosis 82 Condition Onset
XDRGDC83  DIM       2      737  diagnosis 83 Condition Onset
XDRGDC84  DIM       2      739  diagnosis 84 Condition Onset
XDRGDC85  DIM       2      741  diagnosis 85 Condition Onset
XDRGDC86  DIM       2      743  diagnosis 86 Condition Onset
XDRGDC87  DIM       2      745  diagnosis 87 Condition Onset
XDRGDC88  DIM       2      747  diagnosis 88 Condition Onset
XDRGDC89  DIM       2      749  diagnosis 89 Condition Onset
XDRGDC90  DIM       2      751  diagnosis 90 Condition Onset
XDRGDC91  DIM       2      753  diagnosis 91 Condition Onset
XDRGDC92  DIM       2      755  diagnosis 92 Condition Onset
XDRGDC93  DIM       2      757  diagnosis 93 Condition Onset
XDRGDC94  DIM       2      759  diagnosis 94 Condition Onset
XDRGDC95  DIM       2      761  diagnosis 95 Condition Onset
XDRGDC96  DIM       2      763  diagnosis 96 Condition Onset
XDRGDC97  DIM       2      765  diagnosis 97 Condition Onset
XDRGDC98  DIM       2      767  diagnosis 98 Condition Onset
XDRGDC99  DIM       2      769  diagnosis 99 Condition Onset
XDRDC100  DIM       2      771  diagnosis 100 Condition Onset
.XDRGOP01 DIM       7      773  operation code 1
.XDRGOP02 DIM       7      780  operation code 2
.XDRGOP03 DIM       7      787  operation code 3
.XDRGOP04 DIM       7      794  operation code 4
.XDRGOP05 DIM       7      801  operation code 5
.XDRGOP06 DIM       7      808  operation code 6
.XDRGOP07 DIM       7      815  operation code 7
.XDRGOP08 DIM       7      822  operation code 8
.XDRGOP09 DIM       7      829  operation code 9
.XDRGOP10 DIM       7      836  operation code 10
.XDRGOP11 DIM       7      843  operation code 11
.XDRGOP12 DIM       7      850  operation code 12
.XDRGOP13 DIM       7      857  operation code 13
.XDRGOP14 DIM       7      864  operation code 14
.XDRGOP15 DIM       7      871  operation code 15
.XDRGOP16 DIM       7      878  operation code 16
.XDRGOP17 DIM       7      885  operation code 17
.XDRGOP18 DIM       7      892  operation code 18
.XDRGOP19 DIM       7      899  operation code 19
.XDRGOP20 DIM       7      906  operation code 10
.XDRGOP21 DIM       7      913  operation code 21
.XDRGOP22 DIM       7      920  operation code 22
.XDRGOP23 DIM       7      927  operation code 23
.XDRGOP24 DIM       7      934  operation code 24
.XDRGOP25 DIM       7      941  operation code 25
.XDRGOP26 DIM       7      948  operation code 26
.XDRGOP27 DIM       7      955  operation code 27
.XDRGOP28 DIM       7      962  operation code 28
.XDRGOP29 DIM       7      969  operation code 29
.XDRGOP30 DIM       7      976  operation code 30
.XDRGOP31 DIM       7      983  operation code 31
.XDRGOP32 DIM       7      990  operation code 32
.XDRGOP33 DIM       7      997  operation code 33
.XDRGOP34 DIM       7     1004  operation code 34
.XDRGOP35 DIM       7     1011  operation code 35
.XDRGOP36 DIM       7     1018  operation code 36
.XDRGOP37 DIM       7     1025  operation code 37
.XDRGOP38 DIM       7     1032  operation code 38
.XDRGOP39 DIM       7     1039  operation code 39
.XDRGOP40 DIM       7     1046  operation code 40
.XDRGOP41 DIM       7     1053  operation code 41
.XDRGOP42 DIM       7     1060  operation code 42
.XDRGOP43 DIM       7     1067  operation code 43
.XDRGOP44 DIM       7     1074  operation code 44
.XDRGOP45 DIM       7     1081  operation code 45
.XDRGOP46 DIM       7     1088  operation code 46
.XDRGOP47 DIM       7     1095  operation code 47
.XDRGOP48 DIM       7     1102  operation code 48
.XDRGOP49 DIM       7     1109  operation code 49
.XDRGOP50 DIM       7     1116  operation code 50
.XDRGOP51 DIM       7     1123  operation code 51
.XDRGOP52 DIM       7     1130  operation code 52
.XDRGOP53 DIM       7     1137  operation code 53
.XDRGOP54 DIM       7     1144  operation code 54
.XDRGOP55 DIM       7     1151  operation code 55
.XDRGOP56 DIM       7     1158  operation code 56
.XDRGOP57 DIM       7     1165  operation code 57
.XDRGOP58 DIM       7     1172  operation code 58
.XDRGOP59 DIM       7     1179  operation code 59
.XDRGOP60 DIM       7     1186  operation code 60
.XDRGOP61 DIM       7     1193  operation code 61
.XDRGOP62 DIM       7     1200  operation code 62
.XDRGOP63 DIM       7     1207  operation code 63
.XDRGOP64 DIM       7     1214  operation code 64
.XDRGOP65 DIM       7     1221  operation code 65
.XDRGOP66 DIM       7     1228  operation code 66
.XDRGOP67 DIM       7     1235  operation code 67
.XDRGOP68 DIM       7     1242  operation code 68
.XDRGOP69 DIM       7     1249  operation code 69
.XDRGOP70 DIM       7     1256  operation code 70
.XDRGOP71 DIM       7     1263  operation code 71
.XDRGOP72 DIM       7     1270  operation code 72
.XDRGOP73 DIM       7     1277  operation code 73
.XDRGOP74 DIM       7     1284  operation code 74
.XDRGOP75 DIM       7     1291  operation code 75
.XDRGOP76 DIM       7     1298  operation code 76
.XDRGOP77 DIM       7     1305  operation code 77
.XDRGOP78 DIM       7     1312  operation code 78
.XDRGOP79 DIM       7     1319  operation code 79
.XDRGOP80 DIM       7     1326  operation code 80
.XDRGOP81 DIM       7     1333  operation code 81
.XDRGOP82 DIM       7     1340  operation code 82
.XDRGOP83 DIM       7     1347  operation code 83
.XDRGOP84 DIM       7     1354  operation code 84
.XDRGOP85 DIM       7     1361  operation code 85
.XDRGOP86 DIM       7     1368  operation code 86
.XDRGOP87 DIM       7     1375  operation code 87
.XDRGOP88 DIM       7     1382  operation code 88
.XDRGOP89 DIM       7     1389  operation code 89
.XDRGOP90 DIM       7     1396  operation code 90
.XDRGOP91 DIM       7     1403  operation code 91
.XDRGOP92 DIM       7     1410  operation code 92
.XDRGOP93 DIM       7     1417  operation code 93
.XDRGOP94 DIM       7     1424  operation code 94
.XDRGOP95 DIM       7     1431  operation code 95
.XDRGOP96 DIM       7     1438  operation code 96
.XDRGOP97 DIM       7     1445  operation code 97
.XDRGOP98 DIM       7     1452  operation code 98
.XDRGOP99 DIM       7     1459  operation code 99
.XDROP100 DIM       7     1466  operation code 100
.XDRGALS2 DIM       5     1473  Acute los Same as XDRGALOS but 5 digit
.XDRGNLOS DIM       4     1478  Non-acceptable los
.XDRGTOTL DIM       4     1482  Total Leave Days
.XDRGSDAY DIM       1     1486  Same day (0 = not sameday, 1 = sameday)
.XDRGMHLS DIM       1     1487  Mental health legal status
.XDRGAMOD DIM       1     1488  Admission mode
.XDRGCTYP DIM       2     1489  Care Type
.XDRGFNDS DIM       2     1491  Funding source
.XDRGICUH DIM       4     1493  Hours in ICU
.XDRGATSI DIM       1     1497  Aboriginal Torres Straight Islander
.XDRGPCOD DIM       4     1498  Post Code
.XDRGQDAY DIM       3     1502  Total qualified baby days
.XDRGPDAY DIM       4     1505  Total psyciatric care days
.XDRGUROR DIM       1     1509  Unplanned return to theatre
.XDRGURGA DIM       1     1510  DRG Urgency of Admission
.USERKEY1 DIM       2     1511  User Key 1
.USERKEY2 DIM       2     1513  User Key 2
.
.End of Record            1515  NWAU Input File
.
.****************************************************************************
INPFIL9   FILE      ASCII, FIXED=256        * ICD9 grouper file
.
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
.XDRGADMN DIM       8       1   Admission number
.XDRGADAT DIM      10       9   Admission date (dd/mm/ccyy)
.XDRGATIM DIM       2      19   Admission time (hh)
.XDRGDDAT DIM      10      21   Discharge date (dd/mm/ccyy)
.XDRGDTIM DIM       2      31   Discharge time (hh)
.XDRGBDAT DIM      10      33   Birth date (dd/mm/ccyy)
.XDRGAGEY DIM       3      43   Age in years (if > 364 days)
.XDRGAGED DIM       3      46   Age in days (if <= 364 days)
.XDRGSEX  DIM       1      49   Sex
.XDRGSEP  DIM       2      50   Separation mode
.XDRGAWHT DIM       4      52   Admission weight
.XDRGILOS DIM       1      56   Intended los
.                                 0 = not entered
.                                 1 = same day
.                                 2 = overnight
.XDRGSDAY DIM       1      57   Same day (0 = not sameday, 1 = sameday)
.XDRGMHLS DIM       1      58   Mental health legal status
.XDRGHMV  DIM       4      59   Hours on mechanical ventiliation
.XDRGALOS DIM       4      63   Acute los
XDRGD901  DIM       5      67   diagnosis 1
XDRGD902  DIM       5      72   diagnosis 2
XDRGD903  DIM       5      77   diagnosis 3
XDRGD904  DIM       5      82   diagnosis 4
XDRGD905  DIM       5      87   diagnosis 5
XDRGD906  DIM       5      92   diagnosis 6
XDRGD907  DIM       5      97   diagnosis 7
XDRGD908  DIM       5     102   diagnosis 8
XDRGD909  DIM       5     107   diagnosis 9
XDRGD910  DIM       5     112   diagnosis 10
XDRGD911  DIM       5     117   diagnosis 11
XDRGD912  DIM       5     122   diagnosis 12
XDRGD913  DIM       5     127   diagnosis 13
XDRGD914  DIM       5     132   diagnosis 14
XDRGD915  DIM       5     137   diagnosis 15
XDRGD916  DIM       5     142   diagnosis 16
XDRGD917  DIM       5     147   diagnosis 17
XDRGD918  DIM       5     152   diagnosis 18
XDRGD919  DIM       5     157   diagnosis 19
XDRGD920  DIM       5     162   diagnosis 20
XDRGD921  DIM       5     167   diagnosis 21
XDRGO901  DIM       4     172   operation code 1
XDRGO902  DIM       4     176   operation code 2
XDRGO903  DIM       4     180   operation code 3
XDRGO904  DIM       4     184   operation code 4
XDRGO905  DIM       4     188   operation code 5
XDRGO906  DIM       4     192   operation code 6
XDRGO907  DIM       4     196   operation code 7
XDRGO908  DIM       4     200   operation code 8
XDRGO909  DIM       4     204   operation code 9
XDRGO910  DIM       4     208   operation code 10
XDRGO911  DIM       4     212   operation code 11
XDRGO912  DIM       4     216   operation code 12
XDRGO913  DIM       4     220   operation code 13
XDRGO914  DIM       4     224   operation code 14
XDRGO915  DIM       4     228   operation code 15
XDRGO916  DIM       4     232   operation code 16
XDRGO917  DIM       4     236   operation code 17
XDRGO918  DIM       4     240   operation code 18
XDRGO919  DIM       4     244   operation code 19
XDRGO920  DIM       4     248   operation code 20
XDRGO921  DIM       4     252   operation code 21
.
.End of Record            256
.
.********************************************************************
OUTFILE2  FILE      ASCII, FIXED=327
.
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  ------------------------------------
.XDRGADMN DIM       8       1   Admission number
XDRGDRG   DIM       4       9   Diagnostic Related Group (DRG)
XDRGDRGD  DIM       72     13   DRG description
XDRGMDC   DIM       2      85   Major Diagnostic Category (MDC)
XDRGMDCD  DIM       73     87   MDC description
XDRGCCL   DIM       1     160   CC class level
XDRGGSC   DIM       2     161   Grouper status code
XDRGNWT   DIM       9     163   DRG national weight
XDRGNALS  DIM       7     172   DRG national average LOS
XDRGSWT   DIM       9     179   DRG state weight
XDRGSALS  DIM       7     188   DRG state average LOS
XDRGLWT   DIM       9     195   DRG local weight
XDRGLALS  DIM       7     204   DRG local average LOS
XDRGCTRV  DIM       5     211   Grouper Country 04 for Aust. + version *C-50344
XDRGECRW  DIM      11     216   ECCS RAW Format
.
.
.XDRGNWAU  DIM     11     227   Total NWAU for unix grouper (11 Characters)
.
.End of Record            238
.
.************************************************************************
.                  Unix Grouper Output File Variables (non-NWAU) - 2025
.************************************************************************
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
.XDRGSTAT  DIM       1       1   State Code
.XDRGHOSP  DIM      10       2   Hospital ID
.XDRGMEDN  DIM      13      12   Medical Record Number(Admission Number)
.XDRGHTYP  DIM       1      25   Hospital Type
.XDRGADAT  DIM      10      26   Admission date (dd/mm/ccyy)
.XDRGDDAT  DIM      10      36   Seperation(Discharge) date (dd/mm/ccyy)
.XDRGSEP   DIM       2      46   Separation mode
.XDRGBDAT  DIM      10      48   Birth date (dd/mm/ccyy)
.XDRGAWHT  DIM       4      58   Admission weight
.XDRGAGEY  DIM       3      62   Age in years (if > 364 days)
.XDRGAGED  DIM       3      65   Age in days (if <= 364 days)
.XDRGSEX   DIM       1      68   Sex
.XDRGHMV   DIM       4      69   Hours on mechanical ventiliation
.XDRGDS01  DIM       5      73   Principle Diagnosis 1
XDRGDI01  DIM       2       78  diagnosis 1 Cluster Id
.XDRGDS02  DIM       5      80   diagnosis 2
.XDRGDS03  DIM       5      85   diagnosis 3
.XDRGDS04  DIM       5      90   diagnosis 4
.XDRGDS05  DIM       5      95   diagnosis 5
.XDRGDS06  DIM       5     100   diagnosis 6
.XDRGDS07  DIM       5     105   diagnosis 7
.XDRGDS08  DIM       5     110   diagnosis 8
.XDRGDS09  DIM       5     115   diagnosis 9
.XDRGDS10  DIM       5     120   diagnosis 10
.XDRGDS11  DIM       5     125   diagnosis 11
.XDRGDS12  DIM       5     130   diagnosis 12
.XDRGDS13  DIM       5     135   diagnosis 13
.XDRGDS14  DIM       5     140   diagnosis 14
.XDRGDS15  DIM       5     145   diagnosis 15
.XDRGDS16  DIM       5     150   diagnosis 16
.XDRGDS17  DIM       5     155   diagnosis 17
.XDRGDS18  DIM       5     160   diagnosis 18
.XDRGDS19  DIM       5     165   diagnosis 19
.XDRGDS20  DIM       5     170   diagnosis 20
.XDRGDS21  DIM       5     175   diagnosis 21
.XDRGDS22   DIM       5     180   diagnosis 22
.XDRGDS23   DIM       5     185   diagnosis 23
.XDRGDS24   DIM       5     190   diagnosis 24
.XDRGDS25   DIM       5     195   diagnosis 25
.XDRGDS26   DIM       5     200   diagnosis 26
.XDRGDS27   DIM       5     205   diagnosis 27
.XDRGDS28   DIM       5     210   diagnosis 28
.XDRGDS29   DIM       5     215   diagnosis 29
.XDRGDS30   DIM       5     220   diagnosis 30
.XDRGDS31   DIM       5     225   diagnosis 31
.XDRGDS32   DIM       5     230   diagnosis 32
.XDRGDS33   DIM       5     235   diagnosis 33
.XDRGDS34   DIM       5     240   diagnosis 34
.XDRGDS35   DIM       5     245   diagnosis 35
.XDRGDS36   DIM       5     250   diagnosis 36
.XDRGDS37   DIM       5     255   diagnosis 37
.XDRGDS38   DIM       5     260   diagnosis 38
.XDRGDS39   DIM       5     265   diagnosis 39
.XDRGDS40   DIM       5     270   diagnosis 40
.XDRGDS41   DIM       5     275   diagnosis 41
.XDRGDS42   DIM       5     280   diagnosis 42
.XDRGDS43   DIM       5     285   diagnosis 43
.XDRGDS44   DIM       5     290   diagnosis 44
.XDRGDS45   DIM       5     295   diagnosis 45
.XDRGDS46   DIM       5     300   diagnosis 46
.XDRGDS47   DIM       5     305   diagnosis 47
.XDRGDS48   DIM       5     310   diagnosis 48
.XDRGDS49   DIM       5     315   diagnosis 49
.XDRGDS50   DIM       5     320   diagnosis 50
.XDRGDS51   DIM       5     325   diagnosis 51
.XDRGDS52   DIM       5     330   diagnosis 52
.XDRGDS53   DIM       5     335   diagnosis 53
.XDRGDS54   DIM       5     340   diagnosis 54
.XDRGDS55   DIM       5     345   diagnosis 55
.XDRGDS56   DIM       5     350   diagnosis 56
.XDRGDS57   DIM       5     355   diagnosis 57
.XDRGDS58   DIM       5     360   diagnosis 58
.XDRGDS59   DIM       5     365   diagnosis 59
.XDRGDS60   DIM       5     370   diagnosis 60
.XDRGDS61   DIM       5     375   diagnosis 61
.XDRGDS62   DIM       5     380   diagnosis 62
.XDRGDS63   DIM       5     385   diagnosis 63
.XDRGDS64   DIM       5     390   diagnosis 64
.XDRGDS65   DIM       5     395   diagnosis 65
.XDRGDS66   DIM       5     400   diagnosis 66
.XDRGDS67   DIM       5     405   diagnosis 67
.XDRGDS68   DIM       5     410   diagnosis 68
.XDRGDS69   DIM       5     415   diagnosis 69
.XDRGDS70   DIM       5     420   diagnosis 70
.XDRGDS71   DIM       5     425   diagnosis 71
.XDRGDS72   DIM       5     430   diagnosis 72
.XDRGDS73   DIM       5     435   diagnosis 73
.XDRGDS74   DIM       5     440   diagnosis 74
.XDRGDS75   DIM       5     445   diagnosis 75
.XDRGDS76   DIM       5     450   diagnosis 76
.XDRGDS77   DIM       5     455   diagnosis 77
.XDRGDS78   DIM       5     460   diagnosis 78
.XDRGDS79   DIM       5     465   diagnosis 79
.XDRGDS80   DIM       5     470   diagnosis 80
.XDRGDS81   DIM       5     475   diagnosis 81
.XDRGDS82   DIM       5     480   diagnosis 82
.XDRGDS83   DIM       5     485   diagnosis 83
.XDRGDS84   DIM       5     490   diagnosis 84
.XDRGDS85   DIM       5     495   diagnosis 85
.XDRGDS86   DIM       5     500   diagnosis 86
.XDRGDS87   DIM       5     505   diagnosis 87
.XDRGDS88   DIM       5     510   diagnosis 88
.XDRGDS89   DIM       5     515   diagnosis 89
.XDRGDS90   DIM       5     520   diagnosis 90
.XDRGDS91   DIM       5     525   diagnosis 91
.XDRGDS92   DIM       5     530   diagnosis 92
.XDRGDS93   DIM       5     535   diagnosis 93
.XDRGDS94   DIM       5     540   diagnosis 94
.XDRGDS95   DIM       5     545   diagnosis 95
.XDRGDS96   DIM       5     550   diagnosis 96
.XDRGDS97   DIM       5     555   diagnosis 97
.XDRGDS98   DIM       5     560   diagnosis 98
.XDRGDS99   DIM       5     565   diagnosis 99
.XDRDS100   DIM       5     570   diagnosis 100
XDRGDI02  DIM       2       575  diagnosis 2 Cluster Id
XDRGDI03  DIM       2       577  diagnosis 3 Cluster Id
XDRGDI04  DIM       2       579  diagnosis 4 Cluster Id
XDRGDI05  DIM       2       581  diagnosis 5 Cluster Id
XDRGDI06  DIM       2       583  diagnosis 6 Cluster Id
XDRGDI07  DIM       2       585  diagnosis 7 Cluster Id
XDRGDI08  DIM       2       587  diagnosis 8 Cluster Id
XDRGDI09  DIM       2       589  diagnosis 9 Cluster Id
XDRGDI10  DIM       2       591  diagnosis 10 Cluster Id
XDRGDI11  DIM       2       593  diagnosis 11 Cluster Id
XDRGDI12  DIM       2       595  diagnosis 12 Cluster Id
XDRGDI13  DIM       2       597  diagnosis 13 Cluster Id
XDRGDI14  DIM       2       599  diagnosis 14 Cluster Id
XDRGDI15  DIM       2       601  diagnosis 15 Cluster Id
XDRGDI16  DIM       2       603  diagnosis 16 Cluster Id
XDRGDI17  DIM       2       605  diagnosis 17 Cluster Id
XDRGDI18  DIM       2       607  diagnosis 18 Cluster Id
XDRGDI19  DIM       2       609  diagnosis 19 Cluster Id
XDRGDI20  DIM       2       611  diagnosis 20 Cluster Id
XDRGDI21  DIM       2       613  diagnosis 21 Cluster Id
XDRGDI22  DIM       2       615  diagnosis 22 Cluster Id
XDRGDI23  DIM       2       617  diagnosis 23 Cluster Id
XDRGDI24  DIM       2       619  diagnosis 24 Cluster Id
XDRGDI25  DIM       2       621  diagnosis 25 Cluster Id
XDRGDI26  DIM       2       623  diagnosis 26 Cluster Id
XDRGDI27  DIM       2       625  diagnosis 27 Cluster Id
XDRGDI28  DIM       2       627  diagnosis 28 Cluster Id
XDRGDI29  DIM       2       629  diagnosis 29 Cluster Id
XDRGDI30  DIM       2       631  diagnosis 30 Cluster Id
XDRGDI31  DIM       2       633  diagnosis 31 Cluster Id
XDRGDI32  DIM       2       635  diagnosis 32 Cluster Id
XDRGDI33  DIM       2       637  diagnosis 33 Cluster Id
XDRGDI34  DIM       2       639  diagnosis 34 Cluster Id
XDRGDI35  DIM       2       641  diagnosis 35 Cluster Id
XDRGDI36  DIM       2       643  diagnosis 36 Cluster Id
XDRGDI37  DIM       2       645  diagnosis 37 Cluster Id
XDRGDI38  DIM       2       647  diagnosis 38 Cluster Id
XDRGDI39  DIM       2       649  diagnosis 39 Cluster Id
XDRGDI40  DIM       2       651  diagnosis 40 Cluster Id
XDRGDI41  DIM       2       653  diagnosis 41 Cluster Id
XDRGDI42  DIM       2       655  diagnosis 42 Cluster Id
XDRGDI43  DIM       2       657  diagnosis 43 Cluster Id
XDRGDI44  DIM       2       659  diagnosis 44 Cluster Id
XDRGDI45  DIM       2       661  diagnosis 45 Cluster Id
XDRGDI46  DIM       2       663  diagnosis 46 Cluster Id
XDRGDI47  DIM       2       665  diagnosis 47 Cluster Id
XDRGDI48  DIM       2       667  diagnosis 48 Cluster Id
XDRGDI49  DIM       2       669  diagnosis 49 Cluster Id
XDRGDI50  DIM       2       671  diagnosis 50 Cluster Id
XDRGDI51  DIM       2       673  diagnosis 51 Cluster Id
XDRGDI52  DIM       2       675  diagnosis 52 Cluster Id
XDRGDI53  DIM       2       677  diagnosis 53 Cluster Id
XDRGDI54  DIM       2       679  diagnosis 54 Cluster Id
XDRGDI55  DIM       2       681  diagnosis 55 Cluster Id
XDRGDI56  DIM       2       683  diagnosis 56 Cluster Id
XDRGDI57  DIM       2       685  diagnosis 57 Cluster Id
XDRGDI58  DIM       2       687  diagnosis 58 Cluster Id
XDRGDI59  DIM       2       689  diagnosis 59 Cluster Id
XDRGDI60  DIM       2       691  diagnosis 60 Cluster Id
XDRGDI61  DIM       2       693  diagnosis 61 Cluster Id
XDRGDI62  DIM       2       695  diagnosis 62 Cluster Id
XDRGDI63  DIM       2       697  diagnosis 63 Cluster Id
XDRGDI64  DIM       2       699  diagnosis 64 Cluster Id
XDRGDI65  DIM       2       701  diagnosis 65 Cluster Id
XDRGDI66  DIM       2       703  diagnosis 66 Cluster Id
XDRGDI67  DIM       2       705  diagnosis 67 Cluster Id
XDRGDI68  DIM       2       707  diagnosis 68 Cluster Id
XDRGDI69  DIM       2       709  diagnosis 69 Cluster Id
XDRGDI70  DIM       2       711  diagnosis 70 Cluster Id
XDRGDI71  DIM       2       713  diagnosis 71 Cluster Id
XDRGDI72  DIM       2       715  diagnosis 72 Cluster Id
XDRGDI73  DIM       2       717  diagnosis 73 Cluster Id
XDRGDI74  DIM       2       719  diagnosis 74 Cluster Id
XDRGDI75  DIM       2       721  diagnosis 75 Cluster Id
XDRGDI76  DIM       2       723  diagnosis 76 Cluster Id
XDRGDI77  DIM       2       725  diagnosis 77 Cluster Id
XDRGDI78  DIM       2       727  diagnosis 78 Cluster Id
XDRGDI79  DIM       2       729  diagnosis 79 Cluster Id
XDRGDI80  DIM       2       731  diagnosis 80 Cluster Id
XDRGDI81  DIM       2       733  diagnosis 81 Cluster Id
XDRGDI82  DIM       2       735  diagnosis 82 Cluster Id
XDRGDI83  DIM       2       737  diagnosis 83 Cluster Id
XDRGDI84  DIM       2       739  diagnosis 84 Cluster Id
XDRGDI85  DIM       2       741  diagnosis 85 Cluster Id
XDRGDI86  DIM       2       743  diagnosis 86 Cluster Id
XDRGDI87  DIM       2       745  diagnosis 87 Cluster Id
XDRGDI88  DIM       2       747  diagnosis 88 Cluster Id
XDRGDI89  DIM       2       749  diagnosis 89 Cluster Id
XDRGDI90  DIM       2       751  diagnosis 90 Cluster Id
XDRGDI91  DIM       2       753  diagnosis 91 Cluster Id
XDRGDI92  DIM       2       755  diagnosis 92 Cluster Id
XDRGDI93  DIM       2       757  diagnosis 93 Cluster Id
XDRGDI94  DIM       2       759  diagnosis 94 Cluster Id
XDRGDI95  DIM       2       761  diagnosis 95 Cluster Id
XDRGDI96  DIM       2       763  diagnosis 96 Cluster Id
XDRGDI97  DIM       2       765  diagnosis 97 Cluster Id
XDRGDI98  DIM       2       767  diagnosis 98 Cluster Id
XDRGDI99  DIM       2       769  diagnosis 99 Cluster Id
XDRDI100  DIM       2       771  diagnosis 100 Cluster Id
.XDRGOP01  DIM       7     773   operation code 1
.XDRGOP02  DIM       7     780   operation code 2
.XDRGOP03  DIM       7     787   operation code 3
.XDRGOP04  DIM       7     794   operation code 4
.XDRGOP05  DIM       7     801   operation code 5
.XDRGOP06  DIM       7     808   operation code 6
.XDRGOP07  DIM       7     815   operation code 7
.XDRGOP08  DIM       7     822   operation code 8
.XDRGOP09  DIM       7     829   operation code 9
.XDRGOP10  DIM       7     836   operation code 10
.XDRGOP11  DIM       7     843   operation code 11
.XDRGOP12  DIM       7     850   operation code 12
.XDRGOP13  DIM       7     857   operation code 13
.XDRGOP14  DIM       7     864   operation code 14
.XDRGOP15  DIM       7     871   operation code 15
.XDRGOP16  DIM       7     878   operation code 16
.XDRGOP17  DIM       7     885   operation code 17
.XDRGOP18  DIM       7     892   operation code 18
.XDRGOP19  DIM       7     899   operation code 19
.XDRGOP20  DIM       7     906   operation code 20
.XDRGOP21  DIM       7     913   operation code 21                     
.XDRGOP22  DIM       7     920   operation code 22                     
.XDRGOP23  DIM       7     927   operation code 23                     
.XDRGOP24  DIM       7     934   operation code 24                     
.XDRGOP25  DIM       7     941   operation code 25                     
.XDRGOP26  DIM       7     948   operation code 26                     
.XDRGOP27  DIM       7     955   operation code 27                     
.XDRGOP28  DIM       7     962   operation code 28                     
.XDRGOP29  DIM       7     969   operation code 29                     
.XDRGOP30  DIM       7     976   operation code 30                     
.XDRGOP31  DIM       7     983   operation code 31                     
.XDRGOP32  DIM       7     990   operation code 32                     
.XDRGOP33  DIM       7     997   operation code 33                     
.XDRGOP34  DIM       7    1004   operation code 34                     
.XDRGOP35  DIM       7    1011   operation code 35                     
.XDRGOP36  DIM       7    1018   operation code 36                     
.XDRGOP37  DIM       7    1025   operation code 37                     
.XDRGOP38  DIM       7    1032   operation code 38                     
.XDRGOP39  DIM       7    1039   operation code 39                     
.XDRGOP40  DIM       7    1046   operation code 40                     
.XDRGOP41  DIM       7    1053   operation code 41                     
.XDRGOP42  DIM       7    1060   operation code 42                     
.XDRGOP43  DIM       7    1067   operation code 43                     
.XDRGOP44  DIM       7    1074   operation code 44                     
.XDRGOP45  DIM       7    1081   operation code 45                     
.XDRGOP46  DIM       7    1088   operation code 46                     
.XDRGOP47  DIM       7    1095   operation code 47                     
.XDRGOP48  DIM       7    1102   operation code 48                     
.XDRGOP49  DIM       7    1109   operation code 49                     
.XDRGOP50  DIM       7    1116   operation code 50                     
.XDRGOP51  DIM       7    1123   operation code 51                     
.XDRGOP52  DIM       7    1130   operation code 52                     
.XDRGOP53  DIM       7    1137   operation code 53                     
.XDRGOP54  DIM       7    1144   operation code 54                     
.XDRGOP55  DIM       7    1151   operation code 55                     
.XDRGOP56  DIM       7    1158   operation code 56                     
.XDRGOP57  DIM       7    1165   operation code 57                     
.XDRGOP58  DIM       7    1172   operation code 58                     
.XDRGOP59  DIM       7    1179   operation code 59                     
.XDRGOP60  DIM       7    1186   operation code 60                     
.XDRGOP61  DIM       7    1193   operation code 61                     
.XDRGOP62  DIM       7    1200   operation code 62                     
.XDRGOP63  DIM       7    1207   operation code 63                     
.XDRGOP64  DIM       7    1214   operation code 64                     
.XDRGOP65  DIM       7    1221   operation code 65                     
.XDRGOP66  DIM       7    1228   operation code 66                     
.XDRGOP67  DIM       7    1235   operation code 67                     
.XDRGOP68  DIM       7    1242   operation code 68                     
.XDRGOP69  DIM       7    1249   operation code 69                     
.XDRGOP70  DIM       7    1256   operation code 70                     
.XDRGOP71  DIM       7    1263   operation code 71                     
.XDRGOP72  DIM       7    1270   operation code 72                     
.XDRGOP73  DIM       7    1277   operation code 73                     
.XDRGOP74  DIM       7    1284   operation code 74                     
.XDRGOP75  DIM       7    1291   operation code 75                     
.XDRGOP76  DIM       7    1298   operation code 76                     
.XDRGOP77  DIM       7    1305   operation code 77                     
.XDRGOP78  DIM       7    1312   operation code 78                     
.XDRGOP79  DIM       7    1319   operation code 79                     
.XDRGOP80  DIM       7    1326   operation code 80                     
.XDRGOP81  DIM       7    1333   operation code 81                     
.XDRGOP82  DIM       7    1340   operation code 82                     
.XDRGOP83  DIM       7    1347   operation code 83                     
.XDRGOP84  DIM       7    1354   operation code 84                     
.XDRGOP85  DIM       7    1361   operation code 85                     
.XDRGOP86  DIM       7    1368   operation code 86                     
.XDRGOP87  DIM       7    1375   operation code 87                     
.XDRGOP88  DIM       7    1382   operation code 88                     
.XDRGOP89  DIM       7    1389   operation code 89                     
.XDRGOP90  DIM       7    1396   operation code 90                     
.XDRGOP91  DIM       7    1403   operation code 91                     
.XDRGOP92  DIM       7    1410   operation code 92                     
.XDRGOP93  DIM       7    1417   operation code 93                     
.XDRGOP94  DIM       7    1424   operation code 94                     
.XDRGOP95  DIM       7    1431   operation code 95                     
.XDRGOP96  DIM       7    1438   operation code 96                     
.XDRGOP97  DIM       7    1445   operation code 97                     
.XDRGOP98  DIM       7    1452   operation code 98                     
.XDRGOP99  DIM       7    1459   operation code 99                     
.XDROP100  DIM       7    1466   operation code 100
.XDRGALS2  DIM       5    1473   Acute los Same as XDRGALOS but 5 digit*C-50344
.XDRGNLOS  DIM       4    1478   Non-acceptable los
.XDRGTOTL  DIM       4    1482   Total Leave Days
.XDRGSDAY  DIM       1    1486   Same day (0 = not sameday, 1 = sameday)
.XDRGMHLS  DIM       1    1487   Mental health legal status
.XDRGDRG   DIM       4    1488   Diagnostic Related Group (DRG)
.XDRGMDC   DIM       2    1492   Major Diagnostic Category (MDC)
XDRGGAGE  DIM       1     1494  Age used for grouping edit
XDRGGSEX  DIM       1     1495  Sex used for grouping edit
XDRGGLOS  DIM       1     1496  Los used for grouping edit
XDRGGSDF  DIM       1     1497  Same Day Field used for grouping edit
XDRGGSEP  DIM       1     1498  Seperation Code used for grouping edit
XDRGADMW  DIM       2     1499  Admission Weight used for grouping edit
XDRGGHMV  DIM       1     1501  Hrs on Mech Ventilation used for grouping edit
XDRGGMHL  DIM       1     1502  Mental Hlth Leave status used for grouping edit
XDRGGPDX  DIM       1     1503  Principle Diagnosis used for grouping edits
XDRGDX01  DIM       3     1504  Secondary diagnosis used for grouping edits
XDRGDX02  DIM       3     1507  Secondary diagnosis used for grouping edits
XDRGDX03  DIM       3     1510  Secondary diagnosis used for grouping edits
XDRGDX04  DIM       3     1513  Secondary diagnosis used for grouping edits
XDRGDX05  DIM       3     1516  Secondary diagnosis used for grouping edits
XDRGDX06  DIM       3     1519  Secondary diagnosis used for grouping edits
XDRGDX07  DIM       3     1522  Secondary diagnosis used for grouping edits
XDRGDX08  DIM       3     1525  Secondary diagnosis used for grouping edits
XDRGDX09  DIM       3     1528  Secondary diagnosis used for grouping edits
XDRGDX10  DIM       3     1531  Secondary diagnosis used for grouping edits
XDRGDX11  DIM       3     1534  Secondary diagnosis used for grouping edits
XDRGDX12  DIM       3     1537  Secondary diagnosis used for grouping edits
XDRGDX13  DIM       3     1540  Secondary diagnosis used for grouping edits
XDRGDX14  DIM       3     1543  Secondary diagnosis used for grouping edits
XDRGDX15  DIM       3     1546  Secondary diagnosis used for grouping edits
XDRGDX16  DIM       3     1549  Secondary diagnosis used for grouping edits
XDRGDX17  DIM       3     1552  Secondary diagnosis used for grouping edits
XDRGDX18  DIM       3     1555  Secondary diagnosis used for grouping edits
XDRGDX19  DIM       3     1558  Secondary diagnosis used for grouping edits
XDRGDX20  DIM       3     1561  Secondary diagnosis used for grouping edits
XDRGDX21  DIM       3     1564  Secondary diagnosis used for grouping edits
XDRGDX22  DIM       3     1567  Secondary diagnosis used for grouping edits
XDRGDX23  DIM       3     1570  Secondary diagnosis used for grouping edits
XDRGDX24  DIM       3     1573  Secondary diagnosis used for grouping edits
XDRGDX25  DIM       3     1576  Secondary diagnosis used for grouping edits
XDRGDX26  DIM       3     1579  Secondary diagnosis used for grouping edits
XDRGDX27  DIM       3     1582  Secondary diagnosis used for grouping edits
XDRGDX28  DIM       3     1585  Secondary diagnosis used for grouping edits
XDRGDX29  DIM       3     1588  Secondary diagnosis used for grouping edits
XDRGDX30  DIM       3     1591  Secondary diagnosis used for grouping edits
XDRGDX31  DIM       3     1594  Secondary diagnosis used for grouping edits
XDRGDX32  DIM       3     1597  Secondary diagnosis used for grouping edits
XDRGDX33  DIM       3     1600  Secondary diagnosis used for grouping edits
XDRGDX34  DIM       3     1603  Secondary diagnosis used for grouping edits
XDRGDX35  DIM       3     1606  Secondary diagnosis used for grouping edits
XDRGDX36  DIM       3     1609  Secondary diagnosis used for grouping edits
XDRGDX37  DIM       3     1612  Secondary diagnosis used for grouping edits
XDRGDX38  DIM       3     1615  Secondary diagnosis used for grouping edits
XDRGDX39  DIM       3     1618  Secondary diagnosis used for grouping edits
XDRGDX40  DIM       3     1621  Secondary diagnosis used for grouping edits
XDRGDX41  DIM       3     1624  Secondary diagnosis used for grouping edits
XDRGDX42  DIM       3     1627  Secondary diagnosis used for grouping edits
XDRGDX43  DIM       3     1630	Secondary diagnosis used for grouping edits
XDRGDX44  DIM       3     1633  Secondary diagnosis used for grouping edits
XDRGDX45  DIM       3     1636  Secondary diagnosis used for grouping edits
XDRGDX46  DIM       3     1639  Secondary diagnosis used for grouping edits
XDRGDX47  DIM       3     1642  Secondary diagnosis used for grouping edits
XDRGDX48  DIM       3     1645  Secondary diagnosis used for grouping edits
XDRGDX49  DIM       3     1648  Secondary diagnosis used for grouping edits
XDRGDX50  DIM       3     1651  Secondary diagnosis used for grouping edits
XDRGDX51  DIM       3     1654  Secondary diagnosis used for grouping edits
XDRGDX52  DIM       3     1657  Secondary diagnosis used for grouping edits
XDRGDX53  DIM       3     1660  Secondary diagnosis used for grouping edits
XDRGDX54  DIM       3     1663  Secondary diagnosis used for grouping edits
XDRGDX55  DIM       3     1666  Secondary diagnosis used for grouping edits
XDRGDX56  DIM       3     1669  Secondary diagnosis used for grouping edits
XDRGDX57  DIM       3     1672  Secondary diagnosis used for grouping edits
XDRGDX58  DIM       3     1675  Secondary diagnosis used for grouping edits
XDRGDX59  DIM       3     1678  Secondary diagnosis used for grouping edits
XDRGDX60  DIM       3     1681  Secondary diagnosis used for grouping edits
XDRGDX61  DIM       3     1684  Secondary diagnosis used for grouping edits
XDRGDX62  DIM       3     1687  Secondary diagnosis used for grouping edits
XDRGDX63  DIM       3     1690  Secondary diagnosis used for grouping edits
XDRGDX64  DIM       3     1693  Secondary diagnosis used for grouping edits
XDRGDX65  DIM       3     1696  Secondary diagnosis used for grouping edits
XDRGDX66  DIM       3     1699  Secondary diagnosis used for grouping edits
XDRGDX67  DIM       3     1702  Secondary diagnosis used for grouping edits
XDRGDX68  DIM       3     1705  Secondary diagnosis used for grouping edits
XDRGDX69  DIM       3     1708  Secondary diagnosis used for grouping edits
XDRGDX70  DIM       3     1711  Secondary diagnosis used for grouping edits
XDRGDX71  DIM       3     1714  Secondary diagnosis used for grouping edits
XDRGDX72  DIM       3     1717  Secondary diagnosis used for grouping edits
XDRGDX73  DIM       3     1720  Secondary diagnosis used for grouping edits
XDRGDX74  DIM       3     1723  Secondary diagnosis used for grouping edits
XDRGDX75  DIM       3     1726  Secondary diagnosis used for grouping edits
XDRGDX76  DIM       3     1729  Secondary diagnosis used for grouping edits
XDRGDX77  DIM       3     1732  Secondary diagnosis used for grouping edits
XDRGDX78  DIM       3     1735  Secondary diagnosis used for grouping edits
XDRGDX79  DIM       3     1738  Secondary diagnosis used for grouping edits
XDRGDX80  DIM       3     1741  Secondary diagnosis used for grouping edits
XDRGDX81  DIM       3     1744  Secondary diagnosis used for grouping edits
XDRGDX82  DIM       3     1747  Secondary diagnosis used for grouping edits
XDRGDX83  DIM       3     1750  Secondary diagnosis used for grouping edits
XDRGDX84  DIM       3     1753  Secondary diagnosis used for grouping edits
XDRGDX85  DIM       3     1756  Secondary diagnosis used for grouping edits
XDRGDX86  DIM       3     1759  Secondary diagnosis used for grouping edits
XDRGDX87  DIM       3     1762  Secondary diagnosis used for grouping edits
XDRGDX88  DIM       3     1765  Secondary diagnosis used for grouping edits
XDRGDX89  DIM       3     1768  Secondary diagnosis used for grouping edits
XDRGDX90  DIM       3     1771  Secondary diagnosis used for grouping edits
XDRGDX91  DIM       3     1774  Secondary diagnosis used for grouping edits
XDRGDX92  DIM       3     1777  Secondary diagnosis used for grouping edits
XDRGDX93  DIM       3     1780  Secondary diagnosis used for grouping edits
XDRGDX94  DIM       3     1783  Secondary diagnosis used for grouping edits
XDRGDX95  DIM       3     1786  Secondary diagnosis used for grouping edits
XDRGDX96  DIM       3     1789  Secondary diagnosis used for grouping edits
XDRGDX97  DIM       3     1792  Secondary diagnosis used for grouping edits
XDRGDX98  DIM       3     1795  Secondary diagnosis used for grouping edits
XDRGDX99  DIM       3     1798  Secondary diagnosis used for grouping edits
XDRDX100  DIM       3     1801  Secondary diagnosis used for grouping edits
XDRGSR01  DIM       3     1804  Procedure used for grouping edits
XDRGSR02  DIM       3     1807  Procedure used for grouping edits
XDRGSR03  DIM       3     1810  Procedure used for grouping edits
XDRGSR04  DIM       3     1813  Procedure used for grouping edits
XDRGSR05  DIM       3     1816  Procedure used for grouping edits
XDRGSR06  DIM       3     1819  Procedure used for grouping edits
XDRGSR07  DIM       3     1822  Procedure used for grouping edits
XDRGSR08  DIM       3     1825  Procedure used for grouping edits
XDRGSR09  DIM       3     1828  Procedure used for grouping edits
XDRGSR10  DIM       3     1831  Procedure used for grouping edits
XDRGSR11  DIM       3     1834  Procedure used for grouping edits
XDRGSR12  DIM       3     1837  Procedure used for grouping edits
XDRGSR13  DIM       3     1840  Procedure used for grouping edits
XDRGSR14  DIM       3     1843  Procedure used for grouping edits
XDRGSR15  DIM       3     1846  Procedure used for grouping edits
XDRGSR16  DIM       3     1849  Procedure used for grouping edits
XDRGSR17  DIM       3     1852  Procedure used for grouping edits
XDRGSR18  DIM       3     1855  Procedure used for grouping edits
XDRGSR19  DIM       3     1858  Procedure used for grouping edits
XDRGSR20  DIM       3     1861  Procedure used for grouping edits
XDRGSR21  DIM       3     1864  Procedure used for grouping edits
XDRGSR22  DIM       3     1867  Procedure used for grouping edits
XDRGSR23  DIM       3     1870  Procedure used for grouping edits
XDRGSR24  DIM       3     1873  Procedure used for grouping edits
XDRGSR25  DIM       3     1876  Procedure used for grouping edits
XDRGSR26  DIM       3     1879  Procedure used for grouping edits
XDRGSR27  DIM       3     1882  Procedure used for grouping edits
XDRGSR28  DIM       3     1885  Procedure used for grouping edits
XDRGSR29  DIM       3     1888  Procedure used for grouping edits
XDRGSR30  DIM       3     1891  Procedure used for grouping edits
XDRGSR31  DIM       3     1894  Procedure used for grouping edits
XDRGSR32  DIM       3     1897  Procedure used for grouping edits
XDRGSR33  DIM       3     1900  Procedure used for grouping edits
XDRGSR34  DIM       3     1903  Procedure used for grouping edits
XDRGSR35  DIM       3     1906  Procedure used for grouping edits
XDRGSR36  DIM       3     1909  Procedure used for grouping edits
XDRGSR37  DIM       3     1912  Procedure used for grouping edits
XDRGSR38  DIM       3     1915  Procedure used for grouping edits
XDRGSR39  DIM       3     1918  Procedure used for grouping edits
XDRGSR40  DIM       3     1921  Procedure used for grouping edits
XDRGSR41  DIM       3     1924  Procedure used for grouping edits
XDRGSR42  DIM       3     1927  Procedure used for grouping edits
XDRGSR43  DIM       3     1930  Procedure used for grouping edits
XDRGSR44  DIM       3     1933  Procedure used for grouping edits
XDRGSR45  DIM       3     1936  Procedure used for grouping edits
XDRGSR46  DIM       3     1939  Procedure used for grouping edits
XDRGSR47  DIM       3     1942  Procedure used for grouping edits
XDRGSR48  DIM       3     1945  Procedure used for grouping edits
XDRGSR49  DIM       3     1948  Procedure used for grouping edits
XDRGSR50  DIM       3     1951  Procedure used for grouping edits
XDRGSR51  DIM       3     1954  Procedure used for grouping edits
XDRGSR52  DIM       3     1957  Procedure used for grouping edits
XDRGSR53  DIM       3     1960  Procedure used for grouping edits
XDRGSR54  DIM       3     1963  Procedure used for grouping edits
XDRGSR55  DIM       3     1966  Procedure used for grouping edits
XDRGSR56  DIM       3     1969  Procedure used for grouping edits
XDRGSR57  DIM       3     1972  Procedure used for grouping edits
XDRGSR58  DIM       3     1975  Procedure used for grouping edits
XDRGSR59  DIM       3     1978  Procedure used for grouping edits
XDRGSR60  DIM       3     1981  Procedure used for grouping edits
XDRGSR61  DIM       3     1984  Procedure used for grouping edits
XDRGSR62  DIM       3     1987  Procedure used for grouping edits
XDRGSR63  DIM       3     1990  Procedure used for grouping edits
XDRGSR64  DIM       3     1993  Procedure used for grouping edits
XDRGSR65  DIM       3     1996  Procedure used for grouping edits
XDRGSR66  DIM       3     1999  Procedure used for grouping edits
XDRGSR67  DIM       3     2002  Procedure used for grouping edits
XDRGSR68  DIM       3     2005  Procedure used for grouping edits
XDRGSR69  DIM       3     2008  Procedure used for grouping edits
XDRGSR70  DIM       3     2011  Procedure used for grouping edits
XDRGSR71  DIM       3     2014  Procedure used for grouping edits
XDRGSR72  DIM       3     2017  Procedure used for grouping edits
XDRGSR73  DIM       3     2020  Procedure used for grouping edits
XDRGSR74  DIM       3     2023  Procedure used for grouping edits
XDRGSR75  DIM       3     2026  Procedure used for grouping edits
XDRGSR76  DIM       3     2029  Procedure used for grouping edits
XDRGSR77  DIM       3     2032  Procedure used for grouping edits
XDRGSR78  DIM       3     2035  Procedure used for grouping edits
XDRGSR79  DIM       3     2038  Procedure used for grouping edits
XDRGSR80  DIM       3     2041  Procedure used for grouping edits
XDRGSR81  DIM       3     2044  Procedure used for grouping edits
XDRGSR82  DIM       3     2047  Procedure used for grouping edits
XDRGSR83  DIM       3     2050  Procedure used for grouping edits
XDRGSR84  DIM       3     2053  Procedure used for grouping edits
XDRGSR85  DIM       3     2056  Procedure used for grouping edits
XDRGSR86  DIM       3     2059  Procedure used for grouping edits
XDRGSR87  DIM       3     2062  Procedure used for grouping edits
XDRGSR88  DIM       3     2065  Procedure used for grouping edits
XDRGSR89  DIM       3     2068  Procedure used for grouping edits
XDRGSR90  DIM       3     2071  Procedure used for grouping edits
XDRGSR91  DIM       3     2074  Procedure used for grouping edits
XDRGSR92  DIM       3     2077  Procedure used for grouping edits
XDRGSR93  DIM       3     2080  Procedure used for grouping edits
XDRGSR94  DIM       3     2083  Procedure used for grouping edits
XDRGSR95  DIM       3     2086  Procedure used for grouping edits
XDRGSR96  DIM       3     2089  Procedure used for grouping edits
XDRGSR97  DIM       3     2092  Procedure used for grouping edits
XDRGSR98  DIM       3     2095  Procedure used for grouping edits
XDRGSR99  DIM       3     2098  Procedure used for grouping edits
XDRGS100  DIM       3     2101  Procedure used for grouping edits
.XDRGGSC  DIM       2     2104  Grouper status code
.XDRGCCL  DIM       1     2106  Clinical Complexity class level
XDRGCLOS  DIM       5     2107  System Calculated length of Stay       
XDRGCAGD  DIM       3     2112  System Calculated Age in Days          
XDRGCAGY  DIM       3     2115  System Calculated Age in Years         
XDRGCBWT  DIM       4     2118  System Calculated Birth Weight         
XDRGCSDF  DIM       1     2122  System Calculated Same Day Field       
XDRGCMHL  DIM       1     2123  System Calculated M. Healt. Leg.Status 
XDRGULOS  DIM       5     2124  Used Length of Stay                    
XDRGUAGD  DIM       3     2129  Used Age in Days                       
XDRGUAGY  DIM       3     2132  Used Age in Years                      
XDRGUBWT  DIM       4     2135  Used Birth Weight                      
XDRGUSDF  DIM       1     2139  Used Same Day Field                    
XDRGUMHL  DIM       1     2140  Used M. Healt. Leg.Status              
.XDRGECRW DIM      11     2141  ECCS RAW Format
XDRGCHSC  DIM       2     2152  Charlson Score
XDRGCF01  DIM       1     2154  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF02  DIM       1     2155  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF03  DIM       1     2156  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF04  DIM       1     2157  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF05  DIM       1     2158  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF06  DIM       1     2159  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF07  DIM       1     2160  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF08  DIM       1     2161  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF09  DIM       1     2162  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF10  DIM       1     2163  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF11  DIM       1     2164  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF12  DIM       1     2165  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF13  DIM       1     2166  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF14  DIM       1     2167  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF15  DIM       1     2168  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF16  DIM       1     2169  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF17  DIM       1     2170  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF18  DIM       1     2171  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF19  DIM       1     2172  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF20  DIM       1     2173  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF21  DIM       1     2174  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF22  DIM       1     2175  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF23  DIM       1     2176  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF24  DIM       1     2177  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF25  DIM       1     2178  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF26  DIM       1     2179  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF27  DIM       1     2180  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF28  DIM       1     2181  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF29  DIM       1     2182  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF30  DIM       1     2183  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF31  DIM       1     2184  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF32  DIM       1     2185  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF33  DIM       1     2186  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF34  DIM       1     2187  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF35  DIM       1     2188  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF36  DIM       1     2189  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF37  DIM       1     2190  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF38  DIM       1     2191  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF39  DIM       1     2192  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF40  DIM       1     2193  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF41  DIM       1     2194  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF42  DIM       1     2195  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF43  DIM       1     2196  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF44  DIM       1     2197  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF45  DIM       1     2198  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF46  DIM       1     2199  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF47  DIM       1     2200  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF48  DIM       1     2201  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF49  DIM       1     2202  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF50  DIM       1     2203  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF51  DIM       1     2204  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF52  DIM       1     2205  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF53  DIM       1     2206  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF54  DIM       1     2207  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF55  DIM       1     2208  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF56  DIM       1     2209  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF57  DIM       1     2210  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF58  DIM       1     2211  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF59  DIM       1     2212  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF60  DIM       1     2213  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF61  DIM       1     2214  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF62  DIM       1     2215  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF63  DIM       1     2216  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF64  DIM       1     2217  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF65  DIM       1     2218  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF66  DIM       1     2219  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF67  DIM       1     2220  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF68  DIM       1     2221  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF69  DIM       1     2222  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF70  DIM       1     2223  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF71  DIM       1     2224  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF72  DIM       1     2225  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF73  DIM       1     2226  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF74  DIM       1     2227  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF75  DIM       1     2228  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF76  DIM       1     2229  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF77  DIM       1     2230  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF78  DIM       1     2231  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF79  DIM       1     2232  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF80  DIM       1     2233  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF81  DIM       1     2234  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF82  DIM       1     2235  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF83  DIM       1     2236  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF84  DIM       1     2237  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF85  DIM       1     2238  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF86  DIM       1     2239  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF87  DIM       1     2240  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF88  DIM       1     2241  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF89  DIM       1     2242  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF90  DIM       1     2243  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF91  DIM       1     2244  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF92  DIM       1     2245  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF93  DIM       1     2246  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF94  DIM       1     2247  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF95  DIM       1     2248  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF96  DIM       1     2249  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF97  DIM       1     2250  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF98  DIM       1     2251  Diagnosis Complexity Flag for grouper >= v11.0
XDRGCF99  DIM       1     2252  Diagnosis Complexity Flag for grouper >= v11.0
XDRGC100  DIM       1     2253  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGVERS DIM       3     2254  Grouper Version
.
.End of Record            2257  Non-NWAU Output File
.
.************************************************************************
.                  Unix Grouper Output File Variables (NWAU)
.************************************************************************
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
.XDRGSTAT  DIM       1       1   State Code
....
. same format as non-NWAU apart from XDRGNWAU:
....
.XDRGECRW DIM      11     2141  ECCS RAW Format
.XDRGNWAU DIM      11     2152  Total NWAU for unix grouper (11 Characters)
.XDRGCHSC DIM       2     2163  Charlson Score
.XDRGCF01 DIM       1     2165  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF02 DIM       1     2166  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF03 DIM       1     2167  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF04 DIM       1     2168  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF05 DIM       1     2169  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF06 DIM       1     2170  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF07 DIM       1     2171  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF08 DIM       1     2172  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF09 DIM       1     2173  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF10 DIM       1     2174  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF11 DIM       1     2175  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF12 DIM       1     2176  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF13 DIM       1     2177  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF14 DIM       1     2178  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF15 DIM       1     2179  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF16 DIM       1     2180  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF17 DIM       1     2181  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF18 DIM       1     2182  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF19 DIM       1     2183  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF20 DIM       1     2184  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF21 DIM       1     2185  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF22 DIM       1     2186  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF23 DIM       1     2187  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF24 DIM       1     2188  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF25 DIM       1     2189  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF26 DIM       1     2190  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF27 DIM       1     2191  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF28 DIM       1     2192  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF29 DIM       1     2193  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF30 DIM       1     2194  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF31 DIM       1     2195  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF32 DIM       1     2196  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF33 DIM       1     2197  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF34 DIM       1     2198  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF35 DIM       1     2199  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF36 DIM       1     2200  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF37 DIM       1     2201  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF38 DIM       1     2202  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF39 DIM       1     2203  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF40 DIM       1     2204  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF41 DIM       1     2205  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF42 DIM       1     2206  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF43 DIM       1     2207  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF44 DIM       1     2208  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF45 DIM       1     2209  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF46 DIM       1     2210  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF47 DIM       1     2211  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF48 DIM       1     2212  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF49 DIM       1     2213  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF50 DIM       1     2214  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF51 DIM       1     2215  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF52 DIM       1     2216  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF53 DIM       1     2217  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF54 DIM       1     2218  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF55 DIM       1     2219  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF56 DIM       1     2220  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF57 DIM       1     2221  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF58 DIM       1     2222  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF59 DIM       1     2223  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF60 DIM       1     2224  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF61 DIM       1     2225  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF62 DIM       1     2226  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF63 DIM       1     2227  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF64 DIM       1     2228  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF65 DIM       1     2229  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF66 DIM       1     2230  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF67 DIM       1     2231  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF68 DIM       1     2232  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF69 DIM       1     2233  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF70 DIM       1     2234  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF71 DIM       1     2235  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF72 DIM       1     2236  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF73 DIM       1     2237  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF74 DIM       1     2238  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF75 DIM       1     2239  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF76 DIM       1     2240  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF77 DIM       1     2241  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF78 DIM       1     2242  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF79 DIM       1     2243  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF80 DIM       1     2244  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF81 DIM       1     2245  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF82 DIM       1     2246  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF83 DIM       1     2247  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF84 DIM       1     2248  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF85 DIM       1     2249  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF86 DIM       1     2250  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF87 DIM       1     2251  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF88 DIM       1     2252  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF89 DIM       1     2253  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF90 DIM       1     2254  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF91 DIM       1     2255  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF92 DIM       1     2256  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF93 DIM       1     2257  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF94 DIM       1     2258  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF95 DIM       1     2259  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF96 DIM       1     2260  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF97 DIM       1     2261  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF98 DIM       1     2262  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGCF99 DIM       1     2263  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGC100 DIM       1     2264  Diagnosis Complexity Flag for grouper >= v11.0
.XDRGVERS DIM       3     2265  Grouper Version
.
.End of Record            2268  NWAU Output File
.
...
...XDRGMD01  DIM       5     466   Mapped diagnosis 1
...XDRGMD02  DIM       5     471   Mapped diagnosis 2
...XDRGMD03  DIM       5     476   Mapped diagnosis 3
...XDRGMD04  DIM       5     481   Mapped diagnosis 4
...XDRGMD05  DIM       5     486   Mapped diagnosis 5
...XDRGMD06  DIM       5     491   Mapped diagnosis 6
...XDRGMD07  DIM       5     496   Mapped diagnosis 7
...XDRGMD08  DIM       5     501   Mapped diagnosis 8
...XDRGMD09  DIM       5     506   Mapped diagnosis 9
...XDRGMD10  DIM       5     511   Mapped diagnosis 10
...XDRGMD11  DIM       5     516   Mapped diagnosis 11
...XDRGMD12  DIM       5     521   Mapped diagnosis 12
...XDRGMD13  DIM       5     526   Mapped diagnosis 13
...XDRGMD14  DIM       5     531   Mapped diagnosis 14
...XDRGMD15  DIM       5     536   Mapped diagnosis 15
...XDRGMD16  DIM       5     541   Mapped diagnosis 16
...XDRGMD17  DIM       5     546   Mapped diagnosis 17
...XDRGMD18  DIM       5     551   Mapped diagnosis 18
...XDRGMD19  DIM       5     556   Mapped diagnosis 19
...XDRGMD20  DIM       5     561   Mapped diagnosis 20
...XDRGMP01  DIM       7     566   Mapped operation code 1
...XDRGMP02  DIM       7     573   Mapped operation code 2
...XDRGMP03  DIM       7     580   Mapped operation code 3
...XDRGMP04  DIM       7     587   Mapped operation code 4
...XDRGMP05  DIM       7     594   Mapped operation code 5
...XDRGMP06  DIM       7     601   Mapped operation code 6
...XDRGMP07  DIM       7     608   Mapped operation code 7
...XDRGMP08  DIM       7     615   Mapped operation code 8
...XDRGMP09  DIM       7     622   Mapped operation code 9
...XDRGMP10  DIM       7     629   Mapped operation code 10
...XDRGMP11  DIM       7     636   Mapped operation code 11
...XDRGMP12  DIM       7     643   Mapped operation code 12
...XDRGMP13  DIM       7     650   Mapped operation code 13
...XDRGMP14  DIM       7     657   Mapped operation code 14
...XDRGMP15  DIM       7     664   Mapped operation code 15
...XDRGMP16  DIM       7     671   Mapped operation code 16
...XDRGMP17  DIM       7     678   Mapped operation code 17
...XDRGMP18  DIM       7     685   Mapped operation code 18
...XDRGMP19  DIM       7     692   Mapped operation code 19
...XDRGMP20  DIM       7     699   Mapped operation code 20
...                                                                    *D-50344
...End of Record            706                                        *D-50344
.
.
.************************************************************************
.                Codefinder DRG Output File Variables
.************************************************************************
.Name     Type   Length  Start  Description
.-------  -----  ------  -----  --------------------------------------
.XDRGGRP   DIM       3           Grouper version used
.XDRGDRG   DIM       4           Diagnostic Related Group (DRG)
.XDRGDRGD  DIM       72          DRG description
.XDRGMDC   DIM       2           Major Diagnostic Category (MDC)
.XDRGMDCD  DIM       73          MDC description
.XDRGCCL   DIM       1           CC class level
.XDRGGSC   DIM       2           Grouper status code
.XDRGNWT   DIM       9           DRG national weight
.XDRGNALS  DIM       7           DRG national average LOS
.XDRGSWT   DIM       9           DRG state weight
.XDRGSALS  DIM       7           DRG state average LOS
.XDRGLWT   DIM       9           DRG local weight
.XDRGLALS  DIM       7           DRG local average LOS
.
.
. ----- Include Variables -----
.
.                               * This is actually the Grouper version
.                               * and is the last 3 digits of XDRGCTRV.
.                               * It changed to 5 digits with
.                               * the new CME. It gets extracted later.
XDRGGRP   DIM       3           * Grouper version used                 *C-50344
XDRGURGA  DIM       1           * DRG Urgency of Admission
.
XDRGAMOD  DIM       1           * Admission mode
XDRGATSI  DIM       1           * Aboriginal Torres Straight Islander
XDRGCTYP  DIM       2           * Care Type
XDRGCCTY  DIM       2           * Care Type - Codefinder input
XDRGATYP  DIM       2           * Admit Type - NZ - Codefinder input
XDRGFNDS  DIM       2           * Funding source
XDRGICUH  DIM       4           * Hours in ICU
XDRGPCDY  DIM       4           * PC Days
XDRGPCOD  DIM       4           * Post Code
XDRGUROR  DIM       1           * Unplanned return to theatre
XDRGTOTN  FORM      12.4        * Total NWAU
XDRGNWAU  DIM       11          * Total NWAU for unix grouper (11 Characters)
XDRGQDAY  DIM       3           * Total qualified baby days
XDRGPDAY  DIM       4           * Total psyciatric care days
UNIXNWAU  FORM      1           * Unix grouper export and import NWAU fields
.
AUTHCODE  INIT      "kW3qhvk06hZiIEID"      * CSC's Authrization code
AUTHFLAG  FORM      1                       * Authorization code matches CSC's? 
DCIDVALS  INIT      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
BYPASSRD  FORM      1
CODECNT   FORM      3
CODELINE  DIM       250                                               *I-190768
DATA150B  DIM       250
ICDCDESC  DIM       200                     * Code description        *I-190768
CCCLASS   DIM       1                       * CC Class Level (for ARCL:)
CONTCARF  DIM       2                       * Contract care flag for ICD Coding
DACCDATE  DIM       8                       * Accident Date (for Disease Coding)
DIAGDCID  DIM       2                       * Diagnosis cluster id
.
DOUT31    DIM       8                       * 3.1 output filename
DOUT41    DIM       8                       * 4.1 output filename
DOUT42    DIM       8                       * 4.2 output filename
DOUT50    DIM       8                       * 5.0 output filename      
DOUT51    DIM       8                       * 5.1 output filename      *I-61562
DOUT52    DIM       8                       * 5.2 output filename     *I-137125
DOUT60    DIM       8                       * 6.0 output filename     *I-197814
DOUT62    DIM       8                       * 6.2 output filename     *I-267797
DOUT70    DIM       8                       * 7.0 output filename     *I-284669
DOUT80    DIM       8                       * 8.0 output filename
DOUT90    DIM       8                       * 9.0 output filename
DOUT100   DIM       8                       * 10.0 output filename
DOUT110   DIM       8                       * 11.0 output filename
DOUT120   DIM       8                       * 12.0 output filename
.
.                                      * moved from programs - start  *I-197814
DRGFLNAM  DIM       12      * used for standard routine LODGXX00
DRGO41FN  DIM       12      * DRG 4.1 Batch file name
DRGO42FN  DIM       12      * DRG 4.2 Batch file name
DRGO50FN  DIM       12      * DRG 5.0 Batch file name
DRGO51FN  DIM       12      * DRG 5.1 Batch file name
DRGO52FN  DIM       12      * DRG 5.2 Batch file name
DRGO60FN  DIM       12      * DRG 6.0 Batch file name                 *I-197814
DRGO62FN  DIM       12      * DRG 6.2 Batch file name                 *I-267797
DRGO70FN  DIM       12      * DRG 7.0 Batch file name                 *I-284669
DRGO80FN  DIM       12      * DRG 8.0 Batch file name
DRGO90FN  DIM       12      * DRG 9.0 Batch file name
DRG100FN  DIM       12      * DRG 10.0 Batch file name
DRG110FN  DIM       12      * DRG 11.0 Batch file name
DRG120FN  DIM       12      * DRG 12.0 Batch file name
.
DRG041    INIT      "041"
DRG042    INIT      "042"
DRG050    INIT      "050"
DRG051    INIT      "051"
DRG052    INIT      "052"
DRG060    INIT      "060"                                             *I-197814
DRG062    INIT      "062"                                             *I-267797
DRG070    INIT      "070"                                             *I-284669
DRG080    INIT      "080"
DRG090    INIT      "090"
DRG100    INIT      "100"
DRG110    INIT      "110"
DRG120    INIT      "120"
.                                      * moved from programs - end    *I-197814
.
DRGIND    DIM       1                       * "DRG Driver in use" Indicator
DTXTEXT   DIM       100                     * 
DTXDATA   DIM       15
ENCSTDAT  DIM       8                       * from ADATE or Episode Start Date
ENCENDAT  DIM       8                       * from DDATE or Episode End Date
ENCSTTIM  DIM       8
ENCENTIM  DIM       8
ENCDTYPE  DIM       1                       * CodeFinder Disease Prefix DISTYPE
..
EPSTTDAT  DIM       8       * selected Episode Start Date - Date format
EPENDDAT  DIM       8       * selected Episode End Date   - Date format
EPSTTDIS  DIM       15      * selected Episode Start Date - Display format
EPENDDIS  DIM       15      * selected Episode End Date   - Display format
EPSTTTIM  DIM       8       * selected Episode Start Time
EPENDTIM  DIM       8       * selected Episode End Time
CARETYPE  DIM       3       
EPNODAYS  DIM       20      
EPSNOLOS  FORM      4       
ADNODAYS  FORM      4
ADATEDIS  DIM       11
DDATEDIS  DIM       11
..
FILRFGRP  FORM      1                       * File returned from grouper flag
FMTTXNO   FORM      2                       * FMT: texts count
FMTTEXT   DIM       30[10]                  * FMT: texts returned 
FMTLINE   DIM       100
FMTWORK   DIM       15[10]
GRPDTE    DIM       8                       * Grouper date
GRPSWICH  DIM       1                       * CPDATS00 switch
DRGVERS   DIM       3
DFLTVFLG  FORM      1                       * Default Grouper version flag
USENZWIS  FORM      1                       * Use NZ WIES tags from Codefinder
OPENFLG   FORM      2                       * grouper version output file
ONSETIND  DIM       1                       * Onset Ind. returned from CodeFindr
RUNGRP    FORM      1                       * Run grouper on this machine flag
PASSNUM   FORM      1
PLACE2    DIM       2                       * 2 digit place holder     
PLACE3    DIM       3                       * 3 digit place holder
PROCDATE  DIM       8                       * Procedure date
PHYSTEXT  DIM       35                      * Physician text
WAHEALTH  FORM      1                       * Flag to bypass Oper.Dates
SETCLACC  FORM      1                       * Indicator to set call to CLRACC00
.
FPTR      FORM      3
LPTR      FORM      3
F1B       FORM      1
TOTWISCF  FORM      12.4                    * WIES Total (for Codefinder WIES)
FORM84    FORM      8.4
FORM64    FORM      6.4
FORM42    FORM      4.2
FORM124   FORM      12.4
ENCRNWGT  DIM       11
ENCRNLOS  DIM       7
SYSTGVAL  DIM       3                       * 3M Codefinder System Value
CFPAYCOD  DIM       3                       * 3M Codefinder PAY Code
WEBCODER  FORM      "0"                     * initiate web Codefinder? (1=yes)
VALDDCID  DIM       2                       * Cluster ID to validate
+
.
TURBOCMD  DIM       1                       * TurboGrouper command
TURBOSAV  FORM      1                       * Retain previous details
TURBFTIM  DIM       11                      * TurboGrouper file time hhmmssuu
TURBODRG  DIM       3                       * Temp TurboGrouper DRG field
.
. Export TurboGrouper Fields
.
TURBOFL1  FILE      ASCII, FIXED=4096       * TurboGrouper export file
.
.Name     Type   Length  Description
.-------  -----  ------  --------------------------------------
XTRB0001  DIM       10   Interface ID
XTRB0002  DIM       3    Interface Version
XTRB0003  DIM       9    PAS Version
XTRB0004  DIM       8    Episode ID
XTRB0005  DIM       1    TurboGrouper Command
XTRB0006  DIM       1    PAS Command
XTRB0007  DIM       4    Hospital Campus Code
XTRB0008  DIM       1    State Identifier
XTRB0009  DIM       1    Establishment Identifier
XTRB0010  DIM       1    SA2  of Hospital
XTRB0011  DIM       1    SLA  of Hospital
XTRB0012  DIM       4    Postcode of Hospital
XTRB0013  DIM       1    Remoteness of Hospital
XTRB0014  DIM       8    Patient ID
XTRB0015  DIM       20   Family Name
XTRB0016  DIM       25   Given Names
XTRB0017  DIM       10   Date of Birth
XTRB0018  DIM       1    Sex
XTRB0019  DIM       1    Indigenous Status
XTRB0020  DIM       1    SA2  of Patient's Usual Residence
XTRB0021  DIM       1    SLA  of Patient's Usual Residence
XTRB0022  DIM       4    Postcode of Patient's Usual Residence
XTRB0023  DIM       1    Remoteness of Patient's Usual Residence
XTRB0024  DIM       2    Care Type
XTRB0025  DIM       1    Age in Years
XTRB0026  DIM       1    Age in Days
XTRB0027  DIM       6    Admission Weight
XTRB0028  DIM       10   Admission Date
XTRB0029  DIM       10   Separation Date
XTRB0030  DIM       4    Leave Days
XTRB0031  DIM       1    Length of Stay
XTRB0032  DIM       1    Non-acceptable Length of Stay
XTRB0033  DIM       1    HITH  Days
XTRB0034  DIM       5    Psychiatric Care Days
XTRB0035  DIM       5    Qualified Days for Newborns
XTRB0036  DIM       5    Mechanical Ventilation Hours
XTRB0037  DIM       5    Intensive Care Unit Hours
XTRB0038  DIM       1    Mental Health Legal Status
XTRB0039  DIM       1    Urgency of Admission
XTRB0040  DIM       1    Same Day Status
XTRB0041  DIM       1    Short Stay Status
XTRB0042  DIM       1    Separation Mode
XTRB0043  DIM       2    Funding Source
XTRB0044  DIM       2    ICD-10-AM Edition
.
XTRB0045  DIM       9    ICD-10-AM principal diagnosis
XTRB45SV  DIM       9    ICD-10-AM Save orig. principal diag (Not exported)
XTRB45CI  DIM       10   ICD-10-AM Save orig. principal diag Coder(Not exported)
.
XTRB46XX  DIM       9[200]  ICD-10-AM secondary diags/morph codes 1 to 200
XTRB47XX  DIM       1[200]  COF 1 to 200
XTRB48XX  DIM       10[200] Diagnosis dates 1 to 200
XTRB48AD  DIM       8[200]  Accident date 1 to 200 (Not exported)
XTRB0049  DIM       1       ACHI Edition
.
XTRB50XX  DIM       9[200]  ACHI intervention codes 1 to 200
XTRB51XX  DIM       16[200] Intervention dates 1 to 200
XTRB51CL  DIM       10[200] Intervention Clinician (Not exported)
.
XTRB0052  DIM       1    TurboGrouper Version
XTRB0053  DIM       4    AR-DRG Version
XTRB0054  DIM       4    AR-DRG
XTRB0055  DIM       4    VIC-DRG Version
XTRB0056  DIM       4    VIC-DRG
XTRB0057  DIM       4    MDC
XTRB0058  DIM       1    GAGE
XTRB0059  DIM       1    GSEX
XTRB0060  DIM       1    GLOS
XTRB0061  DIM       1    GSDF
XTRB0062  DIM       1    GSEP
XTRB0063  DIM       1    GADMW
XTRB0064  DIM       1    GHMV
XTRB0065  DIM       1    GMHLS
XTRB0066  DIM       1    GURGADM
XTRB0067  DIM       1    GPDX
XTRB68XX  DIM       3[200]   GDX  1 to 200
XTRB69XX  DIM       3[200]   GSRG 1 to 200
XTRB0070  DIM       1    GST
XTRB0071  DIM       1    PCCL
XTRB0072  DIM       1    CLOS
XTRB0073  DIM       1    CAGED
XTRB0074  DIM       1    CAGEY
XTRB0075  DIM       1    CADMW
XTRB0076  DIM       1    CSDF
XTRB0077  DIM       1    CMHLS
XTRB0078  DIM       1    CURGADM
XTRB0079  DIM       1    ULOS
XTRB0080  DIM       1    UAGED
XTRB0081  DIM       1    UAGEY
XTRB0082  DIM       1    UADMW
XTRB0083  DIM       1    USDF
XTRB0084  DIM       1    UMHLS
XTRB0085  DIM       1    UURGADM
XTRB0086  DIM       11   ECCS_RAW
XTRB0087  DIM       1    ECCS_RND
XTRB0088  DIM       1    NWAU Version
XTRB0089  DIM       1    NWAU Status
XTRB0090  DIM      17    NWAU Total
XTRB0091  DIM       1    NWAU Price
XTRB0092  DIM       1    NWAU Funding
XTRB0093  DIM       1    WIES Version
XTRB0094  DIM       1    WIES Status
XTRB0095  DIM       1    WIES Total
XTRB0096  DIM       1    WIES Price
XTRB0097  DIM       1    WIES Funding
XTRB0098  DIM       1    Non-invasive Ventilation Hours
XTRB0099  DIM       1    Coronary Care Unit Hours
XTRB0100  DIM       1    Admission Mode
XTRB0101  DIM       1    Unplanned Theatre
XTRB0102  DIM       1    Unplanned Intensive Care Unit
XTRB0103  DIM       1    Diagnosis finish dates 1 to 200
XTRB104X  DIM       16[200] Interventionfinish  dates 1 to 200
XTRB105X  DIM       1[200]  Intervention flags 1 to 200
XTRB0106  DIM       19   PAS Export Date/Time
XTRB0107  DIM       10   PAS User ID
XTRB0108  DIM       80   PAS User Name
XTRB109X  DIM       10[200]  Diagnosis Coder ID X 200
XTRB110X  DIM       80[200]  Diagnosis Coder Name X 200
XTRB111X  DIM       16[200]  Diagnosis Coder Date X 200
XTRB112X  DIM       10[200]  Procedure Coder ID X 200
XTRB113X  DIM       80[200]  Procedure Coder Name X 200
XTRB114X  DIM       16[200]  Procedure Coder Date X 200
XTRB0115  DIM       1    Not used - Diagnosis Row ID X 200
XTRB0116  DIM       1    Not used - Intervention Row ID X 200
XTRB0117  DIM       6    Health Fund ID
XTRB0118  DIM       40   Health Fund Name
XTRB0119  DIM       4    Health Fund AR-DRG Version
XTRB0120  DIM       1    Contract Days
XTRB0121  DIM       1    NWAU Base
XTRB0122  DIM       1    Admission COunt
XTRB0123  DIM       1    AHR Index Episode ID
XTRB0124  DIM       1    NWAU AHR Category
XTRB0125  DIM       1    NWAU AHR Complexity
XTRB0126  DIM       1    Reasmission Episode ID List
XTRB0127  DIM       1    Readmission NWAU Base List
XTRB0128  DIM       1    Readmission NWAU AHR Category List
XTRB0129  DIM       1    Readmission NWAU AHR Complexity List
XTRB0130  DIM       1    HAC Version
XTRB0131  DIM       1    AHR Version
XTRB0132  DIM       1    ABF Type
XTRB0133  DIM       1    CCHI Version
XTRB0134  DIM       1    CCHI Tier
XTRB0135  DIM       1    CCHI Status
XTRB0136  DIM       1    CCHI Total
XTRB0137  DIM       1    CCHI Price
XTRB0138  DIM       1    CCHI Funding
XTRB0139  DIM       1    Gender
XTRB0140  DIM       1    NWAU Length of Stay (Average)
XTRB0141  DIM       1    NWAU Length of Stay (Low)
XTRB0142  DIM       1    NWAU Length of Stay (High)
XTRB0143  DIM       1    NWAU Length of Stay (Adjusted)
XTRB0144  DIM       1    WIES Length of Stay(Average)
XTRB0145  DIM       1    WIES Length of Stay(Low)
XTRB0146  DIM       1    WIES Length of Stay(High)
XTRB0147  DIM       2    Charlson Score
.
XTRB0148  DIM       1    Diagnosis Alert X 200
XTRB0149  DIM       1    Intervention Alert X 200
XTRB0150  DIM       1    Alert List
XTRB0151  DIM       1    Alert Severity
XTRB0152  DIM       1    Alert Score
XTRB0153  DIM       1    Alert Reference
XTRB154X  DIM       2[200]  Diagnosis Cluster X 200
XTRB0155  DIM       1    Intervention Cluster X 200 
.
TABDELIM  INIT      011                     * TAB character (Octal)
.
. Import TurboGrouper Fields
.
TURBOFL2  FILE      HL7, FIXED=4096         * TurboGrouper import file
.
.         Fields must be pipe delimited and in the following sequence.
.         Field lengths are irrelevant other than the fact that where
.         a field is longer than allowed, the extra data will be ignored.
.
.Name     Type   Length  Description
.-------  -----  ------  --------------------------------------
.XTRB0001 DIM       10   Interface ID
.XTRB0002 DIM       3    Interface Version
.XTRB0003 DIM       1    PAS Version
.XTRB0004 DIM       8    Episode ID
.XTRB0005 DIM       1    TurboGrouper Command
.XTRB0006 DIM       1    PAS Command
.XTRB0007 DIM       1    Hospital Campus Code
.XTRB0008 DIM       1    State Identifier
.XTRB0009 DIM       1    Establishment Identifier
.XTRB0010 DIM       1    SA2  of Hospital
.XTRB0011 DIM       1    SLA  of Hospital
.XTRB0012 DIM       4    Postcode of Hospital
.XTRB0013 DIM       1    Remoteness of Hospital
.XTRB0014 DIM       8    Patient ID
.XTRB0015 DIM       20   Family Name
.XTRB0016 DIM       25   Given Names
.XTRB0017 DIM       10   Date of Birth
.XTRB0018 DIM       1    Sex
.XTRB0019 DIM       1    Indigenous Status
.XTRB0020 DIM       1    SA2  of Patient's Usual Residence
.XTRB0021 DIM       1    SLA  of Patient's Usual Residence
.XTRB0022 DIM       1    Postcode of Patient's Usual Residence
.XTRB0023 DIM       1    Remoteness of Patient's Usual Residence
.XTRB0024 DIM       2    Care Type
.XTRB0025 DIM       1    Age in Years
.XTRB0026 DIM       1    Age in Days
.XTRB0027 DIM       6    Admission Weight
.XTRB0028 DIM       10   Admission Date
.XTRB0029 DIM       10   Separation Date
.XTRB0030 DIM       1    Leave Days
.XTRB0031 DIM       1    Length of Stay
.XTRB0032 DIM       1    Non-acceptable Length of Stay
.XTRB0033 DIM       1    HITH  Days
.XTRB0034 DIM       1    Psychiatric Care Days
.XTRB0035 DIM       1    Qualified Days for Newborns
.XTRB0036 DIM       5    Mechanical Ventilation Hours
.XTRB0037 DIM       5    Intensive Care Unit Hours
.XTRB0038 DIM       1    Mental Health Legal Status
.XTRB0039 DIM       1    Urgency of Admission
.XTRB0040 DIM       1    Same Day Status
.XTRB0041 DIM       1    Short Stay Status
.XTRB0042 DIM       1    Separation Mode
.XTRB0043 DIM       2    Funding Source
.XTRB0044 DIM       2    ICD-10-AM Edition
.XTRB0045 DIM       9    ICD-10-AM principal diagnosis
XTRB46AA  DIM       2250 ICD-10-AM secondary diags/morph codes (X 200)
XTRB47AA  DIM       450  COF (X 200)
XTRB48AA  DIM       2250 Diagnosis date (X 200)
.XTRB0049 DIM       1    ACHI Edition
XTRB50AA  DIM       2250 ACHI intervention code (X 200)
XTRB51AA  DIM       3450 Intervention date start time(X 200)
.XTRB0052 DIM       1    TurboGrouper Version
.XTRB0053 DIM       3    AR-DRG Version
.XTRB0054 DIM       4    AR-DRG
.XTRB0055 DIM       4    VIC-DRG Version
.XTRB0056 DIM       4    VIC-DRG
.XTRB0057 DIM       4    MDC
.XTRB0058 DIM       1    GAGE
.XTRB0059 DIM       1    GSEX
.XTRB0060 DIM       1    GLOS
.XTRB0061 DIM       1    GSDF
.XTRB0062 DIM       1    GSEP
.XTRB0063 DIM       1    GADMW
.XTRB0064 DIM       1    GHMV
.XTRB0065 DIM       1    GMHLS
.XTRB0066 DIM       1    GURGADM
.XTRB0067 DIM       1    GPDX
XTRB68AA  DIM       850  GDX  (X 200)
XTRB69AA  DIM       850  GSRG (X 200)
.XTRB0070 DIM       1    GST
.XTRB0071 DIM       1    PCCL
.XTRB0072 DIM       1    CLOS
.XTRB0073 DIM       1    CAGED
.XTRB0074 DIM       1    CAGEY
.XTRB0075 DIM       1    CADMW
.XTRB0076 DIM       1    CSDF
.XTRB0077 DIM       1    CMHLS
.XTRB0078 DIM       1    CURGADM
.XTRB0079 DIM       1    ULOS
.XTRB0080 DIM       1    UAGED
.XTRB0081 DIM       1    UAGEY
.XTRB0082 DIM       1    UADMW
.XTRB0083 DIM       1    USDF
.XTRB0084 DIM       1    UMHLS
.XTRB0085 DIM       1    UURGADM
.XTRB0086 DIM       11   ECCS_RAW
.XTRB0087 DIM       1    ECCS_RND
.XTRB0088 DIM       1    NWAU Version
.XTRB0089 DIM       1    NWAU Status
.XTRB0090 DIM       17   NWAU Total
.XTRB0091 DIM       1    NWAU Price
.XTRB0092 DIM       1    NWAU Funding
.XTRB0093 DIM       1    WIES Version
.XTRB0094 DIM       1    WIES Status
.XTRB0095 DIM       1    WIES Total
.XTRB0096 DIM       1    WIES Price
.XTRB0097 DIM       1    WIES Funding
.XTRB0098 DIM       1    Non-invasive Ventilation Hours
.XTRB0099 DIM       1    Coronary Care Unit Hours
.XTRB0100 DIM       1    Admission Mode
.XTRB0101 DIM       1    Unplanned Theatre
.XTRB0102 DIM       1    Unplanned Intensive Care Unit
.XTRB0103 DIM       1    Diagnosis finish dates 1 to 200
XTRB104A  DIM       3450 Intervention finish dates 1 to 200
XTRB105A  DIM       450  Intervention flags 1 to 200
.XTRB0106 DIM       19   PAS Export Date/Time
.XTRB0107 DIM       10   PAS User ID
.XTRB0108 DIM       80   PAS User Name
XTRB109A  DIM       2250  Diagnosis Coder ID X 200
XTRB110A  DIM       1     Diagnosis Coder Name X 200
XTRB111A  DIM       3250  Diagnosis Coder Date X 200
XTRB112A  DIM       2250  Procedure Coder ID X 200
XTRB113A  DIM       1     Procedure Coder Name X 200
XTRB114A  DIM       3250  Procedure Coder Date X 200
.XTRB0115 DIM       1     Not used - Diagnosis Row ID X 200
.XTRB0116 DIM       1     Not used - Intervention Row ID X 200
.XTRB0117 DIM       6     Health Fund ID
.XTRB0118 DIM       40    Health Fund Name
.XTRB0119 DIM       4     Health Fund AR-DRG Version
.XTRB0120  DIM       1    Contract Days
.XTRB0121  DIM       1    NWAU Base
.XTRB0122  DIM       1    Admission COunt
.XTRB0123  DIM       1    AHR Index Episode ID
.XTRB0124  DIM       1    NWAU AHR Category
.XTRB0125  DIM       1    NWAU AHR Complexity
.XTRB0126  DIM       1    Reasmission Episode ID List
.XTRB0127  DIM       1    Readmission NWAU Base List
.XTRB0128  DIM       1    Readmission NWAU AHR Category List
.XTRB0129  DIM       1    Readmission NWAU AHR Complexity List
.XTRB0130  DIM       1    HAC Version
.XTRB0131  DIM       1    AHR Version
.XTRB0132  DIM       1    ABF Type
.XTRB0133  DIM       1    CCHI Version
.XTRB0134  DIM       1    CCHI Tier
.XTRB0135  DIM       1    CCHI Status
.XTRB0136  DIM       1    CCHI Total
.XTRB0137  DIM       1    CCHI Price
.XTRB0138  DIM       1    CCHI Funding
.XTRB0139  DIM       1    Gender
.XTRB0140  DIM       1    NWAU Length of Stay (Average)
.XTRB0141  DIM       1    NWAU Length of Stay (Low)
.XTRB0142  DIM       1    NWAU Length of Stay (High)
.XTRB0143  DIM       1    NWAU Length of Stay (Adjusted)
.XTRB0144  DIM       1    WIES Length of Stay(Average)
.XTRB0145  DIM       1    WIES Length of Stay(Low)
.XTRB0146  DIM       1    WIES Length of Stay(High)
.XTRB0147  DIM       2    Charlson Score
.
.XTRB0148  DIM       1    Diagnosis Alert X 200
.XTRB0149  DIM       1    Intervention Alert X 200
.XTRB0150  DIM       1    Alert List
.XTRB0151  DIM       1    Alert Severity
.XTRB0152  DIM       1    Alert Score
.XTRB0153  DIM       1    Alert Reference
XTRB154A  DIM       650     Diagnosis Cluster X 200
.XTRB0155  DIM       1    Intervention Cluster X 200
.
. Export AMHCC Grouper Fields
.
AMHCCFL1  FILE      ASCII, FIXED=4096       * AMHCC Grouper export file
.
.Name     Type   Length  Description
.-------  -----  ------  --------------------------------------
XAMH0001  DIM       8       1   Admission number
XAMH0002  DIM      10       9   Admission date (dd/mm/ccyy)
XAMH0003  DIM      10      19   Discharge date (dd/mm/ccyy)
XAMH0004  DIM      10      29   Birth date (dd/mm/ccyy)
XAMH0005  DIM       3      39   Age in years (blank)
XAMH0006  DIM       1      42   Age Group (mehhonaf.mhhnhoty Cat hs indc.1)
XAMH0007  DIM       2      43   Care Type (patmi1af.acare Cat CC udf.6)
XAMH0008  DIM       1      45   Admitted Indicator (1=Yes)
XAMH0009  DIM       2      46   Mental Health Phase of Care (Cat hf thcscod)
XAMH0010  DIM       2      48   Mental Health Legal Status (pmvx Cat LS indc.5)
XAMH0011  DIM       1      50   HoNOS Disruptive behaviour (agegrp=1)
XAMH0012  DIM       1      51   HoNOS Non-organic somatic symptoms (agegrp=1)
XAMH0013  DIM       1      52   HoNOS Peer relationships (agegrp=1)
XAMH0014  DIM       1      53   HoNOS Overactivity,Attention,Concentration(ag=1)
XAMH0015  DIM       1      54   HoNOS OveractivityAggressionAgitation(agrp=2,3)
XAMH0016  DIM       1      55   HoNOS NonAccidentalSelfInjury (agegrp=1)
XAMH0017  DIM       1      56   HoNOS NonAccidentalSelfInjury (agegrp=2,3)
XAMH0018  DIM       1      57   HoNOS AlcoholSubstanceSolventMisuse (agegrp=1)
XAMH0019  DIM       1      58   HoNOS ProblemDrinkingOrDrugTaking (agegrp=2,3)
XAMH0020  DIM      10      59   Phase End Date (dd/mm/ccyy)
XAMH0021  DIM       1      69   HoNOS ScholasticOrLanguageSkills (agegrp=1)
XAMH0022  DIM       1      70   HoNOS CognitiveProblems (agegrp=2,3)
XAMH0023  DIM       1      71   HoNOS PhysicalIllnessOrDisabilityProblems(ag=1)
XAMH0024  DIM       1      72   HoNOS PhysicalIllnessOrDisabilityProblems(2,3)
XAMH0025  DIM       1      73   HoNOS HallucinationsDelusions (agegrp=1)
XAMH0026  DIM       1      74   HoNOS HallucinationsDelusions (agegrp=2,3)
XAMH0027  DIM       1      75   HoNOS EmotionalAndRelatedSymptoms (agegrp=1)
XAMH0028  DIM       1      76   HoNOS ProblemsWithDepressedMood (agegrp=2,3)
XAMH0029  DIM       1      77   HoNOS OtherMentalAndBehaviouralProblem (ag=2,3)
XAMH0030  DIM       1      78   HoNOS FamilyLifeAndRelationships (agegrp=1)
XAMH0031  DIM       1      79   HoNOS ProblemsWithRelationships (agegrp=2,3)
XAMH0032  DIM       1      80   HoNOS SelfCareAndIndependence (agegrp=1)
XAMH0033  DIM       1      81   HoNOS ProblemsWithActivitiesOfDailyLiving(2,3)
XAMH0034  DIM       1      82   HoNOS ProblemsWithLivingConditions (agegrp=2,3)
XAMH0035  DIM       1      83   HoNOS PoorSchoolAttendance (agegrp=1)
XAMH0036  DIM       1      84   HoNOS ProblemsWithOccupationAndActivities (2,3)
XAMH0037  DIM      10      85   Phase Start Date (dd/mm/ccyy)
.
.End of Record             95
.
.
. Import AMHCC Grouper Fields
.
AMHCCFL2  FILE      ASCII, FIXED=4096       * AMHCC Grouper import file
.
.Name     Type   Length  Description
.-------  -----  ------  --------------------------------------
XAMHC001  DIM       8       1   RecordID (Visit Number)
XAMHC002  DIM      10       9   EndClass (AMHCC Code)
.
.End of Record             19
+
