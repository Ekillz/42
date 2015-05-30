/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 14:48:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 15:43:27 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lf_move(t_env *e, int keycode)
{
	int rot;

	rot = 69;
	if (keycode == 123)
	{
		ft_bzero(e->img, e->bpp * 512 + 384 * e->size_line);
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(-rot) - e->diry * sin(-rot);
		e->diry = e->olddirx * sin(-rot) + e->diry * cos(-rot);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(-rot) - e->planey * sin(-rot);
		e->planey = e->oldplanex * sin(-rot) + e->planey * cos(-rot);
		raycaster(e);
	}
	if (keycode == 124)
	{
		ft_bzero(e->img, e->bpp * 512 + 384 * e->size_line);
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(rot) - e->diry * sin(rot);
		e->diry = e->olddirx * sin(rot) + e->diry * cos(rot);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(rot) - e->planey * sin(rot);
		e->planey = e->oldplanex * sin(rot) + e->planey * cos(rot);
		raycaster(e);
	}
}

int		up(t_env *e)
{
	ft_bzero(e->img, e->bpp * 512 + 384 * e->size_line);
	if (e->worldmap[(int)(e->posx + e->dirx)][(int)(e->posy)] == 0
			&& e->worldmap[(int)(e->posx)][(int)(e->posy + e->diry)] == 2
			&& (int)e->posx == 5 && (int)e->posy == 12)
	{
		e->posx = 12;
		e->posy = 12;
		e->dirx = -0.99;
		e->diry = 0;
		e->planex = 0;
		e->planey = 0.66;
		raycaster(e);
		return (0);
	}
	if (e->worldmap[(int)(e->posx + e->dirx)][(int)(e->posy)] == 0)
		e->posx += e->dirx / e->speed;
	if (e->worldmap[(int)(e->posx)][(int)(e->posy + e->diry)] == 0)
		e->posy += e->diry / e->speed;
	if (e->worldmap[(int)(e->posx + e->dirx)][(int)(e->posy)] == 0
			|| e->worldmap[(int)(e->posx)][(int)(e->posy + e->diry)] == 0)
	{
		raycaster(e);
	}
	return (0);
}

void	down(t_env *e)
{
	ft_bzero(e->img, e->bpp * 512 + 384 * e->size_line);
	if (e->worldmap[(int)(e->posx - e->dirx)][(int)(e->posy)] == 0)
		e->posx -= e->dirx / e->speed;
	if (e->worldmap[(int)(e->posx)][(int)(e->posy - e->diry)] == 0)
		e->posy -= e->diry / e->speed;
	if (e->worldmap[(int)(e->posx)][(int)(e->posy - e->diry)] == 0 ||
			e->worldmap[(int)(e->posx - e->dirx)][(int)(e->posy)] == 0)
	{
		raycaster(e);
	}
}
