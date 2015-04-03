# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 16:58:01 by emammadz          #+#    #+#              #
#    Updated: 2015/02/27 15:26:21 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_minishell1

NAME = lib.a

SRCC =	main.c\
		shell.c\
		get_env.c\
		get_env2.c\
		security.c\
		conditions.c\
		conditions2.c\
		conditions3.c\

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
