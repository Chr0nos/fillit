/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:11:45 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/03 14:00:01 by snicolet         ###   ########.fr       */
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
	unsigned short			b;
	unsigned char			p;
	unsigned char			x;

	b = elem->bin;
	ft_putstr("Removing ... ");
	ft_putchar(elem->letter);
	ft_putchar('\n');
	p = elem->pos >> 8;
	ft_putnbr((int)p);
	ft_putstr(" line\n");
	x = (unsigned char)(elem->pos & 255);
	ft_putnbr((int)x);
	ft_putstr(" colone\n");
	f->bgrid[p] ^= (b & 61440) >> x;
	f->bgrid[p + 1] ^= ((b << 4) & 61440) >> x;
	f->bgrid[p + 2] ^= ((b << 8) & 61440) >> x;
	f->bgrid[p + 3] ^= ((b << 12) & 61440) >> x;
	elem->placed = 0;
	return (0);
}
