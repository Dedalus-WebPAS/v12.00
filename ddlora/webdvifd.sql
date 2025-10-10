create table webdviaf
(
  wbdihosp    varchar2(3) default ' ' not null,
  wbdipypn    varchar2(8) default ' ' not null,
  wbdiprun    varchar2(4) default ' ' not null,
  wbdipdat    varchar2(8) default ' ' not null,
  wbdiclbp    varchar2(9) default ' ' not null,
  wbdiclca    varchar2(9) default ' ' not null,
  wbdiclid    varchar2(6) default ' ' not null,
  wbdildat    varchar2(8) default ' ' not null,
  wbditrid    varchar2(24) default ' ' not null,
  wbdirkey    varchar2(24) default ' ' not null,
  wbdistat    varchar2(1) default ' ' not null,
  wbdiltyp    varchar2(2) default ' ' not null,
  wbdimsid    varchar2(36) default ' ' not null,
  wbdispar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvia1 primary key( 
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid,
wbditrid)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvia2 on webdviaf
(
wbditrid,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid
)
  tablespace pas_indx; 
create unique index webdvia3 on webdviaf
(
wbdirkey,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid,
wbditrid
)
  tablespace pas_indx; 
create unique index webdvia4 on webdviaf
(
wbdirkey,
wbditrid,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid
)
  tablespace pas_indx; 
