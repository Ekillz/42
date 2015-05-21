<?php

class UnholyFactory {

	public $fighters = array();

	public function absorb ( $type_soldier ) {
		if ( get_parent_class($type_soldier) == "Fighter" )
		{
			$type_s = $type_soldier->get_type_f();
			if (method_exists( $type_soldier, "fight" ))
			{
				if ( !in_array($type_soldier, $this->fighters) )
				{
					array_push($this->fighters, $type_soldier);
					print ("(Factory absorbed a fighter of type " .$type_s. ")" . PHP_EOL);
				}
				else
					print ("(Factory already absorbed a fighter of type " .$type_s. ")" . PHP_EOL);
			}
		}
		else
			print ("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
	}

	public function fabricate ( $type_soldier ) {
		foreach ($this->fighters as $f) {
			if ( $f->get_type_f() == $type_soldier)
			{
				print ("(Factory fabricates a fighter of type " .$type_soldier. ")" . PHP_EOL);
				return $f;
			}
		}
		print ("(Factory hasn't absorbed any fighter of type " .$type_soldier. ")" . PHP_EOL);
	}

}

?>
