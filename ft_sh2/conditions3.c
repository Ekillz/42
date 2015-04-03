/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:55 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/17 18:39:16 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_exit2(t_env *e)
{
	ft_putendl("exit");
	if (check_redirect(e))
	{
		redirect(e);
		close_fd(e);
	}
	exit(ft_atoi(e->args[1]));
}

void			ft_exit(t_env *e)
{
	e->i > 4 ? ft_putendl("exit: Expression Syntax.") : NULL;
	if (e->i > 2 && check_redirect(e) == 0)
		return ;
	else if (e->i == 2 || (e->i >= 3 && check_redirect(e)))
	{
		e->i = 0;
		while (e->args[1][e->i] && ft_isdigit(e->args[1][e->i]))
			e->i++;
		if (e->args[1][e->i] && ft_isdigit(e->args[1][0]))
			ft_putendl("exit: Badly formed number.");
		else if (e->args[1][e->i] && check_redirect(e) == 0)
			ft_putendl("exit: Expression Syntax.");
		else
			ft_exit2(e);
	}
	else if (e->i == 1)
	{
		ft_putendl("exit");
		exit(0);
	}
}
