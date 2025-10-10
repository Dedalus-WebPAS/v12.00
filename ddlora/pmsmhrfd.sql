create table pmsmhraf
(
  pmmjrtyp    varchar2(2) default ' ' not null,
  pmmjcode    varchar2(50) default ' ' not null,
  pmmjrdat    varchar2(8) default ' ' not null,
  pmmjrtim    varchar2(8) default ' ' not null,
  pmmjerrm    varchar2(500) default ' ' not null,
  pmmjrcod    varchar2(20) default ' ' not null,
  pmmjrdsc    varchar2(100) default ' ' not null,
  pmmjrdet    varchar2(100) default ' ' not null,
  pmmjstat    varchar2(3) default ' ' not null,
  pmmjhosp    varchar2(6) default ' ' not null,
  pmmjhosc    varchar2(10) default ' ' not null,
  pmmjpaid    varchar2(8) default ' ' not null,
  pmmjpsid    varchar2(8) default ' ' not null,
  pmmjseid    varchar2(6) default ' ' not null,
  pmmjadat    varchar2(10) default ' ' not null,
  pmmjares    varchar2(200) default ' ' not null,
  pmmjddat    varchar2(10) default ' ' not null,
  pmmjrhcp    varchar2(50) default ' ' not null,
  pmmjauth    varchar2(50) default ' ' not null,
  pmmjetyp    varchar2(100) default ' ' not null,
  pmmjelci    varchar2(5) default ' ' not null,
  pmmjconw    varchar2(3) default ' ' not null,
  pmmjward    varchar2(5) default ' ' not null,
  pmmjroom    varchar2(5) default ' ' not null,
  pmmjabed    varchar2(5) default ' ' not null,
  pmmjedtc    varchar2(10) default ' ' not null,
  pmmjedtm    varchar2(10) default ' ' not null,
  pmmjcdat    varchar2(8) default ' ' not null,
  pmmjctim    varchar2(8) default ' ' not null,
  pmmjcuid    varchar2(10) default ' ' not null,
  pmmjudat    varchar2(8) default ' ' not null,
  pmmjutim    varchar2(8) default ' ' not null,
  pmmjuuid    varchar2(10) default ' ' not null,
  pmmjspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmsmhra1 primary key( 
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index pmsmhra2 on pmsmhraf
(
pmmjhosp,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
)
  tablespace pas_indx; 
create unique index pmsmhra3 on pmsmhraf
(
pmmjpsid,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
)
  tablespace pas_indx; 
create unique index pmsmhra4 on pmsmhraf
(
pmmjpaid,
pmmjrtyp,
pmmjcode,
pmmjrdat,
pmmjrtim
)
  tablespace pas_indx; 
create unique index pmsmhra5 on pmsmhraf
(
pmmjcode,
pmmjrtyp,
pmmjrdat,
pmmjrtim
)
  tablespace pas_indx; 
