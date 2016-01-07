/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 14:22:23 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		canfit(t_fillit *f, int x, int y, t_element *bloc)
{
	register const unsigned short	*m = bloc->masks;

	if (((bloc->width + x) <= f->grid_size) &&
			!((m[0] >> x) & f->bgrid[y]) &&
			!((m[1] >> x) & f->bgrid[y + 1]) &&
			!((m[2] >> x) & f->bgrid[y + 2]) &&
			!((m[3] >> x) & f->bgrid[y + 3]))
		return (1);
	return (0);
}

int		insert_bin(t_fillit *f, int x, int y, t_element *elem)
{
	register unsigned short	*m;

	if (!canfit(f, x, y, elem))
		return (0);
	m = elem->masks;
	elem->pos = (unsigned short)((unsigned short)(y) << 8);
	elem->pos |= (unsigned short)x;
	f->bgrid[y] |= m[0] >> x;
	f->bgrid[y + 1] |= m[1] >> x;
	f->bgrid[y + 2] |= m[2] >> x;
	f->bgrid[y + 3] |= m[3] >> x;
	elem->placed = 1;
	return (1);
}

int		removator(t_fillit *f, t_element *elem)
{
	const register unsigned short	b = elem->bin;
	const register unsigned char	p = elem->pos >> 8;
	const register unsigned char	x = (unsigned char)(elem->pos & 255);

	f->bgrid[p] ^= (b & 61440) >> x;
	f->bgrid[p + 1] ^= ((b << 4) & 61440) >> x;
	f->bgrid[p + 2] ^= ((b << 8) & 61440) >> x;
	f->bgrid[p + 3] ^= ((b << 12) & 61440) >> x;
	elem->placed = 0;
	return (0);
}
