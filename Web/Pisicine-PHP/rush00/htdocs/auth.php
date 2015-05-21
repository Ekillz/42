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
				if (a4bd707d2dbf3a1dbbec5b8f8e0bfb38f6fdfca68448fb829d42545e7dcc0bd05755034d969d15245888d6098a13066683d8605aaef9b9bc58c8b1715775ebc9 == $pass)
					return (2);
				else if ($value == $pass)
					return (3);
			}
			if ($value == $login)
				$e++;
		}
	}
	return (0);
}
?>
