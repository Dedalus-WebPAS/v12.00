. V11.04.01 24/11/2023 TTI C-0871324 Initial version                            
. *----------------------------------------------------------------------
. * Include Name  :   MRTPLLFD.INC
. *
. * Function      :   File Def'n Include for Medical Records                    
. *                   Medical Records Pulling List       
. *
. * File Type     :   SQL
. *
. * File Name     :   mrtpllaf.dat
. *
. * Index Values  :   KEY20                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
MRTPLLA1   IFILE    SQL, FIXED=309, KEY="U1-8,9-18,19-20"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
MRPLVISN  DIM       8      8        1     Visit Number                       
MRPLMRKY  DIM       10     10       9     Medical Record Key                 
MRPLRQST  DIM       2      2        19    Request Status                     
.                                         01 = Keep                            
.                                         02 = Cancelled/Removed from List     
MRPLCUID  DIM       10     10       21    Added By UserID (from websecaf)    
MRPLCDAT  DIM       8      8        31    Date Record Added                  
MRPLCTIM  DIM       8      8        39    Time Record Added                  
MRPLUUID  DIM       10     10       47    Updated By UserID (from websecaf)  
MRPLUDAT  DIM       8      8        57    Date Record Updated                
MRPLUTIM  DIM       8      8        65    Time Record Updated                
MRPLUDF1  DIM       10     10       73    User Defined Field 1               
MRPLUDF2  DIM       10     10       83    User Defined Field 2               
MRPLUDC1  DIM       3      3        93    User Defined Coded Field 1         
MRPLUDC2  DIM       3      3        96    User Defined Coded Field 2         
MRPLFTX1  DIM       80     80       99    Free text field 1                  
MRPLFTX2  DIM       80     80       179   Free Text Field 2                  
MRPLSPAR  DIM       50     50       259   Spare                              
.
.End of Record                      309  
.
