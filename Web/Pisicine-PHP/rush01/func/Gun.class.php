<?PHP

require_once("Dice.trait.php");

class Gun
{
	private $_name;
    private $_load;
    private $_short_range;
    private $_mid_range;
    private $_long_range;
	private $_area;

	public static $verbose = false;

	use Dice;

	//MAGIC
	public function __construct($kw_arg)
	{
		$this->init($kw_arg);

        if (self::$verbose)
			echo "Gun constructed.".PHP_EOL;
	}

	public function __destruct()
    {
        if (self::$verbose)
			echo "Gun destructed.".PHP_EOL;
    }

	//PRIVATE
	public function init(array $kw_arg)
	{
		$this->setName($kw_arg['name']);
		$this->setLoad($kw_arg['load']);
		$this->setSrange($kw_arg['srange']); //s = short
		$this->setMrange($kw_arg['mrange']); //m = middle
		$this->setLrange($kw_arg['lrange']); //l = long
		$this->setArea($kw_arg['area']);
	}

	//SET
	public function setName($arg)
	{
		$this->_name = $arg;
	}
	public function setLoad($arg)
	{
		$this->_load = $arg;
	}
	public function setSrange($arg)
	{
		$this->_short_range = $arg;
	}
	public function setMrange($arg)
	{
		$this->_mid_range = $arg;
	}
	public function setLrange($arg)
	{
		$this->_long_range = $arg;
	}
	public function setArea($arg)
	{
		$this->_area = $arg;
	}

	//GET
	public function getName()
	{
		return $this->_name;
	}
	public function getLoad()
	{
		return $this->_load;
	}
	public function getSrange()
	{
		return $this->_short_range;
	}
	public function getMrange()
	{
		return $this->_mid_range;
	}
	public function getLrange()
	{
		return $this->_long_range;
	}
	public function getArea()
	{
		return $this->_area;
	}
}
/*
	$GunA = new Gun(array('name' => 'hahahaha', 'load' => "hehehe", 'srange' => 3, 'mrange' => 5, 'lrange' => 7, 'area' => 3));
	$GunB = new Gun(array('name' => 'haha', 'load' => "hehe", 'srange' => 2, 'mrange' => 4, 'lrange' => 6, 'area' => 2));
*/
?>