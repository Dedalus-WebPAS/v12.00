//jsVersion  : V12.00.00
//
// Source Code:  ./ipad/cliweb0601707.js
//
// Modification 
//
// Version   Date       Responsible/Changes Made
//------------------------------------------------------------------------------
// V10.07.01 15.10.2015 B.G.Ackland CAR
//                      Change onkeyup to oninput for IOS bluetooth keyboard support
// V10.03.01 06.08.2013 B.G.Ackland CAR 289383
//                      New AJAXPostString2 to fix post encoding
// V10.03.00 13/04/2012 Version change
// V10.01.00 13/04/2012 Version change
// V10.00.00 13/04/2012 Created for Mobility Suite
//
/******************************************************************************
 * global variables
 *****************************************************************************/
window.procedureTableName = "Procedure";
window[window.procedureTableName+"Suggestion"] = null;
window.diagnosisTableName = "Diagnosis";
window[window.diagnosisTableName+"Suggestion"] = null;
window.db = null;
window.lastFocus = ""; 
window.delay = false;
window.timeoutId = 0; //id used to reference the timeout function
//
// Initialize Page
//
function init() {
  var actionBtn = parent.document.getElementById('actionButton');
  if(actionBtn) {
    actionBtn.className = actionBtn.className.replace(/SpanButton/g,"");
    actionBtn.className = actionBtn.className.replace(/Blue/g,"");
    actionBtn.className = actionBtn.className + " SpanButtonBlue";
    actionBtn.innerText = "Save";
    actionBtn.onclick = function() {
      if (checkform()) {
        parent.frames['PatFrame'].refreshScreen();
        parent.CloseDocument();
      }
    }
  }
}
/******************************************************************************
 * trim - remove white spaces
 *****************************************************************************/
String.prototype.trim = function () {
        return this.replace(/^\s+|\s+$/g, '');
}
/******************************************************************************
 * checkType - the event when user types into a text field
 *****************************************************************************/
function checkType(stringName,tblName,reptNo,e) {
  var delayTime = 250; //250ms
  var url = "../cgi-bin/cliweb06.php?search=" ;
  if(!e){
    e=event;
  }
  window.lastFocus = tblName; //what input field was last focused on
  clearTimeout(window.timeoutId); //clear when event is trigged before delayTime
  if(stringName.value.length > 2 ) {
    if (e.keyCode == 8 || e.keyCode ==46) {
      window.timeoutId = setTimeout( function() {
         window[tblName+"Suggestion"].getListRemotely(stringName,url,reptNo);
      },delayTime);
    } else if(e.keyCode < 32 || (e.keyCode >= 33 && e.keyCode <=56) || (e.keyCode >= 112 && e.keyCode <= 123)) {
     //ignore keys
       return;
    }else {
       window.timeoutId = setTimeout( function() {
         window[tblName+"Suggestion"].getListRemotely(stringName,url,reptNo);
       },delayTime);
    }
  }else {
    window[tblName+"Suggestion"].hide();
  }
}

/******************************************************************************
 * populate - set the value from autosuggestion to inputfields
 *****************************************************************************/
