/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:33:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/18 16:13:14 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fx(0)
{
	return;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return;
}

Fixed::Fixed(const int n)
{
	this->_fx = n * 256;
	return;
}

Fixed::Fixed(const float n)
{
	this->_fx = roundf(n * 256.0);
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
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

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->_fx < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->_fx > rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->_fx <= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->_fx >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->_fx == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->_fx != rhs.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed res;
	res._fx = this->_fx + rhs.getRawBits();
	return res;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed res;
	res._fx = this->_fx - rhs.getRawBits();
	return res;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed res;
	res._fx = (this->_fx * rhs.getRawBits()) / 256;
	return res;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed res;
	res._fx = this->_fx / rhs.getRawBits();
	return res;
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return fix1._fx > fix2._fx ? fix2 : fix1;
}

Fixed const &Fixed::min(Fixed const &fix1, const Fixed &fix2)
{
	return fix1._fx > fix2._fx ? fix2 : fix1;
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return fix1._fx < fix2._fx ? fix2 : fix1;
}

Fixed const &Fixed::max(Fixed const &fix1, const Fixed &fix2)
{
	return fix1._fx < fix2._fx ? fix2 : fix1;
}

Fixed &Fixed::operator++()
{
	this->_fx += 1;
	return *this;
}

Fixed Fixed::operator++(int rhs)
{
	(void)rhs;
	Fixed copy(*this);
	++(*this);
	return copy;
}

const int Fixed::_bits = 8;
