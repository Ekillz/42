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

if ((!$_POST[login] || !$_POST[passwd]) && $_POST["register"] != "Se connecter")
	header('Location: register.php'); // si temps, mettre message user doit remplir 2 champs //
else
{
	if ($_POST[passwd] == $_POST[confirmation])
	{
		$tab = unserialize(file_get_contents("../private/passwd"));
		if (login_exist($tab) != 2)
		{
			$pass = hash('whirlpool', $_POST['passwd']);
			$login = $_POST['login'];
			$order = array();
			$tab[] = array("login" => $login, "passwd" => $pass, "order" => $order);
			file_put_contents("../private/passwd",serialize($tab));
			header('Location: index.php');
		}
		else
			header('Location: register.php'); // si temps, mettre message, user existe //
	}
	else
		header('Location: register.php'); // si temps mettre message passwd et confirmation ne match pas //
}
?>
