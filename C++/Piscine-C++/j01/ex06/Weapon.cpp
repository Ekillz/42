/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:52:01 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/17 13:49:42 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string t) : type(t)
{
	return;
}

std::string const &Weapon::getType(void)
{
	std::string const &str = this->type;
	return (str);
}

void Weapon::setType(std::string t)
{
	this->type = t;
}
