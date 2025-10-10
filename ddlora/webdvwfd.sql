create table webdvwaf
(
  wbdwhosp    varchar2(3) default ' ' not null,
  dwbdwflg    varchar2(2) default ' ' not null,
  wbdwmodl    varchar2(1) default ' ' not null,
  wbdwuniq    varchar2(8) default ' ' not null,
  wbdwinvn    varchar2(8) default ' ' not null,
  wbdwbatn    varchar2(8) default ' ' not null,
  wbdwurno    varchar2(8) default ' ' not null,
  wbdwpbat    varchar2(8) default ' ' not null,
  wbdwnbat    varchar2(8) default ' ' not null,
  wbdwtrid    varchar2(24) default ' ' not null,
  dwbdweet    varchar2(1) default ' ' not null,
  wbdwamtc    number(14,2) default 0 not null,
  wbdwamdp    number(14,2) default 0 not null,
  wbdwammp    number(14,2) default 0 not null,
  wbdwpdat    varchar2(8) default ' ' not null,
  wbdwstat    varchar2(2) default ' ' not null,
  wbdwclid    varchar2(6) default ' ' not null,
  wbdwrkey    varchar2(24) default ' ' not null,
  wbdwokey    varchar2(36) default ' ' not null,
  wbdwprac    varchar2(10) default ' ' not null,
  wbdwmsid    varchar2(36) default ' ' not null,
  wbdwprov    varchar2(8) default ' ' not null,
  wbdwctyp    varchar2(2) default ' ' not null,
  wbdwcuid    varchar2(10) default ' ' not null,
  wbdwcdat    varchar2(8) default ' ' not null,
  wbdwctim    varchar2(8) default ' ' not null,
  wbdwuuid    varchar2(10) default ' ' not null,
  wbdwudat    varchar2(8) default ' ' not null,
  wbdwutim    varchar2(8) default ' ' not null,
  wbdwspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvwa1 primary key( 
wbdwhosp,
dwbdwflg,
wbdwmodl,
wbdwuniq,
wbdwinvn,
wbdwbatn)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvwa2 on webdvwaf
(
wbdwinvn,
wbdwbatn,
wbdwmodl
)
  tablespace pas_indx; 
create unique index webdvwa3 on webdvwaf
(
wbdwbatn,
wbdwuniq,
wbdwinvn
)
  tablespace pas_indx; 
create unique index webdvwa4 on webdvwaf
(
wbdwuniq,
wbdwinvn,
wbdwbatn
)
  tablespace pas_indx; 
create unique index webdvwa5 on webdvwaf
(
wbdwhosp,
wbdwurno,
wbdwuniq,
wbdwinvn,
wbdwbatn
)
  tablespace pas_indx; 
create unique index webdvwa6 on webdvwaf
(
wbdwtrid,
wbdwinvn,
wbdwbatn
)
  tablespace pas_indx; 
create unique index webdvwa7 on webdvwaf
(
dwbdwflg,
wbdwhosp,
wbdwmodl,
wbdwuniq,
wbdwinvn,
wbdwbatn
)
  tablespace pas_indx; 
