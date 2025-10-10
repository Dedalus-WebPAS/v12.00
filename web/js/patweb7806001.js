//jsVersion  : V12.00.00
////=============================================================================
//// Program   : patweb7806001.js
////
//// Written   : 17/06/2024
////
//// Function  : Standard Functions Used in patweb7806001.html SJOG standard
////
////============================================================================
//

function checkTheatre(ReturnCode,ReturnName,GSTKey,GSTAppl,GSTCode,GSTtap,GSTtcd) {
  if (validateMbs(ReturnCode,ReturnName,UpdateForm.tempamnt,
                  UpdateForm.tempgsta,UpdateForm.tempgstc,
                  UpdateForm.suggclss,UpdateForm.dcasclss,
                  UpdateForm.pmsfd004 )) {

  if (UpdateForm.pmsfd003 != undefined){             // Planned Length of Stay
    if (UpdateForm.pmsfd003.value==0) {
      UpdateForm.suggclss.value=UpdateForm.dcasclss.value;
    }
  }

    if (UpdateForm.tempgsta.value==2) {
      GSTKey.value="1";
      ableTF(GSTAppl,GSTCode);
      GSTAppl.className="Mandatory";

      for (var i =0 ; i < GSTCode.length; i++) {
          if (GSTCode.options[i].value==UpdateForm.tempgstc.value) {
            GSTCode.selectedIndex=i } };

      GSTtap.value=GSTAppl.value;
      GSTtcd.value=GSTCode.value;
    }
    else {
      GSTKey.value="0";
      disableTF(GSTAppl,GSTCode);

      GSTAppl.value=UpdateForm.tempgsta.value;
      GSTCode.value=UpdateForm.tempgstc.value;

      GSTtap.value=UpdateForm.tempgsta.value;
      GSTtcd.value=UpdateForm.tempgstc.value;

      GSTAppl.disabled=true;
      GSTCode.disabled=true;

    }
//
//  only get Admission type default on first theatre fee item
//
    if (ReturnCode.name=="thefee01") {
      if (isWhitespace(UpdateForm.suggclss.value)) {
        UpdateForm.pmsfd006.value=UpdateForm.pmsfd006.value+"      ";
        UpdateForm.dummy.value=UpdateForm.pmsfd006.value.substr(0,6)
                              +UpdateForm.thefee01.value;
        validateCode(67,UpdateForm.dummy,UpdateForm.suggclss)
      }

       if ((UpdateForm.accomchr!=undefined) &&
           (UpdateForm.accomchr.value) != "1") {

       if (UpdateForm.pmsfd010 != undefined){        // Admission Type - Cat A
        if (!isWhitespace(UpdateForm.suggclss.value)) {
         for (i=0; i<UpdateForm.pmsfd010.length; i++) {
           if (UpdateForm.pmsfd010.options[i].value.substr(0,3)==
               UpdateForm.suggclss.value) {
             UpdateForm.pmsfd010.selectedIndex=i;
           }
         }
        }
       }

      }
    }
//
  }
}

function checkMisc(ReturnCode,ReturnName,GSTKey,GSTAppl,GSTCode,GSTmap,GSTmcd,KeyAmt,Amount) {
   if (isWhitespace(ReturnCode.value)) {
     return;;
   }
 
  if (validateMisc(ReturnCode,ReturnName,
                  UpdateForm.tempgsta,
                  UpdateForm.tempgstc,KeyAmt,Amount)) {
    if (UpdateForm.tempgsta.value==2) {
      GSTKey.value="1";
      ableTF(GSTAppl,GSTCode);
      GSTAppl.className="Mandatory";

      for (var i =0 ; i < GSTCode.length; i++) {
          if (GSTCode.options[i].value==UpdateForm.tempgstc.value) {
            GSTCode.selectedIndex=i } };

      GSTmap.value=GSTAppl.value;
      GSTmcd.value=GSTCode.value;
    }
    else {
      GSTKey.value="0";
      disableTF(GSTAppl,GSTCode);

      GSTAppl.value=UpdateForm.tempgsta.value;
      GSTCode.value=UpdateForm.tempgstc.value;

      GSTmap.value=UpdateForm.tempgsta.value;
      GSTmcd.value=UpdateForm.tempgstc.value;

      GSTAppl.disabled=true;
      GSTCode.disabled=true;

    }

  if(document.getElementById("ptcnifcl").value == 1) {
      TotalExpLOSA();
  }

 } else {
    ReturnCode.value="";
 }
}

