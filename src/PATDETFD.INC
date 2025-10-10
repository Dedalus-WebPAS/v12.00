. V12.00.01 15/05/2025 ITU C-0925576 Added desc for Code Field 1 for Debt Type 2
. V11.05.02 18/11/2024 TT C-0925576 Added PTDESDAT to PTDETXT2 fields
. V10.05.01 26/08/2014 JT C-298984 Added Amount to be repaid and Frequency of Pa
. V10.04.01 05/03/2014 JT C-295681 Added System
. V10.02.01 20/04/2011 ML  CAR 233229 Added UR Number
. V10.01.01 18/11/2010 ML  Created table
. *----------------------------------------------------------------------
. * Include Name  :   PATDETFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Patient Debt Registration file     
. *
. * File Type     :   SQL
. *
. * File Name     :   patdetaf.dat
. *
. * Index Values  :   KEY10   KEY18                                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PATDETA1   IFILE    SQL, FIXED=362, KEY="U1-1,2-9,81-81"
PATDETA2   IFILE    SQL, FIXED=362, KEY="U73-80,1-1,2-9,81-81"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PTDETYPE  DIM       1      1        1     Patient Debt Type                  
.                                         1=Patient Only                       
.                                         2=Payment Plan Invoice               
.                                         3=Debt Collection                    
.                                         4=Payment Plan Admission             
PTDEINVN  DIM       8      8        2     Invoice Number/Admission Number    
.                                         (when PTDETYPE = 4)                  
PTDEAGNT  DIM       3      3        10    Debt Collection Agency (Cat dc)    
PTDEDTCL  DIM       8      8        13    Date Debt Cleared                  
PTDECDAT  DIM       8      8        21    Date Record Created (CCYYMMDD)     
PTDECTIM  DIM       8      8        29    Time Record Created (HH:MM:SS)     
PTDECUID  DIM       10     10       37    WEB User ID Created (websecaf)     
PTDEUDAT  DIM       8      8        47    Date Record Updated (CCYYMMDD)     
PTDEUTIM  DIM       8      8        55    Time Record Updated (HH:MM:SS)     
PTDEUUID  DIM       10     10       63    WEB User ID Updated (websecaf)     
PTDEURNO  DIM       8      8        73    UR Number                          
PTDESYST  DIM       1      1        81    System                             
.                                         1 = A & E                            
.                                         2 = Outpatient                       
.                                         3 = Inpatient                        
.                                         4 = Private Practice                 
PTDERPAY  FORM      12.2   8        82    Amount to be repaid per period     
PTDEFREQ  DIM       3      3        90    Frequency of Payment (Cat FP)      
.                                         eg.Daily,Weekly,Fortnightly,Monthly,Q
.                                         uaterly                              
PTDESDAT  DIM       8      8        93    Payment Start Date (CCYYMMDD)      
PTDEEDAT  DIM       8      8        101   Payment End Date (CCYYMMDD)        
PTDENOFP  FORM      5.2    5        109   No. of payments                    
PTDEDAT1  DIM       8      8        114   Date field 1 (CCYYMMDD)            
PTDEDAT2  DIM       8      8        122   Date field 2 (CCYYMMDD)            
PTDETIM1  DIM       8      8        130   Time Field 1 (HH:MM:SS)            
PTDETIM2  DIM       8      8        138   Time Field 2 (HH:MM:SS)            
PTDECOD1  DIM       3      3        146   Code Field 1                       
.                                         FA Code(cat FA) for Debt Type=2 or 4 
PTDECOD2  DIM       3      3        149   Code Field 2                       
PTDETXT1  DIM       80     80       152   Text Field 1                       
PTDETXT2  DIM       80     80       232   Text Field 2                       
PTDESPAR  DIM       50     50       312   Spare                              
.
.End of Record                      362  
.
