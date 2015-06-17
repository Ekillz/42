/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:19:17 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 15:20:24 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie 
{
	public:
		std::string name;
		std::string type;

		Zombie(std::string type1, std::string name1);
		~Zombie(void);
		void announce();
};

#endif
