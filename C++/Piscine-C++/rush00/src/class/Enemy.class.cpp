/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:55:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/21 21:03:02 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Enemy::Enemy(void) : Vessel()
{
	this->_x = 1;
	this->_y = 1;
	this->_chp = 0;
	this->_mhp = 1;
	this->_dmg = 1;
	this->_armor = 0;
	this->_ammo = 20;
}

Enemy::Enemy(int x, int y) : Vessel()
{
	this->_x = x;
	this->_y = y;
	this->_chp = 0;
	this->_mhp = 1;
	this->_dmg = 1;
	this->_armor = 0;
	this->_ammo = 20;
	return ;
}

Enemy & Enemy::operator=(Enemy const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	this->_chp = src.getChp();
	this->_mhp = src.getMhp();
	this->_dmg = src.getDmg();
	this->_armor = src.getArmor();
	this->_ammo = src.getAmmo();

	return (*this);
}

Enemy & Enemy::operator+=(int amount)
{
	this->_y = this->_y + amount;
	return (*this);
}

Enemy & Enemy::operator-=(int amount)
{
	this->_y = this->_y - amount;
	return (*this);
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
	std::cout << "Enemy dead" << std::endl;
	return;
}

void Enemy::collideAction()
{
	std::cout << "enemy: new collide action" << std::endl;
}

void Enemy::shoot()
{
	std::cout << "enemy shooted" << std::endl;
}

void Enemy::genMov()
{
	switch ( random() % 20 )
	{
		case		1:
			if ( this->getX() - 1 > 0 )
				this->setX( this->getX() - 1 );
			break;
		case		2:
			if ( this->getX() + 1 < MAX_W )
				this->setX( this->getX() + 1 );
			break;
		default:
			break;
	}
}
