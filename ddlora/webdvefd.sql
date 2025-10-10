create table webdveaf
(
  wbdeclid    varchar2(6) default ' ' not null,
  wbderptc    varchar2(3) default ' ' not null,
  wbdemevc    varchar2(2) default ' ' not null,
  wbdeevdt    varchar2(8) default ' ' not null,
  wbdeevid    varchar2(2) default ' ' not null,
  wbdeptsc    varchar2(4) default ' ' not null,
  wbdeptst    varchar2(500) default ' ' not null,
  wbdeptmn    varchar2(10) default ' ' not null,
  wbdeptmr    varchar2(1) default ' ' not null,
  wbdeptfn    varchar2(40) default ' ' not null,
  wbdeptgn    varchar2(40) default ' ' not null,
  wbdetrid    varchar2(24) default ' ' not null,
  wbdemsid    varchar2(36) default ' ' not null,
  wbderkey    varchar2(24) default ' ' not null,
  wbdespar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvea1 primary key( 
wbdeclid,
wbderptc,
wbdemevc,
wbderkey)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvea2 on webdveaf
(
wbdetrid,
wbdeclid,
wbderptc,
wbdemevc,
wbderkey
)
  tablespace pas_indx; 
create unique index webdvea3 on webdveaf
(
wbdemsid,
wbdeclid,
wbderptc,
wbdemevc,
wbderkey
)
  tablespace pas_indx; 
create unique index webdvea4 on webdveaf
(
wbderkey,
wbdeclid,
wbderptc,
wbdemevc
)
  tablespace pas_indx; 
