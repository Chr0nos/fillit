/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superdisplayator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 12:26:51 by qloubier          #+#    #+#             */
/*   Updated: 2016/01/07 00:26:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		display_line(t_fillit *f, size_t p)
{
	size_t			e;
	char			buffer[21];
	unsigned char	x;
	unsigned short	b;

	e = 0;
	ft_memset(buffer, (int)'.', 21);
	ft_memset(buffer + f->grid_size, (int)'\0', 21 - f->grid_size);
	while (e < f->elements_count)
	{
		x = f->elems[e].pos >> 8;
		if (x <= p && (x + 4) > p)
		{
			b = (f->elems[e].bin << (p - x) * 4) & 61440;
			x = (unsigned char)(f->elems[e].pos & 255);
			buffer[x] = (b & 32768) ? f->elems[e].letter : buffer[x];
			buffer[x + 1] = (b & 16384) ? f->elems[e].letter : buffer[x + 1];
			buffer[x + 2] = (b & 8192) ? f->elems[e].letter : buffer[x + 2];
			buffer[x + 3] = (b & 4096) ? f->elems[e].letter : buffer[x + 3];
		}
		++e;
	}
	ft_putstr(buffer);
}

int			super_display_of_doom(t_fillit *f)
{
	size_t			p;

	p = 0;
	ft_putstr("Grid size : ");
	ft_putnbr((int)f->grid_size);
	ft_putchar('\n');
	while (p < f->grid_size)
	{
		ft_putnbr((int)p);
		ft_putchar(' ');
		display_line(f, p);
		ft_putchar('\n');
		++p;
	}
	return (1);
}
