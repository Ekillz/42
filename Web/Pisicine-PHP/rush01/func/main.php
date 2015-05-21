<html>
<head>
<link href="wow.css" rel="stylesheet">
     </head>

     <body>

<?php

     require_once("Player.class.php");
require_once("Zone.class.php");
require_once("ExempleGun.class.php");
require_once("ExempleShip.class.php");

function init()
{

	$g1 = New ExempleGun();
	$g2 = New ExempleGun();
	$g3 = New ExempleGun();
	$g4 = New ExempleGun();

	$s1 = New ExempleShip([$g1, $g2, $g3]);
	$s2 = New ExempleShip([$g1, $g2, $g3]);
	$s3 = New ExempleShip([$g2, $g3]);
	$s4 = New ExempleShip([$g1, $g3]);

	$s1->setXMin(100);
	$s1->setXMax(110);
	$s1->setYMin(80);
	$s1->setYMax(84);

	$s2->setXMin(30);
	$s2->setXMax(40);
	$s2->setYMin(60);
	$s2->setYMax(64);

	$s3->setXMin(60);
	$s3->setXMax(70);
	$s3->setYMin(20);
	$s3->setYMax(24);

/*    
	echo "<pre>";
	print_r ($s3->getXMin().PHP_EOL);
	print_r ($s3->getYMin().PHP_EOL);
	print_r ($s3->getXMax().PHP_EOL);
	print_r ($s3->getYMax().PHP_EOL);
	echo "</pre>";
*/
    
	$s3->rotate("left");
	$s3->rotate("left");
	$s3->rotate("left");
	$s3->rotate("left");

    /*  
	echo "<pre>";
	print_r( $s3->getXMin().PHP_EOL);
	print_r( $s3->getYMin().PHP_EOL);
	print_r( $s3->getXMax().PHP_EOL);
	print_r( $s3->getYMax().PHP_EOL);
	echo "</pre>";
    */
    
	$p1 = New player([$s1, $s2]);
	$p2 = New player([$s3, $s4]);

	$z = new zone(array("p1" => $p1,
						"p2" => $p2));
	$z->aff_map();

	//SAVE $z TO BDD
}

function gameLoop()
{
	while (42)
	{
		//LOAD $z FROM BDD
		if (!$p1->play()) //use html form instead (cf. form.html)
		{
			echo "p2 won";
			break ;
		}
		if (!$p2->isAlive())
		{
			echo "p1 won";
			break ;
		}
		//SAVE $z TO BDD

		//LOAD $z FROM BDD
		if (!$p2->play()) //use html form instead (cf. form.html)
		{
			echo "p1 won";
			break ;
		}
		if (!$p1->isAlive())
		{
			echo "p2 won";
			break ;
		}
		//SAVE $z TO BDD
	}
}

init();
gameLoop();
echo "game over";

?>

</body>
</html>
