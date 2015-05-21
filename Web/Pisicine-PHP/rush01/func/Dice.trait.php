<?php

trait Dice
{
    public function roll()
    {
        return rand(1, 6);
    }
}

?>