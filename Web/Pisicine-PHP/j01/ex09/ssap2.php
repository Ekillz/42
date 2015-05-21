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
	$tab = array();
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
	$a_i = 0;
	$n_i = 0;
	$o_i = 0;
	$alph_tab = array();
	$num_tab = array();
	$other_tab = array();
	while ($tab[$i])
	{
		if (ctype_alpha($tab[$i][0]))
		{
			$alph_tab[$a_i] = $tab[$i];
			$a_i++;
		}
		else if (is_numeric($tab[$i][0]))
		{
			$num_tab[$n_i] = $tab[$i];
			$n_i++;
		}
		else
		{
			$other_tab[$o_i] = $tab[$i];
			$o_i++;
		}
		$i++;
	}
	sort($num_tab, SORT_STRING);
	sort($alph_tab, SORT_STRING | SORT_FLAG_CASE);
	sort($other_tab, SORT_STRING | SORT_FLAG_CASE);
	$i = 0;
	while ($alph_tab[$i])
	{
		echo "{$alph_tab[$i]}\n";
		$i++;
	}
	$i = 0;
	while ($num_tab[$i])
	{
		echo "{$num_tab[$i]}\n";
		$i++;
	}
	$i = 0;
	while ($other_tab[$i])
	{
		echo "{$other_tab[$i]}\n";
		$i++;
	}
}
?>
