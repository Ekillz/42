#!/usr/bin/php
<?php
if (!file_exists("private"))
	mkdir("private");
$prod = array();
$prod[0] = "banh_lot";
$prod[1] = "bobun";
$prod[2] = "che_1";
$prod[3] = "che_2";
$prod[4] = "oyatsu";
$prod[5] = "pho";
$prod[6] = "raviolis";
$prod[7] = "sponge_roll";
$prod[8] = "trois_couleurs";
$i = 0;
$photo = array();
while ($prod[$i])
{
	$photo[$i] = "Ressources/asie/".$prod[$i].".jpg";
	$i++;
}
$i = 0;
while ($prod[$i])
{
	$tab[] = array("id" => $prod[$i], "photo" => $photo[$i]);
	$i++;
}
file_put_contents("private/base_asie",serialize($tab));
$prod2[0] = "choux";
$prod2[1] = "eclair_choco";
$prod2[2] = "entrecote";
$prod2[3] = "nicoise";
$prod2[4] = "quiche";
$prod2[5] = "ratatouille";
$prod2[6] = "terrine";
$i = 0;
$photo2 = array();
while ($prod2[$i])
{
	$photo2[$i] = "Ressources/fr/".$prod2[$i].".jpg";
	$i++;
}
$i = 0;
while ($prod2[$i])
{
	$tab2[] = array("id" => $prod2[$i], "photo" => $photo2[$i]);
	$i++;
}
file_put_contents("private/base_fr",serialize($tab2));
$prod3[0] = "banh_lot";
$prod3[1] = "che_1";
$prod3[2] = "che_2";
$prod3[3] = "choux";
$prod3[4] = "eclair_choco";
$prod3[5] = "oyatsu";
$prod3[6] = "sponge_roll";
$prod3[7] = "trois_couleurs";
$i = 0;
$photo3 = array();
while ($prod3[$i])
{
	$photo3[$i] = "Ressources/desserts/".$prod3[$i].".jpg";
	$i++;
}
$i = 0;
while ($prod3[$i])
{
	$tab3[] = array("id" => $prod3[$i], "photo" => $photo3[$i]);
	$i++;
}
file_put_contents("private/base_desserts",serialize($tab3));
$pass = hash('whirlpool', "epic");
$login = "admin";
$order = array();
$tab[] = array("login" => $login, "passwd" => $pass, "order" => $order);
file_put_contents("private/passwd",serialize($tab));
?>
