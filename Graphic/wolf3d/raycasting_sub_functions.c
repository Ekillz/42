/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sub_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 18:17:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 14:40:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void calculate_mouvement(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

void first_declarations(t_env *e)
{
	e->camerax = 2 * e->x / (double)e->w - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camerax;
	e->raydiry = e->diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry)
			/ (e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx)
			/ (e->raydiry * e->raydiry));
	e->hit = 0;
}

void dda_algorithm(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
}

void draw_wall_1(t_env *e)
{
	if (e->side == 0)
		e->perpwalldist = fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2)
				/ e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2)
				/ e->raydiry);
	e->lineheight = abs((int)(e->h / e->perpwalldist));
	e->drawstart = -e->lineheight / 2 + e->h / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->xx = e->drawstart;
	while (e->drawstart)
	{
		e->color = 0xCCFFFF;
		mlx_put_pixel_to_img(e, e->x, e->drawstart, e->color);
		e->drawstart--;
	}
}

void draw_wall_2(t_env *e)
{
	e->drawstart = e->xx;
	e->drawend = e->lineheight / 2 + e->h / 2;
	if (e->drawend >= e->h)
		e->drawend = e->h - 1;
	e->xx = e->drawend;
	while (e->drawend < e->h - 1)
	{
		e->color = 0x994C00;
		mlx_put_pixel_to_img(e, e->x, e->drawend, e->color);
		e->drawend++;
	}
	e->drawend = e->xx;
}
