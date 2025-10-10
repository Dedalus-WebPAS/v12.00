<?php
/*
.----------------------------------------------------------------------
. Program       : preadm01-sqlsrv.php
.
. Function      : Pre-admission Portal Interface - SQL Server ('pdo_sqlsrv')
.
. Requirements  : PHP SQL Server Configuration
.
. Modifications :
.
.     V11.05.02   29/11/2024  Don Nguyen    TSK 0946366, 0949472
.                 Default "/tmp" if 'portal_tmp_doc_dir' ini config not defined
.     V11.05.01   26/11/2024  Don Nguyen    TSK 0954346
.                 Replaced "/tmp/" with 'portal_tmp_doc_dir' ini config value
.     V11.04.03   30/08/2024  Don Nguyen    TSK 0937761
.                 Use portal specific database config instead of setup.php
.     V11.04.02   07/08/2024  Don Nguyen    TSK 0937761
.                 Referenced updated db connection variable (setup.php)
.     V11.04.01   15/07/2024  Don Nguyen    TSK 0937761
.                 Re-wrote error handling for reportno=9 (Get PDF Form)
.     V11.03.00   19/06/2024  Don Nguyen    TSK 0937761
.                 Created NEW for SQL Server (MSSQL) using 'pdo_sqlsrv' driver
.----------------------------------------------------------------------
PRGID     INIT      "preadm01-sqlsrv.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "Pre-admission Portal Interface"
.----------------------------------------------------------------------
*/

// Get a connection to the Patient Portal database via PDO (pdo_sqlsrv)
$dsn = "sqlsrv:Server=".$ini['portal_srv'].";Database=".$ini['portal_sid'];
try {
  $portal_conn = new PDO($dsn, $ini['portal_uid'], $ini['portal_pwd']);
} catch (PDOException $e) {
  error_log("Patient Portal database connection error: " . $e->getMessage() . " | DSN: $dsn");
  die("Patient Portal database connection error: " . $e->getMessage());
}

$admissionid = (isset($_REQUEST["admissionid"])) ? $_REQUEST["admissionid"] : null;
$reportno = (isset($_REQUEST["reportno"])) ? $_REQUEST["reportno"] : null;
$admissdt = (isset($_REQUEST["admissdt"])) ? $_REQUEST["admissdt"] : null;
$admissno = (isset($_REQUEST["admissno"])) ? $_REQUEST["admissno"] : null;
$urnumber = (isset($_REQUEST["urnumber"])) ? $_REQUEST["urnumber"] : null;
$keywords = (isset($_REQUEST["keywords"])) ? $_REQUEST["keywords"] : null;
$frstdate = (isset($_REQUEST["frstdate"])) ? $_REQUEST["frstdate"] : null;
$lastdate = (isset($_REQUEST["lastdate"])) ? $_REQUEST["lastdate"] : null;
$doctcode = (isset($_REQUEST["doctcode"])) ? $_REQUEST["doctcode"] : null;
$comments = (isset($_REQUEST["comments"])) ? $_REQUEST["comments"] : null;
$hospitalstate = (isset($_REQUEST["hospitalstate"])) ? $_REQUEST["hospitalstate"] : null;
$hospitalcode = (isset($_REQUEST["hospitalcode"])) ? $_REQUEST["hospitalcode"] : null;
$hospitalname = (isset($_REQUEST["hospitalname"])) ? $_REQUEST["hospitalname"] : null;
$callproc = (isset($_REQUEST["callproc"])) ? $_REQUEST["callproc"] : null;
$status = (isset($_REQUEST["status"])) ? $_REQUEST["status"] : null;

$portal_url = $ini['portal_url'];
$portal_security_token = $ini['portal_security_token'];

$facility = $ini['portal_facility'];
if (isset($_GET['facility'])) { $facility = $_GET['facility'];}

$securenm = "";
$secureid = "";

$remoteUser=$_SERVER['REMOTE_USER'];

$sql = "SELECT WBSEUID, WBSENAM FROM WEBSECAF WHERE WBSELOGN=:remoteUser";

