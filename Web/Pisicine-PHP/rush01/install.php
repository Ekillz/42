<?php

if (!file_exists('bdd')) {
	mkdir('bdd');
	echo "Directory 'bdd' created\n";
}

if (!file_exists('bdd/user.bdd')) {
	$user = array();
	$admin = array('login' => "admin", 'password' => hash('whirlpool', 'admin'), 'highscore' => 0);
	$user[] = $admin;
	$s_user = serialize($user);
	file_put_contents('bdd/user.bdd', $s_user);
	echo "Admin account created, password : 'admin'\n";
}

?>
