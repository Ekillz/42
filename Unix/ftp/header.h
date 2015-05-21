/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:11 by emammadz          #+#    #+#             */
/*   Updated: 2015/03/25 14:44:10 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/mman.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <netdb.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "libft/libft.h"
# include <sys/param.h>

typedef struct	s_env
{
	char	*line;
	int		ret;
	char	**args;
	char	**environ;
	char	*first_pwd;
	char	*home;
	int		pwd_nb;
	int		send;
	int		root;
	int		t;
}				t_env;

typedef struct	s_server
{
	int		sock_1;
	int		sock;
	int		cs;
	int		save;
	int		save2;
	int		cd_error;
	int		port;
}				t_server;

void			env_erreur(void);
void			ctrl_c(int sig);
void			shell_success(t_env *e, t_server *serv);
void			exec_cd2(t_env *e, t_server *serv);
void			client_shell(t_env *e, char *home, int sock);
void			get_put_msg(int sock, char **args, int which);
void			send_file2(int sock, int which);
void			fork_message(int sock);
int				local_check_cd(char *line);
void			local_cd(char *line, char *home);
void			local_fork(char *line);
void			local_pwd(void);
int				local_conditions(char *line, char *home);
void			shell(t_server *shell, t_env *e);
void			success_msg(t_server *serv, int which);
void			server_msg(int sock);
void			ft_dup(t_server *serv, int which);
void			client_main_conditions(t_env *e, char *line, int sock);
void			client_quit(int sock);
void			client_error(int ac);
void			get_file(int sock, char *name, int which);
void			send_file(int sock, char *name, int which);
void			ftp_erreur(char *buf, t_server *serv);
int				check_serveur_root_erreur(char *av, int ac);
int				path_permission(int pwd_nb);
int				first_pwd_count(char *pwd);
void			cd_erreur(char *line, t_server *serv);
void			exec_cd(t_env *e, char *line, t_server *serv);
int				check_cd(char **args, t_server *serv);
void			declarations_server(t_env *e);
void			server_argument_error(int ac, int which);
void			create_port_socket(t_server *serv, char *av);
void			main_conditions(t_env *e, char *buf, int sock, t_server *serv);
void			show_pwd(t_server *serv);
void			ft_fork(t_env *e, t_server *serv);
int				search_name_index(char *name, t_env *e);
int				create_server(int port);
int				create_client(char *addr, int port);
#endif
