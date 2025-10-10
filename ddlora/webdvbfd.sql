create table webdvbaf
(
  wbdbbthn    varchar2(8) default ' ' not null,
  wbdbbthl    number(14,2) default 0 not null,
  wbdbtrib    number(6,0) default 0 not null,
  wbdbdtbc    varchar2(8) default ' ' not null,
  wbdbtmbc    varchar2(8) default ' ' not null,
  wbdboper    varchar2(10) default ' ' not null,
  wbdbefnm    varchar2(18) default ' ' not null,
  wbdblocn    varchar2(65) default ' ' not null,
  wbdbsnid    varchar2(60) default ' ' not null,
  wbdbspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvba1 primary key( 
wbdbbthn)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvba2 on webdvbaf
(
wbdbdtbc,
wbdbbthn
)
  tablespace pas_indx; 
