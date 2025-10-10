. V11.04.01 29/11/2023 TTI C-0929044 Added Created User Id/Date/Time and        
. V                                  Updated User Id/Date/Time fields          
. V11.01.03 11/08/2021 PVL C-0909175 Added Service Type                         
. V11.01.02 06/08/2021 PVL C-0909175 Added Provider Number                      
. V11.01.01 20/07/2021 PVL C-0909175 Created BBSW FD                            
. *----------------------------------------------------------------------
. * Include Name  :   WEBBBSFD.INC
. *
. * Function      :   File Def'n Include for Web System Table                   
. *                   WebServices BBSW Table             
. *
. * File Type     :   SQL
. *
. * File Name     :   webbbsaf.dat
. *
. * Index Values  :   KEY30   KEY17   KEY24   KEY24   KEY35   KEY40   KEY53  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
WEBBBSA1   IFILE    SQL, FIXED=316, KEY="U1-3,4-5,6-6,7-14,15-22,23-30"
WEBBBSA2   IFILE    SQL, FIXED=316, KEY="U15-22,23-30,6-6"
WEBBBSA3   IFILE    SQL, FIXED=316, KEY="U23-30,7-14,15-22"
WEBBBSA4   IFILE    SQL, FIXED=316, KEY="U7-14,15-22,23-30"
WEBBBSA5   IFILE    SQL, FIXED=316, KEY="U1-3,31-38,7-14,15-22,23-30"
WEBBBSA6   IFILE    SQL, FIXED=316, KEY="U55-78,15-22,23-30"
WEBBBSA7   IFILE    SQL, FIXED=316, KEY="U171-206,15-22,23-30,6-6"
WEBBBSA8   IFILE    SQL, FIXED=316, KEY="U4-5,1-3,6-6,7-14,15-22,23-30"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
WBBSHOSP  DIM       3      3        1     Hospital ID (pathspaf)             
DWBBSFLG  DIM       2      2        4     Eclipse Status Flag                
.                                         ibaPAS Processing                    
.                                            0 = Not Sent                      
.                                            1 = Error (PAS validation)        
.                                            2 = Extracted                     
.                                         Eclipse - Processing                 
.                                            3 = Error (SA validation)         
.                                            4 = Posted                        
.                                            5 = Received                      
.                                         Eclipse - Reported                   
.                                            6 = Complete - Reported           
.                                         Eclipse - Remittance                 
.                                            7 = Reported                      
.                                            8 = Closed                        
WBBSMODL  DIM       1      1        6     webPas Module                      
.                                         1 = Emergency                        
.                                         2 = Private Practice                 
.                                         3 = Outpatient                       
WBBSUNIQ  DIM       8      8        7     Unique Identifier / Visit Number   
WBBSINVN  DIM       8      8        15    Invoice Number                     
WBBSBATN  DIM       8      8        23    Batch Number                       
WBBSURNO  DIM       8      8        31    U/R/ Number                        
WBBSPBAT  DIM       8      8        39    Previous Batch Number              
.                                         (Resubmission from)                  
WBBSNBAT  DIM       8      8        47    Next Batch Number                  
.                                         (Resubmission to)
WBBSTRID  DIM       24     24       55    Claim Transaction ID               
WBBSAMTC  FORM      12.2   8        79    Amount Claimed                     
WBBSAMTP  FORM      12.2   8        87    Amount Paid by Medicare            
WBBSPDAT  DIM       8      8        95    Payment Date                       
WBBSSTAT  DIM       2      2        103   Closed Status                      
.                                         Spaces - not closed                  
.                                         " 0" = Closed                        
.                                         " 1" = Closed with Write Of          
.                                         " 2" = Closed with Payment           
.                                         " 3" = Closed with WO & Pymt         
WBBSCLID  DIM       6      6        105   Claim ID                           
WBBSRKEY  DIM       24     24       111   Report Retrieval Key / Trans Id.   
.                                         Consists Of:                         
.                                         PayeeProviderNum                     
.                                         PMSClaimId                           
.                                         Authorisation/Lodgement Date         
.                                         Format:                              
.                                         ppppppppxxxxxxddmmyyyy               
WBBSOKEY  DIM       36     36       135   O/P outbokaf key                   
WBBSMSID  DIM       36     36       171   Message Id                         
WBBSPROV  DIM       8      8        207   Provider Number                    
WBBSSTYP  DIM       1      1        215   Service Type                       
.                                         P = Pathology                        
.                                         S = Specialist                       
.                                         O = General                          
WBBSCUID  DIM       10     10       216   Created By Web User ID (websecaf)  
WBBSCDAT  DIM       8      8        226   Date Record Created (CCYYMMDD)     
WBBSCTIM  DIM       8      8        234   Time Record Created (HH:MM:SS)     
WBBSUUID  DIM       10     10       242   Updated By Web User ID (websecaf)  
WBBSUDAT  DIM       8      8        252   Date Record Updated (CCYYMMDD)     
WBBSUTIM  DIM       8      8        260   Time Record Updated (HH:MM:SS)     
WBBSSPAR  DIM       48     48       268   Spare Variable                     
.
.End of Record                      316  
.
.Redefine Key Variables 
.----------------------
WBBSFLAG  FORM      2
