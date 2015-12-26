/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:11:45 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/26 12:05:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void					removator(t_fillit *x, unsigned int n)
{
	const unsigned short	mask = x->elems[n].mask;
	unsigned short			b;
	unsigned short			p;
	unsigned short			submask;

	submask = 15;
	p = 0;
	while (p < x->elems[n].height)
	{
		b = x->bgrid[x->elems[n].pos + p];
		x->bgrid[x->elems[n].pos + p] = (b & (mask & submask));
		submask <<= 4;
		p++;
	}
	x->elems[n].mask = 0;
}
