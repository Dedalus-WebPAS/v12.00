. V11.04.01 12/12/2023 TTI C-0932089 Added 6 new fields                         
. *----------------------------------------------------------------------
. * Include Name  :   PRIDOCFD.INC
. *
. * Function      :   File Def'n Include for Private Practice                   
. *                   Medical Practice Doctor File for PP
. *
. * File Type     :   SQL
. *
. * File Name     :   pridoctf.dat
. * Audit Name    :   priauddo.dat
. *
. * Index Values  :   KEY22   KEY22   KEY32                                  
. *
. *----------------------------------------------------------------------
.
.Audit File Definition
.--------------------
PRIAUDDO   IFILE    SQL, FIXED=253, KEY="D1-8,9-16,17-18,19-19"                 
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PRDOAUDD  DIM       8      8        1     Date of Change
PRDOAUDT  DIM       8      8        9     Time of Change
PRDOAUDP  DIM       2      2        17    Port
PRDOAUDR  DIM       1      1        19    Record Type
.                                         A=Added Record
.                                         B=Before Change
.                                         C=After Change
.                                         D=Deleted Record
PRDOAUDS  FORM      1      2        20    Record Status
.                                         1=Not Printed
.                                         2=Printed
PRDOAUDO  DIM       4      4        22    Operator ID
.
.
.Data File Definition
.--------------------
PRIDOCT1   IFILE    SQL, FIXED=228, KEY="U1-6,7-16,17-19,20-22"
PRIDOCT2   IFILE    SQL, FIXED=228, KEY="U7-16,1-6,17-19,20-22"
PRIDOCT3   IFILE    SQL, FIXED=228, KEY="U51-60,7-16,1-6,17-19,20-22"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PRDOPRAC  DIM       6      6        1     Medical Practice Code              
PRDODOCT  DIM       10     10       7     Associated Doctor Code             
PRDOCLAM  DIM       3      3        17    Claim Code (Category CL)           
PRDOPIND  DIM       3      3        20    Patient Indicator (Category GI)    
PRDOCOMM  FORM      3.2    4        23    Associated Doctor % Commission     
PRDOFEEP  FORM      3.2    4        27    % of Schedule Fee Charged          
PRDOSTAT  FORM      1      2        31    Associated Doctor Status           
.                                              1 = Inactive                    
.                                              0 = Active                      
PRDOCRCD  DIM       5      5        33    Creditor Code                      
PRDOABNN  DIM       11     11       38    ABN Number                         
PRDOGSTR  FORM      1      2        49    GST Register (0=No, 1=Yes)         
PRDOPROV  DIM       10     10       51    Service Provider                   
PRDOHRSN  DIM       3      3        61    Reason for Hold Code (Cat rh)      
PRDOFTXT  DIM       80     80       64    Reason for Hold Free Text          
PRDOHIFD  DIM       8      8        144   Hold Invoices From Date (ccyymmdd) 
PRDOHLDT  DIM       8      8        152   On Hold Last Update Date (ccyymmdd)
PRDOHLTI  DIM       8      8        160   On Hold Last Update Time (hh:mm:ss)
PRDOHLUI  DIM       10     10       168   On Hold Last Update User ID        
PRDOSPAR  DIM       50     50       178   Spare Variable                     
.
.End of Record                      228  
.
