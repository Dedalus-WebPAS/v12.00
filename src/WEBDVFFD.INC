. V12.00.01 08/05/2025 PVL C-0939466 Added GST Indicator                        
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVFFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices DVAW Ass Med Evt Serv  
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvfaf.dat
. *
. * Index Values  :   KEY37   KEY61   KEY73   KEY37                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVFA1   IFILE    SQL, FIXED=300, KEY="U1-6,7-9,10-11,20-21,123-146"
WEBDVFA2   IFILE    SQL, FIXED=300, KEY="U63-86,1-6,7-9,10-11,20-21,123-146"
WEBDVFA3   IFILE    SQL, FIXED=300, KEY="U87-122,1-6,7-9,10-11,20-21,123-146"
WEBDVFA4   IFILE    SQL, FIXED=300, KEY="U123-146,1-6,7-9,10-11,20-21"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDFCLID  DIM       6      6        1     Claim ID                           
WBDFRPTC  DIM       3      3        7     Report counter (right just.)       
WBDFMEVC  DIM       2      2        10    Medical Event counter (right just.)
WBDFACRF  DIM       8      8        12    Account Reference Number (InvoiceN)
WBDFSRVC  DIM       2      2        20    Service Counter (right just.)      
WBDFASSC  DIM       4      4        22    Assessment Code                    
WBDFBEPD  DIM       9      9        26    Benefit Paid                       
WBDFCHAM  DIM       9      9        35    Charge Amount                      
WBDFSVID  DIM       4      4        44    Service Id                         
WBDFITMN  DIM       5      5        48    Item NUmber                        
WBDFNOFP  DIM       2      2        53    Number of Patients                 
WBDFPROV  DIM       8      8        55    Service Provider Number            
WBDFTRID  DIM       24     24       63    Transaction ID                     
WBDFMSID  DIM       36     36       87    Message ID                         
WBDFRKEY  DIM       24     24       123   Report Retrieval Key               
WBDFGSTI  DIM       3      3        147   GST Indicator                      
WBDFSPAR  DIM       150    150      150   Spare Variable                     
.
.End of Record                      300  
.
