<?php
/*
.----------------------------------------------------------------------
. Program       : ResultsView.php
.
. Function      : AJAX Result Statistics for Dashboard Components
.
. Modifications :
.
. V11.04.02  07/08/2024  Don Nguyen         TSK 0938324
.                        Referenced updated db connection variable (setup.php)
. V11.04.01  30/07/2024  Don Nguyen         TSK 0938324
.                        Added support for SQL Server database (dbtype="mssql")
. V10.07.01  08.01.2016  B.G.Ackland
.                        Trim ED Site Code 
. V10.06.01  15.09.2016  B.G.Ackland
.                        Remove traling comma in Result JSON set
. V10.05.00  08.10.2014  B.G.Ackland
.                        New
.----------------------------------------------------------------------
PRGID     INIT      "ResultsView.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "Clinical Results AJAX Statistics"
.----------------------------------------------------------------------
*/
//
 require "setup.php";

 $secureid = (isset($_SERVER["REMOTE_USER"])) ? $_SERVER["REMOTE_USER"] : null;
 if ($secureid==null) { echo "ERROR:  Invalid Security"; exit(1); }

 $reportno = (isset($_REQUEST["reportno"])) ? $_REQUEST["reportno"] : null;
 $template = (isset($_REQUEST["template"])) ? $_REQUEST["template"] : null;
 $sitecode = (isset($_REQUEST["sitecode"])) ? trim($_REQUEST["sitecode"]) : null;
 $agehours = (isset($_REQUEST["agehours"])) ? $_REQUEST["agehours"] : 12;
 $norecord = (isset($_REQUEST["norecord"])) ? $_REQUEST["norecord"] : 20;
 $marked = (isset($_REQUEST["marked"])) ? $_REQUEST["marked"] : '0';
 $fname = (isset($_REQUEST["fname"])) ? $_REQUEST["fname"] : null;
 $aname = (isset($_REQUEST["aname"])) ? $_REQUEST["aname"] : 'resultArray';

 switch($reportno) {
  case 1: // Emergency Department Results Statistics
    header("Content-type: application/javascript"); 
    $YYYY=date('Y');

    if ($dbtype == "mssql") {
      $qry = "SELECT RELNDSS, HLCODES, RELNMSN, COUNT(*) 
              FROM RELN$YYYY
              LEFT JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=RELNDSS
              WHERE RELNLTY='09' AND RELNRST IN ('F','C')
              AND RELNLKY=:sitecode
              AND (RELNRDT + RELNRTM) >= FORMAT(DATEADD(HOUR, -:agehours, GETDATE()), 'yyyyMMddHH:mm')
              GROUP BY RELNDSS, HLCODES, RELNMSN
              ORDER BY RELNDSS, HLCODES, RELNMSN";

       try {
        $sth = $conn->prepare($qry);

        $agehours = (int)$agehours;

        $sth->bindParam(':sitecode', $sitecode, PDO::PARAM_STR);
        $sth->bindParam(':agehours', $agehours, PDO::PARAM_INT);

        if (!$sth->execute()) {
          error_log("PDO_Statement execute error: " . implode(" | ",$sth->errorInfo()));
          echo "ERROR: " . implode(" | ",$sth->errorInfo());
          closeConnection();
          exit(1);
        }

        $reply = "";
        if ($fname!=null) $reply .= "function $fname() {\n";

        while ($row = $sth->fetch(PDO::FETCH_NUM)) {
          $reply .= $aname."[".$aname.".length\]= ['$row[0]','$row[1]','$row[2]','$row[3]']; \n";
        }

        if ($fname!=null) $reply .= "}\n";

      } catch (PDOException $e) {
        error_log("PDO Exception: " . $e->getMessage() . " | SQL: $qry");
        echo "ERROR: " . $e->getMessage();
        closeConnection();
        exit(1);
      }
    }
    else {
      $qry = "SELECT relndss, hlcodes, relnmsn, count(*)
              FROM reln$YYYY 
              LEFT JOIN hl7codaf ON hlcotid='0074' AND hlcocod=relndss
              WHERE relnlty='09' AND relnrst IN ('F','C')
              AND relnlky=:sitecode
              AND relnrdt || relnrtm >= TO_CHAR(SYSDATE-:agehours/24,'YYYYMMDDHH:MI')
              GROUP BY relndss, hlcodes, relnmsn
              ORDER BY relndss, hlcodes, relnmsn";

      $stmt = oci_parse($conn,$qry) or die("can't parse query");
      oci_bind_by_name($stmt, ':sitecode', $sitecode);
      oci_bind_by_name($stmt, ':agehours', $agehours);
      if (!oci_execute($stmt)) {echo "ERROR:".oci_error($stmt);exit(1);}

      $reply = "";
      if ($fname!=null) $reply .= "function $fname() {\n";

      while ($row  = oci_fetch_row($stmt)) {
        $reply .= $aname."[".$aname.".length\]= ['$row[0]','$row[1]','$row[2]','$row[3]']; \n";
      }

      if ($fname!=null) $reply .= "}\n";
    }

    echo $reply;
    break;

  case 2: // Emergency Department Recent Results JSON Output
    header("Content-type: application/javascript"); 
    $YYYY=date('Y');

    if ($dbtype == "mssql") {
      $qry = "SELECT TOP (:norecord1) RELNRDT, RELNRTM, PSNAME, PGNAME,
                                      HLCODES, RECTDES, RELNNOR, RELNRST,
                                      RELNDSS, PURNO, DEMVIADM
              FROM (
                SELECT RELNRDT, RELNRTM, PSNAME, PGNAME, HLCODES,
                       RECTDES, RELNNOR, RELNRST, RELNDSS, PURNO, DEMVIADM,
                       ROW_NUMBER() OVER (ORDER BY RELNRDT + RELNRTM DESC) as rn
                FROM   RELN$YYYY
                INNER  JOIN PATMA1AF ON PURNO=RELNPID
                INNER  JOIN EMRVISAF ON EMVIURNO=PURNO AND DEMVISTA IN ('1','2')
                LEFT   JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=RELNDSS
                LEFT   JOIN RESCTAAF ON RECTLAB=RELNLAB AND RECTSEG='OBR'
                                     AND RECTFLD='04'
                                     AND RECTSYS=RELNUCS AND RECTCOD=RELNUSC
                WHERE  RELNLTY='09' AND RELNRST IN ('F','C')
                AND    RELNLKY=:sitecode";

      if ($marked=='0') { $qry .= " AND RELNMSN='0'"; }

      $qry .= " AND    RELNRDT + RELNRTM >= FORMAT(DATEADD(HOUR, -:agehours, GETDATE()), 'yyyyMMddHH:mm')
              ) t
              WHERE rn <= :norecord2";

      try {
        $sth = $conn->prepare($qry);

        $agehours = (int)$agehours;
        $norecord = (int)$norecord;

        $sth->bindParam(':sitecode', $sitecode, PDO::PARAM_STR);
        $sth->bindParam(':agehours', $agehours, PDO::PARAM_INT);
        $sth->bindParam(':norecord1', $norecord, PDO::PARAM_INT);
        $sth->bindParam(':norecord2', $norecord, PDO::PARAM_INT);

        if (!$sth->execute()) {
          error_log("PDO_Statement execute error: " . implode(" | ",$sth->errorInfo()));
          echo "ERROR: " . implode(" | ",$sth->errorInfo());
          closeConnection();
          exit(1);
        }

        $rowCount=0;
        $reply = "[";

        while ($row = $sth->fetch(PDO::FETCH_NUM)) {
          if ($rowCount>0) { $reply .= ","; }

          $reply .= "{\"date\":\"$row[0]\",";
          $reply .= "\"time\":\"$row[1]\",";
          $reply .= "\"surname\":\"$row[2]\",";
          $reply .= "\"given\":\"$row[3]\",";
          $reply .= "\"service\":\"$row[4]\",";
          $reply .= "\"test\":\"$row[5]\",";
          $reply .= "\"normal\":\"$row[6]\",";
          $reply .= "\"status\":\"$row[7]\",";
          $reply .= "\"code\":\"$row[8]\",";
          $reply .= "\"urnumber\":\"$row[9]\",";
          $reply .= "\"admissno\":\"$row[10]\"}\n";
          $rowCount++;
        }

        $reply .= "]";

      } catch (PDOException $e) {
        error_log("PDO Exception: " . $e->getMessage() . " | SQL: $qry");
        echo "ERROR: " . $e->getMessage();
        closeConnection();
        exit(1);
      }
    }
    else {
      $qry = "SELECT * FROM 
             (SELECT relnrdt, relnrtm, psname, pgname, hlcodes, 
                     rectdes, relnnor, relnrst,relndss, purno,
                     demviadm
              FROM reln$YYYY 
              JOIN patma1af ON purno=relnpid
              JOIN emrvisaf ON emviurno=purno AND demvista IN ('1','2') 
              LEFT JOIN hl7codaf ON hlcotid='0074' AND hlcocod=relndss
              LEFT JOIN resctaaf ON rectlab=relnlab AND rectseg='OBR'
                                 AND rectfld='04'  
                                 AND rectsys=relnucs AND rectcod=relnusc
              WHERE relnlty='09' AND relnrst IN ('F','C')
              AND   relnlky=:sitecode";

      if ($marked=='0') { $qry.= " AND   relnmsn='0'"; }
      $qry.= "AND   relnrdt || relnrtm >= TO_CHAR(SYSDATE-:agehours/24,'YYYYMMDDHH:MI')
              ORDER BY relnrdt || relnrtm DESC)
              WHERE ROWNUM <= :norecord";

      $stmt = oci_parse($conn,$qry) or die("can't parse query");
      oci_bind_by_name($stmt, ':sitecode', $sitecode);
      oci_bind_by_name($stmt, ':agehours', $agehours);
      oci_bind_by_name($stmt, ':norecord', $norecord);
      if (!oci_execute($stmt)) {echo "ERROR:".oci_error($stmt);exit(1);}

      $rowCount=0;
      $reply = "[";

      while ($row  = oci_fetch_row($stmt)) {
          if ($rowCount>0) { $reply .= ","; }
          $reply .= "{\"date\":\"$row[0]\",";
          $reply .= "\"time\":\"$row[1]\",";
          $reply .= "\"surname\":\"$row[2]\",";
          $reply .= "\"given\":\"$row[3]\",";
          $reply .= "\"service\":\"$row[4]\",";
          $reply .= "\"test\":\"$row[5]\",";
          $reply .= "\"normal\":\"$row[6]\",";
          $reply .= "\"status\":\"$row[7]\",";
          $reply .= "\"code\":\"$row[8]\",";
          $reply .= "\"urnumber\":\"$row[9]\",";
          $reply .= "\"admissno\":\"$row[10]\"}\n";
          $rowCount++;
      }

      $reply .= "]";
    }

    echo $reply;
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
