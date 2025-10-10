. V11.04.01 24/11/2023 JJA 0919335 Initial Version
. *----------------------------------------------------------------------
. * Include Name  :   PATDDHFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Health Fund History Dates          
. *
. * File Type     :   SQL
. *
. * File Name     :   patddhaf.dat
. *
. * Index Values  :   KEY17                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PATDDHA1   IFILE    SQL, FIXED=316, KEY="U1-6,7-8,9-16,265-265"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PTDDFUND  DIM       6      6        1     Health Fund                        
PTDDFTYP  DIM       2      2        7     Field Type                         
.                                         01 - HCP Equivalent                  
.                                         02 - Health Fund Group               
.                                         03 - Theatre Charging Indicator      
PTDDDTTO  DIM       8      8        9     Effective Date To                  
PTDDFLD1  DIM       80     80       17    Field 1                            
PTDDFLD2  DIM       80     80       97    Field 2                            
PTDDCFD1  DIM       10     10       177   Coded Field 1                      
PTDDCFD2  DIM       10     10       187   Coded Field 2                      
PTDDFVL1  FORM      12.2   8        197   Form Value 1                       
PTDDFVL2  FORM      12.2   8        205   Form Value 2                       
PTDDCRBY  DIM       10     10       213   Created By                         
PTDDCRDT  DIM       8      8        223   Created Date                       
PTDDCRTM  DIM       8      8        231   Created Time                       
PTDDUPBY  DIM       10     10       239   Updated By                         
PTDDUPDT  DIM       8      8        249   Updated Date                       
PTDDUPTM  DIM       8      8        257   Updated Time                       
PTDDDLEN  DIM       1      1        265   Deleted Entry = 1
PTDDSPAR  DIM       50     50       266   Spare               
.
.End of Record                      316  
.
. Other field definitions
. -----------------------
.
. Fields used in PATDDHRD.PBL
.---------------------------
WKDHAFND  DIM       6
WKDHFTYP  DIM       2
WKDHDTTO  DIM       8
WKDHDLEN  DIM       1

