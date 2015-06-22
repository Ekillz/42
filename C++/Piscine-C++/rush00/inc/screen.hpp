/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:46:35 by chaueur           #+#    #+#             */
/*   Updated: 2015/06/21 21:12:07 by chaueur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP

# define SCREEN_HPP

# define MAX_W		76
# define MAX_H		78

#include "data.hpp"

void		print_score( int score );
void		scr_end( void );
void		scr_upd( Player *p, Enemy *horde, Object *objs );
void		scr_init( void );

#endif /* SCREEN_HPP */
