/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:06:18 by chaueur           #+#    #+#             */
/*   Updated: 2015/06/21 20:40:03 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(void)
{
	srand( time(NULL) );
	data_init();
	

	// ch = getch();				/* Wait for user input */
	// if ( ch == KEY_F(1) )		/* Without keypad enabled this will */
	// 	printw("F1 Key pressed");
	// else
	// {
	// 	printw("The pressed key is ");
	// 	attron(A_BOLD);
	// 	printw("%c", ch);
	// 	attroff(A_BOLD);
	// }
	// refresh();
	// getch();
	// endwin();					/* End curses mode		  */
	return 0;
}
