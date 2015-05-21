<?PHP

require_once('IZone.class.php');

class Zone implements IZone
{
	private $_width;
    private $_height;
    private $_map; //array
	private $_p1;
	private $_p2;
	private $_Xmin;
	private $_Xmax;
	private $_Ymin;
	private $_Ymax;


	public static $verbose = false;

	//MAGIC
	public function __construct(array $kw_arg)
	{
		if (array_key_exists("width", $kw_arg))
			$this->setWidth($kw_arg["width"]);
		else
			$this->setWidth(150);

		if (array_key_exists("height", $kw_arg))
			$this->setHeight($kw_arg["height"]);
		else
			$this->setHeight(100);

		if (array_key_exists("obstacle", $kw_arg))
			$this->setMap($this->getHeight(), $this->getWidth(), $kw_arg["obstacle"]);
		else
			$this->setMap($this->getHeight(), $this->getWidth(), array());

		if (array_key_exists("p1", $kw_arg))
			$this->setP1($kw_arg["p1"]);
		else
			$this->setP1(null);

		if (array_key_exists("p2", $kw_arg))
			$this->setP2($kw_arg["p2"]);
		else
			$this->setP2(null);

		if (self::$verbose)
			echo "Zone constructed.".PHP_EOL;
	}

	public function __destruct()
	{
		if (self::$verbose)
			echo "Zone destructed.".PHP_EOL;
	}


	//PUBLIC
	public function canMoveMap($move, $indShip, $Player)
	{
		if ($Player == 1)
		{
			if ($this->_p1Ships[$indShip]->getSens() == 'up')
				return $this->MoveYmin($move, $indShip, $Player, $this->_obs);
			if ($this->_p1Ships[$indShip]->getSens() == 'down')
				return $this->MoveYmax($move, $indShip, $Player, $this->_obs);
			if ($this->_p1Ships[$indShip]->getSens() == 'left')
				return $this->MoveXmin($move, $indShip, $Player, $this->_obs);
			if ($this->_p1Ships[$indShip]->getSens() == 'right')
				return $this->MoveXmax($move, $indShip, $Player, $this->_obs);
		}
		else
		{
			if ($this->_p2Ships[$indShip]->getSens() == 'up')
				return $this->MoveYmin($move, $indShip, $Player, $this->_obs);
			if ($this->_p2Ships[$indShip]->getSens() == 'down')
				return $this->MoveYmax($move, $indShip, $Player, $this->_obs);
			if ($this->_p2Ships[$indShip]->getSens() == 'left')
				return $this->MoveXmin($move, $indShip, $Player, $this->_obs);
			if ($this->_p2Ships[$indShip]->getSens() == 'right')
				return $this->MoveXmax($move, $indShip, $Player, $this->_obs);
		}
	}

	public	 function aff_map()
	{
		echo '<table>';

		$p1Ships = $this->getP1()->getShips();
		$p2Ships = $this->getP2()->getShips();

		foreach($p1Ships as $ship)
		{
			$X = 12 * $ship->getXMin();
			$Y = 12 * $ship->getYMin();
			$SX = 12 * ($ship->getXMax() - $ship->getXMin() + 1) - 1;
			$SY = 12 * ($ship->getYMax() - $ship->getYMin() + 1) - 1;

			echo '<img src= '.$ship->getSprite().' style="background-color:red; left:'.$X.'px; top:'.$Y.'px; width:'.$SX.'px;height:'.$SY.'px;" alt="Vaisse11" class="vais">';
		}

		foreach($p2Ships as $ship2)
		{
			$X = 12 * $ship2->getXMin();
			$Y = 12 * $ship2->getYMin();
			$SX = 12 * ($ship2->getXMax() - $ship2->getXMin() + 1) - 1;
			$SY = 12 * ($ship2->getYMax() - $ship2->getYMin() + 1) - 1;

			echo '<img src= '.$ship2->getSprite().' style="background-color:blue; left:'.$X.'px; top:'.$Y.'px; width:'.$SX.'px;height:'.$SY.'px;" alt="Vaisse11" class="vais">';
		}

		echo '<img src="img/asteroidBig01.png" alt="asteroid" class="asteroid">';
		echo '<img src="img/asteroidBig01.png" alt="asteroid" class="asteroid1">';
		echo '<img src="img/asteroidBig01.png" alt="asteroid" class="asteroid2">';
		echo '<img src="img/asteroidBig01.png" alt="asteroid" class="asteroid3">';

		$y = 0;

		while ($y < 100)
		{
			echo '<tr>';
			$x = 0;
			while ($x < 150)
			{
				echo '<td class = "black" ></td>';
				$x++;
			}
			echo '</tr>';
			$y++;
		}
		echo '</table>';
	}

