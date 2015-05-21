#!/usr/bin/php
<?php

if ($argc == 4)
{
	$i = 1;
	while ($argv[$i])
	{
		$argv[$i] = trim($argv[$i], " ");
		$argv[$i] = trim($argv[$i], "\t");
		$i++;
	}
	if ($argv[2] == "-")
		$res = $argv[1] - $argv[3];
	else if ($argv[2] == "+")
		$res = $argv[1] + $argv[3];
	else if ($argv[2] == "/")
		$res = $argv[1] / $argv[3];
	else if ($argv[2] == "*")
		$res = $argv[1] * $argv[3];
	else if ($argv[2] == "%")
		$res = $argv[1] % $argv[3];
	echo "$res\n";
}
else
	echo "Incorrect Parameters\n";

?>
