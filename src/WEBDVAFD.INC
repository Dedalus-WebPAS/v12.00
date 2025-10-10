. V11.04.01 11/11/2024 PVL C-0939466 Created Eclipse DVAW Audit History Table   
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVAFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVAW Audit History     
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvaaf.dat
. *
. * Index Values  :   KEY27   KEY27   KEY35   KEY51   KEY63                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVAA1   IFILE    SQL, FIXED=312, KEY="U1-8,9-16,17-24,35-36,175-175"
WEBDVAA2   IFILE    SQL, FIXED=312, KEY="U9-16,17-24,35-36,1-8,175-175"
WEBDVAA3   IFILE    SQL, FIXED=312, KEY="U1-8,25-32,9-16,17-24,35-36,175-175"
WEBDVAA4   IFILE    SQL, FIXED=312, KEY="U47-70,1-8,9-16,17-24,35-36,175-175"
WEBDVAA5   IFILE    SQL, FIXED=312, KEY="U176-211,1-8,9-16,17-24,35-36,175-175"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDAINVN  DIM       8      8        1     Invoice Number                     
WBDADATE  DIM       8      8        9     Date of Transaction (ccyymmdd)     
WBDATIME  DIM       8      8        17    Time of Transaction (hh:mm:ss)     
WBDABATN  DIM       8      8        25    Batch Number                       
WBDASTAT  FORM      2      2        33    Status (see webdvaaf.WBDWFLAG)     
WBDATYPE  DIM       2      2        35    Type                               
.                                         0 = Not Applicable                   
.                                         1 = Report Request                   
.                                         2 = Report Request Response          
.                                         3 = Viewed                           
.                                         4 = Data Error Response              
.                                         5 = Transmission Error Response      
WBDAOPER  DIM       10     10       37    Web User Id (websecaf)             
WBDATRID  DIM       24     24       47    Transaction Id                     
WBDAEROR  DIM       4      4        71    Hub Error Code                     
WBDAEROT  DIM       100    100      75    Hub Error Explanaton Text          
WBDAMODL  DIM       1      1        175   webPAS Module                      
.                                         1 = Emergency                        
.                                         2 = Private Practice                 
.                                         3 = Outpatient                       
WBDAMSID  DIM       36     36       176   Message ID                         
WBDASPAR  DIM       100    100      212   Spare Variable                     
.
.End of Record                      312  
.
