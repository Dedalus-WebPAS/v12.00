-- create table WEBPJVAF
if object_id('WEBPJVAF') is null
create table WEBPJVAF (
 [WBPJPAG] varchar(20) not null,
 [WBPJCLS] varchar(50) not null,
 [WBPJVAL] varchar(500) not null,
 [WBPJCBY] varchar(10) not null,
 [WBPJCDT] varchar(8) not null,
 [WBPJCTM] varchar(5) not null,
 [WBPJUBY] varchar(10) not null,
 [WBPJUDT] varchar(8) not null,
 [WBPJUTM] varchar(5) not null,
 [WBPJSPA] varchar(100) not null,
 [LF] varchar(1) null,
 [ROWID] bigint not null IDENTITY(1,1)
 constraint WEBPJVAF_01 primary key clustered ([WBPJPAG],[WBPJCLS])
 );
if not exists (select * from sys.indexes where object_id=object_id('WEBPJVAF') and name='WEBPJVAF_rx') create unique nonclustered index WEBPJVAF_rx on WEBPJVAF([ROWID]) with(allow_page_locks=off);

-- create timestamp
if not exists (select * from sys.columns where object_id=object_id('WEBPJVAF') and name='ROW_CREATED') alter table WEBPJVAF add[ROW_CREATED] datetime not null default GETUTCDATE(),[ROW_UPDATED] datetime not null default GETUTCDATE();
go

-- create trigger
create or alter trigger WEBPJVAF_ROW_UPDATED_TRIGGER on WEBPJVAF after update as
begin
set nocount on;
update WEBPJVAF set ROW_UPDATED = GETUTCDATE()
where ROWID in (select ROWID from inserted with(NOLOCK));
end;
go
