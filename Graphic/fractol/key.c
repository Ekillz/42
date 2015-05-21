/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:52:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 17:26:15 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key(t_env *e, int keycode)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 65362)
	{
		e->move_y /= 1.01;
		check_fractol(e);
	}
	if (keycode == 65451)
	{
		e->iteration_add += 10;
		check_fractol(e);
	}
	if (keycode == 65453)
	{
		e->iteration_add -= 10;
		check_fractol(e);
	}
}

void	key_2(t_env *e, int keycode)
{
	if (keycode == 65364)
	{
		e->move_y *= 1.01;
		check_fractol(e);
	}
	if (keycode == 123)
	{
		e->move_x /= 1.01;
		check_fractol(e);
	}
	if (keycode == 65363)
	{
		e->move_x *= 1.01;
		check_fractol(e);
	}
	if (keycode == 65450)
	{
		e->color_add += 10;
		check_fractol(e);
	}
}

void	redraw_fractol(t_env *e, int fractol)
{
	if (fractol == 1)
		draw_fractol_mandelbrot(e);
	else if (fractol == 2)
		draw_fractol_julia(e);
	else if (fractol == 3)
		draw_fractol_julia(e);
	else if (fractol == 4)
		draw_fractol_julia(e);
	else if (fractol == 5)
		draw_fractol_burning_ship(e);
}

void	key_3(t_env *e, int keycode)
{
	if (keycode == 49)
	{
		e->av[1] = "1";
		check_fractol(e);
	}
	if (keycode == 50)
	{
		e->av[1] = "2";
		check_fractol(e);
	}
	if (keycode == 51)
	{
		e->av[1] = "3";
		check_fractol(e);
	}
	if (keycode == 65455)
	{
		e->color_add -= 10;
		check_fractol(e);
	}
	if (keycode == 52)
	{
		e->av[1] = "4";
		check_fractol(e);
	}
}

int		mouse_move_hook(int x, int y, t_env *e)
{
	e->mouse_x = (double)x;
	e->mouse_y = (double)y;
	check_fractol(e);
	return (0);
}
