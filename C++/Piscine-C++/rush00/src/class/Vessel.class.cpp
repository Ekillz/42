/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vessel.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:37:12 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/20 18:31:11 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vessel.class.hpp"

Vessel::Vessel(void)
{
	return;
}

Vessel & Vessel::operator=(Vessel const & src)
{
	*this = src;
	return (*this);
}

Vessel::Vessel(Vessel const & src)
{
	*this = src;
	return ;
}

Vessel::~Vessel(void)
{
	return ;
}

void Vessel::collideAction()
{
	std::cout << "collide action" << std::endl;
}

int Vessel::getDmg() const{ return this->_dmg; }
int Vessel::getArmor() const { return this->_armor; }
int Vessel::getAmmo() const { return this->_ammo; }
int Vessel::getX() const { return this->_x; }
int Vessel::getY() const { return this->_y; }
int Vessel::getChp() const { return this->_chp; }
int Vessel::getMhp() const { return this->_mhp; }

void Vessel::setDmg(int amount) { this->_dmg = amount;}
void Vessel::setArmor(int amount) { this->_armor = amount;}
void Vessel::setAmmo(int amount) { this->_ammo = amount;}
void Vessel::setX(int amount) { this->_x = amount;}
void Vessel::setY(int amount) { this->_y = amount;}
void Vessel::setChp(int amount) { this->_chp = amount;}
void Vessel::setMhp(int amount) { this->_mhp = amount;}
