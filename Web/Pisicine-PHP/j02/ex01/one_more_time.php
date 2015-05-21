#!/usr/bin/php
<?php

function check_nb_args($which, $av)
{
	if ($which === 0)
	{
		$tab = explode(" ", $av);
		if (count($tab) != 5)
			return (-1);
	}
	else if ($which === 1)
	{
		$new_tab = explode(" ", $av);
		$tab = explode(":", $new_tab[4]);
		if (count($tab) != 3)
			return (-1);
		if (is_numeric($tab[0]) == FALSE)
			return (-1);
		if (is_numeric($tab[1]) == FALSE)
			return (-1);
		if (is_numeric($tab[2]) == FALSE)
			return (-1);
		if ($tab[0] > 23 || $tab[0] < 0)
			return (-1);
		if ($tab[1] > 59 || $tab[1] < 0)
			return (-1);
		if ($tab[2] > 59 || $tab[2] < 0)
			return (-1);
	}
	else if ($which === 2)
	{
		$tab = explode(" ", $av);
		if (is_numeric($tab[3]) == FALSE)
			return (-1);
	}
	else if ($which == 3)
	{
		$tab = explode(" ", $av);
		if (ctype_alpha($tab[2]) == FALSE)
			return (-1);
		$new = array();
		$new[0] = "Janvier";
		$new[1] = "Fevrier";
		$new[2] = "Mars";
		$new[3] = "Avril";
		$new[4] = "Mai";
		$new[5] = "Juin";
		$new[6] = "Juillet";
		$new[7] = "Aout";
		$new[8] = "Septembre";
		$new[9] = "Octobre";
		$new[10] = "Novembre";
		$new[11] = "Decembre";
		$i = 0;
		while ($new[$i])
		{
			if (strcasecmp($tab[2], $new[$i]) == 0)
			{
				$e = $i;
				$found = 3;
			}
			$i++;
		}
		if ($found != 3)
			return (-1);
		else if ($found == 3)
			return ($e + 1);
	}
	else if ($which == 4)
	{
		$tab = explode(" ", $av);
		if (is_numeric($tab[1]) == FALSE)
			return (-1);
		if ($tab[1] < 1 || $tab[1] > 31)
			return (-1);
	}
	else if ($which == 5)
	{
		$tab = explode(" ", $av);
		if (ctype_alpha($tab[0]) == FALSE)
			return (-1);
		$new[0] = "Lundi";
		$new[1] = "Mardi";
		$new[2] = "Mercredi";
		$new[3] = "Jeudi";
		$new[4] = "Vendredi";
		$new[5] = "Samedi";
		$new[6] = "Dimanche";
		$i = 0;
		while ($new[$i])
		{
			if (strcasecmp($tab[0], $new[$i]) == 0)
				$found = 3;
			$i++;
		}
		if ($found != 3)
			return (-1);
	}
	return (1);
}

if ($argc == 2)
{
	$av = $argv[1];
	$wrong = 0;

	if (check_nb_args(0, $av) == -1)
		$wrong = 1;
	if (check_nb_args(1, $av) == -1)
		$wrong = 2;
	if (check_nb_args(2, $av) == -1)
		$wrong = 3;
	if (check_nb_args(3, $av) == -1)
		$wrong = 4;
	else
		$month = check_nb_args(3, $av);
	if (check_nb_args(4, $av) == -1)
		$wrong = 5;
	if (check_nb_args(5, $av) == -1)
		$wrong = 6;
	if ($wrong > 0)
	{
		echo "Wrong Format\n";
		return (0);
	}
	else
	{
		$tab = explode(" ", $av);
		$res = $tab[3].$month.$tab[1];
		date_default_timezone_set('Europe/Paris');
		$time = strtotime($res);
		$heure = explode(":", $tab[4]);
		$second = $heure[2] + ($heure[1] * 60) + ($heure[0] * 3600);
		$time = $time + $second;
		echo "$time\n";
	}
}
?>
