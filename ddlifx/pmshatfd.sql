create table pmshataf
(
  pmhthosp    char(3) default ' ' not null,
  pmhttype    char(3) default ' ' not null,
  pmhtkval    char(25) default ' ' not null,
  pmhtsdat    char(8) default ' ' not null,
  pmhtedat    char(8) default ' ' not null,
  pmhttxt1    char(80) default ' ' not null,
  pmhttxt2    char(80) default ' ' not null,
  pmhttxt3    char(80) default ' ' not null,
  pmhttxt4    char(80) default ' ' not null,
  pmhtval1    char(6) default ' ' not null,
  pmhtval2    char(6) default ' ' not null,
  pmhtval3    char(6) default ' ' not null,
  pmhtval4    char(6) default ' ' not null,
  pmhtind1    char(1) default ' ' not null,
  pmhtind2    char(1) default ' ' not null,
  pmhtind3    char(1) default ' ' not null,
  pmhtind4    char(1) default ' ' not null,
  pmhtcod1    char(3) default ' ' not null,
  pmhtcod2    char(3) default ' ' not null,
  pmhtcod3    char(3) default ' ' not null,
  pmhtcod4    char(3) default ' ' not null,
  pmhtcusr    char(10) default ' ' not null,
  pmhtcdat    char(8) default ' ' not null,
  pmhtctim    char(8) default ' ' not null,
  pmhtuusr    char(10) default ' ' not null,
  pmhtudat    char(8) default ' ' not null,
  pmhtutim    char(8) default ' ' not null,
  pmhtfusr    char(10) default ' ' not null,
  pmhtfdat    char(8) default ' ' not null,
  pmhtftim    char(8) default ' ' not null,
  pmhtspar    char(100) default ' ' not null,
  lf          char(1)
);
create unique index pmshata1 on pmshataf
(
pmhthosp,
pmhttype,
pmhtkval,
pmhtsdat
);
revoke all on pmshataf from public ; 
grant select on pmshataf to public ; 
