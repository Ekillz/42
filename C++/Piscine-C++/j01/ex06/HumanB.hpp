/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 13:56:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/17 14:02:28 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "HumanA.hpp"

class HumanB
{
	public:
		Weapon *weapon;
		std::string name;
		void attack(void);
		HumanB(std::string n);
		void setWeapon(Weapon &w);
};

#endif
