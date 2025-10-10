create table pmsfetaf
(
  pmfetype    char(3) default ' ' not null,
  pmfeline    char(3) default ' ' not null,
  pmfetext    char(80) default ' ' not null,
  pmfespar    char(30) default ' ' not null,
  lf          char(1)
);
create unique index pmsfeta1 on pmsfetaf
(
pmfetype,
pmfeline
);
revoke all on pmsfetaf from public ; 
grant select on pmsfetaf to public ; 
