/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:31:15 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/17 17:14:20 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	grid_reset(t_fillit *x)
{
	unsigned short	p;

	p = GRID_EDGE - 1;
	while (p--)
	{
		ft_memset(x->grid[p], '.', GRID_EDGE - 1);
		x->grid[p][GRID_EDGE - 1] = '\0';
	}
}
