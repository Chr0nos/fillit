/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/22 20:59:39 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	binarizator_of_doom(t_element *t)
{
	unsigned short			b;
	unsigned int			line;
	unsigned int			col;
	int						pow;
	unsigned int			x;

	b = 0;
	col = 0;
	pow = 0;
	line = 0;
	while ((line < t->height) && (!(col = 0)))
	{
		x = 4;
		while (col < t->width)
		{
			if ((++pow) && (t->data[line][col++] != '.'))
				b |= 1 << pow;
			x--;
		}
		while (x > 0)
			if (++pow)
				x--;
		++line;
	}
	return (b / 2);
}
