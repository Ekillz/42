/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:09:28 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 16:54:33 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	if (keycode == 46)
	{
		e->minimap++;
		raycaster(e);
	}
	if (keycode == 69 && e->speed > 2)
		e->speed -= 0.1;
	if (keycode == 78)
		e->speed += 0.1;
	if (keycode == 53)
		exit (0);
	if (keycode == 126)
		up(e);
	if (keycode == 125)
		down(e);
	lf_move(e, keycode);
	return (0);
}

void	declarations_mlx(t_env *e, int which)
{
	e->img_ptr = mlx_new_image(e->mlx, 512, 384);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->size_line, &e->endian);
	if (which == 0)
	{
		mlx_hook(e->win, 2, 1L << 0, &key_press_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
	}
}

int		main(void)
{
	t_env e;

	e.posx = 6;
	e.posy = 12;
	e.dirx = -0.99;
	e.diry = 0;
	e.planex = 0;
	e.planey = 0.66;
	e.w = 512;
	e.minimap = 1;
	e.h = 384;
	e.speed = 3;
	declare_and_check_mlx_error(&e);
	declarations_mlx(&e, 0);
	map(&e);
	raycaster(&e);
	mlx_loop(e.mlx);
	ft_freetab((char **)e.tmp_map);
	return (0);
}
