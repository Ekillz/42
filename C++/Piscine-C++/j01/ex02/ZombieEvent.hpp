/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:25:56 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 15:20:34 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
#define ZOMBIEEVENT_H

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		std::string type;

		void setZombieType(std::string type);
		Zombie* newZombie(std::string name);
		void randomChump(void);
};


#endif
