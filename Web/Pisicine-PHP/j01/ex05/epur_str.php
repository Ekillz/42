#!/usr/bin/php
<?php
	if ($argc == 2)
	{
		$argv[1] = trim($argv[1], " ");
		$tab = explode(" ", $argv[1]);
		$tab = array_filter($tab);
		$i = 0;
		foreach ($tab as $elem)
			$my_str = $my_str." ".$elem;
		$my_str = trim($my_str);
		echo $my_str;
		echo "\n";
	}
?>
