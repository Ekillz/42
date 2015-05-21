<?php

function change_pw($tab, $pass)
{
	$e = 0;
	$i = 0;
	foreach($tab as $login)
	{
		foreach($login as $key => $value)
		{
			if ($e == 1)
			{
				if ($value == $pass)
				{
					$tab[$i][passwd] = hash('whirlpool', $_POST[newpw]);
					file_put_contents("../private/passwd",serialize($tab));
					return (2);
				}
			}
			if ($value == $_POST['login'])
				$e++;
		}
		$i++;
	}
	return (0);
}
if (!$_POST[login] || !$_POST[oldpw] || !$_POST[newpw] || !$_POST[submit] || $_POST[submit] != "OK")
	echo "ERROR\n";
else
{
	$tab = unserialize(file_get_contents("../private/passwd"));
	$pass = hash('whirlpool', $_POST['oldpw']);
	if (change_pw($tab, $pass) == 2)
		echo "OK\n";
	else
		echo "ERROR\n";
}
?>
