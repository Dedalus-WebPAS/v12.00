create table pmsqpxaf
(
  dpmqxmes    char(20) default ' ' not null,
  pmpxudt1    char(8) default ' ' not null,
  pmpxutm1    char(8) default ' ' not null,
  pmpxudt2    char(8) default ' ' not null,
  pmpxutm2    char(8) default ' ' not null,
  pmpxudt3    char(8) default ' ' not null,
  pmpxutm3    char(8) default ' ' not null,
  pmpxudt4    char(8) default ' ' not null,
  pmpxutm4    char(8) default ' ' not null,
  pmpxudt5    char(8) default ' ' not null,
  pmpxutm5    char(8) default ' ' not null,
  pmpxahc1    char(10) default ' ' not null,
  pmpxahg1    char(10) default ' ' not null,
  pmpxagc1    char(2) default ' ' not null,
  pmpxahc2    char(10) default ' ' not null,
  pmpxahg2    char(10) default ' ' not null,
  pmpxagc2    char(2) default ' ' not null,
  pmpxatf1    char(80) default ' ' not null,
  pmpxatf2    char(80) default ' ' not null,
  pmpxatf3    char(80) default ' ' not null,
  pmpxatf4    char(80) default ' ' not null,
  pmpxatf5    char(80) default ' ' not null,
  pmpxeth1    char(3) default ' ' not null,
  pmpxeth2    char(3) default ' ' not null,
  pmpxlan1    char(3) default ' ' not null,
  pmpxlan2    char(3) default ' ' not null,
  pmqxspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmsqpxa1 on pmsqpxaf
(
dpmqxmes
);
revoke all on pmsqpxaf from public ; 
grant select on pmsqpxaf to public ; 