function populate(code,name) {
 var d_obspn001 = document.getElementById("d_obspn001");
 var d_obspn002 = document.getElementById("d_obspn002");
 var obspn001 = document.getElementById("obspn001");
 var obspn002 = document.getElementById("obspn002");
 if (window.lastFocus == window.procedureTableName) {
    d_obspn002.value = name.trim();
    obspn002.value = code;
  } else if (window.lastFocus == window.diagnosisTableName){
    d_obspn001.value = name.trim();
    obspn001.value = code;
  }
}
//
// Display Search Panel
//
function displaySearchPanel(placeHolderText) {
   var searchText = document.getElementById('searchText');
   searchText.setAttribute('placeHolder',placeHolderText);
   searchText.value = "";
   searchText.focus();  

   if(placeHolderText.match(/Diagnosis/)) {
     searchText.onkeyup = function() {
       checkType(searchText,diagnosisSearch,"searchResult");
     }    
   }else {
     searchText.onkeyup = function() {
       checkType(searchText,procedureSearch,"searchResult");
     }
   }
}
//-----------------------------------------------------------------------------
// submit to web service the keyword search
//-----------------------------------------------------------------------------
function checkType(stringName,searchKeyword,div,e) {
  var delayTime = 150; //250ms
  if(!e) {
    e = event;
  }
  clearTimeout(window.timeoutId);
  if(stringName.value.length > 2)
  {
    if (e.keyCode == 8 || e.keyCode ==46) {
      window.timeoutId = setTimeout( function() {
          searchKeyword(stringName.value);
      },delayTime);
    } else if(e.keyCode < 32 || (e.keyCode >= 33 && e.keyCode <=56) ||
             (e.keyCode >= 112 && e.keyCode <= 123)) {
      return;
    }else {
      window.timeoutId = setTimeout( function() {
          searchKeyword(stringName.value);
      },delayTime);
    }
  } else if(stringName.value.length == 0) {
      ListLocation = document.getElementById(div);
      ListLocation.innerHTML = "";
  }
}
//-----------------------------------------------------------------------------
// doctor keyword search for the search panel
//-----------------------------------------------------------------------------
function diagnosisSearch(value) {
  var obj = new Object();
  var url   = "../cgi-bin/cliweb06.php?reportno=7&search="+value;
  var xmlHttp = createHttpObject();
  xmlHttp.open('GET',url,true);
  xmlHttp.send();
  xmlHttp.onreadystatechange = function() {
    if (xmlHttp.readyState == 4 && xmlHttp.status == 200) {
      if ((xmlHttp.responseText).length < 2) {
         ListLocation = document.getElementById("searchResult");
         if (ListLocation) {
            ListLocation.innerHTML = "<ul class='sectionList'>"+
                                     "<li class='sectionItem' style='text-align:center'>"+
                                     "No Matching Diagnosis Found</li></ul>";
         }
         return;
      }
      obj = eval("("+xmlHttp.responseText+")"); //convert text to javascript object
      var OS2=" ";
      for (var i =0; i < obj.length; i++) {
          OS2 += "<li class=sectionItem onclick=\"AddSearchResult("
                 +"'"+obj[i].code+"','"+obj[i].name+"','principleDiagnosis');\" />"+
                 "<span>("+obj[i].code+") "+
                   obj[i].name+ "</span></li>";
      }
      ListLocation = document.getElementById("searchResult");
      ListLocation.innerHTML = OS2;
    }
  }
}
//-----------------------------------------------------------------------------
// add the doctor to the array list
//-----------------------------------------------------------------------------
function AddSearchResult(code,name,divName){
  var panel = document.getElementById(divName);
  var fileName = "";
  if (divName.match(/Diagnosis/)) {
      fieldName = "obspn001";
  } else {
      fieldName = "obspn002";
  }
  panel.innerHTML = "<div onclick=\"removeItem(this,'"+name+"','"+panel.id+"');\""+
                    " style='padding-bottom:15px;'>("+
                    code+") "+name+
                    " <input type=\"hidden\" id=\""+fieldName+"\" name=\""+fieldName+"\" "+
                    "  value=\""+code+"\" />"+
                    "</div>";
}
function removeItem(obj,itemDesc,divName) {
  div = document.getElementById(divName);
  confirmMsg="Click OK to remove "+itemDesc;
  alertify.confirm(confirmMsg, function (e) {    
    if (e) { 
      div.removeChild(obj);
    }
  });
}
function procedureSearch(value) {
  var obj = new Object();
  var url   = "../cgi-bin/cliweb06.php?reportno=6&search="+value;
  var xmlHttp = createHttpObject();
  xmlHttp.open('GET',url,true);
  xmlHttp.send();
  xmlHttp.onreadystatechange = function() {
    if (xmlHttp.readyState == 4 && xmlHttp.status == 200) {
      if ((xmlHttp.responseText).length < 2) {
        ListLocation = document.getElementById("searchResult");
        if (ListLocation) {
          ListLocation.innerHTML = "<ul class='sectionList'>"+
                                   "<li class='sectionItem' style='text-align:center'>"+
                                   "No Matching Procedure Found</li></ul>";
        }
        return;
      }
      obj = eval("("+xmlHttp.responseText+")"); //convert text to javascript object
      var OS2=" ";
      for (var i =0; i < obj.length; i++) {
        OS2 += "<li class=sectionItem onclick=\"AddSearchResult("+
               "'"+obj[i].code+"','"+obj[i].name+"','principleProcedure');\" />"+
               "<span>("+obj[i].code+") "+
               obj[i].name+ "</span></li>";
      }
      ListLocation = document.getElementById("searchResult");
      ListLocation.innerHTML = OS2;
    }
  }
}
function checkform() {
 var obspn002 = document.getElementById("obspn002");
 var obspn001 = document.getElementById("obspn001");
 var okToSubmit = false;
 var arr = new Array();
 arr.push(obspn001);
 arr.push(obspn002);
 for(var i = 0; i < arr.length; i++) {
   if (arr[i]) {
       okToSubmit = true;
   } else {
       alertify.alert("Please make sure prinicple dignosis and principle procedure is populated.");
       okToSubmit = false;
       break;
   }
 }
 if(okToSubmit){
   addNote('A0');
 }
 return okToSubmit;
}
