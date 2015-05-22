<?php

namespace Symfony\HomeBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\HomeBundle\Entity\product;
use Symfony\Component\HttpFoundation\Response;
class DefaultController extends Controller
{
    public function brandAction($brand, $engine)
    {
      if ($engine == "125+")
        $engine = 999;
    	$product = $this->getDoctrine()->getRepository('SymfonyHomeBundle:product');
      if ($engine == "all" && $brand == "other")
        $product = $product->findAll();
      else
      {
        $product = $product->createQueryBuilder('p');
        if ($brand == "other")
          $product = $product->where('p.engine = '.$engine)->getQuery()->getResult();
        else if ($engine == "all")
          $product = $product->where('p.brand = '."'".$brand."'")->getQuery()->getResult();
        else
          $product = $product->where('p.engine = '.$engine.' and p.brand = '."'".$brand."'")->getQuery()->getResult();
      }
      if ($engine == 999)
        $engine = "125+";
    	return $this->render('SymfonyHomeBundle:Default:index.html.twig', array(
    		'engine'     => $engine,
    		'brand'      => $brand,
    		'product'    => $product
    	));
    }
}
