. V11.04.01 11/12/2023 TTI C-0932089 Added 6 new fields                         
. *----------------------------------------------------------------------
. * Include Name  :   PRIPRAFD.INC
. *
. * Function      :   File Def'n Include for Private Practice                   
. *                   Medical Practice                   
. *
. * File Type     :   SQL
. *
. * File Name     :   pripracf.dat
. * Audit Name    :   priaudpr.dat
. *
. * Index Values  :   KEY6    KEY36                                          
. *
. *----------------------------------------------------------------------
.
.Audit File Definition
.--------------------
PRIAUDPR   IFILE    SQL, FIXED=366, KEY="D1-8,9-16,17-18,19-19"                 
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PRPRAUDD  DIM       8      8        1     Date of Change
PRPRAUDT  DIM       8      8        9     Time of Change
PRPRAUDP  DIM       2      2        17    Port
PRPRAUDR  DIM       1      1        19    Record Type
.                                         A=Added Record
.                                         B=Before Change
.                                         C=After Change
.                                         D=Deleted Record
PRPRAUDS  FORM      1      2        20    Record Status
.                                         1=Not Printed
.                                         2=Printed
PRPRAUDO  DIM       4      4        22    Operator ID
.
.
.Data File Definition
.--------------------
PRIPRAC1   IFILE    SQL, FIXED=341, KEY="U1-6"
PRIPRAC2   IFILE    SQL, FIXED=341, KEY="U7-36,1-6"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PRPRCODE  DIM       6      6        1     Medical Practice Code              
PRPRDESC  DIM       30     30       7     M.P. Description                   
PRPRPDOC  DIM       10     10       37    M.P. Primary Doctor                
PRPRADD1  DIM       25     25       47    M.P. Address Line 1                
PRPRADD2  DIM       25     25       72    M.P. Address Line 2                
PRPRADD3  DIM       25     25       97    M.P. Address Line 3                
PRPRPOST  DIM       4      4        122   M.P. Postcode                      
PRPRTELP  DIM       12     12       126   M.P. Telephone                     
PRPRSTAT  FORM      1      2        138   M.P. Status                        
.                                             1 = Inactive                     
.                                             0 = Active                       
PRPRTIME  FORM      1      2        140   Service Time on invoice            
.                                             0 = No                           
.                                             1 = Yes                          
PRPRRANG  DIM       3      3        142   Spare                              
PRPRPMCI  DIM       8      8        145   MCI (3 alpha and 5 numeric)        
PRPRPYEE  DIM       10     10       153   Payee Name Provider Number         
PRPRREGI  DIM       3      3        163   Register                           
PRPRRDAT  DIM       8      8        166   Fees Invoiced Reset Date (ccyymmdd)
PRPRHRSN  DIM       3      3        174   Reason for Hold Code (Cat rh)      
PRPRFTXT  DIM       80     80       177   Reason for Hold Free Text          
PRPRHIFD  DIM       8      8        257   Hold Invoices From Date (ccyymmdd) 
PRPRHLDT  DIM       8      8        265   On Hold Last Update Date (ccyymmdd)
PRPRHLTI  DIM       8      8        273   On Hold Last Update Time (hh:mm:ss)
PRPRHLUI  DIM       10     10       281   On Hold Last Update User ID        
PRPRSPAR  DIM       50     50       291   Spare Variable                     
.
.End of Record                      341  
.
