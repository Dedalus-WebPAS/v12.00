. V11.04.01 11/12/2023 TTI C-0932089 Initial version                            
. *----------------------------------------------------------------------
. * Include Name  :   PRIONHFD.INC
. *
. * Function      :   File Def'n Include for Private Practice                   
. *                   Private Practice On Hold Trans Hist
. *
. * File Type     :   SQL
. *
. * File Name     :   prionhaf.dat
. *
. * Index Values  :   KEY24                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PRIONHA1   IFILE    SQL, FIXED=205, KEY="U1-8,9-16,17-24"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PRONUNIQ  DIM       8      8        1     Unique ID for Private Practice     
PRONTDAT  DIM       8      8        9     Transaction Date (ccyymmdd)        
PRONTTIM  DIM       8      8        17    Transaction Time (hh:mm:ss)        
PRONUSID  DIM       10     10       25    User ID of user performing trans   
PRONHRSN  DIM       3      3        35    Reason for Hold Code (Cat rh)      
PRONFTXT  DIM       80     80       38    Reason for Hold Free Text          
PRONACTN  DIM       1      1        118   Action Code                        
.                                         A=Added Hold for Referral            
.                                         S=Added Hold for Service Doctor      
.                                         P=Added Hold for Medical Practice    
.                                         F= Added Hold for Health Fund        
.                                         U=Updated                            
.                                         D=Deleted                            
PRONDOCT  DIM       10     10       119   Service Doctor (prihreff)          
PRONPRAC  DIM       6      6        129   Medical Practice (prihreff)        
PRONPIND  DIM       3      3        135   Patient Indicator (Cat GI)         
PRONCLAM  DIM       3      3        138   Claim Code (Cat CL)                
PRONHFND  DIM       6      6        141   Health Fund Code                   
PRONHIFD  DIM       8      8        147   Hold Invoices From Date (ccyymmdd) 
PRONSPAR  DIM       50     50       155   Spare Variable                     
.
.End of Record                      205  
.
