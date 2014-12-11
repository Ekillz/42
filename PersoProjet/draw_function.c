/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 19:04:44 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 19:38:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void draw_map(t_env *e)
{
	while (e->x++ < e->max)
	{
		e->y = 0 + e->add;
		while (e->y++ < e->may)
			mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0x00FF33);
	}
}
