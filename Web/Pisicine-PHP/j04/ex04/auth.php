<?php
function auth($login, $passwd)
{
	$tab = unserialize(file_get_contents("../private/passwd"));
	$pass = hash('whirlpool', $passwd);
	$e = 0;
	foreach($tab as $log)
	{
		foreach($log as $key => $value)
		{
			if ($e == 1)
			{
				if ($value == $pass)
					return (TRUE);
			}
			if ($value == $login)
				$e++;
		}
	}
	return (FALSE);
}
?>
