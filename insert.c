/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:33:28 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 12:21:47 by snicolet         ###   ########.fr       */
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

static int				canfit(t_fillit *f, unsigned int p, unsigned short b,
		const unsigned short tab[4])
{
	unsigned char			x;
	unsigned short			mask;

	x = 0;
	while (x < 4)
	{
		mask = (b << (4 * x)) & tab[x];
		if ((f->bgrid[p] & mask) != 0)
			return (0);
		++x;
	}
	return (1);
}

static unsigned short	movebits(t_fillit *f, unsigned int p, unsigned short b,
		const unsigned short bintab[4])
{
	//while ((!canfit(f, p, b, bintab)) && ((b & 15) == 0))
	//{
	//	b >>= 1;
	//	ft_putbits(&b, sizeof(unsigned short));
	//}
	(void)f;
	(void)p;
	(void)bintab;
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
		b = movebits(f, p, bo, bintab);
		if ((canfit(f, p, b, bintab)) && (x = 4))
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

