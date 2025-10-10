. V11.04.01 14/11/2024 PVL C-0939466 Created DVAW Payment Header Table          
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVHFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVAW DVYW Payment      
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvhaf.dat
. *
. * Index Values  :   KEY47   KEY47   KEY48   KEY47   KEY47                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVHA1   IFILE    SQL, FIXED=289, KEY="U1-3,4-11,12-15,16-23,129-152"
WEBDVHA2   IFILE    SQL, FIXED=289, KEY="U1-3,16-23,4-11,12-15,129-152"
WEBDVHA3   IFILE    SQL, FIXED=289, KEY="U1-3,78-78,16-23,4-11,12-15,129-152"
WEBDVHA4   IFILE    SQL, FIXED=289, KEY="U1-3,129-152,4-11,12-15,16-23"
WEBDVHA5   IFILE    SQL, FIXED=289, KEY="U129-152,1-3,4-11,12-15,16-23"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDHHOSP  DIM       3      3        1     Hospital ID                        
WBDHPYPN  DIM       8      8        4     Payee Provider Number              
WBDHPRUN  DIM       4      4        12    Payment Run Number                 
WBDHPDAT  DIM       8      8        16    Payment Run Date                   
WBDHDAMN  DIM       9      9        24    Deposit Amount                     
WBDHACCN  DIM       9      9        33    Bank Account Number                
WBDHACNM  DIM       30     30       42    Bank Account Name                  
WBDHBSBC  DIM       6      6        72    BSB Code                           
WBDHSTAT  DIM       1      1        78    Status                             
.                                         0 = Received                         
.                                         1 = Partial                          
.                                         2 = Released                         
.                                         3 = Processing                       
WBDHRSTA  DIM       50     50       79    Report Status                      
WBDHRKEY  DIM       24     24       129   Report Retrieval Key               
WBDHMSID  DIM       36     36       153   Message Id                         
WBDHSPAR  DIM       100    100      189   Spare Variable                     
.
.End of Record                      289  
.
