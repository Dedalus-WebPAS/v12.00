<?php
/*
.----------------------------------------------------------------------
. Program       : AutoSuggest.php
.
. Function      : AJAX Type Ahead Search Function
.
. Modifications :
.
. V11.04.02  07/08/2024  Don Nguyen    TSK 0939766
.            Referenced updated db connection variable (setup.php)
. V11.04.01  20/06/2024  Don Nguyen    TSK 0939766
.            Re-wrote to add support for SQL Server database (dbtype="mssql")
. V10.11.01  02.11.2017  Davin         Task 0837347
.            Return practice counter (pmhgcntr) in search type 10
. V10.09.01  03.02.2017  B.G.Ackland   Task 0832932
.            Add new search type 10 to return HCP and Practice codes Combined
.            Made as a copy of type 8
. V10.06.02  12.08.2015  B.G.Ackland   CARxxxxxx
.            Change split to preg_split to avoid deprecated warning messages
. V10.06.01  15.06.2015  B.G.Ackland   CARxxxxxx
.            Added User table Keyword Search
. V10.04.01  01.07.2014  B.G.Ackland   CARxxxxxx
.            Added Search Option 8 for HCP Practice Search
.----------------------------------------------------------------------
PRGID     INIT      "AutoSuggest.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "AJAX Type Ahead Search Function"
.----------------------------------------------------------------------
*/
 require "setup.php";

 $uid = $_SERVER['REMOTE_USER'];
 $reportno = (isset($_REQUEST["reportno"])) ? $_REQUEST["reportno"] : null;
 $keywords = (isset($_REQUEST["keywords"])) ? $_REQUEST["keywords"] : null;
 $rowcount = (isset($_REQUEST["rowcount"])) ? $_REQUEST["rowcount"] :10;

 $keyword1 = $keywords;
 $keyword2 = "";
 $arrKeyword = preg_split("/[\s,]+/",$keywords);

 if (count($arrKeyword) > 1) {
   $keyword1 = $arrKeyword[0];
   $keyword2 = $arrKeyword[1];
 } else {
   $arrKeyword = preg_split("/[\s,]+/",$keywords);
   if (count($arrKeyword) > 1) {
     $keyword1 = $arrKeyword[0];
     $keyword2 = $arrKeyword[1];
   }
 }

 $reply = "";
 $dl    = "','";

 switch($reportno) {

   /* HCP Search */
   case 1:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) PMHCHCPC AS code
                ,PMHCSNAM + ', ' + PMHCTITL + ' ' + PMHCGNAM + '(' + PMHCHCPC + ')' AS value
                ,PMHCADR1 + ' ' + PMHCADR2 + ' ' + PMHCADR3 + ' ' + PMHCADR4 + ' ' + PMHCPOST AS subtext
              FROM  PMSHCPAF
              JOIN  PMSHKIAF a ON a.PMHKHCPC = PMHCHCPC AND a.PMHKKKWD LIKE UPPER(:keyword1) + '%'
              WHERE PMHCSTTS = '0'
              AND   ( ISNULL(:keyword2, '') = ''
                      OR
                      PMHCHCPC IN (SELECT b.PMHKHCPC
                                   FROM PMSHKIAF b
                                   WHERE b.PMHKHCPC = a.PMHKHCPC
                                   AND b.PMHKKKWD LIKE UPPER(:keyword3) + '%'))
             ";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT DISTINCT pmhchcpc  code
                    ,pmhcsnam||', '||pmhctitl||' '||pmhcgnam||'('||pmhchcpc||')' value
                    ,pmhcadr1||' '||pmhcadr2||' '||pmhcadr3||' '||pmhcadr4||' '||pmhcpost subtext
              FROM   pmshcpaf
              JOIN   pmshkiaf a ON a.pmhkhcpc=pmhchcpc AND a.pmhkkkwd LIKE UPPER(:keyword1)||'%'
              WHERE  pmhcstts = '0'
              AND    ROWNUM  < :rowcount
              AND    ( NVL(':keyword2','')='' 
                       OR
                       a.pmhkhcpc IN (SELECT b.pmhkhcpc FROM pmshkiaf b 
                                      WHERE b.pmhkhcpc = a.pmhkhcpc
                                      AND b.pmhkkkwd LIKE UPPER(:keyword2)||'%')
                     )";

      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    } 
    break;


   /* Transfer Source */
   case 2:
    if ($dbtype == "mssql") {
      $qry = "SELECT TOP (:rowcount - 1) PTVACODE  AS CODE
                    ,PTVADESC + '(' + PTVACODE + ')' AS NAME
                    ,'' AS SUBTEXT
              FROM   PATVADAF
              WHERE  PTVAACTV <> 'I'
              AND    (PTVADESC LIKE UPPER(:keyword1 + '%')
              OR      PTVACODE LIKE UPPER(:keyword2 + '%'))";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword1, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT ptvacode  code
                    ,ptvadesc||'('||ptvacode||')'  name
                    ,''  subtext
              FROM   patvadaf
              WHERE  ROWNUM  < :rowcount
              AND    ptvaactv <> 'I'
              AND    (ptvadesc LIKE UPPER(:keyword1||'%')
              OR      ptvacode LIKE UPPER(:keyword1||'%'))";

      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
    }
    break;


   /* Doctor Search */
   case 3:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) DCODE  AS CODE
                    ,DSNAME + ', ' + DTITL + ' ' + DGNAME + '(' + DCODE + ')'  AS VALUE
                    ,DSADD1 + ' ' + DSADD2 + ' ' + DSADD3 + ' ' + DSADD4 + ' ' + DSPOST  AS SUBTEXT
              FROM   PATDO1AF
              JOIN   PATDKIAF a ON a.PTDKDOC=DCODE AND a.PTDKKWD LIKE UPPER(:keyword1 + '%')
              WHERE  DRSTAT <> '1'
              AND    ( ISNULL(:keyword2, '') = ''
                       OR
                       DCODE IN (SELECT b.PTDKDOC FROM PATDKIAF b
                                 WHERE b.PTDKDOC = DCODE
                                 AND b.PTDKKWD LIKE UPPER(:keyword3 + '%')) )";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT DISTINCT dcode  code
                    ,dsname||', '||dtitl||' '||dgname||'('||dcode||')'  value
                    ,dsadd1||' '||dsadd2||' '||dsadd3||' '||dsadd4||' '||dspost  subtext
              FROM   patdo1af
              JOIN   patdkiaf a ON a.ptdkdoc=dcode AND a.ptdkkwd LIKE UPPER(:keyword1||'%')
              WHERE  drstat <> '1'
              AND    ROWNUM  < :rowcount
              AND    ( NVL(':keyword2','')='' 
                       OR
                       dcode IN (SELECT b.ptdkdoc FROM patdkiaf b 
                                 WHERE b.ptdkdoc = dcode
                                 AND b.ptdkkwd LIKE UPPER(:keyword2||'%')) )";

      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    }
    break;


   /* Health Fund Search */
   case 4:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) a.PTHFFUN + '|' + a.PTHFTAB AS code,
                a.PTHFFUN + '-' + b.HFNAME AS value,
                a.PTHFTAB + '-' + c.HFNAME AS subtext
              FROM PATKHFAF a
              JOIN PATFN1AF b ON b.HCODE = a.PTHFFUN AND b.HFTABL = '0000'
              JOIN PATFN1AF c ON c.HCODE = a.PTHFFUN AND c.HFTABL = a.PTHFTAB
              WHERE a.PTHFKWD LIKE UPPER(:keyword1 + '%')
              AND c.HFTABL <> '0000'
              AND b.DHFTACT <> '1'
              AND c.DHFTACT <> '1'
              AND ( ISNULL(:keyword2, '') = ''
                    OR
                    EXISTS (SELECT 1 
                            FROM PATKHFAF d
                            WHERE d.PTHFFUN = a.PTHFFUN
                            AND d.PTHFTAB = a.PTHFTAB
                            AND d.PTHFKWD LIKE UPPER(:keyword3 + '%')) )
              ORDER BY value";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT distinct a.pthffun||'|'||a.pthftab  code
                    ,a.pthffun||'-'||b.hfname  value
                    ,a.pthftab||'-'||c.hfname  subtext
              FROM   patkhfaf a 
              JOIN   patfn1af b ON b.hcode=a.pthffun AND b.hftabl='0000'
              JOIN   patfn1af c ON c.hcode=a.pthffun AND c.hftabl=a.pthftab
              WHERE  a.pthfkwd LIKE UPPER(:keyword1||'%')
              AND    c.hftabl <> '0000'
              AND    b.dhftact <> '1'
              AND    c.dhftact <> '1'
              AND    ROWNUM  < :rowcount
              AND    ( NVL(':keyword2','')='' 
                       OR
                       EXISTS (SELECT 1 FROM patkhfaf d 
                               WHERE d.pthffun = a.pthffun
                               AND   d.pthftab = a.pthftab
                               AND   d.pthfkwd LIKE UPPER(:keyword2||'%') )
                     )
             order by 2";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    }
    break;


   /* Case Team */
   case 5:
    if ($dbtype == "mssql") {
      $qry = "SELECT TOP (:rowcount - 1) ALCATEAM AS code
                    ,ALCADESC + '(' + ALCATEAM + ')' AS name
                    ,'' AS subtext
              FROM   ALLCASAF
              WHERE  ALCAACTV = '1'
              AND    (UPPER(ALCADESC) LIKE UPPER('%' + :keyword1 + '%')
                      OR UPPER(ALCATEAM) LIKE UPPER(:keyword2 + '%'))";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword1, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT alcateam  code
                    ,alcadesc||'('||alcateam||')' name
                    ,'' subtext
              FROM   allcasaf
              WHERE  ROWNUM  < :rowcount
              AND    alcaactv = '1'
              AND    (UPPER(alcadesc) LIKE UPPER('%'||:keyword1||'%')
                      OR UPPER(alcateam) LIKE UPPER(:keyword1||'%'))";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
    }
    break;


   /* Diagnosis Current Edition 7 */
   case 6:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) DPCODE AS code
                       ,PT0DDESC AS value
                       ,DDESC AS subtext
              FROM   PAT10D7F
              JOIN   PATKCD7F a ON a.PTCDITM = DPCODE
                                AND a.PTCDKWD LIKE UPPER(:keyword1 + '%')
              WHERE  DFLAG = 'P'
              AND    ( ISNULL(:keyword2, '') = ''
                       OR
                       DPCODE IN (SELECT b.PTCDITM FROM PATKCD7F b
                                  WHERE b.PTCDITM = DPCODE
                                  AND b.PTCDKWD LIKE UPPER(:keyword3 + '%'))
                     )";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT distinct dpcode  code
                    ,pt0ddesc  value
                    ,ddesc  subtext
              FROM   pat10d7f
              JOIN   patkcd7f a ON a.ptcditm=dpcode
                                AND a.ptcdkwd LIKE UPPER(:keyword1||'%')
              WHERE  dflag = 'P'
              AND    ROWNUM  < :rowcount
              AND    ( NVL(':keyword2','')=''
                       OR
                       dpcode IN ( SELECT b.ptcditm FROM patkcd7f b
                                   WHERE b.ptcditm = dpcode
                                   AND b.ptcdkwd LIKE UPPER(:keyword2||'%') )
                     )";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    }
    break;


   /* User */
   case 7:
    $keywords=str_replace(" ","%",$keywords);

    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) WBSEUID AS code
                    ,WBSENAM AS value
                    ,(SELECT CASE ACODE
                               WHEN ' ' THEN 'No Occupation Set'
                               ELSE TDESC
                             END
                      FROM PATCODES
                      WHERE TCODE='w0'
                      AND ACODE=WBSEOCG) + '(' + WBSEUID + ')' AS subtext
              FROM   WEBSECAF
              WHERE  (UPPER(WBSENAM) LIKE UPPER('%' + :keyword1 + '%')
                      OR UPPER(WBSEUID) LIKE UPPER(:keyword2 + '%'))
              AND    WBSEACT='1'";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keywords, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keywords, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT DISTINCT wbseuid  code
                    ,wbsenam value
                    ,(SELECT CASE acode
                      WHEN ' ' THEN 'No Occupation Set'
                      ELSE tdesc 
                      END
                      FROM patcodes WHERE tcode='w0' AND acode=wbseocg)||'('||wbseuid||')' subtext
              FROM   websecaf
              WHERE (UPPER(wbsenam) LIKE UPPER('%'||:keywords||'%')
                     OR UPPER(wbseuid) LIKE UPPER(:keywords||'%'))
              AND    wbseact='1'
              AND    ROWNUM < :rowcount
             ";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keywords', $keywords);
    }
    break;


   /* HCP Practice Search */
   case 8:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1) PMHCHCPC AS code,
                     PMHCSNAM + ', ' + PMHCTITL + ' ' + PMHCGNAM + '(' + PMHCHCPC + ')' AS value,
                     PMHGADD1 + ' ' + PMHGADD2 + ' ' + PMHGADD3 + ' ' +
                     PMHGADD4 + ' ' + PMHGADD5 + ' ' + PMHGADD6 + ' ' + PMHGPOST AS subtext
              FROM   PMSHCPAF
              JOIN   PMSHCLAF l ON l.PMHLHCPC = PMHCHCPC AND l.PMHLSTAT = '0'
              JOIN   PMSHCGAF p ON p.PMHGPRAC = l.PMHLHCPR AND p.PMHGSTTS = '0'
              JOIN   PMSHKIAF a ON a.PMHKHCPC = PMHCHCPC AND a.PMHKKKWD LIKE UPPER(:keyword1) + '%'
              WHERE  PMHCSTTS = '0'
              AND    ( ISNULL(:keyword2, '') = ''
                       OR 
                       PMHCHCPC IN (SELECT b.PMHKHCPC
                                    FROM   PMSHKIAF b
                                    WHERE  b.PMHKHCPC = PMHCHCPC
                                    AND    b.PMHKKKWD LIKE UPPER(:keyword3) + '%')
                     )";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT distinct pmhchcpc  code
                    ,pmhcsnam||', '||pmhctitl||' '||pmhcgnam||'('||pmhchcpc||')' value
                    ,pmhgadd1||' '||pmhgadd2||' '||pmhgadd3||' '||
                     pmhgadd4||' '||pmhgadd5||' '||pmhgadd6||' '||pmhgpost subtext
              FROM   pmshcpaf
              JOIN   pmshclaf l ON l.pmhlhcpc=pmhchcpc AND l.pmhlstat='0'
              JOIN   pmshcgaf p ON p.pmhgprac=l.pmhlhcpr AND p.pmhgstts='0'
              JOIN   pmshkiaf a ON a.pmhkhcpc=pmhchcpc AND a.pmhkkkwd LIKE upper(:keyword1)||'%'
              WHERE  pmhcstts = '0'
              AND    ROWNUM  < :rowcount
              AND    ( NVL(':keyword2','')=''
                       OR
                       pmhchcpc IN (SELECT b.pmhkhcpc FROM pmshkiaf b
                                    WHERE b.pmhkhcpc = pmhchcpc
                                    AND b.pmhkkkwd LIKE UPPER(:keyword2)||'%')
                     )";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    }
    break;


   /* User Table */
   case 9:
    if (strlen($keywords) > 2)
      $keywords="%".$keywords."%";
    else
      $keywords=$keywords."%";

    if ($dbtype == "mssql") {
      $qry = "SELECT TOP (:rowcount - 1) WBSEUID AS code
                    ,WBSENAM AS name
                    ,'' AS subtext
              FROM   WEBSECAF
              WHERE  (UPPER(WBSENAM) LIKE UPPER(:keyword1)
                      OR UPPER(WBSEUID) LIKE UPPER(:keyword2))
              ORDER BY WBSENAM";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keywords, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keywords, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT WBSEUID  code
                    ,WBSENAM  name
                    ,'' subtext
              FROM   websecaf
              WHERE  ROWNUM  < :rowcount
              AND   (upper(WBSENAM) like upper(:keywords)
              OR    upper(WBSEUID) like upper(:keywords))
              ORDER BY WBSENAM";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keywords', $keywords);
    }
    break;


   /* Search for HCP and Practice Code */
   case 10:
    if ($dbtype == "mssql") {
      $qry = "SELECT DISTINCT TOP (:rowcount - 1)
                  RIGHT(PMHCHCPC + SPACE(10), 10) + RIGHT(PMHGPRAC + SPACE(10), 10) + LEFT(SPACE(2) + PMHGCNTR, 2) AS code,
                  PMHCSNAM + ', ' + PMHCTITL + ' ' + PMHCGNAM + '(' + PMHCHCPC + ')' AS value,
                  PMHGADD1 + ' ' + PMHGADD2 + ' ' + PMHGADD3 + ' ' + PMHGADD4 + ' ' + PMHGADD5 + ' ' + PMHGADD6 + ' ' + PMHGPOST AS subtext
              FROM PMSHCPAF
              JOIN PMSHCLAF l ON l.PMHLHCPC = PMHCHCPC AND l.PMHLSTAT = '0'
              JOIN PMSHCGAF p ON p.PMHGPRAC = l.PMHLHCPR AND p.PMHGSTTS = '0'
              JOIN PMSHKIAF a ON a.PMHKHCPC = PMHCHCPC AND a.PMHKKKWD LIKE UPPER(:keyword1) + '%'
              WHERE PMHCSTTS = '0'
              AND ( ISNULL(:keyword2, '') = ''
                    OR
                    PMHCHCPC IN
                    (
                      SELECT b.PMHKHCPC 
                      FROM PMSHKIAF b
                      WHERE b.PMHKHCPC = PMHCHCPC
                      AND b.PMHKKKWD LIKE UPPER(:keyword3) + '%'
                    )
                  )";

      try {
        $sth = $conn->prepare($qry);
        $sth->bindParam(':rowcount', $rowcount, PDO::PARAM_STR);
        $sth->bindParam(':keyword1', $keyword1, PDO::PARAM_STR);
        $sth->bindParam(':keyword2', $keyword2, PDO::PARAM_STR);
        $sth->bindParam(':keyword3', $keyword2, PDO::PARAM_STR);
      } catch (PDOException $e) {
        error_log("PDO Error - " . $e->getMessage() . " | SQL: $qry");
        exit(1);
      }
    }
    else {
      $qry = "SELECT DISTINCT RPAD(pmhchcpc,10,' ')||RPAD(pmhgprac,10,' ')||LPAD(pmhgcntr,2,' ')  code
                    ,pmhcsnam||', '||pmhctitl||' '||pmhcgnam||'('||pmhchcpc||')' value
                    ,pmhgadd1||' '||pmhgadd2||' '||pmhgadd3||' '||
                     pmhgadd4||' '||pmhgadd5||' '||pmhgadd6||' '||pmhgpost subtext
              FROM   pmshcpaf
              JOIN   pmshclaf l ON l.pmhlhcpc=pmhchcpc AND l.pmhlstat='0'
              JOIN   pmshcgaf p ON p.pmhgprac=l.pmhlhcpr AND p.pmhgstts='0'
              JOIN   pmshkiaf a ON a.pmhkhcpc=pmhchcpc AND a.pmhkkkwd LIKE UPPER(:keyword1)||'%'
              WHERE  pmhcstts = '0'
              AND    ROWNUM  < :rowcount
              AND    (NVL(':keyword2','')=''
                      OR
                      pmhchcpc IN (SELECT b.pmhkhcpc FROM pmshkiaf b
                                   WHERE b.pmhkhcpc = pmhchcpc
                                   AND b.pmhkkkwd LIKE UPPER(:keyword2)||'%')
                     )";
      $stmt = oci_parse($conn,$qry) or die('cant parse query');
      oci_bind_by_name($stmt, ':rowcount', $rowcount);
      oci_bind_by_name($stmt, ':keyword1', $keyword1);
      oci_bind_by_name($stmt, ':keyword2', $keyword2);
    }
    break;

   default:
    oci_close($conn); 
    exit();
    break;
 }

 $reply .= "[";

 if ($dbtype == "mssql") {  // MSSQL (SQL Server)
   try {
     if ($sth->execute()) {
       while ($row = $sth->fetch(PDO::FETCH_NUM)) {
         $reply .= "{\"code\":\"$row[0]\",
                     \"value\":\"$row[1]\",
                     \"subtext\":\"$row[2]\"},";
       }
       $sth->closeCursor();
     }
   } catch (PDOException $e) {
     error_log("PDO Execute Error - " . $e->getMessage() . " | SQL: $qry");
   }

   // close db connection
   $sth = null;
   $conn = null;
 }
 else {  // Oracle
   if ($stmt) {
      if (oci_execute($stmt)) {
        $numcols = oci_num_fields($stmt);
        while ($row  = oci_fetch_row($stmt)) {
          $reply .= "{\"code\":\"$row[0]\",
                      \"value\":\"$row[1]\",
                      \"subtext\":\"$row[2]\"},";
        }
      } else {
        $e = oci_error($stmt);
        echo $e['message'];
      }
      oci_close($conn);
   }
 }

 $reply .= "]";
 echo $reply;
?>
