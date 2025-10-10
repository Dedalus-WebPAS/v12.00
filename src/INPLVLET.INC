.******************************************************************************
.* System         : Inpatients                                                *
.*                                                                            *
.* Include Name   : INPLVLET.INC (for PATILTFD)                               *
.*                                                                            *
.* Function       : Include the LC and LX variables for Patient Letters       *
.*                                                                            *
.* Author         : Don Nguyen                                                *
.*                                                                            *
.* Note           : When adding variables, add to the LCNOVARS value as this  *
.*                  must equal the total number of variables in the list.     *
.*                                                                            *
.* Modifications  :                                                           *
.*----------------------------------------------------------------------------*
.* V12.00.01 05/09/2025  Thanh T           TSK 0949457                        *
.*           Added LCPUSRAC-LCPUSRIL fields                                   *
.* V11.04.03 17/07/2024  Thanh T           TSK 0939648                        *
.*           Added LCPXSN18/%secraddr - Secure Address                        *
.*                 LCPXSN19/%verfaddr - Verified Address                      *
.*                 LCPXSN20/%multbirt - Multiple Birth Indicator              *
.*                 LCPXSN21/%emailval - Email Validation Flag                 *
.*                 LCPXSN22/%statusbb - Status Indicator 22                   *
.*                 LCPXSN23/%statusbc - Status Indicator 23                   *
.*                 LCPXSN24/%statusbd - Status Indicator 24                   *
.*                 LCPXSN25/%statusbe - Status Indicator 25                   *
.*                 LCPXSN26/%statusbf - Status Indicator 26                   *
.*                 LCPXSN27/%statusbg - Status Indicator 27                   *
.*                 LCPXSN28/%statusbh - Status Indicator 28                   *
.*                 LCPXSN29/%statusbi - Status Indicator 29                   *
.*                 LCPXSN30/%statuscz - Status Indicator 30                   *
.* V11.04.02 17/05/2024  Thanh T           TSK 0941543                        *
.*           Added %ethncoda to %nok1desb for Ethnicity1-2, Main Language     *
.*           Spoken At Home 1-2 and Next Of Kin Main Language Spoken At       *
.*           Home 1-2 variables for Codes and long descriptions (206-217)     *
.* V11.04.01 05.02.2024  DA Sarkies        TSK 0936282                        *
.*           Increase size of variable to hold health fund number             *
.* V11.02.01 26/04/2022  Thanh T           TSK 0903453                        *
.*           Added LXPXUCC4, LXUCC4LD, LXPXATF1, LXPXUCC5, LXUCC5LD and       *
.*           LXPXATF2 fields                                                  *
.* V11.01.02 20/08/2021  Ebon Clements    TSK 0910423                         *
.*           Added last ward bed variables 194 and 199                        *
.* V11.01.01 01/06/2021  Ebon Clements    TSK 0900650                         *
.*           Added overdue leave register variables 189 to 193                *
.* V11.00.01 15/07/2020  Tracey Nguyen    TSK 0893621                         *
.*           Added %smsusrnm (LCCSMSUN/LXXSMSUN)                              *
.* V10.15.01 29/11/2019  Thanh T          TSK 0885262                         *
.*           Added %pgnami(LXPGNAM1) and %pgnams(LXPGNAM2)                    *
.* V10.14.01 28/08/2019  Thanh T          TSK 0877294                         *
.*           Added %aday(LXADAY), %adays(LXADAYS) and %atimem(LXATIMEM)       *
.*----------------------------------------------------------------------------*
.*       V10.13.01  27/11/2018  Ken Bell         TSK 0866588                  *
.*                  Added LCADATEX(%adatex) and LCADATEN(adaten)              *
.*       V10.13.00  14/11/2018  Don Nguyen       TSK 0863187                  *
.*                  Create new                                                *
.******************************************************************************
.
LCPAGE    INIT      "%page"       * New page                               * 1
LCACLASS  INIT      "%aclass"     * Admission class
LCADATE   INIT      "%adate"      * Admission date
LCADCFUL  INIT      "%adcful"     * Attending doctor full name
LCADCGIV  INIT      "%adcgiv"     * Attending doctor given names           * 5
LCADCINI  INIT      "%adcini"     * Attending doctor first initial
LCADCSUR  INIT      "%adcsur"     * Attending doctor surname
LCADCTTL  INIT      "%adcttl"     * Attending doctor title
LCADDA    INIT      "%adda"       * Patient address line 1
LCADDB    INIT      "%addb"       * Patient address line 2                 * 10
LCADDC    INIT      "%addc"       * Patient address line 3
LCADDD    INIT      "%addd"       * Patient address line 4
LCADMN    INIT      "%admn"       * Admission number
LCATYPE   INIT      "%atype"      * Admission type
LCAUSRA   INIT      "%ausra"      * Admission user defined field 1         * 15
LCAUSRB   INIT      "%ausrb"      * Admission user defined field 2
LCAUSRC   INIT      "%ausrc"      * Admission user defined field 3
LCAUSRD   INIT      "%ausrd"      * Admission user defined field 4
LCAUSRE   INIT      "%ausre"      * Admission user defined field 5
LCBTELE   INIT      "%btele"      * Business telephone                     * 20
LCCARECL  INIT      "%carecl"     * Care class
LCCLMCOD  INIT      "%clmcod"     * Claim code
LCCOFB    INIT      "%cofb"       * Country of birth
LCCURDAT  INIT      "%curdat"     * Current date
LCDDATE   INIT      "%ddate"      * Discharge date                         * 25
LCDOB     INIT      "%dob"        * Date of birth
LCFRSTI   INIT      "%frsti"      * First initial
LCFULLN   INIT      "%fulln"      * Full name
LCGIVN    INIT      "%givn"       * Given names
LCHADDA   INIT      "%hadda"      * Hospital postal address line 1         * 30
LCHADDB   INIT      "%haddb"      * Hospital postal address line 2
LCHFMEM   INIT      "%hfmem"      * Health fund membership number
LCHFTAB   INIT      "%hftab"      * Health fund table
LCHFUND   INIT      "%hfund"      * Health fund
LCHOSP    INIT      "%hosp"       * Hospital name                          * 35
LCHOSTEL  INIT      "%hostel"     * Hospital telephone number
LCHPOST   INIT      "%hpost"      * Hospital postal postcode
LCLETDAT  INIT      "%letdat"     * Date of letter (input at time of printing)
LCLOCDOC  INIT      "%locdoc"     * Local doctor
LCMEDI    INIT      "%medi"       * Medicare number                        * 40
LCNOKAA   INIT      "%nokaa"      * Next of kin address line 1
LCNOKAB   INIT      "%nokab"      * Next of kin address line 2
LCNOKAC   INIT      "%nokac"      * Next of kin address line 3
LCNOKAD   INIT      "%nokad"      * Next of kin address line 4
LCNOKBT   INIT      "%nokbt"      * Next of kin business telephone         * 45
LCNOKNM   INIT      "%noknm"      * Next of kin name
LCNOKPC   INIT      "%nokpc"      * Next of kin postcode
LCNOKPT   INIT      "%nokpt"      * Next of kin private telephone
LCPOST    INIT      "%post"       * Patient postcode
LCPTELE   INIT      "%ptele"      * Private telephone                      * 50
LCPUSRA   INIT      "%pusra"      * PMI user defined field 1 - Short Desc
LCPUSRB   INIT      "%pusrb"      * PMI user defined field 2 - Short Desc
LCPUSRC   INIT      "%pusrc"      * PMI user defined field 3 - Short Desc
LCRDCFUL  INIT      "%rdcful"     * Referring doctor full name
LCRDCGIV  INIT      "%rdcgiv"     * Referring doctor given names           * 55
LCRDCINI  INIT      "%rdcini"     * Referring doctor first initial
LCRDCSUR  INIT      "%rdcsur"     * Referring doctor surname
LCRDCTTL  INIT      "%rdcttl"     * Referring doctor title
LCREFERL  INIT      "%referl"     * Referral source
LCRELIG   INIT      "%relig"      * Religion                               * 60
LCSURN    INIT      "%surn"       * Surname
LCTDCFUL  INIT      "%tdcful"     * Treating doctor full name
LCTDCGIV  INIT      "%tdcgiv"     * Treating doctor given names
LCTDCINI  INIT      "%tdcini"     * Treating doctor first initial
LCTDCSUR  INIT      "%tdcsur"     * Treating doctor surname                * 65
LCTDCTTL  INIT      "%tdcttl"     * Treating doctor title
LCTITLE   INIT      "%title"      * Title
LCURNO    INIT      "%urno"       * U/R number
LCKNNAME  INIT      "%mailnme"
LCNKADD1  INIT      "%mailada"    * address of the letter                  * 70
LCNKADD2  INIT      "%mailadb"
LCNKADD3  INIT      "%mailadc"
LCNKADD4  INIT      "%mailadd"
LCNKPOST  INIT      "%mailpc"     * mail post code
LCGPSNAM  INIT      "%rggpsnm"    * registered gp's surname                * 75
LCGPGNAM  INIT      "%rggpgnm"    * registered gp's given name
LCGPADD1  INIT      "%rggpada"    * address of reffering Gp
LCGPADD2  INIT      "%rggpadb"               
LCGPADD3  INIT      "%rggpadc"               
LCGPADD4  INIT      "%rggpadd"                                             * 80
LCGPPOST  INIT      "%rggppc"     * registered gp poscode
LCRGPSNM  INIT      "%rfgrsnm"    * refered gp's surname
LCRGPGNM  INIT      "%rfgrgnm"    * refered gp's given name
LCRGPAD1  INIT      "%rfgrada"    * address of reffering Gp
LCRGPAD2  INIT      "%rfgradb"                                             * 85
LCRGPAD3  INIT      "%rfgradc"               
LCRGPAD4  INIT      "%rfgradd"               
LCRGPPST  INIT      "%rfgrpc"     * refered gp poscode
LCGPFH    INIT      "%gpfhn"      * GPFH Approval Number
LCECR     INIT      "%ecrn"       * ECR Approval Number                    * 90
LCHSPNAM  INIT      "%hspname"    * Hospital name (multi hospitals)
LCHSPAD1  INIT      "%hspadda"    *    "     address 1
LCHSPAD2  INIT      "%hspaddb"    *    "     address 2
LCHSPAD3  INIT      "%hspaddc"    *    "     address 3
LCHSPAD4  INIT      "%hspaddd"    *    "     address 4                     * 95
LCHSPOST  INIT      "%hsppost"    *    "     post Code
LCHSPHON  INIT      "%hspphon"    *    "     phon Number
LCRGPRNM  INIT      "%rgprcnm"    * regstrd gp's practice name
LCRGPRA1  INIT      "%rgprcaa"    * regstrd gp's practice address 1
LCRGPRA2  INIT      "%rgprcab"    * regstrd gp's practice address 2        * 100
LCRGPRA3  INIT      "%rgprcac"    * regstrd gp's practice address 3
LCRGPRA4  INIT      "%rgprcad"    * regstrd gp's practice address 4
LCRGPRPC  INIT      "%rgprcpc"    * regstrd gp's practice post code
LCRGPRPH  INIT      "%rgprcph"    * regstrd gp's practice Phone No.
LCRFPRNM  INIT      "%rfprcnm"    * refered gp's practice name             * 105
LCRFPRA1  INIT      "%rfprcaa"    * refered gp's practice address 1
LCRFPRA2  INIT      "%rfprcab"    * refered gp's practice address 2
LCRFPRA3  INIT      "%rfprcac"    * refered gp's practice address 3
LCRFPRA4  INIT      "%rfprcad"    * refered gp's practice address 4
LCRFPRPC  INIT      "%rfprcpc"    * refered gp's practice post code        * 110
LCRFPRPH  INIT      "%rfprcph"    * refered gp's practice Phone No.
LCCTELE   INIT      "%ctele"      * Cellular Phone Number
LCPADDA   INIT      "%padda"      * Postal address line 1
LCPADDB   INIT      "%paddb"      * Postal address line 2
LCPADDC   INIT      "%paddc"      * Postal address line 3                  * 115
LCPADDD   INIT      "%paddd"      * Postal address line 4
LCPPOST   INIT      "%ppost"      * Postal Post Code       
LCPXMSNA  INIT      "%pxmsna"     * Mother's Surname
LCPXMGNA  INIT      "%pxmgna"     * Mother's Given Name
LCPXMTLE  INIT      "%pxmtle"     * Mother's Title                         * 120
LCPXMAD1  INIT      "%pxmad1"     * Mother's Address Line 1
LCPXMAD2  INIT      "%pxmad2"     * Mother's Address Line 2
LCPXMAD3  INIT      "%pxmad3"     * Mother's Address Line 3
LCPXMAD4  INIT      "%pxmad4"     * Mother's Address Line 4
LCPXMPOS  INIT      "%pxmpos "    * Mother's Address Post Code             * 125
LCPXMPNO  INIT      "%pxmpno"     * Mother's Private Number
LCPXMBNO  INIT      "%pxmbno"     * Mother's Business Number
LCPXMMNO  INIT      "%pxmmno"     * Mother's Mobile Number
LCPXMEML  INIT      "%pxmeml"     * Mother's Email Address
LCPXMCNT  INIT      "%pxmcnt"     * Mother's Country of Birth (Cat C)      * 130
LCPXMCRP  INIT      "%pxmcrp"     * Mother's Correspondence  0=NO,1=YES
LCPXMLAB  INIT      "%pxmlab"     * Mother's Name on Labels  0=NO,1=YES
LCPXMREL  INIT      "%pxmrel"     * Relationship to Patient
LCPXFSNA  INIT      "%pxfsna"     * Father's Surname
LCPXFGNA  INIT      "%pxfgna"     * Father's Given Name                    * 135
LCPXFTLE  INIT      "%pxftle"     * Father's Title
LCPXFAD1  INIT      "%pxfad1"     * Father's Address Line 1
LCPXFAD2  INIT      "%pxfad2"     * Father's Address Line 2
LCPXFAD3  INIT      "%pxfad3"     * Father's Address Line 3
LCPXFAD4  INIT      "%pxfad4"     * Father's Address Line 4                * 140
LCPXFPOS  INIT      "%pxfpos"     * Father's Address Post Code
LCPXFPNO  INIT      "%pxfpno"     * Father's Private Number
LCPXFBNO  INIT      "%pxfbno"     * Father's Business Number
LCPXFMNO  INIT      "%pxfmno"     * Father's Mobile Number
LCPXFEML  INIT      "%pxfeml"     * Father's Email Address                 * 145
LCPXFCNT  INIT      "%pxfcnt"     * Father's Country of Birth (Cat C)
LCPXFCRP  INIT      "%pxfcrp"     * Father's Correspondence 0=NO,1=YES
LCPXFLAB  INIT      "%pxflab"     * Father's Name on Labels 0=NO,1=YES
LCPXFREL  INIT      "%pxfrel"     * Relationship to Patient
LCPXDVAC  INIT      "%pxdvac"     * DVA Card Colour (Cat DX)               * 150
LCPXABRG  INIT      "%pxabrg"     * Aboriginality (Cat VA)
LCPXPRVI  INIT      "%pxprvi "    * Privacy Indicator (Cat PV)
LCVXABRG  INIT      "%vxabrg"     * Aboriginality (PRS/2) (Cat VA)
LCVXCADM  INIT      "%vxcadm"     * Admission Criterion (PRS/2) (Cat VB)
LCVXIRAD  INIT      "%vxirad"     * Intent to Readmit (PRS/2) (Cat VR)     * 155
LCVXIDUS  INIT      "%vxidus"     * Intend Stay Duration (PRS/2) Cat VI
LCVXCRAV  INIT      "%vxcrav "    * Carer Availability (PRS/2) (Cat VK)
LCVXRCCT  INIT      "%vxrcct"     * Crit. Care Xfer Reason (PRS/2) (VJ)
LCVXAPWD  INIT      "%vxapwd"     * Admitting Point Ward (patwr1af)
LCVXAPBD  INIT      "%vxapbd"     * Admitting Point Bed (patwr1af)         * 160
LCRFFAXN  INIT      "%rgprfax"    * regstrd gp's fax number
LCRGFAXN  INIT      "%rfprfax"              
LCCURDTN  INIT      "%curdtn"     * Current date - no date extension
LCBPAYRN  INIT      "%bpaycrn"    * BPAY Number for last invoice
LCLSTINV  INIT      "%lstinv"     * Last invoice number for visit          * 165
LCIHINUM  INIT      "%pihino"     * Patient IHI Number
LCCASETC  INIT      "%vxcstc"     * HCP Case Team code
LCCASETD  INIT      "%vxcstd"     * HCP Case Team description
LCCSMSID  INIT      "%smsid"      * SMS Message ID
LCCSMSKY  INIT      "%smskey"     * SMS visit key                          * 170
LCSMSCOD  INIT      "%smscode"    * SMS Code
LCCSMSPH  INIT      "%smsphone"   * SMS Phone Number
LCCSMSUR  INIT      "%smsurno"    * SMS U/R Number
LCCSMSUS  INIT      "%smsuser"    * SMS User Id
LCELTOOP  INIT      "%elgtoop"    * Total out of pocket expenses           * 175
LCFOODDT  INIT      "%fooddate"   * Fasting Date - Food
LCFOODTM  INIT      "%foodtime"   * Fasting Time - Food
LCFLUIDD  INIT      "%fluiddate"  * Fasting Date - Fluid
LCFLUIDT  INIT      "%fluidtime"  * Fasting Time - Fluid
LCATIME   INIT      "%atime"      * Admission time                         * 180
LCADATEX  INIT      "%adatex"     * Admission date (99th xxx yyyy)
LCADATEN  INIT      "%adaten"     * Admission date (dd/mm/yyyy)
LCADAY    INIT      "%aday"       * Admission day of the week (Tuesday)
LCADAYS   INIT      "%adays"      * Admission day of the week (Tue)
LCATIMEM  INIT      "%atimem"     * Admission time (am/pm format)          * 185
LCPGNAM1  INIT      "%pgnami"     * Patient 1st Given Name	      
LCPGNAM2  INIT      "%pgnams"     * Patient 2nd Given Name	      
LCCSMSUN  INIT      "%smsusrnm"   * SMS User Name (WBSENAM)
LCLVDATE  INIT      "%leavdate"   * Leave date
LCLVTIME  INIT      "%leavtime"   * Leave time                             * 190
LCLVEXRD  INIT      "%leavexrd"   * Leave expected return date
LCLVEXRT  INIT      "%leavexrt"   * Leave expected return time 
LCLVLTYP  INIT      "%leavtype"   * Leave type
LCWARDCD  INIT      "%wardcode"   * Last ward code
LCWARDSN  INIT      "%wardsnam"   * Last ward short name                   * 195
LCWARDLN  INIT      "%wardlnam"   * Last ward long name
LCBEDDCD  INIT      "%bedcode"    * Last bed code
LCBEDDSN  INIT      "%bedsname"   * Last bed short name
LCBEDDLN  INIT      "%bedlname"   * Last bed long name
LCPXUCC4  INIT      "%idengend"   * Identifying Gender Code                * 200
LCUCC4LD  INIT      "%idgendsc"   * Identifying Gender Long Description
LCPXATF1  INIT      "%idgentxt"   * Identifying Gender Free Text
LCPXUCC5  INIT      "%pronoun"    * Identifying Pronoun Code
LCUCC5LD  INIT      "%prondesc"   * Identifying Pronoun Long Description
LCPXATF2  INIT      "%prontext"   * Identifying Pronoun Free Text          * 205
LCETHCO1  INIT      "%ethncoda"   * Ethnicity 1 Code                       * 206
LCETHLD1  INIT      "%ethndesa"   * Ethnicity 1 Long Description           * 207
LCETHCO2  INIT      "%ethncodb"   * Ethnicity 2 Code                       * 208
LCETHLD2  INIT      "%ethndesb"   * Ethnicity 2 Long Description           * 209
LCMLNCO1  INIT      "%lancoda"    * Main Language 1 Code                   * 210
LCMLNLD1  INIT      "%landesa"    * Main Language 1 Long Description       * 211
LCMLNCO2  INIT      "%lancodb"    * Main Language 2 Code                   * 212
LCMLNLD2  INIT      "%landesb"    * Main Language 2 Long Description       * 213
LCNKLCO1  INIT      "%noklcoda"   * NOK Main Language 1 Code               * 214
LCNKLLD1  INIT      "%nokldesa"   * NOK Main Language 1 Long Description   * 215
LCNKLCO2  INIT      "%noklcodb"   * NOK Main Language 2 Code               * 216
LCNKLLD2  INIT      "%nokldesb"   * NOK Main Language 2 Long Description   * 217
LCPXSN18  INIT      "%secraddr"   * Secure Address                         * 218
LCPXSN19  INIT      "%verfaddr"   * Verified Address                       * 219
LCPXSN20  INIT      "%multbirt"   * Multiple Birth Indicator               * 220
LCPXSN21  INIT      "%emailval"   * Email Validation Flag                  * 221
LCPXSN22  INIT      "%statusbb"   * Status Indicator 22                    * 222
LCPXSN23  INIT      "%statusbc"   * Status Indicator 23                    * 223
LCPXSN24  INIT      "%statusbd"   * Status Indicator 24                    * 224
LCPXSN25  INIT      "%statusbe"   * Status Indicator 25                    * 225
LCPXSN26  INIT      "%statusbf"   * Status Indicator 26                    * 226
LCPXSN27  INIT      "%statusbg"   * Status Indicator 27                    * 227
LCPXSN28  INIT      "%statusbh"   * Status Indicator 28                    * 228
LCPXSN29  INIT      "%statusbi"   * Status Indicator 29                    * 229
LCPXSN30  INIT      "%statuscz"   * Status Indicator 30                    * 230
LCPUSRAC  INIT      "%pusracod"   * PMI user defined field 1 - Code        * 231
LCPUSRAL  INIT      "%pusralde"   * PMI user defined field 1 - Long Desc   * 232
LCPUSRBC  INIT      "%pusrbcod"   * PMI user defined field 2 - Code        * 233
LCPUSRBL  INIT      "%pusrblde"   * PMI user defined field 2 - Long Desc   * 234
LCPUSRCC  INIT      "%pusrccod"   * PMI user defined field 3 - Code        * 235
LCPUSRCL  INIT      "%pusrclde"   * PMI user defined field 3 - Long Desc   * 236
LCPUSRDC  INIT      "%pusrdcod"   * PMI user defined field 4 - Code        * 237
LCPUSRDD  INIT      "%pusrddes"   * PMI user defined field 4 - Short Desc  * 238
LCPUSRDL  INIT      "%pusrdlde"   * PMI user defined field 4 - Long Desc   * 239
LCPUSREC  INIT      "%pusrecod"   * PMI user defined field 5 - Code        * 240
LCPUSRED  INIT      "%pusredes"   * PMI user defined field 5 - Short Desc  * 241
LCPUSREL  INIT      "%pusrelde"   * PMI user defined field 5 - Long Desc   * 242
LCPUSRFC  INIT      "%pusrfcod"   * PMI user defined field 6 - Code        * 243
LCPUSRFD  INIT      "%pusrfdes"   * PMI user defined field 6 - Short Desc  * 244
LCPUSRFL  INIT      "%pusrflde"   * PMI user defined field 6 - Long Desc   * 245
LCPUSRGC  INIT      "%pusrgcod"   * PMI user defined field 7 - Code        * 246
LCPUSRGD  INIT      "%pusrgdes"   * PMI user defined field 7 - Short Desc  * 247
LCPUSRGL  INIT      "%pusrglde"   * PMI user defined field 7 - Long Desc   * 248
LCPUSRHC  INIT      "%pusrhcod"   * PMI user defined field 8 - Code        * 249
LCPUSRHD  INIT      "%pusrhdes"   * PMI user defined field 8 - Short Desc  * 250
LCPUSRHL  INIT      "%pusrhlde"   * PMI user defined field 8 - Long Desc   * 251
LCPUSRIC  INIT      "%pusricod"   * PMI user defined field 9 - Code        * 252
LCPUSRID  INIT      "%pusrides"   * PMI user defined field 9 - Short Desc  * 253
LCPUSRIL  INIT      "%pusrilde"   * PMI user defined field 9 - Long Desc   * 254
.
LCNOVARS  FORM      "254"
.
.
.
LXPAGE    INIT      "  -----              Page Break               ":
                    "  -----  "
