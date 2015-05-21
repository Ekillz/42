# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/28 17:58:51 by emammadz          #+#    #+#              #
#    Updated: 2015/03/26 16:07:37 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fractol

NAME = fractol.a

MLX_FLAG = -L/usr/X11/lib -lmlx -lXext -lX11

SRCC =	main.c\
		mandelbrot.c\
		key.c\
		key2.c\
		error.c\
		julia.c\
		key_hook.c\
		declarations.c\
		burning_ship.c\

SRCO = $(SRCC:%.c=%.o)

LIB = -framework OpenGL -framework AppKit  -L mlx

FLAG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@cd ./libft && make && cd ..
	@gcc $(FLAG) $(SRCC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@make -C mlx
	@gcc -o $(EXEC) -Wall -Werror -Wextra $(NAME) mlx/libmlx.a libft/libft.a $(LIB)

fast:
	@gcc -o $(EXEC) -Wall -Wextra -Werror $(SRCC) libft/libft.a $(MLX_FLAG)

clean:
	@cd ./libft && make clean && cd ..
	@rm -f $(SRCO)

fclean: clean
	@cd ./libft && make fclean && cd ..
	@rm -f $(NAME) $(EXEC)

re: fclean all
	@cd ./libft && make re && cd ..
