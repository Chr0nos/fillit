/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 15:55:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned char	revbits(unsigned char b)
{
	unsigned char	x;
	int				p;

	x = 0;
	p = 0;
	while (p < 8)
	{
		x |= ((b >> p) & 1) << (7 - p);
		++p;
	}
	return (x);
}

static int			insert_bin(t_fillit *f, unsigned int n)
{
	unsigned char		b;
	const unsigned char	bo = revbits((unsigned char)f->elems[n].bin);
	unsigned int		p;
	const unsigned int	end = f->grid_size * f->grid_size;

	b = bo;
	p = 0;
	while (p < end)
	{
		while (((f->bgrid[p] & b) != 0) && ((b & 1) == 0))
			b >>= 1;
		if ((f->bgrid[p] & b) == 0)
		{
			f->bgrid[p] |= b;
			return (1);
		}
		b = bo;
		p++;
	}
	return (0);
}

static int			trouvator_engine(t_fillit *x, unsigned int n)
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
	else
		return (0);
}

int					trouvator(t_list *lst)
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
