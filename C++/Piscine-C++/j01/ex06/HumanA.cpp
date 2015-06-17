/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:09:23 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/17 13:58:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : name(n), weapon(&w)
{
	return;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->type << std::endl;
}
