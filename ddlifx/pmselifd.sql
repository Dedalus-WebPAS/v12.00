create table pmseliaf
(
  pmeivisn    char(8) default ' ' not null,
  pmeirtyp    char(1) default ' ' not null,
  pmeicntr    char(3) default ' ' not null,
  pmeiitmn    char(9) default ' ' not null,
  pmeiserv    decimal(5,0) default 0 not null,
  pmeigste    char(1) default ' ' not null,
  pmeigsta    char(1) default ' ' not null,
  pmeigstc    char(6) default ' ' not null,
  pmeikeyi    char(1) default ' ' not null,
  pmeiamnt    decimal(14,2) default 0 not null,
  pmeispar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmselia1 on pmseliaf
(
pmeivisn,
pmeirtyp,
pmeicntr
);
revoke all on pmseliaf from public ; 
grant select on pmseliaf to public ; 
