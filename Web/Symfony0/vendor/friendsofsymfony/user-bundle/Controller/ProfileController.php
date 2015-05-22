<?php

/*
 * This file is part of the FOSUserBundle package.
 *
 * (c) FriendsOfSymfony <http://friendsofsymfony.github.com/>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace FOS\UserBundle\Controller;

use Symfony\HomeBundle\Entity\product;
use FOS\UserBundle\FOSUserEvents;
use FOS\UserBundle\Event\FormEvent;
use FOS\UserBundle\Event\FilterUserResponseEvent;
use FOS\UserBundle\Event\GetResponseUserEvent;
use FOS\UserBundle\Model\UserInterface;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\Security\Core\Exception\AccessDeniedException;
use Symfony\UserBundle\Entity;
use Symfony\Component\HttpFoundation\Response;
/**
 * Controller managing the user profile
 *
 * @author Christophe Coevoet <stof@notk.org>
 */
class ProfileController extends Controller
{

    /**
     *  ads new product
     */

    public function cancelNewsAction()
    {
        $um = $this->get('fos_user.user_manager');
        $username = $this->getUser()->getUserName();
        $user = $um->findUserByUsername($username);
        $user->setMailNews('no');
        $um->updateUser($user);
        return new Response ('We successfully unchecked your email on our newsletter');
    }

    /**
     *  ads new product
     */
    public function addProductAction()
    {
        $request = $this->get('request');
        if ($request->isMethod('POST'))
        {
            $em = $this->getDoctrine()->getManager();
            $product = new product();
            $product->setName($request->request->get('name'))
                   ->setPrice($request->request->get('price'))
                   ->setDescription($request->request->get('description'))
                   ->setPath($request->request->get('path'))
                   ->setEngine($request->request->get('size'))
                   ->setStock($request->request->get('stock'))
                   ->setBrand($request->request->get('brand'));
            $em->persist($product);
            $em->flush();
            $this->newsLetter($product);
            $url = $this->generateUrl('fos_user_profile_show');
            $response = new RedirectResponse($url);
            return $response;

        }
        else
            return $this->render('FOSUserBundle:Profile:addProduct.html.twig');
    }

    /**
     *  shows user without profile login
     */
    public function allShowAction($name)
    {
        $um = $this->get('fos_user.user_manager');
        $user = $um->findUserByUsername($name);
        if ($user)
        {
            $image = $user->getImage();
            $user = NULL;
            return $this->render('FOSUserBundle:Profile:allshow.html.twig', array(
                'user' => $user,
                'image' => $image
            ));
        }
        else
        {
            $url = $this->generateUrl('symfony_home');
            $response = new RedirectResponse($url);
            return $response;
        }
    }

    /**
     * delete a user
     */
    public function deleteAction($username)
    {
        $userManager = $this->get('fos_user.user_manager');
        $user = $userManager->findUserByUsername($username);
        if ($username != 'admin' && $user)
        {
            $userManager->deleteUser($user);
            $user = $this->getUser();
        }
        return $this->render('FOSUserBundle:Profile:admin.html.twig', array(
                'user' => $userManager->findUsers()

            ));
    }

    /**
     * Show the user
     */
    public function showAction()
    {
        $user = $this->getUser();
        $um = $this->get('fos_user.user_manager');
        if (!is_object($user) || !$user instanceof UserInterface)
        {
            throw new AccessDeniedException('This user does not have access to this section.');
        }
        if ($user->getUsername() != 'admin')
        {
            $um = $this->get('fos_user.user_manager');
            $image = $um->findUserByEmail($user->getEmail());
            $image = $image->getImage();
            return $this->render('FOSUserBundle:Profile:show.html.twig', array(
                'user' => $user,
                'image' => $image
            ));
        }
        else
        {
            return $this->render('FOSUserBundle:Profile:admin.html.twig', array(
                'user' => $um->findUsers()

            ));
        }
    }

    /**
     * Edit the user
     */
    public function editAction(Request $request)
    {
        $user = $this->getUser();
        if (!is_object($user) || !$user instanceof UserInterface) {
            throw new AccessDeniedException('This user does not have access to this section.');
        }

        /** @var $dispatcher \Symfony\Component\EventDispatcher\EventDispatcherInterface */
        $dispatcher = $this->get('event_dispatcher');

        $event = new GetResponseUserEvent($user, $request);
        $dispatcher->dispatch(FOSUserEvents::PROFILE_EDIT_INITIALIZE, $event);

        if (null !== $event->getResponse()) {
            return $event->getResponse();
        }

        /** @var $formFactory \FOS\UserBundle\Form\Factory\FactoryInterface */
        $formFactory = $this->get('fos_user.profile.form.factory');

        $form = $formFactory->createForm();
        $form->setData($user);

        $form->handleRequest($request);

        if ($form->isValid()) {
            /** @var $userManager \FOS\UserBundle\Model\UserManagerInterface */
            $userManager = $this->get('fos_user.user_manager');

            $event = new FormEvent($form, $request);
            $dispatcher->dispatch(FOSUserEvents::PROFILE_EDIT_SUCCESS, $event);

            $userManager->updateUser($user);

            if (null === $response = $event->getResponse()) {
                $url = $this->generateUrl('fos_user_profile_show');
                $response = new RedirectResponse($url);
            }

            $dispatcher->dispatch(FOSUserEvents::PROFILE_EDIT_COMPLETED, new FilterUserResponseEvent($user, $request, $response));

            return $response;
        }

        return $this->render('FOSUserBundle:Profile:edit.html.twig', array(
            'form' => $form->createView()
        ));
    }
}
