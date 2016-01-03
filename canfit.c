/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 16:05:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	canfit_bloc(t_fillit *f, size_t p, t_element *bloc, size_t x)
{
	unsigned short	mask;

	mask = bloc->bin;
	if (((bloc->height + p) <= f->grid_size) &&
		((bloc->width + x) <= f->grid_size) &&
		!(((mask & 61440) >> x) & f->bgrid[p]) &&
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
	while (mask & f->bgrid[p])
	{
		mask >>= 1;
		if (((++x) + bloc->width) > f->grid_size)
			return (-1);
	}
	return ((int)x);
}

/*
 * ** f = fillit structure
 * ** p = current line
 * ** b = binarized tetromino
 * ** tab = binaries masks table
 * ** return: 1 if the tetro can fit line "p", in other case 0
 * */

int			canfit(t_fillit *f, size_t p, t_element *elem)
{
	int		x;

	//ft_putbits(&(f->elems[n].bin), sizeof(unsigned short));
	x = 0;
	while ((x = canfit_horizontal(f, p, elem, (size_t)x)) != -1)
	{
		ft_putnbr(x);
		ft_putstr(" seams good\n");
		if (canfit_bloc(f, p, elem, (size_t)x))
			return (x);
		if ((unsigned int)(++x) >= f->grid_size)
			return (-1);
	}
	return (-1);
}
