/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 17:17:35 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 14:52:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
	public:
		FragTrap(std::string nam);
		FragTrap(void);
		FragTrap(FragTrap const & src);
		FragTrap & operator=(FragTrap const &rhs);
		~FragTrap(void);

		std::string name;
		void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);		
		void vaulthunter_dot_exe(std::string const & target);
};

#endif
