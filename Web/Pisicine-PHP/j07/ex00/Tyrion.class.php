<?php

class tyrion extends Lannister
{
	public function __construct()
	{
		parent::__construct();
		print("My name is Tyrion\n");
	}
	public function getSize()
	{
		return "short";
	}
	public function __destruct()
	{
		return;
	}
}

?>
