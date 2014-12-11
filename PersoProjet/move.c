/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 20:42:22 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 20:59:17 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void right_move(t_env *e)
{

	mlx_clear_window(e->mlx, e->win);
	recursive_edge_draw(e);
	e->add_move_x = e->add_move_x + 10;
	character_motion_lf(e);
}

void left_move(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	recursive_edge_draw(e);
	ve_edge_draw(e);s->add_move_x = e->add_move_x - 10;
	character_motion_lf(e);
}

void up_move(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	recursive_edge_draw(e);
	e->add_move_y = e->add_move_y + 10;
	character_motion_ud(e);
}

void down_move(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	recursive_edge_draw(e);
	e->add_move_y = e->add_move_y - 10;
	character_motion_ud(e);
}
