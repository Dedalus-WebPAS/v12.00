. V11.05.01 24/02/2025 JT C-0946490 Created FD
. *----------------------------------------------------------------------
. * Include Name  :   PMSHATFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Hospital Attributes                
. *
. * File Type     :   SQL
. *
. * File Name     :   pmshataf.dat
. *
. * Index Values  :   KEY39                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSHATA1   IFILE    SQL, FIXED=586, KEY="U1-3,4-6,7-31,32-39"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMHTHOSP  DIM       3      3        1     Hospital Id (pathspaf)             
.                                         Blank - for Single Hospital          
PMHTTYPE  DIM       3      3        4     Type of Attribute                  
.                                         001 - Discharge DRG Code for CWO     
PMHTKVAL  DIM       25     25       7     Key Value                          
.                                         Type of Attribute:                   
.                                         001 - Health Fund(D6),Disc.DRG(D4)   
PMHTSDAT  DIM       8      8        32    Effective Start Date (ccyymmdd)    
PMHTEDAT  DIM       8      8        40    Effective End Date (ccyymmdd)      
PMHTTXT1  DIM       80     80       48    Text 1                             
PMHTTXT2  DIM       80     80       128   Text 2                             
PMHTTXT3  DIM       80     80       208   Text 3                             
PMHTTXT4  DIM       80     80       288   Text 4                             
PMHTVAL1  DIM       6      6        368   Value 1                            
PMHTVAL2  DIM       6      6        374   Value 2                            
PMHTVAL3  DIM       6      6        380   Value 3                            
PMHTVAL4  DIM       6      6        386   Value 4                            
PMHTIND1  DIM       1      1        392   Indicator 1 (1=Yes/0=No)           
.                                         Type of Attribute:                   
.                                         001 - Active/Inactive                
PMHTIND2  DIM       1      1        393   Indicator 2 (Yes/No)               
PMHTIND3  DIM       1      1        394   Indicator 3 (Yes/No)               
PMHTIND4  DIM       1      1        395   Indicator 4 (Yes/No)               
PMHTCOD1  DIM       3      3        396   Coded Value 1                      
PMHTCOD2  DIM       3      3        399   Coded Value 2                      
PMHTCOD3  DIM       3      3        402   Coded Value 3                      
PMHTCOD4  DIM       3      3        405   Coded Value 4                      
PMHTCUSR  DIM       10     10       408   User who Created Record (websecaf) 
PMHTCDAT  DIM       8      8        418   Date Record Created (ccyymmdd)     
PMHTCTIM  DIM       8      8        426   Time Record Created (hh:mm:ss)     
PMHTUUSR  DIM       10     10       434   User who Updated Record (websecaf) 
PMHTUDAT  DIM       8      8        444   Date Record Updated (ccyymmdd)     
PMHTUTIM  DIM       8      8        452   Time Record Updated (hh:mm:ss)     
PMHTFUSR  DIM       10     10       460   User who Finished Attribute(websec)
PMHTFDAT  DIM       8      8        470   Date Attribute Finished (ccyymmdd) 
PMHTFTIM  DIM       8      8        478   Time Attribute Finished (hh:mm:ss) 
PMHTSPAR  DIM       100    100      486   Spare                              
.
.End of Record                      586  
.
. Fields used in PMSHATRD.PBL
.---------------------------
WKHATHOS   DIM        3                           Hospital id
WKHTTYPE   DIM        3                           Type of Attribute
WKHTDATE   DIM        8                           Effective date
WKHTKVAL   DIM        25                          Key value
WKHTXXDT   FORM        1                          Date Range error flag
WKHTINAC   DIM         1                          Active flag
.
