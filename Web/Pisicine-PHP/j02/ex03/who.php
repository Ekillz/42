#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');
$fd = fopen("/var/run/utmpx", "r");
$str = fread($fd, 1256);
$i = 0;
while (!feof($fd))
{
	$tab = unpack("a256user/a4id/a32line/ipid/itype/i2time/a256host/@", $str);
	if (trim($tab[user]) == get_current_user())
	{
		$tab_2[$i] = $tab;
		$i++;
	}
	$str = fread($fd, 628);
}

$e = 0;

while ($tab_2[$e])
{
	$login[$e] = $tab_2[$e][user];
	$line[$e] = $tab_2[$e][line];
	$time1[$e] = $tab_2[$e][time1];
	$e++;
}
sort($login);
sort($line);
sort($time1);
$i = 0;
while ($tab_2[$i])
{
	$str = strftime("%b %e %H:%M",$time1[$i]);
	echo $login[$i]." ".$line[$i]." ".$str."\n";
	$i++;
}
//foreach($tab_2 as $s)
//	print_r($s);
?>
