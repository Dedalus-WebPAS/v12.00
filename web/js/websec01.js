//jsVersion  : V12.00.00
//========================================================================
// Program   : websec01.js
//
// Function  : Standard Functions Used in websec01  
//========================================================================
//   Report 1 
//========================================================================
function CheckSitePass(type,site,pass) {
  if(isWhitespace(site.value)) { return;}
  var serverURL   = "../cgi-bin/patweb80.pbl?reportno=76" +
                    "&valdtype=" + type + 
                    "&checksit=" + site.value.replace(/ /g,"+") +
                    "&valdcode=" + pass.value.replace(/ /g,"+")
  var returnValue = RSExecute(serverURL);
  if (returnValue.status==0) {
    ReturnValue=returnValue.return_value.split("|");
    if(type=="1") { 
      if(ReturnValue[0]=="1") {
        SitePass.style.display="";
        pass.className="Mandatory"
      } else {
        SitePass.style.display="none";
        pass.className=""
      }
    }
  } else {
    pass.value="";
    pass.focus();
  }
}
//========================================================================
//   Report 3
//========================================================================
function AlertLevels() {
        var p=document.security_main;
  linkurl="websec01.pbl?reportno=03&template=008" +
                    "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2;
  DFrameLink(linkurl,0,Left,650,450);
}
function CategorySec() {
  var p=document.security_main;
  linkurl="comweb03.pbl?reportno=03&template=004" +
                    "&scusr002=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-600)/2
  DFrameLink(linkurl,0,Left,600,390)
}
function UserSecAccess() {
  var p=document.security_main;
  if (document.security_main.d_wbsec029.checked==true) {
    alert("This User already has Access to all Practices");
    return;
  }
  linkurl="priweb01.pbl?reportno=06&template=002" +
                    "&pruserid=" + p.wbsec001.value.replace(/ /g,"+") +
                    "&updttype=S";
  Left=(document.body.clientWidth-650)/2
  DFrameLink(linkurl,0,Left,650,450)
}
function UserHosAccess() {
  var p=document.security_main;
  if(document.security_main.d_wbsec035!=undefined) {
    if (document.security_main.d_wbsec035.checked==true) {
    alert("This User already has Access to all Hospitals");
    return;
    }
  }
  linkurl="websec01.pbl?reportno=03&template=005" +
                    "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2
  DFrameLink(linkurl,0,Left,650,450)
}
function ShowDetail03(linkurl) {
  Left=(document.body.clientWidth-900)/2;
  DFrameLink(linkurl,0,Left,900,800)
}
function EditID03() {
  SelectCode.template.value=3;
  SelectCode.wbsec001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-900)/2;
  DFrameSubmit(SelectCode,0,Left,900,800);

}

function ReportGrop03() {
  var p=document.security_main;
  linkurl="websec01.pbl?reportno=12&template=001" +
                    "&wbidname=" + p.wbsec002.value.replace(/ /g,"+") +
                    "&webuseid=" + p.wbsec001.value.replace(/ /g,"+") +
                    "&wbrur001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2;
  DFrameLink(linkurl,0,Left,650,450);
}

function secLevels03() {
   var p=document.security_main;
   linkurl="websec01.pbl?reportno=04&template=001" +
                    "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
   Left=(document.body.clientWidth-650)/2;
   DFrameLink(linkurl,0,Left,650,450);
}

function ReportLevels(){
  var p=document.security_main;
  linkurl="websec01.pbl?reportno=04&template=005" +
                    "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2;
  DFrameLink(linkurl,0,Left,650,450);
}

