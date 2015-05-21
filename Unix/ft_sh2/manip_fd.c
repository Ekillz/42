/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 15:03:41 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 17:10:41 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	close_fd(t_env *e)
{
	if (e->redirect == 0 || e->redirect == 1)
	{
		dup2(e->fd2, 1);
		close(e->fd2);
	}
	else if (e->redirect == 2 || e->redirect == 3)
	{
		dup2(e->fd2, 0);
		close(e->fd2);
	}
}

int		check_redirect_args(t_env *e)
{
	if (ft_strequ(e->args[1], ">") || ft_strequ(e->args[1], ">>"))
		return (1);
	else if (ft_strequ(e->args[1], "<") || ft_strequ(e->args[1], "<<"))
		return (1);
	return (0);
}

void	pipe_args(t_env *e)
{
	int			i;
	int			s;
	static int	t = 0;

	s = 0;
	i = 0;
	while (e->args[i])
	{
		if (ft_strequ(e->args[i], "|"))
		{
			if (t > 0)
				free(e->p_args);
			e->pipe_on = 1;
			t++;
			e->p_args = malloc(sizeof(char **) * 10000);
			do_tern_point_vir(e);
			while (e->p_args[s])
			{
				e->p_args[s] = ft_strtrim(e->p_args[s]);
				s++;
			}
			break ;
		}
		i++;
	}
}

void	ft_dup_redirect(t_env *e)
{
	int pipe_fd;

	if (e->redirect == 0 || e->redirect == 2)
		e->fd = open(e->args[e->redirect_index + 1], O_RDWR | O_CREAT, 0644);
	else if (e->redirect == 1)
		e->fd = open(e->args[e->redirect_index + 1]
				, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (e->redirect == 3)
	{
		pipe_fd = redirect_double_left(e);
		e->fd2 = dup(0);
		dup2(pipe_fd, 0);
		close(pipe_fd);
	}
	if (e->redirect == 1 || e->redirect == 0)
	{
		e->fd2 = dup(1);
		dup2(e->fd, STDOUT_FILENO);
	}
	else if (e->redirect == 2)
	{
		e->fd2 = dup(0);
		dup2(e->fd, STDIN_FILENO);
	}
}
