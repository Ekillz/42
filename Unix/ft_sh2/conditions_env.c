/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:29:24 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/10 19:36:29 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	write_env_erreur(t_env *e)
{
	ft_putstr_erreur("env: ");
	ft_putstr_erreur(ft_strsub(e->line, 4, 1500));
	ft_putstr_erreur(": No such file or directory");
	write(2, "\n", 1);
}

void	redirect_env(t_env *e)
{
	redirect(e);
	get_env(e);
	close_fd(e);
}

void	write_unsetenv_erreur(void)
{
	ft_putstr_erreur("Bad usage: Usage: setenv [NAME=VALUE] [1 or 0]: ");
	ft_putstr_erreur("by default it will be 0! 1 is to reset");
	write(2, "\n", 1);
}
