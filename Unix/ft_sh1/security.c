/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:14:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/13 13:12:22 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_equal(char *line)
{
	int i;

	i = 0;
	if (line[0] == '=' && line[1] == '=')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		search_name_index(char *name, t_env *e)
{
	int i;

	i = 0;
	while (e->environ[i])
	{
		if (ft_strnequ(name, e->environ[i], ft_strlen(name)) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		access_check(t_env *e)
{
	int i;

	i = 0;
	while (e->path[i])
	{
		if (access(ft_strjoin(ft_strjoin(e->path[i], "/"),
						e->args[0]), X_OK) == 0)
			return (1);
		else if (access(e->args[0], X_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		check_fork(t_env *e)
{
	if (ft_strequ(ft_strtrim(e->line), "") == 1)
	{
		e->enter = 1;
		return (0);
	}
	if (access_check(e) == 1 && ft_strequ("env", e->args[0]) == 0
			&& ft_strequ("cd", e->args[0]) == 0)
	{
		return (1);
	}
	return (0);
}

void	cd_erreur(t_env *e)
{
	ft_putstr_erreur("cd: no such file or directory: ");
	if (e->i == 2)
		ft_putstr_erreur(e->args[1]);
	write(2, "\n", 1);
}
