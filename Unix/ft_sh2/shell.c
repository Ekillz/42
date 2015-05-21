/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:42:34 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/03 16:44:31 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void shell(t_env *e)
{
	int			ret;
	static int	t = 0;
	char		*name;
	char		*tmp;

	name = e->environ[search_name_index(get_new_name("USER", 0), e)];
	if (env_name_search("USER", e) == 1)
	{
		tmp = ft_strsub(name, 5, 1000);
		ft_putstr(tmp);
		ft_putstr("-> ");
		ft_memdel((void *)&tmp);
	}
	else
		ft_putstr("$> ");
	if (t > 0)
		free(e->line);
	t++;
	e->line = malloc(sizeof(char *) * 10000);
	signal(SIGINT, ctrl_c);
	ret = read(0, e->line, 10000);
	e->line[ret - 1] = '\0';
	e->ret = ret;
	shell_2(e);
}

void commands(t_env *e)
{
	static int	t = 0;
	char		*path_tmp;
	char		*path_tmp_2;

	if (t == 0)
		path_tmp_2 = e->environ[search_name_index(get_new_name("PATH", 0), e)];
	if (search_name_index("PATH=", e) != -1)
		path_tmp = e->environ[search_name_index(get_new_name("PATH", 0), e)];
	else
		path_tmp = path_tmp_2;
	free_pwd_path(e, t);
	t++;
	e->buf_path = malloc(sizeof(char *) * 100000);
	e->old_pwd = malloc(sizeof(char *) * 100000);
	e->point_vir == 1 ? (e->args = split_it(e->point_args[e->d])) :
		(e->args = split_it(e->line));
	e->path = ft_strsplit(ft_strsub(path_tmp, 5, 10000), ':');
	commands_declarations(e);
	if (e->pipe_on == 1)
		if (pipe_error_check(e))
			return ;
	main_conditions(e);
}
