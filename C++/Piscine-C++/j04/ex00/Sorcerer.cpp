/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 16:34:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 16:40:57 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string nam, std::string tit) : name(nam), title(tit)
{
	std::cout << nam << ", " << title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	return;
}

Sorcerer::~Sorcerer(void)
{
	return:
}

Sorcerer & Sorcerer::operator=(Sorcerer const &rhs)
{
	(void)rhs;
	return *this;
}
