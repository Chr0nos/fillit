/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canfit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 13:59:10 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 18:04:10 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			canfit(t_fillit *f, int x, int y, t_element *bloc)
{
	const unsigned short	mask = bloc->bin;

	if (((bloc->height + y) <= (unsigned char)f->grid_size) &&
			((bloc->width + x) <= (unsigned char)f->grid_size) &&
			!(((mask & 61440) >> x) & f->bgrid[y]) &&
			!((((mask << 4) & 61440) >> x) & f->bgrid[y + 1]) &&
			!((((mask << 8) & 61440) >> x) & f->bgrid[y + 2]) &&
			!((((mask << 12) & 61440) >> x) & f->bgrid[y + 3]))
		return (x);
	return (-1);
}
