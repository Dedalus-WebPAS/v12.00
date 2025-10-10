create table patddhaf
(
  ptddfund    char(6) default ' ' not null,
  ptddftyp    char(2) default ' ' not null,
  ptdddtto    char(8) default ' ' not null,
  ptddfld1    char(80) default ' ' not null,
  ptddfld2    char(80) default ' ' not null,
  ptddcfd1    char(10) default ' ' not null,
  ptddcfd2    char(10) default ' ' not null,
  ptddfvl1    decimal(14,2) default 0 not null,
  ptddfvl2    decimal(14,2) default 0 not null,
  ptddcrby    char(10) default ' ' not null,
  ptddcrdt    char(8) default ' ' not null,
  ptddcrtm    char(8) default ' ' not null,
  ptddupby    char(10) default ' ' not null,
  ptddupdt    char(8) default ' ' not null,
  ptdduptm    char(8) default ' ' not null,
  ptdddlen    char(1) default ' ' not null,
  ptddspar    char(50) default ' ' not null,
  lf          char(1)
);
create unique index patddha1 on patddhaf
(
ptddfund,
ptddftyp,
ptdddtto,
ptdddlen
);
revoke all on patddhaf from public ; 
grant select on patddhaf to public ; 
