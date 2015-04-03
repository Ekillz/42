/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:50:18 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/10 19:14:38 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		loop_double_left(t_env *e, int ret)
{
	while (ft_strequ(e->line_redirect, e->args[e->redirect_index + 1]) == 0)
	{
		e->line_buf = ft_strjoin(e->line_redirect, e->line_buf);
		e->line_buf = ft_strjoin("\n", e->line_buf);
		ft_putstr("?");
		ret = read(0, e->line_redirect, 10000);
		e->line_redirect[ret - 1] = '\0';
	}
}

static void		free_double_left(t_env *e)
{
	free(e->line_redirect);
	free(e->line_buf);
}

int				redirect_double_left(t_env *e)
{
	int			ret;
	int			pipe_fd[2];
	static int	t = 0;

	if (t > 0)
		free_double_left(e);
	t++;
	pipe(pipe_fd);
	if (e->redirect_left_enter == 0)
	{
		e->redirect_left_enter = 1;
		e->line_redirect = malloc(sizeof(char *) * 10000);
		e->line_buf = malloc(sizeof(char *) * 10000);
		ft_putstr("?");
		ret = read(0, e->line_redirect, 10000);
		e->line_redirect[ret - 1] = '\0';
		loop_double_left(e, ret);
		if (ft_strequ(e->line_redirect, e->args[e->redirect_index + 1]))
			ft_putstr_fd(e->line_buf, pipe_fd[1]);
		close(pipe_fd[1]);
		return (pipe_fd[0]);
	}
	return (-1);
}
