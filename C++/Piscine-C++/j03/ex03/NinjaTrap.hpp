/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 15:15:58 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 16:00:35 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "CLapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(std::string nam);
		NinjaTrap(void);
		NinjaTrap(NinjaTrap const & src);
		NinjaTrap & operator=(NinjaTrap const &rhs);
		~NinjaTrap(void);

		std::string name;
		void ninjaShoebox(ClapTrap const &target);
		void ninjaShoebox(FragTrap const &target);
		void ninjaShoebox(ScavTrap const &target);
		void ninjaShoebox(NinjaTrap const &target);
};

#endif
