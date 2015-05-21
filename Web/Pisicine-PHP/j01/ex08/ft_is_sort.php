<?php

function ft_is_sort($str)
{
	$i = 0;
	$tmp = $str;
	sort($tmp);
	while ($str[$i])
	{
		if ($tmp[$i] != $str[$i])
			return (0);
		$i++;
	}
	return (1);
}

?>
