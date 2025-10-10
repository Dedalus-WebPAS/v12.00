<?php
/*
.----------------------------------------------------------------------
. Program       : StyleSheet.php
.
. Function      : Return Site Configured Style Sheet
.
. Modifications :
.
. V11.04.02  07/08/2024  Don Nguyen         TSK 0938324, 0938327
.                        Referenced updated db connection variable (setup.php)
. V11.04.01  30/07/2024  Don Nguyen         TSK 0938324
.                        Added support for SQL Server database (dbtype="mssql")
. V10.05.01  08.08.2014  B.G.Ackland        CAR 300303
.                        General Utility to return and save CSS configuration
.                        by Page.
. V10.05.00  17.07.2014  B.G.Ackland
.                        New
.----------------------------------------------------------------------
PRGID     INIT      "StyleSheet.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "Site Defined Dynamic Style Sheet"
.----------------------------------------------------------------------
*/
//
 require "setup.php";

 $secureid = (isset($_SERVER["REMOTE_USER"])) ? $_SERVER["REMOTE_USER"] : null;
 if ($secureid==null) { echo "ERROR: Invalid Security"; exit(1); }

 $reportno = (isset($_REQUEST["reportno"])) ? $_REQUEST["reportno"] : null;
 $pagekey  = (isset($_REQUEST["pagekey"]))  ? $_REQUEST["pagekey"] : null;
 $classkey = (isset($_REQUEST["classkey"])) ? $_REQUEST["classkey"] : null;
 $classval = (isset($_REQUEST["classval"])) ? $_REQUEST["classval"] : null;

 switch($reportno) {
  case 1: // return a Style Sheet Content for the Page Key
    header("Content-type: text/css");

    if ($dbtype == "mssql") {
      $qry = "SELECT WBPCCLS, WBPCVAL FROM WEBPCLAF WHERE WBPCPAG=:pagekey";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':pagekey', $pagekey, PDO::PARAM_STR);

        if (!$sth->execute()) {
          error_log("PDO_Statement execute error: " . implode(" | ", $sth->errorInfo()));
          echo "ERROR: " . implode(" | ", $sth->errorInfo());
          closeConnection();
          exit(1);
        }

        $reply = "";
        while ($row = $sth->fetch(PDO::FETCH_NUM)) {
          $classnam=$row[0];
          $classval=$row[1];
          $reply .= ".$classnam { $classval }\n";
        }

        $sth->closeCursor();  // free up connection to server
        $sth = null;

      } catch (PDOException $e) {
        error_log("PDO Exception: " . $e->getMessage() . " | SQL: $qry");
        echo "ERROR: " . $e->getMessage();
        closeConnection();
        exit(1);
      }
    }
    else {
      $qry = "SELECT wbpccls, wbpcval FROM webpclaf WHERE wbpcpag=:pagekey";

      $stmt = oci_parse($conn,$qry) or die("can't parse query");
      oci_bind_by_name($stmt, ':pagekey', $pagekey);
      if (!oci_execute($stmt)) {echo "ERROR: ".oci_error($stmt);exit(1);}

      $reply = "";
      while ($row  = oci_fetch_row($stmt)) {
        $classnam=$row[0];
        $classval=$row[1];
        $reply .= ".$classnam { $classval }\n";
      }
    }
    echo $reply;
    break;

  case 2: // insert/update class for a page
    if ($dbtype == "mssql") {
      $qry = "SELECT WBPCCLS, WBPCVAL
              FROM WEBPCLAF
              WHERE WBPCPAG=:pagekey AND WBPCCLS=:classkey";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':pagekey', $pagekey, PDO::PARAM_STR);
        $sth->bindParam(':classkey', $classkey, PDO::PARAM_STR);

        if (!$sth->execute()) {
          error_log("PDO_Statement execute error: " . implode(" | ", $sth->errorInfo()));
          echo "ERROR: " . implode(" | ", $sth->errorInfo());
          closeConnection();
          exit(1);
        }

        $row_count = sizeof($sth->fetchAll());

        if ($row_count == 0) {
          if ($classval=="") { echo 'UPDATED'; exit(0); }

          $qry = "INSERT INTO WEBPCLAF
                   ( WBPCPAG, WBPCCLS, WBPCVAL, WBPCCBY,
                     WBPCCDT, WBPCCTM, WBPCUBY, WBPCUDT, WBPCUTM, WBPCSPA )
                  VALUES 
                   ( :pagekey, :classkey, :classval, :secureid1,
                     CONVERT(VARCHAR(8), GETDATE(), 112),
                     CONVERT(VARCHAR(5), GETDATE(), 8), :secureid2,
                     CONVERT(VARCHAR(8), GETDATE(), 112),
                     CONVERT(VARCHAR(5), GETDATE(), 8), ' ' )";

          $sth = $conn->prepare($qry);
          $sth->bindParam(':pagekey', $pagekey, PDO::PARAM_STR);
          $sth->bindParam(':classkey', $classkey, PDO::PARAM_STR);
          $sth->bindParam(':classval', $classval, PDO::PARAM_STR);
          $sth->bindParam(':secureid1', $secureid, PDO::PARAM_STR);
          $sth->bindParam(':secureid2', $secureid, PDO::PARAM_STR);
        }
        else {
          if ($classval=="") {
            $qry = "DELETE FROM WEBPCLAF
                    WHERE  WBPCPAG=:pagekey
                    AND    WBPCCLS=:classkey";

            $sth = $conn->prepare($qry);
            $sth->bindParam(':pagekey', $pagekey, PDO::PARAM_STR);
            $sth->bindParam(':classkey', $classkey, PDO::PARAM_STR);
          } else {
            $qry = "UPDATE WEBPCLAF SET
                      WBPCVAL = :classval,
                      WBPCUBY = :secureid,
                      WBPCUDT = CONVERT(VARCHAR(8), GETDATE(), 112),
                      WBPCUTM = CONVERT(VARCHAR(5), GETDATE(), 8)
                    WHERE WBPCPAG=:pagekey
                    AND   WBPCCLS=:classkey";

            $sth = $conn->prepare($qry);
            $sth->bindParam(':pagekey', $pagekey, PDO::PARAM_STR);
            $sth->bindParam(':classkey', $classkey, PDO::PARAM_STR);
            $sth->bindParam(':classval', $classval, PDO::PARAM_STR);
            $sth->bindParam(':secureid', $secureid, PDO::PARAM_STR);
          }
        }

        if (!$sth->execute()) {
          error_log("PDO_Statement execute error: " . implode(" | ", $sth->errorInfo()));
          echo "ERROR: " . implode(" | ", $sth->errorInfo());
          closeConnection();
          exit(1);
        }

        $sth->closeCursor();  // free up connection to server
        $sth = null;

      } catch (PDOException $e) {
        error_log("PDO Exception: " . $e->getMessage() . " | SQL: $qry");
        echo "ERROR: " . $e->getMessage();
        closeConnection();
        exit(1);
      }
    }
    else {
      $qry = "SELECT wbpccls, wbpcval
              FROM webpclaf
              WHERE wbpcpag=:pagekey AND wbpccls=:classkey";
      $rs=oci_parse($conn,$qry) or die ("Error Query [".$SQL."]");
      oci_bind_by_name($rs, ':pagekey',  $pagekey);
      oci_bind_by_name($rs, ':classkey', $classkey);
      if (!oci_execute($rs)) {echo "ERROR: ".oci_error($rs);exit(1);}
      oci_fetch($rs);

      if (oci_num_rows($rs)==0) {
        if ($classval=="") { echo 'UPDATED'; exit(0); }

        $qry = "INSERT INTO webpclaf
                ( wbpcpag, wbpccls, wbpcval, 
                  wbpccby, wbpccdt, wbpcctm,
                  wbpcuby, wbpcudt, wbpcutm, wbpcspa )
                Values (:pagekey,:classkey,:classval, :secureid,
                        to_char(sysdate,'YYYYMMDD'), to_char(sysdate,'HH24:MI'),
                        :secureid, to_char(sysdate,'YYYYMMDD'),
                        to_char(sysdate,'HH24:MI'),' ')";
          $rs=oci_parse($conn,$qry) or die ("Error Query [".$SQL."]");
          oci_bind_by_name($rs, ':pagekey',  $pagekey);
          oci_bind_by_name($rs, ':classkey', $classkey);
          oci_bind_by_name($rs, ':classval', $classval);
          oci_bind_by_name($rs, ':secureid', $secureid);
      } else {
        if ($classval=="") {
          $qry = "DELETE from webpclaf 
                  WHERE wbpcpag=:pagekey
                  AND   wbpccls=:classkey";
          $rs=oci_parse($conn,$qry) or die ("Error Query [".$SQL."]");
          oci_bind_by_name($rs, ':pagekey',  $pagekey);
          oci_bind_by_name($rs, ':classkey', $classkey);
        } else {
          $qry = "UPDATE webpclaf SET
                    wbpcval = :classval,
                    wbpcuby = :secureid, 
                    wbpcudt = to_char(sysdate,'YYYYMMDD'), 
                    wbpcutm = to_char(sysdate,'HH24:MI')
                  WHERE wbpcpag=:pagekey
                  AND   wbpccls=:classkey";
          $rs=oci_parse($conn,$qry) or die ("Error Query [".$SQL."]");
          oci_bind_by_name($rs, ':pagekey',  $pagekey);
          oci_bind_by_name($rs, ':classkey', $classkey);
          oci_bind_by_name($rs, ':classval', $classval);
          oci_bind_by_name($rs, ':secureid', $secureid);
        }
      }
      if (!oci_execute($rs)) {echo "ERROR: ".oci_error($rs);exit(1);}
    }

    echo 'UPDATED';
    break;

  default:
    echo 'ERROR: Invalid Option.';
    break;
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
