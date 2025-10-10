. V11.04.01 30/05/2024 IT C-0919569 Added Index 2                               
. *----------------------------------------------------------------------
. * Include Name  :   PATECHFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Patient Exploding Charges Table    
. *
. * File Type     :   SQL
. *
. * File Name     :   patechaf.dat
. *
. * Index Values  :   KEY30   KEY30                                          
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PATECHA1   IFILE    SQL, FIXED=100, KEY="U1-3,4-6,43-48,49-54,7-15,16-18"
PATECHA2   IFILE    SQL, FIXED=100, KEY="U7-15,1-3,4-6,43-48,49-54,16-18"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PTECCTYP  DIM       3      3        1     Claim Type (Cat CL)                
PTECATYP  DIM       3      3        4     Admission Type (Cat A)             
PTECMBSC  DIM       9      9        7     MBS Code                           
DPTECUNI  DIM       3      3        16    Unique Counter
PTECEMCH  DIM       9      9        19    Exploding Miscellaneous Charge     
PTECOPPC  DIM       3      3        28    Operating Personnel Code (Cat OP)  
PTEC1MCF  FORM      3.2    4        31    1st % of Miscellaneous Charge Fee  
PTEC2MCF  FORM      3.2    4        35    2nd % of Miscellaneous Charge Fee  
PTEC3MCF  FORM      3.2    4        39    3rd % of Miscellaneous Charge Fee  
PTECHFND  DIM       6      6        43    Health Fund (Active)               
PTECHGRP  DIM       6      6        49    Health Fund Group (Active)         
PTECQNTY  DIM       3      3        55    Quantity                           
PTECSPAR  DIM       42     42       58    Spare                              
.
.End of Record                      100  
.
.Redefine form field key
.-----------------------
PTECUNIQ  FORM      3
.
. Fields used in PATITMRD.PBL
.---------------------------
WKECCTYP  DIM       3                     Claim Type (Cat CL)
WKECATYP  DIM       3                     Admission Type (Cat A)
WKECHFND  DIM       6                     Health Fund (Active)
WKECHGRP  DIM       6                     Health Fund Group (Active)
WKECMBSC  DIM       9                     MBS Code

