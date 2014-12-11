/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_edge_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:43:08 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 19:38:52 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void recursive_edge_draw(t_env *e)
{
	e->c = 4;
	while (e->c)
	{
		if (e->c == 4)
		{
			e->x = 0;
			e->y = 0;
			e->max = 800;
			e->may = 50;
			e->add = 0;
		}
		else if (e->c == 3)
		{
			e->x = 0;
			e->y = 750;
			e->may = 800;
			e->add = 750;
		}
		else if (e->c == 2)
		{
			e->x = 0;
			e->max = 50;
			e->may = 800;
			e->y = 0;
			e->add = 0;
		}
		else if (e->c == 1)
		{
			e->x = 750;
			e->max = 800;
			e->y = 0;
			e->may = 800;
			e->add = 0;
		}
		draw_map(e);
		e->c--;
	}
}
