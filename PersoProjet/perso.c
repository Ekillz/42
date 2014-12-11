/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:19:40 by emammadz          #+#    #+#             */
/*   Updated: 2014/12/11 20:45:14 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void draw(t_env *e)
{
	recursive_edge_draw(e);
	e->add = 0;
	e->add_move_x = 0;
	e->add_move_y = 0;
	character_motion_lf(e);
	object(e);
}
int mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse %d (%d:%d)\n" , button, x, y);
	return (0);
}

int expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	e->keycode = keycode;
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit (0);
	if (keycode == 65363)
		right_move(e);
	if (keycode == 65361)
		left_move(e);
	if (keycode == 65362)
		up_move(e);
	if (keycode == 65364)
		down_move(e);
	return (0);
}

int main(void)
{
	t_env e;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 800, "game.exe");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
