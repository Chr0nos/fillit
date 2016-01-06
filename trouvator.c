/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 14:32:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void	reset_placed(t_fillit *x)
{
	unsigned int	p;

	p = x->elements_count;
	while (p--)
		x->elems[p].placed = 0;
}

static int	grid_extend(t_fillit *x)
{
	if (x->grid_size >= 16)
		return (0);
	grid_reset(x);
	reset_placed(x);
	x->grid_size += 1;
	ft_printf("setting grid size to %d\n", x->grid_size);
	return (1);
}

static int	trouvator_o_matic(t_fillit *f, t_point *p, unsigned int piece,
		unsigned int n)
{
	if ((!f->elems[piece].placed) &&
			(insert_bin(f, p->x, p->y, &f->elems[piece]) != 0))
	{
		if (trouvator_engine(*f, n + 1))
			return (1);
		removator(f, &f->elems[piece]);
	}
	return (0);
}

int			trouvator_engine(t_fillit f, unsigned int n)
{
	t_point			p;
	unsigned int	piece;

	if (n == f.elements_count)
	{
		displayator(&f);
		return (1);
	}
	piece = 0;
	while (piece < f.elements_count)
	{
		p.y = 0;
		while ((p.y < (int)f.grid_size) && (!(p.x = 0)))
		{
			while (p.x < (int)f.grid_size)
			{
				if (trouvator_o_matic(&f, &p, piece, n) == 1)
					return (1);
				p.x++;
			}
			p.y++;
		}
		piece++;
	}
	return (0);
}

int			trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	while ((trouvator_engine(*fillit, 0) == 0) && (grid_extend(fillit)))
		(void)fillit;
	free(fillit);
	return (0);
}
