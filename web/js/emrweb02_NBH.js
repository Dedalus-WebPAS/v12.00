//jsVersion  : V12.00.01
//========================================================================
// For NBH
function PatientReturn() {
  f = document.UpdateForm

  if (f.emexp018.value == "       0") {
    f.emexp018.value = "";
  }

  detailsArray = [f.emexp002,f.emexp003,
                  f.emexp004,f.emexp005];

  validateUrMerge(8,
                  f.emexp018,
                  f.gname,
                  f.dummy,
                  f.emexp005,
                  f.deceased,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.gname,
                  f.sname,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.dummy,
                  f.selsex,
                  f.pfgname,
                  f.pfsname);

  if (f.deceased.value == "1"){
    f.emexp018.value = "";
    f.gname.value = "";
    f.emexp002.value = "";
    f.emexp003.value = "";
    f.pfgname.value = "";
    f.pfsname.value = "";
    f.selsex.value = "";
    f.emexp004.value = "";
    f.emexp005.value = "";
    ToggleDetails(f.emexp018,detailsArray);
    return false;
  }

  if (!CheckEmrVisit(f.emexp018.value,f.emvis001.value)) {
    f.emexp018.value = "";
    f.gname.value = "";
    f.emexp002.value = "";
    f.emexp003.value = "";
    f.pfgname.value = "";
    f.pfsname.value = "";
    f.selsex.value = "";
    f.emexp004.value = "";
    f.emexp005.value = "";
    ToggleDetails(f.emexp018,detailsArray);
    return;
  }

  f.emexp002.value=f.gname.value.replace(/,/g,"");
  f.emexp003.value=f.sname.value.replace(/,/g,"");

  var ptcnnmpr = f.ptcnnmpr.value;
  if (ptcnnmpr == "3" && !isWhitespace(f.emexp018.value)) {
    document.getElementById('PrefNamesBoth').style.display="";
    document.getElementById('PrefNamesSurname').style.display="none";
    document.getElementById('PrefNamesGiven').style.display="none";
    document.getElementById('pmpxi83b').value=
      f.pfgname.value.replace(/,/g,"");
    document.getElementById('pmpxi82b').value=
      f.pfsname.value.replace(/,/g,"");
  } else if (ptcnnmpr=="0" || isWhitespace(f.emexp018.value)) {
    document.getElementById('PrefNamesBoth').style.display="none";
    document.getElementById('PrefNamesSurname').style.display="none";
    document.getElementById('PrefNamesGiven').style.display="none";
  } else if (ptcnnmpr=="1" && !isWhitespace(f.emexp018.value)) {
    document.getElementById('PrefNamesBoth').style.display="none";
    document.getElementById('PrefNamesSurname').style.display="none";
    document.getElementById('PrefNamesGiven').style.display="";
    document.getElementById('pmpxi83g').value=
      f.pfgname.value.replace(/,/g,"");
  } else {
    document.getElementById('PrefNamesBoth').style.display="none";
    document.getElementById('PrefNamesSurname').style.display="";
    document.getElementById('PrefNamesGiven').style.display="none";
    document.getElementById('pmpxi82s').value=
      f.pfsname.value.replace(/,/g,"");
  }

  dispsex();
  ToggleDetails(f.emexp018,detailsArray);
  return true;
}
//-----------------------------------------------------------------
// Function to check for expected patients with the same name or ur
//-----------------------------------------------------------------
function checkExpectedPatNBH(urnum) {
  f = document.UpdateForm;
  if (isWhitespace(urnum)) return false;;
  var serverURL = "../cgi-bin/emrweb08.pbl?reportno=16" +
                  "&valdcode="+urnum.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|")

    if (!isWhitespace(ReturnValue[0])) {
      if(confirm("Possible Expected Patient Match.\n" +
                 "U/R - \t\t" + ReturnValue[1].replace(/ /g,"") + "\n" +
                 "Surname - \t" + ReturnValue[2] + "\n" +
                 "Given Name - \t" + ReturnValue[3] + "\n" +
                 "Select OK to register U/R - " + urnum.replace(/ /g,"")  +
                 " using Expected Patient details \n" +
                 "Select Cancel to continue with this registration.")) {
         // Unique no
         if (f.emexp001 != undefined) {
           f.emexp001.value = ReturnValue[0]
         } 
         // U/R No.
         if (f.emexp018 != undefined) {
           f.emexp018.value = ReturnValue[1]
         }
         // Location
         if (f.emvis006 != undefined) {
           f.emvis006.value = ReturnValue[4]
           f.emvis006.focus();
           f.emvis006.blur();
         } 
         // Attendance source
         if (f.emvis061 != undefined) {
           if(!isWhitespace(ReturnValue[5])) {
             for (var i=0; i < f.emvis061.length; i++) {
               if (f.emvis061.options[i].value == 
                   ReturnValue[5]) {
                 f.emvis061.selectedIndex=i;
               }
             }
           }
         }
         // Amb Case no
         if (f.emvis034 != undefined) {
           if(!isWhitespace(ReturnValue[6])) {
             f.emvis034.value=ReturnValue[6]
           }
         }
         // Flag to default presenting complaint
         if (f.pcomdeft != undefined) {
           f.pcomdeft.value = "1";
         }
         // Presenting Complaint Code
         if (f.emexp007 !=undefined) {
           if(!isWhitespace(ReturnValue[7])) {
             f.emexp007.value = ReturnValue[7]
           }
         }
         // Presenting Complaint Line 1
         if (f.emexp008 != undefined) {
           if(!isWhitespace(ReturnValue[8])) {
             f.emexp008.value = ReturnValue[8]
           }
         }
         // Presenting Complaint Line 2
         if (f.emexp009 != undefined) {
           if (!isWhitespace(ReturnValue[9])) {
             f.emexp009.value = ReturnValue[9]
           }
         }
         // Presenting Complaint Line 3
         if (f.emexp010 != undefined) {
           if (!isWhitespace(ReturnValue[10])) {
             f.emexp010.value = ReturnValue[10]
           }
         } 
         // Presenting Complaint Line 4
         if (f.emexp011 != undefined) {
           if (!isWhitespace(ReturnValue[11])) {
             f.emexp011.value = ReturnValue[11]
           }
         } 
         // Presenting Complaint Line 5
         if (f.emexp012 != undefined) {
           if (!isWhitespace(ReturnValue[12])) {
             f.emexp012.value = ReturnValue[12]
           }
         } 
         // Presenting Complaint Line 6
         if (f.emexp013 != undefined) {
           if (!isWhitespace(ReturnValue[13])) {
             f.emexp013.value = ReturnValue[13]
           }
         }
 
         return true;
      }
    }
  }
  return false;
}
