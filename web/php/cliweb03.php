<?php
/*
.----------------------------------------------------------------------
. Program       : cliweb03.php
.
. Function      : Clinical Result Services
.
. Modifications :
.
. V11.04.02  07/08/2024  Don Nguyen    TSK 0939766
.            Referenced updated db connection variable (setup.php)
. V11.04.01  20/06/2024  Don Nguyen    TSK 0939766
.            Re-wrote to add support for SQL Server database (dbtype="mssql")
. V11.03.01  05/09/2023  Don Nguyen    TSK 0934402
.            Replaced class named constructor declaration with __construct
.            for PHP 8+ compliance.
. V10.06.01  04.08.2015 B.G.Ackland CAR 320105
.            Changed wbseuid to wbselogn
. V10.04.01  B.G.Ackland
.            Refine Quick List Results to Ignore the DSS of ZZ for Order items
.----------------------------------------------------------------------
PRGID     INIT      "cliweb03.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "Clinical Result Services"
.----------------------------------------------------------------------
*/
require "setup.php";

/******************************************************************************
 *  Cliweb03 object instantiated
 ******************************************************************************/
$cliweb02 = new Cliweb03($conn,$dbtype);
$cliweb02->getQueryByReportNumber();
$cliweb02->closeConnection();

/******************************************************************************
 *  Cliweb03 - common web class
 ******************************************************************************/
class Cliweb03 { 
   //instance variables
   private $reply = "";
   private $secureid = null;
   private $reportno = "";
   private $conn = null;
   private $admissno = "";
   private $urnumber = "";
   private $typflter= "";
   private $filtrdss = "";
   private $labflter = "";
   private $keyword = "";
   private $rowcount = "10";
   private $sex ="";
   private $dob = "";
   private $firstName = "";
   private $lastName = "";
   private $dbtype = "";

   // Cliweb03 constructor
   public function __construct($connection,$dbtype) {
    $this->secureid = $_SERVER['REMOTE_USER'];
    $this->reportno = (isset($_REQUEST["reportno"])) ? $_REQUEST["reportno"] : null;
    $this->urnumber = (isset($_REQUEST["urnumber"])) ? $_REQUEST["urnumber"] : null;
    $this->admissno = (isset($_REQUEST["admissno"])) ? $_REQUEST["admissno"] : null;
    $this->keyword =  (isset($_REQUEST["keyword"]))  ? $_REQUEST["keyword"] : null;
    $this->rowcount = (isset($_REQUEST["numrow"]))   ? $_REQUEST["numrow"] : null;
    $this->typflter = (isset($_REQUEST["typflter"])) ? $_REQUEST["typflter"] : null;
    $this->labflter = (isset($_REQUEST["labflter"])) ? $_REQUEST["labflter"] : null;
    $this->filtrdss = (isset($_REQUEST["filtrdss"])) ? $_REQUEST["filtrdss"] : null;
    $this->wardcode = (isset($_REQUEST["wardcode"])) ? $_REQUEST["wardcode"] : null;
    $this->sex = (isset($_REQUEST["sex"])) ? $_REQUEST["sex"] : null;
    $this->dob = (isset($_REQUEST["dob"])) ? $_REQUEST["dob"] : null;
    $this->firstName = (isset($_REQUEST["fname"])) ? $_REQUEST["fname"] : null;
    $this->secondName = (isset($_REQUEST["sname"])) ? $_REQUEST["sname"] : null;
    $this->conn = $connection;
    $this->dbtype = $dbtype;
   }
  
