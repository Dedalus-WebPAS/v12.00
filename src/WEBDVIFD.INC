. V11.04.01 15/11/2024 PVL C-0939466 Created WebServices DVAW DVYW Payment Detai
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVIFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVAW DVYW Payment      
. *
. * File Type     :   SQL
. *
. * File Name     :   webdviaf.dat
. *
. * Index Values  :   KEY53   KEY53   KEY77   KEY77                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVIA1   IFILE    SQL, FIXED=243, KEY="U1-3,4-11,12-15,16-23,42-47,56-79"
WEBDVIA2   IFILE    SQL, FIXED=243, KEY="U56-79,1-3,4-11,12-15,16-23,42-47"
WEBDVIA3   IFILE    SQL, FIXED=243, KEY="U80-103,1-3,4-11,12-15,16-23,42-47,56-79"
WEBDVIA4   IFILE    SQL, FIXED=243, KEY="U80-103,56-79,1-3,4-11,12-15,16-23,42-47"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDIHOSP  DIM       3      3        1     Hospital ID                        
WBDIPYPN  DIM       8      8        4     Payee Provider Number              
WBDIPRUN  DIM       4      4        12    Payment Run Number                 
WBDIPDAT  DIM       8      8        16    Payment Run Date                   
WBDICLBP  DIM       9      9        24    Claim Benefit Paid                 
WBDICLCA  DIM       9      9        33    Claim Charge Amount                
WBDICLID  DIM       6      6        42    Claim ID                           
WBDILDAT  DIM       8      8        48    Lodgement Date                     
WBDITRID  DIM       24     24       56    Claim Transaction ID               
WBDIRKEY  DIM       24     24       80    Report Retrieval Key               
WBDISTAT  DIM       1      1        104   Status                             
.                                         0 = Received                         
.                                         1 = Locked                           
.                                         2 = Released                         
.                                         3 = Released to Suspense A/C         
WBDILTYP  DIM       2      2        105   Lock Type (numeric - right just)   
WBDIMSID  DIM       36     36       107   Message ID                         
WBDISPAR  DIM       100    100      143   Spare Variable                     
.
.End of Record                      243  
.
