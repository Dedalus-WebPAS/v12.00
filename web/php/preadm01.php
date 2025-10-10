<?php
/*
.----------------------------------------------------------------------
. Program       : preadm01.php
.
. Function      : Preadmission Portal Interface
.
. Requirements  : PHP MSSQL Configuration
.
. Modifications :
.
.     V11.04.01   19/06/2024  Don Nguyen    TSK 0937761
.                 Added support for SQL Server (MSSQL) database using the 
.                 'pdo_sqlsrv' driver; where portal_type="sqlsrv"
.     V10.05.02   B.G.Ackland 
.                 Add New CSC Trinity Portal Option
.     V10.05.01   B.G.Ackland CAR 302046
.                 Add New Parameter for Stored Procedure Name
.                 Add New Option to Execute using Stored Procedure Name
.----------------------------------------------------------------------
PRGID     INIT      "preadm01.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "Preadmission Portal Interface"
.----------------------------------------------------------------------
*/
require "setup.php";

$PortalType=$ini['portal_type'];

if ($PortalType=='oracle') {
   require "preadm01-oracle.php";
} 
else if ($PortalType=='sqlsrv') {
   require "preadm01-sqlsrv.php";  // using 'pdo_sqlsrv' driver
} else {
   require "preadm01-mssql.php";   // using 'pdo_dblib' driver
}
?>
