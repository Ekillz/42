/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:30:09 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 16:35:53 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x, int y, t_env *e)
{
	e->mouse_x = x;
	e->mouse_y = y;
	if (button == 4)
	{
		e->mouse += 1 + e->adapt_zoom;
		adapt_zoom_infini(e);
		e->mouse_x > 200 ? (e->move_x += 1 / e->mouse) :
			(e->move_x -= 1 / e->mouse);
		e->mouse_y > 200 ? (e->move_y += 1 / e->mouse) :
			(e->move_y -= 1 / e->mouse);
		check_fractol(e);
	}
	if (button == 5)
	{
		e->mouse /= 1.1;
		check_fractol(e);
	}
	return (0);
}

int expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	show_info(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	key(e, keycode);
	key_2(e, keycode);
	key_3(e, keycode);
	key_4(e, keycode);
	return (0);
}

int main(int ac, char **av)
{
	t_env e;

	e.av = av;
	if (ac == 2 && check_valid_argument(&e) == 1)
	{
		declarations_mlx(&e);
		mlx_expose_hook(e.win, expose_hook, &e);
		if (ft_strequ(av[1], "1") == 1)
			draw_fractol_mandelbrot(&e);
		else if (ft_strequ(av[1], "2") == 1)
			draw_fractol_julia(&e);
		else if (ft_strequ(av[1], "3") == 1)
			draw_fractol_julia(&e);
		else if (ft_strequ(av[1], "4") == 1)
			draw_fractol_julia(&e);
		else if (ft_strequ(av[1], "5") == 1)
			draw_fractol_burning_ship(&e);
		mlx_loop(e.mlx);
	}
	else
	{
		error_arguments();
		exit(0);
	}
	return (0);
}
