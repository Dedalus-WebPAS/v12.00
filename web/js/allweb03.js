//jsVersion  : V12.00.02
//========================================================================

//Ajax Call retrieving data based on UR number
function CheckurVisit(OptionNumber,OptionDate,ReturnCode,ReturnName) {

  ReturnFunction="" ;
  ReturnName.value="";

  //Checks arguments for a function, and assigns it to ReturnFuction
  //Otherwise clares it.
  for (var i=3; i < CheckurVisit.arguments.length; i++) {
    if (typeof(CheckurVisit.arguments[i]) == 'function') {
      ReturnFunction=CheckurVisit.arguments[i] }
    else {
      CheckurVisit.arguments[i].value=""; }  }

  if (isWhitespace(ReturnCode.value)) return;;

  //Calls the backend
  var serverURL  = "../cgi-bin/allweb03.pbl?reportno=" + OptionNumber +
               "&valddate=" + OptionDate.value.replace(/ /g,"+") + 
               "&returnfm=2" +
               "&valdcode=" + ReturnCode.value.replace(/ /g,"+") 
  var returnValue = RSExecute(serverURL);

  //Was the retrieval successul
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")
    ReturnName.value=trim(ReturnValue[0])
    j=0

    //Goes through the results and assigns the data
    for (var i=4; i < CheckurVisit.arguments.length; i++) {
       if (typeof(CheckurVisit.arguments[i]) != 'function') {
         j++
         CheckurVisit.arguments[i].value=ReturnValue[j] } }

    //Otherwise returns the function
    if (typeof(ReturnFunction) == 'function') {
       ReturnFunction() } }
  else {
    ReturnCode.select();  }
}
//
//
function CheckReferral(OptionNumber,ReturnCode,ReturnDep,ReturnName,ReturnLink,ReturnClaim,ReturnClinic,ReturnWait,ReturnUR,ReturnContract,ReturnPurchaser,ReturnRefDat1,ReturnRefDat2) {
  ReturnFunction="" ;
  ReturnName.value="";
  if (isWhitespace(ReturnCode.value)) return;;

  var serverURL  = "../cgi-bin/allweb03.pbl?reportno=" + OptionNumber +
               "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
               "&valddept=" + ReturnDep.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")
//

    ReturnName.value=ReturnValue[0]
    ReturnLink.value=ReturnValue[1]
    ReturnClaim.value=ReturnValue[2]
    document.AddForm.deftclmc.value=ReturnValue[2]
    ReturnClinic.value=ReturnValue[3]
    document.AddForm.deftclin.value=ReturnValue[3]
    ReturnWait=ReturnValue[4] 
    document.AddForm.status.value=ReturnValue[4]
    ReturnUR=ReturnValue[5] 
    document.AddForm.urnumber.value=ReturnValue[5]

    if (document.AddForm.ndisvald != undefined) {
      document.AddForm.ndisvald.value = ReturnValue[10];
    }

    if(ReturnContract != undefined)
    {
      ReturnContract.value=ReturnValue[6];
//      document.AddForm.deftcont.value=ReturnValue[6];
    }
    if(ReturnPurchaser!=undefined) {
      ReturnPurchaser.value=ReturnValue[7];
//      document.AddForm.deftpurc.value=ReturnValue[7];
    }

    if(ReturnRefDat1!=undefined) {
      ReturnRefDat1.value=ReturnValue[8];
    }
    if(ReturnRefDat2!=undefined) {
      ReturnRefDat2.value=ReturnValue[9];
    }

//
  } else {
    ReturnName.value="";
    ReturnLink.value="";
    ReturnClaim.value="";
    ReturnClinic.value="";
    ReturnCode.select();  }
}
//------------------------------------------------------------------
//  Validate an MBS item from the private practice item file
//------------------------------------------------------------------
function validatePMBS(ReturnCode,ReturnName) {
  ReturnFunction="" ;
  ReturnName.value="";
  for (var i=2; i < validatePMBS.arguments.length; i++) {
    if (typeof(validatePMBS.arguments[i]) == 'function') {
      ReturnFunction=validatePMBS.arguments[i] }
    else {
      validatePMBS.arguments[i].value=""; }  }
  if (isWhitespace(ReturnCode.value)) return;;
  var serverURL   = "../cgi-bin/allweb01.pbl?reportno=9" +
                    "&valdcode=" + ReturnCode.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")
    ReturnName.value=trim(ReturnValue[0])
    j=0
    for (var i=2; i < validatePMBS.arguments.length; i++) {
       if (typeof(validatePMBS.arguments[i]) != 'function') {
         j++
         validatePMBS.arguments[i].value=ReturnValue[j] } }
    if (typeof(ReturnFunction) == 'function') {
       ReturnFunction() } }
  else {
    ReturnCode.select();
    return false;
     }
}
//
//------------------------------------------------------------
// Validate a visit number and check it is for this U/R
//------------------------------------------------------------
function ValidateVisit(ValidateV,ValidateUR,ReturnName) {
  ReturnFunction="" ;
  ReturnName.value="";
  for (var i=3; i < ValidateVisit.arguments.length; i++) {
    if (typeof(ValidateVisit.arguments[i]) == 'function') {
      ReturnFunction=ValidateVisit.arguments[i] }
    else {
      ValidateVisit.arguments[i].value=""; }  }
  if (isWhitespace(ValidateV.value)) return;;
  var serverURL = "../cgi-bin/allweb03.pbl?reportno=10&valdcode=" +
                    ValidateV.value.replace(/ /g,"+") +
                    "&valdurno=" + ValidateUR.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|");
    ReturnName.value=ReturnValue[0];
    j=0
    for (var i=3; i < ValidateVisit.arguments.length; i++) {
       if (typeof(ValidateVisit.arguments[i]) != 'function') {
         j++
         ValidateVisiValidateVisit[i].value=ReturnValue[j] } }
    if (typeof(ReturnFunction) == 'function') {
       ReturnFunction() } }
  else {
    ValidateV.value=""; 
    ValidateV.focus();;  
    return false;}
}
//------------------------------------------------------------
// Validate a photo number
//------------------------------------------------------------
function ValidatePhoto(ReturnCode,ReturnName) {
  ReturnFunction="" ;
  ReturnName.value="";
  for (var i=2; i < ValidatePhoto.arguments.length; i++) {
    if (typeof(ValidatePhoto.arguments[i]) == 'function') {
      ReturnFunction=ValidatePhoto.arguments[i] }
    else {
      ValidatePhoto.arguments[i].value=""; }  }
  if (isWhitespace(ReturnCode.value)) return;;
  var serverURL   = "../cgi-bin/allweb03.pbl?reportno=11" +
                    "&valdcode=" + ReturnCode.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")
    ReturnName.value=trim(ReturnValue[0])
    j=0
    for (var i=2; i < ValidatePhoto.arguments.length; i++) {
       if (typeof(ValidatePhoto.arguments[i]) != 'function') {
         j++
         ValidatePhoto.arguments[i].value=trim(ReturnValue[j]) } }
    if (typeof(ReturnFunction) == 'function') {
       ReturnFunction() } }
  else {
    ReturnCode.select();
    return false;
     }
}
//------------------------------------------------------------
// Case Referral Alert
//------------------------------------------------------------
function CaseReferralAlert() {
  alert("Valid Case Referral Characters\n\n" +
"A - GP/Medical Practitioner\n" +
"B - Specialist Aged or Disability Assessment\n" +
"C - Comprehensive HACC Assessment\n" +
"D - Community Nursing Service\n" +
"E - Hospital (public)\n" +
"F - Psychiatric/Mental Health Service or Facility\n" +
"G - Extended Care/Rehabilitation Facility\n" +
"H - Palliative Care Facility/Hospice\n" +
"I - Government Residential Aged Care Facility\n" +
"J - Aboriginal Health Service\n" +
"K - Carelink Centre\n" +
"L - Other Community Based Government Medical/Health Service\n" +
"M - Other Government Medical Health Service\n" +
"N - Other Government Community Based Services Agency \n" +
"O - Hospital (private)\n" +
"P - Non Government Residential Aged Care Facility\n" +
"Q - Other Non Government Medical/Health Service\n" +
"R - Other Non Government Community Based Service\n" +
"S - Law Enforcement Agency\n" +
"T - Other\n");
}
//
function ValCaseReferral(caseref) {
  caseref.value=caseref.value.toUpperCase()
  checkref=caseref.value.search('[^A-T]');
  if(checkref >= 0) {
    alert("Invalid Case Referral Character Entered - " +
           caseref.value.substr(checkref,1));
    CaseReferralAlert();
    caseref.select();
    caseref.focus();
    return;
  }
//
  for (i=0; i<caseref.value.length; i++) {
    X=i + 1
    if(X==i) { return} 
    checkdup=caseref.value.substr(X).search(caseref.value.substr(i,1));
    if(checkdup >=0) {
       alert("Duplicate codes not allowed") 
       caseref.select();
       caseref.focus();
    }
  } 
}
//
function CheckLinkedBookings(referral,ur,checkflag) {
  if (isWhitespace(referral.value)) {
   return;
  }
  var serverURL = "../cgi-bin/allweb02.pbl?reportno=6&updatety=3" +
                  "&admissno=" + referral.value.replace(/ /g,"+") 
                  
  var returnValue = RSExecute(serverURL);
  ReturnValue=returnValue.return_value.split("|");
  if (returnValue.status==0) {
    if (ReturnValue[0] == 1) {    // Booked appointments exits
      var message = "Warning : Linked outpatient appointments exist " +
                    "for this referral" +
                    "\nClick OK to view and cancel appointments. " +
                    "Cancel to Continue.";
      if(confirm(message)) {
          linkUrl="allweb02.pbl?reportno=4&template=3" +
                  "&urnumber=" + ur.value.replace(/ /g,"+") +
                  "&admissno=" + referral.value.replace(/ /g,"+")
          Left=(document.body.clientWidth-700)/2
          DFrameLink(linkUrl,15,Left,700,450)
      } else {
        checkflag.value=1;
      }
    } else {
        checkflag.value=1;
    }
  }
}
function CheckFutureBookings(referral,closedate) {
  if (isWhitespace(referral.value) || isWhitespace(closedate.value)) {
   return true;
  }
  var serverURL = "../cgi-bin/allweb02.pbl?reportno=6&updatety=6" +
                  "&admissno=" + referral.value.replace(/ /g,"+") +
                  "&alref007=" + closedate.value.replace(/ /g,"+")

  var returnValue = RSExecute(serverURL);
  ReturnValue=returnValue.return_value.split("|");
  if (returnValue.status==0) {
    if (ReturnValue[0] == 1) {    // Booked future appointments exits
      var message = "Error : Linked outpatient appointments exist " +
                    "for this referral after the proposed Contact/Closure date."
      alert(message)
      return false;
    }
  }
  return true;
}
function PostParent() {
   document.UpdateForm.checkappt.value=1;
   AddEncounter(UpdateForm);
}
function GetEncDefaults(refvis,outvis) {
 if (isWhitespace(refvis) || isWhitespace(outvis)) {
  return;
 }
 var serverURL = "../cgi-bin/allweb02.pbl?reportno=6&updatety=4" +
                 "&refrlvis=" + refvis.replace(/ /g,"+") +
                 "&admissno=" + outvis.replace(/ /g,"+") 
 var returnValue = RSExecute(serverURL);
 ReturnValue=returnValue.return_value.split("|");
 if (returnValue.status==0) {
   if (ReturnValue[0] == 1) {
   }
   document.AddForm.alenc005.value=ReturnValue[0];

//   if (document.AddForm.todaydat!=undefined) {
//       if (document.AddForm.todaydat.value ==
//           document.AddForm.alenc005.value) {
//         document.AddForm.alenc006.value=ReturnValue[1] + ":00";
//       }
//   } else {
/* Condition Check for Indicators28 to category CG with type C and D */
     if( (ReturnValue[8] && (document.AddForm.d_ctimedeft))
        &&((document.AddForm.deptlcod.value.substr(75,1)=='C')||
           (document.AddForm.deptlcod.value.substr(75,1)=='D')
           )
       )
     {
       if(!isWhitespace(ReturnValue[8])) {
          document.AddForm.alenc006.value=ReturnValue[8] + ":00";
       }
     }
     else{
      document.AddForm.alenc006.value=ReturnValue[1] + ":00";
     }
//   }

   document.AddForm.d_alenc011.value=trim(ReturnValue[2]);
   document.AddForm.alenc011.value=trim(ReturnValue[2]);
//
   if(document.AddForm.alenc115!=undefined) {
    for(var i=0; i < document.AddForm.alenc115.length; i++) {
     if(document.AddForm.alenc115.options[i].value.substr(0,3)==ReturnValue[3]){
        document.AddForm.alenc115.selectedIndex=i;
      }
    } 
   }
//
   if(document.AddForm.alenc044!=undefined) {
     document.AddForm.alenc044.value=ReturnValue[4];
   }
//
   if(document.AddForm.alenc004!=undefined) {
     if (ReturnValue[5] != "      ") {
        document.AddForm.alenc004.value=ReturnValue[5]; }
   }
//
   if(document.AddForm.alenc007!=undefined) {
      for (var i =0 ; i < document.AddForm.alenc007.length; i++) {
          if (document.AddForm.alenc007.options[i].value.substr(0,3) ==
                       ReturnValue[6]) {
             document.AddForm.alenc007.selectedIndex=i }
      }
   }
//
   if(document.AddForm.alenc120!=undefined) {
    for(var i=0; i < document.AddForm.alenc120.length; i++) {
     if(document.AddForm.alenc120.options[i].value.substr(0,3)==ReturnValue[7]){
        document.AddForm.alenc120.selectedIndex=i;
      }
    }
   }
 }
}
function valClaimCode() {
  validateCode(41,UpdateForm.urnumber,UpdateForm.claimc);
  for (var i =0 ; i < document.UpdateForm.alenc115.length; i++) {
    if (document.UpdateForm.claimc.value==
        trim(document.UpdateForm.alenc115.options[i].value.substr(0,3))){
          document.UpdateForm.alenc115.selectedIndex=i;
    }
  }
}
//
function getCheckInTimeCookie() {
  if(parent.AhAutoCheckIn!=undefined &&
     isWhitespace(AddForm.bulkenck.value)) {
      if(AddForm.alenc006!=undefined) {
        parent.AhAutoCheckIn(AddForm.alenc006.value);
        ExpireCookiePath("CheckInTimeCookie");
        return;
      }
  }
  document.AddForm.urnockie.value="";
  document.AddForm.admnckie.value="";
  document.AddForm.rwnockie.value="";
  document.AddForm.clnockie.value="";
  document.AddForm.caseckie.value="";
//
  if (GetCookieData('CheckInTimeCookie')=="unknown") {
   return;
  }
//
  tmckaray=GetCookieData('CheckInTimeCookie').split("|")

  document.AddForm.urnockie.value=tmckaray[0];
  document.AddForm.admnckie.value=tmckaray[1];
  document.AddForm.rwnockie.value=tmckaray[2];
  document.AddForm.clnockie.value=tmckaray[3];
  document.AddForm.caseckie.value=tmckaray[4];
//
  ExpireCookiePath("CheckInTimeCookie");
//
  if (isWhitespace(document.AddForm.urnockie.value)) {
    return;
  }
  if (parent.RemoteCheckInAH != undefined) {
    parent.RemoteCheckInAH(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value,
                          document.AddForm.alenc006.value);
    return;
  }
  if (parent.RemoteCheckIn != undefined) {
    parent.RemoteCheckIn(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value);
  }
}
//
function getTimeSeenCookie() {
  if(parent.AhAutoTimeSeen!=undefined &&
     isWhitespace(AddForm.bulkenck.value)) {
      if(AddForm.alenc006!=undefined) {
        parent.AhAutoTimeSeen(AddForm.alenc006.value);
        ExpireCookiePath("TimeSeenOnlyCookie");
        return;
      }
  }
  document.AddForm.urnockie.value="";
  document.AddForm.admnckie.value="";
  document.AddForm.rwnockie.value="";
  document.AddForm.clnockie.value="";
  document.AddForm.caseckie.value="";
//
  if (GetCookieData('TimeSeenOnlyCookie')=="unknown") {
   return;
  }
//
  tmsnaray=GetCookieData('TimeSeenOnlyCookie').split("|")

  document.AddForm.urnockie.value=tmsnaray[0];
  document.AddForm.admnckie.value=tmsnaray[1];
  document.AddForm.rwnockie.value=tmsnaray[2];
  document.AddForm.clnockie.value=tmsnaray[3];
  document.AddForm.caseckie.value=tmsnaray[4];
//
  ExpireCookiePath("TimeSeenOnlyCookie");
//
  if (isWhitespace(document.AddForm.urnockie.value)) {
    return;
  }
  if (parent.RemoteTimeSeenAH != undefined) {
    parent.RemoteTimeSeenAH(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value,
                          document.AddForm.alenc006.value);
    return;
  }
  if (parent.RemoteTimeSeen != undefined) {
    parent.RemoteTimeSeen(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value);
  }
}
//
function getDepartureTimeCookie() {
  document.AddForm.urnockie.value="";
  document.AddForm.admnckie.value="";
  document.AddForm.rwnockie.value="";
  document.AddForm.clnockie.value="";
  document.AddForm.caseckie.value="";
//
  if (GetCookieData('DepartureTimeCookie')=="unknown") {
     return;
  }
//
  tmdparay=GetCookieData('DepartureTimeCookie').split("|")
  document.AddForm.urnockie.value=tmdparay[0];
  document.AddForm.admnckie.value=tmdparay[1];
  document.AddForm.rwnockie.value=tmdparay[2];
  document.AddForm.clnockie.value=tmdparay[3];
  document.AddForm.caseckie.value=tmdparay[4];
//
  ExpireCookiePath("DepartureTimeCookie");
//
  if (isWhitespace(document.AddForm.urnockie.value)) {
    return;
  }
  if (parent.RemoteDepartureAH != undefined &&
      document.AddForm.alenc018 != undefined) {
    parent.RemoteDepartureAH(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value,
                          document.AddForm.alenc018.value);
    return;
  }

  if (parent.RemoteDeparture != undefined) {
    parent.RemoteDeparture(document.AddForm.urnockie.value,
                          document.AddForm.admnckie.value,
                          document.AddForm.rwnockie.value,
                          document.AddForm.clnockie.value,
                          document.AddForm.caseckie.value);
  }
}

