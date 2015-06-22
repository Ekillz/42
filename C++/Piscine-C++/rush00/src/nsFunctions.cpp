/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsFunctions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 20:59:56 by emammadz          #+#    #+#             */
/*   Updated: 2015/06/21 20:56:02 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int col::checkCol(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;
	while (i < MAX_ENEMY)
	{
		if (((a->getX() + 1 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() + 2 == b[i].getX())  && (a->getY() == b[i].getY())) ||
				((a->getX() == b[i].getX())  && (a->getY() == b[i].getY())))
			return (1);
		i++;
	}
	i = 0;
	while (i < MAX_OBJECT)
	{
		if (((a->getX() + 1 == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX() + 2 == c[i].getX())  && (a->getY() == c[i].getY())) ||
				((a->getX()  == c[i].getX())  && (a->getY() == c[i].getY())))
			return (2);
		i++;
	}
	return (0);
}

/*void col::updateEshot( Object *eShot )
{
	mvprintw( eShot->getY(), eShot->getX(), ESHOT );
	move( eShot->getY(), eShot->getX() );
	eShot->setY( eShot->getY() + 1 );
}*/

void col::updatePos(Player *a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{

	// fShot = user shot, eShot = Enemy shot, obstacle = obstacle lool //
	int i = 0;
	while (i < MAX_ENEMY)
	{
		if ( b[i].getChp() > 0 )
		{
			b[i] += 1;
			b[i].genMov();
			mvprintw( b[i].getY(), b[i].getX(), ENEMY );
		}
		i++;
	}
	i = 0;
	while (i < MAX_OBJECT)
	{
		if ( c[i].getChp() > 0 )
		{
			if (c[i].getType() == "obstacle" || c[i].getType() == "eShot")
			{
				c[i] += 1;
				if ( c[i].getType() == "obstacle" )
					mvprintw( c[i].getY(), c[i].getX(), OBSTACLE );
				else
				{
					mvprintw( c[i].getY(), c[i].getX(), FSHOT );
					if (col::checkCol(a, b, c) == 2)
						a->setChp(0);
					mvprintw( c[i].getY(), c[i].getX(), " " );
					c[i] += 1;
					mvprintw( c[i].getY(), c[i].getX(), FSHOT );
				}
			}
			else if (c[i].getType() == "fShot")
			{
				c[i] -= 1;
				mvprintw( c[i].getY(), c[i].getX(), FSHOT );
			}
		}
		i++;
	}
}

void col::createEnemy(Enemy b[MAX_ENEMY], int x, int y)
{
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if (b[i].getChp() <= 0)
		{
			b[i].setChp(1);
			b[i].setX(x);
			b[i].setY(y);
			break;
		}
		i++;
	}
}

void col::checkPos(Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if (b[i].getY() > MAX_H)
			b[i].setChp(0);
		i++;
	}
	i = 0;

	while (i < MAX_OBJECT)
	{
		if (c[i].getY() > MAX_H || c[i].getY() < 0) // < 0 pour le tir player qui monte //
			c[i].setChp(0);
		i++;
	}
}

void col::createObject(Object c[MAX_OBJECT], int x, int y, std::string type)
{
	int i = 0;

	while (i < MAX_OBJECT )
	{
		if (c[i].getChp() <= 0)
		{
			c[i].setChp(1);
			c[i].setX(x);
			c[i].setY(y);
			c[i].setType(type);
			break;
		}
		i++;
	}
}

void col::checkHit(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT])
{
	int i = 0;
	int e;
	while (i < MAX_OBJECT)
	{
		if (c[i].getChp() > 0)
		{
			if (c[i].getType() == "fShot")
			{
				e = 0;
				while (e < MAX_ENEMY)
				{
					if ((c[i].getX() == b[e].getX()) &&(c[i].getY() == b[e].getY()))
					{
						b[e].setChp(b[e].getChp() - 1);
						a->setScore(a->getScore() + 10);
						c[i].setChp(0);
						break;
					}
					e++;
				}
				e = 0;
				while (e < MAX_OBJECT)
				{
					if (c[e].getType() != "fShot")
					{
						if ((c[i].getX() == c[e].getX()) && (c[i].getY() == c[e].getY()))
						{
							c[e].setChp(c[e].getChp() - 1);
							a->setScore(a->getScore() + 5);
							c[i].setChp(0);
							break ;
						}
					}
					e++;
				}
			}
		}
		i++;
	}
}