function casExtSec03() {
  var p=document.security_main;
  linkurl="ciaweb01.pbl?reportno=02&template=001" +
                    "&casec002=" + p.wbsec001.value.replace(/ /g,"+")+
                    "webuseid" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2;
  DFrameLink(linkurl,0,Left,650,450);
}
function DeleteAction03() { 
ans=confirm("Are you sure you want to Delete?")
if (ans) {
    document.security_main.updttype.value="D";
    userid = document.security_main.wbsec001.value;
    document.security_main.nextpage.value="7";
    document.security_main.redirect.value="rshweb02.pbl?reportno=1&template=9"+
                                    "&delterep=1"+
                                    "&fltusrid="+userid+
                                    "&discancl=1"+
                                    "&showqued=1"; 
    SetCookie("rshweb0201009",parent.location .href);          //0948348    
    document.security_main.submit();
    }
}
function UpdateAction03() { 
 checkmrt=document.security_main.wbsec030.value.search('[^a-zA-Z0-9]');
 if (checkmrt >= 0) {
   alert("MRT Security Number can only be alphanumeric!");
   document.security_main.wbsec030.value="";
   document.security_main.wbsec030.focus();
   return;
 }
  if(trim(document.security_main.wbsec015.value)=="0"){
    alert("Age by Number of Day Must be Greater Than Zero");
    return
  }
  if(document.security_main.d_wbsec027.checked == true) {
     document.security_main.wbsec027.value="1";
  } else {
     document.security_main.wbsec027.value="0";
  }
  if(document.security_main.d_wbsec029.checked == true) {
     document.security_main.wbsec029.value="1";
  } else {
     document.security_main.wbsec029.value="0";
  }
  if(document.security_main.d_wbsec035!=undefined) {
    if(document.security_main.d_wbsec035.checked == true) {
       document.security_main.wbsec035.value="1";
    } else {
       document.security_main.wbsec035.value="0";
    }
  }
  if(document.security_main.d_wbsec037!=undefined) {
    if(document.security_main.d_wbsec037.checked == true) {
       document.security_main.wbsec037.value="1";
    } else {
       document.security_main.wbsec037.value="0";
    }
  }
  if(document.security_main.d_wbsec061!=undefined) {
    if(document.security_main.d_wbsec061.checked == true) {
       document.security_main.wbsec061.value="1";
    } else {
       document.security_main.wbsec061.value="0";
    }
  }
  if(document.security_main.d_wbsec064!=undefined) {
    if(document.security_main.d_wbsec064.checked == true) {
       document.security_main.wbsec064.value="1";
    } else {
       document.security_main.wbsec064.value="0";
    }
  }
  if (document.security_main.wbsec011.checked == false) {
    userid = document.security_main.wbsec001.value;
    document.security_main.nextpage.value="7";
    document.security_main.redirect.value="rshweb02.pbl?reportno=1&template=9"+
                                    "&delterep=1"+
                                    "&fltusrid="+userid+
                                    "&discancl=1"+
                                    "&showqued=1";
    SetCookie("rshweb0201009",parent.location .href);          //0948348    
  }

  if (validateMandatory(security_main)) {
    document.security_main.submit();
  }
}
function SetDays03() {
  if(document.security_main.wbsec014.checked==true) {
    document.security_main.wbsec015.className="Mandatory Number";
  } else {
    document.security_main.wbsec015.className="Number";
  }
}
function CopyAction03() {
  var p=document.security_main;
  linkurl="websec01.pbl?reportno=03&template=013" +
          "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-440)/2;
  DFrameLink(linkurl,0,Left,440,260);
}
function ResetAction03() {
ans=confirm("Are you sure you want to Reset the password?")
if (ans) {
    document.security_main.updttype.value="R";
    document.security_main.submit();
    }
}
function WindowHelpMe03() {
alert(top.content.PopUpFrame.TemplateFile.content)
alert(top.content.TemplateFile.content)
}
function validateNurse() {
  var hcpnurse = chkHcpOTNurse();
  if  (hcpnurse==true){
      validateCode('18',document.security_main.wbsec034,
                        document.security_main.dummy1);
  }
  else {
      validateCode('17',document.security_main.wbsec034,
                        document.security_main.dummy1,
                        document.security_main.gnm,SetNurseName);
  }
}

function SetNurseName() {
security_main.dummy1.value=security_main.gnm.value.replace(/\s*$/g,"")+
                              " " +
                        security_main.dummy1.value.replace(/\s*$/g,"")
}
function GenerateKeyword03() {
 if(confirm("Generate Security ID Keyword Table")) {
   document.GenerateForm.submit();
 }
}
function ResetPassword03(userid) {
 if(confirm("Are you sure you want to Reset the password for : " + userid)) {
   document.ResetPassword.wbsec001.value=userid;
   SubmitHidden(ResetPassword);
 }
}
//C-0825792 - Check parameter to Use pmshcpaf/oprnuraf for OT Nurse
function chkHcpOTNurse(){
  if (document.getElementById('opcnurse')) {
      if (document.getElementById('opcnurse').value == "1") {
        return true;
      }
      else {
        return false;
      }
  }
  else {
      return false;
  }
}
//C-0825792 - Search Nurse from pmshcpaf/oprnuraf for OT Nurse
function SearchOTNurse(NurseId,ReturnNurseName) {
  var hcpnurse = chkHcpOTNurse();
  if (hcpnurse==true){
     HCPSearchFrame(NurseId,ReturnNurseName,20);
  }
  else {
     NurseSearchFrame(NurseId,ReturnNurseName);
  }
}

