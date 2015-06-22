/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 14:03:59 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 15:25:48 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string nam) : name(nam)
{
	std::cout << "CL4P-TP " << name << " came into existence" << std::endl;
	return ;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "CL4P-TP " << " came into existence" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "CL4P-TP " << this->name << " went to valhala" << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	(void)rhs;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name <<  " pokes " <<  target << " at range , dealing " << this->rangedAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name <<  " pokes " <<  target << " at melee , dealing " << this->meleeAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPoints - ((int)amount - this->armorDamageReduction)) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints -= ((int)amount - this->armorDamageReduction);

	std::cout << this->name <<  " took " << amount - this->armorDamageReduction << " points of damage like a man" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->hitPoints + (int)amount) > this->maxHitPoints)
		this->hitPoints = this->maxHitPoints;
	else
		this->hitPoints += (int)amount;

	std::cout << this->name <<  " used green magic to heal himself for  " << amount << " hit points!" << std::endl;

}
