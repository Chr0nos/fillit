/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/31 12:26:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						insert_bin(t_fillit *f, t_element *elem, unsigned int n)
{
	const unsigned short	bo = elem->bin;
	size_t					p;
	int						x;

	p = 0;
	while (p + elem->height <= f->grid_size)
	{
		x = canfit(f, p, n);
		f->bgrid[p] &= ((unsigned short)65535) << (16 - f->grid_size);
		if (x > -1)
		{
			ft_putstr("placed at ");
			ft_putnbr(x);
			ft_putchar('\n');
			elem->pos = (unsigned short)((unsigned short)(p) << 8);
			elem->pos |= (unsigned short)x;
			f->bgrid[p] |= (bo & 61440) >> x;
			f->bgrid[p + 1] |= ((bo << 4) & 61440) >> x;
			f->bgrid[p + 2] |= ((bo << 8) & 61440) >> x;
			f->bgrid[p + 3] |= ((bo << 12) & 61440) >> x;
			return (1);
		}
		p++;
	}
	return (0);
}
