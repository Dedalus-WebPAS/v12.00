create table webdvaaf
(
  wbdainvn    char(8) default ' ' not null,
  wbdadate    char(8) default ' ' not null,
  wbdatime    char(8) default ' ' not null,
  wbdabatn    char(8) default ' ' not null,
  wbdastat    decimal(2,0) default 0 not null,
  wbdatype    char(2) default ' ' not null,
  wbdaoper    char(10) default ' ' not null,
  wbdatrid    char(24) default ' ' not null,
  wbdaeror    char(4) default ' ' not null,
  wbdaerot    char(100) default ' ' not null,
  wbdamodl    char(1) default ' ' not null,
  wbdamsid    char(36) default ' ' not null,
  wbdaspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvaa1 on webdvaaf
(
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
);
create unique index webdvaa2 on webdvaaf
(
wbdadate,
wbdatime,
wbdatype,
wbdainvn,
wbdamodl
);
create unique index webdvaa3 on webdvaaf
(
wbdainvn,
wbdabatn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
);
create unique index webdvaa4 on webdvaaf
(
wbdatrid,
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
);
create unique index webdvaa5 on webdvaaf
(
wbdamsid,
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
);
revoke all on webdvaaf from public ; 
grant select on webdvaaf to public ; 
