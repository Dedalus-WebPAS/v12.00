//jsVersion  : V12.00.01
//========================================================================
// Program   : logintimeout.js
//========================================================================
// Variable declarations
var secTimeOutWarning = 9999999;  // Display Time Out Warning after 1200 seconds
var IBATimeOut=false;
//var webRoot = '/';                 // path to virtual web root
//=============================================================================
// Variable for webAS openIDC logout workflow IDP URL
// Blank in Standard.js - Populated (if openIDC is used) in Custom.js
//=============================================================================
var openIDCLogoutURL = "";


// Functional Declarations
//----------------------------------------------------------------------
//------------------------------------------------------------
// openIDC Logout Workflow (if used)
//-----------------------------------------------------------
function openIDCLogout() {
//  getTop().location.href=openIDCLogoutURL;
  window.location.href=openIDCLogoutURL;
  return;
}
//------------------------------------------------------------
// Flush Users Login Credentials and Return to Home Page
//------------------------------------------------------------
function FlushCredentials()
{
  if (window.navigator.userAgent.indexOf("MSIE") != -1)
  {
   // IE can do this from the browser level
    document.execCommand("ClearAuthenticationCache");
  }
  else
  {
    // all others need to be provoked - set up async unatorised call
    // this will fail with 401, prompting new authentication
    ExpireCookiePath('IBASecGroup');
//  var url= webRoot + "/cgi-bin/websec01.pbl?reportno=1&template=1&for=logoff";
    var url= "../cgi-bin/websec01.pbl?reportno=1&template=1&for=logoff";
    logoff = createHttpObject();
    logoff.open("GET",url,false,"nobody","");
    logoff.send(null);
    logoff.abort();
  }
  return;
}
function ExpireCookiePath(fieldName)
{
  var cookie_date = new Date ( );                // current date & time
  cookie_date.setTime ( cookie_date.getTime() - 1 );
  document.cookie = fieldName += "=; expires=" + cookie_date.toGMTString();
}
//------------------------------------------------------------
//  createHttpObject: set up object for Ajax_RSExecute calls
//------------------------------------------------------------
function createHttpObject()
{
  try
  {
    xmlHttp=new XMLHttpRequest(); // Firefox, Opera 8.0+, Safari
  }
  catch (e)
  {
    // Internet Explorer in newer or older form
    try
    {
      xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
    }
    catch (e)
    {
      try
      {
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      catch (e)
      {
        alert("Your browser does not support AJAX!");
        return false;
      }
    }
  }
  return xmlHttp;
}
//------------------------------------------------------------
// Flush Users Login Credentials and Return to Home Page
//------------------------------------------------------------
function Logout()
{
  if (!isWhitespace(openIDCLogoutURL)) {
    openIDCLogout();
  } else {
    FlushCredentials()
//    getTop().location.href= "/";
    window.location.href= "/";
  }
  return;
}
//----------------------------------------------------------------------
// Function : Time Out Warning
//----------------------------------------------------------------------
function TimeOutWarning()
{
  // set up the inevitable
  timerHandle = window.setTimeout('Logout()',15000); 

  // build and display a last chance frame
  PopUpFrame.document.open();
  PopUpFrame.document.write( "" +
//  '<link rel="stylesheet" href="../../html/standard.css" type="text/css">' +
//   "\n" +
//  '<link rel="stylesheet" href="../../html/custom.css" type="text/css">'
//   + "\n" +
  '<script type="text/javascript" src="../../js/Standard.js"></script>' + "\n" +
  "<style>\n" +
  ".logoff {" +
  "margin: 0;" +
  "background-color:#ff0000;" +
  "color: #ffffff; " +
  "font-style: sans serif;" +
  "font-size: 10pt;" +
  "text-align: center;" +
  "width:100%;" +
  "} \n" +
  "</style>\n</head>\n" +
  '<body class="logoff" ' +
  ' onclick="parent.location.reload();">' + "\n" +
  '<br /><strong>Message</strong>' + "\n" +
  '<br /><img src="../../images/InformationStatus.gif" align="absmiddle" />  ' +
  'Automatic Logout Triggered<br />Click Here to Abort');

  PopUpFrame.document.close()
  PopUpScreen.style.height=100;
  PopUpScreen.style.width=250;
  PopUpScreen.style.top=100;
  PopUpScreen.style.left=100;
  PopUpScreen.style.display="";
}
function isWhitespace (s) {
 var i;
 if (isEmpty(s)) return true;
 for (i = 0; i < s.length; i++) {
   var c = s.charAt(i);
   if (whitespace.indexOf(c) == -1) return false;
 }
    return true; // All characters are whitespace.
}
function isEmpty(s) {
 return ((s == null) || (s.length == 0))
}
function SetTimeOutWarning()
{
  if (secTimeOutWarning < 86400)
  {
    if (IBATimeOut != undefined && IBATimeOut)
      window.clearTimeout(IBATimeOut);
    IBATimeOut = window.setTimeout('TimeOutWarning()',secTimeOutWarning * 1000);
  }
  return;
}

function ResetTimeOutWarning()
{
  SetTimeOutWarning();
}
// Function Call
ResetTimeOutWarning();
//
