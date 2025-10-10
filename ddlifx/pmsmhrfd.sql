create table pmsmhraf
(
  pmmjrtyp    char(2) default ' ' not null,
  pmmjcode    char(50) default ' ' not null,
  pmmjrdat    char(8) default ' ' not null,
  pmmjrtim    char(8) default ' ' not null,
  pmmjerrm    char(500) default ' ' not null,
  pmmjrcod    char(20) default ' ' not null,
  pmmjrdsc    char(100) default ' ' not null,
  pmmjrdet    char(100) default ' ' not null,
  pmmjstat    char(3) default ' ' not null,
  pmmjhosp    char(6) default ' ' not null,
  pmmjhosc    char(10) default ' ' not null,
  pmmjpaid    char(8) default ' ' not null,
  pmmjpsid    char(8) default ' ' not null,
  pmmjseid    char(6) default ' ' not null,
  pmmjadat    char(10) default ' ' not null,
  pmmjares    char(200) default ' ' not null,
  pmmjddat    char(10) default ' ' not null,
  pmmjrhcp    char(50) default ' ' not null,
  pmmjauth    char(50) default ' ' not null,
  pmmjetyp    char(100) default ' ' not null,
  pmmjelci    char(5) default ' ' not null,
  pmmjconw    char(3) default ' ' not null,
  pmmjward    char(5) default ' ' not null,
  pmmjroom    char(5) default ' ' not null,
  pmmjabed    char(5) default ' ' not null,
  pmmjedtc    char(10) default ' ' not null,
  pmmjedtm    char(10) default ' ' not null,
  pmmjcdat    char(8) default ' ' not null,
  pmmjctim    char(8) default ' ' not null,
  pmmjcuid    char(10) default ' ' not null,
  pmmjudat    char(8) default ' ' not null,
  pmmjutim    char(8) default ' ' not null,
  pmmjuuid    char(10) default ' ' not null,
  pmmjspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmsmhra1 on pmsmhraf
(
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
);
create unique index pmsmhra2 on pmsmhraf
(
pmmjhosp,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
);
create unique index pmsmhra3 on pmsmhraf
(
pmmjpsid,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
);
create unique index pmsmhra4 on pmsmhraf
(
pmmjpaid,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
);
create unique index pmsmhra5 on pmsmhraf
(
pmmjcode,
pmmjrtyp,
pmmjrdat,
pmmjrtim
);
revoke all on pmsmhraf from public ; 
grant select on pmsmhraf to public ; 
