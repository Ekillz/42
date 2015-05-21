<?php

function unser($path)
{
	$tab = unserialize(file_get_contents($path));
	return ($tab);
}

?>
