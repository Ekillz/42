/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:06:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/17 13:44:03 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : n(N)
{
	const char *names[] = {"Jon", "Cersei", "Arya", "Stannis", "Jaime", "Sansa", "Theon"};
	int i = 0;
	int c;
	this->obj = new Zombie[N];
	srand(time(NULL));
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	c = rand() % 7;
	while (i < N)
	{
		this->obj[i].type = "Stark";
		this->obj[i].name = names[rand() % 7];
		i++;
	}
	return ;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->obj;
	return ;
}

void ZombieHorde::announce(void)
{
	int i = 0;
	while (i < this->n)
	{
		this->obj[i].announce();
		i++;
	}
}
