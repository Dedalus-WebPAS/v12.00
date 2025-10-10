create table pmsmhqaf
(
  pmmqrtyp    char(2) default ' ' not null,
  pmmqcode    char(50) default ' ' not null,
  pmmqrdat    char(8) default ' ' not null,
  pmmqrtim    char(8) default ' ' not null,
  pmmqruid    char(10) default ' ' not null,
  pmmqhosp    char(6) default ' ' not null,
  pmmqepid    char(8) default ' ' not null,
  pmmqadat    char(8) default ' ' not null,
  pmmqreas    char(200) default ' ' not null,
  pmmqetyp    char(1) default ' ' not null,
  pmmqelcy    char(2) default ' ' not null,
  pmmqcons    char(1) default ' ' not null,
  pmmqauth    char(10) default ' ' not null,
  pmmqrhcp    char(10) default ' ' not null,
  pmmqb64p    char(200) default ' ' not null,
  pmmqmime    char(6) default ' ' not null,
  pmmqflnm    char(50) default ' ' not null,
  pmmqsubj    char(50) default ' ' not null,
  pmmqurno    char(8) default ' ' not null,
  pmmqcdat    char(8) default ' ' not null,
  pmmqctim    char(8) default ' ' not null,
  pmmqcuid    char(10) default ' ' not null,
  pmmqudat    char(8) default ' ' not null,
  pmmqutim    char(8) default ' ' not null,
  pmmquuid    char(10) default ' ' not null,
  pmmqspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmsmhqa1 on pmsmhqaf
(
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa2 on pmsmhqaf
(
pmmqhosp,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa3 on pmsmhqaf
(
pmmqurno,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa4 on pmsmhqaf
(
pmmqepid,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa5 on pmsmhqaf
(
pmmqcode,
pmmqrtyp,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa6 on pmsmhqaf
(
pmmqadat,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
create unique index pmsmhqa7 on pmsmhqaf
(
pmmqhosp,
pmmqcdat,
pmmqctim,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
);
revoke all on pmsmhqaf from public ; 
grant select on pmsmhqaf to public ; 
