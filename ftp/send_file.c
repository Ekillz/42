/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 16:44:39 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/21 18:26:38 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void send_file(int sock, char *name, int which)
{
	char		*str;
	int			fd;
	int			r;

	fd = open(name, O_RDWR);
	if (fd == -1)
		send_file2(sock, which);
	else
	{
		str = malloc(sizeof(char *) * (300000 + 1));
		r = read(fd, str, 300000);
		str[r] = '\0';
		if (which == 1)
		{
			if (r > 0)
				printf("SUCCESS : %d bytes sent\n", r);
			else
				printf("ERROR : %d bytes sent\n", r);
		}
		send(sock, str, r, MSG_DONTROUTE);
		ft_memdel((void *)&str);
	}
}
