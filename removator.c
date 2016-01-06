/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:11:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/06 23:22:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** the mask is different from elem[n].bin because the bits can be moved before
** submask is here to parse just 4 bits in the mask itself
** the idea is to remove along the 4 maximum lines (defined by .height)
*/

int					removator(t_fillit *f, t_element *elem)
{
	const unsigned short	b = elem->bin;
	const unsigned char		p = elem->pos >> 8;
	unsigned char			x = (unsigned char)(elem->pos & 255);

	f->bgrid[p] ^= (b & 61440) >> x;
	f->bgrid[p + 1] ^= ((b << 4) & 61440) >> x;
	f->bgrid[p + 2] ^= ((b << 8) & 61440) >> x;
	f->bgrid[p + 3] ^= ((b << 12) & 61440) >> x;
	elem->placed = 0;
	return (0);
}
