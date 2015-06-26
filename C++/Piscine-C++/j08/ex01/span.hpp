/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:36:11 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/26 15:56:55 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
class Span
{
	public:
		typedef std::vector<int> vec;
		Span( unsigned int n);
		Span & operator=( const Span & src);
		Span(Span & src);
		~Span(void);
		void addNumber(unsigned int i);
		int shortestSpan(void);
		int longestSpan(void);
	private:
		Span(void);
		vec _tab;
		unsigned int _len;
		int _count;
		unsigned int	_test;
};

#endif
