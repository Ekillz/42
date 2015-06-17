/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:53:54 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 18:25:20 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	Brain *t = new Brain();
	this->brain = *t;
}

std::string Human::identify()
{
	return (this->brain.identify());
}

Brain Human::getBrain(void)
{
	return (this->brain);
}
