/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:53:38 by chaueur           #+#    #+#             */
/*   Updated: 2015/06/21 20:40:06 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void		game_over( Player *p )
{
	int		c = 0;

	erase();
	clear();
	mvprintw( MAX_H / 2, MAX_W / 2, "/////	Game Over :( Score: %5d	/////", p->getScore() );
	mvprintw( MAX_H / 2 + 1, MAX_W / 2, "/////	Replay: r	Quit: q		/////", p->getScore() );
	refresh();
	while ( c != 'r' && c != 'q' )
	{
		c = getch();
		if ( c == 'r' || c == 'q' )
		{
			delete p;
			if (c == 'r')
				data_init();
			else
		    	exit(0);
		}	
	}
}

void			data_init()
{
	Player		*p = new Player;
	Enemy		*horde = new Enemy[MAX_ENEMY];
	Object		*objs = new Object[MAX_OBJECT];
	
	scr_init();
	scr_upd( p, horde, objs );
	main_loop( p, horde, objs );
}
