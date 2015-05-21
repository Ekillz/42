<?php
session_start();
$_SESSION["loggued_on_user"] = NULL;
$_SESSION["admin"] = NULL;
session_destroy();
header('Location: index.php');
?>
