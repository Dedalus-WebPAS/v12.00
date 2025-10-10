//jsVersion  : V12.00.00
//========================================================================
function GetTheatreRequestCookies() {
  if (GetCookieData("BookTheatreReqVisitnoCookie")!="unknown") {
    document.AddForm.bkthvick.value=
    GetCookieData("BookTheatreReqVisitnoCookie");
  }
  ExpireCookiePath("BookTheatreReqVisitnoCookie");
  if (GetCookieData("BookTheatreReqReqnumCookie")!="unknown") {
    document.AddForm.requestn.value=
    GetCookieData("BookTheatreReqReqnumCookie");
  }
  ExpireCookiePath("BookTheatreReqReqnumCookie");
  if (GetCookieData("TheatreRequestRedirect")!="unknown" &&
      !isWhitespace(GetCookieData("TheatreRequestRedirect"))) {
    document.AddForm.nextlink.value=
    GetCookieData("TheatreRequestRedirect");
  }
  ExpireCookiePath("TheatreRequestRedirect");

  if (!isWhitespace(document.AddForm.requestn.value)) {
    var serverURL   = "../cgi-bin/comweb80.pbl?reportno=93" +
               "&valdcode=" + document.AddForm.requestn.value.replace(/ /g,"+");
    var returnValue = RSExecute(serverURL);
    if (returnValue.status==0) {
      if (document.AddForm.opcom009 != undefined) {
        document.AddForm.opcom009.value=returnValue.return_value;
      }
    }
    var serverURL   = "../cgi-bin/comweb80.pbl?reportno=94" +
               "&valdcode=" + document.AddForm.requestn.value.replace(/ /g,"+");
    var returnValue = RSExecute(serverURL);
    if (returnValue.status==0) {
      ReturnValue=returnValue.return_value.split("|")
      assignTheatreReqDefaults(ReturnValue);
      document.getElementById('thetrqin').value="1";
    }
  }
}
function assignTheatreReqDefaults(ReturnValue) {
  if (!isWhitespace(ReturnValue[0])) {
    for (var i =0 ; i < document.AddForm.bokrx003.length; i++) {
      if (document.AddForm.bokrx003.options[i].value.substr(0,3) ==
          ReturnValue[0]) {
        document.AddForm.bokrx003.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[1])) {
    for (var i =0 ; i < document.AddForm.bokrx002.length; i++) {
      if (document.AddForm.bokrx002.options[i].value.substr(0,3) ==
          ReturnValue[1]) {
        document.AddForm.bokrx002.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[2])) {
    for (var i =0 ; i < document.AddForm.operanae.length; i++) {
      if (document.AddForm.operanae.options[i].value.substr(0,3) ==
          ReturnValue[2]) {
        document.AddForm.operanae.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[3])) {
    document.AddForm.operprv1.value=ReturnValue[3];
    validateCode(4,
                 document.AddForm.operprv1,
                 document.AddForm.mbsdesc1,
                 document.AddForm.bookdate);
  }

  if (!isWhitespace(ReturnValue[4])) {
    document.AddForm.operprv2.value=ReturnValue[4];
    validateCode(4,
                 document.AddForm.operprv2,
                 document.AddForm.mbsdesc2,
                 document.AddForm.bookdate);
  }

  if (!isWhitespace(ReturnValue[5])) {
    document.AddForm.operprv3.value=ReturnValue[5];
    validateCode(4,
                 document.AddForm.operprv3,
                 document.AddForm.mbsdesc3,
                 document.AddForm.bookdate);
  }

  if (!isWhitespace(ReturnValue[6])) {
    document.AddForm.operdes1.value=ReturnValue[6];
  }

  if (!isWhitespace(ReturnValue[7])) {
    document.AddForm.operdes2.value=ReturnValue[7];
  }

  if (!isWhitespace(ReturnValue[8])) {
    document.AddForm.operdes3.value=ReturnValue[8];
  }

  if (!isWhitespace(ReturnValue[9])) {
    document.AddForm.opercomm.value=ReturnValue[9];
  }

  if (!isWhitespace(ReturnValue[10])) {
    for (var i =0 ; i < document.AddForm.operknow.length; i++) {
      if (document.AddForm.operknow.options[i].value.substr(0,3) ==
          ReturnValue[10]) {
        document.AddForm.operknow.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[11])) {
    for (var i =0 ; i < document.AddForm.opdea032.length; i++) {
      if (document.AddForm.opdea032.options[i].value.substr(0,3) ==
          ReturnValue[11]) {
        document.AddForm.opdea032.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[12])) {
    for (var i =0 ; i < document.AddForm.opdea033.length; i++) {
      if (document.AddForm.opdea033.options[i].value.substr(0,3) ==
          ReturnValue[12]) {
        document.AddForm.opdea033.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[13])) {
    for (var i =0 ; i < document.AddForm.opdea035.length; i++) {
      if (document.AddForm.opdea035.options[i].value.substr(0,3) ==
          ReturnValue[13]) {
        document.AddForm.opdea035.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[14])) {
    for (var i =0 ; i < document.AddForm.opdea038.length; i++) {
      if (document.AddForm.opdea038.options[i].value.substr(0,1) ==
          ReturnValue[14]) {
        document.AddForm.opdea038.selectedIndex=i
      }
    }
  }

  if (!isWhitespace(ReturnValue[15])) {
    document.AddForm.opdea039.value=ReturnValue[15].substr(6,2) +
                                    ReturnValue[15].substr(4,2) +
                                    ReturnValue[15].substr(0,4);
    checkDate(document.AddForm.opdea039,'Consent Date')
  }

  if (!isWhitespace(ReturnValue[16])) {
    document.getElementById('thetrqvl').value=ReturnValue[16]
  }
}
