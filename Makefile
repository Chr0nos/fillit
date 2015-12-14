# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 12:12:09 by snicolet          #+#    #+#              #
#    Updated: 2015/12/11 12:33:08 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
GCC=clang -Wall -Werror -Wextra
LIBFT=../libft/
OBJ=main.o

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
