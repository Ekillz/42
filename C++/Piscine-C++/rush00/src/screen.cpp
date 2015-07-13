/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:42:36 by chaueur           #+#    #+#             */
/*   Updated: 2015/07/13 15:55:43 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void		print_score( int score, int life )
{
	/* HUD. */
	mvprintw(0, 0, "/////	Score: %5d	/////", score);
	mvprintw(1, 0, "/////	Life : %5d	/////", life);
}

void		scr_end( void )
{
	endwin();
}

void		scr_upd( Player *p, Enemy *horde, Object *objs )
{
	int colision;
	/* clear window */
	erase();	

	/* Position cursor on player. */
	mvprintw( p->getY(), p->getX(), PLAYER );
	//move( p->getY(), p->getX() );


	/* Check enemies and projectiles */
	col::checkPos( horde, objs );

	/* Check projecitles collision */
	col::checkHit( p, horde, objs );


	colision = col::checkCol( p, horde, objs );
	if (colision == 1 || colision == 2)
		p->setChp(p->getChp() - 1);
	if (p->getChp() <= 0)
	{
		game_over( p );
	}

	col::updatePos(p,  horde, objs );
	/* Update enemies and projectiles */
	

	print_score( p->getScore(), p->getChp() );
	refresh();
}

void		scr_init( void )
{
	int			max_y, max_x;

	initscr();
	curs_set(0); /* Hide cursor */
	start_color();
    use_default_colors();
	getmaxyx(stdscr, max_y, max_x);
	if ( max_x < MAX_W || max_y < MAX_H + 1 )
	{
		endwin();
		printf( "Screen must be at least %dpx / %dpx\n", MAX_W * 8, MAX_H * 16 );
		exit(0);
	}
	atexit( scr_end );
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
}
