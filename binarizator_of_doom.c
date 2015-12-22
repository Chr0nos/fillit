/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/22 21:53:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	binarizator_of_doom(t_element *t)
{
	unsigned short			b;
	unsigned int			line;
	unsigned int			col;
	int						pow;

	b = 0;
	col = 0;
	pow = 0;
	line = 0;
	while ((line < t->height) && (!(col = 0)))
	{
		while (col < t->width)
		{
			if ((++pow) && (t->data[line][col++] != '.'))
				b |= 1 << pow;
		}
		++line;
	}
	b = b >> 1;
	while ((b & (unsigned short)15) == 0)
		b = b >> 4;
	while ((b & (unsigned short)4369) == 0)
		b = b >> 1;
	return (b);
}
