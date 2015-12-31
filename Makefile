# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:12:09 by snicolet          #+#    #+#              #
#*   Updated: 2015/12/29 21:57:53 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME=fillit
GCC=clang -Wall -Werror -Wextra -Weverything -fsanitize=address
LIBFT=../libft/
OBJ=main.o \
	read_file.o \
	tetro_info.o \
	preparator.o \
	trouvator.o \
	grid_reset.o \
	displayator.o \
	superdisplayator.o\
	binarizator_of_doom.o \
	removator.o \
	insert.o \
	tetro_checks.o \
	canfit.o

all: libft $(NAME)
$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME) -I $(LIBFT) -L $(LIBFT) -lft
%.o: %.c
	$(GCC) -c -I $(LIBFT) $<
clean:
	rm -f $(OBJ)
fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)
re: fclean libftre all
libft:
	make -C $(LIBFT)
libftre:
	make -C $(LIBFT) re
norminette:
	make -C $(LIBFT) norminette
	norminette *.[ch]

.PHONY: libft libftre clean re fclean