// function validateMisc(ReturnCode,ReturnName,GSTAppl,GSTCode,KeyAmt,Amount) {
//   if (isWhitespace(ReturnCode.value)) {
//     return;;
//   }
//   if (document.UpdateForm.pmsfd004!=undefined) {
//    var serverURL   = "../cgi-bin/patweb80.pbl?reportno=40" +
//                  "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
//                  "&returndt=" + UpdateForm.pmsfd004.value.replace(/ /g,"+") +
//                  "&valdtype=3"
//    } else {
//    var serverURL   = "../cgi-bin/patweb80.pbl?reportno=40" +
//                  "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
//                  "&valdtype=1"
//    }
// 
// 
//   KeyAmt.value="0";
//   var returnValue = RSExecute(serverURL);
//   if (returnValue.status==0) {
//     ReturnValue=returnValue.return_value.split("|");
//     ReturnName.value=trim(ReturnValue[0]);
//     GSTAppl.value=ReturnValue[1];
//     GSTCode.value=ReturnValue[2];
//     if ((ReturnValue[3]=="Y") && (Amount.value!="zzz")) {
//       KeyAmt.value="1";
//       window.Amount=Amount;
//       window.Itemn=ReturnName;
//       linkURL="patweb76.pbl?reportno=01&template=051" +
//               "&urnumber=" + UpdateForm.urnumber.value.replace(/ /g,"+") +
//               "&admissno=" + UpdateForm.admissno.value.replace(/ /g,"+")
//       Left=(document.body.clientWidth-350)/2
//       DFrameLink(linkURL,250,Left,350,120)
//     }
//     return true;
//   }
//   else {
//     FocusDelay(ReturnCode);
//     return false;
//   }
// }

function validateMisc(ReturnCode,ReturnName,GSTAppl,GSTCode,KeyAmt,Amount) {
  if (isWhitespace(ReturnCode.value)) {
    return;;
  }
  if (document.UpdateForm.pmsfd004!=undefined) {
   var serverURL   = "../cgi-bin/patweb80.pbl?reportno=4" +
                 "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
                 "&returndt=" + UpdateForm.pmsfd004.value.replace(/ /g,"+") +
                 "&valdadno=" + UpdateForm.admissno.value.replace(/ /g,"+") +
                 "&valdtype=5"
   } else {
   var serverURL   = "../cgi-bin/patweb80.pbl?reportno=4" +
                 "&valdcode=" + ReturnCode.value.replace(/ /g,"+") +
                 "&valdadno=" + UpdateForm.admissno.value.replace(/ /g,"+") +
                 "&valdtype=5"
   }

  KeyAmt.value="0";
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|");
    ReturnName.value=trim(ReturnValue[0]);
    GSTAppl.value=ReturnValue[10];
    GSTCode.value=ReturnValue[11];
    if ((ReturnValue[15]=="Y") && (Amount.value!="zzz")) {
      KeyAmt.value="1";
      window.Amount=Amount;
      window.Itemn=ReturnName;
      linkURL="patweb76.pbl?reportno=01&template=051" +
              "&urnumber=" + UpdateForm.urnumber.value.replace(/ /g,"+") +
              "&admissno=" + UpdateForm.admissno.value.replace(/ /g,"+")
      Left=(document.body.clientWidth-350)/2
      DFrameLink(linkURL,250,Left,350,120)
    }

   if(document.getElementById("ptcnifcl").value == 1) {
    document.UpdateForm.misamt01.value=(parseFloat(ReturnValue[12])
                                    + (parseFloat(ReturnValue[13])));
   }

    return true;
  }
  else {
    FocusDelay(ReturnCode);
    return false;
  }
}

function DisabledGST(itemcd,gstky,gstap,gstcd) {
 if (itemcd != undefined){
  if (!isWhitespace(itemcd.value)) {
   if ((gstky.value)!="1") {
      gstap.disabled=true;
      gstcd.disabled=true;
   } else {
      gstap.disabled=false;
      gstcd.disabled=false;
      gstap.className="Mandatory";
   }
  }
 }
}

