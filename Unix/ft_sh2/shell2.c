/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:19:33 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 16:45:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	shell_2(t_env *e)
{
	e->d = 0;
	e->c = 1;
	e->point_vir = 0;
	if (point_vir(e) == 1)
	{
		e->point_args = ft_strsplit(e->line, ';');
		e->c = count_point_args(e);
	}
	while (e->c)
	{
		commands(e);
		e->c--;
		e->d++;
	}
}

void	free_pwd_path(t_env *e, int t)
{
	if (t > 0)
	{
		free(e->buf_path);
		free(e->old_pwd);
	}
}

void	commands_declarations(t_env *e)
{
	e->i = 0;
	e->enter = 0;
	while (e->args[e->i])
		e->i++;
	e->redirect = -1;
	e->index_pipe = 0;
	e->redirect_index = 9999;
	e->redirect_index_2 = 9999;
	e->redirect_left_enter = 0;
	e->sh_erreur = 0;
	e->pipe_on = 0;
	pipe_args(e);
}

int		pipe_error_check(t_env *e)
{
	if (main_errors(e) == 1)
	{
		ft_putstr_fd("Ambiguous redirect.\n", 2);
		return (1);
	}
	else if (e->sh_erreur == 1)
	{
		sh_erreur(e);
		return (1);
	}
	return (0);
}
