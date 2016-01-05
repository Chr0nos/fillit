/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:31:15 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 15:08:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	grid_reset(t_fillit *x)
{
	unsigned int	p;

	p = x->grid_size;
	while (p--)
		x->bgrid[p] = 0;
	p = x->elements_count;
}
