/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:27:15 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/18 16:13:16 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed(void);
		Fixed & operator=(Fixed const &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator<(Fixed const &rhs);		
		bool operator>(Fixed const &rhs);		
		bool operator<=(Fixed const &rhs);		
		bool operator>=(Fixed const &rhs);		
		bool operator==(Fixed const &rhs);		
		bool operator!=(Fixed const &rhs);
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;
		Fixed & operator++();
		Fixed operator++(int rhs);
		static Fixed		&min(Fixed &fix1, Fixed &fix2);
		static Fixed const	&min(Fixed const &fix1, const Fixed &fix2);
		static Fixed		&max(Fixed &fix1, Fixed &fix2);
		static Fixed const	&max(Fixed const &fix1, const Fixed &fix2);

	private:
		int _fx;
		static const int _bits;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
#endif
