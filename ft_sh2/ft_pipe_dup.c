/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:51:23 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/10 17:55:04 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_dup_1(t_env *e, int pipe_fd[2])
{
	if (e->redirect >= 0)
	{
		ft_dup_redirect(e);
		new_args_copy(e, split_it(e->p_args[e->index_pipe]));
		e->pipe_args = e->new_args;
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	if (e->redirect < 0)
		e->pipe_args = split_it(e->p_args[e->index_pipe]);
	pipe_exec(e);
}

void	ft_dup_2(t_env *e, int pipe_fd[2])
{
	check_second_redirect(e);
	if (e->redirect >= 0)
	{
		ft_dup_redirect(e);
		new_args_copy(e, split_it(e->p_args[e->index_pipe]));
		e->pipe_args = e->new_args;
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	if (e->redirect < 0)
		e->pipe_args = split_it(e->p_args[e->index_pipe]);
	pipe_exec(e);
}

void	ft_dup_3(t_env *e, int pipe_fd[2])
{
	dup2(e->fd2, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	e->pipe_args = split_it(e->p_args[e->index_pipe]);
	pipe_exec(e);
}
