//jsVersion  : V12.00.00
//========================================================================
// Program   : patweb07.js
//
// Function  : Standard Functions Used in patweb07 templates
//
//========================================================================
//
// Admission / Master Details
//
//------------------------------------------------------------
// Report 4 functions
//------------------------------------------------------------

//Validate NDIS Number
function validateNDISNumber(NDISNumb,State) {

  //Checks if NDIS number matches requirements
  if (!checkNdisNumber(NDISNumb,State)) {
     var errorMsg = "NDIS Identifier - Must be numeric " + 
                    "and 9 digits in length";

     alert(errorMsg);
     NDISNumb.select();
     NDISNumb.focus();
     return false;
  }
  return true;
}

