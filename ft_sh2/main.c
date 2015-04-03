/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:41:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 16:26:46 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv, char **envp)
{
	t_env e;

	if (!(*envp))
	{
		ft_putstr_fd("No environment found, the shell will exit ", 2);
		ft_putstr_fd("for security reasons.\n", 2);
		exit(0);
	}
	e.environ = envp;
	e.redirect = -1;
	while (1 + 1 == 2)
		shell(&e);
	(void)argv;
	(void)argc;
	return (0);
}
