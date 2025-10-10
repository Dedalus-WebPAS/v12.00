. V11.04.01 12/11/2024 PVL C-0939466 Created WebService DVAW Batch Header Table 
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVBFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebService DVAW Batch Header       
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvbaf.dat
. *
. * Index Values  :   KEY8    KEY16                                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVBA1   IFILE    SQL, FIXED=290, KEY="U1-8"
WEBDVBA2   IFILE    SQL, FIXED=290, KEY="U21-28,1-8"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDBBTHN  DIM       8      8        1     Batch No                           
WBDBBTHL  FORM      12.2   8        9     Batch Total                        
WBDBTRIB  FORM      6      4        17    Total records in batch             
WBDBDTBC  DIM       8      8        21    Date batch created (ccyymmdd)      
WBDBTMBC  DIM       8      8        29    Time batch created (hh:mm:ss)      
WBDBOPER  DIM       10     10       37    Web User Id                        
WBDBEFNM  DIM       18     18       47    Extract Filename                   
WBDBLOCN  DIM       65     65       65    Location Id                        
WBDBSNID  DIM       60     60       130   Sender Id (email)                  
WBDBSPAR  DIM       100    100      190   Spare variable                     
.
.End of Record                      290  
.
