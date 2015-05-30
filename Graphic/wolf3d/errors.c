/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:48:42 by emammadz          #+#    #+#             */
/*   Updated: 2015/05/30 14:21:37 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void declare_and_check_mlx_error(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putstr_fd("mlx init error\n", 2);
		exit(0);
	}
	else if (!(e->win = mlx_new_window(e->mlx, 512, 384, "Ekillz")))
	{
		ft_putstr_fd("mlx win error\n", 2);
		exit(0);
	}
}
