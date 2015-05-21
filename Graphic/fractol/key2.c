/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:01:52 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 17:23:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void key_4(t_env *e, int keycode)
{
	if (keycode == 65421)
	{
		e->mouse += 1 + e->adapt_zoom;
		adapt_zoom_infini(e);
		e->mouse_x > 200 ? (e->move_x += 1 / e->mouse) :
			(e->move_x -= 1 / e->mouse);
		e->mouse_y > 200 ? (e->move_y += 1 / e->mouse) :
			(e->move_y -= 1 / e->mouse);
		check_fractol(e);
	}
	if (keycode == 53)
	{
		e->av[1] = "5";
		check_fractol(e);
	}
}
