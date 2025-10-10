create table webdvhaf
(
  wbdhhosp    varchar2(3) default ' ' not null,
  wbdhpypn    varchar2(8) default ' ' not null,
  wbdhprun    varchar2(4) default ' ' not null,
  wbdhpdat    varchar2(8) default ' ' not null,
  wbdhdamn    varchar2(9) default ' ' not null,
  wbdhaccn    varchar2(9) default ' ' not null,
  wbdhacnm    varchar2(30) default ' ' not null,
  wbdhbsbc    varchar2(6) default ' ' not null,
  wbdhstat    varchar2(1) default ' ' not null,
  wbdhrsta    varchar2(50) default ' ' not null,
  wbdhrkey    varchar2(24) default ' ' not null,
  wbdhmsid    varchar2(36) default ' ' not null,
  wbdhspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvha1 primary key( 
wbdhhosp,
wbdhpypn,
wbdhprun,
wbdhpdat,
wbdhrkey)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvha2 on webdvhaf
(
wbdhhosp,
wbdhpdat,
wbdhpypn,
wbdhprun,
wbdhrkey
)
  tablespace pas_indx; 
create unique index webdvha3 on webdvhaf
(
wbdhhosp,
wbdhstat,
wbdhpdat,
wbdhpypn,
wbdhprun,
wbdhrkey
)
  tablespace pas_indx; 
create unique index webdvha4 on webdvhaf
(
wbdhhosp,
wbdhrkey,
wbdhpypn,
wbdhprun,
wbdhpdat
)
  tablespace pas_indx; 
create unique index webdvha5 on webdvhaf
(
wbdhrkey,
wbdhhosp,
wbdhpypn,
wbdhprun,
wbdhpdat
)
  tablespace pas_indx; 
