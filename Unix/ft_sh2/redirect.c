/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:13:21 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:40:34 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	redirect(t_env *e)
{
	if (check_redirect(e))
	{
		if (e->fork_on == 1 && e->pipe_on == 0)
		{
			new_args_copy(e, e->args);
			ft_dup_redirect(e);
		}
	}
}

void	new_args_copy(t_env *e, char **args)
{
	static int	t = 0;
	int			i;

	i = 0;
	if (t > 0)
		free(e->new_args);
	t++;
	e->new_args = malloc(sizeof(char **) * 1000);
	while (args[i])
	{
		if (ft_strequ(args[i], ">") || ft_strequ(args[i], ">>"))
			break ;
		else if (ft_strequ(args[i], "<") || ft_strequ(args[i], "<<"))
			break ;
		else
			e->new_args[i] = args[i];
		i++;
	}
}

int		check_redirect(t_env *e)
{
	int i;

	i = 1;
	while (e->args[i])
	{
		if (ft_strequ(e->args[i], ">"))
			e->redirect = 0;
		else if (ft_strequ(e->args[i], ">>"))
			e->redirect = 1;
		else if (ft_strequ(e->args[i], "<"))
			e->redirect = 2;
		else if (ft_strequ(e->args[i], "<<"))
			e->redirect = 3;
		if (e->redirect >= 0)
		{
			e->redirect_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}
