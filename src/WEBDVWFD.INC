. V11.05.01 28/03/2025 PVL C-0939466 Added 4=Posted
. V11.04.01 06/11/2024 PVL C-0939466 Created DVAW FD                            
. *----------------------------------------------------------------------
. * Include Name  :   WEBDVWFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebService DVAW Table              
. *
. * File Type     :   SQL
. *
. * File Name     :   webdvwaf.dat
. *
. * Index Values  :   KEY30   KEY17   KEY24   KEY24   KEY35   KEY40   KEY30  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBDVWA1   IFILE    SQL, FIXED=388, KEY="U1-3,4-5,6-6,7-14,15-22,23-30"
WEBDVWA2   IFILE    SQL, FIXED=388, KEY="U15-22,23-30,6-6"
WEBDVWA3   IFILE    SQL, FIXED=388, KEY="U23-30,7-14,15-22"
WEBDVWA4   IFILE    SQL, FIXED=388, KEY="U7-14,15-22,23-30"
WEBDVWA5   IFILE    SQL, FIXED=388, KEY="U1-3,31-38,7-14,15-22,23-30"
WEBDVWA6   IFILE    SQL, FIXED=388, KEY="U55-78,15-22,23-30"
WEBDVWA7   IFILE    SQL, FIXED=388, KEY="U4-5,1-3,6-6,7-14,15-22,23-30"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBDWHOSP  DIM       3      3        1     Hospital ID (pathspaf)             
DWBDWFLG  DIM       2      2        4     Eclipse Status Flag                
.                                         webPAS Processing                    
.                                         0 = Not Sent                         
.                                         1 = Error (PAS validation)           
.                                         2 = Extracted                        
.                                         WebServices - Processing             
.                                         3 = Error (SA validation)            
.                                         4 = Posted
.                                         5 = Received                         
.                                         Eclipse - Reported                   
.                                         6 = Complete - Reported              
.                                         Eclipse - Remittance                 
.                                         7 = Reported                         
.                                         8 = Closed                           
WBDWMODL  DIM       1      1        6     webPas Module                      
.                                         1 = Emergency                        
.                                         2 = Private Practice                 
.                                         3 = Outpatient                       
WBDWUNIQ  DIM       8      8        7     Unique Identifier / Visit Number   
WBDWINVN  DIM       8      8        15    Invoice Number                     
WBDWBATN  DIM       8      8        23    Batch Number                       
WBDWURNO  DIM       8      8        31    U/R/ Number                        
WBDWPBAT  DIM       8      8        39    Previous Batch Number              
WBDWNBAT  DIM       8      8        47    Next Batch Number                  
WBDWTRID  DIM       24     24       55    Claim Transaction ID               
DWBDWEET  DIM       1      1        79    WebServices extract type           
.                                         0 - DVA                              
.                                         1 - DVA & Medicare                   
.                                         2 - Medicare Only                    
WBDWAMTC  FORM      12.2   8        80    Amount Claimed                     
WBDWAMDP  FORM      12.2   8        88    Amount Paid by DVA                 
WBDWAMMP  FORM      12.2   8        96    Amount Paid by Medicare            
WBDWPDAT  DIM       8      8        104   Payment Date                       
WBDWSTAT  DIM       2      2        112   Closed Status                      
.                                         Spaces - not closed                  
.                                         " 0" = Closed                        
.                                         " 1" = Closed with Write Off         
.                                         " 2" = Closed with Payment           
.                                         " 3" = Closed with WO & Pymt         
WBDWCLID  DIM       6      6        114   Claim ID                           
WBDWRKEY  DIM       24     24       120   Report Retrieval Key / Trans Id.   
.                                         Consists of:                         
.                                         PayeeProviderNum (pppppppp)          
.                                         PMSClaimID (xxxxxx)                  
.                                         Authorisation/Lodgement Date (ddmmyyy
.                                         y)                                   
.                                         Format: ppppppppxxxxxxddmmyyyy       
WBDWOKEY  DIM       36     36       144   O/P outbokaf key                   
WBDWPRAC  DIM       10     10       180   Medical Practice                   
WBDWMSID  DIM       36     36       190   Message Id                         
WBDWPROV  DIM       8      8        226   Provider Number                    
WBDWCTYP  DIM       2      2        234   DVAW Type                          
.                                         O = General                          
.                                         S = Specialist                       
.                                         P = Pathology                        
WBDWCUID  DIM       10     10       236   Created By Web User ID (websecaf)  
WBDWCDAT  DIM       8      8        246   Date Record Created (CCYYMMDD)     
WBDWCTIM  DIM       8      8        254   Time Record Created (HH:MM:SS)     
WBDWUUID  DIM       10     10       262   Updated By Web User ID (websecaf)  
WBDWUDAT  DIM       8      8        272   Date Record Updated (CCYYMMDD)     
WBDWUTIM  DIM       8      8        280   Time Record Updated (HH:MM:SS)     
WBDWSPAR  DIM       100    100      288   Spare Variable                     
.
.End of Record                      388  
.
. Redefine FORM fields from key
. -----------------------------
WBDWFLAG  FORM      2
WBDWEETP  FORM      1
