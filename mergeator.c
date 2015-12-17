/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:28:25 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 17:46:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	mergeator(t_fillit *x, unsigned short line,
		unsigned short col, unsigned short tetro_id)
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
