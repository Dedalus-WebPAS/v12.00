create table pmsqpxaf
(
  dpmqxmes    varchar2(20) default ' ' not null,
  pmpxudt1    varchar2(8) default ' ' not null,
  pmpxutm1    varchar2(8) default ' ' not null,
  pmpxudt2    varchar2(8) default ' ' not null,
  pmpxutm2    varchar2(8) default ' ' not null,
  pmpxudt3    varchar2(8) default ' ' not null,
  pmpxutm3    varchar2(8) default ' ' not null,
  pmpxudt4    varchar2(8) default ' ' not null,
  pmpxutm4    varchar2(8) default ' ' not null,
  pmpxudt5    varchar2(8) default ' ' not null,
  pmpxutm5    varchar2(8) default ' ' not null,
  pmpxahc1    varchar2(10) default ' ' not null,
  pmpxahg1    varchar2(10) default ' ' not null,
  pmpxagc1    varchar2(2) default ' ' not null,
  pmpxahc2    varchar2(10) default ' ' not null,
  pmpxahg2    varchar2(10) default ' ' not null,
  pmpxagc2    varchar2(2) default ' ' not null,
  pmpxatf1    varchar2(80) default ' ' not null,
  pmpxatf2    varchar2(80) default ' ' not null,
  pmpxatf3    varchar2(80) default ' ' not null,
  pmpxatf4    varchar2(80) default ' ' not null,
  pmpxatf5    varchar2(80) default ' ' not null,
  pmpxeth1    varchar2(3) default ' ' not null,
  pmpxeth2    varchar2(3) default ' ' not null,
  pmpxlan1    varchar2(3) default ' ' not null,
  pmpxlan2    varchar2(3) default ' ' not null,
  pmqxspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmsqpxa1 primary key( 
dpmqxmes)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
