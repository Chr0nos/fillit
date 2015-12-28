/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 09:55:27 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 13:09:46 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_MAP_H
# define FILLIT_MAP_H

#include "fillit.h"

typedef unsigned short tetrobloc;

typedef struct		s_point
{
	unsigned char	x;
	unsigned char	y;
}					t_point;

typedef struct		s_grid_cell
{
	tetrobloc		bin_cell;
	s_grid_cell		*left;
	s_grid_cell		*right;
	s_grid_cell		*top;
	s_grid_cell		*bottom;
	t_point			coord;

}					t_gcell;

tetrobloc			move_bloc(tetrobloc bloc);
int					is_colliding(t_gcell *grid, tetrobloc bloc, t_point coord);
t_point				get_first_position(t_gcell *grid, t_element);

#endif
