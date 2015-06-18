/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:33:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/18 12:27:08 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fx(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fx = n * 256;
	return;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fx = roundf(n * 256.0);
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fx = rhs.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_fx;
}

void Fixed::setRawBits(int const raw)
{
	this->_fx = raw;
}

float Fixed::toFloat(void) const
{
	return this->_fx / 256.0;
}

int Fixed::toInt(void) const
{
	return this->_fx / 256;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.getRawBits() / 256.0;
	return o;
}

const int Fixed::_bits = 8;
