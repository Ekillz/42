/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe_redirec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:20:26 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 16:13:09 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		check_mid_redirect(t_env *e, int s)
{
	int i;
	int r;

	r = 0;
	i = 1;
	while (i <= s - 1)
	{
		if (e->p_args[i][r] == '>' || e->p_args[i][r] == '<')
			return (1);
		r++;
		if (!e->p_args[i][r])
		{
			r = 0;
			i++;
		}
	}
	return (0);
}

static int		check_last_redirect(t_env *e, int s)
{
	int r;

	r = 0;
	while (e->p_args[s][r])
	{
		if (e->p_args[s][r] == '<')
			return (1);
		r++;
	}
	return (0);
}

static int		check_exist(t_env *e, int s)
{
	int		r;
	int		i;
	int		t;
	char	**args_exist;

	t = 0;
	r = 0;
	i = 0;
	while (e->p_args[i])
	{
		args_exist = split_it(e->p_args[i]);
		t = check_exist2(e, r, t, args_exist);
		i++;
		r = 0;
	}
	if (t == s + 1)
		return (1);
	return (0);
}

int				main_errors(t_env *e)
{
	int r;
	int s;

	s = 0;
	r = 0;
	while (e->p_args[s])
		s++;
	s--;
	e->nb_pipe_args = s;
	if (check_exist(e, s) == 1)
	{
		if (s > 1)
			if (check_mid_redirect(e, s) == 1)
				return (1);
		if (check_last_redirect(e, s) == 1)
			return (1);
		if (main_errors2(e, r) == 1)
			return (1);
		return (0);
	}
	else
		e->sh_erreur = 1;
	return (0);
}
