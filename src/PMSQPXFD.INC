. V11.05.01 19/11/2024 TT C-0945766 Added PMPXAHC1 to PMPXATF5
. V11.04.02 01/11/2024 TT C-0953569 Changed Ethnicity 1 to Ancestry/Ethnicity 1
. V                                 and Ethnicity 2 to Ancestry/Ethnicity 2
. V11.04.01 20/03/2024 TT C-0941543 Added Ethnicity 1-2 & Main Language Spoken
.                                   At Home 1-2
. V11.04.01 21/12/2023 TT C-0936263 Initial version                            
. *----------------------------------------------------------------------
. * Include Name  :   PMSQPXFD.INC
. *
. * Function      :   File Def'n Include for Patient System                     
. *                   Queuing Patient Details Message Ext
. *
. * File Type     :   SQL
. *
. * File Name     :   pmsqpxaf.dat
. *
. * Index Values  :   KEY20                                                  
. *
. *----------------------------------------------------------------------
.
.Data File Definition
.--------------------
PMSQPXA1   IFILE    SQL, FIXED=657, KEY="U1-20"
.
.Name     Type      Length Physical Start Description
.----     ----      ------ -------- ----- -----------
DPMQXMES  DIM       20     20       1     Message Id                         
.PMPXUDT1  DIM       8      8        21    User Defined Date 1 (ccyymmdd)     
.PMPXUTM1  DIM       8      8        29    User Defined Time 1 (hh:mm:ss)     
.PMPXUDT2  DIM       8      8        37    User Defined Date 2 (ccyymmdd)     
.PMPXUTM2  DIM       8      8        45    User Defined Time 2 (hh:mm:ss)     
.PMPXUDT3  DIM       8      8        53    User Defined Date 3 (ccyymmdd)     
.PMPXUTM3  DIM       8      8        61    User Defined Time 3 (hh:mm:ss)     
.PMPXUDT4  DIM       8      8        69    User Defined Date 4 (ccyymmdd)     
.PMPXUTM4  DIM       8      8        77    User Defined Time 4 (hh:mm:ss)     
.PMPXUDT5  DIM       8      8        85    User Defined Date 5 (ccyymmdd)     
.PMPXUTM5  DIM       8      8        93    User Defined Time 5 (hh:mm:ss)     
.PMPXAHC1  DIM       10     10       101   Additional HCP 1
.PMPXAHG1  DIM       10     10       111   Additional HCP Group 1
.PMPXAGC1  DIM       2      2        121   Additional HCP Group Count 1
.PMPXAHC2  DIM       10     10       123   Additional HCP 2
.PMPXAHG2  DIM       10     10       133   Additional HCP Group 2
.PMPXAGC2  DIM       2      2        143   Additional HCP Group Count 2
.PMPXATF1  DIM       80     80       145   Identifying Gender Free Text
.PMPXATF2  DIM       80     80       225   Identifying Pronoun Free Text
.PMPXATF3  DIM       80     80       305   Additional Text Field 3
.PMPXATF4  DIM       80     80       385   Additional Text Field 4
.PMPXATF5  DIM       80     80       465   Additional Text Field 5
.PMPXETH1  DIM       3      3        545   Ancestry/Ethnicity 1        
.PMPXETH2  DIM       3      3        548   Ancestry/Ethnicity 2        
.PMPXLAN1  DIM       3      3        551   Main Language Spoken at Home 1     
.PMPXLAN2  DIM       3      3        554   Main Language Spoken at Home 2     
PMQXSPAR  DIM        100    100      557   Spare Variable                     
.
.End of Record                       657  
.
.Redefine Key Variables
.----------------------
PMQXMESI  FORM      20
