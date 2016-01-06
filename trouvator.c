/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 22:47:42 by snicolet         ###   ########.fr       */
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

static int	trouvator_o_matic(t_fillit *f, t_point p, t_element *elem,
		unsigned int n)
{
	while ((p.y < (int)f->grid_size) && (!(p.x = 0)))
	{
		while (p.x < (int)f->grid_size)
		{
			if (insert_bin(f, p.x, p.y, elem) != 0)
			{
				if (trouvator_engine(*f, n + 1, p.y))
					return (1);
				removator(f, elem);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int			trouvator_engine(t_fillit f, unsigned int n, int y)
{
	t_point			p;
	unsigned int	piece;
	t_element		*elem;

	if (n == f.elements_count)
	{
		super_display_of_doom(&f);
		//displayator(&f);
		return (1);
	}
	p.y = y;
	piece = 0;
	while ((piece < f.elements_count) && (elem = &f.elems[piece]))
	{
		if ((!elem->placed) && (trouvator_o_matic(&f, p, elem, n) == 1))
			return (1);
		p.y = 0;
		p.x = 0;
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
	while ((trouvator_engine(*fillit, 0, 0) == 0) && (grid_extend(fillit)))
		(void)fillit;
	free(fillit);
	return (0);
}
