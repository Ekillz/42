/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/19 16:26:01 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/19 16:41:00 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
#define SORCERER_H

#include <iostream>

class Sorcerer
{
	public:
		Sorcerer(std::string nam, std::string tit);
		//Sorcerer(void); se renseigner
		Sorcerer(Sorcerer const & src);
		Sorcerer & operator=(Sorcerer const &rhs);
		~Sorcerer(void);
		
		std::string name;
		std::string title;
};

#endif
