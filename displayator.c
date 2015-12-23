/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:53:17 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 14:55:03 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	display_tetro_of_the_infinite_agony(t_element *t)
{
	char			buffer[21];
	int				p;
	int				bit;
	unsigned short	nb;

	nb = t->bin;
	buffer[20] = '\0';
	p = 0;
	bit = 0;
	while (bit < 16)
	{
		if (p % 5 == 0)
			buffer[p++] = '\n';
		if (nb >> bit++ & (unsigned short)1)
			buffer[p++] = (char)t->letter;
		else
			buffer[p++] = '.';
	}
	buffer[p] = '\0';
	ft_putendl(buffer + 1);
}

static void	display_bits(unsigned short nb)
{
	char	buffer[17];
	int		p;

	p = 16;
	buffer[p--] = '\0';
	p++;
	while (p--)
		buffer[p] = ((nb >> (15 - p) & (unsigned short)1) ? '1' : '0');
	ft_putstr(buffer);
}

static void	display_tetrominos(t_fillit *x)
{
	unsigned int	p;

	p = 0;
	while (p < x->elements_count)
	{
		ft_putnbr((int)x->elems[p].bin);
		ft_putchar('\n');
		display_bits(x->elems[p].bin);
		ft_putchar('\n');
		display_tetro_of_the_infinite_agony(&x->elems[p]);
		ft_putchar('\n');
		p++;
	}
}

static void	display_bgrid_bits(t_fillit *x)
{
	unsigned int	p;
	unsigned int	end;

	end = x->grid_size;
	p = 0;
	while (p < end)
	{
		ft_putbits(&x->bgrid[p++], sizeof(unsigned char));
		if (p % x->grid_size == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

void		displayator(t_fillit *x)
{
	size_t	p;

	display_tetrominos(x);
	p = 0;
	while (p < x->grid_size)
		ft_putnendl(x->grid[p++], x->grid_size);
	display_bgrid_bits(x);
}
