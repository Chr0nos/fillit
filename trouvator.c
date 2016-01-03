/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 15:55:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void	swap_map(t_fillit *x, unsigned int p1, unsigned int p2)
{
	char	tmp;

	tmp = x->map[p1];
	x->map[p1] = x->map[p2];
	x->map[p2] = tmp;
}

static int	grid_extend(t_fillit *x)
{
	if (x->grid_size >= 16)
		return (0);
	grid_reset(x);
	x->grid_size += 1;
	ft_printf("setting grid size to %d\n", x->grid_size);
	return (1);
}

static int	trouvator_engine(t_fillit *x, unsigned int n)
{
	int		ret;

	ret = insert_bin(x, &x->elems[(unsigned int)x->map[n]]);
	//echec de l insertion
	if (ret == 0)
	{
		//on reviens en arriere si c est possible (si on es pas deja au debut)
		if ((int)n - 1 >= 0)
		{
			removator(x, &x->elems[n - 1]);
			swap_map(x, n, n - 1);
			return (trouvator_engine(x, n - 1));
		}
		//sinon on agrandis la taille de la grille et on reprends du debut
		else if (grid_extend(x))
			return (trouvator_engine(x, 0));
		return (0);
	}
	if (n + 1 == x->elements_count)
		return ((int)x->grid_size);
	return (trouvator_engine(x, n + 1));
}

int			trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	trouvator_engine(fillit, 0);
	displayator(fillit);
	free(fillit->elems);
	free(fillit);
	return (0);
}
