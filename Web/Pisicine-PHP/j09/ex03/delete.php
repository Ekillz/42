<?php 
	$to_do = "{$_GET['id']};{$_GET['val']};";
	$to_do_list = file_get_contents("list.csv");
	$to_do = str_replace($to_do, "", $to_do_list);
	file_put_contents("list.csv" , $to_do);
?>
