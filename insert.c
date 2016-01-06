/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 19:48:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		insert_bin(t_fillit *f, int x, int y, t_element *elem)
{
	const unsigned short	*m = elem->masks;

	if (((size_t)y + elem->height <= f->grid_size) && (canfit(f, x, y, elem)))
	{
		elem->pos = (unsigned short)((unsigned short)(y) << 8);
		elem->pos |= (unsigned short)x;
		f->bgrid[y] |= m[0] >> x;
		f->bgrid[y + 1] |= m[1] >> x;
		f->bgrid[y + 2] |= m[2] >> x;
		f->bgrid[y + 3] |= m[3] >> x;
		elem->placed = 1;
		return (1);
	}
	return (0);
}
