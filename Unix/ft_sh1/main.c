/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 16:28:14 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/27 14:48:08 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char **argv, char **envp)
{
	t_env e;

	if (!(*envp))
	{
		ft_putstr("No environment found, the shell will exit ");
		ft_putstr("for security reasons.\n");
		exit(0);
	}
	e.environ = envp;
	while (1 + 1 == 2)
		shell(&e);
	(void)argv;
	(void)argc;
	return (0);
}
