.---------------------------------------------------------------------
. Get Common System Parameters - Variables used in GTCMPA00
.----------------------------------------------------------------------
. V11.05.01  24/03/2025  Ebon Clements  TSK 0958460
.            Changed CPARUSER to 10 characters
. V11.01.00  23/02/2021  Thanh T       TSK 0891886
.            Initial version
.----------------------------------------------------------------------
.
CPARPARM  DIM       8 (Parameter ID)
CPARMHOS  FORM      1 (Multi Hospital flag)
CPARUSER  DIM       10 (Logon User ID)
.
CPARERRO  FORM      1 (1 - Read failed
.                      0 - Read OK)

.******************************************************************************
.*        COMPARFD - Hospital Level Parameter definitions                     *
.******************************************************************************
PTCNOLDR  FORM      12       Number of minutes before highlighting Leave Red
