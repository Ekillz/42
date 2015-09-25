# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/15 14:02:10 by emammadz          #+#    #+#              #
#    Updated: 2015/09/23 17:32:39 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = guess

EXEC2 = train

EXEC3 = graphic

SRCC = main.cpp\

SRCC2 = train.cpp\

SRCC3 = graphic.c\

SRCO = $(SRCC:%.cpp=%.o)

SRCO2 = $(SRCC2:%.cpp=%.o)

SRCO3 = $(SRCC3:%.c=%.o)

FLAG = -Wall -Werror -Wextra

LIB = -framework OpenGL -framework AppKit -L mlx

.PHONY: all fast clean fclean

all: main main2 main3

%.o: %.c
	@echo -n  $< :
	@clang++ -o $@ -c $< $(FLAG)
	@echo

main: $(SRCO)
	@clang++ -o $(EXEC) $(FLAG) $(SRCO)

main2: $(SRCO2)
	@clang++ -o $(EXEC2) $(FLAG) $(SRCO2)

main3:
	@make -C mlx
	@gcc -o $(EXEC3) $(FLAG) graphic.c  mlx/libmlx.a $(LIB)

clean:
	@rm -f $(SRCO) $(SRCO2) $(SRCO3)

fclean: clean
	@rm -f $(SRCO) $(SRCO2) $(SRCO3) $(EXEC) $(EXEC2) $(EXEC3)

re: fclean all
