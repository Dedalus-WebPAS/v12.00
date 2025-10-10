--------------------------------------------------------
--  File created - Friday-August-26-2011   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Procedure RESFLNPR
--------------------------------------------------------
set define off;

CREATE OR REPLACE PROCEDURE RESFLNPR
AS
v_reslnkcy  varchar2(8);
v_reslnkpy  varchar2(8);
v_resdeacy  varchar2(8);
v_resdeapy  varchar2(8);
v_date      varchar2(8);
v_sqlstmt1  varchar2(1500);
v_sqlstmt2  varchar2(1500);

BEGIN

v_date     := to_char(sysdate-180,'YYYYMMDD'); 
v_reslnkcy := 'reln'||to_char(sysdate,'YYYY'); 
v_reslnkpy := 'reln'||to_char(sysdate-365,'YYYY'); 
v_resdeacy := 'reda'||to_char(sysdate,'YYYY'); 
v_resdeapy := 'reda'||to_char(sysdate-365,'YYYY'); 

v_sqlstmt1 := 'INSERT INTO resflnaf 
       SELECT relnlty, relnlky, relnlab
             , relnucs, relnusc
             , nvl(substr(redavst,18,100),'' '')
             , relndss, to_char(count(*),''999999999''),'' '','' ''
       FROM ( 
           SELECT relnlty, relnlky, relnlab, relnucs, relnusc, redavst, relndss
           FROM '||v_reslnkcy||'
           LEFT JOIN '||v_resdeacy||' on redardt=relnrdt and redartm=relnrtm and redarun=relnrun
                     and redavst like ''Tests Complete%''
           WHERE  relnlty IN (''03'',''04'',''05'',''06'',''07'',''08'',''09'')
           AND    relnrdt >  '''||v_date||'''
           UNION ALL
           SELECT relnlty, relnlky, relnlab, relnucs, relnusc, redavst, relndss
           FROM  '||v_reslnkpy||'
           LEFT JOIN '||v_resdeapy||' on redardt=relnrdt and redartm=relnrtm and redarun=relnrun
                     and redavst like ''Tests Complete%''
           WHERE  relnlty IN (''03'',''04'',''05'',''06'',''07'',''08'',''09'')
           AND    relnrdt >  '''||v_date||''' 
           )
       GROUP BY relnlty, relnlky, relnlab, relnucs, relnusc,  nvl(substr(redavst,18,100),'' ''), relndss';

v_sqlstmt2 := 'INSERT INTO resflnaf 
       SELECT ''00'', ''0000000000'', relnlab
            , relnucs, relnusc
            , nvl(substr(redavst,18,100),'' '')
            , relndss, to_char(count(*),''999999999''),'' '','' ''
       FROM ( 
           SELECT relnlab, relnucs, relnusc, redavst, relndss FROM '||v_reslnkcy||'
           LEFT JOIN '||v_resdeacy||' on redardt=relnrdt and redartm=relnrtm and redarun=relnrun
                     and redavst like ''Tests Complete%''
           WHERE  relnlty IN (''01'')
           AND    relnrdt >  '''||v_date||'''
        UNION ALL
           SELECT relnlab, relnucs, relnusc, redavst, relndss FROM '||v_reslnkpy||'
           LEFT JOIN '||v_resdeapy||' on redardt=relnrdt and redartm=relnrtm and redarun=relnrun
                     and redavst like ''Tests Complete%''
           WHERE  relnlty IN (''01'')
           AND    relnrdt >  '''||v_date||'''
         )
        GROUP BY relnlab, relnucs, relnusc,  nvl(substr(redavst,18,100),'' ''), relndss';

EXECUTE IMMEDIATE 'truncate table resflnaf';
EXECUTE IMMEDIATE v_sqlstmt1;
EXECUTE IMMEDIATE v_sqlstmt2;
COMMIT;
END;

/

