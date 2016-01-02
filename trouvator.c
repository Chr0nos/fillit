/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/31 12:27:19 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void				swap_map(t_fillit *f, unsigned int n1, unsigned int n2)
{
	f->map[n2] = f->map[n1];
	f->map[n1] = f->map[n1] + f->map[n2];
	f->map[n1] = f->map[n1] - f->map[n2];
}

static int				trouvator_engine(t_fillit *x, unsigned int n)
{
	int		ret;

	ret = insert_bin(x, &x->elems[(unsigned int)x->map[n]]);
	if (ret == 0)
		return (0);
	if (n + 1 == x->elements_count)
		return (1);
	if (trouvator_engine(x, n + (unsigned int)(ret++)))
		return (1);
	ft_putendl("failed to place element");
	//removator(x, n);
	//ft_memset(x->bgrid, 0, sizeof(unsigned short) * x->grid_size);
	return (0);
}

int						trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	(void)swap_map;
	swap_map(fillit, 0, 3);	//pensser a virer cette ligne <<
	while ((trouvator_engine(fillit, 0) == 0) && (fillit->grid_size < 16))
	{
		fillit->grid_size += 1;
		grid_reset(fillit);
		ft_printf("setting grid size to %d\n", fillit->grid_size);
	}
	displayator(fillit);
	free(fillit->elems);
	free(fillit);
	return (0);
}
