/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 14:58:05 by snicolet         ###   ########.fr       */
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

int			canfit(t_fillit *f, size_t p, t_element *elem)
{
	int		x;

	x = 0;
	while ((x = canfit_horizontal(f, p, elem, (size_t)x)) != -1)
	{
		if (canfit_bloc(f, p, elem, (size_t)x))
			return (x);
		if ((unsigned int)(++x) >= f->grid_size)
			return (-1);
	}
	return (-1);
}
