. *----------------------------------------------------------------------
. * Include Name  :   PATFN2TD.INC
. *
. * Function      :   CGI variables for Overnight tables
. * Modifications :
. *
. *        V11.05.01 20/01/2025  J.Tan           TSK 0946490
. *                  Mod for CWO payment model
. *        V11.02.00 05/04/2022 J.Tan   TSK 0814566
. *                  Created
. *----------------------------------------------------------------------
.
.  Modifications  :
.
.Health Fund On Hold Invoice
.
.Name     Type      Length   Description
.----     ----      ------   -----------
FNEXT001  DIM       6         * Health Fund Code
FNEXT002  FORM      1         * Payment Model/Billing Mech. Ventilation Hrs
.                               0=No, 1=EPM, 2=CWO
FNEXT003  FORM      6.2       * Mech. Ventilation Daily Rate
FNEXT004  FORM      2         * Hours for MV Additional Day
FNEXT005  DIM       9         * Misc. charge code for Mech vent
FNEXT006  DIM       3         * Hospital Code
FNEXT007  DIM       8         * Effective Todate
.
