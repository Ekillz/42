/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:13:16 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 14:28:41 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void raycaster(t_env *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		first_declarations(e);
		calculate_mouvement(e);
		dda_algorithm(e);
		draw_wall_1(e);
		draw_wall_2(e);
		select_color_and_draw(e);
		e->x++;
	}
	if (e->minimap % 2 == 0)
	{
		mini_map(e);
		draw_map(e, (int)e->posx, (int)e->posy, 1);
		draw_fov(e, 0);
		draw_fov(e, 1);
	}
	expose_hook(e);
}
