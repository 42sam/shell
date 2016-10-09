# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 22:36:30 by ssachet           #+#    #+#              #
#    Updated: 2015/04/03 16:16:14 by ssachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIB = libft.a
CFLAGS = -Wall -Wextra -Werror

GET_FILES = get_next_line.c
GET_PATH = ./get_next_line/
GET = $(addprefix $(GET_PATH), $(GET_FILES))

PRINT_FILES = ft_printf.c cast_str_cox.c cast_to_numeric.c cast_to_wc.c conversion_type.c add.c add_format.c apply.c apply_left_width.c apply_width.c assistant.c is.c  to_s_a_c.c to_x_to_o.c ft_sprintf.c colors.c
PRINT_PATH = ./printf/
PRINT = $(addprefix $(PRINT_PATH), $(PRINT_FILES))

TERM_FILES = term_init.c term_print.c term_underline.c term_highlight.c term_move.c term_assistant.c term_clear.c term_time.c loading_attributes.c cursor.c term_del.c switch_to_canonical.c
TERM_PATH = ./term/
TERM = $(addprefix $(TERM_PATH), $(TERM_FILES))

LIST_FILES = ft_lstadd.c ft_lstcpy.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_lstprint.c ft_lstsplit.c get_value.c lst_del_node.c lst_to_array.c lstcpy.c new_dict.c push.c set_value.c
LIST_PATH= ./list/
LIST = $(addprefix $(LIST_PATH), $(LIST_FILES))

MEM_FILES = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
MEM_PATH = ./mem/
MEM = $(addprefix $(MEM_PATH), $(MEM_FILES))

STR_FILES= case_down.c case_up.c char_index.c char_to_str.c ft_has_char.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_ltrim.c ft_putarray.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_rtrim.c ft_stpcpy.c ft_strcat.c ft_strchr.c ft_strchr_rev.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_uppercase.c hard_trim.c has_char.c has_char_at_end.c has_char_rev.c is_digitstr.c is_dot.c is_lowercase.c is_space_str.c is_uppercase.c makestr.c pad_left.c pad_right.c strstrcount.c tab_to_space.c tr.c trim_all.c
STR_PATH = ./str/
STR = $(addprefix $(STR_PATH), $(STR_FILES))

UNIX_FILES = file_exists.c get_current_dir.c is_directory.c is_file.c
UNIX_PATH = ./unix/
UNIX = $(addprefix $(UNIX_PATH), $(UNIX_FILES))

GENERAL_FILES = free_and_null.c tablen.c
GENERAL_PATH = ./general/
GENERAL = $(addprefix $(GENERAL_PATH), $(GENERAL_FILES))

INT_FILES = ft_atoi.c ft_itoa.c ft_ltoa.c tab_del_i.c
INT_PATH = ./int/
INT = $(addprefix $(INT_PATH), $(INT_FILES))

H = libft.h printf/ft_printf.h get_next_line/get_next_line.h term/termlib.h

O = $(LIST_FILES:.c=.o) $(STR_FILES:.c=.o) $(UNIX_FILES:.c=.o) $(GENERAL_FILES:.c=.o)\
	$(INT_FILES:.c=.o) $(MEM_FILES:.c=.o) $(PRINT_FILES:.c=.o) $(GET_FILES:.c=.o) $(TERM_FILES:.c=.o)

all:
	$(CC) -c $(CFLAGS) $(LIST) $(STR) $(UNIX) $(GENERAL) $(INT) $(MEM) $(PRINT) $(GET) $(TERM)
	ar rc $(LIB) $(O) $(H)
	ranlib $(LIB)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(LIB)

re: fclean all

.PHONY: all libftprintf.a mainprintf clean fclean
