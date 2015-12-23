/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarizator_of_doom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/12/23 11:59:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	binarizator_of_doom(char *s)
{
	unsigned short			b;
	unsigned int			p;
	int						pow;

	b = 0;
	pow = 0;
	p = 0;
	while (p < 21)
	{
		if ((s[p] != '\n') && (++pow) && (s[p] != '.'))
			b |= 1 << pow;
		p++;
	}	
	b = b >> 1;
	while ((b & (unsigned short)15) == 0)
		b = b >> 4;
	while ((b & (unsigned short)4369) == 0)
		b = b >> 1;
	return (b);
}
