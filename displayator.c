/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:53:17 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/05 15:23:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void	display_tetro_of_the_infinite_agony(t_element *t)
{
	char			buffer[21];
	int				p;
	int				bit;
	unsigned short	nb;

	nb = t->display;
	buffer[20] = '\0';
	p = 0;
	bit = 0;
	while (bit < 16)
	{
		if (p % 5 == 0)
			buffer[p++] = '\n';
		if ((nb >> bit++) & (unsigned short)1)
			buffer[p++] = (char)t->letter;
		else
			buffer[p++] = '.';
	}
	buffer[p] = '\0';
	ft_putendl(buffer + 1);
}

static void	display_bits(unsigned short nb)
{
	char	buffer[33];
	int		p;

	p = 16;
	buffer[32] = '\0';
	while (p--)
	{
		buffer[(p * 2) + 1] = ((nb >> (15 - p) & (t_tetrobloc)1) ? '1' : '0');
		buffer[(p * 2)] = ' ';
	}
	ft_putstr(buffer);
}

static void	display_tetrominos(t_fillit *x)
{
	unsigned int	p;
	t_element		*elem;

	p = 0;
	while (p < x->elements_count)
	{
		elem = &x->elems[p];
		ft_putnbr((int)elem->bin);
		ft_putchar('\n');
		display_bits(elem->bin);
		ft_putchar('\n');
		display_tetro_of_the_infinite_agony(elem);
		ft_putchar('\n');
		p++;
	}
}

static void	display_bgrid_bits(t_fillit *x)
{
	unsigned int	p;

	p = 0;
	while (p < x->grid_size)
	{
		display_bits(x->bgrid[p++]);
		ft_putchar('\n');
	}
}

void		displayator(t_fillit *x)
{
	display_tetrominos(x);
	display_bgrid_bits(x);
	super_display_of_doom(x);
}
