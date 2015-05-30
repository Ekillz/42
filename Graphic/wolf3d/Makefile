# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 16:08:12 by emammadz          #+#    #+#              #
#    Updated: 2015/05/30 15:50:18 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = wolf3d

NAME = lib.a

LIB = -framework OpenGL -framework AppKit  -L mlx

SRCC =	main.c\
		errors.c\
		draw_img.c\
		map.c\
		raycaster.c\
		minimap.c\
		raycasting_sub_functions.c\
		raycasting_colors.c\
		key_hooks.c\

SRCO = $(SRCC:%.c=%.o)

FLAG = -Wall -Werror -Wextra

.PHONY: all fast clean fclean

all: wolf3d

%.o: %.c
	@echo -n  $< :
	@gcc -o $@ -c $< $(FLAG)
	@echo

wolf3d: $(SRCO)
	@make -C mlx
	@make -C libft
	@gcc -o $(EXEC) $(FLAG) $(SRCO) mlx/libmlx.a libft/libft.a $(LIB)

fast: $(SRCO)
	@gcc $(FLAG) -o $(EXEC) $(SRCO) libft/libft.a mlx/libmlx.a $(LIB)

clean:
	@make clean -C libft
	@rm -f $(SRCO)

fclean: clean
	@make fclean -C libft
	@rm -f $(SRCO) $(EXEC)

re: fclean all
	@make re -C libft
