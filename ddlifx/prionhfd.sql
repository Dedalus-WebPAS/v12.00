create table prionhaf
(
  pronuniq    char(8) default ' ' not null,
  prontdat    char(8) default ' ' not null,
  pronttim    char(8) default ' ' not null,
  pronusid    char(10) default ' ' not null,
  pronhrsn    char(3) default ' ' not null,
  pronftxt    char(80) default ' ' not null,
  pronactn    char(1) default ' ' not null,
  prondoct    char(10) default ' ' not null,
  pronprac    char(6) default ' ' not null,
  pronpind    char(3) default ' ' not null,
  pronclam    char(3) default ' ' not null,
  pronhfnd    char(6) default ' ' not null,
  pronhifd    char(8) default ' ' not null,
  pronspar    char(50) default ' ' not null,
  lf          char(1)
);
create unique index prionha1 on prionhaf
(
pronuniq,
prontdat,
pronttim
);
revoke all on prionhaf from public ; 
grant select on prionhaf to public ; 
