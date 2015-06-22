/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:55:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/21 20:17:25 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Player::Player(void) : Vessel()
{
	this->_x = 1;
	this->_y = MAX_H;
	this->_chp = 1;
	this->_mhp = 1;
	this->_score = 0;
	this->_dmg = 1;
	this->_armor = 0;
	this->_ammo = 20;
}

Player & Player::operator=(Player const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	this->_chp = src.getChp();
	this->_mhp = src.getMhp();
	this->_score = src.getScore();
	this->_dmg = src.getDmg();
	this->_armor = src.getArmor();
	this->_ammo = src.getAmmo();

	return (*this);
}

Player::Player(Player const & src)
{
	*this = src;
}

Player::~Player(void)
{
	std::cout << "Player dead" << std::endl;
	return;
}

void Player::collideAction()
{
	std::cout << "new collide action" << std::endl;
}

void Player::shoot()
{
	std::cout << "player shooted" << std::endl;
}

int Player::getScore() const { return this->_score; }

void Player::setScore(int amount) { this->_score = amount;}
