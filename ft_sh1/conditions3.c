/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:05:50 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/03 16:09:15 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(t_env *e)
{
	e->i > 2 ? ft_putendl("exit: Expression Syntax.") : NULL;
	if (e->i > 2)
		return ;
	else if (e->i == 2)
	{
		e->i = 0;
		while (e->args[1][e->i] && ft_isdigit(e->args[1][e->i]))
			e->i++;
		if (e->args[1][e->i] && ft_isdigit(e->args[1][0]))
			ft_putendl("exit: Badly formed number.");
		else if (e->args[1][e->i])
			ft_putendl("exit: Expression Syntax.");
		else
		{
			ft_putendl("exit");
			exit(ft_atoi(e->args[1]));
		}
	}
	else if (e->i == 1)
	{
		ft_putendl("exit");
		exit(0);
	}
}

int		ft_fork2(t_env *e, int i)
{
	e->enter = 1;
	e->father = fork();
	if (e->father > 0)
	{
		e->enter = 1;
		wait(NULL);
	}
	if (e->father == 0)
	{
		while (e->path[i])
		{
			if (access(e->args[0], X_OK) == 0)
				execve(e->args[0], e->args, e->environ);
			i++;
		}
	}
	return (0);
}
