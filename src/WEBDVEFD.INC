. V11.04.01 13/11/2024 PVL C-0939466 Created WebServices DVDW Assessment Med Evt
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVEFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVEW Ass Med Evt Rep   
. *
. * File Type     :   SQL
. *
. * File Name     :   webdveaf.dat
. *
. * Index Values  :   KEY35   KEY59   KEY71   KEY35                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVEA1   IFILE    SQL, FIXED=801, KEY="U1-6,7-9,10-11,677-700"
WEBDVEA2   IFILE    SQL, FIXED=801, KEY="U617-640,1-6,7-9,10-11,677-700"
WEBDVEA3   IFILE    SQL, FIXED=801, KEY="U641-676,1-6,7-9,10-11,677-700"
WEBDVEA4   IFILE    SQL, FIXED=801, KEY="U677-700,1-6,7-9,10-11"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDECLID  DIM       6      6        1     Claim ID                           
WBDERPTC  DIM       3      3        7     Report counter (right just.)       
WBDEMEVC  DIM       2      2        10    Medical Event counter (right just.)
WBDEEVDT  DIM       8      8        12    Event Date                         
WBDEEVID  DIM       2      2        20    Event Id                           
WBDEPTSC  DIM       4      4        22    Patient Status Code                
WBDEPTST  DIM       500    500      26    Patient Status Text                
WBDEPTMN  DIM       10     10       526   Patient Veteran Number             
WBDEPTMR  DIM       1      1        536   Patient Member Reference           
WBDEPTFN  DIM       40     40       537   Patient Family Name                
WBDEPTGN  DIM       40     40       577   Patient Given Name                 
WBDETRID  DIM       24     24       617   Transaction Id                     
WBDEMSID  DIM       36     36       641   Message Id                         
WBDERKEY  DIM       24     24       677   Report Retrieval Key               
WBDESPAR  DIM       100    100      701   Spare Variable                     
.
.End of Record                      801  
.
