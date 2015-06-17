# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 13:21:52 by emammadz          #+#    #+#              #
#    Updated: 2015/06/15 20:09:19 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = Hipcontact

SRCC = main.cpp\
	   Contact.class.cpp\

SRCO = $(SRCC:%.cpp=%.o)

FLAG = -Wall -Werror -Wextra

.PHONY: all fast clean fclean

all: main

%.o: %.c
	@echo -n  $< :
	@clang++ -o $@ -c $< $(FLAG)
	@echo

main: $(SRCO)
	@clang++ -o $(EXEC) $(FLAG) $(SRCO)

fast: $(SRCO)
	@clang++ $(FLAG) -o $(EXEC) $(SRCO)

clean:
	@rm -f $(SRCO)

fclean: clean
	@rm -f $(SRCO) $(EXEC)

re: fclean all
