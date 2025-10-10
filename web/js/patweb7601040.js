//jsVersion  : V12.00.00

//========================================================================
// Program   : patweb7601040.js
//  
// Written   : 15.02.2008 J.Tan
//  
// Function  : Standard Functions for patweb7601040.html
//      
//========================================================================

function init() {
  InitPostCodes();
  document.getElementById('repoption').innerHTML=document.getElementById('URSpan').innerHTML;
}

function SubmitForm1() {
  // disable button to avoid double clicking
  DisButton();

  if (validateMandatory(UpdateForm))
  {
   document.UpdateForm.nextpage.value="1"
  if (UpdateForm.reptoptn.value==1){
   document.UpdateForm.redirect.value="patweb76.pbl?reportno=01&template=35" +
       "&urnumber=" +document.UpdateForm.urnumber.value.replace(/ /g,"+")
//       "&admissno=" +document.UpdateForm.admissno.value.replace(/ /g,"+")
  } else {
   document.UpdateForm.redirect.value="patweb76.pbl?reportno=01&template=41" +
       "&urnumber=" +document.UpdateForm.urnumber.value.replace(/ /g,"+")
//       "&admissno=" +document.UpdateForm.admissno.value.replace(/ /g,"+")
  }

  if(document.UpdateForm.d_pmsfd029!=undefined) {
    if(document.UpdateForm.d_pmsfd029.checked==true) {
       document.UpdateForm.pmsfd029.value="1";
    } else {
       document.UpdateForm.pmsfd029.value="0";
    }
  }

  if (document.UpdateForm.d_pmsfd030!=undefined) {
   if(document.UpdateForm.d_pmsfd030.checked==true) {
      document.UpdateForm.pmsfd030.value="1";
   } else {
      document.UpdateForm.pmsfd030.value="0";
   }
  }

  if (document.UpdateForm.pmsfd003!=undefined) {
     document.UpdateForm.expcdlos.value=document.UpdateForm.pmsfd003.value;
  }

     document.UpdateForm.gstapl01.disabled=false;
     document.UpdateForm.gstapl02.disabled=false;
     document.UpdateForm.gstapl03.disabled=false;
     document.UpdateForm.gstapl04.disabled=false;
     document.UpdateForm.gstapl05.disabled=false;
     document.UpdateForm.gstapl06.disabled=false;

     document.UpdateForm.gstcod01.disabled=false;
     document.UpdateForm.gstcod02.disabled=false;
     document.UpdateForm.gstcod03.disabled=false;
     document.UpdateForm.gstcod04.disabled=false;
     document.UpdateForm.gstcod05.disabled=false;
     document.UpdateForm.gstcod06.disabled=false;

  if ((document.UpdateForm.mbsbox1 != undefined) &&
      (document.UpdateForm.mbsbox1.checked == true)) {
     document.UpdateForm.gstapl07.disabled=false;
     document.UpdateForm.gstapl08.disabled=false;
     document.UpdateForm.gstapl09.disabled=false;
     document.UpdateForm.gstapl10.disabled=false;
     document.UpdateForm.gstapl11.disabled=false;
     document.UpdateForm.gstapl12.disabled=false;

     document.UpdateForm.gstcod07.disabled=false;
     document.UpdateForm.gstcod08.disabled=false;
     document.UpdateForm.gstcod09.disabled=false;
     document.UpdateForm.gstcod10.disabled=false;
     document.UpdateForm.gstcod11.disabled=false;
     document.UpdateForm.gstcod12.disabled=false;
  }

  if ((document.UpdateForm.mbsbox2 != undefined) &&
      (document.UpdateForm.mbsbox2.checked == true)) {
     document.UpdateForm.gstapl13.disabled=false;
     document.UpdateForm.gstapl14.disabled=false;
     document.UpdateForm.gstapl15.disabled=false;
     document.UpdateForm.gstapl16.disabled=false;
     document.UpdateForm.gstapl17.disabled=false;
     document.UpdateForm.gstapl18.disabled=false;

     document.UpdateForm.gstcod13.disabled=false;
     document.UpdateForm.gstcod14.disabled=false;
     document.UpdateForm.gstcod15.disabled=false;
     document.UpdateForm.gstcod16.disabled=false;
     document.UpdateForm.gstcod17.disabled=false;
     document.UpdateForm.gstcod18.disabled=false;
  }

  if ((document.UpdateForm.mbsbox3 != undefined) &&
      (document.UpdateForm.mbsbox3.checked == true)) {
     document.UpdateForm.gstapl19.disabled=false;
     document.UpdateForm.gstapl20.disabled=false;
     document.UpdateForm.gstapl21.disabled=false;
     document.UpdateForm.gstapl22.disabled=false;
     document.UpdateForm.gstapl23.disabled=false;
     document.UpdateForm.gstapl24.disabled=false;

     document.UpdateForm.gstcod19.disabled=false;
     document.UpdateForm.gstcod20.disabled=false;
     document.UpdateForm.gstcod21.disabled=false;
     document.UpdateForm.gstcod22.disabled=false;
     document.UpdateForm.gstcod23.disabled=false;
     document.UpdateForm.gstcod24.disabled=false;
  }

  if ((document.UpdateForm.mbsbox4 != undefined) &&
      (document.UpdateForm.mbsbox4.checked == true)) {
     document.UpdateForm.gstapl25.disabled=false;
     document.UpdateForm.gstapl26.disabled=false;
     document.UpdateForm.gstapl27.disabled=false;
     document.UpdateForm.gstapl28.disabled=false;
     document.UpdateForm.gstapl29.disabled=false;
     document.UpdateForm.gstapl30.disabled=false;

     document.UpdateForm.gstcod25.disabled=false;
     document.UpdateForm.gstcod26.disabled=false;
     document.UpdateForm.gstcod27.disabled=false;
     document.UpdateForm.gstcod28.disabled=false;
     document.UpdateForm.gstcod29.disabled=false;
     document.UpdateForm.gstcod30.disabled=false;
  }

     document.UpdateForm.gstapm01.disabled=false;
     document.UpdateForm.gstapm02.disabled=false;
     document.UpdateForm.gstapm03.disabled=false;
     document.UpdateForm.gstapm04.disabled=false;
     document.UpdateForm.gstapm05.disabled=false;
     document.UpdateForm.gstapm06.disabled=false;

     document.UpdateForm.gstcom01.disabled=false;
     document.UpdateForm.gstcom02.disabled=false;
     document.UpdateForm.gstcom03.disabled=false;
     document.UpdateForm.gstcom04.disabled=false;
     document.UpdateForm.gstcom05.disabled=false;
     document.UpdateForm.gstcom06.disabled=false;

  if ((document.UpdateForm.misbox1 != undefined) &&
      (document.UpdateForm.misbox1.checked == true)) {
     document.UpdateForm.gstapm07.disabled=false;
     document.UpdateForm.gstapm08.disabled=false;
     document.UpdateForm.gstapm09.disabled=false;
     document.UpdateForm.gstapm10.disabled=false;
     document.UpdateForm.gstapm11.disabled=false;
     document.UpdateForm.gstapm12.disabled=false;

     document.UpdateForm.gstcom07.disabled=false;
     document.UpdateForm.gstcom08.disabled=false;
     document.UpdateForm.gstcom09.disabled=false;
     document.UpdateForm.gstcom10.disabled=false;
     document.UpdateForm.gstcom11.disabled=false;
     document.UpdateForm.gstcom12.disabled=false;
  }

  if ((document.UpdateForm.misbox2 != undefined) &&
      (document.UpdateForm.misbox2.checked == true)) {
     document.UpdateForm.gstapm13.disabled=false;
     document.UpdateForm.gstapm14.disabled=false;
     document.UpdateForm.gstapm15.disabled=false;
     document.UpdateForm.gstapm16.disabled=false;
     document.UpdateForm.gstapm17.disabled=false;
     document.UpdateForm.gstapm18.disabled=false;

     document.UpdateForm.gstcom13.disabled=false;
     document.UpdateForm.gstcom14.disabled=false;
     document.UpdateForm.gstcom15.disabled=false;
     document.UpdateForm.gstcom16.disabled=false;
     document.UpdateForm.gstcom17.disabled=false;
     document.UpdateForm.gstcom18.disabled=false;
  }
  if ((document.UpdateForm.misbox3 != undefined) &&
      (document.UpdateForm.misbox3.checked == true)) {
     document.UpdateForm.gstapm19.disabled=false;
     document.UpdateForm.gstapm20.disabled=false;
     document.UpdateForm.gstapm21.disabled=false;
     document.UpdateForm.gstapm22.disabled=false;
     document.UpdateForm.gstapm23.disabled=false;
     document.UpdateForm.gstapm24.disabled=false;

     document.UpdateForm.gstcom19.disabled=false;
     document.UpdateForm.gstcom20.disabled=false;
     document.UpdateForm.gstcom21.disabled=false;
     document.UpdateForm.gstcom22.disabled=false;
     document.UpdateForm.gstcom23.disabled=false;
     document.UpdateForm.gstcom24.disabled=false;
  }
  if ((document.UpdateForm.misbox4 != undefined) &&
      (document.UpdateForm.misbox4.checked == true)) {
     document.UpdateForm.gstapm25.disabled=false;
     document.UpdateForm.gstapm26.disabled=false;
     document.UpdateForm.gstapm27.disabled=false;
     document.UpdateForm.gstapm28.disabled=false;
     document.UpdateForm.gstapm29.disabled=false;
     document.UpdateForm.gstapm30.disabled=false;

     document.UpdateForm.gstcom25.disabled=false;
     document.UpdateForm.gstcom26.disabled=false;
     document.UpdateForm.gstcom27.disabled=false;
     document.UpdateForm.gstcom28.disabled=false;
     document.UpdateForm.gstcom29.disabled=false;
     document.UpdateForm.gstcom30.disabled=false;
  }

   document.UpdateForm.submit(); 
  }
}

