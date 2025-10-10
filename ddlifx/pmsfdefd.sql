create table pmsfdeaf
(
  pmfehosp    char(3) default ' ' not null,
  pmfesyst    char(1) default ' ' not null,
  pmfesite    char(6) default ' ' not null,
  pmfeyear    char(4) default ' ' not null,
  pmfeperd    char(2) default ' ' not null,
  pmfeftyp    char(1) default ' ' not null,
  pmfecode    char(13) default ' ' not null,
  pmfeinvn    char(8) default ' ' not null,
  pmfertyp    char(2) default ' ' not null,
  pmfetrno    char(6) default ' ' not null,
  pmfeinvd    char(8) default ' ' not null,
  pmfeurno    char(8) default ' ' not null,
  pmfeadmn    char(8) default ' ' not null,
  pmfeamnt    decimal(14,2) default 0 not null,
  pmfecuid    char(10) default ' ' not null,
  pmfecdat    char(8) default ' ' not null,
  pmfectim    char(10) default ' ' not null,
  pmfespre    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmsfdea1 on pmsfdeaf
(
pmfehosp,
pmfesyst,
pmfesite,
pmfeyear,
pmfeperd,
pmfeftyp,
pmfecode,
pmfeinvn,
pmfertyp,
pmfetrno
);
create unique index pmsfdea2 on pmsfdeaf
(
pmfeinvn,
pmfertyp,
pmfetrno,
pmfehosp,
pmfesyst,
pmfesite,
pmfeyear,
pmfeperd,
pmfeftyp,
pmfecode
);
revoke all on pmsfdeaf from public ; 
grant select on pmsfdeaf to public ; 
