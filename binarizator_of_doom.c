/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/22 18:17:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	pow = 1;
	col = t->width + 1;
	while ((--col) && (line = t->height + 1))
	{
		while (line)
		{
			if ((++pow) && (t->data[--line][col] != '.'))
				b += ft_pow(2, pow) / 2;
		}
		x = 4 - t->width;
		while (x)
			if (++pow)
				x--;
	}
	return (b / 2);
}
