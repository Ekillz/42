/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 12:43:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 13:58:57 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nam) : hitPoints(100), maxHitPoints(100), energyPoints(50),
	maxEnergyPoints(50), level(1), name(nam), meleeAttackDamage(20), rangedAttackDamage(15),
	armorDamageReduction(3)
{
	std::cout << "SC4V-TP " << name << " came into existence" << std::endl;
	return ;
}

ScavTrap::ScavTrap(void) : hitPoints(100), maxHitPoints(100), energyPoints(50),
	maxEnergyPoints(50), level(1), meleeAttackDamage(20), rangedAttackDamage(15),
	armorDamageReduction(3)
{
	std::cout << "SC4V-TP " << " came into existence" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP " << this->name << " went to valhala" << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	(void)rhs;
	return *this;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->name <<  " pokes " <<  target << " at range , dealing " << this->rangedAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << this->name <<  " pokes " <<  target << " at melee , dealing " << this->meleeAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPoints - ((int)amount - this->armorDamageReduction)) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints -= ((int)amount - this->armorDamageReduction);

	std::cout << "SC4V-TP " << this->name <<  " took " << amount - this->armorDamageReduction << " points of damage like a man" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if ((this->hitPoints + (int)amount) > this->maxHitPoints)
		this->hitPoints = this->maxHitPoints;
	else
		this->hitPoints += (int)amount;

	std::cout << "SC4V-TP " << this->name <<  " used green magic to heal himself for  " << amount << " hit points!" << std::endl;

}

void ScavTrap::challengeNewcomer(void)
{
	const char *names[] = {"Drink this, it contains 2 liters of water. Now take this pill its for power, good actually it was viagra... Now try to pee", "Can you catch a misquito without killing it?", "Get past the security with 2kg of coke, and no you can't swallow it", "what does c++ have that c does not?... the class."};
	std::cout << "SC4V-TP " << names[rand() % 4] << std::endl;
}
