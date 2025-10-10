create table resflnaf
(
  refllty varchar2(2) default ' ' not null,
  refllky varchar2(10) default ' ' not null,
  refllab varchar2(3) default ' ' not null,
  reflucs varchar2(12) default ' ' not null,
  reflusc varchar2(12) default ' ' not null,
  reflvst varchar2(100) default ' ' not null,
  refldss varchar2(10) default ' ' not null,
  reflcnt varchar2(10) default ' ' not null,
  reflspa varchar2(50) default ' ' not null,
  lf      varchar2(1) default ' ' not null
)
  tablespace pas_data;

create unique index resflna1 on resflnaf 
(
refllty,
refllky,
refllab,
reflucs,
reflusc,
reflvst,
refldss
) 
  tablespace pas_indx;

create unique index resflna2 on resflnaf
(
refllty,
refllky,
reflcnt,
refllab,
reflucs,
reflusc,
reflvst,
refldss
)
  tablespace pas_indx;

create unique index resflna3 on resflnaf
(
refllty,
refllky,
refllab,
reflcnt,
reflucs,
reflusc,
reflvst,
refldss
)
  tablespace pas_indx;

