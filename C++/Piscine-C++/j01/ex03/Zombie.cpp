/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:21:34 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 17:06:32 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << "<" + this->name + "  (" + this->type + ")>  "  + "Braiiiiiiinnnssss... IQ > 120 PLS" << std::endl;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "!HEADSHOT!" << " <" << this->name << "  (" << this->type << ")>  "  "deeeeaaaaaddd...." << std::endl;
	return ;
}
