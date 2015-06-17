/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:46:35 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 18:28:52 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : size(1260)
{
	const void * address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << address;
	std::string name = ss.str();
	this->adress = name;
	return;
}

std::string Brain::identify(void)
{
	return (this->adress);
}
