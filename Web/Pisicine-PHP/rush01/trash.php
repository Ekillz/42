<?php
session_start();

include('form.php');
include('bdd.php');
check_register();
	if ($_POST['log'] === 'Deconnexion') {
		$_SESSION['loggued_on_user'] = "";
	}
	if ($_POST['log'] === 'Connexion' && !$_SESSION['loggued_on_user']) {
		if (auth($_POST['login'], $_POST['password'])) {
			$_SESSION['loggued_on_user'] = $_POST['login'];
			echo "logué";
		}
	}
	if ($_SESSION['loggued_on_user']) {
		echo "<div id='login_interface'>";
		echo "<p>Bonjour ".$_SESSION['loggued_on_user']."</p>";
		echo "	<form action=".$_SERVER['PHP_SELF']." method='POST'>
					<input type='submit' name='log' value='Deconnexion'>
				</form>";
		echo "</div>";
	}
	if (!$_SESSION['loggued_on_user']) {
		echo "<div id='login_interface'>";
		echo "	<form action=".$_SERVER['PHP_SELF']." method='POST'>
					<input type='text' name='login' placeholder='login'><br/>
					<input type='password' name='password' placeholder='password'><br/>
					<input type='submit' name='log' value='Connexion'>
				</form>";
		echo "</div>";
	}

 if (!$_SESSION['loggued_on_user'])
 	display_register();
?>