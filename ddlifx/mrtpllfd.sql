create table mrtpllaf
(
  mrplvisn    char(8) default ' ' not null,
  mrplmrky    char(10) default ' ' not null,
  mrplrqst    char(2) default ' ' not null,
  mrplcuid    char(10) default ' ' not null,
  mrplcdat    char(8) default ' ' not null,
  mrplctim    char(8) default ' ' not null,
  mrpluuid    char(10) default ' ' not null,
  mrpludat    char(8) default ' ' not null,
  mrplutim    char(8) default ' ' not null,
  mrpludf1    char(10) default ' ' not null,
  mrpludf2    char(10) default ' ' not null,
  mrpludc1    char(3) default ' ' not null,
  mrpludc2    char(3) default ' ' not null,
  mrplftx1    char(80) default ' ' not null,
  mrplftx2    char(80) default ' ' not null,
  mrplspar    char(50) default ' ' not null,
  lf          char(1)
);
create unique index mrtplla1 on mrtpllaf
(
mrplvisn,
mrplmrky,
mrplrqst
);
revoke all on mrtpllaf from public ; 
grant select on mrtpllaf to public ; 
