<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Yummy</title>
	<link href='http://fonts.googleapis.com/css?family=Dancing+Script:700' rel='stylesheet' type='text/css'>
	<link rel="stylesheet" type="text/css" href="../../css/general.css">
	<link rel="stylesheet" type="text/css" href="../../css/admin.css">
	<script>
		function confirm_del(){
			confirm("Etes-vous sur de supprimer le produit $n ?");
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
			<h2>Gestion des produits</h2>
				<form action="product.php" method="post">
					Produits<br><br>
					Nom produit<br>
					<input type="text" name="product_id"><br><br>	
					<textarea rows="4" cols="50" name="product_description" form="product.php">
					Entrer la description ici...</textarea><br><br>
					<input type="submit" name="add_product_id" value="Ajouter produit"><br><br>
					<input type="submit" name="deleter_product_id" value="Supprimer ID produit"><br><br>
				</form>
				
				<form action="upload.php" method="post" enctype="multipart/form-data">
				    Image produit<br><br>
				    <input type="file" name="product_id" id="fileToUpload">
				    <input type="submit" value="Upload" name="submit">
				</form>
					<br>
					<br>
				</form>
			</div>
		</div>
	</div>
</body>
</html>