LXACLASS  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXADATE   INIT      "99th XXXXXXXXX 9999"
LXADCFUL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXADCGIV  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXADCINI  INIT      "X"
LXADCSUR  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXADCTTL  INIT      "XXXXXXXXX"
LXADDA    INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXADDB    INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXADDC    INIT      "XXXXXXXXXXXXXXXXXXXX"
LXADDD    INIT      "XXXXXXXXXXXXXXXXXXXX"
LXADMN    INIT      "XXXXXXXX"
LXATYPE   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXAUSRA   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXAUSRB   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXAUSRC   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXAUSRD   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXAUSRE   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXBTELE   INIT      "XXXXXXXXXXXX"
LXCARECL  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXCLMCOD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXCOFB    INIT      "XXXXXXXXXXXXXXXXXXXX"
LXCURDAT  INIT      "99th XXXXXXXXX 9999"
LXDDATE   INIT      "99th XXXXXXXXX 9999"
LXDOB     INIT      "XX/XX/XXXX"
LXFRSTI   INIT      "X"
LXFULLN   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXGIVN    INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXHADDA   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXHADDB   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXHFMEM   INIT      "XXXXXXXXXXXXXXXXXXX"
LXHFTAB   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXHFUND   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXHOSP    INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXHOSTEL  INIT      "XXXXXXXXXXXX"
LXHPOST   INIT      "XXXX"
LXLETDAT  INIT      "99th XXXXXXXXX 9999"
LXLOCDOC  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXMEDI    INIT      "XXXXXXXXXX"
LXNOKAA   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXNOKAB   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXNOKAC   INIT      "XXXXXXXXXXXXXXX"
LXNOKAD   INIT      "XXXXXXXXXXXXXXX"
LXNOKBT   INIT      "XXXXXXXXXXXX"
LXNOKNM   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXNOKPC   INIT      "XXXX"
LXNOKPT   INIT      "XXXXXXXXXXXX"
LXPOST    INIT      "XXXX"
LXPTELE   INIT      "XXXXXXXXXXXX"
LXPUSRA   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRB   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRC   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRDCFUL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRDCGIV  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXRDCINI  INIT      "X"
LXRDCSUR  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRDCTTL  INIT      "XXXXXXXXX"
LXREFERL  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRELIG   INIT      "XXXXXXXXXXXXXXXXXXXX"
LXSURN    INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXTDCFUL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXTDCGIV  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXTDCINI  INIT      "X"
LXTDCSUR  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXTDCTTL  INIT      "XXXXXXXXX"
LXTITLE   INIT      "XXXX"
LXURNO    INIT      "XXXXXXXX"
LXKNNAME  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXNKADD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"       
LXNKADD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXNKADD3  INIT      "XXXXXXXXXXXXXXX"
LXNKADD4  INIT      "XXXXXXXXXXXXXXX"
LXNKPOST  INIT      "XXXXXXXX"     
LXGPSNAM  INIT      "XXXXXXXXXXXXXXXXXXXX"   
LXGPGNAM  INIT      "XXXXXXXXXXXXXXXXXXXX"  
LXGPADD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"     
LXGPADD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXGPADD3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXGPADD4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXGPPOST  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"     
LXRGPSNM  INIT      "XXXXXXXXXXXXXXXXXXXX"   
LXRGPGNM  INIT      "XXXXXXXXXXXXXXXXXXXX"             
LXRGPAD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"            
LXRGPAD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXRGPAD3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXRGPAD4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"               
LXRGPPST  INIT      "XXXXXXXX"            
LXGPFH    INIT      "XXXXXXXXXXXXXXXXXXXX"
LXECR     INIT      "XXXXXXXXXXXXXXXXXXXX"
LXHSPNAM  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"     
LXHSPAD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"           
LXHSPAD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"           
LXHSPAD3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"           
LXHSPAD4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"           
LXHSPOST  INIT      "XXXXXXXX"                        
LXHSPHON  INIT      "XXXXXXXXXXXXXXXXXXXX"                        
LXRGPRNM  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXRGPRA1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRGPRA2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRGPRA3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRGPRA4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRGPRPC  INIT      "XXXXXXXX"
LXRGPRPH  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRFPRNM  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXRFPRA1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRFPRA2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRFPRA3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRFPRA4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXRFPRPC  INIT      "XXXXXXXX"
LXRFPRPH  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXCELL    INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPADDA   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPADDB   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPADDC   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPADDD   INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPPOST   INIT      "XXXXXXXX"
LXPXMSNA  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXMGNA  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMTLE  INIT      "XXXX"
LXPXMAD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMAD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMAD3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMAD4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMPOS  INIT      "XXXXXXXX"
LXPXMPNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXMBNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXMMNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXMEML  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXMCNT  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXMCRP  INIT      "XXX"
LXPXMLAB  INIT      "XXX"
LXPXMREL  INIT      "XXXXXXXXXX"
LXPXFSNA  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXFGNA  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFTLE  INIT      "XXXX"
LXPXFAD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFAD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFAD3  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFAD4  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFPOS  INIT      "XXXXXXXX"
LXPXFPNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXFBNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXFMNO  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXFEML  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXFCNT  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXFCRP  INIT      "XXX"
LXPXFLAB  INIT      "XXX"
LXPXFREL  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXDVAC  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXABRG  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXPRVI  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXABRG  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXCADM  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXIRAD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXIDUS  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXCRAV  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXRCCT  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXAPWD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXAPBD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRFFAXN  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXRGFAXN  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXCURDTN  INIT      "99 XXXXXXXXX 9999"
LXBPAYRN  INIT      "XXXXXXXXXXXXXXX"
LXLSTINV  INIT      "99999999"
LXIHINUM  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXVXCASC  INIT      "XXXXXXXXXX"
LXVXCASD  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXXSMSID  INIT      "XXXXXXXXXXXXXXXX"             
LXXSMSKY  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXSMSCOD  INIT      "XXX" 
LXXSMSPH  INIT      "XXXXXXXXXXXXXXXXXXXX" 
LXXSMSUR  INIT      "XXXXXXXX"
LXXSMSUS  INIT      "XXXXXXXXXX" 
LXELTOOP  INIT      "XXXXXXXXXXXXXXX"
LXFOODDT  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXFOODTM  INIT      "XXXXX"
LXFLUIDD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXFLUIDT  INIT      "XXXXX"
LXATIME   INIT      "XXXXX"
LXADATEX  INIT      "99th XXX 9999"
LXADATEN  INIT      "99/99/9999"
LXADAY    INIT      "XXXXXXXXX"
LXADAYS   INIT      "XXX"
LXATIMEM  INIT      "99:99 XX"
LXPGNAM1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPGNAM2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXXSMSUN  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXLVDATE  INIT      "XXXXXXXXXXX"
LXLVTIME  INIT      "XXXXXXXX"
LXLVEXRD  INIT      "XXXXXXXXXXX"
LXLVEXRT  INIT      "XXXXXXXX"
LXLVLTYP  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXWARDCD  INIT      "XXX"
LXWARDSN  INIT      "XXXXXXXXXX"
LXWARDLN  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXBEDDCD  INIT      "XXX"
LXBEDDSN  INIT      "XXXXXXXXXX"
LXBEDDLN  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPXUCC4  INIT      "XXX"
LXUCC4LD  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXATF1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXUCC5  INIT      "XXX"
LXUCC5LD  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXATF2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXETHCO1  INIT      "XXX"
LXETHLD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" 
LXETHCO2  INIT      "XXX"
LXETHLD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXMLNCO1  INIT      "XXX"
LXMLNLD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXMLNCO2  INIT      "XXX"
LXMLNLD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXNKLCO1  INIT      "XXX"
LXNKLLD1  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXNKLCO2  INIT      "XXX"
LXNKLLD2  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPXSN18  INIT      "X"
LXPXSN19  INIT      "X"
LXPXSN20  INIT      "X"
LXPXSN21  INIT      "X"
LXPXSN22  INIT      "X"
LXPXSN23  INIT      "X"
LXPXSN24  INIT      "X"
LXPXSN25  INIT      "X"
LXPXSN26  INIT      "X"
LXPXSN27  INIT      "X"
LXPXSN28  INIT      "X"
LXPXSN29  INIT      "X"
LXPXSN30  INIT      "X"
LXPUSRAC  INIT      "XXX"
LXPUSRAL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRBC  INIT      "XXX"
LXPUSRBL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRCC  INIT      "XXX"
LXPUSRCL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRDC  INIT      "XXX"
LXPUSRDD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRDL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSREC  INIT      "XXX"
LXPUSRED  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSREL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRFC  INIT      "XXX"
LXPUSRFD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRFL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRGC  INIT      "XXX"
LXPUSRGD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRGL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRHC  INIT      "XXX"
LXPUSRHD  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRHL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
LXPUSRIC  INIT      "XXX"
LXPUSRID  INIT      "XXXXXXXXXXXXXXXXXXXX"
LXPUSRIL  INIT      "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
