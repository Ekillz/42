/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:23:45 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/22 17:12:06 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_file2(int sock, int which)
{
	if (which == 1)
	{
		printf("ERROR : File doesn't exist\n");
		write(sock, "ERROR", 5);
	}
	else if (which == 2)
		write(sock, "ERROR = File doesn't exist\n", 27);
}

void	get_put_msg(int sock, char **args, int which)
{
	if (which == 0)
	{
		if (!args[1] || args[2])
			send(sock, "usage : get <file>\n", 19, MSG_DONTROUTE);
		else
			send_file(sock, args[1], 2);
	}
	else if (which == 1)
	{
		if (!args[1] || args[2])
			send(sock, "usage : put <file>\n", 19, MSG_DONTROUTE);
		else
			get_file(sock, args[1], 2);
	}
}
