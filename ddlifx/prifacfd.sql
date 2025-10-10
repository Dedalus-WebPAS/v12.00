create table prifactf
(
  prfadate    char(8) default ' ' not null,
  prfadebt    char(8) default ' ' not null,
  dprfascn    char(2) default ' ' not null,
  prfaactn    char(3) default ' ' not null,
  prfacomm    char(60) default ' ' not null,
  prfampra    char(6) default ' ' not null,
  prfadtcp    char(8) default ' ' not null,
  prfacdat    char(8) default ' ' not null,
  prfactim    char(8) default ' ' not null,
  prfacuid    char(10) default ' ' not null,
  prfaudat    char(8) default ' ' not null,
  prfautim    char(8) default ' ' not null,
  prfauuid    char(10) default ' ' not null,
  prfaspar    char(50) default ' ' not null,
  lf          char(1)
);
create unique index prifact1 on prifactf
(
prfadate,
prfadebt,
dprfascn
);
create unique index prifact2 on prifactf
(
prfadebt,
dprfascn,
prfadate
);
revoke all on prifactf from public ; 
grant select on prifactf to public ; 
