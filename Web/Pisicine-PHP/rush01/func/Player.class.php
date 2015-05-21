<?php

require_once("IPlayer.class.php");

class Player implements IPlayer
{
    private $_ships;

    public static $verbose = false;

    //MAGIC
    public function __construct(array $ships)
    {
		$this->_ships = array();
		$this->addShips($ships);

		if (self::$verbose)
			echo "Player constructed.".PHP_EOL;
	}

	public function __destruct()
	{
		if (self::$verbose)
			echo "Player destructed.".PHP_EOL;
	}

	//PUBLIC METHOD

	public function isAlive() // /!\ will clear temp states (activated, bonus...)
	{
		$ships = $this->getShips();

		foreach ($ships as $key => $ship)
		{
			$ship->setActivated(false); //cleaning activation
            $ship->setBonusShield(0); //cleaning bonus
            $ship->setBonusSpeed(0);
            $ship->setBonusShoot(0);
			if ($ship->getPc() <= 0)
				unset($ships[$key]); //cleaning dead ship
		}

		if (count($this->getShips()) == 0)
			return false;
		else
			return true;
	}

	public function canPlay()
	{
		foreach ($ships as $ship)
			if (!$ship->getActivated())
				return true;
		return false;
	}

	//GET
	public function getShips()
	{
		return $this->_ships;
	}

	//SET
	public function addShips($ships)
	{
		foreach ($ships as $ship)
			array_push($this->_ships, $ship);
	}

}

?>