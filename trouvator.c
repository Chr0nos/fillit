/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 17:55:30 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		insert(t_fillit *f, int p, int n)
{
	char		*g;
	char		c;
	int			x;
	int			y;
	const int	gs = (int)f->grid_size;

	x = 0;
	while ((x <= f->elems[n].height) && (!(y = 0)))
	{
		while (y < f->elems[n].width)
		{
			g = &(f->grid[(p / gs) + x][(p % gs) + y]);
			c = f->elems[n].data[x][y++];
			if (c == '.')
				;
			else if (*g != '.')
				return (0);
			else
				*g = c;
		}
		++x;
	}
	return (1);
}

static int		trouvator_engine(t_fillit *x, int p, int n)
{
	int		ret;

	ret = insert(x, p, n);
	if (!ret)
	{
		removator(x, (char)x->elems[n].letter);
		return (0);
	}
	else if (n + 1 < (int)x->elements_count)
		return (trouvator_engine(x, p + x->elems[n].width - 1, n + 1));
	return (1);
}

int				trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	if (!fillit)
		return (-1);
	trouvator_engine(fillit, 0, 0);
	displayator(fillit);
	liberator(fillit);
	return (0);
}
