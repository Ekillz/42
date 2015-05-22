<?php

namespace Symfony\HomeBundle\Controller;

use FOS\UserBundle\Entity\User;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\HomeBundle\Entity\product;
use Symfony\Component\HttpFoundation\Response;

class DataController extends Controller
{

   public function addProductAction()
   {
       $em = $this->getDoctrine()->getManager();
       $product = new product();
       $product->setName('Aprilia 50 motard')
               ->setPrice('1599€')
               ->setDescription("Le SR Motard apporte à la gamme des scooters SR sportifs, l’esprit des grands supermotard Aprilia parmi lesquels la Dorsoduro ou l'ancienne SX")
               ->setPath('/bundles/vmotors/images/aprilia-50')
               ->setEngine('50')
               ->setStock('2')
               ->setBrand('aprilia');
       $em->persist($product);
       $em->flush();
       $this->newsLetter($product);
       return new Response('done');
   }

	 public function createAction()
    {
       $em = $this->getDoctrine()->getManager();
       $product = new product();
       $product->setName('Aprilia 50 motard')
               ->setPrice('1599€')
               ->setDescription("Le SR Motard apporte à la gamme des scooters SR sportifs, l’esprit des grands supermotard Aprilia parmi lesquels la Dorsoduro ou l'ancienne SX")
               ->setPath('/bundles/vmotors/images/aprilia-50')
               ->setEngine('50')
               ->setStock('2')
               ->setBrand('aprilia');
       $em->persist($product);
       $product = new product();
       $product->setName('Gilera Runner 50 sp')
               ->setPrice('2499€')
               ->setDescription("Le Runner de Gilera fait partie de la catégorie poids lourds dans le monde du scooter 50 cm3! En effet, avec ses 100Kg et ses équipements dignes d'un 125 cm3, il se positionne au top de ce qui se fait. Ainsi, il permet de répondre aux besoins des plus exigeants...")
               ->setPath('/bundles/vmotors/images/runner-50')
               ->setEngine('50')
               ->setStock('5')
               ->setBrand('other');
       $em->persist($product);
       $product = new product();
       $product->setName('Piaggio Zip 50')
               ->setPrice('1099€')
               ->setDescription("Equipé du performant moteur 2 temps Piaggio Hi-PER2, le Zip 50 2T est particulièrement agréable à conduire en environnement urbain. Ses petites roues de 10'' et son gabarit compact font merveille.")
               ->setPath('/bundles/vmotors/images/zip-50')
               ->setEngine('50')
               ->setStock('13')
               ->setBrand('other');
       $em->persist($product);
       $product = new product();
       $product->setName('kawasaki Z1000')
               ->setPrice('11999')
               ->setDescription("Les carénages sculptés et le design inspiré du concept “Sugomi” rendent la Z1000 encore plus agressive et en font une moto unique, dépouillée de tout artifice afin de mettre en avant son côté bestial. Les réglages de châssis et de moteur, la tenue de route et l’expérience de pilotage poussée à son paroxysme font de la Z1000 le roadster de grosse cylindrée le plus radical du marché.")
               ->setPath('/bundles/vmotors/images/kawasaki-z1000.png')
               ->setEngine('999')
               ->setStock('3')
               ->setBrand('kawasaki');
       $em->persist($product);
       $product = new product();
       $product->setName('Yamaha majesty 125')
               ->setPrice('2999')
               ->setDescription("C'est peut-être le véhicule urbain dont vous rêviez ! En effet, le nouveau Majesty S combine praticité, performance et économie. Ce scooter urbain de 125 cm³ rendra chaque déplacement plus agréable.")
               ->setPath('/bundles/vmotors/images/yamaha-majesty-125.jpg')
               ->setEngine('125')
               ->setStock('7')
               ->setBrand('yamaha');
       $em->persist($product);
       $em->flush();
       return new Response('Id du produit créé : '.$product->getId());
    }
}
?>
