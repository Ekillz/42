/* **a************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:49:29 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 18:04:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractol_mandelbrot(t_env *e)
{
	declarations(e);
	while (e->row < e->height)
	{
		while (e->col < e->width)
		{
			e->c_re = (e->col - e->width / 2.0) * 4.0 / (e->mouse * e->width);
			e->c_im = (e->row - e->height / 2.0) * 4.0 / (e->mouse * e->width);
			e->c_re += e->move_x - 1;
			e->c_im += e->move_y - 1;
			e->x = 0;
			e->y = 0;
			e->iteration = 0;
			algo_mandelbrot(e);
			draw_mandelbrot(e);
			e->col++;
		}
		e->col = 0;
		e->row++;
	}
	expose_hook(e);
}

void mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->img[(x * 4) + (y * e->size_line)], &color, (sizeof(size_t)));
}

void draw_mandelbrot(t_env *e)
{
	if (e->iteration == 1)
		e->color = 0xB8860B;
	if (e->iteration == 2)
		e->color = 0xDAA520;
	if (e->iteration == 3)
		e->color = 0xFFA500;
	if (e->iteration == 4)
		e->color = 0xFF8C00;
	if (e->iteration == 5)
		e->color = 0xFF8C00;
	if (e->iteration > 10 && e->iteration < 30)
		e->color = 0xFF0000;
	else if (e->iteration < 10 && e->iteration > 5)
		e->color = 0xFFFF00;
	else if (e->iteration > 30 && e->iteration < 40)
		e->color = 0x0000FF;
	else if (e->iteration > 40)
		e->color = 0x008000;
	if (e->iteration < e->max)
		mlx_put_pixel_to_img(e, e->col, e->row, e->color + e->color_add);
	else
		mlx_put_pixel_to_img(e, e->col, e->row, 0x000000);
}

void algo_mandelbrot(t_env *e)
{
	while (e->x * e->x + e->y * e->y <= 4 && e->iteration < e->max)
	{
		e->x_new = e->x * e->x - e->y * e->y + e->c_re;
		e->y = 2 * e->x * e->y + e->c_im;
		e->x = e->x_new;
		e->iteration++;
	}
}
