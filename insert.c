/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 14:05:21 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						insert_bin(t_fillit *f, int x, int y, t_element *elem)
{
	const unsigned short	bo = elem->bin;

	if ((size_t)y + elem->height <= f->grid_size)
	{
		x = canfit(f, x, y, elem);
		f->bgrid[y] &= ((unsigned short)65535) << (16 - f->grid_size);
		if (x > -1)
		{
			elem->pos = (unsigned short)((unsigned short)(y) << 8);
			elem->pos |= (unsigned short)x;
			f->bgrid[y] |= (bo & 61440) >> x;
			f->bgrid[y + 1] |= ((bo << 4) & 61440) >> x;
			f->bgrid[y + 2] |= ((bo << 8) & 61440) >> x;
			f->bgrid[y + 3] |= ((bo << 12) & 61440) >> x;
			elem->placed = 1;
			return (1);
		}
	}
	return (0);
}
