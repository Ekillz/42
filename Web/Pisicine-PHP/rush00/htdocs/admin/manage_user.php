<?php
session_start();
if (!$_SESSION[admin])
	header('Location: ../index.php');
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Yummy</title>
	<link href='http://fonts.googleapis.com/css?family=Dancing+Script:700' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" type="text/css" href="../../css/general.css">
	<link rel="stylesheet" type="text/css" href="../../css/admin.css">
	<script>
		function confirm_del()
		{
			confirm("Etes-vous sur de vouloir supprimer l'utilisateur $n ?");
		}
	</script>
</head>
<body>
	<div id="header">
		<div id="logo">
			<h1><a href="../index.php">Yummy</a></h1>
		</div>
		<div id="form">
			<a class="admin_link" href="admin.php">Administration</a>
		</div>
	</div>
	<div id="main">
		<div id="panel">
			<div class="menu"><p><a href="orders.php">Commandes</a></p></div>
			<div class="menu"><p><a href="manage_user.php">Gestion utilisateurs</a></p></div>
			<div class="menu"><p><a href="manage_product.php">Gestion produits</a></p></div>
		</div>
		<div id="content">
			<div id="about">
			<h2>Gestion des utilisateurs</h2>
				<form action="../modif.php" method="post">
					Identifiant<br>
					<input type="text" name="login">
					<input onclick="confirm_del()" type="submit" name="delete_user" value="Supprimer l'utilisateur">
				</form>
					<br>
			</div>
		</div>
	</div>
</body>
</html>
