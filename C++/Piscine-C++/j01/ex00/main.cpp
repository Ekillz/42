/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 13:13:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 14:10:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap(int which)
{
	Pony *p = new Pony(50, 30, 40, 29, 3);
	std::cout << "height: " << p->height << std::endl;
	std::cout << "width: " << p->width << std::endl;
	std::cout << "weight: " << p->weight << std::endl;
	std::cout << "speed: " << p->speed << std::endl;
	std::cout << "age: " << p->age << std::endl;
	p->jump(10);
	if (which == 0)
		delete p;
	std::cout << "getting out of function scope" << std::endl << std::endl;
}

void ponyOnTheStack(void)
{
	Pony p(50, 30, 40, 29, 3);
	std::cout << "height: " << p.height << std::endl;
	std::cout << "width: " << p.width << std::endl;
	std::cout << "weight: " << p.weight << std::endl;
	std::cout << "speed: " << p.speed << std::endl;
	std::cout << "age: " << p.age << std::endl;
	p.jump(2000);
	std::cout << "getting out of function scope" << std::endl << std::endl;
}

int main(void)
{
	std::cout << "creating instance dynamically and deleting, destructor will be called" << std::endl;
	ponyOnTheHeap(0);
	std::cout << "creating instance dynamically without deleting, destructor will not be called " << std::endl;
	ponyOnTheHeap(1);
	std::cout << "creating instance statically, destructor will be called" << std::endl;
	ponyOnTheStack();
	return (0);
}
