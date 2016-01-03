/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 11:46:25 by snicolet         ###   ########.fr       */
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
	char			letter;
	unsigned char	height;
	unsigned char	width;
	char			placed;
	unsigned short	pos;
	unsigned short	bin;
	unsigned short	display;
}					t_element;

typedef struct		s_fillit
{
	unsigned short	bgrid[GRID_EDGE];
	unsigned int	elements_count;
	unsigned int	grid_size;
	t_element		*elems;
	char			map[26];
	char			padding[6];
}					t_fillit;

# include "fillit_map.h"

int					main(int ac, char **av);
int					read_file(const char *file, t_list **lst);
t_fillit			*preparator(t_list *lst);
t_fillit			*duplicator(t_fillit *f);
int					trouvator(t_list *lst);
void				grid_reset(t_fillit *x);
void				displayator(t_fillit *x);
unsigned short		binarizator_of_doom(char *s);
int					removator(t_fillit *x, unsigned int n);
unsigned char		tetro_width(unsigned short b);
unsigned char		tetro_height(unsigned short b);
int					insert_bin(t_fillit *f, t_element *elem);
int					check_line(char *buffer, int len);
int					canfit(t_fillit *f, size_t p, t_element *elem);
void				super_display_of_doom(t_fillit *f);

#endif
