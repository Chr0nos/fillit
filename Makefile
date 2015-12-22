# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:12:09 by snicolet          #+#    #+#              #
#    Updated: 2015/12/22 21:45:28 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
GCC=clang -Wall -Werror -Wextra -Weverything -fsanitize=address
LIBFT=../libft/
OBJ=main.o \
	read_file.o \
	tetro_info.o \
	preparator.o \
	liberator.o \
	trouvator.o \
	grid_reset.o \
	displayator.o \
	binarizator_of_doom.o \
	removator.o

all: $(NAME)
$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME) -I $(LIBFT) -L $(LIBFT) -lft
%.o: %.c
	$(GCC) -c -I $(LIBFT) $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
