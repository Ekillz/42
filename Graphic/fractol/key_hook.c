/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 13:54:47 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 15:08:58 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_hook(int keycode, t_env *e)
{
	(void)e;
	(void)keycode;
	return (0);
}

void	adapt_zoom_infini(t_env *e)
{
	if (e->mouse > 1500)
		e->adapt_zoom += 50;
	else if (e->mouse > 1000)
		e->adapt_zoom += 25;
	else if (e->mouse > 250)
		e->adapt_zoom += 5;
	else if (e->mouse > 50)
		e->adapt_zoom += 3;
	else if (e->mouse > 13)
		e->adapt_zoom += 2;
}
