/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:12:03 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/27 16:51:53 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_env(t_env *e)
{
	char **tmp_env;

	tmp_env = e->environ;
	while (*tmp_env)
	{
		ft_putstr(*tmp_env);
		ft_putchar('\n');
		tmp_env++;
	}
}

int		env_name_search(char *name, t_env *e)
{
	int		i;
	char	*tmp_name;

	i = 0;
	if (ft_strequ(name, "=") == 0)
		tmp_name = ft_strjoin(name, "=");
	else
		tmp_name = name;
	while (e->environ[i])
	{
		if (ft_strnequ(tmp_name, e->environ[i], ft_strlen(name) + 1) == 0)
			i++;
		else
		{
			e->index_env = i;
			return (1);
		}
		if (!e->environ[i])
			return (0);
	}
	return (-1);
}

void	malloc_env(char *name, char *value, t_env *e, int which)
{
	int				i;
	int				len;
	static char		**new_env;
	static char		*new_str;
	static int		t = 0;

	e->name_value_len = ft_strlen(name) + ft_strlen(value);
	len = 0;
	i = 0;
	while (e->environ[i])
	{
		len += ft_strlen(e->environ[i]);
		i++;
	}
	if (t > 0)
		free_all(new_env, new_str);
	new_env = malloc(sizeof(char **) * (len + (i - 1) + e->name_value_len + 2));
	new_str = malloc(sizeof(char *) * (ft_strlen(name) + ft_strlen(value) + 2));
	new_str = ft_strcpy(new_str, name);
	new_str = ft_strcat(new_str, "=");
	new_str = ft_strcat(new_str, value);
	if (which == 1)
		set_env(new_str, new_env, e, name);
	else
		ft_unset_env(new_env, e, name);
}

void	set_env(char *new_str, char **new_env, t_env *e, char *name)
{
	int r;

	r = 0;
	while (e->environ[r])
	{
		new_env[r] = e->environ[r];
		r++;
	}
	if (new_str[0] == '=')
		new_str[1] = '\0';
	if (env_name_search(name, e) == 0)
		new_env[r] = new_str;
	else
		new_env[e->index_env] = new_str;
	e->environ = new_env;
}

char	*get_new_name(char *line, int which)
{
	int			i;
	int			e;
	char		*buf;

	i = 0;
	e = 0;
	buf = malloc(sizeof(char *) * ft_strlen(line));
	if (which == 1)
	{
		while (line[i] != '=')
			i++;
		i++;
		if (!(line[i]))
			return ("1931");
		while (line[i] != '\0')
			buf[e++] = line[i++];
	}
	else if (which == 0)
	{
		while (line[i] != '=')
			buf[e++] = line[i++];
		buf[e] = line[i];
	}
	buf[e] = '\0';
	return (buf);
}
