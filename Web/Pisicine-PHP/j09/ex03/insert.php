<?php 
	$to_do = "{$_GET['id']};{$_GET['val']};";
	file_put_contents("list.csv" , $to_do, FILE_APPEND);
?>