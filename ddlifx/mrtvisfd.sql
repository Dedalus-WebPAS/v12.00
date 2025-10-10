create table mrtvisaf
(
  mrvsvsno    char(8) default ' ' not null,
  mrvsmkey    char(10) default ' ' not null,
  mrvsxky1    char(10) default ' ' not null,
  mrvsxky2    char(10) default ' ' not null,
  mrvsxky3    char(10) default ' ' not null,
  mrvsxky4    char(10) default ' ' not null,
  mrvsxky5    char(10) default ' ' not null,
  mrvsspar    char(50) default ' ' not null,
  lf          char(1)
);
create unique index mrtvisa1 on mrtvisaf
(
mrvsvsno
);
create unique index mrtvisa2 on mrtvisaf
(
mrvsmkey,
mrvsvsno
);
revoke all on mrtvisaf from public ; 
grant select on mrtvisaf to public ; 
