# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 22:35:15 by ssachet           #+#    #+#              #
#    Updated: 2015/04/03 16:49:47 by ssachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = ft_minishell1
MAIN = myshell.c
LIB = -Llibft -lft -I libft -I libft/get_next_line -I libft/printf
TERMLIB = -ltermcap

SRC= myshell.c assistant.c built_in.c env.c exec.c print.c signals.c history_alias.c init.c strstr_insert.c key_process.c setenv.c print_history.c print_command_line.c autocompletion.c from_line_to_exec.c child_signals.c autocompletion2.c
H = myshell.h libft/libft.h libft/get_next_line/get_next_line.h libft/printf/ft_printf.h libft/term/termlib.h
O = $(SRC:.c=.o)

.PHONY: all allo clean fclean re

all: $(EXEC)

%.o: %.c $(H)
	$(CC) $(CFLAGS) -c $<

$(EXEC): $(O)
	make -C libft/
	$(CC) -o $(EXEC) $(O) $(LIB) $(TERMLIB)

clean:
	rm -rf $(O)
	make clean -C libft

fclean: clean
	rm -rf $(EXEC)
	make fclean -C libft

re: fclean all

test:
	$(CC) -c $(SRC)
	$(CC) $(O) $(H) $(LIB) $(TERMLIB)
	#$(CC) $(CFLAGS) -c $(SRC)
