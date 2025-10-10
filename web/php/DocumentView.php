<?php
/*
.----------------------------------------------------------------------
. Program       : DocumentView.php
.
. Function      : Return Clinical Document from Storage Location.
.                 Avoids need to have the directory in web path for security.
.
. Modifications :
.
. V11.04.02 07/08/2024  Don Nguyen     TSK 0937761, 0938325
.                       Referenced updated db connection variable (setup.php)
. V11.04.01 15/07/2024  Don Nguyen     TSK 0937761, 0938325
.                       Added support for SQL Server database (dbtype="mssql")
. V11.00.02 09/12/2020  Don Nguyen     TSK 0898865
.                       Added ability to return a document as an attachment.
.                       Added "Content-Length: " to headers.
. V11.00.01 16/07/2020  Don Nguyen     TSK 0894325
.                       Added support for ".txt" files
. V10.14.02 21/05/2019  Sunny          Task 0874438 
.                       Added .docx support
. V10.14.01 10/05/2019  Sunny          Task 0874438 
.                       Added .rtf
. V10.12.01 11/05/2018  Jill Parkinson Task 0856928
.                       Added .tif
. V10.04.01 01.07.2014  B.G.Ackland
.                       Added Close to Oracle Connection
.----------------------------------------------------------------------
PRGID     INIT      "DocumentView.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "View Clinical Document"
.----------------------------------------------------------------------
*/
 require "setup.php";

 $secureid = (isset($_SERVER["REMOTE_USER"])) ? $_SERVER["REMOTE_USER"] : null;

 if ($secureid==null) { echo "Invalid Security"; exit(1); }

 $filename = (isset($_REQUEST["filename"])) ? $_REQUEST["filename"] : null;
 $location = (isset($_REQUEST["location"])) ? $_REQUEST["location"] : null;
 $attachment = (isset($_REQUEST["attachment"])) ? $_REQUEST["attachment"] : null;

 $qry = "SELECT * FROM OBSPCTAF WHERE OBPTSLID = :location";

 if ($dbtype == "mssql") {
   try {
     $sth = $conn->prepare($qry);
     $sth->bindParam(':location', $location, PDO::PARAM_STR);

     if (!$sth->execute()) {
       error_log("PDO_Statement execute error: " . implode(" | ",$sth->errorInfo()));
       echo "ERROR: ".implode(" | ",$sth->errorInfo());
       closeConnection();
       exit(1);
     }

     $LocationRecord = $sth->fetch(PDO::FETCH_ASSOC);

   } catch (PDOException $e) {
     error_log("PDO Exception: " . $e->getMessage() . " | SQL: $qry");
     echo "ERROR: " . $e->getMessage();
     closeConnection();
     exit(1);
   }
 }
 else {
   $rs=oci_parse($conn,$qry) or die ("Invalid Location");

   oci_bind_by_name($rs, ':location', $location);
   if (!oci_execute($rs)) { echo oci_error($rs); exit(1);}

   $LocationRecord=oci_fetch_array($rs,OCI_BOTH+OCI_RETURN_NULLS);
 }

 $LocationPath=$LocationRecord["OBPTSDIR"];

 if (!file_exists("$LocationPath$filename")) {
   echo "File not found: $filename";
 } else {
   $type = strtolower(substr($filename, strrpos($filename, ".")));
   $content_type = "";
   if ($type == ".txt")  $content_type = "text/plain";
   if ($type == ".html") $content_type = "text/html";
   if ($type == ".pdf")  $content_type = "application/pdf";
   if ($type == ".doc")  $content_type = "application/ms-word";
   if ($type == ".docx") $content_type = "application/ms-word";
   if ($type == ".rtf")  $content_type = "application/ms-word";
   if ($type == ".jpg")  $content_type = "image/jpeg";
   if ($type == ".jpeg") $content_type = "image/jpeg";
   if ($type == ".png")  $content_type = "image/png";
   if ($type == ".gif")  $content_type = "image/gif";
   if ($type == ".tif")  $content_type = "image/tif";
   if ($content_type!="") {
     header("Content-Type: " . $content_type);
     if ($attachment == "1") {
       header("Content-Disposition: attachment;filename=\"" . $filename . "\"");
     }
     else {
       header("Content-Disposition: filename=\"" . $filename . "\"");
     }
     header("Content-Length: " . filesize($LocationPath.$filename));
     readfile($LocationPath.$filename);
   } else {
     echo "<p style='text-align:center'>The attachment is not configured as a available content type.";
     echo "<p style='text-align:center'>Please contact your systems administrator.";
   }
 }

 closeConnection();

function closeConnection() {
  global $conn, $dbtype;

  if ($dbtype == "mssql") {
    $conn = null;
  }
  else {
    oci_close($conn);
  }
}
?>
