create table webdvdaf
(
  wbddclid    varchar2(6) default ' ' not null,
  wbddrptc    varchar2(3) default ' ' not null,
  wbddclbp    varchar2(9) default ' ' not null,
  wbddclca    varchar2(9) default ' ' not null,
  wbddsrvp    varchar2(8) default ' ' not null,
  wbddstat    varchar2(50) default ' ' not null,
  wbddtrid    varchar2(24) default ' ' not null,
  wbddmsid    varchar2(36) default ' ' not null,
  wbddrkey    varchar2(24) default ' ' not null,
  wbddcuid    varchar2(10) default ' ' not null,
  wbddcdat    varchar2(8) default ' ' not null,
  wbddctim    varchar2(8) default ' ' not null,
  wbdduuid    varchar2(10) default ' ' not null,
  wbddudat    varchar2(8) default ' ' not null,
  wbddutim    varchar2(8) default ' ' not null,
  wbddspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvda1 primary key( 
wbddclid,
wbddrptc,
wbddrkey)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvda2 on webdvdaf
(
wbddtrid,
wbddclid,
wbddrptc,
wbddrkey
)
  tablespace pas_indx; 
create unique index webdvda3 on webdvdaf
(
wbddmsid,
wbddclid,
wbddrptc,
wbddrkey
)
  tablespace pas_indx; 
create unique index webdvda4 on webdvdaf
(
wbddrkey,
wbddclid,
wbddrptc
)
  tablespace pas_indx; 
