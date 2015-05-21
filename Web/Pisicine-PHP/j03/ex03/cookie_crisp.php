<?php
if ($_GET[action] == "set" && $_GET[name] && $_GET[value])
	setcookie($_GET[name], $_GET[value]);
else if ($_GET[action] == "get" && $_GET[name] && !$_GET[value])
{
	$str = $_COOKIE[$_GET[name]];
	if ($str)
		echo $str."\n";
}
else if ($_GET[action] == "del" && $_GET[name] && !$_GET[value])
	setcookie($_GET[name], $_GET[value], time() - 1337);
?>
