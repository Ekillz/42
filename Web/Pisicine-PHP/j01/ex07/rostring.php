#!/usr/bin/php
<?php
if ($argc > 1)
{
	$argv[1] = trim($argv[1], " ");
	$tab = explode(" ", $argv[1]);
	$tab = array_filter($tab);
	foreach ($tab as $elem)
		$str = $str." ".$elem;
	$argv[1] = $str;
	$argv[1] = trim($argv[1], " ");
	if (strpos($argv[1], " ") == FALSE)
		echo "{$argv[1]}\n";
	else
	{
		$new_str = explode(" ", $argv[1]);
		$i = 1;
		while ($new_str[$i])
		{
			echo $new_str[$i];
			echo " ";
			$i++;
		}
		echo $new_str[0];
		echo "\n";
	}
}
?>
