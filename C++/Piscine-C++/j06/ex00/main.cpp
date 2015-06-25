/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 19:32:13 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/24 19:55:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <float.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <cstring>

void	is_char( char c )
{
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>( c ) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" <<  std::endl;
	std::cout << "double: " << static_cast<double>( c ) << std::endl;
}

void	is_int( int i, int precision )
{
	if ( isprint(i) )
		std::cout << "char: "<< "'" << static_cast<char> ( i ) << "'" << std::endl;
	else
		std::cout << "char: " << " Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	if ( fmod ( static_cast<double>( i ), 1 ) == 0 )
	{
		std::cout << std::setprecision( precision ) << "float: " << static_cast<float>( i ) << ".0f" << std::endl;
		std::cout << std::setprecision( precision ) << "double: " << static_cast<double>( i ) << ".0" << std::endl;
	}
	else
	{
		std::cout << std::setprecision( precision ) << "float: " << static_cast<float>( i ) << ".f" << std::endl;
		std::cout << std::setprecision( precision ) << "double: " << static_cast<double>( i ) << std::endl;
	}

}

void	is_float( float f, int precision )
{
	if ( isprint(f) )
		std::cout << "char: " << "'" << static_cast<char> ( f ) << "'" << std::endl;
	else
		std::cout << "char: " << " Non displayable" << std::endl;
	if ( f < INT_MAX )
		std::cout << "int: " << static_cast<int>( f ) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if ( fmod ( f, 1 ) == 0 )
	{
		std::cout << std::setprecision( precision ) << "float: " << f << ".0f" << std::endl;	
		std::cout << std::setprecision( precision ) << "double: " << static_cast<double>( f ) << ".0" << std::endl;
	}
	else
	{
		std::cout << std::setprecision( precision ) <<  "float: " << f << "f" << std::endl;
		std::cout << std::setprecision( precision ) <<  "double: " << static_cast<double>( f ) << std::endl;
	}
}

void	is_double( double d, int precision )
{
	if ( isprint(d) )
		std::cout << "char: " << "'" << static_cast<char> ( d ) << "'" <<  std::endl;
	else
		std::cout << "char: " << " Non displayable" << std::endl;
	if ( d < INT_MAX )
		std::cout << "int: " << static_cast<int>( d ) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if ( d < FLT_MAX )
	{
		if ( fmod ( d , 1 ) == 0 )
			std::cout << std::setprecision( precision ) <<  "float: " << static_cast<float>( d ) << ".0f" << std::endl;	
		else
			std::cout << std::setprecision( precision ) <<  "float: " << static_cast<float>( d ) << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if ( fmod ( d , 1 ) == 0 )
		std::cout << std::setprecision( precision ) <<  "double: " << d << ".0" << std::endl;
	else
		std::cout << std::setprecision( precision ) <<  "double: " << d << std::endl;		
}

void		detect_type( std::string tmp )
{
	char const	*parser = tmp.c_str();
	if ( tmp.length() == 1 && !isdigit( tmp[0] ) && isprint( tmp[0]) )
		is_char ( static_cast<char>( tmp[0] ) );
	else
	{
		if ( strcmp( parser, "nan") == 0 || strcmp( parser, "nanf") == 0 )
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if ( parser )
		{
			if ( *parser == '-' || *parser == '+' )
			{
				char	sign = *parser;
				parser++;
				if ( strcmp( parser, "inff") == 0 || strcmp( parser, "inf") == 0 )
				{
					if ( sign == '-' )
					{
						std::cout << "char: impossible" << std::endl;
						std::cout << "int: impossible" << std::endl;
						std::cout << "float: -inff" << std::endl;
						std::cout << "double: -inf" << std::endl;
						return ;
					}	
					else
					{
						std::cout << "char: impossible" << std::endl;
						std::cout << "int: impossible" << std::endl;
						std::cout << "float: +inff" << std::endl;
						std::cout << "double: +inf" << std::endl;
						return ;
					}
				}
			}
			float	floating_point = false;
			float	f = false;
			while ( isdigit( *parser ))
			{
				parser++;
				if ( *parser == '.' )
				{
					floating_point = true ? floating_point = true : floating_point = false;
					parser++;
				}
				if ( *parser == 'f' )
				{

					f = true ? f = true : f = false;
					parser++;	
				}
			}
			if ( *parser )
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return ;
			}
			else
			{
				if ( ( !floating_point && !f ) && ( atol( tmp.c_str() ) <= INT_MAX && atol( tmp.c_str() ) >= INT_MIN ) )
					is_int ( static_cast<int>( atol( tmp.c_str() ) ), strlen( tmp.c_str() ) );
				else if ( ( floating_point && f ) && ( atof( tmp.c_str() ) <= FLT_MAX && atof( tmp.c_str() ) >= FLT_MIN ) )
					is_float ( static_cast<float>( atof( tmp.c_str() ) ), strlen( tmp.c_str() ) );
				else if ( ( floating_point && !f ) && ( atof( tmp.c_str() ) <= DBL_MAX && atol( tmp.c_str() ) >= -DBL_MAX ) )
					is_double ( static_cast<double>( atof( tmp.c_str() ) ), strlen( tmp.c_str()  ) );
				else
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible" << std::endl;
					return ;
				}		

			}
		}
	}
}

void	convert( char *s )
{
	std::string		tmp = s;
	detect_type( tmp );	
}

int		main( int ac, char **av )
{
	if ( ac == 2 )
		convert( av[1] );
	std::cout << std::endl;
	return (0);
}
