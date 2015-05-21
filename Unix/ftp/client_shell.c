/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:53:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/22 15:29:28 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	client_shell(t_env *e, char *home, int sock)
{
	char *tmp;

	ft_putstr("ftp-> ");
	e->line = malloc(sizeof(char *) * 1000);
	signal(SIGINT, ctrl_c);
	e->ret = read(0, e->line, 1000);
	e->line[e->ret - 1] = '\0';
	tmp = ft_strtrim(e->line);
	if (local_conditions(tmp, home) == 0)
	{
		send(sock, tmp, ft_strlen(tmp), MSG_DONTROUTE);
		client_main_conditions(e, tmp, sock);
	}
	ft_memdel((void *)&e->line);
	ft_memdel((void *)&tmp);
}
