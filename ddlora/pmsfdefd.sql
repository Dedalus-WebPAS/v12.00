create table pmsfdeaf
(
  pmfehosp    varchar2(3) default ' ' not null,
  pmfesyst    varchar2(1) default ' ' not null,
  pmfesite    varchar2(6) default ' ' not null,
  pmfeyear    varchar2(4) default ' ' not null,
  pmfeperd    varchar2(2) default ' ' not null,
  pmfeftyp    varchar2(1) default ' ' not null,
  pmfecode    varchar2(13) default ' ' not null,
  pmfeinvn    varchar2(8) default ' ' not null,
  pmfertyp    varchar2(2) default ' ' not null,
  pmfetrno    varchar2(6) default ' ' not null,
  pmfeinvd    varchar2(8) default ' ' not null,
  pmfeurno    varchar2(8) default ' ' not null,
  pmfeadmn    varchar2(8) default ' ' not null,
  pmfeamnt    number(14,2) default 0 not null,
  pmfecuid    varchar2(10) default ' ' not null,
  pmfecdat    varchar2(8) default ' ' not null,
  pmfectim    varchar2(10) default ' ' not null,
  pmfespre    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmsfdea1 primary key( 
pmfehosp,
pmfesyst,
pmfesite,
pmfeyear,
pmfeperd,
pmfeftyp,
pmfecode,
pmfeinvn,
pmfertyp,
pmfetrno)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
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
)
  tablespace pas_indx; 
