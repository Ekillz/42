/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/12 15:20:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_unsetenv(t_env *e)
{
	if (e->args[1] && env_name_search(e->args[1], e)
			== 1 && e->args[3] && (ft_strequ(e->args[2], ">") ||
				ft_strequ(e->args[2], ">>")))
	{
		malloc_env(e->args[1], "bloblo", e, 0);
		redirect(e);
		get_env(e);
		close_fd(e);
	}
	else if (e->args[1] && env_name_search(e->args[1], e) == 1 &&
			check_redirect(e) == 0)
		malloc_env(e->args[1], "bloblo", e, 0);
	else
	{
		ft_putstr_erreur("unsetenv: Bad usage or non existant variable: ");
		ft_putstr_erreur("Usage: unsetenv [NAME].");
		write(2, "\n", 1);
	}
}

int		ft_fork(t_env *e, int i)
{
	e->enter = 1;
	if ((e->father = fork()) == -1)
	{
		ft_putstr("FORK ERROR");
		return (-1);
	}
	if (e->father > 0)
	{
		e->enter = 1;
		wait(NULL);
	}
	if (e->father == 0)
		ft_fork_2_normal(e, i);
	if (e->redirect >= 0 && e->redirect < 4)
		close_fd(e);
	return (0);
}

void	sh_erreur(t_env *e)
{
	ft_putstr_erreur("ft_sh2: command not found: ");
	ft_putstr_erreur(e->line);
	write(2, "\n", 1);
}

void	main_conditions(t_env *e)
{
	if (check_cd(e) == 1)
	{
		redirect(e);
		close_fd(e);
		exec_cd(e);
	}
	else if (ft_strequ("exit", e->args[0]))
		ft_exit(e);
	else if (check_env(e, 0))
	{
		check_redirect(e);
		if (check_env(e, 1) == 3)
			return ;
		close_fd(e);
	}
	else if (ft_strequ(e->args[0], "setenv"))
		exec_setenv(e);
	else if (ft_strequ(e->args[0], "unsetenv"))
		exec_unsetenv(e);
	else if (e->ret == 1 || ft_strequ(e->line, ""))
		return ;
	else if (check_fork(e))
		main_conditions2(e);
	else if (e->enter == 0)
		sh_erreur(e);
}

void	free_all(char **new_env, char *new_str)
{
	free(new_env);
	free(new_str);
}
