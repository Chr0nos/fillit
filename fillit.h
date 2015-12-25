/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/25 18:00:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define TETRO_MAX 26
# define TETRA_BASE 5
# define TETRA_HEIGH 4
# define TETRA_BLOCS 4
# define GRID_EDGE 16
# define BUFF_SIZE TETRA_BASE * TETRA_HEIGH + 1

typedef struct		s_element
{
	char			**data;
	char			letter;
	unsigned char	height;
	unsigned char	width;
	unsigned char	pos;
	unsigned short	mask;
	unsigned short	bin;
	long			padding;
}					t_element;

typedef struct		s_fillit
{
	unsigned short	bgrid[GRID_EDGE];
	char			grid[GRID_EDGE][GRID_EDGE];
	unsigned int	elements_count;
	unsigned int	grid_size;
	t_element		*elems;
}					t_fillit;

int					main(int ac, char **av);
int					read_file(const char *file, t_list **lst);
t_fillit			*preparator(t_list *lst);
int					trouvator(t_list *lst);
void				liberator(t_fillit *x);
void				grid_reset(t_fillit *x);
void				displayator(t_fillit *x);
unsigned short		binarizator_of_doom(char *s);
void				removator(t_fillit *x, char letter);
int					tetro_width(t_element *t, int line);
int					insert_bin(t_fillit *f, unsigned int n);

#endif
