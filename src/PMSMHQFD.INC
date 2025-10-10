. V11.04.01 29/02/2024 PVL C-0939978 Created FD - NIHC IHI MyHR Upload Request D
. *----------------------------------------------------------------------
. * Include Name  :   PMSMHQFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   NIHC IHI Upload MyHR Request Detail
. *
. * File Type     :   SQL
. *
. * File Name     :   pmsmhqaf.dat
. *
. * Index Values  :   KEY68   KEY74   KEY76   KEY76   KEY68   KEY76   KEY90  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSMHQA1   IFILE    SQL, FIXED=791, KEY="U1-2,3-52,53-60,61-68"
PMSMHQA2   IFILE    SQL, FIXED=791, KEY="U79-84,1-2,3-52,53-60,61-68"
PMSMHQA3   IFILE    SQL, FIXED=791, KEY="U631-638,1-2,3-52,53-60,61-68"
PMSMHQA4   IFILE    SQL, FIXED=791, KEY="U85-92,1-2,3-52,53-60,61-68"
PMSMHQA5   IFILE    SQL, FIXED=791, KEY="U3-52,1-2,53-60,61-68"
PMSMHQA6   IFILE    SQL, FIXED=791, KEY="U93-100,1-2,3-52,53-60,61-68"
PMSMHQA7   IFILE    SQL, FIXED=791, KEY="U79-84,639-646,647-654,1-2,3-52,53-60,61-68"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMMQRTYP  DIM       2      2        1     Request Type                       
.                                         "10" - Upload to MyHR                
PMMQCODE  DIM       50     50       3     Request Code                       
.                                         "10" - Unique Transaction ID         
PMMQRDAT  DIM       8      8        53    Request Date                       
PMMQRTIM  DIM       8      8        61    Request Time                       
PMMQRUID  DIM       10     10       69    Request User ID (websecaf)         
PMMQHOSP  DIM       6      6        79    Hospital Code                      
PMMQEPID  DIM       8      8        85    Source Episode ID (Visit Number)   
PMMQADAT  DIM       8      8        93    Admission Date                     
PMMQREAS  DIM       200    200      101   Admission Reason                   
PMMQETYP  DIM       1      1        301   Episode Type                       
PMMQELCY  DIM       2      2        302   Episode Life Cycle                 
PMMQCONS  DIM       1      1        304   Consent to Upload MyHR             
PMMQAUTH  DIM       10     10       305   Author (HCP Code)                  
.                                         Display Code - Name on Template      
PMMQRHCP  DIM       10     10       315   Responsible HCP at Discharge (Code)
.                                         Display Code - Name on Template      
PMMQB64P  DIM       200    200      325   Base64 Document Path               
PMMQMIME  DIM       6      6        525   MIME File-Type                     
PMMQFLNM  DIM       50     50       531   Document File Name (Category wi)   
.                                         - obspcoaf                           
PMMQSUBJ  DIM       50     50       581   Subject from new Document Type     
.                                         either IP / ED Discharge Summary     
PMMQURNO  DIM       8      8        631   UR Number                          
PMMQCDAT  DIM       8      8        639   Date Created                       
PMMQCTIM  DIM       8      8        647   Time Created                       
PMMQCUID  DIM       10     10       655   Created By                         
PMMQUDAT  DIM       8      8        665   Date Updated                       
PMMQUTIM  DIM       8      8        673   Time Updated                       
PMMQUUID  DIM       10     10       681   Updatd By                          
PMMQSPAR  DIM       100    100      691   Spare                              
.
.End of Record                      791  
.
