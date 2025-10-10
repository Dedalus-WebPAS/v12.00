create table webdvhaf
(
  wbdhhosp    char(3) default ' ' not null,
  wbdhpypn    char(8) default ' ' not null,
  wbdhprun    char(4) default ' ' not null,
  wbdhpdat    char(8) default ' ' not null,
  wbdhdamn    char(9) default ' ' not null,
  wbdhaccn    char(9) default ' ' not null,
  wbdhacnm    char(30) default ' ' not null,
  wbdhbsbc    char(6) default ' ' not null,
  wbdhstat    char(1) default ' ' not null,
  wbdhrsta    char(50) default ' ' not null,
  wbdhrkey    char(24) default ' ' not null,
  wbdhmsid    char(36) default ' ' not null,
  wbdhspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvha1 on webdvhaf
(
wbdhhosp,
wbdhpypn,
wbdhprun,
wbdhpdat,
wbdhrkey
);
create unique index webdvha2 on webdvhaf
(
wbdhhosp,
wbdhpdat,
wbdhpypn,
wbdhprun,
wbdhrkey
);
create unique index webdvha3 on webdvhaf
(
wbdhhosp,
wbdhstat,
wbdhpdat,
wbdhpypn,
wbdhprun,
wbdhrkey
);
create unique index webdvha4 on webdvhaf
(
wbdhhosp,
wbdhrkey,
wbdhpypn,
wbdhprun,
wbdhpdat
);
create unique index webdvha5 on webdvhaf
(
wbdhrkey,
wbdhhosp,
wbdhpypn,
wbdhprun,
wbdhpdat
);
revoke all on webdvhaf from public ; 
grant select on webdvhaf to public ; 
