create table mrtvisaf
(
  mrvsvsno    varchar2(8) default ' ' not null,
  mrvsmkey    varchar2(10) default ' ' not null,
  mrvsxky1    varchar2(10) default ' ' not null,
  mrvsxky2    varchar2(10) default ' ' not null,
  mrvsxky3    varchar2(10) default ' ' not null,
  mrvsxky4    varchar2(10) default ' ' not null,
  mrvsxky5    varchar2(10) default ' ' not null,
  mrvsspar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint mrtvisa1 primary key( 
mrvsvsno)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index mrtvisa2 on mrtvisaf
(
mrvsmkey,
mrvsvsno
)
  tablespace pas_indx; 
