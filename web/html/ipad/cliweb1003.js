//jsVersion  : V12.00.00
//
// Source Code:  ./ipad/cliweb1003.js
//
// Modification
//
// Version   Date          Responsible/Changes Made
//------------------------------------------------------------------------------
// V10.04.01 05.06.2014 B.G.Ackland   CAR 299627
//                      PDF Attachment Review
// V10.03.03 18.12.2013 B.G.Ackland   CAR 295133
//                      Improved Comment Display
// V10.03.02 06.08.2013 B.G.Ackland   CAR 289383
//                      Fixed to use createHttpObject() in place of XMLHttpRequest()
// V10.01.01 04.12.2012 B.G.Ackland New Medical Record View Refresh
// V10.01.00 13/04/2012 Version change
// V10.00.00 13/04/2012 Created for Mobility Suite
//
//----------------------------------------------------------------------
// Javascript    : PathologyAnalysis.js
// Usage         : iPad Cumulative Patholgy Results
// Written       : 15.03.2010 B.G.Ackland
//
// Modifications : 
//----------------------------------------------------------------------
//   V10.00.01 15.03.2010 B.G.Ackland
//             iPad Implementation with Sort on Dates
//
//----------------------------------------------------------------------
var GraphLayout=0;
var AnalyteA=0;
var AnalyteB=1;
function TableOutput(OrderAscDsc) {
   TableHeading(OrderAscDsc);
   TableBody(OrderAscDsc);
   TableEnding();
}
function Table(Border,Cellspacing,Cellpadding,Width,Align) {
   this.Border = Border;
   this.Cellspacing = Cellspacing;
   this.Cellpadding = Cellpadding;
   this.Width = Width;
   this.Align = Align;
   this.ResultCommentIndex = new Array();
   this.ResultCommentText = new Array();
   this.ResultDate = new Array();
   this.ResultAnalyte = new Array();
   this.ResultUnit = new Array();
   this.ResultDesc = new Array();
   this.ResultLink = new Array();
   this.ResultRefRan = new Array();
   this.ResultRows = new Array();
   this.ResultColor = new Array();
   this.rows = new Array();
   this.dataset = new Array();
   this.dataname = new Array();
   this.graphon = new Array();
   this.addRow = _addTableRow;
   this.columns = new Array();
   this.addColumn = _addTableColumn;
}
function _addTableColumn() {
  this.columns[this.columns.length] = new Array();
  var column = this.columns[this.columns.length-1];
  for(var i = 0; i < arguments.length; i++) 
     column[column.length] = arguments[i];
}
function _addTableRow() {
  this.rows[this.rows.length] = new Array();
  var row = this.rows[this.rows.length-1];
  for(var i = 0; i < arguments.length; i++) {
     row[row.length] = arguments[i];
  }
  if (row[0].match(/comment/i)||row[7].match(/comment/i)) {
    IndexValue =row[7]+' '+FormatDateTime(row[1]).replace(/<br>/i,'')
    MatchResult=0;
    for(var i = 0; i < this.ResultCommentIndex.length; i++) {
      if ( IndexValue == this.ResultCommentIndex[i] ) {
        MatchResult=1;
        this.ResultCommentText[i]+=" "+row[2]
      } 
    }
    if (MatchResult==0) {
      this.ResultCommentIndex[i]=IndexValue;
      this.ResultCommentText[i]=row[2];
    }
  } else {
    MatchResult=0
    for(var i = 0; i < this.ResultDate.length; i++) {
       if ( row[1] == this.ResultDate[i] ) {
         MatchResult=1
         DateIndex=i 
       } 
    }
    if (MatchResult==0) {
      this.ResultDate[this.ResultDate.length] = row[1] 
      DateIndex=this.ResultDate.length-1 
    }
    MatchResult=0
    for(var i = 0; i < this.ResultAnalyte.length; i++) {
       if ( row[0] == this.ResultAnalyte[i] ) {
         MatchResult=1
         AnalyteIndex=i 
       } 
    }
    if (MatchResult==0) {
      this.ResultAnalyte[this.ResultAnalyte.length] = row[0] 
      AnalyteIndex=this.ResultAnalyte.length-1 
    }
    this.ResultLink[DateIndex]=row[5]
    this.ResultRefRan[AnalyteIndex]=row[3].replace("\^  "," - ");
    this.ResultUnit[AnalyteIndex]=row[4]
    var index = row[4].indexOf('^');
    if(index != -1) {
      row[4]= row[4].substring(0,index);
    }
    if (isWhitespace(row[4])) {
      this.ResultUnit[AnalyteIndex]="&nbsp;"
    } else {
      this.ResultUnit[AnalyteIndex]=row[4]
    }
    this.ResultDesc[AnalyteIndex]=row[7]
    if ( AnalyteIndex >= this.ResultRows.length ) {
      this.ResultRows[AnalyteIndex] = new Array()
      this.ResultColor[AnalyteIndex] = new Array()
    }
    if (this.ResultRows[AnalyteIndex][DateIndex]==undefined) {
      this.ResultRows[AnalyteIndex][DateIndex]=row[2] 
    } else {
      this.ResultRows[AnalyteIndex][DateIndex]+= "|" + row[2] 
    }
    this.ResultColor[AnalyteIndex][DateIndex]=row[6]
  }
}
//------------------------------------------------------------
// Show Result Details
//------------------------------------------------------------
function ShowResult(ResultKey) {
   var url = "cliweb10.pbl?reportno=01&"+
              "template=022&resultky="+ResultKey.replace(/ /g,"+");
   openDocument(CGIPath+url,"Clinical Results");
   document.ResultLink.resultky.value=ResultKey;
}
//------------------------------------------------------------
// New Output Table Body
//------------------------------------------------------------
function TableBody(OrderAscDsc) {
 for(var i = 0; i < Results.ResultRows.length; i++) {
   RowClass="TableRowEven"
   if (i%2==1) { RowClass="TableRowOdd" }
      TableString[TableString.length] = "<tr class=" + RowClass + 
		" onclick='javascript:openResultChart(\""+i+"\",\""+Results.ResultLink[Results.ResultLink.length - 1]+"\");'><td>" +
                  Results.ResultDesc[i] + "</td>";

   if (OrderAscDsc==0) {
      for(var j=0; j < Results.ResultDate.length; j++) { OutputCell(i,j) }}
   else {
      for(var j=Results.ResultDate.length-1; j>=0; j--) { OutputCell(i,j) }}

   TableString[TableString.length] = "<td>" + Results.ResultUnit[i] + "</td>"
   TableString[TableString.length] = "<td class=ResultRef>" + Results.ResultRefRan[i] + "</td></tr>"
  }
  for(var i = 0; i < Results.ResultCommentIndex.length; i++) {
    RowClass="TableRowEven"
    if (i%2==1) { RowClass="TableRowOdd" }
    TableString[TableString.length] = "<tr style='height:auto;' class=" + RowClass + ">"+
                 "<td colspan="+(Results.ResultDate.length+3)+" style='padding:10px;'>" + 
                  Results.ResultCommentIndex[i] + "<br>"+
                  Results.ResultCommentText[i] + "</td></tr>";
  }
}
function OutputCell(i,j) {
 if (isWhitespace(Results.ResultColor[i][j])) {
    TableString[TableString.length] = "<td style='text-align:right'>" }
 else {
    TableString[TableString.length] = "<td style='text-align:right;background-color:#" +
    Results.ResultColor[i][j] + "'>" }
 if (isWhitespace(Results.ResultRows[i][j])) {
    TableString[TableString.length] = "&nbsp;</td>" }
 else {
    TableString[TableString.length] = Results.ResultRows[i][j] + "</td>" } 
}
function FormatDateTime(datetime) {
   yyyy = datetime.substr(0,4);
   mm = datetime.substr(4,2);
   dd = datetime.substr(6,2);
   time = datetime.substr(8,5);
   mth3=mm;
   switch(mm) {
     case "01": mth3="Jan"; break;
     case "02": mth3="Feb"; break;
     case "03": mth3="Mar"; break;
     case "04": mth3="Apr"; break;
     case "05": mth3="May"; break;
     case "06": mth3="Jun"; break;
     case "07": mth3="Jul"; break;
     case "08": mth3="Aug"; break;
     case "09": mth3="Sep"; break;
     case "10": mth3="Oct"; break;
     case "11": mth3="Nov"; break;
     case "12": mth3="Dec"; break;
   }
   return(dd + " " + mth3 + " " + yyyy + " <br> " + time );
}
//------------------------------------------------------------
// Output Table Heading
//------------------------------------------------------------
function TableHeading(OrderAscDsc) {
  TableString = [];
  ToggleSort="0";
  if (OrderAscDsc==0) ToggleSort="1";
  TableString[TableString.length] = "<table class=CumulativeResults>"
   TableString[TableString.length] = "<tr><td class=HeadingCell "+
                                     " onclick=TableOutput('"+ToggleSort+"');>" +
                                     "Date<br>Time</td>"
   if (OrderAscDsc==0) {
      for(var i=0; i < Results.ResultDate.length; i++) { OutputDateCell(i) }}
   else {
      for(var i=Results.ResultDate.length-1; i >= 0; i--) { OutputDateCell(i) }}
   TableString[TableString.length] = "<td class=HeadingCell>Units</td>"
   TableString[TableString.length] = "<td class=HeadingCell align=center>Ref.Range</td></tr>"
}
//------------------------------------------------------------
// Output Heading Date Cells
//------------------------------------------------------------
function OutputDateCell(i) {
     TableString[TableString.length] = "<td align=right class=HeadingCell>" + 
                    "<a href='javascript:ShowResult(\"" + 
                    Results.ResultLink[i] + "\")'>" +
                     FormatDateTime(Results.ResultDate[i]) + "</a></td>" 
}
//------------------------------------------------------------
// Output Table Ending and Update Table Location
//------------------------------------------------------------
function TableEnding() 
{
  var TableLoaction = document.getElementById('TableLocation');
  TableString[TableString.length] = "</table>";

  if (TableString.join)
    TableLocation.innerHTML = TableString.join("");
  else 
  {
    var TableStringX="";
    for (vari=0; i < TableString.length; i++) TableStringX+=TableString[i];
    TableLocation.innerHTML = TableStringX;
  }
}
function MarkResult() {
  var xmlHttp = createHttpObject();
  var theURL   = "cliweb10.pbl"
  parameters  ="reportno="+encodeURIComponent(document.MarkSeen.reportno.value)
  parameters+="&template="+encodeURIComponent(document.MarkSeen.template.value)
  parameters+="&markalll="+encodeURIComponent(document.MarkSeen.markalll.value)
  parameters+="&auditkey="+encodeURIComponent(document.MarkSeen.auditkey.value)
  xmlHttp.open("POST", theURL, false);
  xmlHttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
  xmlHttp.send(parameters);
  resultText=xmlHttp.responseText
  if (resultText.match(/Invalid/i)) {
    alertify.alert(resultText.replace(/.*alert\(\"/i,"").replace(/\".*/,""));
  }
  else {
    parent.frames['PatFrame'].refreshScreen();
    parent.CloseDocument();
  }
}
function init() {
  var docSection=document.getElementById("DocumentSection");
  var docTable=document.getElementById("DocumentTable");
  var docRegex= new RegExp("(.+OpenDocument..)(.+)(..;.+)","g");
  if (typeof docTable.rows[1] == "undefined") {
    docSection.style.display="none";
  } else {
    if (typeof docTable.rows[1].cells[0] != "undefined") {
      ImageLinkURL=docTable.rows[1].cells[0].innerHTML.replace(docRegex,"$2");
      if (resultOpenDocument) {
        OpenDocument(ImageLinkURL);
      }
    }
  }
  InitTable();
  var actionBtn = parent.document.getElementById('actionButton');
  if(actionBtn) {
    actionBtn.className = actionBtn.className.replace(/SpanButton/g,"");
    actionBtn.className = actionBtn.className.replace(/Blue/g,"");
    actionBtn.className = actionBtn.className + " SpanButtonBlue";
    actionBtn.innerText = "Mark as Read";
    actionBtn.onclick = function() {
       MarkResult();
    }
  }
}
function OpenDocument(theURL) {
  imageDiv=document.getElementById("imgDiv")
  imgFrame=document.getElementById("imgFrame")
  imgFrame.style.backgroundColor="white";
  imgFrame.style.height="1024px";
  imgFrame.style.width="100%";
  imgFrame.src=theURL;
  allowZoom();
  imageDiv.style.display='block';
  imageDiv.style.width='100%';
  imageDiv.style.position='absolute';
  imageDiv.style.top='0px';
  imageDiv.style.left='0px';
}
