/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:41:43 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/10 19:36:32 by emammadz         ###   ########.fr       */
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
	int		fork_on;
	char	**tmp_name_value;
	char	**path;
	char	*buf_path;
	char	*old_pwd;
	int		test;
	int		enter;
	int		name_value_len;
	pid_t	father;
	char	*path_access;
	char	*execve_path;
	int		i;
	char	**new_args;
	int		redirect_index;
	int		fd;
	int		fd2;
	int		redirect;
	int		nb_redirect;
	int		i_args;
	char	**p_args;
	int		pipe_on;
	char	**pipe_args;
	int		fd3;
	int		p[2];
	int		index_pipe;
	pid_t	child;
	int		pipe_mid;
	int		nb_pipe_args;
	int		sh_erreur;
	int		redirect_index_2;
	char	**point_args;
	int		d;
	int		c;
	int		point_vir;
	char	*line_redirect;
	char	*line_buf;
	int		redirect_left_enter;
	int		second_redirect;
	int		signal;
}				t_env;

void			write_unsetenv_erreur(void);
void			redirect_env(t_env *e);
void			write_env_erreur(t_env *e);
void			ft_fork_2_normal(t_env *e, int i);
void			main_conditions2(t_env *e);
int				main_errors2(t_env *e, int r);
int				check_exist2(t_env *e, int r, int t, char **args_exist);
void			do_tern_point_vir(t_env *e);
void			do_tern_point_vir(t_env *e);
void			ft_dup(t_env *e, int pipe_fd[2], int which);
void			exec_fork2(t_env *e, int i, int pipe_fd[2]);
void			exec_fork3(t_env *e, int i, int pipe_fd[2]);
void			pipe_exec(t_env *e);
void			ft_dup_3(t_env *e, int pipe_fd[2]);
void			ft_dup_2(t_env *e, int pipe_fd[2]);
void			ft_dup_1(t_env *e, int pipe_fd[2]);
int				pipe_error_check(t_env *e);
void			commands_declarations(t_env *e);
void			free_pwd_path(t_env *e, int t);
void			shell_2(t_env *e);
void			ctrl_c(int sig);
int				redirect_double_left(t_env *e);
int				point_vir(t_env *e);
int				count_point_args(t_env *e);
int				check_second_redirect(t_env *e);
void			ft_dup_redirect(t_env *e);
int				main_errors(t_env *e);
void			pipe_mid(t_env *e, int pipe_fd[2]);
void			exec_fork(t_env *e, int i);
void			ft_pipe(t_env *e, int i);
void			pipe_args(t_env *e);
int				check_redirect_args(t_env *e);
void			count_redirect(t_env *e);
void			close_fd(t_env *e);
int				check_redirect(t_env *e);
void			new_args_copy(t_env *e, char **args);
void			redirect(t_env *e);
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
