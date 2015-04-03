/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_vir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:19:21 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/09 19:12:50 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		point_vir(t_env *e)
{
	int i;

	i = 0;
	while (e->line[i])
	{
		if (e->line[i] == ';')
		{
			e->point_vir = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		count_point_args(t_env *e)
{
	int i;

	i = 0;
	while (e->point_args[i])
		i++;
	return (i);
}
