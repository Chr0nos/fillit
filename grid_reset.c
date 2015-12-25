/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:31:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/25 17:12:07 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static void	bgrid_reset(t_fillit *x)
{
	unsigned int	p;

	p = x->grid_size;
	while (p--)
		x->bgrid[p] = 0;
}

void		grid_reset(t_fillit *x)
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
