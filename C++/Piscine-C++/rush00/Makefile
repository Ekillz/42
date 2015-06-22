# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaueur <chaueur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 10:20:20 by chaueur           #+#    #+#              #
#    Updated: 2015/06/21 21:43:12 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FLAG = -Wall -Wextra -Werror -c

LIB = -lncurses

INC = -I ./inc
SRC = src/data.cpp \
	  src/main.cpp \
	  src/screen.cpp \
	  src/actions.cpp \
	  src/nsFunctions.cpp \

SRC2 = src/class/Player.class.cpp \
	   src/class/Vessel.class.cpp \
	   src/class/Enemy.class.cpp \
	   src/class/Object.class.cpp

SRC0 = data.o \
	  main.o \
	  screen.o \
	  actions.o \
	  nsFunctions.o \
	  Player.class.o \
	  Vessel.class.o \
	  Enemy.class.o \
	  Object.class.o

all: $(NAME)

$(NAME):
	clang++ $(FLAG) $(SRC) $(SRC2) $(INC)
	clang++ -o $(NAME) $(SRC0) $(SRC02) $(LIB)

clean:
	rm -f $(SRC0)

fclean: clean
	rm -f $(NAME)

re: fclean all
