create table webdveaf
(
  wbdeclid    char(6) default ' ' not null,
  wbderptc    char(3) default ' ' not null,
  wbdemevc    char(2) default ' ' not null,
  wbdeevdt    char(8) default ' ' not null,
  wbdeevid    char(2) default ' ' not null,
  wbdeptsc    char(4) default ' ' not null,
  wbdeptst    char(500) default ' ' not null,
  wbdeptmn    char(10) default ' ' not null,
  wbdeptmr    char(1) default ' ' not null,
  wbdeptfn    char(40) default ' ' not null,
  wbdeptgn    char(40) default ' ' not null,
  wbdetrid    char(24) default ' ' not null,
  wbdemsid    char(36) default ' ' not null,
  wbderkey    char(24) default ' ' not null,
  wbdespar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvea1 on webdveaf
(
wbdeclid,
wbderptc,
wbdemevc,
wbderkey
);
create unique index webdvea2 on webdveaf
(
wbdetrid,
wbdeclid,
wbderptc,
wbdemevc,
wbderkey
);
create unique index webdvea3 on webdveaf
(
wbdemsid,
wbdeclid,
wbderptc,
wbdemevc,
wbderkey
);
create unique index webdvea4 on webdveaf
(
wbderkey,
wbdeclid,
wbderptc,
wbdemevc
);
revoke all on webdveaf from public ; 
grant select on webdveaf to public ; 
