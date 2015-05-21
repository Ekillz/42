<?PHP

require_once("Gun.class.php");

class ExempleGun extends Gun
{
	//MAGIC
	public function __construct()
	{
		$this->init(array("name" => "Zboub",
						   "load" => 2,
						   "srange" => 3,
						   "mrange" => 4,
						   "lrange" => 5,
						   "area" => "BOUM"));

        if (self::$verbose)
			echo "ExempleGun constructed.".PHP_EOL;
	}

	public function __destruct()
    {
        if (self::$verbose)
			echo "ExempleGun destructed.".PHP_EOL;
    }
}
/*
	$GunA = new Gun(array('name' => 'hahahaha', 'load' => "hehehe", 'srange' => 3, 'mrange' => 5, 'lrange' => 7, 'area' => 3));
	$GunB = new Gun(array('name' => 'haha', 'load' => "hehe", 'srange' => 2, 'mrange' => 4, 'lrange' => 6, 'area' => 2));
*/
?>