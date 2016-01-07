/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 00:26:20 by snicolet         ###   ########.fr       */
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

typedef unsigned short	t_tetrobloc;
typedef struct			s_element
{
	char				letter;
	unsigned char		height;
	unsigned char		width;
	char				placed;
	unsigned short		pos;
	unsigned short		bin;
	unsigned short		display;
	unsigned short		masks[4];
}						t_element;

typedef struct			s_fillit
{
	unsigned short		bgrid[GRID_EDGE];
	unsigned int		elements_count;
	unsigned int		grid_size;
	t_element			elems[26];
}						t_fillit;

int						main(int ac, char **av);
int						read_file(const char *file, t_list **lst);
t_fillit				*preparator(t_list *lst);
t_fillit				*duplicator(t_fillit *f);
int						trouvator_engine(t_fillit f, unsigned int n,
		unsigned int piece);
int						trouvator(t_list *lst);
void					grid_reset(t_fillit *x);
void					displayator(t_fillit *x);
unsigned short			binarizator_of_doom(char *s);
int						removator(t_fillit *x, t_element *elem);
unsigned char			tetro_width(unsigned short b);
unsigned char			tetro_height(unsigned short b);
int						insert_bin(t_fillit *f, int x, int y, t_element *elem);
int						check_line(char *buffer, int len);
int						canfit(t_fillit *f, int x, int y, t_element *bloc);
int						super_display_of_doom(t_fillit *f);

#endif