function ShowGST() {
p=UpdateForm
  DisabledGST(p.thefee01,p.gsttky01,p.gstapl01,p.gstcod01);
  DisabledGST(p.thefee02,p.gsttky02,p.gstapl02,p.gstcod02);
  DisabledGST(p.thefee03,p.gsttky03,p.gstapl03,p.gstcod03);
  DisabledGST(p.thefee04,p.gsttky04,p.gstapl04,p.gstcod04);
  DisabledGST(p.thefee05,p.gsttky05,p.gstapl05,p.gstcod05);
  DisabledGST(p.thefee06,p.gsttky06,p.gstapl06,p.gstcod06);
  DisabledGST(p.thefee07,p.gsttky07,p.gstapl07,p.gstcod07);
  DisabledGST(p.thefee08,p.gsttky08,p.gstapl08,p.gstcod08);
  DisabledGST(p.thefee09,p.gsttky09,p.gstapl09,p.gstcod09);
  DisabledGST(p.thefee10,p.gsttky10,p.gstapl10,p.gstcod10);

  DisabledGST(p.thefee11,p.gsttky11,p.gstapl11,p.gstcod11);
  DisabledGST(p.thefee12,p.gsttky12,p.gstapl12,p.gstcod12);
  DisabledGST(p.thefee13,p.gsttky13,p.gstapl13,p.gstcod13);
  DisabledGST(p.thefee14,p.gsttky14,p.gstapl14,p.gstcod14);
  DisabledGST(p.thefee15,p.gsttky15,p.gstapl15,p.gstcod15);
  DisabledGST(p.thefee16,p.gsttky16,p.gstapl16,p.gstcod16);
  DisabledGST(p.thefee17,p.gsttky17,p.gstapl17,p.gstcod17);
  DisabledGST(p.thefee18,p.gsttky18,p.gstapl18,p.gstcod18);
  DisabledGST(p.thefee19,p.gsttky19,p.gstapl19,p.gstcod19);
  DisabledGST(p.thefee20,p.gsttky20,p.gstapl20,p.gstcod20);

  DisabledGST(p.thefee21,p.gsttky21,p.gstapl21,p.gstcod21);
  DisabledGST(p.thefee22,p.gsttky22,p.gstapl22,p.gstcod22);
  DisabledGST(p.thefee23,p.gsttky23,p.gstapl23,p.gstcod23);
  DisabledGST(p.thefee24,p.gsttky24,p.gstapl24,p.gstcod24);
  DisabledGST(p.thefee25,p.gsttky25,p.gstapl25,p.gstcod25);
  DisabledGST(p.thefee26,p.gsttky26,p.gstapl26,p.gstcod26);
  DisabledGST(p.thefee27,p.gsttky27,p.gstapl27,p.gstcod27);
  DisabledGST(p.thefee28,p.gsttky28,p.gstapl28,p.gstcod28);
  DisabledGST(p.thefee29,p.gsttky29,p.gstapl29,p.gstcod29);
  DisabledGST(p.thefee30,p.gsttky30,p.gstapl30,p.gstcod30);

  DisabledGST(p.thefee31,p.gsttky31,p.gstapl31,p.gstcod31);
  DisabledGST(p.thefee32,p.gsttky32,p.gstapl32,p.gstcod32);
  DisabledGST(p.thefee33,p.gsttky33,p.gstapl33,p.gstcod33);
  DisabledGST(p.thefee34,p.gsttky34,p.gstapl34,p.gstcod34);
  DisabledGST(p.thefee35,p.gsttky35,p.gstapl35,p.gstcod35);
  DisabledGST(p.thefee36,p.gsttky36,p.gstapl36,p.gstcod36);
  DisabledGST(p.thefee37,p.gsttky37,p.gstapl37,p.gstcod37);
  DisabledGST(p.thefee38,p.gsttky38,p.gstapl38,p.gstcod38);
  DisabledGST(p.thefee39,p.gsttky39,p.gstapl39,p.gstcod39);
  DisabledGST(p.thefee40,p.gsttky40,p.gstapl40,p.gstcod40);

  DisabledGST(p.thefee41,p.gsttky41,p.gstapl41,p.gstcod41);
  DisabledGST(p.thefee42,p.gsttky42,p.gstapl42,p.gstcod42);
  DisabledGST(p.thefee43,p.gsttky43,p.gstapl43,p.gstcod43);
  DisabledGST(p.thefee44,p.gsttky44,p.gstapl44,p.gstcod44);
  DisabledGST(p.thefee45,p.gsttky45,p.gstapl45,p.gstcod45);
  DisabledGST(p.thefee46,p.gsttky46,p.gstapl46,p.gstcod46);
  DisabledGST(p.thefee47,p.gsttky47,p.gstapl47,p.gstcod47);
  DisabledGST(p.thefee48,p.gsttky48,p.gstapl48,p.gstcod48);
  DisabledGST(p.thefee49,p.gsttky49,p.gstapl49,p.gstcod49);
  DisabledGST(p.thefee50,p.gsttky50,p.gstapl50,p.gstcod50);

  DisabledGST(p.mischg01,p.gstmky01,p.gstapm01,p.gstcom01);
  DisabledGST(p.mischg02,p.gstmky02,p.gstapm02,p.gstcom02);
  DisabledGST(p.mischg03,p.gstmky03,p.gstapm03,p.gstcom03);
  DisabledGST(p.mischg04,p.gstmky04,p.gstapm04,p.gstcom04);
  DisabledGST(p.mischg05,p.gstmky05,p.gstapm05,p.gstcom05);
  DisabledGST(p.mischg06,p.gstmky06,p.gstapm06,p.gstcom06);
  DisabledGST(p.mischg07,p.gstmky07,p.gstapm07,p.gstcom07);
  DisabledGST(p.mischg08,p.gstmky08,p.gstapm08,p.gstcom08);
  DisabledGST(p.mischg09,p.gstmky09,p.gstapm09,p.gstcom09);
  DisabledGST(p.mischg10,p.gstmky10,p.gstapm10,p.gstcom10);

  DisabledGST(p.mischg11,p.gstmky11,p.gstapm11,p.gstcom11);
  DisabledGST(p.mischg12,p.gstmky12,p.gstapm12,p.gstcom12);
  DisabledGST(p.mischg13,p.gstmky13,p.gstapm13,p.gstcom13);
  DisabledGST(p.mischg14,p.gstmky14,p.gstapm14,p.gstcom14);
  DisabledGST(p.mischg15,p.gstmky15,p.gstapm15,p.gstcom15);
  DisabledGST(p.mischg16,p.gstmky16,p.gstapm16,p.gstcom16);
  DisabledGST(p.mischg17,p.gstmky17,p.gstapm17,p.gstcom17);
  DisabledGST(p.mischg18,p.gstmky18,p.gstapm18,p.gstcom18);
  DisabledGST(p.mischg19,p.gstmky19,p.gstapm19,p.gstcom19);
  DisabledGST(p.mischg20,p.gstmky20,p.gstapm20,p.gstcom20);

  DisabledGST(p.mischg21,p.gstmky21,p.gstapm21,p.gstcom21);
  DisabledGST(p.mischg22,p.gstmky22,p.gstapm22,p.gstcom22);
  DisabledGST(p.mischg23,p.gstmky23,p.gstapm23,p.gstcom23);
  DisabledGST(p.mischg24,p.gstmky24,p.gstapm24,p.gstcom24);
  DisabledGST(p.mischg25,p.gstmky25,p.gstapm25,p.gstcom25);
  DisabledGST(p.mischg26,p.gstmky26,p.gstapm26,p.gstcom26);
  DisabledGST(p.mischg27,p.gstmky27,p.gstapm27,p.gstcom27);
  DisabledGST(p.mischg28,p.gstmky28,p.gstapm28,p.gstcom28);
  DisabledGST(p.mischg29,p.gstmky29,p.gstapm29,p.gstcom29);
  DisabledGST(p.mischg30,p.gstmky30,p.gstapm30,p.gstcom30);

  DisabledGST(p.mischg31,p.gstmky31,p.gstapm31,p.gstcom31);
  DisabledGST(p.mischg32,p.gstmky32,p.gstapm32,p.gstcom32);
  DisabledGST(p.mischg33,p.gstmky33,p.gstapm33,p.gstcom33);
  DisabledGST(p.mischg34,p.gstmky34,p.gstapm34,p.gstcom34);
  DisabledGST(p.mischg35,p.gstmky35,p.gstapm35,p.gstcom35);
  DisabledGST(p.mischg36,p.gstmky36,p.gstapm36,p.gstcom36);
  DisabledGST(p.mischg37,p.gstmky37,p.gstapm37,p.gstcom37);
  DisabledGST(p.mischg38,p.gstmky38,p.gstapm38,p.gstcom38);
  DisabledGST(p.mischg39,p.gstmky39,p.gstapm39,p.gstcom39);
  DisabledGST(p.mischg40,p.gstmky40,p.gstapm40,p.gstcom40);

  DisabledGST(p.mischg41,p.gstmky41,p.gstapm41,p.gstcom41);
  DisabledGST(p.mischg42,p.gstmky42,p.gstapm42,p.gstcom42);
  DisabledGST(p.mischg43,p.gstmky43,p.gstapm43,p.gstcom43);
  DisabledGST(p.mischg44,p.gstmky44,p.gstapm44,p.gstcom44);
  DisabledGST(p.mischg45,p.gstmky45,p.gstapm45,p.gstcom45);
  DisabledGST(p.mischg46,p.gstmky46,p.gstapm46,p.gstcom46);
  DisabledGST(p.mischg47,p.gstmky47,p.gstapm47,p.gstcom47);
  DisabledGST(p.mischg48,p.gstmky48,p.gstapm48,p.gstcom48);
  DisabledGST(p.mischg49,p.gstmky49,p.gstapm49,p.gstcom49);
  DisabledGST(p.mischg50,p.gstmky50,p.gstapm50,p.gstcom50);

}

