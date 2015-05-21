<?php   session_start();
            include 'login_exist.php';
            if (!$_SESSION['loggued_on_user'] || $_SESSION['loggued_on_user'] == "")
                $_SESSION["guest"] = "OK";
            if ($_GET[user] && $_GET[product])
            {
                $tab = unserialize(file_get_contents("../private/passwd"));
                $i = login_exist($tab, $_GET[user]);
                $tab[$i]['order'][] = $_GET[product];
                if ($i != -1)
                    file_put_contents("../private/passwd", serialize($tab));
            }
            if ($_SESSION["guest"] == "OK")
            {
                if (!isset($_SESSION["tmp"]))
                {
                    $tmp = array();
                    $_SESSION["tmp"] = $tmp;
                }
                if ($_GET[product])
                    array_push($_SESSION["tmp"], $_GET[product]);
			}
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
		
	<title>Yummy</title>
	<link href='http://fonts.googleapis.com/css?family=Dancing+Script:700' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" type="text/css" href="css/general.css">
	<link rel="stylesheet" type="text/css" href="css/index.css">
</head>
<body>
	<div id="header">
		<div id="logo">
			<h1><a href="index.php">Yummy</a></h1>
		</div>
		<?php if (!$_SESSION['loggued_on_user']) : ?>
				<div id="form">
					<form id="form1" method="POST" action="check_user.php">
						<div id="log">
                    		<input type="text" name="login" placeholder="Nom d'utilisateur">
                   		 	<input type="password" name="passwd" placeholder="Mot de passe">
                  		  	<input class="button" type="submit" name="register" value="Se connecter">
                		</div>
                		<input id="reg" class="button" type="submit" name="register" value="S'inscrire">
            		</form>
				</div>
		<?php endif ?>
		<?php if ($_SESSION['loggued_on_user']) : ?>
				<div id="logout">
					<form  method="POST" action="logout.php">
						<input class="button" type="submit" name="deconnexion" value="logout">
					</form>
				</div>
		<?php endif ?>
	</div>
	<div id="main">
        <div id="menu">
            <form>
                <ul>
                    <li><a href="./index.php?cat=base_fr">Gourmandise francaise</a></li>
                    <li><a href="./index.php?cat=base_asie">Delices d'Asie</a></li>
                    <li><a href="./index.php?cat=base_desserts">Desserts</a></li>
                </ul>
            </form>
        </div>
        <div id="cart">
            <img src="Ressources/cart.png" title="cart">
            <ul>
                <form>
                    <?php
                        //print_r($_SESSION);
						//print_r($_SESSION['tmp']);
                        $tab = unserialize(file_get_contents("../private/passwd"));
                        $i = login_exist($tab, $_SESSION['loggued_on_user']);
                        if ($i > 0)
                        {
                            for ($j = 0; $tab[$i][order][$j]; $j++)
                                echo("<li>{$tab[$i][order][$j]}</li>");
                        }
                        else if ($i == -1)
                        {
                                $tab = $_SESSION["tmp"];
								foreach ($tab as $key => $product) {
                                    echo("<li>{$product}</li>");
                                }
                        }
                        if ($_SESSION["guest"] != "OK")
                            echo("<input class='button' type='submit' name='valid_order' value='Envoyer commande'>");
                    ?>
                </form>
            </ul>
		</div>
		<?php
            if (!isset($_GET['cat']))
                $cat = "base_fr";
            else
                $cat = $_GET['cat'];
			$tab = unserialize(file_get_contents("../private/{$cat}"));
            echo("<div id='catalog'>");
			for ($i = 0; $tab[$i]; $i++)
			{
                $photo = $tab[$i]['photo'];
                $name = $tab[$i]['id'];
                if (isset($_SESSION["loggued_on_user"]))
                    $user = $_SESSION["loggued_on_user"];
                else
                    $user = "guest";
				echo("<div class='col5'><img class='food' src=$photo><a href='./index.php?cat={$cat}&user={$user}&product={$name}'><input type='image' class='buy' src='Ressources/fork_knife.png' title='buy food' name=$name></a></div>");
			}
            echo("</div>");
		?>
        <!---<div id="catalog">
            <div class="col5">
                <img class="food" src="Ressources/asie/pho.jpg">
                <form method="POST" action="order.php">
                    <input type="image" class="buy" src="Ressources/fork_knife.png" title="buy food" name="$var">
                </form>
            </div>
            <div class="col5">
            </div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
            <div class="col5"></div>
        </div> --->
    </div>
</div>
</body>
</html>
