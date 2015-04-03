# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 19:06:16 by emammadz          #+#    #+#              #
#    Updated: 2015/03/25 17:18:30 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = serveur

CLIENT = client

SRCC =	server.c\
		server_shell.c\
		fork.c\
		built_in.c\
		built_in2.c\
		serv_erreur.c\
		send_file.c\
		norme.c\
		exec_cd.c\

SRCC2 = client.c\
		send_file.c\
		client_shell.c\
		built_in2.c\
		client_erreur.c\
		local_conditions.c\
		norme.c\
		signal.c\

SRCO = $(SRCC:%.c=%.o)

SRCO2 = $(SRCC2:%.c=%.o)

FLAG = -Wall -Werror -Wextra

.PHONY: all serveur client fast clean fclean

all: lib serveur client

%.o: %.c
	@echo -n  $< :
	@gcc -o $@ -c $< $(FLAG)
	@echo

lib:
	@make -C libft

serveur: $(SRCO)
	@gcc $(FLAG) -o $(EXEC) $(SRCO) libft/libft.a

client: $(SRCO2)
	@gcc $(FLAG) -o $(CLIENT) $(SRCO2) libft/libft.a

fast:
	@gcc $(FLAG) -o $(EXEC) $(SRCC) libft/libft.a
	@gcc $(FLAG) -o $(CLIENT) $(SRCC2) libft/libft.a

clean:
	@cd ./libft && make clean && cd ..
	@rm -f $(SRCO) $(SRCO2)

fclean: clean
	@cd ./libft && make fclean && cd ..
	@rm -f $(EXEC) $(CLIENT)

re: fclean all
	@cd ./libft && make re && cd ..
