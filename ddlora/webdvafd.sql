create table webdvaaf
(
  wbdainvn    varchar2(8) default ' ' not null,
  wbdadate    varchar2(8) default ' ' not null,
  wbdatime    varchar2(8) default ' ' not null,
  wbdabatn    varchar2(8) default ' ' not null,
  wbdastat    number(2,0) default 0 not null,
  wbdatype    varchar2(2) default ' ' not null,
  wbdaoper    varchar2(10) default ' ' not null,
  wbdatrid    varchar2(24) default ' ' not null,
  wbdaeror    varchar2(4) default ' ' not null,
  wbdaerot    varchar2(100) default ' ' not null,
  wbdamodl    varchar2(1) default ' ' not null,
  wbdamsid    varchar2(36) default ' ' not null,
  wbdaspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvaa1 primary key( 
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvaa2 on webdvaaf
(
wbdadate,
wbdatime,
wbdatype,
wbdainvn,
wbdamodl
)
  tablespace pas_indx; 
create unique index webdvaa3 on webdvaaf
(
wbdainvn,
wbdabatn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
)
  tablespace pas_indx; 
create unique index webdvaa4 on webdvaaf
(
wbdatrid,
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
)
  tablespace pas_indx; 
create unique index webdvaa5 on webdvaaf
(
wbdamsid,
wbdainvn,
wbdadate,
wbdatime,
wbdatype,
wbdamodl
)
  tablespace pas_indx; 