function checkGST(GSTAppl,GSTCode,GSTtap,GSTtcd) {
  if (GSTAppl.selectedIndex==1) {
    GSTCode.className="Mandatory";
      GSTtap.value=GSTAppl.value;
      GSTtcd.value=GSTCode.value;
  }
  else {
    GSTCode.className="";
    GSTCode.value="";
      GSTtap.value=GSTAppl.value;
      GSTtcd.value=GSTCode.value;
  }
}

function SetGST(GSTAppl,GSTCode,GSTtap,GSTtcd) {
      GSTtap.value=GSTAppl.value;
      GSTtcd.value=GSTCode.value;
}

function ChkExtra() {
  if(!isWhitespace(document.getElementById("thefee07").value)) {
      ExtraMBS1.innerHTML=extrambs1.innerHTML;
      document.UpdateForm.mbsbox1.checked=true;
    } else {
      ExtraMBS1.innerHTML=blanklabe1.innerHTML;
  }

  if(!isWhitespace(document.getElementById("thefee13").value)) {
      ExtraMBS2.innerHTML=extrambs2.innerHTML;
      document.UpdateForm.mbsbox2.checked=true;
      document.UpdateForm.mbsbox1.disabled = true;
    } else {
      ExtraMBS2.innerHTML=blanklabe1.innerHTML;
      document.UpdateForm.mbsbox1.disabled = false;
  }
  if(!isWhitespace(document.getElementById("thefee19").value)) {
      ExtraMBS3.innerHTML=extrambs3.innerHTML;
      document.UpdateForm.mbsbox3.checked=true;
      document.UpdateForm.mbsbox2.disabled = true;
    } else {
      ExtraMBS3.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("thefee25").value)) {
      ExtraMBS4.innerHTML=extrambs4.innerHTML;
      document.UpdateForm.mbsbox4.checked=true;
      document.UpdateForm.mbsbox3.disabled = true;
    } else {
      ExtraMBS4.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("thefee31").value)) {
      ExtraMBS5.innerHTML=extrambs5.innerHTML;
      document.UpdateForm.mbsbox5.checked=true;
      document.UpdateForm.mbsbox4.disabled = true;
    } else {
      ExtraMBS5.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("thefee37").value)) {
      ExtraMBS6.innerHTML=extrambs6.innerHTML;
      document.UpdateForm.mbsbox6.checked=true;
      document.UpdateForm.mbsbox5.disabled = true;
    } else {
      ExtraMBS6.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("thefee43").value)) {
      ExtraMBS7.innerHTML=extrambs7.innerHTML;
      document.UpdateForm.mbsbox7.checked=true;
      document.UpdateForm.mbsbox6.disabled = true;
    } else {
      ExtraMBS7.innerHTML=blanklabe1.innerHTML;
  }



  if(!isWhitespace(document.getElementById("mischg07").value)) {
      ExtraMis1.innerHTML=extramis1.innerHTML;
      document.UpdateForm.misbox1.checked=true;
    } else {
      ExtraMis1.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("mischg13").value)) {
      ExtraMis2.innerHTML=extramis2.innerHTML;
      document.UpdateForm.misbox2.checked=true;
      document.UpdateForm.misbox1.disabled = true;
    } else {
      ExtraMis2.innerHTML=blanklabe1.innerHTML;
      document.UpdateForm.misbox1.disabled = false;
  }
  if(!isWhitespace(document.getElementById("mischg19").value)) {
      ExtraMis3.innerHTML=extramis3.innerHTML;
      document.UpdateForm.misbox3.checked=true;
      document.UpdateForm.misbox2.disabled = true;
    } else {
      ExtraMis3.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("mischg25").value)) {
      ExtraMis4.innerHTML=extramis4.innerHTML;
      document.UpdateForm.misbox4.checked=true;
      document.UpdateForm.misbox3.disabled = true;
    } else {
      ExtraMis4.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("mischg31").value)) {
      ExtraMis5.innerHTML=extramis5.innerHTML;
      document.UpdateForm.misbox5.checked=true;
      document.UpdateForm.misbox4.disabled = true;
    } else {
      ExtraMis5.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("mischg37").value)) {
      ExtraMis6.innerHTML=extramis6.innerHTML;
      document.UpdateForm.misbox6.checked=true;
      document.UpdateForm.misbox5.disabled = true;
    } else {
      ExtraMis6.innerHTML=blanklabe1.innerHTML;
  }
  if(!isWhitespace(document.getElementById("mischg43").value)) {
      ExtraMis7.innerHTML=extramis7.innerHTML;
      document.UpdateForm.misbox7.checked=true;
      document.UpdateForm.misbox6.disabled = true;
    } else {
      ExtraMis7.innerHTML=blanklabe1.innerHTML;
  }
}