try {
  $sth = $conn->prepare($sql);
  $sth->bindParam(':remoteUser', $remoteUser, PDO::PARAM_STR);

  if ($sth->execute()) {
    $row = $sth->fetch(PDO::FETCH_NUM);

    $secureid=$row[0];
    $securenm=$row[1];

    $sth->closeCursor();
  }
  else { exit(1); }

} catch (PDOException $e) {
  echo "ERROR: " . $e->getMessage();
  error_log("PDO Exception: " . $e->getMessage() . " | SQL: $sql");
  exit(1);
}

if ($reportno==1) {
  $sql = "EXEC dbo.PortalInterface_webPASList :facility, :status, :frstdate, :lastdate, :doctcode";

  try {
    $sth = $portal_conn->prepare($sql);
    $sth->bindParam(':facility', $facility, PDO::PARAM_STR);
    $sth->bindParam(':status',   $status, PDO::PARAM_STR);
    $sth->bindParam(':frstdate', $frstdate, PDO::PARAM_STR);
    $sth->bindParam(':lastdate', $lastdate, PDO::PARAM_STR);
    $sth->bindParam(':doctcode', $doctcode, PDO::PARAM_STR);

    if ($sth->execute()) {
      $c = 0;  // row counter
      $reply = "function AddRows() {";

      while ($row = $sth->fetch(PDO::FETCH_NUM)) {
        $reply .= "\nt.addRow(\"";

        foreach ($row as $val)  // loop all columns of the row
        {
          $reply .= $val . "\",\"";  // append the column value
        }

        $reply.= "$c\");";  // append row counter
        $c++;
      }
       
      $reply .= "\n}";

      echo $reply;

      $sth->closeCursor();
    }

  } catch (PDOException $e) {
    echo "ERROR: " . $e->getMessage();
    error_log("PDO Exception: " . $e->getMessage() . " | SQL: $sql");
    exit(1);
  }
}

if ($reportno==2) {
  AdmissionJSON("EXEC dbo.PortalInterface_webPASAdmission :admissionid");
}

if ($reportno==3) {
  $sql = "EXEC dbo.PortalInterface_webPASUpdate :admissionid, :status, :secureid, :securenm, :urnumber, :admissno, :comments";

  try {
    $sth = $portal_conn->prepare($sql);
    $sth->bindParam(':admissionid', $admissionid, PDO::PARAM_STR);
    $sth->bindParam(':status',   $status, PDO::PARAM_STR);
    $sth->bindParam(':secureid', $secureid, PDO::PARAM_STR);
    $sth->bindParam(':securenm', $securenm, PDO::PARAM_STR);
    $sth->bindParam(':urnumber', $urnumber, PDO::PARAM_STR);
    $sth->bindParam(':admissno', $admissno, PDO::PARAM_STR);
    $sth->bindParam(':comments', $comments, PDO::PARAM_STR);

    if ($sth->execute()) {  // update success
      $sth->closeCursor();
    }
    else {
      echo "ERROR: " . implode(" | ", $sth->errorInfo());
      exit(1);
    }

  } catch (PDOException $e) {
    echo "ERROR: " . $e->getMessage();
    error_log("PDO Exception: " . $e->getMessage() . " | SQL: $sql");
    exit(1);
  }

  echo "";
  exit(0);
}

if ($reportno==4) {
  AdmissionJSON("EXEC dbo.PortalInterface_webPASDefaultReg :admissionid");
}

if ($reportno==5) {
  AdmissionJSON("EXEC dbo.PortalInterface_webPASDefaultNok :admissionid");
}

if ($reportno==6) {
  AdmissionJSON("EXEC dbo.PortalInterface_webPASDefaultAdm :admissionid");
}

if ($reportno==7) {
  AdmissionJSON("EXEC dbo.PortalInterface_webPASDefaultThr :admissionid");
}

if ($reportno==8) {
  AdmissionJSON("EXEC dbo.$callproc :admissionid");
}

