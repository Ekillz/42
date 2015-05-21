<?php

require_once("Dice.trait.php");
require_once("IShip.class.php");

class Ship implements IShip
{
    private $_name;
    private $_sprite;
    private $_spriteUp;
    private $_spriteDown;
    private $_spriteLeft;
	private $_spriteRight;
	private $_way; //up/down/right/left
	private $_pc; //point de coque
	private $_pp; //point moteur
	private $_speed;
	private $_maneuver;
	private $_gun;
	private $_bonusShield;
	private $_bonusSpeed;
	private $_bonusShoot;
	private $_activated;
	private $_still;
	private $_xMin;
	private $_yMin;
	private $_xMax;
	private $_yMax;

	public static $verbose = false;

	use Dice;

	//MAGIC
	public function __construct(array $kw_arg)
	{
		$this->init($kw_arg);

		if (self::$verbose)
			echo "Ship constructed.".PHP_EOL;
	}

	public function __destruct()
	{
		if (self::$verbose)
			echo "Ship destructed.".PHP_EOL;
	}

	//PUBLIC

	//order
	public function _order(array $order)
	{
		if (array_key_exists("repair", $order))
			$this->setPc($order["repair"] * $this->roll()); //be sure it's still

		if (array_key_exists("shield", $order))
			$this->setBonusShield($order["shield"]);

		if (array_key_exists("speed", $order))
			$this->setBonusSpeed($$order["speed"] * $this->roll());

		if (array_key_exists("shoot", $order))
			$this->setBonusShoot($order["shoot"] * $this->roll());

		return true;
	}

	//move
	public function move($length)
	{
		//TODO
	}
	public function rotate($way)
	{
		if ($way != "right" && $way != "left")
			return false;
        
		switch ($this->getWay())
		{
		case "left":
			$way == "right" ? $this->setWay("up") : $this->setWay("down");
			break ;
		case "right":
			$way == "right" ? $this->setWay("down") : $this->setWay("up");
			break ;
		case "up":
			$way == "right" ? $this->setWay("right") : $this->setWay("left");
			break ;
		case "down":
			$way == "right" ? $this->setWay("left") : $this->setWay("right");
			break ;
		}

        switch ($this->getWay())
		{
		case "left":
            $this->setSprite($this->getSpriteLeft());
			break ;
		case "right":
            $this->setSprite($this->getSpriteRight());
			break ;
		case "up":
            $this->setSprite($this->getSpriteUp());
			break ;
		case "down":
            $this->setSprite($this->getSpriteDown());
			break ;
        }

        $cste = ($this->getXMax() - $this->getXMin() - ($this->getYMax() - $this->getYMin())) / 2;
        $this->setXMin($this->getXMin() + $cste);
        $this->setYMin($this->getYMin() - $cste);
        $this->setXMax($this->getXMax() - $cste);
        $this->setYMax($this->getYMax() + $cste);

/*
        $centreX = ($this->getXMax() - $this->getXMin()) / 2;
        $centreY = ($this->getYMax() - $this->getYMin()) / 2;
        
        $this->setXMin($centreY / 2 - $centreX);
        $this->setXMax($centreY / 2 + $centreX);

        $this->setYMin($centreX / 2 - $centreY);
        $this->setYMax($centreX / 2 + $centreY);
*/


        
        return true;
	}

	//shoot
	public function shoot(array $shoot)
	{
		//TODO
	}

