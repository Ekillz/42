/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_erreur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 17:05:40 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 13:23:58 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	client_error(int ac)
{
	if (ac != 3)
	{
		ft_putstr("Usage : client <addr> <port>\n");
		exit(-1);
	}
}

void	client_quit(int sock)
{
	if (close(sock) == -1)
		ft_putstr("ERROR : There was a problem while closing the connection\n");
	else
		ft_putstr("SUCCESS : Connection succesfully cancelled\n");
	exit(0);
}