  /****************************************************************************
   *	getQueryByReportNumber - assigns a query based on report number
   ****************************************************************************/
  public function getQueryByReportNumber() {
    $currentDate = getDate();
    $currentYear = $currentDate['year'];
    $previousYear = $currentDate['year'] - 1;

    switch($this->reportno) {

      /* My Quick List (All Diagnostic Services) */
      case 1: 
        if ($this->dbtype == "mssql") {
          $qry = "SELECT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES, RECTLAB,
                                           RELBDES, REFLVST
                  FROM RESFLNAF
                  JOIN RESLABAF ON RELBLCD=REFLLAB
                  JOIN RESCTAAF ON RECTLAB=REFLLAB
                  AND  RECTCOD=REFLUSC
                  AND  RECTSEG='OBR'
                  AND  RECTFLD='04'
                  AND  RECTSYS=REFLUCS
                  JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=REFLDSS
                  WHERE REFLLTY='03'
                  AND  REFLDSS NOT IN ('ZZ')
                  AND  REFLLKY = (SELECT WBSEDOC FROM WEBSECAF
                                  WHERE WBSELOGN = :secureid)
                  ORDER BY REFLCNT DESC";

          try {
            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':secureid', $this->secureid, PDO::PARAM_STR);
            $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);
          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry = "SELECT * FROM (
                  SELECT refldss,rectcod,rectdes,rectlab,relbdes,reflvst
                  FROM resflnaf
                  JOIN reslabaf ON relblcd=refllab
                  JOIN resctaaf ON rectlab=refllab
                  AND  rectcod=reflusc
                  AND  rectseg='OBR'
                  AND  rectfld='04'
                  AND  rectsys=reflucs
                  JOIN hl7codaf ON hlcotid='0074' AND hlcocod=refldss
                  WHERE refllty='03'
                  AND   refldss not in ('ZZ')
                  AND  refllky = (SELECT wbsedoc from websecaf
                  WHERE wbselogn = :secureid )
                  ORDER by reflcnt desc)
                  WHERE ROWNUM <= :rowcount";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':secureid', $this->secureid);
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);
          $this->getQuickList($stmt);
        }
        break;


      /* Service (Coding Table) Keyword Search */
      case 2:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT DISTINCT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES,
                                           RECTLAB, RELBDES, REFLVST, REFLCNT
                  FROM RESCTAAF
                  JOIN RESLABAF ON RELBLCD=RECTLAB
                  JOIN RESFLNAF ON REFLLTY='00' AND REFLLAB=RECTLAB
                               AND REFLUCS=RECTSYS AND REFLUSC=RECTCOD
                  WHERE RECTSEG='OBR'
                  AND  RECTFLD='04'
                  AND  UPPER(RECTDES) LIKE UPPER('%' + :keyword + '%')
                  ORDER BY REFLCNT DESC";

          try {
            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':keyword', $this->keyword, PDO::PARAM_STR);
            $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);
          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry = "SELECT distinct refldss,rectcod,rectdes,rectlab,relbdes,
                                  reflvst,reflcnt
                  FROM resctaaf 
                  JOIN reslabaf ON relblcd=rectlab
                  JOIN resflnaf ON refllty='00' and refllab=rectlab 
                               and reflucs=rectsys and reflusc=rectcod 
                  WHERE rectseg='OBR'
                  AND  rectfld='04'
                  AND  upper(rectdes) LIKE upper('%'||:keyword||'%')
                  AND  ROWNUM <= :rowcount
                  ORDER by reflcnt desc";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':keyword', $this->keyword);
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);
          $this->getQuickList($stmt); //keyword search
        }
        break;


      /* Service Type List (Mobility - iPad) */
      case 3:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT HLCOCOD, HLCODES
                  FROM   HL7CODAF
                  WHERE  HLCOTID='0074'";

          try {
            $sth = $this->conn->prepare($qry);
          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getServiceType_MSSQL($sth);
        }
        else {
          $qry = "SELECT hlcocod, hlcodes
                  FROM   hl7codaf
                  WHERE  hlcotid='0074'";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          $this->getServiceType($stmt);
        }
        break;


      /* My Quick List with Service Type Filter */
      case 4:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES, RECTLAB,
                                           RELBDES,REFLVST
                  FROM RESFLNAF
                  JOIN RESLABAF ON RELBLCD = REFLLAB
                  JOIN RESCTAAF ON RECTLAB=REFLLAB
                  AND  RECTCOD=REFLUSC
                  AND  RECTSEG='OBR'
                  AND  RECTFLD='04'
                  AND  RECTSYS=REFLUCS
                  JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=REFLDSS
                  WHERE REFLLTY='03'
                  AND  REFLLKY = (SELECT WBSEDOC FROM WEBSECAF
                                  WHERE WBSELOGN = :secureid)
                  AND REFLDSS = :typflter
                  ORDER BY REFLCNT DESC";

          try {

             $sth = $this->conn->prepare($qry);
             $sth->bindParam(':secureid', $this->secureid, PDO::PARAM_STR);
             $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);

             $typefilter = trim($this->typflter);
             $sth->bindParam(':typflter', $typefilter, PDO::PARAM_STR);

           } catch (PDOException $e) {
             error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
           }

           $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry = "SELECT * FROM
                   (SELECT refldss,rectcod,rectdes,rectlab, relbdes,reflvst
                    FROM resflnaf
                    JOIN reslabaf ON relblcd = refllab
                    JOIN resctaaf ON rectlab=refllab
                    AND  rectcod=reflusc
                    AND  rectseg='OBR'
                    AND  rectfld='04'
                    AND  rectsys=reflucs
                    JOIN hl7codaf ON hlcotid='0074' AND hlcocod=refldss
                    WHERE refllty='03'
                    AND  refllky = (SELECT wbsedoc from websecaf
                                    WHERE wbselogn = :secureid)
                    AND refldss = :typflter 
                    ORDER by reflcnt desc)
                  WHERE ROWNUM <= :rowcount";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':secureid', $this->secureid);
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

          $typefilter = trim($this->typflter);
          oci_bind_by_name($stmt, ':typflter', $typefilter);

          $this->getQuickList($stmt);
        }
        break;


      /* Service (Coding Table) Keyword Search with Type Filter */
      case 5:
        if ($this->dbtype == "mssql") {
          $qry =  "SELECT DISTINCT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES,
                                            RECTLAB, RELBDES, REFLVST, REFLCNT
                   FROM RESCTAAF
                   JOIN RESLABAF ON RELBLCD=RECTLAB
                   JOIN RESFLNAF ON REFLLTY='00' AND REFLLAB=RECTLAB
                                AND REFLUCS=RECTSYS AND REFLUSC=RECTCOD
                   WHERE RECTSEG='OBR'
                   AND  RECTFLD='04'
                   AND  UPPER(RECTDES) LIKE UPPER('%' + :keyword + '%')
                   AND  REFLDSS = :typflter
                   ORDER BY REFLCNT DESC";

          try {

            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':keyword', $this->keyword, PDO::PARAM_STR);
            $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);

            $typefilter = trim($this->typflter);
            $sth->bindParam(':typflter', $typefilter, PDO::PARAM_STR);

          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry =  "SELECT distinct refldss,rectcod,rectdes,rectlab,relbdes,
                                   reflvst,reflcnt
                   FROM resctaaf
                   JOIN reslabaf ON relblcd=rectlab
                   JOIN resflnaf ON refllty='00' and refllab=rectlab 
                                and reflucs=rectsys and reflusc=rectcod
                   WHERE rectseg='OBR'
                   AND  rectfld='04'
                   AND  upper(rectdes) LIKE upper('%'||:keyword||'%')
                   AND  ROWNUM <= :rowcount
                   AND refldss = :typflter
                   ORDER by reflcnt desc";
          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':keyword', $this->keyword);
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

          $typefilter = trim($this->typflter);
          oci_bind_by_name($stmt, ':typflter', $typefilter);

          $this->getQuickList($stmt); //keyword search
        }
        break;


      /* Patient Results with Service Type Filter */
      case 6:
         if ($this->dbtype == "mssql") {
           $qry = " SELECT DISTINCT TOP (:rowcount-0) RELNDSS, RELNUSC,
                        RECTDES, RELNLAB, RELBDES,
                        REPLACE(REDAVST, 'Tests Completed:','') AS ResultValue,
                        COUNT(*) AS Counter
                    FROM (
                        SELECT RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                        FROM RELN{$currentYear}
                        LEFT JOIN REDA{$currentYear} ON REDARDT = RELNRDT
                                                      AND REDARTM = RELNRTM
                                                      AND REDARUN = RELNRUN
                                                      AND REDAVST LIKE 'Tests Completed:%'
                        WHERE RELNLTY = '01'
                        AND RELNLKY = :urnumber1
                        AND RELNDSS = :typflter1
                        UNION
                        SELECT RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                        FROM RELN{$previousYear}
                        LEFT JOIN REDA{$previousYear} ON REDARDT = RELNRDT
                                                      AND REDARTM = RELNRTM
                                                      AND REDARUN = RELNRUN
                                                      AND REDAVST LIKE 'Tests Completed:%'
                        WHERE RELNLTY = '01'
                        AND RELNLKY = :urnumber2
                        AND RELNDSS = :typflter2
                        GROUP BY RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                    ) AS Subquery
                    JOIN RESLABAF ON RELBLCD = RELNLAB
                    JOIN RESCTAAF ON RECTLAB = RELNLAB AND RECTSEG = 'OBR'
                                  AND RECTFLD = '04'
                                  AND RECTSYS = RELNUCS
                                  AND RECTCOD = RELNUSC
                    GROUP BY RELNDSS, RELNUSC, RECTDES, RELNLAB, RELBDES, REDAVST
                    ORDER BY Counter DESC ";

           try {

             $sth = $this->conn->prepare($qry);
             $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);
             $sth->bindParam(':urnumber1', $this->urnumber, PDO::PARAM_STR);
             $sth->bindParam(':urnumber2', $this->urnumber, PDO::PARAM_STR);

             $typefilter = trim($this->typflter);
             $sth->bindParam(':typflter1', $typefilter, PDO::PARAM_STR);
             $sth->bindParam(':typflter2', $typefilter, PDO::PARAM_STR);

           } catch (PDOException $e) {
             error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
           }

           $this->getQuickList_MSSQL($sth);
         }
         else {
           $qry ="SELECT distinct relndss,relnusc,rectdes,relnlab,relbdes,
                         replace(redavst,'Tests Completed:'),count(*)
                  FROM (SELECT relnlab,relndss, relnucs, relnusc, redavst
                       FROM reln{$currentYear}
                       left join reda{$currentYear} on redardt=relnrdt
                                                   and redartm=relnrtm
                                                   and redarun=relnrun
                                                   and redavst like 'Tests Completed:%'
                                                   and rownum=1
                       WHERE relnlty='01'
                       AND relnlky= :urnumber
                       AND relndss= :typflter
                       UNION
                       SELECT relnlab,relndss, relnucs, relnusc, redavst
                       FROM reln{$previousYear}
                       left join reda{$previousYear} on redardt=relnrdt
                                                   and redartm=relnrtm
                                                   and redarun=relnrun
                                                   and redavst like 'Tests Completed:%'
                                                   and rownum=1
                       WHERE relnlty='01'
                       AND relnlky= :urnumber
                       AND relndss= :typflter
                       GROUP BY relnlab,relndss, relnucs, relnusc, redavst)
                 JOIN reslabaf ON relblcd = relnlab
                 JOIN resctaaf ON rectlab = relnlab AND rectseg='OBR'
                      AND rectfld='04'
                      AND rectsys=relnucs
                      AND rectcod=relnusc
                      AND ROWNUM <=  :rowcount
                 GROUP BY relndss,relnusc,rectdes,relnlab,relbdes, redavst
                 ORDER BY 7 desc";

           $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
           oci_bind_by_name($stmt, ':urnumber', $this->urnumber);
           oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

           $typefilter = trim($this->typflter);
           oci_bind_by_name($stmt, ':typflter', $typefilter);

           $this->getQuickList($stmt);
         }
         break;


      /* Patient Results (All Diagnostic Services) */
      case 7:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT DISTINCT TOP (:rowcount-0) RELNDSS, RELNUSC, RECTDES,
                         RELNLAB, RELBDES,
                         REPLACE(REDAVST, 'Tests Completed:','') AS ResultValue,
                         COUNT(*) AS Counter
                  FROM (
                      SELECT RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                      FROM RELN{$currentYear}
                      LEFT JOIN REDA{$currentYear} ON REDARDT = RELNRDT
                                                    AND REDARTM = RELNRTM
                                                    AND REDARUN = RELNRUN
                                                    AND REDAVST LIKE 'Tests Completed:%'
                      WHERE RELNLTY = '01'
                      AND RELNLKY = :urnumber1
                      UNION
                      SELECT RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                      FROM RELN{$previousYear}
                      LEFT JOIN REDA{$previousYear} ON REDARDT = RELNRDT
                                                    AND REDARTM = RELNRTM
                                                    AND REDARUN = RELNRUN
                                                    AND REDAVST LIKE 'Tests Completed:%'
                      WHERE RELNLTY = '01'
                      AND RELNLKY = :urnumber2
                      GROUP BY RELNLAB, RELNDSS, RELNUCS, RELNUSC, REDAVST
                  ) AS Subquery
                  JOIN RESLABAF ON RELBLCD = RELNLAB
                  JOIN RESCTAAF ON RECTLAB = RELNLAB AND RECTSEG = 'OBR'
                                AND RECTFLD = '04'
                                AND RECTSYS = RELNUCS
                                AND RECTCOD = RELNUSC
                  GROUP BY RELNDSS, RELNUSC, RECTDES, RELNLAB, RELBDES, REDAVST
                  ORDER BY Counter DESC";

           try {
             $sth = $this->conn->prepare($qry);
             $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);
             $sth->bindParam(':urnumber1', $this->urnumber, PDO::PARAM_STR);
             $sth->bindParam(':urnumber2', $this->urnumber, PDO::PARAM_STR);
           } catch (PDOException $e) {
             error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
           }

           $this->getQuickList_MSSQL($sth);
         }
         else {
           $qry ="SELECT distinct relndss,relnusc,rectdes,relnlab,relbdes,
                         replace(redavst,'Tests Completed:'),count(*)
                  FROM (SELECT relnlab,relndss, relnucs, relnusc, redavst
                       FROM reln{$currentYear}
                       left join reda{$currentYear} on redardt=relnrdt
                                                   and redartm=relnrtm
                                                   and redarun=relnrun
                                                   and redavst like 'Tests Completed:%'
                                                   and rownum=1
                       WHERE relnlty='01'
                       AND relnlky= :urnumber
                       UNION
                       SELECT relnlab,relndss, relnucs, relnusc, redavst
                       FROM reln{$previousYear}
                       left join reda{$previousYear} on redardt=relnrdt
                                                   and redartm=relnrtm
                                                   and redarun=relnrun
                                                   and redavst like 'Tests Completed:%'
                                                   and rownum=1
                       WHERE relnlty='01'
                       AND relnlky= :urnumber
                       GROUP BY relnlab,relndss, relnucs, relnusc, redavst)
                 JOIN reslabaf ON relblcd = relnlab
                 JOIN resctaaf ON rectlab = relnlab AND rectseg='OBR'
                      AND rectfld='04'
                      AND rectsys=relnucs
                      AND rectcod=relnusc
                      AND ROWNUM <=  :rowcount
                 GROUP BY relndss,relnusc,rectdes,relnlab,relbdes, redavst
                 ORDER BY 7 desc";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':urnumber', $this->urnumber);
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

          $this->getQuickList($stmt);
        }
        break;


      /* Unlinked Clinical Results (Mobility - iPad) */
      case 9:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT RELNRDT, RELNRTM, RELNRUN, REERMSG, RELNDSS, RECTDES,
                         RELNNOR
                  FROM   RESERRAF, RELN{$currentYear}, REHA{$currentYear},
                         RESPIDAF, RESCTAAF
                  WHERE RELNRDT=REERRDT
                  AND RELNRTM=REERRTM
                  AND RELNRUN=REERRUN
                  AND REHARDT=RELNRDT
                  AND REHARTM=RELNRTM
                  AND REHARUN=RELNRUN
                  AND REHAPID=REPIPID
                  AND REPIGNM LIKE :firstName1 + '%'
                  AND REPISNM LIKE :secondName1 + '%'
                  AND REPIDOB=:dob1
                  AND REPISEX=:sex1
                  AND RELNLAB=RECTLAB
                  AND RECTSEG='OBR'
                  AND RECTFLD='04'
                  AND RELNUCS=RECTSYS
                  AND RELNUSC=RECTCOD
                  AND REHARDT > CONVERT(VARCHAR(8), DATEADD(day, -90, GETDATE()), 112)
                  UNION
                  SELECT RELNRDT, RELNRTM, RELNRUN, REERMSG, RELNDSS, RECTDES, RELNNOR
                  FROM RESERRAF, RELN{$previousYear}, REHA{$previousYear},
                       RESPIDAF, RESCTAAF
                  WHERE RELNRDT=REERRDT
                  AND RELNRTM=REERRTM
                  AND RELNRUN=REERRUN
                  AND REHARDT=RELNRDT
                  AND REHARTM=RELNRTM
                  AND REHARUN=RELNRUN
                  AND REHAPID=REPIPID
                  AND REPIGNM LIKE :firstName2 + '%'
                  AND REPISNM LIKE :secondName2 + '%'
                  AND REPIDOB=:dob2
                  AND REPISEX=:sex2
                  AND RELNLAB=RECTLAB
                  AND RECTSEG='OBR'
                  AND RECTFLD='04'
                  AND RELNUCS=RECTSYS
                  AND RELNUSC=RECTCOD
                  AND REHARDT > CONVERT(VARCHAR(8), DATEADD(day, -90, GETDATE()), 112)
                  ORDER BY RELNRDT DESC";

          try {
            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':firstName1', $this->firstName, PDO::PARAM_STR);
            $sth->bindParam(':firstName2', $this->firstName, PDO::PARAM_STR);
            $sth->bindParam(':secondName1', $this->secondName, PDO::PARAM_STR);
            $sth->bindParam(':secondName2', $this->secondName, PDO::PARAM_STR);
            $sth->bindParam(':dob1', $this->dob, PDO::PARAM_STR);
            $sth->bindParam(':dob2', $this->dob, PDO::PARAM_STR);
            $sth->bindParam(':sex1', $this->sex, PDO::PARAM_STR);
            $sth->bindParam(':sex2', $this->sex, PDO::PARAM_STR);
          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getUnlinkedResults_MSSQL($sth);
        }
        else {
          $qry = "SELECT relnrdt, relnrtm, relnrun, reermsg, relndss, rectdes,
                         relnnor 
                  FROM   reserraf, reln{$currentYear}, reha{$currentYear},
                         respidaf, resctaaf
                  WHERE relnrdt=reerrdt
                  AND relnrtm=reerrtm
                  AND relnrun=reerrun
                  AND rehardt=relnrdt
                  AND rehartm=relnrtm
                  AND reharun=relnrun
                  AND rehapid=repipid
                  AND repignm LIKE ':firstName%'
                  AND repisnm LIKE ':secondName%'
                  AND repidob=:dob
                  AND repisex=:sex
                  AND relnlab=rectlab
                  AND rectseg='OBR'
                  AND rectfld='04'
                  AND relnucs=rectsys
                  AND relnusc=rectcod
                  AND rehardt > to_char(sysdate-90,'YYYYMMDD') 
                  UNION 
                  SELECT relnrdt, relnrtm, relnrun, reermsg, relndss, rectdes,
                         relnnor 
                  FROM reserraf, reln{$previousYear}, reha{$previousYear},
                       respidaf, resctaaf
                  WHERE relnrdt=reerrdt
                  AND relnrtm=reerrtm
                  AND relnrun=reerrun
                  AND rehardt=relnrdt
                  AND rehartm=relnrtm
                  AND reharun=relnrun
                  AND rehapid=repipid
                  AND repignm LIKE :firstName||'%'
                  AND repisnm LIKE :secondName||'%'
                  AND repidob=:dob
                  AND repisex=:sex
                  AND relnlab=rectlab
                  AND rectseg='OBR'
                  AND rectfld='04'
                  AND relnucs=rectsys
                  AND relnusc=rectcod
                  AND rehardt > to_char(sysdate-90,'YYYYMMDD') 
                  ORDER BY relnrdt DESC";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':firstName', $this->firstName);
          oci_bind_by_name($stmt, ':secondName', $this->secondName);
          oci_bind_by_name($stmt, ':dob', $this->dob);
          oci_bind_by_name($stmt, ':sex', $this->sex);

          $this->getUnlinkedResults($stmt);
        }
        break;


      /* Ward Quick List (All Diagnostic Services) */
      case 10:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT TOP (:rowcount) REFLDSS, RECTCOD, RECTDES, RECTLAB,
                                           RELBDES, REFLVST
                  FROM RESFLNAF
                  LEFT JOIN RESLABAF ON RELBLCD=REFLLAB
                  LEFT JOIN RESCTAAF ON RECTLAB=REFLLAB
                  AND  RECTCOD=REFLUSC
                  AND  RECTSEG='OBR'
                  AND  RECTFLD='04'
                  AND  RECTSYS=REFLUCS
                  LEFT JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=REFLDSS
                  WHERE REFLLTY='04'
                  AND  REFLDSS NOT IN ('ZZ')
                  AND  REFLLKY = :wardcode
                  ORDER BY REFLCNT DESC";

          try {

            $sth = $this->conn->prepare($qry);

            $rowcount = (int)$this->rowcount;
            $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_INT);

            $wardcode = trim($this->wardcode);
            $sth->bindParam(':wardcode', $wardcode, PDO::PARAM_STR);

          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry =  "SELECT * FROM 
                    (SELECT refldss,rectcod,rectdes,rectlab,relbdes,reflvst
                     FROM resflnaf
                     LEFT JOIN reslabaf ON relblcd=refllab
                     LEFT JOIN resctaaf ON rectlab=refllab
                     AND  rectcod=reflusc
                     AND  rectseg='OBR'
                     AND  rectfld='04'
                     AND  rectsys=reflucs
                     LEFT JOIN hl7codaf ON hlcotid='0074' AND hlcocod=refldss
                     WHERE refllty='04'
                     AND   refldss NOT IN ('ZZ')
                     AND  refllky = :wardcode
                     ORDER BY reflcnt DESC)
                   WHERE ROWNUM <= :rowcount ";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

          $wardcode = trim($this->wardcode);
          oci_bind_by_name($stmt, ':wardcode', $wardcode);

          $this->getQuickList($stmt);
        }
        break;


      /* Ward Quick List with Service Type Filter */
      case 11:
        if ($this->dbtype == "mssql") {
          $qry =  "SELECT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES,
                                            RECTLAB, RELBDES, REFLVST
                   FROM RESFLNAF
                   JOIN RESLABAF ON RELBLCD=REFLLAB
                   JOIN RESCTAAF ON RECTLAB=REFLLAB
                   AND  RECTCOD=REFLUSC
                   AND  RECTSEG='OBR'
                   AND  RECTFLD='04'
                   AND  RECTSYS=REFLUCS
                   JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=REFLDSS
                   WHERE REFLLTY='04'
                   AND  REFLLKY = :wardcode
                   AND  HLCOCOD = :typflter
                   ORDER BY REFLCNT DESC";

          try {

            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);

            $wardcode = trim($this->wardcode);
            $typefilter = trim($this->typflter);
            $sth->bindParam(':wardcode', $wardcode, PDO::PARAM_STR);
            $sth->bindParam(':typflter', $typefilter, PDO::PARAM_STR);

          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          $qry =  "SELECT * FROM
                    (SELECT refldss,rectcod,rectdes,rectlab,relbdes,reflvst
                     FROM resflnaf
                     JOIN reslabaf ON relblcd=refllab
                     JOIN resctaaf ON rectlab=refllab
                     AND  rectcod=reflusc
                     AND  rectseg='OBR'
                     AND  rectfld='04'
                     AND  rectsys=reflucs
                     JOIN hl7codaf ON hlcotid='0074' AND hlcocod=refldss
                     WHERE refllty='04'
                     AND  refllky = :wardcode
                     AND  hlcocod = :typflter
                     ORDER BY reflcnt DESC)
                   WHERE ROWNUM <= :rowcount ";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

          $wardcode = trim($this->wardcode);
          $typefilter = trim($this->typflter);
          oci_bind_by_name($stmt, ':wardcode', $wardcode);
          oci_bind_by_name($stmt, ':typflter', $typefilter);

          $this->getQuickList($stmt);
        }
        break;


      /* Pathology Common Orders List */
      case 12:
        $filterString="";

        if ($this->dbtype == "mssql") {
          if (isset($_GET['labflter'])) {
            $filterString=" AND REFLLAB = :labflter ";
          }
          $qry = "SELECT TOP (:rowcount-0) REFLDSS, RECTCOD, RECTDES, RECTLAB,
                                           RELBDES, REFLVST
                  FROM RESFLNAF
                  JOIN RESLABAF ON RELBLCD=REFLLAB
                  JOIN RESCTAAF ON RECTLAB=REFLLAB
                  AND  RECTCOD=REFLUSC
                  AND  RECTSEG='OBR'
                  AND  RECTFLD='04'
                  AND  RECTSYS=REFLUCS
                  JOIN HL7CODAF ON HLCOTID='0074' AND HLCOCOD=REFLDSS
                  WHERE REFLLTY='00'
                  AND  REFLDSS NOT IN ('ZZ')
                  AND  REFLLKY='0000000000' $filterString
                  ORDER BY REFLCNT DESC";

          try {

            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':rowcount', $this->rowcount, PDO::PARAM_STR);

            if (isset($_GET['labflter'])) {
              $labfilter = trim($this->labflter);
              $sth->bindParam(':labflter', $labfilter, PDO::PARAM_STR);
            }

          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getQuickList_MSSQL($sth);
        }
        else {
          if (isset($_GET['labflter'])) {
            $filterString=" AND refllab = :labflter ";
          }
          $qry =  "SELECT * FROM (
                     SELECT refldss,rectcod,rectdes,rectlab,relbdes,reflvst
                     FROM resflnaf
                     JOIN reslabaf ON relblcd=refllab
                     JOIN resctaaf ON rectlab=refllab
                     AND  rectcod=reflusc
                     AND  rectseg='OBR'
                     AND  rectfld='04'
                     AND  rectsys=reflucs
                     JOIN hl7codaf ON hlcotid='0074' AND hlcocod=refldss
                     WHERE refllty='00'
                     AND   refldss not in ('ZZ')
                     AND   refllky='0000000000' $filterString
                     ORDER by reflcnt desc)
                   WHERE ROWNUM <= :rowcount";

           $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
           oci_bind_by_name($stmt, ':rowcount', $this->rowcount);

           if (isset($_GET['labflter'])) {
             $labfilter = trim($this->labflter);
             oci_bind_by_name($stmt, ':labflter', $labfilter);
           }

           $this->getQuickList($stmt);
        }
        break;


      /* Notes List (when using Doctor Notes List; useDoctorNotesList=true) */
      case 13:
        if ($this->dbtype == "mssql") {
          $qry = "SELECT COUNT(*), REHDRCI
                  FROM (
                      SELECT REHDRCI
                      FROM RELN{$currentYear}
                      JOIN REHD{$currentYear} ON REHDRDT=RELNRDT
                                              AND REHDRTM=RELNRTM
                                              AND REHDRUN=RELNRUN
                      WHERE RELNLTY = '01'
                      AND   RELNLKY = :urnumber1
                      UNION
                      SELECT REHDRCI
                      FROM RELN{$previousYear}
                      JOIN REHD{$previousYear} ON REHDRDT=RELNRDT
                                               AND REHDRTM=RELNRTM
                                               AND REHDRUN=RELNRUN
                      WHERE RELNLTY = '01'
                      AND   RELNLKY = :urnumber2
                  ) AS Subquery
                  GROUP BY REHDRCI 
                  ORDER BY 1";

          try {
            $sth = $this->conn->prepare($qry);
            $sth->bindParam(':urnumber1', $this->urnumber, PDO::PARAM_STR);
            $sth->bindParam(':urnumber2', $this->urnumber, PDO::PARAM_STR);
          } catch (PDOException $e) {
            error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
          }

          $this->getServiceType_MSSQL($sth);
        }
        else {
          $qry = "SELECT count(*), rehdrci FROM (
                   SELECT rehdrci
                   FROM reln{$currentYear}
                   JOIN rehd{$currentYear} on rehdrdt=relnrdt and rehdrtm=relnrtm and rehdrun=relnrun
                   WHERE relnlty = '01'
                   AND   relnlky = :urnumber
                   UNION
                   SELECT rehdrci
                   FROM reln{$previousYear}
                   JOIN rehd{$previousYear} on rehdrdt=relnrdt and rehdrtm=relnrtm and rehdrun=relnrun
                   WHERE relnlty = '01'
                   AND   relnlky = :urnumber )
                  group by rehdrci order by 1";

          $stmt = oci_parse($this->conn,$qry) or die('cant parse query');
          oci_bind_by_name($stmt, ':urnumber', $this->urnumber);

          $this->getServiceType($stmt);
        }
        break;

      default:
        echo "Query Not Used/Available";
        break;
    }
  }

  function getUnlinkedResults($stmt) {
    $i = 0;

    if ($stmt) {
      if (oci_execute($stmt)) {
        $this->reply .= "[";

        while ($row = oci_fetch_row($stmt)) {
          $date = $row[0];
          $time = $row[1];
          $run = $row[2];
          $errmsg = $row[3];  
          $dss = $row[4];
          $description= $row[5];
          $status = $row[6];
          $this->reply .= "{\"date\":\"".$date."\",".
                           "\"time\":\"".$time."\",".
                           "\"run\":\"".$run."\",".
                           "\"errmsg\":\"".$errmsg."\",".
                           "\"dss\":\"".$dss."\",".
                           "\"description\":\"".$description."\",".
                           "\"status\":\"".$status."\"},";
          $i++;
        }

        if ($i > 0) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }
      } else {
        $e = oci_error($stmt);
        echo $e['message'];
      }
    }

    echo $this->reply;
  }

  function getUnlinkedResults_MSSQL($sth) {  // SQL Server
    $i = 0;
    $this->reply = "";

    try {
      if ($sth->execute()) {
        $this->reply .= "[";
 
        while ($row = $sth->fetch(PDO::FETCH_NUM))  {
          $date = $row[0];
          $time = $row[1];
          $run = $row[2];
          $errmsg = $row[3];
          $dss = $row[4];
          $description= $row[5];
          $status = $row[6];
          $this->reply .= "{\"date\":\"".$date."\",".
                           "\"time\":\"".$time."\",".
                           "\"run\":\"".$run."\",".
                           "\"errmsg\":\"".$errmsg."\",".
                           "\"dss\":\"".$dss."\",".
                           "\"description\":\"".$description."\",".
                           "\"status\":\"".$status."\"},";
          $i++;
        }

        if ($i > 0) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }

        $sth->closeCursor();
        $sth = null;
      }
    } catch (PDOException $e) {
      error_log("PDO Execute Error - " . $e->getMessage());
    }

    echo $this->reply;
  }

  /****************************************************************************
   *  Display a quick list; format in JSON.
   *    example: [{"code":"FBC","description":"Full Blood Count"}]   
   *  
   *    usage in front end javascript: 
   *    
   *    var obj = eval('('+<php output here>+')') 
   *
   *    alert(obj[0].code)              output: FBC
   *    alert(obj[0].description)       output: Full Blood Count
   ****************************************************************************/
  function getQuickList($stmt) {
    $i =0;
     if ($stmt) {
      if (oci_execute($stmt)) {
        $this->reply .= "[";

        while ($row = oci_fetch_row($stmt)) {
          $type = str_pad($row[0],5);
          $code = str_pad($row[1],10);
          $description = $row[2];
          $labcode = $row[3];
          $labname = $row[4];
          $testsets = $row[5];
          $this->reply .= "{\"type\":\"".$type."\",".
                           "\"code\":\"".$code."\",".
                           "\"labcode\":\"".$labcode."\",".
                           "\"labname\":\"".$labname."\",".
                           "\"testsets\":\"".$testsets."\",".
                           "\"description\":\"".$description."\"},";
          $i++;
        }

        if ($i > 0 ) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }
      } else {
        $e = oci_error($stmt);
        echo $e['message'];
      }
    }
    echo $this->reply;
  }

  function getQuickList_MSSQL($sth) {  // SQL Server
    $i =0;

    $this->reply .= "[";

    try {
      if ($sth->execute()) {
        while ($row = $sth->fetch(PDO::FETCH_NUM))  {
          $type = str_pad($row[0],5);
          $code = str_pad($row[1],10);
          $description = $row[2];
          $labcode = $row[3];
          $labname = $row[4];
          $testsets = $row[5];
          $this->reply .= "{\"type\":\"".$type."\",".
                           "\"code\":\"".$code."\",".
                           "\"labcode\":\"".$labcode."\",".
                           "\"labname\":\"".$labname."\",".
                           "\"testsets\":\"".$testsets."\",".
                           "\"description\":\"".$description."\"},";
          $i++;
        }

        if ($i > 0 ) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }

        $sth->closeCursor();
        $sth = null;
      }
    } catch (PDOException $e) {
      error_log("PDO Execute Error - " . $e->getMessage());
    }

    echo $this->reply;
  }

  function getServiceType($stmt) {
    $i =0;
    if ($stmt) {
      if (oci_execute($stmt)) {
        $this->reply .= "[";
        while ($row = oci_fetch_row($stmt)) {
          $code = str_pad($row[0],5);
          $description = $row[1];
          $this->reply .= "{\"code\":\"".$code."\",".
                           "\"description\":\"".$description."\"},";
          $i++;
        }
        if ($i > 0 ) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }
      } else {
        $e = oci_error($stmt);
        echo $e['message'];
      }
    }
    echo $this->reply;
  }

  function getServiceType_MSSQL($sth) {  // SQL Server
    $i =0;

    try {
      if ($sth->execute()) {
        $this->reply .= "[";

        while ($row = $sth->fetch(PDO::FETCH_NUM))  {
          $code = str_pad($row[0],5);
          $description = $row[1];
          $this->reply .= "{\"code\":\"".$code."\",".
                           "\"description\":\"".$description."\"},";
          $i++;
        }

        if ($i > 0 ) {
          $this->reply = substr_replace($this->reply,"",-1);
          $this->reply .= "]";
        } else {
          $this->reply = "";
        }

        $sth->closeCursor();
        $sth = null;
      }
    } catch (PDOException $e) {
      error_log("PDO Execute Error - " . $e->getMessage());
    }

    echo $this->reply;
  }

  /****************************************************************************
   * close current connection
   ****************************************************************************/
  public function closeConnection() {
    if ($this->dbtype == "mssql") {  // MSSQL (SQL Server)
      // close db connection
      $this->conn = null;
    }
    else {  // Oracle
      oci_close($this->conn);
    }
  }
}  //end class

?>
