/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:31:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 12:32:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	bgrid_reset(t_fillit *x)
{
	unsigned int	p;

	p = GRID_EDGE;
	while  (p--)
		x->bgrid[p] = 0;
}

void	grid_reset(t_fillit *x)
{
	unsigned int	p;

	p = 0;
	while (p < x->grid_size)
	{
		ft_memset(x->grid[p], '.', x->grid_size);
		x->grid[p][x->grid_size - 1] = '\0';
		p++;
	}
	bgrid_reset(x);
}
