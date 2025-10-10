//jsVersion  : V12.00.00
//==============================================================================
// Program   : DedalusDocumentTemplates.js
//==============================================================================
//
// This is used to define HTML document templates for the creation of new clinical documents.
// Any Number of Document Templates may be associated to a Clinical Document Type (cat wi).
// A document template is defined by a HTML Template that is associated with a web service.
//  setSendTo(<type>,<value>)
//   where <type> can be
//     TEXT     - Set the to field to the value.
//     HCP      - Set the to field to a HCP and default to the patients GP.
//     PATIENT  - Set the to field to the Patients Name.
//     PRACTICE - Set the to field to the Patients Name.
//     HCPPRAC  - Set the to field to the Patient's HCP Practice.
//
//  setSubjectTo(<type>,<value>
//   where <type> can be
//     TEXT    - Set the to field to the <value>.
//     UNIT    - Set the to field to the Unit Description Associated with the Patient.
//               Append anything in the <value> field
//
//  addDocumentTemplate(<display text>,<web service template URL>);
//     Any number of document templates can be defined for each document type
//     by adding multiple templates.
//------------------------------------------------------------------------------
//var validDocTypes="001|002|003|004";
var validDocTypes="015|001|002|003|004";
function showValidTypes() {
  el=UpdateForm.corsp003
  for (i=el.options.length-1;i>0;i--) {
    documentType=el.options[i].value.substr(0,3);
    if (validDocTypes.indexOf(documentType)<0) {
      el.remove(i);
    }
  }
}
function setDocumentFields() {
  DisableResults();
  DisableCarbonCopy();
  el=UpdateForm.corsp003
  documentType=el.options[el.selectedIndex].value.substr(0,3);
  switch (documentType) {
    case "015":
      EnableCarbonCopy();
      EnableResults();
      setFrom(documentType);
      break;
    case "002":
      EnableCarbonCopy();
      EnableResults();
      break;
    case "003":
      break;
    case "001":
      break;
  }
}
function setDocumentType() {
  var errCode = 0;
  clearDocumentTemplate();
  setDocumentFields();
  el=UpdateForm.corsp003

  documentType = el.options[el.selectedIndex].value.substr(0,3);

  if ((!isWhitespace(PatientVIS)) && (documentType != "")) {
    if(document.UpdateForm.ptvistyp.value == "3") {
      setSendTo("HCP","");
      setSendTo("HCPPRAC","");
      setSendTo("PRACTICE","");
      setFrom(documentType);
      setSubjectTo("TEXT","Inpatient Discharge Summary");
      addDocumentTemplate("IP Discharge Summary","cliweb06.pbl?reportno=09&template=304","","Discharge Summary");
      loadTemplate();
    } else if (document.UpdateForm.ptvistyp.value = "1"){
      setSendTo("HCP","");
      setSubjectTo("TEXT","Emergency Discharge Summary");
      setFrom(documentType);
      addDocumentTemplate("ED Discharge Summary","emrweb02.pbl?reportno=01&template=304","","Emergency Discharge Summary");
      loadTemplate();
    } else {
      errcode = 1; 
      setFrom(documentType);
      alert("Invalid Document Type, No Templates Available.")
      clearTemplate();
    } 
  } else {
    errcode=1;
    setFrom(documentType);
    alert("Invalid Document Type, No Templates Available.")
    clearTemplate();
  }


  /*
  documentType=el.options[el.selectedIndex].value.substr(0,3);
  switch (documentType) {
    case "015":
      break;
    case "002":
      break;
    case "003":
//      setFrom(documentType);
      setSendTo("TEXT","Hospital Medical Records");
      setSubjectTo("UNIT","Operation Summary");
      addDocumentTemplate("Operation Note   ","patweb98.pbl?reportno=01&template=304","","");
      loadTemplate();
      break;
    case "001":
//      setFrom(documentType);
      setSendTo("PATIENT","");
      setSubjectTo("TEXT","Sample Document Notes");
      addDocumentTemplate("","");
      addDocumentTemplate("Sample Patient Template ","patweb98.pbl?reportno=01&template=305","","");
      loadTemplate();
      break;
    case "004":
//      setFrom(documentType);
      setSendTo("TEXT","Hospital Medical Records");
      setSubjectTo("TEXT","  ");
      addDocumentTemplate("","");
      addDocumentTemplate("Progress Notes MR065     ","cliweb06.pbl?reportno=01&template=300&notetype=GEN","MR065","Progress Notes (MR065) Visit"+PatientVIS);
      addDocumentTemplate("Basic Observations       ","cliweb02.pbl?reportno=01&template=300","MR065","Basic Observations Visit"+PatientVIS);
      addDocumentTemplate("Neurological Observation ","cliweb02.pbl?reportno=01&template=301","MR065","Neurological Observation"+PatientVIS);
      addDocumentTemplate("Fluid Observation        ","cliweb02.pbl?reportno=01&template=302","MR065","Fluid Observation Visit"+PatientVIS);
      addDocumentTemplate("Observation Summary      ","cliweb02.pbl?reportno=01&template=303","MR065","Observation Summary Visit"+PatientVIS);
      addDocumentTemplate("Result Summary           ","cliweb10.pbl?reportno=06&template=003","MR065","Visit Results Summary"+PatientVIS);
      break;
    default:
//      setFrom(documentType);
      alert("Invalid Document Type, No Templates Available.")
      clearTemplate();
      errCode = 1;
      break;
  }
  */

  return errCode;
}
function setFrom(documentType) {
//  alert(window.fromDiV);
  if (window.fromDIV != undefined) {
    if (documentType == "015") {
      if (!isWhitespace(document.DefaultValues.emvidoct.value)) {
        document.updateValues.fromName.value=
        document.DefaultValues.emvidoct.value;
        document.updateValues.signatureName.value=
        document.DefaultValues.emvidoct.value;
        window.fromDIV.innerHTML=document.DefaultValues.emvidoct.value;
      }
    } else if (documentType == "002") {

       if (DefaultValues.atdrcode.value != "") {
         UpdateForm.corsp009.value = DefaultValues.atdrname.value; 
         UpdateForm.corsp008.value = DefaultValues.atdrcode.value; 
       } else {
         UpdateForm.corsp009.value = DefaultValues.emvidoct.value; 
         UpdateForm.corsp008.value = DefaultValues.emvcode.value; 
       }
    } else {
      window.fromDIV.innerHTML=document.DefaultValues.userfrom.value;
      UpdateForm.corsp009.value = DefaultValues.atdrname.value; 
      UpdateForm.corsp008.value = DefaultValues.atdrcode.value; 
    }
  }
}
