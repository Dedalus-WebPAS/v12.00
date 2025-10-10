create table patechaf
(
  ptecctyp    varchar2(3) default ' ' not null,
  ptecatyp    varchar2(3) default ' ' not null,
  ptecmbsc    varchar2(9) default ' ' not null,
  dptecuni    varchar2(3) default ' ' not null,
  ptecemch    varchar2(9) default ' ' not null,
  ptecoppc    varchar2(3) default ' ' not null,
  ptec1mcf    number(5,2) default 0 not null,
  ptec2mcf    number(5,2) default 0 not null,
  ptec3mcf    number(5,2) default 0 not null,
  ptechfnd    varchar2(6) default ' ' not null,
  ptechgrp    varchar2(6) default ' ' not null,
  ptecqnty    varchar2(3) default ' ' not null,
  ptecspar    varchar2(42) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint patecha1 primary key( 
ptecctyp,
ptecatyp,
ptechfnd,
ptechgrp,
ptecmbsc,
dptecuni)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index patecha2 on patechaf
(
ptecmbsc,
ptecctyp,
ptecatyp,
ptechfnd,
ptechgrp,
dptecuni
)
  tablespace pas_indx; 
