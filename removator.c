/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:11:45 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 11:36:38 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static unsigned short rmmask(unsigned short b, unsigned short mask)
{
	unsigned short	p;
	unsigned short	bit;
	unsigned short	ret;

	p = 16;
	bit = 1;
	ret = 0;
	while (p--)
	{
		if (((b & bit) != 0) && ((mask & bit) == 0))
			ret += bit;
		bit <<= 1;
	}
	return (ret);
}

void					removator(t_fillit *x, unsigned int n)
{
	const unsigned short	mask = x->elems[n].mask;
	unsigned short			b;
	unsigned short			p;

	p = 4;
	while (p--)
	{
		b = x->bgrid[x->elems[n].pos + p];
		x->bgrid[x->elems[n].pos] = rmmask(b, mask >> (4 * p));
	}
	x->elems[n].mask = 0;
}
