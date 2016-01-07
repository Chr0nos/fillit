/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouvator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:03:43 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 14:20:26 by qloubier         ###   ########.fr       */
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
//*

static int	trouvator_magic(t_fillit *x, char *idxs)
{
	t_idx i;

	grid_reset(x);
	i = 0;
	while (i < x->elements_count && insert_bin(x, &x->elems[(t_idx)(idxs[i])]))
	{
		//ft_printf("pass on %d as %d\n", (int)i, (int)(idxs[i]));
		++i;
	}
	if (i == x->elements_count)
	{
		//ft_printf("stop on this\n");
		return (1);
	}
	//ft_printf("not stop on %d width offset %d\n", (0 - ((int)x->elements_count - (int)i)));
	return (0 - ((int)x->elements_count - (int)i));
}

static int	trouvator_brutforce(t_fillit *x, char *idxs, unsigned char c)
{
	unsigned char	i;
	int				n;

	i = 0;
	n = 2;
	//ft_printf("Call %d in %d elements\n", (int)c, (int)(x->elements_count));
	if ((unsigned int)c >= x->elements_count)
		return (trouvator_magic(x, idxs));
	while(i < x->elements_count)
	{
		n = 0;
		//ft_printf("%d at %d\n", (int)c, (int)i);
		if (idxs[i] == -1)
		{
			idxs[i] = (char)c;
			n = trouvator_brutforce(x, idxs, c + 1);
			if (n == 1)
				return (1);
			//ft_printf("remove %d\n", (int)c);
			idxs[i] = -1;
			if (n < 0)
				return (n + 1);
		}
		++i;
	}
	//ft_putnbr((int)i);
	//ft_putchar('\n');
	return (n);
}
//*/
static int	trouvator_engine(t_fillit *x, unsigned int n)
{
	char	idxs[26];

	ft_memset(idxs, -1, 26);
	x->offset = 0;
	n = (unsigned int)trouvator_brutforce(x, idxs, 0);
	ft_printf("return value : %d\n", n);
	//if (n == x.elements_count)
	if (n == 1)
	{
		displayator(x);
		return ((int)(x->grid_size));
	}
	/*
	x.offset = 0;
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
	}//*/
	return (0);
}

int			trouvator(t_list *lst)
{
	t_fillit	*fillit;

	fillit = preparator(lst);
	ft_lstdel(&lst, ft_lstpulverisator);
	if (!fillit)
		return (-1);
	while ((trouvator_engine(fillit, 0) == 0) && (grid_extend(fillit)))
		(void)fillit;
	free(fillit);
	return (0);
}
