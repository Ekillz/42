<?php

/*
** Fonction d'authentification de l'user, et du password
*/
function auth($id, $pw)
{
	if (!file_exists("bdd/user.bdd"))
		return false;

	$tab = unserialize(file_get_contents("bdd/user.bdd"));

	foreach ($tab as $stuff)
		if ($stuff['login'] === htmlspecialchars($id) && $stuff['password'] === hash("whirlpool", $pw))
			return true;

	return false;
}

function pack_game($game) {
    $file = "bdd/".$_SESSION'game_id'].".bdd";
    file_put_contents($file, serialize($game));    
}

function unpack_game() {
    $file = "bdd/".$_SESSION['game_id'].".bdd";
    if (file_exists($file)) {
        $game = unserialize(file_get_contents($file));
    }
}

function is_log() {
    if ($_POST['delog'] === "Deconnexion") {
        $_SESSION['loggued_on_user'] = "";
    }
    else if ($_SESSION['loggued_on_user']) {
        header('Location: lobby.php');
    }
    else if ($_SERVER['PHP_SELF'] === "index.php" && !$_SESSION['loggued_on_user']) {
         header('Location: index.php');
    }
    else
        return true;
}

function display_delog() {
    echo "    <div id='delog'>
                <form action='index.php' method='POST'>
                    <input type='submit' name='delog' value='Deconnexion'>
                </form>
            </div>
    ";
}

?>
