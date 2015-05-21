#!/usr/bin/php
<?php

if ($argc > 1)
{
	$i = 1;
	while ($i < $argc)
	{
		$argv[$i] = trim($argv[$i], " ");
		$tab_2 = explode(" ", $argv[$i]);
		$tab_2 = array_filter($tab_2);
		foreach ($tab_2 as $elem)
			$str = $str." ".$elem;
		$str = trim($str);
		$argv[$i] = $str;
		$str = NULL;
		$i++;
	}
	$i = 1;
	$e = 0;
	while ($i < $argc)
	{
		if (strpos($argv[$i], " ") == FALSE)
		{
			$tab[$e] = $argv[$i];
			$e++;
		}
		else
		{
			$new_tab = explode(" ", $argv[$i]);
			$len = count($new_tab);
			$tab = array_merge($tab, $new_tab);
			$e = $e + $len;
		}
		$i++;
	}
	$i = 0;
	sort($tab);
	while ($tab[$i])
	{
		echo "{$tab[$i]}\n";
		$i++;
	}
}
?>
