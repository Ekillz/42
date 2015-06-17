/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:28:44 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 17:39:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	const char *str = "Hi THIS IS BRAIN";
	const char *p = str;
	const char &t = *str;

	std::cout << p << std::endl;
	std::cout << &t << std::endl;

	return (0);
}
