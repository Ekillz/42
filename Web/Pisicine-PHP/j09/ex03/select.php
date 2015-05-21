<?php 
	$list = fgets(fopen("list.csv", "r"), filesize("list.csv"));
	$to_do_list = array();
	$to_do_list = explode(";", $list);
	$i=0;
	$j=0;
	foreach ($to_do_list as $el)
		echo "$el ";
?>