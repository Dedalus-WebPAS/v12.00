SET NOCOUNT ON;
GO

CREATE OR ALTER PROCEDURE RESFLNPR
AS
BEGIN

    DECLARE @v_reslnkcy NVARCHAR(8),
            @v_reslnkpy NVARCHAR(8),
            @v_resdeacy NVARCHAR(8),
            @v_resdeapy NVARCHAR(8),
            @v_date NVARCHAR(8),
            @v_sqlstmt1 NVARCHAR(1500),
            @v_sqlstmt2 NVARCHAR(1500);

    SET @v_date = CONVERT(NVARCHAR, DATEADD(DAY, -180, GETDATE()), 112);
    SET @v_reslnkcy = 'RELN' + CONVERT(NVARCHAR, YEAR(GETDATE()));
    SET @v_reslnkpy = 'RELN' + CONVERT(NVARCHAR, YEAR(DATEADD(YEAR, -1, GETDATE())));
    SET @v_resdeacy = 'REDA' + CONVERT(NVARCHAR, YEAR(GETDATE()));
    SET @v_resdeapy = 'REDA' + CONVERT(NVARCHAR, YEAR(DATEADD(YEAR, -1, GETDATE())));

    SET @v_sqlstmt1 = 'INSERT INTO RESFLNAF
       SELECT RELNLTY, RELNLKY, RELNLAB
             , RELNUCS, RELNUSC
             , ISNULL(SUBSTRING(REDAVST,18,100), '''')
             , RELNDSS, RIGHT(REPLICATE('' '', 9) + CAST(COUNT(*) AS NVARCHAR(9)),9),'' '','' ''
       FROM (
           SELECT RELNLTY, RELNLKY, RELNLAB, RELNUCS, RELNUSC, REDAVST, RELNDSS
           FROM '+@v_reslnkcy+'
           LEFT JOIN '+@v_resdeacy+' ON REDARDT=RELNRDT AND REDARTM=RELNRTM AND REDARUN=RELNRUN
                     AND REDAVST LIKE ''Tests Complete%''
           WHERE  RELNLTY IN (''03'',''04'',''05'',''06'',''07'',''08'',''09'')
           AND    RELNRDT >  '''+@v_date+'''
           UNION ALL
           SELECT RELNLTY, RELNLKY, RELNLAB, RELNUCS, RELNUSC, REDAVST, RELNDSS
           FROM  '+@v_reslnkpy+'
           LEFT JOIN '+@v_resdeapy+' ON REDARDT=RELNRDT AND REDARTM=RELNRTM AND REDARUN=RELNRUN
                     AND REDAVST LIKE ''Tests Complete%''
           WHERE  RELNLTY IN (''03'',''04'',''05'',''06'',''07'',''08'',''09'')
           AND    RELNRDT >  '''+@v_date+'''
       ) AS Subquery
       GROUP BY RELNLTY, RELNLKY, RELNLAB, RELNUCS, RELNUSC, ISNULL(SUBSTRING(REDAVST,18,100), ''''), RELNDSS';


    SET @v_sqlstmt2 = 'INSERT INTO RESFLNAF
       SELECT ''00'', ''0000000000'', RELNLAB
            , RELNUCS, RELNUSC
            , ISNULL(SUBSTRING(REDAVST,18,100), '''')
            , RELNDSS, RIGHT(REPLICATE('' '', 9) + CAST(COUNT(*) AS NVARCHAR(9)),9),'' '','' ''
       FROM (
           SELECT RELNLAB, RELNUCS, RELNUSC, REDAVST, RELNDSS FROM '+@v_reslnkcy+'
           LEFT JOIN '+@v_resdeacy+' ON REDARDT=RELNRDT AND REDARTM=RELNRTM AND REDARUN=RELNRUN
                     AND REDAVST LIKE ''Tests Complete%''
           WHERE  RELNLTY IN (''01'')
           AND    RELNRDT >  '''+@v_date+'''
        UNION ALL
           SELECT RELNLAB, RELNUCS, RELNUSC, REDAVST, RELNDSS FROM '+@v_reslnkpy+'
           LEFT JOIN '+@v_resdeapy+' ON REDARDT=RELNRDT AND REDARTM=RELNRTM AND REDARUN=RELNRUN
                     AND REDAVST LIKE ''Tests Complete%''
           WHERE  RELNLTY IN (''01'')
           AND    RELNRDT >  '''+@v_date+'''
       ) AS Subquery
       GROUP BY RELNLAB, RELNUCS, RELNUSC, ISNULL(SUBSTRING(REDAVST,18,100), ''''), RELNDSS';

    -- Truncate table and execute the dynamic SQL statements.
    TRUNCATE TABLE RESFLNAF;
    EXEC sp_executesql @v_sqlstmt1;
    EXEC sp_executesql @v_sqlstmt2;

END
GO

