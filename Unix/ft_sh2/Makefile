# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 14:40:27 by emammadz          #+#    #+#              #
#    Updated: 2015/03/10 19:36:45 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_minishell2

NAME = lib.a

SRCC =	main.c\
		shell.c\
		get_env.c\
		get_env2.c\
		security.c\
		conditions.c\
		conditions2.c\
		conditions3.c\
		redirect.c\
		redirect2.c\
		manip_fd.c\
		pipe.c\
		pipe2.c\
		error_pipe_redirec.c\
		point_vir.c\
		double_left.c\
		signal.c\
		shell2.c\
		ft_pipe_dup.c\
		pipe3.c\
		manip_fd2.c\
		error_pipe_redirect2.c\
		main_conditions2.c\
		conditions_env.c\

SRCO = $(SRCC:%.c=%.o)

FLAG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@cd ./libft && make && cd ..
	@gcc $(FLAG) $(SRCC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@gcc -o $(EXEC) -Wall -Werror -Wextra $(NAME) libft/libft.a

fast:
	@gcc -o $(EXEC) -Wall -Wextra -Werror $(SRCC) libft/libft.a

clean:
	@cd ./libft && make clean && cd ..
	@rm -f $(SRCO)

fclean: clean
	@cd ./libft && make fclean && cd ..
	@rm -f $(NAME) $(EXEC)

re: fclean all
	@cd ./libft && make re && cd ..
