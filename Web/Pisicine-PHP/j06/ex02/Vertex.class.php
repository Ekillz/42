<?php

require_once "Color.class.php";

class Vertex 
{
	private $_x;
	private $_y;
	private $_z;
	private $_w;
	static $verbose = False;
	private $_color;
	public function __construct(array $kwargs)
	{
		if (array_key_exists('x', $kwargs) && array_key_exists('y', $kwargs) && 
			array_key_exists('z', $kwargs))
		{
			$this->_x = $kwargs["x"];
			$this->_y = $kwargs["y"];
			$this->_z = $kwargs["z"];
		}
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs["w"];
		else
			$this->_w = 1.0;
		if (array_key_exists('color', $kwargs))
			$this->_color = $kwargs['color'];
		else
			$this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
		if (self::$verbose)
			echo $this." constructed\n";
	}
	public function __destruct()
	{
		if (self::$verbose)
			echo $this. " destructed\n";
	}
	public function __tostring()
	{
		if (self::$verbose)
			return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, %s )", array($this->_x, $this->_y, $this->_z, $this->_w, $this->_color)));
		else
			return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f )", array($this->_x, $this->_y, $this->_z, $this->_w)));
	}
	public function doc()
	{
		return ("\n".file_get_contents('Vertex.doc.txt'));
	}
	public function getX()
	{ 
		return $this->_x; 
	}
	public function getY() 
	{
		return $this->_y; 
	}
	public function getZ()
	{ 
		return $this->_z; 
	}
	public function getW() 
	{
		return $this->_w;
	}
	public function getColor() { 
		return $this->_Color; 
	}
	public function setX($new_val)
	{
		$this->_x = $new_val;
	}
	public function setY($new_val)
	{
		$this->_y = $new_val;
	}
	public function setZ($new_val)
	{
		$this->_z = $new_val;
	}
	public function setW($new_val)
	{
		$this->_w = $new_val;
	}
	public function setColor($new_val)
	{
		$this->_color = $new_val;
	}
}
?>
