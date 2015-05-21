<?php

function login($login, $passwd)
{
	include 'auth.php';
	session_start();
	if (auth($login, $passwd) == 2)
	{
		$_SESSION["admin"] = "OK";
		$_SESSION["guest"] = NULL;
		$_SESSION["loggued_on_user"] = "admin";
		return (2);
	}
	else if (auth($login, $passwd) == 3)
	{
		$_SESSION["admin"] = NULL;
		$_SESSION["guest"] = NULL;
		$_SESSION["loggued_on_user"] = $login;
		return (3);
	}
	else
	{
		$_SESSION["admin"] = NULL;
		$_SESSION["guest"] = "OK";
		$_SESSION["loggued_on_user"] = NULL;
		return (4);
	}
	return (0);
}

?>
