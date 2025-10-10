//jsVersion  : V12.00.00
//========================================================================
// Program   : outweb0602001.js
//
// Function  : Standard Functions Used in outweb0602001 templates
//
// Version   : 
//
//========================================================================
OutputArray = new Array();  // Create Array to Store Rows of Table
OldArray = new Array();  // Create Array to Store Rows of Table
var MKey="";

function createOutputArray(ReturnCode) {
    AddOutputArray(ReturnCode.value,ReturnCode.id.substring(0,8))
}

function updateOutputArray(ReturnCode) {

  for (var i=0;i<Results.childNodes.length;i++) {
    if(ReturnCode.value == Results.childNodes[i].value){
      Results.childNodes[i].name = ReturnCode.id.substring(0,8);
    }
  }
}

function OutputTable(ReturnCode) {
  var MKey="";
  var Flag=0;
  AddOutputArray(ReturnCode)
}
function AddOutputArray(MKey,id) {
  OutputArray[OutputArray.length] = "<input type=hidden name=" + id +
                                    " value='" + MKey + "'>"
}
function OutputDivision() {
    OutputString=""
    for (i=OutputArray.length-1;i>=0;i--) {
      OutputString+=OutputArray[i] }
    Results.innerHTML=OutputString
}

function defaultCheck(currId,checked) {

  var num = currId.substring(8,12);
  var mrkeplst = document.getElementById('mrkeplst'+num)

  if (!checked) {
    mrkeplst.checked = true;
    RemoveTable(mrkeplst); 
  }
}

function removeChecks(currId,checked) {

  var num = currId.substring(8,12);
  var mrrmvlst = document.getElementById('mrrmvlst'+num)
  var mrkeplst = document.getElementById('mrkeplst'+num)
  var mrreckey = document.getElementById('mrreckey'+num)

  if (checked == true) {
    if(currId.substring(0,8)=="mrrmvlst"){
      mrkeplst.checked = false;
      mrreckey.checked = false;
    } else if (currId.substring(0,8)=="mrkeplst") {
      mrrmvlst.checked = false;
      mrreckey.checked = false;
    } else {
      mrrmvlst.checked = false;
      mrkeplst.checked = false;
    }
  }
}

function RemoveTable(ReturnCode) {

  updateOutputArray(ReturnCode);
  removeChecks(ReturnCode.id,ReturnCode.checked);

/*
  var code = ReturnCode.value;
  var MKey="";
  var Flag=0;
  removeChecks(ReturnCode.id,ReturnCode.checked);
  OldArray=OutputArray
  OutputArray = new Array();  // Create Array to Store Rows of Table
  j=0;
  for (i=0;i<OldArray.length;i++) {
    x = code.substring(0,20)
    y = OldArray[i].substring(40,60)
    if ((x!=y)||(ReturnCode.checked == true)) {
      OutputArray[j]=OldArray[i]
      j++ }
    else {
      Flag="1" }
  }
  if (Flag == "1") {
    OutputDivision() }
  else {
    AddOutputArray(code,ReturnCode.id.substring(0,8))
    OutputDivision() }
  defaultCheck(ReturnCode.id,ReturnCode.checked);
*/
}

function ValidateMRTS() {
  var serverURL = "../cgi-bin/mrtweb04.pbl?reportno=6" +
                  "&valdmrts=" + SelectPeriod.mrtsecno.value.replace(/ /g,"+")

  var returnValue = RSExecute(serverURL);

  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|");
    SelectPeriod.mrtsecid.value=ReturnValue[0];
    return true;
  } else {
    SelectPeriod.mrtsecno.select();
    return false }
}

function moveRecords() {
  if (validateMandatory(SelectPeriod)) {

    if (SelectPeriod.mrtsecno!=undefined) {
      ans=ValidateMRTS();
      if (ans==false) { return; }
    }

    if (isWhitespace(Results.innerHTML)) { 
       alert("No Records Selected");  
       return }
    linkURL="outweb06.pbl?reportno=2&template=002";
    Left=(document.body.clientWidth-500)/2
    DFrameLink(linkURL,100,Left,500,300);
//  document.SelectPeriod.updatety.value="A";
//  document.SelectPeriod.target="PopUpFrame"
//  document.SelectPeriod.submit();
  }
}
function ViewMicroFilm(microflm) {
  linkURL="outweb06.pbl?reportno=2&template=003" +
          "&microflm=" + microflm 
  Left=(document.body.clientWidth-300)/2
  DFrameLink(linkURL,100,Left,300,100);
}
function LimitReached() {
 alert("Limit Reached")
}
// ------------------------------------------------------------
// Columns Available
//  0 - HTML Link    
//  1 - UR No  
//  2 - Visit No
//  3 - Patient's Name          
//  4 - App Time           
//  5 - Admitting Point
//  6 - Current Location
//  7 - Type of document
//  8 - Filled Status
// ------------------------------------------------------------
function InitTable(TableView) {
OutputDivision()
switch (TableView) {
case 0: {
 t = new Table(1,0,1,"100%","center");
 t.addColumn("UR No.","String",1,1,"left","","",50)
 t.addColumn("Visit No.","String",2,2,"left","","",50)
 t.addColumn("Patient's Name","String",3,3,"left","","",140)
 t.addColumn("Adm.Book Time","String",4,4,"left","","",100)
 t.addColumn("Admitting Point","String",5,5,"left","","",60)
 t.addColumn("Current Location","String",6,6,"left","","",140)
 t.addColumn("Document Type","String",7,7,"left","","",60)
 t.addColumn("Filled","String",8,8,"center","","",40)
 AddTableRows()
 TableOutput(0,1);    // Order Column,Asc Dsc
 break;
 }
 }
}
function PrintLabels() {
 Left=(document.body.clientWidth-300)/2
 linkurl="mrtweb01.pbl?reportno=15&template=002"
 DFrameLink(linkurl,50,Left,300,130)
}

//Includes reports for admitted patients
function updateInclAdmis(element) {

  if (element.checked) {
    document.getElementById('incladms').value = 1;
  } else {
    document.getElementById('incladms').value = 0;
  }
  document.SelectPeriod.submit();

}

