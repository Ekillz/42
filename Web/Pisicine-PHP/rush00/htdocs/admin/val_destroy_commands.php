<?php
session_start();
if (!$_SESSION['admin'])
	header('Location: ../index.php');

include '../functions.php';

if ($_POST['send'])
{
	validate_commands($_POST['send'], 0);
	header('Location: orders.php');
}
else if ($_POST['delete_order'] == "Annuler la commande")
{
	validate_commands($_POST['order'], 1);
	header('Location: orders.php');
}
?>
