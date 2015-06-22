/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:43:21 by chaueur           #+#    #+#             */
/*   Updated: 2015/06/21 19:42:25 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP

# define HEADER_HPP

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#include "../src/class/IEntity.class.hpp"
#include "../src/class/Vessel.class.hpp"
#include "../src/class/Player.class.hpp"
#include "../src/class/Enemy.class.hpp"
#include "../src/class/Object.class.hpp"
#include "data.hpp"
#include "screen.hpp"
#include "actions.hpp"

namespace col
{
	int  checkCol(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void updatePos(Player *a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void createEnemy(Enemy b[MAX_ENEMY], int x, int y);
	void createObject(Object c[MAX_OBJECT], int x, int y, std::string type);
	void checkPos(Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
	void updateEshot( Object *eShot );
	void checkHit(Player * a, Enemy b[MAX_ENEMY], Object c[MAX_OBJECT]);
}

#endif
