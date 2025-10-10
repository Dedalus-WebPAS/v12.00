create table allcctaf
(
  alccdept    varchar2(3) default ' ' not null,
  alcccont    varchar2(3) default ' ' not null,
  alcccdat    varchar2(8) default ' ' not null,
  alccctim    varchar2(8) default ' ' not null,
  alcccuid    varchar2(10) default ' ' not null,
  alccudat    varchar2(8) default ' ' not null,
  alccutim    varchar2(8) default ' ' not null,
  alccuuid    varchar2(10) default ' ' not null,
  alcctype    varchar2(2) default ' ' not null,
  alccspar    varchar2(48) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint allccta1 primary key( 
alccdept,
alcctype,
alcccont)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
