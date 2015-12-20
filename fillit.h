/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 15:35:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define TETRO_MAX 26
# define TETRA_BASE 5
# define TETRA_HEIGH 4
# define TETRA_BLOCS 4
# define GRID_EDGE 24
# define BUFF_SIZE TETRA_BASE * TETRA_HEIGH + 1

typedef struct		s_element
{
	char			**data;
	unsigned char	height;
	unsigned char	width;
	unsigned short	bin;
	int				letter;
}					t_element;

typedef struct		s_fillit
{
	char			grid[GRID_EDGE][GRID_EDGE];
	size_t			elements_count;
	size_t			grid_size;
	t_list			*lst;
	t_element		*elems;
}					t_fillit;

int					main(int ac, char **av);
int					read_file(const char *file, t_list **lst);
void				tetro_cleaner(char *s);
void				lst_callback(size_t p, size_t len, void *content);
t_fillit			*preparator(t_list *lst);
int					trouvator(t_list *lst);
void				liberator(t_fillit *x);
void				grid_reset(t_fillit *x);
void				displayator(t_fillit *x);
unsigned int		mergeator(t_fillit *x, unsigned short tetro_id);
unsigned short		binarizator_of_doom(t_element *t);
void				removator(t_fillit *x, char letter);

#endif
