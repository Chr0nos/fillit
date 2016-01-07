# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:12:09 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/07 04:01:32 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME=fillit
FLAGS=
CC=clang -Wall -Werror -Wextra -Weverything $(FLAGS)
LIBFT=./libft/
OBJ=main.o \
	read_file.o \
	tetro_info.o \
	preparator.o \
	trouvator.o \
	grid_reset.o \
	superdisplayator.o\
	binarizator_of_doom.o \
	insert.o \
	tetro_checks.o

all: libft $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT) BTREE= GNL=
	$(CC) $(OBJ) -o $(NAME) -I $(LIBFT) -L $(LIBFT) -lft

%.o: %.c
	$(CC) -c -I $(LIBFT) $<

clean:
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)
re: fclean libftre all

libftre:
	make -C $(LIBFT) BTREE= GNL= re

norminette:
	make -C $(LIBFT) norminette
	norminette *.[ch]

.PHONY: libft libftre clean re fclean