//========================================================================
//   Report 4
//========================================================================
function ShowDetail04(linkurl) {
  Left=(document.body.clientWidth-450)/2
  DFrameLink04(linkurl,0,Left,450,160)
}
function DFrameLink04(LinkToUrl,FrameTop,FrameLeft,FrameWidth,FrameHeight) {
  DFrameStart()
  PopUpFrame.document.location.href=LinkToUrl
  PopUpScreen.style.top=FrameTop + document.body.scrollTop
  PopUpScreen.style.left=FrameLeft
  MaxWidth=document.width-FrameLeft
  MaxHeight=document.height-FrameTop
  if (FrameWidth>MaxWidth)   { PopUpScreen.style.width=MaxWidth }
                        else { PopUpScreen.style.width=FrameWidth }
  if (FrameHeight>MaxHeight) { PopUpScreen.style.height=MaxHeight }
                        else { PopUpScreen.style.height=FrameHeight }
  PopUpScreen.style.display=""
}
//========================================================================
//   Report 6
//========================================================================
function ShowDetail06(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,500,180)
}
function EditLookup06() {
  SelectCode.template.value='3';
  SelectCode.wbspg001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-450)/2;
  DFrameSubmit(SelectCode,0,Left,500,125);
}
function StartList06(category) {
parent.location.href="websec01.pbl?reportno=06&template=001&startkey="+category;
DFrameExit();
}
function ViewOpt06(program) {
parent.location.href="websec01.pbl?reportno=07&template=001&wbspg001="+program;
DFrameExit();
}
function ViewDoc06(program) {
parent.location.href="../doc/" + program.toLowerCase() + ".html";
DFrameExit();
}
function ViewUser06(program) {
parent.location.href="websec01.pbl?reportno=15&template=002&filtserv="+program;
DFrameExit();
}
function ViewAllTemplate06(program) {
parent.location.href="websec01.pbl?reportno=15&template=001&filtserv="+program;
DFrameExit();
}
//========================================================================
//   Report 7
//========================================================================
function ShowDetail07(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,150);
}
function EditLookupPg07() {
    SelectCode.template.value='3';
    SelectCode.wbspg001.value=SelectCode.wbspg001.value;
    SelectCode.wbsop001.value=SelectCode.startkey.value;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,150);
}
function AddPage07(lookpage) {
    SelectCode.reportno.value='07';
    SelectCode.template.value='2';
    SelectCode.wbspg001.value=lookpage;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,150);
}
function ViewID07(lookid) {
    SelectCode.reportno.value="06";
    SelectCode.template.value="3";
    SelectCode.wbspg001.value=lookid;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,125);
}
function ViewTempl07(program,option) {
parent.location.href="websec01.pbl?reportno=08&template=001&wbspg001="+program+"&wbsop001="+option;
DFrameExit();
}
//========================================================================
//   Report 8
//========================================================================
function ShowDetail08(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,220);
}
function ViewOpts08(program) {
location.href="websec01.pbl?reportno=07&template=001&wbspg001="+program;
self.close();
}
function EditLookupPg08() {
    SelectCode.template.value='3';
    SelectCode.wbspg001.value=SelectCode.wbspg001.value;
    SelectCode.wbsop001.value=SelectCode.wbsop001.value;
    SelectCode.wbtpl001.value=SelectCode.startkey.value;
    Left=(document.body.clientWidth-550)/2;
    DFrameSubmit(SelectCode,0,Left,550,400);
}
function AddPage08(program,option) {
    SelectCode.reportno.value='08';
    SelectCode.template.value='2';
    SelectCode.wbspg001.value=program;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,220);
}
function ViewOpt08(program,option) {
    SelectCode.reportno.value='07';
    SelectCode.template.value='3';
    SelectCode.wbspg001.value=program;
    SelectCode.wbsop001.value=option;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,150);
}
//========================================================================
//   Report 9
//========================================================================
function ShowDetail09(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,160);
}
function EditLookup09() {
  SelectCode.template.value='3';
  SelectCode.wbrtm001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-450)/2;
  DFrameSubmit(SelectCode,0,Left,450,125);
}
//========================================================================
//   Report 10
//========================================================================
function ShowDetail10(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,140);
}
function EditLookup10() {
  SelectCode.template.value='3';
  SelectCode.wbrgm001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-450)/2;
  DFrameSubmit(SelectCode,0,Left,450,140);
}
function GroupDet10(group) {
parent.location.href="websec01.pbl?reportno=11&template=001&wbrdt001="+group;
DFrameExit();
}
//========================================================================
//   Report 11
//========================================================================
function ShowDetail11(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,155);
}
function EditLookup11() {
  SelectCode.template.value='3';
  SelectCode.wbrgm001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-450)/2;
  DFrameSubmit(SelectCode,0,Left,450,125);
}
function AddDetail11(station) {
    document.SelectCode.reportno.value='11';
    document.SelectCode.template.value='2';
    document.SelectCode.wbrdt001.value=station;
    Left=(document.body.clientWidth-450)/2;
    DFrameSubmit(SelectCode,0,Left,450,155);
}
//========================================================================
//   Report 12
//========================================================================
function ShowDetail12(linkurl) {
  Left=(document.body.clientWidth-450)/2;
  DFrameLink(linkurl,0,Left,450,110);
}
//========================================================================
//   Report 14
//========================================================================
function ShowDetail14(linkurl) {
  Left=(document.body.clientWidth-500)/2;
  DFrameLink(linkurl,0,Left,500,200);
}
function EditLookup14() {
  SelectCode.template.value='3';
  SelectCode.wbgrp001.value=SelectCode.startkey.value;
  Left=(document.body.clientWidth-500)/2;
  DFrameSubmit(SelectCode,0,Left,500,200);
}
function PostGroup14() {
  if (document.AddForm.d_wbgrp004.checked==true)
    document.AddForm.wbgrp004.value="0";
  else 
    document.AddForm.wbgrp004.value="1";
 
  SubmitForm();
}
function UpdateGroup14() {
  if (document.UpdateForm.d_wbgrp004.checked==true) 
    document.UpdateForm.wbgrp004.value="0";
  else 
    document.UpdateForm.wbgrp004.value="1";
 
  setFormactn('U');
}
function UserGrpSecAccess() {
	var p=document.security_main;
  if (document.security_main.d_wbsec037.checked==true) 
  {
    alert("This User already has Access to all Security Groups");
    return;
  }
  linkurl="websec01.pbl?reportno=03&template=006" +
                    "&wbsec001=" + p.wbsec001.value.replace(/ /g,"+");
  Left=(document.body.clientWidth-650)/2;
  DFrameLink(linkurl,0,Left,650,450);
}
//========================================================================
//   Report 15
//========================================================================
function PostSearch15() {
  document.SelectCode.updttype.value=" ";
  document.SelectCode.submit();
}
function UpdateSecurity15() {
  var TemplateSelected=false;
  var MarkCount=0;
  for (var i=0; i < document.SelectCode.length; i++) {
    if (document.SelectCode.elements[i].name.match(/markedky/)) {
      if (document.SelectCode.elements[i].checked==true) {
          TemplateSelected=true;
          MarkCount++;
      }
    }
  }
  if (parseInt(MarkCount,10) > 250) {
     alert("A maximun of 250 templates can be marked for update.");
     return;
  }
  if (TemplateSelected==false) {
     alert( "Please select at least one template to update." )
     return;
  }
  document.SelectCode.updttype.value="A";
  SubmitHidden(SelectCode);
}
function SelectAll15(AllCheckBox) {
  for (var i=0; i < document.SelectCode.length; i++) {
    if (document.SelectCode.elements[i].name.match(/markedky/)) {
      if(AllCheckBox.checked==true) {
         document.SelectCode.elements[i].checked=true;
      } else {
         document.SelectCode.elements[i].checked=false;
      }
    }
  }
}
function UpdateUserSecurity15() {
  var TemplateSelected=false;
  var MarkCount=0;
  for (var i=0; i < document.SelectCode.length; i++) {
    if (document.SelectCode.elements[i].name.match(/markedky/)) {
      if (document.SelectCode.elements[i].checked==true) {
          TemplateSelected=true;
          MarkCount++;
      }   
    }
  }
  if (parseInt(MarkCount,10) > 250) {
     alert("A maximun of 250 Security ID's can be marked for update.");
     return;
  }
  if (TemplateSelected==false) {
     alert( "Please select at least one security id to update." )
     return;
  }
  document.SelectCode.updttype.value="U";
  SubmitHidden(SelectCode);
}
function DisableDeleteButton() {
  f = document.security_main;
  if (f.ptcnusld.value != "1") {return}
  var serverURL = "../cgi-bin/comweb81.pbl?reportno=68" +
                  "&valdcode=" + f.cuuserid.value.replace(/ /g,"+") +
                  "&valdtype=WEBSEC01"
  var returnValue = RSExecute(serverURL);
  if (returnValue.status == 0) {
    ReturnValue = returnValue.return_value.split("|")
    if (ReturnValue.length > 1) {
      var SecLevel = ReturnValue[2];
      if (SecLevel < f.ptcnsecl.value) {
        f.btnDelete.disabled = true
      }
    }
             else {
               f.btnDelete.disabled = true
             }
  }
}

