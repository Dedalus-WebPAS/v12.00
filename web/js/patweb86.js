//jsVersion  : V12.00.00
//=============================================================================
// Program   : patweb86.js
//
// Written   : 14.05.2002 Pat Dirito  
//
// Function  : Standard Functions Used in patweb86 templates 
//
//=============================================================================
// Report No 2 javascript functions 
//=============================================================================
//
//   NEXT PAGE BUTTON
//
//function PatientLink(link,set) {
//  location.href=link;
//}
function PatientLink(link,lock) {
  var admissno=link.substr(65,8);
  var ur=link.substr(47,8);

  //
  //  If lock = 0 then no Patient Codding, need to lock Record
  //
  if (lock=="0") {
    var serverURL = "../cgi-bin/mrtweb02.pbl?reportno=2" +
                    "&urnumber=" + ur.replace(/ /g,"+") +
                    "&admissno=" + admissno.replace(/ /g,"+") +
                    "&valdtype=3";

    if (IEBrowser) {
      var returnValue = RSExecute(serverURL);

      if (returnValue.status==0) {
        ReturnValue=returnValue.return_value.split("|");
        if (ReturnValue[0]=="1") {
          location.href=link;
        }
      }
    }
    else {
      var returnValue = RSExecuteFetch(serverURL);

      returnValue.then(
        function (returnValue) {
          returnValue = ParseFetchData(returnValue);  // parse fetch() result

          if (returnValue.status==0) {
            ReturnValue=returnValue.return_value.split("|");
            if (ReturnValue[0]=="1") {
              location.href=link;
            }
          }
        }
      );
    }
  } else {
    location.href=link;
  }
}
function NextRecordSet(key) {
  alert("Limit Reached")
  NextPage.innerHTML="<input type=button class=button value=Next " +
                     "onclick='NextRecords(\"" + key + "\");'>"
}
function NextRecords(Key) {
  document.SelectPeriod.uncodkey.value=Key;
  document.SelectPeriod.submit();
}

//
function valHfund(ReturnFund,FundName) {
  if(!isWhitespace(ReturnFund.value)) {
     validateCode(16,ReturnFund,FundName)
  }
  if(isWhitespace(ReturnFund.value)) {
    ReturnFund.value="";
    FundName.value="";
  }
}
//
function clrHfund(hfund,hfdesc,hftable,hftdesc) {
  hfund.value="";
  hfund.className="";
  hfdesc.value="";
  hftable.value="";
  hftable.className="";
  hftdesc.value="";
  hfund.select();
}

function sortMrtLocation(selElem) {
// function to sort M/R Location dropdown.
    var tmpAry = new Array();
    var allOptionFound = false;
    var startNumber = 0;

    for (var i=0;i<selElem.options.length;i++) {

        if(selElem.options[i].text == "All") {
              allOptionFound = true;
              continue;
        }
        tmpAry[i] = new Array();
        tmpAry[i][1] = selElem.options[i].text;
        //ignore case
        tmpAry[i][0] = selElem.options[i].text.toUpperCase();
        tmpAry[i][2] = selElem.options[i].value;
    }

    tmpAry.sort();

    while (selElem.options.length > 0) {
        selElem.options[0] = null;
    }

    if(allOptionFound == true) {
      startNumber = 0;
      selElem.options[0] = new Option("All"," ");
    }
    
    for (var i=startNumber;i<tmpAry.length;i++) {
        if(typeof tmpAry[i] != 'undefined' ) {
          var op = new Option(tmpAry[i][1], tmpAry[i][2]);
          selElem.options[i+1] = op;
        }
    }

    return;
}
//
