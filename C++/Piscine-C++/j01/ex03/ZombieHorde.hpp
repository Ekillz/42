/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:02:42 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 17:22:28 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
#define ZOMBIEHORDE_H

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde
{
	public:
		Zombie *obj;
		int n;

		void announce(void);
		ZombieHorde(int N);
		~ZombieHorde(void);
};

#endif
