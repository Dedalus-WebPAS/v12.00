create table patdetaf
(
  ptdetype    varchar2(1) default ' ' not null,
  ptdeinvn    varchar2(8) default ' ' not null,
  ptdeagnt    varchar2(3) default ' ' not null,
  ptdedtcl    varchar2(8) default ' ' not null,
  ptdecdat    varchar2(8) default ' ' not null,
  ptdectim    varchar2(8) default ' ' not null,
  ptdecuid    varchar2(10) default ' ' not null,
  ptdeudat    varchar2(8) default ' ' not null,
  ptdeutim    varchar2(8) default ' ' not null,
  ptdeuuid    varchar2(10) default ' ' not null,
  ptdeurno    varchar2(8) default ' ' not null,
  ptdesyst    varchar2(1) default ' ' not null,
  ptderpay    number(14,2) default 0 not null,
  ptdefreq    varchar2(3) default ' ' not null,
  ptdesdat    varchar2(8) default ' ' not null,
  ptdeedat    varchar2(8) default ' ' not null,
  ptdenofp    number(7,2) default 0 not null,
  ptdedat1    varchar2(8) default ' ' not null,
  ptdedat2    varchar2(8) default ' ' not null,
  ptdetim1    varchar2(8) default ' ' not null,
  ptdetim2    varchar2(8) default ' ' not null,
  ptdecod1    varchar2(3) default ' ' not null,
  ptdecod2    varchar2(3) default ' ' not null,
  ptdetxt1    varchar2(80) default ' ' not null,
  ptdetxt2    varchar2(80) default ' ' not null,
  ptdespar    varchar2(50) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint patdeta1 primary key( 
ptdetype,
ptdeinvn,
ptdesyst)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
create unique index patdeta2 on patdetaf
(
ptdeurno,
ptdetype,
ptdeinvn,
ptdesyst
)
  tablespace pas_indx; 
