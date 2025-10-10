. V11.05.01 20/02/2025 JT C-0955356 Created new FD                              
. *----------------------------------------------------------------------
. * Include Name  :   PMSFDEFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Financial Summary Details          
. *
. * File Type     :   SQL
. *
. * File Name     :   pmsfdeaf.dat
. *
. * Index Values  :   KEY46   KEY46                                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSFDEA1   IFILE    SQL, FIXED=207, KEY="U1-3+4-4+5-10+11-14,15-16,17-17,18-30,31-38,39-40,41-46"
PMSFDEA2   IFILE    SQL, FIXED=207, KEY="U31-38,39-40,41-46,1-3+4-4+5-10+11-14,15-16,17-17,18-30"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMFEHOSP  DIM       3      3        1     Hospital Id                        
PMFESYST  DIM       1      1        4     System Indicator                   
.                                         1 = A + E                            
.                                         2 = Outpatient                       
.                                         3 = Inpatient                        
.                                         4 = Other Financial                  
.                                         5 = Day Center                       
PMFESITE  DIM       6      6        5     Outpatient Site                    
PMFEYEAR  DIM       4      4        11    Financial Year                     
PMFEPERD  DIM       2      2        15    Period (1 to 14) 14 for Last Year  
PMFEFTYP  DIM       1      1        17    Financial Type                     
.                                         A = Fees Generated                   
.                                         B = Cash Received                    
.                                         C = Journal                          
.                                         D = Credit Note                      
PMFECODE  DIM       13     13       18    Financial Code                     
.                                                 FOR FEES INVOICED
.                                                   Accommodation Non-Casemix...
.                                                   -------------------------
.                                                   AXXXYYY  - I/P ACCOMMODATION
.                                                   NXXXYYY  - Credit Note Accm.
.                                      CACCFEE=0       XXX - ADMISS TYPE
.                                                            OR WARD OR CLAIMTYP
.                                                      YYY - BLANK OR
.                                                            CLAIM TYPE
.
.                                                   AXXXYYYZ - I/P ACCOMODATION
.                                                   NXXXYYYZ - Credit Note
.                                                      XXX - CLAIM TYPE
.                                                      YYY - ADMISS TYPE
.                                                      Z   - EXTRA CHRG
.                                                            (0 = Other)
.                                                            (1 = Extra)
.                                                   AXXXXXX  - O/P CHARGE
.                                                   NXXXXXX  - Credit Note O/P
.                                                      XXXXXX - CLINIC
.
.                                                   Accommodation Casemix....
.                                                   -------------------------
.                                   LUMPSUM         CXYYYZZZ - Lumpsum (Casemix)
.                                                   HXYYY - Credit Note Lumpsum
.                                                    X   - Daycase/Overnight
.                                                      (0 - Overnight,1-Daycase)
.                                                    YYY - Adm.Type or ClaimTyp
.                                      CACCFEE=4     YYY - Adm.Type
.                                                    ZZZ - ClaimType
.
.                                   DAILY CHARGE    DXXXZZZ - Daily charge
.                                                            (Casemix)
.                                                   XXX - Ward or ClaimType
.                                      CACCFEE=4    XXX - Ward
.                                                   ZZZ - ClaimType
.
.                                                   JXXX - Credit Note Daily Chg
.                                                      XXX - Ward or ClaimType
.             <Nursing Home is not use anymore>
.                                                   Accommodation Nursing Home..
.                                                   -------------------------
.                                                   RXXX - Resident Contribution
.                                                    XXX - NH Account code
.                                                   A    - Accommodation charge
.                                                   I    - Income tested fee
.
.                                                   Miscellaneous Casemix....
.                                                   -------------------------
.                                                   TXYYYZZZ - Misc items(Csmix)
.                                                   PXYYYZZZ - Crd.Note Cmx Misc
.                                                    X   - Episode Type
.                                                        0 - MSO ,1 - Daycase
.                                                    YYY - Misc.Item group
.                                                    ZZZ - Misc.Item code
.                                                   or
.                                      PTCNMFEE=1   TXYYYZZZ - Misc items(Csmix)
.                                                   PXYYYZZZ - Crd.Note Cmx Misc
.                                                    X   - Episode Type
.                                                        0 - MSO ,1 - Daycase
.                                                    YYY - Claim code
.                                                    ZZZ - Misc.Item group
.
.                                                   Miscellaneous Non-Casemix...
.                                                   -------------------------
.                                                   MXXXYYYY - MISC ITEMS
.                                                   QXXXYYYY - Credit Note Misc.
.                                                             XXX - MIS ITM GRP
.                                                             YYYY - MIS ITM CDE
.                                                   or
.                                      PTCNMFEE=1   MXXXYYYY - MISC ITEMS (CL)
.                                                   QXXXYYYY - Credit Note
.                                                             XXX - CLAIM CODE
.                                                             YYYY - MIS GRP CDE
.
.                                                   G        - GOVERNMENT SUBSID
.                                                   S        - Credit Note
.
.                                                 FOR RECEIPTS
.                                                 -------------
.                                                   A        - FROM PATIENT
.                                                   BXXXXXX  - FROM HEALTH FUND
.                                                   C        - FROM GOVT SUBSIDY
.                                                   DXXX     - DEPOSITS
.                                                   EHXXXXX  - Eclipse payments
.                                                              XXXXXX - H. Fund
.                                                   ECXXX    - Eclipse payments
.                                                              XXX - Claim Code
.                                                   IXXXXXX  - FROM INSURANCE CO.
.                                                   MXXX     - FROM PATIENT
.                                                              VIA MERC CARDS
.                                                 FOR  JOURNALS
.                                                 -------------
.                                                   XX       - JOURNAL CODE
.                                      PTCNJFEE=1   XXXYY    - JOURNAL CODE (CL)
.                                                              XXX - CLAIM CODE
.                                                              YY - JOURNAL CODE
.                                                   WCXXX    - MERCHANT COMMISS
.                                                              XXX - MERC CODE
.                                                   WJXXX    - MERCHANT JOURNAL
.                                                              XXX - MERC CODE
.                                                 FOR  MERCHANT CARDS
.                                                 -------------------
.                                                   XXX       - MERCHANT CODE
.
PMFEINVN  DIM       8      8        31    Invoice Number                     
PMFERTYP  DIM       2      2        39    Record Type                        
.                                         1 = Accommodation                    
.                                         2 = Item                             
.                                         3 = Credit Note Accom.               
.                                         4 = Credit Note Item                 
.                                         5 = GST                              
.                                         6 = Credit Note GST                  
.                                         7 = Cash                             
.                                         8 = Journal                          
PMFETRNO  DIM       6      6        41    Transaction Number                 
PMFEINVD  DIM       8      8        47    Invoice date (ccyymmdd)            
PMFEURNO  DIM       8      8        55    U/R Number                         
PMFEADMN  DIM       8      8        63    Admission Number                   
PMFEAMNT  FORM      12.2   8        71    Transaction Amount                 
PMFECUID  DIM       10     10       79    Web User Id Created (websecaf)     
PMFECDAT  DIM       8      8        89    Date Record Created (ccyymmdd)     
PMFECTIM  DIM       10     10       97    Time Record Created (hh:mm:ss)     
PMFESPRE  DIM       100    100      107   Spare Variable                     
.
.End of Record                      207  
.
