create table patddhaf
(
  ptddfund    varchar2(6) default ' ' not null,
  ptddftyp    varchar2(2) default ' ' not null,
  ptdddtto    varchar2(8) default ' ' not null,
  ptddfld1    varchar2(80) default ' ' not null,
  ptddfld2    varchar2(80) default ' ' not null,
  ptddcfd1    varchar2(10) default ' ' not null,
  ptddcfd2    varchar2(10) default ' ' not null,
  ptddfvl1    number(14,2) default 0 not null,
  ptddfvl2    number(14,2) default 0 not null,
  ptddcrby    varchar2(10) default ' ' not null,
  ptddcrdt    varchar2(8) default ' ' not null,
  ptddcrtm    varchar2(8) default ' ' not null,
  ptddupby    varchar2(10) default ' ' not null,
  ptddupdt    varchar2(8) default ' ' not null,
  ptdduptm    varchar2(8) default ' ' not null,
  ptdddlen    varchar2(1) default ' ' not null,
  ptddspar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint patddha1 primary key( 
ptddfund,
ptddftyp,
ptdddtto,
ptdddlen)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
