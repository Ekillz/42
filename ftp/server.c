/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 12:33:19 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/01 14:52:49 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	main_conditions(t_env *e, char *buf, int sock, t_server *serv)
{
	e->args = split_it(buf);
	if (ft_strequ("quit", e->args[0]))
	{
		close(sock);
		ft_putstr_fd("\nA user disconnected\n",  0);
		exit(0);
	}
	else if (ft_strequ(e->args[0], "get"))
		get_put_msg(sock, e->args, 0);
	else if (ft_strequ(e->args[0], "put"))
		get_put_msg(sock, e->args, 1);
	else if (ft_strequ(e->args[0], "ls") || ft_strequ(e->args[0], "/bin/ls"))
		ft_fork(e, serv);
	else if (ft_strequ(e->args[0], "pwd") || ft_strequ(e->args[0], "/bin/pwd"))
		show_pwd(serv);
	else if (check_cd(e->args, serv))
		exec_cd(e, buf, serv);
	else
	{
		if (serv->cd_error == 1)
			cd_erreur(buf, serv);
		else if (ft_strequ(ft_strtrim(buf), "") == 0)
			ftp_erreur(buf, serv);
	}
	ft_freetab(e->args);
}

int		create_server(int port)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;
	int					sock;

	proto = getprotobyname("tcp");
	if (!(proto))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(sock, 42);
	return (sock);
}

void	create_port_socket(t_server *serv, char *av)
{
	int					port;
	int					sock;

	port = ft_atoi(av);
	sock = create_server(port);
	serv->sock = sock;
	serv->port = port;
}

void	declarations_server(t_env *e)
{
	e->first_pwd = malloc(sizeof(char *) * MAXPATHLEN);
	e->first_pwd = getcwd(e->first_pwd, MAXPATHLEN);
	e->pwd_nb = first_pwd_count(e->first_pwd);
	e->home = e->first_pwd;
	e->t = 0;
}

int		main(int ac, char **av, char **envp)
{
	t_env				e;
	t_server			serv;
	unsigned int		cslen;
	struct sockaddr_in	*csin;
	pid_t				father;

	!(*envp) ? (env_erreur()) : (NULL);
	server_argument_error(ac, 0);
	if (av[2])
		e.root = check_serveur_root_erreur(av[2], ac);
	declarations_server(&e);
	create_port_socket(&serv, av[1]);
	ft_putstr_fd("Waiting for new connection\n", 0);
	while (1 + 1 == 2)
	{
		e.t++;
		serv.cs = accept(serv.sock, (struct sockaddr *)&csin, &cslen);
		if ((father = fork()) == -1)
			send(serv.cs, "ERROR : Fork failed\n", 20, MSG_DONTROUTE);
		else if (father == 0)
			shell_success(&e, &serv);
	}
	close(serv.cs);
	close(serv.sock);
	return (0);
}
