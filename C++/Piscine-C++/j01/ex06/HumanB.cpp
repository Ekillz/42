/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:58:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/17 14:01:56 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n)
{
	return;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->type << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;	
}
