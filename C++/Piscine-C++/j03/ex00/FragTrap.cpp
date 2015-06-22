/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 17:20:03 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 22:34:43 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string nam) : hitPoints(100), maxHitPoints(100), energyPoints(100),
	maxEnergyPoints(100), level(1), name(nam), meleeAttackDamage(30), rangedAttackDamage(20),
	armorDamageReduction(5)
{
	std::cout << "FR4G-TP " << name << " initialized" << std::endl;
	return ;
}

FragTrap::FragTrap(void) : hitPoints(100), maxHitPoints(100), energyPoints(100),
	maxEnergyPoints(100), level(1),  meleeAttackDamage(30), rangedAttackDamage(20),
	armorDamageReduction(5)
{
	std::cout << "FR4G-TP " << " initialized" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
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

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP " << this->name << " destructed" << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name <<  " attacks " <<  target << " at range , causing " << this->rangedAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->name <<  " attacks " <<  target << " at melee , causing " << this->meleeAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if ((this->hitPoints - ((int)amount - this->armorDamageReduction)) < 0)
		this->hitPoints = 0;
	else
		this->hitPoints -= ((int)amount - this->armorDamageReduction);

	std::cout << "FR4G-TP " << this->name <<  " took " << amount - this->armorDamageReduction << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if ((this->hitPoints + (int)amount) > this->maxHitPoints)
		this->hitPoints = this->maxHitPoints;
	else
		this->hitPoints += (int)amount;

	std::cout << "FR4G-TP " << this->name <<  " repaired himself for " << amount << " hit points!" << std::endl;

}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	const char *names[] = {"copies pikachu and uses thunder", "spits with haki", "uses jewjutsu", "starts tapdancing creating an earthquake with the epicenter", "shoots with an Barrett .50 cal m82 "};

	if ((this->energyPoints - 25) >= 0)
	{
		std::cout << "FR4G-TP " << this->name << " " << names[rand() % 5] << " on " << target << std::endl;
		this->energyPoints -= 25;
	}
	else
		std::cout << "FR4G-TP " << this->name << " is out of energy" << std::endl;
}
