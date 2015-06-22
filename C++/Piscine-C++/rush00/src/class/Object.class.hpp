/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:20:21 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:46 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_CLASS_HPP
#define OBJECT_CLASS_HPP

#include "IEntity.class.hpp"

class Object : public IEntity
{
	public:
		Object(void);
		Object(int x, int y, std::string type);
		Object(Object const & src);
		Object & operator=(Object const & src);
		virtual ~Object(void);

		void collideAction();
		
		Object & operator+=(int amount);
		Object & operator-=(int amount);

		int getChp() const;
		int getX() const;
		int getY() const;
		int getDmg() const;
		std::string getType() const;

		void setChp(int amount);
		void setX(int amount);
		void setY(int amount);
		void setDmg(int amount);
		void setType(std::string t);
	protected:
		int _chp;
		int _x;
		int _y;
		int _dmg;
		std::string _type;
};

#endif
