<?php
// src/Acme/UserBundle/Entity/User.php

namespace Symfony\UserBundle\Entity;

use FOS\UserBundle\Model\User as BaseUser;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 * @ORM\Table(name="tuto_users")
 */
class User extends BaseUser
{
	/**
     * @ORM\Id
     * @ORM\Column(type="integer")
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    protected $id;

    /**
     * @var string;
     */
    protected $image;

    public function getImage()
    {
    	return $this->image;
    }
    public function setImage($image)
    {
    	$this->image = $image;

    	return $this;
    }
}