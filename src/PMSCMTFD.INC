. V11.04.01 20/12/2023 TTI C-0910994 Added PMCCFTAD to PMCCFCFC fields
. *----------------------------------------------------------------------
. * Include Name  :   PMSCMTFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Casemix Code Matrix Table          
. *
. * File Type     :   SQL
. *
. * File Name     :   pmscmtaf.dat
. *
. * Index Values  :   KEY34   KEY34   KEY34   KEY34   KEY34                  
. *
. *----------------------------------------------------------------------
. * Modifications :
. *----------------------------------------------------------------------
. * V11.01.02 06/04/2021 Tracey Nguyen  TSK 0901515
. *                      Added the following new fields using spare variable
. *                      a) 1 File type for ICD procedure (PMCCIPF)
. *                      b) 3 new CMBS Field Type (PMCCFTS4/PMCCFT5C/PMCCFT6C)
. *                      c) 3 new CMBS Codes From (PMCCPC4F,PMCCSC5F,PMCCTC6F)
. *                      d) 3 new CMBS Codes To   (PMCCPC4T/PMCCSC5T,PMCCTC6T)
. * V11.01.01 09/03/2021 Tracey Nguyen  TSK 0901515
. *                      Added Primary ICD Procedure 1-5 (PMCCICP1-5)
. *                      Increased file length from 300 to 400
. * V10.06.01 15/07/2015 J.Tan          CAR 319342
. *                      Changed Discharge UDF to Care Class
. * V10.03.02 20/09/2012 J.Tan          CAR 271474
. *                      Added index 5
. * V10.03.01 14/05/2012 Jill Parkinson CAR 265369
. *                      Added index 4
. * V10.01.02 20/01/2011 Ebon Clements CAR 233051
. *                      Added PMCCCONT and PMCCMIND
. * V10.01.01 25/11/2010 J.Tan         CAR 233082
. *                      Added 5th index
. * V9.12.01  05/06/2009 J.Tan         CAR 196010
. *                      ICD10 Disease code (Secondary/Tertiary)
. * V9.04.01  20/04/2005 Jill Habasque CAR 60087
. *                      Added index 4
. * V9.03.01  24/07/2003 Jill Habasque CAR 36530
. *                      Added record type to index, added 5 values for fields
. * V5.09.002 11/01/2001 JH  Take out Audit
. * V5.09.003 11/01/2001 JH  ADDED VARIABLES
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSCMTA1   IFILE    SQL, FIXED=560, KEY="U1-3,260-265,4-9,10-12,259-259,13-21,22-27"
PMSCMTA2   IFILE    SQL, FIXED=560, KEY="U260-265,1-3,4-9,10-12,259-259,13-21,22-27"
PMSCMTA3   IFILE    SQL, FIXED=560, KEY="U1-3,4-9,10-12,259-259,22-27,260-265,13-21"
PMSCMTA4   IFILE    SQL, FIXED=560, KEY="U13-21,1-3,4-9,10-12,259-259,22-27,260-265"
PMSCMTA5   IFILE    SQL, FIXED=560, KEY="U260-265,1-3,4-9,10-12,259-259,22-27,13-21"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMCCCCOD  DIM       3      3        1     Claim code (cat CL)                
PMCCHFUN  DIM       6      6        4     Health Fund                        
PMCCHFTY  DIM       3      3        10    Health Fund Type                   
PMCCCMCD  DIM       9      9        13    Casemix Code                       
DPMCCCNT  DIM       6      6        22    Counter                            
PMCCPODY  FORM      6      4        28    Pre Op Cut Off Days                
PMCCNPDY  FORM      6      4        32    No Pay Days                        
PMCCHBPT  FORM      6      4        36    High Boundary Point/Maximum Days St
PMCCCCDY  FORM      6      4        40    Critical Care Cut Off              
PMCCFTDG  FORM      1      2        44    Field type for Disch DRG           
.                                         Field type=0 - Ignore                
.                                                    1 - Mandatory             
.                                                    2 - Must be blank         
.                                                    3 - Exclusive             
PMCCDDRG  DIM       4      4        46    Discharge DRG                      
PMCCFTCM  FORM      1      2        50    Field type for CMBS                
PMCCPCMF  DIM       9      9        52    Primary CMBS from                  
PMCCPCMT  DIM       9      9        61    Primary CMBS to                    
PMCCFTSC  FORM      1      2        70    Field type for Secondary CMBS      
PMCCSCMF  DIM       9      9        72    Secondary CMBS fron                
PMCCSCMT  DIM       9      9        81    Secondary CMBS to                  
PMCCFTTC  FORM      1      2        90    Field type for Tertiary CMBS from  
PMCCTCMF  DIM       9      9        92    Tertiary CMBS from                 
PMCCTCMT  DIM       9      9        101   Tertiary CMBS to                   
PMCCFTDS  FORM      1      2        110   Field type for disch status        
PMCCDSTA  DIM       3      3        112   Discharge Status 1                 
PMCCDST2  DIM       3      3        115   Discharge Status 2                 
PMCCDST3  DIM       3      3        118   Discharge Status 3                 
PMCCDST4  DIM       3      3        121   Discharge Status 4                 
PMCCDST5  DIM       3      3        124   Discharge Status 5                 
PMCCFTDD  FORM      1      2        127   Field type for disch destination   
PMCCDDES  DIM       3      3        129   Discharge Destination 1 (Cat DD)   
PMCCDDE2  DIM       3      3        132   Discharge Destination 2 (Cat DD)   
PMCCDDE3  DIM       3      3        135   Discharge Destination 3 (Cat DD)   
PMCCDDE4  DIM       3      3        138   Discharge Destination 4 (Cat DD)   
PMCCDDE5  DIM       3      3        141   Discharge Destination 5 (Cat DD)   
PMCCFTAS  FORM      1      2        144   Field type for Adm Source          
PMCCASRC  DIM       3      3        146   Admission Source 1 (Cat S)         
PMCCASR2  DIM       3      3        149   Admission Source 2 (Cat S)         
PMCCASR3  DIM       3      3        152   Admission Source 3 (Cat S)         
PMCCASR4  DIM       3      3        155   Admission Source 4 (Cat S)         
PMCCASR5  DIM       3      3        158   Admission Source 5 (Cat S)         
PMCCFT1C  FORM      1      2        161   Field type for ICD disease         
PMCCPICD  DIM       9      9        163   Primary ICD disease 1 (PRIMARY)    
PMCCPIC2  DIM       9      9        172   Primary ICD disease 2 (AND/SECONDAR
PMCCPIC3  DIM       9      9        181   Primary ICD disease 3 (AND/TERTIARY
PMCCPIC4  DIM       9      9        190   Primary ICD disease 4 (OR/PRIMARY) 
PMCCPIC5  DIM       9      9        199   Primary ICD disease 5 (OR/PRIMARY) 
PMCCFTAT  FORM      1      2        208   Field type for Adm type            
PMCCATYP  DIM       3      3        210   Admission Type 1 (Cat A)           
PMCCATY2  DIM       3      3        213   Admission Type 2 (Cat A)           
PMCCATY3  DIM       3      3        216   Admission Type 3 (Cat A)           
PMCCATY4  DIM       3      3        219   Admission Type 4 (Cat A)           
PMCCATY5  DIM       3      3        222   Admission Type 5 (Cat A)           
PMCCFTAU  FORM      1      2        225   Field type for Adm UDF             
PMCCAUDF  DIM       3      3        227   Admission UDF 1                    
PMCCAUD2  DIM       3      3        230   Admission UDF 2                    
PMCCAUD3  DIM       3      3        233   Admission UDF 3                    
PMCCAUD4  DIM       3      3        236   Admission UDF 4                    
PMCCAUD5  DIM       3      3        239   Admission UDF 5                    
PMCCFTDU  FORM      1      2        242   Field type for Care Class          
PMCCDUDF  DIM       3      3        244   Care Class 1 (Cat CC)              
PMCCDUD2  DIM       3      3        247   Care Class 2 (Cat CC)              
PMCCDUD3  DIM       3      3        250   Care Class 3 (Cat CC)              
PMCCDUD4  DIM       3      3        253   Care Class 4 (Cat CC)              
PMCCDUD5  DIM       3      3        256   Care Class 5 (Cat CC)              
PMCCTYPE  DIM       1      1        259   Record Type                        
.                                         O - Overnight                        
.                                         D - Daycase                          
.                                         E - Either                           
PMCCCONT  DIM       6      6        260   Contract ID                        
PMCCMIND  FORM      6      4        266   Minum Days Stay                    
PMCCICP1  DIM       9      9        270   Primary ICD Procedure 1 (PRIMARY   
PMCCICP2  DIM       9      9        279   Primary ICD Procedure 2            
.                                         (AND/SECONDARY)                      
PMCCICP3  DIM       9      9        288   Primary ICD Procedure 3            
.                                         (AND/TERTIARY)                       
PMCCICP4  DIM       9      9        297   Primary ICD Procedure 4 (OR/PRIMARY
PMCCICP5  DIM       9      9        306   Primary ICD Procedure 5 (OR/PRIMARY
PMCCICPF  FORM      1      2        315   Field type for ICD Procedure       
PMCCFTS4  FORM      1      2        317   Field type for Fourth CMBS         
PMCCPC4F  DIM       9      9        319   Fourth CMBS from                   
PMCCPC4T  DIM       9      9        328   Fourth CMBS to                     
PMCCFT5C  FORM      1      2        337   Field type for Fifth CMBS          
PMCCSC5F  DIM       9      9        339   Fifth CMBS from                    
PMCCSC5T  DIM       9      9        348   Fifth CMBS to                      
PMCCFT6C  FORM      1      2        357   Field type for Sixth CMBS from     
PMCCTC6F  DIM       9      9        359   Sixth CMBS from                    
PMCCTC6T  DIM       9      9        368   Sixth CMBS to                      
PMCCFTAD  FORM      1      2        377   Field Type for Attending Dr        
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCADOC  DIM       10     10       379   Attending Doctor (patmi1af.adocta) 
PMCCFTCC  FORM      1      2        389   Field Type for Concession Card Type
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCCCT1  DIM       3      3        391   Concession Card Type 1 (cat ct)    
PMCCCCT2  DIM       3      3        394   Concession Card Type 2 (cat ct)    
PMCCCCT3  DIM       3      3        397   Concession Card Type 3 (cat ct)    
PMCCCCT4  DIM       3      3        400   Concession Card Type 4 (cat ct)    
PMCCCCT5  DIM       3      3        403   Concession Card Type 5 (cat ct)    
PMCCFDDU  FORM      1      2        406   Field Type for Discharge UDF       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCUDF1  DIM       3      3        408   Discharge UDF 1 (cat D1)           
PMCCUDF2  DIM       3      3        411   Discharge UDF 2 (cat D2)           
PMCCUDF3  DIM       3      3        414   Discharge UDF 3 (cat D3)           
PMCCUDF4  DIM       3      3        417   Discharge UDF 4 (cat D4)           
PMCCUDF5  DIM       3      3        420   Discharge UDF 5 (cat D5)           
PMCCFCTA  FORM      1      2        423   Field Type A                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCA1  DIM       3      3        425   Cat Code A 1                       
PMCCFCA2  DIM       3      3        428   Cat Code A 2                       
PMCCFCA3  DIM       3      3        431   Cat Code A 3                       
PMCCFCA4  DIM       3      3        434   Cat Code A 4                       
PMCCFCA5  DIM       3      3        437   Cat Code A 5                       
PMCCFCTB  FORM      1      2        440   Field Type B                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCB1  DIM       3      3        442   Cat Code B 1                       
PMCCFCB2  DIM       3      3        445   Cat Code B 2                       
PMCCFCB3  DIM       3      3        448   Cat Code B 3                       
PMCCFCB4  DIM       3      3        451   Cat Code B 4                       
PMCCFCB5  DIM       3      3        454   Cat Code B 5                       
PMCCFCTC  FORM      1      2        457   Field Type C                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCC1  DIM       3      3        459   Cat Code C 1                       
PMCCFCC2  DIM       3      3        462   Cat Code C 2                       
PMCCFCC3  DIM       3      3        465   Cat Code C 3                       
PMCCFCC4  DIM       3      3        468   Cat Code C 4                       
PMCCFCC5  DIM       3      3        471   Cat Code C 5                       
PMCCFCTD  FORM      1      2        474   Field Type D                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCDC  DIM       10     10       476   Code D                             
PMCCFCTE  FORM      1      2        486   Field Type E                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCEC  DIM       10     10       488   Code E                             
PMCCFCTF  FORM      1      2        498   Field Type F                       
.                                         0 = Ignore                           
.                                         1 = Mandatory                        
.                                         2 = Must be blank                    
.                                         3 = Exclude                          
PMCCFCFC  DIM       10     10       500   Code F                             
PMCCSPAR  DIM       50     50       510   Spare                              
.
.End of Record                      560  
.
.Redefine Key Variables
.----------------------
PMCCCNTR  FORM      6    
