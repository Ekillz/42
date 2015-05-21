<?php
session_start();
if ($_GET["submit"] == "OK")
{
	if ($_GET["login"])
		$_SESSION["login"] = $_GET["login"];
	if ($_GET["passwd"])
		$_SESSION["passwd"] = $_GET["passwd"];
	if (!$_SESSION["login"])
		$_SESSION["login"] = "";
	if (!$_SESSION["passwd"])
		$_SESSION["passwd"] = "";
}
?>
<html><body>
<meta charset="utf-8">
<form method="get" action="index.php">
identifiant : <br /><input type="text" name="login" value="<?php echo $_SESSION[login]; ?>"  size="16"><br>
mot de passe : <br /><input type="password" name="passwd" value="<?php echo $_SESSION[passwd]; ?>" size="16">
<input type="submit" value="OK">
</form></body></html>
