. PATHCSHT.INC
. ------------
.
.          FILE               :  PATHCSHT
.          DESCRIPTION        :  HCS DOCTOR TRANSFER DATA AUDIT FILE
.          RECORD LENGTH      :  64
.
PATHCHT1   IFILE     SQL, FIXED=67, KEY="U1-8"
SAVHCSHT   FILE      SQL, FIXED=67
.
.          MODIFICATIONS: V5.00 02/06/89 K.Peak
.                               Change U/R & Admission to 8 characters
.
. NAME     TYPE   LENGTH   PHYSICAL  START LOC.   DESCRIPTION
. ----     ----   ------   --------  ----------   -----------
DHHTUNIQ   DIM       8           8         1      Unique Key from Control file
HHTURNO    DIM       8           8         9      U/R Number
HHTDATE    DIM       6           6        17      Transfer Date
HHTCODE    DIM       6           6        23      New Doctor Code
HHTADMN    DIM       8           8        29      Admission Number
HHTSPAR    DIM      30          30        37      Spare Variable
.
.END OF RECORD                            67
. 
.  redefine form fields from key
.  -----------------------------
. NAME     TYPE      LENGTH     START LOC.   DESCRIPTION
. ----     ----      ------     ----------   -----------
HHTUNIQ    FORM         8             1      Unique Key from Control file
