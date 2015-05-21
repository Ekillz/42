/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:40:38 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/12 16:26:18 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_cd(t_env *e)
{
	if (e->i == 3 && check_redirect(e) == 0)
		return (0);
	else if ((ft_strequ("cd", e->args[0]) && e->i == 2 &&
				check_redirect(e) == 0)
			|| ft_strequ("cd", e->args[0]))
		return (1);
	else if (ft_strequ("cd", e->args[0]) && check_redirect_args(e))
		return (1);
	return (0);
}

void	exec_cd(t_env *e)
{
	e->old_pwd = ft_strsub(e->environ[search_name_index(get_new_name
				("PWD", 0), e)], 5, 1500);
	if ((ft_strequ("~", e->args[1]) == 1 || (ft_strequ("cd", e->args[0])
				&& ((!e->args[1] && !check_redirect(e))
						|| (e->args[1] && check_redirect(e)))))
			&& (access(ft_strsub(e->environ
						[search_name_index(get_new_name("HOME", 0), e)]
						, 5, 1000), X_OK)) == 0)
		chdir(ft_strsub(e->environ[search_name_index(get_new_name
						("HOME", 0), e)], 5, 1000));
	else if (ft_strequ(e->args[1], "-") == 1 && (access(ft_strsub
					(e->environ[search_name_index(get_new_name("OLDPWD", 0), e)
					], 7, 1000), X_OK)) == 0)
		chdir(ft_strsub(e->environ[search_name_index(
						get_new_name("OLDPWD", 0), e)], 7, 1000));
	else if ((access(e->args[1], X_OK)) == 0)
		chdir(e->args[1]);
	else
		cd_erreur(e);
	malloc_env("PWD", getcwd(e->buf_path, MAXPATHLEN), e, 1);
	if (ft_strequ(e->old_pwd, ft_strsub(e->environ[search_name_index
					(get_new_name("PWD", 0), e)], 5, 1500)) == 0)
		malloc_env("OLDPWD", ft_strjoin("/", e->old_pwd), e, 1);
}

int		check_env(t_env *e, int search_exec)
{
	if (search_exec == 0)
	{
		if (e->redirect >= 0 && ft_strequ("env", e->args[0]))
			return (1);
		if (ft_strequ("env", e->args[0]) == 1 || (ft_strequ("env",
						e->args[0]) == 1 && ft_strequ("-i", e->args[1]) == 1))
			return (1);
	}
	else if (search_exec == 1)
	{
		if ((ft_strequ("env", e->args[0]) && !e->args[1]) ||
				(ft_strequ("env", e->args[0]) && check_redirect_args(e)))
		{
			malloc_env("PWD", getcwd(e->buf_path, MAXPATHLEN), e, 1);
			redirect(e);
			get_env(e);
		}
		else if (ft_strequ("env", e->args[0]) && ft_strequ("-i", e->args[1]))
			return (3);
		else
			write_env_erreur(e);
	}
	return (0);
}

void	exec_setenv(t_env *e)
{
	if (e->args[1] && check_equal(e->args[1]) == 1)
	{
		if (e->i >= 3 && check_redirect(e))
			redirect(e);
		else if (env_name_search(get_new_name(e->args[1], 0), e) == 0
				|| ft_strequ(e->args[1], "=") == 1)
		{
			conditions_setenv(e, 0);
		}
		else if (env_name_search(get_new_name(e->args[1], 0), e) == 1
				&& e->args[2]
				&& ft_strequ(e->args[2], "1") == 1)
		{
			conditions_setenv(e, 1);
		}
		get_env(e);
		close_fd(e);
	}
	else if (e->i == 3 && check_redirect(e))
		redirect_env(e);
	else
		write_unsetenv_erreur();
}

void	conditions_setenv(t_env *e, int which)
{
	if (which == 0)
	{
		e->tmp_name_value = ft_strsplit(e->args[1], '=');
		if (ft_strequ(e->args[1], "=") == 1)
			malloc_env("=", "", e, 1);
		else if (ft_atoi(get_new_name(e->args[1], 1)) == 1931)
			malloc_env(get_new_name(e->args[1], 0), "", e, 1);
		else if (check_equal(e->args[1]) == 1)
			malloc_env(get_new_name(e->args[1], 0),
					get_new_name(e->args[1], 1), e, 1);
	}
	else if (which == 1)
	{
		e->tmp_name_value = ft_strsplit(e->args[1], '=');
		if (ft_strequ(e->args[1], "=") == 1)
			malloc_env("=", "", e, 1);
		else if (ft_atoi(get_new_name(e->args[1], 1)) == 1931)
			malloc_env(get_new_name(e->args[1], 0), "", e, 1);
		else if (check_equal(e->args[1]) == 1)
			malloc_env(get_new_name(e->args[1], 0),
					get_new_name(e->args[1], 1), e, 1);
	}
}
