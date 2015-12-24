/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/24 15:45:54 by snicolet         ###   ########.fr       */
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
	const unsigned int		gs = f->grid_size;

	x = 4;
	while (x--)
		if ((f->bgrid[p + (x * gs)] & ((b & (tab[x] << (4 * (3  - x)))))) != 0)
			return (0);
	return (1);
}

static int				insert_bin(t_fillit *f, unsigned int n)
{
	unsigned short			b;
	const unsigned short	bo = revbits((unsigned char)f->elems[n].bin);
	unsigned int			p;
	const unsigned int		end = f->grid_size * f->grid_size;
	const unsigned short	bintab[4] = { 15, 240, 3840, 61440 };

	p = 0;
	while (p < end)
	{
		b = bo;
		//while ((!canfit(f, p, b, bintab)) && ((b & 1) == 0))
		//	b >>= 1;
		if (canfit(f, p, b, bintab))
		{
			f->bgrid[p] |= b & bintab[3];
			f->bgrid[p + f->grid_size] |= (b & bintab[2]) << 4;
			f->bgrid[p + (f->grid_size * 2)] |= (b & bintab[1]) << 8;
			f->bgrid[p + (f->grid_size * 3)] |= (b & bintab[0]) << 12;
			return (1);
		}
		p++;
	}
	ft_putendl("failed to place a block");
	return (0);
}

static int				trouvator_engine(t_fillit *x, unsigned int n)
{
	int		ret;

	ret = insert_bin(x, n);
	if (ret == 1)
	{
		if (n + 1 < x->elements_count)
			return (trouvator_engine(x, n + 1));
		else
			return (1);
	}
	ft_putendl("failed to place element");
	return (0);
}

int						trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	trouvator_engine(fillit, 0);
	displayator(fillit);
	liberator(fillit);
	return (0);
}
