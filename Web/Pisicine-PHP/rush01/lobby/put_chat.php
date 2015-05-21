<?php
session_start();
echo ("<div id='chat'>");
echo ("<form name='form1')>");
echo ("Your message: <br />");
echo ("<textarea name='msg'></textarea><br />");
$user = '"'.$_SESSION['loggued_on_user'].'"';
echo ("<a href='#' onclick='submitChat(".$user.")'>Send </a><br /><br />");
echo ("</form>");
echo ("</div>");
echo ("<div id='chatlogs'>");
echo ("LOADING CHATLOGS PLEASE WAIT...");
echo ("</div>");
?>