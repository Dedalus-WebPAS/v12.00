-- create table WEBPCLAF
if object_id('WEBPCLAF') is null
create table WEBPCLAF (
 [WBPCPAG] varchar(20) not null,
 [WBPCCLS] varchar(50) not null,
 [WBPCVAL] varchar(500) not null,
 [WBPCCBY] varchar(10) not null,
 [WBPCCDT] varchar(8) not null,
 [WBPCCTM] varchar(5) not null,
 [WBPCUBY] varchar(10) not null,
 [WBPCUDT] varchar(8) not null,
 [WBPCUTM] varchar(5) not null,
 [WBPCSPA] varchar(100) not null,
 [LF] varchar(1) null,
 [ROWID] bigint not null IDENTITY(1,1)
 constraint WEBPCLAF_01 primary key clustered ([WBPCPAG],[WBPCCLS])
 );
if not exists (select * from sys.indexes where object_id=object_id('WEBPCLAF') and name='WEBPCLAF_rx') create unique nonclustered index WEBPCLAF_rx on WEBPCLAF([ROWID]) with(allow_page_locks=off);

-- create timestamp
if not exists (select * from sys.columns where object_id=object_id('WEBPCLAF') and name='ROW_CREATED') alter table WEBPCLAF add[ROW_CREATED] datetime not null default GETUTCDATE(),[ROW_UPDATED] datetime not null default GETUTCDATE();
go

-- create trigger
create or alter trigger WEBPCLAF_ROW_UPDATED_TRIGGER on WEBPCLAF after update as
begin
set nocount on;
update WEBPCLAF set ROW_UPDATED = GETUTCDATE()
where ROWID in (select ROWID from inserted with(NOLOCK));
end;
go

