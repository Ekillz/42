<?php

interface IZone
{
/*	private $_width;
    private $_height;
    private $_map; //array
*/
    
    public function __construct(array $kw_arg);
/*
  keys : "width" => int, "height" => int, "obstacle" => array("x" => y))
*/
}

?>