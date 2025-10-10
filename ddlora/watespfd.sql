create table watespaf
(
  wtepurno    varchar2(8) default ' ' not null,
  wtepedat    varchar2(8) default ' ' not null,
  wteppdob    varchar2(8) default ' ' not null,
  wteppsex    varchar2(1) default ' ' not null,
  wtepmedi    varchar2(10) default ' ' not null,
  wtepmref    varchar2(1) default ' ' not null,
  wtepresi    varchar2(3) default ' ' not null,
  wteppost    varchar2(4) default ' ' not null,
  wtepsubr    varchar2(35) default ' ' not null,
  wtepwebc    varchar2(10) default ' ' not null,
  wtepcdat    varchar2(8) default ' ' not null,
  wtepctim    varchar2(8) default ' ' not null,
  wtepwebu    varchar2(10) default ' ' not null,
  wtepudat    varchar2(8) default ' ' not null,
  wteputim    varchar2(8) default ' ' not null,
  wtepabrg    varchar2(3) default ' ' not null,
  wtepedob    varchar2(1) default ' ' not null,
  wteppgen    varchar2(3) default ' ' not null,
  wtepndis    varchar2(9) default ' ' not null,
  wtepspar    varchar2(34) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint watespa1 primary key( 
wtepurno,
wtepedat)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index watespa2 on watespaf
(
wtepedat,
wtepurno
)
  tablespace pas_indx; 
