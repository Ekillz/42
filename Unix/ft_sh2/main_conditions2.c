/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_conditions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:20:06 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:40:18 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void main_conditions2(t_env *e)
{
	e->fork_on = 1;
	redirect(e);
	if (e->pipe_on == 1)
	{
		ft_pipe(e, 0);
		close_fd(e);
	}
	else
		ft_fork(e, 0);
}

void ft_fork_2_normal(t_env *e, int i)
{
	while (e->path[i])
	{
		if (check_redirect(e) && e->pipe_on == 0)
		{
			e->path_access = ft_strjoin(e->path[i], "/");
			e->execve_path = ft_strjoin(e->path_access, e->args[0]);
			if (access(ft_strjoin(e->path_access, e->args[0]), X_OK) == 0)
				execve(e->execve_path, e->new_args, e->environ);
			if (access(e->new_args[0], X_OK) == 0)
				execve(e->args[0], e->new_args, e->environ);
		}
		else
		{
			e->path_access = ft_strjoin(e->path[i], "/");
			e->execve_path = ft_strjoin(e->path_access, e->args[0]);
			if (access(ft_strjoin(e->path_access, e->args[0]), X_OK) == 0)
				execve(e->execve_path, e->args, e->environ);
			if (access(e->args[0], X_OK) == 0)
				execve(e->args[0], e->args, e->environ);
		}
		i++;
	}
}
