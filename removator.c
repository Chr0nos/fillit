/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:11:45 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 11:50:56 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static unsigned short rmmask(unsigned short b, unsigned short mask)
{
	return (b & ~mask);
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
		x->bgrid[x->elems[n].pos + p] = rmmask(b, mask >> (4 * p));
	}
	x->elems[n].mask = 0;
}
