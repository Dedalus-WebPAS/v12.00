. V11.04.01 13/11/2024 PVL C-0939466 Created WebServices DVDW Assessment Report 
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVDFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVDW Assessment Re     
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvdaf.dat
. *
. * Index Values  :   KEY33   KEY57   KEY69   KEY33                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVDA1   IFILE    SQL, FIXED=322, KEY="U1-6,7-9,146-169"
WEBDVDA2   IFILE    SQL, FIXED=322, KEY="U86-109,1-6,7-9,146-169"
WEBDVDA3   IFILE    SQL, FIXED=322, KEY="U110-145,1-6,7-9,146-169"
WEBDVDA4   IFILE    SQL, FIXED=322, KEY="U146-169,1-6,7-9"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDDCLID  DIM       6      6        1     Claim ID                           
WBDDRPTC  DIM       3      3        7     Report counter (right just.)       
WBDDCLBP  DIM       9      9        10    Claim Benefit Paid                 
WBDDCLCA  DIM       9      9        19    Claim Charge Amount                
WBDDSRVP  DIM       8      8        28    Servicing Provider Num             
WBDDSTAT  DIM       50     50       36    Status                             
WBDDTRID  DIM       24     24       86    Claim Transaction ID               
WBDDMSID  DIM       36     36       110   Message ID                         
WBDDRKEY  DIM       24     24       146   Report Retrieval Key               
WBDDCUID  DIM       10     10       170   Created By User ID                 
WBDDCDAT  DIM       8      8        180   Date Created                       
WBDDCTIM  DIM       8      8        188   Time Created                       
WBDDUUID  DIM       10     10       196   Update By User ID                  
WBDDUDAT  DIM       8      8        206   Date Updated                       
WBDDUTIM  DIM       8      8        214   Time Updated                       
WBDDSPAR  DIM       100    100      222   Spare Variable                     
.
.End of Record                      322  
.
