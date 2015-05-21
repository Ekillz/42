<?php

abstract class Fighter{

	public $type_f;

	public function __construct( $type ) {
		$this->type_f = $type;
		return ;
	}

	public function get_type_f(){
		return $this->type_f;
	}

	abstract function fight( $target );
}

?>
