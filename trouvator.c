/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 22:30:31 by snicolet         ###   ########.fr       */
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

static int	trouvator_engine(t_fillit f, unsigned int n)
{
	int				x;
	int				y;
	unsigned int	piece;

	if (n == f.elements_count)
	{
		displayator(&f);
		return (1);
	}
	piece = 0;
	while (piece < f.elements_count)
	{
		y = 0;
		while ((y < (int)f.grid_size) && (!(x = 0)))
		{
			while (x < (int)f.grid_size)
			{
				if ((!f.elems[piece].placed) &&
						(insert_bin(&f, x, y, &f.elems[piece]) != 0))
				{
					if (trouvator_engine(f, n + 1))
						return (1);
					removator(&f, &f.elems[piece]);
				}
				x++;
			}
			y++;
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
