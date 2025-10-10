<?php
/*
.----------------------------------------------------------------------
. Program       : html2pdf.php
.
. Function      : Remote Server Conversion of HTML to PDF
.                 Enables web service request to perform conversion
.                 from alternate application server that is not 
.                 configured with wkhtmltopdf
.
. Modifications :
.     V12.00.02   21/07/2025  Don Nguyen    TSK 0963467
.                 Also remove newline characters from cmdline
.     V12.00.01   08/07/2025  Don Nguyen    TSK 0963467
.                 Prevent arbitrary code execution by removing any leading &
.                 trailing whitespaces from cmdline.
.     V11.04.01   01/08/2024  Don Nguyen    TSK 0948277
.                 Added code to prevent command injection
.----------------------------------------------------------------------
PRGID     INIT      "html2pdf.php"
VERSION   INIT      "V12.00.02"
PRGNAM    INIT      "Remote HTML to PDF Conversion"
.----------------------------------------------------------------------
 $validIP = array("192.168.16.63", "192.168.16.54", "192.168.18.142", "192.168.16.63");
 $validUser = "iba";
 $uid = $_SERVER['REMOTE_USER'];
 $svr = $_SERVER['REMOTE_ADDR'];
 if ($uid != $validUser)          exit("Invalid Security User ID");
 if (!(in_array($svr, $validIP))) exit("Invalid Security Server IP");
*/
 if (isset($_GET['cmdline'])) {
   $cmdline = trim(str_replace("\n", "", $_GET['cmdline']));

   // Prevent command injection by inspecting 'cmdline' (command args) for the
   // following illegal characters: | ; & $ > < \ ! #

   $regex = "/[|;&$><\\!#]/";  // reg. expr to match any illegal character
   if (preg_match($regex,$cmdline)) exit(1); // detected; exit with error

   // OK to pass 'cmdline' args to wkhtmltopdf
   passthru("/opt/iba/bin/wkhtmltopdf $cmdline");
 }
?>
