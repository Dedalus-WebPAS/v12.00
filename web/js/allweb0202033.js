//jsVersion  : V12.00.00
//------------------------------------------------------------
var clientOffsetTime;
var defaultProgressNoteType ="001";

function init() {

  wurl="allweb02.pbl?reportno=2&template=034"+
       "&urnumber=" + document.PatientLinks.urnumber.value.replace(/ /g,"+");
  var h = document.getElementsByTagName("head")[0];
  var s = document.createElement("script");
  var xmlHttp = createHttpObject();
  xmlHttp.open("GET", wurl, false);
  xmlHttp.send();
  if (xmlHttp.responseText!=""&&xmlHttp.status == 200) {
    s.type="text/javascript";
    h.appendChild(s);
    s.text=xmlHttp.responseText;
    ReferralInitTable();
  }
  else {
    alert("Referral Web Service Not available cliweb06.pbl");
  }
}
function ViewAll() {
  wurl="cliweb06.pbl?reportno=1&template=16"+
       "&urnumber=" + document.PatientLinks.urnumber.value.replace(/ /g,"+") +
       "&admissno=" + document.PatientLinks.admissno.value.replace(/ /g,"+") +
       "&httprand=" + Math.random();
  var h = document.getElementsByTagName("head")[0];
  var s = document.createElement("script");
  var xmlHttp = createHttpObject();
  xmlHttp.open("GET", wurl, false);
  xmlHttp.send();
  if (xmlHttp.responseText!=""&&xmlHttp.status == 200) {
    s.type="text/javascript";
    h.appendChild(s);
    s.text=xmlHttp.responseText;
    ReferralInitTable();
  }
  else {
    alert("Notes Web Service Not available cliweb06.pbl");
  }
}
function ReferralInitTable() {
 t = new Table();
 AddReferralRows();
 SortOrderBy=0;
 t.rows.sort(RevStringSort);
 OS= "<ul class=ListNote>"  
 for(var i = 0; i < t.rows.length; i++) {
   theText = "<b>Next Referral</b><br>"+
             "<b>"+t.rows[i][0]+" " +
             t.rows[i][3]+"<br><br>" +
             t.rows[i][5]+"<br>Active From "+t.rows[i][1]+"<br><br>";

   OS += "<li class=ItemNote onclick=\"parent.AddClinicalNote(this,'"+i+"','"+theText+"');\">" +
         "<div class=ntRow><span class=ntWho>"+t.rows[i][0]+"</span>" +
         "<span class=ntType>Active From "+t.rows[i][1]+"</span><div><br>"+
         "<div class=ntRow>"+
         "<span class=ntWho>"+t.rows[i][3]+"</span>" +
         "<span class=ntWhen>"+t.rows[i][4]+"</span></div>" +
         "<div class=ntRow>"+
         "<span class=ntWho>"+t.rows[i][5]+"</span></div>" +
         "<div class=ntRow>"+
         "<span class=ntWho>"+t.rows[i][2]+"</span></div></li>"
 }
 OS+='</ul>'

 ListLocation = document.getElementById("TableLocation");
 ListLocation.innerHTML = OS;
 ListLocation.style.overflow = "auto";
 
 ListLocation.style.height = document.body.clientHeight - ListLocation.offsetTop;
 if (t.rows.length == 0) {
   ListLocation.innerHTML += "<ul class=ListNote>" +
                             "<li class=ItemNote style='text-align:center;'>" + 
                             "No Allied Health Referrals for this patient"+
                             "</li><li class=ItemRes></li></ul>"
 }
}

function setServerDateTime() {
   clientOffsetTime=GetCookieData("clientOffsetTime");
   if (isWhitespace(clientOffsetTime)||clientOffsetTime=='unknown')
   {
     var serverURL   = "../cgi-bin/patweb80.pbl?reportno=1"
     var returnValue = RSExecute(serverURL);
     if (returnValue.status==0) {
       ReturnValue=returnValue.return_value.split("|");
       serverDate=trim(ReturnValue[0]);
       serverTime=trim(ReturnValue[1]);
       serverDateTime=new Date(serverDate+' '+serverTime);
       clientDateTime=new Date();
       clientOffsetTime = serverDateTime.getTime() - clientDateTime.getTime();
       SetCookie("clientOffsetTime",clientOffsetTime,"10")
     }
   }
   serverDateTime=new Date();
   serverDateTime.setTime(serverDateTime.getTime() + parseInt(trim(clientOffsetTime),10));
}
function FormatCommentAge(datetime) {
 yyyy = datetime.substr(0,4);
 mm = datetime.substr(4,2);
 dd = datetime.substr(6,2);
 hh = datetime.substr(8,2);
 mi = datetime.substr(11,2);
 var thisDate= new Date(yyyy,parseInt(mm,10)-1,dd,hh,mi);
 var today= new Date();
 if (isWhitespace(clientOffsetTime)) { setServerDateTime(); }
 today.setTime(today.getTime() + parseInt(trim(clientOffsetTime),10));
 var one_min=1000*60
 var one_hour=1000*60*60
 var one_day=1000*60*60*24
 var one_week=1000*60*60*24*7
 var one_month=1000*60*60*24*30
 mid=Math.ceil((today.getTime()-thisDate.getTime())/(one_min))
 hrd=Math.ceil((today.getTime()-thisDate.getTime())/(one_hour))
 dyd=Math.ceil((today.getTime()-thisDate.getTime())/(one_day))
 wkd=Math.ceil((today.getTime()-thisDate.getTime())/(one_week))
 mtd=Math.ceil((today.getTime()-thisDate.getTime())/(one_month))
 if (mtd>2) return mtd+' months ago';
 if (wkd>2) return wkd+' weeks ago';
 if (dyd>2) return dyd+' days ago';
 if (hrd>2) return hrd+' hours ago';
 return mid+' minutes ago';
}
function FormatDateTime(datetime) {
   yyyy = datetime.substr(0,4);
   mm = datetime.substr(4,2);
   dd = datetime.substr(6,2);
   time = datetime.substr(8,5);
   mth3=mth3Name(mm);
   if (isWhitespace(time)) {
      return(dd + " " + mth3 + " " + yyyy); }
   else {
     return(dd + " " + mth3 + " " + yyyy + " at " + time); }
}

function FormatDate(date) {
   yyyy = date.substr(0,4)
   mm = date.substr(4,2)
   dd = date.substr(6,2)
   mth3=mth3Name(mm);
   return(dd + " " + mth3 + " " + yyyy  );
}

function mth3Name(mm) {
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
  return mth3;
}
function Table() {
   this.rows      = new Array();
   this.addRow    = _addTableRow;
}
function _addTableRow() {
  this.rows[this.rows.length] = new Array();
  var row = this.rows[this.rows.length-1];
  for(var i = 0; i < arguments.length; i++)
     row[row.length] = arguments[i];
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
