/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:53:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/19 16:14:53 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	display_bins(t_fillit *x)
{
	size_t	p;

	p = 0;
	while (p < x->elements_count)
	{
		ft_putnbr(x->elems[p++].bin);
	}
}

void		displayator(t_fillit *x)
{
	size_t	p;

	p = 0;
	while (p < GRID_EDGE - 1)
		ft_putendl(x->grid[p++]);
	display_bins(x);
}
