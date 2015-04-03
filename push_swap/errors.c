/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:54:24 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/26 17:21:57 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_errors(t_env *e)
{
	int i;

	i = 1;
	while (e->av[i])
	{
		if (ft_atoi_long(e->av[i]) > 2147483647 ||
				ft_atoi_long(e->av[i]) <= -2147483648)
			return (-1);
		i++;
	}
	if (check_errors_2(e) == -1)
		return (-1);
	else if (check_errors_3(e) == -1)
		return (-1);
	return (0);
}

int		check_errors_2(t_env *e)
{
	int i;
	int s;

	i = 2;
	s = i;
	while (e->av[s])
	{
		while (i - 1)
		{
			if (ft_atoi(e->av[s]) == ft_atoi(e->av[i - 1]))
				return (-1);
			i--;
		}
		s++;
		i = s;
	}
	return (0);
}

int		check_errors_3(t_env *e)
{
	int s;
	int i;
	int which;

	which = 0;
	i = 0;
	s = 1;
	while (e->av[s])
	{
		if (check_errors_3_part_2(e, i, s, which) == -1)
			return (-1);
		which = 0;
		i = 0;
		s++;
	}
	return (0);
}

int		check_errors_3_part_2(t_env *e, int i, int s, int which)
{
	while (e->av[s][i])
	{
		if (e->av[s][0] == '0' && e->av[s][1] == '0')
			return (-1);
		if (e->av[s][i] == '-' && e->av[s][i + 1] == '0')
			return (-1);
		if (e->av[s][i] == '-' && which == 0)
		{
			i++;
			which = 1;
		}
		if (ft_isdigit(e->av[s][i]))
			i++;
		else
			return (-1);
	}
	return (0);
}

void	error_message(void)
{
	ft_putstr_fd("Error, check your arguments: ", 2);
	ft_putstr_fd("Max int value? Same number? not a number?\n", 2);
}
