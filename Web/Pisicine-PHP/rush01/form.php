<?php

/* 
** Cette fonction affiche une formulaire d'ordre adapté au
** vaisseau qu'elle reçoit en parametre. Les résultats sont
** retournés sous forme de tableau a la page suivante dans $_POST[].
*/ 

function form_order($vessel) {
	echo "	<div>
				<link rel='stylesheet' type='text/css' href='form.css'>
				<form class='formulaire' action='go_to_movement' method='POST'>
					<input type='number' min='0' max='".$vessel->nb_pp."'name='pp_speed' placeholder='PP'>&nbsp PP attribué(s) à la vitesse</br>
					<input type='number' min='0' max='".$vessel->nb_pp."'name='pp_shield' placeholder='PP'>&nbsp PP attribué(s) au bouclier</br>";

	foreach ($vessel->weapon as $weapon) {
		echo "		<input type='number' min='0' max='".$vessel->nb_pp."'name='pp_".$weapon."' placeholder='PP'>&nbsp PP attribué(s) à l'arme ".$weapon."</br>";
	}

	if ($vessel->is_still) {
		echo "		<input type='number' min='0' max='".$vessel->nb_pp."'name='pp_repair' placeholder='PP'>&nbsp PP attribué(s) à la réparation</br>";
	}

	echo "			<input type='submit' value='Confirm'>
				</form>
			</div>";
}

/* echo "<meta charset='utf8'>";

class Bateau { 
	public $weapon = array('1' => "pistolet", '2' => 'fusil', '3' => 'bazooka');
	public $nb_pp = 9;

	public $is_still = true;
}

$black_pearl = new Bateau;

form_order($black_pearl);*/

function check_bdd($key, $value, $bdd)
{
	if (!file_exists("bdd/".$bdd))
		return false;

	$tab = unserialize(file_get_contents("bdd/".$bdd));

	foreach ($tab as $stuff)
		if ($stuff[$key] === $value)
			return true;

	return false;
}

/*
** Cette fonction affiche un le formulaire d'enregistrement; 
** Ce formulaire est verifie par la fonction check_register() sur index.php 
** qui creera un utilisateur si tout est bon
*/
function display_register() {
	echo "	<div>
				<link rel='stylesheet' type='text/css' href='form.css'>
				<form class='formulaire' action='index.php' method='POST'>
					<a>Veuillez entrer votre nom d'utilisateur :</a></br><input type='text' name='login' placeholder='Login'></br>
					<a>Veuillez entrer votre mot de passe :</a></br><input type='password' name='password' placeholder='Password'></br>
					<a>Veuillez verifier votre mot de passe :</a></br><input type='password' name='passwordbis' placeholder='Password'></br>
					<input type='submit' name='sign_up' value='Register'>
				</form>
	";
}

function new_user($id, $pw)
{
	$user = unserialize(file_get_contents("bdd/user.bdd"));

	//check if id is valid
	if (preg_match("#[^a-zA-Z0-9]#", $id) || strlen($id) > 10)
		return false;

	//check if pw is valid
	if (preg_match("#[^a-zA-Z0-9]#", $pw) || strlen($pw) > 16 || strlen($pw) < 5)
		return false;

	$id = htmlspecialchars($id);
	//check if id/mail exists


	$new_user["login"] = $id;
	$new_user["password"] = hash("whirlpool", $pw);


	$user[] = $new_user;
	file_put_contents('bdd/user.bdd', serialize($user));

	return true;
}

function check_register() {
	if (!check_bdd('login', $_POST['login'], 'user.bdd') && strlen($_POST['password']) > 5 && $_POST['password'] === $_POST['passwordbis']) {
		new_user($_POST['login'], $_POST['password']);
		$_SESSION['loggued_on_user'] = $_POST['login'];
		header('Location: lobby.php');
	}
}
?>