//jsVersion  : V12.00.00
//========================================================================
// Program   : mrtweb0118.js
//
// Function  : Standard Functions Used in mrtweb0118 templates
//
//========================================================================
OutputArray = new Array();  // Create Array to Store Rows of Table
OldArray = new Array();  // Create Array to Store Rows of Table
var MKey="";

function SetLinks() 
{
  var lnkadmis = parent.document.getElementsByName('lnkadmis');
  for (var i = 0; i < lnkadmis.length; i++) 
  {
    if (lnkadmis[i].checked == true)  RemoveTable(lnkadmis[i].value);
  }
}

function RemoveTable(ReturnCode) {
  var MKey="";
  var Flag=0;
  OldArray=OutputArray
  OutputArray = new Array();  // Create Array to Store Rows of Table
  j=0;
  for (i=0;i<OldArray.length;i++) {
    x = ReturnCode.substring(0,20)
    y = OldArray[i].substring(40,60)
    if (x!=y) {
      OutputArray[j]=OldArray[i]
      j++
    }
    else {
      Flag="1"
    }
  }
  if (Flag == "1") {
    OutputDivision()
  }
  else {
    AddOutputArray(ReturnCode)
    OutputDivision()
  }
}
function OutputDivision() {
    OutputString=""
    for (i=0; i<OutputArray.length; i++) {
      OutputString+=OutputArray[i]
    }
    Results.innerHTML=OutputString
}
function AddOutputArray(MKey) {
    OutputArray[OutputArray.length] = "<input type=hidden name=lnkadmis" +
                                      " value='" + MKey + "'>"
}

function AddLinks(actionValue) {

  mrtvols = document.getElementsByName('medrecky');
  mrtvolno = document.getElementsByName('mrtvolno');
  marked = false;
  concurrent = true;
  previousMrtVol = 0;
  volNo = 0;
  oversix = false;

  for (var i=0;i<mrtvols.length;i++) {
    
    if (mrtvols[i].checked==true) {
      marked = true;

      if ((previousMrtVol !=0) &&
         (previousMrtVol-1 != (parseInt(mrtvolno[i].innerHTML)))) {
         concurrent = false;
      }
      previousMrtVol = (parseInt(mrtvolno[i].innerHTML));

      if (volNo == 0) {
        document.getElementById("medrecky").value = mrtvols[i].value;
        volNo +=1;
      } else if (volNo <6) {
        document.getElementById("medrcky"+volNo).value = mrtvols[i].value;
        volNo +=1;
      } else {
         mrtvols[i].checked = false;
         oversix = true;
      }
    }
  }

  if(marked==false) {
    alert("Please select a medical record to link");
    return;
  }

  //Are the medical records concurrent
  if (concurrent == false) {
    response = "Place ensure the volumes selected are correct. Volume \n";
    response += "numbers should be consecutive.\n\nPress OK to continue";
    response += "\n\nPress Cancel to return";

    if(!confirm(response)){
      return;
    }
  }

  SetLinks();
  if(isWhitespace(Results.innerHTML)) {
    alert("Please select a visit before linking medical records");
    return;
  }

  if (oversix) {
     alert("Only six volumes can be linked.\nExtra volumes will not be added.")
  }

  setFormactn(actionValue);
}
