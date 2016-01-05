/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 13:32:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int	grid_extend(t_fillit *x)
{
	if (x->grid_size >= 16)
		return (0);
	grid_reset(x);
	x->grid_size += 1;
	ft_printf("setting grid size to %d\n", x->grid_size);
	return (1);
}

static int	trouvator_engine(t_fillit x, unsigned int n)
{
	if (n == x.elements_count)
	{
		displayator(&x);
		return ((int)x.grid_size);
	}
	x.offset = 0;
	while (x.offset < x.elements_count)
	{
		if ((!x.elems[x.offset].placed) &&
			(insert_bin(&x, &x.elems[x.offset]) != 0))
				return (trouvator_engine(x, n + 1));
		x.offset++;
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
	while (trouvator_engine(*fillit, 0) == 0)
	{
		if (!grid_extend(fillit))
			break ;
	}
	free(fillit->elems);
	free(fillit);
	return (0);
}
