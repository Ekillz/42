<?php

class Jaime extends Lannister
{
	public function sleepWith($bitch)
	{
		if (get_class($bitch) == "Tyrion")
			echo "Not even if I'm drunk !\n";
		else if (get_class($bitch) == "Sansa")
			echo "Let's do this.\n";
		else if (get_class($bitch) == "Cersei")
			echo "With pleasure, but only in a tower in Winterfell, then.\n";
	}
}

?>
