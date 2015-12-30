/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/30 19:13:43 by qloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	binarizator_of_doom(char *s)
{
	unsigned short			b;
	int						p;
	char					buf[17];

	p = -1;
	buf[16] = '\0';
	ft_putendl(buf);
	while (++p < 4)
		ft_memcpy(buf + (4 * p), s + (p * 5), 4);
	p = -1;
	b = 0;
	while (++p < 16)
	{
		b |= (buf[p] == '#') ? (1 << p) : 0;
		ft_putnbr(b);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	while ((b & (unsigned short)15) == 0)
		b >>= 4;
	while ((b & (unsigned short)4369) == 0)
		b >>= 1;
	return (b);
}
