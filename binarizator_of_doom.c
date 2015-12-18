/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/18 19:12:55 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	binarizator_of_doom(t_element *t)
{
	unsigned short			b;
	unsigned int			pos;
	unsigned short			x;
	unsigned short			pow;
	const unsigned short	endpos = (unsigned short)(t->height * t->width);

	b = 0;
	pos = 0;
	pow = 1;
	x = 0;
	while (pos < endpos)
	{
		if (x % t->width == 0)
		{
			++x;
			while (--x)
				pow *= 2;
		}
		if (t->data[pos / t->height][pos % t->width] != '.')
			b += pow;
		pow *= 2;
		++x;;
		++pos;
	}
	return (b);
}