	//PRIVATE
	private function InitPos($Player, $indShip)
	{
		$_p1Ships = $_p1->getShips();
		$_p2Ships = $_p2->getShips();

		if ($Player == 1)
		{
			$this->Xmin = $this->_p1Ships[$indShip]->getXmin();
			$this->Xmax = $this->_p1Ships[$indShip]->getXmax();
			$this->Ymin = $this->_p1Ships[$indShip]->getYmin();
			$this->Ymax = $this->_p1Ships[$indShip]->getYmax();
		}
		else
		{
			$this->Xmin = $this->_p2Ships[$indShip]->getXmin();
			$this->Xmax = $this->_p2Ships[$indShip]->getXmax();
			$this->Ymin = $this->_p2Ships[$indShip]->getYmin();
			$this->Ymax = $this->_p2Ships[$indShip]->getYmax();
		}

	}

	private function DeleteDamage($Player, $indShip, $Ship, $nature, $case)
	{
		if ($nature == "obstacle")
		{
			if ($Player == 1)
				$this->_p1Ships[$indShip]->setPc(0);
			else
				$this->_p2Ships[$indShip]->setPc(0);
		}
		else
		{
			if ($Player == 1 && $case > $this->_p1Ships[$indShip]->getManeuver())
				$this->_p1Ships[$indShip]->setPc($this->_p1Ships[$indShip]->getPc() + $this->_p1Ships[$indShip]->getBonusShield() - $Ship->getPc());
			else if ($Player == 2 && $case > $this->_p2Ships[$indShip]->getManeuver())
				$this->_p2Ships[$indShip]->setPV($this->_p2Ships[$indShip]->getPc() + $this->_p1Ships[$indShip]->getBonusShield() - $Ship->getResist());
			if ($$Player == 1 && $case > $this->_p1Ships[$indShip]->getManeuver())
				return ($Ship->getPc() + $Ship->getBonusShield() - $this->_p1Ships[$indShip]->getResist());
			else if ($Player == 2 && $case > $this->_p2Ships[$indShip]->getManeuver())
				return ($Ship->getPc() + $Ship->getBonusShield() - $this->_p2Ships[$indShip]->getResist());
		}
		return true;
	}

	private function AddModif($Player, $dirA, $dirB, $indShip, $move)
	{
		if ($Player == 1)
		{
			$this->_p1Ships[$indShip]->setXmin($dirA);
			$this->_p1Ships[$indShip]->setXmax($dirB);
		}
		else
		{
			$this->_p2Ships[$indShip]->setXmin($dirA);
			$this->_p2Ships[$indShip]->setXmax($dirB);
		}
	}

	private function MoveXmin($move, $indShip, $Player, $obstacles, $nature)
	{
		$i = 0;
		$this->InitPos($player, $indShip);
		$posend = $this->_Xmin - $move;
		while ($this->_Xmin > $posend)
		{
			$this->_Xmin--;
			if ($this->Xmin == -1)
				return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
			$i++;
			foreach($obstacles as $obs)
			{
				if ($this->_Xmin <= $obs->getXmax())
				{
					if ($this->_Ymax - $this->_Ymin >= $obs->getYmax() - $obs->getYmin())
					{
						if (($obs->getYmin() >= $this->_Ymin && $obs->getYmin() <= $this->_Ymax)
							|| ($obs->getYmax() >= $this->_Ymin && $obs->getYmax() <= $this->_Ymax))
							return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
					}
					else
						if (($this->_Ymin >= $obs->getYmin() && $this->_Ymin <= $obs->getYmax())
							|| ($this->_Ymax >= $obs->getYmin() && $this->_Ymax <= $obs->getYmax()))
							return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
				}
			}
		}
		AddModif($Player, $this->_Xmin, $this->_Xmax - $move, $indShip, $move);
		return true;
	}

