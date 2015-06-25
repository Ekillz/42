/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 18:42:50 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/25 18:54:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Awesome { 

	public: 

		Awesome( int n ) : _n( n ) {} 

		bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); } 
		bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); } 
		bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); } 
		bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); } 
		bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); } 
		bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); } 

		int _n; 
}; 

	template<typename U>
void swap(U & a, U & b)
{
	U c = a;
	a = b;
	b = c;
}

	template<typename U>
U & min(U & a, U & b)
{
	if (a < b)
		return (a);
	return (b);
}

	template<typename U>
U & max(U & a, U & b)
{
	if (a > b)
		return (a);
	return (b);
}

int main( void ) {
	int a = 2;
	int b = 3;
	Awesome aa(3);
	Awesome bb(4);
	Awesome cc =  min(aa, bb);
	std::cout << cc._n << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	float f = 3.14;
	float e = 3.1427;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "f = " << f << ", e = " << e << std::endl;
	std::cout << "min( f, e ) = " << ::min( f, e ) << std::endl;
	std::cout << "max( f, e ) = " << ::max( f, e ) << std::endl;
	return 0;
}
