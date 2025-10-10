create table pmsmhqaf
(
  pmmqrtyp    varchar2(2) default ' ' not null,
  pmmqcode    varchar2(50) default ' ' not null,
  pmmqrdat    varchar2(8) default ' ' not null,
  pmmqrtim    varchar2(8) default ' ' not null,
  pmmqruid    varchar2(10) default ' ' not null,
  pmmqhosp    varchar2(6) default ' ' not null,
  pmmqepid    varchar2(8) default ' ' not null,
  pmmqadat    varchar2(8) default ' ' not null,
  pmmqreas    varchar2(200) default ' ' not null,
  pmmqetyp    varchar2(1) default ' ' not null,
  pmmqelcy    varchar2(2) default ' ' not null,
  pmmqcons    varchar2(1) default ' ' not null,
  pmmqauth    varchar2(10) default ' ' not null,
  pmmqrhcp    varchar2(10) default ' ' not null,
  pmmqb64p    varchar2(200) default ' ' not null,
  pmmqmime    varchar2(6) default ' ' not null,
  pmmqflnm    varchar2(50) default ' ' not null,
  pmmqsubj    varchar2(50) default ' ' not null,
  pmmqurno    varchar2(8) default ' ' not null,
  pmmqcdat    varchar2(8) default ' ' not null,
  pmmqctim    varchar2(8) default ' ' not null,
  pmmqcuid    varchar2(10) default ' ' not null,
  pmmqudat    varchar2(8) default ' ' not null,
  pmmqutim    varchar2(8) default ' ' not null,
  pmmquuid    varchar2(10) default ' ' not null,
  pmmqspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmsmhqa1 primary key( 
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index pmsmhqa2 on pmsmhqaf
(
pmmqhosp,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
create unique index pmsmhqa3 on pmsmhqaf
(
pmmqurno,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
create unique index pmsmhqa4 on pmsmhqaf
(
pmmqepid,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
create unique index pmsmhqa5 on pmsmhqaf
(
pmmqcode,
pmmqrtyp,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
create unique index pmsmhqa6 on pmsmhqaf
(
pmmqadat,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
create unique index pmsmhqa7 on pmsmhqaf
(
pmmqhosp,
pmmqcdat,
pmmqctim,
pmmqrtyp,
pmmqcode,
pmmqrdat,
pmmqrtim
)
  tablespace pas_indx; 
