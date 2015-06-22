/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:23:10 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 22:49:08 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string nam) :ClapTrap(nam), name(nam)
{
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->name = nam;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	std::cout << "NINJ4-TP " << name << " came into existence" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(void) : ClapTrap("test")
{
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->meleeAttackDamage = 60;
	this->rangedAttackDamage = 5;
	this->armorDamageReduction = 0;
	std::cout << "NINJ4-TP " << name << " came into existence" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src.name)
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

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NINJ4-TP " << this->name << " went to valhala" << std::endl;
	return ;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &rhs)
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

void NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
	std::cout << "Here is your shoe choosen specifically for you " << target.name << " you will reach a new level, or not" << std::endl;
}
void NinjaTrap::ninjaShoebox(FragTrap const &target)
{
	std::cout << "Here is your shoe choosen specifically for you " << target.name << " you will reach a new level, or not" << std::endl;
}
void NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
	std::cout << "Here is your shoe choosen specifically for you " << target.name << " you will reach a new level, or not" << std::endl;
}
void NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
	std::cout << "Here is your shoe choosen specifically for you " << target.name << " you will reach a new level, or not" << std::endl;
}
