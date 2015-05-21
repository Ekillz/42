<?php
if (($_SERVER['PHP_AUTH_USER'] != "zaz") || ($_SERVER['PHP_AUTH_PW'] != "jaimelespetitsponeys"))
{
	header('HTTP/1.0 401 Unauthorized');
	header('WWW-Authenticate: Basic realm=\'\'Espace membres\'\'');
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
}
else
{
	$file = file_get_contents('../img/42.png');
	$file = base64_encode($file);
	echo "<html><body>\n";
	echo "Bonjour Zaz<br />\n";
	echo "<img src='data:image/png;base64,".$file."'>\n";
	echo "</body></html>\n";
}
?>