function DisButton() {
  document.UpdateForm.feesestm.disabled=true;
  setInterval('document.UpdateForm.feesestm.disabled=false',6000);
}

function SetPostCode01() {
 suburb   = UpdateForm.address2;
 state    = UpdateForm.address3;
 postcode = UpdateForm.postcode;
}
function valSuburb(){
  if (isWhitespace(UpdateForm.address2.value)) {
    return;
  }
  UpCase(UpdateForm.address2);
  if(trim(UpdateForm.postcode.value)!="8888"){
    LookupPostCode(UpdateForm.address2.value);
  }
}
function valPostCode(){
  if (isWhitespace(UpdateForm.postcode.value)) {
    return;
  }
  LookupSuburb(UpdateForm.postcode.value)
}

function checkOpt() {
  if (UpdateForm.reptoptn.value==1){
    document.getElementById('repoption').innerHTML=document.getElementById('URSpan').innerHTML;
  }
  else {
    document.getElementById('repoption').innerHTML=document.getElementById('NameSpan').innerHTML;
    SetPostCode01();
  }
}

function checkUR() {
   p=UpdateForm;
   if (isWhitespace(p.urnumber.value)) {
     return;
   }
   justifyRight(p.urnumber);
   if (!validateCode(13,p.urnumber,p.patname,UpdateUR,p.dummy,
        p.dummy,p.dummy,p.ur,p.admissno,p.dummy,p.dummy,p.dummy,
        p.dummy,p.dummy,p.dummy,p.dummy,p.dummy,p.dummy,p.merge)) {
     p.urnumber.focus();
     return;
   } else {
     if (p.merge.value=="1") {
     alert("Warning : This U/R Number is merged with " + p.urnumber.value); }
   }
}

function UpdateUR() {
 document.UpdateForm.urnumber.value=document.UpdateForm.ur.value
}
