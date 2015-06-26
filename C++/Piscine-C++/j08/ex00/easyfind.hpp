/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 15:53:09 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/25 18:38:04 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
void easyfind(T v, int n)
{
	std::vector<int>::iterator it;
	it = std::find(v.begin(), v.end(), n);
	if (it == v.end())
		throw std::string("Exception: Value couldn't be found");
	else
		std::cout << "Value was found" << std::endl;
}
