<?php

include 'login.php';
if (($_POST["register"] == "Se connecter") && (!$_POST["login"] || !$_POST["passwd"]))
		header('Location: index.php');
else
{
	if ($_POST["register"] == "Se connecter")
	{
		if (login($_POST[login], $_POST[passwd]) == 2)
			header('Location: admin/admin.php');	
		else if (login($_POST[login], $_POST[passwd]) == 3)
			header('Location: user.php'); // page de index normalement au lieu de user.php avec button mon compte et champs supprime//
		else
			header('Location: index.php'); // si temps mettre login ou pass faux //
	}
	else if ($_POST["register"] == "S'inscrire")
		header('Location: register.php');
}
?>
