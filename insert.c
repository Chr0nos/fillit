/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/28 15:41:27 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** revert bits order
*/

static unsigned short	revbits(unsigned short b)
{
	unsigned short	x;
	int				p;

	p = 15;
	x = (unsigned short)((b & 1) << 15);
	while ((b >>= 1))
		x |= (unsigned short)((b & 1) << (--p));
	return (x);
}

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
	const unsigned short	bo = revbits(f->elems[n].bin);
	unsigned int			p;
	unsigned int			x;
	const unsigned short	bintab[4] = { 61440, 3840, 240, 15 };

	p = 0;
	while (p < f->grid_size)
	{
		ft_putchar(f->elems[n].letter);
		ft_putchar('\n');
		ft_putbits(&b, sizeof(unsigned short));
		b = movebits(f, p, n, bo);
		b = bo;
		if ((canfit(f, p, n, b)) && (x = 4))
		{
			ft_putendl("placed");
			f->elems[n].pos = (unsigned short)p;
			f->elems[n].mask = b;
			while (x--)
				f->bgrid[p + x] |= (b & bintab[x]) << (4 * x);
			return (1);
		}
		p++;
	}
	return (0);
}
