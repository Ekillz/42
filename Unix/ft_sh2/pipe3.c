/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:59:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:39:59 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_fork2(t_env *e, int i, int pipe_fd[2])
{
	if (e->p_args[2])
	{
		pipe_mid(e, pipe_fd);
		i++;
		exec_fork3(e, i, pipe_fd);
		e->index_pipe++;
	}
	else
	{
		e->index_pipe++;
		ft_dup(e, pipe_fd, 1);
	}
	exit(0);
}

void	exec_fork3(t_env *e, int i, int pipe_fd[2])
{
	while (e->p_args[i])
	{
		e->index_pipe++;
		e->child = fork();
		if (e->child == 0)
		{
			if (e->p_args[i + 1])
				ft_dup(e, pipe_fd, 2);
			else
				ft_dup(e, pipe_fd, 1);
			exit(0);
		}
		else
		{
			i++;
			if (!e->p_args[i + 1])
			{
				e->index_pipe++;
				ft_dup(e, pipe_fd, 1);
			}
			else
				pipe_mid(e, pipe_fd);
		}
		i += 2;
	}
}
