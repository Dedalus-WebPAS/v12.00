//jsVersion  : V12.00.00
//-----------------------------------------------------------------------------
var showTableFilterSearch = true;
var showTableFilter = true;
var showTableSearch = true;
var printOrder;
var printFormat=false;
var printWidth = new Array();
var FilterColumn = new Array();
var FilterValue = new Array();
var SearchInputField = null;
var SearchTimeoutId = null;
var SearchColumn = new Array();
var SearchValue = new Array();
var filterToggle=0;
var OrderColumn;
var SearchAllValue="";
var SearchAllFlag=false;
var AscDsc;
var filteredRows=0;
var RemoveHTMLTags = /(<([^>]+)>)/ig;
var emTime1;
var emTime2;
var emTime3;
var emTime4;
var emTime5;
var TableSortOrder="";
var CompatibilityMode = false;  // Browser Compatibility Mode
function Table(Border,Cellspacing,Cellpadding,Width,Align,HHeight,RHeight,immediate,emergency,urgent,semi,non) {
   emTime1=immediate;
   emTime2=emergency;
   emTime3=urgent;
   emTime4=semi;
   emTime5=non;
   this.Border = Border;
   this.Cellspacing = Cellspacing;
   this.Cellpadding = Cellpadding;
   this.Width = Width;
   this.Align = Align;
   this.HeadingHeight = HHeight;
   this.RowHeight = RHeight;
   this.rows = new Array();
   this.addRow = _addTableRow;
   this.AddPatient = _addTableRow;
   this.columns = new Array();
   this.addColumn = _addTableColumn;
   this.sortTable = _sortTable;
   this.tableTotals = new Array();
   this.addTotal = _addTableTotal;
   printWidth = new Array();
   AscDsc=1
}
function _addTableTotal() {
  for (var i = 0; i < arguments.length; i++) 
     this.tableTotals[i] = arguments[i];
}
function _sortTable(Column,AscDsc) {
  SortOrderBy = obj.columns[Column][3]
  if (AscDsc == 1) {
    switch(obj.columns[Column][1]) {
      case "Date"      :  obj.rows.sort(NumericSort); break;
      case "DateTime"  :  obj.rows.sort(StringSort); break;
      case "Time"      :  obj.rows.sort(StringSort); break;
      case "Minutes"   :  obj.rows.sort(StringSort); break;
      case "MinutesDelay"   :  obj.rows.sort(StringSort); break;
      case "Number"    :  obj.rows.sort(NumericSort); break;
      case "Graph"     :  obj.rows.sort(NumericSort); break;
      case "Name"      :  obj.rows.sort(StringSort); break;
      case "Image"     :  obj.rows.sort(StringSort); break;
      case "String"    :  obj.rows.sort(StringSort); break;
      case "ImageText" :  obj.rows.sort(StringSort); break;
      case "ImageOld"  :  obj.rows.sort(StringSort); break;
    }
  }
  else {
    switch(obj.columns[Column][1]) {
      case "Date"      :  obj.rows.sort(RevNumericSort); break;
      case "DateTime"  :  obj.rows.sort(RevStringSort); break;
      case "Time"      :  obj.rows.sort(RevStringSort); break;
      case "Minutes"   :  obj.rows.sort(RevStringSort); break;
      case "MinutesDelay"   :  obj.rows.sort(RevStringSort); break;
      case "Number"    :  obj.rows.sort(RevNumericSort); break;
      case "Graph"     :  obj.rows.sort(RevNumericSort); break;
      case "Name"      :  obj.rows.sort(RevStringSort); break;
      case "Image"     :  obj.rows.sort(RevStringSort); break;
      case "String"    :  obj.rows.sort(RevStringSort); break;
      case "ImageText" :  obj.rows.sort(RevStringSort); break;
      case "ImageOld"  :  obj.rows.sort(RevStringSort); break;
    }
  }
}
function NumericSort(a,b) {
  return a[SortOrderBy] - b[SortOrderBy];
}
function StringSort(a,b) {
  if (a[SortOrderBy] < b[SortOrderBy] ) { x = -1 }
  if (a[SortOrderBy] == b[SortOrderBy] ) { x = 0  }
  if (a[SortOrderBy] > b[SortOrderBy] ) { x = 1  }
  return x ;
}
function RevNumericSort(a,b) {
  return b[SortOrderBy] - a[SortOrderBy];
}
function RevStringSort(a,b) {
  if (a[SortOrderBy] < b[SortOrderBy] ) { x = 1 }
  if (a[SortOrderBy] == b[SortOrderBy] ) { x = 0  }
  if (a[SortOrderBy] > b[SortOrderBy] ) { x = -1  }
  return x ;
}
function _addTableColumn() {
  this.columns[this.columns.length] = new Array();
  var column = this.columns[this.columns.length-1];
  for (var i = 0; i < arguments.length; i++) 
     column[column.length] = arguments[i];
}
function _addTableRow() {
  this.rows[this.rows.length] = new Array();
  var row = this.rows[this.rows.length-1];
  for (var i = 0; i < arguments.length; i++) 
     row[row.length] = arguments[i];
}
function FormatIcon(admissno) {
 if (ImgString != "" ) {
   TableString[TableString.length] = "<img src=../images/" + ImgString ; 
   TableString[TableString.length] = " border=0 hspace=4 align=absmiddle alt=\"" ; 
   TableString[TableString.length] = admissno ;
   TableString[TableString.length] = "\">" ;
   if (LinkFlag ) { 
      LinkFlag = 0;
      TableString[TableString.length] = "</a>" ; }
 }
}
function FormatName(Name) {
 EndLink="";
 if ( LinkFlag ) { EndLink += "</a>"; }
 NameFields=Name.split(",");
 if (NameFields.length > 1) {
   Title=NameFields[2].substr(0,1) + NameFields[2].substr(1,5).toLowerCase()
   Given=NameFields[1]
   GivenFields=Given.split(" ");
   var GivenString = "";
   for (var i = 0; i < GivenFields.length; i++) {
     GivenString+=GivenFields[i].substr(0,1)
     GivenString+=GivenFields[i].substr(1,35).toLowerCase()
     GivenString+=" "
   } 
   TitleGiven=Title + " " + GivenString
   Surname=NameFields[0].toUpperCase()
   return( "<b>" + Surname + "</b>, " + TitleGiven + EndLink ) 
 }
 else {
   Given="";
   Title="";
   Surname=Name;
   Initials="";
   return( "<b>" + Surname + "</b>" + EndLink );
 }
}
function FormatGraph(Value,Image) {
     return("<img src=../images/" + Image + " height=10 " +
             "width=" + Value + " align=absbottom>");
}
function FormatImage(Value) {
     return("<img src=../images/" + Value + " border=0>");
}
function FormatTime(datetime) {
   time = datetime.substr(8,5);
   EndLink="";
   if ( LinkFlag ) { EndLink += "</a>"; }
   if (time.match(/^\s+/)) {
   return( "Invalid" +  EndLink) } 
   else {
   return( time + EndLink) }
}
function FormatMinutes(minValue) {
   hValue = Math.floor(minValue/60);
   if (hValue<10) hValue="0"+hValue;
   mValue = minValue%60;
   if (mValue<10) mValue="0"+mValue;
   hLight="emArrival0";
   if (minValue>120) hLight="emArrival1";
   if (minValue>180) hLight="emArrival2";
   if (minValue>240) hLight="emArrival3";
   if (minValue>720) hLight="emArrival4";
   return("<span class="+hLight+">"+hValue+":"+mValue+"</span>")
}
function FormatMinutesDelay(minValue,delay) {
   hValue = Math.floor(minValue/60);
   if (hValue<10) hValue="0"+hValue;
   mValue = minValue%60;
   if (mValue<10) mValue="0"+mValue;
   hLight="emArrival0";
   if (minValue>120) hLight="emArrival1";
   if (minValue>180) hLight="emArrival2";
   if (minValue>240 && minValue < 720) {
       hLight="emArrival3";
       if(isWhitespace(delay)) {
         hLight+= " emArrivalBorder";
       }
   }
   if (minValue>720){
       hLight="emArrival4";
       if(isWhitespace(delay)) {
         hLight+= " emArrivalBorder";
       }
   }
   return("<span class='"+hLight+"'>"+hValue+":"+mValue+"</span>")
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
   EndLink="";
   if ( LinkFlag ) { EndLink += "</a>"; }
   if (time.match(/^\s+/)) {
   return(dd + " " + mth3 + " " + yyyy + "&nbsp;" + EndLink) } 
   else {
   return(dd + " " + mth3 + " " + yyyy + " at " + time + EndLink) }
}
function FormatDate(date) {
   yyyy = date.substr(0,4)
   mm = date.substr(4,2)
   dd = date.substr(6,2)
   mth3=mm
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
   EndLink="";
   if ( LinkFlag ) { EndLink += "</a>"; }
   return(dd + " " + mth3 + " " + yyyy + EndLink);
}
function TableOutput(OrderColumn,AscDsc) {
  if ((window.navigator.userAgent.indexOf("MSIE 6.0")>=1
      || window.navigator.userAgent.indexOf("MSIE 7.0")>=1)
      && window.navigator.userAgent.indexOf("compatible")<0) {
      showTableFilterSearch=false;
  }
//
  var sAgentString = window.navigator.userAgent;
  if ( (sAgentString.indexOf("MSIE 6.0") >= 1 ||
        sAgentString.indexOf("MSIE 7.0") >= 1)
       && sAgentString.indexOf("compatible") >= 1 )
  {
    CompatibilityMode = true;
  }
//  obj.sortTable(OrderColumn,AscDsc);
  if (TableSortOrder=="") {
    TableSortOrder=TableSortOrder+OrderColumn+","+AscDsc+"|";
  }
  SortSequences=TableSortOrder.split("|");
  for (i=0;i<SortSequences.length;i++) {
    if (!isWhitespace(SortSequences[i])) {
      OrderColumn=SortSequences[i].split(",")[0];
      AscDsc=SortSequences[i].split(",")[1];
      obj.sortTable(OrderColumn,AscDsc);
    }
  }
  if (SortSequences.length>5) {
    TableSortOrder="";
    for (i=0;i<SortSequences.length-5;i++) {
      if (!isWhitespace(SortSequences[i])) {
        OrderColumn=SortSequences[i].split(",")[0];
        AscDsc=SortSequences[i].split(",")[1];
        TableSortOrder=TableSortOrder+OrderColumn+","+AscDsc+"|";
      }
    }
  }
  TableRefresh(OrderColumn);
}
function TableHeading(OrderColumn,AscDsc) {

  printOrder=OrderColumn;
  TableString = [];
  TableString[TableString.length] = '<div id=HeadingDivision>'
  TableString[TableString.length] = "<table style=\"table-layout:\" "+
                 " border=" + obj.Border +
                 " cellspacing=" + obj.Cellspacing +
                 " cellpadding=" +  obj.Cellpadding 
  if (obj.Width!=0) {
         TableString[TableString.length] = " width=" + obj.Width  
  }
  TableString[TableString.length]= " >";
  TableString[TableString.length] = "<tr height=" + obj.HeadingHeight + ">" +
             "<td class=HeadingCell align=left width=20% style='border-right:0px;'>" +
             "Selected : <span id=selectedCount>" + obj.rows.length + "</span></td>" + 
             "<td class=HeadingCell align=center style='border-left:0px;border-right:0px'>" +
             document.title + "</td>" +
             "<td class=HeadingCell align=right width=20% style='border-left:0px;'>"
  if (showTableFilterSearch) {
    if (showTableSearch) {
       TableString[TableString.length] = "<input type=text size=12 id=searchAll class='SearchAllTable' "+
             "onfocus='this.value = this.value;SearchFlag=true;' onblur='SearchFlag=false;' "+
             "onkeyup='onSearchAll(event);' title='Search Table' value='"+SearchAllValue+"' placeholder='Search'>"
    }
    if (showTableFilter) {
       TableString[TableString.length] = "<input type=button class='ButtonIcon FilterPlusIcon' "+
             "onclick='ToggleFilter();' title='Filter Table' value=''>"
    }
    TableString[TableString.length] = "<input type=button class='ButtonIcon PrinterIcon' "+
             "onclick='SortTablePrint();' title='Print Page' value=''>"+
             "</td></tr></table>"
  }
  else {
    TableString[TableString.length] = "<img src='../images/PrinterIcon.gif' class=ListIcon "+
             "onclick='SortTablePrint();' alt='Print Page' align=right>"+
             "</td></tr></table>"
  }

  TableString[TableString.length] = "<table style=\"table-layout:fixed\" border=" + obj.Border +
                 " cellspacing=" + obj.Cellspacing +
                 " cellpadding=" +  obj.Cellpadding +
                 " align=" + obj.Align 
  if (obj.Width!=0) {
         TableString[TableString.length] = " width=" + obj.Width  
  }
  TableString[TableString.length] = " >";
  TableString[TableString.length] = "<tr height=" + obj.HeadingHeight + ">";

  if (printWidth.length==0) {  // Save the widths on the first pass for printing
    for(var i = 0; i < obj.columns.length; i++) {
       printWidth[i]=obj.columns[i][7] }
  }
  if (isFinite(obj.columns[0][7])) {
    TotalWidth=0;
    for(var i = 0; i < obj.columns.length; i++) {
       TotalWidth+=parseInt(obj.columns[i][7],10) }
    for(var i = 0; i < obj.columns.length; i++) {
       obj.columns[i][7]=(Math.round(1000*(parseInt(obj.columns[i][7],10)/TotalWidth))/10)+'%' }
  }

  for (var i = 0; i < obj.columns.length; i++) {
    TableString[TableString.length] = "<td class=HeadingCell align=" + obj.columns[i][4] +
                   " width=" + obj.columns[i][7] + " >" ;
    if (obj.columns[i][3] == -1) {
      if (OrderColumn == i) { TableString[TableString.length] = "<b>" }
      TableString[TableString.length] = obj.columns[i][0] + "</td>"; }
    else {
      TableString[TableString.length] = "<a href='javascript:onClick=TableSort(" + i + ")'>";
      if (OrderColumn == i) { TableString[TableString.length] = "<b>" }
      TableString[TableString.length] = obj.columns[i][0] + "</a></td>"; }
  }
  TableString[TableString.length] = "</tr>";
  TableString[TableString.length] = "</table>";
  TableString[TableString.length] = "</div>";
  TableString[TableString.length] = '<div id=BodyDivision>'
  TableString[TableString.length] = "<table style=\"table-layout:fixed\" border=" + obj.Border +
                " cellspacing=" + obj.Cellspacing +
                " cellpadding=" + obj.Cellpadding +
                " align=" + obj.Align 
  if (obj.Width!=0) {
         TableString[TableString.length] = " width=" + obj.Width  
  }
  TableString[TableString.length] = " >";
}
function TableBody() {
 filteredRows=0;
 RowClass="TableRowEven"
 for (var i = 0; i < obj.rows.length; i++) {
  if (TableFilter(obj.rows[i])){
   filteredRows++;
   if (RowClass=="TableRowEven") { RowClass="TableRowOdd" }
   else                          { RowClass="TableRowEven" }
   TableString[TableString.length] = "<tr class=" + RowClass + ">" ;
   for (var j = 0; j < obj.columns.length; j++) {
     if (CompatibilityMode) {
       TableString[TableString.length] = "<td style='word-wrap:break-word;' align=" + obj.columns[j][4]  ;
     } else {
       TableString[TableString.length] = "<td style='padding:0px 5px; word-wrap:break-word;' align=" +
                                          obj.columns[j][4]  ;
     }
     TableString[TableString.length] = " width=" + obj.columns[j][7];
//
     if(obj.columns[j][11]!=undefined) {
       if(!isWhitespace(obj.rows[i][obj.columns[j][11]])) {
         TableString[TableString.length] = " class=" +
                                           obj.rows[i][obj.columns[j][11]]  ;
       }
     }

//
     TableString[TableString.length] = ">" ;
     LinkColumn = obj.columns[j][6];
     LinkFlag = 0
     ImgString = obj.columns[j][5];
     if (LinkColumn != "") {
       LinkHref = obj.columns[j][6];
       if(LinkHref==7) {     // Same as option 2 if not discharged
         if(trim(obj.rows[i][85])=="1") {
           LinkHref=2;       // Current patient so include link
         } else {
           LinkHref="";      // Remove link as not a current patient
         }
       }
       if (LinkHref != ""){ 
           if(LinkHref=="1") {
             TableString[TableString.length] = "<a href='javascript:SelectPatient(\"" +
                            obj.rows[i][3] + "\",\"" +
                            obj.rows[i][4] +
                            "\");'>" ; }
           else if(LinkHref=="2") { 
             TableString[TableString.length] = "<a href='javascript:OpenLocation(\"" +
                            obj.rows[i][3] + "\",\"" +
                            obj.rows[i][4] +
                            "\");'>" ; }
           else if(LinkHref=="3") {
             TableString[TableString.length] = "<a href='javascript:TriagePatient(\"" +
                            obj.rows[i][3] + "\",\"" +
                            obj.rows[i][4] + "\",\"" +
                            obj.rows[i][5] +
                            "\");'>" ; }
           else if(LinkHref=="4") {
             TableString[TableString.length] = "<a href='javascript:SelectPatient(\"" +
                            obj.rows[i][3] + "\",\"" +
                            obj.rows[i][4] + "\",\"" +
                            obj.rows[i][21] +
                            "\");'>" ; }
           else if(LinkHref=="5") {
             if (!isWhitespace(obj.rows[i][33])){
               TableString[TableString.length] =
               "<a href='javascript:ViewTreatingDoctorFrame(\"" +
                                                obj.rows[i][33] +
                                                       "\");'>" ;
             }
           }
           else if(LinkHref=="6") {
             if (!isWhitespace(obj.rows[i][69])){
               TableString[TableString.length] =
               "<a href='javascript:ViewSeniorDoctorFrame(\"" +
                                                obj.rows[i][69] +
                                                       "\");'>" ;
             }
           }

          LinkFlag = 1 }
     }
     switch(obj.columns[j][1]) {
       case "Date" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatDate(obj.rows[i][obj.columns[j][2]]);
         break;
       case "DateTime" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatDateTime(obj.rows[i][obj.columns[j][2]]);
         break;
       case "Time" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatTime(obj.rows[i][obj.columns[j][2]]);
         break;
       case "Minutes" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatMinutes(obj.rows[i][obj.columns[j][2]]);
         break;
       case "MinutesDelay" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatMinutesDelay(obj.rows[i][obj.columns[j][2]],obj.rows[i][obj.columns[j][8]]);
         break;
       case "Name" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatName(obj.rows[i][obj.columns[j][2]]);
         break;
       case "Graph":  
         TableString[TableString.length] = FormatGraph(obj.rows[i][obj.columns[j][2]],obj.columns[j][5]);
         break;
       case "Image":  
         ClassString = TriageTime(obj.rows[i][obj.columns[j][2]],obj.rows[i][12],obj.rows[i][7],obj.rows[i][25],obj.rows[i][26],obj.rows[i][73]);
         tri=parseInt(obj.rows[i][obj.columns[j][2]]);
         if (tri==0) tri="?";
         oStr="<span class="+ClassString+">"+tri+"</span>"
         TableString[TableString.length] = oStr;
         break;
       case "ImageText":
         if (obj.columns[j][5]=="") {
           ImgString=obj.rows[i][obj.column[j][8]]; 
         }
         else {
           ImgString=obj.columns[j][5] +
                       obj.rows[i][obj.columns[j][8]] + ".gif";
         }
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = (obj.rows[i][obj.columns[j][2]]);
         break; 
       case "ImageOld":
         if (obj.columns[j][5] == "") {
           ImageString=t.rows[i][t.columns[j][2]];
         }
         else {
           ImageString=obj.columns[j][5] + obj.rows[i][obj.columns[j][2]] + ".gif"
         }
         ImageString=ImageString.replace(/ /g,"");
         TableString[TableString.length] = FormatImage(ImageString);
         break;
       default    :   
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = obj.rows[i][obj.columns[j][2]];
         TableString[TableString.length] = "&nbsp;"; 
         if ( LinkFlag ) { TableString[TableString.length] = "</a>"; }
         break;
     }
     obj.rows[i][obj.columns[j][2]] 
     TableString[TableString.length] = "</td>" ;
     }
   TableString[TableString.length] = "</tr>" ;
   }
  }
}
function TableEnding() {
  TableString[TableString.length] = "</table></div>";
  var TableLocation   = document.getElementById('TableLocation'); 
  var HeadingSection  = document.getElementById('HeadingSection');
  TableLocation.innerHTML = "";
  if (TableString.join) {
    TableLocation.innerHTML = TableString.join("");
  } else {
    var TableStringX="";
    for (i=0;i < TableString.length; i++) {
       TableStringX+=TableString[i];
    }
    TableLocation.innerHTML = TableStringX;
  }
  document.getElementById('selectedCount').innerHTML=filteredRows;

  _setListHeight();

  _setVerticalScrollbar();
}
function _setListHeight() {
  var TableLocation = document.getElementById('TableLocation');
  var HeadingDivision = document.getElementById('HeadingDivision');
  var BodyDivision = document.getElementById('BodyDivision');

  var sBorderStyle = TableLocation.style.border;  // save current border style

  // We need to do the following to force Chrome to render; before we can set
  // the height values (for more accuracy)
  TableLocation.style.border = "1px solid transparent";

  var height = document.body.clientHeight;

  var listHeight = height - TableLocation.offsetTop - HeadingDivision.offsetHeight - 1;

  TableLocation.style.border = sBorderStyle;  // restore the border style

  if (listHeight > 0) {
    BodyDivision.style.height = listHeight + "px";
  }
}
function _setVerticalScrollbar() {
  var HeadingDivision = document.getElementById('HeadingDivision');
  var BodyDivision    = document.getElementById('BodyDivision');

  // Show the vertical scrollbar accordingly

  if (window.navigator.userAgent.indexOf("MSIE 9.0")>=1) {
    if (BodyDivision.scrollHeight>document.body.clientHeight) {
      HeadingDivision.style.width=BodyDivision.clientWidth;
    }
  }
  if (BodyDivision.scrollHeight >  BodyDivision.clientHeight) {
    // List overflows (i.e. vertical scrollbar visible)
    HeadingDivision.style.overflowY = 'scroll';  // force vertical scrollbar
                                                 // on list heading section
  }
  else {
    // List does NOT overflow (i.e. no vertical scrollbar in BodyDivision)
    if (window.navigator.userAgent.indexOf("MSIE 7.0") >= 1) {
      // Since IE 8 will always show the vertical scrollbar for the BodyDivision
      // (even when scrolling is not needed) we need to also show the
      // vertical scrollbar for HeadingDivision so columns line up.
      HeadingDivision.style.overflowY = 'scroll';
    }
    else {
      HeadingDivision.style.overflowY = 'hidden';
    }
  }
}
function TableSort(OrderColumn) {
 if ( lastOrderColumn == OrderColumn ) { 
   if (AscDsc==1) {AscDsc=2;} else {AscDsc=1;} }
 else { 
   AscDsc=1; }
 TableSortOrder=TableSortOrder+OrderColumn+","+AscDsc+"|";
 lastOrderColumn=OrderColumn;
 TableOutput(OrderColumn,AscDsc);
}
function TableTotals() {
   TableString[TableString.length] = "<tr class=TableRowTotal>" ;
   for (var j = 0; j < obj.columns.length; j++) {
     TableString[TableString.length] = "<td align=" + obj.columns[j][4]  ;
     TableString[TableString.length] = " width=" + obj.columns[j][7] + "><b>" ;
     LinkColumn = obj.columns[j][6];
     LinkFlag = 0
     ImgString = obj.columns[j][5];
     if (LinkColumn != "") {
       LinkHref = obj.tableTotals[obj.columns[j][6]];
       if (LinkHref != ""){ 
         TableString[TableString.length] = "<a href=" + LinkHref + ">" ; 
         LinkFlag = 1 }
     }
     switch(obj.columns[j][1]) {
       case "Date" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatDate(obj.tableTotals[obj.columns[j][2]]);
         break;
       case "DateTime" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatDateTime(obj.tableTotals[obj.columns[j][2]]);
         break;
       case "Name" :  
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = FormatName(obj.tableTotals[obj.columns[j][2]]);
         break;
       case "Graph":  
         TableString[TableString.length] = FormatGraph(obj.tableTotals[obj.columns[j][2]],obj.columns[j][5]);
         break;
       case "Image":  
         ImageString=obj.tableTotals[obj.columns[j][2]];
         TableString[TableString.length] = FormatImage(ImageString);
         break;
       case "ImageText":
         if (obj.tableTotals[obj.columns[j][5]]=="") {
           ImgString=obj.tableTotals[obj.rows[i][obj.column[j][8]]];
         }
         else {
           ImgString=obj.tableTotals[obj.columns[j][5]] +
                     obj.tableTotals[obj.rows[i][obj.columns[j][8]]] + ".gif";
         }
         if ( LinkFlag ) { TableString[TableString.length] = "</a>"; }
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = (obj.tableTotals[obj.rows[i][obj.columns[j][2]]]);
         break;
       default    :   
         FormatIcon(obj.rows[i][4]);
         TableString[TableString.length] = obj.tableTotals[obj.columns[j][2]];
         if ( LinkFlag == "1" ) { TableString[TableString.length] = "</a>"; }
         break;
     }
     obj.tableTotals[obj.columns[j][2]] 
     TableString[TableString.length] = "</td>" ;
     }
   TableString[TableString.length] = "</tr>" ;
}
function CalcTime(datetime) {
   today = new Date();
   yyyy = datetime.substr(0,4)
   mm = datetime.substr(4,2)
   mm = mm - 1
   dd = datetime.substr(6,2)
   hh = datetime.substr(8,2)
   mi = datetime.substr(11,2)
   ss = datetime.substr(14,2)
   cdate = new Date(yyyy,mm,dd,hh,mi,ss);
   difference = today.getTime() - cdate.getTime();
   difference = Math.floor(difference / (1000 * 60));
   return(difference);
}
//
function TriageTime(triagecode,doctdttm,arrvdttm,status,dest,stopdttm) {
   if (status=="2  ") {
     if (dest=="2") {
       theimage = "AdmitIcon";
     } else {
     theimage = "HomeIcon"; }
     return(theimage);
   }
   tcode= new String(triagecode)
   if ((doctdttm == "                ")||(doctdttm == "")) { 
     if (!isWhitespace(stopdttm)) {
       // Stop clock date & time value exists (first seen date/time by
       // Treating doctor/Initial assessor/Other doctor).
       theimage = "triage" + tcode.substr(0,1);
     }
     else {
       datetime = arrvdttm;
       CalcTime(datetime);
       if ((triagecode == 1) & (difference >= emTime1)) {
         theimage = "triage1f";
       }
       else if ((triagecode == 2) & (difference >= emTime2)) {
         theimage = "triage2f";
       }
       else if ((triagecode == 3) & (difference >= emTime3)) {
         theimage = "triage3f";
       }
       else if ((triagecode == 4) & (difference >= emTime4)) {
         theimage = "triage4f";
       }
       else if ((triagecode == 5) & (difference >= emTime5)) {
         theimage = "triage5f";
       }
       else if (triagecode == 6) {
         theimage = "triage6";
       }
       else {
         theimage = "triage" + tcode.substr(0,1);
       }
     }
   }
   else {
     theimage = "triage" + tcode.substr(0,1);
   }
   return(theimage);
}
//------------------------------------------------------------
// Print Table from Window
//------------------------------------------------------------
function SortTablePrint() {
  if (window.navigator.userAgent.indexOf("MSIE 6.0")>=1
      || window.navigator.userAgent.indexOf("MSIE 7.0")>=1) {
    // Printing on Internet Explorer version 6 and above
///
   if(window.navigator.userAgent.indexOf("compatible")>=1) {
     el = top.document.getElementById("navbar");
     if (el && el.style.display != "none") {
       // new ED map with overlayed DFrames
       print();
       return;
     }
   }
//
//    HeadingSection.style.position="relative"
    HeadingSection.style.visibility="hidden";
    HeadingDivision.style.overflow="hidden"
    BodyDivision.style.overflow="hidden"
    BodyDivision.style.height="auto"
    print()
    HeadingSection.style.visibility="visible";
//    HeadingSection.style.position="absolute"
  }
  else {
    el = top.document.getElementById("navbar");
    if (el && el.style.display != "none") {
      // new ED map with overlayed DFrames
      print();
      return;
    }
    SaveHeight=BodyDivision.style.height;
    BodyDivision.style.height="auto";
    print();
    BodyDivision.style.height=SaveHeight;
  }
}
function TableRefresh() {
  if (obj.rows.length != 0 ) {
    if (filterToggle==0) {
      TableHeading(printOrder,AscDsc);
    }
    else {
      FilterHeading();
    }
    TableBody();
    if (obj.tableTotals.length != 0 ) { TableTotals(); }
    TableEnding(); 
    if (filterToggle==1) { FilterEnding(); }
  }
  else {
    TableHeading(printOrder,AscDsc);
    TableEnding(); 
  }

  if (SearchAllFlag) {
    // set focus on search field
    window.setTimeout(function() {
      el=document.getElementById("searchAll");
      if(el){
        el.focus();
        SetCaretPosition("searchAll", -1); //set cursor at end of input value
      }
    }, 1000);
  }
    FormatTableCells();
}
//------------------------------------------------------------
// Dynamic Table Filter Processing
// Called on each row before output.
// Checks Search Name Filter and Column Select Filters
// colFORMATNM = Column Number in the table to search
//------------------------------------------------------------
function TableFilter(el) { 
  if (!isWhitespace(SearchAllValue)) {
    matchValue=false;
    for(var f = 0; f < el.length; f++) {
      // only try to search data table value if it's NOT a link URL
      if (!el[f].match(/pbl?/ig)) {
        if(el[f].toUpperCase().search(SearchAllValue.toUpperCase())>-1) {
          matchValue=true;
        }
      }
    }
    if (!matchValue) return false;
  }
  for(var f = 0; f < SearchValue.length; f++) {
    if (SearchValue[f]!='') {
      if(el[SearchColumn[f]].toUpperCase().search(SearchValue[f])==-1) {
        return false;
      }
    }
  }
  for(var f = 0; f < FilterValue.length; f++) {
    if (FilterValue[f]!='') {
      if (FilterValue[f]!='null') {
        if (FilterValue[f]!=el[FilterColumn[f]]) {
          return false;
        }
      }
      else {
        if (!isWhitespace(el[FilterColumn[f]])) {
          return false;
        }
      }
    }
  }
  return true;
}
//------------------------------------------------------------
// Dynamic Filter Select List onChange Function Call
// Example:
// In Table Initialisation 
// ShowFilter("unitFilter","32");
// In Page HTML
// <select onchange="FilterList(this,'32');" title="Unit" id="unitFilter">
// <option value=''>All Units</option>
// </select>
//------------------------------------------------------------
function onFilterList(el,ColumnNo) {
  for(var f = 0; f < FilterColumn.length; f++) {
    if (FilterColumn[f]==ColumnNo) {
       FilterValue[f]=el.options[el.selectedIndex].value;
    }
  }
  TableRefresh();
}
function onSearchList(e) {
  var delayTime = 150; //delay 0.15 seconds
  if(!e){e = window.event;}
  if (e.srcElement)
    SearchInputField = e.srcElement;
  else if (e.target)
    SearchInputField = e.target;
  else { return; }
  clearTimeout(SearchTimeoutId);
  if (e.keyCode==9) { return; }
  addSearchFilter(SearchInputField);
  if(e.keyCode== 13 || SearchInputField.value.length == 0 ) {
    SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
    return;
  }
  if(SearchInputField.value.length > 2) {
    if(e.keyCode == 8 || e.keyCode == 46) {
      SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
      return;
    }
    if(e.keyCode < 32 || (e.keyCode >= 33 && e.keyCode <= 47)||(e.keyCode >= 112 && e.keyCode <= 123)) {
      return;
    }
    SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
  }
}
function addSearchFilter(el) {
  ColumnNo=el.getAttribute("SearchColumn")
  if (isWhitespace(ColumnNo)) {
    alert("Search Column Attribute Not Valid.");
    return;
  }
  filterAdd=true;
  for(var f = 0; f < SearchColumn.length; f++) {
    if (SearchColumn[f]==ColumnNo) {
      filterAdd=false;
      SearchValue[f]=el.value.toUpperCase();
    }
  }
  if (filterAdd) {
    SearchColumn[SearchColumn.length]=ColumnNo;
    SearchValue[SearchValue.length]=el.value.toUpperCase();
  }
}
function onStatusFilter(el,ColumnNo,MatchValue) {
  addStatusFilter(el,ColumnNo,MatchValue);
  TableOutput(OrderColumn,AscDsc);
}
function addStatusFilter(el,ColumnNo,MatchValue) {
  filterAdd=true;
  for(var f = 0; f < FilterColumn.length; f++) {
    if (FilterColumn[f]==ColumnNo) {
      filterAdd=false;
      if (el.checked) {
        FilterValue[f]=MatchValue;
      }
      else {
        FilterValue[f]="";
      }
    }
  }
  if (filterAdd) {
    FilterColumn[FilterColumn.length]=ColumnNo;
    FilterValue[FilterValue.length]=MatchValue;
  }
}
function FilterHeading() {
  TableString = [];
  TableString[TableString.length] = '<div id=HeadingDivision>'+
             "<table style=\"table-layout:\"" +
             " border=" + obj.Border +
             " cellspacing=" + obj.Cellspacing +
             " cellpadding=" + obj.Cellpadding +
             " width=" + obj.Width +
             " align=" + obj.Align + " >"+
             "<tr><td class=HeadingCell align=left width=20% style='border-right:0px;'>" +                  
             "Selected : <span id=selectedCount>" + obj.rows.length + "</span></td>" +                       
             "<td class=HeadingCell align=center style='border-left:0px;border-right:0px'>" +
             document.title + "</td>" +
             "<td class=HeadingCell align=right width=20% style='border-left:0px;'>" 
  if (showTableFilterSearch) {
    if (showTableSearch) {
      TableString[TableString.length] = "<input type=text size=12 id=searchAll class='SearchAllTable' "+
             "onfocus='this.value = this.value;SearchFlag=true;' onblur='SearchFlag=false;' "+
             "onkeyup='onSearchAll(event);' title='Search Table' value='"+SearchAllValue+"' placeholder='Search'>"
    }
    if (showTableFilter) {
      TableString[TableString.length] = "<input type=button class='ButtonIcon FilterMinusIcon' "+
             "onclick='ToggleFilter();' title='Sort Table' value=''>"
    }
    TableString[TableString.length] = "<input type=button class='ButtonIcon PrinterIcon' "+
             "onclick='SortTablePrint();' title='Print Page' value=''>"+
             "</td></tr></table>"
  }
  else {
    TableString[TableString.length] = "<img src='../images/PrinterIcon.gif' class=ListIcon "+
             "onclick='SortTablePrint();' alt='Print Page' align=right>"+
             "</td></tr></table>"
  }
  TableString[TableString.length] = "<table style=\"table-layout:fixed\"" +
                " border=" + obj.Border +
                " cellspacing=" + obj.Cellspacing +
                " cellpadding=" + obj.Cellpadding +
                " width=" + obj.Width +
                " align=" + obj.Align + " >"+
                "<tr height=" + obj.HeadingHeight + ">";

  if (printWidth.length==0) {  // Save the widths on the first pass for printing
    for(var i = 0; i < obj.columns.length; i++) {
       printWidth[i]=obj.columns[i][7] }
  }
  if (isFinite(obj.columns[0][7])) {
    TotalWidth=0;
    for(var i = 0; i < obj.columns.length; i++) {
       TotalWidth+=parseInt(obj.columns[i][7],10) }
    for(var i = 0; i < obj.columns.length; i++) {
       obj.columns[i][7]=(Math.round(1000*(parseInt(obj.columns[i][7],10)/TotalWidth))/10)+'%' }
  }

  for(var i = 0; i < obj.columns.length; i++) {
    var selectName=trim(obj.columns[i][0]);
    if (selectName.substr(selectName.length-1,1)!='s') selectName+='s';
    if (printFormat) obj.columns[i][7]=printWidth[i];
    TableString[TableString.length] = "<td class=HeadingCell align=" + obj.columns[i][4] + 
                   " width=" + obj.columns[i][7] + " >" ;
    if (obj.columns[i][3] == -1) {
      if (OrderColumn == i) { TableString[TableString.length] = "<b>" }
      TableString[TableString.length] = obj.columns[i][0] + "</td>"; 
    }
    else {
      TableString[TableString.length] = "<select class=TableFilter id='Filter"+i+
                   "' onchange='onFilterList(this,\"" + obj.columns[i][2] + "\");'>" + 
                   "<option value=''>All "+selectName+"</option></select></td>"
    }
  }
  TableString[TableString.length] = "</tr></table></div><div id=BodyDivision>"+
                 "<table style=\"table-layout:fixed\" border=" + obj.Border +
                 " cellspacing=" + obj.Cellspacing + " cellpadding=" + obj.Cellpadding +
                 " width=" + obj.Width + " align=" + obj.Align + " >";
}
function FilterEnding() {
  for(var i = 0; i < obj.columns.length; i++) {
    if (obj.columns[i][3] != -1) {
     ShowFilter('Filter'+i,obj.columns[i][2]);
    }
  }
}
function ToggleFilter() {
  if (filterToggle==0) { filterToggle=1; }
  else { 
   filterToggle=0; 
   for(var i = 0; i < FilterValue.length; i++) {
     FilterValue[i]='';
   }
  }
  TableRefresh();
}
//------------------------------------------------------------
// Dynamic Filter Select List based on Unique Column Values
//------------------------------------------------------------
function ShowFilter(FilterName,ColumnNo) {
 var FilterList = new Array();
 FilterIndex=FilterColumn.length;
 for(var i = 0; i < FilterColumn.length; i++) {
   if (FilterColumn[i]==ColumnNo) FilterIndex=i;
 }
 FilterColumn[FilterIndex]=ColumnNo;
 if (FilterColumn.length>FilterValue.length) FilterValue[FilterValue.length]='';
 BlankColumns=false;
 for(var i = 0; i < obj.rows.length; i++) {
   if (!isWhitespace(obj.rows[i][ColumnNo].replace(RemoveHTMLTags,"").replace(/&nbsp;/gi,""))) {
     addItem=true;
     for(var j = 0; j < FilterList.length; j++) {
       if (obj.rows[i][ColumnNo]==FilterList[j]) addItem=false;
     }
     if (addItem) FilterList[FilterList.length]=obj.rows[i][ColumnNo];
   }
  else {
    BlankColumns=true;
  }
 }
 FilterList.sort();
 el=document.getElementById(FilterName)
 selectIndex=0;
 columnType="";
 for(var i = 0; i < obj.columns.length; i++) {
   if (obj.columns[i][2]==ColumnNo) columnType=obj.columns[i][1]
 }
 if (el.options.length>1) el.options.length=1;
 for(var j = 0; j < FilterList.length; j++) {
   if (FilterList[j]==FilterValue[FilterIndex]) selectIndex=el.options.length;
   switch(columnType) {
     case "DateTime" :  
       nameVal= FormatDateTime(FilterList[j]);break;
     case "Date":
       nameVal= FormatDate(FilterList[j]);break;
     case "DateTimeImg" :
       nameVal= FormatDateTime(FilterList[j]);break;
     case "Time" :  
       nameVal= FormatTime(FilterList[j]);break;
     default:
       nameVal= FilterList[j].replace(RemoveHTMLTags,"").replace(/&nbsp;/gi,"").replace(/ *$/g,"");
   }
   el.options[el.options.length] = new Option(nameVal,FilterList[j]);
 }
 if (BlankColumns) {
   if (FilterValue[FilterIndex]=="null") selectIndex=el.options.length;
   el.options[el.options.length] = new Option("<blank>","null")
 }
 el.selectedIndex=selectIndex;
}
function onSearchAll(e) {
  var delayTime = 250; //delay 0.15 seconds
  SearchAllFlag=true;
  if(!e){e = window.event;}
  if (e.srcElement)
    SearchInputField = e.srcElement;
  else if (e.target)
    SearchInputField = e.target;
  else { return; }
  clearTimeout(SearchTimeoutId);
  if (e.keyCode==9) { return; }
  SearchAllValue=SearchInputField.value;
  if(e.keyCode== 13 || SearchInputField.value.length == 0 ) {
    SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
    return;
  }
  if(SearchInputField.value.length > 2) {
    if(e.keyCode == 8 || e.keyCode == 46) {
      SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
      return;
    }
    if(e.keyCode < 32 || (e.keyCode >= 33 && e.keyCode <= 47)||(e.keyCode >= 112 && e.keyCode <= 123)) {
      return;
    }
    SearchTimeoutId = setTimeout( function() { TableRefresh(); },delayTime);
  }
}
function ViewTreatingDoctorFrame(doctor) {
  DoctorViewFrame(doctor);
}
function ViewSeniorDoctorFrame(doctor) {
  DoctorViewFrame(doctor);
}
function FormatTableCells() {
  if(!IEBrowser) {
    var triage0Cells = document.querySelectorAll("span.triage0");
    for(var i=0, len=triage0Cells.length; i<len; i++) {
      triage0Cells[i].parentNode.style.backgroundColor="purple";
    }
    var triage1Cells = document.querySelectorAll("span.triage1");
    for(var i=0, len=triage1Cells.length; i<len; i++) {
      triage1Cells[i].parentNode.style.background="url('../images/new-triage1.gif')";
    }
    var triage2Cells = document.querySelectorAll("span.triage2");
    for(var i=0, len=triage2Cells.length; i<len; i++) {
      triage2Cells[i].parentNode.style.background="url('../images/new-triage2.gif')";
    }
    var triage3Cells = document.querySelectorAll("span.triage3");
    for(var i=0, len=triage3Cells.length; i<len; i++) {
      triage3Cells[i].parentNode.style.background="url('../images/new-triage3.gif')";
    }
    var triage4Cells = document.querySelectorAll("span.triage4");
    for(var i=0, len=triage4Cells.length; i<len; i++) {
      triage4Cells[i].parentNode.style.background="url('../images/new-triage4.gif')";
    }
    var triage5Cells = document.querySelectorAll("span.triage5");
    for(var i=0, len=triage5Cells.length; i<len; i++) {
      triage5Cells[i].parentNode.style.background="url('../images/new-triage5.gif')";
    }
    var triage1fCells = document.querySelectorAll("span.triage1f");
    for(var i=0, len=triage1fCells.length; i<len; i++) {
      triage1fCells[i].parentNode.style.background="url('../images/new-triage1f.gif')";
    }
    var triage2fCells = document.querySelectorAll("span.triage2f");
    for(var i=0, len=triage2fCells.length; i<len; i++) {
      triage2fCells[i].parentNode.style.background="url('../images/new-triage2f.gif')";
    }
    var triage3fCells = document.querySelectorAll("span.triage3f");
    for(var i=0, len=triage3fCells.length; i<len; i++) {
      triage3fCells[i].parentNode.style.background="url('../images/new-triage3f.gif')";
    }
    var triage4fCells = document.querySelectorAll("span.triage4f");
    for(var i=0, len=triage4fCells.length; i<len; i++) {
      triage4fCells[i].parentNode.style.background="url('../images/new-triage4f.gif')";
    }
    var triage5fCells = document.querySelectorAll("span.triage5f");
    for(var i=0, len=triage5fCells.length; i<len; i++) {
      triage5fCells[i].parentNode.style.background="url('../images/new-triage5f.gif')";
    }
    var emArrival1Cells = document.querySelectorAll("span.emArrival1");
    for(var i=0, len=emArrival1Cells.length; i<len; i++) {
      emArrival1Cells[i].parentNode.style.backgroundColor="green";
    }
    var emArrival2Cells = document.querySelectorAll("span.emArrival2");
    for(var i=0, len=emArrival2Cells.length; i<len; i++) {
      emArrival2Cells[i].parentNode.style.backgroundColor="orange";
    }
    var emArrival3Cells = document.querySelectorAll("span.emArrival3");
    for(var i=0, len=emArrival3Cells.length; i<len; i++) {
      emArrival3Cells[i].parentNode.style.backgroundColor="red";
    }
    var emArrival4Cells = document.querySelectorAll("span.emArrival4");
    for(var i=0, len=emArrival4Cells.length; i<len; i++) {
      emArrival4Cells[i].parentNode.style.backgroundColor="purple";
    }
  }
}
