. V11.04.01 01/03/2024 PVL C-0939978 Created FD - NIHC IHI MyHR Upload Response 
. *----------------------------------------------------------------------
. * Include Name  :   PMSMHRFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   NIHC IHI Upload MyHR ResponseDetail
. *
. * File Type     :   SQL
. *
. * File Name     :   pmsmhraf.dat
. *
. * Index Values  :   KEY68   KEY74   KEY76   KEY76   KEY68                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSMHRA1   IFILE    SQL, FIXED=1445, KEY="U1-2,3-52,53-60,61-68"
PMSMHRA2   IFILE    SQL, FIXED=1445, KEY="U792-797,1-2,3-52,53-60,61-68"
PMSMHRA3   IFILE    SQL, FIXED=1445, KEY="U816-823,1-2,3-52,53-60,61-68"
PMSMHRA4   IFILE    SQL, FIXED=1445, KEY="U808-815,1-2,3-52,53-60,61-68"
PMSMHRA5   IFILE    SQL, FIXED=1445, KEY="U3-52,1-2,53-60,61-68"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMMJRTYP  DIM       2      2        1     Request Type                       
.                                         "10" - Upload to MyHR                
PMMJCODE  DIM       50     50       3     Request Code                       
.                                         "10" - Unique Transaction ID         
PMMJRDAT  DIM       8      8        53    Request Date (CCYYMMDD)            
PMMJRTIM  DIM       8      8        61    Request Time (HH:MM:SS)            
PMMJERRM  DIM       500    500      69    NIHC Error Message                 
.                                         Error message returned from within NI
.                                         HC's                                 
.                                         internal processes (if appropriate). 
PMMJRCOD  DIM       20     20       569   Response Code                      
.                                         Response from external system (HI    
.                                         Service/MyHR Service)                
PMMJRDSC  DIM       100    100      589   Response Code Description          
.                                         Response Description from external sy
.                                         stem (HI                             
.                                         Service/MyHR Service)                
PMMJRDET  DIM       100    100      689   Response Code Details              
.                                         Response details from external system
.                                          (HI                                 
.                                         Service/MyHR Service).               
PMMJSTAT  DIM       3      3        789   Status                             
.                                         Error code that corresponds to intern
.                                         al                                   
.                                         errors within NIHC.                  
PMMJHOSP  DIM       6      6        792   Hospital ID                        
PMMJHOSC  DIM       10     10       798   PasFacCd Hospital Code             
PMMJPAID  DIM       8      8        808   Patient Id / Visit Number          
PMMJPSID  DIM       8      8        816   MRN / UR Number                    
PMMJSEID  DIM       6      6        824   Source Episode Id                  
PMMJADAT  DIM       10     10       830   Admission Date                     
PMMJARES  DIM       200    200      840   Admission Reason                   
PMMJDDAT  DIM       10     10       1040  Discharge Date                     
PMMJRHCP  DIM       50     50       1050  Health Provider Identifier         
PMMJAUTH  DIM       50     50       1100  Health Provider Identifier Auth Id 
PMMJETYP  DIM       100    100      1150  Episode Type                       
PMMJELCI  DIM       5      5        1250  Episode Lifecycle ID               
PMMJCONW  DIM       3      3        1255  Consent Withdrawn                  
PMMJWARD  DIM       5      5        1258  Ward                               
.                                         Placeholder for future use           
PMMJROOM  DIM       5      5        1263  Room                               
.                                         Placeholder for future use.          
PMMJABED  DIM       5      5        1268  Bed                                
.                                         Placeholder for future use.          
PMMJEDTC  DIM       10     10       1273  Episode Date Created               
PMMJEDTM  DIM       10     10       1283  Episode Date Modified              
PMMJCDAT  DIM       8      8        1293  Date Created                       
PMMJCTIM  DIM       8      8        1301  Time Created                       
PMMJCUID  DIM       10     10       1309  Created By                         
PMMJUDAT  DIM       8      8        1319  Date Updated                       
PMMJUTIM  DIM       8      8        1327  Time Updated                       
PMMJUUID  DIM       10     10       1335  Update By                          
PMMJSPAR  DIM       100    100      1345  Spare                              
.
.End of Record                      1445 
.
