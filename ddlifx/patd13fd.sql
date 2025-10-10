create table patd13af
(
  dpcode      char(9) default ' ' not null,
  ddesc       char(70) default ' ' not null,
  dflag       char(1) default ' ' not null,
  dagegp      char(1) default ' ' not null,
  ptxdall1    decimal(3,0) default 0 not null,
  ptxdahl1    decimal(3,0) default 0 not null,
  pt0d2agp    char(1) default ' ' not null,
  ptxdall2    decimal(3,0) default 0 not null,
  ptxdahl2    decimal(3,0) default 0 not null,
  dsex        char(1) default ' ' not null,
  pt0dadtp    char(1) default ' ' not null,
  pt0dprfx    char(2) default ' ' not null,
  pt0dsac2    char(7) default ' ' not null,
  ddagger     char(1) default ' ' not null,
  darea       char(1) default ' ' not null,
  pt0dcpra    char(1) default ' ' not null,
  pt0dacrq    char(1) default ' ' not null,
  pt0dmi9c    char(9) default ' ' not null,
  dpt0dcmf    char(2) default ' ' not null,
  dpt0dv1c    char(1) default ' ' not null,
  dpt0dv2c    char(1) default ' ' not null,
  pt0dv1mp    char(9) default ' ' not null,
  dpt0dv3c    char(1) default ' ' not null,
  pt0dv2mp    char(9) default ' ' not null,
  dpt0dv4c    char(1) default ' ' not null,
  dpt0dv5c    char(1) default ' ' not null,
  dpt0dv6c    char(1) default ' ' not null,
  pt0ddsc2    char(200) default ' ' not null,
  dpt0dv7c    char(1) default ' ' not null,
  dpt0dv8c    char(1) default ' ' not null,
  dpt0dv9c    char(1) default ' ' not null,
  dpt0dvxc    char(1) default ' ' not null,
  ptodmeth    char(1) default ' ' not null,
  dpt0dvx1    char(1) default ' ' not null,
  dpt0dvx2    char(1) default ' ' not null,
  dpt0dvx3    char(1) default ' ' not null,
  pt0dcarq    char(1) default ' ' not null,
  ptdspr13    char(48) default ' ' not null,
  lf          char(1)
);
create unique index patd13a1 on patd13af
(
dpcode
);
create unique index patd13a2 on patd13af
(
ddesc,
dpcode
);
revoke all on patd13af from public ; 
grant select on patd13af to public ; 
