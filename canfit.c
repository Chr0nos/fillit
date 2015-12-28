/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 13:59:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * ** f = fillit structure
 * ** p = current line
 * ** b = binarized tetromino
 * ** tab = binaries masks table
 * ** return: 1 if the tetro can fit line "p", in other case 0
 * */

int					canfit(t_fillit *f, unsigned int p, unsigned int n,
		unsigned short b)
{
	unsigned char			x;
	unsigned short			mask;

	if (p + f->elems[n].height > f->grid_size)
		return (0);
	x = 16;
	mask = 1;
	while ((x--) && (!(b & mask)))
		mask <<= 1;
	if (x > f->grid_size)
		return (0);
	x = 0;
	mask = 15;
	while (x < 4)
	{
		if ((f->bgrid[p] & (b & mask)) != 0)
			return (0);
		mask <<= 4;
		++x;
	}
	return (1);
}
