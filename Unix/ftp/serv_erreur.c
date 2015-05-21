/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_erreur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 12:04:59 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 16:22:30 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_serveur_root_erreur(char *av, int ac)
{
	if (ft_strequ(av, "root"))
		return (1);
	else
		server_argument_error(ac, 1);
	return (0);
}

void	server_argument_error(int ac, int which)
{
	if (which == 0)
	{
		if (ac > 3)
		{
			ft_putstr("Usage : server <port>, you can add <root> for Rights\n");
			exit(-1);
		}
	}
	else
	{
		ft_putstr("Usage : server <port>, you can add <root> for Rights\n");
		exit(-1);
	}
}

void	cd_erreur(char *line, t_server *serv)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin("cd: no such file or directory: ", line);
	tmp2 = ft_strjoin(tmp, "\n");
	send(serv->cs, tmp2, ft_strlen(line) + 32, MSG_DONTROUTE);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&tmp2);
}

void	ftp_erreur(char *buf, t_server *serv)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin("Command: ", buf);
	tmp2 = ft_strjoin(tmp, ": not recognized\n");
	send(serv->cs, tmp2, 28 + ft_strlen(buf), MSG_DONTROUTE);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&tmp2);

}

void	shell_success(t_env *e, t_server *serv)
{
	send(serv->cs, "SUCCESS : New client succesfully connected\n",\
			43, MSG_DONTROUTE);
	shell(serv, e);
}
