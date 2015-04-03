/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:56:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/22 17:15:53 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec_cd2(t_env *e, t_server *serv)
{
	char	*str;
	int		ret;

	str = malloc(sizeof(char *) * MAXPATHLEN);
	str = getcwd(str, MAXPATHLEN);
	ret = chdir(e->args[1]);
	if (path_permission(e->pwd_nb) == 1)
	{
		if (ret == 0)
			success_msg(serv, 0);
		else
			success_msg(serv, 1);
	}
	else
	{
		chdir(str);
		send(serv->cs, "You don't have permission to go further\n",\
				40, MSG_DONTROUTE);
	}
	ft_memdel((void *)&str);
}
