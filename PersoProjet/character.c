/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 19:02:27 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 20:44:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void character_motion_lf(t_env *e)
{
	e->x = 400 + e->add_move_x;
	e->max = 450 + e->add_move_x;
	e->y = 400 - e->add_move_y;
	while (e->x++ < e->max)
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0xFFFFFF);
}

void character_motion_ud(t_env *e)
{
	e->x = 400 + e->add_move_x;
	e->max = 450 + e->add_move_x;
	e->y = 400 - e->add_move_y;
	while (e->x++ < e->max)
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0xFFFFFF);
}
