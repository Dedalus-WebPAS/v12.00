//jsVersion  : V12.00.00
//========================================================================
// Program   : patweb7809006.js
// Function  : Functions Used in patweb7809006.html
//========================================================================
function InitTable(TableView) {
switch (TableView) {
case 0: {
 t = new Table(1,0,2,"100%","center",35,40);

  t.addColumn("Request Date & Time","DateTime",2,2,"left","DocumentIcon.gif",
              "0",50)
  t.addColumn("Eligibility Number","String",3,3,"left","","",50)
  t.addColumn("Patient Name","String",4,4,"left","","",50)
  t.addColumn("Admission Date","DateTime",5,5,"left","","",45)
  t.addColumn("Claim Type","String",6,6,"left","","",45)
  t.addColumn("Health Fund","String",7,7,"left","","",45)
  t.addColumn("Health Fund Table","String",8,8,"left","","",45)
  t.addColumn("Status","String",9,9,"left","","",45)
  t.addColumn("Delete","String",10,10,"left","","",45)
  t.addColumn("Transaction Id","String",11,11,"left","","",45)
  t.addColumn("Error Description","String",12,12,"left","","",45)
  AddTableRows();
   TableOutput(1,0); 
 }
 break; }
}

