/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:49:51 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 19:59:00 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon 
{
	public:
		std::string const &getType(void);
		std::string type;
		void  setType(std::string t);
		Weapon(std::string t);
};

#endif
