/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 15:04:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static int			canfit_height(t_fillit *f, unsigned int p, unsigned int n)
{
	if (p + f->elems[n].height > f->grid_size)
		return (0);
	return (1);
}

static int			canfit_horizontal(t_fillit *f, unsigned int p,
		unsigned short b)
{
	unsigned char	x;
	unsigned short	mask;

	x = 0;
	while (x < 4)
	{
		mask = b & (61440 >> (x * 4));
		if (f->bgrid[p] & mask)
			return (0);
		++x;
	}
	return (1);
}

static int			canfit_vertical(t_fillit *f, unsigned int p,
		unsigned short b)
{
	unsigned short	mask;
	unsigned char	x;

	mask = 7680;
	x = 0;
	while (x < 4)
	{
		mask = b & (7680 >> (x * 4));
		if (f->bgrid[p] & mask)
			return (0);
		x++;
	}
	return (1);
}

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
	if (!canfit_height(f, p, n))
		return (0);
	if (!canfit_horizontal(f, p, b))
		return (0);
	if (!canfit_vertical(f, p, b))
		return (0);
	return (1);
}
