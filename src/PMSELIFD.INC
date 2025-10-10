. V11.04.01 01/07/2024 JT C-0942917 New file to store items from Eligibility che
. *----------------------------------------------------------------------
. * Include Name  :   PMSELIFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Items recorded on Eligibility Check
. *
. * File Type     :   SQL
. *
. * File Name     :   pmseliaf.dat
. *
. * Index Values  :   KEY12                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSELIA1   IFILE    SQL, FIXED=143, KEY="U1-8,9-9,10-12"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
PMEIVISN  DIM       8      8        1     Visit Number                       
PMEIRTYP  DIM       1      1        9     Record Type                        
.                                         1=Theatre Fee Code/MBS               
.                                         2=Miscellaneous item Code            
PMEICNTR  DIM       3      3        10    Counter                            
PMEIITMN  DIM       9      9        13    Theatre Fee Code/MBS or Misc.Code  
PMEISERV  FORM      5      4        22    No of Items                        
PMEIGSTE  DIM       1      1        26    Disabled GST ? (1=Yes)             
.                                         -GST fields can only be entered for 
.                                         item with GST Applicable='Either'
PMEIGSTA  DIM       1      1        27    GST Payable 1=Yes, 0=No            
.                                         -Theatre/Misc.Item with Keyin GST    
PMEIGSTC  DIM       6      6        28    GST Code                           
.                                         -Theatre/Misc.item with keyin GST    
PMEIKEYI  DIM       1      1        34    Keyin Rebate amount for Misc.item ?
.                                         -SJOG IFC
.                                           Misc.Item with Keyin Rebate option  
.                                              1 = Yes, 0 = No
.                                           Theatre MBS item (Recordtype=1)
.                                              X = MBS item from Booking
PMEIAMNT  FORM      12.2   8        35    Item Amount
.                                         -SJOG IFC
.					     Misc.item with Keyin Rebate option
.                                         -HEA IFC
.                                            Item amount
PMEISPAR  DIM       100    100      43    Spare variable                     
.
.End of Record                      143  
.
