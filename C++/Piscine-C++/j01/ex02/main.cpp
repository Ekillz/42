/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:51:46 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 15:56:20 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	Zombie z1("lannister", "stannis");
	ZombieEvent *z2 = new ZombieEvent();
	z2->setZombieType("Targaryen");
	Zombie *test = z2->newZombie("emil");
	z2->randomChump();
	delete z2;
	delete test;
	return (0);
}
