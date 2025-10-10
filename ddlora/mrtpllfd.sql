create table mrtpllaf
(
  mrplvisn    varchar2(8) default ' ' not null,
  mrplmrky    varchar2(10) default ' ' not null,
  mrplrqst    varchar2(2) default ' ' not null,
  mrplcuid    varchar2(10) default ' ' not null,
  mrplcdat    varchar2(8) default ' ' not null,
  mrplctim    varchar2(8) default ' ' not null,
  mrpluuid    varchar2(10) default ' ' not null,
  mrpludat    varchar2(8) default ' ' not null,
  mrplutim    varchar2(8) default ' ' not null,
  mrpludf1    varchar2(10) default ' ' not null,
  mrpludf2    varchar2(10) default ' ' not null,
  mrpludc1    varchar2(3) default ' ' not null,
  mrpludc2    varchar2(3) default ' ' not null,
  mrplftx1    varchar2(80) default ' ' not null,
  mrplftx2    varchar2(80) default ' ' not null,
  mrplspar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint mrtplla1 primary key( 
mrplvisn,
mrplmrky,
mrplrqst)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
