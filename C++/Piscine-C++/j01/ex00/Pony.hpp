/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 12:53:51 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/16 14:10:04 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
#define PONY_H

#include <iostream>
class Pony 
{
	public:
		float height;
		float width;
		float weight;
		float speed;
		int	  age;

		void jump(int height);
		Pony(float h, float w, float wd, float s, int a);
		~Pony(void);
};

#endif
