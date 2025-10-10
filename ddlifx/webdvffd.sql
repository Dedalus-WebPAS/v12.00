create table webdvfaf
(
  wbdfclid    char(6) default ' ' not null,
  wbdfrptc    char(3) default ' ' not null,
  wbdfmevc    char(2) default ' ' not null,
  wbdfacrf    char(8) default ' ' not null,
  wbdfsrvc    char(2) default ' ' not null,
  wbdfassc    char(4) default ' ' not null,
  wbdfbepd    char(9) default ' ' not null,
  wbdfcham    char(9) default ' ' not null,
  wbdfsvid    char(4) default ' ' not null,
  wbdfitmn    char(5) default ' ' not null,
  wbdfnofp    char(2) default ' ' not null,
  wbdfprov    char(8) default ' ' not null,
  wbdftrid    char(24) default ' ' not null,
  wbdfmsid    char(36) default ' ' not null,
  wbdfrkey    char(24) default ' ' not null,
  wbdfspar    char(150) default ' ' not null,
  lf          char(1)
);
create unique index webdvfa1 on webdvfaf
(
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey
);
create unique index webdvfa2 on webdvfaf
(
wbdftrid,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey
);
create unique index webdvfa3 on webdvfaf
(
wbdfmsid,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey
);
create unique index webdvfa4 on webdvfaf
(
wbdfrkey,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc
);
revoke all on webdvfaf from public ; 
grant select on webdvfaf to public ; 
