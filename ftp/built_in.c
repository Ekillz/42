/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 16:28:16 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/22 17:44:36 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_cd(char **args, t_server *serv)
{
	int i;

	i = 0;
	if (ft_strequ("cd", args[0]))
		while (args[i])
			i++;
	if (i > 0 && i < 3)
		return (1);
	if (ft_strequ("cd", args[0]))
		serv->cd_error = 1;
	return (0);
}

void	exec_cd(t_env *e, char *line, t_server *serv)
{
	if ((ft_strequ("~", e->args[1]) || !e->args[1]))
	{
		if (chdir(e->home) == 0)
			send(serv->cs, "SUCCESS : changed directory to home directory\n", \
					46, MSG_DONTROUTE);
		else
			send(serv->cs, "ERROR : Couldn't change to home directory\n",\
					42, MSG_DONTROUTE);
	}
	else if (ft_strequ("~", e->args[1]) == 0 && e->args[1])
	{
		if (e->root != 1)
			exec_cd2(e, serv);
		else
		{
			if (chdir(e->args[1]) == 0)
				success_msg(serv, 0);
			else
				success_msg(serv, 1);
		}
	}
	else
		cd_erreur(line, serv);
}

int		first_pwd_count(char *pwd)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (pwd[i])
	{
		if (pwd[i] == '/')
			e++;
		i++;
	}
	return (e);
}

int		path_permission(int pwd_nb)
{
	char *pwd;

	pwd = malloc(sizeof(char *) * MAXPATHLEN);
	pwd = getcwd(pwd, MAXPATHLEN);
	if (first_pwd_count(pwd) >= pwd_nb)
	{
		ft_memdel((void *)&pwd);
		return (1);
	}
	ft_memdel((void *)&pwd);
	return (0);
}

void	show_pwd(t_server *serv)
{
	char	*buf;

	buf = malloc(sizeof(char *) * MAXPATHLEN + 50);
	if ((buf = getcwd(buf, MAXPATHLEN)) != NULL)
	{
		buf = ft_strjoin("\n", buf);
		send(serv->cs, "SUCCESS : The server's PWD is visible on the Server\n"\
				, 52, MSG_DONTROUTE);
		ft_putstr_fd(buf, 0);
		ft_memdel((void *)&buf);
	}
	else
		send(serv->cs, "ERROR : Couldn't get the server's PWD:\n",\
				37, MSG_DONTROUTE);
}
