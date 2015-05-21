<?php

include 'unserialize.php';

function delete_product($id)
{
	$tab_asie = unser("../private/base_asie");
	$tab_fr = unser("../private/base_fr");
	$tab_desserts = unser("../private/base_desserts");
	$i = 0;
	while ($tab_asie[$i])
	{
		if ($tab_asie[$i]['id'] == $id)
			$tab_asie[$i] = NULL;
		$i++;
	}
	file_put_contents("../private/base_asie", serialize($tab_asie));
	$i = 0;
	while ($tab_fr[$i])
	{
		if ($tab_fr[$i]['id'] == $id)
			$tab_fr[$i] = NULL;
		$i++;
	}
	file_put_contents("../private/base_fr", serialize($tab_fr));
	$i = 0;
	while ($tab_desserts[$i])
	{
		if ($tab_desserts[$i]['id'] == $id)
			$tab_desserts[$i] = NULL;
		$i++;
	}
	file_put_contents("../private/base_desserts", serialize($tab_desserts));
}
?>
