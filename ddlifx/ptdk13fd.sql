create table patdk13f
(
  ptcditm     char(9) default ' ' not null,
  ptcdkwd     char(15) default ' ' not null,
  ptcdspa     char(10) default ' ' not null,
  lf          char(1)
);
create unique index ptdk13a1 on patdk13f
(
ptcditm,
ptcdkwd
);
create unique index ptdk13a2 on patdk13f
(
ptcdkwd,
ptcditm
);
revoke all on patdk13f from public ; 
grant select on patdk13f to public ; 
