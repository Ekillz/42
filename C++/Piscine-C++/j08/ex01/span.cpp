/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:40:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/26 15:57:08 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int n) : _test(n)
{
	/*this->_tab.resize(n);
	this->_count = 0;
	this->_len = n;*/
	return ;
}

Span & Span::operator=(const Span & src)
{
	this->_tab = src._tab;
	this->_len = src._len;
	this->_count = src._count;
	return (*this);
}
Span::Span(Span & src)
{
	*this = src;
}

Span::~Span(void)
{
	return;
}

void Span::addNumber(unsigned int i)
{
	if (this->_count + i > this->_len)
		throw std::string("Cannot add anymore values");
	else
	{
		this->_tab.push_back(i);
		this->_len += 1;
	}
}

int Span::shortestSpan(void)
{
	if (this->_count <= 1)
		throw std::string("Not enough values");
	std::sort(this->_tab.begin(), this->_tab.end());
	return (this->_tab[1] - this->_tab[0]);
}

int Span::longestSpan(void)
{
	std::vector<int>::iterator it = this->_tab.end();
	if (this->_count <= 1)
		throw std::string("Not enough values");
	std::sort(this->_tab.begin(), this->_tab.end());
	return (*it - this->_tab[0]);
}
