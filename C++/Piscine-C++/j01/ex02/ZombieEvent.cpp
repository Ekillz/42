/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:30:46 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 17:20:10 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *z = new Zombie(this->type, name);
	return (z);
}

void ZombieEvent::randomChump(void)
{
	const char *names[] = {"Jon", "Cersei", "Arya", "Stannis", "Jaime", "Sansa", "Theon"};
	srand((unsigned int)time(NULL));
	int c;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	Zombie got(this->type, names[rand() % 7]);	
}
