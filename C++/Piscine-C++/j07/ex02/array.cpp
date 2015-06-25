/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 13:31:15 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/25 18:15:45 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _len;
	public:
		Array(void)
		{
			this->_array = new T[0];
			return;
		}

		Array(unsigned int n)
		{
			this->_array = new T[n];
			this->_len = n;
			return;
		}

		Array & operator=(Array & src)
		{
			delete [] this->_array;
			this->_len = src._len;
			this->_array = src._array;
			return (*this);
		}

		Array(Array & src)
		{
			*this = src;
			return ;
		}

		~Array(void)
		{
			delete [] this->_array;
			return ;
		}

		T size(void)
		{
			return this->_len;
		}

		T & operator[](unsigned int n)
		{
			if (n > this->_len)
				throw std::runtime_error("Trying to acces non allocated memory");
			return this->_array[n];
		}
};
