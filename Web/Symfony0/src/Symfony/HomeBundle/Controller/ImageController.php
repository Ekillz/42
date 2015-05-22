<?php

namespace Symfony\HomeBundle\Controller;

use FOS\UserBundle\Entity\User;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\HomeBundle\Entity\product;
use Symfony\Component\HttpFoundation\Response;

class ImageController extends Controller
{
  public function iAction()
  {
     $um = $this->get('fos_user.user_manager');
     $user = $um->findUserByUsername($name);
     $user->setImage($image);
     $um->updateUser($user);
     return new Response ('Done');
  }
}

?>