function CheckAddHCP() {
  if(document.AddForm.addithcp.checked==true){
     AdditionalHCP.style.display="";
     AdditionalHCP.innerHTML=ShowAdditionalHCP.innerHTML;
  } else {
     AdditionalHCP.innerHTML="";
     AdditionalHCP.style.display="none";
  }
}

function CheckUpdHCP() {
  if(document.UpdateForm.addithcp.checked==true){
     AdditionalHCP.style.display="";
     AdditionalHCP.innerHTML=ShowAdditionalHCP.innerHTML;
  } else {
     AdditionalHCP.innerHTML="";
     AdditionalHCP.style.display="none";
  }
}
function DefaultPreviousContact() {
 if(document.UpdateForm.alcnprev.value!="1") {
   return;
 }
 if (!isWhitespace(document.UpdateForm.prevuc37.value)){
   for (var i =0 ; i < document.UpdateForm.alenc083.length; i++) {
    if (document.UpdateForm.alenc083.options[i].value.substr(0,3) ==
        document.UpdateForm.prevuc37.value) {
       document.UpdateForm.alenc083.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.UpdateForm.prevuc38.value)) {
   for (var i =0 ; i < document.UpdateForm.alenc084.length; i++) {
    if (document.UpdateForm.alenc084.options[i].value.substr(0,3) ==
        document.UpdateForm.prevuc38.value) {
       document.UpdateForm.alenc084.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.UpdateForm.prevuc40.value)) {
   for (var i =0 ; i < document.UpdateForm.alenc086.length; i++) {
    if (document.UpdateForm.alenc086.options[i].value.substr(0,3) ==
        document.UpdateForm.prevuc40.value) {
       document.UpdateForm.alenc086.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.UpdateForm.prevuc34.value)) {
   for (var i =0 ; i < document.UpdateForm.alenc080.length; i++) {
    if (document.UpdateForm.alenc080.options[i].value.substr(0,3) ==
        document.UpdateForm.prevuc34.value) {
       document.UpdateForm.alenc080.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.UpdateForm.prevuc35.value)) {
   for (var i =0 ; i < document.UpdateForm.alenc081.length; i++) {
    if (document.UpdateForm.alenc081.options[i].value.substr(0,3) ==
        document.UpdateForm.prevuc35.value) {
       document.UpdateForm.alenc081.selectedIndex=i }
   }
 }
}
function DefaultPreviousContactCombined() {
 if(document.AddForm.alcnprev.value!="1") {
   return;
 }

 if (!isWhitespace(document.AddForm.prevuc37.value)) {
   for (var i =0 ; i < document.AddForm.alenc083.length; i++) {
    if (document.AddForm.alenc083.options[i].value.substr(0,3) ==
        document.AddForm.prevuc37.value) {
       document.AddForm.alenc083.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.AddForm.prevuc38.value)) {
   for (var i =0 ; i < document.AddForm.alenc084.length; i++) {
    if (document.AddForm.alenc084.options[i].value.substr(0,3) ==
        document.AddForm.prevuc38.value) {
       document.AddForm.alenc084.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.AddForm.prevuc40.value)) {
   for (var i =0 ; i < document.AddForm.alenc086.length; i++) {
    if (document.AddForm.alenc086.options[i].value.substr(0,3) ==
        document.AddForm.prevuc40.value) {
       document.AddForm.alenc086.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.AddForm.prevuc34.value)) {
   for (var i =0 ; i < document.AddForm.alenc080.length; i++) {
    if (document.AddForm.alenc080.options[i].value.substr(0,3) ==
        document.AddForm.prevuc34.value) {
       document.AddForm.alenc080.selectedIndex=i }
   }
 }

 if (!isWhitespace(document.AddForm.prevuc35.value)) {
   for (var i =0 ; i < document.AddForm.alenc081.length; i++) {
    if (document.AddForm.alenc081.options[i].value.substr(0,3) ==
        document.AddForm.prevuc35.value) {
       document.AddForm.alenc081.selectedIndex=i }
   }
 }
}
function setUserDoc(dept,usrdoc,docfield,docname,usrhcp){
  //return if both user hcp or user doc are empty
  if(isWhitespace(usrdoc.value) &&
       isWhitespace(usrhcp.value)) {  
       return;
  }

  if(dept.value.substring(78,79)=="U") {
    // if user hcp value exists
    if(!isWhitespace(usrhcp.value)) {
       docfield.value = usrhcp.value;
    } else {
    // if user hcp value not exists and user doc data present
      if(isWhitespace(usrhcp.value) && !isWhitespace(usrdoc.value)) {
         docfield.value = usrdoc.value;
      }
    }
    ValidateHCP(18,0,docfield,docname);
  } 
}

function checkFutureContactTime() {
  p=document.AddForm;
  if(isWhitespace(p.alenc005.value) || isWhitespace(p.alenc006.value)) {
     return true;
  }
  SetCurrentDateTimeNoFocus(p.currdate,p.currtime);// UNIX time
  if(SetDateYYYYMMDD(p.alenc005.value)>SetDateYYYYMMDD(p.currdate.value)) {
    alert("Contact date should not be in future");
    return false;
  }
  if (SetDateYYYYMMDD(p.alenc005.value)==SetDateYYYYMMDD(p.currdate.value)) {
    var newttime=trim(p.alenc006.value.replace(/:/g,"")) - 0
    var currentt=trim(p.currtime.value.replace(/:/g,"")) - 0
    if(newttime>currentt){
      alert("Contact time should not be in future");
      return false;
    }
 }
 return true;
}

//
// Returns the text for the first option in a dropdown selection list 
// with a matching HDP Equiv value.
//
function getSelectionText(ddl, HDPEquip) {
  if (!ddl || ddl == undefined || HDPEquip == undefined) return;

  for (i=0; i < ddl.options.length; i++) {
    if (trim(ddl.options[i].value.substr(14,4)) == HDPEquip) {
      return ddl.options[i].text;
    }
  }

  return '';
}
function DisplayTrnSrc() {
  var obj = document.getElementById('outbb035');  // get Outcome field
  if (obj == undefined)
    return;

  var i = obj.selectedIndex;
  var code = obj.options[i].value.substr(0,3);        // Code (Category 'OZ')
  var ind11 = obj.options[i].value.substr(13,1);      // Indicator 11
  var destypcod = obj.options[i].value.substr(28,1);  // Destination Type
  var admsrc = document.getElementById('admnsrce');
  var dsttyp = document.getElementById('desttype');

  if (ind11 == 'T') {
    ShowTrnSrc();
    if (admsrc) admsrc.value = code;
    if (dsttyp) dsttyp.value = destypcod;
  }
  else {
    HideTrnSrc();
    if (admsrc) admsrc.value = "";
    if (dsttyp) dsttyp.value = "";
  }
}
function ShowTrnSrc() {
  document.getElementById('divTransDestLbl').innerHTML = "Transfer Destination";
  document.getElementById('divTransDestFld').innerHTML =
    document.getElementById('spTransDest').innerHTML;
}
function HideTrnSrc() {
  document.getElementById('divTransDestLbl').innerHTML = "";
  document.getElementById('divTransDestFld').innerHTML =
    document.getElementById('transferblank').innerHTML;
  document.getElementById('trnsfsrc').value = "";
}
function OutcomeChange(obj) {
  if (obj == undefined)
    return;

  DisplayTrnSrc();

  var i = obj.selectedIndex;
  var ind11 = obj.options[i].value.substr(13,1);      // Indicator 11

  if (ind11 == 'T') {
    ClearTrnFlds();
  }
}
function ClearTrnFlds() {
  document.getElementById('trnsfsrc').value = "";
  document.getElementById('trandesc').value = "";

}
//------------------------------------------------------------
// Validate transfer source codes - (patvadaf)
//------------------------------------------------------------
function validateTransSrc(ReturnCode,ReturnDate,ReturnName,DestType) {
  ReturnFunction="" ;
  ReturnName.value="";
  for (var i=4; i < validateTransSrc.arguments.length; i++) {
    if (typeof(validateTransSrc.arguments[i]) == 'function') {
      ReturnFunction=validateTransSrc.arguments[i];
    }
    else {
      validateTransSrc.arguments[i].value="";
    }
  }

  if (isWhitespace(ReturnCode.value)) return;;

  var serverURL   = "../cgi-bin/patweb80.pbl?reportno=9" +
                    "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
                    "&trandate=" + ReturnDate.value.replace(/ /g,"+") +
                    "&filtdtyp=1&desttype=" + DestType.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")
    ReturnName.value=trim(ReturnValue[0])
    j=0
    for (var i=4; i < validateTransSrc.arguments.length; i++) {
      if (typeof(validateTransSrc.arguments[i]) != 'function') {
        j++
        validateTransSrc.arguments[i].value=ReturnValue[j];
      }
    }

    if (typeof(ReturnFunction) == 'function') {
       ReturnFunction();
    }
    return true;
  }
  else {
    ReturnCode.select();
    ReturnCode.focus();
    return false;
  }
}
function validateContactTime() {
  var ctimeindc=document.getElementById("d_ctimedeft");
  if(ctimeindc){
     var ctimindcval=document.getElementById("deptlcod").value.substr(75,1);
     if((ctimindcval=='S') || (ctimindcval=='D')){
        return true; 
     }
     if(ctimindcval=='C'){
        if(AddForm.alenc006.value < AddForm.d_otbbcitm.value) {
          alert("Contact time should be same as or  after check in time.");
          AddForm.alenc006.focus();
          return false;
        }
     }
  }
  if(!isWhitespace(AddForm.bulkenck.value)) {
    if(!isWhitespace(AddForm.d_otbbcitm.value) &&
       !isWhitespace(AddForm.alenc006.value)) {
      if(AddForm.alenc006.value < AddForm.d_otbbcitm.value) {
        alert("Contact time should be after check in time.");
        AddForm.alenc006.focus();
        return false;
      }
    }
  }
  return true;
}

function lookUpWC(Form) {
WCRefNoSearchFrame(Form.urnumber,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.alenc128,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,Form.dummy1,
                   Form.dummy1,Form.dummy1);
}

function WCRefNoSearchFrame(urnumber,RetEName,RetAdd1,RetAdd2,RetAdd3,
                             RetAdd4,RetPost,RetTele,RetCDat,RetAccPt,
                             RetInsCod,RetClmNo,RetComn1,RetComn2,RetAloc,
                             RetCInj,RetInjCod,RetTime,RetAclc,RetAinz,
                             RetMovv,RetSpti,RetSprt,RetReci,RetTric,
                             RetEsta,RetPddt,RetArg1,RetArg2,RetArsn,
                             RetArtl,RetArrp,RetTwrk,RetOest,RetCsta,
                             RetCName,RetCInjSel,RetInjCodSel,RetAccPtSel,
                             ptcnhdps,RetWorkRel,RetWorkRelSel,RetPlace,
                             RetPlaceSel,RetAct,RetActSel,RetDetDate,
                             RetCinj,RetAinj,RetHCPTP,RetGrad,
                             RetAhos,RetVerb,RetAppr,RetPord,
                             RetGainedBy,RetDocnam1)
 {
  var PopUpFrameDoc = DFrameStart();
  window.urnumber=urnumber;
  window.RetEName=RetEName;     window.RetAdd1=RetAdd1;
  window.RetAdd2=RetAdd2;       window.RetAdd3=RetAdd3;
  window.RetAdd4=RetAdd4;       window.RetPost=RetPost;
  window.RetTele=RetTele;       window.RetCDat=RetCDat;
  window.RetAccPt=RetAccPt;     window.RetInsCod=RetInsCod;
  window.RetClmNo=RetClmNo;     window.RetAloc=RetAloc;
  window.RetCInj=RetCInj;       window.RetInjCod=RetInjCod;
  window.RetCName=RetCName;     window.RetCInjSel=RetCInjSel;
  window.RetTime=RetTime;       window.RetAclc=RetAclc;
  window.RetAinz=RetAinz;       window.RetMovv=RetMovv;
  window.RetSpti=RetSpti;       window.RetSprt=RetSprt;
  window.RetReci=RetReci;       window.RetTric=RetTric;
  window.RetEsta=RetEsta;       window.RetPddt=RetPddt;
  window.RetArg1=RetArg1;       window.RetArg2=RetArg2;
  window.RetArsn=RetArsn;       window.RetArtl=RetArtl;
  window.RetArrp=RetArrp;       window.RetTwrk=RetTwrk;
  window.RetOest=RetOest;       window.RetCsta=RetCsta;
  window.RetCinj=RetCinj;       window.RetAinj=RetAinj;
  window.RetHCPTP=RetHCPTP;         window.RetGrad=RetGrad;
  window.RetInjCodSel=RetInjCodSel; window.RetAhos=RetAhos;
  window.RetAccPtSel=RetAccPtSel;   window.RetVerb=RetVerb;
  window.RetWorkRel=RetWorkRel;     window.RetAppr=RetAppr;
  window.RetWorkRelSel=RetWorkRelSel; window.RetPord=RetPord;
  window.ptcnhdps=ptcnhdps;            window.RetGainedBy=RetGainedBy;
  window.RetPlace=RetPlace;            window.RetDocnam1=RetDocnam1;
  window.RetPlaceSel=RetPlaceSel;
  window.RetAct=RetAct;
  window.RetActSel=RetActSel;
  window.RetDetDate=RetDetDate;
  PopUpFrameDoc.location.href = "../lookups/WCRefNoSearchFrame.html";
  SearchFrameShow();
}


function linkForm(Insuranc,Viewopts) {
   LinkUrl="patweb87.pbl?reportno=6&template=5" +
         "&insuranc=" + Insuranc.replace(/ /g,"+") +
         "&viewopts=" + Viewopts

   Left=(document.body.clientWidth-430)/2
   DFrameLink(LinkUrl,0,Left,430,300)
}

function updateParent(RetClmNo){
    parent.parent.alenc128.value=RetClmNo;
    SearchFrameExit();
    parent.parent.valDoctorUnit();
}
function valDoctorUnit(){}
function ChkSport(){}
//------------------------------------------------------------------
//  Common onLoad function called by VINAH add contact pages 
//------------------------------------------------------------------
function CommonContact(theForm) {
  if(theForm.deptlcod==undefined) return;;
  filterCP=false;
  Stream=theForm.deptlcod.value.substr(10,1);
  if(theForm.deptlcod.value.substr(10,1)=="O") {
    filterCP=true;
  }
//
  if(theForm.alcndevp!=undefined) {                    // Using event program
    if(theForm.alcndevp.value=="1") {                  // to determine program
      if(theForm.alenc079!=undefined) {                // stream 
        if(theForm.alenc079.value.substr(10,1)=="O") { // SOP
          Stream=theForm.alenc079.value.substr(10,1);
          filterCP=true;  
        } else {
          if(!isWhitespace(theForm.alenc079.value.substr(10,1))) {
            filterCP=false;
          }
        }
      }
   }
  }
//
  if(theForm.alenc080 != undefined) {
    if(filterCP== true) { // SOP
      for(var i=0;i<theForm.alenc080.length;i++) {
         HDP=trim(theForm.alenc080.options[i].value.substr(14,4));
         if(HDP != "71" && HDP != "72" && HDP !="51" && HDP !="73" && HDP !="74"
            && HDP !="" && HDP != "61" && HDP != "75" && HDP != "76") {
           theForm.alenc080.remove(i); 
           i--;
         }
      }
    } else {  // Not SOP
      for(var i=0;i<theForm.alenc080.length;i++) {
         HDP=trim(theForm.alenc080.options[i].value.substr(14,4));
         if(HDP == "61" || HDP == "72" || HDP =="73" || HDP =="74" ||
            HDP == "75" || HDP == "76") {
           theForm.alenc080.remove(i);
           i--;
         }
      }
    }  
  }
//
  if(theForm.alenc080 != undefined) {
    if(Stream == "H" || Stream == "T") { 
      for(var i=0;i<theForm.alenc080.length;i++) {
         HDP=trim(theForm.alenc080.options[i].value.substr(14,4));
         if(HDP == "51") {
           theForm.alenc080.remove(i);
           i--;
         }
      }
    }
  }
//
  if(theForm.alenc080 != undefined) {
    if(Stream!="P") {  // Not Palliative Care
      if(theForm.alenc080 != undefined) {
        filterCatCodeList(theForm.alenc080,"1","P","1");
        filterCatCodeList(theForm.alenc080,"1","H","1");
      }
    }
  }
//
  filterNDISContact(theForm);
  filterNDISContactCL(theForm);

  if(theForm.alenc086!=undefined) {
    program=theForm.deptlcod.value.substr(10,1);
    if(program=="T") {
      filterCatCodeList(theForm.alenc086,"1","T","2");
    }
    else {
      filterCatCodeList(theForm.alenc086,"1","T","1");
    }    
  }
//
  HCPNonMandIT(theForm);                  // Call to make HCP non-mand for IT

  if(theForm.alenc080 != undefined) {
    sortSelectionList(theForm.alenc080);  // Sort Contact purpose Long Desc list
  }
}
function HCPNonMandIT(theForm) {
// By default make Health care Provider mandatory, if IT then make Non-mand
  if(theForm.HCP_NonMandIT!=undefined) {
  document.getElementById("HealthCareProvF").innerHTML=
  document.getElementById("ShowHealthCareProv").innerHTML;
  }
// check if Program=IT then make HCP not readonly.
// EventProgram value takes precedence over Dept value.
// If  EventProgram = IT then make HCP not readonly else readonly. 
  program=theForm.deptlcod.value.substr(10,1);
  
  if(theForm.alcndevp!=undefined) {                    // Using event program
     if(theForm.alcndevp.value=="1") {                  // to determine program
        if(theForm.alenc079!=undefined) {                // stream
           if(!isWhitespace(theForm.alenc079.value.substr(10,1))) {
              program=theForm.alenc079.value.substr(10,1); 
           }
        }
     }
  }

  if(program=="F")  {
     // apply non-mandatory HCP for templates on present:HCP_NonMandIT.
     if(theForm.HCP_NonMandIT!=undefined) {
        // hide read only hcp and show srerach HCP
        document.getElementById("HealthCareProvF").innerHTML=
        document.getElementById("ShowHealthCareProvIT").innerHTML;
     } else {
        theForm.alenc004.className="";
        theForm.alenc004.readOnly=false
        theForm.alenc004.value="";
        theForm.SProvider.value="";
     }
  } else {
     // apply Mandatory HCP for templates on present:HCP_MandIT.
     if(theForm.HCP_MandIT!=undefined) {
         theForm.alenc004.className="Mandatory SelectMed";
         theForm.alenc004.disabled=false;
     }
  } 
}
function filterNDISContact(theForm) {
  if(theForm.deptlcod==undefined) return;;       // Department
  if(theForm.alenc115==undefined) return;;       // Claim Code

  removeNDIS=false;

  program=theForm.deptlcod.value.substr(10,1);
  if(program != "I" && program != "A" && program != "R" && program != "S" &&
     program != "E" && program != "L" && program != "D" && program != "V" &&
     program != "C") {
    removeNDIS=true;      // Not HARP or PAC or RIR or SACS HEN TPN HBD VALP EPC
  }

  if(removeNDIS==true) {     // Remove NDIS claim code ind 12 = D
    filterCatCodeList(theForm.alenc115,"12","D","1");
  }
}
//---------------------------------------------------------------------------
//  Common Event Program onChange function called by VINAH add contact pages
//---------------------------------------------------------------------------
function filterContactPurpose(theForm) {
  if(theForm.alcndevp==undefined) return;;            // Using event program  
  if(theForm.alcndevp.value!="1") return;;            // to determine program 
                                                      // stream
  if(theForm.alenc079==undefined) return;;            
 
  if(theForm.deptlcod==undefined) return;;

  if(theForm.CATEG_zH==undefined) return;;
  
  filterCP=false;

  if(theForm.deptlcod.value.substr(10,1)=="O") {
    filterCP=true;
  }

  if(theForm.alenc079.value.substr(10,1)=="O") {
    filterCP=true;
  } else {
    if(!isWhitespace(theForm.alenc079.value.substr(10,1))) {
        filterCP=false;
    }
  }
  saveCP=theForm.alenc080.value.substr(0,3);
  theForm.alenc080.length=1;
  selectOptions6("15",theForm.CATEG_zH,theForm.alenc080);
  if(filterCP== true) {      // SOP Event Program
     for(var i=0;i<theForm.alenc080.length;i++) {
        HDP=trim(theForm.alenc080.options[i].value.substr(14,4));
        if(HDP != "71" && HDP != "72" && HDP != "51" && HDP !="73" && HDP !="74"
           && HDP !="75" && HDP !="76" && HDP !="") {
          theForm.alenc080.remove(i);
          i--;
        }
     }
  } else {  // Not SOP
      for(var i=0;i<theForm.alenc080.length;i++) {
         HDP=trim(theForm.alenc080.options[i].value.substr(14,4));
         if(HDP == "61" || HDP == "72" || HDP =="73" || HDP =="74" ||
            HDP == "75" || HDP == "76") {
           theForm.alenc080.remove(i);
           i--;
         }
      }
    }
//
 for (var i=0; i < theForm.alenc080.length; i++) {             
  if (theForm.alenc080.options[i].value.substr(0,3)==saveCP){
      theForm.alenc080.selectedIndex=i;
  }
 }
}

function ListOptionsCatLD(theDept,theField){

  if(theDept==undefined) return;;

  if(theDept.value.substr(6,1)=="M") { // Mental Health
    filterCatCodeList(theField,"3","G","1"); // Exclude from MH
  } else {
    filterCatCodeList(theField,"3","M","1"); // Remove MH options
  }
}

function filterNDISContactCL(theForm) {
  if(theForm.deptlcod==undefined) return;;       // Department
  if(theForm.alenc115==undefined) return;;       // Claim Code
  if(theForm.CATEG_CL==undefined) return;;

  removeNDIS=false;

  program=theForm.deptlcod.value.substr(10,1);
  if(program != "I" && program != "A" && program != "R" && program != "S" &&
     program != "E" && program != "L" && program != "V" && program != "C") {
    removeNDIS=true;         // Not HARP or PAC or RIR or SACS VALP EPC
  }

  if(theForm.alcndevp!=undefined) {                    // Using event program
    if(theForm.alcndevp.value=="1") {                  // to determine program
      if(theForm.alenc079!=undefined) {                // stream
        program=theForm.alenc079.value.substr(10,1);
        if(program == "I" || program == "A" || program == "R" ||
           program == "S" || program == "E" || program == "L" ||
           program == "D" || program == "V" || program == "C") {
           removeNDIS=false;     // HARP PAC or RIR or SACS HEN TPN HBD VALP EPC
        } else {
           if(!isWhitespace(program)) {
             removeNDIS=true;
           }
        }
      }
    }
  }
  saveCL=theForm.alenc115.value.substr(0,3);
  theForm.alenc115.length=1
  selectOptions3("15",theForm.CATEG_CL,theForm.alenc115);

  filterCatCodeList(theForm.alenc115,"10","X","1");

  if(removeNDIS==true) {     // Remove NDIS claim code ind 12 = D
    filterCatCodeList(theForm.alenc115,"12","D","1");
  }
 for (var i=0; i < theForm.alenc115.length; i++) {
  if (theForm.alenc115.options[i].value.substr(0,3)==saveCL){
      theForm.alenc115.selectedIndex=i;
  }
 }
}
//------------------------------------------------------------------
//  Get default CMBS item for slot (from default charges table)
//------------------------------------------------------------------
function DefaultCMBSItemEnc(ReturnVist,ReturnSlot,ReturnRefr) {
  ReturnFunction="" ;
  for (var i=2; i < DefaultCMBSItemEnc.arguments.length; i++) {
    if (typeof(DefaultCMBSItemEnc.arguments[i]) == 'function') {
      ReturnFunction=DefaultCMBSItemEnc.arguments[i] }
    else {
      DefaultCMBSItemEnc.arguments[i].value=""; }  }
  if (isWhitespace(ReturnVist.value)) return;;
  if (isWhitespace(ReturnSlot.value)) return;;

  var serverURL ="../cgi-bin/allweb02.pbl?reportno=5" +
                    "&visittyp=" + ReturnVist.value.replace(/ /g,"+") +
                    "&nslotkey=" + ReturnSlot.value.replace(/ /g,"+") 
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|");
    if(isWhitespace(ReturnValue[1])) {
      return;
    }
//  AddForm.otbit001.value=ReturnValue[0];
    AddForm.itemn001.value=ReturnValue[1];
    validatePMBS(AddForm.itemn001,AddForm.dummy);
//  AddForm.otbit003.value=ReturnValue[2];
//  AddForm.mbsdesc1.value=ReturnValue[3];
//  AddForm.mbsamnt1.value=ReturnValue[4];
//  AddForm.otbit016.value=ReturnValue[5];
//
  }
}
function CalcDirectUnitStartDate(theForm) {
  if(!checkDate(theForm.alenc005,theForm.alenc005.title)) {return;}

  var eunit = theForm.alend011

  CalcDirectUnit(theForm.alenc005,
                 theForm.alenc006,
                 theForm.alenc017,
                 theForm.alenc018,
                 eunit,
                 "1") ;
}
function CalcDirectUnitEndDate(theForm) {
  if(!checkDate(theForm.alenc017,theForm.alenc017.title)) {return;}

  var eunit = theForm.alenc011

  CalcDirectUnit(theForm.alenc005,
                 theForm.alenc006,
                 theForm.alenc017,
                 theForm.alenc018,
                 eunit,
                 "2") ;
}
function CalcDirectUnitStartTime(theForm) {
  if(!checkTime(theForm.alenc006,theForm.alenc006.title)) {return;}

  var eunit = theForm.alenc011

  CalcDirectUnit(theForm.alenc005,
                 theForm.alenc006,
                 theForm.alenc017,
                 theForm.alenc018,
                 eunit,
                 "3") ;
}
function CalcDirectUnitEndTime(theForm) {
  if(!checkTime(theForm.alenc018,theForm.alenc018.title)) {return;}

  var eunit = theForm.alenc011

  CalcDirectUnit(theForm.alenc005,
                 theForm.alenc006,
                 theForm.alenc017,
                 theForm.alenc018,
                 eunit,
                 "4") ;
}
function CalcDirectUnit(alenc005,alenc006,alenc017,alenc018,alenc011,calctype) {
  if (alenc011==undefined) {return;}
  if (alenc005==undefined) {return;}
  if (alenc006==undefined) {return;}
  if (alenc017==undefined) {return;}
  if (alenc018==undefined) {return;}
  if (isWhitespace(alenc005.value)) {return;}
  if (isWhitespace(alenc006.value)) {
    alenc011.value = "";  
    return;
  }
  if (isWhitespace(alenc017.value)) {return;}
  if (isWhitespace(alenc018.value)) {
    alenc011.value = "";  
    return;
  }

  if(!CheckDateTimeRange(alenc005,
                         alenc006,
                         alenc017,
                         alenc018)) {
    alenc018.value = "";
    alenc011.value = "";
    alert('Contact Start Date/Time cannot be after Contact End Date/Time');
    return;
  }
  CalculateDuration(alenc005,alenc006,alenc017,alenc018,alenc011) ;
  alenc011.className="Mandatory DefaultBlank";
  if(!checkInteger(alenc011,alenc011.title)) {return;}
    alenc011.min=1;
    if(isFinite(alenc011.min)) {
    if (parseInt(alenc011.value,10)<parseInt(alenc011.min,10)) {
      alert( "Direct Units cannot equal zero.\nPlease check the" +
            " Contact Start and End Times.");
       alenc011.min="";
       alenc011.value="";
       alenc011.focus();
       return;
    }
  }
  alenc011.min="";
}

function CalcContactEndDateTime(theForm) {
  theForm.alenc011.className="Mandatory DefaultBlank";
  if(!checkInteger(theForm.alenc011,theForm.alenc011.title)) {return;}
    theForm.alenc011.min=1;
    if(isFinite(theForm.alenc011.min)) {
    if (parseInt(theForm.alenc011.value,10)<parseInt(theForm.alenc011.min,10)) {
      alert( "Direct Units cannot equal zero.\nPlease check the" +
            " Contact Start and End Times.");
       theForm.alenc011.min="";
       theForm.alenc011.value="";
       theForm.alenc011.focus();
       return;
    }
  }
  theForm.alenc011.min="";

  AddSubtractMinute(theForm.alenc005,
                    theForm.alenc006,
                    theForm.alenc011,
                    "A",
                    theForm.alenc017,
                    theForm.alenc018) ;
}
function DefaultContactEndTime() {
  if(document.AddForm.deptlcod==undefined) {
    return;
  }
  if(document.AddForm.d_currtime==undefined) {
    return;
  }
  if(document.AddForm.d_duration==undefined) {
    return;
  }
  ind=document.AddForm.deptlcod.value.substr(69,1);  // Ind 22
  if(ind=="C") { // Current Time
    document.AddForm.alenc018.value = document.AddForm.d_currtime.value;
  }
  if(ind=="S") { // Slot Time Plus Slot Duration
    if(!isWhitespace(document.AddForm.d_duration.value)) {
      f=document.AddForm;
      AddSubtractMinute(f.alenc005,f.alenc006,f.d_duration,"A",
                      f.alenc017,f.alenc018) ;
      if(f.alenc005.value != f.alenc017.value) { // Over midnight
         f.alenc017.value = f.alenc005.value;
         f.alenc018.value = "";
      }
    }
  }
}
//Show/Hide Family/Whanau Involved field
function ShowFamWhanau(theForm) {
  var ind3 = theForm.deptlcod.value.substr(5,1);
  var ind4 = theForm.deptlcod.value.substr(6,1);

  if(ind3=="A" && ind4=="M"){  // MH department
    FamWhanau.style.display="";
    FamWhanau.innerHTML=DisFamWhanau.innerHTML;
    FamWhanauSelect.innerHTML=DisFamWhanauSelect.innerHTML;

    // Set default value if available
    if (isWhitespace(theForm.alenc043.value)){
        switch(DefaultFamilyWhanauInvolved){
          case "No":
            document.getElementById("n_alenc043").checked=true;
            break;
          case "Yes":
            document.getElementById("y_alenc043").checked=true;
            break;
          default:
            document.getElementById("n_alenc043").checked=false;
            document.getElementById("y_alenc043").checked=false;
            break;
        }
    }
    return true;
  }
  else {
    FamWhanau.innerHTML="";
    FamWhanau.style.display="none";
    return false;
  }
}
function checkContactPurposeEnc(theForm) {
  if(theForm.alenc080 == undefined || theForm.alenc083 == undefined
     || theForm.alenc081 == undefined) {
    return true;
  }

  var VINAH_ref = "";
  if(theForm.deptlcod != undefined ) {
     VINAH_ref = theForm.deptlcod.value.substr(10,1);
  }

  if(VINAH_ref == "E" || VINAH_ref == "L" || VINAH_ref == "D") {
    return true;  // HEN, TPN or HBD
  }

  if (theForm.alenc080.value.substr(14,2) == '51') {
    if (theForm.alenc083.value.substr(14,2) != '31') {
      var contactPurpose = getSelectionText(theForm.alenc080, '51');
      var presentStatus = getSelectionText(theForm.alenc083, '31');
      alert("Error: Contact Purpose is " + contactPurpose +
        ", Client Present Status must be " + presentStatus + ".");
      theForm.alenc084.focus();
      return false;
    } else {
      if (theForm.alenc081.value.substr(14,1) != '3') {
        var contactPurpose = getSelectionText(theForm.alenc080, '51');
        var presentStatus = getSelectionText(theForm.alenc083, '31');
        var sessionType = getSelectionText(theForm.alenc081, '3');
        alert("Error: Contact Purpose is " + contactPurpose +
          ", Client Present Status is " + presentStatus + 
          ", Contact Session Type must be " + sessionType + ".");
        theForm.alenc081.focus();
        return false;
      }
    }
  }
  return true;
}

// Check Client Present Status validations for Patient DNA & 
// Contact Purpose is MDCC No Patient
function CheckPresentStatus(theForm) {
 if(theForm.alenc080 == undefined || theForm.alenc083 == undefined
     || theForm.alenc081 == undefined || theForm.alenc084 == undefined
     || theForm.alenc086 == undefined) {
    return true;
 }
 Stream="";
 if(theForm.deptlcod==undefined) {
  Stream=theForm.deptlcod.value.substr(10,1);
 }
  Stream=theForm.deptlcod.value.substr(10,1);
 // alert for HBPCCT Contact when Session type is empty
 if(Stream == "H") {
   if(isWhitespace(theForm.alenc081.value)) {
     alert("Session type is required for Client Present Status");
     FocusDelay(theForm.alenc081);
     return false; 
   }
 }
 // check for Client Present Status for Patient DNA
 if(theForm.alenc083.value.substr(14,2) == '32') {
    if(theForm.alenc084.value.substr(14,1) != '9' || 
      theForm.alenc086.value.substr(14,2) != '98' ||
      theForm.alenc081.value.substr(14,1) == '3' ||
      (Stream != "H" && theForm.alenc080.value.substr(14,2) == '51')) {
      var presentstatusDNA = theForm.alenc083.options
      [theForm.alenc083.selectedIndex].text;
      alert("Contact data is not compatible with Client Present Status of " + 
      presentstatusDNA + ".");
      FocusDelay(theForm.alenc083);
      return false;
    }
 }
// Check if Contact Purpose is MDCC No Patient
  if(theForm.alenc080.value.substr(14,2) == '51') {
    if(theForm.alenc083.value.substr(14,2) != '31' ||
       theForm.alenc084.value.substr(14,1) != '9' ||
       theForm.alenc086.value.substr(14,2) != '98' ||
       theForm.alenc081.value.substr(14,1) != '3') {
       var contactPurpose = theForm.alenc080.options
       [theForm.alenc080.selectedIndex].text;
       alert("Contact data is not compatible with Contact Purpose of " +
       contactPurpose + ".");
       FocusDelay(theForm.alenc080);
       return false;
    }
  }
 return true;
}

//Check Delivery Mode is Delivery Mode is Face to Face, Telephone
//Telehealth,Written, Electronic Mail, SMS Text Messages
function CheckDeliveryMode(theForm) {
 if(theForm.alenc080 == undefined || theForm.alenc083 == undefined
     || theForm.alenc081 == undefined || theForm.alenc084 == undefined
     || theForm.alenc086 == undefined) {
    return true;
 }
 Stream="";
 if(theForm.deptlcod==undefined) {
  Stream=theForm.deptlcod.value.substr(10,1);
 }
  Stream=theForm.deptlcod.value.substr(10,1);
 // alert for HBPCCT Contact when Session type is empty
  if(Stream == "H"){
   if(isWhitespace(theForm.alenc081.value)) {
     alert("Session type is required for Client Present Status");
     FocusDelay(theForm.alenc081);
     return false;
   }
  }
 // check for Delivery Mode to be either of 1/2/3/4/5/8
 // contact purpose not, case conference, case managagement or MDCC no patient
 if(theForm.alenc084.value.substr(14,1) == '1' ||
    theForm.alenc084.value.substr(14,1) == '2' ||
    theForm.alenc084.value.substr(14,1) == '3' ||
    theForm.alenc084.value.substr(14,1) == '4' ||
    theForm.alenc084.value.substr(14,1) == '5' ||
    theForm.alenc084.value.substr(14,1) == '8') {
    if(theForm.alenc080.value.substr(14,2) == '41' ||
       theForm.alenc080.value.substr(14,2) == '42' ||
       theForm.alenc080.value.substr(14,2) == '51') {
        return true;
    }
    if(theForm.alenc086.value.substr(14,2) == '98' ||
      theForm.alenc081.value.substr(14,1) == '3' ||
      theForm.alenc083.value.substr(14,2) == '31' ||
      theForm.alenc083.value.substr(14,2) == '32') {
      var deliverymode = theForm.alenc084.options
      [theForm.alenc084.selectedIndex].text;
      alert("Contact data is not compatible with Delivery Mode of " +
      deliverymode + ".");
      FocusDelay(theForm.alenc084);
      return false;
    }
 }
 return true;
}


//Called when the Occasion of Service value is changed and checks the value
function checkWhanau() {

   var selectValue = getOccasionServiceValue();

   setWhanau(selectValue);

}

//Gets the value for the occassion of service and returns it.
function getOccasionServiceValue() {

   var selectValue = document.getElementById("alenc010").value;
   selectValue = selectValue.substr(8,12)
   selectValue = selectValue.replace(/\s/g,'');

   return selectValue;
}

//Checks the value were the Occassion for service is set and unchangeable
function getWhanauValue() {

   var selectValue = document.getElementById("occServ").value;
   selectValue = selectValue.replace(/\s/g,'');

   setWhanau(selectValue);
}

//Checks if the value passed from occassion of service is listed as setting the
//Whanau value and it will set the value and disable it.
function setWhanau(selectValue) {

   //Defines the values that set the Family/Whanau values
   var WhanauNo = getWhanauNo();
   var WhanauYes = getWhanauYes();
   var whanauSelectValue = document.getElementById("DisFamWhanauSelect");

   //Sets the values of Family/Whanau
   if (whanauSelectValue != null) {
     if (inArray(WhanauNo,selectValue)) {
        document.getElementById("n_alenc043").checked=true;
        document.getElementById("y_alenc043").checked=false;
     } else if (inArray(WhanauYes,selectValue)) {
        document.getElementById("n_alenc043").checked=false;
        document.getElementById("y_alenc043").checked=true;
     } else {
        document.getElementById("n_alenc043").disabled=false;
        document.getElementById("y_alenc043").disabled=false;
     }
   }
}

//Validates Family/Whanau when form is submitted
function confirmWhanau() {

  var selectValue = getOccasionServiceValue();
  var WhanauNo = getWhanauNo();
  var WhanauYes = getWhanauYes();

  //Checks if the Occassion of Service must have a Family/Whanau of No
  //And confirms if Family/Whanau is no
  if (inArray(WhanauNo,selectValue)) {
     if (document.getElementById("y_alenc043").checked == true) {
       alert("Family/Whanau involved must be No");
       return false;
     }

  //Checks if the Occassion of Service must have a Family/Whanau of Yes
  //and confirms if it is yes.
  } else if (inArray(WhanauYes,selectValue)) {
     if (document.getElementById("n_alenc043").checked == true) {
       alert("Family/Whanau involved must be Yes");
       return false;
     }
  }

  return true;
}

//Function that scans an array to determine if it contains the element.
//Returns true if it does, otherwise returns false.
function inArray(arrayString, element) {

  for (x =0; x<arrayString.length;x++) {
    if (arrayString[x] == element) {
       return true;
    }
  }
  return false;
}


// when Delivery Mode(alenc084) = 9  Not Applicable
//  Client Present Status(alenc083) must be 32 - DNA
//  except when  Contact Purpose(alenc080) = 51 MDCC No Patient
function checkDeliveryModeClientPresentStatus(theForm) {
  Stream="";
  if(theForm.deptlcod==undefined) {
     Stream=theForm.deptlcod.value.substr(10,1);
  }
  Stream=theForm.deptlcod.value.substr(10,1); 
  if (theForm.alenc084.value.substr(14,1) == '9') { // Not Applicable
       var delMode  = theForm.alenc084.value.substr(14,1)
    if ((Stream != "H" && theForm.alenc080.value.substr(14,2) != '51')) {
         var conPurp  = theForm.alenc080.value.substr(14,2)
         var presSt   = theForm.alenc083.value.substr(14,2)
      if (theForm.alenc083.value.substr(14,2) != '32') { // DNA

           var deliveryMode   = getSelectionText(theForm.alenc084, delMode);
           var contactPurpose = getSelectionText(theForm.alenc080, conPurp);
           var presentStatus = getSelectionText(theForm.alenc083, presSt);

           var catzLLongDesc = document.getElementById('CATEG_zL').value;
           
           alert("Error : Contact Delivery Mode" + " - " + trim(deliveryMode) +
                   ", not compatible with Contact Client Present Status " + 
                 presentStatus + " or Contact Purpose " + 
                 trim(contactPurpose));
            FocusDelay(theForm.alenc084);
            return false;
      }
    }
    return true;
   }
   return true;
}

function NDISRedirect() {

   NDISAlert = "Warning: NDIS Participant selected -\n"
   NDISAlert += "Please enter NDIS Identifier Number in Concession"
   NDISAlert += " Cards Maintenance"

   alert(NDISAlert);

}
function CheckContactCurrentIP(ur,contdate,conttime,currip) {
  if (isWhitespace(ur.value) || isWhitespace(contdate.value) ||
      isWhitespace(conttime.value)) {
   return;
  }
  var serverURL = "../cgi-bin/allweb02.pbl?reportno=6&updatety=C" +
                  "&urnumber=" + ur.value.replace(/ /g,"+") +
                  "&valddate=" + contdate.value.replace(/ /g,"+") +
                  "&valdtime=" + conttime.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  ReturnValue=returnValue.return_value.split("|");
  if (returnValue.status==0) {
      currip.value=ReturnValue[0];
  }
}

function checkDeliverySettingIP(InpFlag,DelSetting) {
 if(DelSetting == undefined) {
  return true;
 }
 if(DelSetting.value.substr(4,1) == 'O') {
  InpFlag.value = '1'; // Inpatient at other hospital
 }
 if(DelSetting.value.substr(14,2) == '11') {
    if(InpFlag.value != '1') {
    alert("Contact Delivery Setting is '11 - Inpatient Setting' but " +
          "Contact Inpatient Flag is not 'I - Yes(Inpatient/Admitted)'. \n" +
          "Please correct Contact Delivery Setting.");
     return false;
   }
 }
 return true;
}
function DefaultClientPresentStatusDNA() {
  for (var i =0 ; i < document.AddForm.alenc083.length; i++) {
   if (document.AddForm.alenc083.options[i].value.substr(14,2) == "32") {
      document.AddForm.alenc083.selectedIndex=i }
  }
}
function CheckClientPresentStatusDNA(theForm) {
 // if bulk contact & DNA check box is checked, Client Present status has to be DNA
 var BulkDNA = false;
 if(parent.document.getElementById("dnasonly")) {
    if(parent.document.getElementById("dnasonly").checked==true) {
    BulkDNA = true;
    }
 } 

 // if patient is not admitted = "5" OR if it is Bulk Contact
 // then Client Present status has to be DNA
 
 if(theForm.d_obastat.value == "5" || BulkDNA == true) {
   if(!(theForm.alenc083.value.substr(14,2) == '32')) {
      var ClntPresentStat = theForm.alenc083.options
      [theForm.alenc083.selectedIndex].text;
      alert("Client Present Status of " + ClntPresentStat +
             " is not compatible with Appointment Departure Status of DNA.");
      return false;
   }
 }
 else {
      if(theForm.alenc083.value.substr(14,2) == '32') {
      var ClntPresentStat = theForm.alenc083.options
      [theForm.alenc083.selectedIndex].text;
         alert("Client Present Status of " + ClntPresentStat +
               " is not compatible with Appointment Departure Status.");
         return  false;
      }
 }
  return true;
}
