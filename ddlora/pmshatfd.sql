create table pmshataf
(
  pmhthosp    varchar2(3) default ' ' not null,
  pmhttype    varchar2(3) default ' ' not null,
  pmhtkval    varchar2(25) default ' ' not null,
  pmhtsdat    varchar2(8) default ' ' not null,
  pmhtedat    varchar2(8) default ' ' not null,
  pmhttxt1    varchar2(80) default ' ' not null,
  pmhttxt2    varchar2(80) default ' ' not null,
  pmhttxt3    varchar2(80) default ' ' not null,
  pmhttxt4    varchar2(80) default ' ' not null,
  pmhtval1    varchar2(6) default ' ' not null,
  pmhtval2    varchar2(6) default ' ' not null,
  pmhtval3    varchar2(6) default ' ' not null,
  pmhtval4    varchar2(6) default ' ' not null,
  pmhtind1    varchar2(1) default ' ' not null,
  pmhtind2    varchar2(1) default ' ' not null,
  pmhtind3    varchar2(1) default ' ' not null,
  pmhtind4    varchar2(1) default ' ' not null,
  pmhtcod1    varchar2(3) default ' ' not null,
  pmhtcod2    varchar2(3) default ' ' not null,
  pmhtcod3    varchar2(3) default ' ' not null,
  pmhtcod4    varchar2(3) default ' ' not null,
  pmhtcusr    varchar2(10) default ' ' not null,
  pmhtcdat    varchar2(8) default ' ' not null,
  pmhtctim    varchar2(8) default ' ' not null,
  pmhtuusr    varchar2(10) default ' ' not null,
  pmhtudat    varchar2(8) default ' ' not null,
  pmhtutim    varchar2(8) default ' ' not null,
  pmhtfusr    varchar2(10) default ' ' not null,
  pmhtfdat    varchar2(8) default ' ' not null,
  pmhtftim    varchar2(8) default ' ' not null,
  pmhtspar    varchar2(100) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmshata1 primary key( 
pmhthosp,
pmhttype,
pmhtkval,
pmhtsdat)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
