<?php

require_once "Vertex.class.php";

class Vector 
{
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	public static $verbose = False;
	public function __construct(array $kwargs)
	{
		if (array_key_exists('x', $kwargs) && array_key_exists('y', $kwargs) && array_key_exists('z', $kwargs))
		{
			$this->_x = $kwargs["x"];
			$this->_y = $kwargs["y"];
			$this->_z = $kwargs["z"];
			$this->_w = 0.0;
		}
		else if (array_key_exists('dest', $kwargs) || (array_key_exists('dest', $kwargs) && array_key_exists('orig', $kwargs)))
		{
			$dest = $kwargs["dest"];
			if (!array_key_exists('orig', $kwargs))
				$orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
			else
				$orig = $kwargs["orig"];
			$this->_x = $dest->getX() - $orig->getX();
			$this->_y = $dest->getY() - $orig->getY();
			$this->_z = $dest->getZ() - $orig->getZ();
			$this->_w = 0.0;
		}
		if (self::$verbose)
			echo $this." constructed\n";
	}
	public function __destruct()
	{
		if (self::$verbose)
			echo $this." destructed\n";
	}
	public function __toString()
	{
		return (sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w));
	}
	public static function doc()
	{
		return ("\n".file_get_contents('Vector.doc.txt'));
	}
	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function magnitude()
	{
		return sqrt($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z);
	}
	public function normalize()
	{
		$new_mage = $this->magnitude();
		return new Vector(array('x' => ($this->_x / $new_mage), 'y' => ($this->_y / $new_mage), 'z' => ($this->_z / $new_mage)));
	}
	public function add(Vector $rhs)
	{
		return new Vector(array('x' => ($this->_x + $rhs->_x), 'y' => ($this->_y + $rhs->_y), 'z' => ($this->_z + $rhs->_z)));
	}
	public function sub(Vector $rhs)
	{
		return new Vector(array('x' => ($this->_x - $rhs->_x), 'y' => ($this->_y - $rhs->_y), 'z' => ($this->_z - $rhs->_z)));
	}
	public function opposite()
	{
		return new Vector(array('x' => -$this->_x, 'y' => -$this->_y, 'z' => -$this->_z));
	}
	public function scalarProduct($k)
	{
		return new Vector(array('x' => $this->_x * $k, 'y' => $this->_y * $k, 'z' => $this->_z * $k));
	}
	public function dotProduct(Vector $rhs)
	{
		return (($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z));
	}
	public function cos(Vector $rhs)
	{
		return ($this->_x * $rhs->_x + $this->_y * $rhs->_y + $this->_z * $rhs->_z) / sqrt(($this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z) * ($rhs->_x * $rhs->_x + $rhs->_y * $rhs->_y + $rhs->_z * $rhs->_z));
	}
	public function crossProduct(Vector $rhs)
	{
		return new Vector(array('x' => (($this->_y * $rhs->_z) - ($this->_z * $rhs->_y)), 'y' => (($this->_z * $rhs->_x) - ($this->_x * $rhs->_z)), 'z' => (($this->_x * $rhs->_y) - ($this->_y * $rhs->_x))));
	}
}
?>
