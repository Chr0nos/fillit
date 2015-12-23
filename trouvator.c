/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 15:35:39 by snicolet         ###   ########.fr       */
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

static int			insert_bin(t_fillit *f, int n)
{
	unsigned char		b;
	unsigned int		p;
	const unsigned int	end = f->grid_size * f->grid_size;

	b = revbits((unsigned char)f->elems[n].bin);
	p = 0;
	while (p < end)
	{
		if ((f->bgrid[p] & b) == 0)
		{
			f->bgrid[p] = b;
			return (1);
		}
		p++;
	}
	return (0);
}

static int			trouvator_engine(t_fillit *x, int p, int n)
{
	int		ret;

	ret = insert_bin(x, n);
	(void)p;
	(void)ret;
	return (1);
}

int					trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	trouvator_engine(fillit, 0, 0);
	displayator(fillit);
	liberator(fillit);
	return (0);
}
