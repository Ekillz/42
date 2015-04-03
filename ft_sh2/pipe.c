/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:01:13 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/11 15:02:21 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		pipe_exec(t_env *e)
{
	int i;

	i = 0;
	while (e->path[i])
	{
		e->path_access = ft_strjoin(e->path[i], "/");
		e->execve_path = ft_strjoin(e->path_access, e->pipe_args[0]);
		if (access(ft_strjoin(e->path_access, e->pipe_args[0]), X_OK) == 0)
			execve(e->execve_path, e->pipe_args, e->environ);
		if (access(e->pipe_args[0], X_OK) == 0)
			execve(e->pipe_args[0], e->pipe_args, e->environ);
		i++;
	}
	exit(0);
}

void		ft_dup(t_env *e, int pipe_fd[2], int which)
{
	if (which == 0)
		ft_dup_1(e, pipe_fd);
	else if (which == 1)
		ft_dup_2(e, pipe_fd);
	else if (which == 2)
		ft_dup_3(e, pipe_fd);
}

void		exec_fork(t_env *e, int i)
{
	pid_t	father;
	int		pipe_fd[2];

	pipe(pipe_fd);
	father = fork();
	if (father == 0)
	{
		if (e->p_args[i + 1])
			ft_dup(e, pipe_fd, 0);
		exit(0);
	}
	else
		exec_fork2(e, i, pipe_fd);
}

void		ft_pipe(t_env *e, int i)
{
	pid_t	father;

	father = fork();
	if (father == 0)
	{
		exec_fork(e, i);
		exit(0);
	}
	else
		wait(NULL);
	return ;
}
