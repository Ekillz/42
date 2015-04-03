/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 15:35:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 17:22:35 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fork(t_env *e, t_server *serv)
{
	pid_t	father;

	ft_dup(serv, 0);
	if ((father = fork()) == -1)
		send(serv->sock, "FORK ERROR\n", 11, MSG_DONTROUTE);
	if (father > 0)
		wait(NULL);
	if (father == 0)
		ft_putnbr(execv("/bin/ls", e->args));
	ft_dup(serv, 1);
}

int		search_name_index(char *name, t_env *e)
{
	int i;

	i = 0;
	while (e->environ[i])
	{
		if (ft_strnequ(name, e->environ[i], ft_strlen(name)))
			return (i);
		i++;
	}
	return (-1);
}
