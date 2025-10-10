. *----------------------------------------------------------------------
. * Include Name  :   PMSCEXTD.INC
. *
. * Function      :   CGI variables for PMSCEXFD - pmscexaf.dat
. *----------------------------------------------------------------------
.  Modifications Done :
. *----------------------------------------------------------------------
.  V11.04.03  06/05/2024  Thanh T       TSK 0941543
.             Added PMCEX032 and PMCEX033
.  V11.04.02  22/01/2024  Ebon Clements TSK 0932545
.             Added PMCEX028,PMCEX029,PMCEX030,PMCEX031
.  V11.04.01  12/01/2024  Alina Bhari   TSK 0932545
.             Added PMCEX027
.  V11.00.01  30/04/2020  Thanh T       TSK 0876574
.             Added PMCEX026
.  V10.13.01  22/08/2018  Peter Vela    TSK 0859742
.             Added Contact Medicare Number, Referene, DOB
.  V10.07.01  04/01/2016  Ebon Clements TSK 0294154
.             Added send SMS
.  V10.03.01  08/11/2011  Ebon Clements CAR 248529
.             Added counter  
.  V10.02.02  08/06/2011  Ebon Clements CAR 239530
.             Added PMCEX019
.  V10.02.01  07/06/2011  J.Tan         CAR 239592
.             Added Second given name
.  V9.05.00   24/03/2006  Ebon Clements CAR 79277
.             Created include
. *----------------------------------------------------------------------
.Name     Type      Length  Description
.----     ----      ------  -----------
PMCEX001  DIM       8       U/R Number
PMCEX002  DIM       3       Type of Contact
PMCEX003  DIM       3       Counter
PMCEX004  DIM       4       Title
PMCEX005  DIM       40      Surname
PMCEX006  DIM       40      Given Name
PMCEX007  DIM       35      Address Line 1
PMCEX008  DIM       35      Address Line 2
PMCEX009  DIM       35      Address Line 3
PMCEX010  DIM       35      Address Line 4
PMCEX011  DIM       8       Post Code
PMCEX012  DIM       20      Telephone Private
PMCEX013  DIM       20      Telephone Business
PMCEX014  DIM       20      Telephone Mobile
PMCEX015  DIM       10      Relationship
PMCEX016  DIM       80      Email Address
PMCEX017  DIM       1       Send Letter 1=yes
PMCEX018  DIM       1       Active 1=inactive
PMCEX019  DIM       35      Second Give Name
PMCEX020  DIM       3       Country of Birth (Cat C)
PMCEX021  DIM       8       Inactivate Date (CCYYMMDD)
PMCEX022  DIM       1       Send SMS
PMCEX023  DIM       10      Contact Medicare Number
PMCEX024  DIM       1       Contact Reference Number
PMCEX025  DIM       8       Contact DOB
PMCEX026  DIM       1       Send SMS Flag
PMCEX027  DIM       50      Free Text Comments Line 1
PMCEX028  DIM       50      Free Text Comments Line 2 
PMCEX029  DIM       50      Free Text Comments Line 3
PMCEX030  DIM       50      Free Text Comments Line 4
PMCEX031  DIM       50      Free Text Comments Line 5
PMCEX032  DIM       3      Main Language Spoken at Home 1
PMCEX033  DIM       3      Main Language Spoken at Home 2
.
.-------------------------------------------------------------------------
. Display variables for Free Text Comments        
.-------------------------------------------------------------------------
PMCEXD27  DIM       50      Display Free Text Comments Line 1
PMCEXD28  DIM       50      Display Free Text Comments Line 2 
PMCEXD29  DIM       50      Display Free Text Comments Line 3
PMCEXD30  DIM       50      Display Free Text Comments Line 4
PMCEXD31  DIM       50      Display Free Text Comments Line 5
