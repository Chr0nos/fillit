/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 13:12:01 by qloubier         ###   ########.fr       */
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

static int	canfit_horizontal(t_fillit *f, t_idx p, t_element *bloc, t_idx x)
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

int			canfit(t_fillit *f, t_idx p, t_element *elem)
{
	int		x;

	x = f->minx[p];
	while ((x = canfit_horizontal(f, p, elem, (t_idx)x)) != -1)
	{
		if (canfit_bloc(f, p, elem, (t_idx)x))
			return (x);
		if ((unsigned int)(++x) >= f->grid_size)
			return (-1);
	}
	return (-1);
}
