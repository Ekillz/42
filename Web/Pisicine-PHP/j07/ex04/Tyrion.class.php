<?php

class Tyrion extends Lannister
{
	public function sleepWith($bitch)
	{
		if (get_parent_class($bitch) == "Lannister")
			echo "Not even if I'm drunk !\n";
		else if (get_class($bitch) == "Sansa")
			echo "Let's do this.\n";
	}
}

?>
