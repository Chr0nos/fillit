/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 15:12:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define TETRO_MAX 26
# define TETRA_BASE 5
# define TETRA_HEIGH 4
# define TETRA_BLOCS 4
# define BUFF_SIZE TETRA_BASE * TETRA_HEIGH + 1

typedef struct	s_element
{
	char		**data;
	size_t		height;
	size_t		width;
}				t_element;

typedef struct	s_fillit
{
	t_list		*lst;
	size_t		elements_count;
	t_element	*elems;
}				t_fillit;

int				main(int ac, char **av);
int				read_file(const char *file, t_list **lst);
void			tetro_cleaner(char *s);
void			lst_callback(size_t p, size_t len, void *content);
char			**tetro_spliter(char *s);
t_fillit		*preparator(t_list *lst);
int				trouvator(t_list *lst);
void			liberator(t_fillit *x);

#endif
