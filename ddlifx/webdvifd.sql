create table webdviaf
(
  wbdihosp    char(3) default ' ' not null,
  wbdipypn    char(8) default ' ' not null,
  wbdiprun    char(4) default ' ' not null,
  wbdipdat    char(8) default ' ' not null,
  wbdiclbp    char(9) default ' ' not null,
  wbdiclca    char(9) default ' ' not null,
  wbdiclid    char(6) default ' ' not null,
  wbdildat    char(8) default ' ' not null,
  wbditrid    char(24) default ' ' not null,
  wbdirkey    char(24) default ' ' not null,
  wbdistat    char(1) default ' ' not null,
  wbdiltyp    char(2) default ' ' not null,
  wbdimsid    char(36) default ' ' not null,
  wbdispar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvia1 on webdviaf
(
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid,
wbditrid
);
create unique index webdvia2 on webdviaf
(
wbditrid,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid
);
create unique index webdvia3 on webdviaf
(
wbdirkey,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid,
wbditrid
);
create unique index webdvia4 on webdviaf
(
wbdirkey,
wbditrid,
wbdihosp,
wbdipypn,
wbdiprun,
wbdipdat,
wbdiclid
);
revoke all on webdviaf from public ; 
grant select on webdviaf to public ; 
