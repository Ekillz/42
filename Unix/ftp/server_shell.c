/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:36:30 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/01 14:53:28 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			env_erreur(void)
{
	printf("No environment found, the server will exit for security reasons\n");
	exit(0);
}

static void		msg_server_new_client(int root, int t, int port)
{
	ft_putstr("New Client connected\n");
	if (root == 1)
		ft_putstr("[root]");
	ft_putstr("[");
	ft_putnbr(port);
	ft_putstr("]server[");
	ft_putnbr(t);
	ft_putstr("]$> ");
}

void			shell(t_server *serv, t_env *e)
{
	char				*buf;
	int					r;

	msg_server_new_client(e->root, e->t, serv->port);
	buf = malloc(sizeof(char *) * 10000);
	while (1 + 1 == 2)
	{
		r = recv(serv->cs, buf, 10000, MSG_PEEK);
		read(serv->cs, buf, 10000);
		if (buf[r - 1] == '\n')
			buf[r - 1] = '\0';
		else
			buf[r] = '\0';
		main_conditions(e, buf, serv->cs, serv);
		serv->cd_error = 0;
		ft_memdel((void *)&buf);
		buf = malloc(sizeof(char *) * 10000);
	}
}
