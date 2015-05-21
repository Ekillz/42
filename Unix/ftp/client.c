/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:22:08 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 13:25:12 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			client_main_conditions(t_env *e, char *line, int sock)
{
	e->args = split_it(line);
	if (ft_strequ(e->args[0], "quit"))
		client_quit(sock);
	else if (ft_strequ(e->args[0], "put") && e->args[1] && !e->args[2])
		send_file(sock, e->args[1], 1);
	else if (ft_strequ(e->args[0], "get") && e->args[1] && !e->args[2])
		get_file(sock, e->args[1], 1);
	else if (ft_strequ(e->args[0], "ls") || ft_strequ(e->args[0], "/bin/ls"))
		fork_message(sock);
	else if (ft_strequ(e->args[0], "pwd") || ft_strequ(e->args[0], "/bin/pwd"))
		server_msg(sock);
	else if (ft_strequ("cd", e->args[0]))
		server_msg(sock);
	else
	{
		if (ft_strequ(line, "") == 0)
			server_msg(sock);
	}
	ft_freetab(e->args);
}

int				create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (ft_strequ("localhost", addr))
		addr = "127.0.0.1";
	proto = getprotobyname("tcp");
	if (!(proto))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	connect(sock, (const struct sockaddr *)&sin, sizeof(sin));
	return (sock);
}

static void		first_msg(int sock)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof(char *) * 50);
	r = recv(sock, buf, 50, MSG_PEEK);
	read(sock, buf, 50);
	buf[r] = '\0';
	ft_putstr(buf);
	ft_memdel((void *)&buf);
}

int				main(int ac, char **av)
{
	int					port;
	int					sock;
	t_env				e;
	char				*home;

	client_error(ac);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	first_msg(sock);
	home = malloc(sizeof(char *) * MAXPATHLEN);
	if ((home = getcwd(home, MAXPATHLEN)) == NULL)
	{
		printf("Error getting local pwd\n");
		home = ".";
	}
	while (1 + 1 == 2)
		client_shell(&e, home, sock);
	close(sock);
	return (0);
}
