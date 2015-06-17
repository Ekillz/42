/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 20:06:26 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/15 20:17:11 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	Contact::_nbContacts++;
	if (Contact::_nbContacts == 8)
		std::cout << "Contact list initialized" << std::endl;
	return;
}

Contact::~Contact(void)
{
	if (Contact::_nbContacts == 8)
		std::cout << "Contact list destroyed" << std::endl;
	Contact::_nbContacts++;
	return;
}

int Contact::_nbContacts = 0;
