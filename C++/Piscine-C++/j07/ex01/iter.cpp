/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:29:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/25 20:56:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
	template<typename D>
void add(D const & type)
{
	std::cout << type << "  +=  YES WE CAN" << std::endl;
}

	template<typename A>
void iter(A * array, int len, void (*f)(A const &) )
{
	int i = 0;
	while (i < len)
	{
		f(array[i]);
		i++;
	}
}
int main(void)
{
	char str[6] = "dudes";
	int len = 5;
	int tab[5] = {0, 1, 2, 3, 4};
	std::cout << "instanciated as <char>" << std::endl;
	::iter(str, len, add<char>);
	std::cout << "instanciated as <int>" << std::endl;
	::iter(tab, len, add<int>);
	return (0);
}
