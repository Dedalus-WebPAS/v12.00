. V11.04.01 27/11/2023 TTI C-0932689 Added Additional Medical Record Key 1 to 5 
. V5.09.002 03/01/2001                                                          
. *----------------------------------------------------------------------
. * Include Name  :   MRTVISFD.INC
. *
. * Function      :   File Def'n Include for Medical Records                    
. *                   Medical Record Visit Links         
. *
. * File Type     :   SQL
. *
. * File Name     :   mrtvisaf.dat
. *
. * Index Values  :   KEY8    KEY18                                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
MRTVISA1   IFILE    SQL, FIXED=119, KEY="U1-8"
MRTVISA2   IFILE    SQL, FIXED=119, KEY="U9-18,1-8"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
MRVSVSNO  DIM       8      8        1     Visit Number                       
MRVSMKEY  DIM       10     10       9     Medical Record Unique Key          
MRVSXKY1  DIM       10     10       19    Additional Medical Record Key 1    
MRVSXKY2  DIM       10     10       29    Additional Medical Record Key 2    
MRVSXKY3  DIM       10     10       39    Additional Medical Record Key 3    
MRVSXKY4  DIM       10     10       49    Additional Medical Record Key 4    
MRVSXKY5  DIM       10     10       59    Additional Medical Record Key 5    
MRVSSPAR  DIM       50     50       69    Spare                              
.
.End of Record                      119  
.
