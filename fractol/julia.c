/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:56:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 17:06:39 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractol_julia(t_env *e)
{
	declarations(e);
	while (e->row < e->height)
	{
		while (e->col < e->width)
		{
			e->c_re = (e->col - e->width / 2.0) * 4 / (e->mouse * e->width);
			e->c_im = (e->row - e->height / 2.0) * 4 / (e->mouse * e->width);
			e->c_re += e->move_x - 1;
			e->c_im += e->move_y - 1;
			e->iteration = 0;
			algo_julia(e);
			draw_mandelbrot(e);
			e->col++;
		}
		e->col = 0;
		e->row++;
	}
	expose_hook(e);
}

void algo_julia(t_env *e)
{
	while (e->c_re * e->c_re + e->c_im * e->c_im <= 4 && e->iteration < e->max)
	{
		e->c_re_new = e->c_re * e->c_re - e->c_im * e->c_im + e->c_re_julia;
		e->c_im = 2 * e->c_re * e->c_im + e->c_im_julia;
		e->c_re = e->c_re_new;
		e->iteration++;
	}
}
