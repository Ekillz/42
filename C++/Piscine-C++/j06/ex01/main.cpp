/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 15:47:02 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/24 18:41:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

struct Data 
{
	std::string s1;
	int n;
	std::string s2;
};

Data * deserialize(void *raw)
{
	Data *d = new Data;

	d->s1 = reinterpret_cast<char *>(raw);
	d->s2 = d->s1.substr(d->s1.length() - 8, d->s1.length());
	d->n = atoi(d->s1.substr(8, d->s1.length() - 8).c_str());
	d->s1 = d->s1.substr(0, 8);
	return (d);
}

void* serialize(void)
{
	const char list[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	void *b;

	std::string str;
	while (i < 8)
	{
		str.push_back(list[rand() % static_cast<int>(sizeof(list) - 1)]);
		i++;
	}
	std::stringstream out;
	out << rand() % 2147483647;
	str += out.str();
	i = 0;
	while (i < 8)
	{
		str.push_back(list[rand() % static_cast<int>(sizeof(list) - 1)]);
		i++;
	}
	return reinterpret_cast<void *>(const_cast<char *>(str.c_str()));
}

int main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	void *s = serialize();
	std::cout << "Data memory adress: " << s << std::endl;
	std::cout << "Serialized data: "  << reinterpret_cast<char *>(s) << std::endl;
	std::cout << "Deserialized data: " << std::endl;
	Data *d = deserialize(s);
	std::cout << "first string: " << d->s1 << std::endl;
	std::cout << "integer: " << d->n << std::endl;
	std::cout << "second string: " << d->s2 << std::endl;
	return (0);
}
