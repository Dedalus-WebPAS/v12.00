create table patechaf
(
  ptecctyp    char(3) default ' ' not null,
  ptecatyp    char(3) default ' ' not null,
  ptecmbsc    char(9) default ' ' not null,
  dptecuni    char(3) default ' ' not null,
  ptecemch    char(9) default ' ' not null,
  ptecoppc    char(3) default ' ' not null,
  ptec1mcf    decimal(5,2) default 0 not null,
  ptec2mcf    decimal(5,2) default 0 not null,
  ptec3mcf    decimal(5,2) default 0 not null,
  ptechfnd    char(6) default ' ' not null,
  ptechgrp    char(6) default ' ' not null,
  ptecqnty    char(3) default ' ' not null,
  ptecspar    char(42) default ' ' not null,
  lf          char(1)
);
create unique index patecha1 on patechaf
(
ptecctyp,
ptecatyp,
ptechfnd,
ptechgrp,
ptecmbsc,
dptecuni
);
create unique index patecha2 on patechaf
(
ptecmbsc,
ptecctyp,
ptecatyp,
ptechfnd,
ptechgrp,
dptecuni
);
revoke all on patechaf from public ; 
grant select on patechaf to public ; 
