/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:28:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 14:38:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void select_color_and_draw(t_env *e)
{
	if (e->side == 1 && e->raydiry > 0)
		e->color = 0xFF0000;
	if (e->side == 1 && e->raydiry <= 0)
		e->color = 0xFF00FF;
	if (e->side == 0 && e->raydirx > 0)
		e->color = 0x00FF00;
	if (e->side == 0 && e->raydirx <= 0)
		e->color = 0x0000FF;
	if (e->worldmap[e->mapx][e->mapy] == 2 && e->side == 1)
		e->color = 0x202020;
	while (e->drawstart < e->drawend)
	{
		mlx_put_pixel_to_img(e, e->x, e->drawstart, e->color);
		e->drawstart += 1;
	}
}
