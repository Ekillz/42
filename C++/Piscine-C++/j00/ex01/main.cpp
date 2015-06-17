/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:39:46 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 20:37:13 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

static void show_i_contact(Contact *ct, int which)
{
	int nb;
	std::cout << "index:";
	std::cin >> nb;
	std::cout << std::endl;
	if (which == 0)
		return ;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		nb = 32;
	}
	while (nb > 8 || nb < 0 || nb > which - 1)
	{
		std::cout << "index: ";
		std::cin >> nb;
		std::cout << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			nb = 32;
		}
	}
	std::cout << "first name: " << ct[nb].first_name << std::endl;
	std::cout << "last name: " << ct[nb].last_name << std::endl;
	std::cout << "nickname: " << ct[nb].nickname << std::endl;
	std::cout << "login: " << ct[nb].login << std::endl;
	std::cout << "postal adress: " << ct[nb].postal_adress << std::endl;
	std::cout << "email adress: " << ct[nb].email_adress << std::endl;
	std::cout << "phone number: " << ct[nb].phone_number << std::endl;
	std::cout << "birthday date: " << ct[nb].birthday_date << std::endl;
	std::cout << "favorite meal: " << ct[nb].favorite_meal << std::endl;
	std::cout << "underwear color: " << ct[nb].underwear_color << std::endl;
	std::cout << "darkest secret: " << ct[nb].darkest_secret << std::endl;
}

static int show_contacts(Contact *ct)
{
	int i = 0;
	int e = 0;
	std::cout << std::right << std::setw(10) << "index" << " | ";
	std::cout << std::right << std::setw(10) << "first name" << " | ";
	std::cout << std::right << std::setw(10) << "last name" << " | ";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;
	while (i < 8)
	{
		if (!ct[i].login.empty())
		{
			e++;
			std::cout << std::right << std::setw(10) << i << " | ";
			if (ct[i].first_name.length() > 10)
				std::cout << std::right << std::setw(10) << ct[i].first_name.substr(0, 9).append(".")<< " | ";	
			else
				std::cout << std::right << std::setw(10) << ct[i].first_name.substr(0, 10) << " | ";
			if (ct[i].last_name.length() > 10)
				std::cout << std::right << std::setw(10) << ct[i].last_name.substr(0, 9).append(".") <<" | ";
			else
				std::cout << std::right << std::setw(10) << ct[i].last_name.substr(0, 10) << " | ";
			if (ct[i].nickname.length() > 10)
				std::cout << std::right << std::setw(10) << ct[i].nickname.substr(0, 9).append(".") << std::endl;
			else
				std::cout << std::right << std::setw(10) << ct[i].nickname.substr(0, 10) << std::endl;
		}
		i++;
	}
	return e;
}

static void add_info(Contact *ct, int which, const char *info)
{
	std::string buf;
	std::cout << info << ": ";
	std::getline(std::cin, buf, '\n');
	std::cout << std::endl;
	while (buf.empty())
	{
		std::cout << info << ": ";
		std::getline(std::cin, buf, '\n');
		std::cout << std::endl;
	}
	switch (which)
	{
		case 0:
			ct->first_name = buf;
		case 1:
			ct->last_name = buf;
		case 2:
			ct->nickname = buf;
		case 3:
			ct->login = buf;
		case 4:
			ct->postal_adress = buf;
		case 5:
			ct->email_adress = buf;
		case 6:
			ct->phone_number = buf;
		case 7:
			ct->birthday_date = buf;
		case 8:
			ct->favorite_meal = buf;
		case 9:
			ct->underwear_color = buf;
		case 10:
			ct->darkest_secret = buf;
	}
	std::cout << std::endl;
}
static void add_contact(Contact *ct)
{
	add_info(ct, 0, "first name");
	add_info(ct, 1, "last name");
	add_info(ct, 2, "nickname");
	add_info(ct, 3, "login");
	add_info(ct, 4, "postal adress");
	add_info(ct, 5, "email adress");
	add_info(ct, 6, "phone number");
	add_info(ct, 7, "birthday date");
	add_info(ct, 8, "favorite meal");
	add_info(ct, 9, "underwear color");
	add_info(ct, 10, "darkest secret");
}

int main(void)
{
	Contact ct[8];

	std::string buf;
	int i = 0;
	int e;
	while (std::getline(std::cin, buf, '\n'))
	{
		if (buf == "ADD")
		{
			if (i <= 8)
				add_contact(&ct[i]);
			else
				std::cout << "You can't add anymore contacts" << std::endl;
			i++;
		}
		else if (buf =="SEARCH")
		{
			e = show_contacts(ct);
			show_i_contact(ct, e);
		}
		else if (buf == "EXIT")
		{
			std::cout << "the contacts are lost forever." << std::endl;
			break ;
		}
	}
	return (0);
}
