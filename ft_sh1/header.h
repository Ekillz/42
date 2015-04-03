/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 17:09:33 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/27 16:47:43 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/param.h>

typedef struct	s_env
{
	char	*line;
	char	**args;
	char	*buf;
	char	**environ;
	char	*tmp_line;
	int		ret;
	int		index_env;
	char	**tmp_name_value;
	char	**path;
	char	*buf_path;
	char	*old_pwd;
	int		enter;
	int		name_value_len;
	pid_t	father;
	char	*path_access;
	char	*execve_path;
	int		i;
}				t_env;

int				ft_fork2(t_env *e, int i);
void			ft_exit(t_env *e);
void			cd_erreur(t_env *e);
int				check_fork(t_env *e);
void			free_all(char **new_env, char *new_str);
void			main_conditions(t_env *e);
void			sh_erreur(t_env *e);
int				ft_fork(t_env *e, int i);
void			exec_unsetenv(t_env *e);
void			conditions_setenv(t_env *e, int which);
void			exec_setenv(t_env *e);
int				check_env(t_env *e, int search_exec);
void			exec_cd(t_env *e);
int				check_cd(t_env *e);
int				access_check(t_env *e);
int				search_name_index(char *name, t_env *e);
void			ft_unset_env(char **new_env, t_env *e, char *name);
char			*get_new_name(char *line, int which);
int				check_equal(char *line);
void			set_env(char *new_str, char **new_env, t_env *e, char *name);
void			malloc_env(char *name, char *value, t_env *e, int which);
int				env_name_search(char *name, t_env *e);
void			get_env(t_env *e);
char			*get_path(char *line);
void			commands(t_env *e);
void			shell(t_env *e);
#endif
