/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 22:13:09 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	canfit_bloc(t_fillit *f, size_t p, t_element *bloc, int x)
{
	unsigned short	mask;

	mask = bloc->bin;
	if(((bloc->height + p) <= f->grid_size) &&
		!((((mask << 4) & 61440) >> x) & f->bgrid[p + 1]) && 
		!((((mask << 8) & 61440) >> x) & f->bgrid[p + 2]) &&
		!((((mask << 12) & 61440) >> x) & f->bgrid[p + 3]))
		return (1);
	return (0);
}

static int	canfit_horizontal(t_fillit *f, size_t p, t_element *bloc, size_t x)
{
	unsigned short	mask;

	mask = (bloc->bin & 61440) >> x;
	while ((mask & f->bgrid[p]) && (x++ < (f->grid_size - bloc->width)))
		mask >>= 1;
	if ((x < (f->grid_size - bloc->width)))
		return ((int)x);
	return (-1);
}

/*
 * ** f = fillit structure
 * ** p = current line
 * ** b = binarized tetromino
 * ** tab = binaries masks table
 * ** return: 1 if the tetro can fit line "p", in other case 0
 * */

int			canfit(t_fillit *f, size_t p, unsigned int n)
{
	int		x;

	x = 0;
	while ((x = canfit_horizontal(f, p, f->elems + n, (size_t)x)) != -1)
	{
		if (canfit_bloc(f, p, f->elems + n, x))
			return (x);
		++x;
	}
	return (-1);
}
