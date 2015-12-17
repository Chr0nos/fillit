/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:28:25 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 22:55:29 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	is_empty_column(t_fillit *x, const size_t col)
{
	size_t		p;

	p = 0;
	while (p < x->grid_size)
		if (x->grid[p++][col] != '.')
			return (0);
	return (1);
}

unsigned int	mergeator(t_fillit *x, unsigned short tetro_id)
{
	char			**tab;
	char			*s;
	unsigned short	l;
	unsigned short	c;

	tab = x->elems[tetro_id].data;
	l = 0;
	while (l < x->height)
	{
		s = tab[l++];
		while (x->grid[line][col] == '.')
		{
			x->grid[line][col] = *(s++);
			col++;
		}
		if (c != col)
			return (0);
	}
	return (1);
}
