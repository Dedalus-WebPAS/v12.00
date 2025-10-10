create table webdvbaf
(
  wbdbbthn    char(8) default ' ' not null,
  wbdbbthl    decimal(14,2) default 0 not null,
  wbdbtrib    decimal(6,0) default 0 not null,
  wbdbdtbc    char(8) default ' ' not null,
  wbdbtmbc    char(8) default ' ' not null,
  wbdboper    char(10) default ' ' not null,
  wbdbefnm    char(18) default ' ' not null,
  wbdblocn    char(65) default ' ' not null,
  wbdbsnid    char(60) default ' ' not null,
  wbdbspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvba1 on webdvbaf
(
wbdbbthn
);
create unique index webdvba2 on webdvbaf
(
wbdbdtbc,
wbdbbthn
);
revoke all on webdvbaf from public ; 
grant select on webdvbaf to public ; 