function ableTF(GSTAppl,GSTCode) {
  GSTAppl.className="";
  GSTAppl.selectedIndex=0;
  GSTAppl.disabled=false;
  GSTCode.className="";
  GSTCode.selectedIndex=0;
  GSTCode.disabled=false;
}

function ShowXtraItem() {
   if(document.getElementById("addmitem").checked == true) {
      ChkExtra();
   } else {
      ExtraMBS1.innerHTML=blanklabe1.innerHTML;
      ExtraMBS2.innerHTML=blanklabe1.innerHTML;
      ExtraMBS3.innerHTML=blanklabe1.innerHTML;
      ExtraMBS4.innerHTML=blanklabe1.innerHTML;
      ExtraMBS5.innerHTML=blanklabe1.innerHTML;
      ExtraMBS6.innerHTML=blanklabe1.innerHTML;
      ExtraMBS7.innerHTML=blanklabe1.innerHTML;
      ExtraMis1.innerHTML=blanklabe1.innerHTML;
      ExtraMis2.innerHTML=blanklabe1.innerHTML;
      ExtraMis3.innerHTML=blanklabe1.innerHTML;
      ExtraMis4.innerHTML=blanklabe1.innerHTML;
      ExtraMis5.innerHTML=blanklabe1.innerHTML;
      ExtraMis6.innerHTML=blanklabe1.innerHTML;
      ExtraMis7.innerHTML=blanklabe1.innerHTML;
  }

}

function disableTF(GSTAppl,GSTCode) {
  GSTAppl.className="";
  GSTAppl.selectedIndex=0;
  GSTAppl.disabled=true;
  GSTCode.className="";
  GSTCode.selectedIndex=0;
  GSTCode.disabled=true;
}



