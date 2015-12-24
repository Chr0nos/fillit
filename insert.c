/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/24 17:36:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	revbits(unsigned short b)
{
	unsigned short	x;
	int				p;

	x = 0;
	p = 0;
	while (p < 16)
	{
		x |= ((b >> p) & 1) << (15 - p);
		++p;
	}
	return (x);
}

static int				canfit(t_fillit *f, unsigned int p, unsigned short b)
{
	unsigned char			x;
	const unsigned int		gs = f->grid_size;

	x = 0;
	while (x < 4)
	{
		if ((f->bgrid[p + (x * gs)] & (b << (4 * x))) != 0)
			return (0);
		++x;
	}
	return (1);
}

int						insert_bin(t_fillit *f, unsigned int n)
{
	unsigned short			b;
	const unsigned short	bo = revbits((unsigned char)f->elems[n].bin);
	unsigned int			p;
	const unsigned int		end = f->grid_size * f->grid_size;
	const unsigned short	bintab[4] = { 61440, 3840, 240, 15 };

	p = 0;
	while (p < end)
	{
		b = bo;
		ft_putchar(f->elems[n].letter);
		ft_putchar('\n');
		ft_putbits(&b, sizeof(unsigned short));
		while ((!canfit(f, p, b)) && ((b & 240) == 0))
		{
			b >>= 4;
			ft_putbits(&b, sizeof(unsigned short));
		}
		if (canfit(f, p, b))
		{
			ft_putendl("placed");
			f->bgrid[p] |= b & bintab[0];
			f->bgrid[p + f->grid_size] |= (b & bintab[1]) << 4;
			f->bgrid[p + (f->grid_size * 2)] |= (b & bintab[2]) << 8;
			f->bgrid[p + (f->grid_size * 3)] |= (b & bintab[3]) << 12;
			return (1);
		}
		p++;
	}
	return (0);
}

