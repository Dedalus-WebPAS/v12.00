. V9.08.001 26/10/2006 JT Created FD CAR 120001
. *----------------------------------------------------------------------
. * Include Name  :   TMPRBRFD.INC
. *
. * Function      :   File Def'n Include for New Zealand Private                
. *                   NZ Private Contract Procedure Revenue Breakdown File  
. *
. * File Type     :   SQL
. *
. * File Name     :   tmprbraf.dat
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
TMPRBRA1   IFILE    SQL, FIXED=110, KEY="U1-3,4-6,7-12,13-20,21-29,30-37,38-40" 
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
.TEMPHOSP  DIM       3      3        1     Hospital Code (pathspaf)           
.TEMPCLMC  DIM       3      3        4     Claim Code (Catg CL)               
.TEMPCNTR  DIM       6      6        7     Contract (Health Fund)             
.TEMPFTAB  DIM       8      8        13    Fund Table                         
.TEMPCPRC  DIM       9      9        21    Contract Procedure Code (patcmcaf) 
.TEMPEFDT  DIM       8      8        30    Effective Date (CCYYMMDD)          
.TEMPBRCD  DIM       3      3        38    Breakdown Code (Catg FI)           
.TEMPAMNT  FORM      14.2   9        41    Amount                             
.TEMPSPAR  DIM       60     60       50    Spare Variable                     
.
.End of Record                      110  
.
