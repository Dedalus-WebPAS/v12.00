create table prionhaf
(
  pronuniq    varchar2(8) default ' ' not null,
  prontdat    varchar2(8) default ' ' not null,
  pronttim    varchar2(8) default ' ' not null,
  pronusid    varchar2(10) default ' ' not null,
  pronhrsn    varchar2(3) default ' ' not null,
  pronftxt    varchar2(80) default ' ' not null,
  pronactn    varchar2(1) default ' ' not null,
  prondoct    varchar2(10) default ' ' not null,
  pronprac    varchar2(6) default ' ' not null,
  pronpind    varchar2(3) default ' ' not null,
  pronclam    varchar2(3) default ' ' not null,
  pronhfnd    varchar2(6) default ' ' not null,
  pronhifd    varchar2(8) default ' ' not null,
  pronspar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint prionha1 primary key( 
pronuniq,
prontdat,
pronttim)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
