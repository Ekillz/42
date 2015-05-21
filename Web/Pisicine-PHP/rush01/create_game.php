<?php
session_start();

// include('func/Zone.class.php');

class Zone {
	function __construct() {
		echo "La classe zone est construite";
		return ;
	}
}

// /!\ CLASS ZONE BUGGED ? PATH INCORRECT ? /!\

print_r($_POST);
if ($_POST['game_id'] && $_POST['create_game']) {
	$file = "bdd/".$_POST['game_id'].".bdd";
	echo ($file);
	if (file_exists($file))
		header('Location: lobby.php');
	else {
		$game = new Zone;                                       //Initialiser une GAME comme dans main.php
		file_put_contents($file, serialize($game));
		header('Location: ');                                    //GO TO NEW GAME
		$_SESSION['game_id'] = $_POST['game_id'];
	}
}
else if ($_POST['join_game']) {
	$file = "bdd/".$_POST['game_id'].".bdd";
	if (file_exists('$file')) {
		$_SESSION['game_id'] = $_POST['game_id'];
		print_r($_SESSION);
		// header('Location: ');                                 //GO TO JOIN GAME
	}
	else {
		header('Location: lobby.php');
	}
}
	
?>