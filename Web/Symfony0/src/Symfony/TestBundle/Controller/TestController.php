<?php

namespace Symfony\TestBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Response;

class TestController extends Controller
{
	function indexAction()
	{
		return new Response("Ceci est un test!");
	}
}

