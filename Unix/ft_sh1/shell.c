/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:12:41 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 15:57:16 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void shell(t_env *e)
{
	int			ret;
	static int	t = 0;
	char		*name;

	name = e->environ[search_name_index(get_new_name("USER", 0), e)];
	if (env_name_search("USER", e) == 1)
	{
		ft_putstr(ft_strsub(name, 5, 1000));
		ft_putstr("-> ");
	}
	else
	{
		//ft_putstr("\033[33m");
		ft_putstr("$> ");
	}
	if (t > 0)
		free(e->line);
	t++;
	e->line = malloc(sizeof(char *) * 1000);
	ret = read(0, e->line, 1000);
	e->ret = ret;
	e->line[ret - 1] = '\0';
	commands(e);
}

void commands(t_env *e)
{
	static int	t = 0;
	char		*path_tmp;

	if (search_name_index("PATH=", e) != -1)
		path_tmp = e->environ[search_name_index(get_new_name("PATH", 0), e)];
	if (t > 0)
	{
		free(e->buf_path);
		free(e->old_pwd);
	}
	t++;
	e->buf_path = malloc(sizeof(char *) * 100000);
	e->old_pwd = malloc(sizeof(char *) * 100000);
	e->enter = 0;
	e->args = split_it(e->line);
	e->path = ft_strsplit(ft_strsub(path_tmp, 5, 10000), ':');
	e->i = 0;
	while (e->args[e->i])
		e->i++;
	main_conditions(e);
}
