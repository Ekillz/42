/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:51:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/22 17:43:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_file(int sock, char *name, int which)
{
	char	*str;
	int		r;
	int		fd;

	str = malloc(sizeof(char *) * 300000);
	r = recv(sock, str, 300000, MSG_PEEK);
	read(sock, str, 300000);
	str[r] = '\0';
	if (ft_strnequ("ERROR", str, 5) == 0)
	{
		if (which == 1)
		{
			if (r > 0)
				printf("SUCCESS : %d bytes received\n", r);
			else
				printf("ERROR : %d bytes received\n", r);
		}
		fd = open(name, O_CREAT | O_RDWR, 0644);
		write(fd, str, r);
	}
	else if (ft_strnequ("ERROR =", str, 7))
		printf("%s", str);
	ft_memdel((void *)&str);
}

void	ft_dup(t_server *serv, int which)
{
	if (which == 0)
	{
		serv->save = 1;
		serv->save2 = 2;
		dup2(1, serv->save);
		dup2(2, serv->save2);
		dup2(serv->cs, 1);
		dup2(serv->cs, 2);
	}
	else
	{
		dup2(serv->save, 1);
		dup2(serv->save2, 2);
		close(serv->save);
		close(serv->save2);
	}
}

void	server_msg(int sock)
{
	int		r;
	char	*str;

	str = malloc(sizeof(char *) * 100000);
	r = recv(sock, str, 100000, MSG_PEEK);
	read(sock, str, 100000);
	str[r] = '\0';
	ft_putstr_fd(str, 1);
	ft_memdel((void *)&str);
}

void	success_msg(t_server *serv, int which)
{
	char *str;
	char *buf;

	buf = malloc(sizeof(char *) * MAXPATHLEN);
	str = malloc(sizeof(char *) * MAXPATHLEN + 40);
	if (which == 0)
		str = ft_strjoin("SUCCESS New directory is ", getcwd(buf, MAXPATHLEN));
	else if (which == 1)
		str = ft_strjoin("ERROR : Couldn't change directory ",\
				getcwd(buf, MAXPATHLEN));
	str = ft_strjoin(str, "\n");
	send(serv->cs, str, ft_strlen(str), MSG_DONTROUTE);
	ft_memdel((void *)&str);
	ft_memdel((void *)&buf);
}

void	fork_message(int sock)
{
	int		r;
	char	*str;

	str = malloc(sizeof(char *) * 100000);
	r = recv(sock, str, 100000, MSG_PEEK);
	read(sock, str, 100000);
	str[r] = '\0';
	if (ft_strequ("-1", str))
		printf("ERROR : EXECVE Error\n");
	else if (ft_strstr("FORK ERROR", str))
		printf("ERROR : FORK FAILED\n");
	else
		printf("SUCCESS : Execve was executed and %d bytes were received\n%s",\
				r, str);
	ft_memdel((void *)&str);
}
