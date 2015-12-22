/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/22 22:01:42 by snicolet         ###   ########.fr       */
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
	y = 0;
	while ((x < f->elems[n].height) && (!(y = 0)))
	{
		if ((p % gs) + tetro_width(&f->elems[n], x) > gs)
			return (-1);
		while (y < f->elems[n].width)
		{
			g = &(f->grid[(p / gs) + x][(p % gs) + y]);
			c = f->elems[n].data[x][y++];
			if (*g != '.')
				return (0);
			else if (c != '.')
				*g = (char)f->elems[n].letter;
		}
		++x;
	}
	return (p + (x * y));
}

static void		seektowritable(t_fillit *x, int *p)
{
	while ((*p < (int)(x->grid_size * x->grid_size)) &&
			(x->grid[*p / (int)x->grid_size][*p % (int)x->grid_size] != '.'))
		*p += 1;
	*p -= 1;
}

static int		trouvator_engine(t_fillit *x, int p, int n)
{
	int		ret;

	ret = insert(x, p, n);
	if (ret <= 0)
	{
		return (0);
	}
	else if (n + 1 < (int)x->elements_count)
	{
		p += x->elems[n].width;
		seektowritable(x, &p);
		return (trouvator_engine(x, p, n + 1));
	}
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
