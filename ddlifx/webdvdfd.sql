create table webdvdaf
(
  wbddclid    char(6) default ' ' not null,
  wbddrptc    char(3) default ' ' not null,
  wbddclbp    char(9) default ' ' not null,
  wbddclca    char(9) default ' ' not null,
  wbddsrvp    char(8) default ' ' not null,
  wbddstat    char(50) default ' ' not null,
  wbddtrid    char(24) default ' ' not null,
  wbddmsid    char(36) default ' ' not null,
  wbddrkey    char(24) default ' ' not null,
  wbddcuid    char(10) default ' ' not null,
  wbddcdat    char(8) default ' ' not null,
  wbddctim    char(8) default ' ' not null,
  wbdduuid    char(10) default ' ' not null,
  wbddudat    char(8) default ' ' not null,
  wbddutim    char(8) default ' ' not null,
  wbddspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvda1 on webdvdaf
(
wbddclid,
wbddrptc,
wbddrkey
);
create unique index webdvda2 on webdvdaf
(
wbddtrid,
wbddclid,
wbddrptc,
wbddrkey
);
create unique index webdvda3 on webdvdaf
(
wbddmsid,
wbddclid,
wbddrptc,
wbddrkey
);
create unique index webdvda4 on webdvdaf
(
wbddrkey,
wbddclid,
wbddrptc
);
revoke all on webdvdaf from public ; 
grant select on webdvdaf to public ; 
