create table pmseliaf
(
  pmeivisn    varchar2(8) default ' ' not null,
  pmeirtyp    varchar2(1) default ' ' not null,
  pmeicntr    varchar2(3) default ' ' not null,
  pmeiitmn    varchar2(9) default ' ' not null,
  pmeiserv    number(5,0) default 0 not null,
  pmeigste    varchar2(1) default ' ' not null,
  pmeigsta    varchar2(1) default ' ' not null,
  pmeigstc    varchar2(6) default ' ' not null,
  pmeikeyi    varchar2(1) default ' ' not null,
  pmeiamnt    number(14,2) default 0 not null,
  pmeispar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmselia1 primary key( 
pmeivisn,
pmeirtyp,
pmeicntr)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
