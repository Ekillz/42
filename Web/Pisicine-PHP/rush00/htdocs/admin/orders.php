<?php
include '../unserialize.php';
include '../functions.php';
session_start();
if (!$_SESSION['admin'])
	header('Location: ../index.php');
$nb_order;
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
		function valid(){
			confirm("Valider la commande de $n produits?");
		}
		function confirm_del(){
			confirm("Etes-vous sur de vouloir supprimer la commande $n ?");
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
			<h2>Détails des commandes</h2>
			<p>Vous avez <?php echo count_products(unser("../../private/passwd")); ?> commandes en attente pour un total de <?php echo count_commands(unser("../../private/passwd"))." produits"; ?></p><br>
				<?php
				$i = 0;
				$tab = unser("../../private/passwd");
				while ($tab[$i])
				{
					if ($tab[$i]['order'])
					{
						$str = "Valider commande: ".$tab[$i]['login'];
						show_commands($tab, $i);
						echo ("<ul>");
						echo ("<form action='val_destroy_commands.php' method='post'>");
						echo ("<input onclick='valid()' type='submit' name='send' value='$str'>");
						echo ("</form>");
						echo ("</ul>");
					}
					$i++;
				}
				 ?>
				</ul>
				<form action="val_destroy_commands.php" method="post">
					Annuler commande<br>
					<br>
					ID commande<br>
					<input type="text" name="order">
					<input onclick="confirm_del()" type="submit" name="delete_order" value="Annuler la commande">
				</form>
			</div>
		</div>
	</div>
</body>
</html>
