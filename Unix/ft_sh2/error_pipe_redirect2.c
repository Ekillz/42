/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe_redirect2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:54:03 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/11 15:10:42 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_exist2(t_env *e, int r, int t, char **args_exist)
{
	while (e->path[r])
	{
		e->path_access = ft_strjoin(e->path[r], "/");
		if (access(ft_strjoin(e->path_access, args_exist[0]), X_OK) == 0)
		{
			(void)args_exist;
			t++;
			r = 2000;
		}
		else if (access(args_exist[0], X_OK) == 0)
		{
			(void)args_exist;
			t++;
			r = 2000;
		}
		r++;
	}
	return (t);
}

int		main_errors2(t_env *e, int r)
{
	while (e->p_args[0][r])
	{
		if (e->p_args[0][r] == '>')
			return (1);
		r++;
	}
	return (0);
}
