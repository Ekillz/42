/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:16:31 by emammadz          #+#    #+#             */
/*   Updated: 2015/04/01 14:53:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	local_pwd(void)
{
	char *buf;

	buf = malloc(sizeof(char *) * MAXPATHLEN);
	if ((buf = getcwd(buf, MAXPATHLEN)) != NULL)
	{
		printf("%s\n", buf);
		ft_memdel((void *)&buf);
	}
}

void	local_fork(char *line)
{
	pid_t	father;
	char	**args;

	args = split_it(line);
	if ((father = fork()) == -1)
		printf("FORK ERROR\n");
	if (father > 0)
		wait(NULL);
	if (father == 0)
		execv("/bin/ls", args);
	ft_freetab(args);
}

int		local_check_cd(char *line)
{
	int		i;
	char	**args;

	i = 0;
	args = split_it(line);
	if (ft_strequ("lcd", args[0]))
		while (args[i])
			i++;
	ft_freetab(args);
	if (i > 0 && i < 3)
		return (1);
	if (ft_strequ("lcd", args[0]))
		printf("cd: no such file or directory: line: %s\n", line);
	return (0);
}

void	local_cd(char *line, char *home)
{
	char **args;

	args = split_it(line);
	if (ft_strequ("~", args[1]) || !args[1])
	{
		if (chdir(home) == -1)
			printf("chdir failed\n");
	}
	else if (ft_strequ("~", args[1]) == 0 && args[1])
	{
		if (chdir(args[1]) == -1)
			printf("chdir failed\n");
	}
	else
		printf("cd: no such file or directory: line: %s\n", line);
	ft_freetab(args);
}

int		local_conditions(char *line, char *home)
{
	char **args;

	args = split_it(line);
	if (ft_strequ(args[0], "lpwd"))
	{
		local_pwd();
		return (1);
	}
	else if (ft_strequ(args[0], "lls"))
	{
		local_fork(line);
		return (1);
	}
	else if (ft_strequ(args[0], "lcd"))
	{
		if (local_check_cd(line))
			local_cd(line, home);
		return (1);
	}
	ft_freetab(args);
	return (0);
}
