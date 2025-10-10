create table prifactf
(
  prfadate    varchar2(8) default ' ' not null,
  prfadebt    varchar2(8) default ' ' not null,
  dprfascn    varchar2(2) default ' ' not null,
  prfaactn    varchar2(3) default ' ' not null,
  prfacomm    varchar2(60) default ' ' not null,
  prfampra    varchar2(6) default ' ' not null,
  prfadtcp    varchar2(8) default ' ' not null,
  prfacdat    varchar2(8) default ' ' not null,
  prfactim    varchar2(8) default ' ' not null,
  prfacuid    varchar2(10) default ' ' not null,
  prfaudat    varchar2(8) default ' ' not null,
  prfautim    varchar2(8) default ' ' not null,
  prfauuid    varchar2(10) default ' ' not null,
  prfaspar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint prifact1 primary key( 
prfadate,
prfadebt,
dprfascn)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index prifact2 on prifactf
(
prfadebt,
dprfascn,
prfadate
)
  tablespace pas_indx; 
