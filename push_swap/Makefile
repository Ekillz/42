# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/06 13:34:24 by emammadz          #+#    #+#              #
#    Updated: 2015/04/03 17:41:27 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = push_swap

NAME = pushswap.a

SRCC =	main.c\
		errors.c\
		ft_push_swap.c\
		push_tools.c\
		push_tools2.c\
		push_tools3.c\
		push_tools4.c\
		show_moves.c\

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
