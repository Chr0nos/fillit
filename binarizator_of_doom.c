/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/20 13:52:41 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

unsigned short	binarizator_of_doom(t_element *t)
{
	unsigned short			b;
	unsigned int			pos;
	const unsigned short	endpos = (unsigned short)(t->height * t->width);

	b = 0;
	pos = 0;
	while (pos < endpos)
	{
		if (t->data[pos / t->width][pos % t->width] != '.')
			b += (unsigned short)ft_pow(2, ((int)pos + 1) / 2);
		++pos;
	}
	return (b);
}
