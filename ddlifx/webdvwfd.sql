create table webdvwaf
(
  wbdwhosp    char(3) default ' ' not null,
  dwbdwflg    char(2) default ' ' not null,
  wbdwmodl    char(1) default ' ' not null,
  wbdwuniq    char(8) default ' ' not null,
  wbdwinvn    char(8) default ' ' not null,
  wbdwbatn    char(8) default ' ' not null,
  wbdwurno    char(8) default ' ' not null,
  wbdwpbat    char(8) default ' ' not null,
  wbdwnbat    char(8) default ' ' not null,
  wbdwtrid    char(24) default ' ' not null,
  dwbdweet    char(1) default ' ' not null,
  wbdwamtc    decimal(14,2) default 0 not null,
  wbdwamdp    decimal(14,2) default 0 not null,
  wbdwammp    decimal(14,2) default 0 not null,
  wbdwpdat    char(8) default ' ' not null,
  wbdwstat    char(2) default ' ' not null,
  wbdwclid    char(6) default ' ' not null,
  wbdwrkey    char(24) default ' ' not null,
  wbdwokey    char(36) default ' ' not null,
  wbdwprac    char(10) default ' ' not null,
  wbdwmsid    char(36) default ' ' not null,
  wbdwprov    char(8) default ' ' not null,
  wbdwctyp    char(2) default ' ' not null,
  wbdwcuid    char(10) default ' ' not null,
  wbdwcdat    char(8) default ' ' not null,
  wbdwctim    char(8) default ' ' not null,
  wbdwuuid    char(10) default ' ' not null,
  wbdwudat    char(8) default ' ' not null,
  wbdwutim    char(8) default ' ' not null,
  wbdwspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index webdvwa1 on webdvwaf
(
wbdwhosp,
dwbdwflg,
wbdwmodl,
wbdwuniq,
wbdwinvn,
wbdwbatn
);
create unique index webdvwa2 on webdvwaf
(
wbdwinvn,
wbdwbatn,
wbdwmodl
);
create unique index webdvwa3 on webdvwaf
(
wbdwbatn,
wbdwuniq,
wbdwinvn
);
create unique index webdvwa4 on webdvwaf
(
wbdwuniq,
wbdwinvn,
wbdwbatn
);
create unique index webdvwa5 on webdvwaf
(
wbdwhosp,
wbdwurno,
wbdwuniq,
wbdwinvn,
wbdwbatn
);
create unique index webdvwa6 on webdvwaf
(
wbdwtrid,
wbdwinvn,
wbdwbatn
);
create unique index webdvwa7 on webdvwaf
(
dwbdwflg,
wbdwhosp,
wbdwmodl,
wbdwuniq,
wbdwinvn,
wbdwbatn
);
revoke all on webdvwaf from public ; 
grant select on webdvwaf to public ; 
