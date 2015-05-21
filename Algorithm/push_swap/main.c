/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:19:42 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/23 15:11:35 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	main_conditions(t_env *e)
{
	if (e->ac == 2 && check_errors(e) != -1)
	{
		ft_putendl(e->av[1]);
		exit(0);
	}
	if (check_errors(e) == -1)
	{
		error_message();
		exit(0);
	}
	else
	{
		copy_tab(e);
		algo_swap(e);
	}
}

int		main(int ac, char **av)
{
	t_env e;

	e.which = 0;
	e.ac2 = 0;
	e.i = 0;
	e.ac = ac;
	e.av = av;
	if (ac > 1)
		main_conditions(&e);
	else
		ft_putendl_fd("ERROR: No arguments", 2);
	return (0);
}
