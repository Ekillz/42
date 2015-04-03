/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 13:43:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/18 18:09:31 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractol_burning_ship(t_env *e)
{
	int		n;
	int		i;
	int		j;
	double	range;

	range = 2;
	n = 500;
	i = 0;
	declarations(e);
	while (i < n)
	{
		j = 0;
		burning_ship_algo(e, j, i, range);
		i++;
	}
	expose_hook(e);
}

void burning_ship_algo(t_env *e, int j, int i, double range)
{
	int n;
	int k;

	n = 500;
	while (j < n)
	{
		e->x = 0;
		e->y = 0;
		k = 0;
		e->c_re = 2 * (range) * (i / (double)n - 0.5) / e->mouse + e->move_x;
		e->c_im = 2 * (range) * (j / (double)n - 0.5) / e->mouse + e->move_y;
		while (k < e->max && e->x * e->x + e->y * e->y < 10)
		{
			e->x_new = e->x * e->x - e->y * e->y - e->c_re;
			e->y = 2 * fabs(e->x * e->y) - e->c_im;
			e->x = e->x_new;
			k++;
		}
		e->iteration = k;
		e->col = i;
		e->row = j;
		draw_mandelbrot(e);
		j++;
	}
}