if ($reportno==9) {  // Get PDF Form
  $AutoPrint = (isset($_REQUEST["AutoPrint"])) ? $_REQUEST["AutoPrint"] : null;
  $SaveFile = (isset($_REQUEST["SaveFile"])) ? $_REQUEST["SaveFile"] : null;

  $printURL="$portal_url/webPASView.php?SecurityToken=$portal_security_token".
            "&AutoPrint=$AutoPrint".
            "&UserFormID=$admissionid";

  $ch = curl_init();

  curl_setopt($ch, CURLOPT_URL, $printURL);
  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_HEADER, 0);
  curl_setopt($ch, CURLOPT_USERAGENT, "WEBPASREQUEST");

  $response = curl_exec($ch);

  if ($response===false || strpos($response,"ERROR")!==false) {
    echo $response;
    exit(1);
  }
  else {
    if ($SaveFile=="Y") {  // Save the PDF to the temp dir (portal_tmp_doc_dir)
      $tmp_doc_dir = array_key_exists('portal_tmp_doc_dir',$ini) ? $ini['portal_tmp_doc_dir'] : "/tmp";
      $filename = $tmp_doc_dir."/".substr(uniqid(),0,8).".pdf";
      $success = file_put_contents($filename, $response);

      // file_put_contents() returns the number of bytes that were written to
      // the file, or false on failure.
      // It may also return a non-Boolean value which evaluates to false.

      if ($success===false) {
        echo "ERROR: Unable to save the file.";
        exit(1);
      } else {
        echo "FILE:$filename";
      }
    } else {  // Return the raw file contents (with Content-Type set to PDF)
      header('Content-type: application/pdf');
      echo $response;
    }
  }

  exit(0);
}

if ($reportno==10) {
  $sql = "EXEC dbo.PortalInterface_webPASUpdateHospital ".
         " :admissionid, :secureid, :securenm, :hospitalstate,".
         " :hospitalcode, :hospitalname, :comments";

  try {
    $sth = $portal_conn->prepare($sql);
    $sth->bindParam(':admissionid', $admissionid, PDO::PARAM_STR);
    $sth->bindParam(':secureid', $secureid, PDO::PARAM_STR);
    $sth->bindParam(':securenm', $securenm, PDO::PARAM_STR);
    $sth->bindParam(':hospitalstate', $hospitalstate, PDO::PARAM_STR);
    $sth->bindParam(':hospitalcode', $hospitalcode, PDO::PARAM_STR);
    $sth->bindParam(':hospitalname', $hospitalname, PDO::PARAM_STR);
    $sth->bindParam(':comments', $comments, PDO::PARAM_STR);

    if ($sth->execute()) {  // update success
      $sth->closeCursor();
    }
    else {
      echo "ERROR: " . implode(" | ", $sth->errorInfo());
      exit(1);
    }

  } catch (PDOException $e) {
    echo "ERROR: " . $e->getMessage();
    error_log("PDO Exception: " . $e->getMessage() . " | SQL: $sql");
    exit(1);
  }

  echo "";
  exit(0);
}

if ($reportno==11) {
  $hospitalJSON  = file_get_contents('/opt/csc/etc/HospitalCodes.json');
  echo $hospitalJSON;
  exit();
}
 
function AdmissionJSON($sql) {
  global $portal_conn, $admissionid;

  try {
    $sth = $portal_conn->prepare($sql);
    $sth->bindParam(':admissionid', $admissionid, PDO::PARAM_INT);

    if ($sth->execute()) {
      $c = 0;  // row count

      $reply = "[";
      while ($row = $sth->fetch(PDO::FETCH_ASSOC))
      {
        $reply .= "{";

        if ($c > 0) {
          $reply .= ",";
        }
        else { $reply .= "\"cscportal\":\"1\","; }

        $i = 0;  // column count

        foreach ($row as $key => $val)
        {
          if ($i > 0) $reply .= ",";

          $reply .= "\"" . $key . "\":\"" . $val . "\"";

          ++$i;
        }
        $reply .= "}";
        ++$c;
      }
      $reply .= "]";
      echo $reply;

      $sth->closeCursor();
    }
  } catch (PDOException $e) {
    echo "ERROR: " . $e->getMessage();
    error_log("PDO Exception: " . $e->getMessage() . " | SQL: $sql");
    exit(1);
  }
}
?>
