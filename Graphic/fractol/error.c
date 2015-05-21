/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:44:23 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/26 17:22:59 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_valid_argument(t_env *e)
{
	if (ft_strequ(e->av[1], "1") == 1)
		return (1);
	else if (ft_strequ(e->av[1], "2") == 1)
		return (1);
	else if (ft_strequ(e->av[1], "3") == 1)
		return (1);
	else if (ft_strequ(e->av[1], "4") == 1)
		return (1);
	else if (ft_strequ(e->av[1], "5") == 1)
		return (1);
	return (0);
}

void	error_arguments(void)
{
	ft_putstr("No argument or invalid argument!\nThe Valid Arguments are:");
	ft_putstr("\n1 for ->Mandelbrot\n2 for ->Julia\n3 for ->Douady Rabbit \n");
	ft_putstr("4 for ->Peanut Chromosome\n");
	ft_putstr("5 for ->Burning Ship\n");
}

void	check_fractol(t_env *e)
{
	if (ft_strequ(e->av[1], "1") == 1)
		redraw_fractol(e, 1);
	else if (ft_strequ(e->av[1], "2") == 1)
		redraw_fractol(e, 2);
	else if (ft_strequ(e->av[1], "3") == 1)
		redraw_fractol(e, 3);
	else if (ft_strequ(e->av[1], "4") == 1)
		redraw_fractol(e, 4);
	else if (ft_strequ(e->av[1], "5") == 1)
		redraw_fractol(e, 5);
}

void	declare_and_check_mlx_error(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putstr("mlx init error\n");
		exit(0);
	}
	else if (!(e->win = mlx_new_window(e->mlx, 500, 500, "Ekillz")))
	{
		ft_putstr("mlx win error\n");
		exit(0);
	}
}
