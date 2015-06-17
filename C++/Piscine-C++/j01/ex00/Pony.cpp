/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 13:14:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 14:10:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(float h, float w, float wd, float s, int a) : height(h), width(w), weight(wd), speed(s), age(a)
{
	std::cout << "Pony class instance created" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Pony instance destroyed" << std::endl;
	return ;
}

void Pony::jump(int height)
{
	std::cout << "Pony jumped " << height << " meters high" << std::endl; 
}
