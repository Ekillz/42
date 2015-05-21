/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:13:25 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 15:56:36 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void declarations(t_env *e)
{
	if (ft_strequ(e->av[1], "2") == 1)
	{
		e->c_re_julia = -0.7 + (e->mouse_x / 1000);
		e->c_im_julia = 0.27015 + (e->mouse_y / 1000);
	}
	else if (ft_strequ(e->av[1], "3") == 1)
	{
		e->c_re_julia = -0.122565;
		e->c_im_julia = -0.744864;
	}
	else if (ft_strequ(e->av[1], "4") == 1)
	{
		e->c_re_julia = 0.7;
		e->c_im_julia = 1.7;
	}
	e->row = 0;
	e->col = 0;
	e->width = 500;
	e->height = 500;
	e->max = 50 + e->iteration_add;
}

void declarations_mlx(t_env *e)
{
	e->mouse = 1;
	e->iteration_add = 0;
	e->adapt_zoom = 0;
	e->move_x = 1;
	e->move_y = 1;
	e->mouse_x = 1;
	e->mouse_y = 1;
	e->color_add = 0;
	declare_and_check_mlx_error(e);
	e->img_ptr = mlx_new_image(e->mlx, 500, 500);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_line, &e->endian);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 1 << 6, &mouse_move_hook, e);
	mlx_hook(e->win, 2, 1L << 0, &key_press_hook, e);
	mlx_hook(e->win, 3, 1L << 1, &key_hook, e);
}

void show_info(t_env *e)
{
	char *iterations;

	iterations = ft_strjoin("Iterations : ", ft_itoa(e->max));
	mlx_string_put(e->mlx, e->win, 20, 20, 0x000000, iterations);
	if (ft_strequ(e->av[1], "1") == 1)
		mlx_string_put(e->mlx, e->win, 225, 20, 0x000000, "Mandelbrot");
	if (ft_strequ(e->av[1], "2") == 1)
		mlx_string_put(e->mlx, e->win, 225, 20, 0x000000, "Julia");
	if (ft_strequ(e->av[1], "3") == 1)
		mlx_string_put(e->mlx, e->win, 225, 20, 0x000000, "Douady Rabbit");
	if (ft_strequ(e->av[1], "4") == 1)
		mlx_string_put(e->mlx, e->win, 225, 20, 0x000000, "Peanut Chromosome");
	if (ft_strequ(e->av[1], "5") == 1)
		mlx_string_put(e->mlx, e->win, 225, 20, 0x000000, "Burning Ship");
}
