/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaybin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:38:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 17:14:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	displaybin(t_fillit *f)
{
	unsigned int		p;
	unsigned int		bp;
	unsigned int		bit;
	const unsigned int	end = f->grid_size * f->grid_size;
	char				buffer[GRID_EDGE * GRID_EDGE];

	p = 0;
	bp = 0;
	while (p < end)
	{
		bit = 8;
		while (bit--)
			buffer[bp++] = (((f->bgrid[p] & (1 << bit)) == 0) ? '.' : '#');
		++p;
		if (p % f->grid_size == 0)
			buffer[bp++] = '\n';
	}
	buffer[bp] = '\0';
	ft_putendl(buffer);
}
