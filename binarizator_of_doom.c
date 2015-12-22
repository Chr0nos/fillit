/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/22 18:07:41 by snicolet         ###   ########.fr       */
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
	int						pad;

	b = 0;
	col = 0;
	pow = 1;
	col = t->width + 1;
	pad = 0;
	while ((--col) && (line = t->height + 1))
	{
		while (line)
		{
			if ((++pow) && (t->data[--line][col] != '.'))
				b += ft_pow(2, pow) / 2;
		}
	}
	return (b);
}
