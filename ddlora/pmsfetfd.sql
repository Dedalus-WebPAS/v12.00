create table pmsfetaf
(
  pmfetype    varchar2(3) default ' ' not null,
  pmfeline    varchar2(3) default ' ' not null,
  pmfetext    varchar2(80) default ' ' not null,
  pmfespar    varchar2(30) default ' ' not null,
  lf          varchar2(1) default ' ' not null,
constraint pmsfeta1 primary key( 
pmfetype,
pmfeline)
)
tablespace pas_data 
enable primary key using index 
  tablespace pas_indx; 