	//PRIVATE METHOD
	public function init(array $kw_arg)
	{
		$this->setBonusShield(0);
		$this->setBonusSpeed(0);
		$this->setBonusShoot(0);

		//needed
		$this->setName($kw_arg["name"]);
		$this->setSpriteUp($kw_arg["spriteup"]);
		$this->setSpriteDown($kw_arg["spritedown"]);
		$this->setSpriteLeft($kw_arg["spriteleft"]);
		$this->setSpriteRight($kw_arg["spriteright"]);
		$this->setGun($kw_arg["gun"]);

		//optionnal
		if (array_key_exists("pc", $kw_arg))
			$this->setPc($kw_arg["pc"]);
		else
			$this->setPc(5);

		if (array_key_exists("pp", $kw_arg))
			$this->setPp($kw_arg["pp"]);
		else
			$this->setPp(10);

		if (array_key_exists("speed", $kw_arg))
			$this->setSpeed($kw_arg["speed"]);
		else
			$this->setSpeed(15);

		if (array_key_exists("maneuver", $kw_arg))
			$this->setManeuver($kw_arg["maneuver"]);
		else
			$this->setManeuver(4);

		if (array_key_exists("activated", $kw_arg))
			$this->setActivated($kw_arg["activated"]);
		else
			$this->setActivated(false);

		if (array_key_exists("still", $kw_arg))
			$this->setStill($kw_arg["still"]);
		else
			$this->setStill(true);

		if (array_key_exists("xmin", $kw_arg))
			$this->setXMin($kw_arg["xmin"]);
		else
			$this->setXMin(0);

		if (array_key_exists("ymin", $kw_arg))
			$this->setYMin($kw_arg["ymin"]);
		else
			$this->setYMin(0);

		if (array_key_exists("xmax", $kw_arg))
			$this->setXMax($kw_arg["xmax"]);
		else
			$this->setXMax(0);

		if (array_key_exists("ymax", $kw_arg))
			$this->setYMax($kw_arg["ymax"]);
		else
			$this->setYMax(0);

		if (array_key_exists("way", $kw_arg))
        {
			$this->setWay($kw_arg["way"]);
            switch ($kw_arg["way"])
            {
            case "right":
            $this->setSprite($this->getSpriteRight());
                break;
            case "left":
            $this->setSprite($this->getSpriteLeft());
                break;
            case "down":
            $this->setSprite($this->getSpriteDown());
                break;
            case "up":
            $this->setSprite($this->getSpriteUp());
                break;
            }
        }
		else
        {
			$this->setWay("right");
            $this->setSprite($this->getSpriteRight());
        }
	}

	//GET
	public function getName()
	{
		return $this->_name;
	}
	public function getSpriteUp()
	{
		return $this->_spriteUp;
	}
	public function getSpriteDown()
	{
		return $this->_spriteDown;
	}
	public function getSpriteLeft()
	{
		return $this->_spriteLeft;
	}
	public function getSpriteRight()
	{
		return $this->_spriteRight;
	}
	public function getSprite()
	{
		return $this->_sprite;
	}
	public function getPc()
	{
		return $this->_pc;
	}
	public function getPp()
	{
		return $this->_pp;
	}
	public function getSpeed()
	{
		return $this->_speed;
	}
	public function getManeuver()
	{
		return $this->_maneuver;
	}
	public function getBonusShield()
	{
		return $this->_bonusShield;
	}
	public function getGun()
	{
		return $this->_gun;
	}
	public function getActivated()
	{
		return $this->_activated;
	}
	public function getStill()
	{
		return $this->_still;
	}
	public function getXMin()
	{
		return $this->_xMin;
	}
	public function getYMin()
	{
		return $this->_yMin;
	}
	public function getXMax()
	{
		return $this->_xMax;
	}
	public function getYMax()
	{
		return $this->_yMax;
	}
	public function getWay()
	{
		return $this->_way;
	}

	//SET
	public function setName($name)
	{
		$this->_name = $name;
	}
	public function setSpriteUp($sprite)
	{
		$this->_spriteUp = $sprite;
	}
	public function setSpriteDown($sprite)
	{
		$this->_spriteDown = $sprite;
	}
	public function setSpriteLeft($sprite)
	{
		$this->_spriteLeft = $sprite;
	}
	public function setSpriteRight($sprite)
	{
		$this->_spriteRight = $sprite;
	}
	public function setSprite($sprite)
	{
		$this->_sprite = $sprite;
	}
	public function setPc($pc)
	{
		$this->_pc = intval($pc);
	}
	public function setPp($pp)
	{
		$this->_pp = intval($pp);
	}
	public function setSpeed($speed)
	{
		$this->_speed = intval($speed);
	}
	public function setManeuver($maneuver)
	{
		$this->_maneuver = intval($maneuver);
	}
	public function setBonusShield($shield)
	{
		$this->_bonusShield = intval($shield);
	}
	public function setBonusSpeed($speed)
	{
		$this->_bonusSpeed = intval($speed);
	}
	public function setBonusShoot($shoot)
	{
		$this->_bonusShoot = intval($shoot);
	}
	public function setGun($gun)
	{
		$this->_gun = $gun;
	}
	public function setActivated($activated)
	{
		$this->_activated = $activated;
	}
	public function setStill($still)
	{
		$this->_still = $still;
	}
	public function setXMin($x)
	{
		$this->_xMin = intval($x);
	}
	public function setYMin($y)
	{
		$this->_yMin = intval($y);
	}
	public function setXMax($x)
	{
		$this->_xMax = intval($x);
	}
	public function setYMax($y)
	{
		$this->_yMax = intval($y);
	}
	public function setWay($way)
	{
		$this->_way = $way;
	}

}

?>