/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:21:34 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 15:20:57 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << "<" + this->name + "  (" + this->type + ")>  "  + "Braiiiiiiinnnssss... IQ > 120 PLS" << std::endl;
}

Zombie::Zombie(std::string type1, std::string name1) : name(name1), type(type1)
{
	this->announce();
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "!HEADSHOT!" << " <" << this->name << "  (" << this->type << ")>  "  "deeeeaaaaaddd...." << std::endl;
	return ;
}
