/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_fd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:20:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:40:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_tern_point_vir(t_env *e)
{
	e->point_vir == 1 ? (e->point_args[e->d] =
			ft_strtrim(e->point_args[e->d])) : (e->line = ft_strtrim(e->line));
	e->point_vir == 1 ? (e->p_args =
			ft_strsplit(e->point_args[e->d], '|')) :
		(e->p_args = ft_strsplit(e->line, '|'));
}
