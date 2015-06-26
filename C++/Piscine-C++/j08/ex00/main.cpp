/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 16:00:10 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/25 18:38:12 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v(5);
	v[0] = 1;
	v[1] = 6;
	v[2] = 3;
	v[3] = 3;
	v[4] = 2;
	try
	{
		std::cout << "values of vector: " << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << std::endl;
		std::cout << "trying to find 2" << std::endl;
		easyfind(v, 2);
		std::cout << "trying to find 5" << std::endl;
		easyfind(v, 5);
	}
	catch (std::string s)
	{
		std::cout << s << std::endl;
	}
	return (0);
}
