/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 12:47:05 by qloubier         ###   ########.fr       */
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

static int	trouvator_brutforce(t_fillit *x)
{
	size_t	i;
	int		n;

	i = 0;
	n = 1;
	while(i < x->elements_count)
	{
		++i;
		if (x->elems[i - 1].placed)
			continue ;
		n = -1;
		if (insert_bin(x, &(x->elems[i - 1])))
			n = trouvator_brutforce(x);
		if (n == 0)
			removator(x, &(x->elems[i - 1]));
		else if (n == 1)
			return (1);
		else
			return (0);
	}
	/*ft_putnbr((int)i);
	ft_putchar('\n');*/
	return (n);
}

static int	trouvator_engine(t_fillit x, unsigned int n)
{
	n = (unsigned int)trouvator_brutforce(&x);
	//if (n == x.elements_count)
	if (n)
	{
		displayator(&x);
		return ((int)x.grid_size);
	}
	/*x.offset = 0;
	while (x.offset < x.elements_count)
	{
		if ((!x.elems[x.offset].placed) &&
			(insert_bin(&x, &x.elems[x.offset]) != 0))
		{
			if (trouvator_engine(x, n + 1))
				return (1);
			removator(&x, &x.elems[x.offset]);
		}
		x.offset++;
	}*/
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
