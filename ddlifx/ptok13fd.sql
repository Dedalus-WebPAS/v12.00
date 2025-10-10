create table patok13f
(
  ptcoitm     char(9) default ' ' not null,
  ptcokwd     char(15) default ' ' not null,
  ptcospa     char(10) default ' ' not null,
  lf          char(1)
);
create unique index ptok13a1 on patok13f
(
ptcoitm,
ptcokwd
);
create unique index ptok13a2 on patok13f
(
ptcokwd,
ptcoitm
);
revoke all on patok13f from public ; 
grant select on patok13f to public ; 
