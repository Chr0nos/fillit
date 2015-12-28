/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 22:11:17 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						insert_bin(t_fillit *f, unsigned int n)
{
	unsigned short			b;
	const unsigned short	bo = f->elems[n].bin;
	size_t					p;
	int						x;

	p = 0;
	while (p + f->elems[n].height <= f->grid_size)
	{
		ft_putchar(f->elems[n].letter);
		ft_putchar('\n');
		ft_putbits(&b, sizeof(unsigned short));
		x = canfit(f, p, n);
		if (x > -1)
		{
			ft_putendl("placed");
			f->elems[n].pos = (unsigned short)((unsigned short)(p) << 8);
			f->elems[n].pos |= (unsigned short)x;
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
