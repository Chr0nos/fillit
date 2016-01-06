/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 13:58:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	canfit_bloc(t_fillit *f, int x, int y, t_element *bloc)
{
	unsigned short	mask;

	mask = bloc->bin;
	if ((((int)bloc->height + y) <= (int)f->grid_size) &&
		(((int)bloc->width + x) <= (int)f->grid_size) &&
		!(((mask & 61440) >> x) & f->bgrid[y]) &&
		!((((mask << 4) & 61440) >> x) & f->bgrid[y + 1]) &&
		!((((mask << 8) & 61440) >> x) & f->bgrid[y + 2]) &&
		!((((mask << 12) & 61440) >> x) & f->bgrid[y + 3]))
		return (1);
	return (0);
}

static int	canfit_horizontal(t_fillit *f, int x, int y, t_element *bloc)
{
	unsigned short	mask;

	mask = (bloc->bin & 61440) >> x;
	if (mask & f->bgrid[y])
	{
		mask >>= 1;
		if (((++x) + bloc->width) > (int)f->grid_size)
			return (-1);
	}
	return ((int)x);
}

int			canfit(t_fillit *f, int x, int y, t_element *elem)
{
	if ((x = canfit_horizontal(f, x, y, elem)) != -1)
	{
		if (canfit_bloc(f, x, y, elem))
			return (x);
		if (++x >= (int)f->grid_size)
			return (-1);
	}
	return (-1);
}
