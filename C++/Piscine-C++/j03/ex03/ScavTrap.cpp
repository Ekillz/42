/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:43:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 22:48:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nam) : ClapTrap(nam), name(nam)
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->name = nam;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	std::cout << "SC4V-TP " << name << " came into existence" << std::endl;
	return ;
}

ScavTrap::ScavTrap(void) : ClapTrap("test")
{
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	std::cout << "SC4V-TP " << " came into existence" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src.name)
{
	*this = src;
	this->hitPoints = src.hitPoints;
	this->maxHitPoints = src.maxHitPoints;
	this->energyPoints = src.energyPoints;
	this->maxEnergyPoints = src.maxEnergyPoints;
	this->level = src.level;
	this->meleeAttackDamage = src.meleeAttackDamage;
	this->rangedAttackDamage = src.rangedAttackDamage;
	this->armorDamageReduction = src.armorDamageReduction;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP " << this->name << " died with honor" << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	this->hitPoints = rhs.hitPoints;
	this->maxHitPoints = rhs.maxHitPoints;
	this->energyPoints = rhs.energyPoints;
	this->maxEnergyPoints = rhs.maxEnergyPoints;
	this->level = rhs.level;
	this->meleeAttackDamage = rhs.meleeAttackDamage;
	this->rangedAttackDamage = rhs.rangedAttackDamage;
	this->armorDamageReduction = rhs.armorDamageReduction;
	return *this;
}

void ScavTrap::challengeNewcomer(void)
{
	const char *names[] = {"Drink this, it contains 2 liters of water. Now take this pill its for power, good actually it was viagra... Now try to pee", "Can you catch a misquito without killing it?", "Get past the security with 2kg of coke, and no you can't swallow it", "what does c++ have that c does not?... the class."};
	std::cout << "SC4V-TP " << names[rand() % 4] << std::endl;
}