	private function MoveXmax($move, $indShip, $Player, $obstacles, $nature)
	{
		$i = 0;
		$this->InitPos($player, $indShip);
		$posend = $this->_Xmax + $move;
		while ($this->_Xmax < $posend)
		{
			$this->_Xmax++;
			if ($this->Xmax == 150)
				return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
			$i++;
			foreach($obstacles as $obs)
			{
				if ($this->_Xmax >= $obs->getXmin())
				{
					if ($this->_Ymax - $this->_Ymin >= $obs->getYmax() - $obs->getYmin())
					{
						if (($obs->getYmin() >= $this->_Ymin && $obs->getYmin() <= $this->_Ymax)
							|| ($obs->getYmax() >= $this->_Ymin && $obs->getYmax() <= $this->_Ymax))
							return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
					}
					else
						if (($this->_Ymin >= $obs->getYmin() && $this->_Ymin <= $obs->getYmax())
							|| ($this->_Ymax >= $obs->getYmin() && $this->_Ymax <= $obs->getYmax()))
							return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
				}
			}
		}
		AddModif($Player, $this->_Xmax, $this->_Xmin + $moove, $indShip, $move);
		return true;
	}

	//TODO
	private function MoveYmin($move, $indShip, $Player, $obstacles, $nature)
	{
		$i = 0;
		$this->InitPos($player, $indShip);
		$posend = $this->_Ymin - $move;
		while ($this->_Xmax < $posend)
		{
			$this->_Xmax++;
			$i++;
			foreach($obstacles as $obs)
			{
				if ($this->_Xmax >= $obs->getXmin())
				{
					if ($this->_Ymax - $this->_Ymin >= $obs->getYmax() - $obs->getYmin())
					{
						if (($obs->getYmin() >= $this->_Ymin && $obs->getYmin() <= $this->_Ymax)
				            || ($obs->getYmax() >= $this->_Ymin && $obs->getYmax() <= $this->_Ymax))
                            return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
                    }
                    else
                        if (($this->_Ymin >= $obs->getYmin() && $this->_Ymin <= $obs->getYmax())
                            || ($this->_Ymax >= $obs->getYmin() && $this->_Ymax <= $obs->getYmax()))
                            return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
                }
            }
        }
        AddModif($Player, $this->_Xmax, $this->_Xmin + $moove, $indShip, $move);
        return true;
    }

    //TODO
    private function MoveYmax($move, $indShip, $Player, $obstacles, $nature)
    {
        $i = 0;
        $this->InitPos($player, $indShip);
        $posend = $this->_Ymin - $move;
        while ($this->_Xmax < $posend)
        {
            $this->_Xmax++;
            $i++;
            foreach($obstacles as $obs)
            {
                if ($this->_Xmax >= $obs->getXmin())
                {
                    if ($this->_Ymax - $this->_Ymin >= $obs->getYmax() - $obs->getYmin())
                    {
                        if (($obs->getYmin() >= $this->_Ymin && $obs->getYmin() <= $this->_Ymax)
                            || ($obs->getYmax() >= $this->_Ymin && $obs->getYmax() <= $this->_Ymax))
                            return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
                    }
                    else
                        if (($this->_Ymin >= $obs->getYmin() && $this->_Ymin <= $obs->getYmax())
                            || ($this->_Ymax >= $obs->getYmin() && $this->_Ymax <= $obs->getYmax()))
                            return $this->DeleteDamage($Player, $indShip, null, $nature, $i);
                }
            }
        }
        AddModif($Player, $this->_Xmax, $this->_Xmin + $moove, $indShip, $move);
        return true;
    }


	//SET
	public function init_obstacle($obs)
	{
		foreach ($obs as $key => $value)
			$this->_map[$value][$key] = 2;
	}
	public function setMap($h, $w, $obs)
	{
		$this->_map = array();
		$this->i = 0;
		while ($this->i <= $h + 1)
		{
			$this->j = 0;
			$this->_map[$this->i] = array();
			while ($this->j <= $w + 1)
			{
				if ($this->i == 0 || $this->i == $h + 1 || $this->j == 0 || $this->j == $w + 1)
					$this->_map[$this->i][$this->j] = 1;
				else
					$this->_map[$this->i][$this->j] = 0;
				$this->j++;
			}
			$this->i++;
		}
		$this->init_obstacle($obs);
	}
	public function setWidth($arg)
	{
		$this->_width = $arg;
	}
	public function setHeight($arg)
	{
		$this->_height = $arg;
	}
	public function setP1($p)
	{
		$this->_p1 = $p;
	}
	public function setP2($p)
	{
		$this->_p2 = $p;
	}

	//GET
	public function getMap()
	{
		return $this->_map;
	}
	public function getWidth()
	{
		return $this->_width;
	}
	public function getHeight()
	{
		return $this->_height;
	}
	public function getP1()
	{
		return $this->_p1;
	}
	public function getP2()
	{
		return $this->_p2;
	}
}

?>