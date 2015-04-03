/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:41:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/25 14:25:27 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_unset_env(char **new_env, t_env *e, char *name)
{
	int r;
	int	t;

	t = 0;
	r = 0;
	env_name_search(name, e);
	while (r < e->index_env)
	{
		new_env[r] = e->environ[t];
		r++;
		t++;
	}
	t++;
	while (e->environ[t])
	{
		new_env[r] = e->environ[t];
		r++;
		t++;
	}
	new_env[r] = NULL;
	e->environ = new_env;
}
