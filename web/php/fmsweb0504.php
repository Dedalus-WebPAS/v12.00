<?php
/*
.----------------------------------------------------------------------
. Program       : fmsweb0504.php
.
. Function      : Send a simple message to the target address & port expecting
.                 it to be an EFTPOS pinpad. If we get a reply we can understand
.                 we have confirmed that we have a valid address/port.
.
. This program is called via AJAX from templates fmsweb0504002 & fmsweb0504003
.
. Modifications :
.     V11.04.01   01/08/2024  Don Nguyen    TSK 0948277
.                 Added an input filter around the GET parameter values to
.                 prevent XSS attacks and command injection.
.     V10.03.00   2012-12-04  Peter Mc.   Original
.----------------------------------------------------------------------
PRGID     INIT      "fmsweb0504.php"
VERSION   INIT      "V12.00.00"
PRGNAM    INIT      "EFTPOS Pinpad Interfacing"
.----------------------------------------------------------------------
*/
  error_reporting(0);

  // assume a fail until we know better 
  $replymsg = "";
  $address = 0;
  $port    = 0;

  if (isset($_GET['addr'])) {
    $address = filter_input(INPUT_GET,'addr',FILTER_VALIDATE_IP,FILTER_FLAG_IPV4);

    if ($address===false) $replymsg .= "Invalid address parameter. ";
  }
  else {
    $replymsg .= "Address parameter missing. ";
  }

  if (isset($_GET['port'])) {
    $port = filter_input(INPUT_GET,'port',FILTER_VALIDATE_INT);

    if ($port===false) $replymsg .= "Invalid port parameter. ";
  }
  else {
    $replymsg .= "Port parameter missing. ";
  }

  // if a parameter is missing, stop now
  if (strlen($replymsg)) reply(1,$replymsg);
 
  // Create a TCP/IP socket. 
  if (($socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false)
  {
    reply(2,"socket_create() failed: reason: " . socket_strerror(socket_last_error()));
  }

  // connect to the target 
  if (($result = socket_connect($socket, $address, $port)) === false)
  {
     $sockrc  = socket_last_error($socket);
     $sockmsg = socket_strerror($sockrc);
     reply(3, "Cannot connect to $address on port $port.\nReason: ($sockrc) $sockmsg");
  }

  $ping = "#0011K00000";  // this is a status request 

  // send the status chack (effectively a ping request) 
  socket_write($socket, $ping, strlen($ping));

  // get the '#LLLL' from the reply
  $fromhdr =  socket_read($socket,5);

  if (substr($fromhdr,0,1) != '#')
    reply(10,"Unrecognised response from $address");

  // get the remainder of the message 
  $len = substr($fromhdr,1,4) -5;
  $fromrest = socket_read($socket,$len);

  // and close the conversation
  socket_close($socket);

  // responding message must be a 'K' (same as request)
  if (substr($fromrest,0,1) != "K") 
    reply(10,"Unrecognised response from $address");

  // response code must not be 0
  if (substr($fromrest,2,1) == "0")
    reply(11,substr($fromrest,5,20));


  // if we get this far, all is fine 
  reply(0,substr($fromrest,5,20));


function reply($rc,$msg)
{
  echo   sprintf("%03d|%s",$rc,$msg);
  exit; 
}
?>
