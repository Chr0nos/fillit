/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 21:54:53 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	movebits(t_fillit *f, unsigned int p, unsigned int n,
		unsigned short b)
{
	while ((!canfit(f, p, n, b)) && ((b & 30) == 0))
	{
		b >>= 1;
		//ft_putbits(&b, sizeof(unsigned short));
	}
	return (b);
}

int						insert_bin(t_fillit *f, unsigned int n)
{
	unsigned short			b;
	const unsigned short	bo = f->elems[n].bin;
	size_t					p;
	int						x;
	const unsigned short	bintab[4] = { 61440, 3840, 240, 15 };

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
			(unsigned char *)(&(f->elems[n].pos))[0] = (unsigned char)p;
			(unsigned char *)(&(f->elems[n].pos))[1] = (unsigned char)x;
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
