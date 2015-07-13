/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 13:57:14 by chaueur           #+#    #+#             */
/*   Updated: 2015/07/13 15:46:23 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP

# define DATA_HPP

#include "header.hpp"

typedef enum
{
	ACTION_NONE,
	ACTION_MOVE_LEFT,
	ACTION_MOVE_RIGHT,
	ACTION_MOVE_UP,
	ACTION_MOVE_DOWN,
	ACTION_SHOOT,
} action_t;

void			data_init( void );
void			game_over( Player *p );

# define PLAYER		"/^\\"
# define ENEMY		"+"
# define OBSTACLE	"o"
# define ESHOT		"|"
# define FSHOT		"|"
# define MAX_ENEMY 	30
# define MAX_OBJECT 100
# define FRAMERATE  60

#endif
