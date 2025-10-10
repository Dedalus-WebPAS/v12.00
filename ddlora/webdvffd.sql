create table webdvfaf
(
  wbdfclid    varchar2(6) default ' ' not null,
  wbdfrptc    varchar2(3) default ' ' not null,
  wbdfmevc    varchar2(2) default ' ' not null,
  wbdfacrf    varchar2(8) default ' ' not null,
  wbdfsrvc    varchar2(2) default ' ' not null,
  wbdfassc    varchar2(4) default ' ' not null,
  wbdfbepd    varchar2(9) default ' ' not null,
  wbdfcham    varchar2(9) default ' ' not null,
  wbdfsvid    varchar2(4) default ' ' not null,
  wbdfitmn    varchar2(5) default ' ' not null,
  wbdfnofp    varchar2(2) default ' ' not null,
  wbdfprov    varchar2(8) default ' ' not null,
  wbdftrid    varchar2(24) default ' ' not null,
  wbdfmsid    varchar2(36) default ' ' not null,
  wbdfrkey    varchar2(24) default ' ' not null,
  wbdfspar    varchar2(150) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint webdvfa1 primary key( 
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index webdvfa2 on webdvfaf
(
wbdftrid,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey
)
  tablespace pas_indx; 
create unique index webdvfa3 on webdvfaf
(
wbdfmsid,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc,
wbdfrkey
)
  tablespace pas_indx; 
create unique index webdvfa4 on webdvfaf
(
wbdfrkey,
wbdfclid,
wbdfrptc,
wbdfmevc,
wbdfsrvc
)
  tablespace pas_indx; 
