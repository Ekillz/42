<?php

if (!$dir)
{
	mkdir("../private");
	$dir = 1;
}

function login_exist($tab)
{
	foreach ($tab as $login)
	{
		foreach ($login as $log)
		{
			if ($log == $_POST['login'])
				return (2);
		}
	}
	return (0);
}

if (!$_POST[login] || !$_POST[passwd] || !$_POST[submit] || $_POST[submit] != "OK")
	echo "ERROR\n";
else
{
	$tab = unserialize(file_get_contents("../private/passwd"));
	if (login_exist($tab) != 2)
	{
		echo "OK\n";
		$pass = hash('whirlpool', $_POST['passwd']);
		$login = $_POST['login'];
		$tab[] = array("login" => $login, "passwd" => $pass);
		file_put_contents("../private/passwd",serialize($tab));
	}
	else
		echo "ERROR\n";
}
?>
