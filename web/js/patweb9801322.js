//jsVersion  : V12.00.05
//========================================================================
// Program   : patweb9801322.js
//
// Written   : 08.02.2024 DA Sarkies    
//
// Function  : Functions Used in patweb9801322
//
//========================================================================
var printFormat = new Array();
var subjectList = new Array();
var editDocument="";
var editFlag=false;
var notesViewAll = false;
//-----------------------------------------------------------------------------
// onload function to initial page startup
//-----------------------------------------------------------------------------
function init() {
  editDocument = GetCookieData('DischargeDocument');
  ExpireCookiePath("DischargeDocument");
  editFlag=true;
  if (editDocument=='unknown') editFlag=false;
  if (isWhitespace(editDocument)) editFlag=false;
  SetCopies(UpdateForm.nocopies,10);
  SetPrinterByPatient(UpdateForm.selprint,PatientVTY,PatientVIS,PatientWRD);
  filterCatCodeList(document.UpdateForm.corsp003,"6","Y","3")
  el=document.getElementById("documentContent")
  el.style.height=document.body.offsetHeight-100;
  el.style.width="95%";
  SetTinyMCE();
}
function DisableResults() {
  el=document.getElementById("AppendResults")
  el.style.display='none';
}
function EnableResults() {
  el=document.getElementById("AppendResults")
  el.style.display='';
}
function DisableCarbonCopy() {
  el=document.getElementById("CarbonCopyItem")
  el.style.display='none';
  el=document.getElementById("carbonCopy")
  el.value='';
}
function EnableCarbonCopy() {
  el=document.getElementById("CarbonCopyItem")
  el.style.display='';
  el=document.getElementById("carbonCopy")
  el.value='';
}
function DocumentAppend() {
  el=UpdateForm.appendDocument
  switch (el.options[el.selectedIndex].value) {
     case "1": {
       AppendResults();
       break; }
     case "2": {
       SelectFromList("cliweb03.pbl",1,10);
       break; }
     case "3": {
       SelectFromList("patweb98.pbl",1,106);
       break; }
     case "4": { 
       SelectFromList("patweb98.pbl",1,113);
       break; }
     case "5": { 
       SelectFromList("allweb02.pbl",2,33);
       break; }
  }
  
}
function RemoveSingle(theURL) {
  resultKey=theURL.replace(/.*resultky=/,"")
  tinyMCE.activeEditor.dom.remove('cr'+resultKey);
}
function AddClinicalNote(theField, theKey,theText) {

    if (theField.style.backgroundColor=="grey") {
      tinyMCE.activeEditor.dom.remove('cn'+theKey);
      theField.style.backgroundColor=theField.getAttribute("saveBGC");
    } else {
      theField.setAttribute("saveBGC",theField.style.backgroundColor);
      theField.style.backgroundColor="grey";
      var el=tinyMCE.activeEditor.dom.get('clinicalNotes');

      if (el == null) {
         tinyMCE.activeEditor.dom.add(tinyMCE.activeEditor.getBody(), 'span', {id : 'cn'+theKey}, theText);
      }
      else {
        tinyMCE.activeEditor.dom.add(el, 'span', {id : 'cn'+theKey}, theText);
      }
      var myNode = tinyMCE.activeEditor.getDoc().getElementById('cn'+theKey) 
      myNode.scrollIntoView(false);
    }
}
function AppendSingle(theURL) {
  resultKey=theURL.replace(/.*resultky=/,"")
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
    var el=tinyMCE.activeEditor.dom.get('clinicalResultsSection');
    if (el == null) {
      tinyMCE.activeEditor.dom.add(tinyMCE.activeEditor.getBody(), 'span', {id : 'cr'+resultKey}, xmlHttp.responseText);
    }
    else {
      tinyMCE.activeEditor.dom.add(el, 'span', {id : 'cr'+resultKey}, xmlHttp.responseText);
    }
    var myNode = tinyMCE.activeEditor.getDoc().getElementById('cr'+resultKey) 
    myNode.scrollIntoView(false);
  }
  else {
    alert("Results Web Service Not Available or Configured")
  }
}
function AppendResults() {
  confirmMsg="This will append the latest 10 clinical results for this patient visit.\n"+
             "It should be done after you have completed the rest of the discharge summary.\n"+
             "Click Ok to Continue"
  if (confirm(confirmMsg)) {
    page="cliweb10.pbl?reportno=06&template=004"
    theURL=page+'&urnumber='+UpdateForm.urnumber.value.replace(/ /g,"+")+
                '&admissno='+UpdateForm.admissno.value.replace(/ /g,"+")
    xmlHttp.open("GET", theURL, false);
    xmlHttp.send();
    if (xmlHttp.status=="200") {
      var el=tinyMCE.activeEditor.dom.get('clinicalResultsSection');
      if (el == null) {
        tinyMCE.activeEditor.dom.add(tinyMCE.activeEditor.getBody(), 'span', {id : 'clinicalResults'}, xmlHttp.responseText);
      }
      else {
        tinyMCE.activeEditor.dom.add(el, 'span', {id : 'clinicalResults'}, xmlHttp.responseText);
      }
      var myNode = tinyMCE.activeEditor.getDoc().getElementById('clinicalResults') 
      myNode.scrollIntoView(false);
    }
    else {
      alert("Results Web Service Not Available or Configured")
    }
  }
}
function setHCPPracticeAddress() {
  if (UpdateForm.corsp008.value==DefaultValues.gpcode.value) {
      return; }
/* New template to return hcp practice details */
  theURL='patweb99.pbl?reportno=4&template=020'+
      '&genpcode='+UpdateForm.corsp008.value.substr(0,10).replace(/ /g,'+')+
      '&genpprac='+UpdateForm.corsp008.value.substr(10,10).replace(/ /g,'+')+
      '&genppcnt='+UpdateForm.corsp008.value.substr(20,2).replace(/ /g,'+');
  xmlHttp = createHttpObject(); 
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
      eval(xmlHttp.responseText)
      var pracname=document.getElementById("pracname");
      pracname.value=hcpPracname;
      insStr=trim(hcpTitle)+' '+trim(hcpGiven)+' '+trim(hcpSurname);
      tinyMCE.activeEditor.dom.setHTML('toDoctor', insStr);
      insStr='Dear '+trim(hcpTitle)+' '+trim(hcpSurname)+',';
      tinyMCE.activeEditor.dom.setHTML('toSalutation', insStr);
      insStr=hcpPracname
      if (!isWhitespace(hcpAddress1)) insStr+='<br>'+hcpAddress1
      if (!isWhitespace(hcpAddress2)) insStr+='<br>'+hcpAddress2
      if (!isWhitespace(hcpAddress3)) insStr+='<br>'+hcpAddress3
      if (!isWhitespace(hcpAddress4)) insStr+='<br>'+hcpAddress4
      insStr+=trim(hcpAddress5)+' '+hcpPostcode
      insStr+='<br><br>Fax : '+hcpFax
      tinyMCE.activeEditor.dom.setHTML('toAddress', insStr);
    }
    else {
      alert("GP Web Service Not Available or Configured")
    }
}
function setDocumentAddress() {
  if (UpdateForm.corsp008.value==DefaultValues.gpcode.value) {
      return; }
  theURL='patweb99.pbl?reportno=6&template=020'+
         '&pmhcp001='+UpdateForm.corsp008.value.replace(/ /g,'+')
  xmlHttp = createHttpObject(); 
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
      setDoctorAddress(xmlHttp.responseText);
    } else {
      alert("GP Web Service Not Available or Configured")
    }
}
function setDoctorAddress(hcpValues) {
  eval(hcpValues)
  insStr=trim(hcpTitle)+' '+trim(hcpGiven)+' '+trim(hcpSurname);
  tinyMCE.activeEditor.dom.setHTML('fromName', insStr);
  insStr='Dear '+trim(hcpTitle)+' '+trim(hcpSurname)+',';
  tinyMCE.activeEditor.dom.setHTML('toSalutation', insStr);
  insStr=hcpAddress1
  if (!isWhitespace(hcpAddress2)) insStr+='<br>'+hcpAddress2
  if (!isWhitespace(hcpAddress3)) insStr+='<br>'+hcpAddress3
  if (!isWhitespace(hcpAddress4)) insStr+='<br>'+hcpAddress4
  insStr+=trim(hcpAddress5)+' '+hcpPostcode
  insStr+='<br><br>Fax : '+hcpFax
  tinyMCE.activeEditor.dom.setHTML('toAddress', insStr);
}
function setCarbonCopy() {
  if  (isWhitespace(UpdateForm.carbonCopyID.value)) {
    return; }
  theURL='patweb99.pbl?reportno=6&template=020'+
         '&pmhcp001='+UpdateForm.carbonCopyID.value.replace(/ /g,'+')
  xmlHttp = createHttpObject();
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
      setCarbonCopyAddress(xmlHttp.responseText);
    }
    else {
      alert("GP Web Service Not Available or Configured")
    }
}
function setCarbonCopyAddress(hcpValues) {
  eval(hcpValues)
  insStr='CC: '+trim(hcpTitle)+' '+hcpGiven.substr(0,1)+' '+trim(hcpSurname)+'<br>';
  tinyMCE.activeEditor.dom.add(tinyMCE.activeEditor.getBody(), 'span', {id : 'ccName'+hcpSurname}, insStr);
  insStr=hcpAddress1
  if (!isWhitespace(hcpAddress2)) insStr+='<br>'+hcpAddress2
  if (!isWhitespace(hcpAddress3)) insStr+='<br>'+hcpAddress3
  if (!isWhitespace(hcpAddress4)) insStr+=',  '+hcpAddress4
  insStr+=trim(hcpAddress5)+' '+hcpPostcode+'<br><br>'
  tinyMCE.activeEditor.dom.add(tinyMCE.activeEditor.getBody(), 'span', {id : 'ccAddress'}, insStr);
  var myNode = tinyMCE.activeEditor.getDoc().getElementById('ccName'+hcpSurname) 
  myNode.scrollIntoView(false);
}
function loadDocument() {
  if (editFlag) {
    theURL="cliweb08.pbl?reportno=1&template=31&detailky="+editDocument.replace(/ /g,"+")
    xmlHttp = createHttpObject();
    xmlHttp.open("GET", theURL, false);
    xmlHttp.send();
    if (xmlHttp.status=="200") {
      UpdateForm.copyfkey.value=xmlHttp.responseText.split("|")[0];
      theURL=xmlHttp.responseText.split("|")[1];
      UpdateForm.corsp010.value=xmlHttp.responseText.split("|")[2];
      UpdateForm.corsp007.value=xmlHttp.responseText.split("|")[3];
      UpdateForm.corsp008.value=xmlHttp.responseText.split("|")[4].split("^")[0];
      UpdateForm.printfmt.value=xmlHttp.responseText.split("|")[4].split("^")[1];
      documentType=trim(xmlHttp.responseText.split("|")[5]);
      el = UpdateForm.corsp003

      for (i=0;i<el.options.length;i++) { 
       if (trim(el.options[i].value.substr(0,3))==documentType) el.selectedIndex=i; 
      }
      setDocumentFields();
      el = UpdateForm.corsp003
      el.readonly = true;
      el.disabled = true;
      el = UpdateForm.docttemp
      el.className = "";
      el = document.getElementById('documentTemplateSection');
      el.style.display='none';
      xmlHttp.open("GET", theURL, false);
      xmlHttp.send();

      var html = xmlHttp.responseText.replace(/\stype="checkbox"/gi," type=checkbox onclick=this.setAttribute('checked',this.checked);");

      tinyMCE.get('documentContent').setContent(html);
      updateDocumentValues();
      validateCode('18',UpdateForm.corsp008,UpdateForm.corsp009);
      setDocumentAddress();
    }
    else {
      alert("Web Service Not Available. Check your Connection and Try Again.");
    }
  }
}
function updateDocumentValues() {
  el=document.updateValues
  for (i=0;i<el.length;i++) {
    tinyMCE.activeEditor.dom.setHTML(el[i].name, el[i].value);
  }
}
function setSend(el) {
 sendType=el.options[el.selectedIndex].value
 fs=document.getElementById("sendFaxNumber");
 fe=document.getElementById("sendEmailFrom");
 te=document.getElementById("sendEmailTo");
 fs.style.display='none';
 fe.style.display='none';
 te.style.display='none';

 doctorCode = DefaultValues.atdrcode;
 if (doctorCode.value.length == 0){
   doctorCode = DefaultValues.emvcode;
 }

 if (sendType==1) {
   eval(setHCPDetails(DefaultValues.gppcode))
   fs.style.display='';
   UpdateForm.sendtoph.value=hcpFax.replace(/ /g,"");
 }
 if (sendType==2) {
   fe.style.display='';
   te.style.display='';

   eval(setHCPDetails(DefaultValues.gpcode))
   UpdateForm.sendtoem.value=hcpSurgeryEmail.trim();

   eval(setHCPDetails(doctorCode));
   UpdateForm.sendfrem.value=hcpSurgeryEmail.trim();
 }
}
function setHCPDetails(HCPcode) {
  theURL='patweb99.pbl?reportno=6&template=020'+
         '&pmhcp001='+HCPcode.value.replace(/ /g,'+')
  el=UpdateForm.corsp010
  if (el.searchType=="8") {
    var cod=UpdateForm.corsp008.value.split("|")[0];
    var cnt=UpdateForm.corsp008.value.split("|")[1];
    theURL='patweb99.pbl?reportno=5&template=020'+
           '&pmhcg001='+cod.replace(/ /g,'+')
           '&pmhcg002='+cnt.replace(/ /g,'+')
  }
  xmlHttp = createHttpObject();
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();

  if (xmlHttp.status=="200") {
      return xmlHttp.responseText;
    }
  else {
    alert("GP Web Service Not Available or Configured")
    return;
  }
}
//------------------------------------------------------------
// Setup HTML Editor
//------------------------------------------------------------
function SetTinyMCE() {
  tinyMCE.init({
  mode: "exact",
  elements : "documentContent",
  init_instance_callback : "loadDocument" ,
  theme : "advanced", 
  plugins : "spellchecker,pagebreak,advlink,advimage,style,table,iespell,inlinepopups,searchreplace,contextmenu,paste,noneditable,visualchars,nonbreaking,xhtmlxtras",
  visual : false, 
  relative_urls : false,
  content_css : "../html/tinymce.css", 
  font_formats : "Arial=arial,helvetica", 
  tm_fonts : "Arial=arial,helvetica", 
  custom_elements : 'page-header,page-body,page-footer',
  extended_valid_elements : 'page-header,page-body,page-footer',
  theme_advanced_font_sizes: "10px,12px,13px,14px,16px,18px,20px", 
  font_size_style_values : "10px,12px,13px,14px,16px,18px,20px",
  theme_advanced_toolbar_location : "top",
  theme_advanced_toolbar_align : "left",
//  theme_advanced_fonts : "Arial=arial;Courier New=Courier New",
  theme_advanced_statusbar_location : "bottom",
  theme_advanced_resizing : true,
  theme_advanced_buttons1 : "bold,italic,underline,strikethrough,|,justifyleft,justifycenter,justifyright,justifyfull,|,formatselect,fontselect,fontsizeselect",
  theme_advanced_buttons2 : "cut,copy,paste,pastetext,pasteword,|,search,replace,|,bullist,numlist,|,outdent,indent,blockquote,|,undo,redo,|,forecolor,backcolor,|,table,delete_table,|,row_after,delete_row,|,col_after,delete_col",
  theme_advanced_buttons3 : "",
  theme_advanced_buttons4 : "",
  entity_encoding : "raw"
  });
}
//-----------------------------------------------------------------------------
// submit list of services to server
//-----------------------------------------------------------------------------
function CreateDocument(documentStatus) {
  var bool = validateMandatory(UpdateForm);
  if (documentStatus=="D") {
    if (!isWhitespace(document.UpdateForm.printfmt.value)) {
      if (trim(document.UpdateForm.printfmt.value) != "undefined") {
        UpdateForm.corsp008.value=
        UpdateForm.corsp008.value.replace(/ /g,"")+"^"+UpdateForm.printfmt.value
      }
    }
    UpdateForm.draftdoc.value="1";
    UpdateForm.sendtype.selectedIndex=0;
  } else if (documentStatus=="F") {
    tinyMCE.activeEditor.dom.setHTML('dateSent',document.UpdateForm.corsp002.value);
    tinyMCE.activeEditor.dom.setHTML('summaryStatus','Final');
  }

  var html = tinyMCE.get('documentContent').getContent({format : 'raw'});

  html = html.replace(/\sonclick=['"]?this\.setattribute\(['"]checked['"],this\.checked\);?['"]?/gi,'').replace(/\schecked=['"]false['"]/gi,'').replace(/\schecked=['"]true['"]/gi,' checked');

  UpdateForm.htmlline.value = html;

  if(bool) {
    theURL=document.UpdateForm.action;
    var postStr=AJAXPostString(document.UpdateForm)
    xmlHttp = createHttpObject();
    xmlHttp.open("POST", theURL, false);
    xmlHttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded; charset:UTF-8");
    xmlHttp.send(postStr);
    if (xmlHttp.status=="200") {
      if (xmlHttp.responseText.match(/PROCESSING|OK/i)) {
        if (document.UpdateForm.nihchrin.value == "1") {
          SetCookie("NIHCIHIMyHRUploadCOOKIE",'1');
          location.href=document.UpdateForm.myhrredr.value;
          return;
        }

        if (document.getElementById('histflag')!=null &&
            document.getElementById('histflag').value=='1') {
              location.href = "cliweb08.pbl?reportno=01&template=030i"+
               '&urnumber='+UpdateForm.urnumber.value.replace(/ /g,"+")+
               '&admissno='+UpdateForm.admissno.value.replace(/ /g,"+")
        } else {
          if (document.getElementById('cretdcck') != null &&
              !isWhitespace(document.getElementById('cretdcck').value)) {
            location.href=document.getElementById('cretdcck').value;
          } else {
              location.href = "cliweb08.pbl?reportno=01&template=030i"+
               '&urnumber='+UpdateForm.urnumber.value.replace(/ /g,"+")+
               '&admissno='+UpdateForm.admissno.value.replace(/ /g,"+")
          }
        }
      }
      else {
        alert(xmlHttp.responseText.replace(/.*alert../i,"").replace(/.\).*/i,""));
      }
    }
    else {
      alert("Web Service Not Available. Check your Connection and Try Again.");
    }
  }
  return bool
}
//-----------------------------------------------------------------------------
// submit list of services to server
//-----------------------------------------------------------------------------
function CreateCopy(documentStatus) {
  var bool = validateMandatory(UpdateForm);

  var html = tinyMCE.get('documentContent').getContent({format : 'raw'});

  html = html.replace(/\sonclick=['"]?this\.setattribute\(['"]checked['"],this\.checked\);?['"]?/gi,'').replace(/\schecked=['"]false['"]/gi,'').replace(/\schecked=['"]true['"]/gi,' checked');

  UpdateForm.htmlline.value = html;

  if(bool) {
    theURL=document.UpdateForm.action;
    var postStr=AJAXPostString(document.UpdateForm);
    xmlHttp = createHttpObject();
    xmlHttp.open("POST", theURL, false);
    xmlHttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded; charset:UTF-8");
    xmlHttp.send(postStr);
    if (xmlHttp.status=="200") {
      if (xmlHttp.responseText.match(/PROCESSING|OK/i)) {
         alert("Document Saved. Copy Created")
      }
      else {
        alert(xmlHttp.responseText.replace(/.*alert../i,"").replace(/.\).*/i,""));
      }
    }
    else {
      alert("Web Service Not Available. Check your Connection and Try Again.");
    }
  }
  return bool
}
//-----------------------------------------------------------------------------
// set options for number of copies
//-----------------------------------------------------------------------------
function SetCopies(ListItem,MaxCopy) {
  for (i=1;i<MaxCopy;i++) {
    ListItem.options[ListItem.options.length]=new Option(i,i);
  }
}
//========================================================================
// Format POST String for AJAX Form Post
//========================================================================
function AJAXPostString(el) {
  parameters="";
  for (i=0;i<el.length;i++) {
    switch (el[i].type) {
     case 'radio': {
       if (el[i].checked) {
         parameters+=el[i].name+"="+el[i].value+"&";
       }
       break; }
     case 'checkbox': {
       if (el[i].checked) {
         parameters+=el[i].name+"="+el[i].value+"&";
       }
       break; }
     case 'hidden': {
       parameters+=el[i].name+"="+el[i].value+"&";
       break; }
     case 'select-one': {
       if (el[i].selectedIndex!=-1) {
         parameters+=el[i].name+"="+el[i].options[el[i].selectedIndex].value +"&";
       }
       break; }
     case 'text': {
       parameters+=el[i].name+"="+el[i].value+"&";
       break; }
     case 'textarea': {
       if (el[i].className=="setLinefeeds") {
         textareaValue=setLinefeeds(el[i].value,el[i].cols);
         parameters+=el[i].name+"="+textareaValue+"&";
       }
       else {
         parameters+=el[i].name+"="+el[i].value+"&";
       }
       break; }
    }
  }
  parameters+='1=1';
  return parameters;
}
function setLinefeeds(textValue,colLength) {
  returnValue="";
  while (textValue.length>colLength) {
    if (textValue.lastIndexOf("\n",colLength)>0) {
      returnValue+=encodeURIComponent(textValue.substr(0,textValue.lastIndexOf("\n",colLength)))+"\n";
      textValue=textValue.substr(textValue.lastIndexOf("\n",colLength));
      continue;
    }
    if (textValue.lastIndexOf("\r",colLength)>0) {
      returnValue+=encodeURIComponent(textValue.substr(0,textValue.lastIndexOf("\r",colLength)))+"\n";
      textValue=textValue.substr(textValue.lastIndexOf("\r",colLength));
      continue;
    }
    if (textValue.lastIndexOf(" ",colLength)>0) {
      returnValue+=encodeURIComponent(textValue.substr(0,textValue.lastIndexOf(" ",colLength)))+"\n";
      textValue=textValue.substr(textValue.lastIndexOf(" ",colLength));
      continue;
    }
    if (textValue.lastIndexOf("&nbsp;",colLength)>0) {
      returnValue+=encodeURIComponent(textValue.substr(0,textValue.lastIndexOf("&nbsp;",colLength)))+"\n";
      textValue=textValue.substr(textValue.lastIndexOf("&nbsp;",colLength));
      continue;
    }
    returnValue+=encodeURIComponent(textValue.substr(0,colLength)+"\n");
    textValue=textValue.substr(colLength);
  }
  returnValue+=encodeURIComponent(textValue);
  return returnValue;
}
//------------------------------------------------------------
// findPos - following function returns the position of a object
//------------------------------------------------------------
function findPos(obj) {
  var curleft = curtop = 0;
  if (obj.offsetParent) {
    do { curleft += obj.offsetLeft;
         curtop += obj.offsetTop;
       } while (obj = obj.offsetParent);
  }
  return [curleft,curtop];
}
function loadTemplate() {
  el=UpdateForm.docttemp;
  page=el.options[el.selectedIndex].value;
  UpdateForm.printfmt.value=printFormat[el.selectedIndex];

  if (isWhitespace(page)) return;
  theURL=page+'&urnumber='+UpdateForm.urnumber.value.replace(/ /g,"+")+
              '&admissno='+UpdateForm.admissno.value.replace(/ /g,"+")
  xmlHttp = createHttpObject();
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
    var html = xmlHttp.responseText.replace(/\stype="checkbox"/gi," type=checkbox onclick=this.setAttribute('checked',this.checked);");
    tinyMCE.get('documentContent').setContent(html);
  }
  else {
    alert("Web Service Not Available. Check your Connection and Try Again.");
  }
}
function clearTemplate() {
  tinyMCE.get('documentContent').setContent("");
}
function setSubjectTo(typeStr,valueStr) {
  if (!isWhitespace(valueStr)) {
    el=UpdateForm.corsp007
    switch (typeStr) {
      case "TEXT":
        el.value=valueStr;
        break;
      case "UNIT":
        el.value=trim(DefaultValues.unitname.value)+" "+valueStr;
        break;
    }
  }
}
function setSendTo(typeStr,valueStr) {
  el=UpdateForm.corsp010
  switch (typeStr) {
    case "TEXT":
      el.value=valueStr;
      el.onfocus="";
      el.onkeyup="";
      break;
    case "HCP":
      el.value=DefaultValues.gpname.value;
      UpdateForm.corsp008.value=DefaultValues.gpcode.value;
      el.setAttribute("searchType","1");
//    el.onfocus=function () { this.value=''; } ;
      el.onkeyup=function () { AutoSuggest(); };
      break;
    case "PRACTICE":
      el.value=DefaultValues.gpname.value;
      UpdateForm.corsp008.value=DefaultValues.gpcode.value;
      el.setAttribute("searchType","8");
//    el.onfocus=function () { this.value=''; } ;
      el.onkeyup=function () { AutoSuggest(); };
      break;
    case "HCPPRAC":
      el.value=DefaultValues.gpname.value;
      UpdateForm.corsp008.value=DefaultValues.gpcode.value;
      if (UpdateForm.pracname != undefined) {
        UpdateForm.pracname.value=DefaultValues.gppname.value;
      }
      el.setAttribute("searchType","10");
//    el.onfocus=function () { this.value=''; } ;
      el.onkeyup=function () { AutoSuggest(); };
      break;
    case "PATIENT":
      el.value=trim(DefaultValues.pattitle.value)+" "+
               trim(DefaultValues.patgname.value)+" "+
               trim(DefaultValues.patsname.value)
      el.onfocus=""
      el.onkeyup="";
      break;
  }
}
function clearDocumentTemplate() {
  el=UpdateForm.docttemp
  el.options.length=0;
  printFormat.length=0;
  subjectList.length=0;
}
function addDocumentTemplate(nameStr,valueStr,printFmt,subjectTxt) {
  el=UpdateForm.docttemp
  printFormat[el.options.length]=printFmt;
  subjectList[el.options.length]=subjectTxt;
  el.options[el.options.length]=new Option(nameStr,valueStr);
}
function EditDocument(DocumentURL) {
  theURL=DocumentURL;
  xmlHttp = createHttpObject(); 
  xmlHttp.open("GET", theURL, false);
  xmlHttp.send();
  if (xmlHttp.status=="200") {
    var html = xmlHttp.responseText.replace(/\stype="checkbox"/gi," type=checkbox onclick=this.setAttribute('checked',this.checked);");

    tinyMCE.get('documentContent').setContent(html);
  }
  else {
    alert("Web Service Not Available. Check your Connection and Try Again.");
  }
}
function SelectFromList(Server,ServerOpt,ServerTmp) {

  PatientLinks.action=Server;
  PatientLinks.reportno.value=ServerOpt;
  PatientLinks.template.value=ServerTmp;

  DFrameStart();

  var PopUpScreen = document.getElementById('PopUpScreen');
  var PatientMenu = document.getElementById('PatientMenu');
  var MaxWidth  = getTop().content.clientWidth;
  var MaxHeight;
  var top = 0;

  PatientLinks.target="PopUpFrame";
  PatientLinks.submit();

  if (PatientMenu) {
    top = PatientMenu.offsetTop + PatientMenu.offsetHeight;

    MaxHeight = document.body.clientHeight
                - PatientMenu.offsetTop
                - PatientMenu.offsetHeight;

  } else {
    top       = document.body.scrollTop;
    MaxHeight = document.body.clientHeight;
  }

  var h = MaxHeight-25;
  PopUpScreen.style.top     = top+ "px";
  PopUpScreen.style.left    =  "0px";
  PopUpScreen.style.height  = h + "px";
  PopUpScreen.style.width   = "33%";
  PopUpScreen.style.display = "";

}
