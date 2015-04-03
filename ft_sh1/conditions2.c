/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 14:28:22 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/13 13:05:09 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_unsetenv(t_env *e)
{
	if (e->args[1] && env_name_search(e->args[1], e) == 1)
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
	if (search_name_index("PATH=", e) != -1)
	{
		e->enter = 1;
		e->father = fork();
		if (e->father > 0)
		{
			e->enter = 1;
			wait(NULL);
		}
		if (e->father == 0)
			while (e->path[i])
			{
				e->path_access = ft_strjoin(e->path[i], "/");
				e->execve_path = ft_strjoin(e->path_access, e->args[0]);
				if (access(ft_strjoin(e->path_access, e->args[0]), X_OK) == 0)
					execve(e->execve_path, e->args, e->environ);
				if (access(e->args[0], X_OK) == 0)
					execve(e->args[0], e->args, e->environ);
				i++;
			}
	}
	else
		ft_fork2(e, i);
	return (0);
}

void	sh_erreur(t_env *e)
{
	ft_putstr_erreur("ft_sh1: command not found: ");
	ft_putstr_erreur(e->line);
	write(2, "\n", 1);
}

void	main_conditions(t_env *e)
{
	int i;

	i = 0;
	if (check_cd(e) == 1)
		exec_cd(e);
	else if (ft_strequ("exit", e->args[0]) == 1)
		ft_exit(e);
	else if (check_env(e, 0) == 1)
		check_env(e, 1);
	else if (ft_strequ(e->args[0], "setenv") == 1)
		exec_setenv(e);
	else if (ft_strequ(e->args[0], "unsetenv") == 1)
		exec_unsetenv(e);
	else if (e->ret == 1 || ft_strequ(e->args[0], "") == 1)
		shell(e);
	else if (check_fork(e) == 1)
		ft_fork(e, i);
	else if (e->enter == 0)
		sh_erreur(e);
	else
		shell(e);
}

void	free_all(char **new_env, char *new_str)
{
	free(new_env);
	free(new_str);
}
