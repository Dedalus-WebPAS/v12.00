create table watespaf
(
  wtepurno    char(8) default ' ' not null,
  wtepedat    char(8) default ' ' not null,
  wteppdob    char(8) default ' ' not null,
  wteppsex    char(1) default ' ' not null,
  wtepmedi    char(10) default ' ' not null,
  wtepmref    char(1) default ' ' not null,
  wtepresi    char(3) default ' ' not null,
  wteppost    char(4) default ' ' not null,
  wtepsubr    char(35) default ' ' not null,
  wtepwebc    char(10) default ' ' not null,
  wtepcdat    char(8) default ' ' not null,
  wtepctim    char(8) default ' ' not null,
  wtepwebu    char(10) default ' ' not null,
  wtepudat    char(8) default ' ' not null,
  wteputim    char(8) default ' ' not null,
  wtepabrg    char(3) default ' ' not null,
  wtepedob    char(1) default ' ' not null,
  wteppgen    char(3) default ' ' not null,
  wtepndis    char(9) default ' ' not null,
  wtepspar    char(34) default ' ' not null,
  lf          char(1)
);
create unique index watespa1 on watespaf
(
wtepurno,
wtepedat
);
create unique index watespa2 on watespaf
(
wtepedat,
wtepurno
);
revoke all on watespaf from public ; 
grant select on watespaf to public ; 
