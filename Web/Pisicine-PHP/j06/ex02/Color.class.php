<?php
class Color
{
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = False;
	public function __construct(array $kwargs)
	{
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = intval(($kwargs['rgb'] >> 16) % 256);
			$this->green = intval(($kwargs['rgb'] >> 8) % 256);
			$this->blue = intval($kwargs['rgb'] % 256);
		}
		else if (array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs))
		{
			$this->red = intval($kwargs["red"]);
			$this->green = intval($kwargs["green"]);
			$this->blue = intval($kwargs["blue"]);
		}
		if (self::$verbose == True)
			echo $this." constructed.\n";
		return;
	}

	public function __toString()
	{
		return sprintf("Color( red: % 3d, green: % 3d, blue: % 3d )", $this->red, $this->green, $this->blue);
	}

	public function __destruct()
	{
		if (self::$verbose == True)
			echo $this." destructed.\n";
	}
	public static function doc()
	{
		$str = "\n".file_get_contents("Color.doc.txt");
		return $str;
	}
	public function add(Color $rhs)
	{
		$red_tmp = $this->red + $rhs->red;
		$green_tmp = $this->green + $rhs->green;
		$blue_tmp = $this->blue + $rhs->blue;
		return new color((array('red' => $red_tmp, 'green' => $green_tmp, 'blue' => $blue_tmp)));
	}
	public function sub(Color $rhs)
	{
		$red_tmp = $this->red - $rhs->red;
		$green_tmp = $this->green - $rhs->green;
		$blue_tmp = $this->blue - $rhs->blue;
		return new color((array('red' => $red_tmp, 'green' => $green_tmp, 'blue' => $blue_tmp)));
	}
	public function mult($f)
	{
		$red_tmp = $this->red * $f;
		$green_tmp = $this->green * $f;
		$blue_tmp = $this->blue * $f;
		return new color((array('red' => $red_tmp, 'green' => $green_tmp, 'blue' => $blue_tmp)));
	}
}
?>
